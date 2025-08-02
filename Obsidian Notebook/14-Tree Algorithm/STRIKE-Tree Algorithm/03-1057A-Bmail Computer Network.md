---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1057A
judul_FAST: Bmail Computer Network
teori_FAST: Mencari path dari root, ke node tertentu dengan menggunakan DFS dan metode backtracking
sumber:
  - codeforces
date_learned: 2025-08-01T23:47:00
tags:
  - tree-algorithm
  - STRIKE
---
Sumber: [Problem - 1057A - Codeforces](https://codeforces.com/problemset/problem/1057/A)

> [!NOTE] ⚔️ Teori STRIKE:
> Kita diminta untuk mencari path dari root ke node $x$. Disini kita bisa menggunakan metode DFS dan backtracking. Soal ini menjadi awal yang baik untuk belajar DFS pada tree, dan juga metode backtracking.

<br/>

---
# 1057A-Bmail Computer Network
**Batas waktu per pengujian:** 4 detik  
**Batas memori per pengujian:** 256 megabyte

Dulu, hanya ada satu router di perusahaan terkenal **Bmail**. Seiring waktu, perusahaan membeli router baru satu per satu. Setiap kali membeli router baru, router tersebut dihubungkan ke salah satu router yang telah dibeli sebelumnya.

Diberikan nilai $p_i$ — yaitu indeks router tempat router ke-$i$ dihubungkan, dengan syarat $p_i < i$.

Sekarang, terdapat total $n$ router di Bmail. Cetak urutan router pada jalur dari router ke-1 hingga router ke-$n$.
### Input

* Baris pertama berisi satu bilangan bulat $n$ $(2 \leq n \leq 200000)$ — jumlah router.
* Baris kedua berisi $n - 1$ bilangan bulat: $p_2, p_3, \ldots, p_n$, di mana $1 \leq p_i < i$.

### Output

* Cetak jalur dari router ke-1 hingga router ke-$n$. Jalur dimulai dari 1 dan diakhiri dengan $n$. Semua elemen dalam jalur harus unik.

<br/>

---
# Sesi STRIKE ⚔️

Karena sebelumnya sudah pernah belajar tentang algoritma graph, maka aku lumayan mengerti apa yang harus dilakukan disini:

- Pertama, soal ini jika disederhanakan akan berbunyi "Cetak jalur dari root ke node $n$". Sudah. Hanya itu. 
<br/>

- Kedua, root selalu bernilai 1, dan sudah ada dari awal. Inputan pertama pada indeks, itu sudah merepresentasikan child dari node root. Itulah alasan kenapa banyaknya node adalah $n-1$, karena node pertama sudah ada dari awal sebagai root. Jika semisal kita memilki inputan seperti ini, maka seperti inilah tree yang terbentuk:

	```bash
	8
	1 1 2 2 3 2 5
	```
	
	![[03-1057A-Bmail Computer Network-1.png]]


<br/>

---
# Jawaban dan Editorial
Soal ini tidak terlalu sulit untuk dipahami, cukup dibutuhkan kemampuan untuk melakukan DFS dan juga backtracking. Pelajari graph dan tree jika belum terlalu mahir menggunakan teknik ini.

## Analisis Pribadi
Berikut adalah jawabanya jika menggunakan kode C++:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-01 21:13
File    : 1057B_Bmail_Computer_Network.cpp
*/

#include <iostream>
#include <vector>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void dfsTrees(bool& found, vector<vector<int>>& vec, int u, int first, int& target, vector<int>& curr) {
   if (found) {
      return;
   }
   curr.push_back(first);
   for (int v : vec[first]) {
      if (v == target) {
         found = true;
         curr.push_back(v);
         return;
      }
      dfsTrees(found, vec, u, v, target, curr);
      if (!found)
         curr.pop_back();
   }
}

auto main() -> int {
   fastio();
   int n;
   cin >> n;
   vector<vector<int>> trees(n);
   for (int i = 1; i < n; i++) {
      int x;
      cin >> x;

      trees[x].push_back(i + 1);
   }

   bool found = false;
   vector<int> rest;
   dfsTrees(found, trees, 1, 1, n, rest);

   for (const auto& x : rest) {
      cout << x << " ";
   }
   return 0;
}
```

Seperti biasa, kita menggunakan adjacency list untuk menampung data inputan, dan langsung membuat susunan treenya.

Disini kita membuat tree dengan ukuran $n$, karena kita ingin menggunakan array 1 based, yang dimulai dari 1, bukan dari 0. Perhatikan juga bahwa kita menggunakan perulangan dimana kita membuat nilai dari increment $i$ dimulai dari 1, bukan nol

Inputan yang kita terima, misal adalah kumpulan index dari $p$, maka $p_i$ merepresentasikan node parentnya, sedangkan index $i$ nya mereprsentasikan node ke-$i$.

Maka, setiap nilai dari $x$, adalah node parent, dari anak-anak berupa node $i+1$. Alasan peanmbahan $i+1$ adalah karena kita menggunakan array 1 based. Setiap parent bisa memiliki banyak anak, tergantung berapa banyak node yang menjadikan node $x$ sebagai nilanya.

<br/>

**Sebelum memanggil Fungsi `dfsTrees`:**

Fungsi DFS akan menjelajah tree untuk mencari keberadaan node dengan indeks $n$. Misal inputan berikut:

```bash
8
1 1 2 2 3 2 5
```

Maka kita perlu mencari path dari root, ke indeks terakhir, yaitu adalah indeks ke 8. Untuk gambar treenya bisa dilihat digambar diatas.

Ada beberapa mekanisme awal supaya DFS kita bekerja dengan baik.

Pertama, jika node target ditemukan lebih awal, maka kita bisa melakukan early-stop, atau menghentikan rekursi segera, sehingga lebih efisien. Untuk mekanisme tersebut, kita menggunakan bantuan bool `found`.

Path yang dicari juga harus disimpan, sehingga hasil akhir dari fungsi DFS adalah menghasilkan path dari root ke node $n$. Kita bisa membuat vector sebagai argumen fungsi.

Berikut adalah contoh kode persiapan pemanggilan fungsi `dfsTrees`:

```cpp
bool found = false;
vector<int> rest;
dfsTrees(found, trees, 1, 1, n, rest);
```

<br/>

**Mekanisme fungsi dfsTrees**:

Sekarang kita analisis fungsi DFS + bakctraking berikut:

```cpp
void dfsTrees(bool& found, vector<vector<int>>& vec, int u, int first, int& target, vector<int>& curr) {
   if (found) {
      return;
   }
   curr.push_back(first);
   for (int v : vec[first]) {
      if (v == target) {
         found = true;
         curr.push_back(v);
         return;
      }
      dfsTrees(found, vec, u, v, target, curr);
      if (!found)
         curr.pop_back();
   }
}
```

Disini kita menggunakakan beberapa parameter:
- bool `found`: berguna untuk mekanisme early-stop ketika node $n$ ditemukan lebih awal. Menghentikan rekursi.
- array dua dimensi `vec`: adjacencly list dari tree berdasarkan inputan yang diberikan.
- int `u`: root node, karena dimulai dari 1, maka kisa bisa beri argumen 1 pada pemanggilan fungsi.
- int `first`: posisi node yang sedang dikunjungi.
- int `target`: yaitu node yang dicari, yaitu $n$.
- vector `curr`: vector yang akan menampung path dari root ke node $n$ ketika ditemukan.

Selama proses rekursi, kita simpan data posisi node yang kita kunjungi kedalam `curr`. Lalu lakukan pemeriksaan DFS, dimana jika nilai dari node sekarang adalah sama dengan `target`, maka artinya node $n$ ditemukan.

Ketika node $n$ ditemukan, maka lakukan push back terakhir ke vector `curr`, rubah bool `found` menjadi true untuk menyalakan mekanisme early-stop, dan hentikan perulangan langsung dengan `return`.

Selama perulangan, kita memanggil fungsi `dfsTrees` secara rekursif, dengan menjadikan nilai dari `v` sebagai argumen fungsi untuk parameter `first`.

Selama proses pencarian, jika semisal DFS sudah mencapai ujung dari tree atau mencapai leaf, maka kita harus mundur kebelakang, menggunakan backtracking. Mekanisme ini dilakukan ketika setelah setiap fungsi `dfsTrees` dipanggil, dan node $n$ tidak ditemukan di jalur yang dikunjungi, maka kita melakukan operasi `pop_back()` pada vector `curr`. Ini memastikan bahwa kita membersihkan jalur yang salah dari vector `curr`, sebelum menimpanya dengan pencarian ke jalur lain. 
