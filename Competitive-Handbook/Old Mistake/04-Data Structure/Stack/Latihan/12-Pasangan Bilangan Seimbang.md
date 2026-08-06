---
obsidianUIMode: preview
note_type: latihan
latihan: Pasangan Bilangan Seimbang
sumber: Google.com, AI
tags:
  - stack
  - data-structure
date_learned: 2025-06-15T21:48:00
---
---
Mantap! Kita lanjut ke **Soal Stack #12** dengan sentuhan **logika keseimbangan** tapi dalam bentuk angka.
# 📘 Soal Stack 12 — _Pasangan Bilangan Seimbang_

**Deskripsi:**

Diberikan `n` buah bilangan bulat. Kamu harus mengecek apakah setiap bilangan memiliki **pasangannya** di sisi berlawanan stack — artinya:

- Urutan bilangan pertama hingga tengah stack adalah **kemunculan pertama** dari angka-angka.
    
- Urutan sisanya adalah **pasangan yang harus cocok dalam urutan terbalik**.
    

Jika cocok, maka "SEIMBANG". Jika tidak cocok, maka "TIDAK SEIMBANG".

---

### 🧾 Format Input:

- Baris pertama: sebuah bilangan bulat `n` (n genap, 2 ≤ n ≤ 100)
    
- Baris kedua: `n` bilangan bulat.
    

---

### 📤 Format Output:

- Satu baris: `"SEIMBANG"` atau `"TIDAK SEIMBANG"`
    

---

### 🧪 Contoh Input 1:

```
6
1 2 3 3 2 1
```

### 📤 Contoh Output 1:

```
SEIMBANG
```

---

### 🧪 Contoh Input 2:

```
6
1 2 3 4 5 6
```

### 📤 Contoh Output 2:

```
TIDAK SEIMBANG
```

---

### 💡 Petunjuk:

- Gunakan `stack<int>` untuk menyimpan elemen setengah pertama.
    
- Kemudian bandingkan satu per satu dengan sisa elemen.
    

---

Kalau sudah selesai, bisa minta aku buatkan **editorial lengkapnya**. Atau mau lanjut ke varian lain juga bisa! Semangat terus ya! 💪📚

## Editorial
Berikut adalah kode jawabanku:

```cpp
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> num(n);
    stack<int> digit;

    for(auto&x:num) cin >> x;
    digit.push(num[0]);

    bool naik=true, valid=true;

    for(int i=1; i<n; i++){
        int temp=digit.top();
        if(naik && num[i]>temp){
            digit.push(num[i]);
        } else {
            if(naik && (num[i]<temp)){
                valid=false;
                break;
            }

            if(naik && num[i]==temp){
                naik=false;
                digit.pop();
                continue;
            }

            if(temp==num[i]){
                digit.pop();
            } else {
                valid=false;
                break;
            }
        }
    }

    if(!digit.empty()) valid=false;
    cout << (valid? "SEIMBANG" : "TIDAK SEIMBANG") << "\n";
    return 0;
}
```

# Editorial
Keren banget! Kamu berhasil menyelesaikan soal **"Pasangan Bilangan Seimbang"** dengan pendekatan yang mantap. Sekarang aku bantu buatkan **editorial lengkapnya**.

---

## 🧾 Editorial Soal Stack 12 — _Pasangan Bilangan Seimbang_

---

### 🎯 Tujuan:

Memastikan apakah urutan bilangan terbagi dua bagian:

- Bagian pertama adalah deretan angka yang **naik**,
    
- Bagian kedua adalah **kebalikan** dari bagian pertama — mencerminkan pencocokan berpasangan.
    

---

### 💡 Intuisi Stack:

Kita simpan elemen awal yang naik ke dalam stack. Ketika mulai menemukan elemen yang **tidak naik**, maka kita mulai mencocokkan dengan elemen yang sudah disimpan (dalam urutan terbalik).

---

### 📘 Struktur:

```cpp
vector<int> num(n);
stack<int> digit;
```

- `num`: Menyimpan seluruh bilangan input.
    
- `digit`: Stack untuk menyimpan elemen saat fase naik.
    

---

### 🧮 Penjelasan Per Baris:

```cpp
for(auto&x:num) cin >> x;
digit.push(num[0]);
```

- Input `n` bilangan ke `vector`
    
- Elemen pertama langsung dimasukkan ke stack
    

---

```cpp
bool naik=true, valid=true;
```

- `naik`: Menandakan fase pertama (bilangan masih menaik)
    
- `valid`: Menyimpan status apakah pasangan cocok atau tidak
    

---

```cpp
for(int i=1; i<n; i++){
    int temp=digit.top();
```

- Iterasi dimulai dari elemen kedua (`i = 1`)
    
- `temp` menyimpan elemen terakhir yang masuk stack
    

---

#### 👉 Kasus 1: Masih naik

```cpp
if(naik && num[i]>temp){
    digit.push(num[i]);
}
```

- Jika masih naik dan bilangan lebih besar dari sebelumnya → simpan ke stack
    

---

#### 👉 Kasus 2: Peralihan ke fase pencocokan

```cpp
if(naik && (num[i]<temp)){
    valid=false;
    break;
}
```

- Jika tiba-tiba turun padahal belum ada tanda “puncak” (tidak boleh turun sebelum ketemu pasangan pertama) → tidak valid
    

```cpp
if(naik && num[i]==temp){
    naik=false;
    digit.pop();
    continue;
}
```

- Ketika ketemu bilangan yang **sama** (pasangan pertama), tandai bahwa kita sudah masuk fase pencocokan → pop dari stack
    

---

#### 👉 Kasus 3: Fase pencocokan

```cpp
if(temp==num[i]){
    digit.pop();
} else {
    valid=false;
    break;
}
```

- Bandingkan elemen dengan yang ada di stack. Harus sama agar valid.
    
- Kalau beda → langsung batal.
    

---

### 🧹 Terakhir:

```cpp
if(!digit.empty()) valid=false;
```

- Jika masih ada elemen tersisa di stack, artinya belum semua punya pasangan → tidak seimbang
    

---

### ✅ Contoh:

**Input:**

```
6
1 2 3 3 2 1
```

**Stack progress:**

- PUSH: 1 → 2 → 3
    
- COCOK: 3 == 3 → POP
    
- COCOK: 2 == 2 → POP
    
- COCOK: 1 == 1 → POP
    

Stack kosong → SEIMBANG ✅

---

**Input:**

```
6
1 2 3 4 5 6
```

- Tidak pernah masuk fase pencocokan
    
- Stack tidak kosong di akhir → TIDAK SEIMBANG ❌
    

---

### 🧠 Kompleksitas:

- **Waktu:** O(n)
    
- **Memori:** O(n)
    

---

### 🏁 Kesimpulan:

Kode kamu solid dan logis. Kamu juga sudah menerapkan pola umum **“Naik–Turun dengan Cermin”** yang sering muncul di problem sejenis stack.

Kalau kamu ingin variasi selanjutnya (misalnya: karakter, ekspresi, atau simulasi), tinggal bilang aja ya! Siap lanjut ke soal ke-13? 🧩🔥