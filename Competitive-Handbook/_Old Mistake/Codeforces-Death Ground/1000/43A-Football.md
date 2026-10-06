---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 43A
judul_DEATH: Football
sumber:
  - codeforces.com
rating: 1000
date_learned: 2025-11-30T12:47:00
tags:
  - strings
---
Sumber: [Problem - 43A - Football](https://codeforces.com/problemset/problem/43/A)

```ad-tip
title:🛡️ Review Death Ground
```

<br/>

---
# 1 | 43A-Football

Solusinya mudah, bisa mengandalkan `unordered_map`, atau langsung saja. Jika menggunakan cara langsung, bisa dengan membuat 2 variabel string, dan 2 variabel integer sebagai variabel counter. Inputan pertama menyimpan string ke variabel pertama, dan sisanya mengandalkan percabangan sebagai pengecekan. Soal ini tidak sulit, hanya dibutuhkan logika sederhana. Berikut beberapa jawabanku yang benar:

```cpp
#include<iostream>
using namespace std;
 
auto main() -> int {
    int n;
    cin >> n;
    string a, b;
    int an = 0, bn=0;
 
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        if (i==0) {
            an ++;
            a = s;
        } else {
            if(a==s) an++;
            else {
                b = s;
                bn++;
            }
        }
    }
    cout << (an > bn ? a : b);
    return 0;
}
```

Dengan menggunaka `unordered_map`:

```cpp
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
 
auto main() -> int {
    int t, maks = -1;
    string win;
    cin >> t;
    unordered_map<string, int> dasmap;
    while (t--) {
        string s;
        cin >> s;
        dasmap[s]++;
 
        maks = max(maks, dasmap[s]);
        if (maks == dasmap[s]) {
            win = s;
        }
    }
    cout << win;
    return 0;
}
```

<br/>

---
# 2 | Analisis Singkat

Selain cara hitung langsung, beberapa orang menggunakan array, menyimpan semua inputan kedalam array, lalu mengurutkanya. Setelah itu, string input yang berada di posisi tengah, akan menunjukan mana yang paling banyak muncul. Cara *clever* namun boros memory, namun bisa digunakan sebagai tambahan teknik penyelesaian.

```cpp
#include<bits/stdc++.h>
using namespace std;

string s[1000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    sort(s, s + n);
    cout << s[n / 2];
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n);
    cout << s[n / 2];
    return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin); 
        freopen("output.txt","w",stdout);  
  #endif
 
   int n;
   cin >> n;
   string s;
    
    map<string, int> mp;
    for(int i = 0; i < n; i++){
      cin >> s;
      mp[s]++;
    }

    string s1;
    int ans = 0;
    for(auto u : mp){
      if(u.second > ans){
        ans = u.second;
        s1 = u.first;
      }
    }

    cout << s1 << endl;

 return 0;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    
    map<string,int>mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    
    string s1="";
    int cnt1 = -1;
    for(auto i : mpp){
        if(i.second > cnt1){
            s1 = i.first;
            cnt1 = i.second;
        }
    }
    cout << s1 << endl;
}
```