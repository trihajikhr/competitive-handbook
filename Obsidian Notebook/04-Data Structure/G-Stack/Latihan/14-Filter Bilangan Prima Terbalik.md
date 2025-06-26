---
obsidianUIMode: preview
note_type: latihan
latihan: Filter Bilangan Prima Terbalik
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T22:02:00
---
---
Siap! Yuk lanjut ke **Soal Stack #14** — kali ini kita coba sesuatu yang lebih logika dan manipulatif, tapi tetap mengasah pemahaman dasar `stack`.
# 📘 Soal Stack 14 — _Filter Bilangan Prima Terbalik_

**Deskripsi:**

Diberikan `n` bilangan bulat. Kamu diminta untuk:

- Menyimpan **hanya bilangan prima** ke dalam stack.
    
- Setelah semua bilangan diproses, tampilkan isi stack dari atas ke bawah (urutan terbalik dari saat dimasukkan).
    

---

### 🧾 Format Input:

- Baris pertama: bilangan bulat `n` (1 ≤ n ≤ 100)
    
- Baris kedua: `n` buah bilangan bulat positif (1 ≤ bilangan ≤ 10⁴)
    

---

### 📤 Format Output:

- Setiap bilangan prima dalam stack (dari atas ke bawah)
    
- Jika tidak ada bilangan prima, cetak `"TIDAK ADA"` (tanpa kutip)
    

---

### 🧪 Contoh Input:

```
7
10 3 7 8 4 11 12
```

### 📤 Contoh Output:

```
11
7
3
```

---

### 🧪 Contoh Input 2:

```
5
4 6 8 10 12
```

### 📤 Output:

```
TIDAK ADA
```

---

### 💡 Petunjuk:

- Buat fungsi `bool isPrime(int x)` untuk mengecek apakah `x` adalah bilangan prima.
    
- Gunakan `stack<int>` untuk menyimpan bilangan prima saja.
    

---

Kalau kamu sudah siap, tinggal implementasikan aja. Setelah itu boleh minta **editorial**, atau lanjut ke **soal ke-15**. Semangat terus! 🌟

## Jawabanku
Berikut adalah jawabanku untuk menyelesaikan kode ini:

```cpp
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;


bool primaChecker(int x){
    if(x<=1) return false;
    for(int i=2; i*i <= x; i++){
        if(x%i==0) return false;
    }
    return true;
}

int main() {
    int n; cin >> n;
    vector<int> input (n);
    stack<int> rest;
    for(auto&x:input) cin >> x;

    for(const auto&x:input){
        if (primaChecker(x)){
            rest.push(x);
        }
    }

    if(rest.empty()){
        cout << "TIDAK ADA\n";
    } else {
        while(!rest.empty()){
            cout << rest.top() << "\n";
            rest.pop();
        }
    }
    return 0;
}
```

# Editorial
Bagus banget! Kode kamu **sudah benar dan optimal**. Sekarang aku buatkan **editorial lengkapnya** supaya kamu bisa menyimpannya ke catatan belajar stack kamu.

---

## 🧾 Editorial Soal Stack 14: _Filter Bilangan Prima Terbalik_

### 🔍 Tujuan Soal:

- Menyaring bilangan **prima** dari sekumpulan angka
    
- Menyimpannya di dalam stack (agar bisa ditampilkan secara **terbalik**)
    
- Menampilkan hasil dari atas stack ke bawah, atau `"TIDAK ADA"` jika kosong
    

---

### 💡 Penjelasan Kode:

```cpp
bool primaChecker(int x){
    if(x<=1) return false;
    for(int i=2; i*i <= x; i++){
        if(x%i==0) return false;
    }
    return true;
}
```

📌 Fungsi `primaChecker(x)` mengecek apakah bilangan `x` adalah prima.

- Cek dari `2` hingga `√x` (efisien).
    
- Jika ada pembagi lain selain 1 dan dirinya sendiri → bukan prima.
    

---

```cpp
int main() {
    int n; cin >> n;
    vector<int> input (n);
    stack<int> rest;
    for(auto&x:input) cin >> x;
```

📌 Input `n` bilangan disimpan dalam `vector<int> input`.  
📌 Disiapkan `stack<int> rest` untuk menyimpan bilangan prima.

---

```cpp
    for(const auto&x:input){
        if (primaChecker(x)){
            rest.push(x);
        }
    }
```

📌 Lakukan filtering:

- Jika `x` adalah bilangan prima → masukkan ke stack `rest`.
    

---

```cpp
    if(rest.empty()){
        cout << "TIDAK ADA\n";
    } else {
        while(!rest.empty()){
            cout << rest.top() << "\n";
            rest.pop();
        }
    }
```

📌 Setelah semua selesai:

- Jika stack kosong, berarti **tidak ada bilangan prima**.
    
- Jika tidak, cetak satu per satu dari atas stack ke bawah.
    

---

### ✅ Contoh:

Input: `10 3 7 8 4 11 12`

- Prima: `3, 7, 11`
    
- Stack isi: `3 → 7 → 11` → karena stack LIFO, maka keluarnya `11\n7\n3`
    

---

### 📌 Kesimpulan Fungsi Stack:

- Stack digunakan untuk membalik urutan bilangan prima.
    
- Fungsi `.push()`, `.top()`, `.pop()`, `.empty()` dimanfaatkan semua.
    
- Sangat cocok untuk latihan filtering + urutan balik.
    

---

Kalau sudah siap, kita lanjut ke **Soal Stack #15**. Kamu mau lanjut langsung atau rehat dulu? 😄