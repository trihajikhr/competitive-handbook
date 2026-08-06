---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 230A
judul_DEATH: Dragons
sumber:
  - codeforces.com
rating: 1000
date_learned: 2025-11-29T19:11:00
tags:
  - greedy
  - sortings
---
Sumber: [Problem - 230A - Codeforces](https://codeforces.com/problemset/problem/230/A)

```ad-tip
title: 🛡️ Review Death Ground
- Jika vector menyimpan tipe data pair, maka ketiak dilakukan sort tanpa custom, secara default nilai yang diurutkan adalah nilai `first` dari pair.
- Struktur data `map` mengurutkan data berdasarkan `key` yang dimasukan kedalamnya.
```

<br/>

---
# 1 | 230A-Dragons

Buat saja vector yang menyimpan tipe data pair, sehingga bisa menyimpan nilai $x$ dan $y$. Setelah itu, terima input, dan lakukan sorting secara ascending. Secara default, ketika vector yang disorting menyimpan tipe data pair, maka tipe pertama atau `first` akan menjadi acuan, jadi tidak perlu custom sort lagi untuk kasus ini.

Setelah itu, isi variabel $curr$ untuk menandai kekuatan awal Kirito, dan lakjukan traversal. Jika $curr < x$, maka hentikan program, karena artinya Kirito tidak mungkin bisa meleati semua level. Jika $curr > x$, maka $curr = curr + y$, dan lanjutkan traversal:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, curr;
    cin >> curr >> t;

    vector<pair<int, int>> vec(t);
    for (auto& [x,y] : vec) {
        cin >> x >> y;
    }

    ranges::sort(vec);
    for (const auto& [x, y] : vec) {
        if (curr > x) curr += y;
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
```

<br/>

---
# 2 | Analisis Singkat

Beberapa orang menggunakan struktur data `map`. Ini karena sturktur data ini secara default akan mengurutkan key yang disimpan, sehingga hanya dengan memasukan data kedalamnya, otomatis data akan terurut dengan sendirinya.

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int s,n;cin>>s>>n;
    map<int,int> m;
    while(n--){
        int d,b;cin>>d>>b;
        m[d]+=b;
    }
    for(auto x:m){
        if(s<=x.first){cout<<"NO";exit(0);}
        else s+=x.second;
    }
    cout<<"YES";
}
```

```cpp
#include <bits\stdc++.h>
using namespace std;
int main(){
    int s, n;
    cin >> s >> n;
    vector<pair<int,int>> a(n);
	for(auto &[u,v] : a) cin >> u >> v;
	sort(a.begin(),a.end());
	for(auto [u,v] : a){
		if(s <= u){
			cout << "NO";
			return 0;
		}
		else s += v;
	}
	cout << "YES";
	return 0;
}
```

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
int s ,n;
cin >> s >> n;
vector <pair<int,int>> dragons(n);
for (int i=0; i<n ; i++)
{
    int x,y;
    cin>>x>>y;
    dragons.push_back({x,y});
}
sort(dragons.begin(), dragons.end());
for (int j=0; j<size(dragons); j++)
{
    if (s > dragons[j].first)
    s +=dragons[j].second;
        else
        {
            cout << "NO";
            return 0;
        }
}
    cout << "YES";
    return 0;
}
```