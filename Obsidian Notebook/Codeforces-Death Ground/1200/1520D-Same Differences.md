---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1520D
judul_DEATH: Same Differences
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips: false
date_learned: 2025-10-29T14:46:00
tags:
  - data-structure
  - hashing
  - math
---
Sumber: [Problem - 1520D - Same Differences](https://codeforces.com/problemset/problem/1520/D)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1520D-Same Differences

Diberikan sebuah array $a$ dengan $n$ elemen. Tentukan banyaknya pasangan array untuk dua buah elemen $i$ dan $j$, dimana $i < j$, yang memenuhi kondisi berikut:

$$j-i \equiv a_j - a_i$$

<br/>

---
# 2 | Sesi Death Ground ⚔️

Pertama, ketahui dulu bahwa solusi yang terpikirkan oleh kita pasti adalah melakukan traversal bersarang untuk menemukan total semua pasangan yang memenuhi syarat. Namun kompleksitas $O(n^2)$ tidak mungkin berhasil disini. 

Perhatikan juga bahwa kita harus menyimpan total pasangan, yang mana jumlahnya bisa sangat besar, sehingga bisa melakukan langkah aman dengan menggunakna tipe data `long long`.

Untuk mengetahui pasangan mana saja yang memenuhi persyaratan yang diberikan, terlebih dahulu lihat array berikut:

$$16,9, 13, 11, 15, 13, 16, 16, 11, 15, 15, 16, 16, 16 ,16, 15, 16$$

Banyaknya pasangan yang ada pada array diatas adalah $7$ pasang. Sekarang mari kita telusuri secara perlahan kenapa hasil akhirnya adalah $7$.

Terdapat sebuah pola, dimana setiap elemen berpasangan yang memenuhi $j-i \equiv a_j - a_i$, maka mereka akan memiliki nilai yang sama untuk $a_j - j \equiv a_i - i$, atau nilai elemenya dikurangi dengan nilai indeksnya. Kita sebut saja nilai ini dengan $dif$.

Jika menggunakan data diatas, maka berikut adalah masing-masing nilai $dif$ dari tiap elemen:

$$8, 11, 8, 11, 8, 10, 9, 3, 6, 5, 5, 4, 3, 2, 0, 0$$

Supaya mudah dilihat, kita sorting (*dalam implementasi asli, sorting tidak perlu dilakukan! Sekedar upaya untuk mempermudah penjelasan!*):

$$0, 0, 2, 3, 3, 4, 5, 5, 6, 8, 8, 8, 9, 10, 11, 11$$

Untuk dua buah elemen dengan nilai $dif$ yang sama, mereka akan membentuk $1$ pair, untuk $3$ buah elemen dengan nilai $dif$ yang sama, mereka akan membentuk $3$ pair, $4$ elemen dengan nilai $dif$ yang sama akan membentuk $6$ pair. Intinya ketika ada kumpulan $dif$ yang sama lebih dari $1$ maka elemen-elemen tersebut mampu untuk membangun pasangan.

Atau, semisal kita memiliki variabel $tpair$ yang menampung banyaknya pasangan untuk kumpulan elemen-dengan dengan $dif$ yang sama, maka kita bisa menggunakan rumus berikut (*rumus penjumlahan deret matematika, namun kita kurangi dengan satu, karena tidak dimulai dari $1$*):

$$tpair =  \frac{(dif-1) \times dif}{2}$$

Kita hanya menghitung nilai $tpair$ dari elemen yang memiliki kemunculan $dif$ yang sama lebih dari $1$, ini karena elemen yang memiliki nilai $dif$ tanpa pasangan, artinya elemen tersebut tidak bisa membangun pair dengan elemen manapun.

Untuk mempermudah penghitungan kemunculan $dif$ yang sama, bisa digunakan struktur data `unordered_map` atau `map`, misal kita simpan di $dasmap$.

Maka akan didapat beberapa elemen dengan nilai $dif$ yang sama lebih dari $1$ sebagai berikut:
$$0(2), 3(2), 5(2), 8(3), 11(2)$$
Setelah itu, gunakan rumus untuk mencari pasangan yang mungkin terbentuk dari $2,2,2,3$ dan $2$ elemen, atau mencari setiap nilai $tpair$, lalu jumlahkan semuanya, dan tampung pada sebuah variabel misal $ans$. Lakukan traversal pada sturktur data yang digunakan, dan hitung:

$$ans = \sum_{i=1}^{i=n} \; \frac{(dif-1) \times dif}{2} $$

Maka, akan didapat hasil berupa $7$.

Berikut adalah implementasiku:

```cpp
#include <chrono>
#include <iostream>
#include <unordered_map>
using namespace std;

using ll = long long;

using DM = unordered_map<ll, ll>;
void print(const DM& dasmap) {
    for (const auto& x : dasmap) {
        cerr << x.second << " ";
    }
}

void solve() {
    ll n;
    cin >> n;
    unordered_map<ll, ll> dasmap;
    dasmap.reserve(n);
    for (ll i = 1, x; i <= n; i++) {
        cin >> x;
        dasmap[x - i]++;
    }

    ll cnt = 0;
    for (const auto& [key, val] : dasmap) {
        if (val > 1) {
            cnt += ((val - 1) * val) / 2;
        }
    }

    cout << cnt << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Mari kita tulis ulang persamaan aslinya sedikit:

$$a_j - a_i = j - i$$

$$a_j - j = a_i - i$$

Mari kita ganti setiap $a_i$ dengan $b_i = a_i - i$. Maka, jawabannya adalah jumlah pasangan $(i, j)$ sedemikian rupa sehingga $i < j$ dan $b_i = b_j$. Untuk menghitung nilai ini, Anda bisa menggunakan `map` atau *sorting*.

### Penjelasan Konsep (Opsional)

Teks ini menjelaskan sebuah trik dalam pemecahan masalah algoritma/pemrograman untuk menghitung jumlah pasangan dalam sebuah urutan atau larik ($a_i$) yang memenuhi properti tertentu.

* **Ide Utamanya** adalah mengubah masalah penjumlahan dan pengurangan pada dua indeks ($a_j - a_i = j - i$) menjadi masalah pencocokan nilai yang sama pada larik yang baru ($b_i = b_j$).
* Jika kita sudah memiliki larik $b$, menghitung jumlah pasangan $(i, j)$ di mana $b_i = b_j$ dan $i < j$ dapat dilakukan dengan efisien, biasanya menggunakan `map` (untuk menghitung frekuensi setiap nilai $b_i$) atau dengan sorting larik $b$ terlebih dahulu.

Implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map < int, int > a;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x -= i;
        res += a[x];
        a[x]++;
    }
    cout << res << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests--> 0) {
        solve();
    }
    return 0;
}
```

## 3.2 | Analisis Pribadi

Berikut adalah implementasiku yang sudah diperpendek dan disederhanakan:

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

using ll = long long;
void solve() {
    ll n;
    cin >> n;
    unordered_map<ll, ll> dasmap;
    dasmap.reserve(n);
    for (ll i = 1, x; i <= n; i++) {
        cin >> x;
        dasmap[x - i]++;
    }

    ll ans = 0;
    for (const auto& [key, val] : dasmap) {
        ans += ((val - 1) * val) / 2;
    }

    cout << ans << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

Well, implementasi editorial menggunakan cara yang lebih clever untuk menjumlahkan banyaknya pasangan yang ada:

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    map < int, int > a;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x -= i;
        res += a[x];
        a[x]++;
    }
    cout << res << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests--> 0) {
        solve();
    }
    return 0;
}
```

Jika elemen tersebut hanya muncul satu kali, maka operasi $res += a[x]$ sama saja dengan menambahkanya dengan angka $0$. Ini karena elemen tersebut belum sempat ditambahkan ke map ketika operasi tersebut dilakukan. Dan ini benar karena elemen dengan nilai $dif$ yang hanya muncul sekali, tidak bisa membangun pair.

Selain itu, operasi inputan langsung membangun jawaban, karena frekuensi ditambahkan satu-persatu, jadi kenapa tidak jumlahkan banyaknya pasangan sekalian 🤔.

Trik yang sangat clever!
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, n, x, a;
    cin >> t;
    while (t--) {
        a = 0, cin >> n;
        map <int, int> m;
        for (int i = 0; i < n; i++)
            cin >> x, a += m[x - (i + 1)]++;
        cout << a << "\n";
    }
}
```

Jika penulis kode ini mengganti nilai awal iterasi $i=1$, dan membuat kondisional didalam perulangannya adalah $i \leq n$, maka operasi penambahan $a$ akan menjadi jauh lebih simpel, yaitu cukup $a += m[x-i]$ saja.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll num, count = 0;
        map <int, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> num;
            count += freq[num - i]++;
        }
        cout << count << "\n";
    }
}
```

Solusi yang lebih simple dan readable. Pendek namun lebih efisien, karena menyimpan hasil langsung ketika menerima inputan.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using ll = long long int;
using namespace std;
#define rep(i, a, b) for (int i = int(a); i < int(b); ++i)
#define SZ(v) int((v).size())
const int MOD = int(1e9) + 7;
const int INF = int(2e8);
const int MAXN = int(2e5);

int a[MAXN + 5];
int f[2 * MAXN + 5];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        ll ans = 0LL;
        rep(i, 1, n + 1) {
            cin >> a[i]; 
            a[i] += (MAXN - i);
            ans += 1ll * f[a[i]];
            f[a[i]]++;
        }
        rep(i, 1, n + 1) f[a[i]] = 0;
        cout << ans << "\n";
    }
    
    return 0;
}
```

Menggunakan konsep yang hampir sama dengan penggunaan struktur data map atau unordered_map, tetapi menggunakan implementasi sendiri, sehingga dibuatlah array dengan ukuran $2 \cdot 10^5$ yang valuenya disimpan di $MAXN$, yaitu array $a$ dan $f$. $MAXN$ ini adalah batasan banyaknya elemen. 

Lalu ketika index $i$ masih bernilai kecil, maka nilai $a[i]$ akan menyimpan nilai yang sangat besar, atau dibangun dari belakang array $a$, karena $a=a+MAXN-i$ .

Lalu, simpan banyaknya jumlah frekuensi dengan menggunakan array $f$, menggunakan indeks yang disimpan oleh array $a$. Itulah alasan digunakan $f[a[i]]$ berkali kali didalam kode, yaitu pengaksesan frekuensi.

Sebenarnya implementasi ini bisa jauh lebih simple jika menggunakan bantuan struktur data yang sudah disediakan oleh STL, tapi tidak apa-apa, kita gunakan sebagai evaluasi dan pembelajaran.