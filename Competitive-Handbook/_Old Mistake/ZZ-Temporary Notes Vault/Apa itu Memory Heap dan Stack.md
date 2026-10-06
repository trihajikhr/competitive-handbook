---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Apa itu Memory Heap dan Stack
sumber: sko.dev
date_learned: 2025-06-28T14:54:00
tags:
  - memory
---
Link Sumber: [Apa itu memori Heap dan Stack - Blog Koding](https://sko.dev/heap-dan-stack)

---
# Apa itu Memory Heap dan Stack
Saat sedang belajar bahasa program Rust, saya bertemu dengan materi Ownership. Materi ini membahas fitur Rust seputar alokasi memori. Karena tidak mau terima begitu saja, saya mundur sedikit _masalah apa sih yang ownership selesaikan?_.. ternyata seputar memori heap dan stack.

**Tidak tahu apa itu memori heap dan stack?**  
saya juga!

Dapatlah bahan belajar baru yang akan saya tuangkan di sini. Tulisan tentang memori heap dan stack

## Kenapa saya tidak pernah mendengarnya?

“Tidak pernah mendengar” mungkin sedikit berlebihan, lebih tepatnya jarang. Alasannya karena selama ini urusan memori saat menjalankan suatu program hanya ada saat berkutat dengan “low level language”.

Semua ada untung-ruginya. Saat ingin menggunakan [bahasa program](https://sko.dev/bahasa-program) yang terkenal dengan kecepatan layaknya “Rust” pasti ada hal seperti ini yang tidak kita temui sebelumnya. Karena itulah perlu sedikit memahami konsep ini, agar tidak asal memakai bahasanya nanti.

## Apa itu heap dan stack?

Ini adalah cara bahasa program menyimpan suatu data di memory. Bukan [database](https://sko.dev/wiki/database), tapi data-data dari program yang kita tulis itu sendiri.

Cara penyimpannya di memori ada dua jenis: Stack dan Heap

## Apa itu penyimpanan Stack pada komputer?

Stack menyimpan data berdasarkan urutan masuknya. Bayangkan piring yang ditumpuk. Pasti cara menumpuknya harus ke atas (bukan menyelipkan ke bawah).

Cara mengambilnya sebaliknya, kita kenal dengan LIFO (last in first out) alias yang terakhir masuk, akan pertama keluar. Ingat tumpukan piring, cara ambilnya harus dari atas.

**Ciri-ciri stack:**

- Data yang disimpan ukurannya sudah ketahuan
- Ukuran data tidak boleh berubah
- Biasanya berjalan otomatis
- Menyimpan dan mengambil data lebih cepat (karena sudah jelas prosedurnya ditumpuk seperti piring)

## Apa itu penyimpanan Heap pada komputer?

Sementara heap, bayangkan kamu masuk ke restoran. Pelayannya akan bertanya “berapa orang Pa?“. Tempat duduk kamu akan disesuaikan dengan jumlah kursi dan orangnya.

Menyimpan data di heap sering diikat dengan kata ‘allocating’. Karena kita harus secara khusus mencarikan tempat untuk data tersebut. Setiap meja di restoran ada nomor atau kodenya. Nomor ini kita sebut sebagai address/pointer yang mewakili meja tersebut.

**Ciri-ciri Heap:**

- Data bisa tidak diketahui ukurannya
- Ukuran data bisa berubah
- Biasanya perlu dikerjakan sendiri oleh programmernya
- Menyimpan dan mengambil data butuh kerja extra (karena butuh tempat khusus, tidak ada urutan)

## Kapan menggunakan Heap, kapan menggunakan Stack?

Kasarnya sih.. kamu pakai stack saat sudah tahu berapa banyak data yang dibutuhkan sebelum compile berjalan dan ukurannya tidak terlalu besar. Heap sebaliknya.

> Setiap bahasa program punya cara masing-masing data mana yang disimpan di heap, data mana yang di stack

### Lebih detail penggunaan heap dan stack

Heap dan stack adalah dua jenis struktur data yang digunakan dalam pemrograman, dan keduanya memiliki penggunaan yang berbeda:

1. **Stack**: Stack biasanya digunakan untuk alokasi memori yang sementara dan bersifat lokal. Misalnya, ketika suatu fungsi dipanggil, ruang untuk variabel lokal dan parameter fungsi dialokasikan di stack, dan mereka secara otomatis ‘dihapus’ saat fungsi selesai.

Stack juga digunakan untuk mengendalikan alur program, seperti melacak fungsi mana yang sedang berjalan dan fungsi mana yang memanggil fungsi lain. Penggunaan memori stack biasanya lebih cepat dibandingkan heap karena alokasi dan dealokasi di stack hanya melibatkan penyesuaian pointer, bukan pencarian blok memori. Namun, ruang di stack biasanya terbatas.

2. **Heap**: Heap digunakan untuk alokasi memori yang perlu bertahan lebih lama dari satu panggilan fungsi atau lebih besar dari yang bisa ditampung oleh stack. Misalnya, jika Kamu perlu mengalokasikan array besar atau jika Kamu membuat objek yang perlu bertahan selama siklus hidup aplikasi, Kamu akan menggunakan heap.

Penggunaan memori heap lebih fleksibel karena memori bisa dialokasikan dan dihapus kapan saja, tetapi juga lebih lambat dan lebih rumit karena perlu menghindari masalah seperti kebocoran memori dan fragmentasi.

Pemilihan antara stack dan heap biasanya didasarkan pada dua pertimbangan: berapa lama Kamu perlu menyimpan data dan berapa banyak data yang perlu Kamu simpan. Jika data hanya perlu disimpan selama durasi panggilan fungsi dan tidak terlalu besar, maka stack adalah pilihan yang baik. Jika data perlu disimpan lebih lama atau jika Kamu perlu menyimpan blok data yang besar, maka Kamu harus menggunakan heap.

## Contoh kongkrit heap dan stack?

Contohnya kamu mau menyimpan angka

```
let x = 10;
```

Karena nilainya sudah diketahui dan relatif kecil, ini disimpan di stack.

Sementara, saat kamu misalnya ingin menerima sesuatu dari input user

```
let input = InputFromUser()
```

Nilainya cenderung tidak diketahui, kita menyimpannya di heap.