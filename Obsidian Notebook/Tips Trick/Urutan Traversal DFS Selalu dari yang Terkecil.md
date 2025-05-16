---
obsidianUIMode: preview
note_type: tips trick
tips_trick: DFS Traversal
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
tags:
  - graph
  - graph-traversal
  - depth-first-search
  - breadth-first-search
---
#graph #graph-traversal #depth-first-search #breadth-first-search 

---
# Urutan Traversal DFS Selalu dari yang Terkecil
Tentu! Ini dia materi tentang **DFS dengan urutan terkecil** — sangat berguna dalam **soal-soal competitive programming** yang meminta traversal terurut.

## 🎯 Tujuan:

Menjalankan **DFS traversal** sehingga simpul yang dikunjungi **selalu dari simpul bernomor terkecil terlebih dahulu**, jika ada beberapa pilihan.

## 🔍 Masalah Umum di DFS:

Secara default, `DFS` hanya mengikuti urutan **penyimpanan tetangga di adjacency list**, yang bisa **acak** tergantung urutan input.

Contoh:

```cpp
0 1
0 2
```

atau

```cpp
0 2
0 1
```

Keduanya mewakili edge yang sama, tapi hasil DFS bisa beda jika kamu tidak **urutkan** tetangganya dulu.

## ✅ Solusi: Sort Adjacency List

Tambahkan sorting sebelum memanggil DFS:

### 💡 Cara 1: Sorting Sekali di `main`

```cpp
for (auto &neighbors : adj)
    sort(neighbors.begin(), neighbors.end());
```

Ini akan memastikan semua daftar tetangga diurutkan dari kecil ke besar sebelum DFS dimulai.

---

## 🧠 Penjelasan Singkat

DFS bekerja seperti ini:

```cpp
for (int i : adj[s])
    if (!visited[i])
        dfsRec(...);
```

Kalau `adj[s]` berisi: `{2, 0, 1}` → maka DFS bisa ke `2` dulu, bukan ke `0`.

Tapi kalau kamu **sort** jadi `{0, 1, 2}` → DFS akan selalu ke simpul yang kecil dulu.

---

## 🧪 Contoh Kode Lengkap

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res) {
    visited[s] = true;
    res.push_back(s);
    for (int i : adj[s]) {
        if (!visited[i])
            dfsRec(adj, visited, i, res);
    }
}

vector<int> DFS(vector<vector<int>> &adj) {
    for (auto &neighbors : adj)  // Urutkan semua tetangga dari kecil ke besar
        sort(neighbors.begin(), neighbors.end());

    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
    return res;
}

void addEdge(vector<vector<int>> &adj, int s, int t) {
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    vector<int> res = DFS(adj);
    for (int i : res)
        cout << i << " ";
    return 0;
}
```

---

## 🧪 Contoh Input

```
7 8
0 1
0 2
0 4
4 5
2 5
1 3
1 6
3 6
```

### 🔄 Output setelah sort adjacency list:

```
0 1 3 6 2 5 4
```

DFS dari 0 → ke 1 → ke 3 → ke 6 → lalu 2 → 5 → 4 (urutan selalu simpul terkecil dahulu).

---

## 📝 Kesimpulan

- Urutan DFS **tidak dijamin** kalau adjacency list tidak diurutkan.
    
- Dengan `sort(adj[i].begin(), adj[i].end())`, kita pastikan DFS selalu ke simpul **bernomor kecil dahulu**.
    
- Ini penting untuk hasil konsisten atau sesuai permintaan soal.
    

# Urutan Traversal BFS Selalu dari yang Terkecil


> [!NOTE] FAQ:
> Hei, apakah dalam BFS cara ini juga berlaku? Maksudku, apakah dalam BFS, urutan inputan yang berbeda menmbuat output juga berbeda, sehingga jika ingin urut, harus dilakukan hal seperti ini?

Ya, **benar sekali!** Dalam **BFS (Breadth-First Search)**, **urutan input edge juga memengaruhi output traversal**, **jika kamu tidak mengurutkan adjacency list**.

---

## 📌 Mengapa Urutan Penting di BFS?

### 🔍 Contoh Sederhana:

```cpp
4 3
0 2
0 1
1 3
```

- BFS dari `0`:
    
    - Tanpa sorting: tetangga `0` bisa `[2, 1]` → hasil BFS bisa: `0 2 1 3`
        
    - Dengan sorting: tetangga `0` jadi `[1, 2]` → hasil BFS: `0 1 2 3`
        

➡️ **Jadi, YA — urutan input edge memengaruhi urutan traversal dalam BFS.**

---

## ✅ Solusi: **Sorting adjacency list** sebelum traversal

Sama seperti di DFS, kamu cukup lakukan ini **sebelum BFS dimulai**:

```cpp
for (auto &neighbors : adj)
    sort(neighbors.begin(), neighbors.end());
```

---

## 🧠 Penjelasan

BFS menggunakan **queue** untuk menjelajahi simpul secara level-order:

```cpp
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            q.push(v);
        }
    }
}
```

- Jika `adj[u]` tidak terurut, maka urutan simpul yang masuk ke `q` bisa acak.
    
- Kalau terurut → simpul terkecil akan dimasukkan ke antrian dulu → hasil BFS lebih rapi dan sesuai permintaan soal.
    

---

## ✨ Kesimpulan

|Traversal|Pengaruh urutan input edge?|Perlu sort adjacency list?|
|---|---|---|
|DFS|Ya|Ya (jika ingin urutan terkecil)|
|BFS|Ya|Ya (jika ingin urutan terkecil)|


