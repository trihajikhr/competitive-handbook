---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 489B
judul_DEATH: BerSU Ball
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips:
date_learned: 2025-10-29T19:56:00
tags:
  - depth-first-search
  - dynamic-programming
  - graph-matchings
  - greedy
  - sortings
  - two-pointers
---
Sumber: [Problem - 489B - Codeforces](https://codeforces.com/problemset/problem/489/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 489B-BerSU Ball

Diberikan $n$ anak laki-laki, dan $m$ anak perempuan. Masing-maing memiliki nilai $a_i \; (1 \leq a_i \leq 100)$,   dan juga $b_j \; (1 \leq b_j \leq 100)$.

Tugasmu adalah menentukan banyaknya pasangan laki-laki dan perempuan, dengan selisih maksimal antara keduanya adalah $1$, atau $|a_i - b_j| \leq 1$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Untuk mempermudah penghitungan banyaknya pasangan yang ada, maka data array $a$ dan $b$ perlu kita sorting terlebih dahulu.

Melihat batasan dari input, kita memiliki  2 cara untuk menyelesaikan permasalahan ini.

Cara pertama adalah dengan melakukan perulangan bersarang, dan mencari mana saja pasangan $|a_i -b_j| \leq 1$. Setelah suatu elemen digunakan, maka elemen tersebut bisa dirubah, supaya tidak terhitung lagi di perulangan selanjunya. Hal ini bisa dilakukan sebagai berikut:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

auto main() -> int {
    int n, m;
    cin >> n;
    vector<int> N(n);
    for (auto& x : N) cin >> x;
    cin >> m;
    vector<int> M(m);
    for (auto& x : M) cin >> x;
    ranges::sort(N);
    ranges::sort(M);
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (abs(N[i]-M[j]) <= 1) {
                ans++;
                M[j] = 1000;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}
```

Cara kedua adalah dengan menggunakan 2 variabel bantu yang akan digunakan sebagai variabel indexing (*two pointers*). Yaitu menggunakan perulangan while, dan menggunakan kondisional dimana kedua variabel ini tidak melebihi $n$ dan $m$. Jika $a_i> b_i$ dan selisih keduanya lebih besar dari $1$, maka perulangan akan memajukan indeks array $b$. Tapi jika $a_i < b_i$ dan selisih keduanya lebih dari $1$, maka majukan indeks array $a$. Dan jika $|a_i -b_i| \leq 1$, maka tambahkan isi dari variabel counter, dan majukan indeks array $a$ dan $b$.

Berikut implementasinya:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, m;
    cin >> n;
    vector<int> B(n);
    for (auto& x : B) cin >> x;
    cin >> m;
    vector<int> G(m);
    for (auto& x : G) cin >> x;
    ranges::sort(B);
    ranges::sort(G);

    int ans = 0, x = 0, y = 0;
    while (x < n && y < m) {
        if (B[x] > G[y] && B[x] - G[y] > 1)
            y++;
        else if (G[y] > B[x] && G[y] - B[x] > 1)
            x++;
        else if (abs(B[x] - G[y]) <= 1)
            ans++, x++, y++;
    }
    cout << ans << '\n';
    return 0;
}
```

Cara ini lebih efisien, karena memiliki kompleksitas berupa $O(n+m)$, jauh lebih cepat dari pada pendekatan pertama yang memiliki kompleksitas $O(n \times m)$.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Tentu, ini terjemahan dari teks tersebut:

Terdapat sekitar 100.500 cara untuk menyelesaikan masalah ini. Anda dapat mencari *maximal matching* pada *bipartite graph* anak laki-laki-anak perempuan, menulis *dynamic programming* (pemrograman dinamis) atau cukup menggunakan pendekatan *greedy* (rakus).

Mari kita urutkan anak laki-laki dan perempuan berdasarkan keterampilan. Jika anak laki-laki dengan keterampilan terendah dapat dipasangkan, itu adalah ide yang baik untuk memindahkannya. Ini tidak dapat mengurangi ukuran jawaban. Gunakan anak perempuan dengan keterampilan terendah untuk dipasangkan. Jadi, Anda bisa menggunakan kode seperti:

```cpp
sort(boys.begin(), boys.end());
sort(girls.begin(), girls.end());

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (abs(boys[i] - girls[j]) <= 1)
        {
            girls[j] = 1000;
            result++;
            break;
        }
```

## 3.2 | Analisis Pribadi

Melihat dari penggunaan kondisional yang lebih rapi dan efisien, aku perbarui kodeku menjadi seperti ini:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    int n, m;
    cin >> n;
    vector<int> B(n);
    for (auto& x : B) cin >> x;
    cin >> m;
    vector<int> G(m);
    for (auto& x : G) cin >> x;
    ranges::sort(B);
    ranges::sort(G);
    int ans = 0, x = 0, y = 0;
    while (x < n && y < m) {
        if (abs(B[x] - G[y]) <= 1)
            ans++, x++, y++;
        else if (B[x] > G[y])
            y++;
        else if (G[y] > B[x])
            x++;
    }
    cout << ans << '\n';
    return 0;
}

```

## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int n, m, a[110], b[110], ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int l = 0, r = 0;
    sort(a, a + n);
    sort(b, b + m);
    while (l < n && r < m) {
        if (a[l] < b[r] - 1) l++;
        else if (b[r] < a[l] - 1) r++;
        else {
            ans++;
            l++;
            r++;
        }
    }
    cout << ans;
}
```

Well, pendekatan ini sama persis dengan jawabanku yang kedua, hanya saja penggunaan kondisional didalam kode ini jauh lebih simple dan efisien, terlihat lebih mudah dipahami.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int & i : a) cin >> i;
	int m;
	cin >> m;
	vector<int> b(m);
	for (int & i : b) cin >> i;
	ranges::sort(a), ranges::sort(b);
	int ans = 0;
	for(auto & i : a) 
		for(auto & j : b) 
			if(abs(i - j) <= 1) ++ans, j = INT_MAX, i = INT_MIN;
	cout << ans;
}
```

Pendekatan yang sama dengan jawabanku yang pertama, namun kompleksitasnya adalah $O(n^2)$, tidak efisien untuk ukuran data besar.


### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int m;
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) < 2) {
            ans++;
            i++;
            j++;
        } else if (a[i] > b[j]) j++;
        else i++;
    }
    cout << ans;
}

int32_t main() {
    // int t;cin>>t;
    // while (t--)
    solve();
}
```

Jawaban yang sama dengan  jawabanku versi kedua. Teknik *two pointers*.