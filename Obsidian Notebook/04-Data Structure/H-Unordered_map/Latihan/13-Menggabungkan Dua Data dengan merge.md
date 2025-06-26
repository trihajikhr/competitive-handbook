---
obsidianUIMode: preview
note_type: latihan
latihan: Menggabungkan Dua Data dengan merge
sumber: chatgpt.com
tags:
  - data-structure
  - unordered_map
date_learned: 2025-06-16T22:30:00
---
---

Berikut **Soal 13** untuk memperkenalkan fungsi **`merge()`** pada `std::unordered_map`. Kerjakan hanya soal ini terlebih dahulu, lalu beritahu aku ketika siap untuk soal berikutnya.

---

# Soal 13 – Menggabungkan Dua Peta Data dengan `merge()`

Diberikan dua kumpulan data A dan B, masing‑masing berisi pasangan kata (string) dan nilai (int). Gabungkan isi peta B ke peta A menggunakan **`unordered_map::merge()`** sehingga hanya elemen dengan key yang **belum ada** di A yang dipindahkan dari B.

### Deskripsi

- Jika sebuah key di B **sudah ada** di A, maka entry itu **tidak** akan dipindahkan—ia tetap berada di B.
    
- Entry yang dipindahkan akan hilang dari B dan muncul di A.
    
- Kamu **tidak** boleh melakukan lookup ganda untuk setiap key; cukup gunakan metode `merge()`.
    

### Format Masukan

- Baris pertama: dua bilangan bulat **_n_** dan **_m_** (1 ≤ _n_, _m_ ≤ 1000) — jumlah entry di A dan B.
    
- Baris berikutnya **_n_** baris: setiap baris “_key value_” untuk peta A.
    
- Lalu **_m_** baris: setiap baris “_key value_” untuk peta B.
    

Contoh:

```
3 4
apple 5
banana 2
cherry 7
banana 3
date 4
apple 1
elderberry 9
```

### Format Keluaran

1. Satu baris berisi dua bilangan: **`sizeA sizeB`** setelah operasi merge.
    
2. Daftar isi peta A—setiap baris “_key value_”—diurutkan leksikografis menaik berdasarkan key.
    

Untuk contoh di atas, key yang dipindahkan dari B ke A hanya `date` dan `elderberry`, sedangkan `banana` dan `apple` tetap di B. Jadi outputnya:

```
5 2
apple 5
banana 2
cherry 7
date 4
elderberry 9
```

---

**Tugasmu**

- Baca input, bangun `unordered_map<string,int> A` dan `B`.
    
- Lakukan `A.merge(B);`
    
- Cetak sesuai format.
    

Setelah selesai, kirim **kode C++** lengkapmu dan jelaskan **singkat** bagaimana `merge()` bekerja—kenapa elemen duplikat tidak dipindahkan. Semangat! 😊

## Jawabanku
Beriukt adalah jawabanku, yang walaupun sudah dikatakan benar, ada sediit minor optimasi yang bisa dilakukan, tapi tenang saja, itu tidak terlalu mempengaruhi performa:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_map>
using namespace std;

inline void fastio(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
}

int main() {
    fastio();
    int n, m;
    cin >> n >> m;

    vector<string> order;
    unordered_map<string, int> A;
    unordered_map<string, int> B;
    A.reserve(n);
    B.reserve(m);
    order.reserve(n);

    string s, name;
    int no;
    while(n--){
        getline(cin >> ws, s);
        stringstream ss(s);
        ss >> name >> no;
        A.emplace(name, no);
    }

    while(m--){
        getline(cin >> ws, s);
        stringstream ss(s);
        ss >> name >> no;
        B.emplace(name, no);
    }

    A.merge(B);
    for(const auto& [key, val]: A){
        order.push_back(key);
    }

    cout << A.size() << " " << B.size() << "\n";
    sort(order.begin(), order.end());
    for(const auto& x: order){
        cout << x << " " << A[x] << "\n";
    }
    return 0;
}
```

Kodenya sudah **benar** dan **sesuai** dengan soal:

- Kamu sudah membaca A dan B dengan `getline`+`stringstream`,
    
- Mengisi `unordered_map` masing‑masing,
    
- Memanggil `A.merge(B);` — elemen dengan key yang sudah ada di A tidak dipindahkan, sisanya dipindah dan dihapus dari B,
    
- Mengumpulkan key A ke `order`, mengurutkannya, lalu mencetak ukuran dan isi A.
    

Satu‑satunya catatan kecil (**opsional**) untuk optimisasi micro:

```cpp
order.reserve(A.size());  // setelah merge, A.size() adalah jumlah final key unik
```

Dengan begitu, `order` tidak akan perlu realokasi saat `push_back` semua key A. Tetapi secara fungsi, programmu sudah **sempurna**.

# Editorial
Editorial Singkat Soal 13 – `unordered_map::merge()`

1. **Membaca Input**
    
    - Dua bilangan `n, m` kemudian `n` entry ke _map_ A dan `m` entry ke _map_ B.
        
    - Gunakan `getline` + `stringstream` untuk parsing nama (`string`) dan nilai (`int`).
        
2. **Reservasi Kapasitas (Opsional)**
    
    - `A.reserve(n); B.reserve(m);` untuk meminimalkan rehash saat insert.
        
3. **Operasi Merge**
    
    ```cpp
    A.merge(B);
    ```
    
    - **Cara Kerja**:
        
        - Untuk tiap elemen di B:
            
            - Jika key **belum ada** di A → dipindahkan _node_ langsung ke A (tanpa konstruksi ulang).
                
            - Jika key **sudah ada** di A → tetap di B, tidak dipindahkan.
                
    - **Keuntungan**:
        
        - **O(1)** per elemen (hanya pointer relink), tanpa lookup ganda atau copy element.
            
4. **Pengumpulan dan Pengurutan Key**
    
    - Iterasi `for (auto& [k,v] : A)` untuk kumpulkan semua `k` ke vector `order`.
        
    - `sort(order.begin(), order.end());` untuk output leksikografis.
        
5. **Output**
    
    - Baris pertama: `A.size()` dan `B.size()` setelah merge.
        
    - Baris berikutnya: setiap `key` + `value` dari A sesuai urutan `order`.
        

> Dengan `merge()`, duplikat di B tidak akan ditransfer, dan perpindahan node dari B ke A terjadi dalam biaya konstan per elemen, membuatnya efisien dan elegan.