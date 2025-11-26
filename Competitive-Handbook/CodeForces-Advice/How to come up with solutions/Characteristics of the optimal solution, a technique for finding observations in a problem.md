---
obsidianUIMode: preview
note_type: Advice
judul_materi: Characteristics of the optimal solution, a technique for finding observations in a problem
sumber: codeforces
date_learned: 2025-06-08T18:45:00
tags:
  - advice
  - problem-solving
---
Link sumber: [Characteristics of the optimal solution, a technique for finding observations in a problem - Codeforces](https://codeforces.com/blog/entry/99291)

---
# 1 | Characteristics of the optimal solution, a technique for finding observations in a problem
## Pendahuluan

Sebagian dari kalian yang cerdas di luar sana mungkin menganggap isi blog ini terlalu jelas, sampai-sampai tidak pantas disebut sebagai sebuah “teknik”. Ini hanyalah proses berpikir yang sangat wajar yang biasanya muncul di benak kita saat mencoba menyelesaikan sebuah soal!

Namun begitu, aku pribadi sering merasa terbantu (dan mungkin kalian juga akan merasa demikian) ketika mencoba menyatakan pikiranku secara eksplisit saat sedang menghadapi sebuah masalah—baik dengan menuliskannya di selembar kertas, menaruh komentar di dalam kode, atau sekadar mengucapkannya keras-keras seperti orang gila :D. Aku memperhatikan bahwa salah satu hal yang membedakan pemecah masalah yang baik dari yang lain (selain dari latihan dan pengetahuan tentang topik atau algoritma tertentu tentunya) adalah cara berpikir dan pendekatannya terhadap sebuah masalah. Jadi, demi membuat diriku jadi problem-solver yang lebih baik, aku kadang merenungkan cara berpikirku sendiri dan mencoba memperbaikinya secara umum, agar bisa lebih fleksibel dalam menghadapi berbagai macam soal. Bagi banyak problem-solver hebat, kemampuan seperti ini adalah efek samping alami dari banyak berlatih soal, yang berkembang secara implisit. Tapi, dengan menyatakan efek samping semacam itu secara eksplisit pada diri sendiri, aku merasa proses belajarku jadi jauh lebih cepat.

Dalam blog ini, aku akan mencoba menjelaskan sebuah teknik berpikir yang aku temukan sering muncul kembali dan cukup membantu dalam menghadapi berbagai soal yang di awal tampak menakutkan bagi banyak orang, terutama kalau pikiran kita belum tertata. Setelah itu, aku akan mencoba menerapkan teknik ini pada beberapa soal Codeforces yang pernah aku selesaikan, dan menurutku tidak mudah jika tidak menggunakan pendekatan ini secara eksplisit. Aku sangat menganjurkan kalian untuk mencoba soal-soal ini terlebih dahulu sebelum membaca solusinya (aku tahu sudah ada editorial resmi yang bagus untuk soal-soal ini, tapi aku menuliskan solusi versi aku sendiri supaya selaras dengan tema blog ini).

**Catatan:** Aku tidak tahu apakah sudah ada orang lain yang pernah membahas teknik serupa di Codeforces atau di luar sana. Aku sudah mencoba mencarinya tapi tidak menemukannya, jadi aku putuskan untuk menuliskannya sendiri.

---
# 2 | Tekniknya (Karakteristik dari solusi optimal)

Banyak dari soal yang kita hadapi melibatkan pencarian sebuah solusi optimal dalam bentuk tertentu. Misalnya: cari subsekuens dengan nilai _sesuatu_ yang seminimal mungkin, atau bentuk sebuah grafik dari array yang memenuhi syarat tertentu. Nah, inti dari teknik ini adalah cara berpikir seperti ini:

> “Anggap saja aku _sudah_ menemukan solusi optimalnya, kira-kira seperti apa bentuknya? Karakteristik apa yang ia miliki? Bisakah aku memodifikasi atau 'memainkan' solusi itu, tapi tetap membuatnya optimal?”

Dengan mengajukan pertanyaan-pertanyaan semacam itu pada diri sendiri dan mencoba menjawabnya, kita bisa mendapatkan banyak pengamatan berharga yang sangat membantu untuk menemukan solusinya. Yang lebih penting lagi: kita harus punya keberanian untuk bereksperimen dengan solusi tersebut—coba ubah-ubah sedikit sambil tetap menjaga agar syarat dari soal tetap terpenuhi. Misalnya: jika sebuah subsekuens punya nilai minimum _sesuatu_, apakah bisa kita kurangi jumlah elemennya, tapi nilainya tetap minimum?

Kalau kamu masih belum benar-benar merasa bahwa pendekatan ini berguna, tenang saja—nanti akan terasa jauh lebih jelas ketika kita mulai membahas contoh-contoh soal.

---
## Problem 1. [1592C - Bakry and Partitioning](https://codeforces.com/problemset/problem/1592/C)

_(Seperti yang telah disebutkan sebelumnya, sangat disarankan untuk mencoba menyelesaikan soal ini sendiri terlebih dahulu — sebelum melanjutkan membaca blog ini.)_

Jadi, soal ini meminta kita untuk mencari cara membagi sebuah pohon menjadi sebuah hutan, di mana setiap pohon dalam hutan tersebut memiliki nilai XOR bitwise yang sama satu sama lain. Mari kita coba terapkan teknik kita di sini:

Misalkan aku berhasil menemukan cara untuk membagi pohon menjadi sebuah hutan, dan sekarang aku punya sebuah hutan yang terdiri dari $q$ pohon, yang semuanya memiliki nilai XOR bitwise sebesar $x$. Apakah ada karakteristik khusus dari $q$ pohon ini? Bisakah aku “bermain-main” sedikit dengan mereka dan mengurangi jumlah pohon tersebut?

Untuk soal ini, akan sangat berguna jika kita berani bermain-main dengan solusi tersebut.

Kita perhatikan bahwa jika kita memiliki sebuah pohon yang kita bagi menjadi 2 pohon dengan nilai XOR masing-masing $a$ dan $b$, maka jelas bahwa sebelum dibagi, nilai XOR keseluruhan pohon adalah $a ⊕ b$. Artinya, bentuk “eksperimen” yang bisa kita lakukan di sini adalah dengan menggabungkan dua pohon menjadi satu pohon baru dengan nilai XOR gabungan dari keduanya.

Sekarang, mari kita kembali ke solusi optimal kita. Jika kita mencoba menggabungkan dua pohon yang sama-sama punya nilai XOR $x$, maka hasil gabungannya akan punya nilai XOR $x ⊕ x = 0$ (tenang, ini tidak merusak sifat optimal dari solusinya). Jika kita tambahkan satu pohon lagi ke pohon hasil gabungan tadi, maka nilai XOR akhirnya akan menjadi $x ⊕ 0 = x$. Jadi, kalau dalam solusi optimal kita ada $q$ pohon, maka kita bisa menguranginya menjadi $q - 2$ pohon, dan **solusinya tetap optimal**.

Jadi, kalau $q$ genap, kita bisa kurangi jadi $2$, dan kalau $q$ ganjil kita bisa kurangi jadi $3$. Ini berarti bahwa jika solusi mungkin dengan $q$ pohon, maka solusi juga mungkin dengan $q \; mod \;2 + 2$ pohon. Sisanya dari masalah ini tinggal bagaimana cara kita menangani dua kasus tersebut dengan benar—yang sebenarnya sudah tidak relevan lagi dengan isi blog ini (tapi kamu bisa lihat pembahasannya di editorial resmi jika masih merasa kesulitan).

---
## Problem 2. [1629D - Peculiar Movie Preferences](https://codeforces.com/problemset/problem/1629/D)

Kita perhatikan bahwa jika sebuah string adalah palindrom, maka kita sudah selesai (jika ada string sepanjang 1 karakter, maka otomatis itu palindrom, jadi kita asumsikan tidak ada string sepanjang 1). Kalau begitu, mari kita terapkan teknik kita:

Jika sebuah palindrom terdiri dari beberapa string, seperti apa bentuknya? Bisakah kita “bermain-main” sedikit dengan mereka?

Sekarang, penting untuk dicatat bahwa jika sebuah string adalah palindrom, maka setiap _prefix_ (awalan) juga merupakan _suffix_ (akhiran) dari string itu. Jadi, jika kita memiliki sebuah string palindrom yang terdiri dari string dengan panjang 2 dan 3, kita bisa bereksperimen dengan memfix-kan string pertama dan terakhir lalu mengabaikan bagian tengahnya, dan string itu **masih akan tetap palindromik**. Ini menyederhanakan masalah menjadi mencari dua string yang bisa digabungkan menjadi sebuah palindrom.

---

## Problem 3. [1366D - Two Divisors](https://codeforces.com/problemset/problem/1366/D)

Pada pandangan pertama, soal ini membuatku menggaruk kepala cukup lama, terus-menerus bertanya: _"bagaimana aku bisa menemukan dua pembagi seperti itu?"_. Namun, aku mencoba menerapkan teknik ini dan bertanya:

Misalnya aku berhasil menemukan dua pembagi $d_1$ dan $d_2$ sehingga $\gcd(d_1 + d_2, a_i) = 1$, kira-kira karakteristik apa yang mungkin dimiliki oleh dua pembagi ini?

Nah, penting untuk dicatat bahwa $d_1$ dan $d_2$ adalah pembagi dari $a_i$, tetapi jika $\gcd(d_1 + d_2, a_i) = 1$, maka untuk setiap bilangan prima $p \mid a_i, p∤(d_1+d_2)⇒p∤d_1$ atau $p \nmid d_2$

Artinya, jika ada bilangan prima $p$ yang membagi $d_1$, maka $p$ **tidak boleh** membagi $d_2$, karena jika tidak, maka $\gcd(d_1 + d_2, a_i) \geq p$. Maka kita langsung bisa menyimpulkan bahwa $\gcd(d_1, d_2) = 1$, yang **tidak mungkin terjadi** jika $a_i$ hanya punya **satu** faktor prima. Jadi kita asumsikan bahwa $a_i$ punya **lebih dari satu faktor prima**.

Kalau kita perhatikan pembagi seperti ini, kita lihat bahwa jika suatu bilangan prima $p$ **tidak** membagi kedua pembagi, maka ada kemungkinan bahwa $p$ membagi jumlah mereka (misalnya: $5 \mid (2 + 3)$). Namun, jika **setiap** faktor prima dari $a_i$ hanya membagi salah satu dari dua pembagi dan bukan keduanya, maka kita bisa yakin bahwa $p$ **tidak** akan membagi jumlahnya. (Karena kalau kita asumsikan tanpa mengurangi keumuman bahwa $p \mid d_1$, maka $d_1 + d_2 \equiv d_2 \pmod{p}$). Ini berarti kita bisa membagi faktor-faktor prima dari $a_i$ ke dalam dua kelompok $d_1$ dan $d_2$, sehingga setiap bilangan prima hanya membagi salah satu dari keduanya.

Dengan begitu, kita bisa menyelesaikan soal ini dengan cara mengambil satu faktor prima dari $a_i$, yaitu $p$, lalu terus bagi $a_i$ dengan $p$ sampai tidak bisa dibagi lagi, dan kemudian cek apakah $a_i$ masih lebih besar dari 1. Kalau iya, berarti kita punya dua faktor pembagi. Salah satu faktor prima dari $a_i$ bisa ditemukan menggunakan metode **sieve of Eratosthenes**.

---

## Problem 4: [1343E - Weights Distributing](https://codeforces.com/problemset/problem/1343/E)

Jelas bahwa kita harus menyebarkan bobot pada jalur kita secara _greedy_, dengan bobot terkecil diberi prioritas tertinggi. Jumlah sisi (edges) yang harus kita beri bobot harus seminimal mungkin, karena jika tidak, kita akan dipaksa menggunakan harga baru dari array yang telah diberikan. Maka dari itu, harga-harga tersebut harus kita tempatkan pada sisi-sisi yang merupakan bagian dari jalur terpendek antara $a$ ke $b$ dan dari $b$ ke $c$. Tapi hal penting yang perlu diperhatikan adalah bahwa dalam sebuah graf, bisa saja terdapat **banyak jalur terpendek**.

Sekarang mari kita bertanya: seperti apa bentuk jalur terpendek tersebut? Karakteristik seperti apa dari jalur terpendek yang dibutuhkan agar total harga minimum bisa dicapai?

Oke, jalur terpendek bisa saja berupa satu garis lurus dari $a \to b$ dan $b \to c$, yaitu dua jalur di mana $a \to b$ dan $b \to c$ **tidak beririsan** kecuali di titik $b$ sebagai simpul umum. Jika mereka beririsan di lebih dari satu simpul, maka jumlah simpul yang terlibat akan bertambah, dan itu justru merugikan kita.

Karena itu, solusi optimal kita akan mencakup **setidaknya satu simpul perpotongan**. Misalnya, kita perbaiki satu simpul umum $x$, dan jalur kita bisa berbentuk:

- $a \to x$
- $x \to b$
- $b \to x$
- lalu $x \to c$

Sisi-sisi yang umum hanyalah pada jalur $x \to b$, maka kita harus menyebarkan harga-harga terkecil pada sisi-sisi yang berada pada jalur dari $x \to b$.

Jadi, total jalur kita adalah:

- dari $a \to x$,
- lalu $x \to c$,
- dan karena ada pengulangan pada jalur $x \to b$ dua kali (sekali ke $b$, sekali kembali), maka totalnya:

$$\text{dist}(a, x) + 2 \cdot \text{dist}(b, x) + \text{dist}(c, x)$$

Dengan demikian, kita bisa simpan jarak terpendek dari $a$, $b$, dan $c$ menggunakan algoritma seperti **Dijkstra** dalam 3 array berbeda, lalu lakukan iterasi terhadap semua kemungkinan simpul $x$, dan kita minimalkan:

$$\text{pref}[\text{dist}(b, x)] + \text{pref}[\text{dist}(a, x) + \text{dist}(b, x) + \text{dist}(c, x)]$$

di mana `pref` adalah array jumlah prefix pada array harga yang telah diurutkan.

---
# 3 | Kesimpulan

Saya harap ide-ide ini bermanfaat dan bukan membuang-buang waktu Anda.

Dari sudut pandang saya yang sederhana, dunia Competitive Programming secara umum dapat dibagi menjadi dua bagian:

1. **Keterampilan murni dalam memecahkan masalah dan berpikir**, dan
    
2. **Teknik/topik/algoritma** yang bisa dipelajari untuk membantu menyelesaikan beberapa jenis masalah tertentu seperti graf, Teori Bilangan, DP, dan sebagainya.
    

Bagian pertama menurut saya bersifat implisit bagi kebanyakan pemecah soal, dan merupakan bagian dari alur berpikir mereka yang tidak terstruktur, tapi menjadi semakin teratur seiring latihan. Namun, saya juga percaya bahwa bagian ini **bisa disusun dan diajarkan** secara sistematis.

Konten blog ini bisa dianggap sebagai salah satu **teknik untuk mengatur alur berpikir**, yaitu bantuan dalam ranah "keterampilan berpikir dan pemecahan masalah murni", bukan teknik/topik/algoritma tertentu.

---

**(Akan ditambahkan lebih banyak soal latihan setelah saya menemukannya. Jika kamu punya rekomendasi soal bagus yang menggunakan teknik ini, silakan tulis di kolom komentar dan akan saya tambahkan ke blog ini.)**

### Soal latihan:

- [233B - Non-square Equation](https://codeforces.com/problemset/problem/233/B)
    
- [1064D - Labyrinth](https://codeforces.com/problemset/problem/1064/D)
    
- [1312E - Array Shrinking](https://codeforces.com/problemset/problem/1312/E)
    
- [1632C - Strange Test](https://codeforces.com/problemset/problem/1632/C)
    
- [1656B - Subtract Operation](https://codeforces.com/problemset/problem/1656/B)
    
- [1656D - K-good](https://codeforces.com/problemset/problem/1656/D)
    
