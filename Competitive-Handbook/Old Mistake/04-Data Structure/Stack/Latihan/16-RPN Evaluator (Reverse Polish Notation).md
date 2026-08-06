---
obsidianUIMode: preview
note_type: latihan
latihan: RPN Evaluator (Reverse Polish Notation)
sumber: Google.com, AI
tags:
  - data-structure
  - stack
date_learned: 2025-06-15T23:43:00
---
---
# 📘 Soal Stack 8 — _RPN Evaluator (Reverse Polish Notation)_

### 🔎 Deskripsi:

Kamu diberikan sebuah ekspresi matematika dalam format **postfix** (Reverse Polish Notation). Tugasmu adalah menghitung hasil ekspresi tersebut menggunakan struktur data **stack**.

---

### 📥 Format Input:

Satu baris string berisi ekspresi postfix.  
Token-token dipisahkan oleh spasi. Token bisa berupa:

- Angka (1 digit, dari `0` sampai `9`)
    
- Operator: `+`, `-`, `*`, `/`
    

---

### 📤 Format Output:

Satu bilangan bulat: hasil akhir evaluasi ekspresi postfix tersebut.

---

### 🧪 Contoh Input:

```
5 1 2 + 4 * + 3 -
```

### ✅ Contoh Output:

```
14
```

---

### 💡 Penjelasan Langkah:

```
5 1 2 + 4 * + 3 -
→ 5 (1 + 2) * 4 + 3 -
→ 5 3 * 4 + 3 -
→ 5 12 + 3 -
→ 17 3 -
→ 14
```

---

### 🔐 Constraint:

- Ekspresi selalu valid.
    
- Tidak ada pembagian oleh nol.
    
- Semua angka hanya satu digit.
    

---

Silakan dikerjakan. Kalau kamu ingin minta kerangka kodenya, cukup bilang aja. Semangat! 💪
# Editorial
Berikut **kode solusi C++** dan **penjelasan editorial** lengkap untuk soal **Stack #8 – RPN Evaluator (Reverse Polish Notation)**.

---

## ✅ Kode C++:

```cpp
#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

int main() {
    string s;
    getline(cin >> ws, s); // Membaca satu baris input postfix expression

    stack<int> st;
    stringstream ss(s);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            // Jika token berupa angka (0-9), ubah jadi int dan push ke stack
            st.push(token[0] - '0');
        } else {
            // Token adalah operator, ambil dua angka dari stack
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int hasil;

            if (token == "+") hasil = a + b;
            else if (token == "-") hasil = a - b;
            else if (token == "*") hasil = a * b;
            else if (token == "/") hasil = a / b;

            // Simpan hasil operasi kembali ke stack
            st.push(hasil);
        }
    }

    // Hasil akhir adalah elemen terakhir di stack
    cout << st.top() << "\n";
    return 0;
}
```

---

## 🧠 Editorial dan Penjelasan:

### 💡 Tujuan:

Mengevaluasi ekspresi postfix (RPN) seperti `5 1 2 + 4 * + 3 -` menjadi hasil perhitungan yang benar, menggunakan **stack**.

---

### 🔄 Algoritma:

1. **Baca input** sebagai satu baris string.
    
2. Gunakan `stringstream` untuk memisahkan token-token berdasarkan spasi.
    
3. Untuk setiap token:
    
    - Jika token berupa angka (misalnya `"5"`), ubah ke integer dan masukkan ke stack.
        
    - Jika token berupa operator (`+`, `-`, `*`, `/`):
        
        - Ambil dua elemen paling atas dari stack (`b` dan `a`).
            
        - Hitung `a <operator> b`.
            
        - Masukkan hasilnya kembali ke stack.
            
4. Setelah semua token diproses, hasil akhir berada di puncak stack.
    

---

### 🧪 Contoh:

Input:

```
5 1 2 + 4 * + 3 -
```

Langkah:

```
Stack: [5]
→ Token '1' → push → [5, 1]
→ Token '2' → push → [5, 1, 2]
→ Token '+' → pop 2 dan 1 → 1+2=3 → push 3 → [5, 3]
→ Token '4' → push → [5, 3, 4]
→ Token '*' → 3*4=12 → push 12 → [5, 12]
→ Token '+' → 5+12=17 → push 17 → [17]
→ Token '3' → push → [17, 3]
→ Token '-' → 17-3=14 → push 14 → [14]
```

Output:

```
14
```

---

### 🧱 Kenapa Pakai Stack?

Karena stack menyimpan operand secara **LIFO (Last In First Out)**, sangat cocok untuk evaluasi postfix di mana operand muncul sebelum operator.

---

Jika kamu ingin versi yang mendukung angka lebih dari satu digit (misalnya `12 3 +`), tinggal ubah `isdigit(token[0])` jadi pengecekan `isdigit` untuk seluruh `token`, atau pakai `stoi(token)`.

Siap lanjut ke variasi berikutnya kalau kamu mau! 💪