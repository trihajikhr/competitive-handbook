---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 05TH-CSGP-0001
nama_algoritma: permutations
kategori_algoritma: complete search
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-04-13T11:35:00
tags:
  - complete-search
  - permutations
  - recursive-permutations
  - stl-permutation
---
#complete-search #permutations #recursive-permutations #stl-permutation

---
# Permutations Algorithm | Method 1
Seperti subset, permutasi juga dapat dihasilkan menggunakan rekursi. Fungsi berikut, `search`, menjalankan iterasi untuk semua permutasi dari himpunan $\{0,1,\dots,n-1\}$. Fungsi ini membangun sebuah vektor `permutation` yang berisi elemen-elemen dalam permutasi, dan pencarian dimulai ketika fungsi dipanggil tanpa parameter.

Setiap pemanggilan fungsi menambahkan elemen baru ke dalam `permutation`. Array `chosen` menunjukkan elemen mana yang sudah dimasukkan ke dalam permutasi. Jika ukuran `permutation` sama dengan ukuran himpunan, maka sebuah permutasi telah dihasilkan.

---

**Permutasi** adalah **semua susunan yang mungkin** dari suatu himpunan, **tanpa pengulangan** dan **dengan memperhatikan urutan**.

Misal:
Kita ingin **menghasilkan semua permutasi** dari himpunan `{0, 1, ..., n-1}`.  
Permutasi = susunan ulang dari elemen-elemen tanpa ada yang diulang.

Contoh (jika `n = 3`):

```
Permutasi dari {0,1,2}:
→ 0 1 2  
→ 0 2 1  
→ 1 0 2  
→ 1 2 0  
→ 2 0 1  
→ 2 1 0
```

## Algoritma Permutations

Perhatikan kode berikut:

```cpp
void search() {
	if (permutation.size() == n) {
		// process permutation
	} else {
		for (int i = 0; i < n; i++) {
			if (chosen[i]) continue;
			chosen[i] = true;
			permutation.push_back(i);
			search();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}
```

Program ini menggunakan:

1. **`permutation`** → vektor yang menyimpan elemen dalam susunan saat ini.
    
2. **`chosen`** → array bool (`true/false`) untuk mencatat elemen yang sudah dipakai.
    
3. **`search()`** → fungsi rekursif untuk membangun permutasi.
    

## Cara Kerja search()

Berikut adalah pseudonya, sudah rapi dan diberi penjelasan baris demi baris:

```cpp
void search() {
    // Basis rekursi: Jika ukuran permutation = n, berarti kita sudah punya satu permutasi lengkap
    if (permutation.size() == n) {
        // proses permutasi, misalnya mencetaknya
    } 
    else {
        // Lakukan percobaan untuk setiap elemen i dari 0 sampai n-1
        for (int i = 0; i < n; i++) {
            // Jika elemen i sudah dipilih sebelumnya, skip
            if (chosen[i]) continue;

            // Tandai elemen i sudah dipilih
            chosen[i] = true;

            // Tambahkan elemen i ke vektor permutation
            permutation.push_back(i);

            // Rekursif: lanjut ke posisi berikutnya
            search();

            // Backtrack: kembalikan keadaan seperti semula
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
```

---

## Ilustrasi Backtracking

Misal `n = 2`, berarti elemen = `{0, 1}`. Proses rekursinya seperti ini:

```
search()
└── i=0 → chosen[0]=true, permutation = [0]
    └── search()
        └── i=1 → chosen[1]=true, permutation = [0, 1]
            └── permutation.size()==n → cetak [0, 1]
        ← backtrack: pop 1, chosen[1]=false
    ← backtrack: pop 0, chosen[0]=false

└── i=1 → chosen[1]=true, permutation = [1]
    └── search()
        └── i=0 → chosen[0]=true, permutation = [1, 0]
            └── permutation.size()==n → cetak [1, 0]
        ← backtrack: pop 0, chosen[0]=false
    ← backtrack: pop 1, chosen[1]=false
```

---

Atau semisal kita meminilii `n=3`, maka visualisasinya seperti ini seperti ini:

```cpp
Start: permutation = [], chosen = [F, F, F]
|
|-- Add 0 → [0], chosen = [T, F, F]
|   |
|   |-- Add 1 → [0, 1], chosen = [T, T, F]
|   |   |
|   |   |-- Add 2 → [0, 1, 2] ✅
|   |   |
|   |   \-- Backtrack
|   |
|   |-- Add 2 → [0, 2], chosen = [T, F, T]
|   |   |
|   |   |-- Add 1 → [0, 2, 1] ✅
|   |   |
|   |   \-- Backtrack
|   \-- Backtrack
|
|-- Add 1 → [1], chosen = [F, T, F]
|   |
|   |-- Add 0 → [1, 0], chosen = [T, T, F]
|   |   |
|   |   |-- Add 2 → [1, 0, 2] ✅
|   |
|   |-- Add 2 → [1, 2], chosen = [F, T, T]
|   |   |
|   |   |-- Add 0 → [1, 2, 0] ✅
|   \-- Backtrack
|
|-- Add 2 → [2], chosen = [F, F, T]
    |
    |-- Add 0 → [2, 0], chosen = [T, F, T]
    |   |
    |   |-- Add 1 → [2, 0, 1] ✅
    |
    |-- Add 1 → [2, 1], chosen = [F, T, T]
        |
        |-- Add 0 → [2, 1, 0] ✅
```

Outputnya adalah:
```bash
0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0
```

### Catatan Penting:

- Setiap node di pohon merepresentasikan **keadaan** dari `permutation` saat ini.
    
- Cabang di bawahnya adalah **angka berikutnya** yang dicoba untuk ditambahkan.
    
- Ketika `permutation.size() == n`, artinya kita sudah mendapatkan **satu permutasi lengkap**.
    
- Lalu **kita kembali (backtrack)**, dan coba pilihan lain.
## Variabel Global (dibutuhkan)

Agar program ini bisa bekerja, kamu butuh:

```cpp
int n;
vector<int> permutation;
bool chosen[MAX]; // MAX ≥ n
```

---

## ✅ Kesimpulan

- Program ini menggunakan **rekursi dengan backtracking** untuk menjelajahi semua kemungkinan permutasi.
    
- `chosen[i]` memastikan **tidak ada elemen yang dipakai dua kali** dalam satu permutasi.
    
- Ketika `permutation.size() == n`, kita tahu **permutasi lengkap telah terbentuk**.
    

# Permutation Algorithm | Method 2

Metode ini digunakan untuk **menghasilkan semua permutasi** dari himpunan `{0, 1, ..., n-1}`, **dalam urutan menaik secara leksikografis** (seperti urutan kamus).

Perhatikan kode berikut:

```cpp
vector<int> permutation;
for (int i = 0; i < n; i++) {
    permutation.push_back(i);
}
do {
    // proses permutasi
} while (next_permutation(permutation.begin(), permutation.end()));
```

## 🛠️ Konsep Dasar: `next_permutation()`

`next_permutation` adalah **fungsi di C++ STL** (Standard Template Library) yang:

- Mengubah urutan elemen di sebuah array atau vector ke **permute berikutnya dalam urutan menaik**
    
- Mengembalikan `true` jika berhasil membuat permutasi berikutnya
    
- Mengembalikan `false` jika sudah berada di **permute terakhir** (urutan terbesar)
    

---

## 📦 Header yang diperlukan:

```cpp
#include <algorithm> // untuk next_permutation
#include <vector>
```

---

## 🧩 Cara Kerja

Misalnya `n = 3`, maka kita mulai dari permutasi awal `{0, 1, 2}`

```cpp
vector<int> permutation = {0, 1, 2};
do {
    // proses permutasi, misalnya cetak isi vector
} while (next_permutation(permutation.begin(), permutation.end()));
```

Fungsi `next_permutation` akan mengubah isi `permutation` menjadi:

```
{0,1,2} → {0,2,1} → {1,0,2} → {1,2,0} → {2,0,1} → {2,1,0}
```

Sampai akhirnya tidak bisa di-_naikkan_ lagi, dan `next_permutation` akan mengembalikan `false`.

---

## ✅ Kelebihan Metode Ini

|Kelebihan|Penjelasan|
|---|---|
|Lebih ringkas|Tidak perlu membuat fungsi rekursif|
|Praktis|Tidak butuh `chosen[]` atau backtracking manual|
|Built-in|Sudah dioptimalkan oleh pustaka C++|

---

## ⚠️ Syarat Penting

- **Urutan awal** harus dalam **urutan menaik** (`{0, 1, ..., n-1}`) agar semua permutasi bisa dihasilkan secara lengkap.
    
- Fungsi ini hanya bisa digunakan untuk permutasi **tanpa pengulangan**.
    

---

## 📝 Contoh Kode Lengkap

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 3;
    vector<int> permutation;

    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }

    do {
        for (int i = 0; i < n; i++) {
            cout << permutation[i] << " ";
        }
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));

    return 0;
}
```

---

## 🔁 Hasil Output

```
0 1 2
0 2 1
1 0 2
1 2 0
2 0 1
2 1 0
```

---

## 🔚 Kesimpulan

- Fungsi `next_permutation` mempermudah kita untuk mengakses semua permutasi dari sebuah vector secara urut.
    
- Ini adalah alternatif efisien dari metode rekursif manual.
    
- Cocok digunakan untuk kasus di mana kamu ingin **menghasilkan semua permutasi tanpa pusing mikirin rekursi**.
    
Oke, ini dia penjelasan lengkap dalam format yang rapi buat kamu catat di Obsidian: perbandingan dua metode menghasilkan permutasi di C++ — **rekursif** vs **`next_permutation()`**, lengkap dengan kelebihan, kekurangan, dan kesimpulan terbaiknya.

---
# Contoh Implementasi Nyata

## 🧭 Metode 1: Rekursif (Backtracking)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> permutation;
vector<bool> chosen;

void search() {
    if ((int)permutation.size() == n) {
        // Cetak permutasi
        for (int x : permutation) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main() {
    cout << "Masukkan nilai n: ";
    cin >> n;

    chosen.assign(n, false);
    search();

    return 0;
}
```

### 📝 Penjelasan Singkat:

- `permutation`: menyimpan elemen permutasi yang sedang dibentuk
    
- `chosen`: menandai angka yang sudah dipakai
    
- Cetak semua permutasi dari angka `0` sampai `n-1`
    
### penjelasan chose.asign()
Yuk kita bongkar perlahan syntax ini:

```cpp
chosen.assign(n, false);
```

Artinya:

> **Buat vektor `chosen` berisi `n` elemen, semuanya diisi dengan `false`.**

### 🧠 Penjelasan Bayi:

Misalnya kamu input `n = 3`, maka baris itu akan menghasilkan:

```cpp
chosen = {false, false, false};
```

Jadi kita siapin array penanda, apakah angka `0`, `1`, `2` udah **dipakai** atau belum dalam permutasi yang sedang dibangun.

---

### 🔍 Kenapa pakai `.assign()`?

Karena `chosen` sudah dideklarasikan sebelumnya sebagai `vector<bool>`, kita gunakan `.assign()` untuk:

- Menghapus semua isi sebelumnya (kalau ada)
    
- Mengisi ulang vektor dengan `n` nilai `false`
    

---

### 📦 Kalau pakai cara lain?

Kamu juga bisa tulis dengan cara ini:

```cpp
chosen = vector<bool>(n, false);
```

Dua-duanya sah, tapi `.assign()` lebih umum dipakai kalau kamu sudah punya vektor dan mau reset isinya.

---

## ⚙️ Metode 2: `next_permutation()` STL

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;

    vector<int> permutation;
    for (int i = 0; i < n; i++) {
        permutation.push_back(i);
    }

    do {
        for (int x : permutation) {
            cout << x << " ";
        }
        cout << "\n";
    } while (next_permutation(permutation.begin(), permutation.end()));

    return 0;
}
```

### 📝 Penjelasan Singkat:

- Mulai dari vector `{0, 1, ..., n-1}`
    
- Gunakan `next_permutation()` untuk menghasilkan permutasi berikutnya
    
- Ulangi sampai ke permutasi terakhir
    

---

## 🔚 Catatan Tambahan

- Keduanya menghasilkan **semua permutasi tanpa pengulangan** dari angka `0` sampai `n-1`
    
- Cocok untuk mempelajari dasar-dasar algoritma atau eksplorasi semua kemungkinan urutan
    

# 🔄 Dua Metode Menghasilkan Permutasi di C++

### ✨ 1. Metode Rekursif (Backtracking)

```cpp
void search() {
    if (permutation.size() == n) {
        // proses permutasi
    } else {
        for (int i = 0; i < n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
```

#### ✅ Kelebihan:

- Dapat dimodifikasi dengan **mudah** untuk permutasi dengan batasan tertentu (misalnya: tidak boleh ada angka tertentu di posisi tertentu).
    
- Berguna untuk belajar konsep **backtracking dan rekursi**.
    
- Bisa dikombinasikan dengan **filter logika custom** selama proses generasi.
    

#### ❌ Kekurangan:

- **Lebih kompleks dan panjang**, terutama untuk pemula.
    
- Perlu manual mengelola `permutation`, `chosen`, dan rekursinya.
    
- Kurang efisien jika hanya ingin semua permutasi **tanpa batasan**.
    

---

### ⚙️ 2. Metode `next_permutation()`

```cpp
vector<int> permutation = {0, 1, ..., n-1};
do {
    // proses permutasi
} while (next_permutation(permutation.begin(), permutation.end()));
```

#### ✅ Kelebihan:

- **Pendek, simpel, dan efisien**.
    
- Tidak perlu bikin fungsi rekursif atau backtracking.
    
- Sudah dioptimalkan di dalam **STL C++**, cocok untuk kebutuhan umum.
    

#### ❌ Kekurangan:

- Hanya bisa digunakan kalau kamu mulai dari urutan **menaik**.
    
- **Kurang fleksibel** untuk permutasi dengan batasan atau kondisi custom.
    
- Tidak cocok kalau kamu butuh melakukan **pembatasan eksplisit** di dalam proses generate-nya.
    

---

## 🥇 Apa yang Terbaik?

|Kebutuhan|Metode yang Disarankan|
|---|---|
|Ingin belajar rekursi & logika algoritmik|🔁 **Metode Rekursif**|
|Ingin kontrol penuh atas proses generate|🔁 **Metode Rekursif**|
|Ingin hasil cepat & simpel tanpa batasan|⚙️ **`next_permutation()`**|
|Butuh performa dan simplicity|⚙️ **`next_permutation()`**|

---

## 🧠 Rangkuman Akhir:

> 🔁 **Gunakan rekursi** jika kamu sedang belajar algoritma, perlu fleksibilitas tinggi, atau ingin kontrol penuh atas proses permutasi.
> 
> ⚙️ **Gunakan `next_permutation()`** jika kamu hanya butuh semua permutasi dalam urutan menaik, tanpa batasan dan ingin solusi cepat.
