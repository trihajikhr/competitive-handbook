---
obsidianUIMode: preview
note_type: latihan
latihan: Rotasi Matriks
sumber:
  - chatgpt.com
tags:
  - vector
  - data-structure
date_learned: 2025-08-25T20:29:00
---
---
# 1 | Rotasi Matriks

Kamu punya matriks `N×N` (disimpan dengan `vector<vector<int>>`). Lakukan rotasi searah jarum jam sebanyak `K` kali. Satu rotasi = rotasi 90° searah jarum jam.

**Contoh Input**

```
N = 3
Matrix =
1 2 3
4 5 6
7 8 9
K = 1
```

**Output**

```
7 4 1
8 5 2
9 6 3
```

Jika `K=2`, hasilnya:

```
9 8 7
6 5 4
3 2 1
```


👉 Hint Editorial:

- Rotasi 90° searah jarum jam = **transpose** + **reverse setiap baris**.
- Karena `K` bisa > 4, gunakan `K % 4`.
- Gunakan `vector<vector<int>>` agar fleksibel.
<br/>

---
# 2 | Jawaban

Berikut adalah jawaban yang sudah benar, dan aku juga baru saja menemukan bahwa ternyata metode ini mungkin untuk dilakukan:

```cpp
#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
using namespace std;

using VVI = vector<vector<int>>;

class Solve {
  public:
   static void rotate(VVI& mat) {
      for (int i = 0; i < (int)mat.size(); i++) {
         for (int j = i + 1; j < (int)mat.size(); j++) {
            swap(mat[i][j], mat[j][i]);
         }
      }

      for (auto& row : mat) {
         std::ranges::reverse(row);
      }
   }
};

auto main() -> int {
   int n = 0;
   cin >> n;
   vector<vector<int>> mat(n, vector<int>(n));
   for (auto& row : mat) {
      for (auto& x : row) {
         cin >> x;
      }
   }

   int k = 0;
   cin >> k;
   k %= 4;

   for (int i = 0; i < k; i++) {
      Solve::rotate(mat);
   }

   for (const auto& row : mat) {
      for (auto x : row) {
         cout << x << " ";
      }
      cout << '\n';
   }
   return 0;
}
```

<br/>

---
# 3 | Editorial

Untuk matriks yang dengan bentuk kotak, yaitu berupa $N \times N$, maka cara yang efisien untuk dilakukan adalah dengan melakukan transpose matriks, lalu mereverse setiap baris pada matriks. Hal itu cukup dilakukan dengan melakukan `swap()`, kemudian melakukan `reverse()`. Operasi ini efisien karena tidak menggunakan memory tambahan.

Sedangkan untuk kasus matriks dengan ukuran $N \times M$, dimana $N \neq M$, maka kita perlu membuat vector baru, dengan ukuran $M \times N$, lalu melakukan pemindahan dari matriks asli ke matriks bantu. Lalu setelah pemindahan selesai, kembalikan lagi nilai dari matriks bantu ke matriks asli, berikut adalah gambaranya:

```cpp
int n = mat.size(), m = mat[0].size();
VVI newMat(m, vector<int>(n));
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        newMat[j][n - i - 1] = mat[i][j];
mat = newMat;
```