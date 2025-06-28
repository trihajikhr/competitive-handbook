---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Kesalahan Umum dalam Tree
sumber: Google.com, AI
date_learned: 2025-06-27T15:06:00
tags:
  - tree-algorithm
---
Link Sumber: 

---
# Masalah Umum Saat Membangun Tree

Berikut adalah beberapa kesalahan atau jebakan yang kerap terjadi ketika kita membuat dan menginisialisasi sebuah binary tree:

## Lupa Menginisialisasi Child

- **Gejala**: Pointer `left`/`right` tidak di–set ke `nullptr` (atau `NULL`), sehingga saat traversal akan mengakses alamat sampah.
	
- **Solusi**: Selalu inisialisasi member `left` dan `right` di konstruktor, atau gunakan default member initializer:
	
	```cpp
	Node(int v) : data(v), left(nullptr), right(nullptr) {}
	```
        
## Pointer Terbalik (Left vs. Right)

- **Gejala**: Data muncul di sisi pohon yang salah—child kiri berisi seharusnya kanan, atau sebaliknya.
	
- **Solusi**: Konsisten dengan konvensi:
	
	```cpp
	parent->left  = new Node(valLeft);
	parent->right = new Node(valRight);
	```
        
## Loop Rekursi Tanpa Basis Case

- **Gejala**: Program crash (stack overflow) karena rekursi tidak pernah berhenti.
	
- **Solusi**: Pastikan fungsi rekursif selalu memeriksa `if (node == nullptr) return;` sebelum memanggil dirinya lagi.
        
## Membangun dari Array yang Tidak Lengkap

- **Gejala**: Menggunakan rumus `2*i+1` / `2*i+2` pada array yang bukan complete tree menyebabkan pointer ke luar batas.
	
- **Solusi**:
	
	- Validasi indeks sebelum memanggil lagi.
		
	- Gunakan sentinel (misal `-1` atau `optional<int>`) dan metode level-order dengan `queue`.
            
## Memory Leak (Tidak Menghapus Node)

- **Gejala**: Aplikasi terus membesar penggunaan memorinya setiap kali membuat tree baru.
	
- **Solusi**:
	
	- Implementasikan fungsi destruktor/release:
		
		```cpp
		void deleteTree(Node* node) {
		  if (!node) return;
		  deleteTree(node->left);
		  deleteTree(node->right);
		  delete node;
		}
		```
		
	- Atau gunakan smart pointer (`unique_ptr` / `shared_ptr`).
            
## Menyambung Child pada Node Salah

- **Gejala**: Saat membangun secara loop atau dari input relasi, child terkadang terpasang pada node yang bukan parent-nya.
	
- **Solusi**:
	
	- Bangun map `value → Node*` dulu, lalu sambungkan berdasarkan relasi parent-child.
		
	- Contoh:
		
		```cpp
		unordered_map<int, Node*> mp;
		// buat seluruh Node dan simpan di mp
		// kemudian untuk tiap (p, l, r):
		if (l != -1) mp[p]->left  = mp[l];
		if (r != -1) mp[p]->right = mp[r];
		```
            
## Kesalahan Off-by-One (Indexing Array)

- **Gejala**: Saat membangun dari array, child tidak sesuai atau skip satu indeks.
	
- **Solusi**:
	
	- Selalu uji dengan array kecil (misal 3–7 elemen) dan cetak struktur untuk verifikasi.
		
	- Dokumentasikan dengan jelas rumus indeks yang dipakai.
            
