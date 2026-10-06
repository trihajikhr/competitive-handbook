---
obsidianUIMode: preview
note_type: latihan
latihan: Editor Sederhana
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:48:00
---
---

Siap! 🚀 Kita lanjut ke **soal stack berikutnya** – kali ini dengan kombinasi **logika penghapusan dan penulisan ulang**. Cocok banget buat ngasah pemahaman tentang bagaimana stack bisa digunakan untuk memanipulasi urutan karakter.
# 📘 Soal Stack 11 — _Editor Sederhana_

**Deskripsi:**

Kamu sedang membuat editor teks mini yang hanya mengenali:

- Karakter alfabet (`a` sampai `z`).
    
- Simbol `#` yang berarti **hapus satu karakter terakhir yang diketik**.
    

Tugasmu adalah menampilkan hasil akhir dari teks setelah semua karakter dan simbol `#` diproses. Kamu harus menggunakan stack untuk menyelesaikan soal ini.

---

**Format Input:**

- Satu baris string `s` (panjang ≤ 1000), hanya berisi huruf kecil dan simbol `#`.
    

---

**Format Output:**

- Satu baris: hasil akhir dari teks.
    

---

**Contoh Input 1:**

```
abc#d##
```

**Contoh Output 1:**

```
a
```

**Contoh Input 2:**

```
a##b##c
```

**Contoh Output 2:**

```
c
```

---

### 💡 Petunjuk:

- Gunakan `stack<char>` untuk menyimpan karakter yang belum dihapus.
    
- Jika karakter adalah huruf, `push()` ke stack.
    
- Jika karakter adalah `#`, `pop()` jika stack tidak kosong.
    

---

Kalau kamu ingin aku bantu buatkan template kode atau editorial setelah menyelesaikan, tinggal bilang saja. Ayo, stack power-up lagi! 💪📚

## Jawabanku
Berikut adalah jawabanku:

```cpp
#include<iostream>
#include<cctype>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
    string s; 
    getline(cin >> ws, s);

    stack<char> alfa;
    for(char c: s){
        if(isalpha(c)){
            alfa.push(c);
        } else if (c=='#'){
            if(!alfa.empty()){
                alfa.pop();
            }
        }
    }
    
    string rest="";
    while(!alfa.empty()){
        rest+=alfa.top();
        alfa.pop();
    }

    reverse(rest.begin(), rest.end());
    cout << rest << "\n";
    return 0;
}
```

# Editorial
Keren! 🔥 Kode kamu sudah **tepat dan efisien**. Sekarang, berikut ini **editorial lengkap** dari solusi tersebut:

---

## 🧾 Judul: Simulasi Editor Teks Sederhana Menggunakan Stack

---

### 📌 Tujuan:

Memproses string yang terdiri dari huruf dan simbol `#`, di mana:

- Huruf ditambahkan ke hasil (seperti diketik ke layar),
    
- Simbol `#` menghapus satu huruf terakhir yang sudah diketik (seperti `Backspace`).
    

---

### 📥 Input:

Satu baris string `s` yang terdiri dari huruf kecil dan simbol `#`.

---

### 📤 Output:

Hasil akhir dari teks setelah proses simbol `#`.

---

### 🧱 Struktur yang Digunakan:

```cpp
stack<char> alfa;
```

Stack digunakan untuk meniru proses **menulis dan menghapus karakter** secara berurutan.

---

### 🧮 Langkah Per Baris:

```cpp
string s; 
getline(cin >> ws, s);
```

- Membaca seluruh baris input.
    
- `ws` memastikan spasi di awal tidak diabaikan.
    

---

```cpp
stack<char> alfa;
for(char c: s){
    if(isalpha(c)){
        alfa.push(c);
    } else if (c=='#'){
        if(!alfa.empty()){
            alfa.pop();
        }
    }
}
```

🔁 Untuk setiap karakter:

- Jika huruf: masukkan ke stack (`push()`).
    
- Jika `#`: hapus karakter terakhir jika ada (`pop()`).
    
- Stack bekerja seperti sejarah pengetikan: Last-In-First-Out.
    

---

```cpp
string rest="";
while(!alfa.empty()){
    rest+=alfa.top();
    alfa.pop();
}
```

- Karakter pada stack disusun **dari akhir ke awal** (karena sifat LIFO).
    
- Disusun dalam string `rest`.
    

---

```cpp
reverse(rest.begin(), rest.end());
cout << rest << "\n";
```

- Membalik urutan string `rest`, karena kita membangun hasil akhir secara terbalik dari stack.
    
- Mencetak hasil akhirnya.
    

---

### 📌 Contoh Kerja Program

**Input:**

```
abc#d##
```

**Proses:**

- push('a') → `a`
    
- push('b') → `ab`
    
- push('c') → `abc`
    
- `#` → hapus `c` → `ab`
    
- push('d') → `abd`
    
- `#` → hapus `d` → `ab`
    
- `#` → hapus `b` → `a`
    

**Output:**

```
a
```

---

### ⚙️ Kompleksitas:

- **Waktu:** O(n)
    
- **Memori:** O(n)  
    Karena tiap karakter hanya diproses satu kali, dan operasi stack (`push/pop/top`) dilakukan dalam waktu konstan.
    

---

### 🏁 Kesimpulan:

Kodenya **ringkas, benar, dan optimal**. Kamu berhasil menerapkan stack dengan benar untuk kasus nyata seperti simulasi editor.

Kalau kamu mau tantangan tambahan:

- **Undo bertingkat** (misalnya `##` menghapus dua sebelumnya),
    
- Atau **mengembalikan hasil dengan spasi, huruf kapital**, dsb.
    

Tinggal bilang aja ya! 💪📄