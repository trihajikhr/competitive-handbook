---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 06TH-GA00-0001
nama_algoritma: Greedy Algorithm
kategori_algoritma: Greedy Algorithm
kesulitan: 🥉 easy 🥈 medium 🥇 hard
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com & deepseek.com"
date_learned: 2025-04-14T23:40:00
tags:
  - greedy
  - hard-algorithm
  - concept-algorithm
---
#greedy #hard-algorithm #concept-algorithm

---
# Greedy Algorithm
**Greedy algorithms** atau Algoritma _greedy_ membangun solusi untuk suatu masalah dengan selalu membuat pilihan yang tampak terbaik pada saat itu. Algoritma _greedy_ tidak pernah menarik kembali pilihannya, tetapi langsung membangun solusi akhir. Karena alasan ini, algoritma _greedy_ biasanya sangat efisien.

Kesulitan dalam merancang algoritma _greedy_ adalah menemukan strategi _greedy_ yang selalu menghasilkan solusi optimal untuk masalah tersebut. Pilihan optimal secara lokal dalam algoritma _greedy_ juga harus optimal secara global. Sering kali sulit untuk membuktikan bahwa suatu algoritma _greedy_ benar-benar berfungsi.

Atau, dengan menggunakan bahasa bayi:

Greedy Algorithm itu kayak bayi yang pengen makan permen sebanyak-banyaknya sekarang, tanpa mikirin besok! 😋🍭  

**Contoh Bayi Greedy:**  
1. Lihat permen terdekat → Ambil yang paling besar.  
2. Lanjut ke permen berikutnya → Ambil lagi yang terbesar saat itu.  
3. Terus begitu sampai permen habis.  

Hasilnya: Dapet banyak permen sekarang, tapi belum tentu paling banyak totalnya (misal ada permen lebih enak di belakang, tapi si bayi udah kenyang duluan).  

**Contoh Nyata:**  
- Ngerampok celengan: Ambil koin terbesar dulu sampai tas penuh.  
- Milih mainan: Ambil yang paling seru dulu, nggak peduli besok ada yang lebih seru.  

Kelebihan: Cepat & gampang!  
Kekurangan: Bisa salah pilih, soalnya cuma lihat yang di depan mata.  

Greedy baby mau yang terbaik SEKARANG, nggak mikirin nanti! 😆

# Poin penting disini
Sebelum aku mulai mempelajari algoritma **greedy** dan **backtracking**, aku terlebih dahulu belajar algoritma seperti **sorting**, **subset**, dan **permutasi**. Menurutku, algoritma-algoritma tersebut relatif mudah dipahami karena implementasinya cukup jelas dan tidak banyak berubah di berbagai soal.

Namun, saat aku berhadapan dengan algoritma **greedy** dan **backtracking**, aku menyadari bahwa keduanya bukanlah algoritma dengan satu bentuk implementasi tetap. Mereka lebih merupakan **konsep** atau **pendekatan umum** dalam menyelesaikan masalah. Tidak ada satu kode implementasi tunggal yang bisa digunakan untuk semua kasus; masing-masing masalah tetap membutuhkan solusi yang disesuaikan, meskipun pendekatannya sama.

Dari situ aku menyimpulkan bahwa untuk mempelajari algoritma seperti greedy dan backtracking, **menghafal tidak akan efektif**—bahkan bisa sia-sia. Jauh lebih penting untuk benar-benar **memahami prinsip kerjanya**, dan cara terbaik untuk mencapainya adalah dengan **berlatih menyelesaikan berbagai soal** yang dapat diselesaikan dengan pendekatan tersebut.

