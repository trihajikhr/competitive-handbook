---
obsidianUIMode: preview
note_type: latihan
latihan: Mencari Satu Jalur Terpendek
sumber:
  - myself
tags:
  - graph-algorithm
  - shortest-paths
date_learned: 2025-08-03T20:23:00
---
---
# The Flying Duthcman

Febrian suka sekali dengan MilkShake. Kemanapun dia keluar rumah, dia selalu membelinya. Ada banyak sekali toko minuman penjual Milkshake, akan tetapi semuanya berubah, ketika negara Api menyerang.

Banyak sekali toko Milkshake yang tutup, sehingga keberadaan minuman Milkshake menjadi langka. Febrian sudah mencari kesana kemari, menjelajahi desa Suna, Konoha, Iwagakure, dan juga Bikini Bottom, tapi tidak ada satupun yang tersisa.

Seorang pengelana memberi tahu Febrian, bahwa ada pasar gelap yang masih menjual milkshake terakhir secara rahasia, hanya pada orang-orang yang memenuhi syarat. Syarat tersebut adalah bahwa siapapun orang yang ingin membelinya dari pasar gelap, harus membawa peta menuju kapal hantu The Flying Dutchman. 

Namun, sayangnya, peta tersebut terpecah pecah menjadi $t$ bagian, dan tersebar diantara $n$ tempat dengan $m$ jalur. Setiap tempat tersebut terhubung satu sama lain, dengan jarak antara kota $u$ dan kota $v$ adalah sebesar $w$. 

Setiap bongkahan peta, memiliki kekuatan magis yang bisa digunakan untuk mempercepat perjalanan dari tempat $u$ ke tempat $v$ sebesar $\frac{w}{c}$, dimana $c$ adalah jumlah bongkahan peta yang sudah dikumpulkan.

Sekarang, bantu Febrian untuk mengumpulkan semua bongkahan peta dengan jarak tempuh seminimal mungkin.

#### Input

Baris pertama terdiri dari $n$ dan $m$, yang merupakan jumlah tempat dan banyaknya jalur. 

Lalu $m$ baris berikutnya terdiri dari $u, v, w$, merepresentasikan kedua tempat yang terhubung, dan jarak dari kedua tempat.

Inputan ketiga adalah $t$, yaitu banyaknya robekan peta yang tersebar, dimana $1\leq t \leq n$, dan diikuti dibawahnya ada sebanyak $t$ digit, menunjukan dimana saja peta tersebut berada.

Inputan terakhir adalah $x$ dan $y$, menunjukan lokasi sekarang Febrian, dan lokasi pasar gelap.

#### Output

Cetak jarak tempuh minimal yang Febrian harus lalui, untuk berhasil mengumpulkan semua peta, dan membawanya ke pasar gelap. 

#### Contoh

Input:

```
20 39
1 2 5
1 3 6
1 4 4
1 5 5 
1 6 7
1 7 7
2 4 4
2 7 5
7 5 5
5 6 6
6 3 6
3 4 4
4 8 4
8 9 3
9 2 7
8 10 3
10 11 4
11 12 8
12 13 7
13 14 4
14 9 4
15 9 8
15 8 6
15 10 5
15 11 6
4 9 4
2 8 4
15 12 7
15 13 7
15 14 7
16 14 15
16 3 21
16 17 19
16 18 32
18 17 54
17 13 7
17 19 14
19 20 7
20 18 17
10
7 5 3 16 20 11 2 12 14 10
1 15
```

![[07-Graph Berbobot dengan Tantangan-1.png]]

<br/>

---
# Jawaban

<br/>

---
# Editorial

> [!NOTE] Referensi
> - [Bitmasking and Dynamic Programming \| Travelling Salesman Problem - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/bitmasking-dynamic-programming-set-2-tsp/)
> - [Bitmasking Dynamic Programming in Algorithms \| Useful Codes](https://useful.codes/bitmasking-dynamic-programming-in-algorithms/)
> - [algorithm - Travelling Sales Man (need to visit only subset of nodes): Bugged - Stack Overflow](https://stackoverflow.com/questions/13195089/travelling-sales-man-need-to-visit-only-subset-of-nodes-bugged)

