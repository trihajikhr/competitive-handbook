---
obsidianUIMode: preview
note_type: Advice
judul_materi: How to read problem statements
sumber:
  - codeforces
date_learned: 2025-08-14T21:16:00
tags:
  - advice
---
Link Sumber: [How to read problem statements - Codeforces](https://codeforces.com/blog/entry/62730)

---
# 1 | How to read problem statements


Tapi Um_nik, kita semua sudah tahu cara membaca, kita punya pengalaman luar biasa selama 2 bulan!  

Oh, anak musim panas kesayanganku, hasil eksperimenku menunjukkan bahwa banyak orang dengan pencapaian keren, seperti medali di ROI, ternyata tidak tahu cara membaca soal. Tapi jangan khawatir, aku akan mengajarimu. Yah… mungkin kamu tidak akan mengerti apa pun, karena seumur hidup kamu tidak pernah berusaha memahami apa pun, dan selalu berharap semua pekerjaan sulit dilakukan orang lain untukmu. Mari kita mulai!

# 2 | Aturan dasar

- Hasil dari membaca soal biasanya adalah **model matematika murni**. Kalau cerita membantu membangun pemahaman yang benar, boleh dipertahankan, tapi tetap buang sebanyak mungkin detail yang tidak perlu.
<br/>

- Bayangkan kamu ingin menjelaskan soal ini ke orang lain. Bagian mana yang akan kamu sampaikan? (Menurut PM-ku, aturan ini tidak akan membantu kamu).
<br/>

- **Lebih singkat = lebih baik.**
<br/>

- **Lebih sederhana = lebih baik.**
<br/>

- **Batasan** adalah bagian dari pernyataan soal. Terutama batasan kecil, karena untuk data kecil kamu bisa mencoba semua kemungkinan.
<br/>

- **Contoh** adalah bagian dari pernyataan soal. Setelah membangun model matematika, pastikan modelmu bekerja dengan benar pada contoh, setidaknya contoh kecil yang bisa kamu periksa dengan cepat.
<br/>

- **Catatan** adalah bagian dari pernyataan soal.
<br/>

- Cobalah menemukan **pola yang familiar**, mungkin objek yang sudah kamu kenal. Misalnya, jika diberikan sebuah graf terhubung dengan tepat satu jalur sederhana antara setiap pasangan simpul, itu disebut **pohon** (_tree_). 4 huruf menggantikan 12 kata, paham kan?
<br/>

- Lebih giatlah mencari sesuatu yang **aneh**, sesuatu yang **tidak kamu harapkan**. Hal itu kemungkinan besar menjadi inti masalahnya.
<br/>

- Kalau ada bagian dari soal yang tidak kamu suka, coba ubah menjadi sesuatu yang kamu suka. Mulailah dengan memahami objeknya, lalu sederhanakan. Ada beberapa soal yang bisa diselesaikan sepenuhnya dengan teknik ini.
<br/>

- Jika model yang kamu dapatkan terlalu besar, coba pecah menjadi beberapa bagian. Akan lebih bagus jika bagian-bagian itu **independen**, seperti “selesaikan problem1, lalu gunakan jawabannya sebagai input ke problem2, dan seterusnya”.
<br/>

- Pada tahap awal, ada baiknya menulis ulang soal versimu sendiri. Di kertas. Dengan tangan.
<br/>

- **Pembuat soal tidak menulis hal acak di pernyataan soal.** Tapi kenapa kamu harus percaya padaku? Aku kan pembuat soal yang buruk. Entahlah, mungkin kamu memang tidak perlu percaya.

# 3 | Beberapa contoh

Aku akan menggunakan Timus untuk hampir semua contoh. Kalau kamu melihat soal dalam bahasa Rusia dan tidak mau, ada pengaturan bahasa di pojok kiri atas.

Alur kerja yang disarankan: baca soalnya di Timus, coba pahami dan sederhanakan dengan aturan-aturan di atas. Kamu tidak perlu membaca bagian “solusi”, tapi aku sudah memperingatkan bahwa konsepku tentang membaca soal **berfungsi**. Maksudku, bagian “pernyataan” sering kali mengandung petunjuk besar menuju solusi.

Dalam kebanyakan kasus, aku tidak akan menulis penjelasan langkah demi langkah tentang bagaimana aku mendapatkan versi akhir. Kamu bisa saja bilang itu bukan cara mengajar yang benar. Aku bisa bilang kamu memang tidak mau belajar. Aku akan menang, karena ini blogku.

### [Networking the "Iset"](http://acm.timus.ru/problem.aspx?space=1&num=1569)
**ℹ️ Statement:** 
Diberikan graf tak berarah, temukan pohon bentangnya (_spanning tree_) dengan diameter minimal.

**ℹ️ Solusi:**   
Diameter memiliki tepat satu pusat. Mari kita tetapkan pusat tersebut — bisa berupa sebuah simpul atau titik tengah sebuah sisi (_edge_).   Untuk pusat yang sudah ditetapkan, pohon dengan diameter minimal adalah pohon dengan tinggi (_height_) minimal jika di-_root_ pada pusat tersebut.  
Jalankan BFS untuk menemukannya.

### [Magic Programmer](http://acm.timus.ru/problem.aspx?space=1&num=2085)
**ℹ️ Statement**: 
Diberikan sebuah pohon, setiap simpul memiliki sebuah himpunan bagian (_subset_) dari semesta (_universe_) berukuran $m$. Temukan sebuah lintasan sedemikian sehingga gabungan tak-saling-beririsan (_disjoint union_) dari himpunan bagian pada simpul-simpul di lintasan tersebut adalah semesta tersebut.

**ℹ️ Solution**: 
Sesuatu yang berhubungan dengan _hashes_ dan _mergeable sets_. Ini tidak menarik, jadi aku tidak akan menghabiskan waktu untuknya.

### [Scheduled Checking](http://acm.timus.ru/problem.aspx?space=1&num=1479)
**ℹ️ Statement**: 
Diberikan sebuah graf tak berarah dengan paling banyak 14 simpul (**kecil = penting**). Bangun sebuah graf bipartit: bagian kiri adalah simpul-simpulnya, bagian kanan adalah semua siklus sederhana.  Temukan jumlah pencocokan (_matchings_) minimal untuk menutupi semua sisinya.

**ℹ️ Solution**: 
Setelah reduksi tersebut, ini menjadi masalah yang sudah cukup dikenal. Kamu juga akan memerlukan _subset DP_ (lihat kan? **kecil = penting**) untuk menghitung nilai yang dibutuhkan.

### [Work for Robots](http://acm.timus.ru/problem.aspx?space=1&num=1695)
**ℹ️ Statement**: 
Hitung jumlah subgraf lengkap (*complete subgraphs*). Mudah dan menyenangkan. Oh, tidak berfungsi pada contoh uji? Ya, tambahkan $+1$, karena di hari pertama mereka tidak akan menemukan subgraf lengkap yang baru. Terserah lah.

### [Coffee and Buns](http://acm.timus.ru/problem.aspx?space=1&num=1907)
**ℹ️ Statement**: 

Hitung banyaknya $m \leq n$ sehingga

$$
\gcd(a^2 + m^2, \ 4(a + m)) \neq 1
$$

Wah, ternyata ini bukan masalah geometri, melainkan masalah teori bilangan?! Siapa yang akan tahu! Ya… kecuali, tentu saja, orang yang memang membaca pernyataan soalnya.

# 5 | Contoh yang lebih sulit
Sekarang saya akan mencoba menjelaskan sesuatu:

### [GOV-internship 2](http://acm.timus.ru/problem.aspx?space=1&num=1879)
**ℹ️ Statement**: 
Tunggu, apa? Jumlah jarak? *Circular strings*? Kedengarannya sulit. Tapi sebenarnya masalah ini jauh lebih mudah untuk *circular strings*. Mari kita coba ubah jumlah jarak menjadi sesuatu yang lebih sederhana.

Kita membandingkan beberapa pasangan karakter dan menambahkan 1 ke jumlah jika mereka berbeda. Pasangan apa? Yah… semua pasangan. Semua pasangan persis satu kali.

Kita punya beberapa string dengan bagian kosong (*blanks*), dan kita ingin mengisi bagian kosong tersebut sehingga jumlah pasangan karakter yang berbeda menjadi minimal.

**ℹ️ Solution**: 
Sebenarnya kita sudah agak menyelesaikannya. Jelas bahwa jika kita hanya punya bagian kosong di satu string, kita harus mengisinya dengan karakter yang paling sering muncul di string lainnya.

Menerapkan ini ke solusi apa pun, kita akan mendapatkan bahwa di setiap string semua bagian kosong diisi dengan karakter yang sama.

Jika karakter pengisi itu berbeda untuk dua string, keduanya bisa dipilih secara independen dan sebaiknya merupakan karakter yang paling sering muncul di string lainnya (kecuali bagian kosong).
Jika mereka sama, kita bisa mencoba semua kemungkinan karakter tersebut.

### [Martian Plates](http://acm.timus.ru/problem.aspx?space=1&num=1526)
**ℹ️ Statement**: 
Kelihatannya menakutkan. Mari kita mulai menguraikannya. Apa saja aksi yang mungkin kita lakukan? Menaruh satu piring di atas atau mengambil piring teratas. Jadi… *first in last out*. Itu terlihat seperti *stack*. Ya, ini memang *stack*.

Itu awal yang bagus. Jadi kita punya sebuah *stack* dan $n$ jenis benda yang bisa kita taruh di dalamnya. Tapi juga ada beberapa jadwal (*timetable*) yang menggambarkan aksi kita. Dan kita harus menghitung jumlah dari jadwal-jadwal ini…

Bagaimana kalau kita lihat dari sisi lain? Kita punya sebuah jadwal, lalu kita gunakan *stack* untuk memodelkan aksi-aksi yang digambarkan oleh jadwal tersebut. Bukankah ini mirip dengan sesuatu yang sudah kita kenal?

Di sini kamu butuh sedikit pengalaman dan sedikit “sihir”, tapi cepat atau lambat kamu akan sadar bahwa jadwal itu adalah **urutan tanda kurung yang benar** (*correct brackets sequence*) dengan $n$ jenis tanda kurung yang berbeda.

Oke. Sekarang masalah ini beroperasi dengan objek yang sudah familiar. Kita harus menghitung jumlah urutan tanda kurung benar dengan panjang tertentu, dan ada juga beberapa syarat tentang tanda kurung mana yang boleh dibuka pada waktu tertentu. Jumlah jenis tanda kurung tidak lebih dari 10, yang agak menyarankan untuk menggunakan **mask** sebagai *state* di *DP*.

### [Winnie the Pooh](http://acm.timus.ru/problem.aspx?space=1&num=1561)
**ℹ️ Statement and solution included, sorry**: 

Kita hanya tertarik pada hari kerja, jadi pada dasarnya kita hidup dalam modulo 7. Angka 7 adalah bilangan prima, itu memberi kita harapan. Setiap jenis madu membutuhkan jumlah hari tertentu yang tetap tetapi tidak diketahui untuk dimakan. Mari kita sebut nilainya $x_i$.

Dan kita punya beberapa informasi tentang… kombinasi linear dari $x_i$? Dalam bentuk persamaan modulo 7, yaitu di dalam medan (*field*)? Keren, ini adalah masalah tentang **eliminasi Gauss**.

Jumlah *query*-nya juga nyaman! Membaca ulang pernyataannya mengonfirmasi: yang perlu kita lakukan hanyalah memelihara **basis dari suatu sistem persamaan linear**, dan memeriksa apakah persamaan baru sudah bisa diekspresikan sebagai kombinasi linear dari yang lama — ini juga sekaligus menangani bagian pengecekan konsistensi.

Kita bahkan belum melakukan apa pun selain membaca pernyataannya, dan kita sudah memecahkan soal dengan tingkat kesulitan jauh di atas 2000.

### [Titan Ruins: Serial Control](http://acm.timus.ru/problem.aspx?space=1&num=1914)
**ℹ️ Statement**: 
Diberikan sebuah matriks persegi berukuran $n \leq 100$. Periksa apakah ada sebuah vektor dengan beberapa koordinat non-integer yang setelah dikalikan dengan matriks menjadi seluruhnya integer.

APAAN?? Kamu bahkan baca nggak sih soalnya, Um\_nik? Ada sesuatu tentang cincin (*rings*), rotasi, dan sihir, dan… APAAN. Ini jelas kelihatannya seperti geometri ajaib, bukan aljabar linear.

Baca lagi. Dan baca lagi.

Oke, sekarang kita bisa bicara.

Mari kita nyatakan jumlah rotasi penuh dari cincin ke-$i$ yang bisa diakses sebagai $x_i$. Nilainya bisa negatif, bisa juga non-integer. Kita nyatakan jumlah rotasi penuh dari cincin ke-$i$ yang dilindungi sebagai $y_i$, dimana $y_i = \sum_{j=1}^n A_{ij} x_j$ (mungkin $A_j$, tidak terlalu penting).

Ya, itu adalah perkalian matriks dengan vektor. Dan ya, kita ingin $x$ bernilai non-integer dan $y$ bernilai integer.

Sekarang silakan baca lagi pernyataan soalnya.

**ℹ️ Solution**: 
Anggap saja: jika solusi ada, maka ada juga solusi dengan $x$ rasional. Ini mungkin terdengar mencurigakan, tetapi setelah dipikir, suku-suku irasional harus “meniadakan” satu sama lain, karena pada akhirnya kita menginginkan nilai rasional. (Aku tidak ingat buktinya :) )

Misalkan penyebut bersama dari semua pecahan pada $x$ adalah $Q$. Kalau kita mengalikan $x$ dengan $Q$, dua hal terjadi: $x$ menjadi bilangan bulat tetapi tidak semua koordinate-nya habis dibagi $Q$; sedangkan $y$ memiliki semua koordinat yang habis dibagi $Q$. Dengan kata lain, kita mengambil vektor tak-nol modulo $Q$ dan mendapatkan vektor nol modulo $Q$. Atau, pangkat (rank) matriks modulo $Q$ kurang dari $n$. Atau, determinannya modulo $Q$ sama dengan $0$.

$$
x' = Qx \in \mathbb{Z}^n,\quad x' \not\equiv 0 \pmod{Q};\qquad
y' = Ax' = Qy \equiv 0 \pmod{Q}
$$

$$
\Rightarrow \exists\, x' \not\equiv 0 \ (\bmod\ Q):\ Ax' \equiv 0 \ (\bmod\ Q)
\Rightarrow \det(A) \equiv 0 \ (\bmod\ Q).
$$

Lalu, apakah kita harus menghitung determinan **modulo** $Q$, bukan menghitung determinan lalu mengambil sisanya modulo $Q$… atau bagaimana?

Baiklah. Jawabannya adalah `"Death"` **jika dan hanya jika** determinan matriks yang diberikan sama dengan $1$ atau $-1$. Pengecekannya bersifat teknis.

# 6 | Trik paling keren membaca soal
[Zamkadye](http://acm.timus.ru/problem.aspx?space=1&num=1847)

**ℹ️ Statement**: 
Kita punya *minimal spanning tree* (MST) di bidang Euclidean, dan kita harus memilih urutan DFS-nya untuk meminimalkan jumlah jarak antar titik bertetangga. Keren, sepertinya kita sudah mengerti maksud soalnya, apa langkah selanjutnya? Jangan buru-buru.

Kita bereskan dulu detail kecilnya. Apa maksud “memilih urutan DFS”? Bukannya sudah tetap untuk sebuah pohon? Tidak juga, karena kita bisa mengubah urutan anak-anak untuk setiap simpul. Jarak dalam fungsi objektif diukur di bidang, bukan di pohon.

“Kita punya MST di bidang Eucl…” Tunggu. Kita tidak punya “sebuah pohon”, tapi punya MST. MST dari apa? Ya, dari graf lengkap pada titik-titik ini. Oke, keren, tapi untuk apa itu? Bukannya masalahnya sama saja untuk semua pohon? Sepertinya iya. Dan bukannya benar kalau setiap pohon bisa menjadi *spanning tree* dari suatu graf? Misalnya, kita buat graf di mana bobot sebuah sisi adalah jarak pada pohon antara kedua ujungnya. Sudah pasti pohon kita akan menjadi MST untuk graf itu. Siapa sih yang nulis pernyataan soal konyol seperti ini!

**Pesan untuk penyusun soal**: *JANGAN. Tulis. Hal-hal acak.*
Hal-hal aneh ITU **penting**.

Mari kita **BERPIKIR**. Aku tahu, aku tahu, itu sulit, dan kamu sudah membuktikan kalau penyusun soalnya bodoh, dan sekarang waktunya menulis klarifikasi sakti untuk menunjukkan siapa bosnya. Tapi sebentar saja. Mari kita analisis semua hal di pernyataan soal ini.

Ya, memang benar setiap pohon bisa jadi MST untuk suatu graf. Tapi, apakah setiap graf bisa menjadi graf dengan metrik Euclidean? Tidak juga. Kita harus punya ketaksamaan segitiga… dan memang ada untuk contoh kita. Jadi penyusunnya tetap bodoh? Jangan buru-buru. Bidang Euclidean bukan hanya metrik, tapi metrik tertentu yang tetap. Dan kita punya geometri. Kita bisa mengukur sudut, misalnya.

Mari lihat MST kita. Ambil suatu simpul $v$ dan dua tetangga berbeda $u$ dan $w$. Apa yang kita tahu? Jarak antara $u$ dan $w$ haruslah yang terbesar di antara ketiga titik ini, kalau tidak pohon itu bukan MST. Sudut terbesar pada segitiga berada di hadapan sisi terpanjangnya. Ya, teorema sekolah yang tak berguna itu. Teorema ini mengatakan bahwa sudut antara dua sisi dari satu simpul minimal adalah $\pi / 3$. Bahkan lebih besar lagi kalau titik-titiknya berada pada koordinat bilangan bulat. Dari sini kita bisa simpulkan bahwa derajat setiap simpul pada MST kita tidak lebih dari 5.

Ah, mana mungkin. Kalau benar, pasti penyusun soal sudah menulis ini di pernyataan. Ini kan batasan pada input, penyusun soal wajib menuliskannya! Oh, benarkah?

Mungkin masih ada hal lain yang bisa kita gali dari MST dengan metrik Euclidean, tapi fakta tentang batas derajat simpul ini sudah cukup untuk menyelesaikan masalah.


# 7 | Model matematika yang berbeda akan membawamu pada solusi yang berbeda

Ya, tapi hanya kalau kamu punya pola pikir tentang bagaimana menyelesaikan masalah. Dan memang seharusnya kamu punya — pola itu bagus, karena itu cara tercepat untuk menemukan solusi.

[Empire Strikes Back](http://acm.timus.ru/problem.aspx?space=1&num=1520)

**ℹ️ Pernyataan dan Solusi**
Kita harus memilih jari-jari untuk pusat-pusat yang diberikan agar dapat menutupi sebuah lingkaran dengan lingkaran-lingkaran kecil. Kita ingin meminimalkan nilai maksimum dari jari-jari tersebut.

“Oh, ini masalah *min-max*! Aku tahu apa yang harus dilakukan!” — Lakukan *binary search* pada jawabannya, lalu periksa apakah lingkaran-lingkaran kecil dengan jari-jari tersebut bisa menutupi lingkaran besar.

Itu memang solusi yang benar, tapi berjalan dalam kompleksitas $O(n^2)$ (memeriksa perpotongan setiap pasangan lingkaran dan memeriksa semua titik potong dalam waktu $O(n)$). Ini masalah geometri, operasinya berat, dan bisa kena *time limit*.


**ℹ️ Pernyataan dan Solusi 2**
Mari kita pikirkan tentang menutupi satu titik pada lingkaran besar. Lingkaran kecil mana yang akan menutupinya? Tentu saja yang terdekat. Jadi, yang kita minati adalah jarak maksimum antara suatu titik di dalam lingkaran besar dan titik terdekat dari himpunan titik yang diberikan.
Jelas ini adalah masalah *Voronoi diagram*. Dengan ini, solusi $O(n^3)$ sangat mudah, solusi $O(n^{2} \log n)$ sudah standar, dan $O(n \log n)$ pun mungkin — meskipun mungkin hanya dengan kode pustaka.

Pengamatan ini membuat beberapa tim kehilangan medali di **ICPC World Finals 2018**. Tim kami juga terjebak dengan model pertama dan bahkan tidak mencoba mengimplementasikannya karena tampak sangat berat dan kami yakin akan kena *time limit*. Jujur saja, tidak ada anggota tim kami yang bisa menulis *Voronoi* dalam $O(n^{2} \log n)$, jadi mungkin itu tidak terlalu penting juga.

# 8 | Menghilangkan hal-hal yang tidak kamu sukai bisa menyelesaikan masalah

Contoh terakhir di blog ini bukan dari Timus, melainkan dari **Yandex.Algorithm Round 3, 2016**, Problem F. Terima kasih kepada **Endagorion** atas karya yang luar biasa ini.

Soal hanya terlihat oleh peserta, jadi saya akan memberikan versi pernyataan yang sudah disederhanakan di sini:

Diberikan sebuah pohon, semua simpul (vertex) awalnya berwarna putih. Dua pemain, Merah dan Biru, secara bergiliran mewarnai simpul putih menjadi merah dan biru. Permainan berakhir ketika tidak ada simpul putih yang tersisa.

Skor permainan adalah $C_R - C_B$, di mana $C_R$ adalah jumlah komponen terhubung berwarna merah, dan $C_B$ adalah jumlah komponen terhubung berwarna biru. Merah ingin memaksimalkan skor, Biru ingin meminimalkan skor. Tentukan skor jika kedua pemain bermain secara optimal.
Batasan: $n \leq 2 \cdot 10^5$.

---

### Solusi

Pernyataannya jelas, tapi kita tidak menyukai formulanya. Terutama kita tidak menyukai $C_i$, karena nilainya berubah secara tak terduga. Apa yang bisa kita katakan tentang jumlah komponen terhubung setelah menghapus beberapa simpul dari sebuah pohon? Ingat, semuanya adalah pohon itu sendiri. Apa yang kita tahu tentang pohon?

Jumlah simpul selalu tepat **1 lebih banyak** daripada jumlah sisi (edge). Jadi, jumlah komponen dalam sebuah hutan = jumlah simpul − jumlah sisi. Kita bisa menulis ulang formula:

$$
C_R - C_B = (V_R - E_R) - (V_B - E_B) = E_B - E_R + (V_R - V_B)
$$

Nilai di dalam tanda kurung adalah konstan, yaitu $n \bmod 2$. Jadi sekarang kita bermain bukan untuk komponen, tapi untuk **edges**.

Lebih baik, tapi masih belum jelas.

Kita mengendalikan simpul, jadi bisakah kita mengekspresikan $E_i$ hanya menggunakan simpul? Apakah kita memiliki persamaan yang mengekspresikan jumlah edge melalui simpul? Ya, kita punya:

$$
2 \cdot E = \sum_{v} \deg(v)
$$

Namun untuk menghitung $E_R$ kita harus menjumlahkan hanya $\deg_R(v)$, yaitu jumlah tetangga merah. Itu buruk, tapi mari coba saja.

$$
2 \cdot (E_B - E_R) = \sum_{v \in B} \deg(v) - \sum_{v \in R} \deg(v)
$$

Ternyata ini benar, karena semua edge RB saling membatalkan.

Jadi, formula skor adalah:

$$
\frac{1}{2} \left( \sum_{v \in B} \deg(v) - \sum_{v \in R} \deg(v) \right) + (n \bmod 2)
$$

Sekarang mudah dilihat bahwa setiap pemain sebaiknya memilih simpul dengan derajat (degree) terkecil yang tersedia pada saat itu.

