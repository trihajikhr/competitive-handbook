---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: competitive-1/8/A
judul_DEATH: Simulasi Array Dinamis
teori_DEATH: Array dinamis ialah vector
sumber:
  - tlx-toki.id
rating:
ada_tips?: true
date_learned: 2025-10-14T14:24:00
tags:
  - data-structure
---
Sumber: [TLX](https://tlx.toki.id/courses/competitive-1/chapters/08/problems/A)

```ad-tip
title:⚔️ Teori Death Ground
Array dinamis seperti vector sangatlah mudah digunakan. Walaupun array biasa mungkin sedikit lebih cepat, kefleksibilitasan dari vector membuatnya jauh lebih powerfull di banyak kondisi.
```

<br/>

---
# 1 | Simulasi Array Dinamis

Kita diminta untuk mensimulasikan $q$ operasi terhadap serangkain array bilangan bulat. Pada mulanya, terdapat satu array kosong. Array ini dinomori sebagai array $1$. Lalu, anda perlu menjalankan serangkain perintah, yang masing-masing dapat berupa:

- `add L X Y`
    - masukkan (_append_) $Y$ buah bilangan bulat, masing-masing adalah $X$, ke belakang larik nomor $L$.
    - dijamin larik nomor $L$ ada.
- `new`
    - buat sebuah larik baru, yang diberi nomor yaitu $1$ lebih tinggi daripada nomor larik tertinggi yang ada sekarang.
- `out L Z`
    - cetak sebuah baris berisi elemen ke-$Z$ dari larik nomor $L$.
    - elemen-elemen dari setiap larik dinomori dari nomor $1$ sampai dengan ukuran larik.
    - dijamin elemen tersebut ada.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika dilihat dari contoh input output, yaitu seperti ini:

```
9
add 1 1 3
add 1 4 1
new
out 1 3
new
add 2 7 2
add 3 5 1
out 2 2
out 3 1
```

Karena dalam satu operasi, kita perlu membaca perintah yang berbeda-beda, maka akan lebih baik jika penanganan inputan seperti ini dilakukan oleh fungsi `stringstream` dari header `sstream`.

Operasi pertama, yaitu `add L X Y`, adalah menambahkan angka $X$ sebanyak $Y$ kali, tepat di belakang larik/array ke $L$. Penambahan ke belakang, membawa intuisi bahwa akan jauh lebih mudah jika kita menggunakan struktur data vector. Ini karena kita bisa menggunakan fungsi `push_back()`, yang akan menambahkan elemen dibagian belakang vector. Karena akan ada beberapa array, maka vector yang kita gunakan juga harus dibuat 2 dimensi. Pada saat pendeklarasian, kita inisialisasi banyaknya vector pada vector 2 dimensi adalah 1, supaya siap menampung data awal.

Ingat juga, setiap inputan memperlakukan array sebagai 1-based index, jadi harus kita konversi inputan yang kita terima supaya pas dengan array 0-based index.

Operasi `new`, bisa ditangani dengan melakukan `emplace_back()` pada vector dua dimensi, menambahkan banyaknya vector pada vector 2 dimensi, dalam keadaan awal yang masih kosong.

Lalu operasi terakhir, yaitu `out L Z`, adalah mengakses vector ke $L$, dan elemen di index ke $Z$. Ini sangat mudah, karena kita cukup menggunakan dua inputan ini sebagai index pengakses vector dua dimensi, cukup sesuaikan saja jika kita menggunakan array 0-based index. 


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

## 3.2 | Analisis Pribadi

Ada beberapa versi jawaban, tapi aku mencoba untuk menggunakan cara yang lebih basic, yaitu vector 2 dimensi. Jadi, berikut adalah jawaban saya:

```cpp
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> data(1);
    int q;
    cin >> q;
    while (q--) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        string cmd;
        int a,b,c;
        ss >> cmd;
        if (cmd == "add") {
            ss >> a >> b >> c;
            for (int i=0; i<c; i++) {
                data[a-1].push_back(b);
            }
        } else if (cmd == "new") {
            data.emplace_back();
        } else if (cmd == "out") {
            ss >> a >> b;
            cout << data[a-1][b-1] << '\n';
        }
    }
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
    int t, idx = 1; cin >> t;
    map<int, vi> arr; arr[1] = vi();
    while(t--) {
        string s; cin >> s;
        if (s == "add") {
            int l, x, y; cin >> l >> x >> y;
            rep(i, 0, y) {
                arr[l].push_back(x);
            }
        } else if (s == "new") {
            idx++; arr[idx] = vi();
        } else if (s == "out") {
            int l, z; cin >> l >> z;
            cout << arr[l][z - 1] << endl;
        }
    }
}
```

Well, daripada pusing-pusing menyamakan standar based-index pada arary, user ini justru langsung saja menggunakan struktur data map (*kecuali untuk operasi out*). Struktur data map tersebut menyimpan dua nilai, satu adalah `int` untuk menyimpan nomor array, dan kedua adalah vector (*kombinasi antara map dan vector*).

Untuk menangani inputan, dia juga tidak perlu menggunakan `sstream`, tapi menangkap string awal, lalu memperlakukanya dengan cara berbeda di bagian percabangan, hmmm.. oke, efisien juga.

Kode ini juga menangani operasi penambahan array, yaitu operasi `new` dengan menggunakan variabel `idx` yang di increment, lalu tetapkan `arr[idx] = vector<int>()`, atau mengisinya dengan vector kosong.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

vector<int>v[10005];
signed main(){
    int q; cin >> q;
    while(q--){
        string t; cin >> t;
        if(t == "add"){
            int l, x, y; cin >> l >> x >> y;
            for(int i=1; i<=y; i++) v[l].pb(x);
        }else if(t == "out"){
            int l,z; cin >> l >> z;
            cout << v[l][z-1] << endl;
        }
    }
}
```

Mari kita bedah kode ini, karena kode ini juga benar, tapi sangat singkat.

Pertama, dia menetapkan vector 2 dimensi:

```cpp
vector<int>v[10005];
```

Dimana ukuran vector 2 dimensi ini sangat besar, langsung ditetapkan sebanyak 10005, dengan tujuan mengatasi semua test case. Hal ini juga membuat program tersebut tidak perlu menangani operasi `new`, karena semua lariknya sudah mengcover kebutuhan input. Tapi ini bukan praktif yang efisien, karena boros memory.

Selebihnya, tidak jauh berbeda dengan kode pertama.

### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> v(1);

    int q;
    cin >> q;
    
    while (q--) {
        string op;
        cin >> ws;
        cin >> op;
        
        if (op == "add") {
            int l, x, y;
            cin >> l >> x >> y;
            for (int i = 0; i < y; i++) {
                v[l-1].push_back(x);
            }
        }
        
        if (op == "new") {
            v.push_back(vector<int>(0));
        }
        
        if (op == "out") {
            int l, z;
            cin >> l >> z;
            cout << v[l-1][z-1] << endl;
        }
    }
}
```

Alur programnya tidak jauh berbeda, mungkin adalah adanya syntax berikut yang menarik:

```cpp
cin >> ws;
```

Maksud dari syntax ini adalah mengatasi spasi kosong diawal inputan, sehingga ketika syntax berikut dijalankan:

```cpp
cin >> op;
```

... maka variabel `op` akan menerima inputan yang tepat. 

```ad-info
`std::ws` adalah sebuah manipulator istream yang didefinisikan dalam header <istream>.

Ketika digunakan bersama dengan operator ekstraksi (operator>>),
ia menyebabkan pembacaan dan pengabaian seluruh karakter whitespace (' ', '\t', '\n', '\r', dan sejenisnya) dari aliran masukan atau `std::istream` hingga karakter pertama yang bukan whitespace ditemukan.
```

Walupun begitu, sebenarnya hal ini tidak perlu, karena inputan yang diberikan sudah dalam format yang sesuai (*tanpa ada spasi kosong diawal baris*).