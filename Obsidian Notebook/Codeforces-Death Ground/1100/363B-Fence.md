---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 363B
judul_DEATH: Fence
teori_DEATH: sliding windows dan prefix sum hampir sama
sumber:
  - codeforces.com
rating: 1100
ada_tips?: true
date_learned: 2025-10-06T15:11:00
tags:
---
Sumber: [Problem - 363B - Codeforces](https://codeforces.com/problemset/problem/363/B)

```ad-tip
title:⚔️ Teori Death Ground
Algoritma yang bisa digunakan untuk mengatasi jumlah segment berurutan dalam array, bukan hanya sliding windows, ternyata prefix sum juga bisa digunakan.

Bedanya adalah, sliding windows lebih hemat memory, karena tidak menggunakan array prefix. 

Sedangkan metode prefix sum, walaupun membutuhkan array tambahan, tetapi bisa menangani beberapa pencarian jumlah segment array $[l \dots r]$ dengan $O(1)$, yang jelas-jelas sangat cepat.

Intinya adalah kedua algoritma ini bisa digunakan untuk permasalahan ini, sesuaikan saja mana yang paling cocok.
```

<br/>

---
# 1 | 363B-Fence

Problemnya sederhana, kita hanya perlu mencari elemen berurutan sebanyak $w$ dalam array berukuran $n$, dimana jumlahnya adalah yang paling kecil. Lalu outputkan elemen pertama yang menjadi titik paling kiri segment array tersebut.

Dari penyederhanaan soal ini, jelas dibutuhkan teknik sliding windows untuk menyelesaikan algoritma.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Gunakan saja sliding windows, dan cari jumlah sum terkecil, dan simpan pointer $l$ jika menggunakan sliding windows dengan bantuan dua pointer.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Masalah mudah lainnya. Kita perlu menghitung **jumlah dari setiap segmen berturut-turut** dari $k$ papan (plank).

Salah satu cara untuk melakukannya adalah dengan menghitung **jumlah prefiks parsial** (partial prefix sums): $s_i = \sum_{j=1}^{i} h_j$. Kemudian, jumlah dari ketinggian papan $i, i+1, \ldots, i+k-1$ adalah **$s_{i+k-1} - s_{i-1}$**.

Pendekatan lain adalah dengan menghitung **jumlah $k$ papan pertama**: $h_1 + h_2 + \ldots + h_k$. Dengan **mengurangi $h_1$ dan menambahkan $h_{k+1}$**, kita mendapatkan jumlah $k$ papan yang dimulai dari papan kedua. Kemudian, dengan **mengurangi $h_2$ dan menambahkan $h_{k+2}$**, kita mendapatkan jumlah $k$ papan yang dimulai dari papan ketiga, dan seterusnya.

## 3.2 | Analisis Pribadi

Algoritma yang dibutuhkan untuk menyelesaikan tantangan ini sangatlah jelas, yaitu *sliding windows*. Disini, aku menggunakan 2 pointer, yaitu $l$ dan $r$ sebagai mekanisme pergeseran. Yang kita perlu cari adalah nilai sum terkecil, sehingga implementasinya bisa sebagai berikkut:

```cpp
#include<iostream>
#include<vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;

    vector<int> data(n);
    for (auto& x : data) cin >> x;
    int ans = -1, mins=INT_MAX, l=0, r=0, sum=0;

    while (r<w) sum += data[r++];
    mins = min(mins, sum);
    if (mins == sum) ans = 1;

    while (r<n) {
        sum+=data[r++];
        sum-=data[l++];
        mins = min(mins, sum);
        if (mins==sum) ans=l+1;
    }

    cout << ans;
    return 0;
}
```

Untuk algoritma ini sendiri, sebainya pelajari di bagian **Algorithm**, karena algoritma ini tidak terlalu sulit (buktinya kodenya juga pendek).

Implementasi ini hanya menggunakan $O(n)$ kompleksitas, dengan memory hanya sebesar $O(n)$. Sebelumnya aku ingin menggunakan sturktur data tambahan yaitu `queue`, tetapi aku merasa kurang efisien, karena harus menggunakan tambahan memory, yang mana padahal tidak perlu.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <iostream>
using namespace std;

main() {
    int n, k, f[150001], x, i = 1, p = 0, j = 0;
    for (cin >> n >> k; i <= n; cin >> x, p += x, f[i++] = p);
    for (i = 1; i <= n - k; i++)
        if (f[i + k] - f[i] < f[j + k] - f[j]) j = i;
    cout << j + 1;
}
```

Algoritma yang digunakan disini adalah prefix sum. Dia mencari jumlah yang ada pada setiap segment array bukan dengan cara iteratif, tapi dengan cara khas prefix sum, yaitu:

$$\sum\limits_{i=l}^{r}a_i = pref[r]-pref[l-1]$$

Bedanya dengan kode di atas: mereka geser 1 indeks, sehingga ekspresinya ditulis sebagai $f[i+k] - f[i]$. yang sebenarnya menghitung jumlah elemen dari $a[i+1]$ sampai $a[i+k]$.  
Maka inisialisasi $j=0$ mewakili segmen pertama $a[1..k]$.

### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,k,a,sum = 0,j = 0,dp[150005];

signed main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a; sum += a;
		dp[i] = sum; 
	}
	
	for(int i = 1; i <= n-k; i++){
		if(dp[i+k]-dp[i] < dp[j+k]-dp[j]) j = i;
	}
	cout << j+1;
}
```

Hampir sama seperti jawaban sebelumnya, namun dari kode ini, aku jadi tahu bahwa ternyata prefix sum, juga merupakan bagian dari dynamic programming, karena ada faktor memoization yang dilakukan didalamnya ketika membangun array prefix.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

#define all(x)(x).begin(), (x).end()

using namespace std;
using ll = long long;

const ll INF = 1e18;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector < ll > pv(n + 1);
    for (ll i = 0; i < n; ++i) {
        ll l;
        cin >> l;

        pv[i + 1] = pv[i] + l;
    }

    ll l = 0, r = l + k - 1;
    ll res = INF;
    ll ind = 0;
    while (r < n) {
        ll sum = pv[r + 1] - pv[l];

        if (sum < res) {
            res = sum;
            ind = l;
        }

        l++, r++;
    }

    cout << ind + 1 << '\n';
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    solve();
    // int t;
    // cin >> t;
    // while (t--)
    //     solve();
}
```

Nahh, tarnyata ada juga user lain yang menggunakan cara yang sama denganku, yaitu cara sliding windows. Bahkan jawabanya masuk jajaran jawaban dengan eksekusi runtime tercepat. Ini artinya implementasiku sudah benar 😀.