---
obsidianUIMode: preview
note_type: latihan
judul_problem: Climbing Stairs
latihan: dynamic programming bottom-up
sumber:
  - myself
tags:
  - dynamic-programming
date_learned: 2026-07-20T02:38:00
---
Link Sumber: 

---
> [!IMPORTANT]
# Climbing Stairs

Ada sebuah tangga, dimana kamu ingin menaiki tangga tersebut hingga anak tangga ke $n$. Untuk setiap gerakan, kamu bisa bergerak $1$ atau $2$ anak tangga sekaligus. Tentukan berapa banyak kombinasi gerakan yang bisa diambil untuk sampai ke anak tangga ke $n$.

**Constrainst:**
- $n \ge 2$

<br/>

---
## Editorial

Problem ini merupakan salah satu contoh klasik untuk memahami *Dynamic Programming*. Ide utamanya adalah menghitung jumlah cara mencapai setiap anak tangga, kemudian menggunakan hasil tersebut untuk membangun solusi berikutnya.

Misalkan $dp[i]$ menyatakan banyaknya cara untuk mencapai anak tangga ke-$i$. Untuk mencapai tangga ke-$i$, terdapat dua kemungkinan terakhir:

1. Berasal dari tangga ke $i-1$ dengan mengambil satu langkah.    
2. Berasal dari tangga ke $i-2$ dengan mengambil dua langkah.

Maka relasi transisinya adalah:

$$  
dp[i]=dp[i-1]+dp[i-2]  
$$

Sebelum melakukan iterasi, kita perlu menentukan *base case*. Terdapat satu cara untuk berada di posisi awal (belum menaiki tangga), yaitu $dp[0]=1$. Untuk anak tangga pertama dibutuhkan  $dp[1]=1$, karena untuk mencapai anak tangga pertama, hanya ada satu cara, yaitu mengambil satu langkah. Lalu tetapkan juga $dp[2]=2$, karena untuk mencapai tangga kedua, terdapat dua cara:

- 1 + 1 langkah
- 2 langkah

Setelah base case ditentukan, kita dapat menghitung nilai berikutnya secara *bottom-up*:

$$  
dp[i]=dp[i-1]+dp[i-2]  
$$

Dengan begitu, setiap submasalah hanya dihitung satu kali.

Kompleksitas:

- Waktu: $O(n)$
- Memori: $O(n)$

<br/>

---
## Jawaban

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];
    return 0;
}
```