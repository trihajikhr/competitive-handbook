---
obsidianUIMode: preview
note_type: latihan
latihan: NAKANJ - Minimum Knight moves !!!
sumber:
  - cp-algorithms.com
tags:
  - graphs
  - graph-BFS
date_learned: 2026-03-16T02:17:00
---
Link Sumber: [SPOJ - NAKANJ - Minimum Knight moves !!!](https://www.spoj.com/problems/NAKANJ/)

---
> [!IMPORTANT]
# NAKANJ - Minimum Knight moves !!!

Anjali dan Nakul adalah teman baik. Mereka baru saja bertengkar saat bermain catur. Nakul ingin tahu jumlah langkah minimum yang dibutuhkan sebuah kuda (_knight_) untuk berpindah dari satu petak ke petak lain di papan catur ($8 \times 8$). Nakul sangat cerdas dan dia sudah menulis program untuk menyelesaikan masalah tersebut. Nakul ingin tahu apakah Anjali bisa melakukannya. Anjali sangat lemah dalam pemrograman. Bantulah dia untuk menyelesaikan masalah ini.

Seekor kuda dapat bergerak membentuk huruf "L" di papan catur — dua petak ke depan, belakang, kiri, atau kanan, kemudian satu petak ke kiri atau kanannya. Pergerakan kuda dianggap valid jika bergerak seperti yang disebutkan di atas dan tetap berada dalam batas papan catur ($8 \times 8$).


![](src/NAKANJ%20-%20Minimum%20Knight%20moves%20!!!-1.png)
### Input

Terdapat total $T$ _test case_. $T$ baris berikutnya berisi dua _string_ (awal dan tujuan) yang dipisahkan oleh spasi.

_String_ awal dan tujuan hanya akan berisi dua karakter:

- Karakter pertama adalah huruf antara `a` dan `h` (inklusif).
    
- Karakter kedua adalah angka antara `1` dan `8` (inklusif).
    

### Constraints

- $1 \le T \le 4096$
### Output

Cetak jumlah langkah minimum yang dibutuhkan kuda untuk mencapai tujuan dari posisi awal dalam baris terpisah.

### Example

**Input:**

```
3
a1 h8
a1 c2
h8 c3
```

**Output:**

```
6
1
4
```

<br/>

---
## Jawaban

<br/>

---
## Editorial