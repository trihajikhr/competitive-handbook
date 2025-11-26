---
obsidianUIMode: preview
note_type: problem set
id_problem: "386"
judul_problem: Lexicographical Numbers
sumber: leetcode.com
kategori_problem: 🥇 contest
kesulitan: 🥈 medium
time_complexity: 🟠 O(n)
memory_complexity: 🟢 O(1)
status: 🏆 solved
date_solved: 2025-05-05T12:37:00
pendekatan: 
tags:
  - depth-first-search
  - Trie
---
Link problem: [Lexicographical Numbers - LeetCode](https://leetcode.com/problems/lexicographical-numbers/description/)

#depth-first-search #Trie 

---
# Lexicographical Numbers
Time limit: -
Memory limit: -


Diberikan sebuah bilangan bulat `n`, kembalikan semua angka dalam rentang `[1, n]` yang **diurutkan secara leksikografis** (seperti urutan dalam kamus).

Kamu **harus** menulis algoritma yang berjalan dalam **kompleksitas waktu O(n)** dan menggunakan **O(1) ruang tambahan** _(tidak termasuk ruang untuk menyimpan hasil output)_.

### Contoh 1:

Input: `n = 13`  
Output: `[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]`

### Contoh 2:

Input: `n = 2`  
Output: `[1, 2]`

### 🔒 Batasan:

- `1 <= n <= 5 * 10⁴`
    

# Jawaban
Jawaban ini sudah cukup efektif, beats 100% user untuk runtime, dan beats 93,95% user untuk Memory:

```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int cur = 1;

        for(int i = 0; i < n; i++) {
            result[i] = cur;

            if(cur * 10 <= n) {
                cur *= 10;
            } else {
                if(cur >= n) {
                    cur /= 10;
                }
                cur++;
                while(cur % 10 == 0) {
                    cur /= 10;
                }
            }
        }

        return result;
    }
};
```

Time complexity: $O(n)$
Memory complexity: $O(1)$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 

## 🎯 Tujuan Masalah:

Diberi integer `n`, kamu diminta untuk menghasilkan angka dari `1` hingga `n` dalam **urutan leksikografis** (seperti dictionary).  
Contoh:

```text
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
```

---

## ✅ Kode Lengkap

```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int cur = 1;

        for(int i = 0; i < n; i++) {
            result[i] = cur;

            if(cur * 10 <= n) {
                cur *= 10;
            } else {
                if(cur >= n) {
                    cur /= 10;
                }
                cur++;
                while(cur % 10 == 0) {
                    cur /= 10;
                }
            }
        }

        return result;
    }
};
```

---

## 🧠 Intuisi Solusi:

Kita ingin membentuk angka dalam urutan leksikografis **tanpa mengubah semua angka ke string dan melakukan sorting**, karena itu mahal (`O(n log n)` dan `O(n log k)` space).

Jadi, pendekatannya adalah **menggunakan DFS secara iteratif**:

- Bayangkan angka-angka sebagai tree:
    
    ```
    1
    ├─ 10
    │  ├─ 100
    │  └─ ...
    ├─ 11
    ├─ 12
    └─ ...
    2
    ├─ 20
    └─ ...
    ```
    
- DFS pada tree ini akan menghasilkan urutan leksikografis.
    

---

## 🧩 Penjelasan Baris per Baris

```cpp
vector<int> result(n);
```

- Membuat array dengan ukuran `n` untuk menyimpan hasil akhir.
    
- Kita akan mengisi `result[i]` dari `0` ke `n-1`.
    

---

```cpp
int cur = 1;
```

- Kita mulai dari angka 1, karena itulah angka pertama dalam urutan leksikografis.
    
- `cur` akan menjadi angka yang sedang kita kunjungi di “tree”.
    

---

```cpp
for(int i = 0; i < n; i++)
```

- Kita akan menambahkan tepat `n` angka ke dalam `result`, jadi loop ini berjalan `n` kali.
    

---

```cpp
result[i] = cur;
```

- Menyimpan angka saat ini (`cur`) ke dalam hasil.
    

---

```cpp
if (cur * 10 <= n)
```

- Cek apakah kita bisa turun ke child node dalam "tree".
    
- Contoh: dari 1 ke 10, dari 10 ke 100, dst.
    
- Kalau bisa, kita eksplorasi lebih dalam dulu (karena DFS).
    

---

```cpp
cur *= 10;
```

- Pergi ke anak pertama dari current number.
    
- Misalnya: dari 1 → 10, 2 → 20, dst.
    

---

```cpp
else { if (cur >= n) { cur /= 10; } }
```

- Jika `cur` melebihi `n`, kita sudah sampai terlalu jauh.
    
- Kita naik (backtrack) ke parent-nya.
    
- Misalnya: jika cur = 13 dan n = 13, cur++ → 14 > 13, kita harus naik ke 1 → 1, lalu ke 2.
    

---

```cpp
cur++;
```

- Setelah mengeksplor anak-anak dari `cur`, kita lanjut ke "sibling" berikutnya.
    
- Misalnya setelah 1 → 10, 11, 12, 13, kita lanjut ke 2.
    

---

```cpp
while (cur % 10 == 0) cur /= 10;
```

- Ini bagian penting: menghindari angka seperti 20, 30, 40... yang tidak valid (karena bisa melewati angka n).
    
- Kita naik ke atas di tree sampai kita menemukan node yang bisa kita teruskan jelajahi (next sibling).
    
- Contoh:
    
    - cur = 19, cur++ → 20
        
    - 20 % 10 == 0 → naik → 2
        
    - cur = 2 → bisa lanjut lagi
        

---

## 💡 Kenapa Ini Lebih Efisien?

- Hanya melakukan **O(n)** operasi — tidak perlu konversi string atau sort.
    
- Sifat tree traversal-nya (DFS) sangat efisien untuk urutan leksikografis.
    

---

## 📈 Kompleksitas:

- **Waktu:** `O(n)` — karena kita kunjungi tiap angka dari 1 ke n tepat sekali.
    
- **Space:** `O(n)` — untuk menyimpan hasil dalam vector.
    

---

## 🧪 Contoh Langkah Eksekusi (n = 13):

```
cur = 1 → simpan → cur = 10 → simpan
cur = 11 → simpan
cur = 12 → simpan
cur = 13 → simpan
cur = 14 (too big) → naik → cur = 1 → cur++ → 2 → simpan
... sampai cur = 9
```

---

## ✅ Ringkasan Fungsi:

|Bagian Kode|Fungsi|
|---|---|
|`vector<int> result(n)`|Menyimpan hasil akhir|
|`cur = 1`|Awal traversal dari angka 1|
|`if (cur * 10 <= n)`|Turun ke anak (DFS) jika masih dalam batas|
|`else` blok|Naik/backtrack lalu lanjut ke sibling berikutnya|
|`while(cur % 10 == 0)`|Hindari angka-angka seperti 20, 30 (backtrack)|
## Contoh Input output
Input:
```
13
```

Output:
```
[1,10,11,12,13,2,3,4,5,6,7,8,9]
```
# Informasi tambahan
Versi lengkap untuk latihan:

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> lexicalOrder(int n) {
            vector<int> result(n);
            int cur = 1;
    
            for(int i = 0; i < n; i++) {
                result[i] = cur;
    
                if(cur * 10 <= n) {
                    cur *= 10;
                } else {
                    if(cur >= n) {
                        cur /= 10;
                    }
                    cur++;
                    while(cur % 10 == 0) {
                        cur /= 10;
                    }
                }
            }
    
            return result;
        }
};
    
int main() {
    int n;
    cin >> n;

    Solution solusi;
    vector<int> rest = solusi.lexicalOrder(n);

    for(auto&x:rest){
        cout << x << " ";
    }
    return 0;
}
```