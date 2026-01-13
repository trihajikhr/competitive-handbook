---
obsidianUIMode: preview
note_type: death ground kilat
kode_soal: 476A
judul_DEATH: Dreamoon and Stairs
sumber:
  - codeforces.com
rating: 1000
date_learned: 2025-11-30T16:28:00
tags:
  - implementation
  - math
---
Sumber: [Problem - 476A - Codeforces](https://codeforces.com/problemset/problem/476/A)

```ad-tip
title:🛡️ Review Death Ground
```

<br/>

---
# 1 | 476A-Dreamoon and Stairs

Bahas secara singkat dulu. Terdapat tangga dengan total anak tangga sebanyak $n$. Kita bisa melangkah di tangga tersebut sebanyak $1$ atau $2$ langkah sekaligus. Diberikan angka $m$ juga.

Tentukan jumlah langkah yang perlu diambil, dimana jumlah langkah tersebut bisa dibagi habis oleh $m$, dan jumlahnya harus seminimal mungkin. Jika tidak mungkin untuk menemukan jawabanya, maka outputkan $-1$.

Oke itu dia soalnya, mari kita pecahakn.

Solusinya awalnya tidak langsung ketemu, tapi terdapat sebuah pola yang jelas. Jumlah langkah yang bisa diambil, hanya berada direntang $(n+1)/2$ hingga $n$. Ini karena kita bisa menggunakan jumlah langkah seminimal mungkin dengan memperbanyak mengambil pilihan $2$ langkah, atau memperbesar jumlah langkah, dengan mengambil pilihan $1$ langkah disetiap gerakan. 

Aku mencoba mencoret-coret kertas, dan ditemukan bahwa jika $n < m$, maka jawabanya jelas tidak ada. Namun selain itu, maka jawabanya pasti ada.

Misal $n=10$ dan $m$ adalah $[1;10]$, maka semua syarat ini bisa terpenuhi, dan jawaban akan tetap ada. Coret-coret sendiri jika perlu, maka akan ditemukan bahwa langkah yang bisa diambil adalah $5,6,7,8,9,10$, dan semua angka-angka ini bisa dibagi habis oleh angka $[1;10]$.

Jadi ini solusinya, ambil nilai tengah dari $n$ yang dibulatkan keatas dengan $(n+1)/2$, misal tampung di $a$, lalu lakukan brute force sebanyak $a+10$ untuk mencari angka yang cocok, yang bisa dibagi habis oleh $m$. Jika angka ditemukan, maka outputkan angka tersebut.

Brute force haya perlu dilakukan sebanyak $10$ kali, karena semua angka $[1;10]$ pasti memiliki kelipatan disetiap $10$ angka.

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    int n, m;
    cin >> n >> m;
    if (n < m) cout << -1;
    else {
        int a = (n+1)/2;
        for (int i=a; i<= a+10; i++) {
            if (i % m == 0) {
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}
```

<br/>

---
# 2 | Analisis Singkat

Beberapa orang menemukan solusi yang memiliki kompleksitas $O(1)$, yaitu dengan mencarinya dengan rumus: 
$$\left \lceil \frac{n}{\frac{2.0}{m}} \right \rceil \times m$$

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long int n, m;
    cin >> n >> m;
    cout << ((m > n) ? -1 : ceil((n / 2.0) / m) * m) << endl;
}
```

```cpp
#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m > n) {
        cout << -1;
        return 0;
    }
    int d = m;
    while (d * 2 < n) {
        d += m;
    }
    cout << d;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int ans = ((n+1)/2+m - 1)/m*m;
    if(ans > n) cout<<"-1";
    else cout<<ans;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(n<m){
        cout<<-1;
        return 0;
    }
    cout<<(int)ceil(n/(2.0*m))*m;
    return 0;
}
```

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int ans;
    int k = n/2;

    if(n % 2 == 0){
        if(k%m!=0) ans = k+ (m-k%m);
        else ans = k;
    }

    else{
        if((k+1)%m!=0) ans = (k + 1) + (m - (k+ 1)%m);
        else ans = k+1;
    }

    if(m>n) cout << -1;
    else cout << ans;
}
```