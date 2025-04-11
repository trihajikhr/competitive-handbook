---
obsidianUIMode: preview
note_type: tips trick
tips_trick: bekerja dengan angka
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
tags:
  - introduction
  - matematika
---
#introduction  #matematika 
# Bekerja dengan Angka

## Integers / Bilangan Bulat

Tipe bilangan bulat yang paling sering digunakan dalam _competitive programming_ adalah `int`, yang merupakan tipe 32-bit dengan rentang nilai $-2^{31} \dots 2^{31}-1$ atau sekitar $-2\cdot10^9 \dots 2\cdot10^9$. Jika tipe `int` tidak cukup, maka tipe 64-bit `long long` dapat digunakan. Tipe ini memiliki rentang nilai $-2^{63} \dots 2^{63}-1$ atau sekitar $-9\cdot10^8 \dots 9\cdot10^{18}$.

Kode berikut mendefinisikan sebuah variabel `long long`:

```cpp
long long x = 123456789123456789LL;
```

Akhiran `LL` menunjukkan bahwa tipe angka tersebut adalah `long long`.

Kesalahan umum saat menggunakan tipe `long long` adalah masih menggunakan tipe `int` di beberapa bagian kode. Misalnya, kode berikut mengandung kesalahan halus:

```cpp
int a = 123456789;
long long b = a * a;
cout << b << "\n"; // Output: -1757895751 (salah!)
```

Meskipun variabel `b` bertipe `long long`, kedua angka dalam ekspresi `a * a` bertipe `int`, sehingga hasilnya juga bertipe `int`. Akibatnya, variabel `b` akan berisi hasil yang salah.

Masalah ini dapat diselesaikan dengan mengubah tipe `a` menjadi `long long` atau dengan mengubah ekspresi menjadi `(long long)a * a`, seperti berikut:

```cpp
long long a = 123456789;
long long b = a * a;
cout << b << "\n"; // Output yang benar
```

Atau:

```cpp
int a = 123456789;
long long b = (long long)a * a;
cout << b << "\n"; // Output yang benar
```

Biasanya, soal dalam kompetisi telah disusun sedemikian rupa sehingga tipe `long long` sudah cukup untuk menangani angka besar. Namun, perlu diketahui bahwa _compiler_ `g++` juga menyediakan tipe 128-bit `__int128_t` dengan rentang nilai $-2^{127} \dots 2^{127}-1$ atau sekitar $-10^{38} \dots 10^{38}$.

Meskipun demikian, tipe `__int128_t` tidak tersedia di semua sistem kontes.

---

## Aritmetika Modular

Kita menyatakan $x \mod m$ sebagai sisa pembagian $x$ oleh $m$. Sebagai contoh:
$17 \, mod  5 = 2$, karena $17=3⋅5+2$.

Dalam beberapa soal, jawaban yang dihasilkan bisa berupa angka yang sangat besar. Namun, cukup mencetak hasilnya dalam bentuk "_modulo m_", yaitu sisa hasil bagi ketika jawaban dibagi dengan $m$. (misalnya, "modulo $10^9+7$").

Dengan cara ini, meskipun jawaban sebenarnya sangat besar, kita hanya perlu menggunakan tipe data `int` atau `long long`.

Salah satu sifat penting dari operasi modulus adalah bahwa dalam operasi penjumlahan, pengurangan, dan perkalian, kita bisa mengambil sisa hasil bagi sebelum melakukan operasi tersebut:

$$(a+b) \mod m = (a \mod m + b \mod m) \mod m$$
$$(a-b) \mod m = (a \mod m - b \mod m) \mod m $$
$$(a\cdot b) \mod m = (a \mod m \cdot b \mod m) \mod m$$

Dengan cara ini, kita dapat mengambil modulus setelah setiap operasi agar angka tidak menjadi terlalu besar.

Sebagai contoh, kode berikut menghitung faktorial dari $n$, yaitu $n!$, dalam modulo $m$:

```cpp
long long x = 1;
for (int i = 2; i <= n; i++) {
    x = (x * i) % m;
}
cout << x % m << "\n";
```

Biasanya, kita ingin sisa hasil bagi selalu berada dalam rentang $0 \dots m-1$. Namun, dalam C++ dan bahasa pemrograman lain, sisa dari bilangan negatif bisa bernilai nol atau negatif. Cara mudah untuk memastikan hasilnya selalu positif adalah dengan terlebih dahulu menghitung modulus seperti biasa, lalu menambahkan $m$ jika hasilnya negatif:

```cpp
x = x % m;
if (x < 0) x += m;
```

Namun, ini hanya diperlukan ketika ada operasi pengurangan dalam kode yang dapat menyebabkan hasil negatif.

---

## Bilangan Floating Point

Tipe data _floating point_ yang umum digunakan dalam _competitive programming_ adalah `double` (64-bit) dan, sebagai ekstensi pada _compiler_ `g++`, `long double` (80-bit). Dalam kebanyakan kasus, `double` sudah cukup, tetapi `long double` memiliki presisi yang lebih tinggi.

Biasanya, soal akan menentukan tingkat presisi yang diperlukan dalam jawaban. Cara mudah untuk mencetak angka dengan presisi tertentu adalah menggunakan fungsi `printf` dan menentukan jumlah angka desimal dalam format string. Sebagai contoh, kode berikut mencetak nilai `x` dengan 9 angka desimal:

```cpp
printf("%.9f\n", x);
```

Salah satu kesulitan dalam menggunakan _floating point_ adalah bahwa beberapa angka tidak dapat direpresentasikan dengan presisi sempurna, sehingga akan terjadi kesalahan pembulatan. Misalnya, perhatikan hasil berikut:

```cpp
double x = 0.3 * 3 + 0.1;
printf("%.20f\n", x); // 0.99999999999999988898
```

Hasilnya mengejutkan karena nilai `x` ternyata sedikit lebih kecil dari 1, padahal secara matematis hasil yang benar adalah 1.

### Perbandingan Bilangan Floating Point

Karena adanya kesalahan pembulatan, membandingkan _floating point_ menggunakan operator (**=** **=**) sangat berisiko. Dua angka yang seharusnya sama bisa dianggap berbeda karena perbedaan kecil dalam representasi biner. Solusi yang lebih baik adalah menganggap dua angka sama jika perbedaan absolutnya lebih kecil dari $\varepsilon$ (_epsilon_), yaitu angka kecil yang mewakili batas toleransi kesalahan.

Sebagai contoh, untuk $\varepsilon = 10^{-9}$, kita dapat membandingkan dua angka sebagai berikut:

```cpp
if (abs(a - b) < 1e-9) {
    // a dan b dianggap sama
}
```

Meskipun bilangan _floating point_ memiliki keterbatasan presisi, _integer_ hingga batas tertentu masih bisa direpresentasikan dengan akurat. Sebagai contoh, dengan `double`, kita bisa merepresentasikan semua bilangan bulat dengan nilai absolut hingga $2^{53}$ secara akurat.