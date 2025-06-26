---
obsidianUIMode: preview
note_type: latihan
latihan: Simulasi Tumpukan Piring
sumber: chatgpt.com
tags:
  - stack
  - data-structure
date_learned:
---
---
# 🧩 Soal 1: Simulasi Tumpukan Piring

**Deskripsi:**

Bayangkan kamu sedang menyusun piring di dapur. Setiap kali ada piring baru, kamu meletakkannya di atas tumpukan. Terkadang, kamu perlu mengambil satu piring dari atas. Buatlah program yang menerima perintah-perintah berikut:

- `PUSH x`: Menambahkan piring bernama `x` ke atas tumpukan.
    
- `POP`: Mengambil piring paling atas dari tumpukan.
    
- `TOP`: Menampilkan nama piring paling atas.
    
- `SIZE`: Menampilkan jumlah piring saat ini.
    
- `EMPTY`: Menampilkan "YA" jika tumpukan kosong, atau "TIDAK" jika tidak.
    

**Input:**

Baris pertama berisi satu bilangan bulat `n` (jumlah perintah).  
Lalu `n` baris berikutnya berisi perintah-perintah di atas.

**Contoh Input:**

```
7
PUSH Merah
PUSH Biru
TOP
SIZE
POP
TOP
EMPTY
```

**Contoh Output:**

```
Biru
2
Merah
TIDAK
```

---

Kalau kamu sudah menyelesaikannya, kirimkan kodenya, nanti aku bantu periksa dan lanjut ke soal berikutnya. Mau langsung coba?

## Jawabanku
Berikut adalah jawaban untuk soal ini:

```cpp
#include<iostream>
#include<sstream>
#include<stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<string> color;
    int n; cin >> n;
    while(n--){
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        string cmd;
        ss >> cmd;

        if(cmd=="PUSH"){
            string col;
            getline(ss >> ws, col);
            color.push(col);
        } else if (cmd=="TOP"){
            cout << color.top() << "\n";
        } else if(cmd=="SIZE"){
            cout << color.size() << "\n";
        } else if(cmd=="POP"){
            color.pop();
        } else if(cmd=="EMPTY"){
            if(color.empty()) cout << "YA\n";
            else cout << "TIDAK\n";
        }
    }
    return 0;
}
```

## Editorial
Jawabanmu **benar dan rapi sekali** — kamu sudah berhasil menggunakan semua fungsi penting dari `std::stack`: `push()`, `pop()`, `top()`, `size()`, dan `empty()`. Nice work! ✨

---

### 📘 Editorial Soal 1: Simulasi Tumpukan Piring

**Tujuan:**  
Melatih penggunaan dasar struktur data `stack` di C++, sekaligus memperkenalkan fungsionalitas umum dalam kehidupan nyata: LIFO (Last In First Out).

---

### 🔍 Penjelasan Kode

```cpp
stack<string> color;
```

- Membuat stack berisi string. Ini mewakili tumpukan piring berdasarkan warnanya.
    

```cpp
int n; cin >> n;
```

- Menerima jumlah perintah yang akan dijalankan.
    

```cpp
getline(cin >> ws, s);
```

- `ws` menghilangkan spasi putih sebelum membaca seluruh baris, agar dapat membaca perintah dengan argumen di belakangnya.
    

```cpp
if(cmd == "PUSH"){
    string col;
    getline(ss >> ws, col);
    color.push(col);
}
```

- Menambahkan piring ke atas tumpukan.
    

```cpp
else if(cmd == "TOP"){
    cout << color.top() << "\n";
}
```

- Menampilkan piring paling atas (tanpa menghapusnya).
    

```cpp
else if(cmd == "SIZE"){
    cout << color.size() << "\n";
}
```

- Menampilkan jumlah piring yang ada saat ini.
    

```cpp
else if(cmd == "POP"){
    color.pop();
}
```

- Menghapus piring paling atas dari tumpukan.
    

```cpp
else if(cmd == "EMPTY"){
    if(color.empty()) cout << "YA\n";
    else cout << "TIDAK\n";
}
```

- Mengecek apakah tumpukan kosong.
    

---

### ✅ Nilai Tambah:

Kamu sudah menambahkan `ios::sync_with_stdio(false);` dan `cin.tie(nullptr);` yang mempercepat I/O — sangat bagus untuk kompetisi atau penggunaan intensif.

---

Siap untuk **Soal ke-2**? Kali ini kita akan menyimulasikan **navigasi halaman web**, konsep **back-forward stack**! Mau lanjut?