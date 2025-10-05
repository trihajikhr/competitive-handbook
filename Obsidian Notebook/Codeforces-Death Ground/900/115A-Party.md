---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 115A
judul_DEATH: Party
teori_DEATH: penggunaan tree bisa menggunakan graph dengan beberapa syarat
sumber:
  - codeforces.com
ada_tips?: true
date_learned: 2025-10-05T16:08:00
tags:
---
Sumber: [Problem - 115A - Codeforces](https://codeforces.com/problemset/problem/115/A)

```ad-tip
title:⚔️ Teori Death Ground
Aku sebelumnya berpikir bahwa ketika ingin mengimplementasikan graph, maka aku harus menggunakan pointer dan algoritma yang berbeda jauh dengan algoritma graph, tapi ternyata salah!

Implementasi tree, ternyata bisa menggunakan cara yang mirip dengan graph, hanya saja dengan beberapa ketentuan sebagai berikut:
- Graph tersebut berarah.
- Tidak ada cycle
```

<br/>

---
# 1 | 115A-Party

Kita diminta untuk mencari berapa banyak kelompok maksimal yang harus dibentuk, agar semua karyawan mampu berkumpul dengan karyawan lain yang levelnya sama dengan mereka, atau tidak ada $A$ yang menjadi senior dari $B$ di kelompok yang sama.

Solusi ini mudah, karena menerapkan penggunaan struktur tree dasar.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Jika ada rantai senioritas sebagai berikut: $A \rightarrow B \rightarrow C \rightarrow D \rightarrow E$, maka kita bisa mengambil kesimpulan bahwa harus dibentuk 5 kelompok agar setiap orang bisa berkumpul di kelompok tanpa ada senior mereka di kelompok yang sama.

Artinya adalah, kita diminta untuk mencari kedalaman maksimal dari tree yang diberikan oleh inputan!

Di soal disebutkan bahwa akan ada karyawan yang tidak memiliki senior sama sekali, dituliskan dengan $-1$. Kita bisa mengartikan ini sebagai root dari tree. Dan jika ada beberapa root, maka akan ada beberapa tree, atau *forest*.

Artinya kita juga perlu mencatat siapa saja karyawan yang menjadi root dari tree pada vector terpisah, dan melakukan perulangan dari setiap root tadi, untuk mencari tree mana yang memiliki kedalaman terdalam.

```ad-warning
Pelajari algoritham graph dan tree untuk memahami penjelasan ini dengan mudah!
```

Step pertama adalah membangun tree berdasarkan inputan, lalu melakukan pencarian secara DFS (*depth-first-search*).

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

using VVI = vector<vector<int>>;
using VI = vector<int>;

void dfs(const VVI& tree, int now, int& rest, int depth=1) {
    rest = max(rest, depth);
    for (const auto& next : tree[now]) {
        dfs(tree, next, rest, depth+1);
    }
}

auto maxDepth(const VVI& tree, const VI& root) -> int {
    int ans = 0;
    for (const auto& node : root) {
        dfs(tree, node, ans);
    }
    return ans;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> tree (n+1);
    vector<int> root;
    for (int i=1, x; i <= n; i++) {
        cin >> x;
        if (x != -1) tree[x].push_back(i);
        else root.push_back(i);
    }

    int ans = maxDepth(tree, root);
    cout << ans;
    return 0;
}
```



<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Kami membiarkan seorang karyawan tanpa manajer disebut sebagai **akar (root)**. Ada sisi (edge) dari seorang manajer ke seorang karyawan yang ia kelola/manajeri.

Perhatikan pertama bahwa graf (graph) adalah kumpulan dari **pohon berarah (directed trees)**. Oleh karena itu, kita dapat memberikan label kedalaman (**depth label**) ke setiap simpul (node) — yang menunjukkan jumlah simpul pada jalur sederhana (**simple path**) dari akar ke simpul tersebut. Jawabannya kemudian adalah **kedalaman maksimum** yang dimiliki sebuah simpul.

Mengapa?

Pertama, jawabannya **dibatasi di bawah** (bounded below) oleh angka ini karena pasangan karyawan mana pun dalam jalur ini tidak boleh berada dalam kelompok yang sama. Kedua, karena graf tersebut adalah pohon, setiap simpul dalam graf memiliki label kedalaman unik yang ditetapkan untuknya. Cukup masukkan semua simpul dengan kedalaman yang sama ke dalam kelompok yang sama. Cukup mudah untuk melihat bahwa tidak ada seorang pun yang akan menjadi atasan dari yang lain dalam satu kelompok, karena jika tidak, kedalaman mereka tidak akan sama.
### Catatan (Remark)

Anda mungkin memperhatikan bahwa ada implementasi **$O(N)$** dari algoritma di atas, namun batasannya adalah 2000. Nah, masalah ini ditukar dengan D1-B karena D1-A sebelumnya dianggap lebih sulit dari yang diperkirakan. Oleh karena itu, dalam prosesnya, kami juga mengurangi batasan untuk N dari 200.000 menjadi 2.000. Saya harap Anda menyukainya :)

## 3.2 | Analisis Pribadi


## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<iostream>

int main() {
    int n, m = 0, k, i = 1, c, a[2002];
    for (std::cin >> n; i <= n;)
        std::cin >> a[i++];
    for (i = 1; i <= n;) {
        k = a[i++], c = 0;
        while (k > 0)
            k = a[k], c++;
        m = c > m ? c : m;
    }
    std::cout << m + 1;
}
```

Program tersebut membaca sebuah pohon yang direpresentasikan dalam bentuk array parent, di mana $a[i]$ menyatakan parent dari simpul $i$ dan nilai $\leq 0$ menandakan bahwa simpul tersebut adalah akar. Setelah data dimasukkan, program menghitung kedalaman maksimum pohon dengan cara melacak setiap simpul ke atas hingga mencapai akar. Untuk setiap simpul $i$, variabel sementara $k$ menyimpan parent dari simpul tersebut, kemudian selama $k > 0$ program akan berpindah ke parent berikutnya ($k = a[k]$) sambil menambah penghitung kedalaman $c$. Nilai maksimum dari $c$ dicatat pada variabel $m$, dan pada akhirnya program mencetak $m+1$ karena kedalaman mencakup simpul awal itu sendiri.

Secara analisis kompleksitas, proses ini pada simpul ke-$i$ memerlukan paling banyak $O(h)$ langkah, dengan $h$ adalah tinggi pohon. Apabila pohon seimbang, maka $h \approx \log n$ sehingga total kompleksitas mendekati $O(n \log n)$. Namun, pada kasus terburuk ketika pohon berbentuk rantai dengan $h = n$, maka jumlah operasi yang dilakukan menjadi

$1 + 2 + 3 + \cdots + n = \frac{n(n+1)}{2} = O(n^2)$

Dari sisi ruang, hanya diperlukan sebuah array berukuran $O(n)$. Dengan demikian, meskipun implementasi ini sederhana, efisiensinya dapat menurun drastis pada pohon dengan struktur rantai panjang.

Atau bisa dibilang, walaupun terlihat simple, namun implementasi DFS kita masih jauh lebih efisien.

### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    int a[t + 1];
    int ans = 1;
    for (int i = 1; i <= t; ++i) cin >> a[i];
    for (int i = 1; i <= t; ++i) {
        int node = a[i];
        int dep = 1;
        while (node != -1) {
            node = a[node];
            dep++;
        }
        ans = max(ans, dep);
    }
    cout << ans;
}
```

Versi ini sebenarnya hampir mirip dengan cara pertama, tapi masih tidak efisien, karena kompleksitas $O(n^2)$ di kasus worst case. Hanya saja penulisan kode ini jauh lebih readable dan lebih rapi secara semantik.

### 3 | Jawaban Ketiga

```cpp
#include "bits/stdc++.h"

#ifdef DEBUG
// Test
// Answer for test && answer not_main

#endif

std::vector < int > d;
std::vector < std::vector < int >> g;

void dfs(int v, int p) {
    d[v] = p == -1 ? 1 : d[p] + 1;
    for (auto & i: g[v]) {
        if (i != p) {
            dfs(i, v);
        }
    }
}

void not_main() {
    int n;
    std::cin >> n;
    g.resize(n);
    std::vector < int > s;
    for (int i = 0; i < n; ++i) {
        int pi;
        std::cin >> pi;
        --pi;
        if (pi == -2) {
            s.emplace_back(i);
        } else {
            g[pi].emplace_back(i);
        }
    }
    d.resize(n);
    for (auto & i: s) {
        dfs(i, -1);
    }
    std::cout << * std::max_element(d.begin(), d.end());
}

#ifdef DEBUG

std::random_device rd;
std::mt19937 gen(rd());

#endif

signed main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    fflush(stdout);
    fflush(stdin);
    #ifdef DEBUG
    #else
    int tests = 1;
    //std::cin >> tests;
    while (tests--) {
        not_main();
    }
    #endif
    return 0;
}
```

Ini adalah jawaban tercepat berdasarkan waktu eksekusi (30 ms).

Kode ini menggunakan pendekatan DFS dengan adjacency list untuk menghitung kedalaman maksimum pohon. Setiap simpul disimpan dalam struktur `g`, lalu dilakukan DFS dari setiap akar yang terdeteksi. Pada saat traversal, kedalaman tiap simpul disimpan dalam array `d`, sehingga tidak hanya kedalaman maksimum yang bisa diperoleh, tetapi juga level masing-masing simpul. 

Kompleksitas waktu dari metode ini adalah $O(n)$ karena setiap simpul hanya dikunjungi sekali, sementara kompleksitas ruang juga $O(n)$ untuk menyimpan adjacency list dan array kedalaman. Pendekatan ini lebih fleksibel dibanding implementasi DFS sederhana karena dapat diperluas untuk menyelesaikan berbagai permasalahan lain di tree.