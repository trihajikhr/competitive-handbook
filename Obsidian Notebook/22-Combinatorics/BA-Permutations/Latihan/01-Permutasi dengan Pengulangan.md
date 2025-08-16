---
obsidianUIMode: preview
note_type: latihan
latihan: Permutasi dengan Pengulangan
sumber:
  - myself
tags:
  - combinatorics
date_learned: 2025-08-13T14:37:00
---
---
# Permutasi dengan Faktorial

Diberikan sebuah string $s$, tugasmu adalah menentukan, berapa banyak cara meyusun sebuah urutan tertentu dari string yang diberikan.

**Input:**
Baris pertama terdiri dari $t$ testcase, lalu diikuti sebanyak string $s$ dengan panjang tidak melebihi 17. Ada beberapa string yang acak dan ada yang memiliki banyak karakter sama.

**Output:**
Cetak berapa banyak susunan yang mungkin dari setiap string $s$ yang diberikan!
<br/>

**Contoh:**
Input:

```
5
asdfg
asdfghjh
asdfghjkl
asdfghjklmnbvcxz
makanmakanmakan

```

Output:

```
120
20160
362880
20922789888000
8408400
```


---
# Jawaban

### 1 | Jawaban Pertama

Masih ada beberapa kesalahan, dan perbaikan yang bisa dilakukan:

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto fac(int n) -> long long {
   long long rest = 1;
   for (int i = 1; i <= n; i++) {
      rest *= i;
   }
   return rest;
}

void solve() {
   string s;
   cin >> s;
   long long n = s.length();
   unordered_map<char, long long> dasmap;
   for (char c : s) {
      dasmap[c]++;
   }

   long long rest = 1;
   for (const auto& [key, val] : dasmap) {
      rest *= fac(val);
   }

   cout << fac(n) / rest << '\n';
}

auto main() -> int {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

Kesalahan terjadi ketika aku mendefinisikan optimasi I/O dua kali. Lalu aku membuat kode menjadi kurang efisien, karen fungsi menghitung faktorial yaitu `cac()` dipanggil berkali-kali, yang mana bisa dibuat lebih efisien!
### 2 | Jawaban Kedua

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<long long> factor(16);

void preCompute() {
   int cur = 1;
   for (int i = 1; i <= 15; i++) {
      cur *= i;
      factor[i] = cur;
   }
}

void solve() {
   string s;
   cin >> s;
   int n = s.length();
   unordered_map<char, int> dasmap;
   for (char c : s) {
      dasmap[c]++;
   }

   long long rest = 1;
   for (const auto& [key, val] : dasmap) {
      rest *= factor[val];
   }

   cout << factor[n] / rest << '\n';
}

auto main() -> int {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   preCompute();
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

Jawaban ini sudah cukup baik, karena mengefisiensikan penghitungan faktorial, yang cukup dilakukan sekali, dan sisanya bisa dilakukan dengan cukup $O(1)$.
<br/>

---
# Editorial

**Editorial – Permutasi dengan Pengulangan**

**1. Deskripsi Masalah**
Diberikan string $s$, tentukan jumlah susunan berbeda yang dapat dibentuk dari semua karakter di string tersebut. Karakter dapat berulang.

**2. Analisis**
Permutasi biasa dari $n$ objek berbeda adalah $n!$.
Namun, jika terdapat karakter yang sama, kita harus membagi hasil tersebut dengan faktorial dari jumlah kemunculan tiap karakter, karena pertukaran antar karakter identik tidak menghasilkan susunan baru.

Rumus umum:

$$
\text{Jumlah susunan} = \frac{n!}{\prod_{i=1}^k (f_i!)}
$$

* $n$ = panjang string
* $f_i$ = frekuensi karakter ke-$i$

**3. Pendekatan Solusi**

1. Hitung panjang string $n$.
2. Hitung frekuensi tiap karakter dengan `unordered_map<char, int>`.
3. Gunakan faktorial $n!$ sebagai pembilang.
4. Hitung hasil kali $f_i!$ untuk semua karakter unik sebagai penyebut.
5. Bagi pembilang dengan penyebut untuk mendapatkan hasil akhir.

**4. Optimisasi**

* Faktorial 1–15 dipra-hitungan sekali di awal (`preCompute()`), sehingga tidak perlu menghitung berulang.
* Dengan panjang maksimal ≤ 15, semua perhitungan aman di tipe `long long`.

**5. Kompleksitas Waktu dan Memori**

* Kompleksitas waktu per string: $O(n)$ untuk menghitung frekuensi, dan $O(k)$ untuk perkalian penyebut (k ≤ jumlah karakter unik).
* Kompleksitas memori: $O(k)$ untuk menyimpan frekuensi.

**6. Contoh**
Input: `"AAB"`

* $n = 3$, frekuensi: A=2, B=1
* Rumus: $\frac{3!}{2! \cdot 1!} = \frac{6}{2} = 3$
  Susunan: `AAB`, `ABA`, `BAA`.
