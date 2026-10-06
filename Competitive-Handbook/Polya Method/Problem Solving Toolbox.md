Source: **The HTSI Protocol: G.P. 1945 Archive**
# A. Tips & Trick

## I. Memahami Soal
### 1. Draw a Figure

Menggambar figur (*draw a figure*) adalah langkah awal menerjemahkan masalah abstrak ke bentuk yang lebih konkret dan mudah dikelola. Gambar atau ilustrasi memvisualisasikan hubungan antara yang diketahui dan yang dicari, sehingga pola tersembunyi yang tidak tampak dalam teks atau angka mentah dapat terlihat. Gambar bekerja bersama notasi yang tepat: gambar menunjukkan strukturnya, notasi memberi nama pada setiap unsurnya.

1. Buatlah gambar atau ilustrasi dari masalah sebelum mencari penyelesaian, karena informasi visual jauh lebih mudah diproses daripada teks atau angka mentah.
2. *Dapatkah hubungan antara yang diketahui dan yang dicari digambarkan?* Tunjukkan data dan yang tidak diketahui pada gambar yang sama.
3. Amati gambar untuk menemukan pola atau hubungan tersembunyi yang belum terlihat dari pernyataan masalah.
4. Beri simbol, variabel, atau nama yang jelas dan konsisten pada setiap unsur dalam gambar, agar masalah nyata dapat dijembatani ke bentuk matematis atau logis.
5. Gunakan notasi yang baik sebagai bahasa ringkas, sehingga perhitungan dan analisis lanjutan dapat dilakukan secara terstruktur tanpa kebingungan.

**Konteks Pemrograman:**

6. Gambarlah soal dalam bentuk yang sesuai dengan strukturnya, seperti graf untuk relasi antarobjek, grid untuk peta dan matriks, garis bilangan untuk interval, pohon untuk hierarki, atau tabel untuk keadaan DP.
7. Gambarlah contoh masukan dari soal, lalu telusuri secara manual pada gambar tersebut untuk memastikan pemahaman terhadap keluaran yang diminta.
8. Tandai pada gambar nilai masukan, keluaran yang dicari, dan batasan penting, seperti $n$ simpul dan $m$ sisi, agar hubungan antara data dan yang dicari terlihat.
9. Gunakan gambar untuk menemukan pola, misalnya dengan menggambar kasus kecil secara berurutan lalu mengamati apa yang berubah dari satu kasus ke kasus berikutnya.
10. Gambarkan keadaan data selama algoritma berjalan, seperti isi larik, tumpukan, antrean, atau tabel DP pada tiap langkah, agar kesalahan logika mudah ditemukan.
11. Selaraskan nama pada gambar dengan nama variabel dalam kode, seperti `adj`, `dist`, dan `dp`, agar gambar dan kode dapat dicocokkan langsung.
12. Gambar adalah alat bantu, bukan bukti. Periksa bahwa pola yang tampak pada gambar juga berlaku pada kasus lain, terutama kasus tepi yang sulit digambar, seperti $n = 0$ atau $n = 1$.

### 2. Look at the Unknown

Prinsip melihat yang tidak diketahui (*look at the unknown*) berakar dari ungkapan *respice finem*, yaitu lihatlah tujuan akhir. Pada masalah pencarian, perhatian dipusatkan pada yang dicari, dan pada masalah pembuktian, pada kesimpulan yang hendak dibuktikan. Fokus pada tujuan mengarahkan pikiran untuk mencari alat, metode, dan penyebab yang dapat menghasilkannya. Mengingat masalah lama dengan yang tidak diketahui sama atau mirip adalah titik awal yang paling masuk akal dan praktis.

1. *Apa yang tidak diketahui?* Pada masalah pembuktian: *apa kesimpulannya?*
2. *Lihat yang tidak diketahui! Adakah masalah lama dengan yang tidak diketahui sama atau mirip?* Cara ini lebih efisien daripada mencari "masalah terkait" secara umum.
3. Lihat masalah lama itu secara skematis saja, tanpa terbebani seluruh detailnya yang rumit, karena hal ini menghemat beban penyajian.
4. Manfaatkan penyaringan oleh jenis yang tidak diketahui, karena pilihan dari ingatan langsung menyempit pada masalah dasar dan paling akrab yang memiliki jenis yang dicari sama.
5. Biarkan jenis yang dicari menyarankan rencana awal, lalu tambahkan elemen pembantu yang diperlukan. Perkiraan bahwa unsur yang belum diketahui dapat dicari sudah merupakan kemajuan esensial dalam membentuk rencana.
6. Apabila tidak ada masalah lama dengan yang tidak diketahui persis sama, beralihlah ke masalah dengan yang tidak diketahui yang mirip sebagai panduan.
7. Pada masalah pembuktian, pusatkan perhatian pada kesimpulan, lalu panggil kembali teorema lama dengan kesimpulan serupa. Dari sana, rencana pembuktian biasanya muncul.
8. Sadari bahwa ada atau tidaknya masalah acuan menentukan mudah atau sulitnya suatu masalah. Tanpa masalah dasar yang sesuai, penyelesaian menuntut gagasan yang benar-benar baru.

**Konteks Pemrograman:**

9. Tuliskan terlebih dahulu dengan tepat apa yang diminta oleh keluaran, termasuk jenisnya (satu bilangan, himpunan, urutan, konstruksi, atau jawaban ya atau tidak), jumlahnya, dan aturan bila ada banyak jawaban yang sah.
10. Gunakan jenis keluaran sebagai petunjuk teknik. Misalnya, "hitung banyaknya" sering mengarah ke DP atau kombinatorika, "nilai minimum atau maksimum" ke greedy, DP, atau pencarian biner pada jawaban, "jarak terpendek" ke algoritma jalur terpendek, dan "ada atau tidak" ke pemeriksaan syarat perlu dan cukup.
11. Cari soal lama yang keluarannya sama atau mirip, lalu tentukan apakah bentuk masukan dan batasannya juga sesuai sehingga tekniknya dapat dipinjam.
12. Tanyakan besaran apa saja yang menentukan keluaran, lalu rancang keadaan DP, struktur data, atau variabel pembantu yang menyimpan besaran tersebut.
13. Mulailah dari keluaran dan telusuri ke belakang: informasi apa yang harus tersedia agar keluaran ini dapat dihitung, dan dari mana informasi itu diperoleh.
14. Pada soal pembuktian atau pada saat memverifikasi algoritma, tulis kesimpulan yang harus berlaku (misalnya keluaran optimal atau semua syarat terpenuhi), lalu cari sifat atau lemma yang menghasilkannya.
15. Periksa kecocokan antara jenis keluaran dan teknik yang dipilih, terutama batasan seperti $n$ dan $m$. Pencocokan keluaran saja tidak menjamin teknik tersebut cukup cepat.

### 3. Notation

Notasi (*notation*) adalah bahasa yang dirancang khusus agar ringkas, presisi, dan konsisten tanpa pengecualian. Pemilihan notasi memengaruhi tingkat kesulitan perhitungan, kejelasan berpikir, dan efisiensi penyelesaian masalah, sehingga perlu ditetapkan sejak awal. Merumuskan persamaan pada hakikatnya adalah menerjemahkan bahasa sehari-hari ke dalam bahasa simbol.

1. Pilihlah notasi dengan cermat sejak awal, karena langkah ini menghemat waktu, menghindarkan keraguan, dan memaksa unsur-unsur masalah dipahami lebih tajam.
2. Gunakan satu simbol hanya untuk satu objek dalam satu masalah. Satu objek boleh ditulis dengan simbol berbeda apabila ada alasan khusus.
3. *Apakah notasi ini langsung mengingatkan pada objeknya?* Gunakan huruf awal nama objek, selama huruf tersebut belum dipakai untuk hal lain.
4. Gunakan huruf awal alfabet, seperti $a$, $b$, $c$, untuk data atau konstanta yang diketahui, dan huruf akhir alfabet, seperti $x$, $y$, $z$, untuk hal yang dicari. Apabila beberapa objek berkedudukan setara, urutan huruf lebih disukai daripada inisial.
5. Gunakan jenis huruf yang berbeda untuk kategori yang berbeda, agar kategori objek dapat dikenali dari hurufnya.
6. Cerminkan hubungan antarobjek melalui huruf yang bersesuaian, sehingga simbol saling menunjuk satu sama lain.
7. Upayakan notasi yang padat makna (*pregnant notation*), yaitu notasi yang memungkinkan kesimpulan ditarik langsung tanpa harus melihat gambar.
8. Hindari memakai simbol berarti baku, seperti $e$, $i$, dan $\pi$, untuk arti lain agar tidak menimbulkan kebingungan.
9. Manfaatkan notasi standar yang lazim dipakai pada masalah sebelumnya, karena notasi tersebut membantu memanggil kembali prosedur lama yang berguna.

**Konteks Pemrograman:**

10. Beri nama variabel yang bermakna dan mencerminkan peran datanya, serta gunakan satu nama untuk satu peran pada seluruh program.
11. Ikuti notasi pada pernyataan soal, seperti $n$, $m$, $k$, dan `a[i]`, agar kode mudah dicocokkan dengan soal dan batasannya.
12. Tetapkan konvensi indeks sejak awal, yaitu mulai dari `0` atau `1` serta rentang tertutup atau setengah terbuka, lalu pertahankan secara konsisten.
13. Tulis dalam komentar atau catatan arti setiap keadaan DP, setiap fungsi, dan setiap invarian sebelum mengodekannya.
14. Bedakan notasi yang berkaitan, seperti nilai dan indeks, serta jawaban dan jawaban sementara, melalui awalan atau akhiran yang seragam.
15. Gunakan nama standar dan singkatan yang lazim dalam pemrograman kompetitif, seperti `dp`, `pre`, `adj`, dan `dist`, agar mudah dikenali kembali.
16. Hindari nama yang mudah tertukar, seperti `l`, `1`, `O`, dan `0`, serta nama yang bentrok dengan fungsi atau pustaka bawaan.

### 4. Setting Up Equations

Menyusun persamaan (*setting up equations*) pada hakikatnya adalah penerjemahan dari bahasa sehari-hari ke dalam bahasa simbol. Kesulitan utama dalam pemecahan masalah sering kali terletak pada penerjemahan konteks verbal menjadi bentuk matematis, sehingga proses ini perlu dilakukan dengan teliti dan tidak tergesa-gesa.

1. Pahami sepenuhnya syarat masalah yang tertulis dalam kata-kata, serta kuasai bentuk ekspresi dan notasi matematika yang akan digunakan, seperti halnya penerjemah menguasai bahasa asal dan bahasa tujuan.
2. Pada masalah sederhana, pisahkan pernyataan verbal dan ubah langsung menjadi simbol.
3. Pada masalah yang lebih rumit, jangan terpaku pada kata demi kata. Pusatkan perhatian pada makna utamanya, lalu susun ulang pernyataan kondisi agar selaras dengan rumus atau konsep matematis yang tersedia.
4. *Dapatkah syarat masalah dipisahkan menjadi bagian-bagian?* Uraikan kondisi yang besar menjadi beberapa syarat terpisah.
5. *Dapatkah bagian ini dituliskan sebagai persamaan?* Evaluasi setiap syarat secara mandiri dengan pertanyaan tersebut.
6. Lakukan pemisahan hanya apabila bagian-bagiannya dapat dinyatakan secara matematis.
7. Hubungkan definisi konsep dasar dengan hubungan geometris atau aljabar yang dapat diubah menjadi rumus.
8. Jangan terburu-buru menuliskan rumus sebelum masalah diuraikan dengan benar.

**Konteks Pemrograman:**

9. Terjemahkan pernyataan soal menjadi model formal, yaitu tentukan besaran yang dicari, besaran yang diketahui, dan hubungan di antara keduanya, misalnya dalam bentuk rumus, relasi rekurens, atau graf.
10. Tuliskan batasan soal sebagai pertidaksamaan, misalnya $1 \le n \le 2 \cdot 10^5$, lalu gunakan untuk menentukan kompleksitas yang dapat diterima.
11. Nyatakan jawaban sebagai relasi rekurens, yaitu tentukan arti keadaan, nilai awal, dan transisi antarkeadaan, misalnya $dp_i = \min(dp_{i-1}, dp_{i-2}) + c_i$.
12. Ubah syarat dalam kata-kata menjadi syarat logis yang dapat diperiksa dengan kode, seperti `a[i] <= a[j]` atau `sum % k == 0`, lalu pisahkan syarat majemuk menjadi syarat tunggal.
13. Periksa model terhadap contoh masukan dengan menghitung secara manual, agar kesalahan penerjemahan terdeteksi sebelum menulis kode.
14. Perhatikan makna kata yang rawan salah tafsir, seperti "paling sedikit" dan "paling banyak", "berbeda" dan "berurutan", serta rentang yang tertutup atau setengah terbuka.

### 5. Condition

Syarat (*condition*) adalah bagian utama dari masalah pencarian, yang menentukan hubungan antara yang tidak diketahui dan data. Berdasarkan sifat dan jumlah pembatasnya, syarat dapat berlebihan (*redundant*), kontradiktif (*contradictory*), tidak cukup (*insufficient*), atau pas (*just sufficient*). Memeriksa jenis syarat membantu menilai apakah suatu masalah dapat dipecahkan dan apakah jawabannya tunggal.

1. Kenali syarat sebagai bagian utama masalah pencarian, dan pastikan bagian-bagiannya terpahami sebelum mencari penyelesaian.
2. *Apakah mungkin memenuhi syarat itu?* Syarat yang bagian-bagiannya saling bertentangan tidak dapat dipenuhi oleh objek atau nilai mana pun.
3. *Apakah syarat cukup untuk menentukan yang tidak diketahui?* Syarat yang tidak cukup menyisakan lebih dari satu kemungkinan jawaban.
4. *Apakah syarat berlebihan atau kontradiktif?* Syarat berlebihan memuat bagian yang tidak diperlukan, sedangkan syarat kontradiktif tidak dapat dipenuhi.
5. Bandingkan jumlah syarat dengan jumlah yang tidak diketahui. Syarat yang lebih banyak biasanya berlebihan atau kontradiktif, syarat yang lebih sedikit biasanya tidak cukup, dan jumlah yang sama biasanya pas.
6. Ingat bahwa kesamaan jumlah hanyalah petunjuk umum. Pada kasus pengecualian, syarat yang jumlahnya sama dengan jumlah yang tidak diketahui tetap dapat kontradiktif atau tidak cukup.

**Konteks Pemrograman:**

7. Periksa apakah batasan soal dapat dipenuhi oleh suatu masukan atau keluaran. Apabila soal meminta menentukan ada atau tidaknya jawaban, kontradiksi antarsyarat adalah salah satu kemungkinan jawabannya.
8. Periksa apakah syarat cukup untuk menentukan keluaran secara tunggal. Apabila ada banyak jawaban yang sah, cari tahu bagaimana soal memilih salah satunya, seperti terkecil secara leksikografis, nilai optimum, atau jawaban apa pun yang valid.
9. Kenali syarat yang berlebihan dalam soal, seperti jaminan yang tidak memengaruhi jawaban. Namun, berhati-hatilah, karena pada soal kontes jaminan masukan sering sengaja diberikan agar dapat dimanfaatkan.
10. Pisahkan syarat majemuk menjadi syarat tunggal, lalu periksa satu per satu apakah ada yang saling bertentangan atau saling mengimplikasikan.
11. Periksa kasus tepi yang membuat syarat tidak dapat dipenuhi atau tidak menentukan jawaban, seperti masukan kosong, nilai batas, atau parameter yang saling bertentangan, dan tentukan keluaran yang diminta pada kasus tersebut.
12. Pada soal konstruktif, bangun jawaban lalu periksa dengan pemeriksa sederhana (*checker*) bahwa seluruh syarat terpenuhi. Pada soal yang menuntut jawaban "tidak mungkin", buktikan bahwa ada syarat yang pasti terlanggar.

## II. Pencarian Ide
### 6. Definition

Definisi (*definition*) adalah pernyataan makna suatu istilah dengan memakai istilah lain yang sudah dipahami dengan baik. Istilah matematika terbagi menjadi istilah primitif yang tidak didefinisikan secara formal dan istilah turunan yang didefinisikan secara formal. Definisi matematika bersifat mendikte, yaitu menciptakan makna matematisnya sendiri, bukan mengikuti pemakaian bahasa sehari-hari. Kembali ke definisi membantu melihat fakta nyata di balik istilah teknis, karena kekuatan sebuah istilah terletak pada gagasan di baliknya, bukan pada bunyinya.

1. *Apa definisi dari istilah-istilah dalam masalah ini?* Kembalilah ke definisi ketika masalah dipenuhi istilah teknis yang belum dipahami.
2. Jangan berhenti pada mengetahui definisi. Gunakan definisi itu dengan memasukkan unsur dan hubungan konkretnya ke dalam gambar atau persamaan.
3. Ganti istilah teknis dengan definisinya, sehingga masalah yang tampak rumit dan muluk disederhanakan menjadi pernyataan baru yang bebas dari istilah teknis tersebut.
4. Bedakan istilah primitif dari istilah turunan, dan ingat bahwa makna istilah matematika ditentukan oleh definisinya, bukan oleh arti sehari-hari.
5. Apabila hanya definisi yang kamu ketahui, kembali ke definisi adalah satu-satunya jalan. Apabila kamu menguasai teorema terkait, pertimbangkan memakai teorema karena dapat lebih efisien.
6. *Adakah definisi alternatif untuk objek yang sama?* Pilih definisi yang paling memudahkan penyelesaian.
7. Gunakan kembali ke definisi untuk menguji argumen, baik milik sendiri maupun orang lain: gantikan istilah dengan definisinya di dalam pikiran, lalu pastikan sifat hakiki istilah itu benar-benar diperhitungkan.

**Konteks Pemrograman:**

8. Baca ulang istilah kunci dalam soal secara harfiah, seperti "subarray", "subsequence", "jalur sederhana", "pohon", "permutasi", atau "berurutan", dan pastikan definisinya sama dengan yang kamu bayangkan. Perbedaan kecil sering mengubah soal secara total.
9. Tuliskan definisi formal setiap istilah dalam soal sebagai syarat yang dapat diperiksa, seperti `a[i] <= a[j]` atau `sum % k == 0`, lalu pakai syarat tersebut dalam model.
10. Substitusikan definisi ke dalam pernyataan soal untuk menyederhanakannya, misalnya mengganti "bilangan prima" dengan "bilangan yang tepat memiliki dua pembagi positif", dan lihat apakah soal menjadi lebih sederhana.
11. Pilih definisi yang paling cocok dari beberapa definisi ekuivalen, misalnya pohon sebagai graf terhubung tanpa siklus, atau sebagai graf terhubung dengan $n - 1$ sisi, tergantung mana yang memudahkan algoritma.
12. Periksa definisi pada kasus tepi, seperti apakah subarray boleh kosong, apakah rentang tertutup atau setengah terbuka, dan apakah $0$ dan $1$ termasuk bilangan prima atau tidak.
13. Gunakan definisi untuk menguji solusi dan bukti, termasuk editorial: pada tiap klaim, tanyakan apakah klaim itu benar menurut definisi, bukan hanya menurut contoh.
14. Perjelas istilah yang ambigu dalam soal dengan membaca ulang pernyataan dan contoh masukan. Apabila tetap ambigu, dalam kontes ajukan klarifikasi bila diizinkan, dan dalam latihan tulis asumsi secara eksplisit.

### 7. Analogy

Analogi (*analogy*) adalah bentuk kemiripan khusus ketika dua objek memiliki kesamaan dalam hubungan antarbagian internalnya, meskipun objeknya sendiri berbeda. Tingkat analogi bervariasi, mulai dari yang samar hingga yang memiliki presisi matematis. Dalam pemecahan masalah, analogi digunakan untuk menemukan masalah serupa yang lebih sederhana, kemudian memanfaatkan metode atau hasilnya, serta untuk menduga hasil pada kasus yang lebih rumit.

1. *Adakah masalah yang memiliki struktur hubungan yang sama tetapi lebih sederhana?*
2. Selesaikan terlebih dahulu masalah analog yang lebih sederhana tersebut.
3. *Dapatkah metodenya ditiru, atau hasilnya digunakan secara langsung?*
	   * Tiru metodenya langkah demi langkah.
	   * Gunakan hasilnya secara langsung tanpa memedulikan cara memperolehnya.
4. Apabila belum dapat digunakan secara langsung, modifikasi metode atau hasil tersebut hingga sesuai.
5. Gunakan analogi untuk menduga hasil pada masalah yang lebih rumit.
6. Perkuat dugaan dengan mencari keteraturan pola pada kasus-kasus yang berurutan.
7. Jadikan dugaan yang sederhana dan harmonis sebagai petunjuk, tetapi tetap lakukan pengujian dan pembuktian sebelum digunakan.
8. Kenali tingkat presisi analogi, karena semakin presisi, semakin dapat diandalkan:
	   * Dua sistem yang hubungan antarobjeknya diatur oleh hukum yang sama.
	   * Isomorfisme: korespondensi satu-satu antarobjek yang mempertahankan hubungan tertentu.
	   * Homomorfisme: korespondensi satu-ke-banyak yang mempertahankan hubungan tertentu.

**Konteks Pemrograman:**

1. Petakan masalah ke bentuk baku yang telah dikenal, seperti graf, jalur terpendek, knapsack, atau interval, agar alat penyelesaiannya dapat langsung digunakan.
2. Bandingkan masalah dengan soal yang pernah diselesaikan, lalu tentukan bagian struktur masukan, keluaran, dan batasan yang sama serta yang berbeda. Bagian yang berbeda itulah yang perlu dimodifikasi.
3. Buat masalah analog yang lebih sederhana dengan mengecilkan batasan atau mengurangi dimensi, misalnya ukuran masukan yang kecil atau struktur satu dimensi.
4. Gunakan hasil brute force pada masukan kecil untuk menduga pola atau rumus.
5. Periksa batas berlakunya analogi. Analogi hanya berlaku sejauh hubungan intinya sama, sehingga hasil yang dipinjam perlu dibandingkan dengan brute force pada kasus kecil dan diuji pada kasus tepi dari masalah yang sebenarnya.

### 8. Specialization

Spesialisasi (*specialization*) adalah proses beralih dari pertimbangan terhadap sekelompok objek ke kelompok yang lebih kecil, atau bahkan satu objek spesifik yang terkandung di dalamnya. Spesialisasi dipakai untuk membantah pernyataan umum, menguji keyakinan, menyederhanakan masalah yang terlalu beragam, dan menjadi batu loncatan menuju solusi masalah umum.

1. *Adakah kasus khusus yang paling mudah dijangkau, yang dapat diperiksa terlebih dahulu?*
2. Ujilah pernyataan umum dengan mencari contoh penyangkal (*counter-example*). Satu objek yang tidak memenuhi pernyataan sudah cukup untuk membuktikan bahwa pernyataan umum tersebut salah.
3. Periksa kasus ekstrem atau kasus batas, karena kasus tersebut sering terlewatkan oleh pembuat generalisasi. Apabila pernyataan gagal pada kasus ekstrem, pernyataan itu terbantahkan. Apabila tetap benar, keyakinan terhadap kebenarannya semakin kuat.
4. Apabila masalah memiliki terlalu banyak variabel atau kemungkinan, ambil kasus khusus yang paling mudah dijangkau untuk memahami dinamika masalah tanpa terbebani kerumitan kondisi umum.
5. Jadikan kasus khusus sebagai masalah pembantu. Selesaikan terlebih dahulu, kemudian gabungkan dengan wawasan tambahan yang relevan untuk menjembatani penyelesaian menuju masalah umum.
6. Berikan interpretasi konkret pada konsep yang abstrak dengan mengaitkannya pada objek nyata, agar gagasannya lebih intuitif.
7. Jangan ragu melangkah mundur ke kasus yang paling sederhana apabila jalan penyelesaian umum belum terlihat.

**Konteks Pemrograman:**

8. Mulailah dari masukan terkecil yang mungkin, seperti $n = 0, 1, 2$, atau struktur kosong, untuk memahami perilaku masalah dan memastikan program menanganinya dengan benar.
9. Periksa nilai batas pada seluruh batasan soal, seperti nilai minimum, nilai maksimum, semua elemen sama, semua elemen berbeda, dan data yang sudah terurut atau terbalik.
10. Cari contoh penyangkal terhadap algoritma, khususnya algoritma greedy atau dugaan rumus, dengan membandingkannya terhadap brute force pada banyak masukan kecil yang dibangkitkan secara acak.
11. Selesaikan terlebih dahulu kasus khusus sebagai subtugas, seperti batasan kecil, struktur khusus (rantai, pohon, atau graf lengkap), atau nilai parameter tertentu, kemudian perluas ke kasus umum.
12. Telusuri contoh masukan secara manual dan buat contoh kecil sendiri untuk menguji pemahaman terhadap soal sebelum menulis kode.
13. Perhatikan kasus khusus yang sering menimbulkan galat, seperti pembagian dengan nol, luapan bilangan bulat (*overflow*), dan akses di luar batas indeks.

### 9. Generalization

Generalisasi (*generalization*) adalah proses beralih dari mempertimbangkan satu objek atau himpunan terbatas ke himpunan yang lebih luas yang mencakup objek tersebut. Generalisasi membantu menemukan hukum umum dari pengamatan kasus khusus, dan terkadang membuat masalah menjadi lebih mudah diselesaikan karena sifat esensialnya menjadi tampak.

1. *Adakah pola pada kasus khusus ini yang mungkin berlaku secara umum?*
2. Amati kasus-kasus spesifik terlebih dahulu, kemudian ajukan dugaan bahwa pola yang tampak berlaku pada himpunan yang lebih luas.
3. Pertimbangkan masalah yang lebih umum, karena masalah yang lebih umum terkadang justru lebih mudah diselesaikan (*inventor's paradox*).
4. Gunakan generalisasi untuk memilah sifat yang benar-benar relevan dari sifat yang kebetulan. Sifat esensial itulah yang menjadi kunci penyelesaian.
5. Ubah angka konkret menjadi simbol atau variabel, sehingga prosedur penyelesaian dapat diterapkan pada data yang bervariasi.
6. Manfaatkan bentuk simbolik untuk menguji hasil dengan memvariasikan data dan memverifikasinya melalui berbagai alur.
7. Perlakukan hasil generalisasi sebagai dugaan sampai diuji dan dibuktikan.

**Konteks Pemrograman:**

8. Rumuskan ulang batasan konkret sebagai parameter, misalnya mengganti nilai tetap dengan $n$, $k$, atau $m$, kemudian selesaikan untuk parameter umum tersebut.
9. Selesaikan untuk semua awalan, semua rentang, atau semua nilai parameter sekaligus apabila bentuk umum tersebut lebih mudah dimodelkan, misalnya melalui DP atau tabel hasil antara.
10. Gunakan keluaran brute force pada beberapa masukan kecil untuk menduga rumus umum, kemudian buktikan atau uji dugaan tersebut pada masukan yang lebih besar.
11. Abstraksikan solusi menjadi prosedur yang tidak bergantung pada nilai tertentu, seperti fungsi, templat, atau struktur data generik, sehingga dapat dipakai ulang pada soal lain.
12. Periksa bahwa generalisasi tidak melanggar batasan waktu dan memori. Bentuk yang lebih umum dapat menjadi lebih mahal untuk dihitung.

### 10. Variation of the Problem

Variasi dari masalah (*variation of the problem*) adalah prinsip untuk tidak terjebak pada satu pendekatan yang tidak membuahkan hasil, dengan mengubah, merestrukturisasi, dan melihat masalah dari berbagai sudut pandang. Variasi membantu menemukan bagian masalah yang paling mudah dijangkau, memicu ingatan terhadap pengetahuan yang relevan, serta menjaga minat dan fokus ketika kemajuan terhenti.

1. *Dapatkah masalah ini dinyatakan dengan cara lain, dari sudut pandang yang berbeda?*
2. Ubah bentuk atau kondisi masalah untuk menemukan aspek yang paling mudah dijangkau, karena keberhasilan bergantung pada pemilihan aspek yang tepat.
3. Manfaatkan variasi untuk memicu asosiasi ingatan. Unsur baru yang dimunculkan menciptakan titik temu dengan pengetahuan dan pengalaman lama yang relevan.
4. Ajukan pertanyaan baru tentang masalah yang sama apabila konsentrasi pada satu titik mulai membosankan atau melelahkan, agar minat dan fokus pulih serta jalan pikiran baru terbuka.
5. Variasikan data hingga mencapai bentuk ekstrem untuk memperkirakan sifat hasil akhir dan menyediakan tolok ukur untuk menguji kebenaran rumus atau jawaban.
6. *Adakah gagasan berguna dalam percobaan pertama yang gagal?* Modifikasi percobaan tersebut untuk memperoleh masalah pembantu yang lebih mudah dijangkau.
7. Gunakan operasi variasi yang telah teruji, yaitu kembali ke definisi, memisahkan dan menggabungkan kembali, menambahkan elemen pembantu, generalisasi, spesialisasi, dan analogi.
8. Terapkan variasi pada saat yang tepat. Apabila pemikiran sedang berjalan lancar, teruskan. Apabila kemajuan terhenti, variasi masalah menjadi sangat penting.
9. Ubah setiap kegagalan menjadi batu loncatan agar proses berpikir tetap dinamis dan kaya perspektif.

**Konteks Pemrograman:**

10. Ubah pernyataan soal menjadi bentuk lain yang ekuivalen, misalnya dari urutan menjadi himpunan, dari larik menjadi graf, dari penjumlahan atas pasangan menjadi penjumlahan atas elemen, atau dari proses bertahap menjadi keadaan akhir.
11. Ubah arah pandang terhadap masalah, seperti menghitung dari belakang, memproses secara luring dalam urutan tertentu, memfokuskan pada kontribusi setiap elemen, atau menukar peran antara indeks dan nilai.
12. Variasikan batasan untuk melihat perubahan pendekatan yang dibutuhkan, misalnya $n$ kecil memungkinkan pencacahan, sedangkan $n$ besar menuntut rumus atau struktur data khusus.
13. Apabila solusi yang gagal (jawaban salah, melebihi batas waktu, atau melebihi batas memori) mengandung gagasan yang benar, modifikasi bagian yang menjadi penyebab kegagalan, bukan membuang seluruhnya.
14. Apabila terhenti terlalu lama pada satu pendekatan, tinggalkan sejenak dan tinjau ulang soal dari awal dengan pertanyaan baru, atau berpindah ke soal lain terlebih dahulu apabila sedang dalam kontes.

### 11. Working Backwards

Bekerja mundur (*working backwards* atau *method of analysis*) adalah strategi pemecahan masalah yang berakar dari tradisi Yunani Kuno. Proses berpikir dimulai dari kondisi akhir yang diinginkan, lalu ditelusuri ke belakang hingga bertemu dengan data awal. Berbeda dengan bekerja maju yang mengandalkan uji coba dari data awal, metode ini menuntut kesediaan untuk sejenak menjauhi tujuan demi menemukan jalan yang benar-benar menuju solusi.

1. Anggaplah hal yang dicari sudah ditemukan (*assume what is sought as already found*).
2. *Dari kondisi atau langkah apa hasil ini dapat diperoleh?*
3. Ulangi penelusuran pada kondisi pendahulu yang ditemukan, yaitu cari pendahulu dari pendahulunya, hingga mencapai situasi yang telah diketahui atau dapat dibuat dari data awal.
4. Balikkan urutan langkah yang telah ditemukan, lalu jalankan secara maju dari data awal hingga hasil akhir.
5. Bersiaplah untuk sejenak menjauhi tujuan. Dorongan untuk langsung menuju sasaran sering kali menghalangi penemuan jalan memutar yang sebenarnya benar.
6. Hindari mencoba-coba secara maju tanpa wawasan (*muddling through*). Apabila percobaan maju berulang kali gagal, beralihlah ke penelusuran mundur dari tujuan.

**Konteks Pemrograman:**

7. Mulailah dari keadaan akhir yang diinginkan, lalu tentukan keadaan sebelumnya yang dapat mengarah ke sana. Pendekatan ini mendasari DP mundur dan memoisasi, yaitu menyatakan jawaban sebagai fungsi dari keadaan-keadaan pendahulunya.
8. Balikkan proses apabila operasi dapat dibalik, misalnya menelusuri dari hasil akhir kembali ke keadaan awal, atau memproses kueri dari belakang ke depan.
9. Telusuri mundur dari keluaran yang diminta: untuk menghasilkan keluaran ini, informasi apa yang harus sudah tersedia, dan bagaimana informasi tersebut dihitung dari masukan?
10. Rekonstruksi solusi dengan menelusuri mundur dari keadaan optimum menggunakan penunjuk pendahulu atau tabel DP, kemudian balikkan urutannya untuk memperoleh jawaban dalam urutan maju.
11. Pada masalah pencarian, pertimbangkan mencari dari titik tujuan, atau dari kedua arah sekaligus apabila ruang keadaan sangat besar.
12. Pastikan setiap langkah mundur dapat dibalik secara sah. Langkah yang tidak dapat dibalik secara unik dapat menghasilkan keadaan pendahulu yang tidak valid atau lebih dari satu kemungkinan.

### 12. Decomposing and Recombining

Pemisahan dan penggabungan kembali (*decomposing and recombining*) adalah dua operasi mental dalam pemecahan masalah: memecah masalah utuh menjadi bagian-bagian yang lebih kecil, lalu merangkainya kembali menjadi bentuk baru yang lebih mudah dijangkau. Pemisahan dilakukan setelah masalah dipahami secara keseluruhan, dan penggabungan kembali menghasilkan masalah pembantu.

1. Pahami masalah secara keseluruhan terlebih dahulu sebelum mendalami detail, agar tidak terjebak pada bagian kecil dan kehilangan gambaran utuh.
2. *Apa yang tidak diketahui? Apa datanya? Apa syaratnya?*
3. Pisahkan syarat menjadi bagian-bagian terpisah apabila diperlukan, atau kembalilah ke definisi istilah untuk memunculkan elemen baru.
4. Pada masalah untuk mencari, gabungkan kembali elemen-elemen tersebut menjadi masalah pembantu dengan mempertahankan yang tidak diketahui dan mengubah data serta syarat. Salah satu caranya adalah melepaskan sebagian syarat tanpa menambah data, sehingga himpunan kemungkinan jawaban menjadi lebih luas dan lebih mudah ditelaah.
5. *Dapatkah sesuatu yang berguna diturunkan dari data?* Pertahankan data dan ubah yang tidak diketahui, dengan mencari unsur baru yang lebih mudah diperoleh dan dapat menjadi batu loncatan menuju jawaban utama.
6. Apabila kedua cara tersebut gagal, ubah yang tidak diketahui dan data sekaligus, misalnya dengan membalik peran keduanya atau menyederhanakan masalah menjadi pencarian satu unsur kunci.
7. Pada masalah untuk membuktikan, pisahkan hipotesis dan kesimpulan. *Adakah teorema dengan kesimpulan serupa?* Pertahankan kesimpulan dan ubah hipotesis, atau lepaskan sebagian hipotesis untuk menguji apakah kesimpulan tetap berlaku.
8. Pertahankan hipotesis dan ubah kesimpulan dengan menurunkan konsekuensi baru yang berguna dari hipotesis yang ada.
9. Ubah hipotesis dan kesimpulan sekaligus agar keduanya menjadi lebih dekat dan lebih mudah dihubungkan.

**Konteks Pemrograman:**

10. Pisahkan soal menjadi masukan, keluaran, dan batasan, lalu pisahkan syarat yang majemuk menjadi syarat-syarat tunggal yang dapat ditangani satu per satu.
11. Pecah solusi menjadi modul yang independen, seperti pembacaan masukan, pemodelan, algoritma utama, dan pencetakan keluaran, kemudian rangkai kembali setelah masing-masing diuji.
12. Pecah masalah menjadi submasalah yang saling bebas atau tumpang tindih, seperti pembagian berdasarkan indeks, nilai, atau komponen graf. Gabungkan hasilnya dengan operasi yang sesuai, misalnya penjumlahan, pengambilan maksimum, atau penggabungan dua bagian (*divide and conquer*).
13. Lepaskan sebagian syarat soal untuk memperoleh versi yang lebih mudah, selesaikan versi tersebut, kemudian tambahkan kembali syarat yang dilepas satu per satu.
14. Pastikan penggabungan kembali memperhitungkan interaksi antarbagian, seperti kasus yang dihitung ganda, kasus yang terlewat, dan syarat yang melintasi batas pemisahan.

## III. Membangun Solusi

### 13. Auxiliary Elements

Elemen pembantu (*auxiliary elements*) adalah elemen baru yang ditambahkan ke dalam konsepsi masalah selama proses penyelesaian, dengan harapan dapat membantu menemukan solusi. Penambahan ini membuat pemahaman terhadap masalah menjadi lebih kaya dibandingkan kondisi awalnya. Elemen pembantu dapat berwujud garis pembantu dalam geometri, variabel tak diketahui pembantu dalam aljabar, atau teorema pembantu yang dibuktikan khusus untuk menunjang masalah utama.

1. *Adakah elemen yang dapat ditambahkan agar masalah ini menjadi lebih mudah dipahami dan diselesaikan?*
2. Tambahkan elemen pembantu untuk memanfaatkan hasil yang telah diketahui. *Apakah ada masalah serupa yang pernah diselesaikan, tetapi bentuk yang diperlukan belum tampak pada masalah ini?*
3. Kembalilah ke definisi, dan wujudkan definisi tersebut secara konkret, bukan sekadar menyebutkannya.
4. Tambahkan elemen pembantu untuk memperjelas dan memperkaya konsepsi masalah, meskipun cara penggunaannya belum diketahui secara pasti.
5. Jaga keselarasan bentuk, terutama simetri antarunsur, ketika menempatkan elemen pembantu.
6. Pastikan setiap penambahan memiliki alasan yang jelas dan tidak dilakukan secara sembarangan.
7. Setelah penambahan, periksa apakah masalah dapat disederhanakan menjadi masalah pembantu yang lebih mudah.
8. Catat alasan di balik setiap elemen yang ditambahkan, bukan hanya langkahnya.

**Konteks Pemrograman:**

1. Tambahkan variabel atau struktur data pembantu untuk menyimpan informasi yang tidak tersedia secara langsung, seperti array prefix sum, penghitung frekuensi, atau peta indeks.
2. Tambahkan fungsi pembantu atau lemma yang dibuktikan secara terpisah, seperti pernyataan invarian atau properti yang perlu dijamin.
3. Tambahkan simpul, sisi, atau keadaan pembantu pada model masalah, seperti simpul sumber dan simpul tujuan semu pada graf, elemen penjaga (*sentinel*), atau dimensi tambahan pada keadaan DP.
4. Tambahkan keluaran pembantu untuk pengamatan, seperti mencetak keadaan antara, membuat generator uji, atau menulis pemeriksa (*checker*) sederhana.
5. Pastikan setiap elemen pembantu tidak merusak kebenaran dan batasan efisiensi, baik dari segi waktu maupun memori.
### 14. Auxiliary Problem

Masalah pembantu (*auxiliary problem*) adalah masalah yang ditinjau bukan demi masalah itu sendiri, melainkan sebagai sarana untuk membantu menyelesaikan masalah utama. Kemampuan merancang masalah pembantu saat masalah utama sulit diselesaikan secara langsung merupakan bentuk kecerdasan dalam mengatasi rintangan secara tidak langsung. Masalah pembantu dapat dimanfaatkan hasilnya maupun metodenya, tetapi penelaahannya memakan waktu dan tenaga.

1. *Adakah masalah lain yang lebih mudah, yang penyelesaiannya dapat membantu menyelesaikan masalah ini?*
2. *Apa yang tidak diketahui? Dapatkah masalah divariasikan agar tidak diketahui yang baru lebih mudah dijangkau?*
3. Gunakan masalah pembantu sebagai sarana, bukan tujuan. Manfaatkan hasilnya untuk memperoleh jawaban masalah utama, atau manfaatkan metodenya pada masalah utama.
4. Pertimbangkan secara matang sebelum memilih masalah pembantu, karena upaya yang gagal berarti waktu yang terbuang. Pilihlah yang lebih mudah dijangkau, bersifat instruktif, atau memberikan pendekatan baru.
5. Tentukan apakah pengurangan bersifat ekuivalen, yaitu penyelesaian salah satu masalah otomatis menyelesaikan yang lain.
6. Pada pengurangan ekuivalen, susun rantai masalah pembantu hingga mencapai masalah yang mudah. Jika setiap langkah ekuivalen, penyelesaian masalah terakhir merupakan penyelesaian masalah awal.
7. Periksa kesetaraan pada setiap langkah perubahan kondisi. Pergeseran ke kondisi yang lebih sempit menyebabkan solusi hilang, sedangkan pergeseran ke kondisi yang lebih luas menimbulkan solusi semu.
8. Pada pengurangan searah, gunakan masalah yang kurang ambisius (misalnya kasus khusus) sebagai batu loncatan. Gabungkan hasilnya dengan pengamatan tambahan untuk menyelesaikan masalah utama.
9. Pertimbangkan masalah yang lebih ambisius. Masalah yang lebih umum terkadang justru lebih mudah diselesaikan (*inventor's paradox*).

**Konteks Pemrograman:**

10. Ubah masalah menjadi masalah pembantu yang ekuivalen dengan mengganti sudut pandang, misalnya mengubah "hitung yang memenuhi syarat" menjadi "hitung total dikurangi yang tidak memenuhi syarat", atau mengubah pencarian nilai optimum menjadi pemeriksaan "apakah nilai $X$ dapat dicapai" (pencarian biner pada jawaban).
11. Selesaikan terlebih dahulu kasus khusus atau subtugas sebagai batu loncatan, seperti subtask dengan batasan kecil, struktur khusus (rantai, pohon, atau graf lengkap), atau nilai parameter tertentu.
12. Perumum masalah bila bentuk umumnya lebih mudah dimodelkan, misalnya menyelesaikan untuk semua awalan sekaligus atau semua nilai parameter sekaligus melalui DP.
13. Perhatikan syarat pada setiap transformasi. Transformasi yang tidak ekuivalen, seperti kesalahan pada kasus tepi, pembulatan, atau syarat monotonisitas pada pencarian biner, menyebabkan jawaban salah yang tetap lolos pada contoh masukan.
14. Pertimbangkan biaya masalah pembantu terhadap sisa waktu kontes. Hentikan penelusuran apabila tidak kunjung memberikan kemajuan.

### 15. Symmetry

Simetri (*symmetry*) memiliki dua makna: makna geometris yang spesifik dan makna logis yang lebih luas. Mengenali dan menjaga simetri membantu menyederhanakan proses berpikir, menghindari kerumitan yang tidak perlu, dan memverifikasi hasil akhir.

1. Pahami dua makna simetri, yaitu geometris (seperti simetri cermin terhadap bidang atau titik) dan logis atau aljabar (seperti ekspresi yang nilainya tidak berubah ketika variabel-variabelnya dipertukarkan).
2. *Adakah bagian-bagian masalah yang berperan sama dan dapat dipertukarkan?* Identifikasi unsur-unsur tersebut dan perlakukan secara setara.
3. Tangani bagian yang simetris secara simetris pula, dan jangan merusak simetri tanpa alasan yang jelas, karena hal itu hanya memperumit penyelesaian.
4. Perlakukan unsur simetris secara tidak simetris hanya apabila ada alasan praktis yang kuat.
5. Gunakan simetri untuk menguji hasil. Periksa apakah sifat simetri semula tetap terjaga pada solusi atau rumus akhir.
6. Manfaatkan simetri untuk memangkas langkah penyelesaian dan menemukan pola solusi dengan lebih jernih.

**Konteks Pemrograman:**

7. Identifikasi unsur yang dapat dipertukarkan, seperti dua pemain dengan peran sama, dua sisi pada graf tak berarah, atau elemen yang urutannya tidak memengaruhi jawaban. Manfaatkan sifat tersebut untuk menyederhanakan model, misalnya dengan mengurutkan elemen atau menetapkan satu urutan kanonik.
8. Kurangi kasus dengan menetapkan urutan pada pasangan simetris, misalnya hanya memeriksa pasangan $(i, j)$ dengan $i < j$, atau mengasumsikan tanpa mengurangi keumuman bahwa $a \le b$.
9. Hindari penghitungan ganda yang timbul dari simetri. Apabila objek yang sama dapat dihitung dalam beberapa urutan, tetapkan representasi kanonik atau bagi hasil dengan banyaknya duplikat secara tepat.
10. Manfaatkan simetri struktur masukan, seperti palindrom, pencerminan, rotasi, atau pertukaran sumbu koordinat, untuk memperkecil ruang pencarian atau menggunakan ulang hasil perhitungan.
11. Terapkan simetri pada kode, yaitu tulis satu fungsi untuk kasus yang serupa dan panggil dengan parameter yang berbeda, alih-alih menyalin kode untuk setiap kasus.
12. Gunakan simetri sebagai uji kebenaran, misalnya memeriksa bahwa jawaban tidak berubah ketika masukan dipertukarkan, dicerminkan, atau diberi label ulang, serta bahwa matriks atau relasi yang seharusnya simetris memang simetris.
13. Periksa bahwa simetri benar-benar berlaku sebelum dimanfaatkan. Simetri yang hanya tampak pada contoh masukan dapat dipatahkan oleh batasan atau syarat tambahan dalam soal.

### 16. Inventor's Paradox

*Inventor's paradox* menyatakan bahwa rencana yang lebih ambisius sering kali memiliki peluang keberhasilan yang lebih besar. Beralih ke masalah yang lebih luas atau lebih umum dapat membuat masalah jauh lebih mudah ditangani daripada masalah aslinya, asalkan peralihan itu didasari pemahaman mendalam tentang keterkaitan yang melampaui objek di depan mata.

1. *Adakah masalah yang lebih umum atau lebih ambisius, yang justru lebih mudah diselesaikan daripada masalah ini?*
2. Pertimbangkan membuktikan pernyataan yang lebih menyeluruh, atau menjawab sekumpulan pertanyaan yang saling terkait sekaligus, karena hal ini kerap lebih mudah daripada membuktikan satu klaim tunggal yang terbatas.
3. Manfaatkan bentuk yang lebih luas untuk memilah sifat utama yang benar-benar esensial, sehingga alur penyelesaian menjadi lebih jelas dan lugas.
4. Pastikan rencana yang lebih ambisius didasari visi yang mendalam tentang keterkaitan antarobjek, bukan pretensi kosong. Paradoks ini hanya berlaku apabila generalisasinya tepat.

**Konteks Pemrograman:**

5. Selesaikan untuk semua awalan, semua rentang, atau semua nilai parameter sekaligus apabila hal itu lebih mudah dimodelkan daripada satu kueri tunggal, misalnya melalui DP yang menyimpan jawaban untuk setiap keadaan.
6. Perkuat pernyataan induksi atau invarian dengan menambahkan informasi ke dalam keadaan DP, karena pernyataan yang lebih kuat sering kali lebih mudah dibuktikan dan dihitung.
7. Jawab seluruh kueri sekaligus secara luring, misalnya dengan mengurutkannya, memakai teknik sapuan (*sweep line*), atau menghitung tabel hasil untuk semua kemungkinan, alih-alih menjawab satu per satu.
8. Perumum parameter masalah, seperti mengganti nilai konkret menjadi $k$ atau $n$, apabila bentuk umumnya menyingkapkan struktur yang tersembunyi pada kasus tertentu.
9. Ubah masalah optimasi menjadi bentuk yang lebih umum, seperti menghitung seluruh nilai yang mungkin dicapai atau memeriksa kelayakan untuk setiap nilai $X$ (misalnya pencarian biner pada jawaban), apabila bentuk tersebut lebih mudah diperiksa.
10. Periksa biaya generalisasi terhadap batasan waktu dan memori. Bentuk yang lebih umum dapat menjadi lebih mahal, sehingga manfaatnya perlu ditimbang terhadap kompleksitasnya.

## IV. Menguji dan Membuktikan

### 17. Examine Your Guess

Pemeriksaan terhadap tebakan (*examine your guess*) adalah sikap memperlakukan dugaan atau intuisi secara kritis. Menerima tebakan begitu saja sebagai kebenaran adalah keliru, tetapi mengabaikannya juga merugikan. Tebakan yang muncul setelah masalah dipahami dan dipikirkan secara mendalam biasanya memuat setidaknya sebagian kebenaran, dan tebakan yang salah pun berguna karena mengarahkan pada tebakan yang lebih baik.

1. Munculkan tebakan setelah memahami dan memikirkan masalah secara mendalam, karena tebakan semacam itu biasanya memuat sebagian kebenaran.
2. Jangan menerima tebakan tanpa pengujian. Tebakan yang tidak diuji akan mengakar kaku dan membuat bukti yang berlawanan diabaikan.
3. Jangan mengabaikan tebakan begitu saja. Tebakan yang salah tetap berguna apabila diperiksa secara kritis, karena dapat menuntun pada gagasan yang lebih baik.
4. Perlakukan tidak ada gagasan yang benar-benar buruk, kecuali apabila tidak bersikap kritis terhadapnya.
5. *Dapatkah tebakan ini dirumuskan secara tegas sebagai pernyataan yang harus dibuktikan?* Rumuskan secara berani, sehingga masalah untuk mencari berubah menjadi masalah untuk membuktikan.
6. Apabila pembuktian untuk seluruh kasus terlalu sulit, ujilah tebakan pada kasus yang lebih khusus atau bagian yang lebih lemah, sehingga kemajuan tetap diperoleh.
7. Uji tebakan awal secara sistematis dan, apabila ada petunjuk lain, ujilah tebakan susulan yang dihasilkan, karena struktur tebakan yang diperkuat mempermudah penemuan jawaban yang tepat.
8. Uji tebakan melalui unsur lain yang berhubungan dengannya, seperti kendala atau bagian yang bersilangan dengan tebakan tersebut.

**Konteks Pemrograman:**

9. Perlakukan dugaan algoritma, rumus, atau pola sebagai hipotesis yang harus diuji, bukan sebagai kebenaran, meskipun lolos pada contoh masukan.
10. Bandingkan dugaan dengan brute force pada banyak masukan kecil yang dibangkitkan secara acak, termasuk kasus tepi, sebelum menjadikannya dasar solusi.
11. Cari contoh penyangkal secara aktif, terutama untuk strategi greedy, dengan mencoba masukan yang dirancang untuk mematahkan dugaan.
12. Tuliskan dugaan secara eksplisit sebagai klaim, misalnya "jawaban selalu bernilai $x$ apabila kondisi $y$ terpenuhi", lalu coba buktikan atau patahkan, bukan sekadar mengodekan dugaan tersebut.
13. Gunakan umpan balik hasil pengiriman (jawaban salah, melebihi batas waktu) sebagai informasi tambahan untuk memperbaiki dugaan. Dugaan yang gagal sering menunjukkan bagian yang perlu diubah.
14. Batasi waktu pengujian dugaan selama kontes. Apabila dugaan terus gagal setelah beberapa percobaan, rumuskan dugaan baru dengan mengamati kasus-kasus yang gagal tersebut.
15. Periksa kembali dugaan terhadap batasan waktu dan memori sebelum mengodekannya, karena dugaan yang benar tetapi terlalu lambat tetap tidak dapat digunakan.

### 18. Induction and Mathematical Induction

Induksi (*induction*) adalah proses menemukan hukum umum dari pengamatan kasus-kasus khusus, sedangkan induksi matematika (*mathematical induction*) adalah metode pembuktian yang sepenuhnya rigor untuk menetapkan kebenaran dugaan tersebut. Keduanya sering dipakai bersamaan, tetapi landasan logikanya berbeda: induksi menghasilkan dugaan yang bersifat sementara, sedangkan induksi matematika memberikan kepastian.

1. Amati kasus-kasus khusus secara berurutan, lalu rumuskan dugaan umum dari pola yang tampak. Gunakan generalisasi, spesialisasi, dan analogi sebagai alat penemuannya.
2. Perlakukan hasil induksi sebagai dugaan yang bersifat sementara dan heuristik. Pengamatan eksperimental tidak dapat menjadi otoritas tertinggi, sehingga dugaan harus dibuktikan secara ketat.
3. *Benarkah rumus atau pernyataan ini pada kasus dasar?*
4. *Jika pernyataan ini benar untuk suatu bilangan bulat n, apakah ia juga benar untuk bilangan bulat berikutnya?*
5. Simpulkan kebenaran untuk seluruh nilai n secara berantai, dari kasus dasar ke kasus berikutnya dan seterusnya.
6. Nyatakan dugaan secara eksplisit dan presisi sebelum membuktikannya. Pernyataan yang lebih spesifik dan kuat terkadang justru lebih mudah dibuktikan daripada klaim umum yang samar (*inventor's paradox*).

**Konteks Pemrograman:**

7. Gunakan keluaran brute force pada masukan kecil sebagai bahan pengamatan, lalu rumuskan dugaan pola atau rumus dari urutan hasil tersebut.
8. Uji dugaan terhadap brute force pada banyak masukan kecil yang berbeda, termasuk kasus tepi, sebelum menjadikannya dasar solusi. Lolos pada contoh masukan belum membuktikan kebenaran.
9. Gunakan pola induksi untuk merancang algoritma: nyatakan jawaban untuk ukuran n sebagai fungsi dari jawaban untuk ukuran yang lebih kecil. Pola ini mendasari rekurens, DP, dan rekursi.
10. Buktikan kebenaran algoritma dengan induksi, misalnya pada invarian lingkaran, kebenaran rekursi, atau argumen bahwa strategi greedy tetap optimal pada setiap langkah.
11. Tentukan kasus dasar dengan benar dan lengkap, seperti masukan kosong atau satu elemen. Kasus dasar yang keliru atau terlewat menyebabkan rekursi tidak berhenti atau jawaban salah.
12. Rumuskan pernyataan induksi yang cukup kuat, misalnya dengan menambahkan informasi ke dalam keadaan DP atau invarian, karena hipotesis yang terlalu lemah tidak dapat dibuktikan.

### 19. Test by Dimension

Pengujian dengan dimensi (*test by dimension*) adalah metode cepat untuk memverifikasi atau menurunkan rumus dengan membandingkan dimensi kedua ruas persamaan. Metode ini mendeteksi kekeliruan perhitungan dan membantu mengonfirmasi kebenaran rumus dengan cara yang sederhana, tetapi tidak memberikan informasi tentang konstanta tanpa dimensi.

1. Tetapkan dimensi setiap besaran dalam persamaan, misalnya panjang berdimensi $L$, luas berdimensi $L^2$, dan volume berdimensi $L^3$.
2. Perlakukan konstanta murni, seperti $\pi$ atau bilangan rasional, sebagai besaran tanpa dimensi.
3. Jumlahkan atau kurangkan hanya suku-suku yang berdimensi sama. Dimensi hasil kali atau pangkat adalah hasil kali atau pangkat dari dimensi masing-masing faktor.
4. *Apakah dimensi kedua ruas persamaan sama?* Terapkan pemeriksaan ini pada hasil akhir maupun langkah perantara.
5. Gunakan uji dimensi untuk membedakan dua rumus yang mirip dan untuk mengingat rumus yang hampir terlupakan.
6. Gunakan uji dimensi untuk meramalkan bentuk hubungan antarbesaran dengan menyamakan pangkat setiap satuan dasar pada kedua ruas, sehingga eksponen setiap variabel dapat ditentukan tanpa penurunan yang rumit.
7. Sadari batasannya: uji dimensi tidak menentukan nilai konstanta tanpa dimensi dan tidak menjelaskan syarat keberlakuan rumus.

**Konteks Pemrograman:**

8. Periksa "dimensi" besaran dalam kode, yaitu apakah suatu nilai merupakan banyak, indeks, jarak, biaya, atau waktu. Jangan menjumlahkan atau membandingkan besaran yang jenisnya berbeda, seperti indeks dengan nilai.
9. Periksa konsistensi tipe dan rentang pada setiap ekspresi, misalnya `int` dengan `long long`, bilangan bulat dengan bilangan riil, serta hasil perkalian yang dapat melampaui rentang tipe data.
10. Gunakan analisis orde besar untuk menguji kompleksitas: perkirakan jumlah operasi dari batasan soal, misalnya $n = 2 \cdot 10^5$ dengan kompleksitas $O(n^2)$ menghasilkan sekitar $4 \cdot 10^{10}$ operasi, lalu bandingkan dengan sekitar $10^8$ operasi per detik.
11. Periksa ukuran jawaban terhadap batasan, yaitu apakah jawaban dapat melebihi rentang tipe data atau memerlukan modulo, dan apakah ukuran memori sesuai dengan batas yang diberikan.
12. Periksa setiap suku dalam relasi rekurens atau transisi DP: apakah semua suku yang dibandingkan atau dijumlahkan memiliki makna yang sama, misalnya sama-sama menyatakan biaya minimum untuk keadaan yang sejenis.
13. Periksa satuan pada soal, seperti detik dan milidetik, atau berbasis 0 dan berbasis 1, serta pastikan konversi dilakukan sebelum membandingkan nilai.

### 20. Reductio ad Absurdum and Indirect Proof

*Reductio ad absurdum* adalah cara menunjukkan bahwa suatu asumsi salah dengan menurunkan konsekuensi logisnya hingga menghasilkan sesuatu yang absurd atau mustahil. Pembuktian tidak langsung (*indirect proof*) adalah cara membuktikan suatu pernyataan dengan menunjukkan bahwa asumsi kebalikannya salah. Keduanya efektif sebagai alat penemuan ketika cara langsung buntu, tetapi sering terasa tidak nyaman sebagai cara penyampaian, sehingga hasilnya sebaiknya disusun ulang menjadi pembuktian langsung.

1. Gunakan kedua metode ini sebagai alat penemuan apabila semua cara langsung mengalami jalan buntu.
2. Andaikan bahwa kondisi yang diminta dapat dipenuhi (*reductio*), atau andaikan kebalikan dari pernyataan yang hendak dibuktikan (*indirect proof*).
3. *Konsekuensi apa yang dapat diturunkan dari asumsi ini?* Telusuri secara logis hingga muncul hal yang absurd, yaitu bertentangan dengan fakta yang diketahui.
4. Simpulkan bahwa asumsi awal salah, sehingga kondisi tersebut tidak mungkin dipenuhi (*reductio*), atau pernyataan semula benar (*indirect proof*).
5. Sadari bahwa metode ini menuntut perhatian pada asumsi yang pada akhirnya dibuang. Ketegangan batin ini wajar, dan itulah sebabnya metode ini sering terasa tidak nyaman.
6. Pisahkan dua fungsinya, yaitu sebagai alat penemuan yang berharga dan sebagai cara penyampaian yang sering melelahkan apabila disampaikan bertele-tele.
7. *Dapatkah argumen ini disusun ulang menjadi pembuktian langsung?* Setelah solusi ditemukan, tinjau kembali dan ubah menjadi argumen positif yang menghasilkan kesimpulan secara langsung, tanpa asumsi palsu.

**Konteks Pemrograman:**

8. Gunakan pengandaian untuk membuktikan kebenaran algoritma, misalnya dengan mengandaikan bahwa solusi optimal berbeda dari hasil greedy, lalu tunjukkan bahwa penukaran (*exchange argument*) tidak memperburuk solusi sehingga pengandaian itu bertentangan.
9. Gunakan pengandaian untuk menunjukkan bahwa suatu keadaan atau jawaban mustahil, sehingga cabang tersebut dapat dibuang dari pencarian atau dikeluarkan dari kasus yang perlu diperiksa.
10. Gunakan pertentangan untuk memangkas ruang pencarian pada pencarian runut balik dan *branch and bound*: apabila suatu keadaan parsial pasti menuju kontradiksi dengan syarat soal, hentikan penelusuran pada keadaan tersebut.
11. Gunakan pengandaian untuk memeriksa kelayakan jawaban, yaitu apabila jawaban $x$ dapat dicapai, tentukan syarat perlu yang harus berlaku, lalu periksa apakah syarat itu terlanggar. Kontradiksi berarti $x$ mustahil dicapai.
12. Gunakan pembuktian kebalikan (kontraposisi) apabila syarat yang tidak dipenuhi lebih mudah dikarakterisasi, misalnya menghitung kasus yang tidak memenuhi syarat, lalu mengurangkannya dari total.
13. Gunakan pengandaian untuk merancang kasus uji penyangkal, yaitu andaikan algoritma benar, cari masukan yang membuatnya bertentangan dengan jawaban brute force, lalu jadikan masukan itu uji.
14. Setelah solusi ditemukan lewat pengandaian, ubah menjadi karakterisasi langsung, misalnya syarat perlu dan cukup atau invarian yang dapat diperiksa dengan kode, agar solusi mudah diimplementasikan dan diuji.


## V. Menghadapi Kebuntuan
### 21. Subconscious Work

Kerja bawah sadar (*subconscious work*) adalah proses ketika pikiran terus mengolah masalah di luar kesadaran. Ketika usaha sadar yang intens menemui jalan buntu, istirahat sejenak sering membuat masalah kembali ke kesadaran dalam keadaan lebih jernih dan lebih dekat dengan solusi. Proses ini hanya bekerja apabila didahului pemikiran sadar yang sungguh-sungguh.

1. *Apakah pemikiran sadar masih produktif, atau sudah saatnya mengistirahatkan pikiran?* Kenali batas kemampuan refleksi sadar, karena memaksa pikiran terus-menerus tidak lagi menghasilkan.
2. Berikan pemikiran sadar yang intensif sebagai pemicu awal. Hanya masalah yang digeluti secara serius, diinginkan solusinya dengan kuat, dan dikerjakan dengan ketegangan berpikir yang tinggi yang dapat diolah oleh pikiran bawah sadar.
3. Jangan meninggalkan masalah dalam keadaan kosong. Selesaikan setidaknya satu poin kecil, atau perjelas satu aspek pertanyaan, sebelum beristirahat.
4. Beristirahatlah dengan sengaja, lalu kembali ke masalah dengan pikiran yang lebih segar.
5. Pandang ide yang muncul mendadak sebagai buah kerja keras, bukan keberuntungan. Pencerahan itu lahir dari ketekunan dan hasrat yang kuat pada tahap awal.
6. Seimbangkan kerja keras yang terfokus dengan waktu istirahat yang cukup.

**Konteks Pemrograman:**

7. Tuliskan keadaan terakhir sebelum berhenti, yaitu apa yang sudah diketahui, dugaan yang sedang diuji, dan langkah berikutnya, agar pikiran dapat melanjutkan dengan jelas setelah jeda.
8. Dalam kontes, beralihlah ke soal lain apabila terhenti terlalu lama pada satu soal, lalu kembali setelah beberapa waktu. Tetapkan batas waktu agar jeda tidak berubah menjadi penundaan tanpa kemajuan.
9. Setelah kontes atau sesi latihan, tinggalkan soal yang belum terselesaikan sejenak sebelum membaca editorial, dengan tetap memberi usaha sadar yang sungguh-sungguh terlebih dahulu.
10. Bila kode bermasalah dan penyebab galat tidak kunjung ditemukan, berhentilah sejenak, lalu telusuri ulang dari awal dengan membaca kode dan soal secara utuh.
11. Jadwalkan latihan secara teratur dengan jeda istirahat, karena tidur dan jeda membantu pikiran menyatukan pola dan teknik yang baru dipelajari.
12. Jangan menjadikan jeda sebagai alasan menghindari usaha. Jeda hanya berguna setelah pemikiran sadar yang mendalam, dan tidak menggantikannya.

<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>

# B. Mindset dan Sikap

## Determination, Hope, Success

Tekad, harapan, dan keberhasilan (*determination, hope, success*) menegaskan bahwa pemecahan masalah bukan urusan intelektual semata, karena kemauan dan emosi berperan sangat penting. Tekad naik dan turun mengikuti harapan dan keputusasaan: mudah bertahan ketika solusi terasa dekat, tetapi sulit ketika jalan keluar belum tampak. Karena itu, tekad perlu dijaga dengan bijak melalui harapan yang cukup dan keberhasilan-keberhasilan kecil.

1. Sadari bahwa pemecahan masalah membutuhkan kemauan dan emosi, bukan hanya kecerdasan. Tekad yang setengah-setengah mungkin cukup untuk masalah rutin, tetapi masalah yang serius menuntut daya tahan yang panjang melewati kerja keras dan kekecewaan.
2. Kenali bahwa tekad naik dan turun bersama harapan dan keputusasaan, dan bersiaplah untuk bertahan pada saat jalan keluar belum terlihat.
3. Sesuaikan tekad dengan prospek yang ada secara bijak, bukan bertahan secara membabi buta tanpa harapan dan tanpa keberhasilan.
4. Pertahankan setidaknya sedikit harapan untuk memulai, dan kumpulkan beberapa keberhasilan kecil untuk terus maju.
5. Jangan meremehkan keberhasilan kecil.
6. *Apabila masalah utama belum dapat dipecahkan, adakah masalah terkait yang lebih mudah untuk diselesaikan terlebih dahulu?*
7. Bangkitkan hasrat untuk memahami dan menyelesaikan masalah, karena kesalahan konyol dan kelambatan umumnya berakar pada ketiadaan hasrat tersebut.
8. Latih kemauan melalui masalah yang tidak terlalu mudah, yaitu bertahan melewati kegagalan, menghargai kemajuan kecil, bersabar menunggu datangnya gagasan utama, dan berkonsentrasi penuh ketika gagasan itu muncul.
9. Alami dan terimalah dinamika emosi dalam perjuangan mencari solusi sebagai bagian yang esensial dari belajar memecahkan masalah.

**Konteks Pemrograman:**

10. Pecah target besar menjadi target kecil yang dapat dicapai, seperti lolos satu soal, satu subtugas, atau satu kasus uji, lalu rayakan setiap kemajuan agar harapan tetap terjaga.
11. Terimalah bahwa jawaban salah, melebihi batas waktu, dan galat waktu eksekusi adalah bagian normal dari proses, dan perlakukan sebagai informasi, bukan sebagai penilaian terhadap kemampuan diri.
12. Catat kemajuan latihan secara teratur, seperti soal yang diselesaikan dan teknik yang dikuasai, agar kemajuan yang lambat tetap terlihat dan tekad tidak pudar.
13. Pilih soal pada tingkat kesulitan yang menantang tetapi masih dapat dijangkau, karena soal yang terlalu mudah tidak melatih ketekunan, sedangkan soal yang terlalu sulit mematikan harapan.
14. Dalam kontes, jaga kestabilan emosi setelah hasil buruk. Kembalilah pada soal berikutnya yang paling mungkin diselesaikan, dan jangan membiarkan satu kegagalan menjatuhkan seluruh kontes.
15. Berusahalah sungguh-sungguh pada soal yang sulit sebelum membaca editorial, lalu pelajari penyelesaiannya sampai benar-benar dipahami agar kegagalan berubah menjadi kemajuan.

## Signs of Progress

Tanda-tanda kemajuan (*signs of progress*) adalah petunjuk yang menunjukkan bahwa pendekatan yang sedang dipakai berada di jalur yang benar menuju solusi. Sebagian tanda dapat dinyatakan secara jelas, sebagian berupa perasaan dan intuisi. Semuanya bersifat heuristik, yaitu memberikan indikasi yang masuk akal tetapi tidak menjamin kepastian.

1. Perhatikan apakah data yang tadinya menganggur atau tampak berlebihan kini berhasil dilibatkan, karena solusi yang utuh pasti memanfaatkan seluruh data yang ada.
2. *Apakah rumus atau rencana yang sedang dibangun sudah memuat seluruh syarat esensial dari masalah?* Rencana yang mengakomodasi seluruh syarat menunjukkan struktur yang selaras dengan solusi sejati.
3. Perhatikan apakah muncul gagasan dari masalah serupa yang lebih sederhana dan pernah diselesaikan, karena hal ini sering menjadi petunjuk kunci menuju penyelesaian.
4. Perhatikan apakah bentuk dan strukturnya makin jernih, yaitu hal yang dicari makin dipahami, data tertata rapi, syarat terpisah dengan tepat, dan notasi atau visualisasi mudah diingat.
5. Perhatikan perasaan yang menyertai pemikiran, seperti optimisme, rasa bahwa rencana terasa seimbang dan harmonis, atau dorongan inspirasi yang mendadak. Perasaan ini berasal dari kerja bawah sadar dan lebih bersifat psikologis daripada logis.
6. Perlakukan setiap tanda sebagai petunjuk heuristik, bukan kepastian. Menganggapnya pasti menimbulkan kekecewaan, sedangkan mengabaikannya menghentikan kemajuan. Percayalah, tetapi tetap amati dengan cermat.
7. *Jika A mengimplikasikan B, dan B terbukti benar, apakah A kini menjadi lebih dapat dipercaya?* Dalam penalaran heuristik, kesimpulan yang terbukti hanya menguatkan kepercayaan, tidak membuktikan A secara pasti.
8. Gunakan tanda kemajuan untuk memusatkan energi pada pendekatan yang tepat dan menghindari jalan buntu.
9. Latih kepekaan membaca tanda kemajuan melalui pengalaman, karena pakar mampu menangkap petunjuk halus yang sering tidak disadari pemula.

**Konteks Pemrograman:**

10. Perhatikan apakah seluruh batasan dan informasi soal telah terpakai dalam solusi. Batasan yang belum terpakai, seperti nilai maksimum $n$, jaminan keunikan, atau sifat khusus masukan, sering menjadi petunjuk bahwa ada yang terlewat.
11. Perhatikan apakah solusi lolos pada contoh masukan, kasus kecil, dan perbandingan dengan brute force. Ini tanda kemajuan yang kuat, tetapi bukan bukti kebenaran.
12. Perhatikan apakah kompleksitas yang diperoleh sesuai dengan batasan soal. Kecocokan antara kompleksitas dan batasan sering menandakan bahwa pendekatan sudah mendekati yang dimaksudkan.
13. Perhatikan apakah model makin sederhana, misalnya keadaan DP makin sedikit, transisi makin jelas, atau soal terpetakan ke bentuk baku. Penyederhanaan yang alami sering menandakan arah yang benar.
14. Perhatikan apakah solusi yang diduga memiliki bentuk akhir yang pendek dan elegan, serta apakah tingkat kesulitan soal sesuai dengan solusi yang ditemukan. Solusi yang terlalu rumit untuk soal yang mudah menandakan ada pendekatan yang lebih baik.
15. Perhatikan tanda bahwa pendekatan tidak berhasil, seperti kasus yang terus bertambah, syarat tambahan yang terus muncul, atau kompleksitas yang tidak dapat ditekan. Tanda ini juga informasi, sehingga alihkan pendekatan lebih awal.
16. Gunakan hasil pengiriman dan pengujian sebagai tanda kemajuan, misalnya jumlah kasus uji yang lolos atau jenis kegagalan yang berubah, dan tetap ingat bahwa tanda tersebut hanya petunjuk.

## Pedantry and Mastery

Kekakuan (*pedantry*) adalah penerapan aturan secara harfiah dan tanpa dipertanyakan, baik pada situasi yang cocok maupun yang tidak. Penguasaan (*mastery*) adalah penerapan aturan dengan keluwesan dan pertimbangan matang, disertai pengetahuan tentang kapan aturan itu cocok. Daftar pertanyaan dan saran dalam SOP ini membantu, tetapi penggunaannya harus dipelajari melalui pengalaman, bukan dijalankan secara mekanis.

1. Jangan menerapkan aturan secara harfiah dan tanpa pertanyaan, baik pada situasi yang cocok maupun yang tidak cocok.
2. Pahami aturan yang dipakai. Pemahaman membedakan pengguna yang bijak dari pengguna yang hanya mengikuti kebiasaan.
3. Pertimbangkan kapan suatu aturan cocok, dan jangan biarkan rumusan kata dari aturan mengaburkan tujuan utama tindakan atau peluang yang ditawarkan situasi.
4. Pelajari penggunaan pertanyaan dan saran pemecahan masalah melalui pengalaman langsung, yaitu percobaan dan kesalahan, kegagalan, dan keberhasilan.
5. Dorong setiap langkah yang dicoba oleh pengamatan yang tekun dan berpikiran terbuka terhadap masalah yang dihadapi.
6. *Apakah aturan ini sungguh cocok dengan masalah yang sedang dihadapi, dan apakah aku memahami alasannya?*
7. Apabila cenderung bergantung pada aturan, pegang satu aturan ini: selalu gunakan otak sendiri terlebih dahulu (*always use your own brains first*).

**Konteks Pemrograman:**

8. Jangan menjalankan seluruh daftar pemeriksaan dalam SOP ini secara berurutan pada setiap soal. Pilih butir yang relevan dengan keadaan soal dan tahap pengerjaan saat ini.
9. Pahami dahulu soalnya secara mandiri sebelum mencari teknik atau algoritma baku. Pencocokan pola yang dilakukan tanpa berpikir dapat menyesatkan ke teknik yang salah.
10. Jangan menerapkan template, pola kode, atau trik yang dihafal tanpa memahami mengapa ia benar dan kapan syaratnya berlaku.
11. Utamakan tujuan soal, yaitu jawaban yang benar dalam batasan waktu dan memori, dibandingkan kepatuhan pada prosedur. Apabila soal mudah dapat diselesaikan langsung, kerjakan langsung.
12. Sesuaikan penggunaan SOP dengan konteks. Dalam kontes dengan waktu terbatas, pakai butir yang paling berguna saja. Dalam latihan dan evaluasi pascakontes, telaah lebih lengkap.
13. Setelah soal selesai, evaluasi mengapa suatu aturan berhasil atau gagal pada soal tersebut, agar pertimbangan makin terasah dan tidak sekadar bertambah hafalan.
14. Jangan menyalin solusi atau editorial tanpa memahaminya. Solusi yang tidak dipahami tidak melatih kemampuan menerapkan aturan secara luwes.

## Wisdom of Proverbs

Peribahasa (*wisdom of proverbs*) adalah kristalisasi pengalaman manusia selama berabad-abad dalam menghadapi tantangan hidup, dan banyak yang selaras dengan prinsip pemecahan masalah. Peribahasa bukan sistem ilmiah yang bebas kontradiksi, tetapi menggambarkan heuristik dan strategi pemecahan masalah secara kaya. Prinsipnya dapat dikelompokkan menurut fase pemecahan masalah: memahami masalah, menyusun rencana, melaksanakan rencana, dan meninjau kembali.

1. Pikirkan tujuan akhir sebelum memulai (*respice finem*), agar tidak tersesat di tengah jalan.
2. Bangkitkan kemauan dan tekad yang kuat, karena masalah sulit tidak terpecahkan tanpa kehendak (*where there is a will there is a way*).
3. Bertekunlah dalam bekerja, karena gagasan baik membutuhkan usaha yang konsisten (*an oak is not felled at one stroke*).
4. *Adakah pendekatan lain yang dapat dicoba apabila pendekatan ini tidak berhasil?* Variasikan percobaan dan sesuaikan strategi dengan keadaan, serta siapkan rencana cadangan (*have two strings to your bow*).
5. Bersedia mengubah pikiran dan strategi apabila ada alasan yang kuat, dan jangan bertahan pada rencana yang jelas tidak berhasil.
6. Manfaatkan setiap peluang, termasuk fakta atau keadaan sederhana, sebagai alat yang berguna.
7. Pertimbangkan sebelum bertindak (*look before you leap*), tetapi jangan terlalu lama ragu-ragu, karena tidak ada kemajuan tanpa keberanian untuk memulai.
8. Waspadai bias keinginan pribadi. *Apakah aku mempercayai hal ini karena buktinya, atau karena aku menginginkannya benar?*
9. Laksanakan rencana langkah demi langkah sesuai urutan yang logis, dan periksa setiap langkahnya.
10. Pikirkan kembali hasil yang diperoleh, karena pemikiran kedua sering kali lebih baik (*second thoughts are best*) dan dapat mengonfirmasi kebenaran atau memunculkan wawasan baru.
11. Gunakan verifikasi ganda, yaitu lebih dari satu pembuktian atau jalur konfirmasi, agar hasil akhir lebih kokoh (*it is safe riding at two anchors*).

**Konteks Pemrograman:**

12. Tetapkan keluaran yang diminta dan batasan soal sebelum menulis kode, agar solusi diarahkan pada tujuan yang benar.
13. Siapkan rencana cadangan dalam kontes, misalnya solusi yang lebih lambat tetapi benar untuk memperoleh sebagian poin, atau pendekatan alternatif apabila pendekatan utama gagal.
14. Waspadai bias terhadap solusi sendiri, yaitu kecenderungan meyakini kode sudah benar hanya karena lolos contoh masukan. Cari bukti yang dapat mematahkannya, seperti brute force dan kasus tepi.
15. Kerjakan secara bertahap, yaitu tulis bagian kecil, uji, lalu lanjutkan, alih-alih menulis seluruh program sekaligus dan baru mencari galat di akhir.
16. Pertimbangkan secara matang sebelum mulai mengodekan, tetapi jangan terlalu lama merenung. Apabila rencana sudah cukup jelas dan terbukti benar secara masuk akal, mulailah menulis kode.
17. Tinjau kembali solusi setelah lolos, baik dengan membaca ulang soal untuk memeriksa syarat yang terlewat, maupun dengan membandingkannya dengan solusi lain atau editorial setelah berusaha sendiri.
18. Verifikasi dengan lebih dari satu cara, misalnya brute force, perhitungan manual pada contoh, pemeriksaan invarian, dan pembangkit uji acak.

<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>
<br/>

# C. Addition
## I. Jenis Masalah

### 1. Routine Problem

Masalah rutin (*routine problem*) adalah soal yang dapat diselesaikan hanya dengan memasukkan data khusus ke dalam rumus umum, atau dengan mengikuti langkah dari contoh yang baru dipelajari, tanpa memerlukan keaslian berpikir. Latihan rutin dalam jumlah tertentu memang diperlukan, tetapi bila hanya itu yang dikerjakan, pertimbangan dan daya cipta tidak terlatih.

1. Kenali masalah rutin, yaitu masalah yang penyelesaiannya hanya menuntut penggantian data pada rumus umum atau peniruan langkah dari contoh yang baru dikerjakan.
2. *Adakah masalah terkait yang kuketahui?* Pada masalah rutin, jawaban pertanyaan ini sudah tersedia, sehingga pertanyaan tersebut kehilangan fungsi heuristiknya. Periksa apakah jawabannya datang dari pemahaman atau hanya dari kebiasaan.
3. Lakukan latihan rutin secukupnya, tetapi jangan menjadikannya satu-satunya bentuk latihan.
4. Jangan menjalankan prosedur secara mekanis. Prosedur yang kaku tidak menyisakan ruang bagi pertimbangan dan daya cipta.
5. Bedakan masalah rutin dan non-rutin berdasarkan proses mental yang dituntut, bukan berdasarkan besarnya angka atau kesulitan hitungan. Masalah non-rutin menuntut eksplorasi, analisis, dan percobaan, karena pola penyelesaiannya belum diketahui.
6. Setelah menyelesaikan masalah rutin, tinjau kembali hasilnya agar pengetahuan terkonsolidasi, yaitu dengan mencari cara lain atau kemungkinan pemakaian pada masalah yang berbeda.
7. Waspadai ilusi kemampuan. Lancar pada soal rutin belum berarti mampu menghadapi soal yang strukturnya sedikit diubah.

**Konteks Pemrograman:**

8. Kenali jenis soal sejak awal: soal rutin yang cocok dengan bentuk baku atau teknik yang sudah dikuasai, atau soal non-rutin yang menuntut gagasan baru. Alokasikan waktu dan usaha sesuai jenisnya.
9. Selesaikan soal rutin dengan cepat dan akurat, misalnya dengan menyiapkan potongan kode yang sudah teruji untuk teknik baku, agar waktu kontes tersisa untuk soal non-rutin.
10. Periksa dahulu apakah soal yang tampak rutin benar-benar rutin. Batasan atau syarat tambahan dapat membuat template yang dihafal tidak berlaku.
11. Jangan memaksakan template pada soal non-rutin. Apabila template tidak cocok, kembalilah memahami struktur soal.
12. Jangan mengukur kemampuan dari lancarnya soal rutin. Ujilah dengan soal yang strukturnya dibalik atau dimodifikasi dari soal yang sudah dikuasai.
13. Seimbangkan porsi latihan: soal rutin untuk kecepatan dan ketelitian, soal non-rutin pada batas kemampuan untuk melatih penalaran.
14. Setelah soal rutin selesai, tanyakan apakah ada cara yang lebih sederhana, dan apakah teknik yang dipakai berlaku pada soal lain yang berbeda bentuk.

### 2. Problems to Find, Problems to Prove

Masalah pencarian (*problems to find*) bertujuan menemukan suatu objek yang disebut yang tidak diketahui (*unknown*), sedangkan masalah pembuktian (*problems to prove*) bertujuan menunjukkan secara konklusif bahwa suatu pernyataan yang terdefinisi jelas itu benar atau salah. Masalah pencarian terdiri dari yang tidak diketahui, data, dan syarat. Masalah pembuktian terdiri dari hipotesis dan kesimpulan. Keduanya diperlakukan secara paralel, sehingga pertanyaan untuk satu jenis memiliki padanan pada jenis lainnya.

1. Tentukan jenis masalah terlebih dahulu: apakah yang diminta adalah menemukan suatu objek, atau menunjukkan benar tidaknya suatu pernyataan.
2. *Apa yang tidak diketahui? Apa datanya? Apa syaratnya?* Gunakan pertanyaan ini pada masalah pencarian.
3. *Apa hipotesisnya? Apa kesimpulannya?* Gunakan pertanyaan ini pada masalah pembuktian. Perlu diingat bahwa sebagian pernyataan tidak dapat dipisah secara alami menjadi hipotesis dan kesimpulan.
4. Pisahkan bagian-bagian dari syarat (pada masalah pencarian) atau bagian-bagian dari hipotesis (pada masalah pembuktian).
5. Cari hubungan antara data dan yang tidak diketahui (pada masalah pencarian), atau antara hipotesis dan kesimpulan (pada masalah pembuktian).
6. *Lihat yang tidak diketahui! Adakah masalah lama dengan yang tidak diketahui sama atau mirip?* Pada masalah pembuktian, lihat kesimpulannya dan ingat teorema lama dengan kesimpulan yang sama atau mirip.
7. Pertahankan sebagian syarat dan lepaskan sisanya, lalu ubah yang tidak diketahui atau data agar lebih dekat. Pada masalah pembuktian, pertahankan sebagian hipotesis dan cari hipotesis baru yang memudahkan penurunan kesimpulan.
8. *Apakah seluruh data dan seluruh syarat sudah digunakan?* Pada masalah pembuktian, periksa apakah seluruh hipotesis sudah digunakan.

**Konteks Pemrograman:**

9. Kenali jenis tugas dalam soal. Soal yang meminta nilai, konstruksi, atau jawaban "ya/tidak" bersifat pencarian, sedangkan menjamin kebenaran algoritma bersifat pembuktian. Dalam kontes, kebanyakan soal adalah pencarian, tetapi keyakinan terhadap solusi bergantung pada pembuktian.
10. Tuliskan soal sebagai masukan (data), keluaran (yang tidak diketahui), dan batasan (syarat), lalu pastikan ketiganya terpahami sebelum memilih algoritma.
11. Pisahkan syarat yang majemuk menjadi syarat tunggal, lalu telaah hubungan setiap syarat dengan keluaran yang diminta.
12. Cari soal lama dengan keluaran yang serupa, misalnya "hitung banyaknya", "cari nilai minimum", atau "tentukan apakah ada", karena bentuk keluaran sering menunjuk pada teknik yang sesuai.
13. Pastikan seluruh data dan batasan telah dimanfaatkan. Informasi yang tidak terpakai sering menunjukkan bahwa ada yang terlewat.
14. Rumuskan klaim kebenaran algoritma sebagai masalah pembuktian dengan hipotesis (masukan memenuhi batasan) dan kesimpulan (keluaran program benar), lalu cari alasan atau contoh penyangkal.
15. Lepaskan sebagian batasan untuk memperoleh versi yang lebih mudah, selesaikan, lalu tambahkan kembali batasan tersebut.
16. Pada soal konstruktif, periksa bahwa jawaban yang dibangun memenuhi seluruh syarat. Pembangkitan jawaban dan pemeriksa (*checker*) sederhana dapat dipakai untuk memverifikasinya.

### 3. Practical Problems

Masalah praktis (*practical problems*), seperti masalah rekayasa, tampak berbeda dari masalah matematika murni, tetapi motif dan prosedur penyelesaiannya pada dasarnya sama. Unsur-unsurnya lebih rumit, lebih luas, dan kurang terdefinisi tajam: yang tidak diketahui tidak tunggal, syaratnya banyak dan sering saling bertentangan, dan datanya nyaris tak terbatas. Masalah praktis sering memuat atau mengarah pada pembentukan masalah matematika di dalamnya.

1. Gunakan pengalaman masa lalu, sebagaimana pada masalah matematika murni. *Pernahkah aku melihat masalah yang sama dalam bentuk lain? Adakah masalah terkait yang kuketahui?*
2. Perjelas konsep yang masih kabur sejak awal, karena upaya memperjelas konsep sering menjadi bagian penting dari penyelesaian.
3. *Apakah aku telah menggunakan semua data yang benar-benar berkontribusi pada solusi, dan semua syarat yang memengaruhi solusi secara signifikan?* Pertanyaan ini menggantikan "semua data dan semua syarat" karena pada masalah praktis data hampir tak terbatas.
4. Tetapkan batasan masalah, dan bersiaplah mengabaikan detail kecil yang tidak memengaruhi hasil secara berarti.
5. Terjemahkan masalah praktis menjadi masalah matematika, lalu terapkan teori yang sesuai.
6. Terimalah pendekatan (aproksimasi) saat menerjemahkan ke bentuk matematika. Ketidakakuratan kecil rasional untuk diterima demi kemudahan dan kesederhanaan penyelesaian.
7. Bedakan pengetahuan yang presisi dari pengetahuan empiris yang belum sepenuhnya presisi, dan perlakukan hasil dengan kehati-hatian yang sesuai.

**Konteks Pemrograman:**

8. Modelkan soal atau masalah nyata menjadi model matematis yang bersih dengan memilih besaran yang penting dan membuang yang tidak relevan, misalnya mengabaikan cerita latar dan menyisakan masukan, keluaran, dan batasan.
9. Kenali informasi yang hanya berupa cerita atau pengecoh dalam pernyataan soal, tetapi pastikan tidak ada batasan penting yang ikut terbuang. Pada soal kontes, hampir setiap batasan numerik berfungsi.
10. Gunakan aproksimasi secara sadar. Pendekatan heuristik, pembatasan kedalaman pencarian, atau pemangkasan yang menerima sedikit ketidakpastian dapat dipakai bila soal mengizinkan, misalnya pada soal dengan toleransi galat atau skor parsial.
11. Pada perhitungan bilangan riil, tetapkan toleransi galat yang sesuai dan waspadai galat pembulatan yang menumpuk, alih-alih membandingkan kesamaan secara persis.
12. Dalam pemrograman nyata di luar kontes, jelaskan konsep yang masih kabur melalui spesifikasi, contoh masukan dan keluaran, serta asumsi yang ditulis secara eksplisit sebelum mengodekan.
13. Bila syarat bertentangan atau tidak lengkap, tetapkan prioritas dan asumsi secara eksplisit, lalu catat agar dapat ditinjau kembali.
14. Perlakukan keputusan penyederhanaan sebagai hipotesis yang perlu diuji. Periksa bahwa model yang disederhanakan masih menghasilkan jawaban yang benar pada contoh dan kasus tepi.
### 4. Puzzle

Teka-teki (*puzzle*), seperti permainan anagram, adalah jenis masalah yang dapat didekati dengan pertanyaan dan saran heuristik yang sama seperti masalah lain, karena daftar heuristik bersifat universal dan tidak terikat pada materi tertentu. Daftar tersebut bukan jalan pintas menuju jawaban, melainkan sarana untuk menjaga pikiran tetap bergerak ketika usaha terasa buntu.

1. *Apa yang tidak diketahui? Apa datanya? Apa syaratnya?* Terapkan pertanyaan ini pada teka-teki seperti pada masalah lain, termasuk syarat tentang jumlah unsur dan jenis kata atau bentuk yang mungkin.
2. Buatlah gambaran sebagai bantuan visual, misalnya menyiapkan ruang kosong sebanyak unsur yang dicari.
3. *Dapatkah masalah dinyatakan kembali dari sudut pandang lain?* Pisahkan dan urutkan unsur-unsurnya untuk melihat strukturnya, sehingga muncul petunjuk tambahan.
4. Selesaikan bagian yang lebih kecil terlebih dahulu. Bentuklah potongan-potongan pendek, lalu susun secara bertahap menjadi bentuk yang lebih panjang.
5. Tebak bagian yang lazim, seperti pola awal atau akhir yang umum pada bentuk yang dicari, lalu ujilah tebakan tersebut.
6. Pertahankan sebagian syarat dan abaikan sisanya, misalnya dengan memikirkan bentuk yang memiliki ciri langka dari unsur-unsur yang ada.
7. Pahami bahwa pertanyaan heuristik bukan keajaiban yang memberi jawaban instan tanpa usaha.
8. Gunakan pertanyaan heuristik untuk menjaga pikiran tetap berjalan (*keep the ball rolling*). Saat frustrasi dan ingin menyerah, pertanyaan tersebut memicu percobaan, sudut pandang, variasi, dan stimulasi baru.

**Konteks Pemrograman:**

9. Terapkan daftar pertanyaan ini pada soal apa pun, termasuk soal yang tampak seperti teka-teki, permainan, atau cerita unik. Pertanyaan tentang masukan, keluaran, dan batasan tetap berlaku.
10. Gambar atau tabelkan soal, misalnya dengan menggambar graf, grid, atau tabel keadaan, dan telusuri contoh masukan secara manual sebelum menulis kode.
11. Nyatakan ulang soal dari sudut pandang lain, seperti mengurutkan data, memisahkan jenis elemen, menghitung frekuensi, atau memilah berdasarkan paritas atau kelas sisa.
12. Selesaikan versi kecil terlebih dahulu, seperti masukan kecil atau jumlah unsur yang sedikit, lalu perluas secara bertahap ke versi penuh.
13. Pada soal pencarian kombinatorial, gunakan batasan untuk memangkas ruang kemungkinan, misalnya dengan menebak bagian yang lazim, memeriksa syarat perlu, dan membuang kandidat yang pasti gagal.
14. Gunakan pertanyaan heuristik sebagai pemicu ketika terhenti. Ajukan satu pertanyaan baru atau ubah sudut pandang, lalu coba lagi, daripada mengulang pendekatan yang sama.
15. Jangan menunggu pertanyaan heuristik memberikan jawaban. Gunakan pertanyaan itu untuk menjaga proses berpikir tetap berjalan, lalu lakukan pengujian dan pembuktian sendiri.

## II. Tentang Heuristic

### 5. Heuristic

Heuristik (*heuristic*, atau *heuretic*, atau *ars inveniendi*) adalah cabang studi yang mempelajari metode dan aturan penemuan serta penciptaan. Sebagai kata sifat, heuristik berarti "berfungsi untuk menemukan" (*serving to discover*). Studi ini berada di persilangan logika, filsafat, dan psikologi. Dalam pemecahan masalah, heuristik berarti memakai petunjuk dan prosedur yang lazimnya membantu menemukan solusi, tanpa menjamin keberhasilan.

1. Pahami bahwa heuristik berfungsi untuk menemukan, yaitu menuntun pencarian solusi, bukan menjamin kepastian jawaban.
2. *Prosedur atau petunjuk apa yang lazimnya membantu menemukan solusi pada masalah seperti ini?*
3. Pelajari metode penemuan sebagai disiplin tersendiri yang dapat dilatih, bukan sebagai bakat bawaan atau kebetulan semata.
4. Perlakukan hasil heuristik sebagai petunjuk yang masuk akal, lalu lengkapi dengan pengujian dan pembuktian.
5. Hidupkan kembali prinsip penemuan dalam bentuk yang sederhana dan dapat dipakai, bukan sebagai teori yang hanya dipelajari.

**Konteks Pemrograman:**

6. Bedakan heuristik sebagai petunjuk penemuan dari algoritma yang terbukti benar. Heuristik membantu menemukan gagasan, sedangkan kebenaran solusi tetap harus diuji atau dibuktikan.
7. Gunakan heuristik untuk mempersempit kemungkinan dan mengarahkan pencarian, seperti mengamati kasus kecil, menebak pola, memetakan ke bentuk baku, atau mencoba pendekatan yang berbeda.
8. Dalam algoritma, heuristik juga berarti pendekatan yang menerima kemungkinan hasil tidak optimal demi kecepatan, seperti pada soal dengan skor parsial atau toleransi. Pastikan soal mengizinkannya sebelum dipakai.
9. Bangun kumpulan heuristik pribadi dari soal-soal yang pernah diselesaikan, dan catat petunjuk yang berhasil maupun yang gagal.
10. Latih penemuan secara sengaja, yaitu berusaha sendiri menemukan gagasan sebelum membaca editorial, lalu pelajari bagaimana gagasan itu dapat ditemukan, bukan hanya apa solusinya.

### 6. Heuristic Reasoning

Penalaran heuristik (*heuristic reasoning*) adalah penalaran yang bersifat sementara dan masuk akal (*provisional and plausible*), bukan mutlak atau ketat, dengan tujuan utama menemukan solusi. Penalaran ini berfungsi seperti perancah (*scaffolding*) pada pembangunan gedung: penting untuk mendirikan pembuktian yang ketat, tetapi dilepas setelah bangunan berdiri kokoh. Landasannya umumnya induksi dan analogi.

1. Gunakan penalaran heuristik untuk memperoleh dugaan awal sebelum kepastian atau pembuktian yang sempurna tersedia.
2. Dasarkan penalaran pada induksi dan analogi, yaitu kumpulkan pola dan kemiripan untuk mengarahkan dugaan.
3. Perlakukan hasilnya sebagai perancah, yaitu alat sementara yang membantu membangun pembuktian ketat dan kemudian dilepas.
4. *Apakah argumen ini hanya masuk akal, atau sudah terbukti secara ketat?* Bedakan keduanya dengan jelas setiap kali menarik kesimpulan.
5. Jangan mencampuradukkan penalaran heuristik dengan pembuktian ketat, dan jangan pernah mengklaim penalaran heuristik sebagai pembuktian yang mutlak.
6. Sampaikan argumen heuristik secara terbuka, jujur, dan proporsional sebagai persiapan bagi pembuktian formal, bukan secara ambigu atau ragu-ragu.

**Konteks Pemrograman:**

7. Gunakan pengamatan pada kasus kecil, pola dari brute force, dan analogi dengan soal lama untuk menyusun dugaan algoritma atau rumus, lalu catat dugaan tersebut sebagai hipotesis.
8. Beri label yang jelas pada setiap klaim dalam catatan pengerjaan, apakah sudah dibuktikan, hanya lolos pengujian acak, atau baru berupa firasat, agar tingkat keyakinan tidak tercampur.
9. Jangan menjadikan lolos contoh masukan atau pengujian acak sebagai bukti kebenaran. Kekuatannya hanya meningkatkan keyakinan, bukan memberi kepastian.
10. Lengkapi dugaan yang menjadi dasar solusi dengan pembuktian singkat atau pengujian yang sistematis, terutama pada strategi greedy dan rumus yang diduga dari pola.
11. Sesuaikan upaya pembuktian dengan konteks. Dalam kontes, argumen heuristik yang kuat disertai pengujian brute force dapat memadai untuk mengirim solusi. Dalam latihan, usahakan pembuktian yang lengkap.
12. Lepaskan perancah setelah solusi selesai, yaitu rapikan solusi akhir menjadi argumen langsung yang dapat dibuktikan, dan buang dugaan atau percobaan yang tidak lagi diperlukan.

### 7. Modern Heuristic

Heuristik modern (*modern heuristic*) berupaya memahami seluruh alur proses pemecahan masalah, terutama operasi mental yang berguna di dalamnya. Pemecahan masalah dipandang sebagai proses kompleks dengan banyak fase: kemajuan, variasi masalah, pembedaan jenis masalah, pemilihan notasi dan gambar, penalaran yang bersifat sementara, serta faktor psikologis seperti tekad, harapan, dan kerja bawah sadar. Heuristik berlaku untuk semua jenis masalah, tetapi tidak menyediakan aturan penemuan yang pasti berhasil.

1. Pahami pemecahan masalah sebagai proses yang utuh dan berfase, lalu kenali operasi mental yang berguna pada setiap fase, bukan hanya pada langkah akhirnya.
2. Gunakan daftar pertanyaan dan saran sebagai petunjuk operasi mental. *Apa yang tidak diketahui? Buatlah gambar. Dapatkah hasil ini digunakan?*
3. Pantau kemajuan, termasuk dinamika emosi dan tanda-tanda bahwa pendekatan berada di jalur yang benar.
4. Variasikan masalah melalui pemisahan dan penggabungan kembali, definisi ulang, generalisasi, spesialisasi, dan analogi, untuk menemukan elemen atau masalah pembantu.
5. Bedakan masalah pencarian dari masalah pembuktian, dan manfaatkan notasi yang tepat serta gambar sebagai alat bantu.
6. Perlakukan penalaran heuristik sebagai penalaran yang sementara dan masuk akal, sehingga setiap dugaan harus diuji secara ketat.
7. Perhatikan faktor psikologis, yaitu tekad, harapan, keberhasilan, dan kerja bawah sadar, sebagai bagian dari proses pemecahan masalah.
8. Terapkan heuristik pada semua jenis masalah, dari masalah praktis hingga teka-teki, tanpa mengharapkan aturan penemuan yang pasti berhasil.
9. Jadikan dialog antara guru dan siswa sebagai model dialog mental internal: ajukan sendiri pertanyaan dan saran tersebut kepada diri sendiri saat berpikir.
10. Latih operasi mental yang sama pada masalah sederhana, karena kebiasaan yang terbentuk di sana dapat dipakai pada masalah yang lebih sulit.

**Konteks Pemrograman:**

11. Susun alur kerja pribadi yang utuh dari pemahaman soal, perancangan, pelaksanaan, hingga peninjauan kembali, dan ketahui butir mana dari SOP ini yang dipakai pada tiap fase.
12. Biasakan dialog internal saat mengerjakan soal, misalnya menanyakan apa masukan dan keluarannya, adakah soal serupa, dan bagaimana hasil pada kasus kecil, sebelum menulis kode.
13. Pantau kemajuan secara berkala dalam kontes, dan beralihlah pendekatan atau soal apabila tidak ada tanda kemajuan.
14. Perlakukan setiap dugaan algoritma sebagai sementara sampai diuji dengan brute force dan kasus tepi, dan buktikan bila risikonya besar.
15. Terapkan pertanyaan yang sama pada soal yang tampak asing, seperti soal berbentuk cerita, permainan, atau teka-teki, karena heuristiknya tidak bergantung pada topik.
16. Catat petunjuk dan teknik yang berhasil dari setiap soal, agar dialog internal makin kaya seiring pengalaman.

### 8. Rules of Discovery

Aturan penemuan (*rules of discovery*) yang pasti berhasil dalam menyelesaikan semua masalah tidak ada, dan harapan akan aturan semacam itu sama seperti pencarian batu filsuf oleh para alkemis, karena menuntut keajaiban. Heuristik yang masuk akal tidak menjanjikan aturan yang tak pernah gagal, melainkan mempelajari prosedur, operasi mental, dan langkah yang lazimnya berguna. Daftar pertanyaan dalam SOP ini adalah alat bantu yang nyata, terstruktur, dan dapat dipelajari untuk membimbing alur berpikir.

1. Sadari bahwa tidak ada aturan penemuan yang pasti berhasil untuk semua masalah. Menuntut aturan semacam itu sama dengan mengharapkan keajaiban.
2. Kenali bahwa penemuan tetap membutuhkan kecerdasan dan sedikit keberuntungan, serta kesediaan menunggu gagasan cemerlang datang setelah usaha sungguh-sungguh. Menunggu tanpa usaha tidak menghasilkan apa pun.
3. *Prosedur atau langkah apa yang biasanya berguna pada masalah seperti ini?* Pelajari operasi mental yang lazim bermanfaat, bukan mencari jaminan keberhasilan.
4. Ingat bahwa prosedur heuristik pada dasarnya sudah dipraktikkan secara alami oleh setiap orang yang berakal sehat dan tertarik pada masalahnya. Tugasnya adalah menyadari dan melatihnya secara sengaja.
5. Gunakan pertanyaan dan saran dalam daftar sebagai alat bantu yang dapat dipelajari, bukan sebagai rumus ajaib yang menjamin jawaban.
6. Terimalah kegagalan suatu prosedur sebagai hal wajar, lalu coba prosedur lain.

**Konteks Pemrograman:**

7. Jangan mencari teknik tunggal yang pasti menyelesaikan semua soal. Bangun kumpulan teknik dan kebiasaan berpikir yang lazimnya berguna, lalu pilih sesuai soal.
8. Terimalah bahwa sebagian soal tidak terselesaikan dalam kontes, dan perlakukan hal itu sebagai bagian normal dari proses, bukan sebagai bukti bahwa metodenya salah.
9. Jangan menganggap SOP ini menjamin solusi. Fungsinya menjaga pikiran tetap bergerak, mempersempit kemungkinan, dan mengurangi kesalahan, sedangkan penemuan solusinya tetap menuntut usaha sendiri.
10. Perkaya kemampuan melalui latihan dan penelaahan soal secara rutin, karena kecerdasan dan intuisi dalam menemukan solusi terbentuk dari pengalaman, bukan dari rumus.
11. Setelah setiap soal, catat prosedur yang ternyata berguna dan yang tidak, agar kumpulan alat bantu pribadi makin akurat dari waktu ke waktu.
12. Apabila semua prosedur telah dicoba dan tidak berhasil, tinggalkan soal sejenak atau beralih ke soal lain, lalu kembali dengan sudut pandang baru.
## III. Pelaksanaan dan Pembelajaran

### 9. Carrying Out

Melaksanakan rencana (*carrying out*) adalah tahap mengeksekusi ide penyelesaian. Berbeda dengan tahap merancang rencana yang bebas memakai penalaran heuristik dan argumen sementara, tahap ini menuntut setiap langkah diperiksa dengan teliti dan dibuktikan dengan argumen yang ketat. Perancah dilepas, dan semakin teliti pemeriksaan saat pelaksanaan, semakin bebas penalaran heuristik saat perancangan.

1. Lepaskan perancah saat melaksanakan rencana. Periksa setiap langkah dan buktikan hanya dengan argumen yang ketat dan pasti.
2. *Dapatkah aku melihat dengan jelas bahwa langkah ini benar? Dapatkah aku membuktikannya?*
3. Manfaatkan ketelitian pelaksanaan untuk membebaskan perancangan, yaitu berani menduga saat merancang karena setiap dugaan akan diperiksa ketat saat melaksanakan.
4. Kerjakan detail dalam urutan yang tepat. Pastikan langkah-langkah utama sudah solid sebelum memeriksa detail kecil.
5. Sadari bahwa urutan penemuan ide, urutan pengerjaan detail, dan urutan penyajian akhir sering berbeda, sehingga jangan memaksakan satu urutan untuk ketiganya.
6. Ujilah pembuktian yang rumit dengan gaya Euklides, yaitu bergerak searah dari data ke yang tidak diketahui (atau dari hipotesis ke kesimpulan), dengan setiap unsur baru diturunkan langsung dari langkah sebelumnya, sehingga setiap langkah dapat diperiksa tanpa melihat ke depan atau ke belakang.
7. Waspadai kelemahan gaya Euklides: kebenaran tiap langkah mudah terlihat, tetapi tujuan dan arah keseluruhan argumen sulit dipahami. Pakailah gaya ini untuk memeriksa, dan dahului dengan gambaran intuitif gagasan utama saat menyampaikan argumen.
8. Gunakan dua jalur pemahaman secara bersamaan, yaitu penglihatan intuitif dan pembuktian formal. Intuisi dapat melampaui pembuktian formal, dan sebaliknya manipulasi formal dapat melampaui intuisi.
9. *Dapatkah aku membuktikan secara formal apa yang tampak jelas secara intuitif, dan melihat secara intuitif apa yang telah terbukti secara formal?* Latih keduanya.

**Konteks Pemrograman:**

10. Setelah rencana solusi matang, beralihlah dari mode menduga ke mode memeriksa. Pada saat menulis kode, tidak ada lagi dugaan yang dibiarkan tanpa diuji.
11. Tulis kode sesuai rancangan yang sudah diputuskan, dan jangan mengubah algoritma di tengah penulisan tanpa kembali ke tahap perancangan terlebih dahulu.
12. Kerjakan dalam urutan yang tepat: kerangka utama dan alur data lebih dahulu, baru detail seperti kasus tepi, optimasi kecil, dan format keluaran.
13. Periksa setiap bagian kode secara terpisah dan terperinci, seperti gaya Euklides: untuk setiap baris atau blok, tanyakan apakah keadaan sebelumnya menjamin keadaan sesudahnya, dengan memeriksa invarian, batas indeks, dan inisialisasi.
14. Uji setiap bagian segera setelah ditulis, dengan contoh masukan dan kasus kecil, sebelum melanjutkan ke bagian berikutnya.
15. Ketika menelusuri kode secara manual, gunakan intuisi untuk menggambar atau membayangkan keadaan data, lalu cocokkan dengan hasil penelusuran formal baris demi baris. Ketidakcocokan keduanya menunjukkan letak galat.
16. Ketika menjelaskan solusi kepada orang lain atau menulis catatan pascakontes, dahulukan gagasan utama secara intuitif, lalu sajikan langkah rinci.

### 10. Progress and Achievement

Kemajuan (*progress*) dan pencapaian utama (*essential achievement*) dalam pemecahan masalah dinilai dari dua proses mental: mobilisasi, yaitu memanggil kembali pengetahuan relevan yang tersimpan dalam ingatan, dan organisasi, yaitu memadukan pengetahuan tersebut menjadi satu argumen yang selaras dengan masalah. Keduanya tidak terpisah, karena hanya fakta relevan yang dipanggil yang dapat diorganisasi. Kemajuan dapat berjalan bertahap atau melompat mendadak melalui gagasan cemerlang (*bright idea*).

1. Mobilisasikan pengetahuan yang relevan. *Pernahkah aku melihat masalah ini sebelumnya? Adakah masalah terkait atau teorema yang berguna?* Ingat pula masalah yang pernah diselesaikan, teorema yang diketahui, dan definisi baku.
2. Organisasikan pengetahuan yang telah dipanggil menjadi satu kesatuan argumen yang selaras dengan masalah. *Bisakah hasil atau metode dari masalah terkait digunakan di sini? Perlukah elemen pembantu ditambahkan?*
3. Periksa kelengkapan bahan. *Apakah seluruh data dan seluruh syarat telah digunakan, dan apakah semua konsep esensial telah diperhitungkan?*
4. Lihat masalah dari berbagai sudut pandang. Kemajuan hampir tidak mungkin tercapai tanpa variasi masalah, karena pemahaman yang makin kaya lahir dari perubahan cara pandang.
5. Nilai kemajuan dengan membandingkan pemahaman sekarang dengan pemahaman awal. Apabila pemahaman makin kaya, jalan penyelesaian makin jelas, dan bahan-bahan baru telah terkumpul, kemajuan sedang terjadi.
6. Buat prakiraan tentang langkah yang mungkin berguna, misalnya teorema yang dapat dipakai atau istilah yang perlu dikembalikan ke maknanya. Perlakukan prakiraan ini sebagai dugaan yang masuk akal, bukan kepastian.
7. *Apakah syarat dapat dipenuhi? Apakah syarat cukup untuk menentukan yang tidak diketahui, ataukah berlebihan atau saling bertentangan?* Gunakan pertanyaan ini untuk menguji prakiraan solusi.
8. Gunakan penalaran heuristik sebagai penunjuk jalan sementara, lalu lengkapi dengan pembuktian agar penyelesaian akhir pasti dan mutlak.
9. Terimalah bahwa kemajuan dapat datang bertahap atau melompat. Gagasan cemerlang adalah perubahan mendadak cara memahami masalah disertai prakiraan yang mantap mengenai langkah menuju solusi, sehingga persiapkan, pancing, laksanakan, dan manfaatkan gagasan tersebut dengan menerapkan pertanyaan-pertanyaan heuristik secara tekun.

**Konteks Pemrograman:**

10. Kumpulkan teknik, soal lama, dan pola yang relevan dengan soal ini, seperti struktur data, algoritma baku, dan trik dari soal serupa, lalu catat yang paling mungkin berguna sebelum memilih satu.
11. Padukan teknik yang dipanggil menjadi satu rancangan utuh, yaitu model, algoritma, struktur data, kompleksitas, dan penanganan kasus tepi, lalu periksa apakah semuanya saling cocok.
12. Periksa kelengkapan pemakaian informasi soal, termasuk setiap batasan, jaminan masukan, dan sifat khusus yang belum terpakai.
13. Ukur kemajuan dengan indikator yang konkret, misalnya pemahaman soal yang makin jelas, model yang makin sederhana, kompleksitas yang makin mendekati batasan, atau jumlah kasus uji yang lolos.
14. Setelah muncul gagasan mendadak, jangan langsung mengodekan. Tuliskan gagasan itu secara eksplisit, lalu uji pada contoh, brute force kecil, dan kasus tepi sebelum menjadikannya dasar solusi.
15. Apabila kemajuan terhenti, variasikan soal dengan menyatakan ulang, mengubah sudut pandang, menyederhanakan batasan, atau mengamati kasus kecil, sebagai cara memancing gagasan baru.
16. Setelah kontes atau sesi latihan, catat gagasan kunci yang membuka solusi, agar pengetahuan tersebut mudah dipanggil kembali pada soal berikutnya.

### 11. Why Proofs?

Pembuktian (*proofs*) memiliki nilai yang mendasar dalam membentuk disiplin berpikir logis, daya ingat, dan kemampuan bernalar, bukan sekadar formalitas akademik. Pembuktian lengkap memberi tolok ukur yang presisi untuk menilai argumen dan klaim, menunjukkan bahwa matematika adalah sistem logis yang saling terikat, dan membantu mengingat fakta secara lebih bertahan lama. Pembuktian tidak lengkap boleh dipakai untuk menyampaikan intuisi, selama dinyatakan secara jujur.

1. *Mengapa pernyataan ini benar, dan bukan hanya tampak benar?* Jangan mengira kebenaran suatu rumus atau teorema sudah cukup terlihat secara langsung.
2. Pelajari pembuktian lengkap sebagai standar penalaran yang ketat dan contoh kebenaran yang tidak terbantahkan, agar memiliki tolok ukur untuk menilai argumen, klaim, atau bukti yang dijumpai.
3. Pahami bahwa matematika adalah sistem logis yang saling mengikat. Pembuktian menghubungkan setiap teorema dengan aksioma dan definisi dasarnya.
4. Gunakan pembuktian sebagai alat bantu ingatan. Fakta yang berdiri sendiri sulit dihafal dan mudah terlupa, sedangkan fakta yang dihubungkan oleh pembuktian sederhana lebih mudah bertahan dalam ingatan.
5. Jangan hanya menghafal rumus atau prosedur tanpa alasan, karena hal itu membuat pengetahuan terasa terputus dan cepat terlupakan.
6. Apabila pembuktian lengkap terlalu rumit, gunakan pembuktian tidak lengkap untuk menangkap gambaran umum dan intinya (*germ of the proof*).
7. Nyatakan secara jujur bahwa suatu pembuktian tidak lengkap, dan jangan menyajikannya seolah-olah sempurna.
8. Kuasai pembuktian lengkapnya terlebih dahulu sebelum menyederhanakannya.

**Konteks Pemrograman:**

9. Buktikan kebenaran algoritma sebelum mengodekannya, terutama untuk strategi greedy, rumus dugaan, dan transformasi masalah. Lolos pada contoh masukan bukan bukti kebenaran.
10. Gunakan pembuktian untuk menemukan sifat yang dapat dimanfaatkan, seperti invarian, batas atas dan bawah, atau syarat perlu dan cukup, yang sering langsung menunjukkan algoritma yang tepat.
11. Simpan alasan di balik setiap teknik, bukan hanya templatnya, agar teknik tersebut mudah diingat dan diterapkan secara luwes pada soal yang berbeda bentuk.
12. Pada kontes, kerangka pembuktian singkat sudah memadai. Cukup tuliskan klaim, alasan intinya, dan titik yang paling rawan, lalu periksa dengan brute force pada masukan kecil.
13. Jujurlah terhadap diri sendiri tentang tingkat keyakinan. Bedakan solusi yang sudah dibuktikan, yang hanya lolos pengujian acak, dan yang hanya berupa firasat, lalu tentukan seberapa besar risiko yang dapat diterima untuk dikirimkan.
14. Setelah membaca editorial, pahami pembuktiannya, bukan hanya algoritmanya, agar gagasannya dapat digunakan kembali pada soal lain.


### 12. The Intelligent Problem-Solver

Pemecah masalah yang cerdas (*the intelligent problem-solver*) sering mengajukan pertanyaan reflektif kepada dirinya sendiri selama berpikir. Pertanyaan itu bukan sekadar rumusan kata, melainkan wujud sikap mental yang tepat untuk memicu langkah penyelesaian pada setiap fase pekerjaan. Pertanyaan hanya bermanfaat bila digunakan dengan pertimbangan sendiri dan disertai komitmen yang sungguh-sungguh pada masalahnya.

1. Ajukan pertanyaan reflektif kepada diri sendiri selama berpikir, dan temukan atau pahami cara memakainya secara alami, sebagai alat bantu untuk menghadirkan sikap mental yang sesuai dengan fase yang sedang dikerjakan.
2. Jangan puas hanya dengan memahami penjelasan atau contoh penggunaan sebuah pertanyaan. Pemahaman sejati baru tercapai ketika kamu mengalami sendiri saat pertanyaan itu memicu prosedur berpikir yang tepat dan terbukti berguna.
3. Jangan mengajukan pertanyaan secara mekanis atau tanpa alasan. Ajukan berdasarkan pengamatan cermat terhadap masalah dan penilaian mandiri tentang apakah situasi saat ini cocok untuk strategi tersebut.
4. *Apakah pertanyaan ini sungguh cocok dengan keadaan masalahku sekarang?*
5. Pahami masalah selengkap dan sejernih mungkin sebelum melangkah ke perumusan solusi.
6. Kerahkan konsentrasi dan hasrat yang sungguh-sungguh untuk menemukan jawaban, karena pemahaman saja tidak membawa hasil tanpa dorongan tersebut.
7. Curahkan dedikasi dan kepribadian secara utuh pada masalah. Apabila dorongan itu tidak ada, lebih baik tinggalkan masalah itu terlebih dahulu.
8. Pahami bahwa pemecahan masalah adalah disiplin mental yang hidup, bukan sekadar penerapan rumus atau daftar periksa.

**Konteks Pemrograman:**

9. Bacalah soal sampai benar-benar paham sebelum memikirkan algoritma, dengan memastikan masukan, keluaran, batasan, dan contoh sudah jelas, bila perlu dengan menyatakannya ulang dengan kata sendiri.
10. Biasakan dialog internal pada setiap fase pengerjaan, misalnya bertanya apa yang dicari, adakah soal serupa, bagaimana hasil pada kasus kecil, dan apakah solusi sudah diuji, lalu jadikan kebiasaan tersebut otomatis melalui latihan.
11. Setelah suatu pertanyaan atau butir SOP terbukti membantu pada sebuah soal, catat momen dan alasannya, agar pemahamanmu berasal dari pengalaman, bukan dari hafalan.
12. Pilih butir SOP sesuai keadaan soal dan sisa waktu, dan jangan menjalankan seluruh daftar secara berurutan pada setiap soal.
13. Pilih soal yang benar-benar ingin diselesaikan dan kerjakan dengan fokus penuh. Dalam kontes, apabila sebuah soal tidak lagi menggerakkan usaha sungguh-sungguh, beralihlah ke soal lain lalu kembali kemudian.
14. Libatkan diri sepenuhnya pada soal yang sedang dikerjakan, dengan menyingkirkan gangguan dan menetapkan waktu fokus yang jelas selama latihan maupun kontes.

### 13. The Intelligent Reader

Pembaca yang cerdas (*the intelligent reader*) memiliki dua kebutuhan saat mengikuti suatu alur bernalar: memastikan bahwa setiap langkah benar, dan memahami tujuan di balik langkah tersebut. Langkah yang diragukan kebenarannya akan dipertanyakan, sedangkan langkah yang tujuannya tidak terlihat membuat alur berpikir hilang dan membuat pembaca jenuh. Karena itu, memahami sebuah argumen berarti memahami kebenaran sekaligus alasan setiap langkahnya.

1. Pastikan setiap langkah dalam suatu argumen benar, dan pertanyakan langkah yang kebenarannya diragukan.
2. *Mengapa langkah ini diambil, dan apa tujuannya dalam keseluruhan argumen?* Jangan puas dengan mengetahui bahwa suatu langkah benar tanpa memahami alasannya.
3. Waspadai hilangnya alur berpikir. Apabila tujuan suatu langkah sama sekali tidak terlihat, berhentilah dan telusuri motifnya sebelum melanjutkan.
4. Telusuri bagaimana argumen itu dapat ditemukan secara wajar oleh manusia, bukan hanya bagaimana argumen itu dibuktikan. Pola penalaran yang tertangkap dapat dipakai kembali pada masalah lain.
5. Gunakan pertanyaan penjejak data. *Apakah seluruh data telah digunakan?* Pertanyaan ini memberi alasan yang wajar untuk melibatkan unsur yang sebelumnya terabaikan.
6. Libatkan diri secara aktif saat membaca, yaitu ajukan pertanyaan yang sama dan cobalah menebak langkah berikutnya sebelum melihatnya, agar langkah penyelesaian terasa mampu ditemukan sendiri.
7. Ketika menyajikan argumen kepada orang lain, ungkapkan motivasi di balik setiap langkah, bukan hanya kebenarannya, agar argumen dapat dipahami dan direplikasi secara mandiri.

**Konteks Pemrograman:**

8. Saat membaca editorial atau solusi orang lain, pastikan dua hal pada setiap langkah: apakah langkah itu benar, dan mengapa langkah itu diambil. Jangan hanya menyalin algoritmanya.
9. Jeda sebelum membaca langkah berikutnya pada editorial, lalu tebak sendiri langkah selanjutnya. Cara ini melatih kemampuan menemukan, bukan hanya mengikuti.
10. Tanyakan data atau batasan apa yang dimanfaatkan oleh sebuah langkah dalam editorial, karena batasan yang dipakai sering menunjukkan alasan di balik pendekatannya.
11. Saat membaca kode orang lain, pahami peran setiap bagian dan invarian yang dijaganya, bukan hanya apa yang dikerjakan baris demi baris.
12. Jika bagian editorial tidak dapat dipahami, tandai bagian itu, uji dengan contoh kecil, lalu kembali setelah berusaha sendiri. Jangan melanjutkan dengan anggapan sudah paham.
13. Saat menulis catatan pascakontes atau menjelaskan solusi kepada orang lain, sertakan alasan di balik setiap langkah dan cara gagasan itu ditemukan, bukan hanya hasil akhirnya.
14. Setelah memahami sebuah solusi, tutup editorial dan tulis ulang penalarannya dengan kata sendiri, termasuk motif setiap langkah, untuk menguji bahwa pemahamannya benar-benar utuh.


### 14. Rules of Style

Aturan gaya (*rules of style*) adalah dua aturan jenaka namun tajam tentang cara menyampaikan pemikiran, baik dalam pembuktian, esai, maupun penjelasan konsep yang rumit. Kejelasan adalah yang utama: isi harus didahulukan daripada bentuk, dan gagasan disampaikan satu per satu secara runtut. Aturan ini mencerminkan disiplin berpikir dalam memecahkan masalah dan menyusun argumen.

1. Milikilah sesuatu untuk disampaikan. Sebelum memikirkan bahasa, pilihan kata, atau struktur, pastikan isi pemikirannya sudah jelas, karena gaya seindah apa pun tanpa substansi hanyalah bungkus kosong.
2. *Apakah gagasan yang hendak kusampaikan sudah jelas bagiku sendiri?* Apabila belum, matangkan dahulu pemikirannya sebelum menulis atau menjelaskan.
3. Kendalikan diri ketika memiliki dua hal untuk disampaikan. Jangan menumpahkan keduanya sekaligus, karena dua gagasan yang berjalan bersamaan menimbulkan kebingungan dan beban kognitif.
4. Tuntaskan satu poin hingga jernih, baru lanjutkan ke poin berikutnya.
5. Utamakan isi di atas formalitas, dan jaga keruntutan langkah demi langkah agar setiap pemikiran dapat dipahami dengan sempurna.

**Konteks Pemrograman:**

6. Pahami solusi sepenuhnya sebelum menulis kode. Tuliskan terlebih dahulu gagasan intinya dalam beberapa kalimat atau langkah, karena kode yang ditulis tanpa gagasan yang jelas cenderung berbelit dan penuh galat.
7. Beri setiap fungsi, blok, atau variabel satu tanggung jawab. Hindari fungsi yang mengerjakan dua hal sekaligus, dan pisahkan pembacaan masukan, pemrosesan, serta pencetakan keluaran.
8. Selesaikan dan ujilah satu bagian sebelum beralih ke bagian berikutnya. Menulis dan men-debug banyak bagian sekaligus membuat sumber galat sulit dilacak.
9. Tulis kode yang jelas dan mudah dibaca, dengan nama bermakna dan struktur yang runtut, serta utamakan kejelasan di atas trik yang rumit, terutama karena kode harus dapat ditinjau ulang saat mencari galat.
10. Beri komentar singkat pada bagian yang gagasannya tidak terlihat dari kode, seperti alasan suatu pendekatan benar atau arti suatu invarian, bukan pada hal yang sudah jelas.
11. Saat menjelaskan solusi kepada orang lain, misalnya dalam diskusi tim atau catatan pascakontes, mulailah dari gagasan utama, lalu rinci satu langkah pada satu waktu.
12. Dalam kontes, jangan menangani dua kesulitan sekaligus. Tentukan satu hambatan yang sedang dikerjakan, selesaikan, lalu pindah ke hambatan berikutnya.

### 15. Rules of Teaching

Aturan mengajar (*rules of teaching*) menegaskan bahwa esensi mengajar terletak pada penguasaan substansi dan pembentukan sikap mental, bukan pada aturan formal semata. Dua aturannya menyangkut penguasaan materi dan penguasaan yang melampaui materi dasar. Bagi pemecah masalah mandiri, aturan ini dapat dibaca sebagai tuntutan untuk menguasai bahan yang dipelajari secara mendalam dan mempraktikkan sendiri sikap mental yang ingin dibentuk.

1. Kuasai materi yang hendak dipelajari atau dijelaskan secara utuh dan mendalam, karena tanpa pemahaman mendasar, proses belajar dan menjelaskan kehilangan kejelasan dan arah.
2. Kuasai lebih dari sekadar materi dasar. Pemahaman ekstra di luar bahan inti memberi kedalaman perspektif, keluwesan dalam menjawab pertanyaan, dan kepercayaan diri.
3. *Apakah aku benar-benar memahami hal ini, sehingga mampu menjelaskannya dan menjawab pertanyaan di luar contoh yang ada?*
4. Utamakan substansi di atas tata cara. Aturan formal memiliki kegunaan, tetapi tidak boleh menggantikan pemahaman yang sesungguhnya.
5. Miliki dan praktikkan sendiri sikap mental yang ingin ditanamkan dalam memecahkan masalah, sebelum menuntutnya dari orang lain.

**Konteks Pemrograman:**

6. Kuasai dasar-dasar secara mendalam, seperti struktur data, kompleksitas, matematika diskret, dan algoritma baku, termasuk alasan kerjanya, bukan hanya cara memakainya.
7. Pelajari teknik melampaui yang dibutuhkan soal saat ini, seperti variasi, batasan penerapan, dan hubungannya dengan teknik lain, agar mampu menghadapi soal yang bentuknya dimodifikasi.
8. Uji penguasaan dengan menjelaskan solusi kepada orang lain atau menuliskannya secara runtut tanpa melihat catatan. Bagian yang tidak dapat dijelaskan menunjukkan pemahaman yang belum utuh.
9. Setelah mempelajari teknik baru, terapkan sendiri pada beberapa soal tanpa bantuan, termasuk mengimplementasikannya dari awal, sebelum menganggapnya dikuasai.
10. Praktikkan sendiri kebiasaan berpikir yang dianjurkan dalam SOP ini, seperti menguji dugaan, memeriksa kasus tepi, dan meninjau kembali solusi, dan jangan hanya mengetahuinya.
11. Apabila membimbing atau berdiskusi dengan sesama peserta, tuntun dengan pertanyaan dan petunjuk secukupnya agar ia sendiri yang menemukan solusinya, bukan dengan menyerahkan jawaban.






