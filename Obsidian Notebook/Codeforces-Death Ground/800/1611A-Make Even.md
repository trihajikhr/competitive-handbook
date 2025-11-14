---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1611A
judul_DEATH: Make Even
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-20T16:47:00
tags:
  - constructive-algorithms
  - math
---
Sumber: [Problem - 1611A - Codeforces](https://codeforces.com/problemset/problem/1611/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1611A-Make Even

Diberikan sebuah angka. Kita bisa memilih $l$ angka yang selalu dimulai dari kiri, dan melakukan reverse terhada angka tersebut, yang dimulai dari digit pertama hingga digit ke-$l$.

Tujuan kita adalah membuat angka yang diberikan menjadi genap dengan melakukan operasi tadi. Outputkan minimal operasi yang diperlukan untuk membuat angka menjadi genap.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah. Jika digit terakhir adalah genap, maka tidak diperlukan operasi sama sekali, atau $0$ operasi.

Jika digit terakhir bukan genap, melainkan digit yang paling depan, maka kita bisa melakukan operasi yang mereverse semua digit. Total operasi yang dibutuhkan hanyalah $1$.

Jika digit paling belakang atau paling depan bukan digit genap, tetapi ada digit genap pada angka ini (*mungkin ada di index bagian tengah*), maka dibutuhkan hanya $2$ operasi, yaitu melakukan reverse pertama untuk menjadikan digit depan menjadi genap, lalu melakukan oeprari reverse kedua untuk menjadikan digit paling belakang genap juga.

Tapi jika tidak ada digit genap sama sekali pada angka, maka outputkan saja $-1$.

Solusi ini mengarah pada fakta, bahwa jawaban yang tersedia, hanyalah $-1,0,1,2$ saja. 

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;
    if ((s.back() - '0') % 2 == 0) {
        cout << "0\n";
    } else if ((s.front() - '0') % 2 == 0){
        cout << "1\n";
    } else {
        for (char& c: s) {
            if ((c-'0') % 2 == 0) {
                cout << "2\n";
                return;
            }
        }
        cout << "-1\n";
    }
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


Jika bilangan tersebut sudah genap, maka tidak ada yang perlu dilakukan, sehingga jawabannya dalam kasus ini adalah 0.

Sekarang mari kita ingat kembali keterbagian dengan 2: suatu bilangan habis dibagi 2 jika dan hanya jika digit terakhirnya habis dibagi 2 (yaitu, genap).

Dari sini, dapat disimpulkan bahwa jika tidak ada digit genap dalam bilangan kita, maka jawabannya adalah -1.

Mari kita lihat operasi kita. Apa yang terjadi? Digit pertama selalu bertukar dengan digit yang bernomor $l$. Secara khusus, ketika kita membalik seluruh bilangan, digit pertama bertukar dengan digit terakhir. Perhatikan bahwa tidak ada digit lain, selain digit pertama pada saat ini, yang bisa menjadi digit terakhir.

Oleh karena itu, Anda dapat melakukan ini: jika digit pertama dari suatu bilangan habis dibagi 2 (yaitu, genap), maka kita membalik seluruh bilangan. Digit pertama akan menjadi digit terakhir, dan bilangan tersebut akan menjadi genap. Oleh karena itu, Anda hanya perlu melakukan satu operasi.

Lalu, bagaimana jika digit pertama dari suatu bilangan ganjil? Dalam kasus ini, kita dapat menemukan digit genap pertama dalam bilangan tersebut (misalkan berada pada posisi $x$), dan membalik *prefix* (awalan) sepanjang $x$ (dalam satu operasi). Sekarang, digit pertama dari bilangan kita telah menjadi genap, dan kita dapat menggunakan kasus sebelumnya (satu operasi lagi). Dengan demikian, kita hanya akan melakukan 2 operasi.

Implementasi editorial:

```cpp
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        string n;
        cin >> n;
        if((n.back() - '0') % 2 == 0) {
            cout << "0\n";
            continue;
        }
        if((n[0] - '0') % 2 == 0) {
            cout << "1\n";
            continue;
        }
        int count_2 = count(n.begin(), n.end(), '2');
        int count_4 = count(n.begin(), n.end(), '4');
        int count_6 = count(n.begin(), n.end(), '6');
        int count_8 = count(n.begin(), n.end(), '8');
        if(count_2 > 0 || count_4 > 0 || count_6 > 0 || count_8 > 0) {
            cout << "2\n";
            continue;
        }
        cout << "-1\n";
    }
    return 0;
}
```

## 3.2 | Analisis Pribadi

Ide dan konsep dari editorial sudah sama dengan implementasiku. Bahkan mungkin jauh lebih efisien kodeku, karena tidak melakukan pencarian digit genap sendiri-sendiri seperti pada impplementasi editorial. 
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a = -1;
        if (n % 2 == 0) {
            a = 0;
        } else {
            n = n / 10;
            while (n > 0) {
                if (n % 2 == 0) {
                    if (n < 10) a = 1;
                    else a = 2;
                }
                n = n / 10;
            }
        }
        cout << a << endl;
    }
}
```

Hampir sama dengan kodeku, bedanya kode ini tetap menggunakan tipe data integer yaitu `long long`, dan melakukan pencarian dan pengecekan digit dari belakang dengan melakukan operasi $n/=10$.
### 2 | Jawaban Kedua

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    string s;
    for (cin >> t; t--;) {
        cin >> s;
        int a = s[0] - '0', b = s.back() - '0', c = 0;
        for (char i : s)
            if ((i - '0') % 2 == 0) c++;
        cout << (b % 2 ? a % 2 ? c ? 2 : -1 : 1 : 0) << endl;
    }
}
```

Ini baru pertama kali aku melihat kondisional ternary yang kompleks seperti ini:

```cpp
cout << (b % 2 ? a % 2 ? c ? 2 : -1 : 1 : 0) << endl;
```

Tapi bisa digunakan sebagai tambahan tips & trick kedepanya.
### 3 | Jawaban Ketiga

```cpp
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << 0 << endl;
            continue;
        }

        string s = to_string(n);
        bool hasEvenDigit = false;
        for (char c : s) {
            if ((c - '0') % 2 == 0) {
                hasEvenDigit = true;
                break;
            }
        }

        if (!hasEvenDigit) {
            cout << -1 << endl;
        } else {
            if ((s[0] - '0') % 2 == 0) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }

    return 0;
}
```

Memperlakukan inputan sebagai integer dan juga sebagai string (*hasil konversi*).