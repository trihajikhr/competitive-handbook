---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Bit manipulation
sumber:
  - cp-algorithms.com
date_learned: 2025-10-13T15:52:00
tags:
  - bitwise
  - bit-representation
---
Link Sumber: [Bit manipulation - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/bit-manipulation.html)

---
# 1 | Bit Manipulation

## 1.1 | Bilangan Biner (Binary Number)

**Bilangan biner** adalah bilangan yang diekspresikan dalam sistem bilangan basis-2 (sistem bilangan biner). Ini adalah metode ekspresi matematis yang hanya menggunakan dua simbol: biasanya "**0**" (nol) dan "**1**" (satu).

Kita katakan bahwa suatu bit tertentu **disetel (set)** jika nilainya satu (1), dan **dibersihkan (cleared)** jika nilainya nol (0).

Bilangan biner $\large(a_k a_{k-1} \dots a_1 a_0)_2$ merepresentasikan bilangan:
$$\large(a_k a_{k-1} \dots a_1 a_0)_2 = a_k \cdot 2^k + a_{k-1} \cdot 2^{k-1} + \dots + a_1 \cdot 2^1 + a_0 \cdot 2^0.$$

Sebagai contoh, bilangan biner $\large 1101_2$ merepresentasikan bilangan $\large 13$:
$$\large \begin{align} 1101_2 &= 1 \cdot 2^3 + 1 \cdot 2^2 + 0 \cdot 2^1 + 1 \cdot 2^0 \\ &= 1\cdot 8 + 1 \cdot 4 + 0 \cdot 2 + 1 \cdot 1 = 13 \end{align}$$

Komputer merepresentasikan bilangan bulat (integer) sebagai bilangan biner. Bilangan bulat positif (baik bertanda (signed) maupun tidak bertanda (unsigned)) direpresentasikan dengan digit-digit binernya, dan bilangan bertanda negatif biasanya direpresentasikan menggunakan **Komplemen Dua (Two's complement)**.

```cpp
unsigned int unsigned_number = 13;
assert(unsigned_number == 0b1101);

int positive_signed_number = 13;
assert(positive_signed_number == 0b1101);

int negative_signed_number = -13;
assert(negative_signed_number == 0b1111'1111'1111'1111'1111'1111'1111'0011);
```

CPU sangat cepat memanipulasi bit-bit ini dengan operasi-operasi spesifik. Untuk beberapa masalah, kita dapat memanfaatkan representasi bilangan biner ini untuk mempercepat waktu eksekusi. Dan untuk beberapa masalah (khususnya dalam kombinatorika atau pemrograman dinamis) di mana kita ingin melacak objek mana yang sudah kita ambil dari himpunan objek tertentu, kita cukup menggunakan bilangan bulat yang cukup besar di mana setiap digit merepresentasikan sebuah objek, dan bergantung pada apakah kita mengambil atau membuang objek tersebut, kita menyetel atau membersihkan digitnya.

## 1.2 | Operator Bit (Bit Operators)

Semua operator yang diperkenalkan ini bekerja secara instan (kecepatan yang sama dengan operasi penjumlahan) pada CPU untuk bilangan bulat dengan panjang tetap (*fixed-length integers*).

### 1.2.1 | Operator Bitwise (Bitwise Operators)

|    Operator     |         Nama Operator          | Cara Kerja                                                                                                                                                                                                                                |
| :-------------: | :----------------------------: | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|   $\large \&$   |          Bitwise AND           | Membandingkan setiap bit dari operand pertama dengan bit yang bersesuaian pada operand kedua. Jika kedua bit adalah 1, maka bit hasilnya disetel menjadi 1. Selain itu, bit hasilnya disetel menjadi 0.                                   |
|       \|        |    Bitwise Inclusive OR    | Membandingkan setiap bit dari operand pertama dengan bit yang bersesuaian pada operand kedua. Jika salah satu dari kedua bit adalah 1, maka bit hasilnya disetel menjadi 1. Selain itu, bit hasilnya disetel menjadi 0.                   |
| $\large \wedge$ | Bitwise Exclusive OR (XOR) | Membandingkan setiap bit dari operand pertama dengan bit yang bersesuaian pada operand kedua. Jika satu bit adalah 0 dan bit lainnya adalah 1 (berbeda), maka bit hasilnya disetel menjadi 1. Selain itu, bit hasilnya disetel menjadi 0. |
|  $\large \sim$  |  Bitwise Complement (NOT)  | Membalik setiap bit pada sebuah bilangan. Jika suatu bit disetel (1), operator akan membersihkannya (0), dan sebaliknya.                                                                                                                  |

Contoh-contoh:

$$\begin{array}{rcl} n &=& 01011000 \\ n-1 &=& 01010111 \\ \hline n \ \& \ (n-1) &=& \mathbf{01010000} \end{array}$$

$$\begin{array}{rcl} n &=& 01011000 \\ n-1 &=& 01010111 \\ \hline n \ | \ (n-1) &=& \mathbf{01011111} \end{array}$$

$$\begin{array}{rcl} n &=& 01011000 \\ n-1 &=& 01010111 \\ \hline n \ \wedge \ (n-1) &=& \mathbf{00001111} \end{array}$$

$$\begin{array}{rcl} n &=& 01011000 \\ \hline \sim n &=& \mathbf{10100111} \end{array}$$

### 1.2.2 | Operator Geser (Shift Operators)

Terdapat dua operator untuk menggeser bit:

1.  Operator Geser Kanan / Right Shift ($\large \gg$):
    * Menggeser sebuah bilangan ke kanan dengan menghilangkan beberapa digit biner terakhir.
    * Setiap geseran ke kanan sebesar satu posisi mewakili pembagian integer dengan 2. Jadi, geser kanan sebesar $\large k$ posisi merepresentasikan pembagian integer dengan $\large 2^k$.
    * *Contoh:* $\large 5 \gg 2 = 101_2 \gg 2 = 1_2 = 1$. Hal ini sama dengan $\large \frac{5}{2^2} = \frac{5}{4} = 1$ (pembagian integer). Di komputer, menggeser bit jauh lebih cepat daripada melakukan pembagian.

2.  Operator Geser Kiri / Left Shift ($\large \ll$):
    * Menggeser sebuah bilangan ke kiri dengan menambahkan digit nol di belakang.
    * Sama seperti geser kanan, geser kiri sebesar $\large k$ posisi merepresentasikan perkalian dengan $\large 2^k$.
    * *Contoh:* $\large 5 \ll 3 = 101_2 \ll 3 = 101000_2 = 40$. Hal ini sama dengan $\large 5 \cdot 2^3 = 5 \cdot 8 = 40$.
    * Perhatikan, untuk bilangan bulat dengan panjang tetap, ini berarti digit yang paling kiri akan terbuang, dan jika Anda menggeser terlalu banyak, Anda akan berakhir dengan nilai 0.

<br/>

---

# 2 | Trik Berguna (Useful Tricks)

## 2.1 | Menyetel/Membalik/Membersihkan sebuah Bit

Dengan menggunakan pergeseran bitwise (*bitwise shifts*) dan beberapa operasi bitwise dasar, kita dapat dengan mudah menyetel (set), membalik (flip), atau membersihkan (clear) sebuah bit.

  * $\large 1 \ll x$ adalah bilangan yang hanya memiliki bit ke-$\large x$ yang disetel.
  * $\large \sim(1 \ll x)$ adalah bilangan yang semua bit-nya disetel, kecuali bit ke-$\large x$.

| Operasi | Rumus | Deskripsi |
| :--- | :--- | :--- |
| **Setel (Set)** bit ke-$\large x$ | $\large n ~|~ (1 \ll x)$ | Menggunakan **OR** untuk memastikan bit ke-$\large x$ pada $\large n$ menjadi 1. |
| **Balik (Flip)** bit ke-$\large x$ | $\large n ~\wedge~ (1 \ll x)$ | Menggunakan **XOR** untuk membalik nilai bit ke-$\large x$ pada $\large n$ (0 menjadi 1, 1 menjadi 0). |
| **Bersihkan (Clear)** bit ke-$\large x$ | $\large n ~\&~ \sim(1 \ll x)$ | Menggunakan **AND** dengan masker yang semua bit-nya 1 kecuali bit ke-$\large x$ (yang bernilai 0), sehingga bit ke-$\large x$ pada $\large n$ menjadi 0. |

-----

### Memeriksa Apakah sebuah Bit Disetel

Nilai bit ke-$\large x$ dapat diperiksa dengan menggeser bilangan tersebut $\large x$ posisi ke kanan ($\large \gg x$), sehingga bit ke-$\large x$ berada di posisi satuan. Setelah itu, kita bisa mengekstrak nilainya dengan melakukan operasi **Bitwise AND** dengan 1 ($\large \& 1$).

```cpp
bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}
```

  * Jika bit ke-$\large x$ adalah 1, hasilnya akan menjadi 1 (true).
  * Jika bit ke-$\large x$ adalah 0, hasilnya akan menjadi 0 (false).

-----

### Memeriksa Apakah Bilangan Habis Dibagi oleh Pangkat dari 2

Dengan menggunakan operasi AND ($\large \&$), kita dapat memeriksa apakah sebuah bilangan $\large n$ **genap** karena $\large n ~\&~ 1 = 0$ jika $\large n$ genap, dan $\large n ~\&~ 1 = 1$ jika $\large n$ ganjil.

Secara lebih umum, $\large n$ habis dibagi oleh $\large 2^k$ tepat ketika $\large n ~\&~ (2^k - 1) = 0$.

```cpp
bool isDivisibleByPowerOf2(int n, int k) {
    int powerOf2 = 1 << k;
    return (n & (powerOf2 - 1)) == 0;
}
```

Kita dapat menghitung $\large 2^k$ dengan menggeser angka 1 ke kiri sebanyak $\large k$ posisi ($\large 1 \ll k$).

Trik ini berfungsi karena:

1.  $\large 2^k - 1$ adalah bilangan yang terdiri dari tepat $\large k$ buah digit **satu** (1). Misalnya, jika $k=3$, maka $2^3 - 1 = 7$, dan $7$ dalam biner adalah $111_2$.
2.  Sebuah bilangan yang habis dibagi $\large 2^k$ harus memiliki digit nol (0) di $\large k$ posisi bit paling kanan (bit ke 0 hingga $k-1$).
3.  Ketika kita melakukan operasi $\large AND$ dengan $\large 2^k - 1$ (yang merupakan masker $\underbrace{11\dots1}_{k}$), hasilnya harus **0** jika semua bit terendah $\large n$ adalah nol.

## 3.1 | Memeriksa Apakah Bilangan Bulat Adalah Pangkat dari 2

Sebuah bilangan yang merupakan pangkat dari dua ($\large 2^k$) adalah bilangan yang hanya memiliki satu bit yang disetel (misalnya, $\large 32 = 0010\ 0000_2$). Sementara itu, bilangan pendahulu (predecessor) dari bilangan tersebut ($\large n-1$) memiliki bit tersebut tidak disetel dan semua bit setelahnya disetel (misalnya, $\large 31 = 0001\ 1111_2$).

Oleh karena itu, operasi Bitwise AND dari sebuah bilangan ($\large n$) dengan pendahulunya ($\large n-1$) akan selalu menghasilkan 0 jika dan hanya jika $\large n$ adalah pangkat dari 2, karena mereka tidak memiliki bit yang disetel secara bersamaan (umum).

Perhatikan bahwa trik ini hanya berlaku untuk pangkat dari 2 dan untuk bilangan 0 (yang sudah tidak memiliki bit yang disetel). Untuk mengecualikan 0, kita menambahkan kondisi $\large n$.

```cpp
bool isPowerOfTwo(unsigned int n) {
    // n && memastikan n bukan 0.
    // !(n & (n - 1)) memastikan hanya satu bit yang disetel.
    return n && !(n & (n - 1));
}
```

-----

### Membersihkan Bit yang Disetel Paling Kanan (Clear the Right-most Set Bit)

Ekspresi $\large n ~\&~ (n-1)$ dapat digunakan untuk **mematikan** (membersihkan/mengubah menjadi 0) bit yang disetel paling kanan dari sebuah bilangan $\large n$.

Cara kerjanya:

1.  Ekspresi $\large n-1$ akan membalik semua bit setelah bit yang disetel paling kanan dari $\large n$, **termasuk** bit yang disetel paling kanan itu sendiri (menjadi 0).
2.  Semua digit tersebut (dari bit paling kanan hingga bit yang disetel paling kanan) akan berbeda dari bilangan aslinya $\large n$.
3.  Dengan melakukan **Bitwise AND** ($\large \&$), semua bit yang berbeda tersebut akan menjadi 0, menghasilkan bilangan $\large n$ asli dengan hanya bit yang disetel paling kanan yang diubah menjadi 0.

Sebagai contoh, perhatikan bilangan $\large 52 = 0011\ 0100_2$ (bit yang disetel paling kanan adalah pada posisi ke-2):

$$\begin{array}{rcl} n &=& 001101\mathbf{00} \\ n-1 &=& 001100\mathbf{11} \\ \hline n \ \& \ (n-1) &=& \mathbf{00110000} \end{array}$$

-----

### Algoritma Brian Kernighan (Brian Kernighan's Algorithm)

Kita dapat menghitung jumlah bit yang disetel (*set bits*) dalam sebuah bilangan bulat menggunakan ekspresi di atas.

Idenya adalah hanya mempertimbangkan bit-bit yang disetel dari bilangan bulat $\large n$ dengan cara mematikan bit yang disetel paling kanannya (setelah dihitung), sehingga iterasi loop berikutnya mempertimbangkan bit disetel paling kanan berikutnya.

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // Mematikan bit yang disetel paling kanan
        count++;         // Hitung bit yang baru saja dimatikan
    }
    return count;
}
```

Algoritma ini sangat efisien karena jumlah perulangan (*loop*) yang dilakukan sama dengan **jumlah bit yang disetel** (*population count* atau *popcount*), bukan berdasarkan jumlah total bit dalam bilangan (misalnya, 32 atau 64 bit).


Tentu, berikut terjemahan dari materi yang tersisa mengenai **Count Set Bits Upto $\large n$** dan bagian penutup lainnya.

## Menghitung Jumlah Bit yang Disetel Hingga $\large n$ (Count Set Bits Upto $\large n$)

-----

Untuk menghitung jumlah bit yang disetel dari semua bilangan bulat hingga bilangan $\large n$ (termasuk $\large n$), menjalankan Algoritma Brian Kernighan pada setiap bilangan hingga $\large n$ akan mengakibatkan **"Time Limit Exceeded"** dalam kontes pemrograman.

Kita dapat menggunakan fakta bahwa untuk bilangan hingga $\large 2^x$ (yaitu, dari $\large 1$ sampai $\large 2^x - 1$), terdapat $\large x \cdot 2^{x-1}$ bit yang disetel. Ini dapat divisualisasikan sebagai berikut:

$$\begin{array}{cccccc} 0 & \to & 0 & 0 & 0 & 0 \\ 1 & \to & 0 & 0 & 0 & 1 \\ 2 & \to & 0 & 0 & 1 & 0 \\ 3 & \to & 0 & 0 & 1 & 1 \\ 4 & \to & 0 & 1 & 0 & 0 \\ 5 & \to & 0 & 1 & 0 & 1 \\ 6 & \to & 0 & 1 & 1 & 0 \\ 7 & \to & 0 & 1 & 1 & 1 \\ 8 & \to & 1 & 0 & 0 & 0 \end{array}$$

Kita dapat melihat bahwa semua kolom bit kecuali yang paling kiri memiliki $\large 4$ (yaitu $\large 2^2$) bit yang disetel di setiap kolom. Artinya, hingga bilangan $\large 2^3 - 1$ (yaitu 7), jumlah bit yang disetel adalah $\large 3 \cdot 2^{3-1} = 12$.

Dengan pengetahuan baru ini, kita dapat merancang algoritma berikut:

1.  Temukan pangkat tertinggi dari $\large 2$ yang lebih kecil atau sama dengan bilangan $\large n$ yang diberikan. Misalkan bilangan ini adalah $\large 2^x$.
2.  Hitung jumlah bit yang disetel dari $\large 1$ hingga $\large 2^x - 1$ menggunakan rumus $\large x \cdot 2^{x-1}$.
3.  Hitung jumlah bit yang disetel pada **bit paling signifikan (Most Significant Bit/MSB)** dari $\large 2^x$ hingga $\large n$ dan tambahkan ke total.
4.  Kurangi $\large 2^x$ dari $\large n$ dan ulangi langkah-langkah di atas menggunakan $\large n$ yang baru.

<!-- end list -->

```cpp
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        // x adalah eksponen, sehingga 2^x <= n. bit_width(n) mengembalikan jumlah bit yang diperlukan untuk menyimpan n, 
        // sehingga bit_width(n) - 1 adalah x (indeks bit tertinggi).
        int x = std::bit_width(n) - 1; 
        
        // 1. Tambahkan jumlah set bit dari 1 hingga 2^x - 1
        // x << (x - 1) sama dengan x * 2^(x-1)
        count += x << (x - 1); 
        
        // 2. Kurangi 2^x dari n (Menghilangkan MSB dari n)
        // 1 << x sama dengan 2^x
        n -= 1 << x;             
        
        // 3. Tambahkan n + 1 (Jumlah bilangan dari 2^x hingga n) 
        // sebagai kontribusi dari MSB yang kita kurangi tadi.
        count += n + 1;          
    }
    return count;
}
```

-----

## Trik Tambahan (Additional Tricks)

-----

  * $\large n ~\&~ (n + 1)$: **Membersihkan semua bit satu di belakang (trailing ones):** $\large 0011\ 0111_2 \rightarrow 0011\ 0000_2$.
  * $\large n ~|~ (n + 1)$: **Menyetel bit nol terakhir yang dibersihkan:** $\large 0011\ 0101_2 \rightarrow 0011\ 0111_2$.
  * $\large n ~\&~ -n$: **Mengekstrak bit yang disetel terakhir (least significant set bit):** $\large 0011\ 0100_2 \rightarrow 0000\ 0100_2$.

Banyak trik lainnya dapat ditemukan dalam buku *Hacker's Delight*.

-----

## Dukungan Bahasa dan Compiler (Language and Compiler Support)

-----

**C++20** mendukung beberapa operasi tersebut melalui *standard library* `bit`:

  * `has_single_bit`: Memeriksa apakah bilangan adalah pangkat dari dua.
  * `bit_ceil` / `bit_floor`: Membulatkan ke atas/bawah ke pangkat dari dua berikutnya.
  * `rotl` / `rotr`: Memutar bit dalam bilangan (rotasi).
  * `countl_zero` / `countr_zero` / `countl_one` / `countr_one`: Menghitung nol/satu di depan/belakang.
  * **`popcount`**: Menghitung jumlah bit yang disetel.

Selain itu, terdapat juga **fungsi *predefined* (bawaan) pada beberapa *compiler***, seperti GCC, yang membantu bekerja dengan bit (berfungsi juga pada versi C++ yang lebih lama):

  * `__builtin_popcount(unsigned int)`: Mengembalikan jumlah bit yang disetel. (Contoh: `__builtin_popcount(0b0001'0010'1100) == 4`).
  * `__builtin_ffs(int)`: Menemukan indeks bit yang disetel pertama (paling kanan). (Contoh: `__builtin_ffs(0b0001'0010'1100) == 3`).
  * `__builtin_clz(unsigned int)`: Jumlah nol di depan (*leading zeros*). (Contoh: `__builtin_clz(0b0001'0010'1100) == 23`).
  * `__builtin_ctz(unsigned int)`: Jumlah nol di belakang (*trailing zeros*). (Contoh: `__builtin_ctz(0b0001'0010'1100) == 2`).
  * `__builtin_parity(x)`: Paritas (genap atau ganjil) dari jumlah bit satu dalam representasi biner.

**Catatan:** Beberapa operasi (baik fungsi C++20 maupun fungsi bawaan Compiler) mungkin cukup lambat di GCC jika Anda tidak mengaktifkan target *compiler* tertentu dengan `#pragma GCC target("popcnt")`.