---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1747C
judul_DEATH: Swap Game
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips: false
date_learned: 2025-10-26T06:31:00
tags:
  - games
---
Sumber: [Problem - 1747C - Codeforces](https://codeforces.com/problemset/problem/1747/C)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1747C-Swap Game

Alice dan Bob sedang memainkan permainan, dimana mereka memiliki array $a$ dengan $n$ elemen. Mereka akan bermain bergantian, dengan Alice bermain pertama kali. 

Setiap putaran, mereka akan melakukan operasi berikut:

- Jika $a_1=0$, maka player yang sedang mendapat giliran kalah.
- Player memilih $i$ untuk $2 \leq i \leq n$. Lalu mengurangi $a_1$ sebanyak $1$ dan menukar $a_1$ dengan $1_i$.

Tentukan siapa yang menang jika kedua pemain bermain optimal.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Setelah berpikir keras, aku menemukan solusinya. Yang jelas, mustahil untuk menerapkan perulangan atau pendekatan naif, karena ukuran dari setiap nilai $a$ memiliki batasan yang sangat besar yaitu $1 \leq a_i \leq 10^{9}$. Permainan optimal adalah mereka akan mencari nilai **terkecil** yang ada pada array $a$ untuk dipilih, dan dijadikan sebagai pilihan utama untuk memenangkan permainan.

Ketika mencoba mengkeksplor jawaban, aku mencoba menaruh angka terkecil di posisi $a_1$, dan ternyata Bob selalu menang. Ini karena Alice dipaksa mengurangi nilai dari $a_1$. Dan ketika nilai asli $a_1$ dikeluarkan, Bob bisa dengan mudah memasukanya kembali ke $a_1$, menjadikan Alice tidak memiliki pilihan lain selain harus mengurangi nilai yang dikuasai penuh oleh Bob, dan menjadikan Alice kalah diakhir.

Tetapi ketika nilai terkecil ditaruh di selain $a_1$, Alice yang memegang kendali penuh dengan nilai tersebut, karena Alice yang bermain pertama kali. Alice bisa langsung memasukan nilai tersebut ke $a_1$, dan menjadikan Bob dipaksa mengurangi nilai tersebut hingga habis, menjadikanya kalah.

Simplenya, jika salah satu nilai terkecil ada di $a_1$, maka Bob menang. Tapi jika tidak, yaitu nilai terkecil ada di selain $a_1$, maka Alice yang pasti menang.

Berikut implementasiku:

```cpp
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

void solve() {
    int n, mins = INT_MAX, idx=-1;
    cin >> n;

    for (int i=1, x; i<=n; i++) {
        cin >> x;
        if (x < mins) {
            mins = x;
            idx =i;
        }
    }
    if (idx==1) cout << "Bob\n";
    else cout << "Alice\n";
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

**Hint 1**:
Bagi masalah menjadi dua kasus yang berbeda:
1.  Ketika $a_1 > \min(a)$.
2.  Ketika $a_1 = \min(a)$.

**Hint 2**:
Anda tidak memerlukan petunjuk lebih lanjut untuk menyelesaikan masalah.

### Kasus 1: $a_1 > \min(a)$

Dalam kasus ini, Alice dapat memaksa Bob untuk selalu mengurangi elemen minimum dengan selalu memilih elemen minimum dari $a$ pada gilirannya.

Sementara itu, Bob tidak bisa berbuat banyak; semua elemen lain yang akan dia tukarkan nilainya akan lebih besar dari atau sama dengan $\min(a)$.

Bahkan jika terdapat beberapa nilai minimum dalam $a$, pada gerakan pertama Alice akan melakukan pengurangan dari $a_1$. Oleh karena itu, dalam kasus ini, **Alice akan selalu menang**.
### Kasus 2: $a_1 = \min(a)$

Dalam kasus ini, strategi optimal untuk Bob adalah selalu memilih elemen minimum dari array, yaitu $a_1$.

Alice akan selalu menukar elemen yang lebih besar dari $a_1$ pada gilirannya. Oleh karena itu, dalam kasus ini, Bob akan selalu menang.

Implementasi editorial:

```cpp
// Jai Shree Ram  
  
#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC



template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}


int solve(){
 		int n; cin >> n;
 		vector<int> a(n);
 		for(auto &i:a)cin >> i;
 		sort(a.begin() + 1,a.end());
 		cout << (a[0] > a[1] ? "Alice" : "Bob") << endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
```
## 3.2 | Analisis Pribadi

Ide dan konsep utamaku sama dengan jawaban dari editorial. Bahkan lebih efisien karena tidak menggunakan sorting, melainkan membaca langsung inputan, dan mendeteksi nilai terkecil pertama.
## 3.3 | Analisis Jawaban User Lain

Karena solusi dari soal ini ternyata sederhana, maka jawaban dari pengguna lain juga kebanyakan tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a, x, y;
    cin >> t;
    while (t--) {
        cin >> n >> x >> y;
        for (int i = 0; i < n - 2; i++) {
            cin >> a;
            y = min(y, a);
        }
        cout << (x > y ? "Alice\n" : "Bob\n");
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> v(n);
        for(int &i:v) cin>>i;
        cout<<(*min_element(v.begin(),v.end())<v[0]?"Alice\n":"Bob\n");
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mn = *min_element(a.begin(), a.end());
    if(a[0] == mn) {
        cout <<"Bob\n";
    } else {
        cout << "Alice\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
```