---
obsidianUIMode: preview
note_type: latihan
latihan: Range Addition (Prefix Technique)
sumber:
  - chatgpt.com
tags:
  - vector
  - data-structure
date_learned: 2025-08-26T14:57:00
---
---
# 1 | Range Addition (Prefix Technique)

Diberikan array `A` berisi `N` elemen awal `0`.
Ada `Q` update berupa `(L, R, X)` → tambahkan `X` ke semua elemen `A[L..R]`.

Tugas: setelah semua update, cetak array akhir.

**Contoh Input:**

```
N = 5, Q = 3
Updates:
1 3 5   // add 5 to A[1],A[2],A[3]
2 4 2   // add 2 to A[2],A[3],A[4]
0 1 3   // add 3 to A[0],A[1]
```

**Proses:**

Langkah-langkah:

1. Start `[0 0 0 0 0]`
2. After `(1,3,5)` → `[0 5 5 5 0]`
3. After `(2,4,2)` → `[0 5 7 7 2]`
4. After `(0,1,3)` → `[3 8 7 7 2]`

**Output:**

```
3 8 7 7 2
```

---

💡 Hint Optimal (Prefix Technique / Difference Array):

1. Buat `vector<int> diff(N+1,0)`
2. Untuk update `(L,R,X)`:

   ```cpp
   diff[L] += X;
   if (R+1 < N) diff[R+1] -= X;
   ```
3. Setelah semua update, lakukan prefix sum untuk dapat array akhir:

   ```cpp
   for (int i = 0; i < N; i++) {
       if (i>0) diff[i] += diff[i-1];
   }
   ```

* Kompleksitas: O(N + Q)
* Memory: O(N)

<br/>

---
# 2 | Jawaban

## 2.1 | Kompleksitas O(QK)

Ini adalah jawaban pertamaku, namun ternyata masih bisa ditingkatkan lagi:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n = 0;
   int q = 0;
   cin >> n >> q;
   vector<int> data(n, 0);

   while ((q--) != 0) {
      int a, b, c;  // NOLINT
      cin >> a >> b >> c;

      for (int i = a; i <= b; i++) {
         data[i] += c;
      }
   }

   for (const auto& x : data) {
      cout << x << " ";
   }
   return 0;
}
```

## 2.2 | Kompleksitas O(Q+K)

Cara ini menyimpan hasil perbedaan atau selisih, sehingga kompleksitasnya menjadi jauh lebih efisien:

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n = 0;
   int q = 0;
   cin >> n >> q;
   vector<int> data(n, 0);
   vector<int> diff(n + 1, 0);

   while ((q--) != 0) {
      int a, b, c;  // NOLINT
      cin >> a >> b >> c;

      diff[a] += c;
      if (b + 1 < n) {
         diff[b + 1] -= c;
      }
   }

   data[0] = diff[0];
   for (int i = 1; i < n; i++) {
      data[i] = data[i - 1] + diff[i];
   }

   for (const auto& x : data) {
      cout << x << " ";
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial


Program ini bekerja dengan prinsip menyimpan informasi perubahan secara efisien. Pada awalnya, setiap posisi di set memiliki nilai nol. Ketika sebuah operasi dimasukkan, tujuannya adalah menambahkan nilai tertentu ke semua posisi dalam sebuah rentang berurutan. Jika program langsung menambahkan nilai ke setiap posisi dalam rentang untuk setiap operasi, hal itu akan memakan banyak waktu, terutama jika jumlah posisi atau operasi besar. 

Untuk mengatasi hal ini, program tidak menulis nilai baru langsung ke setiap posisi, melainkan mencatat efek dari operasi tersebut di titik awal dan titik setelah akhir rentang. Setelah semua operasi dimasukkan, program memproses posisi demi posisi dari awal sampai akhir. Saat bergerak maju, program menjumlahkan semua efek penambahan yang berlaku pada posisi itu, sehingga setiap posisi akhirnya menerima semua kontribusi dari operasi yang mempengaruhinya. 

Dengan pendekatan ini, program tetap menghasilkan nilai akhir yang sama seperti jika semua operasi dilakukan satu per satu, namun jauh lebih efisien karena tidak melakukan pengulangan pekerjaan yang sama, dan kompleksitas waktu total menjadi linear terhadap jumlah posisi dan jumlah operasi.

