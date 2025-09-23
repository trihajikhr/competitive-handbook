---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Inversions
sumber:
  - codeforces.com
  - chatgpt.com
  - gemini.google.com
date_learned: 2025-09-10T23:59:00
tags:
  - tips-trick
  - problem-statement
---
Link Sumber: 

---
# 1 | Apa itu Inversions

Kadang ada beberapa soal yang memberikan permasalahan pada array, dengan menyebutkan *inversions*, atau inversion. 

Jadi, apa itu inversion?

Diberikan array/permutasi $a$ dengan panjang $n$. Sebuah **inversion** adalah pasangan indeks $(i, j)$ dengan:

$$
i < j \quad \text{dan} \quad a[i] > a[j]
$$

Contoh:
$a = [3, 1, 2]$

* Pasangan (1,2): $3>1$ ✅ inversion
* Pasangan (1,3): $3>2$ ✅ inversion
* Pasangan (2,3): $1>2$ ❌ bukan inversion

Total inversions = 2.

<br/>

---

# 2 | Penjelasan Lain

**Inversion** dalam sebuah array adalah sepasang elemen yang posisinya salah jika dilihat dari urutan yang seharusnya (ascending). Secara formal, sepasang indeks $(i, j)$ memiliki inversion jika $i < j$ tetapi nilai $A[i]$ lebih besar dari nilai $A[j]$.

Sederhananya, ini terjadi ketika sebuah angka yang lebih besar muncul **sebelum** sebuah angka yang lebih kecil.

## 2.1 | Contoh

Mari kita ambil array $A = [3, 1, 2]$.

Kita periksa setiap pasang elemen:

* **Pasangan (3, 1):** Angka 3 berada di indeks 0 dan angka 1 di indeks 1. Karena $3 > 1$, ini adalah sebuah **inversion**.
* **Pasangan (3, 2):** Angka 3 berada di indeks 0 dan angka 2 di indeks 2. Karena $3 > 2$, ini juga sebuah **inversion**.
* **Pasangan (1, 2):** Angka 1 berada di indeks 1 dan angka 2 di indeks 2. Karena $1 < 2$, ini **bukan** sebuah inversion.

Jadi, total inversions dalam array $[3, 1, 2]$ adalah 2.
## 2.2 | Sifat-sifat Inversion

* Array yang sudah **terurut sempurna** (dari kecil ke besar) tidak memiliki inversions sama sekali (jumlahnya nol).
* Array yang **terurut terbalik** (dari besar ke kecil) memiliki jumlah inversions paling banyak.
* Jumlah inversions bisa digunakan sebagai ukuran seberapa "tidak terurut" sebuah array. Semakin besar jumlahnya, semakin kacau urutan array tersebut.

Permasalahan seperti [Problem - 1918B - Codeforces](https://codeforces.com/problemset/problem/1918/B) biasanya meminta Anda untuk menemukan cara untuk meminimalkan jumlah inversions, yang seringkali membutuhkan pemahaman mendalam tentang konsep ini dan algoritma seperti **Merge Sort** atau struktur data seperti **Fenwick Tree** untuk menghitungnya secara efisien.

<br/>

---
# 3 | Kasus Inversions yang Sering Muncul

Dalam dunia *competitive programming*, konsep **inversion** biasanya muncul dalam beberapa jenis kasus, terutama yang berkaitan dengan pengurutan (sorting) dan analisis data.

Konsep **inversion** memang sangat penting dan sering menjadi dasar dari berbagai masalah. Selain yang sudah disebutkan, ada beberapa kasus lain di mana inversions berperan, terutama dalam masalah yang berkaitan dengan geometri dan data multidimensi.

Selain kasus-kasus yang sudah disebutkan, **inversions** juga muncul dalam konteks yang lebih spesifik dan lanjutan dalam _competitive programming_
## 3.1 | Menghitung Jumlah Inversions

Ini adalah kasus yang paling umum. Soal akan meminta Anda untuk menghitung total jumlah inversions dalam sebuah array atau seberapa "tidak terurut" array tersebut. Solusi paling efisien untuk masalah ini adalah dengan menggunakan algoritma **Merge Sort**. Ketika Anda menggabungkan dua sub-array yang sudah terurut, Anda dapat menghitung inversions dengan membandingkan elemen-elemen dari kedua sub-array tersebut. Setiap kali elemen dari sub-array kanan lebih kecil dari elemen sub-array kiri, itu berarti semua elemen yang tersisa di sub-array kiri akan membentuk inversions dengan elemen dari sub-array kanan tersebut.
## 3.2 | Meminimalisir Inversions

Kasus ini lebih kompleks. Anda diberikan dua array dan harus menggabungkannya atau melakukan operasi lain untuk mendapatkan array baru dengan jumlah inversions yang paling sedikit. Contohnya adalah soal [Problem - 1918B - Codeforces](https://codeforces.com/problemset/problem/1918/B) yang Anda sebutkan, di mana tujuannya adalah menyusun ulang dua array, $A$ dan $B$, sedemikian rupa sehingga array $B$ yang sudah disusun ulang memiliki inversions minimal.
## 3.3 | Permutasi dan Ranking

Soal-soal ini sering melibatkan permutasi dan hubungannya dengan inversions. Jumlah inversions dari sebuah permutasi bisa digunakan untuk menentukan paritasnya (genap atau ganjil), yang merupakan konsep penting dalam aljabar dan kombinatorika.
## 3.4 | Struktur Data

Untuk kasus di mana Anda perlu menghitung inversions secara *online* (yaitu, satu per satu saat elemen dimasukkan) atau pada array yang berubah-ubah, seringkali digunakan struktur data canggih seperti **Fenwick Tree (Binary Indexed Tree)** atau **Segment Tree**. Dengan struktur ini, Anda dapat menghitung berapa banyak elemen yang lebih besar di sebelah kiri atau berapa banyak elemen yang lebih kecil di sebelah kanan dari suatu elemen dengan cepat ($O(\log n)$).
## 3.5 | Masalah Titik di Ruang 2D

Bayangkan Anda memiliki sejumlah titik di bidang kartesius (2D), dan Anda diminta untuk menghitung pasangan titik $(p_1, p_2)$ di mana $p_1.x < p_2.x$ dan $p_1.y > p_2.y$. Masalah ini pada dasarnya adalah masalah menghitung inversions. Anda bisa mengurutkan titik-titik tersebut berdasarkan koordinat x-nya, lalu menghitung inversions pada koordinat y-nya. Sering kali, ini diselesaikan dengan teknik-teknik seperti **Divide and Conquer** (mirip Merge Sort) atau menggunakan struktur data seperti **Fenwick Tree**.
## 3.6 | Sort Stability (Stabilitas Pengurutan)

Inversions juga digunakan untuk mengukur stabilitas dari algoritma pengurutan. Sebuah algoritma pengurutan dikatakan **stabil** jika tidak mengubah urutan relatif dari elemen-elemen yang memiliki nilai yang sama. Contohnya, jika Anda memiliki data pasangan `(nama, usia)` dan mengurutkannya berdasarkan usia, algoritma yang stabil akan memastikan bahwa jika ada dua orang dengan usia yang sama, urutan mereka dalam daftar akhir akan tetap sama seperti urutan awalnya. Dalam konteks ini, perubahan pada jumlah inversions bisa menjadi indikasi ketidakstabilan.
## 3.7 | Jarak Metrik pada Permutasi

Dalam matematika, khususnya dalam kombinatorika, jumlah inversions dapat digunakan sebagai salah satu cara untuk mengukur "jarak" antara dua permutasi. Ini dikenal sebagai **Kendall Tau distance**. Jarak ini dihitung dari jumlah inversions yang perlu ditukar untuk mengubah satu permutasi menjadi permutasi yang lain. Konsep ini muncul dalam algoritma machine learning seperti **ranking and recommendation systems**, di mana Anda mencoba mengukur seberapa mirip dua daftar peringkat.

Singkatnya, **inversions** bukanlah sekadar konsep teoritis, tetapi alat praktis yang digunakan untuk mengukur keteraturan, menganalisis hubungan antar data, dan bahkan mengukur jarak dalam berbagai domain. Pemahaman yang kuat tentang inversions dan cara menghitungnya secara efisien adalah salah satu keterampilan dasar yang sangat berharga dalam *competitive programming*.
## 3.8 | Masalah pada Pohon (Trees)

Pada beberapa masalah yang melibatkan struktur data pohon, Anda mungkin perlu menghitung inversions pada urutan yang dihasilkan dari penjelajahan (traversal) pohon, seperti pre-order atau post-order traversal. Masalah ini bisa menjadi rumit dan seringkali memerlukan kombinasi teknik dari Fenwick Tree, Segment Tree, atau bahkan teknik khusus untuk pohon seperti **Heavy-Light Decomposition** untuk memproses query pada jalur atau sub-pohon secara efisien.
## 3.9 | Geometri Komputasional Lanjutan

Dalam geometri komputasional, inversions adalah dasar untuk menyelesaikan berbagai masalah, seperti menghitung perpotongan segmen garis. Jika Anda memiliki serangkaian segmen garis horizontal dan vertikal, menghitung berapa banyak dari mereka yang berpotongan bisa diubah menjadi masalah inversions setelah data diolah dan diurutkan dengan benar. Konsep ini juga berlaku dalam masalah lain, seperti menghitung jumlah pasangan titik yang memenuhi kondisi geometris tertentu.
## 3.10 | Masalah Kombinatorik dan Dynamic Programming

Dalam *dynamic programming* (DP) yang melibatkan permutasi, jumlah inversions seringkali menjadi bagian dari state (keadaan) DP. Misalnya, Anda diminta untuk membangun sebuah permutasi dengan jumlah inversions tertentu atau mencari jumlah cara untuk mendapatkan permutasi yang memenuhi syarat tertentu.

Memahami konsep inversions dengan mendalam dan menguasai berbagai algoritma untuk menghitungnya adalah salah satu kunci untuk sukses dalam _competitive programming_. Ini menunjukkan kemampuan Anda untuk melihat pola tersembunyi dalam masalah yang tampak rumit dan menerapkannya ke dalam solusi yang efisien.