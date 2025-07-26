---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Tree dengan Class vs Struct
sumber: chatgpt.com
date_learned: 2025-07-06T15:03:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Tree dengan Class vs Struct, mana lebih baik?

> Hei, sebelumnya aku belajar tentang algoritma tree, dan kebanyakan tutorial menggunakan struct Node untuk fondasi tree nya, tapi ada juga yang menggunakan class.
> 
> Pertanyaanku, mana penulisan yang lebih baik? dan apa kelebihan dan kekuranganya?

Pertanyaan yang sangat bagus! Dalam C++, baik `struct` maupun `class` sebenarnya adalah dua cara untuk mendefinisikan **tipe data user-defined**, dan perbedaan utamanya hanya pada **default access modifier**:

- `struct`: default **public**
    
- `class`: default **private**
    

Jadi secara teknis, keduanya bisa digunakan untuk membangun struktur data seperti tree. Namun, ada pertimbangan desain yang membuat orang memilih satu dibanding yang lain.

---

## 🔍 Perbandingan `struct` vs `class` untuk Node Tree

| Aspek                          | `struct`                               | `class`                                     |
| ------------------------------ | -------------------------------------- | ------------------------------------------- |
| Default Access             | Public                                 | Private                                     |
| Tujuan Filosofis           | Untuk data **plain** (POD)             | Untuk **encapsulasi** dan OOP               |
| Cocok untuk Tree Node?     | Ya, terutama jika hanya menyimpan data | Ya, terutama jika ingin kontrol akses lebih |
| Encapsulation              | Lemah (harus eksplisit atur private)   | Kuat (default private)                      |
| Ekstensi OOP (Inheritance) | Bisa, tapi tidak lazim                 | Cocok untuk inheritance / polymorphism      |
| Kebiasaan (konvensi)       | Digunakan di struktur data dasar (POC) | Digunakan dalam sistem OOP kompleks         |

---

## 📌 Kapan Memilih `struct`

Gunakan `struct` jika:

- Node hanya menyimpan **data** dan **pointer anak** (left/right).
    
- Tidak butuh enkapsulasi atau validasi khusus.
    
- Fokus pada **kesederhanaan** dan **kemudahan debugging**.
    
- Cocok untuk tree dalam **kontes algoritma**, **latihan dasar**, atau implementasi cepat.
    

Contoh:

```cpp
template<typename T>
struct Node {
    T data;
    Node* left;
    Node* right;

    Node(T val) : data(val), left(nullptr), right(nullptr) {}
};
```

Contoh dengan `unique_ptr`:

```cpp
template<typename T>
struct Node {
	T data;
	unique_ptr<Node<T>> left, right;
	Node(T data) : data(data) {}
};
```

---

## 📌 Kapan Memilih `class`

Gunakan `class` jika:

- Kamu butuh **enkapsulasi**, misalnya menyembunyikan detail implementasi.
    
- Kamu ingin menambahkan **fungsi anggota**, misal insert/delete langsung di Node.
    
- Kamu ingin menerapkan **desain berorientasi objek**, termasuk inheritance dan polymorphism.
    
- Aplikasi bersifat **kompleks atau produksi**.
    

Contoh:

```cpp
template<typename T>
class Node {
private:
    T data;
    Node* left;
    Node* right;

public:
    Node(T val) : data(val), left(nullptr), right(nullptr) {}

    T getData() const { return data; }
    void setLeft(Node* l) { left = l; }
    Node* getLeft() const { return left; }
    // dst...
};
```

Contoh dengan `unique_ptr`:

```cpp
template<typename T>
class Node {
private:
    T data;
    std::unique_ptr<Node<T>> left, right;

public:
    Node(T data) : data(data) {}

    T getData() const { 
        return data; 
    }

    Node<T>* setLeft(T val) {
        left = std::make_unique<Node<T>>(val);
        return left.get();
    }

    Node<T>* getLeft() const {
        return left.get(); 
        // gunakan .get() untuk mengakses pointer mentah
    }

    // Bisa ditambah metode lainnya:
    void setRight(T val) {
        right = std::make_unique<Node<T>>(val);
    }

    Node<T>* getRight() const {
        return right.get();
    }
};

```

---

## ✅ Kesimpulan

- Untuk **latihan struktur data**, gunakan `struct`: lebih ringan, to the point.
    
- Untuk **desain skala besar**, gunakan `class`: lebih fleksibel dan aman.
    
- Di C++, `struct` dan `class` itu **hampir setara secara fungsional**, jadi pilihan lebih bergantung pada **niat desain dan konteks penggunaan**.
    

---
<br/><br/><br/>
# Struct vs Class Versi 2
Berikut adalah **kesimpulan detail** mengenai penggunaan `struct` vs `class` di C++, khususnya dalam konteks membangun struktur data seperti **tree node**.

---

## 🧩 Persamaan `struct` dan `class` di C++

|Fitur|`struct`|`class`|
|---|---|---|
|Template support|✔️ Ya|✔️ Ya|
|Constructor/destructor|✔️ Ya|✔️ Ya|
|Bisa punya fungsi anggota|✔️ Ya|✔️ Ya|
|Mendukung inheritance / polymorphism|✔️ Ya|✔️ Ya|
|Mendukung akses modifier (`public`, dll)|✔️ Ya|✔️ Ya|

> 🟰 Jadi secara fitur, `struct` dan `class` **setara di C++**, tidak seperti di C (yang hanya punya `struct`).

---

## 🔐 Perbedaan Utama

| Aspek                       | `struct`                   | `class`                          |
| --------------------------- | -------------------------- | -------------------------------- |
| Default access modifier | `public`                   | `private`                        |
| Filosofi desain         | Untuk data sederhana (POD) | Untuk desain berorientasi objek  |
| Cocok untuk             | Struktur data ringan       | Sistem kompleks, OOP             |
| Keterbacaan             | Ringan, mudah dibaca       | Lebih formal, bisa lebih verbose |

---

## 🧪 Studi Kasus: Node Pohon

### Menggunakan `struct`

```cpp
template<typename T>
struct Node {
    T data;
    std::unique_ptr<Node<T>> left, right;

    Node(T data) : data(data) {}
};
```

📌 Cocok jika:

- Hanya menyimpan data & pointer.
    
- Tidak ada kebutuhan validasi / encapsulation.
    
- Fokus pada **latihan algoritma** atau kontes competitive programming.
    

---

### Menggunakan `class`

```cpp
template<typename T>
class Node {
private:
    T data;
    std::unique_ptr<Node<T>> left, right;

public:
    Node(T data) : data(data) {}

    T getData() const { return data; }
    Node<T>* setLeft(T val) {
        left = std::make_unique<Node<T>>(val);
        return left.get();
    }
    Node<T>* getLeft() const { return left.get(); }
    // dan seterusnya...
};
```

📌 Cocok jika:

- Ingin **menyembunyikan detail implementasi**.
    
- Ingin memberi **kontrol lebih besar** terhadap bagaimana data dimodifikasi.
    
- Perlu **menghindari misuse**, misalnya pengguna langsung mengubah `left` sembarangan.
    
- Bagian dari **arsitektur aplikasi besar**.
    

---

## ✅ Ringkasan Akhir

| Kriteria                          | Gunakan `struct`                             | Gunakan `class`                             |
| --------------------------------- | -------------------------------------------- | ------------------------------------------- |
| Latihan dasar struktur data   | ✔️ Lebih cepat dan ringan                    | ❌ Terlalu verbose                           |
| Kontrol penuh atas akses data | ❌ Tidak cocok (kecuali diberi `private`)     | ✔️ Lebih baik                               |
| Enkapsulasi & keamanan data   | ❌ Harus eksplisit                            | ✔️ Secara default                           |
| Produksi / skala besar        | ❌ Rentan disalahgunakan                      | ✔️ Lebih aman, modular                      |
| Kecepatan penulisan           | ✔️ Lebih singkat                             | ❌ Lebih panjang dan formal                  |
| Konvensi modern C++           | ✔️ Masih banyak dipakai untuk POD-like types | ✔️ Disarankan untuk API dan sistem kompleks |

---

Kalau kamu kerja di proyek nyata, rekomendasinya:

- Gunakan `class` untuk **API, library, game engine**, atau **software produksi**.
    
- Gunakan `struct` untuk **latihan coding**, **struktur data dasar**, atau ketika kamu butuh **kecepatan dan kesederhanaan**.
    
