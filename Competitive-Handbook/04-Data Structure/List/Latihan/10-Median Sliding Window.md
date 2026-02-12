---
obsidianUIMode: preview
note_type: latihan
latihan: Median Sliding Window
sumber: chatgpt.com
tags:
  - list
  - data-structure
date_learned: 2025-07-09T16:32:00
---
---
# Soal 10 (Bonus STL): Median Sliding Window

### 🧠 Deskripsi:

Kamu diberikan stream angka dan sebuah window ukuran tetap `k`. Untuk setiap posisi window (geser ke kanan satu per satu), **cetak median** dari nilai-nilai dalam window tersebut.

### 📥 Input:

Baris pertama: dua bilangan bulat `n` dan `k`  
Baris kedua: `n` bilangan bulat — data stream
### 📤 Output:

Cetak `n - k + 1` bilangan — median dari setiap window, satu baris dipisah spasi  
Jika jumlah dalam window **ganjil**: median = nilai tengah  
Jika **genap**: median = rata-rata dua nilai tengah (pakai float, 1 digit di belakang koma)
### 🧪 Contoh Input:

```
7 3
1 3 -1 -3 5 3 6
```

### 💬 Output:

```
1 -1 -1 3 5
```

### 💡 Petunjuk:

- Gunakan `std::list` atau `std::multiset` untuk menyimpan elemen dalam window
    
- Saat window bergeser, **hapus elemen pertama** dan **tambah elemen baru**
    
- Untuk menghitung median, kamu perlu **akses ke tengah list**
    
# Jawabanku
## Jawaban yang masih belum cukup optimal
Jawaban ini masih memiliki sedikit kesalahan logika sederhana, berdasarkan penilaian editorial:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int evenWindow(list<int> temp){
    temp.sort();
    auto itr = temp.begin();
    advance(itr, temp.size()/2-1);
    int a = *itr; itr++;
    int b = *itr;
    return (a+b)/2;
}

int oddWindow(list<int>temp){
    temp.sort();
    auto itr = temp.begin();
    advance(itr, temp.size()/2);
    return *itr;
}

int numGen(int t){
    return t%2==0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,t; cin >> n >> t;
    list<int> dalist, temp;
    list<int> ::iterator l, r;
    
    for(int i=0, x; i<n; i++) {
        cin >> x;
        dalist.push_back(x);
        if(i<t) temp.push_back(x);
    }

    r = dalist.begin();
    advance(r, t-1);

    for(int i=0; i< n-t+1; i++) {
        if(i==0){
            if(numGen(t)){
                cout << evenWindow(temp) << " ";
            } else cout << oddWindow(temp) << " ";
        } else {
            r++;
            temp.push_back(*r);
            temp.pop_front();
            if(numGen(t)){
                cout << evenWindow(temp) << " ";
            } else cout << oddWindow(temp) << " ";
        }
    }
    return 0;
}
```

## Jawaban yang lebih baik
Berikut adalah jawaban yang lebih baik dan lebih benar:

### Pendekatan Lebih ke List

Pendekatan yang lebih mendalami list:

```cpp
#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip> // untuk setprecision

using namespace std;

float getMedian(list<int> temp) {
    temp.sort();
    auto itr = temp.begin();
    int size = temp.size();

    if (size % 2 == 1) {
        advance(itr, size / 2);
        return *itr;
    } else {
        advance(itr, size / 2 - 1);
        int a = *itr;
        itr++;
        int b = *itr;
        return (a + b) / 2.0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    list<int> data, window;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        data.push_back(x);
        if (i < k) window.push_back(x);
    }

    auto r = data.begin();
    advance(r, k - 1);

    cout << fixed << setprecision(1); // format angka: 1 digit desimal

    for (int i = 0; i <= n - k; ++i) {
        cout << getMedian(window) << " ";
        if (++r == data.end()) break; // jika sudah sampai akhir, stop
        window.push_back(*r);         // tambahkan elemen baru
        window.pop_front();           // geser window (hapus elemen depan)
    }

    return 0;
}
```

# Editorial
Tentu! Berikut adalah **editorial penjelasan per blok kode program** dari solusi sliding window median menggunakan `std::list`.

### 🎯 Tujuan:

Mencetak median dari setiap window berukuran `k` saat digeser dari kiri ke kanan sepanjang data stream `n` elemen.

### 📦 1. Header dan Namespace

```cpp
#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip> // untuk setprecision

using namespace std;
```

**Penjelasan:**

- `iostream` untuk input/output
    
- `list` untuk menyimpan window (sesuai permintaan)
    
- `algorithm` untuk `sort()` pada list
    
- `iomanip` untuk mengatur presisi output float (`setprecision`)

### 📌 2. Fungsi `getMedian**`**

```cpp
float getMedian(list<int> temp) {
    temp.sort(); // sort isi window
    auto itr = temp.begin();
    int size = temp.size();

    if (size % 2 == 1) {
        advance(itr, size / 2);
        return *itr;
    } else {
        advance(itr, size / 2 - 1);
        int a = *itr;
        itr++;
        int b = *itr;
        return (a + b) / 2.0;
    }
}
```

**Penjelasan:**

- Fungsi ini menerima salinan `list<int>` berisi elemen dalam window.
    
- `temp.sort()` mengurutkan window (karena list tidak random-access).
    
- Untuk **jumlah ganjil**, ambil elemen ke-`k/2`.
    
- Untuk **jumlah genap**, ambil dua elemen tengah lalu rata-ratakan jadi `float`.
    
- Mengembalikan median sesuai format.

### 🧠 3. Main Function: Input dan Inisialisasi

```cpp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
```

**Penjelasan:**

- Optimasi I/O agar lebih cepat.
    
- Baca jumlah elemen `n` dan ukuran window `k`.

### 🛒 4. Baca Stream dan Inisialisasi Window

```cpp
    list<int> data, window;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        data.push_back(x);
        if (i < k) window.push_back(x);
    }

    auto r = data.begin();
    advance(r, k - 1);
```

**Penjelasan:**

- `data`: menyimpan seluruh stream
    
- `window`: menyimpan elemen-elemen window pertama
    
- `r`: iterator menunjuk ke elemen terakhir dari window awal → digunakan nanti saat sliding

### 📤 5. Cetak Median Tiap Window

```cpp
    cout << fixed << setprecision(1); // format angka: 1 digit desimal

    for (int i = 0; i <= n - k; ++i) {
        cout << getMedian(window) << " ";

        if (++r == data.end()) break;     // window sudah di akhir, selesai
        window.push_back(*r);             // tambahkan elemen baru
        window.pop_front();               // geser window (hapus elemen lama)
    }

    return 0;
}
```

**Penjelasan:**

- Gunakan `fixed` dan `setprecision(1)` untuk memastikan float tampil satu angka di belakang koma.
    
- Loop dari 0 hingga `n - k`:
    
    - Cetak median dari isi `window`
        
    - Geser `r` ke kanan satu langkah
        
    - Tambahkan elemen baru ke window (`push_back`)
        
    - Hapus elemen paling kiri dari window (`pop_front`)
        

---

### 🧪 Contoh Proses 

Inputan :
```
7 3
1 3 -1 -3 5 3 6
```

|Iterasi|Window|Median|
|---|---|---|
|0|1 3 -1|1.0|
|1|3 -1 -3|-1.0|
|2|-1 -3 5|-1.0|
|3|-3 5 3|3.0|
|4|5 3 6|5.0|

---

## ✅ Kesimpulan:

- `std::list` digunakan untuk latihan manipulasi linked list, walau kurang optimal secara performa.
    
- `sort()` pada list digunakan per window karena tidak ada akses indeks langsung.
    
- Fungsi modular (`getMedian`) memisahkan logika median dari logika sliding window.
    
- Output sesuai ketentuan: median dalam float, 1 digit di belakang koma.
    

Kalau kamu ingin lanjutan seperti **analisis kompleksitas** atau **perbandingan dengan multiset/heap**, tinggal bilang ya!