---
obsidianUIMode: preview
note_type: latihan
latihan: Copy–Paste Blok Tugas
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:46:00
---
---
Siap! Kita ke **Soal 13: Copy–Paste Blok Tugas**. Di sini kamu akan menggunakan beberapa fungsi `vector` tingkat lanjut seperti `insert(begin, first, last)` dan manipulasi sub‑range.

---

# 🧩 Soal 13: Copy–Paste Blok Tugas

### 📥 Input

1. Integer `n` — jumlah tugas awal (1 ≤ n ≤ 10⁵)
    
2. `n` baris berikutnya — nama tugas awal (string tanpa spasi)
    
3. Integer `q` — jumlah perintah (1 ≤ q ≤ 10⁵)
    
4. `q` baris perintah, masing‑masing format:
    
    - **`COPY i j`**  
        → Salin blok tugas dari posisi `i` sampai `j` (1‑based, inklusif) ke **clipboard**.  
        Abaikan jika `i < 1` atau `j > current_size` atau `i > j`.
        
    - **`PASTE k`**  
        → Tempel isi clipboard **sebelum** posisi `k` (1‑based).  
        Abaikan jika `k < 1` atau `k > current_size+1`, atau jika clipboard kosong.
        
    - **`SHOW`**  
        → Cetak seluruh daftar tugas sekarang, satu per baris (atau `"KOSONG"` jika kosong).
        

> **Catatan:** Clipboard menyimpan hasil `COPY` terakhir (menimpa yang sebelumnya), tapi tidak otomatis mem-paste.

---

### 📤 Output

Setiap kali menemui perintah `SHOW`, cetak daftar tugas saat ini dari indeks 1 sampai akhir, satu per baris. Jika kosong, cetak `"KOSONG"`.

---

### 🔍 Contoh

**Input:**

```
5
A
B
C
D
E
7
COPY 2 4
PASTE 6
SHOW
COPY 3 5
PASTE 1
SHOW
PASTE 100
```

**Output:**

```
A
B
C
D
B
C
D
E
C
D
E
A
B
C
D
B
C
D
E
```

**Penjelasan singkat:**

1. **COPY 2 4** → clipboard = `[B, C, D]`
    
2. **PASTE 6** → tempel sebelum pos 6 (yaitu di akhir): list → `[A B C D E | B C D]`
    
3. **SHOW** → cetak 8 elemen di atas
    
4. **COPY 3 5** → clipboard = `[C, D, E]`
    
5. **PASTE 1** → tempel sebelum pos 1: list → `[C D E, A B C D B C D E]`
    
6. **SHOW** → cetak 11 elemen
    
7. **PASTE 100** → invalid (abaikan)
    

---

### 🎯 Tujuan & Fungsi `vector` yang Dipakai

- **Clipboard**: `vector<string> clip;`
    
- **Copy range**:
    
    ```cpp
    clip.assign(tasks.begin() + (i-1),
                tasks.begin() + j);
    ```
    
- **Paste range**:
    
    ```cpp
    tasks.insert(tasks.begin() + (k-1),
                 clip.begin(), clip.end());
    ```
    
- **Validasi**:
    
    - `1 ≤ i ≤ j ≤ tasks.size()`
        
    - `1 ≤ k ≤ tasks.size()+1`
        
    - `!clip.empty()`
        

---

Silakan kerjakan, lalu kirim kodenya—aku akan bantu review dan kasih editorial lengkap! 🚀

## Jawaban Salah
Ini adalah kode yang salah, dan terdapat masalah pada logika:

```cpp
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> task(n);
    for(auto&x:task) cin >> x;

    vector<string> clip;

    int q; cin >> q;
    while(q--){
        string s;
        getline(cin >> ws, s);

        string cmd;
        stringstream ss(s);
        ss >> cmd;
        
        if(cmd=="COPY"){
            int i,j;
            ss >> i >> j;
            if(1 <=i <= j <= task.size()){
                clip.assign(task.begin() + (i+1), task.begin()+j);
            }
        } else if(cmd=="PASTE"){
            int k;
            ss >> k;
            if(1 <= k <=task.size()+1){
                task.insert(task.begin()+(k+1), clip.begin(), clip.end());
            }
        } else {
            if(task.empty()){
                cout << "KOSONG\n";
            } else {
                for(const auto&x:task){
                    cout << x << "\n";
                }
            }
        }
    }
    return 0;
}
```

### Jawaban benar
Berikut adalah jawaban yang benar, berdasarkan perbaikan dari editorial:

```cpp
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<string> task(n);
    for (auto &x : task) 
        cin >> x;

    vector<string> clip;
    int q; 
    cin >> q;
    string line;
    getline(cin, line);  

    while (q--) {
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "COPY") {
            int i, j;
            ss >> i >> j;
            if (1 <= i && i <= j && j <= (int)task.size()) {
                clip.assign(
                    task.begin() + (i - 1),
                    task.begin() + j
                );
            }
        }
        else if (cmd == "PASTE") {
            int k;
            ss >> k;
            if (!clip.empty() && 1 <= k && k <= (int)task.size() + 1) {
                task.insert(
                    task.begin() + (k - 1),
                    clip.begin(), clip.end()
                );
            }
        }
        else if (cmd == "SHOW") {
            if (task.empty()) {
                cout << "KOSONG\n";
            } else {
                for (const auto &x : task)
                    cout << x << "\n";
            }
        }
    }

    return 0;
}

```
## Editorial
Berikut editorial lengkap sekaligus perbaikan untuk solusi **Soal 13: Copy–Paste Blok Tugas**:

---

## 1. Masalah Validasi Range di C++

Kamu menulis:

```cpp
if (1 <= i <= j <= task.size()) { … }
```

Di C++ itu tidak memeriksa “1 ≤ i **dan** i ≤ j **dan** j ≤ N”, melainkan meng‐chaining boolean yang salah semantics.

❌ **Perbaikan**:

```cpp
if (1 <= i && i <= j && j <= (int)task.size()) {
    // valid COPY
}
```

Dan serupa untuk `PASTE`:

```cpp
if (1 <= k && k <= (int)task.size() + 1 && !clip.empty()) {
    // valid PASTE
}
```

---

## 2. Off‐by‐One Indexing

- **COPY**: soal minta salin dari posisi i…j **inklusif** (1‑based).  
    Maka `begin` harus di `task.begin() + (i‑1)`, dan `end` di `task.begin() + j`.
    
    ❌ Kamu pakai `task.begin() + (i+1)` yang keliru.
    
    ```cpp
    // Betulnya:
    clip.assign(
      task.begin() + (i - 1),
      task.begin() + j
    );
    ```
    
- **PASTE**: soal minta tempel **sebelum** posisi k (1‑based).  
    Maka posisi insert adalah `task.begin() + (k‑1)`, bukan `+(k+1)`.
    
    ```cpp
    // Betulnya:
    task.insert(
      task.begin() + (k - 1),
      clip.begin(), clip.end()
    );
    ```
    

---

## 3. Mengecek Clipboard Kosong

Sebelum `PASTE` pastikan `clip` tidak kosong, agar tidak men‐insert range kosong:

```cpp
if (!clip.empty() && 1 <= k && k <= (int)task.size() + 1) {
    // baru lakukan insert
}
```

---

## 4. Parsing dan SHOW

- Kamu sudah benar menggunakan `getline(cin>>ws, s)` dan `stringstream` untuk parsing baris penuh.
    
- `SHOW` kamu tangani di `else`-nya—potongan ini sudah OK, tapi lebih eksplisit bisa pakai `else if (cmd == "SHOW")` agar tidak salah tangkap perintah tak dikenal.
    

---

## 5. Kode Revisi Penuh

```cpp
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<string> task(n);
    for (auto &x : task) 
        cin >> x;

    vector<string> clip;
    int q; 
    cin >> q;
    string line;
    getline(cin, line);  // buang newline

    while (q--) {
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "COPY") {
            int i, j;
            ss >> i >> j;
            if (1 <= i && i <= j && j <= (int)task.size()) {
                clip.assign(
                    task.begin() + (i - 1),
                    task.begin() + j
                );
            }
        }
        else if (cmd == "PASTE") {
            int k;
            ss >> k;
            if (!clip.empty() && 1 <= k && k <= (int)task.size() + 1) {
                task.insert(
                    task.begin() + (k - 1),
                    clip.begin(), clip.end()
                );
            }
        }
        else if (cmd == "SHOW") {
            if (task.empty()) {
                cout << "KOSONG\n";
            } else {
                for (const auto &x : task)
                    cout << x << "\n";
            }
        }
        // else: abaikan perintah tak dikenal
    }

    return 0;
}
```

Dengan perubahan di atas, programmu akan:

1. Validasi boundary dengan benar (tidak crash).
    
2. Copy/Paste rentang yang tepat sesuai soal (inklusif) dan 1‑based index.
    
3. Abaikan PASTE kalau clipboard kosong.
    
4. Cetak “KOSONG” jika daftar benar‑benar kosong.
    

Semoga membantu! Kalau ada pertanyaan, tinggal ditanya—atau siap lanjut ke Soal 14? 🚀

# Editorial untuk jawaban benar
## Editorial Soal 13: Copy–Paste Blok Tugas

### Ringkasan Masalah

Kamu mempunyai daftar tugas (`vector<string> task`) berskala besar dan perlu mendukung perintah:

- **COPY i j**: Menyalin blok tugas dari posisi _i_ sampai _j_ (1‑based, inklusif) ke clipboard.
    
- **PASTE k**: Menempel (paste) isi clipboard _sebelum_ posisi _k_ (1‑based) di `task`.
    
- **SHOW**: Menampilkan seluruh daftar atau mencetak `"KOSONG"` jika `task` kosong.
    

### Struktur Data Utama

- **`vector<string> task`** — Menyimpan daftar tugas aktif.
    
- **`vector<string> clip`** — Clipboard untuk operasi copy–paste.
    

### Pseudocode Inti

1. Baca `n` dan isi `task` dengan `n` string.
    
2. Inisialisasi `clip` (kosong).
    
3. Baca `q` perintah.
    
4. Untuk tiap perintah:
    
    - **COPY i j**:
        
        - Jika valid (`1 ≤ i ≤ j ≤ task.size()`), lakukan:
            
            ```cpp
            clip.assign(
              task.begin() + (i - 1),
              task.begin() + j
            );
            ```
            
    - **PASTE k**:
        
        - Jika valid (`!clip.empty()` dan `1 ≤ k ≤ task.size()+1`), lakukan:
            
            ```cpp
            task.insert(
              task.begin() + (k - 1),
              clip.begin(), clip.end()
            );
            ```
            
    - **SHOW**:
        
        - Jika `task.empty()`: cetak `"KOSONG"`.
            
        - Lainnya: iterasi `task` dan cetak tiap elemen.
            

### Penjelasan Fungsi & Metode

|Fungsi|Tujuan|
|---|---|
|`assign(first, last)`|Menyalin range `[first, last)` ke clipboard (`clip`).|
|`insert(pos, b, e)`|Menyisipkan range `[b, e)` sebelum iterator `pos` di `task`.|
|`task.begin()`|Mendapatkan iterator ke awal vector.|
|`task.size()`|Mendapatkan ukuran vector untuk validasi indeks.|
|`clear()` (opsional)|Membersihkan `clip` jika perlu (tidak digunakan di versi ini).|

### Off‑by‑One & Validasi

- **Indeks 1‑based** → C++ internal 0‑based: `pos = input – 1`.
    
- **Validasi COPY**: gunakan `&&`, bukan chaining `1 ≤ i <= j <= n`.
    
- **Validasi PASTE**: cek juga `!clip.empty()` agar tidak insert range kosong.
    

### Kompleksitas

- **Time**: O(n + q + total_clip_size), rata‑rata operasi `assign` dan `insert` perintah memberikan O(k) untuk ukuran rentang k.
    
- **Space**: O(n + m), dengan `m` ukuran maksimum clipboard.
    

---

Dengan editorial ini, kamu memahami cara memanfaatkan kombinasi `assign` dan `insert` untuk operasi copy–paste efektif pada `vector`. Semoga membantu!