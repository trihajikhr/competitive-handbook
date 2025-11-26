---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1613A
judul_DEATH: Long Comparison
teori_DEATH: trik perbandingan angka besar
sumber:
  - codeforces.com
rating: 900
ada_tips?: true
date_learned: 2025-10-14T23:18:00
tags:
  - string
---
Sumber: [Problem - 1613A - Codeforces](https://codeforces.com/problemset/problem/1613/A)

```ad-tip
title:⚔️ Teori Death Ground
Hasil perbandingan dua angka tidak berubah jika Anda membagi kedua angka tersebut dengan angka positif yang sama
```

<br/>

---
# 1 | 1613A-Long Comparison

Kita diberi dua angka, yaitu $x$ dan $p$. Angka $x$ adalah angka asli, sedangkan $y$, adalah jumlah penambahan digit $0$ ke belakang angka $x$.

Kamu diberikan 2 buah angka seperti ini, yaitu $x1$ dengan $p1$, dan $x2$ dengan $p2$. Tentukan mana angka yang lebih besar antara $x1$ dan $x2$ setelah menerapkan penambahan digit $0$ beberapa kali terhadap $x$.


<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama, aku menggunakan pendeaktan manual, yaitu menggunakan perulangan sebanyak $y$ kali untuk mengalikan $x$ dengan $10$. Tapi angka yang dihasilkan jelas sangat besar, karena penambahan digit, berarti ukuranya bertambah sangat besar. Melihat dari batasan input, maka angka maksimal yang terbentuk jika menggunakan proses ini, bisa mencapai $100000^{100000}$ (*kalau hitunganku tidak salah, tapi yang jelas, sangat besar!*).

Oleh karena itu, aku mencoba memperlakukanya dengan string. Tapi tetap, jika ada sebuah string yang memiliki panjang hingga $10000$, maka juga meledak juga itu kompleksitas. Bahkan operasi membangun digit $0$ dibelakang nilai $x$, pada kasus $p=100000$ juga akan memakan kompleksitas yang sangat besar, tidak efisien:


Contoh kode yang time limit!:
```cpp
#include<iostream>
using namespace std;

#define le length()

void solve() {
    string x1, x2;
    int p1, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    for (int i=0; i<p1; i++) x1+='0';
    for (int i=0; i<p2; i++) x2+='0';

    if (x1.le > x2.le) cout << ">\n";
    else if (x1.le < x2.le) cout << "<\n";
    else {
        for (int i=0; i<x1.le; i++) {
            if (x1[i]-'0' > x2[i]-'0') {
                cout << ">\n";
                return;
            }

            if (x1[i]-'0' < x2[i]-'0') {
                cout << "<\n";
                return;
            }
        }
        cout << "=\n";
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

Oleh karena itu, solusi efisien dibutuhkan disini. Dan sepertinya aku gagal membaca dan menemukan langkah pertama menuju solusi dari soal ini!


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Pertama, mari kita katakan bahwa menambahkan angka dengan $p$ angka nol sama dengan mengalikannya dengan $10^p$.

Angka-angka yang diberikan begitu besar sehingga tidak dapat dimuat dalam tipe *integer* (*bilangan bulat*) yang wajar. Bahkan jika Anda menggunakan bahasa pemrograman dengan *integer* panjang tak terbatas (misalnya, Python) atau menyimpan angka dalam *string*, Anda tetap akan menghadapi masalah batas waktu (*time limit issue*). Jadi, mari kita pelajari cara mengecilkan angka-angka tersebut sedikit.

Perhatikan bahwa hasil perbandingan dua angka tidak berubah jika Anda membagi kedua angka tersebut dengan angka positif yang sama. Jadi, kita bisa terus **membagi kedua angka dengan $10$** hingga salah satunya tidak dapat dibagi lagi.

Mari kita abaikan angka nol di akhir (*trailing zeros*) pada $x_1$ dan $x_2$ dan biarkan angka-angka tersebut apa adanya. Jika angka pertama ditambahkan dengan $p_1$ angka nol dan angka kedua ditambahkan dengan $p_2$ angka nol, kita dapat **mengurangi $\min(p_1, p_2)$** dari kedua nilai tersebut, yang secara efektif membagi kedua angka dengan $10^{\min(p_1, p_2)}$.

Dengan cara ini, salah satu angka menjadi cukup pendek untuk dimuat dalam tipe *integer* (karena $p=0$ dan $x$ hanya sampai $10^6$). Angka yang lain mungkin masih cukup besar.

Namun, jika angka tersebut benar-benar besar, kita dapat langsung mengatakan bahwa itu lebih besar dari angka yang lain. Katakanlah, jika nilai $p$-nya **setidaknya $7$**. Angka ini setidaknya $10^7$, dan angka yang lain paling banyak adalah $10^6$.

Jika tidak, kita dapat menghitung angka ini juga dan membandingkan nilainya secara normal.

Kompleksitas keseluruhan: $O(1)$ per kasus uji (*testcase*).

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin >> t;
	while (t--){
		long long x1, x2;
		int p1, p2;
		cin >> x1 >> p1 >> x2 >> p2;
		int mn = min(p1, p2);
		p1 -= mn;
		p2 -= mn;
		if (p1 >= 7)
			cout << ">" << endl;
		else if (p2 >= 7)
			cout << "<" << endl;
		else{
			for (int i = 0; i < p1; ++i) x1 *= 10;
			for (int i = 0; i < p2; ++i) x2 *= 10;
			if (x1 < x2)
				cout << "<" << endl;
			else if (x1 > x2)
				cout << ">" << endl;
			else
				cout << "=" << endl;
		}
	}
}
```

## 3.2 | Analisis Pribadi

Dari penjelasan editorial, sudah dijelaskan bahwa memperlakukan nilai $x$ sebagai angka atau string, tetap kurang efisien. 

Kita mendapat pelajaran bahwa:

> Perhatikan bahwa hasil perbandingan dua angka tidak berubah jika Anda membagi kedua angka tersebut dengan angka positif yang sama. Jadi, kita bisa terus **membagi kedua angka dengan $10$** hingga salah satunya tidak dapat dibagi lagi.

Kita tetapkan variabel $mn$ sebagai variabel yang menampung nilai terkecil antara $p1$ dan $p2$, lalu mengurangi kedua nilai ini dengan $mn$. Karena nilai $p$ sangatlah besar, maka pembagian dengan angka ini, sama saja dengan mengurangi banyaknya digit yang harus kita pakai, sehingga solusi $p1-mn$ dan $p2-mn$ akan memudahkan kita. 

Oh ya, operasi ini juga akan membuat salah satu nilai antara $p1$ atau $p2$ menjadi bernilai $0$.

Jika ada suatu nilai antara $p1$ dan $p2$ yang memiliki nilai lebih dari $7$, maka jelas penambahan digit yang banyak ini akan membuat angka $x$ nya menjadi lebih besar dari batas maksimal inputan $x$, sehingga jawabanya bisa langsung ditetapkan.

Jika tidak, maka kita bisa membangung variabel long long, dan menggunakan perulangan untuk membangun angka. Operasi ini akan aman, karena kita sudah menyederhanakan angka, dan memfilter perbedaan  selisih (*menghindari angka terlalu besar*) yang membuat jawaban bisa ditemukan lebih awal.

Lalu, lakukan perbandingan untuk kedua angka sebagai bilangan bulat.

Berikut implementasiku:

```cpp
#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--){
        long long x1, x2;
        int p1, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        int mn = min(p1, p2);
        p1 -= mn;
        p2 -= mn;
        if (p1 >= 7)
            cout << ">" << endl;
        else if (p2 >= 7)
            cout << "<" << endl;
        else{
            for (int i = 0; i < p1; ++i) x1 *= 10;
            for (int i = 0; i < p2; ++i) x2 *= 10;
            if (x1 < x2)
                cout << "<" << endl;
            else if (x1 > x2)
                cout << ">" << endl;
            else
                cout << "=" << endl;
        }
    }
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include "bits/stdc++.h"
using namespace std;

int t, a, b, c, d;
int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        double y = log10(1.0 * a / c) + b - d;
        cout << (y == 0 ? "=" : (y > 0 ? ">" : "<")) << endl;
    }
    return 0;
}
```

Aku sepertinya perlu belajar apa itu fungsi `log10()`. Program ini menerima nilai $x$ dan $p$ sebagai integer. Setelah itu, tetapkan double $y$ yang akan menampung nilai dari operasi:

```cpp
log10(1.0 *(a/c)) + (b-d)
```

Jika nilai $y=0$, maka nilai $x1$ dan $x2$ adalah sama. Jika lebih dari $0$, maka artinya $x1$ lebih besar. Jika kurang dari $0$, maka artinya $x1$ lebih kecil (*double ternary conditional*).

Berhubung contoh kode pertama dan kedua sama, penjelasan kode yang berbentuk seperti ini aku pindah ke contoh kode kedua!

### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double x1, p1, x2, p2;
        cin >> x1 >> p1 >> x2 >> p2;
        double ans;
        ans = log10(x1 / x2) + p1 - p2;
        if (ans == 0) cout << "=" << endl;
        else if (ans > 0) cout << ">" << endl;
        else cout << "<" << endl;
    }
}
```


Diberikan dua bilangan dalam bentuk:

$$
N_1 = x_1 \times 10^{p_1}, \quad N_2 = x_2 \times 10^{p_2},
$$

dengan $x_1, x_2 \in \mathbb{R}^+$ dan $p_1, p_2 \in \mathbb{Z}$.
Tujuannya adalah menentukan hubungan komparatif antara $N_1$ dan $N_2$, yaitu apakah:

$$
N_1 < N_2, \quad N_1 = N_2, \quad \text{atau} \quad N_1 > N_2.
$$

**1. Transformasi Logaritmik**

Untuk menghindari *overflow* akibat nilai $N_1$ dan $N_2$ yang berpotensi sangat besar, perbandingan dilakukan dalam domain logaritmik. Karena fungsi logaritma monoton naik pada domain positif, relasi urutan tetap terjaga, yaitu:

$$
N_1 \, \# \, N_2 \quad \Leftrightarrow \quad \log_{10}(N_1) \, \#  \, \log_{10}(N_2),
$$

dengan simbol “$\#$” mewakili salah satu dari relasi $\{<, =, >\}$.

**2. Reduksi Persamaan**

Dengan menerapkan sifat logaritma terhadap bentuk umum bilangan, diperoleh:

$$
\log_{10}(N_1) = \log_{10}(x_1) + p_1,
$$

$$
\log_{10}(N_2) = \log_{10}(x_2) + p_2.
$$

Selisih kedua nilai logaritmik tersebut adalah:

$$
\Delta = \log_{10}(N_1) - \log_{10}(N_2)
= \log_{10}\left( \frac{x_1}{x_2} \right) + (p_1 - p_2).
$$

**3. Implementasi dalam Kode**

Baris berikut:

```cpp
ans = log10(x1 / x2) + p1 - p2;
```

secara langsung merepresentasikan nilai $\Delta$ di atas.

Interpretasi hasilnya adalah:

$$
\Delta
\begin{cases}
0 &\Rightarrow N_1 = N_2,\\
> 0 &\Rightarrow N_1 > N_2,\\
< 0 &\Rightarrow N_1 < N_2.
\end{cases}
$$


**4. Kesimpulan**

Variabel `ans` berfungsi sebagai wadah untuk nilai:

$$
\text{ans} = \log_{10}(N_1) - \log_{10}(N_2),
$$

...yakni selisih logaritma basis-10 antara dua bilangan dalam bentuk ilmiah.
Nilai ini digunakan untuk menentukan relasi komparatif antara $N_1$ dan $N_2$ **tanpa perlu menghitung nilainya secara eksplisit**, sehingga menghindari kehilangan presisi atau *overflow* pada bilangan besar.
### 3 | Jawaban Ketiga

```cpp
// JAI BAJARANG BALI
// ThinkTank30

// give me some sunshine, give me some rain, give me another chance to grow up once again

#include <bits/stdc++.h>

#define int long long
#define endl "\n"
#define all(s) (s).begin(), (s).end()
#define vi vector<int>
#define pb push_back
const int MOD =1e9+7;

using namespace std;

void solve(){
    string a,b;
    int p1,p2;
    cin>>a>>p1>>b>>p2;
    int len1=a.size() +p1;
    int len2 = b.size() + p2;
    if(len1>len2) cout<<">"<<endl;
    else if(len1<len2) cout<<"<"<<endl;
    else{
        while(a.size() < b.size()){
            a+='0';
        }
        while(a.size()>b.size()){
            b+='0';
        }
        for (int i=0;i<a.size();i++){
           if(a[i] > b[i]){
            cout<<">"<<endl;
            return;
           }
           if(a[i]<b[i]){
            cout<<"<"<<endl;
            return;
           }
        }
        cout<<"="<<endl;
    }
}
signed main (){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);

    int tt=1;
    cin>>tt;
    while(tt--){
    solve();
    }

}
```

Dibandingkan solusi-solusinya sebelumnya, solusi ini adalah solusi yang paling tidak matematis, alias simple, alias lebih mudah dipahami jika dasar matematikanya tidak terlalu kuat (*dan itulah alasanku memilih contoh kode ini*).

Alur program dan logikanya simple, program ini membuat variabel $len1$ dan $len2$, yang masing-masing menyimpan nilai $x+p.length()$. Nah, operasi ini bertujuan untuk menyimpan banyaknya digit yang dimiliki oleh masing-masing nilai $x$. Ini masuk akal, karena angka dengan digit yang paling banyak, otomatis nilainya lebih besar.

Tapi, jika nilai atau ukuran $len1$ dan $len2$ sama, maka logika berbeda perlu diterapkan disini. Program ini menambahkan digit $0$ pada nilai $x$ yang paling pendek digitnya, supaya nilainya sama dengan digit $x$ satunya lagi.

Lalu, melakukan perbandingan per digit, melalui operasi berikut:

```cpp
for (int i=0;i<a.size();i++){
   if(a[i] > b[i]){
	cout<<">"<<endl;
	return;
   }
   
   if(a[i]<b[i]){
	cout<<"<"<<endl;
	return;
   }	   
}

cout<<"="<<endl;
```

Jika sampai akhir digitnya tidak ada yang berbeda, maka perulangan tidak dihentikan oleh `return`, dan berakhir dengan mengoutputkan $=$.
