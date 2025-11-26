---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 433B
judul_DEATH: Kuriyama Mirai's Stones
teori_DEATH: prefix sum problem
sumber:
  - codeforces.com
rating: 1200
ada_tips:
date_learned: 2025-10-30T01:07:00
tags:
  - dynamic-programming
  - implementation
  - sortings
---
Sumber: [Problem - 433B - Codeforces](https://codeforces.com/problemset/problem/433/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 433B-Kuriyama Mirai's Stones

Kuriyama memiliki batu $a$ sebanyak $n$, dengan batu ke-$i$  memiliki harga $a_i$. Kuriyama ingin mengetahui hal berikut:

1. Total harga batu-batu di titik $l$ hingga $r$ $(1 \leq l \leq r \leq n)$.
2. Total harga batu-batu termurah dari titik $l$ hingga $r$ $(1 \leq l \leq r \leq n)$.

Akan diberikan $q$ queries, dimana setiap queries akan berisi 3 inputan berupa $type,l,r$, dimana $type$ menunjukan operasi mana yang ingin digunakan, dan rentang $l$ dan $r$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, algoritma *prefix sum* wajib digunakan  disini, karena akan membuat kompleksitas per queries hanya $O(1)$. 

Pertama bangun array queries untuk array yang masih teracak. Setelah prefix sum pertama selesai dibuat, sorting array, dan bangung prefix sum lagi, kali ini untuk daftar batu termurah.

Setelah itu, pada operasi queries, perika $type$ yang diberikan, dan jalankan algoritma prefix sum untuk mendapatkan rentang jumlah yang sesuai dari titik $l$ hingga $r$.

> Hanya menerapkan algoritma prefix sum. Jadi aku tidak akan menjelaskan panjang lebar.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using ll = long long;
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, q, x, l, r;
    cin >> n;
    vector<ll> v(n+1), p(n+1), c(n+1);
    for (int i=1; i<=n;i++) {
        cin >> v[i];
        p[i] = p[i-1] + v[i];
    }
    
    ranges::sort(v);
    for (int i=1; i<=n; i++) {
        c[i] = c[i-1] + v[i];
    }
    
    cin >> q;
    while (q--) {
        cin >> x >> l >> r;
        if (x==1) cout << p[r]-p[l-1] << '\n';
        else if (x==2) cout << c[r] - c[l-1] << '\n';
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Sortir barisan $v$ untuk mendapatkan barisan $u$. Pengurutan (sorting) dapat dilakukan dalam $O(n \log n)$ menggunakan *quicksort*.

Sekarang kita tertarik pada jumlah (sum) dari sebuah interval dari barisan yang diberikan. Ini dapat dilakukan dengan menghitung jumlah prefiks (*prefix sum*) dari barisan tersebut terlebih dahulu. Yaitu, misalkan $sv_i = \sum_{j=1}^{i} v_j$. Jumlah bilangan dalam interval $[l, r]$ kemudian akan menjadi $sv_r - sv_{l-1}$. Kita dapat menangani barisan $u$ dengan cara yang sama.

Pra-pemrosesan (*preprocessing*) membutuhkan waktu $O(n)$, dan menjawab kueri (*query*) hanya $O(1)$. Total kompleksitasnya adalah $O(n \log n + q)$.

Implementasi editorial:

```cpp
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define LL "%I64d"
const int maxn = 100010;

int n, m;
long long y[maxn], z[maxn];

int main() {
    scanf("%d", & n);
    for (int a = 1; a <= n; a++) {
        int v;
        scanf("%d", & v);
        y[a] = z[a] = v;
    }
    
    sort(y + 1, y + n + 1);
    for (int a = 1; a <= n; a++)
        z[a] += z[a - 1], y[a] += y[a - 1];
    scanf("%d", & m);
    
    for (int a = 1; a <= m; a++) {
        int opt, l, r;
        scanf("%d%d%d", & opt, & l, & r);
        if (opt == 1) printf(LL "\n", z[r] - z[l - 1]);
        else printf(LL "\n", y[r] - y[l - 1]);
    }

    return 0;
}
```

## 3.2 | Analisis Pribadi

Ide dan konsep dari editorial sama dengan jawabanku, mengandalkan prefix sum memang menjadi kunci di soal ini.
## 3.3 | Analisis Jawaban User Lain

Metode prefix sum menjadi kunci yang jelas di konsep ini. Jawaban pengguna lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[100010], b[100010];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) a[i] += a[i - 1], b[i] += b[i - 1];
    int m;
    cin >> m;
    while (m--) {
        int o, l, r;
        cin >> o >> l >> r;
        if (o == 1) cout << a[r] - a[l - 1] << '\n';
        else cout << b[r] - b[l - 1] << '\n';
    }
    return 0;
}
```
### 2 | Jawaban Kedua

```cpp
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 100050;
long long a[N], b[N];
int main() {
    int n, i, q, l, r, t;
    scanf("%i", & n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", & a[i]);
        b[i] = a[i];
        a[i] += a[i - 1];
    }
    sort(b + 1, b + 1 + n);
    for (i = 1; i <= n; i++) b[i] += b[i - 1];
    scanf("%i", & q);
    while (q--) {
        scanf("%i %i %i", & t, & l, & r);
        printf("%lld\n", t == 1 ? a[r] - a[l - 1] : b[r] - b[l - 1]);
    }
    return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
// By the name of Allah, Most Gracious, and Merciful
#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(), v.end()
#define int long long
using namespace std;

const int M = 1e9+7;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
void solve() {
    int n;
    cin >> n;
    vector<int>v(n+1);
    vector<int>pref(n+1);
    for(int i=1; i<=n; i++){
    	cin >> v[i];
    	pref[i]=v[i]+pref[i-1];
	}
    sort(all(v));
    for(int i=1; i<=n; i++){
    	v[i] += v[i-1];
	}
	int q;
	cin >> q;
	while(q--){
		int c, l, r;
		cin >> c >> l >> r;
		if(c==1){
			cout << pref[r]-pref[l-1] << '\n';
		}else{
			cout << v[r]-v[l-1] << "\n";
		}
	}
}


signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
```