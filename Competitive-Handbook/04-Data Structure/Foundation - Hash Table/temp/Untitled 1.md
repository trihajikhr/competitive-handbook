---
obsidianUIMode: preview
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
# Hash Table Data Structure

## 1. Apa itu _Hash Table_?

_Hash table_ adalah _data structure_ yang digunakan untuk melakukan _insert_, _look up_, dan _remove_ _key-value pairs_ secara cepat. _Hash table_ beroperasi berdasarkan konsep _hashing_, di mana setiap _key_ diterjemahkan oleh _hash function_ menjadi _index_ yang unik di dalam sebuah _array_. _Index_ tersebut berfungsi sebagai lokasi penyimpanan untuk _value_ yang terkait. Secara sederhana, _hash table_ memetakan _keys_ dengan _value_-nya.

### 1.1. _Hash Function_ dan _Table_

#### _Load factor_

_Load factor_ dari sebuah _hash table_ ditentukan oleh perbandingan jumlah elemen yang disimpan dengan ukuran _table_ tersebut. Jika _load factor_ tinggi, _table_ mungkin mengalami _cluttered_ yang mengakibatkan waktu pencarian lebih lama dan peningkatan _collisions_. _Load factor_ yang ideal dapat dipertahankan dengan menggunakan _hash function_ yang baik dan _table resizing_ yang tepat.
#### _Hash function_

_Hash function_ adalah _function_ yang menerjemahkan _keys_ menjadi _array indices_. _Keys_ harus didistribusikan secara merata ke seluruh _array_ melalui _hash function_ yang baik untuk meminimalkan _collisions_ dan memastikan _lookup speeds_ yang cepat.

- **_Integer universe assumption_**: Berdasarkan asumsi ini, _keys_ dianggap sebagai _integers_ dalam rentang tertentu. Hal ini memungkinkan penggunaan operasi _hashing_ dasar seperti _division_ atau _multiplication hashing_.
    
- **_Hashing by division_**: Teknik _hashing_ sederhana ini menggunakan sisa hasil bagi (_remainder_) antara _key_ dengan ukuran _array_ sebagai _index_. Teknik ini bekerja dengan baik ketika ukuran _array_ adalah _prime number_ dan _keys_ terdistribusi secara merata.
    
- **_Hashing by multiplication_**: Operasi _hashing_ ini mengalikan _key_ dengan konstanta antara 0 dan 1, kemudian mengambil bagian fraksional dari hasilnya. _Index_ kemudian ditentukan dengan mengalikan komponen fraksional tersebut dengan ukuran _array_. Teknik ini efektif ketika _keys_ tersebar secara merata.

### Kriteria Pemilihan _Hash Function_

Memilih _hash function_ yang tepat bergantung pada karakteristik _keys_ dan fungsionalitas _hash table_ yang diinginkan. Berikut adalah kriteria utamanya:

- **Distribusi Seragam**: _Hash function_ yang baik harus mendistribusikan _keys_ di seluruh _hash table_ secara seragam untuk meminimalkan _collisions_. Peluang dua _keys_ untuk melakukan _hashing_ ke posisi yang sama di _table_ harus konstan.
    
- **Efisiensi Komputasi**: _Hash function_ harus efisien secara komputasi untuk memungkinkan _hashing_ dan _key retrieval_ yang cepat.
    
- **Keamanan**: Seharusnya sulit untuk menyimpulkan _key_ dari nilai _hash_-nya.
    
- **Fleksibilitas**: _Hash function_ harus mampu beradaptasi terhadap perubahan data, seperti perubahan ukuran atau format _keys_.
    

## Teknik Resolusi _Collisions_

_Collisions_ terjadi ketika dua atau lebih _keys_ menunjuk ke _index_ _array_ yang sama.

- **_Open addressing_**: _Collisions_ ditangani dengan mencari ruang kosong berikutnya dalam _table_. Jika _slot_ pertama sudah terisi, _hash function_ diterapkan pada _slot_ berikutnya hingga ditemukan ruang kosong. Metode ini mencakup _double hashing_, _linear probing_, dan _quadratic probing_.
    
- **_Separate Chaining_**: Dalam _separate chaining_, setiap _slot_ di _hash table_ menyimpan _linked list_ dari objek yang melakukan _hashing_ ke _slot_ tersebut. Jika dua _keys_ melakukan _hashing_ ke _slot_ yang sama, keduanya akan dimasukkan ke dalam _linked list_ tersebut.
    
- **_Robin Hood hashing_**: _Collisions_ ditangani dengan melakukan pertukaran _keys_ untuk mengurangi panjang _chain_. Jika _key_ baru melakukan _hashing_ ke _slot_ yang sudah terisi, algoritma akan membandingkan jarak antara _slot_ tersebut dengan _ideal slot_ dari kedua _key_. _Key_ yang ada akan ditukar dengan yang baru jika _key_ tersebut lebih dekat ke _ideal slot_-nya.
    

## _Dynamic Resizing_

Fitur ini memungkinkan _hash table_ untuk melakukan ekspansi atau kontraksi sebagai respons terhadap perubahan jumlah elemen. Hal ini mendukung _load factor_ yang ideal serta menjaga _lookup times_ tetap cepat.

## Contoh Implementasi dalam C++

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Hash {
    int BUCKET; // Jumlah buckets

    // Vector of vectors untuk menyimpan chains
    vector<vector<int>> table;

    // Memasukkan key ke dalam hash table
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Menghapus key dari hash table
    void deleteItem(int key);

    // Hash function untuk memetakan values ke key
    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash();

    // Constructor untuk menginisialisasi bucket count dan table
    Hash(int b) {
        this->BUCKET = b;
        table.resize(BUCKET);
    }
};

// Fungsi untuk menghapus key dari hash table
void Hash::deleteItem(int key) {
    int index = hashFunction(key);

    // Mencari dan menghapus key dari table[index] vector
    auto it = find(table[index].begin(), table[index].end(), key);
    if (it != table[index].end()) {
        table[index].erase(it); // Hapus key jika ditemukan
    }
}

// Fungsi untuk menampilkan hash table
void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (int x : table[i]) {
            cout << " --> " << x;
        }
        cout << endl;
    }
}

// Driver program
int main() {
    // Vector yang berisi keys untuk dipetakan
    vector<int> a = {15, 11, 27, 8, 12};

    // Memasukkan keys ke dalam hash table
    Hash h(7); // 7 adalah jumlah buckets 
    for (int key : a)
        h.insertItem(key);

    // Menghapus 12 dari hash table
    h.deleteItem(12);

    // Menampilkan hash table
    h.displayHash();

    return 0;
}
```

## Analisis Kompleksitas

- **Rata-rata (_Average Case_)**: Operasi _lookup_, _insertion_, dan _deletion_ memiliki _time complexity_ $O(1)$.
    
- **Kasus Terburuk (_Worst Case_)**: Operasi tersebut dapat memerlukan waktu $O(n)$, di mana $n$ adalah jumlah elemen dalam _table_.
    

## Aplikasi _Hash Table_

- **Indeks dan Pencarian**: Digunakan dalam mesin pencari untuk menyimpan _web pages_ yang telah di-_index_.
    
- **_Caching_**: Data sering di-_cache_ di memori melalui _hash tables_ untuk akses cepat.
    
- **Kriptografi**: _Hash functions_ digunakan untuk membuat _digital signatures_, memvalidasi data, dan menjamin integritas data.
    
- **Basis Data**: Digunakan untuk mengimplementasikan _database indexes_, memungkinkan akses cepat berdasarkan _key values_.