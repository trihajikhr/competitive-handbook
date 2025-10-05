---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 556A
judul_DEATH: Case of the Zeros and Ones
teori_DEATH:
sumber:
  - codeforces.com
ada_tips?: true
date_learned: 2025-10-04T15:15:00
tags:
  - string
---
Sumber: [Problem - 556A - Codeforces](https://codeforces.com/problemset/problem/556/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 556A-Case of the Zeros and Ones

Kita diminta untuk menentukan panjang minimal string (yang hanya terdiri dari 1 dan 0), jika untuk setiap pasangan 1 dan 0, bisa kita keluarkan dari string. 

Dalam trial of ten, aku bisa menjawabnya dalam 5 menit, karena problem ini tergolong mudah.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, solusi ini mudah, kita cukup menentukan berapa banyak kemunculan 0 dan 1. Lalu, kalikan kemunculan paling sedikit dengan 2 (karena penghapusan menghilangkan 2 karakter), dan kurangi panjang string dengan hasil tadi:

$$n - min(cnt0, cnt1) \times 2$$

Atau, kita cukup menghitung satu kemunculan karakter saja, misal 1, lalu tentukan mana yang paling sedikit, antara kemunculan angka 1, atau kemunculan angka 0 yang bisa didapat dengan melakukan penghitungan $n-cnt1$:

$$n-min(cnt1, n-cnt1) \times 2$$

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Jika masih ada setidaknya satu `0` dan setidaknya satu `1` dalam string, maka jelas akan terdapat substring `01` atau substring `10` (atau keduanya) dan kita bisa menghapusnya. Urutan penghapusan substring tidaklah penting: bagaimanapun juga kita akan melakukan operasi sebanyak $min(\#0, \#1)$.

Maka jawabannya adalah $\#1 + \#0 - 2\min(\#1, \#0) = |\#1 - \#0|$.

Waktu: $O(n)$.

## 3.2 | Analisis Pribadi

Solusi ini mudah, aku bisa menjawabnya dalam 5 menit, dan penjelasan dari solusi sudah dijelaskan diatas. Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

auto main() -> int {
    int n, cnt1=0; cin >> n;
    char c;
    for (int i=0; i<n; i++) {
        cin >> c;
        if (c=='1') cnt1++;
    }

    cout << n-(min(cnt1,n-cnt1)*2);
    return 0;
}
```

Hanya menggunakan satu variabel counter, dan tidak menampung inputan dengan string, tapi baca langsung dengan tipe data char.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
   int n;cin>>n;
   string s;cin>>s;
   int k=count(s.begin(),s.end(),'0');
   cout<<abs(n-(2*k));
}
```

Menggunakan fungsi `count()` untuk menghitung banyaknya kemunculan karakter `0`. Namun menurutku ini tidak efektif, karena harus menyimpan string terlebih dahulu, padahal bisa langsung menghitungnya dengan tipe data char.

### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int t=abs(n-2*count(s.begin(),s.end(),'1'));
    cout<<t<<endl;
}
```

Menggunakan selisih dari $n$ dengan $cnt1 \times 2$. 

### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int te =0 ;
    for(auto in : s){
        if(in=='0') te--;
        else te++;
    }
    cout << abs(te) << '\n';
}
```

Dia menggunakan logika naik turun, dimana jika karakter 0 maka nilai `te` turun, dan jika karakter 1 maka `te` naik. Lalu diakhir program, kita cukup outputkan hasil dari `te`. Cukup unik.