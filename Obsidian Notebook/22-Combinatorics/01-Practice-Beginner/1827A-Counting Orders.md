---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1827A
judul_STRIKE: Counting Orders
teori_STRIKE: upper_bound dan lower_bound
sumber:
  - codeforces
ada_tips?: true
date_learned: 2025-08-15T13:07:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1827A - Codeforces](https://codeforces.com/problemset/problem/1827/A)

```ad-tip
title:⚔️ Teori STRIKE

Fungsi bawaan seperti `upper_bound()` akan sangat membantu proses pencarian angka-angka pada array $A$ yang lebih besar dari setiap $B_i$. Jadi, pelajarilah fungsi-funsi seperti itu.

Perdalam pemahaman materi kombinasi, dan perhatikan apakah dipernyataan soal, dibolehkan menggunakan angka-angka duplikat atau tidak!
```

- [ ] Pelajari cara mengurutkan array dengan STL, dengan dan tanpa ranges, maupun sort custom.
- [ ] Membuat latihan soal yang sama dengan soal 1827A, untuk memantapkan pemahaman
- [x] Mempelajari fungsi `upper_bound` dan `lower_bound`! ✅ 2025-08-16
- [ ] Pelajari materi kombinasi dengan digit harus berbeda!

<br/>

---
# 1 | Counting Orders


Diberikan dua array $a$ dan $b$, masing-masing berisi $n$ bilangan bulat. Semua elemen di $a$ saling berbeda (*pairwise distinct*). 

Temukan banyaknya cara untuk menyusun ulang (*reorder*) $a$ sehingga berlaku: $a_i > b_i \quad \text{untuk semua} \quad 1 \le i \le n$. Hasilnya diambil **modulo** $10^9 + 7$.

Dua cara penyusunan ulang dianggap berbeda jika array hasil akhirnya berbeda.

#### Input:
Setiap *test* berisi beberapa *test case*. Baris pertama berisi satu bilangan bulat $t$ $(1 \le t \le 10^4)$ — banyaknya *test case*.

Deskripsi masing-masing *test case* adalah sebagai berikut:

* Baris pertama setiap *test case* berisi satu bilangan bulat $n$ $(1 \le n \le 2 \cdot 10^5)$ — panjang array $a$ dan $b$.
* Baris kedua berisi $n$ bilangan bulat berbeda $a_1, a_2, \dots, a_n$ $(1 \le a_i \le 10^9)$ — array $a$.
* Baris ketiga berisi $n$ bilangan bulat $b_1, b_2, \dots, b_n$ $(1 \le b_i \le 10^9)$ — array $b$.

Dijamin bahwa semua elemen pada $a$ **saling berbeda**.
Dijamin bahwa jumlah seluruh $n$ pada semua *test case* tidak melebihi $2 \cdot 10^5$.

#### Output:
Untuk setiap *test case*, cetak banyaknya cara menyusun ulang array $a$ sehingga $a_i > b_i \quad \text{untuk semua} \quad 1 \le i \le n$. Hasilnya diambil **modulo** $10^9 + 7$.

<br/>

---
# 2 | Sesi STRIKE ⚔️

1. Dibutuhkan penerapan kombinasi di materi ini.
2. Fungsi bawaan seperti `upper_bound()` akan sangat membantu proses pencarian angka-angka pada array $A$ yang lebih besar dari setiap $B_i$. Jadi, pelajarilah fungsi-funsi seperti itu.

#tips-trick Manfaatkan fungsi bawaan dengan bijak. Mereka kadang sangat menyingkat pekerjaan! 
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

```ad-hint
Urutkan array $b$, lalu tentukan nilai $a_n$ hingga $a_1$.
```

Pertama, kita dapat mengurutkan array $b$, karena ini **tidak mengubah** jawaban.

Mari kita coba memilih nilai $a$ dari $a_n$ hingga $a_1$. Berapa banyak cara untuk memilih nilai $a_i$?

Nilai baru $a_i$ harus memenuhi $a_i > b_i$. Namun, beberapa kandidat sudah dipakai sebagai $a_j$ untuk $j > i$. Karena $a_j > b_j \ge b_i$, kita tahu bahwa **tepat** ada $(n - i)$ kandidat yang sudah dipilih sebelumnya oleh semua nilai $j > i$. Jadi, banyaknya cara untuk memilih $a_i$ adalah: $\bigl|\{ k \mid a_k > b_i \}\bigr| - (n - i)$

Kita dapat menggunakan *two pointers* atau *binary search* untuk menghitung $\bigl|\{ k \mid a_k > b_i \}\bigr|$ untuk setiap $i$ secara efisien.

**Kompleksitas waktu:** $O(n \log n)$

Berikut implementasinya:

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

struct testcase {
   testcase() {
      int n;
      cin >> n;
      
      vector<int> a(n);
      for (int i = 0; i < n; i++) cin >> a[i];
      sort(a.begin(), a.end());
      
      vector<int> b(n);
      for (int i = 0; i < n; i++) cin >> b[i];
      sort(b.begin(), b.end(), greater<>());
      
      ll result = 1;
      for (int i = 0; i < n; i++) {
         int geq_count = a.size() - (upper_bound(a.begin(), a.end(), b[i]) -
         a.begin());
         result = result * max(geq_count - i, 0) % MOD;
      }
      cout << result << "\n";
   }
};

signed main() {
   cin.tie(0)->sync_with_stdio(0);
   int t;
   cin >> t;
   while (t--) testcase();
}
```
## 3.2 | Analisis Pribadi
### 3.2.1 | Pemahaman awal

Aku memiliki implementasi sendiri, yaitu sebagai berikut:

```cpp
/*
Author  : Riveris
Date    : 2025-08-15 13:24
Problem : Codeforces | 1827A - Counting Orders
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1'000'000'007;

void solve() {
   int n;
   cin >> n;
   vector<int> A(n), B(n);
   for (auto &x : A) cin >> x;
   for (auto &x : B) cin >> x;

   ranges::sort(A);
   ranges::sort(B);

   long long ans = 1;
   for (int i = n - 1; i >= 0; i--) {
      int pos = ranges::upper_bound(A, B[i]) - A.begin();
      int count = n - pos;

      int used = (n - 1) - i;
      int pilihan = count - used;

      if (pilihan <= 0) {
         cout << 0 << '\n';
         return;
      }

      ans = (ans * pilihan) % MOD;
   }

   cout << ans % MOD << '\n';
}

auto main() -> int {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

Its time untuk membedah kode ini!

Pertama, kita buat 2 vector dengan ukuran $n$, lalu kita sorting secara ascending. Kenapa di sorting? Secara logika, kita tidak perlu mempertahankan urutan array, karena kita hanya diminta berapa banyak kombinasi susunan yang memenuhi syarat yang diminta, yaitu untuk setiap $a_i > b_i$. Jadi, untuk mempermudah proses pencarian dan perhitungan, kita lakukan sorting.

Jika menggunakan vector, kita bisa menggunakan 2 cara sorting, yaitu dengan cara biasa dan juga dengan menggunakan bantuan `ranges`:

```cpp
sort(vector.begin(), vector.end());

// atau

ranges::sort(vector);
```

Kedua cara diatas akan mengurutkan array secara ascending. 

Setelah itu, kita deklarasikan `ans`, yaitu singkatan dari *answer* (ada juga yang menggunakan `rest`, singkatan dari *result*) untuk menampung jawaban dari banyaknya kombinasi yang mungkin, karena ada kemungkinan jawabanya sangat besar, kita set sebagai `long long`. Inisialisasi juga dengan 1, karena akan digunakan sebagai operasi perkalian nantinya:

```cpp
long long ans = 1;
```

Nah, sekarang perhatikan bagian ini:

```cpp
for (int i = n - 1; i >= 0; i--) { // kode }
```

Kenapa kita memulai perulangan dari belakang?

* $B[0]$ adalah nilai terkecil, $B[n-1]$ adalah nilai terbesar.
* Syarat kita: $a_i > b_i$.
* Kalau kita memilih dari **belakang**, kita akan mengisi posisi $i = n-1$ (pasangan dengan $B[n-1]$) terlebih dahulu.

**Logikanya:**

* $B[n-1]$ punya batas syarat paling **ketat**, karena dia nilai terbesar di $B$.
* Jadi untuk memenuhi $a_{n-1} > b_{n-1}$, kita harus memilih salah satu elemen terbesar di $A$.
* Kalau kita ambil dari indeks kecil dulu, bisa saja kita pakai angka besar di posisi awal, lalu tidak tersisa angka cukup besar untuk posisi akhir yang butuh nilai lebih tinggi.
* Dengan memilih dari **belakang**, kita selalu memastikan bahwa **posisi yang butuh nilai terbesar diprioritaskan lebih dulu**.

**Contoh:**

$A = [3, 5, 8]$
$B = [4, 6, 7]$ (sudah sort ascending)

Iterasi dari belakang:

1. $i = 2$, $B[2] = 7$ → pilih $8$ (hanya satu kandidat)
2. $i = 1$, $B[1] = 6$ → sisa $3, 5$ → pilih $\text{(hanya 5 yang > 6? Tidak ada)}$ → gagal.

Kalau kita pilih dari depan:

* $i = 0$, $B[0] = 4$ → bisa saja ambil 5 atau 8 (misal ambil 8)
* Nanti di $i = 2$, butuh $a_2 > 7$ → sisa 3 dan 5 → gagal juga, padahal ada cara lain kalau urutannya benar.

📌 **Intinya**:
Mulai dari belakang = memastikan **batas terbesar di-check dulu** supaya elemen besar tidak terbuang di posisi yang syaratnya longgar.

Oke, sekarang kita naik ke pembahasan yang bagian ini:

```cpp
int pos = ranges::upper_bound(A, B[i]) - A.begin();
```

Apa kegunaa dari fungsi ini? Artinya:

1. **`ranges::upper_bound(A, B[i])`**

   * Fungsi ini mencari **iterator** ke elemen pertama di `A` yang **lebih besar** dari `B[i]`.
   * Karena `upper_bound` butuh array `A` dalam kondisi **terurut ascending** (makanya kita sort dulu).
   * Misal:

		```
		A = [2, 5, 7, 9]
		B[i] = 5
		```
	
     Maka `ranges::upper_bound(A, 5)` menunjuk ke elemen **7** (index ke-2).



2. **`- A.begin()`**

   * Ini mengubah *iterator* hasil `upper_bound` menjadi **indeks** (posisi angka di array).
   * Contoh: Kalau iterator menunjuk ke 7 di atas, index-nya adalah `2`.
<br/>

2. **Makna variabel `pos`**

   * `pos` adalah **index pertama** di `A` yang nilainya **lebih besar** dari `B[i]`.
   * Semua elemen di posisi `pos` sampai `A.end()` adalah kandidat $a_k > b_i$.
   * Jadi jumlah kandidatnya:

     ```cpp
     count = n - pos;
     ```

🔍 Singkatnya:
`ranges::upper_bound(A, B[i]) - A.begin()` = *"berapa banyak elemen dari awal `A` sampai tepat sebelum elemen pertama yang lebih besar dari `B[i]`"*.


Oke, selanjutnya perhatikan potongan kode ini:

```cpp
int used = (n - 1) - i;
int pilihan = count - used;

if (pilihan <= 0) {
 cout << 0 << '\n';
 return;
}
```

```ad-warning
Cara ini ternyata masih bisa dioptimalkan, dan diperjelas lagi! Langsung saja pelajari cara kedua, [[#3.2.2 Hasil pemahaman sendiri]]
```
### 3.2.2 | Hasil pemahaman sendiri

Akhirnya, setelah berusaha memahaminya dengan jelas dan teliti, aku benar benar paham bagaimana alur algoritmanya. Well, lumayan melelahkan, tapi sekarang aku sudah paham:

```cpp
/*
Author  : Riveris
Date    : 2025-08-16 02:53
Problem : Codeforces | 1827A - Counting Orders
*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
   int n;
   cin >> n;
   vector<int> A(n), B(n);
   for (auto& x : A) cin >> x;
   for (auto& x : B) cin >> x;

   ranges::sort(A);
   ranges::sort(B, greater<>());

   long long ans = 1;
   for (int i = 0; i < n; i++) {
      int pos = ranges::upper_bound(A, B[i]) - A.begin();
      int count = n - pos;

      count -= i;

      if (count <= 0) {
         cout << 0 << " ";
         return;
      }

      ans = (ans * count) % MOD;
   }

   cout << ans << '\n';
}

auto main() -> int {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

Baiklah, katakanlah kita memiliki inputan seperti ini:

```
6
6 9 8 4 5 2
4 1 5 6 3 1
```

Maka berikut adalah kira-kira array yang terbentuk:

![[1827A-Counting Orders-1.png]]

Nah, disini, kita perlu melakukan sorting, supaya lebih mudah menyelesaikan tantangan. Array `A` kita sorting ascending, dan array `B` kita sorting secara descending:

```cpp
ranges::sort(A);
ranges::sort(B, greater<>());
```

![[1827A-Counting Orders-2.png]]

Nah, tugas kita sekarang, adalah mencari berapa banyak elemen dari array `A`, yang lebih besar dari setiap array B, maka didapat hasil seperti ini:

![[1827A-Counting Orders-3.png]]

Proses ini ada pada bagian kode ini:

```cpp
  int pos = ranges::upper_bound(A, B[i]) - A.begin();
  int count = n - pos;
```

Fungsi `upper_bound()` berguna untuk mencari angka yang tepat diatas $B_i$ pada array $A$. Semisal kita mencari nilai pada array $A$ yang diatas 6, maka posisi tersebut ditemuakn di indeks 4, yaitu di letak angka 8.

Nah, kode ini:

```cpp
int count = n - pos;
```

Berguna untuk mengetahui, berapa total sebenarnya angka pada array $A$ yang lebih besar dari $B_i$. Sehingga didapat nilai yaitu 2, dimana diatas angka 6, memang ada 2 angka pada array $A$, yaitu 8 dan 9.

Nah, karena kita diminta untuk membuat banyaknya kombinasi yang mungkin, dimana setiap $A_i > B_i$, maka kita perlu tahu rumus dan penerapan kombinasi disini.

Seadainya semua angka boleh digunakan berkali-kali asal memenuhi, maka jawabanya adalah dengan mengalikan semua kombinasi yang tersedia diatas:

$$
\text{kombinasi}=2\cdot3\cdot4\cdot5\cdot6\cdot6 = 4320
$$
Nah, tetapi, setiap angka hanya boleh digunakan sekali disini. Artinya, dari posisi paling kiri, kita mulai mengurangi setiap banyaknya kemungkinan angka sebanyak $1$, karena sudah ada beberapa angka yang digunakan didepan, sehingga banyaknya kombinasi angka dibagian belakang menjadi semakin sedikit

Perhatikan kode ini:

```cpp
  count -= i;
  if (count <= 0) {
	 cout << 0 << " ";
	 return;
  }
  ans = (ans * count) % MOD;
```

kode `count -= i` berguna untuk melakukan proses pengurangan pada tiap digitnya. Dimana pada posisi paling kiri, semua digit masih tersedia, sehingga tidak perlu dikurang, atau kurangi dengan nilai $i$, yang tepat sedang bernilai 0. Dan seterusnya, jelasnya bisa dilihat dibagian bawah!

Sebenarnya kita bisa saja menyimpan setiap nilai `count` kedalam vector, dan menghitung banyaknya kombinasi di proses terpisah, namun cara tersebut kurang efisien, karena kita jadi menggunakan 1 array tambahan yang sebenarnya tidak perlu.

Ketika nilai count kurang dari 0, artinya ada angka dari $B$ yang terlalu besar, bahkan lebih besar dari semua elemen di $A$. Atau digit yang tersedia untuk memenuhi syarat setiap $A_i > B_i$, sudah habis terpakai di digit yang lebih kiri. Ketika kondisi ini terjadi, maka ototmatis tidak ada kombinasi yang memenuhi syarat, sehingga kita langsung outputkan 0, dan berhenti. Ini cara yang bahkan jauh lebih efisien daripada editorial yang diberikan, karena kita langsung menghentikan program jika memang diawal sudah ditemukan kondisi yang jelas tidak akan memnuhi syarat.

Jika aman, maka kita tampung hasil perkalian antara nilai `ans` sekarang dengan `count`, lalu bagi dengan MOD, baru kita perbarui nilai dari `ans`.

Maka menjadi seperti ini:

$$
\text{kombinasi}=(2-0)\times(3-1)\times(4-2)\times(5-3)\times(6-4)\times(6-5)
$$
$$
\text{kombinasi}=2\cdot2\cdot2\cdot2\cdot2\cdot1
$$
$$
\text{kombinasi} = 32
$$



## 3.3 | Analisis Jawaban User Lain