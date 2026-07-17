---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned: 2026-07-12T01:23:00
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Key dan Value

Dalam struktur data _hash table_, _key_ dan _value_ merupakan pasangan data yang tidak terpisahkan, yang sering disebut sebagai _key-value pair_. Berikut adalah penjelasannya:

## Definisi _key_ (kunci)

- _Key_ adalah pengidentifikasi unik yang digunakan untuk mengakses data dalam _hash table_.
- _Key_ berfungsi sebagai masukan utama bagi _hash function_ untuk menentukan di mana lokasi penyimpanan data di dalam _array_.
- Karena _key_ menentukan lokasi, maka sangat penting agar _key_ bersifat _immutable_ atau tidak dapat diubah setelah dimasukkan ke dalam _hash table_. Jika _key_ berubah, maka _hash code_ yang dihasilkan akan berubah, sehingga data tidak akan bisa ditemukan kembali.

## Definisi _value_ (nilai)

- _Value_ adalah data sebenarnya yang ingin disimpan dan dikaitkan dengan _key_ tertentu.
- _Value_ bisa berupa tipe data apa saja, mulai dari angka, _string_, objek, hingga struktur data yang lebih kompleks.
- Berbeda dengan _key_, _value_ tidak berpengaruh pada penentuan lokasi penyimpanan di dalam _array_.

## Hubungan antara _key_ dan _value_

- _Hash table_ dirancang untuk melakukan pemetaan (_mapping_) dari _key_ ke _value_ secara efisien.
- Dalam implementasinya, pasangan _key-value_ ini sering dikemas dalam sebuah struktur yang disebut _entry_ atau _node_.
- Saat Anda melakukan operasi _put_ (menyimpan data), sistem akan memproses _key_ melalui _hash function_ untuk mencari _bucket_-nya, lalu menyimpan pasangan _key-value_ tersebut di sana.
- Saat Anda melakukan operasi _get_ (mengambil data), sistem akan memproses _key_ yang sama untuk menemukan _bucket_ yang tepat, lalu membandingkan _key_ yang tersimpan di _bucket_ tersebut dengan _key_ yang Anda cari untuk memastikan bahwa _value_ yang dikembalikan sudah benar.

# FAQ
## Penerapan Hash Function

> Jadi ketika aku pertama kali menyimpan, dan mengambil data dengan *key*, maka *key* tersebut harus diolah lagi oleh *hash function*?

Tepat sekali. Itulah prinsip utama cara kerja _hash table_. Berikut adalah penjelasannya:

- Pada saat pertama kali Anda menyimpan data (_insertion_): Sistem akan memasukkan _key_ tersebut ke dalam _hash function_ untuk mendapatkan _index_. Setelah _index_ didapatkan, sistem akan menempatkan pasangan _key_ dan _value_ ke dalam _bucket_ di posisi tersebut.
- Pada saat Anda ingin mengambil data kembali (_retrieval_): Sistem harus mengolah kembali _key_ yang sama ke dalam _hash function_ yang sama. Karena sifat _hash function_ adalah _deterministik_ (hasilnya selalu sama untuk _input_ yang sama), maka sistem akan mendapatkan _index_ yang persis sama dengan posisi penyimpanan sebelumnya.
- Proses verifikasi: Setelah sistem sampai di _bucket_ yang dituju berdasarkan _index_ dari _hash function_, sistem akan melakukan pengecekan (_comparison_). Jika di dalam _bucket_ tersebut terdapat lebih dari satu data (karena _collision_), sistem akan membandingkan _key_ yang Anda berikan dengan _key_ yang tersimpan di dalam _bucket_ tersebut untuk memastikan Anda mendapatkan _value_ yang benar.

Jadi, proses _hashing_ ini memang selalu terjadi setiap kali ada operasi akses data agar sistem tahu ke mana harus mencari atau menyimpan tanpa harus memeriksa setiap _bucket_ satu per satu. Itulah alasan mengapa _hash table_ bisa memiliki performa akses yang sangat cepat (_constant time_ $O(1)$).

