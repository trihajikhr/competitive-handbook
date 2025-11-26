---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 96A
judul_DEATH: Football
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips:
date_learned: 2025-11-26T11:18:00
tags:
  - implementation
  - strings
---
Sumber: [Problem - 96A - Codeforces](https://codeforces.com/problemset/problem/96/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 96A-Football

Dari inputan string biner yang diberikan, tentukan apakah ada substring berurutan 0 atau 1, misal terdapat substring 0000000 atau 1111111 dalam inputan string yang diberikan. Tentukankanlah.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, ada dua macam pendekatan yang bisa digunakan disini, karena ini adalah soal yang termasuknya mudah. Kita bisa menggunakan pencarian manual, dengan cara menghitung, apakah ada suatu karakter (etnah $1$ atau $0$) yang sama, yang muncul berurutan sebanyak 7 kali. Mungkin dengan cara seperti ini:

```cpp
#include <iostream>
#include <string>
using namespace std;
 
auto main() -> int {
    string s;
    cin >> s;
    int one = 0;
    int zer = 0;
    for (char c : s) {
        if (c == '0') {
            zer++;
            one = 0;
        } else if (c == '1') {
            one++;
            zer = 0;
        }
 
        if (one == 7 || zer == 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
```

Atau, menggunakan cara singkat dengan menggunakan fungsi `find()`, yang akan mengembalikan indeks paling awal jika ditemukan substring berurutan $0$ atau $1$. Yaitu dengan cara seperti ini:

```cpp
#include <iostream>
#include <string>
using namespace std;
auto main() -> int {
    string s;
    cin >> s;
    if (s.find("1111111") != string::npos || s.find("0000000") != string::npos) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
```

Jika substring tidak ditemukan, maka fungsi `find()` akan mengembalikan `string::npos`. Cara kedua ini lebih singkat dan lebih clean, sehingga aku menggunakan cara kedua ini. Memanfaatkan fungsi STL yang sudah ada, dan pastinya lebih baik daripada implementasi manual.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Dalam masalah ini, Anda harus menemukan *substring* terpanjang yang terdiri dari karakter yang sama dan membandingkannya dengan 7.
## 3.2 | Analisis Pribadi

Editorialnya singkat, dan memang seharusnya begitu karena soal ini juga tidak terlalu membutuhkan logika berat untuk diselesaikan.
## 3.3 | Analisis Jawaban User Lain

Ternyata jawaban kebanyakan user lain menggunakan cara yang sama, yaitu menggunakan fungsi `find()`. Jadi implementasiku sudah benar.

Tapi kebanyakan dari mereka menggunakan $-1$ sebagai alias dari `string::npos`. Ketika substring tidak ditemukan, maka akan mengembalikan $-1$, dan mereka menggunakan ini, dan ini masih valid.
### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	cout<<(s.find("0000000")!=-1 || s.find("1111111")!=-1 ? "YES":"NO");
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.find("0000000") != -1 or s.find("1111111") != -1) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.find("0000000") < 100 || s.find("1111111") < 100) {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}
```

