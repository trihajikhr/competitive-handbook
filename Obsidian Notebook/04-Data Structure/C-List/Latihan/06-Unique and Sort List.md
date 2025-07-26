---
obsidianUIMode: preview
note_type: latihan
latihan: Unique and Sort List
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T13:22:00
---
---
Siap! Kita lanjut ke Soal 6, masih menggunakan `std::list` dari C++ STL, tapi kali ini kita gabungkan pengurutan dinamis dan operasi unik agar kamu terbiasa dengan kombinasi STL yang lebih kompleks.
# Soal 6: Unique & Sort List

### 📝 Deskripsi:

Kamu mengelola daftar angka yang dapat bertambah secara dinamis, dan kadang kamu perlu menghapus duplikat atau mengurutkannya. Tugasmu adalah memproses perintah berikut:

### 📥 Input:

Baris pertama berisi bilangan bulat **N** – jumlah perintah.  
Setiap dari N baris berikutnya berisi salah satu dari perintah berikut:

- `"ADD x"` — Tambahkan `x` ke akhir list
    
- `"SORT"` — Urutkan list secara menaik
    
- `"UNIQUE"` — Hapus elemen yang duplikat (berurutan) dari list
    
- `"PRINT"` — Cetak isi list dari depan ke belakang, atau cetak `EMPTY` jika kosong
    

### 📤 Output:

Untuk setiap perintah `PRINT`, cetak isi list dalam satu baris, dipisahkan spasi. Jika kosong, cetak `EMPTY`.

### ⚙️ Batasan:

- `1 <= N <= 1000`
    
- `-10^9 <= x <= 10^9`
    
- Panjang list tidak akan melebihi 10^4

### ❗ Catatan:

- `UNIQUE` hanya menghapus elemen **duplikat yang berdampingan** (seperti `std::unique`)
    
- Jadi, agar semua duplikat hilang, biasanya kamu perlu `SORT` dulu, baru `UNIQUE`

### 💡 Contoh Input:

```
9
ADD 5
ADD 3
ADD 5
ADD 3
SORT
UNIQUE
PRINT
ADD 3
PRINT
```

### 💬 Contoh Output:

```
3 5
3 5 3
```


### 💡 Penjelasan:

- Setelah `SORT`: `3 3 5 5`
    
- Setelah `UNIQUE`: `3 5`
    
- Setelah `ADD 3`: `3 5 3`
    

# Jawabanku
## Tanpa fungsi `sort()`
Karena aku belum mengetahui bahwa terdapat fungsi `sort()` untuk data structure `list`, maka aku menggunakan bantuan vector untuk mensorting data list, sebagai berikut:

```cpp
#include<iostream>
#include<iterator>
#include<algorithm>
#include<sstream>
#include<list>
#include<vector>
using namespace std;

void sorting(list<int>& dalist){
    vector<int> temp;
    for(const auto& x : dalist){
        temp.push_back(x);
    }

    sort(temp.begin(), temp.end());
    int idx=0;
    for(auto&x:dalist) {
        x = temp[idx++];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    list<int>::iterator itr;

    int n; cin >> n;
    while(n--) {
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int val;
        ss >> cmd;

        if(cmd == "ADD") {
            ss >> val;
            dalist.push_back(val);
        } else if (cmd == "SORT") {
            sorting(dalist);
        } else if(cmd=="UNIQUE") {
            dalist.unique();
        } else if(cmd=="PRINT") {
            if(dalist.empty()) cout << "EMPTY\n";
            else {
                for(const auto&x:dalist){
                    cout << x << " ";
                } cout << endl;
            }
        }
    }
    return 0;
}
```

## Dengan fungsi bawaan `sort()`
Berikut adalah implementasi jika menggunakan fungsi bawaan:

```cpp
#include<iostream>
#include<iterator>
#include<algorithm>
#include<sstream>
#include<list>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    list<int> dalist;
    list<int>::iterator itr;

    int n; cin >> n;
    while(n--) {
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string cmd; int val;
        ss >> cmd;

        if(cmd == "ADD") {
            ss >> val;
            dalist.push_back(val);
        } else if (cmd == "SORT") {
            dalist.sort();
        } else if(cmd=="UNIQUE") {
            dalist.unique();
        } else if(cmd=="PRINT") {
            if(dalist.empty()) cout << "EMPTY\n";
            else {
                for(const auto&x:dalist){
                    cout << x << " ";
                } cout << endl;
            }
        }
    }
    return 0;
}
```

# Editorial
🔥 Sangat bagus! 

Kodenya benar secara fungsi, rapi dalam penulisan, dan kamu juga berinisiatif membuat fungsi `sorting()` sendiri untuk mengurutkan `std::list` — itu keren, tapi ada sedikit catatan yang bisa kita optimalkan agar kamu makin jago.

---

## ✅ Review Per Bagian

### 🔹 `ADD x` — ✅

```cpp
dalist.push_back(val);
```

✔️ Tambah ke belakang list, sesuai deskripsi.

### 🔹 `SORT` — 🚀 Bisa Lebih Efisien

```cpp
void sorting(list<int>& dalist){
    vector<int> temp;
    for(const auto& x : dalist){
        temp.push_back(x);
    }

    sort(temp.begin(), temp.end());
    int idx=0;
    for(auto&x:dalist) {
        x = temp[idx++];
    }
}
```

✔️ Fungsi ini **berhasil mengurutkan list** dengan cara:

1. Salin elemen ke `vector`
    
2. Urutkan `vector`
    
3. Salin kembali ke `list`
    

📌 **Catatan:**  
Sebenarnya `std::list` punya fungsi `.sort()` bawaan STL:

```cpp
dalist.sort();
```

Cara ini lebih efisien, karena:

- Tidak butuh alokasi vector baru
    
- Tidak perlu copy data bolak-balik
    
- Lebih hemat memori dan langsung in-place
    

✅ Jadi kamu **boleh pertahankan fungsi `sorting()` buatanmu untuk latihan**, tapi dalam praktik nyata, cukup:

```cpp
dalist.sort();
```

---

### 🔹 `UNIQUE` — ✅

```cpp
dalist.unique();
```

✔️ Ini hanya menghapus **elemen yang sama dan bersebelahan**, jadi kamu paham bahwa:

- Jika ingin hapus semua duplikat → `SORT` dulu baru `UNIQUE`
    

---

### 🔹 `PRINT` — ✅

```cpp
if(dalist.empty()) cout << "EMPTY\n";
else {
    for(const auto& x : dalist) cout << x << " ";
    cout << endl;
}
```

✔️ Penanganan list kosong dan pencetakan baris sangat baik.

---

## ✅ Uji Coba Contoh

### Input:

```
9
ADD 5
ADD 3
ADD 5
ADD 3
SORT
UNIQUE
PRINT
ADD 3
PRINT
```

### Output:

```
3 5
3 5 3
```

✔️ **Sesuai 100%** dengan output yang diharapkan.

---

## ✍️ Saran Singkat

|Hal|Status|Catatan|
|---|---|---|
|Buat fungsi sort sendiri|✅|Oke, tapi bisa diganti `list.sort()`|
|Pemahaman `unique()`|✅|Tepat sasaran|
|Penulisan kode|✅|Rapi dan konsisten|
|Output format|✅|Akurat dan bersih|
