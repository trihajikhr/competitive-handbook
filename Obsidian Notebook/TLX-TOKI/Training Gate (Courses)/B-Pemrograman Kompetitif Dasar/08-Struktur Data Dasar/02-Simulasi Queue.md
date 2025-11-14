---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: competitive-1/8/B
judul_DEATH: Simulasi Queue
teori_DEATH: menggunakan vector sebagai pengganti queue
sumber:
  - tlx-toki.id
rating:
ada_tips?: true
date_learned: 2025-10-14T15:04:00
tags:
  - data-structure
---
Sumber: [TLX](https://tlx.toki.id/courses/competitive-1/chapters/08/problems/B/submissions/4478272)

```ad-tip
title:⚔️ Teori Death Ground
C++ STL memang sudah menyediakan data structure queue. Tapi kita bisa menggunakan vector sebagai pengganti queue. Ada beberapa cara penerapan, mulai dari cara biasa (*lurus kesamping dan menyisakan banyak elemen tak terpakai dibagian depan*), dan juga circular queue (*cara yang lebih efisien untuk meminimalkan ruang yang dipakai, namun lebih sulit*).

Tapi, masih ada cara yang lebih efisien, yaitu
```

<br/>

---
# 1 | Simulasi Queue

Kita diminta untuk mensimulasikan $Q$ operasi terhadap sebuah antrean (*queue*) yang terdiri dari bilangan bulat.

Pada mulanya, queue kosong. Lalu anda perlu menjalankan serangkaian perintah, yang masing-masing dapat berupa:

- `add X Y`
    - masukkan (_enqueue)_ $Y$ buah bilangan bulat, masing-masing adalah $X$, ke belakang antrean, lalu
    - cetak banyaknya bilangan pada antrean.
- `del Y`
    - keluarkan (_dequeue_) $Y$ buah bilangan dari depan antrean, lalu
    - cetak bilangan pertama yang dikeluarkan.
- `rev`
    - balikkan urutan antrean, dengan kata lain ujung depan dan ujung belakang bertukar.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Kode pertamaku mengalami time limit!

Aku menggunakan queue dari C++ STL, untuk melakukan simulasi ini. 

Operasi `add X Y`, adalah melakukan penambahan antrean (*enqueue*) angka $X$ sebanyak $Y$ kali terhadap queue. Ini mudah, karena kita bisa menggunakan fungsi `push()` yang dibungkus oleh perulangan yang berjalan sebanyak $Y$ kali.

Operasi `del Y` juga mudah, kita bisa melakukan perulangan sebanyak $Y$ kali, untuk melakukan fungsi `pop()`, yang akan mengeluarkan satu antrean yang ada didepan (*dequeue*).

Dan lalu operasi `rev`. Data yang disimpan didalam queue, tidak bisa diakses, kecuali data tersebut terletak di paling depan atau paling belakang antrean, dimana kita bisa menggunakan fungsi `front()` dan `back()`. Data structure queue juga tidak bisa direverse dengan menggunakan fungsi `reverse()` dari header `algorithm`. 

```ad-info
Dalam C++, `std::queue` merupakan container adaptor yang hanya mengizinkan akses ke elemen paling depan melalui `front()` dan elemen paling belakang melalui `back()`. Karena tidak menyediakan iterator atau operasi indeks, isi `std::queue` tidak dapat diakses secara langsung maupun dibalik menggunakan fungsi `std::reverse()` dari `<algorithm>`.
```

Oleh karena itu, aku mencoba untuk mengakalinya dengan bantuan struktur data stack. Elemen didalam queue dimasukan kedalam stack, lalu diambil lagi untuk disimpan di queue. Ini akan membuat urutanya menjadi terbalik, sehingga secara tidak langsung mereverse queue (*cara yang ternyata membuat kodeku time limit! Tidak efisien*).

Aku mencoba menjawab dengan kode seperti ini:

```cpp
#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<sstream>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    queue<int> que;
    while (q--) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        string cmd;
        int a, b;

        ss >> cmd;
        if (cmd == "add") {
            ss >> a >> b;
            for (int i=0; i<b; i++) {
                que.push(a);
            }
            cout << que.size() << '\n';
        } else if (cmd == "del") {
            ss >> a;
            cout << que.front() << '\n';
            for (int i=0; i<a; i++) {
                que.pop();
            }
        } else if (cmd == "rev") {
            stack<int> temp;
            while (!que.empty()) {
                temp.push(que.front());
                que.pop();
            }

            while (!temp.empty()) {
                que.push(temp.top());
                temp.pop();
            }
        }
    }

    return 0;
}
```

Tapi ternyata terkena time limit, sehingga walaupun benar secara implementasi, namun kurang cepat dalam ukuran performa.

Akhirnya, aku mecoba menggunakan implementasi queue dengan menggunakan vector, yang untungnya berhasil:

```cpp
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q,  front=0;
    cin >> q;
    vector<int> que;
    while (q--) {
        string s;
        getline(cin >> ws, s);
        string cmd;
        int x, y;
        stringstream ss(s);
        ss >> cmd;

        if (cmd == "add") {
            ss >> x >> y;
            for (int i=0; i<y; i++) {
                que.push_back(x);
            }
            cout << que.size()-front << '\n';
        } else if (cmd == "del") {
            ss >> y;
            if (!que.empty()) {
                cout << que[front] << '\n';
                int temp = que.size()-1;
                front = min(front+y, temp);
            }
        } else if (cmd == "rev") {
            reverse(que.begin() + front, que.end());
        }
    }

    return 0;
}
```

Ketika ada antrean ditambahkan (*enqueue*), maka cukup lakukan `push_back()`. Dan untuk penghapusan dibagian depan (*dequeue*), maka majukan saja variabel `front` dengan menambahkanya dengan banyaknya penghapusan, atau untuk meminimalkan out-of bound, menggunakan:

```cpp
front = min(front+y, temp);
```

Tapi, walaupun berhasil, kompleksitas tertinggi hampir menembus time limit:

![[02-Simulasi Queue-1.png]]

Sehingga jelas, ini juga masih kurang oke! Lanjut ke langkah analisis pribadi untuk jawaban yang lebih baik.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

## 3.2 | Analisis Pribadi

## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    if (!(cin >> Q)) return 0;

    deque<pair<long long,long long>> dq;
    bool rev = false;
    long long total = 0;

    while (Q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            long long X, Y;
            cin >> X >> Y;
            if (!rev) {
                if (!dq.empty() && dq.back().first == X) 
	                dq.back().second += Y;
                else dq.emplace_back(X, Y);
            } else {
                if (!dq.empty() && dq.front().first == X) 
	                dq.front().second += Y;
                else dq.emplace_front(X, Y);
            }
            total += Y;
            cout << total << '\n';
        } else if (cmd == "del") {
            long long Y;
            cin >> Y;
            long long removed = min(Y, total);
            long long rem = removed;
            long long firstRemoved = 0;
            if (removed > 0) {
                if (!rev) {
                    firstRemoved = dq.front().first;
                    while (rem > 0) {
                        if (dq.front().second <= rem) {
                            rem -= dq.front().second;
                            dq.pop_front();
                        } else {
                            dq.front().second -= rem;
                            rem = 0;
                        }
                    }
                } else {
                    firstRemoved = dq.back().first;
                    while (rem > 0) {
                        if (dq.back().second <= rem) {
                            rem -= dq.back().second;
                            dq.pop_back();
                        } else {
                            dq.back().second -= rem;
                            rem = 0;
                        }
                    }
                }
                total -= removed;
            }
            cout << firstRemoved << '\n';
        } else if (cmd == "rev") {
            rev = !rev;
        }
    }

    return 0;
}
```

Jawaban ini tergolong cepat, karena runtime terlamanya hanya 5 ms, dan penggunaan memory semuanya berada di kisaran 580 KB.
### 2 | Jawaban Kedua

```cpp
/* Author : Bandon */
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define vc vector
#define fi first
#define se second
 
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

//BIT MANIPULATION
#define LSB(S) (S & -(S))
#define PowerOfTwo(S) (!((S) & (S - 1)))

//FILE IO
void setIO() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    deque<ll> dq;
    bool fr = true;
    for(ll i = 0; i < n; ++i){
    	string s; cin >> s;
    	if(s == "add"){
    		ll x, y; cin >> x >> y;
    		if(fr){
    			for(ll j = 0; j < y; ++j) dq.pb(x);
    			cout << dq.size() << endl;
    		} else {
    			for(ll j = 0; j < y; ++j) dq.pf(x);
    			cout << dq.size() << endl;
    		}
    	} else if(s == "del"){
    		ll y; cin >> y;
    		if(fr){
    			cout << dq.front() << endl;
    			for(ll j = 0; j < y; ++j) dq.pop_front();
    		} else {
    			cout << dq.back() << endl;
    			for(ll j = 0; j < y; ++j) dq.pop_back();
    		}
    	} else fr = !fr;
    }
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;



int main(){
    deque<int> queue;
    int q;
    cin >> q;
    string s;
    int rev = 1;
    while(q--){
        cin >> s;
        if(s == "add"){
            int x,y;
            cin >> x >> y;
            if(rev % 2){
                while(y--){
                    queue.push_back(x);
                }
            }else{
                while(y--){
                    queue.push_front(x);
                }
            }
            
            cout << queue.size() << endl;
        }
        if(s == "del"){
            int y;
            cin >> y;
            if(rev % 2){
                cout << queue.front() << endl;
                while(y--){
                    queue.pop_front();
                }
            }else{
                cout << queue.back() << endl;
                while(y--){
                    queue.pop_back();
                }
                
            }
            
        }
        if(s == "rev"){
            rev++;
        }
    }
}
```