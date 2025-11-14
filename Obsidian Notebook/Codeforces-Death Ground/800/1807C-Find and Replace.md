---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1807C
judul_DEATH: Find and Replace
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-22T13:14:00
tags:
  - greedy
  - implementation
  - string
---
Sumber: [Problem - 1807C - Codeforces](https://codeforces.com/problemset/problem/1807/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1807C-Find and Replace

Diberikan sebuah string $s$ dengan panjang $n$. Tujuan kita adalah membuat string tersebut menjadi string biner, atau hanya terdiri dari karakter $0$ dan $1$, namun secara selang-seling, dengan menggunakan aturan berikut:

- Dalam satu operasi, pilih salah satu karakter, misal karakter $c$.
- Ganti semua karakter $c$ yang ada pada $s$ menjadi $1$ atau $0$.

Tentukan apakah mungkin menjadikan string $s$ terdiri dari $0$ dan $1$ secara selang-seling atau tidak.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Operasi berlaku untuk semua karakter yang sama, sehingga hal yang menjadikan sebuah string $s$ mungkin untuk menjadi string biner selang-seling atau tidak, adalah bergantung pada lokasi indeks karakter-karakter yang sama.

Lokasi karakter-karakter yang sama tidak boleh ada yang berjarak atau memiliki selisih ganjil. Oleh karena itu, kita bisa menggunakan `unordered_map`, dengan kunci karakter, dan value berupa daftar lokasi indeks karakter-karakter tersebut pada $s$.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, vector<int>> dasmap;
    for (int i=0; i<n; i++) {
        if (!dasmap[s[i]].empty()) {
            if ((i-dasmap[s[i]].back())%2 == 1) {
                cout << "NO\n";
                return;
            }
        } else {
            dasmap[s[i]].push_back(i);
        }
    }

    cout << "YES\n";
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

Aku merasa bahwa menyimpan daftar indeks sepertinya tidak perlu. Yang dibutuhkan hanyalah indeks pertama kemunculan karakter pada string, dan menjadikan nilai tersebut sebagai acuan. Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<unordered_map>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, pair<bool, int>> dasmap;
        dasmap.reserve(n);
        bool stop = false;
        for (int i=0; i<n; i++) {
            if (dasmap[s[i]].first) {
                if ((i-dasmap[s[i]].second)% 2 == 1) {
                    stop = true;
                    break;
                }
            } else {
                dasmap[s[i]].second = i;
                dasmap[s[i]].first = true;
            }
        }
        cout << (stop ? "NO" : "YES") << '\n';
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita selesaikan masalah yang lebih sulit: Diberikan sebuah string $s$ dan sebuah string biner $t$, bisakah kita mengubah $s$ menjadi $t$ menggunakan operasi cari dan ganti (*find and replace*?)

Kita bisa saja mengulang (*iterate*) melalui setiap karakter dari $s$ dan melihat bit mana yang menjadi tujuannya di $t$ (yaitu, $s_i \to t_i$ untuk setiap $i$). Catat setiap perubahan, dan periksa apakah ada huruf tertentu yang perlu diubah menjadi **0 dan 1** secara bersamaan. Jika ada huruf seperti itu, maka itu **tidak mungkin** dilakukan, karena setiap operasi memerlukan penggantian semua kemunculan (*occurrences*) suatu huruf menjadi bit yang sama. Jika tidak ada, maka itu **mungkin** dilakukan, dan kita dapat langsung mengubah setiap huruf menjadi bit yang seharusnya. (Lihat implementasinya untuk pemahaman yang lebih baik.)

Sekarang, untuk masalah ini, karena hanya ada dua string biner bergantian (*alternating binary strings*) dengan panjang $n$ ($01010...$ dan $10101...$), kita cukup memeriksa keduanya. (Sebenarnya, kita hanya perlu memeriksa satu saja — apakah Anda tahu alasannya?) Kompleksitas waktunya adalah $O(n)$.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 200007;
const int MOD = 1000000007;
 
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int mp[26];
	for (int i = 0; i < 26; i++) {
		mp[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int curr = (s[i] - 'a');
		if (mp[curr] == -1) {
			mp[curr] = (i % 2);
		}
		else {
			if (mp[curr] != (i % 2)) {cout << "NO\n"; return;}
		}
	}
	cout << "YES\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt; for (int i = 1; i <= tt; i++) {solve();}
	// solve();
}
```

## 3.2 | Analisis Pribadi

Pendekatan editorial adalah memastikan bahwa titik kemunculan karakter-karakter pertama pada string $s$ memiliki paritas yang sama dengan indeks kemunculan karakter yang sama pada string $s$. Jika ia karakter pertama muncul di paritas ganjil, maka kemunculan karakter yang sama pada string $s$ juga harus muncul di indeks dengan paritas ganjil juga. 

Konsep dan ide hampir sama, namun kompleksitas sudah sama. Kodeku sudah benar dan efisien.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int t;
int main() {
    cin >> t;
    while (t--) {
        int n;
        char a[2010];
        bool f = 1;
        cin >> n >> a;
        for (int i = 0; i < n; i += 2)
            for (int j = 1; j < n; j += 2)
                if (a[i] == a[j])
                    f = 0;
        f ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
```

Kompleksitas $O(n^2)$. Benar secara konsep, dengan menggunakan 2 perulangan, karena batasan panjang string tergolong kecil.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>

#define read(a) for (auto & c: a) cin >> c
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    char a[26] = {'?'}, b[26] = {'?'};
    
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a'] = i % 2 ? '1' : '0';
    }
    
    for (int i = 0; i < n; i++) {
        s[i] = a[s[i] - 'a'];
    }
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            return void(cout << "NO" << '\n');
    }
    
    cout << "YES" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
```

Mendeteksi semua paritas, lalu mengganti string $s$ menjadi karakter $1$ dan karakter $0$ berdasarkan paritas yang disimpan di array $a$. Setelah itu, lakukan pengecekan, apakah ada karakter sama yang berdekatan pada string. Jika ada, maka outputkan `NO`.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        string s;
        cin >> n >> s;
        int mp[27];
        for(int i = 0; i < 26; i++){
            mp[i] = -1;
        }
        int flag = 1;
        for(int i = 0; i < n; i++){
            int current = s[i] - 'a';
            if(mp[current] == -1){
                mp[current] = i % 2;
            }else{
                if(mp[current] != i % 2){
                    flag = 0;
                } 
            }
        }    
        if(flag){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
```

Pendekatan yang sama secara konsep dan implementasi dengan editorial.