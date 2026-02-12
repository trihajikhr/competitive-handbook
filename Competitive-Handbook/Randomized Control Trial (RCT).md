---
obsidianUIMode: preview
note_type: book theory
judul_materi: Randomized Control Trial (RCT)
sumber:
  - myself
date_learned: 2026-02-07T17:50:00
tags:
  - meta-learning
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Randomized Control Trial (RCT)

Dokumen ini memuat rangkaian eksperimen yang dilakukan untuk mengidentifikasi metode belajar yang paling efektif dalam mencapai performa puncak. Setiap eksperimen dirancang untuk membandingkan beberapa pendekatan belajar, dengan tujuan mempertahankan metode yang terbukti efektif dan mengeliminasi metode yang tidak memberikan dampak signifikan. Seluruh proses evaluasi dilakukan secara sistematis menggunakan pendekatan Randomized Controlled Trial (RCT).

## 1. Upsolving > latihan biasa

**Hipotesis:**
Menyelesaikan soal-soal di kontes, dan melakukan upsolving setelahnya lebih penting dan mendorong pertumbuhan daripada menyelesaikan problem biasa. Ini karena tekanann yang diberikan saat kontes, membuat kita berpikir hingga mencapai batasnya, sehingga membaca editorial setelahnya lebih efektif dan masuk ke otak (efek dari frustasi tidak bisa menyelesaikanya di kontes), sehingga pembelejaran menjadi lebih cepat. Sering upsolving baik kontes atau virtual kontes juga akan memberikan timbal balik yang lebih sering, dan lebih efektif karena menerapkan batasan waktu yang lebih nyata!

**Model:**
A: Menyelesaikan soal lewat problemset -> editorial
B: Menyelesaikan soal lewat contes atau virtual kontes -> upsolving editorial

**Metode pengujian:**
- Melakukan virtual contest, dan mencatat waktu yang dibutuhkan selama kontes tersebut. Misal menggunakan virtual kontest atau contest berdurasi 3 atau 4 jam. Maka waktu tersebut diambil dan dijadikan acuan.
- Lalu, setelah melakukan contest, lakukan upsolving pada problem, dan catat rating problem mereka.
- Sesi kedua adalah mengerjakann problem dengan rentang rating yang sama, dalam rentang waktu yang sama pula, misal kontes adalah rating 800 - 900 - 1000 - 1100, maka aku akan mengerjakan problem random dengan kesulitan yang sama pula.
- Parameter yang digunakan (metrik) adalah solver rate tanpa editorial.
- Akan dilakukan randomisasi metode sebanyak 10 kali untuk setiap metode, dengan randomisasi sebagai berikut:
  
	Sesi  1 : B
	Sesi  2 : A
	Sesi  3 : A
	Sesi  4 : B
	Sesi  5 : B
	Sesi  6 : A
	Sesi  7 : B
	Sesi  8 : A
	Sesi  9 : A
	Sesi 10 : B
	Sesi 11 : A
	Sesi 12 : B
	Sesi 13 : B
	Sesi 14 : A
	Sesi 15 : B
	Sesi 16 : A
	Sesi 17 : A
	Sesi 18 : B
	Sesi 19 : B
	Sesi 20 : A

- Menggunakan format perhitungan sebagai berikut:
```
Sesi ke-7
Metode: B
Durasi: 3 jam
Attempted: X
Solved tanpa editorial: Y
Solve rate: Y / X
Catatan singkat (opsional)
```

### Metode A
### Metode B
### Kesimpulan