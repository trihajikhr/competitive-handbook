---
obsidianUIMode: preview
note_type: latihan
latihan: Latihan Pertama Submask Enumeration
sumber:
  - cp-algorithms.com
tags:
  - bit-representation
date_learned: 2025-10-13T17:52:00
---
---
# 1 | Latihan Pertama Submask Enumeration

Diberikan sebuah angka $m$, tentukan submask apa saja yang ada pada angka $m$ dan jumlah submasknya.

<br/>

---
# 2 | Jawaban

<br/>

---
# 3 | Editorial

Karena aku masih pemula di pemahaman bits representation, maka aku akan menyelesaikan latihan ini dengan sedikit perlahan.

Pertama, mari kita pahami dulu apa itu submask. Jika kita memiliki suatu bilangan bitmask $m$, maka submask dari $m$ adalah semua bilangan $s$ yang memenuhi:

$$
s \subseteq m 
\quad \text{atau secara bitwise: } \; (s \,\&\, m) = s \text{}
$$

Artinya, semua bit yang di set di $s$ juga di set di $m$.

Contoh: 
$m=10110_2 = 22$
Submask-nya adalah semua bilangan $s$ yang hanya men set bit di posisi di mana $m$ juga punya bit $1$.

```
10110
10100
10010
10000
00110
00100
00010
00000
```

Atau, submask $s$ dari angka $m$ adalah angka-angka berikut ini (dalam desimal):

```
22
20
18
16
6
4
2
0
```

Total = $8$ submask (karena $m$ punya $3$ bit aktif $=> 2^3 = 8$ kombinasi).

Jika masih tidak paham, coba perhatikan ini:

Nilai dari $m=10110_2 = 22$. Perhatikan, bahwa bit yang di set, hanya ada pada posisi $1,2,4$. Sekarang perhatikan semua submask $s$ dari $m$. Semua angka $s$, memiliki representasi bit yang mana posisi bit ke $1,2,$ atau $4$, juga ikut ter set. 

Artinya, mencari submask dari $m$ sejatinya hanyalah mencari semua bilangan $s$ yang bit-bitnya terset hanya pada posisi-posisi yang juga terset pada $m$. Entah hanya satu bit yang terset, dua, tiga, lebih, atau bahkan tidak ada sama sekali — bilangan $s$ tetap merupakan submask dari $m$ selama setiap posisi bit yang tidak di-set pada $m$, juga tidak di-set pada $s$. Dengan kata lain, mencari semua submask dari $m$ mirip seperti mencari berbagai kombinasi digit $0$ dan $1$, tetapi hanya pada posisi bit yang bernilai $1$ di $m$.


```ad-hint
Dalam representasi bit, angka pertama biasanya merujuk ke sisi paling kanan, bit pertama dihitung dari kanan (LSB – Least Significant Bit).

**Intuisi Kenapa dari Kanan**

Karena sistem biner bekerja seperti sistem desimal, bit paling kanan mewakili nilai paling kecil:

$$101102​=(1×2^4)+(0×2^3)+(1×2^2)+(1×2^1)+(0×2^0)$$

Jadi:
- kanan → pangkat kecil ($2^0, 2^1, \cdots$)
- kiri → pangkat besar ($2^3, 2^4$)
```

Atau, 