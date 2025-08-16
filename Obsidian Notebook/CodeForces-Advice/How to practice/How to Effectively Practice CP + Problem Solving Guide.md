---
obsidianUIMode: preview
note_type: Advice
judul_materi: How to Effectively Practice CP + Problem Solving Guide
sumber:
  - codeforces
date_learned: 2025-08-15T22:37:00
tags:
  - advice
  - how-to-practice
---
Link Sumber: [How to Effectively Practice CP + Problem Solving Guide - Codeforces](https://codeforces.com/blog/entry/116371)

---
# How to Effectively Practice CP + Problem Solving Guide

Ini adalah sedikit modifikasi dari panduan latihan yang pernah saya tulis di subreddit USACO, karena saya pikir ini bisa bermanfaat bagi orang-orang di sini. Beberapa bagian khusus USACO atau hal-hal tambahan yang tidak diperlukan untuk pembaca umum sengaja saya hilangkan. Panduan ini mencakup semua saran umum untuk competitive programming yang saya miliki, sehingga saya tidak perlu mengetiknya ulang lagi.

---
# 1 | Pendahuluan

Ini adalah tulisan tentang bagaimana menurut saya cara terbaik untuk berlatih competitive programming masa kini, berdasarkan pengalaman saya. Saya berasumsi Anda sudah memiliki sedikit pengetahuan dan memahami hal-hal sederhana seperti binary search dan DFS/BFS. Namun, **bacalah catatan kaki jika Anda benar-benar pemula** (belum pernah coding, menyelesaikan <50 soal, Div2 A/B terlalu sulit, rating abu-abu, atau terjebak di level pupil rendah).

Pertama, berikut ringkasan singkat (*tl;dr*) dari strategi latihan sebelum masuk ke penjelasan dan detail yang lebih banyak:

```ad-info
Singkatnya, sebagian besar yang Anda perlukan hanyalah menggunakan Codeforces (tidak peduli untuk lomba apa Anda sedang berlatih), temukan rentang rating di mana Anda bisa menyelesaikan sekitar 30–40% soal secara mandiri, lalu kerjakan tab problem set dari urutan terbalik berdasarkan ID (pengurutan default). Ikutilah setiap kontes live yang Anda bisa, dan lakukan virtual contest untuk setiap kontes live yang Anda lewatkan.

Selain itu, jika tujuan utama Anda adalah target di luar Codeforces (misalnya USACO, tapi bisa diganti dengan OI apa pun, atau jika ICPC maka ganti saja semua penyebutan OI dengan ICPC), kira-kira seminggu sekali (mungkin setiap akhir pekan) saya sarankan Anda melakukan virtual contest OI, lalu _upsolve_ soal-soal yang solusinya (editorial) Anda mengerti setelahnya. Mulailah dari kontes USACO lama hingga selesai semua kontes dalam 5 tahun terakhir, lalu gunakan daftar OI (OI checklist) untuk mencari kontes baru. Pastikan Anda mengerjakan _subtasks_ sebagaimana Anda melakukannya di kontes nyata.
```

Beberapa bagian dari metode ini mungkin terlihat aneh bagi Anda, jadi saya akan menjelaskannya lebih detail dan memberikan alasan mengapa saya percaya ini adalah metode terbaik, serta memberikan beberapa bukti. Jika Anda terlalu malas untuk membaca semuanya, bagian terpenting dari artikel ini sudah dicetak tebal. Saya juga berasumsi Anda mampu berlatih secara cukup rutin (setidaknya beberapa hari latihan setiap minggu selama beberapa bulan), dan metode ini kemungkinan besar tidak akan berhasil jika Anda tidak melakukannya. Namun, jika Anda benar-benar ingin berkembang dengan cepat, idealnya latihan harus dilakukan setiap hari, tanpa jeda.

---
# 2 | Tujuan Latihan  
Pertama-tama, apa tujuan utama dalam berlatih secara efisien? Menurut saya, Anda ingin menemukan sebanyak mungkin ide dan konsep halus secepat mungkin, lalu belajar untuk secara intuitif menyadari kapan menerapkannya dan apa kesamaan di antara ide-ide tersebut. Inilah yang menjadi fokus utama metode latihan saya.

Tujuan penting lainnya adalah ==Anda juga harus merasakan ketidaknyamanan dalam usaha untuk memikirkan ide-ide baru sebanyak mungkin. Namun, jangan keliru mengartikan ini sebagai rasa bingung yang muncul ketika sama sekali tidak tahu harus melakukan apa.== Keadaan yang Anda inginkan adalah secara aktif menghasilkan wawasan baru secepat mungkin — inilah kondisi yang sering Anda butuhkan selama kontes live, di mana Anda harus tahan untuk terus berpikir ide baru sambil berusaha tidak mengulang-ulang ide yang sama di kepala. Tetapi ketika Anda benar-benar tidak tahu bagaimana mendekati atau memahami solusi dari suatu masalah, kemungkinan besar Anda akan kehilangan fokus dan itu tidak membantu perkembangan Anda, jadi kondisi ini sebaiknya diminimalkan.

---

# 3 | Mengapa Codeforces?  

Jadi, mengapa hanya Codeforces? Karena soal-soal Codeforces terbaru cukup baik dalam memperkenalkan berbagai macam konsep, khususnya di rentang rating 2000+. Berkat standar tinggi yang menginginkan soal-soal non-standar di setiap kontes, banyak trik matematika kecil dan teknik greedy yang diperkenalkan, bersama dengan algoritma standar dan struktur data yang juga muncul cukup sering. Inilah alasan saya menganggap mereka sebagai kumpulan soal terbaik, dibandingkan banyak _online judge_ lain yang lebih standar dan kurang beragam atau kurang inovatif.

Kontes Codeforces terbaru jauh lebih baik dibandingkan kontes lama, sehingga Anda sebaiknya mengerjakan soal dari yang terbaru hingga yang terlama di tab problem set. Jika Anda sudah menyelesaikan semua kontes yang lebih baru dari kontes nomor 450, mungkin sudah saatnya Anda menggunakan _judge_ lain dan mulai melakukan lebih banyak _virtual contest_. Tapi di titik itu, kemungkinan besar Anda sudah tidak memerlukan panduan ini lagi.

---

# 4 | Cara Mendekati Soal Saat Latihan  

Baiklah, jadi Codeforces memang bagus. Lalu mengapa hanya memilih rentang rating di mana Anda bisa menyelesaikan sekitar 30–40% soal secara mandiri? Bukankah seharusnya Anda berlatih untuk menemukan solusi sendiri? Nah, seperti yang saya katakan sebelumnya, ==Anda ingin menemukan sebanyak mungkin konsep secepat mungkin. Jika Anda mampu menyelesaikan 80%+ soal yang Anda kerjakan secara mandiri — bahkan jika butuh waktu lama, atau justru _terutama_ jika butuh waktu lama — maka Anda tidak menggunakan waktu secara efektif, karena sebenarnya Anda sudah mampu menemukan konsep itu sendiri. Tidak apa-apa sering membaca editorial, karena di sanalah Anda benar-benar belajar hal baru==.  

Gunakan _binary search_ di tab problem set untuk menemukan rentang rating soal yang sesuai dengan spesifikasi 30–40%, dan saya sarankan rentangnya hanya beberapa ratus poin. Anda bisa menggeser rentang itu ke atas kapan pun bagian bawahnya mulai terasa lebih mudah dan Anda jadi bisa menyelesaikan lebih banyak soal.

Lalu, pertanyaan berikutnya yang wajar adalah: ==berapa lama sebaiknya berpikir sebelum membaca editorial? Menurut saya, cukup habiskan 15 menit untuk berpikir. Setelah itu, jika Anda masih punya ide, teruskan berpikir, tetapi jika Anda benar-benar buntu, bacalah editorial.== Namun, jika setelah membaca editorial Anda mendapatkan ide baru, lanjutkan berpikir lagi. Memang, Anda mungkin menemukan sebuah trik yang Anda temukan sendiri setelah berpikir lama, dan trik itu bisa dipakai nanti. Tapi, apakah sepadan menghabiskan 3 jam hanya untuk menemukan solusi sendiri, padahal Anda bisa saja mengerjakan 2 atau 3 soal lagi jika memilih membaca editorial?

Sebaliknya, mengerjakan soal yang terlalu sulit juga sama buruknya dengan mengerjakan soal yang terlalu mudah. Tidak ada gunanya menghabiskan 4 jam hanya untuk memahami soal _rated_ 3000, jika dalam waktu yang sama Anda bisa mempelajari lebih banyak konsep dari 4 soal _rated_ 2300 (jika itu sesuai level Anda). Itulah mengapa saya menyarankan target 30–40% — biasanya ini adalah titik di mana Anda bisa memahami editorial dengan cukup cepat, tetapi tidak mampu menemukan konsepnya sendiri.

Ini juga menjadi alasan lain mengapa saya memilih Codeforces dibanding sumber lain: soal-soalnya lebih pendek, sehingga Anda bisa menyelesaikan lebih banyak dalam waktu singkat, dan lebih mudah menemukan banyak soal dengan tingkat kesulitan yang mirip.

Namun, ada beberapa catatan penting: ambillah 15 menit waktu berpikir itu dengan sangat serius dan **selalu implementasikan setiap soal**. Ini sangat penting!!! ==Anda hanya boleh melihat editorial jika benar-benar kehabisan ide dan berpikir lebih lama hanya akan membuat Anda kehilangan fokus atau mengulang-ulang ide lama. Dengan kata lain, Anda seharusnya merasa **lelah secara mental**!! (kalau tidak, berarti Anda belum berpikir cukup keras).==

Jangan lebih malas daripada saat di kontes, jangan menyerah hanya karena tidak mau berpikir lebih keras pada detailnya, dan jangan berpikir atau mengimplementasikan dengan santai. Penting untuk berlatih membuat pengamatan sendiri, dan Anda seharusnya bisa menyelesaikan semakin banyak soal dalam rentang rating tersebut seiring Anda menuruni daftar soal — di situlah Anda tahu bahwa Anda berkembang. Jika Anda tidak berkembang, kemungkinan besar Anda belum benar-benar menguras tenaga Anda.

Mungkin Anda berpikir bahwa Anda bisa mempelajari lebih banyak konsep dengan lebih cepat jika tidak mengimplementasikan solusi, dan itu memang sesuai dengan tujuan utama latihan. ==**Namun**, penting untuk selalu mengimplementasikan setiap soal yang tidak sepenuhnya trivial, bahkan jika Anda sudah menemukan solusinya di kepala. Dengan begitu, Anda akan lebih mengingatnya, dan sering kali Anda akan menyadari bahwa Anda sebenarnya belum memahami detailnya sebaik yang Anda kira sebelum mengimplementasikan.== Selalu implementasikan sebelum membaca editorial jika Anda merasa punya ide, bahkan jika belum yakin. Dan jangan melihat implementasi orang lain sebelum Anda sendiri menyelesaikannya, meskipun Anda sudah membaca editorial — kecuali benar-benar sebagai pilihan terakhir.

Saya juga menyarankan untuk mengatur waktu ketika mengerjakan soal, setidaknya saat mengimplementasikan. Ini akan membantu Anda tetap fokus dan meningkatkan kecepatan implementasi (yang penting agar tidak membuang waktu di kontes). Jika Anda mencatat waktu pengerjaan, semoga Anda akan melihat diri Anda semakin cepat untuk tingkat kesulitan soal yang sama :).

Ketika Anda menyelesaikan sebuah soal, pastikan Anda **merenungkan teknik dan pola pikir** yang digunakan, serta bagaimana Anda bisa menggeneralisasi proses berpikir tersebut agar dapat menyelesaikan soal lain dengan lebih efisien (bayangkan Anda sedang mengajarkan orang lain cara terbaik mendekati soal serupa). Lakukan hal yang sama ketika Anda mempelajari algoritma atau trik baru, dan bayangkan bagaimana Anda akan menemukannya sendiri (kebanyakan algoritma itu sudah lama ada dan sebenarnya tidak sulit jika menggunakan proses yang sama seperti mengerjakan soal kontes untuk menurunkannya dari nol).

Cobalah membuat daftar versi Anda sendiri, mirip dengan daftar yang saya miliki di bagian “*extra advice how to think*”, lalu simpan dan perbarui daftar tersebut setiap kali menyelesaikan soal. ==Tujuannya adalah menemukan daftar ringkas berisi pertanyaan-pertanyaan mendasar yang selalu mengarahkan Anda menuju solusi — bukan sekadar mengelompokkan berdasarkan algoritma atau teknik yang digunakan.==

Bertanyalah secara mendalam bagaimana satu pola pikir bisa berlaku di banyak konteks. Ingat, Anda sedang menyiapkan **sistem untuk menyelesaikan soal baru**, bukan sekadar menghafal soal yang sudah pernah Anda lihat. Demikian pula, renungkan apa saja yang bisa salah dan bagaimana secara sadar menghindari jebakan mental.

==Selain itu, akan berguna juga untuk melihat solusi orang lain setelah Anda menyelesaikan soal dengan cepat, guna melihat apakah ada trik implementasi yang belum Anda ketahui, lalu pikirkan juga bagaimana Anda bisa membuat kode Anda lebih ringkas.==

Saya rasa, di masa depan Anda akan berterima kasih pada diri sendiri jika semua solusi kode Anda dikumpulkan di GitHub, masing-masing dilengkapi komentar satu kalimat yang merangkum poin penting dari soal tersebut — meskipun hal ini tidak terlalu wajib.

---
# 5 | Kapan Belajar Algoritma / Struktur Data  

Pertanyaan berikutnya adalah: kapan dalam metode ini saya seharusnya belajar algoritma atau struktur data standar yang baru?  

==Saran saya, ketika Anda menemukan sebuah algoritma atau konsep lain (mungkin ide matematika) di sebuah editorial yang belum Anda ketahui, segera cari dan baca artikel tentang itu, implementasikan dalam konteks soal tersebut, lalu lanjutkan mengerjakan soal berikutnya di tab problem set.==

Biasanya Anda bisa menemukan artikel tersebut di **USACO Guide**, **cp-algorithms**, atau blog Codeforces. Gagasannya adalah algoritma akan muncul dengan frekuensi yang sesuai dengan relevansinya. Jadi, jika algoritma itu benar-benar penting, Anda akan menemukannya lagi di banyak soal lain dalam waktu dekat, dan Anda tidak perlu mencari soal tambahan khusus dengan topik tersebut.

==Demikian pula, penting untuk melihat algoritma dalam **konteks**, inilah alasan mengapa Anda tidak seharusnya berlatih berdasarkan topik. Jika berlatih per topik, Anda kemungkinan akan melewatkan banyak teknik dan trik halus yang tidak ada di daftar topik, dan terlalu terbiasa mengetahui algoritma yang akan dipakai sejak awal, padahal seharusnya Anda mencoba menebak itu sendiri selama 15 menit waktu berpikir.==

Namun, jika Anda ingin istirahat atau punya waktu luang tambahan ketika tidak bisa mengerjakan soal, membaca artikel algoritma secara acak di tempat-tempat yang disebutkan di atas adalah cara yang baik untuk mendapatkan ide baru. Tapi tetap saja, **lebih penting untuk aktif mengerjakan soal** ketika Anda bisa.

---
# 6 | Kontes Live

Hal yang mungkin paling terlihat salah dari metode latihan ini — meskipun sudah saya jelaskan alasannya sebelumnya — adalah seolah-olah Anda tidak cukup sering berlatih menyelesaikan soal secara mandiri. Di sinilah **kontes live** berperan.

Penting untuk mengikuti sebanyak mungkin kontes live dari semua _judge_ yang Anda bisa (kecuali yang semua soalnya terasa terlalu mudah). Di sinilah Anda melatih kemampuan berpikir mandiri, dan jika Anda rajin mencari, sebenarnya ada banyak sekali kontes yang diadakan setiap saat, terutama yang berkualitas tinggi dari AtCoder dan Codeforces.

==Anda juga sebaiknya melakukan _upsolve_ untuk soal termudah yang belum Anda selesaikan selama kontes.== Namun setelah itu, langsung kembali ke _grind_ problem set Codeforces, kecuali ada soal lain dari kontes tersebut yang masuk dalam rentang rating latihan Anda di Codeforces.

==Terakhir, untuk memastikan Anda mengikuti cukup banyak kontes, setiap kontes Codeforces yang Anda lewatkan dan _rated_ untuk Anda, kerjakan sebagai **virtual contest**.==

Selain itu, jika tujuan utama Anda adalah kontes lain (misalnya USACO/OI, atau diganti dengan ICPC), lakukan virtual OI sekitar **sekali per minggu**, karena _subtasks_ menjadi semakin penting di USACO, dan ini juga bagus untuk melatih fokus dalam waktu lama. Anda juga sebaiknya mengalihkan latihan menjadi sebagian besar OI virtual pada minggu sebelum kontes USACO dimulai.

Pastikan pada OI virtual ini Anda berusaha mendapatkan **poin maksimal** seperti di kontes nyata, yang berarti mengimplementasikan _subtasks_, bukan hanya _full solve_ (atau karakteristik khusus lain dari kontes tersebut yang berbeda dengan Codeforces).

Jika Anda tidak banyak berlatih atau merasa virtual contest terlalu banyak memakan waktu dari latihan Codeforces, mungkin cukup lakukan **dua minggu sekali** alih-alih setiap minggu.

```ad-hint
Upsolve itu istilah di competitive programming buat **menyelesaikan kembali soal yang sebelumnya gagal kamu selesaikan saat kontes**, tapi kali ini di luar waktu lomba.

Biasanya langkahnya kayak gini:

1. **Setelah kontes**, lihat soal-soal yang tadi nggak sempat kamu pecahkan.
2. Coba **kerjain sendiri tanpa lihat editorial dulu** — ini penting biar otak tetap terlatih mikir.
3. Kalau masih buntu setelah usaha cukup lama, **baru baca editorial atau lihat kode orang lain**, lalu coba **implementasi ulang dari nol** sampai benar-benar paham.
4. Kadang juga latihan mengubah-ubah atau mengoptimalkan solusi, biar kamu dapet insight lebih dalam.

📌 Intinya: upsolve itu *kontes versi rematch pribadi* buat memeras semua pelajaran dari soal yang gagal, supaya kalau nemu tipe yang mirip di masa depan, langsung auto-solved.
```

---
# 7 | Menjadwalkan Latihan  

Bagian ini tidak sepenting yang lain, tapi lebih ke beberapa saran untuk menjadwalkan waktu agar latihan bisa konsisten. ==Menurut saya, jelas yang terbaik adalah berlatih setiap hari, dan itu sebenarnya tidak sesulit yang Anda bayangkan jika sudah membangun kebiasaan yang baik.==

Akan bagus jika Anda punya **waktu tetap** setiap hari untuk berlatih, karena ini akan membuatnya menjadi kebiasaan konsisten. Demikian pula, jika Anda bisa menyediakan **tempat khusus** untuk latihan, itu juga bagus, karena akan melatih pola pikir bahwa waktu dan tempat tersebut khusus untuk latihan saja, sehingga Anda membangun fokus. Usahakan latihan setidaknya **90 menit** pada waktu yang sudah dijadwalkan, tapi lebih lama tentu lebih baik. Dan **jangan buka Discord!!!** ketika Anda sedang latihan di waktu khusus itu :clown:.

Selain waktu latihan yang terjadwal, Anda mungkin bisa menambah waktu latihan di beberapa atau banyak hari dengan cara lain jika memang serius. Misalnya, saya rasa bagus untuk menghafal beberapa soal di awal hari — mungkin sedikit lebih sulit dari yang biasanya Anda latih — lalu memikirkannya sepanjang hari (di sekolah, saat mandi, makan, dan sebagainya), atau bahkan soal yang sama selama beberapa hari. Ini membantu Anda melatih kemampuan berpikir mandiri.

Selain itu, ketika punya waktu luang di kelas atau saat di mobil dan orang lain yang menyetir, ini adalah waktu yang baik untuk membaca artikel algoritma. Saat saya bersekolah dulu, saya bahkan membeli keyboard portabel untuk latihan di kelas, dan menghabiskan sebagian besar waktu istirahat makan siang di perpustakaan mengerjakan soal — meskipun ini mungkin agak berlebihan.

Intinya adalah: carilah semua waktu dalam sehari untuk berlatih dengan cara apa pun yang memungkinkan. Tetapi yang paling penting tetaplah **waktu latihan terjadwal**.

---
# 8 | Penyesuaian Menjelang Kontes Besar

Jika Anda sedang berlatih untuk suatu tujuan utama (semoga setidaknya sudah beberapa bulan berlatih mengikuti metode di atas), ketika sudah tinggal beberapa minggu lagi menuju kontes besar, mulailah menghabiskan lebih banyak waktu latihan untuk **virtual contest** yang relevan dengan kontes tersebut, serta tinjau kembali silabus atau ide-ide penting yang relevan (jika ada daftarnya).  

Selain itu, periksa apakah Anda terjebak dalam jebakan berikut:

- **Anda terlalu lambat** dalam menemukan ide atau mengimplementasikan solusi → lakukan lebih banyak virtual contest yang berirama cepat, dan ukur waktu Anda dalam latihan lainnya.
<br/>

- **Anda buruk dalam mengalokasikan waktu** di kontes gaya OI/ICPC → fokuslah pada virtual contest yang relevan, latih pembagian poin _subtasks_, menentukan soal mana yang dikerjakan, dan kapan harus pindah soal, seperti di kontes nyata.
<br/>

- **Masih sulit membuat terobosan ide besar** yang tampak muncul entah dari mana → coba lakukan lebih banyak tebakan, dan mainkan beberapa kontes AtCoder juga, lol.
<br/>

---

# 9 | Penutup  
Semoga panduan ini cukup bermanfaat bagi sebagian dari Anda, dan memberikan gambaran lengkap tentang cara berlatih untuk USACO maupun competitive programming secara umum. Jika menurut Anda ini berguna, silakan bagikan ke orang lain.

Bagi para peserta yang lebih berpengalaman, beri tahu saya jika ada hal yang sangat Anda tidak setujui dari yang saya katakan — saya akan tertarik mendengar sudut pandang Anda, meskipun kemungkinan besar Anda tidak akan mengubah pendapat saya :).

---
# 10 | Catatan Kaki

Saya merekomendasikan bagian awal dari halaman **USACO Training** untuk pemula absolut. Menurut saya, ini adalah cara yang baik untuk memulai karena membimbing Anda mempelajari dasar-dasar, dan Anda sudah bisa memulainya begitu menguasai dasar-dasar sebuah bahasa pemrograman, sebaiknya C++ (Anda bisa menggunakan Codecademy untuk belajar dasar-dasarnya, yang seharusnya hanya memakan waktu maksimal beberapa hari. Bagian-bagian lain dari bahasa tersebut akan Anda pelajari sambil mengerjakan lebih banyak soal dan mencari di Google sesuai kebutuhan).

Namun, segera setelah Anda menyelesaikan **Chapter 1** atau soal-soalnya mulai terasa mudah (atau jika Codeforces masih terasa terlalu menakutkan, maksimal setelah menyelesaikan **Chapter 2**), saat itulah saya menyarankan Anda mulai menggunakan metode latihan ini, dan mungkin juga mencoba beberapa soal dari bagian **Sorting and Searching** di CSES.

Namun, sebagian besar pembaca panduan ini seharusnya sudah memiliki sedikit pengalaman.

**Sumber yang disebutkan:**

- USACO — [http://www.usaco.org](http://www.usaco.org/)
- Codeforces — [https://codeforces.com](https://codeforces.com/)
- AtCoder — [https://atcoder.jp](https://atcoder.jp/)
- CSES — [https://cses.fi/problemset/](https://cses.fi/problemset/)
- Training Gate — [https://usaco.training](https://usaco.training/)
- OI Checklist — [https://oichecklist.pythonanywhere.com](https://oichecklist.pythonanywhere.com/)
- CP-Algorithms — [https://cp-algorithms.com](https://cp-algorithms.com/)
- USACO Guide — [https://usaco.guide](https://usaco.guide/)
- Codecademy — [https://www.codecademy.com/catalog/language/c-plus-plus](https://www.codecademy.com/catalog/language/c-plus-plus)

---
# 11 |  Saran Tambahan: Cara Berpikir untuk Menyelesaikan Soal  

Secara umum, pastikan Anda **selalu memikirkan ide-ide baru** dan terus-menerus **menggabungkan pengamatan lama untuk membuat pengamatan baru**. Jangan khawatir untuk langsung menemukan solusi secara utuh — pikirkan satu langkah kecil demi satu langkah kecil!

Biasanya, ini berarti: pikirkan apa yang Anda ketahui **pasti**, lalu gunakan itu untuk **menebak ide** tentang sifat atau arah penyelesaian, periksa apakah bisa dibuktikan, gabungkan dengan pengamatan sebelumnya, lalu ulangi.

Kalau benar-benar buntu, **cobalah menebak hal yang lebih ekstrem** (ini salah satu hal yang jarang dilakukan orang yang tidak berkembang). **Tulislah pengamatan Anda** dan pastikan Anda menulis hal-hal baru secepat mungkin, bahkan jika terlihat kecil atau tidak relevan.

Untuk tips yang lebih langsung, coba ikuti **daftar periksa berikut** saat mendekati sebuah masalah:

Berarti kalau diterjemahkan, bagian checklist ini kira-kira seperti ini:

1. **Lihat dari sudut pandang biner** — baik dari segi representasi bit maupun dari segi membagi sesuatu menjadi dua bagian — serta dari **sudut pandang graf** (misalnya pasangan dalam input), atau kadang dari **sudut pandang koordinat geometris**.
<br/>

2. **Pikirkan bagaimana informasi yang sudah ada bisa digunakan kembali** — seperti prinsip DP, tapi lebih umum.  Contohnya: two pointers, memperluas konstruksi sebelumnya, sweep line, memecah query menjadi bagian-bagian yang sudah diketahui. Tanyakan: apa yang saling bergantung, dan bagaimana? Urutkan berdasarkan ketergantungan. Kadang, coba buat satu pilihan, lalu lihat apakah masalahnya menjadi bentuk yang sama sehingga bisa diinduksi (contoh: greedy, MST, DP, decision tree seperti trie, atau tanya “apa yang sudah pasti saya ketahui?”). Bisa juga dengan menggabungkan masalah-masalah kecil untuk mendapat jawaban (contoh: range DP, divide & conquer, meet in the middle), sehingga informasi dari masalah kecil bisa dipakai ulang.
<br/>

3. **Sederhanakan semaksimal mungkin** — buat representasi informasi yang ringkas (contoh: bitmask), singkirkan transisi/state yang tidak perlu. Tanyakan: _Apa hal minimum yang dibutuhkan agar kondisi benar?_  Saat ada perubahan atau keputusan dibuat, _apa hal minimum yang benar-benar penting?_  Kadang operasi bisa digabung menjadi operasi yang lebih sederhana (contoh: mengubah operasi menjadi sesuatu yang bisa dipercepat dengan binary exponentiation). Buat batasan seketat mungkin dan gunakan untuk mengurangi jumlah state yang perlu dipertimbangkan.  Tanyakan: apakah jawaban atau konstruksi setara dengan batasan/kondisi minimum tertentu? (Coba tebak jika buntu).
<br/>

4. **Ubah segala sesuatu menjadi rumus** — kembangkan atau tulis ulang sebanyak mungkin bentuk (bahkan yang sederhana seperti ∣x∣→±x). Pikirkan rumus-rumus terkait untuk transformasi (contoh: kombinatorika) dan representasi lain (jangan lupa matriks/polinomial).
<br/>

5. **Visualisasikan semuanya** — gambarkan secara sketsa atau diagram untuk membantu pemahaman.

6. **Cari struktur khusus** seperti sifat monotonicity, concavity, dan sejenisnya. Sifat-sifat ini sering membuka optimisasi seperti binary search atau optimisasi DP. Perhatikan juga **kondisi baru** atau **pembatasan tambahan** yang muncul (contoh: jumlah elemen berbeda hanya $\sqrt{n}$ dari total $n$). Lakukan ini **untuk setiap bagian** dari masalah — baik subbagian tertentu maupun struktur keseluruhan solusi.
<br/>

7. **Telusuri test case secara manual**. Mulailah dengan brute force, lalu bandingkan dengan ide terbaik yang sudah kamu miliki. Jika buntu, buat **generator + brute force checker** untuk mencari pola baru dari data acak.
<br/>

8. **Hindari berpikir hal yang sama berulang kali** Tulis semua ide yang muncul, bahkan yang kecil.
  Setiap pengamatan baru adalah kemajuan, dan mungkin nanti bisa digabung dengan ide lain.
  Mengulang-ulang pikiran yang sama tanpa progres hanya membuang waktu.
<br/>

9. **Gunakan kasus yang disederhanakan** lalu kembangkan. Contoh: ubah $a[i]$ menjadi 0/1, ubah array → tree → graph, ubah $2^x$ menjadi $k$, atau turunkan batas constraint. Bisa juga dengan **mengasumsikan sesuatu yang kamu inginkan sudah ada** (misalnya data structure untuk range query, batas untuk binary search, pengetahuan sebelumnya) lalu selesaikan dari situ — sering kali hal tersebut memang bisa dibuat kalau itu mempermudah.
<br/>

10. **Ubah urutan proses** untuk menyederhanakan. Contoh: ubah add/delete umum menjadi add/delete terakhir (offline), tukar urutan dependensi, atau lihat masalah **dari arah kebalikan** (terutama untuk counting). Secara umum, cobalah **mengganti sudut pandang**. Ulangi pernyataan masalah dan kondisinya dengan sebanyak mungkin cara untuk menemukan perspektif baru. Transformasi yang terlihat “indah” biasanya pertanda arah yang tepat (contoh: difference array).
<br/>

11. **Jika suatu bagian mirip algoritma standar**, atau kamu punya solusi yang terlalu lambat di suatu tahap: Coba pikirkan **semua cara** yang kamu tahu untuk melakukan hal standar itu, lalu lihat apakah ada modifikasi yang cocok untuk masalah yang kamu kerjakan. Pahami bagian mana yang bisa diubah atau diadaptasi untuk kasus spesifik ini.
<br/>

12. **Perhatikan hal “aneh” di statement**. Misalnya constraint yang tidak biasa, atau masalah yang mirip problem terkenal tapi dengan perbedaan kecil. Hal-hal ini biasanya adalah kunci solusi — pikirkan kenapa pembuat soal menaruhnya.
<br/>

13. **Kadang brute force masih berguna**. Kalau pilihan kecil, brute force saja. Kalau pilihan terlalu banyak, bisa pilih secara acak atau pilih yang menonjol (misalnya nilai maksimum/minimum, atau hanya yang paling dekat di kiri/kanan). Sering kali **kasus ekstrem** adalah kuncinya.  Kalau problem terlihat terlalu sulit di awal, coba tebak bagian mana yang **tidak penting** untuk jawaban. Pada soal konstruktif/interactive dengan banyak pilihan, sering bisa selesai hanya dengan subset kecil dari pilihan yang ada.
<br/>

14. **Jangan terlalu mempersulit**. Coba beberapa arah, tapi jika membutuhkan terlalu banyak langkah atau edge case, mungkin itu bukan arah yang benar. Biasanya ada solusi yang rapi dan mudah dibuktikan. Tebak solusi yang “indah” (misalnya greedy atau konstruksi paling sederhana), berharap itu benar, lalu verifikasi. Jangan memaksa jalur tertentu sampai buntu. Jika terjebak pada detail kecil meski sudah di jalur yang benar, mundur sebentar dan pikir ulang gambaran besarnya.
<br/>

15. **Ubah fokus antara lokal dan global**. Kadang lebih mudah memikirkan jawaban untuk satu elemen saja daripada seluruh proses (contoh: membuat kondisi untuk binary search atau menghitung kasus per elemen, mudah di-update untuk query).  Kadang sebaliknya: lihat seluruh himpunan solusi di awal, siapkan data offline, lalu kerjakan sekaligus. Intinya, ubah **skala atau ruang lingkup** berpikir sesuai kebutuhan.

16. **Percaya bahwa kamu bisa menyelesaikan setiap problem**, tapi hadapi setiap problem selangkah demi selangkah. Bahkan ide-ide paling standar pun bisa dipelajari sendiri jika diperlakukan seperti problem baru pada umumnya.
<br/>

17. **Kalau mengingat samar-samar soal yang mirip** tapi tidak ingat sumber atau detailnya, **jangan buang waktu** untuk mengingat. Lebih baik mulai menyelesaikan dari nol.
<br/>

18. **Jika waktu hampir habis**, kadang bisa mencoba **cheese** (cara nakal) dengan solusi acak atau heuristik. Ini terutama berlaku di kompetisi OI yang punya subtasks — dapat poin parsial masih lebih baik daripada kosong.
<br/>

19. **Bisa memecah problem menjadi beberapa bagian** yang diselesaikan dengan cara berbeda tergantung constraint.  Contoh: sqrt decomposition, small-to-large, memisahkan bagian update dan query, atau membedakan kasus genap/ganjil.
<br/>

20. **Pecah menjadi problem independen** jika memungkinkan. Contoh: interval yang tidak saling mempengaruhi, atau memisahkan koordinat $x$ dan $y$. Kalau bergantung pada banyak hal sekaligus, proseslah dalam urutan yang menghilangkan salah satu dimensi ketergantungan dulu sehingga hanya perlu fokus pada sisanya. Contoh: sweep line di satu dimensi, lalu query di dimensi lainnya.
<br/>

21. **Petakan ke bentuk kanonik** (mis. leksikografis minimal) atau ke representasi yang ekuivalen untuk membantu perhitungan (_counting_) atau memberi sudut pandang alternatif pada solusi. Contoh: pikirkan ide **greedy** untuk mencapai konfigurasi tertentu, lalu buat **DP counting** yang meniru langkah greedy agar tidak terjadi _overcount_. Temukan ide sederhana untuk **satu** kueri dulu, lalu percepat **banyak** kueri dengan **pra-komputasi** kondisi (mis. hal-hal yang ditambahkan saat greedy) agar lebih cepat.
<br/>

22. **Bayangkan seolah-olah kamu sudah tahu solusinya di awal**, lalu kunci pilihan-pilihan tertentu sejak awal dan selesaikan sisanya.  Teknik ini bisa dipakai untuk membuktikan dua hal ekuivalen, menyingkirkan pilihan yang tak perlu dipertimbangkan, atau mengungkap sifat konfigurasi optimal.
<br/>

23. **Hitung hanya yang benar-benar perlu** pada setiap waktu, terutama untuk skenario **update/query**.  Kadang bisa memakai argumen **amortized** atau **lazy** (mis. melacak interval tertutup dalam _set_, **lazy propagation** pada segtree).
<br/>

24. **Tanya: apa yang tetap (invarian) dan apa yang berubah?**  Bagaimana satu operasi memengaruhi properti masalah (jumlah/selisih elemen, selalu mendekati target, bisa dibalik, dst.)?   Saat menelusuri test case manual, **tebak** sifat-sifat ini lalu **buktikan/bantah**. Gunakan properti tersebut untuk membuktikan pilihan mana yang optimal atau apa **bottleneck** sehingga bisa memberi batas pada jawaban.
<br/>

25. (Mirip poin **3** dan **10**) **Kompresi kelompok objek** lalu selesaikan di atas kelompok itu ketika relasi internalnya tidak relevan, dan terus sederhanakan bila memungkinkan sepanjang proses. Contoh: kompres **siklus**, **SCC**, **biconnected components**, **directed MST**.
<br/>

26. Saat **menebak ide**, pastikan kamu mencatat **semua asumsi** yang dibuat, bahwa asumsi itu **benar** dan **mencakup masalah secara penuh**. Buat contoh yang menyorot apa saja yang bisa gagal, lalu pakai untuk membantu membuktikan/menyangkal ide. Jika kamu terlalu lama menghabiskan waktu membantah ide yang salah, kemungkinan kamu perlu melangkah **lebih bertahap**; jangan menebak ekstrem sebelum benar-benar buntu.
<br/>

27. Jika **buntu di detail** padahal ide utama sudah ada, buat **lebih banyak test case** manual dan/atau tulis **pseudocode yang rinci**, tandai langkah yang belum sepenuhnya kamu yakini bekerja, lalu pikirkan lebih dalam. **Jangan malas menuliskan detail!**
<br/>

28. Bisa kah kamu membuktikan sesuatu **benar “sebagian besar waktu”**? Coba teknik **probabilistik** (mis. **hashing**, pengujian pada himpunan sampel, dst.) atau juga lihat **poin 19**.


Selain itu, memang baik menggunakan batasan-batasan problem sebagai panduan awal untuk menentukan arah berpikir, tetapi jangan sampai hal itu membatasi diri pada satu ide tertentu saja. Ingat juga, apapun yang terjadi, jangan sampai salah membaca soal—lebih baik meluangkan sedikit waktu tambahan untuk memahami soal dengan benar daripada terburu-buru mengerjakan hal yang ternyata bukan yang diminta.

---

# 12 | Tips Implementasi  

Pertama, periksa secara singkat apakah kamu tidak melewatkan ide atau metode implementasi yang lebih mudah. Hal ini akan menghemat banyak waktu.

Usahakan memiliki gambaran yang jelas untuk setiap bagian kode yang akan kamu tulis, lalu tulislah secepat mungkin. Kadang kamu tidak punya gambaran jelas untuk seluruh kode dan hanya punya garis besar, dan itu tidak masalah, tetapi di pikiranmu tetap harus ada pembagian bagian kode menjadi potongan kecil, dan setiap potongan kecil itu sudah jelas rencananya sebelum ditulis. Jika perlu, pikirkan lagi sebelum menulis bagian berikutnya. Rencanakan kodenya agar ringkas namun tetap mudah dibaca, dan hindari menulis ulang hal yang sama berkali-kali. Jika kamu terus menulis ulang, berarti kamu perlu mundur sejenak, merencanakan lebih baik, dan memeriksa lagi idemu.

Untuk debugging, cukup tambahkan banyak pernyataan print di dalam kode lalu cari sumber masalahnya. Cobalah melakukan _binary search_ pada alur kode untuk mencari tahu di bagian mana hasil keluaran pertama kali tidak sesuai perkiraan. Jika menyadari ada bagian yang tidak benar, jangan terjebak membuat perubahan kecil berulang-ulang untuk memperbaikinya. Sebaiknya kembali ke tahap perencanaan dan tulis ulang ketika sudah jelas. Cobalah juga menelusuri beberapa contoh secara manual mengikuti langkah kode, dan baca setiap baris kode dengan teliti. Sering kali, kesalahan justru ada di bagian yang kamu yakini tidak mungkin salah, lol.

Menambahkan satu kalimat komentar di kode yang menjelaskan ide utama dari setiap masalah juga akan sangat membantu, baik untuk mempermudah debugging maupun untuk memahami solusi di masa depan, jika suatu saat kamu perlu melihat kembali kode tersebut.

---
# 13 | Membagi Waktu di Kontes OI  

Dengan asumsi ada 3 soal dalam 4 jam — sesuaikan skala sesuai kebutuhan

Biasanya saya membaca semua 3 soal di 15 menit pertama, lalu menghabiskan sekitar 15 menit untuk masing-masing soal guna memikirkan idenya dan menentukan urutan tingkat kesulitan menurut saya, dari yang paling mudah. Jika dalam waktu itu saya sudah menemukan solusi lengkap untuk satu soal, saya langsung mengimplementasikannya. Kalau belum, saya melakukan langkah berikut. Saya kemudian membagi sisa waktu sekitar tiga jam secara merata untuk ketiga soal, dan mencoba mengerjakannya dari yang termudah ke yang tersulit.

Saat fokus pada satu soal, sangat penting untuk benar-benar fokus hanya pada soal itu. Selama sebagian besar jam untuk soal tersebut, implementasi dilakukan segera setelah solusi lengkap ditemukan. Implementasi untuk subtask bisa dilakukan jika hal itu membantu menguji ide menuju solusi penuh, atau jika sudah benar-benar kehabisan ide baru (dalam kondisi ini, setelah mengimplementasikan subtask, lanjutkan ke soal berikutnya). Namun, jika sudah menghabiskan sekitar 50 menit untuk satu soal dan belum menemukan solusi lengkap, serta kemungkinan tidak akan mendapatkannya dalam 5 menit berikutnya, walaupun merasa masih bisa membuat kemajuan, cukup implementasikan subtask yang sudah ditemukan lalu pindah. Penting untuk benar-benar berpindah karena bisa saja penilaian awal tentang soal termudah ternyata keliru, dan kita ingin punya waktu untuk mencoba semua soal (hal ini beberapa kali menjadi penyebab kegagalan saya di masa lalu). Artinya, begitu berpindah soal, usahakan tidak ada pikiran yang tertinggal, dan sepenuhnya fokus pada soal berikutnya.

---
# 14 | Latihan Matematika + CS  

Jika kamu sedang berlatih untuk olimpiade matematika dan olimpiade informatika, atau sekadar ingin bahan bacaan yang mungkin membantu, cobalah membaca dan mengerjakan beberapa soal dari buku kombinasi keduanya. Secara keseluruhan, akan lebih baik jika kamu aktif menyelesaikan lebih banyak soal untuk latihan CP, tapi jika ada waktu luang, buku ini cukup layak dibaca — karena CP pada dasarnya adalah kombinasi olimpiade matematika + struktur data + implementasi.

Latihan untuk olimpiade matematika secara umum juga akan membantu di competitive programming, tetapi jika fokusmu hanya CP, sebaiknya tetap mengerjakan soal-soal CP langsung.

---
# 15 | Motivasi Tambahan  
Dalam segala hal di hidup ini, kunci keberhasilan adalah belajar menemukan kepuasan dari setiap langkah kecil yang membawa kita menuju kemajuan. Dalam konteks CP, setiap soal yang berhasil diselesaikan dan setiap hari berlatih adalah satu langkah lebih dekat ke tujuanmu di competitive programming. Saat mengerjakan soal, setiap pengamatan baru adalah satu langkah lebih dekat ke solusi.

Pastikan juga kamu tahu prioritasmu dan apa yang benar-benar kamu inginkan dari hidup, supaya tidak menyesal. Jika kamu sungguh ingin mahir di CP, berhenti buang-buang waktu, berhenti mengambil hari libur, mulailah mengerjakan soal sebanyak mungkin, dan kamu akan menemukan kesuksesan. Terobsesilah dengan hal yang paling kamu inginkan sampai kamu mencapainya.