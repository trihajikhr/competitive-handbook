---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 
nama_algoritma: 
kategori_algoritma: 
kesulitan: 🥉 easy 🥈 medium 🥇 hard
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
sumber: 
date_learned: 
tags:
---
#tag #tag #tag 

---
# Loop Untuk Menampilakan Semua Tetangga Node
Oke, aku ngerti! 🔥  
Kamu mau aku bantu buatkan **implementasi lengkap** dari potongan teori Antti Laaksonen tadi, kan?

Langsung aku buatkan ya — **simple graph** pakai **adjacency list**, lalu ada loop `for (auto u : adj[s])` untuk menelusuri tetangganya.

---

### 📜 Implementasi C++:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // adjacency list, 1-based index

    // Input edge
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v); 
        adj[v].push_back(u); // karena graph tidak berarah
    }

    // Contoh: Menampilkan semua node yang bisa dicapai dari node s
    int s;
    cout << "Masukkan node s: ";
    cin >> s;

    cout << "Node yang bisa dicapai dari node " << s << " adalah: ";
    for (auto u : adj[s]) {
        cout << u << " ";
    }
    cout << endl;

    return 0;
}
```

---

### 📚 Penjelasan kode:

- **`vector<vector<int>> adj(n+1)`**  
    Membuat adjacency list dengan 1-based index.
    
- **Input edge**  
    Setiap kali baca `u v`, berarti `u` berteman dengan `v`, dan `v` berteman dengan `u`.
    
- **Loop `for (auto u : adj[s])`**  
    Menelusuri semua node yang bisa langsung dicapai dari node `s`.
    

---

### 📥 Contoh Input:

```
5 4
1 2
1 3
2 4
2 5
2
```

(Artinya: 5 node, 4 edge. Lalu kita ingin tahu node yang bisa dicapai dari node `2`.)

### 📤 Output:

```
Masukkan node s: 2
Node yang bisa dicapai dari node 2 adalah: 1 4 5
```
