---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 584A
judul_DEATH: Olesya and Rodion
sumber:
  - codeforces.com
rating: 1000
date_learned: 2025-11-30T14:20:00
tags:
---
Sumber: [Problem - 584A - Codeforces](https://codeforces.com/problemset/problem/584/A)

```ad-tip
title:🛡️ Review Death Ground
Ingat! Jika angka yang diberikan terlalu besar untuk ditampung dalam int dan long long, artinya gunakan saja string sebagai penampung, atau andalkan output sebagai mekanismenya.
```

<br/>

---
# 1 | 584A-Olesya and Rodion

Jumlah digit adalah $n$, dan angka dengan digit sebanyak $n$ tersebut harus bisa dibagi dengan $t$.

Jika dipikirkan secara mendalam, maka hanya akan ada satu kasus dimana kondisi ini tidak mungkin terpenuhi, dan ini bisa dilihat dari batasan nilai $n(1 \leq n \leq 100)$ dan $t(1 \leq t \leq 10)$ yang diberikan, yaitu ketika $n=1$ dan $t=10$. 

Selain itu, maka jawaban sangat mungkin untuk dicari. Tapi ingat, banyaknya digit sangat besar, sehingga tidak mungkin memperleakukanya sebagai integer atau long long. Kita cukup mengadalkan pemahaman, bahwa angka dengan digit berapapun, bisa dibagi dengan $t$ dengan cara membuat digit pertamanya bisa dibagi oleh $t$, dan sisanay bisa kita isi dengan digit $0$.

Berikut implementasiku yang sudah benar:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    int n, t;
    cin >> n  >> t;
    if (n==1 && t ==10) {
        cout << -1;
    } else {
        cout << (t == 10 ? 1 : t);
        for (int i=0; i<n-1; i++) cout << 0;
    }
    return 0;
}
```

<br/>

---
# 2 | Analisis Singkat

Solusiku sudah sama singkat dan cepatnya.

```cpp
#include <iostream>
int main(){
int n,t;
std::cin>>n>>t;
std::cout<< ( (t>9) ? (--n) ? t : -1 : t ); 
while(--n>0)
    std::cout<<0;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    if (t == 10 && n == 1) {
        cout << -1;
        return 0;
    }
    if (t == 10) cout << 1;
    else cout << t;
    for (int i = 1; i < n; i++)
        cout << 0;
}
```

```cpp
#include<bits/stdc++.h>
#include<cmath>

using namespace std;
int main() {
    int n, k, m;
    cin >> n >> k;
    if (n == 1 && k == 10) cout << "-1";
    else if (n > 1 && k == 10) {
        for (int i = 0; i < n; i++) {
            if (i < n - 1) cout << "1";
            else if (i == n - 1) cout << "0";
        }
    } else {
        for (int i = 0; i < n; i++) {
            cout << k;
        }
    }
}
```