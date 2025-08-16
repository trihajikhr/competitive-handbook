---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 11TH-BGRP-AL02
nama_algoritma: adjacency list
kategori_algoritma: graph algorithm
kesulitan: 🥈 medium
time_complexity: 
memory_complexity: 
sumber:
  - "buku: CP handbook by Antti Laaksonen"
  - chatgpt.com
date_learned: 2025-04-26T21:33:00
tags:
  - graph-algorithm
  - graph-basic
---
---
# 1 | Praktik Adjacency List

Untuk implementasi standar, versi pertama graph dengan menggunakan Adjacency List, kita bisa menggunakan cara berikut:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // n = jumlah node, m = jumlah edge

    vector<vector<int>> adj(n + 1); // adjacency list, asumsi node dari 1..n

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // jika graph tidak berarah, tambahkan ini
    }

    // contoh menampilkan adjacency list
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
```

Jika kamu bertanya-tanya, kenapa nilai `n` harus ditambahkan dengan 1, ada penjelasan yang masuk akal dibawah ini.

Aku tahu, pasti hal ini sedikit aneh, mengingat melihat loop saat menampilkan graph, kita memulai loop dari index `1`, melewatkan index ke-`0`.

---
# 2 | Graph dengan Adjacency List (Index 0-based vs 1-based)

## 2.1 | Menggunakan `adj(n)`

- **Vector size:** `n`
    
- **Node ke-i** disimpan di **`adj[i-1]`**
    
- Saat membaca input (yang biasanya 1-based), perlu **dikurangi 1**:
    
    ```cpp
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u); // jika undirected
    ```
    
- Saat mencetak, **ditambah 1** supaya tampil 1-based:
    
    ```cpp
    for (int i = 0; i < n; i++) {
        cout << "Node " << i+1 << ": ";
        for (int v : adj[i]) {
            cout << v+1 << " ";
        }
        cout << endl;
    }
    ```
    


## 2.2 |  Menggunakan `adj(n+1)`

- **Vector size:** `n+1`
    
- **Node ke-i** disimpan di **`adj[i]`**
    
- Tidak perlu mengubah input.
    
- Langsung saja saat membaca input:
    
    ```cpp
    adj[u].push_back(v);
    adj[v].push_back(u); // jika undirected
    ```
    
- Saat mencetak:
    
    ```cpp
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    ```
    

## 2.3 | Kesimpulan:

|Pilihan|Keterangan|
|---|---|
|`adj(n)`|Perlu `-1` saat input, `+1` saat output|
|`adj(n+1)`|Lebih simpel, tidak perlu ubah input/output|
|`adj[0]`|Di `adj(n+1)`, `adj[0]` dibiarkan kosong|

**Tips:**  
✅ Kalau ingin kode lebih cepat dan bersih untuk kompetisi, lebih aman pakai `adj(n+1)`!  
✅ Tapi untuk hemat memori saat node besar sekali, kadang `adj(n)` lebih efisien.
