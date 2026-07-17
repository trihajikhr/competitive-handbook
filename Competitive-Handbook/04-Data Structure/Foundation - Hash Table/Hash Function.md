---
obsidianUIMode: preview
note_type: book theory
judul_materi: Hash Function
sumber:
date_learned: 2026-07-12T00:05:00
tags:
  - data-structures
  - hash-table
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Hash Function

Dalam struktur data _hash table_, _hash function_ adalah komponen fundamental yang menentukan efisiensi dan performa penyimpanan data. Berikut adalah penjelasannya:

## Definisi _hash function_

_Hash function_ adalah sebuah algoritma atau fungsi matematika yang menerima masukan (_input_) berupa _key_ (kunci) dengan panjang variabel dan mengubahnya menjadi sebuah nilai numerik atau _hash code_ dengan panjang tetap. Nilai ini kemudian digunakan sebagai indeks dalam sebuah _array_ atau _hash table_ untuk menentukan lokasi penyimpanan _value_ (nilai) yang terkait.

## Peran utama _hash function_

- Pemetaan indeks (_index mapping_): Mengubah data kompleks seperti _string_ atau _object_ menjadi indeks _array_ yang efisien untuk diakses.
    
- Distribusi seragam (_uniform distribution_): Memastikan _key_ tersebar merata di seluruh _bucket_ agar tidak menumpuk di satu lokasi, sehingga meminimalkan terjadinya _collision_.
    
- Efisiensi waktu (_time complexity_): Memungkinkan operasi _search_, _insertion_, dan _deletion_ dilakukan dalam waktu rata-rata _constant time_ $O(1)$.


## Karakteristik _hash function_ yang ideal

- Deterministik: _Input_ yang sama harus selalu menghasilkan _output_ (indeks) yang sama.
- Efisien: Komputasi fungsi harus berlangsung sangat cepat (_low computational complexity_).
- Distribusi merata: Meminimalisir _clustering_ dengan menyebarkan _keys_ ke seluruh ruang _array_ yang tersedia.
- Minimal _collision_: Meminimalisir situasi di mana dua _keys_ berbeda menghasilkan indeks yang sama.

## Contoh sederhana implementasi

```cpp
// Contoh sederhana hash function untuk string
function simpleHash(key, arraySize) {
  let hash = 0;
  for (let i = 0; i < key.length; i++) {
    hash += key.charCodeAt(i);
  }
  // Mengembalikan indeks dalam rentang array menggunakan modulo
  return hash % arraySize; 
}
```


# FAQ
> Jadi, untuk setiap kasus, itu bisa beda-beda hash functionya?

Betul sekali. Pemilihan _hash function_ sangat bergantung pada jenis data yang disimpan dan kebutuhan spesifik dari sistem tersebut. Tidak ada satu _hash function_ yang cocok untuk semua kondisi.

Berikut adalah alasan mengapa _hash function_ bisa berbeda-beda tergantung kasusnya:

- Jenis _input data_: _Hash function_ untuk data _string_ akan berbeda cara kerjanya dengan _hash function_ untuk data _integer_ atau objek yang kompleks.
    
- Distribusi data: Jika _key_ yang masuk memiliki pola tertentu (misalnya berurutan), _hash function_ harus dirancang sedemikian rupa agar tidak terjadi _clustering_ atau penumpukan pada indeks tertentu.
    
- Ukuran _hash table_: _Hash function_ harus disesuaikan dengan ukuran _array_ atau _bucket_ agar hasil _mapping_ selalu berada dalam batas indeks yang valid.
    
- Tujuan penggunaan: Dalam beberapa kasus, performa kecepatan komputasi menjadi prioritas utama (_low computational complexity_), sementara dalam kasus lain, keamanan data atau meminimalisir _collision_ menjadi prioritas yang lebih tinggi.
    

Dengan demikian, pengembang sering kali menyesuaikan _hash function_ untuk memastikan efisiensi operasi _search_, _insertion_, dan _deletion_ dalam struktur data tersebut.