---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1471A
judul_DEATH: Strange Partition
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-08T16:01:00
tags:
---
Sumber: https://codeforces.com/problemset/problem/1471/A

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1471A-Strange Partition

Kita diminta untuk menentukan nilai minimal dan maksimal yang bisa dihasilkan, dari sebuah array, dimana kita bisa memilih 2 elemen berpasangan ($a_i$ dan $a_{i+1}$) untuk digantikan dengan $a_i + a_{i+1}$, lalu  melakukan operasi berikut:
$$\sum_{i=1}^k \left\lceil \frac{b_i}{x} \right\rceil$$


Keindahan dari suatu array $b=[b_1, \ldots, b_k]$ didefinisikan sebagai $\sum_{i=1}^{k} \lceil \frac{b_i}{x} \rceil$, yang berarti kita membagi setiap elemen dengan $x$, membulatkannya ke bilangan bulat terdekat di atas (pembulatan ke atas), dan menjumlahkan nilai-nilai yang dihasilkan. Sebagai contoh, jika $x=3$, dan arraynya adalah $[4, 11, 6]$, keindahan larik tersebut adalah sama dengan $\lceil \frac{4}{3} \rceil + \lceil \frac{11}{3} \rceil + \lceil \frac{6}{3} \rceil = 2 + 4 + 2 = 8$.

Tentukan nilai minimal dan maksimal dari keindahan array, jika kita bisa memilih dua elemen berpasangan, dan menggabungkanya menjadi satu!

---
# 2 | Sesi Death Ground ⚔️

Karena keindahan array didapat dari menjumlahkan hasil dari setiap $\lceil \frac{a_i}{x} \rceil$. Maka jelas, bahwa nilai maksimal hanya bisa didapat jika kita membiarkan suatu elemen array tidak habis dibagi dengan nilai $x$. Artinya adalah, kita tidak perlu melakukan penggabungan elemen array sama sekali untuk bisa mendapatkan nilai maksimal yang mungkin, kita hanya perlu melakukan operasi $\sum_{i=1}^n \lceil \frac{a_i}{x} \rceil$ , sehingga elemen yang tidak habis dibagi dengan $x$ akan memaksimalkan total keindahan array (memanfaatkan pembulatan keatas).

Sedangkan untuk meminimalkan keindahan array, kita perlu menggabungkan semua elemen berpasangan pada array menjadi satu, atau menjumlahkan hasilnya langsung, lalu baru melakukan operasi $\lceil \frac{\sum_{i=1}^n a_i}{x} \rceil$. Alasanya adalah, hal ini akan membuat operasi pembulatan hanya dilakukan sekali.

Intinya, nilai maksimal didapat dari melakukan operasi pembulatan keatas sebanyak mungkin, yaitu sebanyak $n$ kali. Sedangkan nilai minimal didapat dari melakukan operasi pembulatan sesedikit mungkin, yaitu hanya sekali.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

using LL = long long;

void solve() {
    LL n, x;
    cin >> n >> x;
    LL minSum = 0, makSum=0;
    vector<LL> data(n);
    for (auto& k : data) {
        cin >> k;
        minSum += k;
        makSum += (k+(x-1))/x;
    }

    cout << (minSum+(x-1))/x << " " << makSum << '\n';
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

Perhatikan bahwa, $\lceil \frac{a+b}{x} \rceil \leq \lceil \frac{a}{x} \rceil + \lceil \frac{b}{x} \rceil$. Ini berarti bahwa **jumlah maksimal** dicapai jika kita tidak menerapkan operasi apa pun, dan **jumlah minimal** dicapai jika kita mengganti semua elemen dengan satu elemen tunggal, yang nilainya sama dengan jumlah dari semua elemen.
## 3.2 | Analisis Pribadi

Solusi yang aku temukan sudah benar, namun masih bisa dibuat lebih efisien lagi, dengan cara tidak perlu menggunakan array. Langsung saja simpan hasil inputan pada variabel final. 

Implementasinya adalah sebagai berikut:

```cpp
#include<iostream>
using namespace std;

using LL = long long;
void solve() {
    LL n, x;
    cin >> n >> x;
    LL minSum = 0, makSum=0;
    for (int i=0, k; i<n; i++) {
        cin >> k;
        minSum += k;
        makSum += (k+(x-1))/x;
    }

    cout << (minSum+(x-1))/x << " " << makSum << '\n';
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

Solusi dari editorial, dan yang aku temukan, sudah merupakan solusi yang paling optimal, sehingga jawaban dari user lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>

int main() {
    using namespace std;
    int T;
    cin >> T;
    while (T--) {
        int N, X;
        cin >> N >> X;
        int64_t a = 0, b = 0;
        while (N--) {
            int v;
            cin >> v;
            a += v;
            b += (v + X - 1) / X;
        }
        cout << (a + X - 1) / X << ' ' << b << '\n';
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,i,j;
		cin>>n>>k;
		long long int a[n],mini=0,maxi=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			mini+=(a[i]+k-1)/k;
			maxi+=a[i];
		}
		cout<<(maxi+k-1)/k<<" "<<mini<<"\n";
	}
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define gcd __gcd
#define yes cout<<"YES";
#define no cout<<"NO\n";
#define fi first
#define se second
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll salmon=1,ans=0;
    cin>>salmon;
    //p=salmon%2;+
    while(salmon--)
    {
        ll n,a,ans=0,x=0,l=0;
        cin>>n>>a;
        ll a1[n+4];
        for(int i=0;i<n;i++)
        {
            cin>>a1[i];
            ans+=a1[i];
            l+=(a1[i]+a-1)/a;
        }
        ans+=a;
        ans--;
        cout<<ans/a<<" "<<l<<endl;
    }
}
```