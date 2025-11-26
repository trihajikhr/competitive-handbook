---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Permutations
sumber:
  - geeksforgeeks.org
  - chatgpt.com
  - "buku: CP handbook by Antti Laaksonen & chatgpt.com"
date_learned: 2025-08-13T13:54:00
tags:
  - combinatorics
---
Link Sumber: 
- [Permutations and Combinations - GeeksforGeeks](https://www.geeksforgeeks.org/maths/permutations-and-combinations/)
- 

---
# Permutasi

## 1 | Arti Permutasi

Permutasi adalah cara menyusun item yang mengutamakan urutan. Misalnya, jika kita memiliki dua komponen $A$ dan $B$, maka keduanya dapat disusun dengan cara berikut, { $AB$ dan $BA$ }.

Permutasi direpresentasikan sebagai $^{n}P_{r}$ 

- Di mana $r$ adalah ukuran permutasi, seperti berapa banyak komponen yang harus Anda pilih.
- Sedangkan $n$ adalah jumlah total komponen yang ada.

> Misalnya, misalkan $n =3$  ($A$, $B$, dan $C$) dan $r = 2$ (semua permutasi berukuran 2). **Maka**  
> terdapat **3 permutasi seperti** itu , yang sama dengan 6. Keenam permutasi tersebut adalah AB, AC, BA, BC, CA, dan CB. Keenam permutasi A, B, dan C yang diambil tiga sekaligus ditunjukkan pada gambar di bawah ini:

![[Permutations-1.png|700]]

<br/>

---
## 2 | Rumus Permutasi

Rumus permutasi digunakan untuk menemukan banyaknya cara memilih $r$ benda dari $n$ benda yang berbeda dalam urutan tertentu, dan penggantian tidak diperbolehkan. Rumusnya diberikan sebagai berikut:

$$^{n}P_{r}=\frac{n!}{(n-r)!}$$

<br/>

---
## 3 | Penjelasan Rumus Permutasi

Seperti yang kita ketahui, permutasi adalah susunan $r$ hal dari $n$ hal di mana urutan susunannya penting ($AB$ dan $BA$ adalah dua permutasi yang berbeda).

**Misalnya :**

> Jika terdapat tiga bilangan berbeda, yaitu 1, 2, dan 3, dan untuk mengubah urutan bilangan tersebut , dengan r = 2, diperoleh (1, 2), (1, 3), (2, 1), (2, 3), (3, 1), dan (3, 2) -> 6 cara.
>   
> Di sini, (1, 2) dan (2, 1) berbeda.  Dengan menempatkan bilangan ketiga dari kiri pada setiap kasus, diperoleh (1, 2, 3), (1, 3), (2, 1, 3), (2, 3, 1), (3, 1, 2) dan (3, 2, 1) - 6 cara.

Secara umum, $n$ hal berbeda dapat diatur dengan mengambil $r (r < n)$ sekaligus dalam $n(n - 1)(n - 2)...(n - r - 1)$ cara. Faktanya, hal pertama dapat berupa salah satu dari $n$ hal tersebut.  
  
Setelah memilih hal pertama, hal kedua akan berupa salah satu dari $n - 1$ hal yang tersisa. Demikian pula, hal ketiga dapat berupa salah satu dari $n - 2$ hal yang tersisa. Demikian pula, hal ke- $r$ dapat berupa salah satu dari $n - (r - 1)$ hal yang tersisa.

![[Permutations-2.png]]

<br/>

---
## 4 | Latihan
Pertanyaan Latihan – Permutasi dan Kombinasi

1. **Berapa banyak cara 5 buku dapat disusun di rak?**
   
   Jawabanya adalah dengan menggunakan faktorial dari 5, yaitu: $5! = 5 \times 4 \times 3 \times 2 \times 1 = 120$
<br/>

2. **Ada berapa cara menyusun 3 barisan orang dari kelompok 10 orang?**
   
   Kita bisa menggunakan rumus permutasi, yaitu: $^{n}P_{r}=\frac{n!}{(n-r)!}$, sehingga penyelesaianya adalah cukup seperti ini: $^{10}P_{3}=\frac{10}{(10-3)!}$, atau kita cukup hitung perkalian dari 10 hingga $n-r+1$, yaitu hingga 8, sehingga jawabanya $10 \times 9 \times 8 =720$.
<br/>

3. **Berapa banyak kode PIN 4 digit dapat dibuat dari angka 0–9 jika pengulangan tidak diperbolehkan?**
   
   Rumus permutasi, yaitu: $^{10}P_{4} = \frac{10!}{(10-4)!} = 10 \times 9 \times 8 \times 7 = 5040$
<br/>

4. **Ada berapa cara 6 orang dapat duduk di meja bundar?**

   Soal ini bukan permutasi biasa — kalau **meja bundar**, susunan melingkar dihitung sama jika bisa diputar. Rumusnya: $(n-1)! = (6-1)! = 5! = 120$ Jadi jawabannya 120, bukan $6! = 720$.
<br/>

6. Ada berapa cara menyusun huruf-huruf dalam kata “MATHEMATICS”?
   
   Itu termasuk **permutasi dengan pengulangan**, karena ada huruf yang sama. Jumlah huruf = 11, dengan pengulangan:
	* M: 2
	* A: 2
	* T: 2
	Rumus: $\frac{11!}{2! \cdot 2! \cdot 2!} = \frac{39916800}{8} = 4989600$
	Jadi jawabannya 4.989.600.

<br/>

7. Ada berapa cara menyusun huruf-huruf dalam kata “MISSISSIPPI”?
   
   Ini **permutasi dengan pengulangan**. Jumlah huruf = 11, dengan pengulangan:
	* M: 1
	* I: 4
	* S: 4
	* P: 2

	Rumus:

	$$
	\frac{11!}{1! \cdot 4! \cdot 4! \cdot 2!}  
	= \frac{39916800}{1 \cdot 24 \cdot 24 \cdot 2}  
	= \frac{39916800}{1152} = 34650
	$$

	Jadi jawabannya **34.650**.
