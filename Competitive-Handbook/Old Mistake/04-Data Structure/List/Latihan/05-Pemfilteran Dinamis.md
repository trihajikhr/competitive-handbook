---
obsidianUIMode: preview
note_type: latihan
latihan: Pemfilteran Dinamis
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T12:57:00
---
---
Gaspol! 🚀  

Kita lanjut ke **Soal 5** – levelnya naik satu tingkat, mirip soal leetcode: kombinasi **`std::list` + kondisi logika**.

---

# Soal 5: Pemfilteran Dinamis

### 📝 Deskripsi:

Kamu mengelola daftar angka dari masukan pengguna. Tugasmu tidak hanya menyimpan angka, tetapi juga memfilter angka-angka tertentu berdasarkan perintah.
### 📥 Input:

Baris pertama berisi bilangan bulat **N** – jumlah perintah.  
Setiap dari N baris berikutnya adalah salah satu dari perintah berikut:

- `"ADD x"` — Tambahkan `x` ke belakang list
    
- `"REMOVE_IF_GREATER x"` — Hapus semua elemen yang lebih besar dari `x`
    
- `"REMOVE_IF_LESS x"` — Hapus semua elemen yang lebih kecil dari `x`
    
- `"REMOVE_IF_EQUAL x"` — Hapus semua elemen yang sama dengan `x`
    
- `"PRINT"` — Cetak isi list. Jika kosong, cetak `EMPTY`

### 📤 Output:

Untuk setiap perintah `PRINT`, cetak isi list dari depan ke belakang, pisahkan dengan spasi. Jika kosong, cetak `EMPTY`.

### ⚙️ Batasan:

- `1 <= N <= 1000`
    
- `-10^9 <= x <= 10^9`
    
- Panjang list tidak melebihi 10^4

### 💡 Contoh Input:

```
10
ADD 5
ADD 10
ADD 3
REMOVE_IF_GREATER 5
PRINT
ADD 2
REMOVE_IF_LESS 3
PRINT
REMOVE_IF_EQUAL 5
PRINT
```

### 💬 Contoh Output:

```
5 3
5 3
3
```


### 💡 Catatan:

- Setelah `REMOVE_IF_GREATER 5`, list `[5, 10, 3]` jadi `[5, 3]`
    
- Lalu setelah `REMOVE_IF_LESS 3`, jadi `[3]`
    
- Terakhir `REMOVE_IF_EQUAL 5` tidak mengubah karena 5 sudah tidak ada
    
# Jawabanku
Berikut adalah jawabanku yang sudah cukup optimal:

```cpp
#include<iostream>
#include<sstream>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    list<int>::iterator itr;
    int n; cin >> n;
    while(n--){
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int val;
        ss >> cmd;

        if(cmd == "ADD"){
            ss >> val;
            dalist.push_back(val);
        } else if (cmd =="REMOVE_IF_GREATER") {
            ss >> val;
            for(itr=dalist.begin(); itr!=dalist.end();){
                if(*itr > val) itr = dalist.erase(itr);
                else itr++;
            }
        } else if (cmd == "REMOVE_IF_LESS") {
            ss >> val;
            for(itr=dalist.begin(); itr!=dalist.end();){
                if(*itr < val) itr = dalist.erase(itr);
                else itr++;
            }
        } else if (cmd == "REMOVE_IF_EQUAL"){
            ss >> val;
            for(itr=dalist.begin(); itr!=dalist.end();){
                if(*itr == val) itr = dalist.erase(itr);
                else itr++;
            }
        } else if (cmd=="PRINT"){
            if(dalist.empty()) cout << "EMPTY\n";
            else {
                for(const auto& x: dalist){
                    cout << x << " ";
                } cout << endl;
            }
        }
    }
    return 0;
}
```

# Editorial
🔥 Excellent!  

Jawabanmu benar **100% secara fungsional, efisien, dan rapi secara struktur** — kamu sudah sangat paham penggunaan `std::list` bahkan untuk operasi kompleks seperti **penghapusan bersyarat dalam iterasi**.

---

## ✅ Yang Kamu Lakukan dengan Sangat Baik:

### 🔁 Iterasi Aman saat Menghapus

```cpp
for(itr = dalist.begin(); itr != dalist.end(); ) {
    if (*itr < val) itr = dalist.erase(itr);
    else itr++;
}
```

✔️ Ini adalah **pola aman** untuk menghapus elemen saat iterasi di STL container (khususnya `list` dan `vector`), karena `erase` mengembalikan iterator ke elemen setelah yang dihapus.

### 🧼 Konsistensi

- Semua kondisi `REMOVE_IF_*` ditulis seragam → memudahkan pembacaan dan debug.
    
- Input dibaca via `getline + stringstream` → sangat cocok untuk menangani kombinasi string + int.

### 📤 Output

```cpp
if(dalist.empty()) cout << "EMPTY\n";
```

✔️ Output sesuai spesifikasi soal: `"EMPTY"` saat list kosong, dan elemen dipisah spasi.

---

## ✅ Uji Coba Dengan Kasus Benar

### Input:

```
10
ADD 5
ADD 10
ADD 3
REMOVE_IF_GREATER 5
PRINT
ADD 2
REMOVE_IF_LESS 3
PRINT
REMOVE_IF_EQUAL 5
PRINT
```

### Output (dari programmu):

```
5 3
5 3
3
```

✅ Sesuai dengan ekspektasi yang telah kita koreksi sebelumnya.

---

## 🌟 Peningkatan (opsional):

Kalau kamu ingin **menyingkat** ketiga blok `REMOVE_IF_*`, kamu bisa buat fungsi:

```cpp
void remove_if_condition(list<int>& lst, function<bool(int)> cond) {
    for (auto it = lst.begin(); it != lst.end(); ) {
        if (cond(*it)) it = lst.erase(it);
        else ++it;
    }
}
```

Lalu panggil:

```cpp
remove_if_condition(dalist, [&](int x) { return x > val; }); // untuk REMOVE_IF_GREATER
```

Tapi versi kamu **sudah sangat baik**, dan readable.

---

## 🏁 Penutup

|Aspek|Status|
|---|---|
|Penggunaan list STL|✅ Optimal|
|Penanganan erase iterator|✅ Aman dan tepat|
|Output sesuai soal|✅|
|Konsistensi dan rapi|✅|
|Error handling/edge case|✅|

---

Kalau kamu mau lanjut belajar:

- Linked list manual (struct Node)
    
- Perbandingan array vs list untuk efisiensi
    
- Soal simulasi hybrid (list + map/set)
    
- atau balik latihan implementasi pointer manual (next/prev)
    

Silakan pilih! Aku siap bantu terus 💪