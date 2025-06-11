---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: C++ Bitwise Operators
sumber: programiz.com
date_learned: 2025-06-09T18:56:00
tags:
  - bits
  - bitwise
---
Link Sumber: [C++ Bitwise Operators](https://www.programiz.com/cpp-programming/bitwise-operators)

---
# C++ Bitwise Operators

Dalam C++, operator bitwise melakukan operasi pada data bertipe integer di tingkat bit secara individual. Operasi-operasi ini mencakup pengujian, penyetelan (setting), atau penggeseran (shifting) bit-bit secara langsung. Sebagai contoh:

```cpp
a & b;
a | b;
```

Berikut adalah daftar 6 operator bitwise yang tersedia dalam C++.

| Operator | Nama (Inggris)           | Deskripsi (Bahasa Indonesia)                                                                                                      |
| :------: | :----------------------- | :-------------------------------------------------------------------------------------------------------------------------------- |
|    &     | Bitwise AND              | Menghasilkan 1 hanya jika kedua bit operan bernilai 1, selain itu menghasilkan 0.                                                 |
|    \|    | Bitwise OR               | Menghasilkan 1, jika salah satu operan bernilai 1.                                                                                |
|    ^     | Bitwise XOR              | Menghasilkan 1 hanya jika **salah satu**, tapi **bukan kedua**, operan bernilai 1; jika sama (keduanya 0 atau 1) maka hasilnya 0. |
|    ~     | Bitwise Complement (NOT) | Operator unary yang membalik semua bit (1 jadi 0, 0 jadi 1).                                                                      |
|    <<    | Bitwise Left Shift       | Menggeser semua bit operan ke kiri sejumlah posisi tertentu; posisi kosong diisi 0.                                               |
|    >>    | Bitwise Right Shift      | Menggeser semua bit operan ke kanan sejumlah posisi tertentu.                                                                     |
Operator-operator ini penting karena Unit Aritmatika dan Logika (Arithmetic-Logic Unit / ALU) yang terdapat di CPU komputer melakukan operasi aritmatika pada tingkat bit.

**Catatan:** Operator bitwise hanya dapat digunakan bersama tipe data `char` dan `int`.

---

## 1 | Operator Bitwise AND di C++

Operator bitwise **AND** `&` mengembalikan nilai **1 hanya jika kedua operan bernilai 1**. Jika tidak, maka hasilnya adalah 0.

Tabel berikut menunjukkan cara kerja operator bitwise AND. Misalkan `a` dan `b` adalah dua operan yang hanya dapat bernilai biner, yaitu 1 atau 0:

![[Programmiz - C++ Bitwise Operators-1.png]]


**Catatan:** Tabel di atas dikenal sebagai **"Tabel Kebenaran (Truth Table)"** untuk operator bitwise AND.

Sekarang mari kita lihat operasi bitwise AND antara dua bilangan bulat **12** dan **25**:

```cpp
12 = 00001100 (dalam biner)
25 = 00011001 (dalam biner)

// Operasi Bitwise AND antara 12 dan 25

     00001100
&    00011001
     --------
     00001000  = 8 (dalam desimal)
```

### Contoh: Operasi Bitwise AND
```cpp
#include <iostream>
using namespace std;

int main() {
    // declare variables
    int a = 12, b = 25;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a & b = " << (a & b) << endl;

    return 0;
}
```

Output:
```
a = 12
b = 25
a & b = 8
```

Pada contoh di atas, kita telah mendeklarasikan dua variabel `a` dan `b`. Perhatikan baris berikut ini:

```cpp
cout << "a & b = " << (a & b) << endl;
```

Di sini, kita melakukan operasi **bitwise AND** antara variabel `a` dan `b`.

---
## 2 | Operator Bitwise OR di C++

Operator bitwise **OR** `|` mengembalikan nilai **1 jika setidaknya salah satu operan bernilai 1**. Jika tidak, maka hasilnya adalah 0.

Tabel kebenaran berikut menunjukkan cara kerja operator bitwise OR. Misalkan `a` dan `b` adalah dua operan yang hanya dapat bernilai biner, yaitu 1 atau 0:

![[Programmiz - C++ Bitwise Operators-2.png ]]

Sekarang mari kita lihat operasi bitwise OR antara dua bilangan bulat **12** dan **25**:

```cpp
12 = 00001100 (dalam biner)
25 = 00011001 (dalam biner)

// Operasi Bitwise OR antara 12 dan 25

    00001100
|   00011001
    --------
    00011101  = 29 (dalam desimal)
```

### Contoh: Operasi Bitwise OR
```cpp
#include <iostream>

int main() {
    int a = 12, b = 25;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a | b = " << (a | b) << endl;

    return 0;
}
```

Output:
```
a = 12
b = 25
a | b = 29
```

Hasil dari operasi **bitwise OR** antara `a = 12` dan `b = 25` adalah **29**.

---
## 3 | Operator Bitwise XOR di C++

Operator bitwise **XOR** `^` mengembalikan nilai **1 jika dan hanya jika salah satu dari operan bernilai 1**. Namun, jika **kedua operan bernilai 0** atau **keduanya bernilai 1**, maka hasilnya adalah **0**.

Tabel kebenaran berikut menunjukkan cara kerja operator bitwise XOR. Misalkan `a` dan `b` adalah dua operan yang hanya dapat bernilai biner, yaitu 1 atau 0:

![[Programmiz - C++ Bitwise Operators-3.png]]

Sekarang mari kita lihat operasi bitwise XOR antara dua bilangan bulat **12** dan **25**:

```cpp
12 = 00001100 (dalam biner)
25 = 00011001 (dalam biner)

// Operasi Bitwise XOR antara 12 dan 25

    00001100
^   00011001
    --------
    00010101  = 21 (dalam desimal)
```

### Contoh: Operasi Bitwise XOR
```cpp
#include <iostream>

int main() {
    int a = 12, b = 25;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a ^ b = " << (a ^ b) << endl;

    return 0;
}
```

Output:
```
a = 12
b = 25
a ^ b = 21
```

Hasil dari operasi **bitwise XOR** antara `a = 12` dan `b = 25` adalah **21**.

---
## 4 | Operator Bitwise Complement di C++

Operator bitwise **complement** adalah operator unary (bekerja pada satu operan saja). Operator ini dilambangkan dengan simbol `~` yang mengubah digit biner **1 menjadi 0** dan **0 menjadi 1**.

![[Programmiz - C++ Bitwise Operators-5.png|500]]


Penting untuk dicatat bahwa bitwise complement dari suatu bilangan bulat **N** sama dengan **-(N + 1)**. Contohnya,

Misalkan kita punya bilangan bulat 35. Berdasarkan aturan tersebut, bitwise complement dari 35 adalah:

$$-(35 + 1) = -36$$

Sekarang, mari kita lihat apakah hasilnya benar atau tidak.

```cpp
35 = 00100011 (dalam biner)

// Menggunakan operator bitwise complement
~ 00100011
 __________
  11011100
```

Pada contoh di atas, kita mendapatkan bahwa bitwise complement dari `00100011` (35) adalah `11011100`. Jika kita langsung mengonversi hasil ini ke desimal, kita akan mendapat 220.

Namun, penting untuk dicatat bahwa kita **tidak bisa langsung mengonversi hasil biner tersebut ke desimal** dan mengharapkan hasil yang diinginkan. Ini karena bilangan biner `11011100` juga setara dengan **-36** dalam representasi bilangan bertanda.

Untuk memahami ini, kita perlu menghitung output biner dari -36 terlebih dahulu. Kita menggunakan **komplemen dua (2's complement)** untuk menghitung representasi biner bilangan negatif.

### Komplemen Dua (2's Complement)

Komplemen dua dari suatu bilangan **N** menghasilkan nilai **-N**.

Dalam aritmatika biner, komplemen satu (1's complement) mengubah semua **0 menjadi 1** dan **1 menjadi 0**.

Kemudian, jika kita menambahkan 1 pada hasil komplemen satu, kita akan mendapatkan komplemen dua dari bilangan asli.

Sebagai contoh:

```cpp
36 = 00100100 (dalam biner)

Komplemen satu (1's Complement) = 11011011

Komplemen dua (2's Complement):
  11011011
+        1
----------
  11011100
```

Di sini, kita melihat bahwa komplemen dua dari 36 (yaitu -36) adalah `11011100`. Nilai ini sama dengan bitwise complement dari 35 yang sudah kita hitung pada bagian sebelumnya.

Jadi, kita bisa mengatakan bahwa bitwise complement dari 35 adalah -36.

### Contoh: Operasi Bitwise Complement
```cpp
#include <iostream>

int main() {
    int num1 = 35;
    int num2 = -150;
    cout << "~(" << num1 << ") = " << (~num1) << endl;
    cout << "~(" << num2 << ") = " << (~num2) << endl;

    return 0;
}
```

Output:

```
~(35) = -36
~(-150) = 149
```

Pada contoh di atas, kita mendeklarasikan dua variabel bertipe integer, yaitu `num1` dan `num2`, dan menginisialisasinya dengan nilai $35$ dan $-150$ secara berturut-turut.

Kemudian, kita menghitung bitwise complement dari kedua variabel tersebut menggunakan kode `~num1` dan `~num2`, lalu menampilkannya di layar.

Bitwise complement dari $35$ adalah: $-(35 + 1) = -36$, atau $\sim 35 = -36$

Bitwise complement dari $-150$ adalah:  $-(-150 + 1) = -(-149) = 149$, atau $\sim (-150) = 149$

Hasil ini sesuai dengan output yang kita dapatkan.

<br/><br/><br/>

---
# C++ Shift Operators

Ada dua operator shift dalam pemrograman C++:

- Operator **Right Shift** (`>>`)
    
- Operator **Left Shift** (`<<`)

Sekarang, kita akan mulai memasuki materi Shift Operator ini.
## 5 | Operator Right Shift di C++

Operator right shift menggeser semua bit ke arah kanan sebanyak jumlah bit yang ditentukan. Operator ini dilambangkan dengan simbol `>>`.

Ketika kita menggeser suatu bilangan ke kanan, bit-bit paling tidak signifikan (least significant bits) akan dibuang, sedangkan bit-bit paling signifikan (most significant bits) akan digantikan dengan angka nol.

![[Programmiz - C++ Bitwise Operators-6.png]]


Seperti yang kita lihat pada gambar di atas, kita memiliki sebuah bilangan 4-bit. Ketika kita melakukan operasi **right shift** sebanyak satu bit, setiap bit digeser ke kanan sebanyak 1 bit.

Akibatnya, bit paling kanan akan dibuang, sementara posisi paling kiri menjadi kosong. Kekosongan ini kemudian diisi dengan angka 0.

---
## 6 | Operator Left Shift di C++

Operator left shift menggeser semua bit ke arah kiri sebanyak jumlah bit yang ditentukan. Operator ini dilambangkan dengan simbol `<<`.

![[Programmiz - C++ Bitwise Operators-7.png]]

Seperti yang kita lihat pada gambar di atas, kita memiliki sebuah bilangan 4-bit. Ketika kita melakukan operasi **left shift** sebanyak 1 bit, setiap bit digeser ke kiri sebanyak 1 bit.

Akibatnya, bit paling kiri akan dibuang, sementara posisi paling kanan menjadi kosong. Kekosongan ini kemudian diisi dengan angka 0.

## Contoh: Operasi Bitwise Shift
```cpp
#include <iostream>

int main() {

    // mendeklarasikan dua variabel bertipe integer
    int num = 212, i;

    // Operasi Shift Right (geser kanan)
    cout << "Shift Right:" << endl;

    // Menggunakan perulangan for untuk menggeser num ke kanan dari 0 bit sampai 3 bit
    for (i = 0; i < 4; i++) {
        cout << "212 >> " << i << " = " << (212 >> i) << endl;
    }

    // Operasi Shift Left (geser kiri)
    cout << "\nShift Left:" << endl;

    // Menggunakan perulangan for untuk menggeser num ke kiri dari 0 bit sampai 3 bit
    for (i = 0; i < 4; i++) {
        cout << "212 << " << i << " = " << (212 << i) << endl;
    }

    return 0;
}
```

Output:

```
Shift Right:
212 >> 0 = 212
212 >> 1 = 106
212 >> 2 = 53
212 >> 3 = 26

Shift Left:
212 << 0 = 212
212 << 1 = 424
212 << 2 = 848
212 << 3 = 1696
```

Dari output program di atas, kita dapat menyimpulkan bahwa untuk sembarang bilangan **N**, hasil dari operator shift right adalah:

```
N >> 0 = N
N >> 1 = (N >> 0) / 2
N >> 2 = (N >> 1) / 2
N >> 3 = (N >> 2) / 2
```

dan seterusnya.

Demikian pula, hasil dari operator shift left adalah:

```
N << 0 = N
N << 1 = (N << 0) * 2
N << 2 = (N << 1) * 2
N << 3 = (N << 2) * 2
```

dan seterusnya.

Oleh karena itu, kita dapat menyimpulkan bahwa,

```
N >> m = [ N >> (m-1) ] / 2
N << m = [ N << (m-1) ] * 2
```

## Bitwise Shift dalam Praktik Nyata

Pada contoh di atas, perlu dicatat bahwa tipe data `int` menyimpan angka dalam 32-bit, yaitu sebuah nilai `int` direpresentasikan oleh 32 digit biner.

Namun, penjelasan kita mengenai operator bitwise shift menggunakan angka yang direpresentasikan dalam 4-bit.

Sebagai contoh, bilangan basis-10, misal angka 13 dapat direpresentasikan dalam 4-bit dan 32-bit sebagai berikut:

```
Representasi 4-bit dari 13 = 1101
Representasi 32-bit dari 13 = 00000000 00000000 00000000 00001101
```

Akibatnya, operasi bitwise left-shift untuk 13 (dan bilangan lainnya) dapat berbeda tergantung pada jumlah bit yang digunakan dalam representasinya.

Hal ini karena dalam representasi 32-bit, terdapat lebih banyak bit yang bisa digeser ke kiri jika dibandingkan dengan representasi 4-bit.
