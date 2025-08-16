---
obsidianUIMode: preview
note_type: latihan
latihan: Koefisien Binomial Dasar
sumber:
  - chatgpt.com
tags:
  - combinatorics
date_learned: 2025-08-11T23:57:00
---
---
# Tim Penyelam Pulau Karang

Di sebuah pulau karang, terdapat **n** penyelam yang siap mengikuti misi penyelamatan mutiara langka di dasar laut.
Pemimpin misi harus memilih tepat **k** orang penyelam untuk membentuk tim misi.

Berapa banyak cara berbeda yang dapat pemimpin misi lakukan dalam memilih tim tersebut?

**Input format:**

```
n k
```

**Output format:**

```
jumlah_cara
```

**Batasan:**

* $0 \le k \le n \le 30$
* Gunakan perhitungan yang tepat (hindari pembulatan).

**Contoh:**

```
Input:
5 2

Output:
10
```

<br/>

---
# Jawaban

```cpp
#include <iostream>
using namespace std;

auto fac(int n) -> long long {
    long long sum = 1;
    for (int i = 2; i <= n; i++) {
        sum *= i;
    }
    return sum;
}

auto C(int n, int k) -> long long {
    return fac(n) / fac(k) / fac(n - k);
}

auto main() -> int {
    int n, k;
    cin >> n >> k;
    cout << C(n, k) << '\n';
    
    return 0;
}
```

<br/>

---
# Editorial

Rumus untuk menyelesaikan koefisien binomial, atau kombinasi, adalah dengan menggunakan rumus:

$$  \binom{n}{k} = \frac{n!}{k!(n-k)!}$$

Jadi, kita membuat fungsi `fac()` untuk menghitung nilai faktorial. Inisialisasi `sum` dengan 1, dan lakukan perkalian hingga `n`. Disini kita menggunakan `long long` untuk mengantisipasi hasil faktorial $n$ yang terlalu besar:

```cpp
auto fac(int n) -> long long {
    long long sum = 1;
    for (int i = 2; i <= n; i++) {
        sum *= i;
    }
    return sum;
}
```

Setelah itu, kita membuat fungsi penghitung nilai koefisien binomial, atau kombinasi, supaya pemanggilanya lebih bersih di `main`, yaitu sebagai berikut:

```cpp
auto C(int n, int k) -> long long {
    return fac(n) / fac(k) / fac(n - k);
}
```

Disini, kita tidak perlu mengalikan $fac(k) \cdot fac(n-k)$, walaupun rumusnya terlihat bahwa kedua nilai ini dikalikan. Kenapa?

Karena sejatinya hasil dari perkalian kedua nilai faktorial tadi, akan digunakan untuk membagi hasil faktorial dari $n$. Ini sama seperti:

$$\frac{10}{2 \cdot5}=1 \leftrightarrow \frac{(\frac{10}{2})}{5}=1$$

Dengan langsung membagi hasil dari $fac(n)$ dengan $fac(k)$ dan $fac(n-1)$, kita menghindari perkalian yang tidak perlu, dimana ini jauh lebih aman, mengingat hasil dari factorial keduanya mungkin terlalu besar sehingga bisa mengakibatkan overflow.

Setelah itu, kita bisa mendapatkan hasil dari koefisien binomial atau kombinasi, dengan melakukan pemanggilan fungsi `C()` pada `main`:

```cpp
auto main() -> int {
    int n, k;
    cin >> n >> k;
    cout << C(n, k) << '\n';
    
    return 0;
}
```
