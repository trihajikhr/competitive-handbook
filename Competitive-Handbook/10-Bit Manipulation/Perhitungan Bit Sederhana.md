---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Perhitungan Bit Sederhana
Di sini, kita akan membedah tiga kasus manipulasi bit yang paling sering kita jumpai di medan kompetisi, lengkap dengan fungsi bawaan (_built-in functions_) dan alternatif cara manualnya.

## Kasus menghitung panjang bit

Saat kita ingin mencari panjang bit, yang sebenarnya kita cari adalah posisi bit 1 tertinggi (Most Significant Bit / MSB). Mengetahui panjang bit suatu angka sangat krusial, seperti pada soal _Rock and Lever_ pada Codeforces, karena performa algoritma kita bergantung pada seberapa besar bit efektif dari angka tersebut.

Ada beberapa cara yang bisa kita gunakan untuk menghitung panjang bit dari suatu bilangan $N$:

### Menggunakan Fungsi Bawaan C++ (`__builtin_clz`)
    
Fungsi `__builtin_clz(N)` berguna untuk menghitung jumlah angka nol di bagian paling kiri (_Count Leading Zeros_) pada representasi 32-bit `int`. Jadi, untuk mendapatkan panjang bitnya, kita tinggal mengurangkan 32 dengan hasil fungsi tersebut.


```cpp
int panjang_bit = 32 - __builtin_clz(N);
```


_Catatan kita:_ Jika $N$ bertipe `long long`, kita wajib menggunakan versi 64-bitnya, yaitu `__builtin_clzll(N)` dan mengurangkannya dari 64.

Perhatikan kode berikut:

```cpp
int hitungPanjangBit(unsigned int x) {
    if (x == 0) return 1; 
    return 32 - __builtin_clz(x);
}
```

*Catatan*: Pengecekan `if (x == 0)` wajib dilakukan untuk menghindari bug/crash karena `__builtin_clz(0)` tidak terdefinisi.
### Menggunakan Fungsi Logaritma (`log2`)

Secara matematis, posisi bit tertinggi dari sebuah angka adalah hasil logaritma basis 2 dari angka tersebut yang dibulatkan ke bawah, lalu ditambah 1.


```cpp
int panjang_bit = std::log2(N) + 1;
```

### Cara Modern dan Lebih Aman (C++20 ke atas)

Jika kompiler Anda sudah mendukung C++20, Anda tidak perlu lagi menghitung secara manual dengan pengurangan. Library `<bit>` menyediakan fungsi khusus bernama **`std::bit_width`** yang dibuat persis untuk tujuan ini.

```cpp
#include <bit> // wajib disertakan

int main(){
	unsigned int x = 10;
	int panjang_bit = std::bit_width(x);
	
	return 0;
}
```

Namun penting diingat disini, fungsi `bit_width()` hanya bisa menerima tipe data `unisgned`, jadi pastikan nilai numeriknya bukan negatif!
### Cara Manual dengan Perulangan (Bit Shift)
    
Jika kita ingin menulisnya secara manual tanpa fungsi bawaan, kita bisa melakukan operasi _right shift_ (`>>`) secara berulang pada $N$ hingga nilainya menjadi 0, sambil menghitung berapa kali perulangan itu berjalan.

```cpp
int panjang_bit = 0;
while (N > 0) {
	panjang_bit++;
	N >>= 1; // Sama dengan membagi N dengan 2
}
```


## Kasus menghitung banyak bit aktif

Bit aktif adalah bit yang bernilai 1. Kita sering kali diminta menghitung jumlah bit 1 ini (disebut juga _Popcount_ atau _Hamming Weight_) untuk keperluan analisis kombinatorika, mencari parity (ganjil/genap), atau saat bermain dengan representasi _bitmask_.

Berikut adalah pilihan cara untuk menghitungnya:

### Menggunakan Fungsi Bawaan C++ (`__builtin_popcount`)

Ini adalah cara tercepat dan paling efisien yang selalu kita gunakan di CP karena fungsi ini langsung diterjemahkan oleh CPU menjadi instruksi assembly satu siklus.

```cpp
int bit_aktif = __builtin_popcount(N);
```

_Catatan kita:_ Gunakan `__builtin_popcountll(N)` jika variabel kita berukuran 64-bit (`long long`).

### Menggunakan Algoritma Brian Kernighan

Cara manual ini jauh lebih cerdas daripada mengecek bit satu per satu. Algoritma ini memanfaatkan ekspresi `N & (N - 1)` yang berfungsi untuk menghapus bit 1 paling kanan pada setiap langkahnya. Perulangan hanya akan berjalan sebanyak jumlah bit aktif yang ada.

```cpp
int bit_aktif = 0;
while (N > 0) {
	N &= (N - 1); // Menghapus bit 1 paling kanan
	bit_aktif++;
}
```

### Cara Manual dengan "Geser-Geser" (Bit Shift)

Pada metode ini, kita selalu memeriksa bit paling kanan (bit ke-0) menggunakan operasi `N & 1`. Jika hasilnya `1`, berarti bit tersebut aktif. Setelah itu, kita geser angkanya ke kanan sejauh 1 bit (`N >>= 1`) untuk memeriksa bit berikutnya, sampai angkanya habis menjadi `0`.

Kodenya akan terlihat seperti ini:

```cpp
int bit_aktif = 0;
while (N > 0) {
    if (N & 1) {  // Periksa apakah bit paling kanan adalah 1
        bit_aktif++;
    }
    N >>= 1;  // Geser ke kanan untuk membuang bit yang sudah diperiksa
}
```

#### Perbandingan: Apa Bedanya dengan Brian Kernighan?

Kedua cara ini sama-sama benar dan menghasilkan jawaban yang sama, tetapi ada perbedaan besar pada **jumlah perulangan (loop)** yang terjadi di dalam memori komputer:

**Metode Geser-Geser:** Perulangan akan berjalan sebanyak **panjang bit efektif** dari angka tersebut.
    
_Contoh:_ Jika $N = 8$ (biner: `1000`), loop akan berjalan sebanyak **4 kali** karena komputer harus menggeser bit tersebut sebanyak 4 kali sampai habis, meskipun jumlah bit `1`-nya hanya ada satu.
    
**Algoritma Brian Kernighan:**
    
Perulangan hanya berjalan sebanyak **jumlah bit 1 yang aktif saja**.

_Contoh:_ Jika $N = 8$ (biner: `1000`), operasi `N & (N - 1)` akan langsung mengubah angka `1000` menjadi `0000` dalam **1 kali loop saja**.
## Kasus menghitung banyak bit mati

Bit mati adalah bit yang bernilai 0. Terkadang, kita justru perlu mengetahui seberapa banyak slot kosong yang tersisa pada representasi biner sebuah angka untuk menentukan inversi (_bitwise NOT_) atau batas ruang memori.

Kita bisa mendapatkan jumlah bit mati ini dengan beberapa pendekatan logika:

### Pengurangan Total Panjang Tipe Data

Cara paling instan adalah dengan menghitung total bit aktif terlebih dahulu, lalu mengurangkannya dari total kapasitas bit tipe data yang kita pakai (32 untuk `int` atau 64 untuk `long long`).

```cpp
int bit_mati = 32 - __builtin_popcount(N);
```
### Pengurangan Berdasarkan Panjang Efektif Angka

Jika maksud kita adalah menghitung bit 0 yang berada di dalam rentang angka itu saja (tanpa menghitung _leading zeros_ di sebelah kiri MSB), maka kita harus mencari panjang efektifnya terlebih dahulu menggunakan metode di subheader pertama, baru dikurangi dengan jumlah bit aktifnya.

```cpp
int panjang_efektif = 32 - __builtin_clz(N);
int bit_mati_internal = panjang_efektif - __builtin_popcount(N);
```
    
### Cara Manual dengan Pengecekan Bit
    
Kita juga bisa melakukan perulangan dari bit paling kanan ke kiri, lalu mengecek apakah bit tersebut bernilai 0 menggunakan operasi bitwise AND (`& 1`).

```cpp
int bit_mati = 0;
while (N > 0) {
	if ((N & 1) == 0) {
		bit_mati++;
	}
	N >>= 1;
}
```