---
obsidianUIMode: preview
note_type: latihan
latihan: Kategori dengan Nilai Tertinggi
sumber: chatgpt.com
tags:
  - data-structure
  - map
date_learned: 2025-06-21T19:30:00
---
---
# 🧩 Soal 6: Kategori dengan Nilai Tertinggi

**Deskripsi:**

Diberikan `n` baris input, masing-masing berisi:

- sebuah `string` sebagai kategori
    
- sebuah `int` sebagai nilai
    

Hitung total nilai dari setiap kategori menggunakan `std::map<string, int>`. Lalu, tentukan kategori dengan **total nilai tertinggi**. Jika ada lebih dari satu dengan nilai tertinggi yang sama, cetak yang **leksikografis terkecil**.

---

### 🧪 Contoh Input:

```
6
buah 10
sayur 5
buah 7
daging 20
sayur 3
buah 2
```

### 📤 Contoh Output:

```
daging
```

---

### 🧪 Contoh Input 2:

```
4
a 10
b 15
c 15
d 5
```

### 📤 Contoh Output 2:

```
b
```

_(karena `b` < `c` dalam urutan leksikografis)_

---

### 💡 Petunjuk:

1. Gunakan `map<string, int>` seperti pada soal sebelumnya.
    
2. Setelah mengisi map, cari pasangan dengan nilai maksimum.
    
3. Simpan `nama_kategori_terbaik` dan perbarui jika ada yang nilainya lebih tinggi **atau** sama tapi key-nya lebih kecil (`<`).
    

---

Silakan coba! Kirimkan hasilmu setelah selesai 💪

## Jawabanku
Berikut adalah jawabanku untuk menyelesaikan problem ini:

```cpp
#include<iostream>
#include<map>
#include<climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> dasmap;
    int n; cin >> n;
    string s; int x;

    while(n--){
        cin >> s >> x;
        dasmap[s]+=x;
    }

    int max=INT_MIN;
    string rest;
    for(const auto& [key, val]: dasmap){
        if(val>max){
            max=val;
            rest=key;
        } else if(val==max){
            rest=(rest< key ? rest : key);
        }
    }

    cout << rest << "\n";
    return 0;
}
```

# Editorial
💯 **Excellent!**  
Kamu sudah menyelesaikan **Soal 6** dengan **sangat baik dan benar secara logika, efisiensi, dan gaya penulisan**.

---

### ✅ Penjelasan Kode-mu:

|Bagian|Penjelasan|
|---|---|
|`dasmap[s] += x;`|Menjumlahkan nilai-nilai per kategori secara langsung.|
|`int max = INT_MIN;`|Menyimpan nilai maksimum saat ini — awali dengan nilai paling kecil.|
|`string rest;`|Menyimpan nama kategori dengan nilai maksimum.|
|`if (val > max)`|Update jika menemukan nilai yang lebih besar.|
|`else if (val == max)`|Jika sama, bandingkan secara leksikografis untuk ambil yang lebih kecil.|
|`cout << rest;`|Cetak hanya satu hasil, sesuai permintaan soal.|

---

### 🔁 Contoh Uji:

#### Input:

```
6
buah 10
sayur 5
buah 7
daging 20
sayur 3
buah 2
```

#### Map akhir:

```
buah   → 19  
sayur  → 8  
daging → 20
```

`max = 20` → Output: `daging` ✅

---

### 🧠 Bonus Tips:

- `rest = (rest < key ? rest : key);` — ini benar, tapi bisa lebih jelas dibaca jika ditulis:
    
    ```cpp
    if (key < rest) rest = key;
    ```
    
    karena kamu sedang mencari yang _lebih kecil secara leksikografis_.
    

---

Siap lanjut ke **Soal 7**, tantangan tentang pencatatan banyak siswa per kelas? Atau mau review dulu?