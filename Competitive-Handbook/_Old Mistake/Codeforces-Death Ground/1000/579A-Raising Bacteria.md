---
obsidianUIMode: preview
note_type: death ground
kode_soal: 579A
judul_DEATH: Raising Bacteria
teori_DEATH: bitmask dan pengecekan apakah suatu angka habis dibagi 2
sumber:
  - codeforces.com
rating: 1000
ada_tips: true
date_learned: 2025-11-29T20:16:00
tags:
  - bitmask
---
Sumber: [Problem - 579A - Codeforces](https://codeforces.com/problemset/problem/579/A)

```ad-tip
title:⚔️ Teori Death Ground
C++ sudah menyediakan fungsi untuk menghitung digit $1$ pada representasi angka integer $x$ dengan menggunakan fungsi `__builtin_popcount(x)`. Untuk long long menggunakan `__builtin_popcountll(x)`.

Sedangkan untuk menghitung digit 0 pada representasi biner, caranya lebih sulit. Mungkin pelajari ini dimateri terpisah, khusus bitmask dan bitwise. 
```

<br/>

---
# 1 | 579A-Raising Bacteria

Ditumbuhkan beberapa bakteri pada sebuah box. Setiap hari, jumlah bakteri didalam box berlipat ganda menjadi dua kali lipat, karena setiap bakteri membelah diri menjadi dua. Kamu berharap, tepat pada hari tertentu, kamu memiliki tepat $x$ bakteri pada box. Tentukan jumlah bakteri minimal yang perlu dimasukan pada box, jika jumlah hari yang diperlukan tidak dibatasi.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Ada sebuah pola. Jika jumlah bakteri yang ingin dilihat adalah $x$, maka jika $x$ adalah sebuah angka hasil dari perpangkatan $2$, maka kita hanya membutuhkan $1$ bakteri saja. Misal, nilai $x=1,2,4,8,16,32,64,128, dst$, maka kita hanya perlu menaruh tepat $1$ bakteri saja pada box, dan menunggu setiap bakteri berlipat ganda.

Artinya, kita hanya perlu berurusan dengan semisal angka $x$ bukan hasil dari perpangkatan $2$. Maka solusinya mudah.

Cara pertama adalah dengan menggunakan bitmask, namun aku tidak terlalu kuat pada algoritma ini, sehingga aku akan menggunakan cara kedua.

Cara kedua adalah dengan melakukan precompute, menyimpan semua angka hasil perpangkatan $2$, misal kita simpan di array $v$, dan melakukan pengurangan terhadap $x$ hingga habis. Pengurangan dilakukan dengan mencari angka hasil perpangkatan dengan $2$ pada array $v$ yang tidak melebihi $x$, bisa sama atau kurang dari $x$. Lalu kurangi $x$ dengan nilai tersebut.

Logika penyelesaianya, adalah bahwa kita harus meminimalkan penambahan bakteri pada box. Sehingga kita harus mengandalkan setiap bakteri berlipat ganda sendirinya. Kita tidak melakukan pendekatan dari depan ke belakang, namun dari belakang ke depan. Yaitu kita mencoba memulai dari bagaimana semisal kita memiliki $x$ bakteri, maka hitung berapa banyak angka hasil perpangkatan $2$ yang dibutuhkan untuk menghabiskan jumlah bakteri $x$.

Kita bisa menggunakan algoritma binary search, yaitu menggunakan fungsi `lower_bound()` untuk mencari posisi yang sesuai dari kumpulan array hasil perpangkatan dengan $2$, lalu simpan hasilnya pada variabel misal $idx$. Jika $x\equiv v[idx]$, maka lakukan $x=x-v[idx]$, tapi jika tidak sama, maka lakukan $x=x-v[idx-1]$, karena kita mengambil nilai dibawahnya.

Dibutuhkan pemahaman bagaimana fungsi `lower_bound()` bekerja untuk memahami hal ini.

Berikut adalah implementasiku yang sudah benar:

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void precompute(vector<int>& v) {
    long long cur = 1;
    while (cur <= INT_MAX) {
        cur *= 2;
        v.push_back(cur);
    }
}

auto main() -> int {
    vector<int> v;
    precompute(v);

    int n, ans = 0;
    cin >> n;
    while (n > 0) {
        int idx = lower_bound(v.begin(), v.end(), n) - v.begin();
        n -= v[idx] == n ? v[idx] : v[idx-1];
        ans++;
    }

    cout << ans;
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tuliskan $x$ dalam bentuk biner. Jika bit ke-$i$ dari sisi *least significant* bernilai $1$ dan representasi biner $x$ memiliki $n$ bit, maka kita menaruh satu bakteri ke dalam kotak pada pagi hari di hari ke-$(n + 1 - i)$.

Kemudian, pada siang hari di hari ke-$n$, kotak tersebut akan berisi $x$ bakteri.

Dengan demikian, jawabannya adalah jumlah bit $1$ dalam representasi biner dari $x$.

Implementasi editorial:

```cpp
#include<cstdio>
int main(){
    int n,an=0;
    scanf("%d",&n);
    while(n){
        if(n&1)an++;
        n>>=1;
    }
    printf("%d\n",an);
    return 0;
}
```
## 3.2 | Analisis Pribadi

Sepertinya menggunakan fungsi bawaan C++ untuk menghitung jumlah bit $1$ pada representasi biner $x$ menjadi solusi yang jauh lebih cepat wkwkw..

Menggunakan fungsi `__builtin_popcount(x)`, kita bisa menghitung berapa banyak digit $1$ pada representasi biner angka $x$ dengan lebih cepat.

Mungkin ini kode baruku, cara bitmask yang aku maksud diawal (yang aku belum tahu):

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    int x;
    cin >> x;
    cout << __builtin_popcount(x);
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <iostream>
main() {
    int i;
    std::cin >> i;
    std::cout << __builtin_popcount(i);
}
```

Mayoritas, sangat banyak orang yang menggunakan fungsi ini. Fungsi ini berguna untuk menghitung berapa banyak digit $1$ pada representasi binera angka $i$. Cara yang jauh lebih cepat dan efisien.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    long int n, k;
    while (cin >> n) {
        k = 0;
        while (n > 1) {
            if (n % 2 == 0)
                n = n / 2;
            else {
                n = n - 1;
                k++;
            }
        }
        cout << k + 1 << endl;
    }
    return 0;
}
```

Menghitung digit $1$ pada representasi biner secara manual dengan menggunakan operasi modulo.
### 3 | Jawaban Ketiga

```cpp
#include <iostream>
using namespace std;
int main(){
    long long x;
    long long ans=0;
    cin>>x;
    while (x!=0){
        if (x%2==1)
            ans++;
        x=x/2;
        
    }
    cout<<ans<<endl;
    return 0;
}
```

Cara ini hampir sama dengan kode kedua.