---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal:
judul_DEATH:
teori_DEATH:
sumber:
rating:
ada_tips:
date_learned:
tags:
---
Sumber:

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | Judul

<br/>

---
# 2 | Sesi Death Ground ⚔️

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Pertama, mari kita lakukan lompatan dengan kelipatan positif, yaitu $+k$, selama posisi $x$ masih lebih besar dari posisi saat ini. Kita akan berakhir di suatu posisi $pos$ yang merupakan hasil penjumlahan langkah $k$:

$$pos = 1 + 2 + \dots + steps = \frac{steps(steps + 1)}{2} \ge x$$

Perhatikan bahwa $0 \le pos - x < steps$, karena jika tidak, kita tidak akan melakukan langkah (*step*) terakhir.

Jika $pos = x$, maka kita beruntung dan selesai tepat di titik $x$. Jika tidak, mari kita amati apa yang terjadi jika kita mengganti satu lompatan $+k$ dengan $-k$. Pada dasarnya, kita akan berakhir di posisi baru $pos'$:

$$pos' = pos - (k + k) = pos - 2k$$


Jika tidak, mari kita lihat apa yang terjadi jika kita mengganti satu $+k$ dengan $-1$. Pada dasarnya, kita akan berakhir di $pos' = pos - (k+1)$. Karena $k \in [1, steps]$, maka $pos' \in [pos - steps - 1, pos - 2]$.

> Asumsi Koreksi Teknis (Sesuai Konteks Soal Jumper):
> 
> Asumsi yang lebih umum dan logis untuk jenis soal "lompatan" ini adalah kita mengganti lompatan $+k$ menjadi $-k$, yang menyebabkan perbedaan sebesar $-2k$ dari total jarak.

Kita tahu bahwa $pos - steps < x$. Jadi, jika $x < pos - 1$, maka kita dapat memilih $k$ yang sesuai dan mengganti $+k$ menjadi $-k$ agar langsung mencapai titik $x$.

* **Jika $pos - x$ adalah bilangan genap**, kita dapat memilih $k = \frac{pos - x}{2}$ dan mengganti lompatan $+k$ dengan $-k$. Perbedaan totalnya adalah $pos - 2k = pos - 2 \cdot (\frac{pos - x}{2}) = pos - (pos - x) = x$.

* **Namun, jika $x + 1 = pos$** (yaitu $pos - x = 1$, ganjil), maka kita memerlukan satu operasi ekstra $-1$ (atau penyesuaian lain, seperti melanjutkan hingga $pos'' \ge x$ dan membuat $pos'' - x$ genap).


Untuk menghitung jumlah langkah (*steps*) dengan cepat, kita dapat mencatat bahwa kita membutuhkan minimal:

$$steps \approx \sqrt{2 \cdot x} - 1$$

Ini didapat karena $steps(steps+1) \le (steps+1)^2 \le 2x$. Kemudian, kita dapat meningkatkan $steps$ secara iteratif selama $\frac{steps(steps + 1)}{2} < x$.


Berikut implementasi editorial:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
		
        int steps = 0;
        while (steps * (steps + 1) < 2 * x)
            steps++;
		
        if (steps * (steps + 1) / 2 == x + 1)
            steps++;
        cout << steps << endl;
    }
}
```

## 3.2 | Analisis Pribadi
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
```
### 2 | Jawaban Kedua

```cpp
```
### 3 | Jawaban Ketiga

```cpp
```