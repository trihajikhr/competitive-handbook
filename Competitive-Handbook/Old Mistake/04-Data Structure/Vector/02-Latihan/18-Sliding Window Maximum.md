---
obsidianUIMode: preview
note_type: latihan
latihan: Sliding Window Maximum
sumber:
  - chatgpt.com
tags:
  - vector
  - data-structure
date_learned: 2025-08-26T14:30:00
---
---
# 1 | Sliding Window Maximum (Vector Only)

Diberikan array `A` dengan `N` elemen dan sebuah integer `K`.  
Tugas: untuk setiap jendela sepanjang `K`, cetak **nilai maksimum** di jendela itu.

**Contoh Input:**

```
N = 8, K = 3
A = [1, 3, -1, -3, 5, 3, 6, 7]
```

**Output:**

```
3 3 5 5 6 7
```

**Constraints:**

- Gunakan hanya `vector`, jangan `deque` atau struktur STL lain.
    
- Waktu optimal: O(NK) untuk implementasi sederhana, O(N) untuk versi optimal.

💡 Hint Strategi (Vector Only):

- Naive O(NK): untuk tiap jendela `[i, i+K-1]`, loop lagi untuk cari maksimum.
    
- Optimized O(N): simpan index maksimum sebelumnya. Jika elemen maksimum keluar jendela, cari maksimum baru dari sisa elemen.
    
- Bisa juga maintain stack atau vector monotonic untuk track maksimum.
    

<br/>

---
# 2 | Jawaban

Berikut adalah jawabannya, namun kompleksitas dari algoritma ini adalah $O(NK)$. Kompleksitas dari algoritma ini sebenarnya bisa dibuat lebih efisien hingga $O(N)$, jika semisal menggunakan struktur data seperti deque:

```cpp
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n = 0;
   int k = 0;
   cin >> n >> k;

   vector<int> data(n);
   for (auto& x : data) {
      cin >> x;
   }

   vector<int> rest;
   int maks = INT_MIN;

   int idxCurr = -1;
   for (int i = 0; i < k; i++) {
      if (maks < data[i]) {
         maks = data[i];
         idxCurr = i;
      }
   }

   rest.push_back(maks);
   int l = 0;
   int r = k - 1;

   while (r != (n - 1)) {
      l++;
      r++;
      if (data[r] > maks) {
         idxCurr = r;
         maks = data[r];
         rest.push_back(data[r]);
      } else {
         if (idxCurr >= l) {
            rest.push_back(maks);
            continue;
         }
         maks = INT_MIN;
         for (int i = l; i <= r; i++) {
            maks = max(maks, data[i]);
         }

         rest.push_back(maks);
      }
   }

   for (const auto& x : rest) {
      cout << x << " ";
   }

   return 0;
}
```

<br/>

---
# 3 | Editorial

Disini, tantangan sebenarnya dari menggunakan algoritma sliding windows yang efisien ketika yang digunakan bukanlah deque, melainkan vector, adalah dengan tetap membuatnya seefisien mungkin.

Langkah awal adalah menerima besaran ukuran dari vector, dan juga lebar ukuran window, yang ditampung dalam variabel $n$ dan juga variabel $k$.

Setelah itu, terima sebanyak $n$ elemen vector.

Deklarasikan juga vector yang digunakan untuk menampung hasil dari operasi sliding windows.

Nah, pertama-tama, kita cari dulu elemen terbesar dan lokasi elemen terbesar pada jendela pertama, yang masih terletak di bagian paling kiri. Ini adalah titik start sliding windows pada soal kali ini, dimana belum dilakukan pergeseran sama sekali.

Setelah itu, kita aku membuat perulangan while, dengan bantuan berupa 2 pointer yang akan menunjuk indeks batas kiri $l$ dan batas kanan $r$ window. Jika semisal ketika dilakukan pergeseran ke kanan, didapati nilai yang lebih besar dari maks, maka kita perbarui nilai maks, dan tambahkan hasilnya ke vector hasil.

Tapi jika tidak, maka kita akan memasukan nilai maks sebelumnya yang kita dapat, asalkan lokasinya masih didalam jendela. Mekanisme ini dilakukan dengan menggunakan bantuan variabel $idxCurr$, dimana variabel ini akan bertanggung jawab menyimpan indeks elemen-elemen terbesar.

Jika lokasi elemen terbesar sudah keluar dari jendela, maka kita harus mencari kandidat elemen terbesar yang baru didalam window. Lakukan perulangan yang dimulai dari $l$ hingga $r$, dapatkan nilai maks yang baru, dan simpan lagi indeksnya.

