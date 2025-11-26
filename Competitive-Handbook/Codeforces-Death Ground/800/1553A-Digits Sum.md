---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1553A
judul_DEATH: Digits Sum
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-22T20:54:00
tags:
  - math
  - number-theory
---
Sumber: [Problem - 1553A - Codeforces](https://codeforces.com/problemset/problem/1553/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1553A-Digits Sum

Diberikan suatu fungsi $S(x)$, dimana akan menjumlahkan jumlah digit dari angka $x$ dan mengembalikan nilai yang akan ditulis dalam sistem desimal (*mungkin angka nol dibelakang dihapus*). Misal $S(5)=5, S(10)=1, S(322)=7$.

Kita menyebut integer $x$ *menarik*, jika $S(x+1) < S(x)$. Tentukan berapa banyak angka menarik yang ada pada rentang $1 \leq x \leq n$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah. Suatu angka $x$ akan menarik jika bisa dibagi $10$, karena setiap penambahan sebanyak $10$, akan mencetak salah satu digit akhir tepat $0$. Ini artinya kita hanya perlu membagi $x$ dengan $10$. Namun, karena yang dicari adalah banyaknya digit $x+1$ yang menarik, maka rumusnya diganti dengan:

$$ans = \lfloor \frac{x+1}{10} \rfloor$$

Maka berikut implementasinya:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << (n+1) / 10 << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita pikirkan: sifat apa yang dimiliki semua bilangan menarik (*interesting numbers*)? Nah, jika sebuah bilangan $x$ tidak berakhir dengan 9, kita dapat memastikan bahwa $f(x+1) = f(x) + 1$, karena digit terakhir akan bertambah satu.

Bagaimana jika bilangan tersebut berakhir dengan 9? Maka digit terakhir akan menjadi 0. Jadi, tidak peduli apa yang terjadi pada digit lain, kita dapat mengatakan bahwa $f(x+1)$ pasti akan lebih kecil dari $f(x)$.

Oleh karena itu, masalah ini meminta kita untuk menghitung semua bilangan $x$ dengan $1 \le x \le n$ yang digit terakhirnya sama dengan 9. Tidak sulit untuk melihat bahwa jawabannya sama dengan $\lfloor \frac{n+1}{10} \rfloor$.

Ini menyimpulkan solusinya, karena sekarang kita dapat menjawab semua kasus uji dalam waktu $O(1)$, menghasilkan total waktu proses $O(t)$.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        cout << (n + 1) / 10 << '\n';
    }
}
```
## 3.2 | Analisis Pribadi

Ide solusiko sama dengan editorial. Memiliki kompleksitas yang sama efisienya yaitu $O(1)$. Jadi implementasiku sudah benar.
## 3.3 | Analisis Jawaban User Lain

Petunjuk dari editorial sudah benar dan tepat, sehingga ide jawaban pengguna lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<iostream>
main() {
    int t;
    std::cin >> t;
    while (t--) {
        int x;
        std::cin >> x;
        std::cout << (x + 1) / 10 << '\n';
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std

int w, n;
int main() {
    cin >> w;
    while (w--) {
        cin >> n;
        cout << (n + 1) / 10 << endl;
    }
    return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>

using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) static_cast < int > ((x).size())
#define int long long

signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (n + 1) / 10 << "\n";

    }
}
```