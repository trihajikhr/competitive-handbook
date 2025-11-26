---
obsidianUIMode: preview
note_type: Advice
judul_materi: On "is this greedy or DP", forcing and rubber bands
sumber:
  - codeforces
date_learned: 2025-08-14T22:20:00
tags:
  - advice
  - problem-solving
---
Link Sumber: [On "is this greedy or DP", forcing and rubber bands - Codeforces](https://codeforces.com/blog/entry/106346)

---
# On "is this greedy or DP", forcing and rubber bands

## 1 | Introduction

Ketika berbicara tentang **"teknik pemecahan masalah"**, secara garis besar ada 3 tingkatan:

1. **Algoritme konkret** (misalnya algoritme Kruskal, pohon Li-Chao, *fast Fourier transform*)
2. **Pola umum** (*dynamic programming*, *greedy*, *square-root decomposition*)
3. **Meta-strategi** (“bagaimana saya bahkan memulai untuk memecahkan masalah ini?”)

Ada sedikit area abu-abu, tapi secara umum klasifikasi ini bekerja dengan baik.

Banyak tutorial telah ditulis untuk ide-ide yang masuk dalam kategori 1 atau 2. Namun sangat sedikit yang membahas kategori ketiga. Dalam katalog, saya rasa hanya ada dua blog yang benar-benar masuk kriteria, yaitu [blog ini](https://codeforces.com/blog/entry/62730) dan [blog ini](https://codeforces.com/blog/entry/92248?#comment-809401). Ada juga komentar berharga [ini](https://codeforces.com/blog/entry/92248?#comment-809401). Mengenai alasan mengapa kategori ketiga jarang dibahas, saya pikir ada dua penyebab utama:

1. **Sebagian besar peserta yang kuat tidak benar-benar memikirkan hal ini secara sadar.**
   
   Setelah menyelesaikan masalah menggunakan FFT, sulit untuk tidak menyadari bahwa Anda telah menggunakan FFT. Jika Anda menggunakan DP, bahkan jika Anda melakukannya tanpa berpikir “ini DP”, tetap mudah mengenali bahwa Anda telah menggunakan DP setelahnya. 
   
   Tetapi untuk hal-hal di kategori ketiga… sulit untuk mengingat dengan jelas bagaimana alur pikir Anda berjalan. Selain itu, setidaknya untuk saya pribadi, saya tidak pernah benar-benar *belajar* (maksudnya membaca dan memahami) sesuatu dari kategori tersebut. Proses berpikir saya berkembang murni dari banyak latihan dan pengalaman.
<br/>

2. **Saat menulis tentang algoritme, mudah untuk tahu Anda benar.**
   
   Anda cukup membuktikannya. Tetapi jika kita masuk ke ranah kategori ketiga, ini mulai terasa kurang nyaman, karena lebih sulit memahami mana yang benar atau bahkan mana yang berguna. Tidak separah menulis tentang psikologi, tapi tetap saja. Bahkan saat saya menulis blog ini, saya bertanya-tanya, “apakah ini masuk akal?”.
<br/>

3. **Tidak jelas apakah menulis blog tipe ini benar-benar membantu siapa pun.** 
   
   Saya tetap berpendapat bahwa, dalam kemampuan memecahkan masalah, hal terpenting yang bisa Anda kendalikan adalah **pengalaman**, dan mencari pengganti untuk itu (misalnya algoritme untuk menemukan algoritme, membaca proses berpikir orang lain) tidak terlalu efektif.
   
   Namun demikian, ada banyak orang yang secara teori seharusnya punya banyak pengalaman, tapi hasil mereka tidak mencerminkan hal itu.
<br/>

Bagi saya, terlalu sulit untuk menulis dan menjelaskan secara rinci bagaimana proses berpikir saya bekerja, dan saya juga tidak yakin ini akan berguna bagi siapa pun.

Tetapi saya pikir saya telah menemukan sesuatu yang sering salah dilakukan oleh pemula, jadi saya akan mencoba menjelaskannya sebaik mungkin.

---
## 2 | The idea

![[On is this greedy or DP, forcing and rubber bands-1.png|500]]

### 2.1 | Forcing Fallacy

Banyak pemula yang mengembangkan “teknik” seperti ini saat memecahkan masalah. Mereka melihat batasan (_constraints_) atau menggunakan intuisi lain — yang biasanya keliru — untuk menebak apakah masalah tersebut harus diselesaikan dengan **DP**, **greedy**, atau metode lain.  

Lalu mereka mencoba “memaksakan” teknik yang sudah dipilih itu ke dalam masalah tersebut.  

Kalau _greedy_, biasanya lebih mudah dipaksakan, tapi kemungkinan besar akan menghasilkan jawaban yang salah. Kalau DP, memang lebih sulit, tapi mereka tetap mencoba.

Sering kali, setelah saya menjelaskan bagaimana menyelesaikan suatu masalah, orang akan bertanya, _“tapi, bisa nggak sih ini diselesaikan dengan DP?”_. Ada banyak alasan mengapa orang bisa bertanya seperti itu, tapi saya yakin bahwa dalam beberapa kasus, inilah penyebabnya:  

Ada sesuatu dalam masalah tersebut yang membuat mereka **percaya bahwa masalah ini _harus_ diselesaikan dengan DP**. Mereka pun mencoba langsung menyelesaikannya dengan DP — memikirkan _state_ dan sebagainya — lalu gagal.

> [!NOTE] Catatan tentang “apakah masalah ini bisa diselesaikan dengan X”
> Itu adalah pertanyaan yang sangat sulit, terutama jika ditujukan pada satu orang.  Secara umum, tidak mungkin untuk tahu apakah ada solusi alternatif yang menggunakan **X**.  
> 
> Jawaban terbaik yang biasanya bisa saya berikan adalah: _“tidak praktis untuk memikirkan masalah ini dengan cara itu”_.
> 
> Namun, jika kamu tetap ingin bertanya, cara mengucapkannya yang lebih baik adalah: “Apakah kamu tahu ada solusi yang menggunakan **X**?”

Demikian pula, ada banyak pertanyaan dan blog yang berbentuk “apakah ini DP atau greedy”. Misalnya, pernah ada sebuah blog yang meminta bantuan untuk suatu soal. Salah satu komentarnya berkata:

> “Ini pasti DP karena greedy itu salah.”

Ada beberapa hal yang keliru dari pernyataan itu:

1. Strategi greedy sederhana dan jelas yang kamu coba memang salah. Namun, tidak ada yang menyingkirkan kemungkinan bahwa ada rangkaian pengamatan menarik yang menghasilkan algoritma greedy lain yang lebih kompleks.
2. **Bukan greedy** tidak berarti **pasti DP**.
3. Ini sebenarnya adalah pertanyaan yang keliru untuk ditanyakan pada tahap itu. “Memutuskan” apakah akan memakai DP atau greedy, lalu memaksakan pilihan tersebut, adalah pendekatan yang buruk.

Ada lebih banyak contoh lagi. Pernah ada blog lucu di mana seseorang mencoba memberi para cheater solusi yang salah. Para cheater ini menolaknya, karena mereka yakin solusi yang benar pasti menggunakan **monotonic stack**. Ini mungkin menjelaskan alasannya: mungkin ada sesuatu di soal yang membuat mereka berpikir soal itu tentang monotonic stack, lalu mereka mencoba memaksakannya.

**Kekeliruan memaksa** (*forcing fallacy*) ini juga berlaku pada algoritma yang lebih spesifik, bukan hanya pola umum seperti DP. Contohnya, saya pernah melihat kode segment tree yang benar-benar tidak masuk akal. Persis inilah yang terjadi: soal tersebut punya *range query* — seorang pemula berasumsi bahwa itu pasti harus diselesaikan dengan segment tree, lalu mencoba memaksakannya tanpa memikirkan sifat *query* di soal tersebut.

Tentu saja tidak berhasil, karena mungkin memang soal itu tidak bisa diselesaikan dengan segment tree, dan pemula ini sedang mencoba “memasukkan balok persegi ke lubang bundar” (*push a square peg into a round hole*). Yang membuatnya lebih ironis adalah: solusi dari soal itu jauh lebih sederhana daripada segment tree.

Pengguna ber-rating tinggi kadang justru memperburuk keadaan. Kalimat umum yang sering kamu dengar setelah kontes adalah:

> “Oh, soal E itu cuma DSU + stack.”

Dan… tidak, bukan begitu. Kamu tidak menyebutkan alasan kenapa itu bekerja, bagaimana cara memakainya, dan sebagainya. Mengetahui bahwa soal itu memakai DSU dan stack saja tidak membuatnya lebih mudah diselesaikan.

Yang justru akan jauh lebih membantu adalah mengetahui hal-hal yang tidak kamu sebutkan tadi — saya mungkin bisa menemukan bagian DSU-nya sendiri. Aneh tapi nyata, kita cenderung melebih-lebihkan bagian “bernama” dari solusi kita.

### 2.2 | Apa yang Harus Dilakukan Alih-alih Memaksa

Mungkin teknik menebak dan memaksakan DP atau greedy cukup berhasil untuk soal-soal mudah dan membuatmu naik ke peringkat hijau, aku tidak benar-benar tahu. Tapi begini: sangat sedikit soal sulit yang bisa diselesaikan **langsung** hanya dengan greedy, DP, atau algoritma umum lainnya. Mereka memang digunakan, iya, tapi **kamu tidak bisa menyelesaikan sebagian besar soal hanya dengan memutuskan akan memakai greedy**.

Dalam kebanyakan soal, kamu diberi suatu struktur tertentu (secara garis besar). Dalam soal yang lebih sulit, kamu tidak bisa langsung menghitung hal yang diminta. Sebaliknya, yang harus kamu lakukan adalah mencoba memahami strukturnya. Maksudku **benar-benar memahami**. Bukan sekadar memahami kata-kata di soalnya, tapi memahami apa yang terjadi di dalamnya. Kumpulkan pengamatan (*observations*). Kadang, bahkan lupakan dulu pertanyaan soalnya, dan coba pahami situasinya secara umum. Contoh-contohnya akan dijelaskan di bawah.

> [!NOTE] Catatan tentang kata *"observation"*
> “Observation” adalah salah satu kata yang punya makna agak khusus dalam matematika. Mungkin sedikit berbeda dari arti sehari-hari yang biasa kamu kenal.
> 
> Membuat *observation* umumnya **bukan** berarti melihat pasangan input/output lalu mencari pola. **Bisa** saja artinya seperti itu dalam beberapa soal (misalnya, dalam soal permainan dengan hanya 2 parameter, kamu bisa *brute-force* lalu menemukan polanya), tapi secara umum bukan itu maksudnya.
> 
> Sebenarnya, *observation* itu mirip seperti teorema kecil. Kamu menemukan suatu fakta melalui rantai penalaran. Rantai penalaran ini disebut **bukti** (*proof*). Biasanya, kalau kamu menemukan sebuah *observation*, kamu juga sudah tahu buktinya.

Untuk menutup bagian ini, pikirkan seperti ini: kamu sedang menyelesaikan integral

$$
\int_{0}^{\pi/2} \arccos\left( \frac{\cos x}{1 + 2 \cos x} \right) dx
$$

Apakah kamu melihat integral ini lalu memutuskan, “sepertinya integral ini harus dikerjakan dengan sedikit penjumlahan dan perkalian”? Itulah analoginya. Ya, kamu memang perlu menjumlahkan dan mengalikan, tapi informasi itu sama sekali tidak membantu menemukan inti jawabannya. Intinya, ide dari solusi ada di tempat lain. Hal yang sama juga berlaku pada soal-soal CP yang sulit: kamu mungkin akan memakai beberapa langkah greedy dan DP, tapi mengetahui itu dari awal tidak akan membantumu.


## to be continued

---
## 5 | Apa maksud semua ini?
Dalam semua contoh soal yang sudah saya tunjukkan, pada dasarnya ada dua bagian utama dalam menemukan solusi:

1. **Memahami dan membentuk ulang masalah secara mendalam**

   * Memahami betul apa yang terjadi dalam soal.
   * Menelusuri struktur masalah, mencari apa yang penting, membuat **observasi** (fakta-fakta kecil yang bisa dibuktikan), mencoba menyederhanakan atau memformulasikan ulang soal.
   * Kadang, kita bahkan mengabaikan dulu pertanyaan utamanya dan hanya menganalisis “dunia” yang dijelaskan dalam soal.
<br/>

1. **Melakukan perhitungan sebenarnya**

   * Setelah tahap pertama selesai, sering kali bagian komputasinya hanyalah teknik yang sudah dikenal — mungkin greedy, DP, binary search, union-find, dan sebagainya.
   * Bagian ini *biasanya mudah* setelah pemikiran sulit di tahap pertama selesai.

**Kenapa ini penting:**

* Banyak pemula memulai dari tahap 2 — “Haruskah saya pakai DP? Haruskah saya pakai greedy? Haruskah saya pakai segment tree?” — tanpa melakukan tahap 1. Itu terbalik.
* Memilih algoritma di awal sering kali membuat kita *memaksakan* algoritma itu pada masalah, dan biasanya gagal.
* Pemilihan algoritma dilakukan **di akhir** proses berpikir, bukan di awal.

**Kisah FFT:**

Akhirnya, saya harus mengatakan bahwa saya sendiri pernah mencoba memaksakan algoritma (yaitu, FFT) pada masalah dan segera menyadari bahwa itu tidak berhasil. Inilah sebenarnya asal mula nama -is-this-fft-.

> [!NOTE]
> Penulis mengakui bahwa ia pernah melakukan kesalahan yang sama — mencoba memaksakan algoritma yang disukai (FFT) ke soal-soal yang sebenarnya tidak memerlukannya. Ternyata itu tidak berhasil, dan dari situlah muncul nama handle “is-this-fft” — sebuah pengingat jenaka agar tidak memulai dengan algoritma terlebih dahulu.
> 
