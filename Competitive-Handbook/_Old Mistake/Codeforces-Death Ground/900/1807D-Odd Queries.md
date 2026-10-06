---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1807D
judul_DEATH: Odd Queries
teori_DEATH: prefix sum problem
sumber:
  - codeforces.com
ada_tips?: true
date_learned: 2025-10-04T16:16:00
tags:
  - math
  - algorithm
---
Sumber: [Problem - 1807D - Codeforces](https://codeforces.com/problemset/problem/1807/D)

```ad-tip
title:⚔️ Teori Death Ground

Algoritma baru! **Prefix Sum algorithm**
```

<br/>

---
# 1 | 1807D-Odd Queries

Ada sebanyak $t$ test case, untuk setiap test case:

Inputan pertama adalah $n$ dan $q$, dimana $n$ adalah banyaknya array, dan $q$ adalah banyaknya queries untuk satu test case.

Lalu dibaris kedua kita diberikan $n$ elemen array.

Dibaris ketiga, untuk setiap $q$ test case, kita akan diberi 3 inputan, yaitu $l,r$ dan $k$.

Tugas kita adalah menentukan, jika semisal kita mengganti nilai array, dari urutan ke $a_l$ hingga $a_r$ dengan $k$, maka jumlah array adalah ganjil.

Jika ganjil, maka outputkan `YES`, jika tidak maka outputkan `NO`.

> 😎 Aku berhasil menyelesaikan tantangan ini, walaupun lebih dari trial of ten, tapi selama ada gambaran apa yang harus dikerjakan, sepertinya tidak masalah.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Aku sudah pernah mencoba soal ini, dan melakukan iteratif manual (untuk setiap queries) hanya akan menghasilkan *time limit exceed*, yang berarti pendekatan seperti ini bukanlah pendekatan yang efisien.

Ini adalah contoh pendekatan yang yang aku maksud terkena *time limit exceed* (tidak efisien):

```cpp
#include<iostream>
#include<vector>
using namespace std;

using LL = long long;

void solve() {
    int n, t;
    cin >> n >> t;
    vector<LL> data(n+1);
    long long sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> data[i];
        sum += data[i];
    }

    while (t--) {
        LL l,r,k, temp = sum;
        cin >> l >> r >> k;
        for (int i=l; i<=r; i++) {
            temp-=data[i];
        }

        temp+= k * ((r-l)+1);
        cout << (temp%2 ? "YES" : "NO") << '\n';
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
```

Alih-alih menggunakan cara manual, ada algoritma tertentu yang akan menjadi solusi utama dari permasalahan ini, algoritma tersebut adalah **Prefix Sum Algorithm**.

Dengan membangun prefix sum dengan kompleksitas $O(n)$, kita bisa menentukan apakah jumlah array yang diganti dengan $k$ dari $a_l$ hingga $a_r$ adalah ganjil atau tidak, cukup dengan $O(1)$ kompleksitas.

Pelajari algoritma ini di materi algoritma terpisah, namun berikut solusi singkatnya.

Pertama, buat 2 vector dengan ukuran $n$ untuk menampung array, dan ukuran $n+1$ untuk prefix sum (vector prefix sum akan menggunakan 1-based index, jadi tambahkan dengan 1).

Setelah prefix sum terbentuk, kita bisa mengetahui bahwa jumlah dari semua array pastinya adalah $pref[n]$.

Jika kita mengganti array $a_l$ hingga $a_r$, maka kita kurangi hasil total tersebut, dengan jumlah dari elemen-elemen yang dihilangkan, dengan rumus:

$$ans=pref[n]-(pref[r]-pref[l-1])$$
Setelah itu, nilai dari $ans$ kita tambahkan banyaknya elemen yang diganti dengan $k$, kita bisa menggunakan rumus berikut:

$$ans += ((r-l)+1)\times k$$
Jika $r=5$ dan $l=3$, maka kita mengganti array ke-3 hingga ke-5. Totalnya adalah 3 (yaitu array ke 3,4,5). Jadi, untuk mendapatkan angka 3, selisihnya kita tambahkan dengan 1. Setelah itu kita kalikan dengan $k$, yaitu angka yang akan menggantikan semua elemen yang digantikan tadi.

Lalu, kita tentukan apakah nilai dari $ans$ adalah ganjil, dengan cara menggunakan operasi modulo:

$$ans \; \%  \; 2 = \begin{cases}
\text{YES} &\text{if } mod == 1 \\
\text{NO} &\text{if } mod == 0 \\

\end{cases}$$

Sehingga, berikut adalah implementasi yang benar:

```cpp
#include<iostream>
#include<vector>
using namespace std;

using LL = long long;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> data(n), pref(n+1,0);
    for (int i=0; i<n; i++) {
        cin >> data[i];
        pref[i+1] = pref[i]+data[i];
    }

    while (k--) {
        LL l,r,c;
        cin >> l >> r >> c;
        if (((pref[n]-(pref[r]-pref[l-1])) + 
	        (((r-l)+1)*c)) % 2 == 1) {
            cout << "YES\n";
        } else cout << "NO\n";
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

Perhatikan bahwa untuk setiap pertanyaan, susunan (*array*) yang dihasilkan adalah **$[a_1, a_2, \dots, a_{l-1}, k, \dots, k, a_{r+1}, a_{r+2}, \dots, a_n]$**.

Jadi, jumlah elemen dari susunan baru setelah setiap pertanyaan adalah:
$$a_1 + \dots + a_{l-1} + (r - l + 1) \cdot k + a_{r+1} + \dots + a_n$$

Kita dapat menghitung $a_1 + \dots + a_{l-1}$ dan $a_{r+1} + \dots + a_n$ dalam waktu $\mathcal{O}(1)$ dengan melakukan pra-hitung (*precomputing*) jumlah semua *prefix* (jumlah awal) dan *suffix* (jumlah akhir), atau alternatifnya dengan menggunakan teknik **jumlah prefix** (*prefix sums*). Dengan demikian, kita dapat menemukan jumlah setiap kali dalam $\mathcal{O}(1)$ per pertanyaan, dan hanya perlu memeriksa apakah hasilnya ganjil atau tidak.

Kompleksitas waktu (*Time complexity*) totalnya adalah **$\mathcal{O}(n+q)$**.

Berikut adalah implementasinya:

```cpp
#include <iostream>
 
using namespace std;
long long n,a[200005],q,sum=0,pref[200005],t;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--)
    {
        sum = 0;
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            sum+=a[i];
            pref[i]=pref[i-1];
            pref[i]+=a[i];
        }
        for(int i = 0; i < q; i++){
            long long l,r,k;
            cin >> l >> r >> k;
            long long ans = pref[n]-(pref[r]-pref[l-1])+k*(r-l+1);
            if(ans%2==1){
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
}
```
## 3.2 | Analisis Pribadi

Setelah aku pikir-pikir kembali, sepertinya kita tidak perlu membuat 2 vector. Langsung saja terima inputan untuk membangun prefix sum, sehingga alokasi memory jauh lebih efisien. 

Berikut implementasinya:

```cpp
#include<iostream>
#include<vector>
using namespace std;

using LL = long long;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> pref(n+1,0);
    for (int i=0, x; i<n; i++) {
        cin >> x;
        pref[i+1] = pref[i]+x;
    }

    while (k--) {
        LL l,r,c;
        cin >> l >> r >> c;
        if (((pref[n]-(pref[r]-pref[l-1])) + 
	        (((r-l)+1)*c)) % 2 == 1) {
            cout << "YES\n";
        } else cout << "NO\n";
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
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>  
using namespace std;

int main() {  
	long long t, n, q, l, r, k, i, x;  
	cin >> t;
	
	while (t--) {
	    cin >> n >> q;
	    long long a[n + 1], b[n + 1] = {0};
	
	    for (i = 1; i <= n; i++) {
	        cin >> a[i];
	        b[i] = b[i - 1] + a[i];
	    }
	
	    while (q--) {
	        cin >> l >> r >> k;
	        x = b[n] + (r - l + 1) * k - (b[r] - b[l - 1]);
	        if (x % 2)
	            cout << "YES" << endl;
	        else
	            cout << "NO" << endl;
	    }
	}
	
	return 0;
}
```

Solusinya hampir sama dengan jawaban pertamaku, namun secara memory, sepertinya jauh lebih efisien jawaban miliku.

### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
#define read(a) for(auto &c : a) cin >> c
using namespace std;
using i64 = long long;

void solve(){
    int n, q; cin >> n >> q;
    vector<i64> a(n); read(a);
    for(int i = 1; i < n; i++){
	a[i] += a[i - 1];
    }
    while(q--){
	i64 l, r, k;
	cin >> l >> r >> k;
        i64 range = l - 2 >= 0 ? a[r - 1] - a[l - 2] : a[r - 1];
	if((a[n - 1] - range + ((r - l + 1) * k)) % 2)
	    cout << "YES" << '\n';
	else
	    cout << "NO" << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--)
	solve();
}
```

Solusinya juga hampir sama, tetapi array yang digunakan disini menggunakan 0-based index, sehingga harus memainkan penggunaan `n-1` dan `n-2`. Penggunaan memory juga sudah efisien, karena hanya menggunakan satu vector prefix sum.

Untuk kode berikut:

```cpp
i64 range = l - 2 >= 0 ? a[r - 1] - a[l - 2] : a[r - 1];
```

Mungkin penulis ingin menentukan, apakah titik perubahan (lokasi dari $l$) ada di awal array, atau ada di tengah-tengah. Hal ini dikarenakan penulis menggunakan 0-based index, sehingga harus dipastikan bahwa ketika menggunakan $a[l-2]$, indexnya tidak malah mengarah ke $-1$. Tetapi, jika penulis menggunakan array 1-based index, hal ini sebenarnya tidak diperlukan.

### 3 | Jawaban Ketiga

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
typedef long long ll;
#define all(v) v.begin(), v.end()

int get (int& x) {
	return (x + 300000) % 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t, n, q, k, l, r;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		vector<int>a(n); 
		for (int i = 0; i < n; ++i) {
			cin >> k;
			a[i] = k % 2;
		}
		vector<int> p(n + 1, 0);
		for (int i = 0; i < n; ++i) p[i + 1] = (p[i] + a[i])%2;
		int sm = (accumulate(all(a), 0))%2;
		while (q--) {
			cin >> l >> r >> k;
			k %= 2;
			int res = sm - (p[r] - p[l - 1]) + (r-l+1)*k;
			res = get(res);
			cout << (res % 2 ? "YES\n" : "NO\n");
		}
	}
}
```

Well, ini adalah jawaban yang cukup unik.

Alih-alih menyimpan nilai asli, penulis ini hanya mencatat apakah setiap elemen yang dimasukan adalah ganjil atau genap, dimana jika ganjil maka menyimpan 1, dan jika genap maka menyimpan 0 (karena menggunakan % 2).

Dia juga membangun prefix sum hanya dari angka-angka 0 dan 1, lalu menjumlahkanya:

```cpp
vector<int> p(n + 1, 0);
for (int i = 0; i < n; ++i) p[i + 1] = (p[i] + a[i])%2;
int sm = (accumulate(all(a), 0))%2;
```

Sepertinya, penulis ini menggunakan aturan berikut:

- $genap$ + $genap$, hasilnya akan selalu genap, tidak peduli berapa kali penjumlahan ini dilakukan.
- $ganjil$ + $ganjil$, hasilnya akan genap, tapi bisa berbeda jika dilakukan lebih dari beberapa kali. Katakanlah $x$ adalah kemunculan angka ganjil. Jika $x$ genap, maka total jumlahnya pasti akan genap. Tapi jika $x$ adalah ganjil, maka total jumlahnya pasti ganjil.
- $ganjil$ + $genap$, hasilnya pasti selalu ganjil.

Dengan menggunakan aturan ini, penulis cukup hanya menggunakan tipe data `int`, karena dijamin angkanya tidak mungkin membengkak (solusi yang lain menggunakan `long long`).

Lalu, nilai $k$ juga dimodulo kan dengan 2, jika genap, maka $k=0$, jika ganjil, maka $k=1$. Masih menerapkan aturan ganjil genap 😀.

Jumlah dari perubahan nilainya ditampung didalam variabel `res`. Disini penulis menggunakan fungsi `get()`, yang sebenarnya tidak perlu. Fungsi `get()` bisa langsung kita hapus, dan langsung saja ke operasi terakhir, yaitu pengecekan apakah `res` ganjil atau genap.


