---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1941C
judul_DEATH: Rudolf and the Ugly String
teori_DEATH:
sumber:
  - codeforces.com
ada_tips?:
date_learned: 2025-10-05T19:55:00
tags:
---
Sumber: [Problem - 1941C - Codeforces](https://codeforces.com/problemset/problem/1941/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1941C-Rudolf and the Ugly String

Terdapat sebuah string $s$ yang diberikan. Tugas kita adalah menghapus semua kemunculan substring `map` dan `pie` seandainya ada didalam string, tapi dengan menghapus seminimal mungkin karakter. Outputkan jumlah karakter minimum yang dihapus, untuk memastikan string $s$ tidak memiliki dua substring tersebut.

Well, solusi dari problem ini mudah, sangat mudah.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Substring `map`, bisa kita hancurkan susunanya dengan menghapus karakter yang ada ditengahnya, yaitu karakter `a`. Ini jauh lebih aman daripada menghapus karakter yang ada disebelah kiri atau kanan, karena ada potensi tersusunya lagi substring terlarang dari hasil penggabungan substring tersebut dengan karakter-karakter disebelahnya. Hal tersebut juga berlaku dengan substring `pie`.

Ini artinya, untuk setiap kemunculan dari substring `pie` atau `map`, kita cukup menghilangkan 1 karakter. Atau dengan kata lain, jawaban dari problem ini adalah menghitung banyaknya kemunculan substring `pie` dan `map` yang ada pada string $s$!



<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Untuk memecahkan masalah ini, Anda perlu menemukan semua kemunculan substring "**pie**", "**map**", "**mapie**" dalam string dan menghapus karakter tengah pada masing-masing substring tersebut. Dengan cara ini, Anda akan menghapus jumlah karakter minimum untuk memastikan bahwa string tersebut tidak lagi mengandung substring "**pie**" dan "**map**".

Berikut adalah kode editorial:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long c = 0; c < t; c++) {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        vector < long long > va;
        for (string sul: {
                "mapie",
                "pie",
                "map"
            }) {
            for (size_t pos = 0;
                (pos = s.find(sul, pos)) != string::npos;) {
                s[pos + sul.length() / 2] = '?';
                va.push_back(pos + sul.length() / 2);
            }
        }
        cout << va.size() << endl;
    }
    return 0;
}
```


## 3.2 | Analisis Pribadi

Aku mengambil 3 karakter dari string $s$ dengan fungsi `substring()`, dan menetukan apakah string tersebut adalah `pie` atau `map`. Jika benar, maka variabel `pos`, yang merupakan variabel yang mengawali titik paling kiri pengambilan substring akan maju sebanyak 2 index. Kita tambahkan `pos` dengan 2 saja, karena penambahkan nilai ke tiga akan dilakukan oleh increment bagian luar.

Lalu, jika tidak, maka kondisional tersebut akan dilewati, dan akan maju ke index selanjutnya, dengan increment luar yaitu `pos++`.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve() {
    int n, ans=0, pos=0;
    string s;
    cin >> n;
    cin >> s;
    while (pos<=n-3) {
        string temp = s.substr(pos,3);
        if (temp=="pie" || temp=="map") {
            ans++, pos+=2;
        }
        pos++;
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

Dann... 

Menurutku, implementasiku jauh lebih simple daripada jawaban dari editorial, karena lebih readable dan sederhana.

Tapi secara kompleksitas, keduanya sama. Sama-sama melakukan sliding window untuk tiap 3 karakter dari string, dan sama penggunaan memory.

Sebenarnya kode ini juga masih bisa dibuat lebih efisien lagi, yaitu tanpa membuat string bantu, melainkan langsung mengandalkan kondisional, seperti:

```cpp
for(int i=0; i<n-2; i++) {
	if(
	(s[i]=='m' && s[i+1]=='a' && s[i+2]=='p') ||
	(s[i]=='p' && s[i+1]=='i' && s[i+2]=='e')
	) ans++;
}
```

## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p') {
                c++;
                i += 2;
            } else if (s[i] == 'p' && s[i + 1] == 'i' && s[i + 2] == 'e') {
                c++;
                i += 2;
            }
        }
        cout << c << endl;
    }
}
```

Ini adalah contoh kode yang menggunakan kondisional, sama seperti penjelanku sebelumnya.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (s.substr(i, 3) == "map" || s.substr(i, 3) == "pie") {
                s[i + 2] = 'q';
                c++;
            }
        }
        cout << c << endl;
    }
}
```

Hampir sama seperti jawabanku, menggunakan fungsi `substring()`.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<long long> vl;
typedef vector<vector<long long>> vvl;
typedef vector<pair<long long, long long>> vpll;
typedef vector<string> vs;
typedef pair<long long, long long> pll;
typedef pair<long long, string> pls;
typedef map<long long, string> mls;
typedef unordered_map<long long, string> umls;
typedef set<string> ss;
typedef unordered_set<string> uss;
typedef multiset<string> mss;
#define nn '\n'
#define fo(x,n) for(ll i=x; i<n; i++)
#define fo2(x,n) for(ll j=x; j<n; j++)
#define fob(x, n) for(ll k=n-1; k>=x; k--)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}

void lesgo();

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t;
    cin >> t;
    fo(0,t){
        lesgo();
    }
    return 0;
}

void lesgo(){
    int n, count = 0;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n-2; i++){
        if(str[i] == 'p' && str[i+1] == 'i' && str[i+2] == 'e'){
            count++;
            i += 2;
        }
        else if(str[i] == 'm' && str[i+1] == 'a' && str[i+2] == 'p'){
            count++;
            i += 2;
        }
    }
    cout << count << nn;
}
```

Hampir sama seperti jawaban pertama, menggunakna kondisional juga, tapi entah kenapa jawaban ini memiliki execution time paling cepat (15 ms) 🤔?