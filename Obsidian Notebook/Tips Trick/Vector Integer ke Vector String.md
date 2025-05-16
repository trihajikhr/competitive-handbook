---
obsidianUIMode: preview
note_type: tips trick
tips_trick: konversi tipe data vector
sumber: chatgpt.com
tags:
  - syntax
  - konvert-tipe-data
  - tipe-data
---
#syntax #konvert-tipe-data #tipe-data 

---
# Vector Integer ke Vector String
Untuk mengkonversi `vector<int>` ke `vector<string>` di C++, kamu bisa melakukannya dengan **loop dan `std::to_string`**. Berikut adalah cara umumnya:

---

## 🔃 **`vector<int>` → `vector<string>`**

```cpp
std::vector<int> vec_int = {1, 23, 456};
std::vector<std::string> vec_str;

for (int x : vec_int) {
    vec_str.push_back(std::to_string(x));
}
```

---

### 📝 Penjelasan:

- `std::to_string(x)` mengubah integer menjadi string.
    
- `vec_str.push_back(...)` menyimpan string hasil konversi ke dalam `vector<string>`.
    

---

### ✅ Jika ingin dalam bentuk fungsi:

```cpp
std::vector<std::string> convertToStringVector(const std::vector<int>& vec_int) {
    std::vector<std::string> vec_str;
    for (int x : vec_int) {
        vec_str.push_back(std::to_string(x));
    }
    return vec_str;
}
```
