---
obsidianUIMode: preview
note_type: book theory
judul_materi: Semua Angka diatas 1 Memiliki Faktor Prima
sumber:
  - myself
  - gemini.google.com
  - codeforces.com
date_learned: 2026-04-08T20:32:00
tags:
  - number-theory
  - prime-number
---
Link Sumber: 

---

> [!IMPORTANT]
>  
# Teorema Dasar Aritmatika: Atom dalam Bilangan Bulat

Dalam struktur matematika, bilangan prima bukanlah sekadar angka yang "sulit dibagi". Mereka adalah elemen dasar, atau dalam istilah komputasi, mereka adalah **atom** yang menyusun setiap bilangan bulat positif. Pemahaman ini bermuara pada satu fakta fundamental: setiap bilangan bulat yang lebih besar dari 1 pasti memiliki setidaknya satu pembagi prima.

## 1. Hakikat Keunikan Faktorisasi

Teorema Dasar Aritmatika menyatakan bahwa setiap bilangan bulat $n > 1$ dapat dinyatakan sebagai produk dari bilangan-bilangan prima. Yang membuatnya istimewa dalam algoritma bukan hanya eksistensi pembagi tersebut, melainkan sifat **uniknya**. Tidak peduli metode apa yang kamu gunakan untuk membedah sebuah angka, kamu akan selalu berakhir dengan setan (set) faktor prima yang sama.

Sebagai contoh, angka $1.200$ akan selalu terdiri dari $2^4 \times 3^1 \times 5^2$. Di dalam kompetisi pemrograman, fakta ini adalah kunci untuk menyelesaikan persoalan _combinatorics_ dan _counting divisors_ tanpa harus melakukan iterasi linier yang membuang waktu.

## 2. Limitasi dalam Pencarian Faktor

Meskipun benar bahwa setiap angka memiliki pembagi prima, distribusi pembagi tersebut mengikuti aturan simetri yang ketat. Jika sebuah bilangan $n$ adalah komposit, maka $n$ harus memiliki setidaknya satu faktor prima $p$ yang memenuhi kondisi $p \leq \sqrt{n}$.

Ini adalah observasi krusial yang mendasari efisiensi algoritma _Trial Division_. Tanpa batasan $\sqrt{n}$ ini, kita akan terjebak dalam kompleksitas $O(n)$ yang mustahil dikerjakan untuk angka di atas $10^8$. Namun, ada satu pengecualian penting: sebuah angka bisa saja memiliki tepat **satu** faktor prima yang lebih besar dari $\sqrt{n}$, namun faktor tersebut tidak mungkin memiliki pasangan sesama faktor besar, karena perkalian keduanya akan melebihi $n$ itu sendiri.

## 3. Relevansi pada Struktur Data

Dalam implementasi tingkat lanjut, kita sering menggunakan konsep **Smallest Prime Factor (SPF)**. Dengan memodifikasi algoritma Sieve of Eratosthenes, kita bisa menyimpan pembagi prima terkecil untuk setiap angka dalam sebuah array.

Hal ini mengubah proses faktorisasi dari yang awalnya membutuhkan waktu akar kuadrat $O(\sqrt{n})$ menjadi logaritmik $O(\log n)$. Setiap kali kita memiliki angka $x$, kita cukup melihat `SPF[x]`, membaginya, dan mengulangi proses tersebut hingga mencapai angka 1. Teknik ini adalah senjata rahasia saat menghadapi soal yang menuntut faktorisasi ribuan angka dalam waktu singkat.

## 4. Ringkasan untuk Implementasi

1. **Identitas Prima:** Jika sebuah angka tidak memiliki pembagi prima hingga batas $\sqrt{n}$, maka angka tersebut secara otomatis dideklarasikan sebagai prima.

<br/>

2. **Kekuatan Eksponen:** Banyaknya pembagi dari suatu angka ditentukan sepenuhnya oleh kombinasi pangkat dari faktor-faktor primanya.

<br/>

3. **Optimasi Memori:** Untuk angka yang sangat besar ($10^{18}$), alih-alih mencari pembagi prima satu per satu, kita beralih ke tes probabilistik seperti Miller-Rabin yang memanfaatkan sifat eksponensial bilangan prima.
    
