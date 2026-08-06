---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 2074B
judul_DEATH: The Third Side
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-22T11:13:00
tags:
  - geometry
  - greedy
  - math
---
Sumber: [Problem - 2074B - Codeforces](https://codeforces.com/problemset/problem/2074/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 2074B-The Third Side

Diberikan sebuah arrray berukuran $n$. Tugasmu adalah melakukan operasi berikut:
- Pilih dua indeks $i$ dan $j$.
- Lalu, tetapkan sebuah variabel $x$ yang menjadikan segitiga menjadi *non-degeneratif*. Dimana $a_i$, $a_j$, dan juga $x$ adalah panjang sisi-sisinya.
- Singkirkan dua elemen $a_i$ dan $a_j$, dan tambahkan $x$ ke akhir arrayy.

Tentukan nilai maksimal yang bisa didapat diakhir array.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Dari contoh input output berikut, aku mendapatkan sebuah intuisi:

Input:

```
4
1
10
3
998 244 353
5
1 2 3 4 5
9
9 9 8 2 4 4 3 5 3
```

Output:

```
10
1593
11
39
```

Perhatikan bahwa untuk membuat segitiga *non-degeneratif*, atau memiliki volume, maka syarat berikut harus terpenuhi untuk 3 sisi segitiga misal $a,b$, dan $c$,

$$a+b>c, \; a+c>b, \; b+c>a$$
Perhatikan testcase ke-$2$, jawabanya yaitu $1593$, mungkin didapat dari operasi berikut:

$$(((998+224)-1) + (353))-1=1593$$
Kita cukup menambabhkan dua elemen bersebelahan, lalu hasilnya kita kurangi dengan satu. Lalu lakukan penambahakn lagi dengan elemen disebelahnya, lalu kurangi dengan satu. Begitu seterusnya. Kenapa dikurangi dengan satu? Karena kita anggap saja $a_i=a$, $b_j=b$, dan $x=c$, lalu kita mencoba memnuhi persamaan berikut:

$$a+b>c$$
Sehingga berikut implementasiku, yang ternyata benar:

```cpp
#include<iostream>
using namespace std;

void solve() {
    long long n, curr = 0, a;
    cin >> n;
    cin >> a;
    curr = a;
    for (int i=1; i<n; i++) {
        cin >> a;
        curr += a;
    }
    cout << curr - (n-1) << "\n";
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

Selisih yang dikurangi satu setiap elemen aku kerjakan saja pada bagian output, karena masing-masing selisih dikurangi satu, maka $curr-(n-1)$. 

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Kita dapat menyelesaikan masalah ini dengan mengamati suatu properti pada jumlah elemen.

Setelah setiap operasi, harus berlaku bahwa $a_i + a_j > x$, dan elemen baru paling banyak adalah $a_i + a_j - 1$. Oleh karena itu, jumlahnya berkurang setidaknya 1.

Namun, kita perhatikan bahwa sebuah segitiga dengan panjang sisi $p$, $q$, $p+q-1$ selalu non-degeneratif (tidak kolinear) karena hal-hal berikut:
1.  $p+q > p+q-1$;
2.  $p+(p+q-1) > q$ karena $2p-1 > 0$;
3.  $q+(p+q-1) > p$ karena $2q-1 > 0$.

Oleh karena itu, Anda dapat mengurangi jumlahnya tepat 1 pada setiap operasi. Jumlah akhir maksimum (yang merupakan elemen terakhir) dengan demikian adalah $\text{sum} - n + 1$.

Implementasi kode:

```cpp
t = int(input())
for _ in range(t):
    n = int(input())
    sm = sum(map(int, input().split()))
    print(sm - n + 1)
```

## 3.2 | Analisis Pribadi

Solusiku sudah sama dengan ide dan konsep dari editorial.
## 3.3 | Analisis Jawaban User Lain

Jawaban dari user lain tidak jauh berbeda, karena satu ide dan konsep dari editorial sudah yang paling efisien.

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,a,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a,sum+=a;
		cout<<sum-n+1<<endl;
	}
} 
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
int main(){
	int t;
	std::cin>>t;
	while(t--){
		int n;
		std::cin>>n;
		long long ans=0;
		for(int i=1,x;i<=n;i++)std::cin>>x,ans+=x;
		std::cout<<ans-n+1<<std::endl;
	}
	return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;
#define fixset(x) fixed<<setprecision(x)
typedef long long ll;
typedef unsigned long long ull;
const int MOD =1e9+7;
long double pi=acos(-1);
const int INF =0x3f3f3f3f;

void solve() {
	int n;
	cin>>n;
	vector<int>a(n);
	ll sum=0;
	for(auto &x:a){cin>>x;sum+=x;}
	cout<<sum-(n-1);
    
}

signed main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    ll t=1;
    cin>>t;
	while(t--) {
		solve();
		cout<<"\n";
	}
    return 0;
}
```