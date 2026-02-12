---
obsidianUIMode: preview
note_type: book theory
judul_materi: Finding Power of Factorial Divisor
sumber:
  - cp-algorithms.com
date_learned: 2026-02-10T01:43:00
tags:
  - combinatorics
  - cp-algorithms
---
Link Sumber: [Finding Power of Factorial Divisor - Algorithms for Competitive Programming](https://cp-algorithms.com/algebra/factorial-divisors.html)

---

> [!IMPORTANT]
>  
# Finding Power of Factorial Divisor

Anda diberikan dua buah bilangan $n$ dan $k$. Temukan bilangan bulat terbesar $x$ sedemikian sehingga $k^x$ habis membagi $n!$.

## 1. Prime $k$ 

Mari kita pertimbangkan kasus di mana $k$ adalah bilangan prima. Ekspresi eksplisit untuk faktorial adalah:

$$n! = 1 \cdot 2 \cdot 3 \ldots (n-1) \cdot n$$

Perhatikan bahwa setiap elemen ke-$k$ dalam hasil kali tersebut habis membagi $k$, yang berarti menambah $+1$ ke dalam jawaban; jumlah elemen tersebut adalah $\Bigl\lfloor\dfrac{n}{k}\Bigr\rfloor$.

Selanjutnya, setiap elemen ke-$k^2$ habis membagi $k^2$, yang berarti menambah $+1$ lagi ke dalam jawaban (pangkat pertama dari $k$ sudah dihitung pada paragraf sebelumnya). Jumlah elemen tersebut adalah $\Bigl\lfloor\dfrac{n}{k^2}\Bigr\rfloor$.

Dan seterusnya, untuk setiap $i$, setiap elemen ke-$k^i$ menambah $+1$ lagi ke dalam jawaban, dan terdapat $\Bigl\lfloor\dfrac{n}{k^i}\Bigr\rfloor$ elemen seperti itu.

Jawaban akhirnya adalah:

$$\Bigl\lfloor\dfrac{n}{k}\Bigr\rfloor + \Bigl\lfloor\dfrac{n}{k^2}\Bigr\rfloor + \ldots + \Bigl\lfloor\dfrac{n}{k^i}\Bigr\rfloor + \ldots$$

Hasil ini juga dikenal sebagai [Legendre's formula](https://en.wikipedia.org/wiki/Legendre%27s_formula). Deret penjumlahan ini tentu saja bersifat terbatas (*finite*), karena hanya sekitar $\log_k n$ elemen pertama yang bukan nol. Dengan demikian, runtime dari algoritma ini adalah $O(\log_k n)$.

### 1.1. Implementation

```cpp
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}
```

## 2. Composite $k$ 

Ide yang sama tidak dapat diterapkan secara langsung. Sebagai gantinya, kita dapat melakukan faktorisasi terhadap $k$, menyatakannya sebagai $k = k_1^{p_1} \cdot \ldots \cdot k_m^{p_m}$. Untuk setiap $k_i$, kita cari berapa kali bilangan tersebut muncul dalam $n!$ menggunakan algoritma yang dijelaskan di atas — mari kita sebut nilai ini sebagai $a_i$. Jawaban untuk $k$ komposit adalah:

$$\min_ {i=1 \ldots m} \dfrac{a_i}{p_i}$$
