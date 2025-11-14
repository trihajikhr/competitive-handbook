---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1696B
judul_DEATH: NIT Destroys the Universe
teori_DEATH: cari rentang cepat, dan membandingkan array cepat
sumber:
  - codeforces.com
rating: 900
ada_tips?: true
date_learned: 2025-10-08T21:55:00
tags:
---
Sumber: [Problem - 1696B - Codeforces](https://codeforces.com/problemset/problem/1696/B)

```ad-tip
title:⚔️ Teori Death Ground
- Kita bisa mencari rentang non-nol dengan cepat, dengan menyimpan nilai min dan max dari indeks, dari setiap elemen array non-nol.
- Kita bisa membandingkan vector, apakah suatu vector atau array semuanya sama atau tidak, dengan langsung membandingkanya dengan mendeklarasikan dan menginisialisasikan vector di kondisional percabangan.
```

<br/>

---
# 1 | 1696B-NIT Destroys the Universe

Kita diberikan sebuah array berukuran $n$ yang terdiri dari $n$ element. Tugas kita adalah membuat elemen array tersebut semuanya menjadi $0$, dengan menggunakan operasi $w=mex$.

Fungsi $mex$ adalah mengambil rentang dari $l$ hingga $r$ dari array, dimana $1 \leq l \leq r \leq n$, dimana akan mengembalikan nilai $w$, dimana $w$ adalah elemen terkecil non-negatif yang tidak ada di rentang $a_l$ hingga $a_r$. 

Tentukan banyaknya operasi yang dibutuhkan untuk memilih rentang yang tepat untuk $l$ dan $r$, dan menjadikan semua elemen pada array menjadi $0$!

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika semuanya nol, maka kita tidak perlu melakukan operasi apapun, outputkan saja langsung $0$ sebagai jawabanya. Jika tidak ada nol sama sekali, maka rentang operasi yang akan dipilih adalah dari awal hingga akhir, atau $l=1$ dan $r=n$. Sehingga kita outputkan saja $1$.

Untuk mengetahuinya, cukup cari nilai min dan max. Jika min dan max keduanya adalah 0, maka jelas semua elemen array adalah $0$. Jika nilai min bukan $0$, maka jelas tidak ada kemunculan angka $0$.

Tantangan yang membuatku kesulitan adalah ketika ada beberapa angka $0$, aku berpikir bahwa jika ada deretan angka yang terbentuk di awal atau akhir array maka jawabanya adalah 1, dan jika terbentuk tepat di tengah maka jawabanya adalah 2. Namun solusi ini salah, dan aku tidak bisa menyelesaikan problem ini hingga akhir.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

**Hint 1**: Berapa banyak operasi yang akan kita lakukan?
Maksimal dua. Mengapa?

**Hint 2**: Bagaimana cara memeriksa apakah array dapat dihancurkan dalam $\mathbf{0}$ atau $\mathbf{1}$ operasi?

Jawabannya adalah maksimal $\mathbf{2}$, karena melakukan operasi pada $[1, n]$ maksimal dua kali akan selalu berhasil. (Jika larik mengandung setidaknya satu nol, kita memerlukan $\mathbf{2}$ operasi. Jika tidak, kita memerlukan $\mathbf{1}$ operasi.)

* Jika larik terdiri dari nol, jawabannya adalah $\mathbf{0}$.
* Jika semua elemen bukan nol membentuk segmen yang bersambungan (berdampingan) dalam larik, jawabannya adalah $\mathbf{1}$. Untuk memeriksanya, Anda dapat menemukan kemunculan elemen bukan nol paling kiri dan paling kanan, dan periksa apakah elemen di antara keduanya juga bukan nol.
* Jika tidak, jawabannya adalah $\mathbf{2}$.

Kompleksitas waktu adalah $O(n)$.

## 3.2 | Analisis Pribadi

Ternyata, untuk mengatasi angka $0$ yang banyak dan tersebar, kita cukup mengecek nilai paling kiri angka non-nol, dan nilai paling kanan angka non-nol.

Jika diantara rentang ini terdapat satu saja angka $0$, maka kita butuh dua operasi, outputkan 2. Tapi jika deret tersebut tidak memiliki satupun niai $0$ di rentangnya, maka jawabanya cukup $1$, karena pilihan $l$ dan $r$ akan tetap sama.

Maka berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> data(n);
    int maks = INT_MIN, mins = INT_MAX;
    for (auto& x : data) {
        cin >> x;
        maks = max(maks, x);
        mins = min(mins, x);
    }

    if (maks==0 && mins==0) {
        cout << 0 << '\n';
    } else if (mins!=0) {
        cout << 1 << '\n';
    } else {
        int l=0, r=n-1;
        while (data[l]==0) l++;
        while (data[r]==0) r--;
        for (int i=l; i<r; i++) {
            if (data[i]==0) {
                cout << 2 << '\n';
                return;
            }
        }
        cout << 1 << '\n';
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int a[100005];
int t;
int n;
int ans;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > 0 && a[i - 1] == 0) ans++;
        }
        cout << min(ans, 2) << "\n";
    }
}
```

Solusi ini simple dan cepat, jika semuanya angka 0, maka nilai `ans` tidak bertambah karena $a[i] > 0$ tidak pernah tercapai, otomatis mengoutputkan 0. 

Nilai dari `ans` hanya bertambah, jika terdapat elemen non-nol yang berada didepan elemen yang bernilai $0$. Perhatikan juga bahwa perulangan dimulai dari $i=1$, dan sempat membandingkan dengan $a[i-1]$, yaitu $a[0]$. Otomatis, jika ada elemen non-nol, maka nilai `ans` jelas sudah memiliki nilai $1$. Jika ada angka nol yang ada di sela-sela deretan angka non-nol, maka `ans` akan bertambah.
### 2 | Jawaban Kedua

```cpp
// https://www.youtube.com/watch?v=q22FRC3fc4w
// Fear has fallen down on me, I’m buried in too deep
// I stumble to my feet, tears frozen to my cheek
// Dreams that bring me light, they tell me to survive
// I’m reaching for a life beyond the peak

#ifndef ONLINE_JUDGE
#include "templates/debug.hpp"
#else
#define debug(...)
#endif

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

#define int i64
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 2;
    if (ranges::count(a, 0) == n) ans = 0;
    else {
        int min_nz = n + 1, max_nz = -1;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                min_nz = min(min_nz, i);
                max_nz = max(max_nz, i);
            }
        }
        set<int> s;
        for (int i = min_nz; i <= max_nz; i++) {
            s.insert(a[i]);
        }
        int mex = 0;
        while (s.count(mex)) mex++;
        if (mex == 0) ans = 1;
    }
    cout << ans << "\n";
}
#undef int

// 大胆猜想，小心求证 Make bold hypotheses and verify carefully
// - You REALLY need some key observations...
// - Don't trust seemaxgly trival conclusions
// - Do something instead of nothing and stay organized
// - Don't get stuck on one approach
// - Formalization is the death of intuition

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
```

Pertama, program menetapkan `ans` sebagai 2. 

Pada percabangan pertama, yaitu:

```cpp
if (ranges::count(a, 0) == n) ans = 0;
```

Syntax ini berguna untuk menghitung banyaknya kemunculan angka $0$ pada array $a$. Dan jika kemunculan angka $0==n$, maka kita tetapkan nilai `ans` adalah 0.

Blok percabangan `else`, mencari nilai minimal dan maksimal dari indeks array non-nol (yang disimpan adalah indexnya), dan melakukan perulangan hanya dari rentang tersebut. Ini adalah salah satu cara *clever* untuk mencari rentang kiri dan kanan dari deret non-nol hanya dengan satu perulangan. Ini jelas terlihat, karena dia menggunakan kondisional yang hanya mencatat min dan max hanya jika $a[i] \neq 0$.       

Lalu dia menggunakan set untuk menyimpan hanya angka-angka unik, dan mencari tahu, apakah dari deret non-nol yang dia cari, terdapat angka $0$ diataranya. Jika iya, maka nilai `ans` akan menjadi 1.

Jika kedua kondisional tadi tidak mengubah nilai `ans` sama sekali, maka nilai `ans` yang disimpan hingga akhir dan dioutputkan adalah 2, sesuai dengan nilai `ans` yang sudah diinisialisasi diawal.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	if(a == vector<int>(n, 0)){
		cout << 0 << '\n';
		return;
	}
	int i = 0;
	while(i < n && a[i] == 0) i++;
	int j = n;
	while(j > 0 && a[j-1] == 0) j--;
	for(int k = i; k < j; k++){
		if(a[k] == 0){
			cout << 2 << '\n';
			return;
		}
	}
	cout << 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
```

Terdapat cara yang cukup unik disini:

```cpp
if(a == vector<int>(n, 0)){
	cout << 0 << '\n';
	return;
}
```

Dia melakukan pengecekan, apakah vector $a$ yang menyimpan inputan, semuanya berisi angka $0$. Dia dengan cara *unik* membandingkanya dengan deklarasi dan inisialisasi vector, cara yang cukup unik!

Untuk logika utama, dia menggunakan cara yang mirip dengan caraku, yaitu menggunakan perulangan `while` untuk mendapatkan rentang $l$ dan $r$, dan melakukan perulangan diatara kedua rentang tersebut. Bisa dibilang hampir mirip dengan caraku:

```cpp
int i = 0;
while(i < n && a[i] == 0) i++;
int j = n;
while(j > 0 && a[j-1] == 0) j--;
for(int k = i; k < j; k++){
	if(a[k] == 0){
		cout << 2 << '\n';
		return;
	}
}
cout << 1 << '\n';
```