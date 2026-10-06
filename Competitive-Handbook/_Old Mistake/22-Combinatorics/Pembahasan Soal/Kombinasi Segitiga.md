---
obsidianUIMode: preview
note_type: latihan
latihan: Kombinasi Segitiga
sumber:
  - tlx-toki.id
tags:
  - combinatorics
date_learned: 2026-02-10T02:54:00
---
Link Sumber: [tlx.toki.id/courses/competitive-1/chapters/02/problems/P1](https://tlx.toki.id/courses/competitive-1/chapters/02/problems/P1)

---
> [!IMPORTANT]
# 1. Kombinasi Segitiga

Pak Dengklek ingin membuat sebuah kandang baru untuk bebek-bebeknya. Dengan alasan estetika, Pak Dengklek ingin kandang baru tersebut berbentuk segitiga.

Untungnya, di halaman rumah Pak Dengklek sudah terpasang $N$ buah pasak pada lokasi-lokasi tertentu. Pasak-pasak tersebut dinomori dari $1$ sampai dengan $N$. Halaman rumah Pak Dengklek dapat dianalogikan sebagai koordinat kartesius. Pasak ke-$i$ terdapat pada lokasi ($x_i$, $y_i$).

Titik-titik sudut dari kandang harus dibentuk dari tiga pasak di antara pasak-pasak yang sudah terpasang tersebut. Pak Dengklek bingung menentukan tiga buah pasak mana yang harus ia pilih karena terdapat banyak sekali cara.

### Tugas Anda

Bantulah Pak Dengklek untuk menghitung banyaknya cara memilih tiga pasak untuk membuat kandang baru. Dua buah cara dianggap berbeda jika terdapat setidaknya satu pasak yang lokasinya berbeda di antara kedua cara tersebut.

### Format Masukan

Baris pertama berisi sebuah bilangan bulat $N$. Kemudian $N$ baris berikutnya masing-masing berisi dua buah bilangan bulat $x_i$ dan $y_i$ dipisahkan oleh sebuah spasi yang menyatakan lokasi pasak ke-$i$.

### Format Keluaran

Sebuah baris berisi sebuah bilangan bulat yaitu banyaknya cara Pak Dengklek dapat membuat kandang baru.

### Batasan
- $1 \leq n \leq 16$
- $-1000 \leq x_i \leq 1000$
- $-1000 \leq y_i \leq 1000$
- Dijamin tidak ada dua pasak yang berada pada posisi yang sama dan tidak ada tiga pasak yang dapat membentuk sebuah garis lurus.

<br/>

---
# 2. Jawaban

Berikut adalah jawabanku:

```cpp
#include <iostream>
#include <vector>
using namespace std;

long long combi(long long n, long long k = 3) {
    long long ans = 1;
    for (long long i = n - k + 1; i <= n; i++) {
        ans *= i;
    }

    for (long long i = 2; i <= k; i++) {
        ans /= i;
    }

    return ans;
}

auto main() -> int {
    long long n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (auto& x : vec) {
        cin >> x.first >> x.second;
    }

    cout << combi(n);
    return 0;
}
```

<br/>

---
# 3. Editorial

Perhatikan bahwa kita tidak mengolah lokasi titik-titik koordinat yang diberikan. Hal ini karena soal menjamin bahwa tidak akan ada 3 pasak yang berada dalam satu garis lurus, yang artinya semua pemilihan titik dipastikan dapat membentuk segitiga, sehingga informasi titik-titik pasak menjadi tidak perlu diperhitungkan.

Disini solusinya mudah, kita hanya perlu menggunakan rumus kombinasi, yaitu dengan menerapkan formula:

$$\binom{n}{k}=\frac{n!}{k! \cdot (n-k)!}$$
Tugas kita adalah mencari banyaknya kombinasi segitiga yang bisa dibentuk, dari setiap memilih $3$ pasak atau titik, sehingga kita bisa menerapakan rumus diatas dengan nilai $k=3$.

Kita melakukan perhitungan dengan mencari nilai dari $\frac{n!}{(n-k)!}$ terlebih dahulu dengan mencari hasil dari perkalian yang dimulai dari $(n-k+1)$ hingga $n$. Setelah itu memulai pembagian dengan $k!$ secara langsung, yaitu dengan melakukan pembagian pada setiap iterasinya.

```cpp
long long combi(long long n, long long k = 3) {
    long long ans = 1;
    for (long long i = n - k + 1; i <= n; i++) {
        ans *= i;
    }
    for (long long i = 2; i <= k; i++) {
        ans /= i;
    }
    return ans;
}
```

Soal yang cukup mengecoh, namun bagus untuk berlatih konsep kombinasi.