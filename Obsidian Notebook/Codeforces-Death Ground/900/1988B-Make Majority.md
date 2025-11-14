---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1988B
judul_DEATH: Make Majority
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-15T15:13:00
tags:
---
Sumber: [Problem - 1988B - Codeforces](https://codeforces.com/problemset/problem/1988/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1988B-Make Majority

Diberikan sebuah sekuen angka yang hanya terdiri dari angka $1$ dan $0$. Kita bisa melakukan beberapa operasi (atau tidak sama sekali) memilih posisi sekuen $l$ dan $r$, untuk $1 \leq l \leq r \leq |a|$ (*dimana $a$ adalah panjang sekuen*), lalu mengganti untuk semua $[a_l, \cdots a_r]$ dengan satu nilai $x$, dimana $x$ adalah angka mayoritas yang ada pada rentang $[a_l, \cdots a_r]$.

Aturan angka mayoritas adala sebagai berikut, dimana $c_0$ adalah jumlah angka $0$, dan $c_1$ adalah jumlah angka $1$:

- Jika $c_0 \geq c_1$, maka mayoritas adalah $0$.
- Jika $c_0 < c_1$, maka mayoritas adalah $1$.

Tentukan, apakah mungkin dengan melakukan beberapa operasi, kita bisa menjadikan sekuan $a=[1]$.


<br/>

---
# 2 | Sesi Death Ground ⚔️

Aku mendapat intuisi yang sangat jelas dari contoh input output berikut:

```
9
100000001
```

Disini, jawabanyanya adalah `YES`. Ya, kita bisa membuat sekuanya menjadi $a=[1]$. Dimana, kita meilih posisi $l=2$ dan $r=8$. Karena semua angka yang ada didalamnya adalah $0$, maka ketika diganti dengan $x$, sekuen tersebut menjadi bernilai $[1,0,1]$. 

Nahh, disini, sangat terlihat bahwa kita bisa memilih $l=1$ dan $r=3$, untuk menjadikan $a=[1]$.

Aku berpikir, karena pemilihan $l$ dan $r$ akan membuat semua angka didalamnya digantikan oleh angka mayoritas, maka, untuk semua segment sekuen yang nilainya berurutan angka $0$, kita bisa menganggapnya sebagai hanya satu kemunculan:

$$[1,0,0,0,1,0,0,1,1,0,0,0] \rightarrow [1,0,1,0,1,1,0]$$
Setelah itu, kita cukup menghitung banyaknya angka $0$ dan $1$ yang tersisa. 

Proses akhir adalah dengan menentukan, apakah kemunculan $c_1 > c_0$. Jika ya, maka outputkan `YES`, dan jika tidak maka outputkan `NO`. 

Dasar dari logika ini, adalah bahwa untuk menjadikan sebuah sekuen menjadi $a=[1]$, kita bisa melakukan dua upaya:
- Mengurangi sebanyak mungkin kemunculan angka $0$, sehingga mayoritas angka $0$ berkurang. Hal ini dilakukan dengan memilih segment berurutan angka $0$, dan menjadikanya nilai $0$ tunggal.
- Memastikan bahwa $c_1 > c_0$, untuk bisa memilih semua rentang sekuen, dan menjadikan $a=[1]$.

Beriku adalah solusiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, c0=0, c1=0;
    cin >> n;
    bool first = true;
    for (int i=0; i<n; i++) {
        char x;
        cin >> x;
        if (x=='1') {
            c1++, first = true;
        }
        else if (x=='0') {
            if (first) {
                c0++, first = false;
            }
        }
    }

    cout << (c1 > c0 ? "YES" : "NO") << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

**Hint 1**: "Kebanyakan barisan" (*Most sequences*) dapat ditransformasi menjadi $[1]$. Kondisi agar sebuah barisan tidak dapat ditransformasi sangatlah ketat (*stringent*).

**Hint 2**: Temukan beberapa *substring* sederhana yang membuat *string* dapat ditransformasi.

Kita daftarkan beberapa kondisi sederhana agar suatu *string* dapat ditransformasi:

* Jika **`111`** ada di suatu tempat (sebagai *substring*) dalam *string*, *string* tersebut selalu dapat ditransformasi.
* Jika **`11`** muncul setidaknya dua kali dalam *string*, *string* tersebut selalu dapat ditransformasi.
* Jika *string* tersebut **berawal dan berakhir dengan `1`**, *string* tersebut selalu dapat ditransformasi.
* Jika *string* tersebut **berawal atau berakhir dengan `1`** dan **`11`** ada dalam *string*, *string* tersebut selalu dapat ditransformasi.

Kondisi-kondisi ini dapat ditemukan dengan menyimulasikan operasi pada *string* pendek di atas kertas.

Sebaliknya, jika suatu *string* tidak memenuhi salah satu dari empat item di atas, *string* tersebut selalu **tidak** dapat ditransformasi. Hal ini dapat dibuktikan menggunakan induksi (sebagai latihan).

Amati bahwa jumlah kemunculan `1` tidak pernah bertambah dalam suatu operasi. Kita dapat mengubah segmen nol (*zero*) yang kontinu menjadi satu nol. Setelah itu, cukup dengan memeriksa bahwa **jumlah kemunculan `1` lebih besar daripada jumlah kemunculan `0`**.

Berikut implementasi:

```py
t = (int)(input())
for _ in range(t):
    n = (int)(input())
    a = input()
    ok = 0
    if a.count("111") >= 1:
        ok = 1
    if a.count("11") >= 2:
        ok = 1
    if a.count("11") >= 1 and (a[0] == "1" or a[-1] == "1"):
        ok = 1
    if a[0] == "1" and a[-1] == "1":
        ok = 1
    if ok:
        print("Yes")
    else:
        print("No")
```
## 3.2 | Analisis Pribadi

Melihat dari beberapa gaya coding user lain lain, berikut adalah improvisasi dari kodeku yang lebih baik:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, cnt=0;
    cin >> n;
    bool first = true;
    for (int i=0; i<n; i++) {
        char x;
        cin >> x;
        if (x=='1') cnt++, first = true;
        else if (x=='0' && first) cnt--, first = false;
    }
    cout << (cnt >= 1  ? "YES" : "NO") << '\n';
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

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		int x=0,y=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')x++;
			else if(!i||s[i]!=s[i-1])y++;
		puts(x>y?"Yes":"No");
	}
	return 0;
}
```

Program ini persis sama dengan caraku. Program ini menghitung banyaknya kemunculan angka $1$, dan banyaknya kemunculan segment $0$, tapi dengan cara yang lebih efisien (*tanpa bantuan variabel boolean seperti caraku*), yaitu dengan melakukan pengecekan, apakah $s[i] \neq s[i-1]$. Jika iya, maka iterasi sedang masuk kedalam segment berurutan angka $0$.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,c;
	for(cin>>T;T>0;T--) {
		cin>>n>>s;
		c=0;
		for(i=0;i<n;i++) {
			if(s[i]=='0'&&(i==0||s[i-1]!='0'))c--;
			else if(s[i]=='1')c++;
		}
		if(c>=1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
```

Program ini hampir sama, namun bentuk efisiensinya berbeda. Alih-alih menggunakan dua variabel untuk count kemunculan angka $0$ dan $1$, dia menggunakan satu variabel yang naik dan turun. Simplenya, jika angka $1$ lebih banyak, pasti nilai variabel $c$ pasti diatas $0$, tapi jika tidak, maka $0$ nya lah yang lebih banyak, membuat $c$ menjadi minus.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
#define umap unordered_map
#define uset unordered_set
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forn1(i, n) for (int i = 1; i <= (n); ++i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; --i)
#define rforn1(i, n) for (int i = (n); i > 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int) (x).size()
#define LSB(x) ((x) & -(x))
inline int MSB(int x) { return x ? 1 << (31 - __builtin_clz(x)) : 0; }
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename... Ts>
inline void print(const Ts&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
    cout << "\n";
}
template <typename T>
inline void print(const vector<T>& v) {
    for (auto x : v) cout << x << " ";
    cout << "\n";
}
template <typename... Ts>
inline void printerr(const Ts&... args) {
    const char* sep = "";
    cerr << "\u001B[31m";
    (((cerr << sep << args), sep = " "), ...);
    cerr << "\u001B[0m" << endl;
}
template <typename T>
inline void printerr(const vector<T>& v) {
    cerr << "\u001B[31m";
    for (auto x : v) cerr << x << " ";
    cerr << "\u001B[0m" << endl;
}

const double EPS = 1e-9;
const int INF = 1e9;
const int MAXN = 3e5;

void solve() {
    int n; cin >> n;
    int a = 0;
    int b = 0;
    char p = '1';
    forn(i, n) {
        char d; cin >> d;
        if (d == '0') {
            a += p != '0';
        } else ++b;
        p = d;
    }
    print(b>a?"Yes":"No");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
}

```

Lagi-lagi sama, hanya saja cara hitungnya yang sedikit berbeda. Variabel $b$ menampung banyaknya kemunculan angka $1$, sedangkan variabel $a$ menampung banyaknya kemunculan segment berurutan $0$, dengan cara melakukan pengecekan, apakah inputan sebelumnya, yang masih disimpan di $p$ adalah $p \neq 0$? Jika iya, maka hasil perbandingan tersebut akan menghasilkan `true`, atau menjadi bernilai $1$, jika `false`, maka akan menjadi bernilai $0$.