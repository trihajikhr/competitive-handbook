---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 580A
judul_DEATH: Kefa and First Steps
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips:
date_learned: 2025-11-27T21:06:00
tags:
  - brute-force
  - dynamic-programming
  - implementation
---
Sumber:

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 580A-Kefa and First Steps

Diberikan sebuah array integer yaitu $n$. Tentukan, dari beberapa angka yang ada didalamnya, nilai berurutan terpanjang yang tidak menurun.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, kita hanya perlu melakukan traversal pada array, dan selama nilai dari $a_i \leq a_{i+1}$, maka tambahkan nilai pada variabel counter. Namun ada cara yang lebih cepat, tanpa menggunakan array sama sekali, yaitu dengan menggunakan 2 variabel bantu, untuk mendeteksi variabel yang menampung data yang sekarang dimasukan, dengan variabel yang menampung data inputan sebelumnya. Lalu lakukan perbandingan pada 2 variabel tersebut.

Cara ini lebih efisien, karena lebih hemat memory:

```cpp
#include <algorithm>
#include <iostream>
using namespace std;
 
auto main() -> int {
    int n = 0;
    cin >> n;
    int cnt = 0;
    int maks = 0;
    int prev = 0;
    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            cnt++;
            prev = x;
            continue;
        }
 
        if (x < prev) {
            maks = max(maks, cnt);
            cnt = 0;
        }
 
        cnt++;
        prev = x;
    }
 
    cout << max(maks, cnt);
    return 0;
}
```

Atau ini:

```cpp
#include<iostream>
#include<vector>
using namespace std;
 
auto main() -> int {
    int n;
    cin >> n;
    int cur = 1, prev = -1, cnt = 1, ans = 0;
 
    for (int i=0; i<n; i++) {
        cin >> cur;
        if (prev != -1) {
            if (cur >= prev) {
                cnt++;
            } else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
 
        prev = cur;
    }
 
    ans = max(ans, cnt);
    cout << ans ;
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Catatan, bahwa jika *array* memiliki dua sub-barisan tidak menurun (*non-decreasing subsequence*) kontinu yang saling berpotongan, keduanya dapat digabungkan menjadi satu. Oleh karena itu, Anda dapat memproses *array* hanya dari kiri ke kanan. Jika sub-barisan yang sedang berjalan dapat dilanjutkan menggunakan elemen ke-$i$, maka kita melakukannya; jika tidak, kita memulai sub-barisan baru. Jawabannya adalah sub-barisan maksimum dari semua yang ditemukan.

Asimtotik—$O(n)$.

Implementasi editorial:

```cpp
#include<iostream>
#include<stdio.h>
using namespace std;
const long long A=100000000000000LL,N=228228;
 
long long a[N],k,o,i,j,n,m;
 
int main(){
	cin>>n;
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	k=1;
	for(i=1;i<n;i++)if(a[i]>=a[i-1])k++;else o=max(o,k),k=1;
	o=max(o,k);
	cout<<o;
}
```

## 3.2 | Analisis Pribadi

Walau kode implementasi lebih singkat, namun penggunaan array didalamnya membuatnya tidak jauh lebih efisien daripada kode pertamaku. Lagipula, kompleksitas waktu keduanya adalah sama-sama $O(n)$, sehingga jelas kode implementasi tidak efisien secara memory.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, sum = 0, max = 0, fa = INT_MAX, a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a >= fa)
      sum++;
    else
      sum = 0;
    if (max < sum)
      max = sum;
    fa = a;
  }
  cout << max + 1;
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0, len = 0, prev = 0, n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    if (k >= prev) ans = max(ans, ++len);
    else len = 1;
    prev = k;
  }
  cout << ans;
}
```
### 3 | Jawaban Ketiga

```cpp
//                        بسم الله الرحمن الرحيم

#include <bits/stdc++.h>
#define int long long
#define I ios_base::sync_with_stdio(0);
#define Love cin.tie(NULL);
#define Coding cout.tie(NULL);
#define endl "\n"
#define all(ls) ls.begin(), ls.end()
#define sum(ls) accumulate(all(ls), 0)
using namespace std;

//      Granteed for testcase 1


 
void solve() {
    int n, mx_c = -1e9, c = 1;
    cin >> n;
    vector<int>ls;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ls.push_back(a);
    }
     
    for(int i = 0; i < n-1; i++){
        if(ls[i+1] >= ls[i]){
            c++;
        }
        else{
            mx_c = max(mx_c, c);
            c = 1;
        }
    }
    mx_c = max(mx_c, c);
    cout << mx_c << endl;
}

signed main() {
    I Love Coding

    solve();
}
```