---
obsidianUIMode: preview
note_type: latihan
latihan: UNDO + REDO di Daftar Tugas
sumber: Google.com, AI
tags:
  - vector
  - data-structure
date_learned: 2025-06-14T21:45:00
---
---
# UNDO + REDO di Daftar Tugas
Mantap, kita naik level ke:



## 🧩 Soal 11: UNDO + REDO di Daftar Tugas

(Fokus: dua buah `vector`, operasi `push_back`, `pop_back`, `back`, dan `clear`)

---

### 🎯 Deskripsi Soal

Sekarang daftar tugasmu tidak hanya bisa di-_UNDO_, tapi juga bisa di-_REDO_. Buat program yang menangani perintah:

- `ADD <teks>`: Menambahkan tugas baru ke akhir
    
- `UNDO`: Menghapus tugas terakhir dan menyimpannya di buffer REDO
    
- `REDO`: Mengembalikan tugas terakhir yang di-_UNDO_
    
- `SHOW`: Menampilkan isi daftar tugas dari awal hingga akhir
    

---

### 📥 Input Format

```
q               // jumlah perintah
<q baris perintah>
```

---

### 📤 Output Format

Cetak seluruh tugas (jika ada) setiap kali perintah `SHOW` dijalankan. Jika daftar kosong, cetak `"KOSONG"`.

---

### 🧪 Contoh Input

```
7
ADD Belajar
ADD Makan
UNDO
SHOW
REDO
SHOW
UNDO
```

---

### ✅ Contoh Output

```
Belajar
Belajar
Makan
```

---

### 💡 Catatan Teknis

- Gunakan dua buah `vector<string>`:
    
    - `stack` → daftar tugas aktif
        
    - `redo_buffer` → menyimpan tugas yang di-_UNDO_
        
- Setiap `ADD` akan **mengosongkan** redo_buffer (seperti aplikasi asli)
    
- `UNDO` → `pop_back()` dari stack, lalu `push_back()` ke redo_buffer
    
- `REDO` → `pop_back()` dari redo_buffer, lalu `push_back()` ke stack
    

---

### 🔧 Tips Tambahan

- Pastikan `UNDO` dan `REDO` **tidak error** jika masing-masing kosong.
    
- Gunakan `stack.empty()` dan `redo_buffer.empty()` untuk validasi.
    

---

Kalau kamu mau coba dulu, kirim jawabanmu ke sini.  
Atau kalau kamu mau langsung implementasi referensinya, aku bisa bantu buatin juga. 🚀

## Jawabanku
Jawaban yang masih kurang tepat, karena masih ada perbaikan yang masih bisa dilakukan:

```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastio();
    int n; cin >> n;
    vector<string> stack;
    vector<string> redo_buffer;
    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd, hobby;
        ss >> cmd >> hobby;
        
        string temp;
        if(cmd=="ADD"){
            stack.push_back(hobby);
            if(!redo_buffer.empty()){
                redo_buffer.clear();
            }
        } else if (cmd=="UNDO"){
            if(!stack.empty()){
                temp = stack.back();
                stack.pop_back();
                redo_buffer.push_back(temp);
            }
        } else if (cmd=="REDO"){
            if(!redo_buffer.empty()){
                temp = redo_buffer.back();
                redo_buffer.pop_back();
                stack.push_back(temp);
            }
        } else if (cmd=="SHOW"){
            for(const auto&x:stack){
                cout << x << "\n";
            }
        }
    }
    return 0;
}
```

#### Jawaban benar
Berikut adalah kode program yang lebih baik dari sebelumnya:

```cpp
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    fastio();
    int n; cin >> n;
    vector<string> task;
    vector<string> redo_buffer;
    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd, hobby;
        ss >> cmd;

        getline(ss >> ws, hobby);
        
        string temp;
        if(cmd=="ADD"){
            task.push_back(hobby);
            if(!redo_buffer.empty()){
                redo_buffer.clear();
            }
        } else if (cmd=="UNDO"){
            if(!task.empty()){
                temp = task.back();
                task.pop_back();
                redo_buffer.push_back(temp);
            }
        } else if (cmd=="REDO"){
            if(!redo_buffer.empty()){
                temp = redo_buffer.back();
                redo_buffer.pop_back();
                task.push_back(temp);
            }
        } else if (cmd=="SHOW"){
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

# Editorial
Berikut **editorial lengkap** untuk solusi **Soal 11: UNDO + REDO** yang kamu tulis:

---

## 📋 Ringkasan Problem

- **ADD**: tambahkan tugas ke akhir daftar (stack)
    
- **UNDO**: hapus tugas terakhir dan simpan ke buffer redo
    
- **REDO**: ambil tugas terakhir dari buffer redo dan kembalikan ke daftar
    
- **SHOW**: cetak semua tugas saat ini
    

Kamu menggunakan dua buah `vector<string>`:

1. `stack` sebagai daftar tugas aktif
    
2. `redo_buffer` sebagai tempat menampung tugas yang di-UNDO
    

---

## ✅ Poin–Poin Yang Sudah Tepat

1. **Fast I/O**
    
    ```cpp
    inline void fastio(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    }
    ```
    
    Membantu mempercepat input/output untuk `q` hingga besar.
    
2. **ADD dan Clear Redo**
    
    ```cpp
    if (cmd == "ADD") {
      stack.push_back(hobby);
      if (!redo_buffer.empty())
        redo_buffer.clear();
    }
    ```
    
    ‣ Menambahkan `hobby` ke `stack`  
    ‣ Mengosongkan `redo_buffer` jika sebelumnya ada undo—sesuai perilaku aplikasi nyata.
    
3. **UNDO**
    
    ```cpp
    else if (cmd == "UNDO") {
      if (!stack.empty()) {
        temp = stack.back();
        stack.pop_back();
        redo_buffer.push_back(temp);
      }
    }
    ```
    
    ‣ Aman (hanya pop jika ada elemen)  
    ‣ Memindahkan elemen terakhir ke `redo_buffer`.
    
4. **REDO**
    
    ```cpp
    else if (cmd == "REDO") {
      if (!redo_buffer.empty()) {
        temp = redo_buffer.back();
        redo_buffer.pop_back();
        stack.push_back(temp);
      }
    }
    ```
    
    ‣ Mengembalikan tugas yang terakhir di-undo.
    
5. **SHOW**
    
    ```cpp
    else if (cmd=="SHOW") {
      for(const auto& x : stack)
        cout << x << "\n";
    }
    ```
    
    ‣ Menampilkan seluruh daftar tugas.
    

---

## ⚠️ Masalah & Penyempurnaan

1. **Menangani `SHOW` saat kosong**  
    Saat `stack` kosong, spesifikasi meminta mencetak `"KOSONG"`.
    
    ```cpp
    else if (cmd == "SHOW") {
      if (stack.empty())
        cout << "KOSONG\n";
      else {
        for (const auto &t : stack)
          cout << t << "\n";
      }
    }
    ```
    
2. **Parsing lebih robust**  
    Saat ini kamu melakukan:
    
    ```cpp
    ss >> cmd >> hobby;
    ```
    
    → Hanya akan menangkap satu kata setelah perintah.  
    Jika nanti tugas bisa berisi spasi, pertimbangkan:
    
    ```cpp
    ss >> cmd;
    if (cmd == "ADD") {
      string rest;
      getline(ss >> ws, rest);
      stack.push_back(rest);
      ...
    }
    ```
    
3. **Penamaan variabel**  
    Menggunakan nama `stack` untuk `vector` bagus, tapi terkadang bisa membingungkan karena `std::stack`.  
    Kamu bisa ganti ke `tasks` atau `todo_list` untuk kejelasan.
    

---

## 🔍 Kompleksitas

- **Time**: O(q) overall, karena tiap perintah hanya O(1) amannya (`push_back`, `pop_back`, `clear`, `back`)
    
- **Memory**: O(q) di worst case (semua perintah ADD tanpa UNDO)
    

---

Dengan sedikit perbaikan di atas, solusi-mu akan:

- Selalu aman (tidak crash)
    
- Memenuhi semua kasus, termasuk daftar kosong
    
- Lebih mudah dibaca dan dipelihara
    

---

Siap untuk **Soal 12: EDIT Tugas**?  
Atau kamu mau eksplor topik lain seperti **Soal 12: Copy-Paste Blok Tugas**?

Tinggal bilang, aku siap siapkan! 🚀