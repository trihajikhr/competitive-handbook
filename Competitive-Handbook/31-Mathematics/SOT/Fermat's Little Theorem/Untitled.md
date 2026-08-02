---
obsidianUIMode: preview
note_type: book theory
judul_materi:
sumber:
date_learned:
tags:
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Teorema Kecil Fermat

Teorema Kecil Fermat (_Fermat's Little Theorem_) adalah salah satu teorema fundamental dalam teori bilangan yang menyatakan bahwa jika $p$ adalah sebuah bilangan prima dan $a$ adalah bilangan bulat yang tidak habis dibagi oleh $p$ (yakni $a$ dan $p$ saling prima, atau $\gcd(a, p) = 1$), maka $a^{p-1}$ akan bernilai kongruen dengan $1$ modulo $p$.

Secara matematis, pernyataan tersebut dituliskan sebagai:

$$a^{p-1} \equiv 1 \pmod p$$

Alternatifnya, untuk setiap bilangan bulat $a$ (tanpa syarat $\gcd(a, p) = 1$), bentuk umum teorema ini adalah:

$$a^p \equiv a \pmod p$$

## Contoh Sederhana

Ambil bilangan prima $p = 5$ dan $a = 2$. Berdasarkan teorema:

$$2^{5-1} = 2^4 = 16$$

Jika kita hitung modulo dari $16$ terhadap $5$:

$$16 \pmod 5 = 1$$

Hasil ini sesuai dengan pernyataan teorema bahwa $2^4 \equiv 1 \pmod 5$.

## Penerapan dalam Komputasi dan Pemrograman

Dalam bidang ilmu komputer, khususnya kriptografi dan kompetisi pemrograman, Teorema Kecil Fermat sangat berguna untuk mencari invers modulo (_modular multiplicative inverse_).

Jika kita ingin mencari invers dari $a$ modulo $p$ (yaitu $a^{-1}$ sedemikian rupa sehingga $a \cdot a^{-1} \equiv 1 \pmod p$), kita dapat menggunakan bentuk turunan dari teorema ini:

$$a \cdot a^{p-2} \equiv 1 \pmod p$$

Dari persamaan di atas, terlihat jelas bahwa invers modulo dari $a$ adalah:

$$a^{-1} \equiv a^{p-2} \pmod p$$

Hal ini memungkinkan kita menghitung pembagian dalam modulo menggunakan **Binary Exponentiation** dengan kompleksitas waktu $O(\log p)$, yang jauh lebih efisien dibandingkan pencarian linear.

## Penyelesaian $a^{b^c} \pmod{10^9 + 7}$

> Bagaimana cara menyelesaikan perhitungan $a^{b^c} \pmod{10^9 + 7}$ menggunakan Teorema Kecil Fermat?

Modulus yang umum digunakan dalam kompetisi pemrograman adalah $M = 10^9 + 7$, di mana nilai tersebut merupakan sebuah bilangan prima. Ketika kita dihadapkan pada bentuk menara eksponen seperti $a^{b^c} \pmod M$, eksponen pada tingkat atas sangatlah besar sehingga tidak dapat dihitung secara langsung menggunakan tipe data biasa. Di sinilah Teorema Kecil Fermat berperan penting melalui sifat **Reduksi Eksponen**.

### Konsep Reduksi Eksponen

Berdasarkan Teorema Kecil Fermat, jika $M$ adalah bilangan prima dan $\gcd(a, M) = 1$, maka:

$$a^{M-1} \equiv 1 \pmod M$$

Hal ini berarti jika kita memangkatkan $a$ dengan kelipatan dari $(M-1)$, hasilnya akan selalu bernilai $1$ modulo $M$. Ketika kita memiliki bentuk eksponen yang besar seperti $E$, kita dapat mereduksi nilai eksponen tersebut dengan mengambil sisa baginya terhadap $(M-1)$:

$$a^E \equiv a^{E \pmod{M-1}} \pmod M$$

Dengan demikian, bentuk menara eksponen $a^{b^c}$ dapat disederhanakan menjadi:

$$a^{(b^c \pmod{M-1})} \pmod M$$

### Langkah-Langkah Algoritma

1. **Periksa Kondisi Khusus ($\gcd(a, M)$):**
    
    Pastikan apakah $a$ habis dibagi oleh $M$ ($a \pmod M = 0$). Jika $a$ adalah kelipatan dari $M$, maka hasil akhirnya langsung $0$ (kecuali jika $b^c = 0$).
    
2. **Hitung Eksponen di Tingkat Bawah:**
    
    Hitung nilai eksponen bagian atas terlebih dahulu menggunakan _Binary Exponentiation_ modulo $(M-1)$:
    
    $$\text{exp} = b^c \pmod{M-1}$$
    
3. **Hitung Hasil Akhir:**
    
    Substitusikan hasil reduksi eksponen tersebut kembali ke basis utama menggunakan _Binary Exponentiation_ modulo $M$:
    
    $$\text{hasil} = a^{\text{exp}} \pmod M$$
    

Pendekatan ini mereduksi kompleksitas waktu secara drastis menjadi $O(\log c + \log M)$, memungkinkan perhitungan eksponen yang sangat besar diselesaikan secara efisien dalam batasan waktu (_time limit_) kompetisi pemrograman.

## Konsep Reduksi Eksponen dan Peran $M-1$

Untuk memahami mengapa eksponen dapat direduksi menjadi modulo $M-1$, kita dapat kembali ke sifat dasar dari **Teorema Kecil Fermat**.

Misalkan kita memiliki bilangan prima $M = 10^9 + 7$ dan $\gcd(a, M) = 1$. Teorema menyatakan:

$$a^{M-1} \equiv 1 \pmod M$$

Jika kita memiliki eksponen yang sangat besar, katakanlah $E$, kita dapat menulis ulang eksponen tersebut menggunakan pembagian bersisa (_Division Algorithm_):

$$E = q(M-1) + r$$

di mana $q$ adalah hasil bagi (_quotient_) dan $r$ adalah sisa pembagian ($r = E \pmod{M-1}$).

Sekarang, mari kita masukkan bentuk $E$ ini ke dalam perpangkatan $a^E \pmod M$:

$$a^E = a^{q(M-1) + r} = (a^{M-1})^q \cdot a^r \pmod M$$

Berdasarkan Teorema Kecil Fermat, karena $a^{M-1} \equiv 1 \pmod M$, maka perpangkatan berapa pun dari $1$ (yaitu $(a^{M-1})^q$) akan tetap bernilai $1$:

$$(1)^q \cdot a^r \equiv 1 \cdot a^r \equiv a^r \pmod M$$

Inilah alasan utamanya: **kelipatan dari $(5-1)$ atau $(M-1)$ akan menghasilkan nilai $1$ jika dimodulo dengan $M$, sehingga bagian tersebut "habis" atau dapat diabaikan**, dan yang tersisa hanyalah sisa baginya saja ($r = E \pmod{M-1}$).

## Mengapa $a^b \pmod{10^9 + 7}$ Cukup Menggunakan _Binary Exponentiation_?

Untuk bentuk sederhana seperti $a^b \pmod M$, kita **tidak memerlukan** Teorema Kecil Fermat karena nilai $b$ (eksponen pada tingkat pertama) umumnya masih dapat ditampung oleh tipe data standar atau langsung dihitung menggunakan _Binary Exponentiation_.

- **Kompleksitas Binary Exponentiation:** Algoritma ini menghitung $a^b \pmod M$ dalam waktu $O(\log b)$. Jika $b \le 10^9$, jumlah operasi yang dibutuhkan hanya sekitar $\log_2(10^9) \approx 30$ langkah saja. Ini sangat cepat dan langsung selesai dalam milidetik.
    
- **Kapan Teorema Kecil Fermat Dibutuhkan?** Teorema ini baru diperlukan ketika eksponennya berupa **menara eksponen** (seperti $b^c$ atau faktorial besar seperti $b!$) di mana nilai eksponen tersebut **terlalu besar untuk disimpan dalam variabel**, atau untuk mencari **invers modulo** ($\frac{1}{a} \equiv a^{M-2} \pmod M$).
    

Jadi, untuk $a^b$, _Binary Exponentiation_ bekerja secara langsung pada basis dan eksponen aslinya tanpa perlu mereduksi eksponennya terlebih dahulu.