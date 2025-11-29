---
obsidianUIMode: preview
note_type: death ground
kode_soal: 122A
judul_DEATH: Lucky Division
teori_DEATH: generate angka dengan kombinasi digit tertentu
sumber:
  - codeforces.com
rating: 1000
ada_tips: true
date_learned: 2025-11-29T13:49:00
tags:
  - brute-force
  - number-theory
---
Sumber: [Problem - 122A - Codeforces](https://codeforces.com/problemset/problem/122/A)

```ad-tip
title:⚔️ Teori Death Ground
Pelajari algoritma generate angka di materi ini!
```

<br/>

---
# 1 | 122A-Lucky Division

Diberikan sebuah angka tertentu. Tentukan apakah angka tersebut bisa dibagi habis oleh suatu pembagi yang terdiri dari digit-digit $4$ dan $7$. Nilai dari $n$ adalah $1 \leq n \leq 1000$.

> lucky number adalah angka yang hanya terdiri dari 4 dan 7.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Dengan menggunakan aturan kombinasi, maka akan ada paling banyak 15 kombinasi angka dengan digit-sigit $4$ dan $7$ yang dapat dibentuk jika angka yang mungkin untuk dibentuk adalah angka dengan $1$ digit hingga $4$ digit.

Dengan menggunakan algoritma generate sederhana, kita bisa mendeklarasikan array yang akan menyimpan 15 kombinasi dari digit-digit tersebut, dan melakukan brute force, dengan melakukan pengecekan apakan inputan $n$ habis dibagi oleh salah satu dari kombinasi tersebut.

Implementasiku seperti ini:

```cpp
#include<iostream>
#include<vector>
using namespace std;
 
void generate(vector<int>& rest, int cur) {
    if (cur > 1000) return;
    generate(rest, cur * 10 + 4);
    generate(rest, cur * 10 + 7);
    if (cur != 0) rest.push_back(cur);
}
 
auto main() -> int {
    vector<int> rest;
    generate(rest, 0);
 
    int n;
    cin >> n;
    for (const auto& x : rest) {
        if (n % x == 0) {
            cout << "YES";
            return 0;
        }
    }
 
    cout << "NO";
    return 0;
}
```

Aku menggunakan beberapa beberapa cara generate yang berbeda, bisa untuk bahan evaluasi saja:

```cpp
#include <iostream>
#include <vector>
using namespace std;
 
using LL = long long;
void gen(vector<LL>& luck, LL cur = 0) {
    if (cur > 0)
        luck.push_back(cur);
    if (cur > 1000)
        return;
    gen(luck, cur * 10 + 4);
    gen(luck, cur * 10 + 7);
}
 
auto main() -> int {
    int num;
    cin >> num;
    vector<LL> luck{};
    gen(luck);
    for (const auto& x : luck) {
        if (num % x == 0) {
            cout << "YES";
            return 0;
        }
    }
 
    cout << "NO";
    return 0;
}
```

Dengan menggunakan string, lalu konversi ke angka:

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
void luckNum(vector<int>& luck, const string& dig = "", string comb = "") {
    comb += dig;
    if (comb.length() > 3) {
        return;
    }
    if (comb != "") {
        luck.emplace_back(stoi(comb));
    }
    luckNum(luck, "4", comb);
    luckNum(luck, "7", comb);
}
 
auto main() -> int {
    int num;
    cin >> num;
    vector<int> luck{};
    luckNum(luck);
    for (const auto& x : luck) {
        if (num % x == 0) {
            cout << "YES";
            return 0;
        }
    }
 
    cout << "NO";
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kamu hanya perlu lakukan perulangan dari $i$ hingga $n$. Jika $i$ adalah angka lucky number, maka coba lakukan pembagian angka $n$ dengan $i$. Jika $n \text{ mod } i \equiv 0$, maka outputkan `YES`. Jika hingga $n$, tidak ada angka lucky number yang membagi habis $n$, maka outputkan `NO`.

## 3.2 | Analisis Pribadi

Editorial mengatakan bahwa kita perlu melakukan brute force. Ini, pada kasus worst case dimana $n=1000$, kita akan melakukan sebanyak $1000$ kali, yang mana tidak efisien jika pada steiap perulanganya kita harus mengecek apakah angka tersebut lucky number atau tidak.

Caraku lebih efisien, karena hanya perlu melakukan generate beberapa angka, dan menghasilkan perulangan paling banyak 15 kali.

## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <iostream>
int l;
int main(){
    std::cin>>l;
    std::cout<<(l%4==0||l%7==0||l%47==0||l%74==0||l%477==0 ? "YES":"NO");
    return 0;
}
```

Jika suatu angka bisa dibagi dengan salah satu kondisional diatas, maka outputkan `YES`. Jujur saja, pendekatan diatas termasuk pendekatan *hard coded*, terlihat simple karena tidak membutuhkan algoritma rumit, namun harus memiliki pemahaman yang baik dengan matematika. 

Dan aku lebih suka menggunakan algoritma generate karena pendekatan ini tidak fleksibel.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int32_t main(){
  int n;
  cin>>n;
  int arr[]={4,7,44,47,74,77,444,447,474,744,477,747,774,777};
  for(auto x:arr){
    if(n%x==0){
      cout<<"YES";
      return 0;
    }
    
  }
  
  cout<<"NO"<<endl;
  return 0;
}
```

Menyimpan semua kombinasi dari digit $4$ dan $7$. Bisa dialihkan ke algoritma generate, tapi seperti karena hanya membutuhkan 15 kombinasi angka saja, user ini lebih memilih menulisnyaknya secara langsung.
### 3 | Jawaban Ketiga

```cpp
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    bool Lucky=false;
    for(int i=4;i<=7;i+=3){
        if(n%i==0){
            Lucky=true;
            break;
        }
        for(int j=4;j<=7;j+=3){
            if(n%(j*10+i)==0){
                Lucky=true;
                break;
            }
            for(int k=4;k<=7;k+=3){
                if(n%(k*100+j*10+i)==0){
                    Lucky=true;
                    break;
                }
            }
        }
    }
    if(Lucky)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
```

User ini melakukan pemeriksaan dengan membuat kombinasi dari $4$ dan $7$ seadainya hanya satu digit, 2 digit, atau 3 digit angka yang diperbolehkan. Gunakan saja algoritma generate seperti ku, dan tidak perlu menggunakan algoritma dengan kompleksitas besar seperti ini. Bisa dilihat bahwa terdapat  3 nested loop, tidak efisien.