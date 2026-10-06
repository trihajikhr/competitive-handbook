---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1843C
judul_FAST: Sum in Binary Tree
teori_FAST: Mengetahui hasil penjumlahan dari binary tree yang tersusun secara menaik, dengan cepat dan efisien
sumber:
  - codeforces
date_learned: 2025-08-01T11:13:00
tags:
  - tree-algorithm
  - STRIKE
---
Sumber: [Problem - 1843C - Codeforces](https://codeforces.com/problemset/problem/1843/C)

>[!NOTE] ⚔️  Teori STRIKE
>Bayangkan kita harus membuat tree, yang sangat-sangat besar, untuk melakukan penelusuran secara DFS, untuk menemukan dimana posisi dari node $x$. Itu sangat tidak efisien!
>
>Pendekatan ini menemukan cara yang sangat kreatif, dimana tanpa membuat tree, kita bisa menemukan jumlah dari semua jalur yang harus dilewati untuk sampai ke node bernilai $x$, dengan memanfaatkan pola-pola yang ada, pada binary tree yang memiliki nilai menaik tiap levelnya.

<br/>

---
# 1843C - Sum in Binary Tree

**Batas waktu per kasus uji**: 1 detik  
**Batas memori per kasus uji**: 256 megabyte

Vanya sangat menyukai matematika. Suatu hari ketika ia sedang menyelesaikan soal matematika lainnya, ia menciptakan sebuah pohon menarik. Pohon ini dibangun sebagai berikut:

![[1843C-Sum in Binary Tree-1.png]]

Awalnya, pohon hanya memiliki satu simpul dengan angka **1** — yaitu akar dari pohon tersebut. Kemudian, Vanya menambahkan dua anak ke simpul itu, dan memberikan mereka nomor berurutan — **2 dan 3**, secara berurutan. Setelah itu, dia akan menambahkan anak-anak ke setiap simpul dalam urutan naik berdasarkan nomornya, mulai dari **2**, dengan memberikan ke setiap simpul nomor terkecil yang belum digunakan.

Sebagai hasilnya, Vanya akan memiliki pohon biner tak hingga dengan akar pada simpul bernomor **1**, di mana setiap simpul akan memiliki **tepat dua anak**, dan nomor-nomor simpul akan diatur secara berurutan berdasarkan lapisan/layer.

📌 _Gambar pohon dimulai dari simpul 1, lalu 2 & 3, kemudian 4–7, lalu 8–15 (pohon biner sempurna)._

Vanya penasaran berapa jumlah semua nomor simpul pada jalur dari simpul bernomor **1** sampai ke simpul bernomor **n** dalam pohon seperti itu. Karena Vanya tidak suka menghitung, dia memintamu untuk membantunya.

### Input

Baris pertama berisi satu bilangan bulat **t** ($1 ≤ t ≤ 10⁴$) — jumlah kasus uji.

Setelah itu terdapat **t** baris — masing-masing berisi satu bilangan bulat **n** ($1 ≤ n ≤ 10¹⁶$) — nomor simpul yang ingin Vanya hitung jumlah semua nomor simpul dari akar ke simpul tersebut.
### Output

Untuk setiap kasus uji, cetak satu bilangan bulat — jumlah yang diinginkan.

<br/>

---
# Sesi STRIKE ⚔️
Sebelum melihat bagian editorial, aku menemukan beberapa petunjuk atau insight.

- Pertama, karena tree dibangung dengan data node yang dimulai dari 1, dan paling kiri, otomatis semua node akan memiliki nilai yang unik.
- Jika root adalah level 0, dan level dibawahnya adalah +1, maka setiap node pada level ke $x$, akan memiliki $2^{x}$ jumlah node.
- Node paling kiri memili selisih eksponensial, yaitu deretan node $1,2,4,8, \dots$.

<br/>

---
# Jawaban dan Editorial


Mudah untuk menyadari bahwa anak dari simpul (vertex) bernomor $u$ memiliki nomor:

- $2 \cdot u$ dan
- $2 \cdot u + 1$

Jadi, nenek moyang (ancestor) dari simpul $u$ memiliki nomor:

- $⌊u / 2⌋$


Berdasarkan rumus ini, panjang jalur dari simpul akar ke simpul bernomor $n$ adalah $⌊log₂(n)⌋$.

Dengan batasan yang diberikan, kita bisa menelusuri jalur ke akar secara eksplisit dan menghitung jumlah seluruh nomor simpul di jalur itu dalam waktu **O(log n)**.

> Kompleksitas total: `O(log n)` per kasus uji.

---

### 💡 Solusi (dalam Python):

```python
t = int(input())
for _ in range(t):
    n = int(input())
    s = 0
    while n >= 1:
        s += n
        n //= 2
    print(s)
```

## Analisis Pribadi
Jika ditulis dengan menggunakan bahasa C++, maka kodenya adalah seperti ini:

```cpp
#include <cmath>
#include <iostream>
using namespace std;

auto main() -> int {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);

   int t;
   cin >> t;
   while (t--) {
      long long n;
      cin >> n;
      long long sum = 0;

      while (n >= 1) {
         sum += n;
         n = floor(n / 2);
      }
      cout << sum << '\n';
   }
   return 0;
}
```

Banyaknya test case $t$ adalah $10^4$, sehingga tipe integer sudah cukup. Sedangkan inputan $n$, adalah sampai $10^{16}$, tipe data long long harus digunakan, karena melebihi $10^9$ yang mampu ditampung oleh integer biasa.

Lakukan perulangan dengan while, dimana jika nilai $n \geq 1$, maka perulangan berlanjut. Tujuan kita disini adalah naik dari node asal ke node parentnya, hingga sampai ke node root.

Dalam setiap perulangan, siapkan variabel sum dan tampung setiap perubahan nilai $n$ pada sum. Setiap perulangan, kita melakukan mekanisme naik ke parent dari node, dengan cara membagi nilai $n$ dengan 2, lalu hasilnya dibulatkan ke bawah.  Seperti pada contoh diatas.

Setelah perulangan selesai, maka nilai sum dari root ke node $n$ berhasil kita dapatkan. Lalu outputkan saja langsung.