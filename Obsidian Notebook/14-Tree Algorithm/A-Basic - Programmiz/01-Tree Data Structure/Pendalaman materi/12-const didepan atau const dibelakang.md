---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: const didepan atau const dibelakang
sumber: Google.com, AI
date_learned: 2025-06-28T20:00:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# const didepan atau const dibelakang, dalam member Function?
```cpp
pair<int, int> minmaxValue() const {
	pair<int,int> a,b;
	if(left) a = left->minmaxValue();
	if(right) b = right->minmaxValue();

	return{
		max(data, max(a.first, b.first)),
		min(data, min(a.second, b.second)) 
	};
}
```
Lihat kode diatas! Apa jadinya jika aku menggunakan const didepaan? Apa bedanya dengan menggunaka const dibelakang seperti diatas?

<br/>

Pertanyaan kamu sangat dalam dan cerdas — membahas posisi `const` dalam deklarasi fungsi C++ memang penting untuk dipahami, apalagi kalau kamu sudah terbiasa mendefinisikan method seperti:

```cpp
pair<int, int> minmaxValue() const
```

---

## 🔍 Jawaban Singkat:

> ✅ **`const` di belakang** (`minmaxValue() const`) berarti:  
> _“Fungsi ini tidak akan memodifikasi data anggota (`member variables`) dari objek yang memanggilnya.”_

> ❌ **`const` di depan** (`const pair<int, int> minmaxValue()`) berarti:  
> _“Nilai balik (return value) berupa `pair` itu bersifat konstan dan tidak bisa diubah setelah dikembalikan.”_

---

## 📌 Penjelasan Lengkap

### 1. `pair<int, int> minmaxValue() const`

- `const` di **belakang** menandakan bahwa **fungsi ini tidak akan mengubah isi objek** tempat fungsi ini dipanggil.
    
- Wajib dipakai jika kamu ingin memanggil fungsi ini dari objek bertipe `const Node` atau dari pointer `const Node*`.
    

Contoh:

```cpp
const Node* root = new Node(10);
root->minmaxValue();  // hanya bisa jika fungsi bersifat const
```

Kalau kamu **tidak** menulis `const` di belakang, maka compiler akan menolak panggilan tersebut karena dikhawatirkan fungsi akan mengubah isi objek.

---

### 2. `const pair<int, int> minmaxValue() const`

- Di sini kamu menambahkan `const` **di depan tipe return**, artinya: **pasangan (`pair`) yang dikembalikan tidak boleh diubah setelah dikembalikan.**
    

Tapi ini **tidak berguna dalam praktik.** Contoh:

```cpp
auto res = root->minmaxValue();  // tetap bisa diubah
res.first = 100; // tetap bisa! karena const-nya tidak menempel ke 'res', hanya ke return value sementara
```

Agar benar-benar efektif, kamu perlu menuliskannya seperti ini:

```cpp
const auto& res = root->minmaxValue();
```

Namun karena kamu **mengembalikan nilai (`by value`)**, maka **`const` di depan tidak ada gunanya** — nilai akan disalin, lalu bisa bebas dimodifikasi di luar.

---

## 🔥 Kesimpulan

|Posisi `const`|Artinya|Penting?|
|---|---|---|
|`minmaxValue() const`|Fungsi tidak mengubah data anggota (`this`)|✅ Ya|
|`const pair<int,int>`|Nilai return tidak bisa diubah (tapi hanya efek sementara)|❌ Tidak penting jika return-nya by value|

✅ Jadi:

- **Tetap gunakan `const` di belakang** jika fungsinya tidak mengubah state objek.
    
- **Tidak perlu `const` di depan** tipe return untuk nilai biasa seperti `pair<int,int>` — tidak memberikan manfaat nyata.
    

---

Kalau kamu ingin aku bantu tunjukkan contoh fungsi yang _harus_ pakai `const` di belakang agar bisa dipanggil dari `const Node*`, tinggal bilang ya!