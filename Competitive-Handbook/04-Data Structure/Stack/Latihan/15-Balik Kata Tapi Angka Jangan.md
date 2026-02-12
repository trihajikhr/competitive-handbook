---
obsidianUIMode: preview
note_type: latihan
latihan: Balik Kata Tapi Angka Jangan
sumber: Google.com, AI
tags:
  - data-structure
  - stack
date_learned: 2025-06-15T22:45:00
---
---
# 🧠 Soal Stack 15 (Revisi) — _Balik Kata Tapi Angka Jangan_

**Deskripsi:**

Diberikan sebuah string yang terdiri dari huruf dan angka (tanpa spasi). Balik urutan semua hurufnya **menggunakan stack**, tetapi **angka harus tetap di posisi aslinya.**

---

### 📥 Input:

Sebuah string `S` (panjang 1–100)  
Contoh:

```
ab1c2de3
```

---

### 📤 Output:

String hasil proses, di mana semua huruf dibalik urutannya, sedangkan posisi angka tetap.  
Contoh:

```
ed1c2ba3
```

📌 Perhatikan:

- 'a', 'b', 'c', 'd', 'e' dibalik jadi 'e', 'd', 'c', 'b', 'a'
    
- Angka '1', '2', dan '3' tetap di posisi semula.
    

---

### 🧪 Contoh Lain:

Input:

```
a1b2c
```

Output:

```
c1b2a
```

---

Mau kamu coba sendiri dulu? Atau aku bantu buatkan kerangkanya?  
Ini _benar-benar soal stack terakhir yang berkelas dan relevan!_ 😎

## Jawabku
Berikut adalah kode jawabanku:

```cpp
#include<iostream>
#include<stack>
#include<cctype>
using namespace std;

int main() {
    string s;
    getline(cin >> ws, s);

    stack<char> huruf;
    for(char c: s){
        if(isalpha(c)){
            huruf.push(c);
        }
    }

    for(char c:s){
        if(isalpha(c)){
            cout << huruf.top();
            huruf.pop();
        } else cout << c;
    }
    return 0;
}
```

# Editorial
🔥 WUIHH!! KEREN! 🔥  
Langsung **bener, bersih, dan tepat sasaran.**  
Kamu pakai `stack<char>` untuk menyimpan huruf, lalu **menjaga posisi angka tetap**, dan semua ini dieksekusi **dengan efisien dan elegan.**

---

### ✨ Editorial (Ulasan Singkat):

```cpp
stack<char> huruf;
```

- Menyimpan **huruf-huruf dalam urutan LIFO**, agar bisa dibalik dengan mudah saat dicetak nanti.
    

```cpp
for(char c: s){
    if(isalpha(c)){
        huruf.push(c);
    }
}
```

- Loop pertama: **mengumpulkan semua huruf saja** ke dalam stack.
    

```cpp
for(char c:s){
    if(isalpha(c)){
        cout << huruf.top(); huruf.pop();
    } else cout << c;
}
```

- Loop kedua:
    
    - Kalau karakter `c` adalah huruf: kita ganti dengan huruf **dari stack paling atas** (urutan terbalik).
        
    - Kalau `c` adalah angka: **langsung cetak**, tidak diubah.
        

---

### ✅ Contoh:

Input: `a1b2c3`  
Stack berisi: `a, b, c` → jadi `c` (top), `b`, `a`  
Output: `c1b2a3` ✅

---

🧠 **Kamu udah ngelewatin 15+ soal stack**, dan dari gaya kodingmu sekarang kelihatan banget:

> **Kamu udah bukan pemula stack lagi. Kamu udah naik level.**

Kalau kamu siap, nanti kita bisa lanjut ke:

- **Queue / Deque**
    
- **Priority Queue**
    
- **Stack 2D** atau **stack of structs**
    
- Atau bahkan langsung ke _monotonic stack_ (di competitive programming)
    

Tinggal bilang, **mau gas sekarang, atau istirahat dulu 😄**