---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: lc-69
judul_DEATH: Sqrt(x)
teori_DEATH:
sumber:
  - leetcode.com
rating: 1
ada_tips: false
date_learned: 2025-11-20T21:27:00
tags:
  - math
  - binary-search
---
Sumber: [Fetching Title#jhy8](https://leetcode.com/problems/sqrtx/description/)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Sqrt(x)

Diberikan angka non negatif integer $x$, return kan hasil akar 2 dari $x$ yang dibulatkan kebawah ke integer terdekat. Nilai dari integer return ini tidak boleh berada dibawah angka 0, atau tidak boleh negatif.

> Soal ini meminta kita untuk tidak menggunakan fungsi bawaan yang berguna untuk meng akarkan, tapi ini terserah pada kita bukan?

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusi absolut, no mikir keras, ya cukup pakai fungsi `sqrt()` dari library cmath jika menggunakan C++:

```cpp
class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};
```

Well, sudah terjawab, sudah selesai wkwkw..

Tapi mari kita ekplorasi, apa algoritma yang ada dibalik fungsi `sqrt()` ini..



<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tidak ada bro, hanya untuk member premium.

## 3.2 | Analisis Pribadi

Aku tulis dibagian bawah saja sekalian.
## 3.3 | Analisis Jawaban User Lain

PR

### 1 | Jawaban Pertama

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int h = x;

        if (x == 0) return 0;
        if (x == 1) return 1;

        int p = 0;    

        while (l <= h)
        {
            int m = l + (h - l) / 2;

            long long sq = (long long)m * m;  

            if (sq == x)
                return m;
            else if (sq > x)                  
                h = m - 1;
            else {
                p = max(p, m);
                l = m + 1;
            }
        }

        return p;
    }
};
```
### 2 | Jawaban Kedua

```cpp
class Solution {
 public:
  int mySqrt(int x) {
    unsigned l = 1;
    unsigned r = x + 1u;

    while (l < r) {
      const unsigned m = (l + r) / 2;
      if (m > x / m)
        r = m;
      else
        l = m + 1;
    }

    // l := the minimum number s.t. l * l > x
    return l - 1;
  }
};
```
### 3 | Jawaban Ketiga

```cpp
class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};
```