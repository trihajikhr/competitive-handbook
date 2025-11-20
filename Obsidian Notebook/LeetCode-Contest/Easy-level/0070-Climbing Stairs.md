---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-70
judul_DEATH: Climbing Stairs
teori_DEATH: dynamic programming basic
sumber:
  - leetcode.com
rating: 1
ada_tips: true
date_learned: 2025-11-20T22:02:00
tags:
  - math
  - dynamic-programming
  - memoization
---
Sumber: [Climbing Stairs - LeetCode](https://leetcode.com/problems/climbing-stairs/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Climbing Stairs

Kamu sedang menaiki tangga. Dibutuhkan $n$ langkah untuk merain puncah. Setiap langkah, kamu memilki 2 pilihan untuk melangkah, yaitu $1$ atau $2$ langkah. Tentukan banyaknya cara melangkah yang berbeda untuk mencapai puncak.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Ini adalah bentuk soal dynamic programming yang paling-paling-paling sering diajarkan, untuk mengenalkan konsep dynamic programming dalam pemrograman. Setiap $n$ posisi tangga, memiliki total jumlah kemungkinan melangkah dari semua tangga dibawah $n$. Sehingga pendekatan dynamic programming berikut jelas sudah merupakan solusi final yang paling efisien:

```cpp
class Solution {
public:
    int climbStairs(int n) {
        array<int, 3> stair{};
        constexpr int MOD = 3;
        stair[0]=1;
        stair[1]=1;

        for(int i=2; i<=n; i++){
            stair[i % MOD] = stair[(i+1) % MOD] + stair[(i+2) % MOD];
        }

        return stair[n % MOD];
    }
};
```

Intinya: **Dynamic programming**. 

Ini adalah kasus dasar dari konsep ini, jadi pelajari saja dynamic programming untuk mempelajari kode diatas dengan mudah.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada untuk member premium.

## 3.2 | Analisis Pribadi

Ini hanyalah soal yang mengenalkan konsep dynamic programming, jadi aku tidak akan menjelaskan terlalu jauh.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int a = 1; // ways to reach step 1
        int b = 2; // ways to reach step 2

        for (int i = 3; i <= n; i++) {
            int c = a + b; // ways to reach current step
            a = b;
            b = c;
        }

        return b;
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
 public:
  int climbStairs(int n) {
    // dp[i] := the number of ways to climb to the i-th stair
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
  }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int a = 1, b = 2;
        for(int i=3;i<=n;i++){
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
```