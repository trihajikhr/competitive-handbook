---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1525B
judul_DEATH: Permutation Sort
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?: false
date_learned: 2025-10-15T11:03:00
tags:
---
Sumber: [Problem - 1525B - Codeforces](https://codeforces.com/problemset/problem/1525/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1525B-Permutation Sort

Diberikan sebuah permutasi berukuran $n$. Kita diharuskan membuat permutasi ini menjadi terurut, dengan cara memilih subarray berurutan, lalu melakukan sorting terhadap subarray yang dipilih. Ukuran dari subarray ini bebas, tapi tidak boleh sama dengan ukuran permutasi $n$. Tentukan minimal jumlah operasi yang harus dilakukan untuk membuat permutasi ini terutut ascending.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika array sudah terurut, maka kita tidak perlu melakukan operasi apapun. Jika Nilai terkecil atau terbesar ada di ujung permutasi, maka kita perlu melakukan satu kali operasi saja, dimana ukuran subarray yang kita ambil adalah $n-1$, elemen yang ada dipojok (*yang sudah tepat*) tidak kita ikutkan, dan solusi ini valid.

Tetapi, jika nilai terkecil ada diujung kanan, dan nilai terbesar ada di ujung kiri, maka dibutuhkan $3$ kali operasi, untuk membuat permutasi menjadi terurut.

Selebihnya, kita hanya perlu menggunakan 2 kali operasi saja.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    bool incre = true;
    for (int i=0; i<n; i++) {
        cin >> vec[i];
        if (i!=0) {
            if (vec[i]<vec[i-1]) incre = false;
        }
    }

    if (incre) {
        cout << 0 << '\n';
        return;
    }

    if (vec[0]==1 || vec[n-1]==n) cout << 1;
    else if (vec[0]==n && vec[n-1]==1) cout << 3;
    else cout << 2;
    cout << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Untuk menyelesaikan masalah ini, cukup dengan mempertimbangkan beberapa kasus:

1.  Jika *array* sudah terurut, jawabannya adalah $0$.
2.  Jika $a[1]=1$ (atau $a[n]=n$), maka Anda dapat mengurutkan *array* dalam satu operasi dengan memilih *subarray* $[1, n-1]$ (atau $[2, n]$).
3.  Jika $a[1]=n$ dan $a[n]=1$, Anda dapat melakukan urutan operasi $[1, n-1]$, $[2, n]$, dan $[1, n-1]$, dan mengurutkan *array* dengan masing-masing operasi tersebut. (Anda tidak dapat melakukannya lebih cepat karena Anda tidak dapat memindahkan $n$ ke posisi $n$ dan $1$ ke posisi $1$ hanya dalam $2$ operasi).
4.  Selain kasus di atas, *array* dapat diurutkan dalam $2$ operasi.


Implementasi editorial:

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a) scanf("%d", &x);
    int ans = 2;
    if (is_sorted(a.begin(), a.end()))
      ans = 0;
    else if (a[0] == 1 || a[n - 1] == n)
      ans = 1;
    else if (a[0] == n && a[n - 1] == 1)
      ans = 3;
    printf("%d\n", ans);
  }
}
```
## 3.2 | Analisis Pribadi
Intuisi awalku sudah tepat seperti petunjuk dan solusi dari editorial. Perbedaanya hanya terletak pada pengecekan apakah permutasi yang diberikan sudah terurut atau belum. Aku menerima inputan dan langsung melakukan pengecekan, sedangkan solusi dari editorial menggunakan bantuan fungsi yang baru aku tahu juga, yaitu `is_sorted()`.

Solusiku mungkin lebih efisien, dan jawaban pertamaku sudah benar.

```cpp
#include<iostream>
#include<vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    bool incre = true;
    for (int i=0; i<n; i++) {
        cin >> vec[i];
        if (i!=0 && vec[i]<vec[i-1]) {
           incre = false;
        }
    }

    if (incre) cout << 0;
    else if (vec[0]==1 || vec[n-1]==n) cout << 1;
    else if (vec[0]==n && vec[n-1]==1) cout << 3;
    else cout << 2;
    cout << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>
#include<queue>
#include<cstring>
#include<cmath>
#include<unordered_map>
using namespace std;

int a[55];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, w = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] != i) w = 1;
        }
        if (a[1] == n && a[n] == 1) w = 3;
        cout << max(w, (a[1] != 1) + (a[n] != n)) << endl;
    }
}
```

Program ini menggunakan array 1-based-index, dan menggunakan variabel $w$ untuk menampung jawabanya. Jika diketahui bahwa premutasi tidak terurut, maka  $w=1$. Jika $a[1]=1 \,\,\&\&\,\, a[n]=n$,  maka $w=3$. 

Terakhir, outputkan nilai terbesar antara $w$ dengan hasil dari kondisional $(a[1] \neq 1) + (a[n] \neq n)$ (*Jika salah satu kondisi terpenuhi, maka menambah nilai 1, jika keduanya terpenuhi, maka menambah nilai 2, jika tidak ada yang terpenuhi, maka menjadi 0*).
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> vec(n + 1);
        bool ok = 1;
        for (int i = 1; i <= n; ++i) {
            cin >> vec[i];
            if (vec[i] != i) ok = 0;
        }
        if (ok) cout << "0\n";
        
        else {
            if (vec[1] == 1 or vec[n] == n) cout << "1\n";
            else if (vec[1] == n && vec[n] == 1) cout << "3\n";
            else cout << "2\n";
        }
    }
}
```

Solusi mirip seperti editorial, karena memang pengecekan seperti ini adalah solusi yang paling efisien, $O(1)$ kompleksitas.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define int long long
#define nl "\n"
#define sp " "
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    if(is_sorted(v.begin(), v.end())){
        cout << 0 << nl; return;}
    if(v[0] == 1 || v[n - 1] == n){
        cout << 1 << nl; return;
    }
    else if(v[0] == n && v[n - 1] == 1){
        cout << 3 << nl; return;
    }
    else cout << 2 << nl; return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();
    
    return 0;
}
```

Another solusi yang mirip editorial.