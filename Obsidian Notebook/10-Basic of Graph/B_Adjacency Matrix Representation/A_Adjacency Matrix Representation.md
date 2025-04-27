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
# Adjacency Matrix Representation
Sebuah **_adjacency matrix_** adalah array dua dimensi yang menunjukkan _edges_ yang ada dalam graf. Dengan _adjacency matrix_, kita dapat dengan efisien memeriksa apakah terdapat _edge_ antara dua node.

Matriks ini dapat disimpan sebagai sebuah array:

```cpp
int adj[N][N];
```

Setiap nilai adj  menunjukkan apakah terdapat _edge_ dari node  ke node . Jika _edge_ tersebut ada dalam graf, maka adj , dan jika tidak ada, maka adj .

Sebagai contoh, graf berikut:

![[A_Adjacency Matrix Representation-1.png]]

dapat direpresentasikan sebagai berikut:

|       | 1   | 2   | 3   | 4   |
| ----- | --- | --- | --- | --- |
| **1** | 0   | 1   | 0   | 0   |
| **2** | 0   | 0   | 1   | 1   |
| **3** | 0   | 0   | 0   | 2   |
| **4** | 1   | 0   | 0   | 0   |
Jika graf memiliki _weight_, representasi _adjacency matrix_ dapat diperluas sehingga matriks menyimpan _weight_ dari _edge_ jika _edge_ tersebut ada.

Dengan menggunakan representasi ini, graf berikut:

![[A_Adjacency Matrix Representation-2.png]]

Sesuai dengan matriks berikut:

|       | 1   | 2   | 3   | 4   |
| ----- | --- | --- | --- | --- |
| **1** | 0   | 5   | 0   | 0   |
| **2** | 0   | 0   | 7   | 6   |
| **3** | 0   | 0   | 0   | 5   |
| **4** | 3   | 0   | 0   | 0   |
Kelemahan dari representasi _adjacency matrix_ adalah matriks tersebut memiliki  elemen, dan biasanya sebagian besar bernilai nol. Oleh karena itu, representasi ini tidak dapat digunakan jika graf berukuran besar.