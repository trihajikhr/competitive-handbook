---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1974B
judul_DEATH: Symmetric Encoding
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-23T19:00:00
tags:
  - implementation
  - sorting
---
Sumber: [Problem - 1974B - Codeforces](https://codeforces.com/problemset/problem/1974/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1974B-Symmetric Encoding

Diberikan sebuah string $s$. Kita diminta untuk melakukan encoding, dengan aturan berikut:

- Pertama, bangun sebuah string $r$, yang mana tersusun dari tiap karakter-karakter yang berbeda dari string $s$, yang disusun secara terurut secara alphabetis.
- Lalu, lakukan encoding dengan cara mengganti setiap karakter $s_i$, dengan karakter yang berlawanan secara simetris yang ada pada string $r$ (*sulit dijelaskan disini, lebih baik kunjungi link problemnya langsung untuk mendapatkan gambaran yang lebih jelas*). 

Misal terdapat string `codeforces`, maka encoding akan dilakukan dengan cara berikut:

- Bangun string $r$ yang hanya terdiri karakter unik dari string $s$ yang sudah diurutkan. Maka didapatkan `cdefors`.
- Lalu ganti $s_i$, yaitu `c` menjadi karakter dari sisi simetri dari karakter yang sama pada string $r$, yaitu `s`.
- Lakukan terus menenus hingga akhir, dan akan didapatkan string hasil encoding adalah `serofedsoc`.

Kamu diberikan string yang sudah di encoding. Yang perlu kamu lakukan adalah melakukan operasi decoding, atau mengambalikan string asli $s$.


<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama ambil karakter yang berbeda pada string yang diberikan. Ini bisa dilakukan dengan menggunakan bantuan struktur data `set`.  Struktur data ini juga mengurutkan data yang disimpanya, sehingga penggunaan struktur data ini mengerjakan 2 tugas penting sekaligus.

Setelah diambil, simpan pada vector. Ini karena data yang tersimpan pada `set` tidak bisa diakses dengan menggunakan operator `[]`, sehingga dipindah ke vector.

Untuk mencegah pencarian masing-masing lokasi karakter yang akan membuat kompleksitas membengkak, lebih baik gunakan struktur data bantuan lain, yang bisa menyimpan nilai kunci dan value (*key and value*), yaitu `unordered_map` atau `map`. Kita bisa membangun lewat traversal terhadap vector yang menyimpan karakter unik. Beri kunci berupa karakter $uniq[i]$, dan valuenya adalah $uniq[uniq.size()-i-1]$.

Setelah itu, lakukan traversal pada string $s$, dan ganti setiap $s_i$ dengan `unordereded_map` yang sudah dibangun sebelumnya, sehingga operasi berikut adalah solusi akhir: $s[i]=dasmap[s[i]]$.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> daset;
    vector<char> uniq;
    unordered_map<char, int> dasmap;
    for (char& c : s) {
        daset.insert(c);
    }

    for (const auto& x : daset) {
        uniq.push_back(x);
    }

    for (int i=0; i<uniq.size(); i++) {
        dasmap[uniq[i]] = uniq[uniq.size() - i -1];
    }

    for (int i=0; i<n; i++) {
        s[i] = dasmap[s[i]];
    }

    cout << s << '\n';
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

Solusi ini cukup cepat menurutku, karena kompleksitas paling tinggi hanyalah $O(n)$, dan hanya dilakukan untuk penyimpanan karakter unik, memindahkan karakter unik ke vector, membangun key value pair, dan juga mengganti tiap string $s$. 

Namun kecepatan ini datang dengan penggunaan memory yang lebih.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita buat sebuah *string* $r$ sesuai dengan definisi dari kondisi tersebut: kita tulis semua huruf dari $s$ sekali dalam urutan menaik (*ascending order*).

Setelah itu, kita hanya perlu mengganti semua karakter di $s$ dengan karakter simetrisnya di dalam *string* $r$. Panjang dari *string* $r$ tidak melebihi $26$, jadi posisi karakter ini dapat ditemukan dengan pencarian linier (*linear search*).

Implementasi editorial:

```py
def solve():
    n = int(input())
    b = input()
    cnt = [0] * 26
    for c in b:
        cnt[ord(c) - ord('a')] = 1
    tmp = ''
    for i in range(26):
        if cnt[i] > 0:
            tmp += chr(ord('a') + i)
    a = ''
    for c in b:
        a += tmp[-1 - tmp.find(c)]
    print(a)
    
 
for _ in range(int(input())):
    solve()
```

## 3.2 | Analisis Pribadi

Dari segi kompleksitas runtime, kodeku sudah cepat. Sehingga sudah benar dan efisien.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        string s;
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end()), 
	        t.erase(unique(t.begin(), t.end()), t.end());
	        
        for (char a: s) 
        cout << t.end()[-(find(t.begin(), t.end(), a) - t.begin()) - 1];
        cout << endl;
    }
}
```

string $s$ disimpan juga pada $t$, yang kemudian diurutkan secara ascending, lalu sisakan satu karakter unik, yang lain dihapus.

Bagian kode ini:

```cpp
for (char a: s) 
    cout << t.end()[-(find(t.begin(), t.end(), a) - t.begin()) - 1];
```

Aku masih tidak paham, terlalu kompleks. Seharusnya bisa lebih readable.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int t;
int n;
int main() {
    cin >> t;
    while (t--) {
        set < char > v;
        string s, a, b;

        cin >> n;
        cin >> s;
        for (char c: s) v.insert(c);
        for (char c: v) a += c;
        for (int i = 0; i < n; i++) {
            int d = a.find(s[i]);
            b += a[a.size() - d - 1];
        }
        cout << b << endl;
    }
}
```

Hampir mirip denganku, namun program ini membangun string decoding dari string $s$ dengan cara membuat variabel $b$, yang  diisi oleh karakter simetri dari string unik yang ada pada variabel $a$. Pencarian karakter unik yang sesuai dengan $s_i$ dilakukan dengan menggunakan pencarian linear, yaitu fungsi `find()` yang akan mengembalikan indeks lokasi, dan menggunakan aturan simetri untuk mendapatkan nilai yang sesuai: $n-i-1$.
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int i, j, k, n, m, t;
char a[666];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        map < char, char > mp;
        string s;
        m = 0;
        cin >> n >> s;
        for (auto c: s) {
            if (!mp[c]) {
                mp[c] = 1;
                a[++m] = c;
            }
        }
        sort(a + 1, a + m + 1);
        for (i = 1; i <= m; i++) {
            mp[a[i]] = a[m + 1 - i];
        }
        for (auto c: s) cout << mp[c];
        cout << '\n';
    }
}
```

Solusi yang hampir mirip denganku, namun lebih efektif karena tidak melakukan penggantian pada string $s$, melainkan langsung saja outputkan valuenya.