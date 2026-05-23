---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Rentang Inklusif dan Rumus R - L + 1
sumber:
  - myself
date_learned: 2026-04-08T18:30:00
tags:
  - tips-trick
  - range-queries
---
---
# The Art of Range Calculation: $R - L + 1$

Dalam dunia _Competitive Programming_, kesalahan satu angka (**Off-by-one error**) adalah penyebab kematian paling konyol di tengah kontes. Memahami mengapa kita menambahkan angka $1$ bukan sekadar menghafal rumus, tapi memahami perbedaan antara **titik** dan **jarak**.

## 1. Titik vs. Ruang (The Fencepost Error)

Bayangkan kamu sedang membangun pagar. Jika kamu ingin membangun pagar sepanjang 10 meter dengan tiang setiap 1 meternya, berapa tiang yang kamu butuhkan?

- Orang awam akan menjawab: $10 \div 1 = 10$.
- **Competitive Programmer** menjawab: $11$.

Kenapa? Karena ada tiang di titik $0$ yang sering terlupakan. Rumus $R - L$ hanya menghitung **interval** (jarak) antar tiang. Sedangkan dalam soal CP, kita biasanya diminta menghitung jumlah **elemen** (tiangnya).

> [!IMPORTANT]
> 
> $R - L$ = Menghitung langkah/jarak.
> 
> $R - L + 1$ = Menghitung objek/elemen yang ada di sepanjang jarak tersebut.

> [!IMPORTANT]
> Ini adalah penjelasanku:
> 
> Jika semisal diberikan $n$ orang dengan $n=10$, dan kita ingin mengetahui berapa banyak orang yang berada di rentang $L$ hingga $R$, misal $L=2$ dan $R=7$, maka berapa banyak orang yang kita ambil?
> 
> Maka, jawabanya bukan dengan melakukan operasi $R-L \rightarrow 7-2 = 5$ orang. Melainkan jawabanya harusnya adalah $6$ orang. Ini dibuktikan dengan kita akan mengambil orang-orang diposisi berikut: $2,3,4,5,6,7$.
> 
> Oleh karena itu, karena rentang ini adalah rentang inklusif, atau dimana batas-batasnya diikutsertakan dalam rentang yang dihitung, maka kita harus menggunakan rumus $R-L+1$.
## 2. Derivasi Matematika Sederhana

Misalkan kita punya himpunan bilangan bulat $S = \{L, L+1, L+2, \dots, R\}$.

Kita ingin mencari $|S|$ (kardinalitas/jumlah anggota).

Jika kita geser (translasikan) semua anggota dengan mengurangi $L - 1$, maka himpunannya menjadi:

$$S' = \{1, 2, 3, \dots, R - (L - 1)\}$$

$$S' = \{1, 2, 3, \dots, R - L + 1\}$$

Karena elemen terakhir dari $S'$ yang dimulai dari 1 adalah $R - L + 1$, maka itulah jumlah elemennya.

## 3. Aplikasi dalam Competitive Programming

### 3.1. Subarray Sum (Prefix Sum)

Jika kita punya array $A$ dan ingin menghitung total nilai dari indeks $L$ ke $R$:

$$\sum_{i=L}^{R} A_i = P[R] - P[L-1]$$

Di sini, $P[L-1]$ dibuang karena kita ingin elemen ke-$L$ **tetap ada** dalam perhitungan. Ini adalah bentuk lain dari logika $+1$ tersebut—kita mundur selangkah agar batas bawahnya inklusif.

### 3.2. Segment Tree & Binary Search

Saat membagi rentang $[L, R]$ menjadi dua:

- `mid = (L + R) / 2`
    
- Kiri: $[L, mid]$
    
- Kanan: $[mid + 1, R]$
    
    Perhatikan `mid + 1`. Jika kita hanya memakai `mid`, kita akan terjebak dalam _infinite loop_ karena rentang kanan tidak pernah mengecil.
    

## 4. Tips Anti-Bug (Grandmaster's Note)

- **Verify with 1:** Jika bingung, masukkan $L=1$ dan $R=1$. Rumusmu harus menghasilkan $1$. Jika $1-1 = 0$, berarti kamu kurang $+1$.

<br/>

- **Inclusive vs Exclusive:** Selalu pastikan soal meminta rentang $[L, R]$ (inklusif) atau $[L, R)$ (eksklusif). Kebanyakan soal CP adalah inklusif. Jika eksklusif, barulah rumusnya cukup $R - L$.
