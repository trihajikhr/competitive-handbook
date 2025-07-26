---
obsidianUIMode: preview
note_type: latihan
latihan: Frekuensi Kemunculan Kata
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:17:00
---
---
# 🧩 Soal 3: Frekuensi Kemunculan Kata

**Deskripsi:**

Buat program C++ yang menerima `n` kata dari input, dan mencetak berapa kali masing-masing kata muncul. Gunakan `std::map<string, int>` untuk menghitung frekuensi. Setelah selesai, tampilkan seluruh isi map dalam urutan leksikografis.

---

### 🧪 Contoh Input:

```
6
apel jeruk apel pisang apel jeruk
```

### 📤 Contoh Output:

```
apel 3
jeruk 2
pisang 1
```

---

### 🛠 Petunjuk Implementasi:

- Gunakan loop untuk membaca kata sebanyak `n`.
    
- Setiap kata, tambahkan `+1` ke `map[word]`.
    
- Setelah itu, iterasi seluruh isi map dan cetak hasilnya.
    

---

Kalau sudah selesai, kirimkan jawabanmu ya! Kita akan review seperti biasa.

## Jawabanku
Berikut adalah jawabanku yang sudah optimal:

```cpp
#include<iostream>
#include<map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> dasmap;
    int n; cin >> n;
    string s;

    while(n--){
        cin >> s;
        dasmap[s]++;
    }

    for(const auto& [key, val]: dasmap){
        cout << key << " " << val << "\n";
    }
    
    return 0;
}
```

# Editorial
🔥 **Perfect!**  
Jawabanmu untuk Soal 3 **sangat baik, rapi, dan efisien**. Ini benar-benar implementasi ideal untuk menghitung frekuensi kata menggunakan `std::map`.

---

### ✅ Hal-Hal Positif dari Kode Kamu:

|Aspek|Penjelasan|
|---|---|
|`dasmap[s]++`|Teknik paling singkat dan aman untuk menghitung frekuensi kemunculan.|
|`map<string, int>`|Tipe yang tepat untuk memetakan kata ke jumlah.|
|Loop `for(const auto& [key, val] : map)`|Modern C++ (structured binding), clean and readable.|
|`ios::sync_with_stdio(false);` & `cin.tie(nullptr);`|Mengoptimalkan input/output — cocok untuk data besar.|

---

### 📌 Penjelasan Singkat:

- `dasmap[s]++` akan:
    
    - Menambahkan 1 ke frekuensi kata `s`.
        
    - Jika `s` belum ada di map, maka akan otomatis disisipkan dengan nilai awal 0, lalu langsung jadi 1.
        
- Map akan otomatis **terurut berdasarkan key**, sehingga kamu tidak perlu sorting manual saat mencetak hasil.
    

---

### 📤 Output dari Contoh:

Jika input:

```
6
apel jeruk apel pisang apel jeruk
```

Output-nya:

```
apel 3
jeruk 2
pisang 1
```

---

Kalau kamu sudah paham dan siap, yuk kita lanjut ke **Soal 4: Mendeteksi Kata Duplikat**. Siap?