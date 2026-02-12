---
obsidianUIMode:
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
# Strategi Belajar

Marginal Gains, pecah hal besar menjadi hal-hal kecil, berikut adalah strategi yang akan aku buat untuk mencapai penguasaan mastery dan memaksimalkan proses pembelajaran:

## 1. Klasifikasikan Soal
Klasifikasikasi atau identifikasi, apakah soal yang diberikan harus diselesaikan dengan pendekatan apa, misal implementasi, dynamic programming, graf, atau ad-hoc. Ini berguna agar kita bisa melakukan pendekatan algoritma penyelesaian yang tepat, dan bisa membedakan masalah algoritma standar dengan masalah yang membutuhkan pengataman unik

## 2. Fase perencanaan
Otak adalah CPU, dan kertas adalah RAM. Lakukan perancangan algoritma di atas kerjatas (metnal modeling) sebelum menyentuk kode. buktikan kebenaran algoritma, dan analisis kompleksitas waktu serta ruan gsecara akurat sebelum impleementasi

## 3. Implementasi
Menerjemahkan logika kedalam kode, fokus pada kecepatan, ketepatan, akurasi, dan ketiadaan bugs. 

## 4. Uppsolving
Melakukan upsolving setelah kontes merupakan momen emas pertumbuhaan. Menyelesaikan soal selama kontes berbeda dengan  ketika diluar kontes, kenapa? ini karena selama kontes, kita mengerjakan soal dibawah tekanan, sehingga kemampuan berpikir kita didorong hingga batasnya. Biasanya kita akan berhenti mengerjakan soal-soal yang kita tahu kita tidak bisa kerjakan, setelah berpikir keras.

Jadi, upsolving adalah momen belajar dari kesalahan yang lebih baik, karena pasti kita masih sangat mengingat betapa sulitnya mengerjakan soal yang kita kesulian mengerjakanya.

> Definisi lain dari upsolving

_Upsolving_ didefinisikan sebagai proses menyelesaikan masalah yang gagal dipecahkan selama kontes berlangsung. Ini adalah salah satu indikator terkuat dari kualitas belajar seseorang. Praktisi yang hanya berfokus pada hasil kontes tanpa melakukan upsolving akan kehilangan peluang untuk belajar dari kesalahan mereka dalam kondisi tekanan tinggi.

Langkah-langkah strategis dalam melakukan upsolving yang berkualitas meliputi:

- Menganalisis kesalahan logika atau implementasi yang menyebabkan kegagalan saat kontes.
    
- Mempelajari teknik baru yang diperlukan untuk menyelesaikan soal tersebut melalui editorial atau diskusi komunitas.
    
- Mengimplementasikan ulang solusi dari awal tanpa melihat kode referensi secara langsung.

## 5. Membaca editorial

Membaca editorial (solusi resmi) adalah pedang bermata dua. Jika dilakukan terlalu dini, ia akan membunuh proses berpikir kreatif; jika dilakukan terlalu lambat, ia akan membuang waktu secara tidak efisien. Pembelajaran berkualitas menggunakan metode "halving" dalam memanfaatkan editorial:

- **Upaya Mandiri:** Mencoba memecahkan masalah tanpa bantuan selama jangka waktu yang ditentukan (misalnya 30-60 menit untuk pemula).
    
- **Umpan Balik Inkremental:** Jika buntu, praktisi hanya boleh membaca sebagian kecil dari editorial atau melihat "tags" untuk mendapatkan petunjuk arah tanpa mengetahui solusi penuh.
    
- **Iterasi Pengulangan:** Setelah mendapatkan petunjuk, waktu latihan untuk soal tersebut dikurangi menjadi setengah dari waktu awal untuk mencoba mengimplementasikannya secara mandiri.
    
- **Analisis Kode Ahli:** Setelah mendapatkan AC, sangat disarankan untuk membaca kode pengiriman dari kompetitor papan atas. Seringkali, kode mereka lebih bersih, lebih cepat, dan menggunakan trik implementasi yang tidak disebutkan dalam editorial resmi.
# Strategi Belajar
## 1. Rasio kesulitan diatas ratinng sekarang
Pembelajaran berkualitas menuntut pemilihan masalah yang berada tepat di atas tingkat kemampuan saat ini, sebuah konsep yang dikenal dalam psikologi pendidikan sebagai _Zone of Proximal Development_. Latihan yang tidak efisien sering terjadi karena praktisi mengerjakan soal yang terlalu mudah (yang hanya memperkuat apa yang sudah diketahui) atau terlalu sulit (yang menyebabkan kebuntuan tanpa pembelajaran bermakna).


| **Kategori Masalah** | **Tingkat Keberhasilan Target** | **Proporsi Latihan** | **Tujuan Strategis**                                           |
| -------------------- | ------------------------------- | -------------------- | -------------------------------------------------------------- |
| Mudah (Easy)         | $> 70\%$                        | $15\%$               | Memperkuat kecepatan implementasi dan konsistensi kode.        |
| Menengah (Medium)    | $40\% - 70\%$                   | $70\%$               | Area utama pertumbuhan; mengasah intuisi dan teknik baru.      |
| Sulit (Hard)         | $< 40\%$                        | $15\%$               | Mendorong batas pemikiran analitis dan penguasaan teknik elit. |


Jika seorang praktisi merasa kemajuannya stagnan, sangat disarankan untuk melakukan "peningkatan kesulitan sementara" (difficulty spike) selama satu hingga dua minggu, dengan mengubah komposisi menjadi 60% menengah dan 40% sulit, sebelum kembali ke rasio normal untuk memulihkan momentum.

## 2. Strategi metakognisi
Kualitas belajar pemrograman kompetitif sangat dipengaruhi oleh kemampuan metakognitif, yaitu kemampuan untuk memantau, mengarahkan, dan mengevaluasi proses berpikir sendiri. Penelitian menunjukkan bahwa individu dengan keterampilan manajemen metakognitif yang kuat memiliki performa yang jauh lebih unggul dibandingkan mereka yang hanya mengandalkan kecerdasan mentah.

### Kerangka Kerja Self-Regulated Learning (SRL)

Pembelajaran yang teregulasi secara mandiri melibatkan tiga fase siklus yang berulang:

1. **Fase Forethought (Pemikiran Awal):** Sebelum mulai mengode, praktisi yang berkualitas melakukan analisis tugas: "Apa tujuan akhir dari masalah ini?", "Sumber daya apa yang saya butuhkan?", dan "Strategi apa yang paling mungkin berhasil?".
    
2. **Fase Performance (Pelaksanaan):** Selama pemecahan masalah, praktisi terus melakukan pemantauan diri: "Apakah arah pemikiran saya saat ini masuk akal?", "Apakah saya mengerti mengapa saya menulis baris kode ini?", dan "Apakah saya terjebak dalam lubang kelinci (rabbit hole) yang tidak produktif?".
    
3. **Fase Reflection (Refleksi):** Setelah penyelesaian masalah (baik berhasil maupun gagal), dilakukan evaluasi diri: "Apa yang menyebabkan saya berhasil?", "Apa yang bisa saya lakukan secara berbeda di masa depan?", dan "Bagaimana ide dari masalah ini bisa diterapkan pada masalah lain?".

### Bahaya Pengenalan Pola Dangkal

Seringkali, praktisi pemula terjebak dalam "pattern recognition" atau pengenalan pola yang tidak didasarkan pada penalaran. Mereka mencoba mencocokkan masalah baru dengan masalah yang pernah mereka kerjakan sebelumnya tanpa memahami prinsip dasarnya. Pembelajaran berkualitas menekankan pada penalaran (_reasoning_) daripada sekadar menghafal templat algoritma. Jika sebuah masalah memiliki variasi kecil yang mematikan logika standar, praktisi yang hanya mengandalkan pengenalan pola akan gagal, sementara mereka yang melatih penalaran akan mampu mengadaptasi solusi mereka.


### Audit Metakognitif dan Dokumentasi

Seorang praktisi berkualitas menyimpan log aktivitas harian atau mingguan yang mencakup refleksi terhadap kesalahan yang dilakukan. Dokumentasi ini bukan sekadar daftar soal yang diselesaikan, melainkan catatan tentang "pelajaran yang dipetik".

|**Elemen Audit Metakognitif**|**Pertanyaan Refleksi Mandiri**|**Indikator Kualitas**|
|---|---|---|
|**Identifikasi Kesalahan**|Mengapa saya tidak bisa menyelesaikan masalah ini dalam waktu kontes?|Kemampuan menjelaskan kegagalan secara spesifik (misal: "salah dalam transisi DP").|
|**Evaluasi Strategi**|Apakah pendekatan saya sudah yang paling optimal dalam hal kompleksitas?|Kesadaran akan trade-off antara waktu implementasi dan kecepatan eksekusi.|
|**Transfer Pengetahuan**|Apakah saya bisa menyelesaikan masalah serupa jika parameternya diubah?|Generalisasi konsep ke dalam domain masalah yang lebih luas.|
|**Pemantauan Fokus**|Apakah saya benar-benar fokus 100% atau terdistraksi selama latihan?|Efisiensi penggunaan waktu latihan dan intensitas konsentrasi.|

# Tolok Ukur Kualitas Belajar yang Tercapai

Menentukan apakah proses belajar seseorang "berkualitas" memerlukan serangkaian metrik yang objektif dan multidimensional. Rating pada platform seperti Codeforces memang merupakan indikator performa, namun ia bukanlah satu-satunya tolok ukur kualitas pembelajaran. Rating sering kali fluktuatif dan dipengaruhi oleh faktor eksternal, sedangkan kualitas pembelajaran sejati bersifat permanen.

### Metrik Kuantitatif Progress

1. **Akurasi Pengiriman Pertama (First-Pass Accuracy):** Kualitas implementasi diukur dari seberapa sering solusi mendapatkan AC pada upaya pertama tanpa perlu melakukan debugging berulang kali. Ini menunjukkan kejernihan pemikiran sebelum penulisan kode.
    
2. **Penurunan Waktu Resolusi (Time-to-Solve):** Untuk tingkat kesulitan yang sama, praktisi berkualitas akan menunjukkan tren penurunan waktu yang dibutuhkan untuk mencapai solusi benar. Ini menandakan penguasaan teknis yang telah terinternalisasi menjadi intuisi.
    
3. **Indeks Diversifikasi Topik:** Kualitas belajar tercapai jika kemampuan praktisi tersebar secara merata di berbagai kategori algoritma (graf, string, matematika, DP), bukan hanya kuat di satu bidang saja. Kesenjangan performa yang besar antar topik menunjukkan adanya "blind spot" dalam kurikulum latihan.
    
4. **Rasio Upsolving:** Persentase masalah yang tidak terselesaikan selama kontes yang kemudian diselesaikan dalam waktu 48 jam setelah kontes berakhir. Target ideal untuk pembelajaran berkualitas adalah minimal 1-2 soal di atas tingkat kemampuan saat kontes.
    