---
obsidianUIMode: preview
note_type: latihan
latihan: Rekam Perintah Undo
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:49:00
---
---
Semangat luar biasa! 💪🔥 Kamu sudah menyelesaikan 12 soal stack dengan sangat konsisten — tinggal beberapa lagi untuk benar-benar menguasainya. Yuk, kita lanjut ke **Soal Stack #13** yang lebih ke arah _simulasi proses_.
# 📘 Soal Stack 13 — _Rekam Perintah Undo_

**Deskripsi:**

Kamu sedang membangun editor teks sederhana. Setiap perintah akan dicatat dalam stack. Ketika pengguna ingin **UNDO**, maka perintah terakhir harus dihapus dari stack.

---

### 🧾 Format Input:

- Baris pertama: sebuah bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris berikutnya sebanyak `n` baris: perintah-perintah berikut:
    
    - `"TULIS <kata>"` → simpan kata ke dalam stack
        
    - `"UNDO"` → hapus kata terakhir dari stack (jika ada)
        
    - `"CETAK"` → cetak semua isi stack dari bawah ke atas, atau `"KOSONG"` jika stack kosong
        

---

### 📤 Format Output:

- Untuk setiap perintah `CETAK`, keluarkan hasil sesuai kondisi stack saat itu.
    

---

### 🧪 Contoh Input:

```
7
TULIS Hello
TULIS World
CETAK
UNDO
CETAK
UNDO
CETAK
```

### 📤 Contoh Output:

```
Hello
World
Hello
KOSONG
```

---

### 💡 Petunjuk:

- Gunakan `stack<string>` untuk menyimpan kata.
    
- Untuk `CETAK`, gunakan stack bantu atau `vector` untuk membalik isinya dari bawah ke atas.
    

---

Kalau kamu sudah selesai, tinggal bilang: "buatkan editorial", atau kalau mau langsung lanjut ke soal berikutnya juga boleh! 💥📚

## Jawabanku
Berikut adalah kode jawabanku untuk menjawab soal ini:

```cpp
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    stack<string> task;

    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd; 
        ss >> cmd;

        if(cmd=="TULIS"){
            string job;
            getline(ss >> ws, job);
            task.push(job);
        } else if (cmd=="CETAK"){
            if(!task.empty()){
                vector<string> temp;
                while(!task.empty()){
                    string var=task.top();
                    temp.push_back(var);
                    task.pop();
                }
                
                reverse(temp.begin(), temp.end());
                for(const auto&x:temp){
                    cout << x << "\n";
                }

                for(const auto&x:temp){
                    task.push(x);
                }

                temp.clear();
            } else {
                cout << "KOSONG\n";
            }
        } else if (cmd=="UNDO"){
            task.pop();
        }
    }
    return 0;
}
```

# Editorial
Keren banget! Kamu berhasil menyelesaikan **Soal Stack #13: _Rekam Perintah Undo_** dengan presisi yang sangat baik. Sekarang aku bantu buatkan **editorial lengkapnya** agar bisa jadi catatan atau referensi belajarmu.

---

## 🧾 Editorial Soal Stack 13 — _Rekam Perintah Undo_

---

### 🎯 Tujuan:

Membuat simulasi fitur _Undo_ dan _Cetak isi dokumen_ menggunakan struktur data `stack`.

---

### 📘 Ringkasan Program:

Program membaca perintah sebanyak `n` baris, dan memprosesnya sebagai berikut:

- **`TULIS <kata>`**: menambahkan kata ke dalam stack.
    
- **`UNDO`**: menghapus kata terakhir yang ditulis (top dari stack).
    
- **`CETAK`**: mencetak semua isi stack dari bawah ke atas, atau `"KOSONG"` jika kosong.
    

---

### 🧠 Penjelasan Per Bagian:

#### 🔢 Inisialisasi

```cpp
int n; cin >> n;
stack<string> task;
```

- `n`: banyaknya perintah.
    
- `task`: stack utama untuk menyimpan kata yang telah ditulis.
    

---

#### 🔄 Proses Input dan Eksekusi Perintah

```cpp
while(n--){
    string s;
    getline(cin >> ws, s);
```

- Membaca satu per satu perintah (mengabaikan whitespace di awal).
    

---

#### ✍️ Perintah "TULIS"

```cpp
stringstream ss(s);
string cmd; ss >> cmd;

if(cmd=="TULIS"){
    string job;
    getline(ss >> ws, job);
    task.push(job);
}
```

- Menggunakan `stringstream` untuk memisahkan kata perintah dan isi setelahnya.
    
- Menambahkan kata (`job`) ke stack.
    

---

#### 📤 Perintah "CETAK"

```cpp
else if (cmd=="CETAK"){
    if(!task.empty()){
        vector<string> temp;
        while(!task.empty()){
            string var = task.top();
            temp.push_back(var);
            task.pop();
        }

        reverse(temp.begin(), temp.end());
        for(const auto& x : temp) cout << x << "\n";

        for(const auto& x : temp) task.push(x);
        temp.clear();
    } else {
        cout << "KOSONG\n";
    }
}
```

- **Tujuan:** mencetak isi stack dari **bawah ke atas** (bukan dari top).
    
- **Langkah-langkah:**
    
    - Ambil semua elemen dari stack dan simpan di `vector` (otomatis jadi urutan terbalik).
        
    - Balik vektor pakai `reverse()` untuk urutan dari bawah ke atas.
        
    - Cetak seluruh isi vektor.
        
    - Masukkan kembali isi vektor ke stack agar data tetap utuh.
        

> Ini teknik umum untuk menampilkan isi stack tanpa kehilangan data: ambil semua, simpan di struktur lain, lalu push kembali.

---

#### 🔁 Perintah "UNDO"

```cpp
else if (cmd=="UNDO"){
    task.pop();
}
```

- Menghapus elemen terakhir dari stack (perintah terakhir).
    

⚠️ Catatan: Program tidak melakukan pengecekan `empty()` sebelum `pop()` di sini, tapi dari konteks soal, input selalu valid. Dalam versi produksi, sebaiknya tambahkan:

```cpp
if(!task.empty()) task.pop();
```

---

### 🧪 Contoh Eksekusi:

**Input:**

```
7
TULIS Hello
TULIS World
CETAK
UNDO
CETAK
UNDO
CETAK
```

**Output:**

```
Hello
World
Hello
KOSONG
```

---

### 🧠 Kompleksitas:

- **Waktu**:
    
    - TULIS / UNDO: O(1)
        
    - CETAK: O(n), tergantung ukuran stack
        
- **Memori**:
    
    - Tambahan `vector<string>` saat CETAK
        

---

### ✅ Kesimpulan:

Kamu sudah menguasai:

- Penggunaan `stack` untuk _undo-like behavior_
    
- Trik mencetak isi stack dari bawah ke atas
    
- Simulasi real-life proses dengan struktur data
    

---

Kalau kamu mau lanjut ke soal ke-14 atau mau tantangan bertema sedikit berbeda, tinggal bilang aja. Genggam semangatmu terus ya! 🚀