---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1372A
judul_DEATH: Omkar and Completion
teori_DEATH:
sumber:
  - codeforces.com
rating: 800
ada_tips: false
date_learned: 2025-10-20T17:47:00
tags:
  - constructive-algorithms
  - implementation
---
Sumber: [Problem - 1372A - Codeforces](https://codeforces.com/problemset/problem/1372/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1372A-Omkar and Completion

Kita diharuskan membuat sebuah array berukuran $n$ ($n$ adalah inputan) yang mana untuk setiap index $x,y,z$ $(1 \leq x,y,z \leq n)$, kondisi berikut harus terpenuhi untuk semua elemen array:

$$a_x + a_y \neq a_z$$
Tidak ada elemen array yang lebih dari $1000$, dan elemen dari indeks $x,y,z$ tidak harus berbeda.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Ada satu petunjuk yang sangat penting disini, yaitu elemen dari indeks yang ditunjuk oleh $x,y,z$ tidak harus berbeda. Ini artinya, jika kita mengisi semua array dengan angka yang sama, otomatis syarat $a_x + a_y \neq a_z$ akan selalu berhasil. 

Intuisi ini juga datang dari informasi lain, bahwa batasan nilai $n$ adalah $1 \leq n \leq 1000$. Jika $n=1000$ dan kita memiliki niat untuk menggunakan semua angka yang berbeda dari $1$ hingga $1000$, maka hal ini tidak akan berhasil membentuk array yang sesuai. Artinya harus ada angka yang sama atau duplikat. Jika hal itu diperbolehkan, maka buat saja semua array menjadi sama.

Solusi dari intuisi ini ternyata benar, dan berikut adalah kodeku:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) cout << 1 << " ";
        cout << "\n";
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Perhatikan bahwa karena semua elemen harus positif, maka $k \neq 2k$. Konstruksi paling sederhana dari masalah ini adalah dengan membuat semua elemen sama dengan $1$.

## 3.2 | Analisis Pribadi

Ide dan konsep awalku sudah benar dengan editorial, sehingga tidak perlu diubah-ubah lagi.
## 3.3 | Analisis Jawaban User Lain

Solusi dan ideku sudah benar dan efisien. Jawaban dari pengguna lain kebanyakan tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        while (t--) {
            cout << 1 << " ";
        }
        cout << endl;
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cout << "622 ";
        cout << endl;
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            cout<<"1"<<" ";
        }
        cout<<"\n";
    }
}
```