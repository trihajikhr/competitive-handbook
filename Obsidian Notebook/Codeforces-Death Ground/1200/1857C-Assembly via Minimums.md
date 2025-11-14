---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1857C
judul_DEATH: Assembly via Minimums
teori_DEATH: menghitung banyaknya elemen berpasangan
sumber:
  - codeforces.com
rating: 1200
ada_tips?: true
date_learned: 2025-10-18T18:22:00
tags:
---
Sumber: [Problem - 1857C - Codeforces](https://codeforces.com/problemset/problem/1857/C)

```ad-tip
title:⚔️ Teori Death Ground
Banyaknya elemen berpasangan pada suatu array berukuran $n$:

$$pair = \frac{n \times (n-1)}{2}$$
```

<br/>

---
# 1 | 1857C-Assembly via Minimums

Suatu array $b$ dibentuk dari array $a$ dengan cara memilih setiap elemen $i,j \; (i<j)$, lalu menulis nilai minimum antara $a_i$ dan $a_j$. Banyak elemen di array $b$ adalah mengambil setiap pasangan yang mungkin dari array $a$, dimana jika ukuranya adalah $n$, maka banyak elemen di array $b$ adalah $\frac{n \cdot (n-1)}{2}$.

Sebagai contoh, array $a=[2,3,5,1]$, akan menghasilkan array $b$ dengan susunan berikut:
$$\min(2, 3), \min(2, 5), \min(2, 1), \min(3, 5), \min(3, 1), min(5, 1) = [2,2,1,3,1,1]$$


Tapi, array yang diberikan ke kita adalah array $b$, dengan elemen yang sudah diacak. Dari array $b$ yang diberikan, kembalikan dan carilah susunan dari array $a$, yang memenuhi cara penyususnan diatas.

Setiap elemen $a$ berada direntang $[-10^9, 10^9]$.
<br/>

---
# 2 | Sesi Death Ground ⚔️

DIjelaskan bahwa array $b$ dalam keadaan diacak, oleh karena itu, kita bisa sorting secara ascending untuk memudahkan proses penyusunan kembali array $a$.

Dari contoh input output berikut:

```
5
3
1 3 1
2
10
4
7 5 3 5 3 3
5
2 2 2 2 2 2 2 2 2 2
5
3 0 0 -2 0 -2 0 0 -2 -2
```

Output:

```
5
3
1 3 1
2
10
4
7 5 3 5 3 3
5
2 2 2 2 2 2 2 2 2 2
5
3 0 0 -2 0 -2 0 0 -2 -2
```

Kita dapat mengambil beberapa kesimpulan:
- Jika $n=2$, maka outputkan lagi 2 elemen yang sama, itu tetap menjadi solusi yang valid.
- Jika $n=3$, maka setelah disorting, susunanya pasti akan memiliki 2 angka yang sama diawal, dan 1 angka berbeda diakhir. Kita cukup outputkan satu elemen pertama, dan dua kali elemen terakhir. Ini akan membentuk solusi yang valid. Penjelasanya ini akan terlihat di kesimpulan ketiga.

Kesimpulan ke 3, adalah jika $n$ berukuran besar, maka akan terbentuk pola sebagai berikut setelah array disorting:

Input:

```
5
3 0 0 -2 0 -2 0 0 -2 -2
```

Sorting:

```
-2 -2 -2 -2 0 0 0 0 0 3
```

Ada sebuah pola yang pasti dimiliki oleh semua inputan setelah disorting, yaitu:
1. $n-1$ elemen segment pertama memiliki nilai yang sama, dibuktikan dengan  $[-2,-2,-2,-2]$, terdapat $5-1=4$ elemen yang sama.

2. $n-2$ elemen segment kedua memiliki nilai yang sama, dibuktikan dengan $[0,0,0]$, terdapat $5-2=3$ elemen yang sama.

3. $n-3$ elemen segment ketiga memiliki nilai yang sama, dibuktikan dengan $[0,0]$, terdapat $5-3=2$ elemen yang sama.

4. $n-4$ elemen segment keempat memiliki nilai yang sama, dibuktikan dengan $3$, terdapat $5-4=1$ elemen yang sama.

5. Dan seterusnya jika $n$ berukuran besar.

Dari pola diatas, kita bisa mengambil elemen pertama dari masing-masing segment, sehingga terbentuk jawaban:

```
-2 0 0 3
```

Lalu, nilai terakhir bisa disamakan dengan elemen terakhir yang kita dapat, karena masih merupakan solusi yang valid (*tidak perlu dibedakan, untuk menghindari inputan sama dengan batas maksimum yang diperbolehkan*).

Sehingga jawaban dari inputan diatas adalah:

```
-2 0 0 3 3
```

Dan ini merupakan jawaban yang valid.

Artinya, kita hanya cukup mengetahui segment-segment pada array yang telah disorting, lalu outputkan elemen pertama dari masing-masing segment. Berikut adalah implementasiku untuk penjelasan ini:

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vec((n * (n-1))/2);
    for (auto& x : vec) {
        cin >> x;
    }
    ranges::sort(vec);
    if (n==2) {
        cout << vec[0] << " " << vec[0] << '\n';
    } else if (n==3) {
        cout << vec[0] << " " << vec[2] << " " << vec[2] << '\n';
    } else {
        int diff = n-1, curr=0;
        while (diff > 0) {
            cout << vec[curr] << " ";
            curr+=diff;
            diff--;
        }
        cout << vec[vec.size()-1] << '\n';
    }
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

Misalnya kita punya *array* $a$ yang ingin kita konstruksi, dengan elemen $a_1, a_2, \dots, a_n$. Untuk menyederhanakan proses, mari kita asumsikan bahwa elemen-elemen dari $a$ diurutkan dalam urutan tidak menurun (*non-decreasing order*), artinya $a_1 \le a_2 \le \dots \le a_n$.


Mari kita mulai dengan $a_1$. Karena elemen-elemen $a$ diurutkan, pasangan-pasangan $(a_1, a_2), (a_1, a_3), \dots, (a_1, a_n)$ akan memiliki $a_1$ sebagai elemen terkecil di setiap pasangan. Oleh karena itu, jumlah kemunculan $a_1$ dalam *array* $b$ akan menjadi $n-1$.

Lanjut ke $a_2$. Kita sudah tahu bahwa $a_1$ muncul sebanyak $n-1$ kali dalam $b$. Karena elemen-elemen $a$ diurutkan, semua pasangan yang melibatkan $a_2$ (kecuali pasangan $(a_1, a_2)$ yang sudah dihitung sebelumnya) akan memiliki $a_2$ sebagai elemen terkecil kedua. Ini berarti $a_2$ akan muncul sebanyak $n-2$ kali dalam *array* $b$.

Kita lanjutkan proses ini untuk setiap elemen $a_i$ dalam $a$. Jumlah kemunculan $a_i$ dalam *array* $b$ akan menjadi **$n-i$**.

Kita tidak dapat menentukan nilai pasti dari $a_n$, karena nilai tersebut tidak akan ditulis ke *array* b. Oleh karena itu, untuk $a_n$ kita dapat memilih bilangan berapa pun dalam rentang $[a_{n-1}; 10^9]$.

Jika ada beberapa elemen $b_i$ dalam *array* $b$ yang memenuhi kondisi untuk $a_i$ tertentu, kita memilih $b_i$ yang terkecil. Pendekatan *greedy* (rakus) ini berhasil karena kita sedang mengkonstruksi a dalam urutan tidak menurun.

Kompleksitasnya adalah $\mathcal{O}(n^2 \log n)$.

Implementasi:

```cpp
#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m = n * (n - 1) / 2, b[m];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(b, b + m);
        for (int i = 0; i < m; i += --n) cout << b[i] << ' ';
        cout << "1000000000\n";
    }
}
```

## 3.2 | Analisis Pribadi

Solusi dari editorial jauh lebih ringkas, dan untuk kasus $n=2$ atau $n=3$, ternyata tidak dibedakan pun tidak masalah. Oke, aku meningkatkan efisiensi kodeku, menjadi seperti ini, mengacu pada editorial:

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = (n * (n-1))/2;
    vector<int> vec(m);
    for (auto& x : vec) cin >> x;
    ranges::sort(vec);
    for (int i=0; i < m; i+= --n) {
        cout << vec[i] << " ";
    }
    cout << vec[vec.size()-1] << '\n';
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
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m = n * (n - 1) / 2;
        vector < int > v(m);
        for (auto & i: v) cin >> i;
        sort(v.begin(), v.end());
        for (int i = 0; i < m; i += --n) cout << v[i] << ' ';
        cout << 1000000000 << endl;

    }
}
```

Banyak orang yang memiliki jawaban yang hampir mirip dengan editorial, jadi aku akan tetapi memasukanya.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(),v.end()
#define loop(i,a,b,d) for(int i=a; i<b; i+=d)
#define fr(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define ret(msg) {cout << msg << endl; return;}
inline int popcnt (int x) { return __builtin_popcountll(x); }
#define mod 1000000007
#define MOD 998244353

void solve() {
    int n;
    cin >> n;
    
    int m = (n*(n-1))/2;
    vi a(m);
    rep(i,m) {
        cin >> a[i];
    }

    sort(all(a));
    int k = 0;
    fr(i,1,n) {
        cout << a[k] << " ";
        k += n-i;
    }
    ret(a[m-1])
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
```

Kode kedua, lebih mirip implementasi pertamaku, namun banyak sekali penggunaan alias disini, butuh fokus ekstra untuk mempelajari apa yang dimaksud oleh kode ini.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define ull unsigned long long
#define vb v.begin()
#define ve v.end()
#define vc v.clear()
#define vs (int)v.size()
#define ss (int)s.size()
#define sb s.back()
#define rs(i) resize(i)
#define ft first
#define sd second
#define inf 0x3f3f3f3f
#define P pair<int, int>
#define forn(i, a, b) for (int i = a; i < b; i++)
#define fore(i, a, b) for (int i = a; i <= b; i++)
#define rofn(i, a, b) for (int i = a; i > b; i--)
#define rofe(i, a, b) for (int i = a; i >= b; i--)
#define Ios ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n;
    m = (n * n - n) / 2;
    vector<int> v(m);
    forn(i, 0, m) {
        cin >> v[i];
    }
    sort(vb, ve);
    int i = 0, k = n;
    while (i < m) {
        cout << v[i] << " ";
        k--;
        i += k;
    }
    cout << v.back() << "\n";
}
signed main() {
    Ios;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
```

Walaupun lebih panjang, pada akhirnya konsep dan ide adalah sama. 