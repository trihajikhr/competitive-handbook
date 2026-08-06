---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1932A
judul_DEATH: Thorns and Coins
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-20T15:09:00
tags:
  - dynamic-programming
  - greedy
  - implementation
---
Sumber: [Problem - 1932A - Codeforces](https://codeforces.com/problemset/problem/1932/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1932A-Thorns and Coins

Terdapat sebuah sell dengan panjang $n$, dan terdapat $3$ rintangan di sepanjang sell ini. Rintangan yang ada pada sel sepanjang $n$ direpresentasikan oleh string yang memiliki panjang yang sama, yang terdiri dari karakter `@` untuk menandakan bahwa sell tersebut memiliki koint, `*` yang menandakan bahwa sell tersebut terdapat rintangan, dan `.` yang menandakan bahwa sell tersebut kosong.

Kita hanya bisa melakukan 2 cara melangkah, yaitu melangkah sepanjang 1 sell atau 2 sell. Jika kita bergerak ke sell berduri, maka permainan berakhir, dan tidak bisa lanjut ke sell selanjunya. Tentukan banyak koin maksimal yang bisa didapat dari sell yang diberikan.
 
<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, kita hanya perlu fokus untuk menghindari rintangan saja. Kita bisa melompati rintangan jika ada tepat satu rintangan didepan. Tapi jika terdapat 2 rintangan berjejeran, maka kita tidak bisa melewati rintangan tersebut, mengakibatkan kita berakhir mendarat di duri, dan permainan berakhir.

Sepanjang perulangan, hitung berapa banyak karakter `@` pada string yang ditraversal, hingga mencapai ujung sell, atau bertemu dengan sell dengan rintangan yang berjeran.

Berikut adalah implemetasiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i=0; i<n; i++) {
        if (s[i]=='*' && s[i+1]=='*') break;
        if (s[i]=='@') ans++;
    }
    cout << ans << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita maju $1$ jika sel berikutnya tidak memiliki duri, dan $2$ jika sebaliknya. Dengan melakukan ini, kita akan mengunjungi semua sel bebas duri yang dapat kita jangkau, dan dengan demikian mengumpulkan semua koin di sel-sel tersebut. Perhatikan bahwa jika kita berada di sel $i$, dan sel $i+1$ serta sel $i+2$ memiliki duri, maka kita hanya bisa melompat ke dalam duri dan dengan demikian mengakhiri permainan.

Oleh karena itu, kita perlu menghitung berapa banyak koin yang muncul dalam *string* sebelum *substring* `**`.

Implemetnasi editorial:

```cpp
#include <bits/stdc++.h>
 
using namespace std;
 
signed main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
 
    int t;
    cin >> t;
    for(int _ = 0; _ < t; ++_){
        int n, ans = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 1; i < n; i++) {
            ans += (s[i] == '@');
            if (s[i] == '*' && s[i - 1] == '*')
                break;
        }
        cout << ans << "\n";
    }
    return 0;
}
```

## 3.2 | Analisis Pribadi

Ini soal yang mudah, tapi berbagai cara implementasi menurutku tidak terlalu penting. Solusiku sendiri sudah menggunakan kompleksitas $O(n)$ dengan *early break*, jadi menurutku sudah efisien.
## 3.3 | Analisis Jawaban User Lain

Sebagai bahan evaluasi, diambil beberapa kode dari orang lain. Namun jika kompleksitas dan efisiensinya sama, maka anggap saja sudah benar:

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*' && s[i + 1] == '*') break;
            else if (s[i] == '@') a++;
        }
        cout << a << endl;
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<stdio.h>
int t, n, ans;
char s[55];
struct __readt__ {
    inline __readt__() {
        scanf("%d", & t);
    }
}

_readt___;
main() {
    scanf("%d%s", & n, s + 1);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '*' && s[i + 1] == '*') break;
        if (s[i] == '@') ++ans;
    }
    printf("%d\n", ans);
    nxt: if (--t) main();
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '@') ans++;
            if (s[i] == '*' && s[i + 1] == '*') break;
        }
        cout << ans << endl;
    }
}
```