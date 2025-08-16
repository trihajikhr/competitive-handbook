---
obsidianUIMode: preview
note_type: latihan
latihan: 1899A - Game with Integers
sumber:
  - codeforces
tags:
  - game-theory
date_learned: 2025-08-08T17:11:00
---
---
# 1899A - Game with Integers


Vanya dan Vova sedang bermain sebuah permainan. Para pemain diberikan sebuah bilangan bulat $n$. Pada gilirannya, seorang pemain bisa **menambahkan 1** ke bilangan saat ini atau menguranginya 1.  

Permainan berlangsung secara bergantian; Vanya memulai terlebih dahulu.

Jika setelah giliran Vanya bilangan tersebut habis dibagi 3, maka Vanya menang.  
Jika 10 giliran sudah berlalu dan Vanya belum menang, maka Vova menang.

Buatlah program yang, berdasarkan nilai $n$, menentukan siapa yang akan menang jika kedua pemain bermain secara optimal.

<br/>

---
# Jawaban

Berikut adalah jawaban yang sudah benar:

```cpp
/*
Author  : trihajikhr
Date    : 2025-08-08 00:56
Problem : Codeforces - 1899A | Game With Integers
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      if (n % 3 == 0) {
         cout << "Second";
      } else
         cout << "First";

      cout << '\n';
   }
}
```

<br/>

---
# Editorial

Jika saat pertama kali main Vanya berada di angka yang bisa dibagi habis dengan 3, maka Vanya akan kalah. Karena, dia hanya akan menang jika dia melakukan gerakan ke angka yang habis dibagi dengan angka 3, bukan baru dimulai. Nah, ketika dia bergerak naik atau turun, lawanya Vova akan menceganhanya, dengan cara mengembalikan angka ke nilai semula. Hal ini terjadi terus menerus, hingga 10 langkah berlalu, dan Vova lah yang menang.

Namun, jika angka $n$ tidak bisa dibagi 3, misal 2, atau 1, Vanya pasti menang, karena dia bisa bergerak naik atau turun, dan mendapatkan angka yang habis dibagi dengan 3.

Jadi, jika $n$ habis dibagi 3, Vova akan mengunci kemenangan. Sedangkan jika tidak, maka Vasya bisa membekuk Vova dalam satu kali gerakan, dan menang. 