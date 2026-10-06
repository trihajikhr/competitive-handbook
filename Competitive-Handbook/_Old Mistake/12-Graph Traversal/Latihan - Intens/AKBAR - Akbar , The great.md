---
obsidianUIMode: preview
note_type: latihan
latihan: AKBAR - Akbar , The great
sumber:
  - spoj.com
tags:
  - graphs
  - graph-BFS
  - graph-DFS
date_learned: 2026-03-15T23:44:00
---
Link Sumber: [SPOJ - AKBAR - Akbar , The great](https://www.spoj.com/problems/AKBAR/)

---
> [!IMPORTANT]
# AKBAR - Akbar , The great

Kita semua akrab dengan masa pemerintahan penguasa Mughal yang agung, Akbar. Ia selalu peduli dengan kemakmuran dan keamanan rakyatnya. Oleh karena itu, untuk menjaga kerajaannya (yang terdiri dari $N$ kota), ia ingin menempatkan prajurit rahasia di seluruh kerajaannya demi melindungi rakyat. Namun, karena kerajaannya sangat luas, ia ingin menempatkan mereka sedemikian rupa sehingga setiap kota dilindungi oleh **satu dan hanya satu** prajurit. Menurut Akbar, ini adalah penempatan yang optimum.

Adapun para prajurit ini dapat melindungi banyak kota sesuai dengan kekuatan mereka. Kekuatan seorang prajurit tertentu didefinisikan sebagai jarak maksimum di mana seorang penjaga dapat melindungi sebuah kota dari kota asalnya (kota asal adalah kota yang ditugaskan kepada penjaga tersebut). Jika terdapat 3 kota $C1$, $C2$, dan $C3$ sedemikian rupa sehingga $C1$-$C2$ dan $C2$-$C3$ terhubung secara berurutan, jika seorang prajurit dengan kekuatan 1 ditempatkan di $C2$, maka semua kota $C1$, $C2$, dan $C3$ dilindungi oleh prajurit tersebut.

Selain itu, kerajaan ini terhubung dengan jaringan jalan rahasia dua arah untuk akses yang lebih cepat yang hanya dapat diakses oleh para prajurit ini. Panjang setiap jalan pada jaringan ini antara dua kota mana pun adalah 1 km. Terdapat $R$ jalan seperti itu di dalam kerajaan.

Ia telah memberikan tugas ini kepada Birbal untuk menempatkan para prajurit. Birbal tidak ingin terlihat bodoh di depan raja, oleh karena itu ia menerima pekerjaan tersebut dan menempatkan $M$ prajurit di seluruh kerajaan, tetapi ia tidak terlalu mahir dalam matematika. Namun karena ia sangat cerdas, ia entah bagaimana berhasil menempatkan para penjaga di seluruh kerajaan dan sekarang beralih kepada Anda (seorang matematikawan jenius ;) ) untuk memeriksa apakah penempatannya sudah baik atau belum.

Tugas Anda adalah memeriksa apakah penempatan prajurit tersebut optimum atau tidak.

### Input

Masukan terdiri dari $T$ _test case_. Setiap _test case_ kemudian terdiri dari 3 bagian:

1. Baris pertama terdiri dari $N$, $R$, dan $M$.
    
2. $R$ baris berikutnya terdiri dari dua angka $A$ dan $B$ yang menunjukkan dua kota di mana terdapat jalan di antaranya.
    
3. $M$ baris berikutnya terdiri dari 2 angka, nomor kota $K$ dan kekuatan $S$ dari prajurit tersebut.
    

- Kekuatan 0 berarti ia hanya akan menjaga kota tempat ia berada.
    
- Asumsikan setiap kota dapat diakses dari setiap kota lainnya.
    

### Constraints

- $T \le 10$
    
- $1 \le N \le 10^6$
    
- $N - 1 \le R \le \min(10^7, (N \times (N - 1)) / 2)$
    
- $1 \le K \le N$
    
- $0 \le S \le 10^6$
    

### Output

Cetak `Yes` jika prajurit ditempatkan secara optimum, jika tidak cetak `No`.

### Example

**Input:**


```
2
3 2 2
1 2
2 3
1 2
2 0
4 5 2
1 4
1 2
1 3
4 2
3 4
2 1
3 0
```

**Output:**

```
No
Yes
```


<br/>

---
## Jawaban

```cpp
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int n, r, m;
    cin >> n >> r >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<pair<int, int>> army(m);
    for (int i = 0; i < m; i++) {
        cin >> army[i].first >> army[i].second;
        army[i].first--;
    }

    vector<pair<bool, int>> visited(n, {false, 0});
    queue<pair<int, int>> que;

    for (int i = 0; i < m; i++) {
        if (visited[army[i].first].first) {
            cout << "No\n";
            return;
        }

        visited[army[i].first] = {true, army[i].first};
        que.push(army[i]);

        while (!que.empty()) {
            int u = que.front().first;
            int sisa = que.front().second;
            que.pop();

            if (sisa <= 0) {
                continue;
            }

            for (auto v : graph[u]) {
                if (!visited[v].first) {
                    visited[v] = {true, army[i].first};
                    que.push({v, sisa - 1});
                } else if (visited[v].second == army[i].first) {
                    continue;
                } else {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i].first) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```

Versi yang dioptimalkan:

```cpp
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void solve() {
    int n, r, m;
    cin >> n >> r >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < r; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<pair<bool, int>> visited(n, {false, -1});
    queue<pair<int, int>> que;

    for (int i = 0; i < m; i++) {
        int k, s;
        cin >> k >> s;
        k--;

        if (visited[k].first) {
            cout << "No\n";
            return;
        }

        que.push({k, s});
        visited[k] = {true, k};

        while (!que.empty()) {
            int u = que.front().first;
            int sis = que.front().second;
            que.pop();

            if (sis <= 0) {
                continue;
            }

            for (int v : graph[u]) {
                if (!visited[v].first) {
                    visited[v] = {true, k};
                    que.push({v, sis - 1});
                } else if (visited[v].second == k) {
                    continue;
                } else {
                    cout << "No\n";
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i].first) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```


<br/>

---
## Editorial