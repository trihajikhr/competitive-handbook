---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Divisibility Rule 10 sd 90
sumber: Google.com, AI
date_learned: 2025-07-16T22:57:00
tags:
  - math
---
Link Sumber: 

---
# Divisibility Rule 10 s/d 90
Berikut materi lengkap tentang **aturan kelipatan (divisibility rules)** untuk bilangan 10, 20, 30, …, 90. Setiap aturan dibagi menjadi:

1. **Pernyataan aturan**
2. **Langkah pengecekan**
3. **Contoh aplikasi**

---

## 1. Aturan untuk 10

1. **Pernyataan:**
   Sebuah bilangan bulat $n$ habis dibagi 10 jika dan hanya jika angka satuannya adalah 0.
2. **Langkah pengecekan:**

   * Lihat digit paling kanan (satuan) dari $n$.
   * Jika digit tersebut $=0$, maka $10 \mid n$.
   * Jika tidak, maka $10\nmid n$.
3. **Contoh:**

   * $n=340$: satuannya $0$, jadi $10\mid340$.
   * $n=123$: satuannya $3$, jadi $10\nmid123$.

---

## 2. Aturan untuk 20

1. **Pernyataan:**
   $n$ habis dibagi 20 ⇔ $n$ habis dibagi 10 **dan** angka puluhan (dua digit terakhir) membentuk bilangan genap ganda, yaitu kelipatan 2.
2. **Langkah pengecekan:**

   * Pastikan $10\mid n$ (satuan = 0).
   * Ambil dua digit terakhir (puluhan dan satuan), misal “$\overline{ab}$”. Karena satuannya 0, cukup cek $a$ genap (0,2,4,6,8).
   * Jika iya, maka $20\mid n$.
3. **Contoh:**

   * $n=260$: dua digit terakhir “60”, dan $60/20=3$, jadi $20\mid260$.
   * $n=450$: dua digit “50”, tapi $50/20=2.5$ bukan bilangan bulat ⇒ $20\nmid450$.

---

## 3. Aturan untuk 30

1. **Pernyataan:**
   $n$ habis dibagi 30 ⇔ $n$ habis dibagi 10 **dan** habis dibagi 3.
2. **Langkah pengecekan:**

   * Cek dulu satuan $=0$ (→ $10\mid n$).
   * Jumlahkan semua digit $n$; jika hasilnya kelipatan 3, maka $3\mid n$.
   * Jika kedua kondisi terpenuhi, maka $30\mid n$.
3. **Contoh:**

   * $n=360$: satuan 0, jumlah digit $3+6+0=9$ (kelipatan 3), ⇒ $30\mid360$.
   * $n=510$: satuan 0, jumlah digit $5+1+0=6$ (kelipatan 3), ⇒ $30\mid510$.
   * $n=430$: satuan 0, jumlah digit $4+3+0=7$ (bukan kelipatan 3) ⇒ $30\nmid430$.

---

## 4. Aturan untuk 40

1. **Pernyataan:**
   $n$ habis dibagi 40 ⇔ $n$ habis dibagi 10 **dan** dua digit terakhir membentuk bilangan kelipatan 4.
2. **Langkah pengecekan:**

   * Pastikan satuan = 0.
   * Ambil dua digit terakhir (“$\overline{ab}$0” sebenarnya berarti bilangan $\,10a$), cek $\overline{ab}0\div40$ bulat ⇔ $\overline{ab}$ genap dan $\overline{ab}$ habis dibagi 4.
3. **Contoh:**

   * $n=520$: dua digit terakhir “20”, $20/4=5$ genap, ⇒ $40\mid520$.
   * $n=680$: dua digit “80”, $80/4=20$, ⇒ $40\mid680$.
   * $n=350$: dua digit “50”, $50/4=12{,}5$ ⇒ $40\nmid350$.

---

## 5. Aturan untuk 50

1. **Pernyataan:**
   $n$ habis dibagi 50 ⇔ digit satuan = 0 **dan** digit puluhan genap kelipatan 5, atau dua digit terakhir adalah 00 atau 50.
2. **Langkah pengecekan:**

   * Cek dua digit terakhir; jika “00” atau “50”, maka $50\mid n$.
3. **Contoh:**

   * $n=450$: dua digit “50” ⇒ $50\mid450$.
   * $n=1200$: dua digit “00” ⇒ $50\mid1200$.
   * $n=130$: dua digit “30” ⇒ $50\nmid130$.

---

## 6. Aturan untuk 60

1. **Pernyataan:**
   $n$ habis dibagi 60 ⇔ $n$ habis dibagi 10 **dan** habis dibagi 6.
2. **Langkah pengecekan:**

   * Cek satuan = 0 (→ $10\mid n$).
   * Cek $6\mid n$: yaitu $2\mid n$ (dua digit terakhir genap) **dan** $3\mid n$ (jumlah digit kelipatan 3).
3. **Contoh:**

   * $n=720$: satuan 0; jumlah digit $7+2+0=9$ (kelipatan 3); digit puluhan “2” genap ⇒ $60\mid720$.
   * $n=540$: satuan 0; jumlah digit $5+4+0=9$; digit puluhan “4” genap ⇒ $60\mid540$.

---

## 7. Aturan untuk 70

1. **Pernyataan:**
   $n$ habis dibagi 70 ⇔ $n$ habis dibagi 10 **dan** habis dibagi 7.
2. **Langkah pengecekan:**

   * Cek satuan = 0.
   * Untuk $7\mid n$, gunakan metode pengurangan ganda digit akhir:

     * Ambil digit terakhir $d$, kalikan 2 → $2d$.
     * Kurangi sisa bilangan depan dengan $2d$.
     * Ulangi sampai mudah diketahui kelipatan 7.
3. **Contoh:**

   * $n=350$: satuan 0. Untuk 35: $5\times2=10$, $3-10=-7$ (kelipatan 7) ⇒ $70\mid350$.
   * $n=560$: satuan 0. Untuk 56: $6\times2=12$, $5-12=-7$ ⇒ $70\mid560$.

---

## 8. Aturan untuk 80

1. **Pernyataan:**
   $n$ habis dibagi 80 ⇔ $n$ habis dibagi 10 **dan** tiga digit terakhir membentuk bilangan kelipatan 8.
2. **Langkah pengecekan:**

   * Cek satuan = 0.
   * Ambil tiga digit terakhir $\overline{abc}0$ → cek $\overline{abc}0/80$ bulat.
3. **Contoh:**

   * $n=1\,120$: tiga digit “1200”; $1200/80=15$ ⇒ $80\mid1120$.
   * $n=3\,280$: “3280” → $3280/80=41$ ⇒ $80\mid3280$.

---

## 9. Aturan untuk 90

1. **Pernyataan:**
   $n$ habis dibagi 90 ⇔ $n$ habis dibagi 10 **dan** habis dibagi 9.
2. **Langkah pengecekan:**

   * Cek satuan = 0.
   * Jumlahkan digit; jika kelipatan 9, maka $9\mid n$.
3. **Contoh:**

   * $n=450$: satuan 0; jumlah digit $4+5+0=9$, ⇒ $90\mid450$.
   * $n=720$: satuan 0; jumlah digit $7+2+0=9$, ⇒ $90\mid720$.
   * $n=810$: satuan 0; jumlah digit $8+1+0=9$, ⇒ $90\mid810$.

---

### Ringkasan Tabel Aturan

| Pembagi | Syarat Utama                                             | Contoh |
| ------- | -------------------------------------------------------- | ------ |
| 10      | Satuan = 0                                               | 340 ✔  |
| 20      | Satuan 0 & puluhan genap                                 | 260 ✔  |
| 30      | Satuan 0 & sum digit ≡0 mod 3                            | 360 ✔  |
| 40      | Satuan 0 & dua digit terakhir ≡0 mod 4                   | 520 ✔  |
| 50      | Dua digit terakhir = 00 atau 50                          | 450 ✔  |
| 60      | Satuan 0 & genap & sum digit ≡0 mod 3                    | 720 ✔  |
| 70      | Satuan 0 & menggunakan metode “kurangi 2×digit terakhir” | 350 ✔  |
| 80      | Satuan 0 & tiga digit terakhir ≡0 mod 8                  | 1120 ✔ |
| 90      | Satuan 0 & sum digit ≡0 mod 9                            | 450 ✔  |

---

Dengan memahami pola “satuan = 0” sebagai dasar untuk semua kelipatan 10, lalu menambahkan pengecekan khusus (mod 2, 3, 4, 7, 8, atau 9), kamu dapat menentukan dengan cepat kelipatan 10, 20, …, 90 pada suatu bilangan. Semoga bermanfaat!
