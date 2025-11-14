---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 368B
judul_DEATH: Sereja and Suffixes
teori_DEATH:
sumber:
  - codeforces.com
rating: 1100
ada_tips?:
date_learned: 2025-10-19T15:14:00
tags:
  - data-structure
  - dynamic-programming
---
Sumber: [Problem - 368B - Codeforces](https://codeforces.com/problemset/problem/368/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 368B-Sereja and Suffixes

Diberikan sebuah array berukuran $n$ dan queries $q$. Setiap queries misal $l$, berada direntang yang sama dengan $1 \leq l \leq n$, dan menunjukan indeks pada array.

Tentukan banyaknya karakter unik pada array, yang dimulai dari indeks $l$ hingga $n$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Karena harus menyimpan karakter unik, mungkin bisa menggunakan struktur data `set`. Pertama, lakukan traversal pada array yang dimulai dari kanan ke kiri, dan masukan $a_i$ ke dalam set. Lalu, simpan ukuran set kedalam array prefix. 

Lalu jawab $q$ queries dengan cara mengoutputkan langsung nilai dari index prefix ke-$l$. Disini aku menggunakan array 1-based index supaya konsisten di semua penggunaan dan memudahkan menyamakanya dengan inputan soal.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
#include<set>
using namespace std;

auto main()-> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1-based index array
    int n, m;
    cin >> n >> m;
    vector<int> pref(n+1), data(n+1);
    set<int> num;

    for (int i=1; i<= n; i++) {
        cin >> data[i];
    }

    for (int i=n; i >= 1; i--) {
        num.insert(data[i]);
        data[i] = static_cast<int>(num.size());
    }

    for (int i=0, x; i<m; i++) {
        cin >> x;
        cout << data[x] << '\n';
    }
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Kita akan menghitung nilai $\mathbf{ans_i}$—yaitu jumlah elemen berbeda pada *suffix* (bagian akhir/deret turunan) yang dimulai dari indeks $i$.

Untuk perhitungan, kita akan berjalan dari akhir larik (*array*), dan kita hitung $ans_i = ans_{i+1} + \mathbf{new\_a_i}$, di mana $\mathbf{new\_a_i}$ sama dengan $\mathbf{1}$, jika elemen $\mathbf{a_i}$ belum pernah ditemui, dan $\mathbf{0}$ jika sebaliknya.

**Penjelasan Singkat:**

Inti dari algoritma ini adalah menggunakan teknik **pemrograman dinamis** (atau penghitungan berulang) dengan berjalan mundur dari belakang larik untuk menghitung jumlah elemen unik pada setiap segmen (*suffix*) larik secara efisien.

* $\mathbf{ans_i}$: Jawaban yang kita cari untuk segmen yang dimulai dari indeks $i$ hingga akhir.
* $\mathbf{ans_{i+1}}$: Jawaban yang sudah dihitung untuk segmen berikutnya (dari $i+1$ hingga akhir).
* $\mathbf{new\_a_i}$: Ini adalah penambahan baru. Jika elemen saat ini ($a_i$) belum pernah muncul di segmen $i+1$ (yaitu, di seluruh sisa larik setelah $i$), maka elemen ini menambah 1 ke jumlah elemen unik. Jika elemen $a_i$ sudah pernah muncul di belakangnya, maka $new\_a_i = 0$.

## 3.2 | Analisis Pribadi

Submit pertamaku sudah benar, dan sudah sesuai dengan penjelasan editorial. Secara ide dan konsep sudah benar.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int main (){
	int n, m; cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	set<int> s;
	int l[n+1];
	for(int i=n-1;i>=0;i--){
		s.insert(a[i]);
		l[i]=s.size();
	}
	while(m--){
		int a; cin>>a;
		cout<<l[a-1]<<endl;
	}
}
```

Implementasi ini mirip dengan implementasiku dan penjelasan konsep editorial, tidak jauh berbeda.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N],l[N],v[N];
int main(){
	cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    for(int i=n;i>=1;i--){
    	v[i]=v[i+1]+!l[a[i]];
		l[a[i]]=1;
	}
	for(int i=1,l;i<=m;i++){
		cin>>l;
		cout<<v[l]<<'\n';
	}
    return 0;
}
```

Tidak menggunakan data struktur set, tapi menggunakan pengecekan manual. Tapi akhirnya harus menggunakan $3$ array, yang mana kurang efisien.
### 3 | Jawaban Ketiga

```cpp
#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m, x;
	cin >> n >> m;
	ll a[n], r[n];
	for (ll i = 0; i < n; ++i) cin >> a[i];
	set<ll>s;
	for (ll i = n - 1; i > -1; --i) {
		s.insert(a[i]);
		r[i] = s.size();
	}
	while (m--) {
		cin >> x;
		cout << r[x-1] << "\n";
	}
	return 0;
}
```

Jawaban dengan konsep dan ide yang sama denganku. Hanya saja menggunakan 0-based index array.