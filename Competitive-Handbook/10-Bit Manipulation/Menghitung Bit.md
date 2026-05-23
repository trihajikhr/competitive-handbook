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

# Mengarungi Arsitektur Memori: Menghitung Bit dan Tipe Data Integer

Di dalam komputer, semua data—baik angka, teks, maupun gambar—pada akhirnya akan diubah menjadi sekumpulan angka `0` dan `1`. Sekumpulan angka ini disebut sebagai **Binary Digit** atau disingkat **Bit**. Bit adalah unit data terkecil dalam komputasi.

Ketika kita mendeklarasikan tipe data seperti `short`, `int`, atau `long long`, kita sebenarnya sedang memesan "kotak penyimpanan" di memori dengan ukuran bit yang berbeda-beda.

## 1. Apa Maksud dari 16-bit, 32-bit, dan 64-bit?

Maksudnya adalah **jumlah digit biner (slot `0` atau `1`) yang disediakan di memori** untuk menyimpan nilai dari variabel tersebut.

Mari kita bedah tiga tipe data integer (bilangan bulat) yang paling sering digunakan:

### A. `short` (16-bit)

Mempunyai panjang **16 digit biner**.

Jika kita menulis:

```cpp
short num = 1;
```

Maka di memori akan disimpan sebagai:

```
00000000 00000001
```

### B. `int` (32-bit)

Mempunyai panjang **32 digit biner**.

Jika kita menulis:

```cpp
int num = 1;
```

Maka di memori akan disimpan sebagai:

```
00000000 00000000 00000000 00000001
```

### C. `long long` (64-bit)

Mempunyai panjang **64 digit biner**.

Jika kita menulis:

```cpp
long long num = 1;
```

Maka di memori akan disimpan sebagai:

```
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001
```

## 2. Batas Maksimum Penyimpanan (_Range_ Nilai)

Karena jumlah digit binernya terbatas, otomatis angka maksimal yang bisa ditampung oleh masing-masing tipe data juga memiliki batas.

Secara _default_, tipe-tipe data di atas bersifat **signed** (bisa menampung angka positif dan negatif). Bit pertama (paling kiri) digunakan sebagai penanda: `0` untuk positif, `1` untuk negatif.

Berikut adalah tabel matematika representasi dan batas nilainya:

|**Tipe Data**|**Ukuran**|**Rumus Batas Nilai**|**Rentang Nilai (Desimal)**|**Estimasi CP (Gampang Diingat)**|
|---|---|---|---|---|
|**`short`**|16-bit|dari $-2^{15}$ hingga $2^{15} - 1$|$-32,768$ s.d. $32,767$|$\approx 3 \cdot 10^4$|
|**`int`**|32-bit|dari $-2^{31}$ hingga $2^{31} - 1$|$-2,147,483,648$ s.d. $2,147,483,647$|$\approx 2 \cdot 10^9$ (Dua Miliar)|
|**`long long`**|64-bit|dari $-2^{63}$ hingga $2^{63} - 1$|$-9.22 \times 10^{18}$ s.d. $9.22 \times 10^{18}$|$\approx 9 \cdot 10^{18}$ (Sembilan Kuintiliun)|

> ⚠️ **Catatan Kritis LGM:** > Di dalam _Competitive Programming_, hafalkan batasan ini:
> 
> - Jika hasil perhitungan atau input soal mencapai **$10^9$**, kamu masih aman menggunakan `int`.
>     
> - Jika hasil perhitungan (terutama hasil perkalian atau penjumlahan berulang) bisa melebihi **$2 \cdot 10^9$** (misal mencapai $10^{12}$ atau $10^{18}$), kamu **WAJIB** menggunakan `long long`.
>     

## 3. Apa yang Terjadi Jika Melebihi Batas? (_Integer Overflow_)

Komputer tidak akan protes atau memunculkan error jika angka yang kamu masukkan melebihi batas slot bitnya. Yang terjadi adalah fenomena bernama **Integer Overflow**.

Bayangkan sebuah odometer (pengukur jarak) pada motor yang hanya memiliki 3 digit. Jika angka sudah mencapai `999` dan kamu maju satu kilometer lagi, angkanya akan berputar kembali ke `000`.

Di dalam sistem biner _signed_ (menggunakan komplemen dua):

- Jika tipe data `int` sudah mencapai batas maksimumnya ($2,147,483,647$) lalu kamu tambah dengan `1`, nilainya akan "tumpah" dan berputar ke angka paling negatif ($-2,147,483,648$).
    

### Contoh Kasus _Bug_ Populer di CP:

```cpp
int a = 1000000; // 10^6
int b = 1000000; // 10^6
long long c = a * b; // Berharap hasilnya 10^12
```

**Apakah kode di atas benar? SALAH.** Meskipun variabel `c` bertipe `long long`, operasi perkalian `a * b` dilakukan antar sesama `int`. Hasil perkalian $10^{12}$ akan mengalami _overflow_ terlebih dahulu di level `int` (menghasilkan angka acak/negatif), baru kemudian angka salah tersebut disimpan ke dalam `c`.

**Solusi yang benar:**

```cpp
long long c = (long long)a * b; // Lakukan casting salah satu ke long long sebelum dikali
```
