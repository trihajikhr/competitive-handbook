---
obsidianUIMode: preview
note_type: book theory
judul_materi: Interactive Problem
sumber:
  - myself
date_learned: 2026-07-15T15:14:00
tags:
  - interactive-problem
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Interactive Problem

## Definisi

*Interactive Problem* adalah sebuah kategori permasalahan dalam pemrograman kompetitif di mana program tidak menerima seluruh data masukan di awal. Sebagai gantinya, program harus berinteraksi secara aktif dengan sistem penguji (*interactor*) melalui sebuah kanal komunikasi dua arah.

Dalam model ini, alur eksekusi bersifat dinamis dan bergantung pada respon dari sistem:

1. Program mengirimkan *query* (pertanyaan) ke standard output.
2. Program menerima respon dari *interactor* melalui standard input.
3. Berdasarkan respon tersebut, program menentukan langkah berikutnya hingga mencapai solusi akhir.

## Perbandingan Paradigma

| Fitur          | Soal Standar                  | Interactive Problem                          |
| -------------- | ----------------------------- | -------------------------------------------- |
| Input          | Diberikan secara utuh di awal | Diberikan secara bertahap (per-query)        |
| Alur           | Linear (baca, proses, cetak)  | Iteratif (tanya, respon, tanya, respon, ...) |
| Ketergantungan | Input statis                  | Input dinamis berdasarkan output             |

## Tujuan Pembelajaran

Permasalahan ini dirancang untuk menguji kemampuan adaptasi logika dan strategi pengumpulan informasi. Berbeda dengan soal standar yang menuntut pemahaman struktur data statis atau rumus matematika, permasalahan interaktif menuntut efisiensi dalam pencarian data tersembunyi dengan batasan jumlah query tertentu.