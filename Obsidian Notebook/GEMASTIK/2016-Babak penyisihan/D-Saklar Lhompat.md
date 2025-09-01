---
obsidianUIMode:
note_type: Reverse Engineering
kode_soal: D
judul_soal: Saklar Lhompat
teori_REVERSE:
sumber:
  - tlx-toki
date_learned: 2025-08-23T07:12:00
tags:
  - reverse-engineering
---
Sumber: [Saklar Lhompat](https://tlx.toki.id/problems/gemastik-2016-pemrograman-penyisihan/D)

```ad-important
*"Reverse engineering transforms observation into insight, and insight into mastery, — just break it down, understand it, build it better."*
```

---
# 1 | Problem Statement

```ad-info
Mendefinisikan permasalahan secara formal, termasuk input, output, dan batasan operasional.
```
## Saklar Lhompat

| Time limit   | 2 s   |
| ------------ | ----- |
| Memory limit | 64 MB |

### Deskripsi

Pak Fuad adalah dosen yang ditunjuk oleh Universitas XYZ untuk mengoordinasikan jalannya penyisihan geMasTIK kategori pemrograman untuk tim-tim pada universitas tersebut. Agar para mahasiswanya lebih berkonsentrasi untuk mengerjakan soal-soal penyisihan yang akan dimulai seminggu lagi, Pak Fuad memiliki sebuah ide: kerjakan babak penyisihan di sebuah vila!

Terdapat banyak mahasiswa yang akan mengikuti babak penyisihan. Setiap mahasiswa akan membawa tepat satu buah laptop, termasuk satu buah _charger_-nya. Pak Fuad ingin mempersiapkan stop kontak yang cukup agar semua mahasiswa bisa men-_charge_ laptop pada saat yang bersamaan.

Terdapat dua jenis steker _charger_ laptop para mahasiswa:

- Steker lurus: bisa dipasang pada lubang stop kontak mana saja.

![[D-Saklar Lhompat-1.png]]

- Steker bengkok: bisa dipasang pada lubang pada kedua ujung stop kontak dengan normal, atau pada lubang yang bukan ujung, namun akan selalu memakan tempat sebanyak dua lubang.

![[D-Saklar Lhompat-2.png]]

Di toko listrik langganan Pak Fuad, hanya tersedia stop kontak dengan 4 lubang:

![[D-Saklar Lhompat-3.png|250]]

Setiap stop kontak memiliki kabel colokan bertipe lurus.

Diketahui bahwa terdapat L mahasiswa yang memiliki laptop dengan steker lurus, dan B mahasiswa yang memiliki laptop dengan steker bengkok.

Di vila tersebut, sayangnya hanya terdapat 1 buah stop kontak pada dinding yang dapat digunakan untuk men-_charge_ laptop-laptop mahasiswa. Tentu saja, satu buah stop kontak 4 lubang harus dihubungkan pada dinding, kemudian stop-stop kontak 4 lubang lainnya dapat dirangkai sedemikian sehingga banyaknya lubang mencukupi untuk semua laptop.

Supaya tidak terjadi arus pendek (atau **_saklarnya lompat_** pada bahasa daerah tertentu), Pak Fuad ingin memasang stop kontak sesedikit mungkin. Berapakah banyaknya stop-stop kontak paling sedikit yang harus dibeli supaya pada saat penyisihan berlangsung, semua laptop mahasiswa bisa di-_charge_ bersamaan?

### Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Setiap kasus uji terdiri atas sebuah baris berisi tepat dua buah bilangan bulat L dan B.

### Format Keluaran

Untuk setiap kasus uji, keluarkan sebuah baris berisi sebuah bilangan bulat yang menyatakan banyaknya stop kontak minimum yang harus dibeli.

### Contoh Masukan

```
3
4 0
0 4
8 8
```

### Contoh Keluaran

```
1
2
5
```

### Penjelasan

Untuk contoh masukan pertama, tentunya Pak Fuad cukup membeli 1 stop kontak, lalu mencoloknya pada colokan di dinding. Maka akan tersedia 4 buah lubang yang bisa dipasang untuk 4 buah steker lurus.

Untuk contoh masukan kedua, salah satu cara yang mungkin adalah:

![[D-Saklar Lhompat-4.png|450]]

Untuk contoh masukan ketiga, salah satu cara yang mungkin adalah:

![[D-Saklar Lhompat-5.png|450]]

### Batasan

- 1 ≤ T ≤ 20
- 0 ≤ L, B ≤ 100
- 2 ≤ L + B

---
# 2 | Petunjuk dan Editorial
## 2.1 | Editorial

```ad-info
Merangkum pendekatan solusi dan strategi algoritmik yang disajikan oleh sumber eksternal.
```

Jika kita memiliki K buah stop kontak, apakah mungkin L steker lurus dan B steker bengkok dapat terpasang seluruhnya? Untuk mengetahui ini, kita harus tahu terlebih dahulu bagaimana cara pencolokan steker-steker yang efisien.

Pertama-tama, jika kita ingin menyambungkan stop kontak pada stop kontak lain, akan optimal jika stekernya dicolok pada lubang tengah dari sebuah stop kontak yang sudah ada. Karena jika dipasang pada lubang pinggir, akan memakan tempat yang sebenarnya bisa dipakai untuk steker-steker bengkok. Dengan demikian, untuk K buah stop kontak, kita memiliki:

- 2K buah lubang pinggir
- K+1 buah lubang tengah

Maka, selanjutnya kita tinggal distribusikan L dan B pada lubang-lubang tersebut. Prioritas pertama adalah memasang steker-steker bengkok ke lubang pinggir. Jika lubang tidak cukup, kita pasangkan sisa steker bengkok ke lubang tengah. Jika kita pasang steker bengkok ke lubang tengah, maka setiap saklar akan menghabiskan 2 lubang. Setelah semua steker bengkok terpasang, kita tinggal hitung lubang tersisa, dan cek apakah lubang tersisa ≤ steker lurus.

Dengan cara di atas, kita tinggal mencoba semua nilai K untuk mencari solusi yang terbaik.  
Kompleksitas solusi di atas bergantung pada implementasi. Namun dengan implementasi yang efisien, solusi di atas adalah O(N), dengan N adalah jawabannya.

**Catatan penulis 1**: Contoh kasus uji ketiga mengecoh; karena sesungguhnya susunan tersebut (yang mana tidak optimal) kebetulan menghasilkan jawaban yang sama dengan susunan optimal.

**Catatan penulis 2**: Awalnya, batasan 2 ≤ L+B direncanakan sebagai 1 ≤ L+B. Hal ini memungkinkan adanya tricky case: jika laptop hanya ada 1, tidak perlu membeli stop kontak; cukup colokkan saja _charger_-nya langsung ke tembok :) Namun, kami merasa ini terlalu "kejam" dan menggantinya.

## 2.2 | Kode

```ad-hint
Menyajikan implementasi referensi sebagai bahan analisis dan pembelajaran.
```

Berikut adalah contoh potongan kode yang benar:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int b, l;
        scanf("%d %d", &l, &b);
        int lo = 0, hi = (l + b);
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            bool ok = true;
            int need = (l + b + mid - 1), ada = 4 * mid;
            int ujung = min(b, mid * 2);
            need -= ujung;
            ada -= ujung;
            ujung = b - ujung;
            need += ujung;
            if (ada >= need)
                hi = mid;
            else
                lo = mid + 1;
        }
        printf("%d\n", lo);
    }

    return 0;
}
```

---
# 3 | Reverse Engineering

```ad-danger
title:Reverse Engineering 🛠️
Menganalisis struktur dan logika kode referensi untuk mengidentifikasi pola, strategi, dan teknik yang digunakan.
```

Baiklah, mari kita bedah kode ini.

Seperti biasa, memanggil header all in, tapi pada praktik nanti, kita cukup memanggil 2 header saja, yaitu `iostream` dan juga `algorithm`, tidak perlu terlalu overkill memanggil `bits`.

Langsung saja pada algoritma utama. Setelah menerima inputan banyaknya test case, maka program selanjutnya adalah menerima banyaknya `l` saklar lurus, dan `b` saklar bengkok. Selanjutnya dibuat 2 variabel yaitu `lo` dengan nilai inisialisasi berupa 0, dan `hi` dengan nilai inisialisasi berupa hasil penjumlahan antara `l` dengan `b`.

Apa tujuan dari variabel ini? Kenapa membuat `lo` dan `hi`?

Oke, simpan dulu pertanyaan tersebut.

Lalu dilakukan perulangan while, dengan kondisional `lo < hi`.

Didalam perulangan while, ada operasi berupa:

```cpp
int mid = (lo + hi) >> 1;
```

Jika bingung apa maksud dari kode diatas, kode diatas digunakan sebagai operator `>> 1` **bitwise shift right** 1 kali → membagi bilangan dengan 2 (floor division). Ini sama saja dengan menulisnya seperti ini:

```cpp
int mid = (lo + hi) / 2;
```

Lalu kenapa kode pertama menggunakan bitwise?

Dulu di era compiler C/C++ yang lebih tua, operasi bitwise (`>> 1`) sering lebih cepat daripada pembagian (`/ 2`).  Karena bitwise cuma geser bit, sementara pembagian butuh operasi aritmetika lebih mahal. 

Tetapi, compiler modern (GCC, Clang, MSVC) sudah otomatis mengoptimalkan `/ 2` menjadi `>> 1` di level assembly. Jadi tidak ada perbedaan performa lagi antara `/ 2` dan `>> 1`.

Cara yang lebih aman dan efisien untuk melakukan operasi yang tujuanya sama persis seperti diatas adalah sebagai berikut:

```cpp
int mid = lo + (hi - lo) / 2;
```

Ini lebih recommended daripada fokus ke `>> 1`. Kenapa? Supaya aman dari **overflow**.  
Jika menggunakan `(lo + hi) / 2`, bisa pecah kalau `lo + hi` melebihi batas `int`.

Tapi dengan `lo + (hi - lo) / 2`, kita hanya menghitung selisih (`hi - lo`), yang pasti lebih kecil, jadi tidak akan overflow.

Oke lanjut, disini dibuat sebuah variabel boolean `ok` dengan inisialisasi awal adalah `true`.

Dibuat juga sebuah variabel `need`, dan `ada`:

```cpp
int need = (l + b + mid - 1), ada = 4 * mid;
```

Kegunaan variable `need` disini, sepertinya adalah untuk menghitung berapa banyak 



---
# 4 | Experimentation

```ad-attention
title:Experimentation ⚙️
Melakukan eksperimen terkontrol pada kode untuk memvalidasi pemahaman, mengeksplorasi variasi, dan mengamati perilaku program.
```

---
# 5 | Hypothesis
## 5.1 | Pertama

```ad-attention
Merumuskan dugaan awal terkait mekanisme atau strategi yang mendasari solusi.
```

## 5.2 | Kedua

```ad-attention
Menyempurnakan hipotesis berdasarkan hasil eksperimen dan pengamatan.
```

---
# 6 | Reconstruction (My Implementation)
## 6.1 | Kode Pertama

```ad-attention
Implementasi awal yang mereplikasi strategi inti berdasarkan pemahaman sendiri.
```
## 6.2 | Kode Kedua

```ad-attention
Versi optimasi dan penyempurnaan, meningkatkan efisiensi, readability, atau algoritma.
```

---

# 7 | Knowledge Extraction

```ad-example
title:Knowledge Extraction
Mengisolasi insight, pola, dan trik algoritmik yang dapat diterapkan secara umum pada permasalahan serupa.
```

---
# 8 | Reflection

```ad-success
Mengevaluasi efektivitas proses pembelajaran, mengidentifikasi keberhasilan, kelemahan, dan peluang untuk aplikasi di konteks lain.
```


