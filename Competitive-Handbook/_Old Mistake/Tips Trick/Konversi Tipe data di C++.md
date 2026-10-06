---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Konvert tipe data
sumber: chatgpt.com
tags:
  - syntax
  - tipe-data
  - konvert-tipe-data
---
#syntax #tipe-data #konvert-tipe-data 

---
# Konversi Tipe Data
Berikut adalah daftar **konversi antar tipe data di C++** yang rapi dan lengkap (bisa langsung kamu salin ke Obsidian). Aku kelompokkan berdasarkan **sumber data** dan ditujukan untuk penggunaan umum di competitive programming atau pengembangan biasa.


## 📌 Konversi antar Tipe Data Dasar


### 🔢 int ↔ string

- **int → string:**
    
    ```cpp
    std::to_string(x);
    ```
    
- **string → int:**
    
    ```cpp
    std::stoi(s);
    ```
    

---

### 🔢 long long ↔ string

- **long long → string:**
    
    ```cpp
    std::to_string(x);
    ```
    
- **string → long long:**
    
    ```cpp
    std::stoll(s);
    ```
    

---

### 🔢 float/double ↔ string

- **float/double → string:**
    
    ```cpp
    std::to_string(x);  // Hasil bisa panjang, gunakan std::ostringstream untuk format
    ```
    
- **string → float:**
    
    ```cpp
    std::stof(s);
    ```
    
- **string → double:**
    
    ```cpp
    std::stod(s);
    ```
    

---

### 🔢 char ↔ int

- **char → int:**
    
    ```cpp
    int x = c - '0';        // Jika c adalah digit
    int x = static_cast<int>(c);  // ASCII value
    ```
    
- **int → char:**
    
    ```cpp
    char c = x + '0';       // Jika x adalah digit 0–9
    char c = static_cast<char>(x);  // ASCII code
    ```
    

---

### 🔢 char ↔ string

- **char → string:**
    
    ```cpp
    std::string s(1, c);  // buat string dengan 1 karakter
    ```
    
- **string → char:**
    
    ```cpp
    char c = s[0];  // karakter pertama
    ```
    

---

### 🔢 bool ↔ string

- **bool → string:**
    
    ```cpp
    std::string s = (b ? "true" : "false");
    ```
    
- **string → bool:**
    
    ```cpp
    bool b = (s == "true");  // Atau buat parser khusus
    ```
    

---

### 🔢 int ↔ float/double

- **int → float/double:**
    
    ```cpp
    float f = static_cast<float>(x);
    double d = static_cast<double>(x);
    ```
    
- **float/double → int:**
    
    ```cpp
    int x = static_cast<int>(d);  // pembulatan ke bawah (trunc)
    ```
    

---

## 📦 Konversi Tipe Koleksi (Bonus)

### 🔃 vector → string

```cpp
std::string s(vec.begin(), vec.end());
```

---

### 🔃 string → vector

```cpp
std::vector<char> vec(s.begin(), s.end());
```

---

### 🔃 vector → set (atau sebaliknya)

```cpp
std::set<int> s(vec.begin(), vec.end());
std::vector<int> vec(s.begin(), s.end());
```

---

### 🔃 stringstream (umum untuk parsing)

```cpp
std::stringstream ss(s);
int x;
ss >> x;  // baca integer dari string
```
