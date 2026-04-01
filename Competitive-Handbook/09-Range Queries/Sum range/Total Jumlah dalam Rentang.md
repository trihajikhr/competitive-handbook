---
obsidianUIMode: preview
note_type: book theory
judul_materi: Total Jumlah dalam Rentang
sumber:
  - myself
  - "buku: CP handbook by Antti Laaksonen"
date_learned: 2026-02-14T21:07:00
tags:
  - range-queries
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Total Jumlah dalam Rentang

Misal kita diberikan array $n$ dengan $n$ elemen. Lalu kita diminta untuk menentukan jumlah elemen dari rentang $l$ hingga $r$, apa yang perlu dilakukan?

Materi ini akan membahas 2 pendekatan untuk menyelesaikan permasalahan ini.

## 1. Pendekatan naif

Pendekatan yang langsung adalah dengan menghitungnya secara langsung, misal diberikan inputan sebagai berikut:

```
10
1 2 3 4 5 6 7 8 9 10
1 4
```

Baris pertama adalah $n$ yaitu ukuran array, dengan baris kedua terdiri dari $n$ elemen array, dan baris ketiga adalah $l$ dan $r$.

Maka kode berikut sudah cukup untuk menyelesaikan permasalah diatas:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, l, r;
    cin >> n;
    vector<int> vec(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    cin >> l >> r;

    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += vec[i];
    }

    cout << sum;
    return 0;
}
```

kompleksitas kode diatas sekarang adalah $O(n)$.

Tapi bagaiman jika soal yang diberikan adalah dengan memberikan beberapa queries $q$. Dimana kita harus menjawab jumlah dari rentang $l$ hingga $r$ sebanyak $q$ kali? 

Jika kita mencoba untuk menyelesaikan tantangan ini dengan mengganti kodenya menjadi seperti ini:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, l, r, q;
    cin >> n >> q;
    vector<int> vec(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    while (q--) {
        cin >> l >> r;

        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += vec[i];
        }

        cout << sum << "\n";
    }
    return 0;
}
```

Maka kompleksitasnya adalah $O(nq)$, yang mana kurang efisien jika $n$ dan $q$ sama-sama bernilai besar. 

Oleh karena itu, diperlukan algoritma yang lebih efisien. 

Untuk array statis, kita bisa menggunakan *Prefix Sum*, sedangkan jika arraynya dinamis, maka kita harus menggunalan algoritma dan penerapan struktur data lanjutan yang lebih canggih, seperti *Segment Tree* atau *Fenwick Tree (Binary Indexed Tree)*.

## 2. Algoritma Prefix Sum

Jika kita diberikan suatu array berukuran $n$, dan kita harus menjawab total jumlah elemen dalam rentang $l$ hingga $r$ sebanyak $q$ queries, dan array bersifat statis atau tidak mengalami perubahan data lagi selama program berjalan, maka algoritma Prefix Sum perlu digunakan.

Ide utama dari Prefix Sum adalah melakukan pra-pemrosesan (*pre-processing*) terhadap array input agar setiap pertanyaan (*query*) mengenai jumlah rentang dapat dijawab dalam kompleksitas konstan, yaitu $O(1)$.

### 2.1. Konsep Dasar

Bayangkan kita membuat sebuah array baru, sebut saja $pref$, di mana setiap elemen $pref[i]$ menyimpan total jumlah elemen dari indeks pertama hingga indeks ke-$i$.

Jika kita memiliki array $A = [a_1, a_2, a_3, ..., a_n]$, maka array prefix sum $P$ didefinisikan sebagai:

- $P[0] = 0$
- $P[1] = a_1$
- $P[2] = a_1 + a_2$
- $P[3] = a_1 + a_2 + a_3$
- $P[n] = a_1 + a_2 + a_3 + \dots + a_n$
- Secara umum: $P[i] = P[i-1] + a_i$

### 2.2. Cara Menghitung Rentang $[l, r]$

Bagaimana cara kita mendapatkan jumlah elemen dari indeks $l$ sampai $r$ hanya dengan menggunakan array $pref$?

Perhatikan logika berikut:

1. $pref[r]$ berisi jumlah dari indeks $1$ sampai $r$.
2. $pref[l-1]$ berisi jumlah dari indeks $1$ sampai $l-1$.
3. Jika kita mengurangkan $pref[r]$ dengan $pref[l-1]$, kita akan membuang bagian awal yang tidak dibutuhkan dan menyisakan rentang $[l, r]$.

Sehingga formula yang bisa digunakan adalah sebagai berikut:

$$\sum_l^ra_i = P[r] - P[l-1]$$

### 2.3. Contoh Visual

Misal diberikan array $A$ dengan ukuran $n=5$, dengan elemen array $A = [3, 1, 4, 1, 5]$.

Maka kita perlu membuat array $P$ dengan ukuran $n+1$, dan melakukan proses berikut

- $P[0] = 0$
- $P[1] = 0+3=3$
- $P[2] = 3 + 1 = 4$
- $P[3] = 4 + 4 = 8$
- $P[4] = 8 + 1 = 9$
- $P[5] = 9 + 5 = 14$

Jika ditanya jumlah dari indeks $2$ ke $4$ ($1 + 4 + 1 = 6$), maka kita cukup menggunakan rumus: $P[4] - P[2-1] = P[4] - P[1] = 9 - 3 = 6$.

_Hasilnya instan tanpa perlu looping!_
### 2.4. Implementasi Kode (C++)

Berikut adalah cara mengimplementasikan Prefix Sum untuk menangani banyak query secara efisien:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    vector<long long> pref(n + 1, 0);

    // 1. Membaca input dan membangun array prefix sum
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    // 2. Menjawab setiap query dalam O(1)
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        // Menggunakan rumus P[r] - P[l-1]
        cout << pref[r] - pref[l - 1] << "\n";
    }

    return 0;
}
```

Dalam implementasi prefix sum, untuk memudahkan, kita perlu mengganti array yang digunakan menjadi array 1-based indexing. Kenapa?

Ini membuat implementasi prefix sum menjadi lebih mudah, karena  untuk $P[l-1]$ ketika $l=1$, kita tetap mengakses wilayah array yaitu elemen $P[0]=0$, sehingga tidak mengakibatkan *out-of-bound*.

Kedua, soal biasanya memberikan nilai $l$ dan $r$ untuk mengakses array sebagai 1-based indexing, sementara di C++ array selalu dimulai dari 0, atau 0-based indexing. Dengan menjadikan jenis indexing pada array sama, kita membuat implementasi menjadi mudah.

> [!TIP]
> Tips lain ketika menggunakan algoritma ini: Ketika ukuran array sangat besar, dan nilai dari setiap elemen $a_i$ juga besar, pertimbangkan untuk menggunakan tipe data `long long` pada array yang digunakan untuk membangun prefix sum. Ini berguna untuk mengatasi kemungkinan terjadinya *overflow* pada saat precompute.
### 2.5. Analisis Kompleksitas

- **Pra-pemrosesan:** $O(n)$ untuk membangun array $pref$.
- **Menjawab Query:** $O(1)$ per query.
- **Total Kompleksitas:** $O(n + q)$.

Bandingkan dengan pendekatan naif yang menggunakan kompleksitas $O(n \times q)$. Jika $n$ dan $q$ bernilai $10^5$, pendekatan naif membutuhkan $10^{10}$ operasi yang beresiko mengalami *time limit exceed*. Sedangkan Prefix Sum hanya butuh sekitar $2 \times 10^5$ operasi, yang mana sangat cepat.

## 3. Fenwick Tree & Segment Tree

Jika kita diminta untuk mencari jumlah dari rentang $l$ hingga $r$ dari array berukuran $n$, sebanyak $q$ queries kali, tetapi diantara dua query elemen array mengalami perubahan, apakah algoritma prefix sum masih bisa digunakan?

Sayangnya jawabanya adalah tidak. 

Memang benar bahwa Prefix Sum adalah algoritma yang "manja" terhadap perubahan data. Masalah utamanya terletak pada biaya pemeliharaan (_maintenance cost_). Karena setiap elemen $pref[i]$ bergantung pada elemen-elemen sebelumnya, satu saja perubahan pada indeks $k$ akan mengakibatkan efek domino yang mengharuskan kita memperbarui seluruh nilai prefix dari indeks $k$ sampai $n$. Jadi, jika ada satu elemen yang berubah, kita terpaksa melakukan kalkulasi ulang yang memakan waktu $O(n)$.

Kalau kita coba hitung kompleksitasnya secara lebih formal, jika kita memiliki $q$ buah operasi yang campur aduk antara _update_ (mengubah angka) dan _query_ (menanyakan jumlah), maka dalam skenario terburuk di mana setiap query didahului oleh satu update, total kompleksitasnya akan membengkak menjadi $O(q \times n)$. Ini jauh lebih buruk daripada $O(n + q)$ yang kita harapkan dari Prefix Sum pada array statis. Itulah sebabnya Prefix Sum hanya "sakti" jika datanya tidak pernah berubah sejak awal.

Sebagai solusi, jika kita memang berhadapan dengan array yang dinamis, kita tidak bisa lagi hanya mengandalkan array biasa. Kita butuh struktur data yang lebih kompleks seperti **Fenwick Tree (Binary Indexed Tree)** atau **Segment Tree**. Kedua struktur ini dirancang untuk menyeimbangkan beban; mereka tidak secepat $O(1)$ untuk query, tapi juga tidak selambat $O(n)$ untuk update. Keduanya biasanya menawarkan waktu $O(\log n)$ untuk kedua jenis operasi tersebut, yang jauh lebih efisien untuk skala data besar.
