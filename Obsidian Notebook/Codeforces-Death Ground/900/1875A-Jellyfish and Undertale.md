---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1875A
judul_DEATH: Jellyfish and Undertale
teori_DEATH:
sumber:
  - codeforces.com
ada_tips?:
date_learned: 2025-10-05T19:02:00
tags:
---
Sumber: [Problem - 1875A - Codeforces](https://codeforces.com/problemset/problem/1875/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1875A-Jellyfish and Undertale

Ada sebuah bom yang terpasang, dengan waktu awalnya adalah $c$. Setiap detik, nilai dari $c$ akan berkurang $1$. Jika nilai dari $c$ adalah nol, maka bom akan meledak.

Kita memiliki $n$ alat, yang bisa digunakan untuk mengutak-atik timer pada bom tersebut, dimana alat ke-$i$, akan menambahkan waktu pada timer tersebut sebanyak $x_i$. Namun, jika penambahkan waktu pada timer tersebut melebihi $a$ detik, maka akan ada bug yang membuat perubahan yang terjadi akan kembali menjadi $a$, atau $min(c+x_{i},a)$.

Tugas kita adalah menentukan, dengan alat dan dan bug pada bom tersebut, waktu terlama yang bisa diulur, sampai bom meledak.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Oke, aku butuh 2 percobaan untuk menyelesaikan problem ini, walaupun kodeku ternyata kurang efisien, jadi kodeku adalah seperti ini:

```cpp
#include<iostream>  
#include<algorithm>  
#include<vector>  
using namespace std;  
  
using LL = long long;  
  
void solve() {  
    LL a, c, n, ans=0, idx=0;  
    cin >> a >> c >> n;  
    vector<LL> v(n);  
    for (auto& x : v) cin >> x;  
  
    ans = c-1, c=1;  
    while (idx < n) {  
        c+= v[idx++];  
        if (c + v[idx] > a || idx == n) {  
            c = min(c,a);  
            ans+=c-1, c=1;  
        }  
    }  
  
    cout << ans+1 << '\n';  
}  
  
auto main() -> int {  
    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  
    int t; cin >> t;  
    while (t--) solve();  
    return 0;  
}
```

Pertama, jika nilai dari $c>1$, maka kita ambil semua nilai $c-1$ tersebut dan langsung tambahkan ke total waktu yang bisa diulur. Ini karena sebelum detik menyentuh angka $1$, maka kita tidak perlu menggunakan alat apapaun.

Ketika timer menyentuh angka $1$, maka kita akan memilih beberapa alat yang tersedia, hingga total waktunya sama atau sedikit melebihi nilai dari $a$. 

Ketika total timer $\geq a$, maka kita akan menset waktu yang berlaku pada timer tersebut menjadi $min(c+x_{i}, a)$, dan menyimpan total waktu yang dibutuhkan untuk timer tersebut kembali berkurang ke angka $1$, dalam hal ini, kita langsung saja ambil nilai $c-1$ lagi.

Karena menggunakan while, untuk mengatasi waktu yang masih tersisa tepat ketika tools terakhir digunakan, maka dibuatkan kondisional sebagai berikut:

```cpp
if (c + v[idx] > a || idx == n) {}
```

Ini mentrigger percabangan, untuk mengambil total waktu yang masih tersisa.

Setelah itu, kita outputkan total waktu yang bisa diulur, yang ditambahkan dengan $1$. Hal ini karena ketika bom menyentuh detik ke $0$, dia juga harus dihitung juga.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kita dapat menggunakan satu alat (**tool**) setiap kali pewaktu (**timer**) mencapai **1**, maka jawabannya adalah $\sum_{i=1}^{n} \min(a-1, x_i) + b$. Hal ini dapat dibuktikan sebagai yang **optimal**. 

Karena untuk setiap alat, jika kita menggunakannya ketika pewaktu adalah $c$, kontribusinya terhadap jawaban adalah $\min(x_i, a-c)$. Kita tidak dapat menggunakan alat tersebut ketika pewaktu kurang dari atau sama dengan $0$ karena bom akan meledak sebelum itu, jadi $c=1$ adalah yang optimal.

* Kompleksitas Waktu (**Time complexity**): $O(n)$ per kasus uji (**test case**).
* Kompleksitas Memori (**Memory complexity**): $O(1)$ per kasus uji (**test case**).

Berikut adalah implementasinya:

```cpp
#include<bits/stdc++.h>
using namespace std;

int n = 0, a = 0, b = 0;
long long ans = 0;

inline void solve(){
	scanf("%d %d %d", &a, &b, &n);
	ans = b;
	for(int i = 0, x = 0 ; i < n ; i ++){
		scanf("%d", &x);
		ans += min(a - 1, x);
	}
	printf("%lld\n", ans);
}

int T = 0;

int main(){
	scanf("%d", &T);
	for(int i = 0 ; i < T ; i ++) solve();
	return 0;
}
```

## 3.2 | Analisis Pribadi

Jika melihat ke editorial, mereka tidak menggunakan array apapaun, karena mereka langsung mengolah inputan yang masuk, dan langsung menyimpan total waktunya. 

Jadi, kodeku diatas kurang efisien karena membuat array, padahal tidak harus.

Berikut adalah implementasiku untuk memperbaikinya:

```cpp
#include<iostream>
#include<algorithm>
using namespace std;
using LL = long long;

void solve() {
    LL a, c, n, x;
    cin >> a >> c >> n;
    LL ans=c;
    for (int i=0; i<n; i++) {
        cin >> x;
        ans += min(a-1, x);
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
## 3.3 | Analisis Jawaban User Lain

Jawaban dan petunjuk dari editorial sudah sangat jelas dan menjadi solusi yang paling singkat. Jawaban lain sepertinya tidak jauh berbeda dengan pendekatan yang dilakukan editorial.
### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

int main() {
    long long a, b, n, x, t, i;
    cin >> t;
    while (t--) {
        cin >> a >> b >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            b += min(x, a - 1);
        }
        cout << b << endl;
    }
}
```

### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,n,x,t;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		for(int i=0;i<n;i++){
			cin>>x;
			b+=min(x,a-1);
		}
		cout<<b<<endl;
	}
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

using namespace std;
void solve() {
    int64_t a, b, n;
    cin >> a >> b >> n;
    int64_t ans = b - 1;
    for (int i = 0; i < n; i++) {
        int64_t k;
        cin >> k;
        ans += min(k + 1 ll, a) - 1;
    }
    cout << ans + 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
```