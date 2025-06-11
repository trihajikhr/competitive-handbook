---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Bitmask in C++
sumber: geeksforgeeks.org
date_learned: 2025-06-09T19:53:00
tags:
  - bits
  - bitwise
---
Link Sumber: [Bitmask in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/bitmasking-in-cpp/)

---
# Bitmask in C++

Dalam dunia pemrograman, di mana presisi dan efisiensi sangat penting, bitmasking adalah teknik yang kuat yang memanfaatkan manipulasi bit. C++ juga menyediakan platform bagi para programmer untuk merepresentasikan data secara efisien dan membuka kemampuan komputasi yang luar biasa melalui bitmasking. Dalam artikel ini, kita akan membahas tentang bitmasking dan teknik bitmasking dalam C++.

### Apa itu bit?  
Bit adalah unit data terkecil. Kita tahu bahwa sistem komputer hanya memahami bahasa biner yang terdiri dari 0 dan 1. Angka 0 dan 1 ini secara tunggal dikenal sebagai 'BIT'.

### Bitmasking dalam C++  
Bitmasking adalah teknik yang digunakan dalam pemrograman untuk melakukan operasi secara lebih efisien pada data biner. Bitmasking sering digunakan dalam algoritma untuk meningkatkan performa dalam hal kompleksitas waktu, dengan memanfaatkan operator bitwise untuk operasi yang efisien pada level bit.

Bitmasking dalam C++ melibatkan manipulasi bit-bit individu dari sebuah angka untuk mencapai hasil yang diinginkan. Ini dilakukan dengan membuat sebuah bit mask dan sering digunakan untuk operasi berikut:

- **Bit Toggle (Membalik bit):** Jika sebuah bit bernilai 0, maka bisa dibalik menjadi 1 dan sebaliknya.
    
- **Bit Setting (Mengatur bit):** Jika sebuah bit bernilai 0, maka disebut 'bit belum diset'. Kita dapat mengaturnya menjadi 1 dengan melakukan operasi toggle. Ini disebut bit setting.
    
- **Bit Clearing (Menghapus bit):** Jika sebuah bit bernilai 1, maka disebut 'bit diset'. Kita dapat mengubahnya menjadi 0 dengan operasi toggle, yang disebut operasi bit clearing.
    
- **Memeriksa apakah bit tertentu menyala atau mati:** Sebuah bit dikatakan menyala jika bernilai 1 dan mati jika bernilai 0. Misalnya, sebuah integer memiliki banyak bit dan kita dapat memeriksa apakah bit tertentu dalam integer tersebut diset atau tidak dengan menggunakan operator bitwise.
    
## Apa itu _Bit Mask_?

**Bit mask** adalah teknik dasar yang digunakan untuk melakukan _bit masking_. Ini pada dasarnya adalah pola biner (_binary pattern_) yang digunakan untuk melakukan berbagai operasi pada level bit seperti:

- _set_ (menyalakan bit),
    
- _clear_ (mematikan bit),
    
- _toggle_ (membalik bit),
    
- atau memeriksa apakah sebuah bit menyala atau tidak (_bit checking_).
    

---

### Cara Membuat Bit Mask:

Misalnya, kita memiliki sekumpulan angka yang representasi binernya terdiri dari 8 bit. Kita akan menggunakan 8-bit ini sebagai referensi dalam artikel ini.

Kita tahu bahwa angka **1** hanya memiliki satu bit yang bernilai 1, yaitu bit paling kanan — yang juga dikenal sebagai **least significant bit** (bit yang paling tidak berarti). Sedangkan 7 bit lainnya bernilai 0. Jadi, bentuknya akan terlihat seperti ini:

```
00000001
```

**Menggeser bit yang menyala (LSB / Least Significant Bit) sebanyak 3 posisi ke kiri** menggunakan ekspresi `(1 << 3)` akan terlihat seperti ini:

```
00001000
```

---

Penjelasan:

- Bilangan `1` dalam biner: `00000001`
    
- Menggeser ke kiri sebanyak 3 bit (`1 << 3`) berarti menambahkan tiga nol di sebelah kanan dan menggeser bit `1` ke kiri:
    
    ```
    00000001  << 3  →  00001000
    ```
    

Artinya, bit keempat dari kanan sekarang bernilai `1`, sementara sisanya `0`.

**Setelah digeser, bit yang menyala ke posisi ke-3 menjadi 8.** Demikian pula, kita bisa melakukan hal ini untuk posisi mana pun. Kita akan menggunakan properti shifting ini dalam teknik-teknik bitwise berikutnya untuk membuat bit mask, lalu melakukan berbagai operasi bitwise dengannya.

# Melakukan Bitmasking di C++

Bitmasking dilakukan dengan membuat **bit mask** untuk operasi yang ingin kita lakukan. Bit mask ini kemudian akan digunakan bersama dengan **operasi bitwise** untuk mendapatkan hasil yang diinginkan.

Bitmasking dilakukan dengan **meletakkan masker** (menyembunyikan beberapa bit yang tidak diperlukan berdasarkan kriteria tertentu), serta **menyetel atau menghapus bit-bit yang tersisa**. Masking bit-bit tertentu ini membantu kita untuk melakukan operasi yang diinginkan dengan lebih efisien, sehingga meningkatkan performa algoritma dan mengoptimalkan penggunaan memori.

Sebelum masuk ke contoh agar lebih mudah dipahami, mari kita pelajari dulu operator-operator bitwise yang menjadi dasar dari semua contoh.

---

### Operator Bitwise dalam C++ yang Digunakan untuk Bitmasking:

- Bitwise AND (`&`) – Mengembalikan `true` hanya jika kedua bit bernilai 1.
    
- Bitwise OR (`|`) – Mengembalikan `true` jika salah satu bit bernilai 1.
    
- Bitwise XOR (`^`) – Mengembalikan `true` jika kedua bit berbeda.
    
- Bitwise NOT (`~`) – Membalik (menegasikan) bit.
    
- Bitwise Left Shift (`<<`) – Menggeser semua bit ke kiri sebanyak 1 posisi.
    
- Bitwise Right Shift (`>>`) – Menggeser semua bit ke kanan sebanyak 1 posisi.
    

---

Selanjutnya, kita akan melihat berbagai operasi bitwise umum beserta contohnya.

## 1 | Menyetel Bit Tertentu

Menyetel (setting) bit tertentu berarti mengubah nilai bit dari `0` menjadi `1`. Hal ini bisa dilakukan dengan memanfaatkan operator Bitwise OR (`|`), karena operator ini akan menghasilkan `1` jika salah satu dari bit operand bernilai `1`, serta menggunakan operator geser kiri (left shift `<<`).

Kita akan menggeser bit LSB (Least Significant Bit) dari angka `1` ke posisi yang ingin kita ubah menjadi `1`, lalu melakukan operasi Bitwise OR dengan bilangan awal.

### Sintaks:

```cpp
integer | (1 << posisi_bit_yang_ingin_disetel)
```

Di sini, `posisi_bit_yang_ingin_disetel` adalah posisi bit (dari kanan, mulai dari 0) yang ingin kita ubah nilainya menjadi `1`.

---

### Contoh:

![[GeeksforGeeks - Bitmask in C++-1.png]]


Menyetel bit tertentu dalam C++

```cpp
// Program C++ untuk menunjukkan cara menyetel bit tertentu
#include <iostream>
using namespace std;

int main(){
    int x = 11;

    // menyetel bit kelima menggunakan bitmask
    x = x | (1 << 5);
    cout << "Hasil setelah menyetel bit kelima: " << x ;

    return 0;
}
```

Output:

```
Hasil setelah menyetel bit kelima: 43
```

---

**Penjelasan:**

- Nilai awal `x = 11` → biner: `00001011`
- `1 << 5` artinya kita menggeser bit `1` ke posisi ke-5 → `00100000` (yaitu 32 dalam desimal)
- Operasi `00001011 | 00100000 = 00101011` → yaitu `43` dalam desimal
    

---
## 2 | Menghapus (Mematikan) Bit Tertentu

Menghapus (clearing) sebuah bit berarti kita mengubah nilai bit dari `1` menjadi `0`, tanpa mengubah bit-bit lainnya. Ini dilakukan dengan operator Bitwise AND (`&`) dan operator negasi Bitwise (`~`).

Operator Bitwise NOT (`~`) akan membalik semua bit:

- `1` jadi `0`
- `0` jadi `1`

Sifat ini sangat berguna untuk menghapus (mengubah menjadi 0) sebuah bit yang sedang dalam kondisi menyala (`1`), karena setelah dibalik lalu di-AND-kan, bit tersebut akan jadi `0`.

### Sintaks:

```cpp
integer & ~(1 << posisi_bit_yang_ingin_dihapus)
```

- `1 << posisi` akan menghasilkan bilangan biner dengan satu bit `1` di posisi yang ingin kita hapus.
    
- `~(1 << posisi)` akan menghasilkan bilangan dengan semua bit `1` kecuali posisi target menjadi `0`.
    
- Lalu dengan operator `&`, hanya bit pada posisi tersebut yang berubah menjadi `0`, sisanya tetap.
    

---

### Contoh:

![[GeeksforGeeks - Bitmask in C++-2.png]]


```cpp
// Program C++ untuk menunjukkan cara menghapus (clear) bit tertentu
#include <iostream>
using namespace std;

int main(){
    int x = 11;

    // menghapus bit di posisi ke-3
    x = x & ~(1 << 3);
    cout << "Hasil setelah menghapus bit ke-3: " << x;

    return 0;
}
```

 Output

```
Hasil setelah menghapus bit ke-3: 3
```

---

### Penjelasan:

- Nilai awal `x = 11` → biner: `00001011`
    
- `1 << 3` → `00001000` (yaitu 8 dalam desimal)
    
- `~(1 << 3)` → `11110111` (semua bit `1`, kecuali posisi ke-3 yang `0`)
    
- `00001011 & 11110111 = 00000011` → yaitu `3` dalam desimal
    

---
## 3 | Membalik (Toggle) Bit Tertentu

**Toggle** berarti kita **membalik** nilai sebuah bit:

- Jika bit bernilai `1`, maka dibalik menjadi `0`.
    
- Jika bit bernilai `0`, maka dibalik menjadi `1`.
    

Operasi ini dapat dilakukan dengan mudah menggunakan **operator XOR (`^`)** bersama dengan **left shift (`<<`)**.

---

### Mengapa XOR?

Sifat dari operator XOR adalah:

- `1 ^ 1 = 0` (sama → 0)
    
- `0 ^ 1 = 1` (berbeda → 1)
    
- `x ^ 0 = x` (nilai tidak berubah jika XOR dengan 0)
    

Jadi, jika kita ingin membalik bit tertentu, kita tinggal **XOR-kan dengan `1` pada posisi tersebut**.

---

### Sintaks:

```cpp
integer ^ (1 << posisi_bit_yang_ingin_dibalik)
```

### Contoh:

![[GeeksforGeeks - Bitmask in C++-3.png]]


```cpp
// Program C++ untuk menunjukkan cara membalik (toggle) bit tertentu
#include <iostream>
using namespace std;

int main()
{
    int x = 11;

    // membalik bit di posisi ke-0
    x = x ^ (1 << 0);
    cout << "Hasil setelah membalik bit ke-0: " << x;

    return 0;
}
```

### Output:

```
Hasil setelah membalik bit ke-0: 10
```

### Penjelasan:

- Nilai awal `x = 11` → biner: `00001011`
    
- `1 << 0` → `00000001`
    
- `00001011 ^ 00000001 = 00001010` → yaitu `10` dalam desimal
    

---
## 4 | Mengecek Apakah Bit Tertentu Menyala (Set) atau Tidak

Dalam operasi ini, kita ingin mengetahui apakah **bit di posisi tertentu bernilai 1 (set)** atau tidak (bernilai 0).

### Cara Kerja:

Kita menggunakan:

- **Operator AND (`&`)**
    
- **Operator shift kiri (`<<`)**
    

Langkah-langkahnya:

1. Geser angka `1` ke posisi bit yang ingin diperiksa.
    
2. Lakukan operasi AND antara angka asli dan hasil shift tersebut.
    
3. Jika hasilnya bukan nol, berarti bit tersebut bernilai 1 (menyala).
    
4. Jika hasilnya nol, berarti bit tersebut **tidak menyala**.
    

---

### Sintaks

```cpp
integer & (1 << posisi_bit_yang_diperiksa)
```

---

### Contoh Implementasi

![[GeeksforGeeks - Bitmask in C++-4.png]]


```cpp
// Program C++ untuk mengecek apakah bit tertentu menyala atau tidak
#include <iostream>
using namespace std;

int main()
{
    int x = 11;

    // Operasi AND akan mengembalikan angka selain nol jika bit menyala,
    // dan nol jika bit tidak menyala
    if (x & (1 << 3)) {
        cout << "Bit ke-3 menyala\n";
    }
    else {
        cout << "Bit ke-3 tidak menyala\n";
    }

    return 0;
}
```

 Output:

```
Bit ke-3 menyala
```

---

### Penjelasan:

- Nilai awal `x = 11` → biner: `00001011`
    
- `1 << 3` → `00001000` (yaitu 8)
    
- `00001011 & 00001000 = 00001000` → bukan nol, berarti **bit ke-3 menyala**
    

---

### Kesimpulan

**Bitmasking** di C++ adalah cara yang sangat efisien untuk **memanipulasi bit** dari sebuah angka dan mengubah nilainya dengan cara yang sangat optimal. Operasi level-bit seperti ini sangat berguna untuk **mengoptimalkan algoritma dan penggunaan memori**.
