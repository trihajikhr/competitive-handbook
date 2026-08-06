---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 1374C
judul_DEATH: Move Brackets
sumber:
  - codeforces.com
rating: 1000
date_learned: 2025-11-30T13:55:00
tags:
  - greedy
  - strings
---
Sumber: [Problem - 1374C - Codeforces](https://codeforces.com/problemset/problem/1374/C)

```ad-tip
title:🛡️ Review Death Ground
Problem yang berkaitan dengan brakcet, sangat umum diselesaikan dengan menggunakan struktur data stack, atau mekanisme seperti stack.
```

<br/>

---
# 1 | 1374C-Move Brackets

Solusinya mudah, kita hanya perlu menghitung berapa banyak bracket penutup yang tidak menutup bracket terbuka manapun. Bisa menggunakan hanya variabel atau sturktur data `stack`:

```cpp
#include<iostream>
#include<stack>
using namespace std;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    stack<char> dast;
 
    for (char&c : s){
        if (c == '(') dast.push(c);
        else {
            if (!dast.empty() && dast.top() == '(') dast.pop();
            else dast.push(c);
        }
    }
    cout << dast.size()/2 << "\n";
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

Cara yang lebih cepat dan tanpa stack:

```cpp
#include<iostream>
using namespace std;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
 
    int temp = 0, cur = 0;
    for (char& c : s) {
        if (c == '(') temp++;
        else {
            if (temp > 0) temp--;
            else cur++;
        }
    }
    cout << cur << "\n";
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

Kebanyakan user menggunakan cara yang sama seperti cara kedua yang aku gunakan, yaitu hanya mengandalkan variabel dan pengecekan dasar.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		int ans = 0;
		int bal = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '(') ++bal;
			else {
				--bal;
				if (bal < 0) {
					bal = 0;
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c = 0;
        string a;
        cin >> n >> a;
        for (int i = 0; i < n; i++) {
            if (a[i] == ')' && c) c--;
            else if (a[i] == '(') c++;
        }
        cout << c << endl;
    }
    return 0;
}
```

```cpp
#include "bits/stdc++.h"
using namespace std;

int t,n;
string a;

int main() {
	ios::sync_with_stdio(false);

	cin>>t;
	while(t--) {
		cin>>n>>a;
		int open=0,close=0;
		for(auto c:a)
			if(c=='(') open++;
			else if(open) open--;
			else close++;
		cout<<(open+close)/2<<"\n";
	}
}
```
