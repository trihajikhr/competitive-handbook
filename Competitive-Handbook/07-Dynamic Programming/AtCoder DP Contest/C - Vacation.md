---
obsidianUIMode: preview
note_type: latihan
judul_problem: C - Vacation
latihan: dynamic programming dasar
sumber:
  - atcoder.jp
tags:
  - dynamic-programming
date_learned: 2026-04-02T23:25:00
---
Link Sumber: [C - Vacation](https://atcoder.jp/contests/dp/tasks/dp_c)

---
> [!IMPORTANT]
# C - Vacation

Liburan musim panas Taro dimulai besok, dan dia telah memutuskan untuk membuat rencana sekarang.

Liburan ini terdiri dari $N$ hari. Untuk setiap $i$ ($1 \le i \le N$), Taro akan memilih salah satu dari aktivitas berikut dan melakukannya pada hari ke-$i$:

- A: Berenang di laut. Dapatkan $a_i$ poin kebahagiaan.
- B: Menangkap serangga di pegunungan. Dapatkan $b_i$ poin kebahagiaan.
- C: Mengerjakan PR di rumah. Dapatkan $c_i$ poin kebahagiaan.

Karena Taro mudah bosan, dia tidak boleh melakukan aktivitas yang sama selama dua hari atau lebih secara berturut-turut.

Temukan total poin kebahagiaan maksimum yang mungkin didapatkan Taro.

**Batasan**

Semua nilai dalam input adalah bilangan bulat.

- $1 \le N \le 10^5$
- $1 \le a_i, b_i, c_i \le 10^4$

**Input**

Input diberikan dari Standard Input dalam format berikut:

```
N
a1 b1 c1
a2 b2 c2
:
an bn cn
```

**Output**

Cetak total poin kebahagiaan maksimum yang mungkin didapatkan Taro.

**Contoh Input 1**

```
3
10 40 70
20 50 80
30 60 90
```

**Contoh Output 1**

```
210
```

Jika Taro melakukan aktivitas dengan urutan C, B, C, dia akan mendapatkan $70 + 50 + 90 = 210$ poin kebahagiaan.

**Contoh Input 2**

```
1
100 10 1
```

**Contoh Output 2**

```
100
```

**Contoh Input 3**

```
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
```

**Contoh Output 3**

```
46
```

Taro harus melakukan aktivitas dengan urutan C, A, B, A, C, B, A.

<br/>

---
## Jawaban

<br/>

---
## Editorial