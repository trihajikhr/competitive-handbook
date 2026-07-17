---
obsidianUIMode: preview
note_type: book theory
judul_materi: Ciri-ciri Interactive Problem
sumber:
  - myself
date_learned: 2026-07-15T15:24:00
tags:
  - interactive-problem
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Ciri-ciri Interactive Problem

Permasalahan interaktif memiliki karakteristik unik yang membedakannya dari permasalahan pemrograman standar. Pengenalan terhadap karakteristik ini penting untuk menentukan strategi penyelesaian yang tepat.

## Ciri-ciri Utama

### 1. Komunikasi Dua Arah

Terdapat mekanisme pertukaran data yang berkelanjutan. Program tidak hanya berperan sebagai pengolah data pasif, tetapi juga sebagai pengambil keputusan yang menentukan pertanyaan apa yang perlu diajukan berikutnya berdasarkan respon yang telah diterima.
### 2. Batasan Query (Query Constraints)

Setiap permasalahan interaktif memiliki batas maksimal jumlah pertanyaan yang diizinkan. Hal ini mengharuskan penggunaan algoritma yang efisien. Jika batas jumlah pertanyaan terlampaui, sistem akan memberikan hasil "Wrong Answer" atau "Query Limit Exceeded".

### 3. Ketergantungan Data (Dynamic Input)

Masukan bersifat dinamis dan tidak tersedia sebelum pertanyaan diajukan. Status sistem penguji akan berubah sesuai dengan interaksi yang dilakukan. Program tidak dapat memproses seluruh data masukan di awal karena data tersebut bergantung pada logika pencarian yang dijalankan.

### 4. Kebutuhan Flush pada Standard Output

Dalam pemrograman standar, buffer pada standard output biasanya tidak menjadi kendala. Namun, pada permasalahan interaktif, output harus segera dikirimkan (*flush*) agar sistem penguji dapat segera memberikan respon. Tanpa *flush*, terjadi kondisi di mana program menunggu respon (input) sementara sistem penguji menunggu pertanyaan (output), sehingga menyebabkan deadlock (TLE).

### 5. Format Output yang Ketat

Sistem interaktif sangat sensitif terhadap format. Format query, penggunaan spasi, dan karakter baris baru harus sesuai dengan spesifikasi yang diberikan. Kesalahan format sekecil apapun akan mengakibatkan kegagalan interaksi.
