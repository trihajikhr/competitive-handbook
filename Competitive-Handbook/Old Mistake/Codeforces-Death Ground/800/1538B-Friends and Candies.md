---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1538B
judul_DETH: Friends and Candies
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-20T16:03:00
tags:
  - greedy
  - math
---
Sumber:

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1538B-Friends and Candies

Diberikan array berukuran $n$ yang merepresentasikan banyaknya orang. Setiap orang, memiliki $a_i$ permen, dan setiap orang mungkin memiliki permen dengan jumlah yang berbeda-beda.

Tugasmu adalah menentukan nilai $k$ terkecil, yaitu banyaknya orang yang dipilih, dimana tujuanmu memilih mereka adalah menjadikan permen yang dimiliki oleh semua orang menjadi sama dengan melakukan operasi mendistribusikan permen dari $k$ orang yang telah dipilih ke orang lainya.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, pertama kita harus mendapatkan jumlah permen dari semua orang, misal $sum = \sum_{1}^{n} a_i$. Jika $sum$ tidak bisa dibagi habis oleh $n$, maka ini artinya mustahil untuk menyamaratakan kepemilikan permen ke semua orang yang ada. 

Jika $sum$ bisa dibagi habis oleh $n$, maka kita hanya perlu mencari berapa banyak orang yang memiliki jumlah permen $a_i > \frac{sum}{n}$. Ini karena orang-orang tersebut mendapatkan jumlah permen yang lebih banyak dari jumlah rerata, sehingga kita pilih untuk kita ambil beberapa.

Berikut implementasiku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

using LL = long long;
void solve() {
    LL n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
        sum += x;
    }

    if (sum % n != 0) cout << -1 << "\n";
    else {
        int diff = 0;
        for (const auto& x : v) {
            if (x > sum/n) diff++;
        }
        cout << diff << "\n";
    }
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


Mari kita notasikan $s$ sebagai jumlah permen yang dimiliki oleh semua teman: $s = \sum_{i=1}^{n} a_i$. Perhatikan bahwa pada akhirnya, setiap teman harus memiliki $\frac{s}{n}$ permen. Jika $s$ tidak habis dibagi $n$, maka tidak ada jawaban.

Bagaimana cara mendapatkan jawaban jika ada? Jika teman ke-$i$ memiliki permen lebih banyak dari $\frac{s}{n}$, maka ia harus dipilih oleh Polycarp (jika tidak, teman ini akan memiliki permen lebih banyak dari yang lain). Jika teman ke-$i$ memiliki permen tidak lebih dari $\frac{s}{n}$, maka Polycarp boleh tidak memilihnya.

Maka, jika jawabannya ada, itu sama dengan jumlah $a_i > \frac{s}{n}$.

Kode editorial:

```cpp
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int > ;
using cd = complex < ld > ;

void solve() {
    int n;
    cin >> n;
    vector < int > a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if (s % n != 0) {
        cout << "-1" << endl;
        return;
    }
    s /= n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s < a[i]) {
            res++;
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```

## 3.2 | Analisis Pribadi

Ide dan konsep dari editorial benar-benar sama dengan ide dan konsepku. Ini artinya kodeku sudah benar. Melihat dari implementasi editorial, kodeku jauh lebih pendek, tapi sama efisienya.
## 3.3 | Analisis Jawaban User Lain

Solusi dari editorial dan konsepku sudah termasuk benar dan efisien, sehingga jawaban dari pengguna lain kebanyakan tidak jauh berbeda:

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
        int a[n + 10], s = 0, p;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        
        if (s % n == 0) {
            p = s / n;
            int k = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] > p) k++;
            }
            cout << k << endl;
        } else cout << "-1" << endl;
    }
    return 0;
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;

int t, n, a[200005];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) sum += a[i];
        if (sum % n != 0) {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i <= n; i++) cnt += a[i] > sum / n;
        cout << cnt << "\n";
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long LL;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++)cin >> a[i];
    int sum = accumulate(a.begin() + 1,a.end(),0);
    if(sum % n == 0){
        int res = 0;
        sum /= n;
        for(int i = 1;i <= n;i++){
            res += a[i] > sum;
        }
        cout << res << endl;
    }else{
        cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}
```

Ohhhhh, aku baru tahu bahwa pengguaan fungsi yang biasanya meminta 2 parameter berupa `a.begin(), a.end()`, ternyata bisa digunakan untuk mengatasi 1-based index array!

Caranya adalah dengan menggunakan `a.begin() + 1`, dan semua itu sudah beres. Ohhhh baru tahu aku.

Ohh ya, fungsi `accumulate()` berguna untuk mendapatkan total semua nilai dari array, dimana defaultnya akan melakukan penjumlahan, dengan parameter ketiga adalah nilai awal atau inisialisasi. Bisa juga digunakan untuk menghitung total perkalian dari semuanya, namun hal itu bisa dipelajari di materi tersendiri.