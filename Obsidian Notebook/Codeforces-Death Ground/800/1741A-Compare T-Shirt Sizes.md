---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1741A
judul_DEATH: Compare T-Shirt Sizes
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-20T15:34:00
tags:
  - implementation
  - string
---
Sumber: [Problem - 1741A - Codeforces](https://codeforces.com/problemset/problem/1741/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1741A-Compare T-Shirt Sizes

Diberikan ukuran baju, yang opsinya adalah sebagai berikut:
- L 
- M
- S
- XXX...X, lalu diikuti oleh S atau L

DIberikan 2 buah inputan ukuran baju, tentukan karakter perbandingan yang sesuai.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Nilai dari $XXXS < XXXL$. Aku memiliki ide untuk untuk memberikan bobot pada setiap ukuran baju. Untuk setiap karakter $X$ ,maka bobotnya bertambah $1$, termasuk untuk karakter $L$. Sedangkan ketika menemui karakter $S$, total bobotnya dikalikan dengan $-1$, membuatnya bernilai negatif bernilai jauh lebih kecil.

Untuk karakter $M$, dia akan otomatis menerima bobot $1$. Setelah itu, bobot antara ukuran baju pertama dengan baju kedua dibandingkan untuk mendapatkan simbol perbandingan atau jawaban yang sesuai.

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

auto cek(const string& str) -> int {
    int ans = 1;
    for (char c: str) {
        if (c=='X' || c=='L') ans++;
        else if (c=='S') ans *= -1;
    }
    return ans;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int x = cek(a), y  = cek(b);
    if (x < y) cout << "<";
    else if (x > y) cout << ">";
    else if (x == y) cout << "=";
    cout << "\n";

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

Misalnya $s_a$ dan $s_b$ masing-masing adalah karakter terakhir dari *string* (baris) $a$ dan $b$. Dan $|a|$, $|b|$ adalah ukuran (panjang) dari *string* tersebut.

1. $s_a \neq s_b$ : Maka jawabannya hanya bergantung pada $s_a$ dan $s_b$ dan didefinisikan secara unik sebagai invers dari $s_a$ ke $s_b$.
	* "<" jika $s_a > s_b$
	* ">" jika $s_a < s_b$
	  
	(Karena karakter S, M, L berada dalam urutan terbalik di alfabet).

2. $s_a = s_b$ :
	* **$|a| = |b|$**. Maka jawabannya adalah "=" (Sama dengan). Ini juga mencakup kasus $s_a = s_b = \text{M}$.
	* **$s_a = s_b = \text{S}$**. Maka semakin besar ukuran *string* ($|a|$ atau $|b|$), semakin kecil ukuran kaus. Artinya, jawabannya adalah "<" jika $|a| > |b|$ dan ">" jika $|a| < |b|$.
	* **$s_a = s_b = \text{L}$**. Maka semakin besar ukuran *string* ($|a|$ atau $|b|$), semakin besar ukuran kaus. Artinya, jawabannya adalah "<" jika $|a| < |b|$ dan ">" jika $|a| > |b|$.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()
#define eb emplace_back
 
 
void ct(char c) {
    cout << c << '\n';
}
 
void solve() {
    string a,b; cin >> a >> b;
    char ca = a.back();
    char cb = b.back();
    if (ca == cb) {
        if (sz(a) == sz(b)) cout << '=';
        else if (ca == 'S') {
            cout << (sz(a) < sz(b) ? '>' : '<');
        } else {
            cout << (sz(a) < sz(b) ? '<' : '>');
        }
    }else cout << (ca < cb ? '>' : '<');
    cout << '\n';
}
 
int main() {
    int t;
    cin >> t;
 
    forn(tt, t) {
        solve();
    }
}
```
## 3.2 | Analisis Pribadi

Pendekatanku adalah melakukan traversal tehadap string, namun pendekatan editorial sepertinya jauh lebih efisien. Ini karena solusi editorial hanya melakukan pengecekan pada karakter terakhir dari string, dan panjang string, jauh lebih efisien dan tidak ada kompleksitas $O(n)$ sama sekali.

Oleh karena itu, beriut adalah implemtnasiku yang sudah diperbaiki:

```cpp
#include<iostream>
using namespace std;

#define sz(v) v.size()
void solve() {
    string a, b;
    cin >> a >> b;
    char x = a.back();
    char y = b.back();
    if (x==y) {
        if (sz(a) == sz(b)) cout << "=";
        else if (x == 'S') {
            cout << (sz(a) > sz(b) ? "<" : ">");
        } else {
            cout << (sz(a) > sz(b) ? ">" : "<");
        }
    } else {
        cout << (x < y ? ">" : "<" );
    }
    cout << "\n";
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
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int calc(char c) {
    return c == 'M' ? 0 : (c == 'S' ? -1 : 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        string a, b;
        cin >> a >> b;
        int x = calc(a.back());
        int y = calc(b.back());
        x *= a.size();
        y *= b.size();
        cout << (x == y ? "=" : (x < y ? "<" : ">")) << '\n';
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2 * 1e5 + 5;
#define sz(v)(int) v.size()

void solve() {
    string s, m;
    cin >> s >> m;
    char so = s.back();
    char mo = m.back();

    if (so == mo) {
        if (sz(s) == sz(m)) cout << '=';
        else if (so == 'S') {
            cout << (sz(s) < sz(m) ? '>' : '<');
        } else {
            cout << (sz(s) < sz(m) ? '<' : '>');
        }
    } else cout << (so < mo ? '>' : '<');
    cout << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
```
### 3 | Jawaban Ketiga

```cpp
// time-limit: 3000
/**
 * Author: distiled
 */
#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG#include </Users/distiled/codeStuff/templates/debug.h>

#else
#define dbg(x...)
#endif
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s, t;
        cin >> s >> t;
        auto calc = [ & ](string & str) -> int {
            if (str == "M")
                return 0;
            int cnt = str.size();
            return cnt * (str[str.size() - 1] == 'L' ? 1 : -1);
        };
        if (calc(s) < calc(t)) {
            cout << "<\n";
        } else if (calc(s) > calc(t)) {
            cout << ">\n";
        } else {
            cout << "=\n";
        }
    }
}
```