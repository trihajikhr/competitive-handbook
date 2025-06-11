---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Pengenalan Bahasa C++ untuk Pemula
sumber: petanikode.com
date_learned: 2025-06-11T13:22:00
tags:
  - basic
---
Link Sumber: [Pengenalan Bahasa C++ untuk Pemula](https://www.petanikode.com/cpp-untuk-pemula/)

---
# Pengenalan Bahasa C++ untuk Pemula

![[1 - Pengenalan Bahasa C++ untuk Pemula-1.png]]

Jadi kamu memutuskan akan belajar C++. Entah karena terpaksa belajar atau sangat terterik dengan C++.

Biasanya sih karena tuntutan dari kampus hehe.. 😄

Tapi tenang saja, belajar C++ itu tidak rugi kok.

Bahkan–menurut saya–belajar C++ itu menguntungkan. Karena dengan C++ kita bisa membuat berbagai macam program.

Seperti membuat Game, Aplikasi Desktop, Web, aplikasi jaringan, aplikasi untuk hacking, bahkan juga Mobile.

Pada artikel ini, kita akan berkenalan dengan bahasa C++.

Mulai dari mempelajari Sejarah dan asal-usulnya, hingga nanti membuat persiapan awal untuk belajar C++.

Mari kita mulai…

## Apa itu C++?

C++ adalah bahasa pemrograman yang dibuat oleh [Bjarne Stroustrup](https://en.wikipedia.org/wiki/Bjarne_Stroustrup)

![[1 - Pengenalan Bahasa C++ untuk Pemula-2.png]]

Seperti namanya, Simbol “`++`” pada huruf C berarti _increment_ dari C.

Sebenarnya C++ sama seperti bahasa C, tapi memiliki fitur yang lebih banyak dibandingkan C.

Karena itulah dinamakan C++ (dibaca _si plus plus_).

Lalu apa bedanya dengan C#?

[Bahasa C#](https://www.petanikode.com/topik/csharp/) dibuat oleh Microsoft dan berjalan di atas mesin virtual .Net. Sedangkan C++ berjalan secara _native_ seperti C.

Dari segi sintaks, C++ dengan C# cukup berbeda. Menurut saya, C++ lebih mirip C dan C# lebih mirip [Java](https://www.petanikode.com/tutorial/java/).

Ada juga yang beranggapan kalau C# adalah peningkatan dari C++.

![[1 - Pengenalan Bahasa C++ untuk Pemula-4.png]]

Itu bisa saja benar, karena ekosistem C#–menurut saya–lebih baik dibandingkan C++.

Tapi tenang saja, tidak ada bahasa yang paling baik dan buruk kok. Semua bahasa punya kelebihan dan kekurangan masing-masing.

C# memang bagus, tapi C++ lebih cepat karena berjalan secara _native_.

Bahasa C++ sendiri banyak terinspirasi dari [bahasa Simula](https://en.wikipedia.org/wiki/Simula).

Mengapa bisa begitu?

Mari kita lihat sejarahnya…

## Sejarah C++

**Pada tahun 1979**, seorang ilmuan komputer asal Denmark bernama Bjarne Stroustrup mulai membuat bahasa pemrograman C++.

Motivasi awalnya sih, karena pengalaman beliau saat tesis dulu.

Waktu itu, saat mengerjakan tesis..

Beliau memiliki temuan.. kalau fitur bahasa Simula sangat membantu untuk membuat aplikasi dalam sekala besar.

Tapi bahasa Simula sangat lambat.

Cerita berikutnya dimulai saat ia bekerja di AT&T Bell Labs.

![[1 - Pengenalan Bahasa C++ untuk Pemula-5.png]]

Ia mendapatkan masalah saat menganalisis kernel Unix yang berhubungan dengan komputasi terdistirbusi.

Sejak saat itu, ia mengingat kembali pengalaman waktu mengerjakan tesis.

Akhirnya ia membuat bahasa baru dengan mengembangkan bahasa C dan memiliki fitur seperti Simula.

Selain Simula, bahasa C juga terinspirasi dari bahasa ALGOL 86, Ada, CLU, dan ML.

**Pada Tahun 1982**, bahasa baru ciptaan Bjarne ini diberi nama C++ dan juga ditambahkan beberapa fitur seperti _class_, _virtual function_, _operator overloading_, _references_, _constants_, dll.

**Pada tahun 1985**, Buku _The C++ Programming Language_ diterbitkan dan menjadi satu-satunya referensi bahasa C++ saat itu.

![[1 - Pengenalan Bahasa C++ untuk Pemula-6.png]]

**Pada tahun 1989**, C++ versi 2.0 dirilis dan diikuti rilis buku _The C++ Programming Language Second Edition_. Beberapa fitur juga ditambahkan pada versi ini, seperti _abstract_ dan _protected member_.

**Pada tahun 1998**, C++ memiliki standar bahasa yang dinamakan C++98.

## Versi Bahasa C++

Versi bahasa C++ akan mengikuti standarisasi yang digunakan. Contoh, untuk C++98 artinya versi bahasa C++ yang menggunakan standarisasi tahun 98.

Standarisasi bahasa C++ dilakukan oleh ISO _(International Organization for Standardization)_.

Mengapa sih harus ada standarisasi?

Ini agar bahasa C++ tidak diimplementasikan seenaknya. Soalnya banyak yang membuat _compiler_ bahasa C++.

Tujuan dari standarisasi ini agar semua _compiler_ tersebut sama.

Bayangkan aja.. ada _compiler_ C++ buatan IBM lalu ada juga buatan komunitas GNU.

Kalau implementasi mereka berbeda, kita bisa repot nantinya.

Harus belajar bahasa C++ versinya IBM dan versinya GNU.

Karena itulah, standarisasi diperlukan.

Saat ini C++ sudah memiliki beberapa standar:

|Versi Resmi|Tahun Rilis|Penyebutan Umum|
|---|---|---|
|C++98|1998|C++ 98|
|C++03|2003|C++ 03|
|C++11|2011|C++ 11 (C++0x final)|
|C++14|2014|C++ 14 (minor update)|
|C++17|2017|C++ 17|
|C++20|2020|C++ 20 (fitur besar)|
|C++23|2023|C++ 23 (modernisasi)|
|C++26|2026 (rencana)|C++ 26 (belum final)|

---

### 💡 Keterangan Tambahan

- **C++98**: Standar pertama C++.
    
- **C++03**: Perbaikan minor dari C++98.
    
- **C++11**: Revolusi besar (lambda, auto, nullptr, dll).
    
- **C++14**: Penyempurnaan C++11.
    
- **C++17**: Penambahan fitur seperti `if constexpr`, `std::optional`, dll.
    
- **C++20**: Fitur besar seperti konsep, ranges, coroutines.
    
- **C++23**: Melanjutkan penyempurnaan dan ekspansi pustaka standar.
    
- **C++26**: Belum dirilis (masih dalam perencanaan).
    

---
Setiap ada fitur baru, maka pada versi tersebut akan dibuat standarisasinya.

Terus, kita akan pakai versi yang mana?

Jika kita baru belajar, sebenarnya kita tidak perlu pusing memikirkan ini.

Karena di setiap versi, basic-nya akan sama saja.

Yang berbeda adalah fitur-fiturnya. Ada fungsi yang ditambahkan dan ada juga yang dihapus.

Untuk dasar seperti variabel, if, loop, fungsi dan lain-lain.. di semua versi akan sama.

## Contoh aplikasi yang dibuat dengan C++

Ada banyak sekali aplikasi yang dibuat dengan C++, saya akan sebutkan beberapa yang saya tahu saja ya..

Pertama ada [**Inkscape**](https://inkscape.org/), inkscape adalah aplikasi untuk desain vektor seperti CorelDraw dan Adobe Illustrator. Inkscape dibuat dengan C++ dan [GTK+ 3](https://www.petanikode.com/topik/gtk/).

![[1 - Pengenalan Bahasa C++ untuk Pemula-7.png]]

Kedua ada [**Krita**](https://krita.org/), aplikasi ini merupakan aplikasi untuk menggambar dan melukis. Krita dibuat dengan C++ dan [Qt 5](https://www.petanikode.com/topik/qt/).

![[1 - Pengenalan Bahasa C++ untuk Pemula-8.png]]

Selain kedua aplikasi keren di atas, masih banyak lagi aplikasi yang dibuat dengan C++:

- Winamp Media Player;
- [MySQL Server](https://www.petanikode.com/topik/mysql/);
- Mozilla Firefox;
- Thunderbird;
- Google Chrome;
- Microsoft Office;
- Adobe PhotoShop;
- Adobe Illustrator;
- [Java Virtual Machine (JVM)](https://www.petanikode.com/tutorial/java/);
- Desktop Environment: KDE;
- Desktop Environment: Apple MacOS UI (Aqua);
- dan masih banyak lagi..

Keren ‘kan C++ 😍

## Apa Selanjutnya?

Kita sudah mengenal bahasa C++ serta mengetahui sejarah dan asal-usulnya.

Intinya, bahasa C++ adalah bahasa peningkatan dari bahasa C dan bisa dipakai untuk membuat berbagai macam program atau aplikasi.

Berikutnya kita akan mulai belajar memprogram C++.