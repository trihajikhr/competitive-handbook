---
obsidianUIMode: preview
note_type: latihan
latihan: Konversi Infix ke Postfix
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:47:00
---
---
# 🧠 Soal Stack 8 – Konversi Infix ke Postfix

**Deskripsi:**  
Diberikan sebuah ekspresi aritmatika infix yang hanya berisi:

- Variabel/huruf kecil `a`–`z`
    
- Operator `+`, `-`, `*`, `/`, `^` (pangkat)
    
- Tanda kurung `(` dan `)`
    

Konversikan ekspresi tersebut ke bentuk postfix (RPN) tanpa spasi.

---

**Format Input:**

- Satu baris string `S` (1 ≤ |S| ≤ 100), valid infix expression tanpa spasi.
    

**Format Output:**

- Satu baris string, ekspresi dalam notasi postfix.
    

---

**Contoh 1**  
Input:

```
a+b*c
```

Output:

```
abc*+
```

**Contoh 2**  
Input:

```
(a+b)*c
```

Output:

```
ab+c*
```

**Contoh 3**  
Input:

```
a^b^c
```

Output:

```
abc^^
```

> Catatan: Operator `^` adalah right‑associative (a^(b^c) → abc^^).

---

### 🔑 Petunjuk Implementasi

1. **Scan** setiap karakter `ch` di infix dari kiri ke kanan.
    
2. **Jika** `ch` huruf/operand → langsung **tambah** ke hasil postfix.
    
3. **Jika** `ch` adalah `(` → `push(ch)` ke stack.
    
4. **Jika** `ch` adalah `)` → **pop** dari stack ke postfix hingga menemukan `(`, lalu buang `(`.
    
5. **Jika** `ch` adalah operator →
    
    - **While** stack tidak kosong **dan**  
        (precedence(top) > precedence(ch) **atau** (precedence(top) == precedence(ch) **dan** operator ch **left‑associative**))  
        → **pop** top ke postfix.
        
    - Kemudian **push(ch)**.
        
6. Setelah scan selesai, **pop** semua sisa operator di stack ke postfix.
    

|Operator|Precedence|Associativity|
|:-:|:-:|:-:|
|^|4|right‑associative|
|* /|3|left‑associative|
|+ -|2|left‑associative|

---

Setelah kamu coba implementasi, kita bisa diskusikan edge‑case seperti berurutan kurung atau operator invalid. Selamat mencoba!

## Jawabanku
Karena ku tidak kunjung menemukan solusi valid yang bisa manangani semua edge case, maka beriut jawabanku:

```cpp
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

int main() {
    string s; cin >> s;
    stack<char> st;

    for(char c : s){
        if(isalpha(c)){
            cout << c;
        } else if(c == '('){
            st.push(c);
        } else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                cout << st.top(); st.pop();
            }
            if(!st.empty()) st.pop(); // buang '('
        } else {
            while(!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(c) ||
                  (precedence(st.top()) == precedence(c) && !isRightAssociative(c)))){
                cout << st.top(); st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        cout << st.top(); st.pop();
    }

    cout << "\n";
    return 0;
}
```

# Editorial
Tentu! Berikut adalah **editorial lengkap** untuk solusi konversi **infix ke postfix** menggunakan struktur data **stack**, berdasarkan algoritma **Shunting Yard** karya Edsger Dijkstra. Editorial ini akan dijelaskan secara **baris per baris**, agar kamu bisa memahami setiap komponennya secara menyeluruh.

---

## 💡 **Judul:** Konversi Ekspresi Infix ke Postfix Menggunakan Stack

### 🎯 **Tujuan Soal**

Mengubah ekspresi aritmatika dalam notasi **infix** (misalnya `a+b*c`) menjadi **postfix** atau **Reverse Polish Notation** (misalnya `abc*+`), dengan memperhatikan:

- **Operator precedence** (urutan prioritas),
    
- **Operator associativity** (kiri atau kanan),
    
- **Penanganan tanda kurung**.
    

---

## ✅ **Solusi Lengkap:**

```cpp
#include<iostream>
#include<stack>
#include<string>
using namespace std;
```

### 📌 Penjelasan:

- Mengimpor library yang dibutuhkan.
    
- `stack` digunakan untuk menyimpan operator selama pemrosesan ekspresi.
    

---

```cpp
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
```

### 📌 Penjelasan:

- Fungsi `precedence()` menentukan prioritas operator.
    
- `^` (pangkat) memiliki prioritas tertinggi (3),
    
- `*` dan `/` prioritas menengah (2),
    
- `+` dan `-` prioritas terendah (1).
    

---

```cpp
bool isRightAssociative(char op) {
    return op == '^';
}
```

### 📌 Penjelasan:

- Operator `^` adalah **right-associative**, artinya dievaluasi dari kanan ke kiri.
    
    - Contoh: `a^b^c` → `a^(b^c)` → `abc^^`
        

---

```cpp
int main() {
    string s; cin >> s;
    stack<char> st;
```

### 📌 Penjelasan:

- Membaca ekspresi infix sebagai string.
    
- Inisialisasi stack `st` untuk menampung operator dan tanda kurung.
    

---

```cpp
    for(char c : s){
        if(isalpha(c)){
            cout << c;
```

### 📌 Penjelasan:

- Jika `c` adalah huruf (variabel `a–z`), langsung dicetak ke output (karena operand selalu langsung dimasukkan ke postfix tanpa stack).
    

---

```cpp
        } else if(c == '('){
            st.push(c);
```

### 📌 Penjelasan:

- Jika karakter `c` adalah `'('`, masukkan ke stack sebagai penanda batas ekspresi yang dikelompokkan.
    

---

```cpp
        } else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                cout << st.top(); st.pop();
            }
            if(!st.empty()) st.pop(); // buang '('
```

### 📌 Penjelasan:

- Jika `c` adalah `')'`, keluarkan semua operator dari stack hingga bertemu `'('`.
    
- Jangan mencetak `'('`, hanya dibuang (tidak tampil di postfix).
    

---

```cpp
        } else {
            while(!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(c) ||
                  (precedence(st.top()) == precedence(c) && !isRightAssociative(c)))){
                cout << st.top(); st.pop();
            }
            st.push(c);
        }
    }
```

### 📌 Penjelasan:

- Jika `c` adalah operator (`+`, `-`, `*`, `/`, `^`):
    
    - Lakukan **pop dari stack ke output** jika:
        
        - Operator di atas stack memiliki **prioritas lebih tinggi** dari `c`, atau
            
        - Prioritasnya sama dan `c` adalah **left-associative**.
            
- Setelah itu, **push** operator `c` ke stack.
    

---

```cpp
    while(!st.empty()){
        cout << st.top(); st.pop();
    }
```

### 📌 Penjelasan:

- Setelah semua karakter selesai diproses, keluarkan sisa operator dari stack ke output.
    

---

```cpp
    cout << "\n";
    return 0;
}
```

---

## 📌 **Contoh Eksekusi:**

### 🧪 Input:

```
(a+b)*c
```

### 🧾 Langkah:

1. `(` → push ke stack
    
2. `a` → output
    
3. `+` → push
    
4. `b` → output
    
5. `)` → pop `+`, buang `(`
    
6. `*` → push
    
7. `c` → output
    
8. Selesai → pop `*`
    

### ✅ Output:

```
ab+c*
```

---

## 🎓 **Kesimpulan:**

|Komponen|Penjelasan|
|---|---|
|Stack|Menyimpan operator sementara|
|Precedence|Menentukan urutan operator dievaluasi|
|Associativity|Menentukan arah evaluasi jika prioritas sama|
|Operand (a-z)|Langsung dikirim ke output postfix|
|Kurung|Mengatur batas evaluasi lokal|

---

Jika kamu tertarik, aku juga bisa bantu kamu menambahkan:

- Penanganan kesalahan (invalid infix),
    
- Fungsi terpisah agar kode modular,
    
- Atau bahkan parser untuk memvalidasi ekspresi secara menyeluruh.
    

Ingin coba latihan lanjutan berdasarkan topik ini? 😊