# Jawaban
## Soal 1
Diketahui sebuah barisan $4, 7,10,13,16, \dots$ 
	a) Carilah rumus suku ke-$n$ dari barisan tersebut!
	b) Carilah 50 jumlah suku yang pertama!

### Jawaban
Terdapat selisih yang sama antara deret $n$, yaitu sebesar $3$. Hal itu bisa dibuktikan dengan $n_i - n_{i-1}$. Maka rumus untuk menemukan nilai suatu $n$ jika terletak di $n_i$ adalah:

$$n=(3 \times n)+1$$

Suku ke 1 = $(3 \times 1)+1=4$
Suku ke 2 = $(3 \times 2)+1=7$
Suku ke 3 = $(3 \times 3)+1=10$
Suku ke 4 = $(3 \times 4)+1=13$
Suku ke 5 = $(3 \times 5)+1=16$

Untuk mencari nilai $n_{50}$, maka $n_{50}=(3 \times 50)+1=151$

## Soal 3
Dari 30 siswa yang terdiri dari 16 siswa dan 14 siswi yang di sebuah SMA akan dipilih lima orang untuk mewakili dalam lomba Matematika. Jika dari kelima yang terpilih tersebut dua diantaranya harus dari siswi,
	a) Apakah dalam kasus pemilihan tersebut masuk kasus permutasi atau kombinasi?
	b) berapakah banyaknya susunan yang mungkin ?

### Jawaban
Kasus ini adalah **kombinasi**, karena yang diminta adalah memilih orang, tanpa memerhatikan urutan atau posisi. Jika siswa $A-B-C-D-E$ yang dipilih, maka susunan $E-D-C-B-A$ juga sama saja.

Untuk mengetahui berapa banyak susunan yang mungkin, karena ini adalah kasus kombinasi, maka kita bisa menggunakan rumus kombinasi berikut:
$$\binom{n}{r}=\frac{n!}{r!(n-r)!}$$
Pilih 2 siswi dari 14:
$$\binom{14}{2}=\frac{14!}{2!(14-2)!}$$
$$\binom{14}{2}=\frac{14 \times 13}{2}=91$$
Pilih 3 siswa laki-laki dari 16 siswa:
$$\binom{16}{3}=\frac{16!}{3!(16-3)!}$$
$$\binom{16}{3}=\frac{16 \times 15 \times 14}{3 \times 2 \times 1}=\frac{3360}{6}=560$$
Kalikan hasil keduanya:
$$\binom{14}{2} \times \binom{16}{3}=91 \times 560=50.960$$
Maka, ada $50.960$ cara untuk memilih 5 orang dengan syarat 2 diataranya adalah siswi.

## Soal 4
Sebutkanlah beberapa cara untuk mendapatkan atau mengumpulkan data dan jelaskan

### Jawaban
1. Penelitian lapangan atau observasi

Pengumpulan data bisa dilakukan dengan mengadakan penelitian langsung di lapangan atau laboratorium terhadap objek penelitian. Hasil penelitian dicatat dan akan dianalisis.

2. Wawancara

Data juga bisa dikumpulkan dengan mewawancarai orang atau objek yang mengetahui objek penelitian.

3. Angket

Angket merupakan pengumpulan data dengan cara memakai daftar isian atau daftar pertanyaan yang sudah disiapkan dan disusun sedemikian rupa sehingga objek penelitian hanya tinggal mengisi atau menjawab pertanyaan yang tersedia.

4. Data penelitian sebelumnya

Pengumpulan data juga bisa dilakukan dengan menggunakan sebagian atau seluruh data yang sudah dicatat atau dilaporkan peneliti sebelumnya.

> Wis terlanjur sing kie 

---
## Soal 5
### Jawaban
Data yang telah disusun dalam bentuk tabel distribusi frekuensi dapat disajikan dalam bentuk diagram yang disebut _histogram_, yaitu diagram kotak yang lebarnya menunjukkan interval kelas, sedangkan batas-batas tepi kotak merupakan tepi bawah dan tepi atas kelas, dan tingginya menunjukkan frekuensi pada kelas tersebut.

Apabila titik-titik tengah sisi atas dari histogram dihubungkan satu sama lain oleh ruas-ruas garis maka diperoleh _poligon frekuensi_.

Sedangkan _Ogive_ adalah grafik yang digambarkan berdasarkan data yang sudah disusun dalam bentuk _tabel distribusi frekuensi kumulatif_. Untuk data yang disusun dalam bentuk tabel distribusi frekuensi kumulatif kurang dari, grafiknya berupa _ogive positif_, sedangkan untuk data yang disusun dalam bentuk tabel distribusi frekuensi kumulatif lebih dari, grafiknya berupa _ogive negatif_.

Perhatikan data 60 siswa berikut:

|  Kelas  | Frekuensi |
| :-----: | :-------: |
| 50 – 54 |     2     |
| 55 – 59 |     4     |
| 60 – 64 |    16     |
| 65 – 69 |    16     |
| 70 – 74 |    10     |
| 75 – 79 |     8     |
| 80 – 84 |     8     |
| 85 – 89 |     2     |
Berikut adalah histogram dan poligonya:

![[Jawaban-1.png]]

Untuk menentukan **ogive positif dan ogive negatif** dari tabel distribusi frekuensi tersebut, kita perlu menghitung:
### Ubah ke Format Tepi Kelas

Kelas seperti `50 s/d 54` → batas bawah dan atas: 50 dan 54  
Tepi kelas dihitung dengan menambahkan dan mengurangi **0,5**:

| Kelas   | Frekuensi | Tepi Bawah | Tepi Atas |
| ------- | --------- | ---------- | --------- |
| 50 – 54 | 2         | 49.5       | 54.5      |
| 55 – 59 | 4         | 54.5       | 59.5      |
| 60 – 64 | 16        | 59.5       | 64.5      |
| 65 – 69 | 16        | 64.5       | 69.5      |
| 70 – 74 | 10        | 69.5       | 74.5      |
| 75 – 79 | 8         | 74.5       | 79.5      |
| 80 – 84 | 8         | 79.5       | 84.5      |
| 85 – 89 | 2         | 84.5       | 89.5      |

###  Ogive Positif & Negatif (Frekuensi Kumulatif Kurang dari & Lebih dari)

Maka didapat berikut hasilnya:

| Tepi Bawah | Ogive  positif | Ogive negatif |
| ---------- | -------------- | ------------- |
| 49.5       | 2              | 66            |
| 54.5       | 6              | 64            |
| 59.5       | 22             | 60            |
| 64.5       | 38             | 44            |
| 69.5       | 48             | 28            |
| 74.5       | 56             | 18            |
| 79.5       | 64             | 10            |
| 84.5       | 66             | 2             |

### Bentuk Grafik
Untuk membuatnya dalam bentuk grafik kta perlu menggunakan tepi bawah frekeuensi frekuensi paling pertama dengan nilai awal 0, atau bisa dibuat lebih mudah dicerna seperti ini:

| Tepi Bawah                          | Ogive  positif | Ogive negatif |
| ----------------------------------- | -------------- | ------------- |
| 49.5                                | 0              | 66            |
| 54.5                                | 2              | 64            |
| 59.5                                | 6              | 60            |
| 64.5                                | 22             | 44            |
| 69.5                                | 38             | 28            |
| 74.5                                | 48             | 18            |
| 79.5                                | 56             | 10            |
| 84.5                                | 64             | 2             |
| (tepi atas, tambahin ini satu) 89,5 | 66             | 0             |

![[Jawaban-3.png]]

