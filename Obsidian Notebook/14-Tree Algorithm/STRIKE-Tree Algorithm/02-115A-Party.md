---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 115C
judul_FAST: Party
teori_FAST: Membuat tree dengan banyak anak sekaligus, tanpa perlu membuat struct atau class.
sumber:
  - codeforces
date_learned: 2025-08-01T20:19:00
tags:
  - tree-algorithm
  - STRIKE
---
Sumber: [Problem - A - Codeforces](https://codeforces.com/contest/115/problem/A)

> [!NOTE] ⚔️ Teori FAST:
> Jika biasanya kita membuat tree dengan kerangka dasar dari class atau struct, kali ini kita bisa membuat tree, dengan pendekatan yang mirip seperti membuat graph, yaitu graph berarah. Pendekatan ini membuat jumlah child dari suatu node menjadi tidak terbatas!
> 
> Pendekatan ini lebih efisien jika kita ingin membuat node pada tree yang mampu memiliki jumlah anak yang dinamis, tidak kaku karena harus menyesuaikan diri pada structur class atau struct yang dibuat!

<br/>

---
# 115A - Party

**Batas waktu per pengujian:** 3 detik  
**Batas memori per pengujian:** 256 megabyte

Sebuah perusahaan memiliki `n` karyawan yang diberi nomor dari 1 sampai `n`. Setiap karyawan memiliki tidak ada manajer langsung atau tepat satu manajer langsung, yang merupakan karyawan lain dengan nomor berbeda.  

Seorang karyawan `A` dikatakan lebih tinggi jabatannya (superior) dari karyawan `B` jika salah satu dari kondisi berikut benar:

- Karyawan `A` adalah manajer langsung dari karyawan `B`
    
- Karyawan `B` memiliki manajer langsung `C` dan karyawan `A` adalah atasan dari karyawan `C`
    

Perusahaan ini tidak memiliki siklus manajerial. Artinya, tidak akan ada karyawan yang menjadi atasan dari manajer langsungnya sendiri.

Hari ini, perusahaan akan mengadakan pesta. Ini melibatkan membagi semua `n` karyawan menjadi beberapa grup: setiap karyawan harus berada di tepat satu grup. Selain itu, dalam satu grup tidak boleh ada dua karyawan `A` dan `B` di mana `A` adalah atasan dari `B`.

**Pertanyaannya:**  
Berapa jumlah minimum grup yang harus dibentuk?
### Input:

- Baris pertama berisi satu bilangan bulat `n` (`1 ≤ n ≤ 2000`) — jumlah karyawan.
    
- `n` baris berikutnya berisi integer `pᵢ` (`1 ≤ pᵢ ≤ n` atau `pᵢ = -1`). Setiap `pᵢ` menunjukkan manajer langsung dari karyawan ke-`i`.
    
    - Jika `pᵢ = -1`, artinya karyawan ke-`i` **tidak memiliki manajer langsung**.
        

Dijamin bahwa:

- Tidak ada karyawan yang menjadi manajer dirinya sendiri (`pᵢ ≠ i`)
    
- Tidak ada siklus manajerial

### Output:

Cetak satu bilangan bulat yang menunjukkan jumlah **minimum grup** yang harus dibentuk dalam pesta tersebut.

<br/>

---

# Sesi FAST ⚔️

- Aku belajar untuk membuat tree, dengan bantuan structur class atau struct, namun kali ini jumlah child dari setiap node tidak ditentukan, dan tidak dibatasi. Pendekatan membuat tree dengan class atau struct tidak tepat digunakan disini. Pendekatan yang paling tepat adalah memperlakukan tree sebagai graph berarah, sehingga dibutuhkan array 2 dimensi, dengan perlakukan seperti pada adjaceny list.
<br/>

- Jawaban adalah tinggi dari tree yang terbuat. Jadi cukup hitung berapa kedalaman atau tinggi tree, dan itulah jawabanya.

<br/>

---

# Jawaban dan Editorial


Kita sebut seorang karyawan yang tidak memiliki manajer sebagai akar (root). Terdapat sebuah sisi (edge) dari manajer ke karyawan yang dia pimpin.

Pertama, perhatikan bahwa graf ini merupakan kumpulan pohon terarah (directed trees). Maka, kita bisa menetapkan label kedalaman (depth) pada setiap simpul—menunjukkan jumlah simpul di jalur sederhana dari root ke simpul tersebut. Jawabannya adalah kedalaman maksimum yang dimiliki suatu simpul.

Mengapa demikian?

Pertama, jawaban pasti minimal sebesar nilai ini, karena setiap pasangan karyawan dalam jalur tersebut tidak bisa berada dalam grup yang sama. Kedua, karena graf berupa pohon, setiap simpul hanya memiliki satu label kedalaman yang unik.  

Maka, cukup kelompokkan semua simpul dengan kedalaman yang sama ke dalam grup yang sama.  

Jelas bahwa tidak akan ada atasan dalam grup yang sama, karena jika iya, maka kedalaman mereka pasti berbeda.

**Catatan tambahan:**

Kamu mungkin menyadari bahwa terdapat implementasi dengan kompleksitas O(N) untuk algoritma ini. Namun, karena batasannya hanya 2000, hal ini masih cukup. Masalah ini sebenarnya dipindah dari posisi D1-B karena soal D1-A sebelumnya dianggap terlalu sulit. Selama proses itu, batasan nilai `N` juga diturunkan dari 200.000 ke 2.000. Semoga kamu menikmatinya :)

## Analisis Pribadi

Dengan bahasa C++, maka jawabanya akan seperti ini:

```cpp

/*
Author  : trihajikhr
Date    : 2025-08-01 17:52
File    : 115A_Party.cpp
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

int maxDepth = 0;

void dfs(const vector<vector<int>>& vec, int u, int depth) {
   maxDepth = max(maxDepth, depth);
   for (int v : vec[u]) {
      dfs(vec, v, depth + 1);
   }
}

auto main() -> int {
   fastio();
   int n;
   cin >> n;

   vector<vector<int>> vec(n + 1);
   vector<int> roots;

   for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x == -1) {
         roots.push_back(i);
      } else {
         vec[x].push_back(i);  // x is manager of i
      }
   }

   for (int root : roots) {
      dfs(vec, root, 1);
   }

   cout << maxDepth << "\n";
   return 0;
}
```

Baiklah, kita bedah jawaban diatas.

Dijelaskan bahwa ketika seorang karyawan yang memiliki nilai $a_i$ yaitu $-1$, maka karyawan tersebut tidak memiliki manajer langsung, ini bisa diasumsikan bahwa ketika ada karyawan yang memiliki value $-1$, maka dia membuat tree baru.

Karena kondisi ini, maka kita perlu mencatat berapa banyak, dan siapa saja karyawan yang menjadi root dari setiap tree yang berbeda-beda. 

Jika nilai dari $a_i$ bukan $-1$, maka karyawan tersebut adalah child, dan memiliki parent yaitu si node $a_i$. Maka kita tampung koneksi atau edge yang terbentuk, dengan menggunakan adjacency list. Jika sudah pernah belajar tentang teori graph, seharusnya cara ini tidaklah terlalu sulit.

Setelah itu, kita lakukan penelusuran untuk setiap tree yang terbentuk, mana tree yang punya level atau kedalaman tertinggi, maka itulah jawabanya. Maka kita perlu melakukan pendekatan *depth-first-search* sebagai berikut:

Pemanggil fungsi:

```cpp
for (int root : roots) {
  dfs(vec, root, 1);
}
```

Fungsinya:

```cpp
void dfs(const vector<vector<int>>& vec, int u, int depth) {
   maxDepth = max(maxDepth, depth);
   for (int v : vec[u]) {
      dfs(vec, v, depth + 1);
   }
}
```

Nilai dari $u$, dimulai dari node root dari setiap, yaitu posisi 1. Lalu kedalaman awalnya adalah satu, karena node root dihitung sebagai level atau kedalaman pertama.

Variabel global `maxDepth` digunakan untuk menampung kedalaman tertinggi dari setiap tree yang di DFS. Setelah itu, maka jawaban akan tertampung di variabel `maxDepth`, dan kita outputkan hasilnya.