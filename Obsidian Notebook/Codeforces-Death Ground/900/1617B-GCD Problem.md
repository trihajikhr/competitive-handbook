---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1617B
judul_DEATH: GCD Problem
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-15T12:40:00
tags:
---
Sumber: [Problem - 1617B - Codeforces](https://codeforces.com/problemset/problem/1617/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1617B-GCD Problem

Diberikan sebuah angka $n$. Kita diminta mencari 3 angka berbeda yaitu $a,b,c$, dimana $a+b+c = n$, dan $GCD(a,b)=c$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama, aku mencoba mengamati batas inputan berikut: $10 \leq n \leq 10^{9}$.

Karena nilai inputan dimulai dari angka $10$, aku mencoba mengeksplorasi hasil dari $10$ hingga $20$. Aku juga memiliki intuisi, bahwa semua angka, dapat disusun oleh penjumlahan $a$ dan $b$, dimana $GCD(a,b)=1$. Aku mencoba mengecek intuisiku ini, dan itu adalah valid:

```
10 -> 5 4 1
11 -> 7 3 1
12 -> 9 2 1
13 -> 7 5 1
14 -> 8 5 1
15 -> 9 5 1
16 -> 8 7 1
17 -> 9 7 1
18 -> 9 8 1
19 -> 11 7 1
20 -> 11 8 1
```
Ingat,  nilai $c$ akan kita langsung isi dengan $1$, dan karena $a+b+c=n$, maka kita cukup mencari nilai $a$ dan $b$ dari $n-1$. Kita isi nilai $a$ dan $b$ dari memecah $n-1$ menjadi dua bagian, dan untuk mengatasi seandainya $n-1$ adalah ganjil, maka operasi pencarian $a$ dan $b$ harus menggunakan cara berikut:

$$a=\lceil\frac{n}{2}\rceil \;\;\; ,\;\;\; b=\frac{n}{2}$$
Nah, nilai dari $a$ dan $b$, belum tentu memenuhi persamaan $GCD(a,b)=1$, sehingga dilakukan perulangan, dengan melakukan increment pada $a$ dan decremenet pada $b$, hingga mencapai kondisi $GCD(a,b)=1$ (*operasi ini tidak akan membengkak, karena tidak akan dihitung terlalu jauh dari nilai awal*).

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<numeric>
using namespace std;

void solve() {
    int n;
    cin >> n;
    n--;
    int a = (n+1)/2, b = n/2;
    while (gcd(a,b) != 1) a++, b--;
    cout << a << " " << b << " " << 1 << "\n";
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

**Hint**: Harus selalu ada solusi yang tersedia untuk $c=1$ di bawah batasan (*constraint*) yang diberikan.


**Solusi**:

Observasi Kunci: Selalu terdapat solusi dengan $c=1$ di bawah batasan yang diberikan. Kita menetapkan $n \ge 10$ karena tidak ada solusi saat $1 \le n \le 5$ atau $n=7$.

- Solusi 1: **Brute Force**
  Mulai dari $a=2, 3, 4, \dots$ dan hitung nilai $b$ menggunakan rumus $b = n - a - 1$. Kemudian, periksa apakah $\gcd(a, b) = 1$. Metode ini berhasil karena Anda akan menemukan bilangan prima $p \le 29$ sedemikian sehingga $n-1$ tidak membagi $p$.

<br/>

- Solusi 2: **Pilihan Acak**
  Pilih $a$ secara acak dan hitung $b$ menggunakan rumus $b = n - a - 1$. Mengulangi proses ini beberapa kali akan memungkinkan Anda menemukan pasangan $(a, b)$ sedemikian sehingga $\gcd(a, b) = 1$.

<br/>

- Solusi 3: **Solusi Konstruktif**
  Solusi ini didasarkan pada konstruksi langsung berdasarkan sisa bagi $n$ (modulo).
	1.  Ketika $n \equiv 0 \pmod 2$ (yaitu $n$ genap), keluarkan $(n-3, 2, 1)$.
	2.  Ketika $n \equiv 1 \pmod 4$, keluarkan $\left(\lfloor \frac{n}{2} \rfloor - 1, \lfloor \frac{n}{2} \rfloor + 1, 1\right)$.
	3.  Ketika $n \equiv 3 \pmod 4$, keluarkan $\left(\lfloor \frac{n}{2} \rfloor - 2, \lfloor \frac{n}{2} \rfloor + 2, 1\right)$.

Implementasi pertama:

```cpp
#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
void solve(int tc) {
    int n; 
    cin >> n;
    while(1) {
        int k = uniform_int_distribution<int>(2, n-2)(rng);
        int l = n-k-1;
        if(k != l && k != 1 && l != 1 && gcd(k, l) == 1) {
            cout << k << ' ' << l << ' ' << 1 << endl;
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) {
        solve(i);
    }
}
```

Implementasi kedua:

```cpp
#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin>>n;
	if (n%2==0) cout<<"2 "<<(n-1)-2<<" 1\n";
	else {
		int cur=(n-1)/2;
		if (cur%2==0) cout<<cur-1<<" "<<cur+1<<" "<<1<<endl;
		else cout<<cur-2<<" "<<cur+2<<" "<<1<<endl;
	}
}
signed main(){
	int t;
	cin>>t;
	while (t--) solve();
}
```
## 3.2 | Analisis Pribadi

Jawaban pertamaku sudah benar, tapi implementasi dan petunjuk dari editorial juga bisa dicoba.

## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (a = 2, b = n - 3; __gcd(a, b) != 1; a++, b--) {}
        cout << a << ' ' << b << ' ' << 1 << '\n';

    }
}
```

Solusinya hampir sama dengan solusiku, hanya saja tidak dimulai dari tengah, tapi dimulai dari $a=2$ dan $b=n-1$. Dan menggunakan perulangan untuk mencari nilai $a$ dan $b$ yang memenuhi syarat $GCD(a,b)=1$.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    int t,a,b,n;
    cin>>t;
    while(t--) {
       cin>>n;
       for(a=2,b=n-3;gcd(a,b)!=1;a++,b--) {}
       cout<<a<<" "<<b<<" "<<1<<'\n';
        }
    return 0;
}
```

Program ini menggunakan logika yang hampir sama dengan contoh kode pertama. Kebanyakan contoh kode program yang mengutamakan kesingkatan, memiliki bentuk seperti ini.
### 3 | Jawaban Ketiga

```cpp
#define chatgpt3_5 "bits/stdc++.h"
#define chatgpt4 "bits/extc++.h"

#include chatgpt3_5

using namespace std;

//#define FLOATING_OCEAN

#define int long long
#define pii pair<int, int>
#define pipi pair<pii, pii>
#define tpi tuple<int, int, int>
#define fs first
#define sc second
#define pb emplace_back
#define ep emplace
#define rall(x) (x).rbegin(),(x).rend()
#define all(x) (x).begin(),(x).end()

constexpr int N = 2e5 + 10, M = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9, PI = acos(-1);

void solve() {
    int n;
    cin >> n;
    for(int c=1;c<=n/c;c++) {
        if(n % c != 0) continue;
        int a = (n - c) / c / 2, b = a + 1;
        if((n - c) / c % 2 == 0) {
            a --;
            if(a % 2 == 0) a --, b ++;
        }
        if(a > 0 && b > 0 && a != c && b != c && a != b) {
            cout << a * c << ' ' << b * c << ' ' << c << '\n';
            return;
        }
    }
}

signed main() {
# ifdef FLOATING_OCEAN
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
# endif
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // init();
    int t = 1;
    cin >> t;
    while (t--) solve();
}
```

Kode ini juga lumayan cepat, namun sulit untuk dipahami. Terlalu ribet dan kompleks, namun bisa digunakan sebagai bahan belajar dan evaluasi.

Diberikan bilangan bulat positif $n$, tujuannya adalah mencari tiga bilangan bulat positif berbeda $a, b, c$ sedemikian sehingga $a + b + c = n$ dan $\gcd(a, b) = c$. Karena $\gcd(a, b) = c$, kita dapat mendefinisikan $a$ dan $b$ sebagai kelipatan dari $c$ dengan faktor-faktor yang relatif prima, yaitu $a = c \cdot x$ dan $b = c \cdot y$, di mana $\gcd(x, y) = 1$. Dengan mensubstitusikan ini ke dalam syarat penjumlahan, kita mendapatkan $c \cdot x + c \cdot y + c = n$, yang disederhanakan menjadi $c(x + y + 1) = n$. Ini menyiratkan bahwa $c$ haruslah pembagi dari $n$. Persamaan ini juga menghasilkan hubungan $x + y = \frac{n}{c} - 1$.

Ide solusinya adalah memaksa kondisi $\gcd(x, y) = 1$ dengan memilih $x$ dan $y$ sebagai bilangan berurutan, yaitu $x = k$ dan $y = k + 1$, karena bilangan berurutan selalu relatif prima. Dengan memilih ini, $x + y = 2k + 1$. Substitusi kembali ke persamaan $x+y$ memberikan $2k + 1 = \frac{n}{c} - 1$. Ini memungkinkan kita memperoleh formula dasar untuk $k$: $k = \frac{1}{2}\left(\frac{n}{c} - 2\right)$.

Implementasi dalam kode dimulai dengan iterasi untuk setiap pembagi $c$ yang mungkin dari $n$:

```cpp
for (int c = 1; c <= n / c; c++) {
    if (n % c != 0) continue;
// ...
```

Di dalam perulangan tersebut, kita menghitung kandidat $x$ dan $y$ (yang di kode disebut `a` dan `b` *sebelum* dikalikan dengan $c$) berdasarkan formula $k$:

```cpp
int a = (n - c) / c / 2, b = a + 1;
```

Perhatikan bahwa $\frac{n-c}{c} = \frac{n}{c} - 1$. Jadi baris ini menghitung $k$ dan $k+1$. Terdapat koreksi khusus jika $\frac{n}{c} - 1$ adalah genap, yang bertujuan untuk memastikan $a', b', c'$ (setelah dikalikan $c$) tetap berbeda dan positif, meskipun $x$ dan $y$ yang baru mungkin tidak berurutan, tetapi tetap relatif prima:

```cpp
if ((n - c) / c % 2 == 0) {
    a--;
    if (a % 2 == 0) a--, b++;
}
```

Setelah perhitungan dan penyesuaian, kita memeriksa validitas akhir dari tripel $(a' = a \cdot c, b' = b \cdot c, c' = c)$ yang dihasilkan. Pemeriksaan ini memastikan bahwa semua bilangan positif dan ketiganya berbeda:

```cpp
if (a > 0 && b > 0 && a * c != c && b * c != c && a * c != b * c) {
    cout << a * c << ' ' << b * c << ' ' << c << '\n';
    return;
}
```

Jika tripel valid ditemukan, hasilnya dicetak dan fungsi berhenti. Dengan demikian, algoritma ini secara efisien mencari pembagi $c$ dan membangun pasangan koefisien relatif prima $x$ dan $y$ untuk memenuhi kedua kondisi yang diberikan.