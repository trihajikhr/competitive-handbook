---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 1873C
judul_DEATH: Target Practice
sumber:
  - codeforces.com
rating: 800
date_learned: 2025-12-05T18:38:00
tags:
---
Sumber: [Problem - 1873C - Codeforces](https://codeforces.com/problemset/problem/1873/C)

```ad-tip
title:🛡️ Review Death Ground
```

<br/>

---
# 1 | 1873C-Target Practice

Solusinya mudah, kita hanya perlu melakukan implementasi sederhana yang mengandalkan percabangan. Kita bisa memulai percabangan dengan kondisional yang mengecek posisi tengah terlebih dahulu, lalu baru menurun satu demi satu.

Kita tidak perlu menggunakan array dua dimensi, cukup gunakan "perlakuan" dua dimensi pada inputaan yang diberikan.

Berikut implementasiku yang sudah benar:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int ans = 0;
    for (int i=1; i<=10; i++) {
        for (int j=1; j<=10; j++) {
            char x;
            cin >> x;
            if (x=='X') {
                if (i>=5 && i <=6 && j>=5 && j <=6) {
                    ans+=5;
                } else if (i>=4 && i<=7 && j>=4 && j <= 7) {
                    ans+=4;
                } else if (i>=3 && i<=8 && j>=3 && j <= 8) {
                    ans+=3;
                } else if (i >=2 && i <= 9 && j >= 2 && j <= 9) {
                    ans +=2;
                } else ans++;
            }
        }
    }
    cout << ans << "\n";
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
# 2 | Analisis Singkat

## 2.1 | Cara singkat

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    char c;
    int num = 0, i, j;
    for (i = 1; i <= 10; i++)
      for (j = 1; j <= 10; j++) {
        cin >> c;
        if (c == 'X') {
          num += min(min(i, 10 - i + 1), min(j, 10 - j + 1));
        }
      }
    cout << num << endl;
  }
}
```

Cara yang clever! Kita hanya perlu menggunakan nilai terkecil, dan petak pada sebelah kiri atas sebagai acuan. Ini membuat kita tidak perlu menggunakan percabangan yang terlalu banyak.

Ketika nilai $i$ atau $j$ besar, maka kita gunakan saja pembalikan dengan $10-i+1$ dan $10-j+1$, sehingga kita hanay perlu melakukan pengecekan sederhana, tidak menyeluruh pada semua bagian petak.

Ketika $i$ lebih besar dari $5$, maka nilai terkecil yang digunakan adalah $10-i-1$. Tapi jika kurang dari atau sama dengan $5$ , maka akan digunakan nilai dari $i$ itu sendiri. 

```ad-hint
Banyak jawaban yang menggunakan pola seperti ini, sepertinya jawaban ini jauh lebih baik!
```

## 2.2 | Cara precompute

```cpp
// Hey stalker :)
#include "bits/stdc++.h"
using namespace std;

#define MOD 1000000007

#define by_DevanshuSharma        \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);

#define no cout << "NO\n";
#define yes cout << "YES\n";

void solve()
{
    int ans = 0;
    bool flag = false;
    vector<pair<long long, long long>> vec;
    map<int, int> mpp;
    set<int> set;

    int matrix[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'X')
            {
                ans += matrix[i][j];
            }
        }
    }
    cout << ans << "\n";
}
int main()
{
    by_DevanshuSharma
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1, t = 0;
    cin >> T;
    while (t++ < T)
    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        // cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
```

Menggunakan precompute, membuat array dua dimensi. Benar-benar investasi waktu yang lumayan untuk menuliskan sebanyak itu haha.

## 2.3 | Cara cepat

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define  nl "\n"
#define forn(a, c) for (int a = 0; a < c; a++) 
#define forl(a, b, c) for (int a = b; a <= c; a++) 
#define forr(a, b, c) for (int a = b; a >= c; a--)
#define fast() (ios_base::sync_with_stdio(false), cin.tie(NULL));

signed main()
{
	fast();
	int t;cin>>t;
	while(t--){
		int var = 0;
		int x = 0,y = 0;
		forn(i,10){
			x = i;
			string s;cin>>s;
			forn(j,10){
				if(s[j] == 'X'){
					y = j;
					if(x>4){x = 9 - x;}
					if(y>4){y = 9 - y;}
					var+= min(x,y)+1;
				}
			}
		}
		cout<<var<<nl;
	}
}
```


Cara ini mirip dengan cara pertama, bedanya menggunakan string untuk menerima seluruh baris, dan melakukan pengecekan satu persatu dengan akses indeks. Tapi logikanya tetap mirip dengan cara pertama diatas!