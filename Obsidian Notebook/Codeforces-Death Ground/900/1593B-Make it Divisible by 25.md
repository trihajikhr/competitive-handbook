---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1593B
judul_DEATH: Make it Divisible by 25
teori_DEATH: Pembagian 25
sumber:
  - codeforces.com
rating: 900
ada_tips?: true
date_learned: 2025-10-08T17:52:00
tags:
  - string
---
Sumber: [Problem - 1593B - Codeforces](https://codeforces.com/problemset/problem/1593/B)

```ad-tip
title:⚔️ Teori Death Ground
- Tampung semua kombinasi, dan gunakan sebagai bahan brute force!
```

<br/>

---
# 1 | 1593B-Make it Divisible by 25

Diberikan sebuah angka. Tugas kita adalah membuat angka tersebut bisa dibagi habis oleh $25$, dengan cara membuang digit-digit yang ada seminimal mungkin. 

Jika penghapusan digit membuat angka $n$ diawali dengan $0$, maka angka nol didepan tersebut  akan dihapus secara otomatis (operasi penghapusan 0 didepan tidak perlu dihitung).

<br/>

---
# 2 | Sesi Death Ground ⚔️

Untuk membuat suatu angka habis dibagi dengan $25$, mudah saja. Kita hanya perlu memastikan bahwa 2 digit terakhirnya adalah angka-angka berikut: $00,25,50,75$.

Aku mengetahui hal ini, namun aku masih kesulitan bagaimana mengatasinya. Aku melakukan pencarian berdasarkan digit, namun solusiku tidak mengarah ke solusi yang efisien. 

Berdasarkan soal, nilai dari $n$ sangatlah besar, yaitu sekitar $10^{18}$, sehingga algoritma yang efisien wajib diterapkan disini!

Solusinya adalah memperlakukan inputan bukan sebagai angka, tetapi sebagai string. Sehingga pencarian solusi ibarat melakukan pencarian array yang hanya berukuran paling tinggi $18$ elemen saja!

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official
Suatu angka dapat dibagi habis oleh **25** jika dan hanya jika dua digit terakhirnya merepresentasikan salah satu dari rangkaian string berikut: "00", "25", "50", "75".

Mari kita pecahkan sub-tugas berikut untuk setiap string: berapakah **jumlah minimum karakter yang harus dihapus** sehingga string tersebut menjadi sufiks (akhiran) dari angka tersebut. Kemudian, dengan memilih minimum dari jawaban untuk semua sub-tugas, kita menyelesaikan keseluruhan masalah.

Mari kita pecahkan sub-tugas untuk string "X Y" di mana 'X' dan 'Y' adalah digit. Kita dapat melakukannya menggunakan algoritma berikut: mari kita hapus digit terakhir angka tersebut hingga digit itu sama dengan 'Y', kemudian digit kedua terakhir dari angka tersebut hingga digit itu sama dengan 'X'. Jika ini tidak memungkinkan, maka sub-tugas ini tidak memiliki solusi (yaitu, hasilnya tidak akan memengaruhi jawaban).

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

const string subseqs[] = {
    "00",
    "25",
    "50",
    "75"
};

const int INF = 100;

int solve(string & s, string & t) {
    int sptr = s.length() - 1;

    int ans = 0;
    while (sptr >= 0 && s[sptr] != t[1]) {
        sptr--;
        ans++;
    }

    if (sptr < 0) return INF;

    sptr--;

    while (sptr >= 0 && s[sptr] != t[0]) {
        sptr--;
        ans++;
    }

    return sptr < 0 ? INF : ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string n;
        cin >> n;

        int ans = INF;
        for (auto e: subseqs)
            ans = min(ans, solve(n, e));

        cout << ans << '\n';
    }

    return 0;
}
```

## 3.2 | Analisis Pribadi

Karena aku tidak paham, akhirnya aku mengikuti panduan darii editorial, berikut implementasiku:

```cpp
#include<iostream>
#include<array>
#include<string>
using namespace std;

const array<string, 4> pass {
    "00",
    "25",
    "50",
    "75",
};

void solve() {
    string n;
    cin >> n;
    int ans = INT_MAX, temp=0;
    for (const auto& p : pass) {
        temp=0;
        int len = static_cast<int>(n.length()) - 1;
        while (len >= 0 && n[len]!=p[1]) {
            len--, temp++;
        }

        len--;
        while (len >= 0 && n[len]!=p[0]) {
            len--, temp++;
        }
        ans = min(ans, temp);
    }
    cout << ans << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

Ternyata, pendekatan editorial menuju solusi adalah *brute force*. Kita tahu bahwa hanya ada 4 kombinasi digit yang membuat suatu angka bisa dibagi habis oleh $25$, yaitu yang terdaapat di array `pass`. Selanjutnya, kita perlu mencari semua langkah yang dibutuhkan untuk memenuhi setiap kombinasi ini!

Lalu tugas kita selanjutnya adalah mencari langkah yang paling sedikit (minimal), dan itulah jawabanya. Jika sebuah kombinasi tidak ditemukan, maka pasti jumlah `temp` akan menjadi lebih besar diatara yang lain, sehingga tidak perlu kita khawatirkan (perulangan while akan berhenti jika sudah melebihi panjang string).

Cari banyaknya langkah untuk menemukan digit terakhir:

```cpp
while (len >= 0 && n[len]!=p[1]) {
	len--, temp++;
}
```

Cari banyaknya langkah untuk menemukan digit kedua dari terakhir:

```cpp
len--;
while (len >= 0 && n[len]!=p[0]) {
	len--, temp++;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

int t, s;
string n;
int main() {
    cin >> t;
    while (t--) {
        s = 0;
        cin >> n;
        for (int i = 0; i < n.size(); i++) {
            for (int j = i + 1; j < n.size(); j++)
                if (((n[i] - '0') * 10 + (n[j] - '0')) % 25 == 0) {
	                s = n.size() - i - 2;
                }
        }
        cout << s << endl;
    }
}
```

Menggunakan pencarian manual, tetapi dimulai dari depan (paling kiri ke kanan). Logika yang digunakan adalah:

Perulangan pertama mengambil digit $i$, dan perulangan kedua mengambil digit $j=i+1$. Jika kedua digit tadi bisa dibagi habis oleh $25$ (dengan cara $(i \times 10) + j$ ), maka simpan jawaban. Karena langkah terkecil untuk membuat angka $n$ bisa dibagi habis oleh $25$ adalah dengan menyingkirkan angka sesedikit mungkin dari kiri, otomatis nilai $s$ akan menampung langkah terkecil untuk membuat angka $n$ habis dibagi oleh $25$ di akhir perulangan.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string inp {};
map < char, vector < size_t >> mp {};

size_t helper(char x, char y) {
    if (mp.find(x) == mp.end() || mp.find(y) == mp.end())
        return INT_MAX;

    vector < size_t > & v1 {
        mp.find(x) -> second
    };
    vector < size_t > & v2 {
        mp.find(y) -> second
    };

    for (int i {
            v1.size() - 1
        }; i >= 0 && !v2.empty(); --i) {
        if (v1[i] < v2.back())
            return inp.size() - v1[i] - 2;
    }

    return INT_MAX;
}

void solve() {
    cin >> inp;
    mp.clear();

    for (size_t i {}; i < inp.size(); ++i)
        mp[inp[i]].push_back(i);

    size_t res {
        INT_MAX
    };

    res = min(helper('2', '5'), min(helper('5', '0'), helper('7', '5')));

    size_t sz {
        mp['0'].size()
    };
    if (sz >= 2)
        res = min(res, inp.size() - mp['0'][sz - 2] - 2);

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t {
        1
    };
    cin >> t;

    while (t--)
        solve();

    return 0;
}
```

Kode tersebut memecahkan masalah dari Codeforces 1593B, yaitu mencari berapa minimal banyak digit yang harus dihapus dari sebuah angka agar hasil akhirnya habis dibagi $25$. Karena bilangan yang habis dibagi $25$ selalu berakhir dengan “00”, “25”, “50”, atau “75”, program mencari dua digit terakhir yang bisa membentuk salah satu dari pola tersebut. 

Program menyimpan semua posisi tiap digit dalam string menggunakan map, lalu lewat fungsi `helper` dicek apakah ada urutan dua digit yang sesuai, misalnya ‘2’ diikuti ‘5’ untuk pola “25”. Jika ditemukan, jumlah digit yang harus dihapus dihitung dari selisih panjang string terhadap posisi digit pertama dari pasangan itu. Program kemudian mengambil nilai terkecil di antara semua kemungkinan pola. Khusus untuk pola “00”, perhitungannya dilakukan langsung dengan memastikan ada minimal dua nol di dalam angka. Hasil akhirnya adalah angka terkecil yang menunjukkan berapa banyak digit perlu dihapus supaya angka tersebut bisa menjadi kelipatan 25.

### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
#define pb push_back
#define vi vector<int>
#define vv vector<vi>
#define vp vector<pair<int, int>> 
#define all(v) v.begin(), v.end()
#define fr(i, n) for(int i=0;i<n;i++)
#define Fr(i, x) for(int i=x;i>=0;i--)
#define speedpenchu cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(0);
using namespace std;
const int N = 2E05+10;
const int MOD = 1000000007;

int BinPow(int a, int b){int ans = 1;while(b > 0){if(b & 1){ans = (ans * a)%MOD;}a = (a * a)%MOD;b >>= 1;}return ans;}

void javabu(){
    string s; cin>>s;
    int n = s.size();
    int res = n;
    Fr(i, n-1){
        Fr(j, i-1){
            if(s[i] == '0' && (s[j] == '0' || s[j] == '5')){
                res = min(res, n-j-2);
                // cout<<n-j-2<<endl;
            }else if(s[i] == '5' && (s[j] == '2' || s[j] == '7')){
                res = min(res, n-j-2);
            }
        }
    }
    cout<<res<<endl;
}

signed main(){
    speedpenchu
    int t; cin>>t;
        while(t--){
            javabu();
            // cout<<50555%25<<endl;
        }
    return 0;
}
```

Program membaca sebuah angka dalam bentuk string $s$ dan menyimpan panjangnya $n$. Nilai awal hasil $res$ diatur sebesar $n$ sebagai batas maksimum. Selanjutnya, program melakukan dua perulangan mundur: indeks luar $i$ berjalan dari $n-1$ ke $0$, dan indeks dalam $j$ berjalan dari $i-1$ ke $0$. 

Setiap pasangan $(s[j], s[i])$ diperiksa untuk melihat apakah membentuk akhiran yang membuat angka habis dibagi 25, yaitu “00”, “25”, “50”, atau “75”. Jika $s[i] = '0'$ dan $s[j]$ adalah `'0'` atau `'5'$, maka pola yang terbentuk adalah “00” atau “50”; jika $s[i] = '5'$ dan $s[j]$ adalah `'2'`atau`'7'$, maka polanya adalah “25” atau “75”. 

Untuk setiap pasangan valid, jumlah digit yang harus dihapus dihitung dengan rumus $n - j - 2$, yaitu banyaknya digit di kanan pasangan tersebut. Nilai $res$ kemudian diperbarui dengan nilai minimum antara $res$ dan hasil perhitungan itu. Setelah semua pasangan selesai diperiksa, nilai akhir $res$ menunjukkan jumlah digit paling sedikit yang perlu dihapus agar angka akhir habis dibagi 25.

