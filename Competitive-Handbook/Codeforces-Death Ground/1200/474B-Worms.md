---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 474B
judul_DEATH: Worms
teori_DEATH: prefix sum dan lower_bound
sumber:
  - codeforces.com
rating: 1200
ada_tips?: false
date_learned: 2025-10-29T16:25:00
tags:
  - binary-search
  - implementation
---
Sumber: [Problems - 474B -Worms](https://codeforces.com/problemset/problem/474/B)

```ad-tip
title:⚔️ Teori Death Ground

Menggunakan prefix sum dan binary search
```

<br/>

---
# 1 | 474B-Worms

Kamu diberikan sebuah array $a$ berukurang $n$. Array $a$ ini menjadi acuan untuk membangun sebuah array $b$, dimana nilainya dari deret kiri ke kanan, dibangun berdasarkan $a_i + 1$ ke $a_1+a_2$, dan seterusnya.

Lalu kamu diberikan $q$ queries atau pertanyaan, dimana setiap $q_i$ akan berada di rentang mana dari array $b$ yang terbentuk. 

Tugasmmu adalah menampilkan indeks yang tepat dari lokasi kemungkinan nilai $q_i$ terhadap array $b$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Well, penjelasan awal sebenarnya adalah penjelasan yang jauh lebih disederhanakan supaya mempercepat pembelajaran.

Disini katakanlah kita memiliki array $2,7,3,4,9$, maka array $b$ akan memiliki nilai sebagai berikut:

- Rentang pertama $[1,2]$
- Rentang kedua $[3,9]$
- Rentang ketiga $[10,12]$
- Rentang keempat ${13,16}$
- Rentang kelimat $[17,25]$

Atau seperti ini: $1,2,3,9,10,12,13,16,17,25$. Ini artinya, satu elemen $a$ akan membuat $2$ elemen $b$, sehingga array $b$ akan memiliki elemen sebanyak $n \times 2$.

Array $b$ ini bisa dibangun langsung ketika menerima inputan, dengan:
- Ketika array $b$ masih kosong, atau $i=1$, maka masukan nilai $1$ dan $a_1$
- Ketika array $b$ sudah tidak kosong, maka masukan $2$ data. Misal nilai dari elemen terakhir array $b$ adalah $back$, maka masukan $back+1$, setelah itu masukan juga $back-1+a_i$. 

Setelah itu, lakukan pencarian lokasi yang pas untuk $q_i$ dengan binary search, yang mana untungnya kita bisa menggunakan fungsi dari header algorithm, yaitu `upper_bound()` atau `lower_bound()`. Pilih salah satu, karena keduanya aman digunakan dikasus ini, karena tidak mungkin ada elemen yang sama selain jika $a_1 = 1$, maka $2$ elemen pertama array $b$ pasti $[1,1]$, tapi untungnya ini juga tidak akan mengganggu jalanya logika program.

Setelah itu, akan didapat nilai index, dan untuk mendapatkan lokasi rentang yang tepat, bagi dengan $2$ dan dibulatkan keatas: $\left\lceil \frac{idx}{2} \right\rceil$

Berikut adalah implementasiku:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n;
    vector<ll> v;
    for (ll i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            v.push_back(1);
            v.push_back(x);
        } else {
            size_t n = v.size();
            v.push_back(v[n - 1] + 1);
            v.push_back(v[n] - 1 + x);
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        cin >> x;
        auto idx = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout << (idx + 1) / 2 << '\n';
    }
    return 0;
}
```

Tanpa menggunakan `push_back()`, tetapi langsung menggunakan operator `[]`:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n;
    vector<ll> v(n * 2);
    for (ll i = 0; i < n; i++) {
        cin >> x;
        if (i == 0) {
            v[i * 2] = 1;
            v[(i * 2) + 1] = x;
        } else {
            v[i * 2] = v[(i * 2) - 1] + 1;
            v[(i * 2) + 1] = v[(i * 2) - 1] + x;
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        cin >> x;
        auto idx = upper_bound(v.begin(), v.end(), x) - v.begin();
        cout << (idx + 1) / 2 << '\n';
    }
    return 0;
}

```
<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Ada dua solusi:

1.  Kita dapat membuat jumlah parsial ($\text{sum}_i = a_1 + a_2 + \dots + a_i$) dan kemudian melakukan binary search untuk setiap permintaan $q_i$ untuk menemukan hasilnya $j$ dengan properti $\text{sum}_{j-1} < q_i$ dan $\text{sum}_j \ge q_i$. Solusi ini memiliki kompleksitas $\text{O}(n + m \cdot \log(n))$.

2.  Kita dapat menghitung terlebih dahulu indeks tumpukan (*pile*) untuk setiap cacing dan kemudian menjawab untuk setiap permintaan dalam $\text{O}(1)$. Solusi ini memiliki kompleksitas $\text{O}(n + m)$.

### Penjelasan Konteks (Tambahan)

Teks ini kemungkinan besar merujuk pada masalah pemrograman kompetitif (seperti "Worms" atau varian dari masalah range query pada tumpukan/seksi).

* Asumsi Masalah: Terdapat $n$ tumpukan/bagian dengan ukuran $a_1, a_2, \dots, a_n$. Cacing/item diurutkan secara berurutan: cacing 1 hingga $a_1$ berada di tumpukan 1; cacing $a_1+1$ hingga $a_1+a_2$ berada di tumpukan 2, dan seterusnya. Kita diberi $m$ pertanyaan ($q_i$), yaitu nomor cacing ke berapa yang sedang dicari.

<br/>

* Jumlah Parsial ($\text{sum}_i$): Ini adalah batas akhir setiap tumpukan.
    * $\text{sum}_1 = a_1$
    * $\text{sum}_2 = a_1 + a_2$ (batas cacing untuk tumpukan 2)
    * Cacing dengan nomor $q_i$ berada di tumpukan $j$ jika $\text{sum}_{j-1}$ (batas tumpukan sebelumnya) sudah dilewati, tetapi $\text{sum}_j$ (batas tumpukan saat ini) belum dilewati.

<br/>

* Kompleksitas ($\text{O}(\dots)$):
    * Solusi 1 (Pencarian Biner): Kita butuh waktu $\text{O}(n)$ untuk menghitung semua $\text{sum}_i$. Lalu, untuk setiap $m$ pertanyaan, pencarian biner pada larik $\text{sum}$ butuh $\text{O}(\log n)$. Total: $\text{O}(n + m \cdot \log n)$.
    * Solusi 2 (Prekalkulasi/Map): Kita menghitung terlebih dahulu tumpukan mana yang sesuai dengan setiap nomor cacing (total $a_1+a_2+\dots+a_n$ cacing) dan menyimpannya dalam larik. Ini butuh waktu $\text{O}(n)$ untuk tumpukan dan $\text{O}(\text{total cacing})$ untuk larik (biasanya disederhanakan menjadi $\text{O}(n+m)$ karena *query* $m$ adalah langkah $\text{O}(1)$). Ini lebih cepat jika $m$ sangat besar.

## 3.2 | Analisis Pribadi

Melihat dari jawaban pengguna lain, ternyata kita cukup membangung prefix sum biasa, dan ketika dilakukan pencarian `lower_bound`, maka hasilnya langsung ditemukan. 

Aku memperbaiki jawabanku menjadi seperti ini:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, q;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> v[i], v[i] += v[i - 1];
    }

    cin >> q;
    while (q--) {
        cin >> x;
        cout << lower_bound(v.begin() + 1, v.end(), x) - v.begin() << '\n';
    }
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>
using namespace std;

int n, arr[1000003], i, x = 1, m, t;

int main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> t;
        while (t--) arr[x] = i, x++;
    }
    cin >> m;
    while (m--) cin >> t, cout << arr[t] << endl;
}
```

Well, dia justru membangun semua deret array dari $1$ hingga sangat besar 😅. Jadi nilai yang disimpan didalam $arr$ akan berisi $1,2,3,4,5,6,7,8,\dots$, dan seterusnya. Jadi boros penggunaan memory! 

Tapi kode ini lebih singkat dan simple juga. Tidak masalah kita jadikan pembelajaran.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s[100228] = {
        0
    }, m, a;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    cin >> m;
    while (m--) {
        cin >> a;
        cout << lower_bound(s, s + n, a) - s << '\n';
    }
    return 0;
}
```

Solusi ini mirip dengan solusi ketiga, akan aku jelaskan disana sekalian!
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

#define IOS() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
#define fir first
#define se second
#define pb(x) push_back(x)
#define pii pair < int, int >
#define all(a)(a).begin(), (a).end()
#define mp(a, b) make_pair(a, b)
using namespace std;
int lowbit(int x) {
    return x & -x;
}
inline int rd() {
    int f = 0;
    int x = 0;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
    if (f) x = -x;
    return x;
}
bool cmp(int x, int y) {
    return x > y;
}
int a[100005];
signed main() {
    //freopen("文件名.in","r",stdin);
    //freopen("文件名.out","w",stdout);
    IOS();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i - 1];
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << lower_bound(a + 1, a + n + 1, x) - a << "\n";
    }
    return 0;
}
```

Ini adalah jawaban dari seorang Red Coder. Ternyata, kita bisa membangunn array $b$ langsung dengan ukuran yang sama dengan $a$. Itu karena kita hanya menyimpan nilai prefix sumnya saja. 

Lalu, pencarian `lower_bound()` juga bisa dilakukan langsung, mengingat ukuran array $b$ sama dengan $a$, sehingga tidak perlu dibagi dengan $2$ seperti implementasiku.

Oleh karena itu, aku memperbarui jawabanku, lihat bagian analisis.