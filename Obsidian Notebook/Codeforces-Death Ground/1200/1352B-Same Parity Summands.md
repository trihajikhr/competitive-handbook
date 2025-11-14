---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1352B
judul_DEATH: Same Parity Summands
teori_DEATH: Paritas sama sebanyak k
sumber:
  - codeforces.com
rating: 1200
ada_tips: true
date_learned: 2025-11-06T21:53:00
tags:
  - constructive-algorithms
  - math
---
Sumber: [Problem - 1352B - Same Parity Summands](https://codeforces.com/problemset/problem/1352/B)

```ad-tip
title:⚔️ Teori Death Ground
Jadi, jika suatu angka bisa disusun oleh angka ganjil atau genap sebanyak $k$ elemen, maka kita tidak perlu memikirkan angka-angka yang perlu digunakan terlalu ketat, gunakan saja penyusun ganjil atau genap terkecil, yaitu $1$ dan $2$, dan angka ke-$k$ bisa kita isi dengan selisih total angka sekarang terhadap $n$.
```

<br/>

---
# 1 | 1352B-Same Parity Summands

Kamu diberikan angka $n \; (1 \leq n \leq 10^9)$ dan juga angka $k \; (1 \leq k \leq 100)$. Tentukan, apakah mungkin untuk membuat sebuah array berukuran $k$, dengan setiap nilai elemenya atau $a_i \; (0 < a_i)$ memiliki paritas yang sama (ganjil atau genap), dan jumlah dari setiap elemenya adalah sama dengan $n \; (n = a_1 + a_2 + \dots + a_k)$. 

Jika jawaban ada, maka outputkan `YES` dan rangkaian array jawaban. Jika tidak, maka outputkan `NO`.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Padahal ini soal kode B untuk DIV 4, tapi bikin pusing aku sial!

Aku yakin ini tidak terlalu sulit, tapi pada akhirnya aku merasa perlu move on, sehingga menggunakan bantuan editorial untuk melihat hint dan petunjuk awal. 

Selebihnya penjelasan ada dibagian bawah 😪.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Pertimbangkan dua kasus: ketika kita memilih semua bilangan ganjil dan semua bilangan genap.

Di kedua kasus, mari kita coba untuk memaksimalkan maksimum. Jadi, jika kita memilih bilangan ganjil, mari kita coba ambil $k-1$ buah angka satu dan sisanya $n-(k-1)$. Tetapi kita perlu memastikan bahwa sisa $n-k+1$ lebih besar dari nol dan ganjil.

Dan dalam kasus bilangan genap, mari kita coba ambil $k-1$ buah angka dua dan sisanya $n-2(k-1)$. Kita juga perlu memeriksa bahwa sisa tersebut lebih besar dari nol dan genap.

Jika tidak satu pun dari kasus-kasus ini benar, cetak "NO".

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int n1 = n - (k - 1);
		if (n1 > 0 && n1 % 2 == 1) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "1 ";
			cout << n1 << endl;
			continue;
		}
		int n2 = n - 2 * (k - 1);
		if (n2 > 0 && n2 % 2 == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; ++i) cout << "2 ";
			cout << n2 << endl;
			continue;
		}
		cout << "NO" << endl;
	}
}
```

## 3.2 | Analisis Pribadi

Pemikiran awalku ternyata sudah BENAR. Yaitu, kita sebenarnya hanya perlu menggunakan angka $1$ sebanyak $k-1$ kali, dan menentukan apakah angka tepat ke-$k$ memiliki selisih ganjil ke $n$. Atau terapkan dengan angka genap, yaitu menggunakan angka $2$ sebanyak $k-1$ kali, dan tentukan apakah tepat angka ke-$k$ memiliki selisih genap terhadap angka $n$.

Yang membuatku pusing adalah, aku berpikir bahwa kedua cara tersebut tidak bisa digunakan semudah meletakanya kedalam percabangan, yang ternyata hal itulah yang merupakan pendekatan yang seharusnya.

Oleh karena itu, jawabanya seharusnya mudah, ini adalah solusiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int a = n-k+1, b = n- 2*(k-1);
    if (a > 0 && a%2 == 1) {
        cout << "YES\n";
        for (int i=0; i<k-1; i++) {
            cout << 1 << " ";
        }
        cout << a << "\n";
    } else if (b > 0 && b%2==0) {
        cout << "YES\n";
        for (int i=0; i<k-1; i++) {
            cout << 2 << " ";
        }
        cout << b << '\n';
    } else cout << "NO\n";
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

Varriabel $a$, digunakan untuk menyimpan angka tepat ke-$k$ seadainya kita ingin menyusun array dengan paritas ganjil yang terdiri dari $k-1$ angka $1$. Nilai dari $a=n-k+1$.

Variabel $b$, digunakan untuk menyimpan angka tepat ke-$k$ seandainya kita ingin menyusun array dengan paritas genap yang terdiri dari $k-1$ angka $2$. Nilai dari $b=n-2(k-1)$.

Jadi, jika suatu angka bisa disusun oleh angka genap atau ganjil sebanyak $k$ elemen, maka kita tidak perlu memikirkan angka-angka yang perlu digunakan terlalu ketat, gunakan saja penyusun genap atau ganjil terkecil, yaitu $1$ dan $2$.
## 3.3 | Analisis Jawaban User Lain

Menurutku pendekatan editorial sudah termasuk efisien, jadi aku akan menambahkan beberapa jawaban user lain sebagai tambahan belajar saja:

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

long long t, n, k, ans1, sum;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (n % 2 == 1 && k % 2 == 0) cout << "NO" << endl;
    else {
      sum = n % k;
      if (sum % 2 == 1) sum += k;
      ans1 = (n - sum) / k;
      if (ans1 <= 0) cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        for (int i = 1; i < k; i++) cout << ans1 << " ";
        cout << ans1 + sum << endl;
      }
    }

  }
  return 0;
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int t;
int main() {
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if ((n - (k - 1)) % 2 == 1 && (n - (k - 1)) > 0) {
      cout << "YES" << endl;
      for (int i = 1; i < k; i++)
        cout << 1 << ' ';
      cout << n - (k - 1) << endl;
    } else if ((n - 2 * (k - 1)) % 2 == 0 && (n - 2 * (k - 1)) > 0) {
      cout << "YES" << endl;
      for (int i = 1; i < k; i++)
        cout << 2 << ' ';
      cout << n - 2 * (k - 1) << endl;
    } else
      cout << "NO" << endl;
  }
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
#define ii pair<int, int>
#define ll pair<long long, long long>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int mod[2] = {1000000007, 998244353};
const int N = 1e5 + 1;
const string NAME = "";
const int lim = 2147483647;
//const unsigned int lim = 4294967295;
//const long long lim = 9223372036854775807;
//const unsigned long long lim = 18446744073709551615;
const int mset = 0x3f;
const double pi = acos(-1);
int t = 1;

void solve(){
    int n, k;
    cin >> n >> k;
    if(n - k + 1 > 0){
        if((n - k + 1) % 2 != 0){
            cout << "YES\n";
            for(int i = 1; i < k; ++i)
                cout << "1 ";
            cout << n - k + 1 << "\n";
            return;
        }
    }
    if(n - 2 * k + 2 > 0){
        if((n - 2 * k + 2) % 2 == 0){
            cout << "YES\n";
            for(int i = 1; i < k; ++i)
                cout << "2 ";
            cout << n - 2 * k + 2 << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen((NAME + ".inp").c_str(), "r")){
        freopen((NAME + ".inp").c_str(), "r", stdin);
        freopen((NAME + ".out").c_str(), "w", stdout);
    }

    cin >> t;
    while(t--)
        solve();
}
```