---
obsidianUIMode: preview
note_type: latihan
latihan: Adjacent Vowels
sumber:
  - chatgpt.com
tags:
  - combinatorics
date_learned: 2025-08-13T17:00:00
---
---
# Adjacent Vowels

Diberikan string `S` (panjang ≤ 17, huruf kecil saja). Hitung jumlah **susunan berbeda** dari seluruh karakter `S` jika **vokal boleh berdampingan** dan huruf yang sama dianggap identik.

**Contoh:**

```
Input:
3
abc
aab
aei

Output:
6
3
6
```

**Keterangan:**

- `abc` → semua permutasi 3 huruf berbeda = `3! = 6`.
- `aab` → huruf 'a' kembar, total = `3!/2! = 3`.
- `aei` → semua vokal, total = `3! = 6`.

<br/>

---
# Jawaban

Ini adalah jawaban yang sudah benar:

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

void solve() {
   string s;
   cin >> s;
   unordered_map<char, int> dasmap;

   for (char& c : s) {
      c = tolower(c);
      dasmap[c]++;
   }

   long long temp = 1;
   for (const auto& [key, val] : dasmap) {
      temp *= factor[val];
   }

   cout << factor[s.length()] / temp << '\n';
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

**Editorial Singkat – Permutasi Multiset**

Jika suatu kata memiliki huruf yang berulang, kita tidak bisa memakai rumus permutasi biasa $n!$ karena setiap pengulangan membuat susunan menjadi tidak unik.

Rumus **permutasi multiset**:

$$
\text{Jumlah Susunan Unik} = \frac{n!}{k_1! \times k_2! \times \dots \times k_m!}
$$

* $n$ = total huruf.
* $k_i$ = jumlah kemunculan huruf ke-i.

**Langkah:**

1. Hitung $n$ = panjang string.
2. Hitung frekuensi tiap huruf.
3. Bagi $n!$ dengan perkalian semua $k_i!$.

Contoh: **MISSISSIPPI**

$$
\frac{11!}{1! \times 4! \times 4! \times 2!} = 34650
$$

Atau bisa dikatakan, baik itu huruf vokal atau bukan, tidak perlu dipikirkan, karena semuanya toh boleh terletak dimana saja.