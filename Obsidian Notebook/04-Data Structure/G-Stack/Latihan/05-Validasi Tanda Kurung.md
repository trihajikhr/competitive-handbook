---
obsidianUIMode: preview
note_type: latihan
latihan: Validasi Tanda Kurung
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:47:00
---
---
# 🧠 Soal Stack 5 – Validasi Tanda Kurung

**Deskripsi:**

Diberikan sebuah string yang terdiri dari tanda kurung bulat `'('` dan `')'`, tanda kurung kurawal `'{'` dan `'}'`, serta tanda kurung siku `'['` dan `']'`. Tentukan apakah tanda kurung dalam string tersebut tersusun dengan benar.

Sebuah susunan dianggap **valid** jika:

- Setiap tanda buka memiliki pasangan tutup yang sesuai dan dalam urutan yang benar.
    
- Tidak ada tanda tutup tanpa pasangan buka.
    

**Format Input:**

- Satu baris string `S` (panjang ≤ 100)
    

**Format Output:**

- Cetak `VALID` jika susunan tanda kurung benar.
    
- Cetak `TIDAK VALID` jika susunan salah.
    

**Contoh Input 1:**

```
{[()]}
```

**Contoh Output 1:**

```
VALID
```

**Contoh Input 2:**

```
([)]
```

**Contoh Output 2:**

```
TIDAK VALID
```

**Contoh Input 3:**

```
((()
```

**Contoh Output 3:**

```
TIDAK VALID
```

---

**Petunjuk Implementasi:**

- Gunakan `stack<char>` untuk menyimpan tanda kurung buka.
    
- Setiap kali menemukan tanda kurung tutup:
    
    - Cek apakah stack kosong (jika iya → tidak valid).
        
    - Cek apakah `top()` adalah pasangan buka yang sesuai.
        
- Di akhir, pastikan stack harus kosong agar semua tanda kurung sudah ditutup.
    

---

Kalau kamu butuh bantuan template dasar atau pengecekan pasangan kurung, tinggal bilang ya! Setelah selesai, kita lanjut ke soal ke-6 yang lebih eksploratif (bisa tema undo-redo, decoding, dll).

## Jawabanku
Kode programku untuk jawaban ini:

```cpp
#include<iostream>
#include<stack>
using namespace std;

int main() {
    string s;
    getline(cin >> ws ,s);

    stack<char> val;
    for(char c:s){
        if(c=='(' || c=='{' || c=='['){
            val.push(c);
        } else {
            if(val.empty()){
                cout << "TIDAK VALID\n";
                return 0;
            }

            char a = val.top();
            if((c==')' && a=='(') || (c=='}' && a=='{') || (c==']' && a=='[')){
                val.pop();
            } else {
                cout << "TIDAK VALID\n";
                return 0;
            }
        }
    }
    
    if(val.empty()) {
        cout << "VALID\n";
    } else {
        cout << "TIDAK VALID\n";
    }

    return 0;
}
```

# Editorial
Berikut editorial lengkap untuk program validasi tanda kurung yang kamu tulis:

---

## 1. Permasalahan

Diberikan sebuah string `s` yang berisi karakter tanda kurung: `()`, `{}`, dan `[]`. Kita perlu memeriksa apakah setiap tanda buka cocok dengan tanda tutup yang sesuai, dan dalam urutan yang benar. Jika semua pasangan cocok dan tidak tersisa, cetak `VALID`; sebaliknya `TIDAK VALID`.

---

## 2. Ide Dasar & Struktur Data

- **Stack** adalah struktur yang paling natural untuk masalah matching tanda kurung karena sifat LIFO‑nya (Last In, First Out): tanda buka terakhir yang muncul harus ditutup lebih dulu.
    
- Saat iterasi string:
    
    1. **Jika** karakter adalah tanda buka (`(`, `{`, `[`), **push** ke stack.
        
    2. **Jika** karakter adalah tanda tutup:
        
        - Jika stack **kosong** → langsung `TIDAK VALID` (tidak ada tanda buka yang menunggu).
            
        - Ambil `top()` stack, periksa apakah tipe bukaannya sesuai.
            
            - Jika sesuai, lakukan **pop()**.
                
            - Jika tidak sesuai, langsung `TIDAK VALID`.
                

---

## 3. Penanganan Sisa Tanda Buka

Setelah memproses semua karakter, kita harus memastikan **stack benar‐benar kosong**. Jika masih ada sisa tanda buka, berarti ada tanda yang tidak ditutup → `TIDAK VALID`.

---

## 4. Detil Implementasi

```cpp
string s;
getline(cin >> ws, s);            // Baca seluruh baris termasuk spasi

stack<char> val;
for (char c : s) {
    if (c=='('||c=='{'||c=='[') {
        val.push(c);             // Simpan tanda buka
    } else {
        if (val.empty()) {       // Tidak ada pasangan buka
            cout<<"TIDAK VALID\n";
            return 0;
        }
        char a = val.top();      // Cek pasangan terdepan
        // Pasangan harus cocok
        if ((c==')'&&a=='(') ||
            (c=='}'&&a=='{') ||
            (c==']'&&a=='[')) {
            val.pop();           // Pasangan cocok, keluarkan
        } else {
            cout<<"TIDAK VALID\n";
            return 0;
        }
    }
}

// Semua karakter sudah diproses
if (val.empty())
    cout<<"VALID\n";
else
    cout<<"TIDAK VALID\n";
```

---

## 5. Kompleksitas

- **Waktu**: O(n), di mana n = panjang string. Setiap karakter diproses sekali, dan operasi stack (`push`, `pop`, `top`, `empty`) adalah O(1).
    
- **Memori**: O(n) di kasus terburuk (semua karakter adalah tanda buka).
    

---

## 6. Corner Cases

- String kosong → stack kosong → `VALID`.
    
- Hanya tanda buka tanpa penutup → sisa di stack → `TIDAK VALID`.
    
- Penutup pertama tanpa pembuka → `TIDAK VALID` pada iterasi pertama.
    
- Kombinasi silang (seperti `([)]`) — akan dideteksi saat perbandingan pasangan.
    

---

Dengan begitu, algoritma ini menjamin pengecekan apakah urutan tanda kurung valid dalam satu kali traversal, menggunakan stack untuk memastikan urutan penutupan yang benar. Semoga membantu memahami tiap baris kodenya! Mau lanjut ke soal berikutnya?