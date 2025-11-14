---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 514A
judul_DEATH: Chewbaсca and Number
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips: false
date_learned: 2025-10-29T10:18:00
tags:
  - greedy
  - implementation
---
Sumber: [Problem - 514A - Chewbaсca and Number](https://codeforces.com/problemset/problem/514/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 514A-Chewbaсca and Number

Diberikan sebuah angka $x (1 \leq x \leq 10^{18})$, dan angka ini tidak diawali oleh angka $0$. Rubah angka ini mejadi angka dengan nilai seminimal mungkin dengan melakukan inversi pada digit $t$, dengan melakukan operasi $9-t$. Pastikan angka hasil invers tidak tidak diawali oleh angka $0$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Sederhana, kita hanya perlu menerima angka $x$ sebagai string, misal string $s$. Lalu setelah itu, lakukan traversal dari depan, dimana jika terdapat angka yang lebih dari $4$, maka isi $s_i=9 - s_i$. Ini karena untuk setiap $s_i \in \{5,6,7,8,9\}$, maka operasi $9-s_i < s_i$. Tapi kita perlu memasukann pengecualian tepat ketika $s_1$, dimana jika $s_1 \equiv 9$, maka kita tidak bisa melakukan operasi inversi, karena akan membuat angka hasil inversi diawali dengan $0$, sehingga kita skip.

Karena angka-angka dalam string $s$ bertipe data char ketika kita mengaksesnya selama traversal, maka operasi perbandingan dan aritmatika yang dilakukan juga harus mengikuti aturan tipe data char.

Berikut adalah implementasikku yang sudah benar:

```cpp
#include<iostream>
#include<string>
using namespace std;

auto main() -> int {
    string s;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (i==0  && s[i]=='9') continue;
        if (s[i] > '4') s[i] = '9' - (s[i]-'0');
    }
    cout << s;
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Sudah jelas bahwa semua digit yang lebih besar dari $4$ perlu diinversi. Satu-satunya pengecualian adalah angka $\mathbf{9}$, jika ia adalah digit pertama.

Kompleksitas: $O(n \; length)$

## 3.2 | Analisis Pribadi

Solusi problem ini sederhana, sehingga jawabanku yang sudah benar tidak perlu dirubah. Tapi aku ingin merubahnya sedikit menjadi lebih pendek, dan kode ini juga benar:

```cpp
#include<iostream>
#include<string>
using namespace std;

auto main() -> int {
    string s; cin >> s;
    for (char& c: s) if (c >= '5') c = '9' - (c-'0');
    if (s[0]=='0')s[0]='9';
    cout << s;
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Ide dan konsep dari editorial sudah merupakan yang paling efisien, sehingga jawaban dari pengguna lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (char & c: s)
        if (c >= '5') c = '9' - (c - '0');
    if (s[0] == '0') s[0] = '9';
    cout << s << endl;
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

signed main() {
	string s; cin >> s;
	for (char& c : s) c = min(c, char('9' - c + '0'));
	if (s[0] == '0') s[0] = '9';
	cout << s;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '5') s[i] = ('9' - s[i]) + '0';
    }
    if (s[0] == '0') s[0] = '9';
    cout << s << '\n';
}
```