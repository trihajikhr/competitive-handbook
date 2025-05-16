---
obsidianUIMode: preview
note_type: problem set
id_problem: "387"
judul_problem: First Unique Character in a String
sumber: leetcode.com
kategori_problem: 🥇 contest
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
status: 🏆 solved
date_solved: 2025-05-05T14:21:00
pendekatan: 
tags:
  - hash-table
  - string
  - queue
  - counting
---
Link problem: [First Unique Character in a String - LeetCode](https://leetcode.com/problems/first-unique-character-in-a-string/description/)

#hash-table #string #queue #counting

---
# First Unique Character in a String
Time limit: -
Memory limit: -


Diberikan sebuah string `s`, temukan **karakter pertama yang tidak berulang** (hanya muncul satu kali) dalam string tersebut, dan kembalikan **indeksnya**.  
Jika tidak ada karakter seperti itu, kembalikan `-1`.

---
### Contoh 1:

**Input:** `s = "leetcode"`  
**Output:** `0`  
**Penjelasan:**  
Karakter `'l'` pada indeks ke-0 adalah karakter pertama yang tidak muncul lagi di indeks manapun.

---

### Contoh 2:

**Input:** `s = "loveleetcode"`  
**Output:** `2`  
**Penjelasan:**  
Karakter `'v'` adalah yang pertama kali muncul dan tidak berulang.

---

### Contoh 3:

**Input:** `s = "aabb"`  
**Output:** `-1`  
**Penjelasan:**  
Semua karakter muncul lebih dari satu kali, jadi tidak ada karakter unik.

---
## 🔒 Batasan:

- `1 <= s.length <= 10⁵`
    
- `s` hanya terdiri dari huruf kecil alfabet bahasa Inggris (`'a'` hingga `'z'`)
    

# Jawaban
Jawaban dengan runtime yang cukup solid:

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']==1) return i;
        }
        return -1;
    }
};
```

Time complexity: $O()$
Memory complexity: $O()$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 
Berikut adalah **editorial lengkap** untuk setiap baris kode dari solusi berikut — fungsinya untuk mencari **indeks karakter pertama yang tidak berulang** dalam string `s`:

---

## 🧠 Intuisi:

- Karena `s` hanya berisi huruf kecil ('a'–'z'), kita bisa memakai **array frekuensi ukuran 26**.
    
- Hitung dulu berapa kali tiap huruf muncul.
    
- Lalu, **iterasi ulang** string dan cari huruf pertama dengan frekuensi `1`.
    

---

### 📦 Kode & Penjelasan Baris per Baris:

```cpp
class Solution {
```

🔹 Mendefinisikan class `Solution`, sesuai format LeetCode.  
🔹 Semua fungsi akan berada di dalam class ini.

---

```cpp
public:
```

🔹 Bagian ini menjadikan fungsi di bawahnya **dapat diakses secara publik**, termasuk oleh LeetCode saat menjalankan pengujian.

---

```cpp
int firstUniqChar(string s) {
```

🔹 Fungsi utama `firstUniqChar` menerima sebuah **string `s`**  
🔹 Mengembalikan **indeks (int)** dari karakter pertama yang tidak berulang. Jika tidak ada, mengembalikan `-1`.

---

```cpp
vector<int> freq(26, 0);
```

🔹 Membuat vektor `freq` dengan ukuran 26 (jumlah huruf kecil alfabet)  
🔹 Diinisialisasi dengan `0`.  
🔹 `freq[i]` menyimpan jumlah kemunculan huruf ke-`i`, di mana:  
  - `'a'` → index 0  
  - `'b'` → index 1  
  - ...  
  - `'z'` → index 25

---

```cpp
for(int i = 0; i < s.length(); i++) {
    freq[s[i] - 'a']++;
}
```

🔹 Loop untuk menghitung frekuensi setiap karakter.  
🔹 `s[i] - 'a'` mengubah karakter menjadi indeks. Contoh:  
  - `'c' - 'a'` = 2  
🔹 `freq[...]++` berarti: naikkan jumlah huruf tersebut sebanyak 1 kali.

---

```cpp
for(int i = 0; i < s.length(); i++) {
    if(freq[s[i] - 'a'] == 1) return i;
}
```

🔹 Loop kedua: mencari **karakter pertama yang hanya muncul sekali**.  
🔹 Jika ditemukan, langsung `return i` (indeksnya).  
🔹 Kenapa perlu loop kedua? Karena kita butuh **urutan kemunculan pertama**, bukan huruf mana saja yang unik.

---

```cpp
return -1;
```

🔹 Jika tidak ada karakter unik dalam string (semua berulang), kembalikan `-1` sebagai jawaban.

---

### ✅ Contoh:

Input: `"loveleetcode"`  
Langkah:

1. Hitung frekuensi:  
     `l:2, o:2, v:1, e:4, t:1, c:1, d:1`
    
2. Loop ke-2:  
     `l (2), o (2), v (1)` → ditemukan! return indeks `2`
    

# Informasi tambahan
Versi latihan dengan `main`:

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution{
   public:
        int firstUniqChar(string s){
            vector<int> freq(26, 0);

            for(int i=0;i<s.length();i++){
                freq[s[i]-'a']++;
            }

            for(int i=0;i<s.length();i++){
                if(freq[s[i]-'a']==1) return i;
            }
            return -1;
        }
};

int main() {
    Solution sol;
    string s; cin >> s;
    cout << sol.firstUniqChar(s) << "\n";
    return 0;
}
```