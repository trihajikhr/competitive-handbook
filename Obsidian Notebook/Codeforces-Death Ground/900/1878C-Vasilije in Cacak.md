---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1878C
judul_DEATH: Vasilije in Cacak
teori_DEATH: Rumus jumlah maksimum dan minimum
sumber:
  - codeforces.com
ada_tips?: true
date_learned: 2025-10-04T12:46:00
tags:
  - math
---
Sumber: [Problem - 1878C - Codeforces](https://codeforces.com/problemset/problem/1878/C)

```ad-tip
title:⚔️ Teori Death Ground
- Rumus Jumlah Minimum: $$\sum_{i=1}^{k} i = 1 + 2 + \dots + k = \frac{k(k+1)}{2}$$
- Rumus Jumlah Maksimum: $$\sum_{i=n-k+1}^{n} i = n + (n-1) + \dots + (n-k+1)$$
```

<br/>

---
# 1 | 1878C-Vasilije in Cacak

Aku diminta menentukan, apakah mungkin, memilih angka dari angka 1 hingga $n$, dimana jika aku mengambil $k$ angka diantaranya, lalu menjumlahkanya, maka hasilnya adalah $x$.

10 menit pertama (trial of ten) aku kesulitan untuk menemukan solusinya.

<br/>

---
# 2 | Sesi Death Ground ☠️

| Kata Kunci (Keyword)               | Penjelasan Singkat                                                                                                         |
| :--------------------------------- | :------------------------------------------------------------------------------------------------------------------------- |
| $k$ bilangan                       | Jumlah bilangan yang dipilih.                                                                                              |
| $n$                                | Batas atas maksimum bilangan yang bisa dipilih ($1$ sampai $n$).                                                           |
| Jumlah Minimum ($S_{\text{min}}$)  | Jumlah terkecil yang mungkin dari $k$ bilangan (yaitu $1, 2, \dots, k$).                                                   |
| Jumlah Maksimum ($S_{\text{max}}$) | Jumlah terbesar yang mungkin dari $k$ bilangan (yaitu $n, n-1, \dots, n-k+1$).                                             |
| Kontradiksi                        | Bagian penting dalam pembuktian untuk menunjukkan bahwa selalu ada $a$ yang dapat diganti dengan $a+1$.                    |
| Prinsip Induksi Matematika         | Metode yang digunakan untuk menyimpulkan bahwa semua jumlah di antara $S_{\text{min}}$ dan $S_{\text{max}}$ dapat dicapai. |


Teks tersebut secara eksplisit menyebutkan dua rumus utama:

## 2.1 | Rumus Jumlah Minimum ($S_{\text{min}}$)

Ini adalah jumlah dari $k$ bilangan asli pertama: $1, 2, 3, \dots, k$.

$$S_{\text{min}} = \sum_{i=1}^{k} i = \frac{k(k+1)}{2}$$

## 2.2 | Rumus Jumlah Maksimum ($S_{\text{max}}$)

Ini adalah jumlah dari $k$ bilangan terbesar yang mungkin: $n, n-1, n-2, \dots, n-k+1$. Rumus ini dihitung dengan mengambil jumlah semua bilangan dari $1$ hingga $n$, dan dikurangi dengan jumlah bilangan yang **tidak** termasuk dalam $k$ bilangan terbesar (yaitu $1$ hingga $n-k$).

$$S_{\text{max}} = \sum_{i=n-k+1}^{n} i = \frac{n(n+1) - (n-k)(n-k+1)}{2}$$


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Jelas bahwa jumlah minimum diperoleh untuk bilangan **$1, 2, 3, \dots, k$**, dan nilainya adalah **$\frac{k(k+1)}{2}$** (jumlah dari $k$ bilangan asli pertama).

Selanjutnya, sudah jelas bahwa jumlah maksimum dicapai untuk bilangan **$n, n-1, n-2, \dots, n-k+1$**, dan nilainya adalah **$\frac{n(n+1) - (n-k)(n-k+1)}{2}$** (jumlah semua bilangan dari $1$ sampai $n$ dikurangi jumlah semua bilangan dari $1$ sampai $n-k$).

Mari kita buktikan bahwa di antara setiap $k$ bilangan (yang jumlahnya tidak maksimal), pasti ada bilangan $a < n$ sedemikian rupa sehingga $a+1$ tidak termasuk di antara $k$ bilangan tersebut. Mari kita asumsikan yang sebaliknya, yaitu ada $k$ bilangan yang jumlahnya tidak maksimal, dan untuk setiap bilangan $a$ di antara $k$ bilangan tersebut, $a+1$ juga termasuk di antara bilangan-bilangan tersebut. Misalkan $v$ adalah yang terkecil di antara mereka. Akibatnya, $v+1$ juga ada di antara $k$ bilangan ini. Karena $v+1$ ada di antara $k$ bilangan ini, maka $v+2$ juga ada di antara $k$ bilangan ini. Demikian pula, kita dapat menyimpulkan bahwa **$v, v+1, v+2, v+3, \dots$** semuanya ada di antara $k$ bilangan ini. Namun, karena kita hanya memiliki $k$ dari mereka, ini adalah $k$ bilangan yang akan menghasilkan jumlah maksimum ($n, n-1, n-2, \dots, n-k+1$). Ini adalah **kontradiksi**!

Jadi, di antara setiap $k$ bilangan (yang jumlahnya tidak maksimal), terdapat bilangan $a < n$ sedemikian rupa sehingga $a+1$ tidak termasuk di antara $k$ bilangan tersebut. Berdasarkan hal ini, mulai dari jumlah minimum $S$, kita dapat memperoleh $S+1$ (dengan mengganti bilangan $a$ dengan $a+1$, jumlahnya bertambah $1$), kemudian dari jumlah $S+1$, kita memperoleh jumlah $S+2$, dan seterusnya.

Oleh karena itu, dengan menerapkan prinsip induksi matematika, kita dapat memperoleh jumlah apa pun yang lebih besar dari atau sama dengan jumlah minimum dan kurang dari atau sama dengan jumlah maksimum.
### 3.1.1 | Ringkasan Matematika dalam Format MathJax

* **Jumlah Minimum:**
    $$\sum_{i=1}^{k} i = 1 + 2 + \dots + k = \frac{k(k+1)}{2}$$
<br/>

* **Jumlah Maksimum:**
    $$\sum_{i=n-k+1}^{n} i = n + (n-1) + \dots + (n-k+1)$$   $$\sum_{i=1}^{n} i - \sum_{i=1}^{n-k} i = \frac{n(n+1)}{2} - \frac{(n-k)(n-k+1)}{2} = \frac{n(n+1) - (n-k)(n-k+1)}{2}$$
<br/>

* **Kondisi Pembuktian (Inti):**
    Jika suatu himpunan $K$ dari $k$ bilangan memiliki jumlah $S < S_{\text{max}}$, maka terdapat $a \in K$ sedemikian rupa sehingga $a < n$ dan $a+1 \notin K$.

<br/>

* **Peningkatan Jumlah:**
    Jika $a \in K$ dan $a+1 \notin K$ (dengan $a<n$), mengganti $a$ dengan $a+1$ akan menghasilkan himpunan baru $K'$ dengan jumlah $S' = S+1$.

<br/>

* **Kesimpulan (Induksi):**
    Semua jumlah $S$ yang mungkin berada dalam rentang:
    $$S_{\text{min}} \le S \le S_{\text{max}}$$
    di mana $S_{\text{min}} = \frac{k(k+1)}{2}$ dan $S_{\text{max}} = \frac{n(n+1) - (n-k)(n-k+1)}{2}$.

### 3.1.2 | Kode

Berikut adalah implementasinya:

```cpp
#include <iostream>

using namespace std;

int main(){
	int t; //read the number of test cases
	cin >> t;
	while(t--){
		long long n, x, k; //read n, x, k for each test case
		cin >> n >> x >> k;
		if(2*k>=x*(x+1) && 2*k<=n*(n+1)-(n-x)*(n-x+1)){ //check if k is between the minimum and maximum sum 
			cout << "YES\n";
		}
		else cout << "NO\n";
	}	
}
```
## 3.2 | Analisis Pribadi

Ohh, kita hanya perlu mencari jumlah maksimum dan minimum yang bisa dibentuk dari memilih $k$ angka yang ada, dari $1$ hingga $n$. 

Untuk mencari jumlah minimum, kita jumlahkan dari 1 hingga $k$ angka pertama. Dan untuk mencari jumlah maksimum, kita jumlahkan angka dari $n$ menurun, hingga sebanyak $k$ kali.

Nah, kita bisa menggunakan rumus tertentu sehingga tidak dibutuhkan perulangan untuk mencari jumlah maksimum dan minimum, sehingga lebih efisien (rumusnya disebutkan diatas).

Lalu, kita hanya perlu menentukan, apakah jumlah target, yaitu $x$, ada diatara jumlah minimum dan maksimum:

$$S_{min} \leq x \leq S_{max}$$

Jika iya, maka sangat mungkin untuk mengambil $k$ angka dan memenuhi jumlah $x$, sehingga kita bisa mengoutputkan `YES`. Tapi jika tidak, maka jelas jumlah $x$ tidak mungkin tercapai, sehingga kita outputkan saja dengan `NO`.

Berikut adalah implementasiku, yang ternyat benar sesuai dugaan:

```cpp
#include<iostream>
using namespace std;

void solve() {
    long long n, k, x;
    cin >> n >> k >> x;
    long long mins, maks;
    mins = (k*(k+1))/2;
    maks = ((n*(n+1)) - ((n-k)*(n-k+1)))/2;
    if (x >= mins && x<= maks) cout << "YES\n";
    else cout << "NO\n";
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

Rumus diatas adalah cara yang langsung menuju ke solusi yang efektif, jadi kebanyakan solusi dari pengguna lain, juga tidak jauh berbeda:

### 1 | Jawaban Pertama

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
		int a,b,c;
		cin>>a>>b>>c;
		int x = a*(a+1) /2  - (a-b)*(a-b+1) /2;
		int y = b*(b+1) /2;
		if( c<=x && c>=y)cout<<"YES"<<nl;
		else cout<<"NO"<<nl;
	}
}
```

### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>

using namespace std;

void Solve() {
    
    long long int n, k, x;
    cin >> n >> k >> x;

    long long int sum1, sum2;
    sum1 = (k)*(k+1)/2;
    sum2 = (n)*(n+1)/2 - (n-k)*(n-k+1)/2;

    if(x >= sum1 && x <= sum2) cout << "YES\n";
    else cout << "NO\n";

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
     cin >> t;
    while (t--) Solve();

    return 0;
}
```

### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;

void rmbl(){
	int n,k,x; cin>>n>>x>>k;
	if (k*2>=x*(x+1) && k*2<=n*(n+1)-(n-x)*(n-x+1)) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int sp=1;
	cin>>sp;
    while(sp--){
        rmbl();
    }
}
```
