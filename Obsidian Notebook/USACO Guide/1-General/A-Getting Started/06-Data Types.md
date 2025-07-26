---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Data Types
sumber:
  - USACO guide
date_learned: 2025-07-18T22:57:00
tags:
  - general-usaco
  - tipe-data
---
Link Sumber: 


```cardlink
url: https://usaco.guide/general/data-types?lang=cpp
title: "Data Types"
description: "The data types needed for competitive programming."
host: usaco.guide
favicon: https://usaco.guide/favicon-32x32.png?v=486b7e9b938c7be5463018a5e8da37f8
image: https://usaco.guide/static/2863837723a7041cb58da9f7856ce0fb/0ff54/social-media-image.jpg
```


---
# Data Types


> [!NOTE] Resources
> - [ ] [Fundamental Types](https://en.cppreference.com/w/cpp/language/types) -> sizes + ranges
> - [ ] [2.2 - Data Types](https://darrenyao.com/usacobook/cpp.pdf#page=11) -> module is based off this
> - [ ] [1.3 - Working with numbers](https://usaco.guide/CPH.pdf#page=16) -> Integers, Modular arithmetic, Floating point numbers
> - [ ] [2.3 - Variables & Types](https://usaco.guide/PAPS.pdf#page=35) -> plenty of exercises

---
## C++: Common Fundamental Data Types

Catatan: Angka-angka ini dapat bervariasi tergantung pada mesin dan/atau kompiler yang kamu gunakan. Untuk tipe data dasar yang lebih mendasar, lihat sumber pertama dalam tabel di atas.

| **Types**    | `int`             | `long long`       | `double`                   | `bool`                         | `char`          |
| ------------ | ----------------- | ----------------- | -------------------------- | ------------------------------ | --------------- |
| Description  | 32-bit integer    | 64-bit integer    | Double-precision float     | True/False value               | 8-bit character |
| Size (bytes) | 4                 | 8                 | 8                          | 1                              | 1               |
| Range        | $−2³¹$ to $2³¹−1$ | $−2⁶³$ to $2⁶³−1$ | $−1.7E+308$ to $+1.7E+308$ | $0$ or $1$ (`true` or `false`) | $−2⁷$ to $2⁷−1$ |

Terdapat beberapa tipe data utama yang sering digunakan dalam kompetisi pemrograman, yaitu: bilangan bulat (integer), bilangan pecahan (floating point), boolean, karakter, dan string. Jika kamu sudah familiar dengan bahasa pemrograman yang kamu gunakan, bagian ini seharusnya hanya menjadi ulasan saja.


Tipe data integer standar 32-bit (`int` di C++ dan Java) dapat menyimpan nilai dari $-2.147.483.648$ hingga $2.147.483.647$, atau kira-kira $\pm 2 \cdot 10^9$.

Beberapa soal mengharuskan kamu untuk menggunakan integer 64-bit (`long long` di C++ dan `long` di Java) alih-alih integer 32-bit. Integer 64-bit lebih jarang mengalami overflow, karena dapat menyimpan nilai dari $-9.223.372.036.854.775.808$ hingga $9.223.372.036.854.775.807$, atau kira-kira $\pm 9 \cdot 10^{18}$. Di Python, tipe `int` tidak memiliki batasan ukuran — kamu bisa menyimpan bilangan sebesar apa pun selama memori mencukupi.

Terkadang (walaupun tidak selalu), pernyataan soal USACO (contohnya seperti pada soal _Haircut_) akan memberikan peringatan seperti berikut:

> Perhatikan bahwa besarnya bilangan yang digunakan dalam soal ini mungkin mengharuskan penggunaan tipe data integer 64-bit (misalnya, `long long` di C/C++).


Dalam soal-soal kontes, biasanya bilangan integer 64-bit sudah cukup untuk menyelesaikan masalah. Oleh karena itu, pada divisi bawah (seperti Bronze dan Silver), sering kali disarankan untuk menggunakan integer 64-bit secara konsisten sebagai pengganti integer 32-bit.

Namun tentu saja, kamu tidak disarankan melakukan ini jika batasan waktu atau memori cukup ketat — hal ini bisa terjadi di divisi USACO yang lebih tinggi. Catatan khusus untuk Java: jika kamu menggunakan `long`, kamu perlu meng-cast kembali ke `int` saat mengakses indeks array, karena indeks array harus bertipe `int`.

Terdapat juga integer 16-bit (`short` di C++ dan Java), tetapi tipe ini jarang berguna karena penghematan memori yang dihasilkan biasanya sangat kecil. Unsigned integer juga tersedia (`unsigned int`, `unsigned long long`, dll). Meskipun jarang digunakan, tipe unsigned dapat menampung nilai dua kali lebih besar karena tidak menyimpan bilangan negatif. Dalam beberapa kasus, ini bisa menjadi perbedaan antara overflow dan tidak overflow.

---

Bilangan **floating point** digunakan untuk menyimpan angka desimal. Namun, floating point tidak akurat secara mutlak, karena representasi biner pada komputer hanya bisa menyimpan desimal hingga tingkat presisi tertentu. Artinya: Jangan pernah membandingkan dua bilangan floating point dengan $==$ secara langsung! Selalu anggap bahwa hasil perhitungan floating point **mungkin sedikit meleset**.

Dalam soal-soal kontes, biasanya ketidakakuratan ini sudah diperhitungkan. Penilaian dilakukan dengan cara memeriksa apakah selisih absolut atau relatif antara jawabanmu dan jawaban yang benar lebih kecil dari suatu konstanta kecil, misalnya: $\epsilon = 10^{-9}$

- Jika output-mu adalah $x$ dan jawaban yang benar adalah $y$, selisih absolut adalah: $|x - y|$

* Jika output-mu adalah $x$ dan jawaban yang benar adalah $y$, Selisih relatif adalah: $\frac{|x - y|}{|y|}$

Hal ini tidak berlaku untuk USACO, karena soal-soalnya biasanya hanya memiliki satu jawaban yang benar secara unik. Jika memang dibutuhkan angka pecahan (floating point), biasanya format outputnya akan seperti ini:

> Cetak nilai $10^6$ kali probabilitas maksimum menerima tepat satu undangan yang diterima, dibulatkan ke bawah ke bilangan bulat terdekat.
> Contoh: soal [Cow Dating](http://www.usaco.org/index.php?page=viewproblem2&cpid=924.

---

Variabel **boolean** hanya memiliki dua nilai: `true` dan `false`. Kita biasanya menggunakan boolean untuk menandai apakah sebuah proses sudah selesai. Kita juga sering menggunakan array boolean untuk menandai elemen-elemen (atau simpul) dalam suatu algoritma yang sudah diproses. Meskipun hanya menyimpan dua nilai, boolean tetap memerlukan 1 byte (8 bit), sehingga menyia-nyiakan 7 bit lainnya. Jika kamu ingin menghemat memori, kamu bisa menggunakan *bitset*:  `std::bitset` di **C++** atau `BitSet` di **Java**

Sayangnya, Python tidak memiliki dukungan bitset secara langsung.

---

Variabel **karakter** menyimpan satu karakter saja. Karakter biasanya dikembalikan saat kamu mengakses indeks tertentu dalam string. Karakter direpresentasikan menggunakan standar ASCII, yang mengasosiasikan tiap karakter dengan angka tertentu. Karena itu, kamu bisa melakukan operasi aritmatika terhadap karakter. Contoh:

* `cout << ('f' - 'a');` di C++
* `System.out.print('f' - 'a');` di Java

Keduanya akan mencetak **5**, karena `'f'` adalah karakter ke-6 dan `'a'` karakter ke-1 dalam alfabet (dimulai dari 0).

> Catatan:
> - Di Java, karakter menggunakan 16-bit
> - Di C/C++, karakter menggunakan 8-bit

---


**String** pada dasarnya adalah array dari karakter. Kamu bisa dengan mudah mengakses karakter tertentu melalui indeks, atau mengambil bagian dari string (substring).

Contoh di Java:

* `charAt(i)` → untuk mengambil karakter ke-`i`
* `substring(i, j)` → untuk mengambil substring dari indeks `i` hingga `j-1`

