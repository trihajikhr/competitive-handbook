---
obsidianUIMode: preview
note_type: latihan
latihan: Evaluasi Ekspresi Postfix
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:47:00
---
---
# Evaluasi Ekspresi Postfix
Berikut **Soal Stack #6** yang akan melatih kamu menggabungkan semua operasi dasar (`push`, `pop`, `top`, `empty`) dalam konteks **evaluasi ekspresi postfix** (Reverse Polish Notation):

---

### 🧠 Soal Stack 6 – Evaluasi Ekspresi Postfix

**Deskripsi:**

Diberikan sebuah ekspresi aritmatika dalam **postfix notation**, hitung nilainya. Ekspresi hanya terdiri dari bilangan bulat (positif/negatif) dan operator `+`, `-`, `*`, `/`. Semua token (operand maupun operator) dipisahkan oleh spasi.

**Format Input:**

- Satu baris string `S` berisi token postfix, misalnya `"2 3 1 * + 9 -"`
    

**Format Output:**

- Cetak satu bilangan bulat—hasil evaluasi ekspresi.
    

**Contoh Input 1:**

```
2 3 1 * + 9 -
```

**Contoh Output 1:**

```
-4
```

> Penjelasan:
> 
> 1. Push `2`
>     
> 2. Push `3`
>     
> 3. Push `1`
>     
> 4. `*` → pop `1` dan `3`, hitung `3*1=3`, push `3`
>     
> 5. `+` → pop `3` dan `2`, hitung `2+3=5`, push `5`
>     
> 6. Push `9`
>     
> 7. `-` → pop `9` dan `5`, hitung `5-9=-4`, push `-4`  
>     Hasil akhir di stack: `-4`
>     

**Contoh Input 2:**

```
5 6 + 2 3 * -
```

**Contoh Output 2:**

```
-1
```

---

**Petunjuk Implementasi:**

1. **Split** string input berdasarkan spasi (gunakan `istringstream` atau `stringstream`).
    
2. Buat `stack<int> st;`
    
3. Untuk setiap token:
    
    - Jika token adalah angka (cek dengan `isdigit()` pada karakter pertama atau coba `stoi()` dan tangani exception), lakukan `st.push(angka)`.
        
    - Jika token adalah operator (`+`, `-`, `*`, `/`):
        
        1. Pastikan `st.size() >= 2`.
            
        2. `b = st.top(); st.pop();`
            
        3. `a = st.top(); st.pop();`
            
        4. Hitung `res = a <op> b`.
            
        5. `st.push(res);`
            
4. Setelah semua token diproses, hasil ada di `st.top()`.
    

---

Kamu ingin:

- ✔️ **Template kode** C++ untuk mulai coba-coba?
    
- ✔️ Membuat **tes kasus tambahan**?
    
- ✔️ Diskusi kompleksitas atau edge‑case (misalnya pembagian oleh nol)?
    

Tinggal pilih, dan kita lanjut!

## Jawabanku
Berikut adalah jawabanku untuk soal ini, walaupun masih ada beberapa perbaikan yang masih dbisa dilakukan:

```cpp
#include<iostream>
#include<stack>
#include<sstream>
#include<cctype>
using namespace std;

pair<int,int> rest (stack<int>&operasi){
    int a, b;
    b = operasi.top(); operasi.pop();
    a = operasi.top(); operasi.pop();
    return {a,b};
}

int main() {
    string s; 
    getline(cin >> ws, s);

    stack<int> operasi;
    stringstream ss(s);
    
    char opr;
    while(ss >> opr){
        if(isdigit(static_cast<int>(opr))){
            operasi.push(opr-'0');
        } else {
            int a,b;
            if(operasi.size()>=2){
                auto [a,b] = rest(operasi);
                if(opr=='*'){
                    operasi.push(a*b);
                } else if(opr=='+'){
                    operasi.push(a+b);
                } else if (opr=='-'){
                    operasi.push(a-b);
                } else if (opr=='/'){
                    operasi.push(a/b);
                }
            }
        }
    }

    while(!operasi.empty()){
        cout << operasi.top() << " ";
        operasi.pop();
    }
    return 0;
}
```

# Editorial
Keren! Kamu sudah hampir berhasil menyelesaikan soal evaluasi postfix. Namun, ada beberapa **catatan penting dan perbaikan yang perlu dilakukan** agar program ini berjalan dengan benar, terutama untuk:

- Angka lebih dari 1 digit (misalnya `12`)
    
- Bilangan negatif
    
- Output akhir yang hanya 1 nilai (bukan di-loop sampai kosong)
    

---

## 🧠 Review & Penjelasan Kode Kamu

### ✅ Yang sudah bagus:

- Menggunakan `stack<int>` dengan baik
    
- Memisahkan operand dengan fungsi `rest()` → clean dan reusable
    
- Struktur `stringstream` untuk parsing
    

---

## ❌ Masalah & Solusi

### 1. **Parsing angka hanya satu digit**

Bagian ini:

```cpp
if(isdigit(static_cast<int>(opr))){
    operasi.push(opr - '0');
}
```

→ Salah, karena `ss >> opr` hanya membaca **satu karakter**, bukan token. Jadi `12` akan dibaca sebagai `'1'`, lalu `'2'` (dua kali loop).

---

### ✅ Solusi: Ubah ke string lalu cek apakah itu angka

Ubah deklarasi jadi:

```cpp
string token;
while (ss >> token) {
    if (isdigit(token[0]) || 
       (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
        operasi.push(stoi(token));
    } else {
        auto [a, b] = rest(operasi);
        if (token == "*") operasi.push(a * b);
        else if (token == "+") operasi.push(a + b);
        else if (token == "-") operasi.push(a - b);
        else if (token == "/") operasi.push(a / b);
    }
}
```

---

### 2. **Output akhir**

Program kamu mencetak semua isi stack:

```cpp
while(!operasi.empty()){
    cout << operasi.top() << " ";
    operasi.pop();
}
```

Padahal hasil akhirnya hanya 1 nilai saja di `operasi.top()`.

✅ Ganti dengan:

```cpp
cout << operasi.top() << "\n";
```

---

## 🛠️ Revisi Akhir Kode:

```cpp
#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

pair<int,int> rest(stack<int>& operasi){
    int b = operasi.top(); operasi.pop();
    int a = operasi.top(); operasi.pop();
    return {a, b};
}

int main() {
    string s;
    getline(cin >> ws, s);
    
    stack<int> operasi;
    stringstream ss(s);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            operasi.push(stoi(token));
        } else {
            auto [a, b] = rest(operasi);
            if (token == "+")      operasi.push(a + b);
            else if (token == "-") operasi.push(a - b);
            else if (token == "*") operasi.push(a * b);
            else if (token == "/") operasi.push(a / b); // pastikan b ≠ 0
        }
    }

    cout << operasi.top() << "\n";
    return 0;
}
```

---

## ✅ Tes Ulang

**Input:**

```
2 3 1 * + 9 -
```

**Output:**

```
-4
```

---

Kalau sudah paham, siap lanjut ke **Soal Stack #7**? Mau tema:

- `undo-redo` simulasi
    
- konversi infix → postfix
    
- atau nyusun ekspresi matematika dari string biasa?
    

Tinggal pilih gaya tantanganmu!

## Kode perbaikan
Berikut adaalh kode yang sudah aku perbaiki sedemikian rupa mengikuti contoh yang ada pada editorial:

```cpp
#include<iostream>
#include<stack>
#include<sstream>
#include<cctype>
using namespace std;

pair<int,int> rest (stack<int>&operasi){
    int a, b;
    b = operasi.top(); operasi.pop();
    a = operasi.top(); operasi.pop();
    return {a,b};
}

int main() {
    string s; 
    getline(cin >> ws, s);

    stack<int> operasi;
    stringstream ss(s);
    
    string opr;
    while(ss >> opr){
        if (isdigit(opr[0]) || 
            (opr.size() > 1 && opr[0] == '-' && isdigit(opr[1]))) {
            operasi.push(stoi(opr));
        } else {
            int a,b;
            if(operasi.size()>=2){
                auto [a,b] = rest(operasi);
                if(opr=="*")      operasi.push(a*b);
                else if(opr=="+") operasi.push(a+b);
                else if(opr=="-") operasi.push(a-b);
                else if(opr=="/")operasi.push(a/b);
            }
        }
    }

    cout << operasi.top() << "\n";
    return 0;
}
```

# Kasus Edge Case
> Nah loh, kalau kaya gini gimana coba? 18765hh90? Pasti tidak valid dong elah!

Wah, ini **kasus penting banget** buat dipertimbangkan saat parsing ekspresi postfix:  
Input seperti `18765hh90` **tidak valid**, karena mengandung **token campuran angka dan huruf** (`hh`) atau bahkan token yang bukan operator apapun.

---

### 📌 Masalah:

Kodenya saat ini langsung memanggil `stoi(token)` jika token diawali angka atau `-`, tanpa mengecek apakah token itu **benar-benar angka murni**.

Misalnya:

```cpp
stoi("90") → ✅ OK  
stoi("hh") → ❌ runtime error (invalid_argument exception)  
stoi("18765hh90") → ❌ juga error
```

---

## ✅ Solusi: Validasi token sebelum `stoi`

### 🔒 Tambahkan fungsi pengecekan apakah token adalah integer valid

```cpp
bool isInteger(const string& s) {
    if (s.empty()) return false;
    int start = (s[0] == '-' ? 1 : 0);
    if (start == 1 && s.size() == 1) return false; // hanya '-' saja

    for (int i = start; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}
```

---

## 🛠 Update kode:

```cpp
#include<iostream>
#include<stack>
#include<sstream>
using namespace std;

bool isInteger(const string& s) {
    if (s.empty()) return false;
    int start = (s[0] == '-' ? 1 : 0);
    if (start == 1 && s.size() == 1) return false;
    for (int i = start; i < s.size(); i++) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

pair<int,int> rest(stack<int>& operasi){
    int b = operasi.top(); operasi.pop();
    int a = operasi.top(); operasi.pop();
    return {a, b};
}

int main() {
    string s;
    getline(cin >> ws, s);
    
    stack<int> operasi;
    stringstream ss(s);
    string token;

    while (ss >> token) {
        if (isInteger(token)) {
            operasi.push(stoi(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (operasi.size() < 2) {
                cout << "ERROR: Jumlah operand tidak cukup.\n";
                return 0;
            }
            auto [a, b] = rest(operasi);
            if (token == "+")      operasi.push(a + b);
            else if (token == "-") operasi.push(a - b);
            else if (token == "*") operasi.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    cout << "ERROR: Pembagian oleh nol.\n";
                    return 0;
                }
                operasi.push(a / b);
            }
        } else {
            cout << "ERROR: Token tidak dikenali → \"" << token << "\"\n";
            return 0;
        }
    }

    if (operasi.size() != 1) {
        cout << "ERROR: Ekspresi tidak valid.\n";
    } else {
        cout << operasi.top() << "\n";
    }

    return 0;
}
```

---

## ✨ Sekarang input seperti:

- `18765hh90` → ❌ `"Token tidak dikenali → \"18765hh90\""`
    
- `2 3 + +` → ❌ `"Jumlah operand tidak cukup"`
    
- `4 0 /` → ❌ `"Pembagian oleh nol"`
    
- `2 3 +` → ✅ `5`
    

---

Siap lanjut ke **Soal Stack #7**? Mau versi permainan `undo-redo`, atau kamu punya ide sendiri soal stack yang ingin kamu kuasai dulu?


