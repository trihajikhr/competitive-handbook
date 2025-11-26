---
obsidianUIMode: preview
note_type: latihan
latihan: No-Adjacent Vowels
sumber:
  - chatgpt.com
tags:
  - combinatorics
date_learned: 2025-08-13T15:57:00
---
---
# No-Adjacent Vowels

Diberikan string huruf kapital Inggris `s` (A–Z). Hitung banyaknya susunan **berbeda** dari seluruh karakter `s` sehingga **tidak ada dua huruf vokal yang bersebelahan**. Huruf vokal: `A, E, I, O, U`. Karakter identik dianggap tak terbedakan. Jika tak mungkin, hasilnya `0`.

**Input**:
Baris pertama sebuah bilangan bulat `t` — banyak test case.  
Setiap test case berisi satu string `s`.

**Output**:
Untuk setiap test case, cetak satu baris berisi jumlah susunan yang memenuhi.

**Batasan**:

- `1 ≤ t ≤ 10^5`
- `1 ≤ |s| ≤ 17`
- `s` hanya berisi `A–Z`
- Jawaban muat di 64-bit signed integer
#### Contoh

Input

```
5
AABC
BANANA
MATHEMATICS
XYZ
BOOKKEEPER
```

Output

```
6
12
1058400
6
3600
```

> Catatan ide solusi: Susun dulu semua konsonan (permutasi dengan pengulangan), sediakan `K+1` slot di sela-selanya, lalu tempatkan vokal (multiset) maksimal satu per slot. Jumlah cara = (susunan konsonan) × (pilih & tata slot untuk vokal).

<br/>

---
# Jawaban

### 1 | Jawaban Pertama

Berikut adalah jawaban pertama yang masih terdapat beberapa kesalahan, namun tidak terlalu fatal:

```cpp
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<long long> factor(18);

void preCompute() {
   factor[0] = 0;
   long long curr = 1;
   for (int i = 1; i <= 17; i++) {
      curr *= i;
      factor[i] = curr;
   }
}

auto isVowels(char c) -> bool {
   if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
      return true;
   }

   return false;
}

auto combination(int n, int k) -> long long { return (factor[n] / factor[k]) / factor[n - k]; }

auto permut(int n, int r) -> long long { return factor[n] / factor[n - r]; }

void solve() {
   string s;
   cin >> s;
   int C = 0, V = 0;

   unordered_map<char, int> dasmap;

   for (char& c : s) {
      c = tolower(c);
      dasmap[c]++;
      if (isVowels(c))
         V++;
      else
         C++;
   }

   if (V >= C + 1) {
      cout << 0 << '\n';
      return;
   }

   long long con = 1;
   long long voc = 1;
   for (const auto& [key, val] : dasmap) {
      if (isVowels(key)) {
         voc *= factor[val];
      } else {
         con *= factor[val];
      }
   }

   if (V == 0) {
      cout << (factor[C] / con) << '\n';
      return;
   }

   long long rest = (factor[C] / con) * combination(C + 1, V) * (factor[V] / voc);
   cout << rest << '\n';
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

Beberapa kesalahan:
- Aku mendefinisikan fungsi `permut()` tetapi tidak digunakan.
- Aku menginisialisasi nilai `factor[0] = 0`, padahal hasil dari faktorial $0!$ adalah 1.

### 2 | Jawaban Kedua

Ini adalah jawaban yang lebih baik daripada jawaban sebelumnya:

```cpp
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<long long> factor(18);

void preCompute() {
   factor[0] = 1;
   long long curr = 1;
   for (int i = 1; i <= 17; i++) {
      curr *= i;
      factor[i] = curr;
   }
}

auto isVowels(char c) -> bool {
   if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
      return true;
   }

   return false;
}

auto combination(int n, int k) -> long long { return (factor[n] / factor[k]) / factor[n - k]; }

void solve() {
   string s;
   cin >> s;
   int C = 0, V = 0;

   unordered_map<char, int> dasmap;

   for (char& c : s) {
      c = tolower(c);
      dasmap[c]++;
      if (isVowels(c))
         V++;
      else
         C++;
   }

   if (V >= C + 1) {
      cout << 0 << '\n';
      return;
   }

   long long con = 1;
   long long voc = 1;
   for (const auto& [key, val] : dasmap) {
      if (isVowels(key)) {
         voc *= factor[val];
      } else {
         con *= factor[val];
      }
   }

   long long rest = (factor[C] / con) * combination(C + 1, V) * (factor[V] / voc);
   cout << rest << '\n';
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

<br/>

---
# Editorial

Misal:

* $V$ = multiset huruf vokal dalam string
* $C$ = multiset huruf konsonan dalam string
* $|V| = v$ dan $|C| = c$

### Langkah 1 – Susun konsonan

Jumlah cara susun konsonan:

$$
\text{waysC} = \frac{c!}{\prod_{x \in C} f_x!}
$$

### Langkah 2 – Tentukan slot untuk vokal

Setelah konsonan disusun, ada $c+1$ slot kosong (termasuk ujung kiri & kanan).
Kita pilih $v$ slot untuk menaruh vokal, satu vokal per slot:

$$
\text{waysSlots} = \binom{c+1}{v}
$$

Jika $v > c+1$, jawabannya 0.

### Langkah 3 – Susun vokal di slot terpilih

Jumlah cara susun vokal:

$$
\text{waysV} = \frac{v!}{\prod_{y \in V} f_y!}
$$

### Langkah 4 – Hasil akhir

$$
\text{jawaban} =
\begin{cases}
\text{waysC} \times \text{waysSlots} \times \text{waysV}, & v \le c+1 \\
0, & \text{lainnya}
\end{cases}
$$

