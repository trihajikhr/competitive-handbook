---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 456A
judul_DEATH: Laptops
teori_DEATH:
sumber:
  - codeforces.com
rating: 1100
ada_tips?:
date_learned: 2025-10-19T12:16:00
tags:
---
Sumber: [Problem - 456A - Codeforces](https://codeforces.com/problemset/problem/456/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 456A-Laptops

Diberikan sebanyak $n$ laptop. Sebuah laptop memiliki harga sebesar $a_i$ dan kualitas sebesar $b_i$. Jika semisal ada laptop $x$ dan $y$, dimana laptop $x$ memiliki harga yang lebih murah daripada laptop $y$ tetapi memiliki kualitas yang lebih tinggi daripada laptop $y$, maka outputkan `Happy Alex`. Jika tidak ada maka outputkan `Poor Alex`.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Mudah saja, terima $a_i$ dan $b_i$ dengan menggunakan vector yang menyimpan tipe data pair. Lalu lakukan sorting berdasarkan elemen pertama pair. 

Setelah itu, lakukan traversal dari elemen pertama hingga akhir. Jika ditemukan laptop dengan kualitas yang lebih tinggi berada di sebelah kiri laptop dengan kualitas yang lebih rendah (*padahal harganya lebih tinggi, karena ke kanan elemen menaik secara ascending*), maka langsung saja outputkan `Happy Alex`, dan hentikan program.

Jika hingga akhir tidak ditemukan kondisi tersebut, maka outputkan `Poor Alex`.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> lap(n);
    for (auto& [x, y] : lap) {
        cin >> x >> y;
    }

    ranges::sort(lap);
    for (int i=0; i<n-1; i++) {
        if (lap[i].second > lap[i+1].second) {
            cout << "Happy Alex";
            return 0;
        }
    }
    cout << "Poor Alex";
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Dalam tugas ini, Anda perlu memeriksa keberadaan pasangan $i$ dan $j$ sedemikian rupa sehingga $i \neq j$, $a[i] < a[j]$, dan $b[i] > b[j]$. Jika pasangan $i$ dan $j$ seperti itu ada, maka outputkan `Happy Alex`.

Ada solusi yang sangat sederhana. Mari kita periksa apakah untuk semua $i$, berlaku $a[i] = b[i]$. Jika kondisi ini benar, kita harus mencetak `Poor Alex`. Kita dapat membuktikannya dengan mudah.

Mari kita urutkan larik $a$ dan $b$ sebagai pasangan angka secara berurutan (*increasing order*). Kita dapat melihat bahwa Alex senang jika kita memiliki setidaknya satu **inversi** di larik $b$, yaitu ada pasangan $i$ dan $j$ sedemikian rupa sehingga $b[i] > b[j]$ dan $i < j$. Ini berarti larik $b$ tidak terurut, dan ini berarti $a \neq b$.

## 3.2 | Analisis Pribadi

Melihat solusi asli yang ternyata lebih singkat, maka aku memperbaiki jawabanku menjadi seperti ini:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    int n; cin >> n;
    bool flag = false;
    for (int i=0, x, y; i<n; i++) {
        cin >> x >> y;
        if (x != y) flag = true;
    }
    cout << (flag ? "Happy Alex" : "Poor Alex");
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <iostream>
using namespace std;
int main(){
	int n,f=0,x,y;
	cin >> n;
	while(n--){
		cin >> x >> y;
		if(x!=y) f=1;
	}
	if(f) cout << "Happy Alex";
	else cout << "Poor Alex";
}
```

Dari solusi ini aku sadar. Aku miss pada bagian problem statement yang mengatakan bahwa setiap $a_i$ tidak ada yang sama, begitu juga dengan $b_i$. Ini artinya, `Poor Alex` hanya akan terjadi jika setiap $a_i = b_i$. Ternyata solusi dari soal ini jauh lebih simple dan singkat.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int flag=0,x,y;
    while(n--){
        cin>>x>>y;
        if(x!=y)flag=1;
    }
    cout<<(flag?"Happy Alex":"Poor Alex");
}
```

Banyak user lain yang menemukan solusi yang sama, dan sepertinya solusi ini memang solusi yang paling efisien.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
//#define debug
#ifndef debug
#pragma GCC optimize("Ofast")
#pragma GCC target ("avx,avx2,fma")
#endif

using namespace std;

int main() {
	#ifndef debug
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#endif
	int n;
	cin>>n;
	int a[n],b[n-1];
	for (int i=0;i<n;i++)
	{
		int p,q;
		cin>>p>>q;
		a[p-1]=q;
	}
	adjacent_difference(a,a+n,b-1);
	sort(b,b+n-1);
	if (b[0]<0) cout<<"Happy Alex";
	else cout<<"Poor Alex";
}
 
```

Dia menggunakan fungsi yang aku tidak terlalu tahu apa kegunaanya, namun tetap berhasil.