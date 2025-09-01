---
obsidianUIMode: preview
note_type: latihan
latihan: EDIT Tugas
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:46:00
---
---
Siap, kita ke **Soal 12: EDIT Tugas** — sekarang kamu akan belajar mengubah elemen di `vector` secara langsung.

---

# 🧩 Soal 12: EDIT Tugas

### 📥 Input

1. Integer `n` — jumlah tugas awal (1 ≤ n ≤ 10⁵)
    
2. `n` baris berikutnya — tiap baris adalah nama tugas (string tanpa spasi)
    
3. Integer `q` — jumlah perintah (1 ≤ q ≤ 10⁵)
    
4. `q` baris perintah, masing‑masing format:
    
    - **`EDIT pos nama_baru`**  
        → Ganti tugas di posisi `pos` (1‑based) menjadi `nama_baru`.
        
    - **`SHOW`**  
        → Cetak semua tugas saat ini, satu per baris.
        

> **Catatan validasi:**
> 
> - Abaikan perintah `EDIT` jika `pos < 1` atau `pos >` current_size.
>     
> - `nama_baru` tidak mengandung spasi.
>     

---

### 📤 Output

Setiap kali menemui perintah `SHOW`, cetak daftar tugas sekarang dari indeks 1 sampai akhir, satu per baris. Jika daftar kosong, cetak `"KOSONG"`.

---

### 🔍 Contoh

**Input:**

```
4
Baca
Tulis
Ngoding
Istirahat
5
SHOW
EDIT 3 Belajar
SHOW
EDIT 5 Jalan
SHOW
```

**Output:**

```
Baca
Tulis
Ngoding
Istirahat
Baca
Tulis
Belajar
Istirahat
Baca
Tulis
Belajar
Istirahat
```

_Penjelasan:_

- `SHOW` pertama mencetak 4 tugas awal.
    
- `EDIT 3 Belajar` mengganti “Ngoding” → “Belajar”.
    
- `SHOW` kedua mencetak daftar yang sudah diubah.
    
- `EDIT 5 Jalan` diabaikan (posisi 5 tidak valid).
    
- `SHOW` ketiga mencetak daftar sama seperti sebelumnya.
    

---

### 🎯 Tujuan & Tips

- **Akses & modifikasi elemen** menggunakan:
    
    ```cpp
    if (pos >= 1 && pos <= tasks.size())
        tasks[pos-1] = nama_baru;
    ```
    
- Atau gunakan `tasks.at(pos-1)` untuk mendapatkan pengecekan out‑of‑range otomatis (melempar exception jika invalid).
    
- **Iterasi**: tampilkan dengan loop:
    
    ```cpp
    for (const auto &t : tasks)
        cout << t << "\n";
    ```
    

---

Coba kerjakan, lalu kirim kodenya untuk dicek dan kita akan lanjut ke variasi **Copy-Paste Blok Tugas** di Soal 13! 🚀

## Jawabanku
Berikut adalah jawabanku untuk problem ini:

```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> task(n);
    for(auto&x:task) cin >> x;

    int q; cin >> q;
    while(q--){
        string s; 
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="SHOW"){
            if(task.empty()){
                cout << "KOSONG\n";
            } else {
                for(const auto&x:task){
                    cout << x << "\n";
                }
            }
        } else if (cmd=="EDIT"){
            string pos, job;
            ss >> pos;
            getline(ss >> ws, job);

            int pose=stoi(pos);
            if(pose>=1 && pose<=task.size()){
                task[pose-1]=job;
            }
        }
    }
    return 0;
}
```

#### Jawaban yang lebih baik
Berikut adalah jawaban yang mengikuti saran editorial:

```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> task(n);
    for(auto&x:task) cin >> x;

    int q; cin >> q;
    while(q--){
        string s; 
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="SHOW"){
            if(task.empty()){
                cout << "KOSONG\n";
            } else {
                for(const auto&x:task){
                    cout << x << "\n";
                }
            }
        } else if (cmd=="EDIT"){
            string job;
            int pos;
            ss >> pos;
            getline(ss >> ws, job);

            if(pos>=1 && pos<=task.size()){
                task.at(pos-1)=job;
            }
        }
    }
    return 0;
}
```
# Editorial
Berikut **editorial lengkap** untuk solusi **Soal 12: EDIT Tugas** yang kamu tulis:

---

## 📋 Ringkasan Problem

- **EDIT pos nama_baru**: Ganti tugas di posisi `pos` (1‑based) menjadi `nama_baru`.
    
- **SHOW**: Cetak semua tugas saat ini, atau `"KOSONG"` jika tidak ada.
    

Kamu menyimpan tugas di `vector<string> task` dengan indeks 0‑based internal, tetapi menerima `pos` 1‑based dari input.

---

## ✅ Poin–Poin Yang Sudah Tepat

1. **Inisialisasi & Input Awal**
    
    ```cpp
    int n; cin >> n;
    vector<string> task(n);
    for (auto &x : task) cin >> x;
    ```
    
    ‣ Membaca `n` dan mengisi `vector` langsung dengan `n` elemen.
    
2. **Fast I/O**
    
    ```cpp
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ```
    
    ‣ Mengoptimalkan performa untuk `q` besar.
    
3. **Parsing Perintah**
    
    ```cpp
    getline(cin >> ws, s);
    stringstream ss(s);
    ss >> cmd;
    ```
    
    ‣ Membaca seluruh baris perintah, lalu memecah token.
    
4. **SHOW dengan Cek Kosong**
    
    ```cpp
    if (cmd == "SHOW") {
      if (task.empty())
        cout << "KOSONG\n";
      else
        for (auto &x : task)
          cout << x << "\n";
    }
    ```
    
    ‣ Menangani daftar kosong sesuai spesifikasi.
    
5. **EDIT dengan Validasi**
    
    ```cpp
    else if (cmd == "EDIT") {
      string pos, job;
      ss >> pos;
      getline(ss >> ws, job);
      int pose = stoi(pos);
      if (pose >= 1 && pose <= task.size())
        task[pose - 1] = job;
    }
    ```
    
    ‣ Mengonversi `pos` dari string ke integer (`stoi`)  
    ‣ Memastikan `1 ≤ pose ≤ task.size()` sebelum mengganti elemen
    

---

## ⚠️ Tips & Penyempurnaan

1. **Parsing Posisi Sebagai Integer Langsung**  
    Kamu bisa lebih ringkas dengan:
    
    ```cpp
    int pose;
    ss >> pose >> ws;
    getline(ss, job);
    ```
    
    Menghindari variabel `pos` string dan `stoi`.
    
2. **Gunakan `at()` untuk Safety (Opsional)**
    
    ```cpp
    if (pose >= 1 && pose <= task.size())
      task.at(pose - 1) = job;
    ```
    
    ‣ `at()` melempar `out_of_range` jika indeks salah, membantu debugging saat pengembangan.
    
3. **Penanganan Whitespaces**  
    Jika nama tugas bisa berisi spasi, pendekatan `getline(ss >> ws, job)` sudah benar.  
    Jika tidak (“string tanpa spasi”), kamu bisa cukup `ss >> job`.
    
4. **Struktur `if/else if`**  
    Kodemu sudah bersih. Pertimbangkan menambahkan `else` blok untuk mengabaikan perintah tak dikenal.
    

---

## 🧠 Kompleksitas

- **Time:** O(n + q) — input awal O(n), tiap perintah O(1) average
    
- **Space:** O(n) — penyimpanan `vector<string>`
    

---

### 🔍 Contoh Uji Coba

**Input:**

```
4
Baca
Tulis
Ngoding
Istirahat
5
SHOW
EDIT 3 Belajar
SHOW
EDIT 5 Jalan
SHOW
```

**Output:**

```
Baca
Tulis
Ngoding
Istirahat
Baca
Tulis
Belajar
Istirahat
Baca
Tulis
Belajar
Istirahat
```

---

Dengan sedikit penyempurnaan di atas, kode-mu sudah **optimal, aman, dan mudah dibaca**. 🚀

Siap melanjutkan ke **Soal 13: Copy-Paste Blok Tugas**? Let’s go!