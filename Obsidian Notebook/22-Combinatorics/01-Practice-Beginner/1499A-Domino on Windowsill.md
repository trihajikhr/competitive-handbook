---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: 1499A
judul_STRIKE: Domino on Windowsill
teori_STRIKE: 
sumber:
  - codeforces
ada_tips?: 
date_learned: 2025-08-14T02:57:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1499A - Codeforces](https://codeforces.com/problemset/problem/1499/A)

```ad-tip
title:⚔️ Teori STRIKE

```

<br/>

---
# 1 | Domino on Windowsill

Kamu memiliki papan yang direpresentasikan sebagai grid berukuran $2 \times n$ kotak.

Pada baris pertama, $k_1$ kotak pertama berwarna putih. Pada baris kedua, $k_2$ kotak pertama berwarna putih. Semua kotak lainnya berwarna hitam.

Kamu memiliki $w$ domino putih (ubin berukuran $2 \times 1$ di mana kedua kotaknya berwarna putih) dan $b$ domino hitam (ubin berukuran $2 \times 1$ di mana kedua kotaknya berwarna hitam).

Kamu dapat menempatkan domino putih di papan jika kedua kotak yang ditempatinya berwarna putih dan belum ditempati domino lain. Demikian juga, kamu dapat menempatkan domino hitam jika kedua kotak yang ditempatinya berwarna hitam dan belum ditempati domino lain.

Domino dapat ditempatkan baik secara horizontal maupun vertikal. Apakah mungkin untuk menempatkan semua $w + b$ domino di papan?

#### Input:
Baris pertama berisi satu bilangan bulat $t$ ($1 \le t \le 3000$) — jumlah *test case*.

Baris pertama dari setiap *test case* berisi tiga bilangan bulat $n$, $k_1$, dan $k_2$ ($1 \le n \le 1000$; $0 \le k_1, k_2 \le n$).

Baris kedua dari setiap *test case* berisi dua bilangan bulat $w$ dan $b$ ($0 \le w, b \le n$).

#### Output:
Untuk setiap *test case*, cetak `YES` jika mungkin menempatkan semua $w + b$ domino di papan, dan `NO` jika tidak.

Kamu boleh mencetak huruf dalam bentuk besar atau kecil (misalnya `yEs`, `yes`, `Yes`, dan `YES` semuanya dianggap jawaban benar).

<br/>

---
# 2 | Sesi STRIKE ⚔️


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kita dapat membuktikan bahwa jika kita memiliki $k_1 + k_2$ kotak putih di papan, maka kita dapat menempatkan sembarang $w$ domino putih selama $2w \le k_1 + k_2$.

Buktinya adalah sebagai berikut: jika $k_1 \ge k_2$ maka kita tempatkan satu domino pada posisi $((1, k_1 - 1), (1, k_1))$, jika tidak, tempatkan domino pada posisi $((2, k_2 - 1), (2, k_2))$. Kemudian kita dapat menyelesaikan penempatan $w - 1$ domino di $k_1 - 2$ kotak di baris pertama dan $k_2$ kotak di baris kedua secara rekursif (atau secara analog, $k_1$ dan $k_2 - 2$).

Pada akhirnya, salah satu dari semua domino berhasil ditempatkan atau $k_1 < 2$ dan $k_2 < 2$.
Jika $k_1 = 0$ atau $k_2 = 0$, maka karena $2w \le k_1 + k_2$, berarti $w = 0$ atau semua domino berhasil ditempatkan. Jika $k_1 = 1$ dan $k_2 = 1$, maka kita mungkin perlu menempatkan satu domino lagi — dan kita dapat menempatkannya secara vertikal.

Kita dapat membuktikan bahwa kita dapat menempatkan sembarang $b$ domino hitam selama $2b \le (n - k_1) + (n - k_2)$ dengan cara yang sama.

Hasilnya, yang perlu kita periksa hanyalah $2w \le k_1 + k_2$ dan $2b \le (n - k_1) + (n - k_2)$.

```cpp
void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;

        if (k1 + k2 >= 2 * w && (n - k1) + (n - k2) >= 2 * b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
```
## 3.2 | Analisis Pribadi

Aku memiliki solusi sebagai berikut:

```cpp
/*
Author  : Riveris
Date    : 2025-08-13 00:26
Problem : Codeforces - 1499A | Domino on Windowsill
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void solve() {
   int n, k1, k2, w, b;
   cin >> n >> k1 >> k2 >> w >> b;

   int black = (n * 2) - k1 - k2;
   int white = k1 + k2;

   if (black >= (b * 2) && white >= (w * 2)) {
      cout << "YES";
   } else {
      cout << "NO";
   }

   cout << "\n";
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

Kita perlu membuat ilustrasi disini.

Pertama, kita diberikan sebuah bidang dengan banyak baris berupa 2, dan banyak kolom adalah $n$. Katakanlah kita memiliki nilai $n$ berupa 8, maka bidang yang terbentuk adalah seperti ini:

![[1499A-Domino on Windowsill-1.png]]

Jangan lupa, kita beri warna dengan warna hitam, 

![[1499A-Domino on Windowsill-2.png]]

Nilai dari $k_1$ menunjukan banyaknya petak putih pada baris pertama, dimulai dari kolom paling kiri. Sedangkan nilai pada $k_2$ untuk baris kedua. Jika kita memiliki $k_1 = 3$ dan $k_2 = 5$, maka sekarang petaknya adalah seperti ini:

![[1499A-Domino on Windowsill-3.png]]

Jika kita diberikan sebuah domino putih berupa $w=4$ dan domino hitam berupa $b=3$, bagaimana cara menentukan apakah domino tersebut muat atau tidak? 

Oke, secara ilustrasi ya pasti gampang kan, jelas. Tapi kalau semisal panjang kolom adalah 153458, dan banyak domino hitam dan putih yang perlu disesuaikan adalah ratusan? 

Oke, solusi menyelesaikan masalah ini sebenarnya cukup mudah, kita tinggal menghitung luas dari bidang putih dan luas dari bidang hitam. 

Untuk menghitung luas dari bidang putih, kita cukup mengetahuinya dengan $L_w=k_1 + k_2$. Dan untuk luas bidang hitam, bisa diketahui dengan $L_b=(2 \cdot n) - L_w$.

Dari ilustrasi diatas, didapat bahwa $L_w=3+5=8$ dan $L_b=(2 \cdot 8)-L_w⇒16-8=8$.

Nah, tugas kita selanjutnya adalah memastikan, bahwa domino tersebut muat atau tidak, dengan cara memastikan bahwa total luas semua domino adalah kurang dari sama dengan luas petak yang sesuai dengan warnanya.

Untuk domino putih, maka persamaan ini harus terpenuhi: $(w \times 2) \leq L_w$
Untuk domino hitam, maka persamaan ini harus terpenuhi: $(b \times 2) \leq L_b$

Jika kedua syarat diatas terpenuhi, maka berarti domino tersebut bisa dimasukan ke dalam bidang-bidang yang sesuai warnanya, sehingga outputkan `YES`. Jika ada satu syarat yang tidak terpenuhi, maka outputkan `NO`. Berikut adalah ilustrasi petak sekarang yang sudah diisi domino:

![[1499A-Domino on Windowsill-4.png]]



