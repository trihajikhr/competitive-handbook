---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1821A
judul_STRIKE: Matching
teori_STRIKE: 
sumber:
  - codeforces
ada_tips?: 
date_learned: 2025-08-14T06:44:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1821A - Codeforces](https://codeforces.com/problemset/problem/1821/A)

```ad-tip
title:⚔️ Teori STRIKE

```

<br/>

---
# 1 | Matching

**Template bilangan bulat** adalah sebuah string yang terdiri dari digit dan/atau tanda tanya (`?`).

Sebuah bilangan bulat positif (lebih besar dari 0) **cocok** dengan template bilangan bulat jika memungkinkan untuk mengganti setiap tanda tanya pada template tersebut dengan sebuah digit sedemikian rupa sehingga kita mendapatkan representasi desimal dari bilangan tersebut **tanpa nol di depan** (leading zero).

**Contoh:**

* `42` cocok dengan `4?`
* `1337` cocok dengan `????`
* `1337` cocok dengan `1?3?`
* `1337` cocok dengan `1337`
* `3` **tidak** cocok dengan `??`
* `8` **tidak** cocok dengan `???8`
* `1337` **tidak** cocok dengan `1?7`

Kamu diberikan sebuah template bilangan bulat yang panjangnya **maksimal 5 karakter**.
Hitung jumlah bilangan bulat positif (lebih besar dari 0) yang cocok dengan template tersebut.


#### Input:
Baris pertama berisi sebuah bilangan bulat `t` (1 ≤ t ≤ 20 000) — banyaknya *test case*.

Setiap *test case* terdiri dari satu baris berisi string `s` (1 ≤ |s| ≤ 5) yang terdiri dari digit dan/atau tanda tanya (`?`) — template bilangan bulat untuk *test case* tersebut.

#### Output:
Untuk setiap *test case*, cetak sebuah bilangan bulat — jumlah bilangan bulat positif (lebih besar dari 0) yang cocok dengan template tersebut.
<br/>

---
# 2 | Sesi STRIKE ⚔️

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Dalam sebuah bilangan bulat positif, digit pertama berada di antara 1 sampai 9, dan setiap digit berikutnya bisa berupa digit apa saja. Hal ini memungkinkan kita untuk menerapkan pendekatan kombinatorial berikut:

1. Hitung jumlah kemungkinan nilai untuk digit pertama:

   * **0** jika karakter pertama dari `s` adalah `0`
   * **1** jika karakter pertama dari `s` adalah digit selain `0`
   * **9** jika karakter pertama dari `s` adalah `?`

2. Hitung jumlah kemungkinan nilai untuk setiap digit lainnya:

   * **1** jika karakter tersebut adalah digit
   * **10** jika karakter tersebut adalah `?`

3. Kalikan semua nilai kemungkinan tersebut.

Implementasi:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		string s;
		cin >> s;
		int ans = 1;
		if(s[0] == '0') ans = 0;
		if(s[0] == '?') ans = 9;
		for(int j = 1; j < s.size(); j++)
			if(s[j] == '?')
				ans *= 10;
		cout << ans << endl;
	}
}
```
## 3.2 | Analisis Pribadi

Ini soal yang lumayan mudah, kita cukup menghitung banyaknya kombinasi angka-angka yang mungkin dari banyaknya karakter `?` yang ada pada digit berjumlah paling banyak 5.

Soal menjelaskan bahwa digit terebut haruslah angka bulat non negatif, atau diatas nol. Jadi, pemeriksaan pertama adalah mengecek apakah karakter pertama dalam digit adalah `0`. Jika iya, maka outputkan 0, karena tidak ada kombinasi digit yang mungkin yang melebihi angka 0 jika karakter pertamanya saja sudah aneh, yaitu `0`.

Jika semisal tidak ada tanda tanya pada digit, artinya tidak ada kombinasi yang harus diisi, sehingga output langsung yaitu 1.

Tapi jika ada tanda tanya pada digit, maka kita baru melakukan operasi pencarian kombinasi.

Setiap slot digit dapat disi dengan 10 karakter, berupa angka 0-9, kecuali untuk karakter pertama, yang hanya bisa diisi dengan 9 karakter yang mungkin yaitu 1-9. Ini artinya, kita cukup mengalikan nilai kombinasi dengan 9 jika tanda tanya ada didigit pertama, dan mengalikanya dengan 10 jika berada di posisi lain selain digit pertama.

Berikut implementasinya:

```cpp
/*
Author  : Riveris
Date    : 2025-08-13 00:49
Problem : Codeforces - 1821A | Matching
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void solve() {
   string s;
   cin >> s;
   if (s[0] == '0') {
      cout << 0 << '\n';
      return;
   }

   bool pass = true;
   for (char c : s) {
      if (c == '?') {
         pass = false;
         break;
      }
   }

   if (pass) {
      cout << 1 << '\n';
      return;
   }

   int rest = 1;
   for (int i = 0; i < s.length(); i++) {
      if (i == 0 && s[i] == '?') {
         rest *= 9;
         continue;
      }

      if (s[i] == '?') {
         rest *= 10;
      }
   }

   cout << rest << '\n';
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```



