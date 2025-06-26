---
obsidianUIMode: preview
note_type: latihan
latihan: Papan Skor Turnamen
sumber: chatgpt.com
tags:
  - data-structure
  - multimap
date_learned: 2025-06-23T19:19:00
---
---
🔥 Siap! Ini dia **Soal 15: Penutup Latihan Multimap**  
Kita buat dengan konteks baru—tema **“Leaderboard Turnamen”**.

---

# 🏆 Soal 15: Papan Skor Turnamen

**Deskripsi**  
Sebuah turnamen menyimpan skor dari beberapa pemain. Setiap pemain bisa bermain berkali-kali dan mendapatkan skor berbeda setiap kali. Data disimpan sebagai `multimap<int, string>` yang berisi pasangan `(skor, nama_pemain)`.

Kamu diminta menampilkan **top N pemain dengan skor tertinggi**, berdasarkan skor. Jika ada dua pemain dengan skor yang sama, tampilkan yang namanya lebih kecil secara leksikografis.

---

**Spesifikasi Input**

1. Baris pertama: integer M — jumlah data skor
    
2. Diikuti M baris:
    
    ```
    skor nama
    ```
    
3. Baris terakhir: integer N — banyaknya pemain teratas yang ingin ditampilkan
    

---

**Spesifikasi Output**

- Tampilkan **maksimal N pemain teratas**, satu per baris:
    
    ```
    skor nama
    ```
    
- Jika ada entri ganda (nama sama, skor sama), tetap tampilkan semuanya
    
- Jika N lebih besar dari jumlah entri, tampilkan seluruhnya
    

---

**Contoh Input:**

```
6
120 Alice
130 Bob
125 Alice
110 Charlie
130 David
100 Evan
3
```

**Output:**

```
130 Bob
130 David
125 Alice
```

---

**Penjelasan:**

- Dua skor tertinggi: 130 Bob, 130 David (urutan nama leksikografis)
    
- Selanjutnya: 125 Alice
    
- Charlie dan Evan tidak termasuk top 3
    

---

Silakan langsung implementasikan! Setelah itu, aku siap kasih rekap seluruh progress multimap-mu 🚀

## Jawabanku
Karena aku belum belajar sort dengan custom comparator, maka aku hanya bisa menyelesaiakn soal ini dengan akurasi 85%, dimana output masih dalam urutan yang tidak sesuai. Oleh karena itu, diambil jawaban langsung daria editoail yang sudah benar dan optimal berikut:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Skor {
    int nilai;
    string nama;

    bool operator<(const Skor& other) const {
        if (nilai != other.nilai) return nilai > other.nilai;
        return nama < other.nama;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    vector<Skor> data;

    while (m--) {
        int skor;
        string nama;
        cin >> skor >> nama;
        data.push_back({skor, nama});
    }

    int n; cin >> n;
    sort(data.begin(), data.end());

    for (int i = 0; i < min((int)data.size(), n); i++) {
        cout << data[i].nilai << " " << data[i].nama << "\n";
    }

    return 0;
}
```

# Editorial
## Dengan fungsi `sort()` custom
Nggak masalah! Ini tantangan yang memang sedikit lebih kompleks karena:

- Kita ingin **mengurutkan berdasarkan skor dari besar ke kecil**
    
- Tapi **nama pemain perlu diurutkan menaik** jika skornya sama
    
- Dan kita ingin ambil **top N entri pertama** dari hasil pengurutan itu
    

---

Berikut **strategi optimal yang bisa kamu ikuti**:

### 🔧 Strategi

1. **Gunakan vector<pair<int, string>>** untuk menyimpan data dari `multimap`
    
2. **Sort vector-nya** secara custom:
    
    - Urutkan berdasarkan skor (menurun)
        
    - Jika skor sama, urutkan nama (menaik)
        
3. Ambil dan cetak **N entri pertama** dari hasil sort
    

---

### 🔢 Langkah Implementasi

1. Masukkan seluruh input ke `vector<pair<int, string>>`
    
2. `sort()` dengan custom comparator:
    
    ```cpp
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);
    });
    ```
    
3. Cetak `min(N, v.size())` entri
    

---

### 💡 Kenapa Tidak Langsung Pakai Multimap?

Karena `multimap` selalu urut **menaik berdasarkan key**. Padahal kita ingin **menurun berdasarkan skor** → jadi kita pindahkan ke `vector` dulu lalu atur urutannya manual.

---

Mau aku bantu tuliskan kode lengkapnya untuk kamu modifikasi? Atau mau coba dulu berdasarkan strategi ini?
## Dengan Struct Comparator
Mantap! Memakai `struct` + overload operator `<` adalah **cara yang sangat rapi dan C++ banget**. Gaya ini membuat `sort()` tetap bersih tanpa perlu lambda panjang.

---

### 🔧 Strategi Ulang: Pakai `struct` + Overload `<`

```cpp
struct Skor {
    int nilai;
    string nama;

    // Urutkan descending berdasarkan nilai,
    // dan ascending berdasarkan nama jika nilai sama
    bool operator<(const Skor& other) const {
        if (nilai != other.nilai) return nilai > other.nilai;
        return nama < other.nama;
    }
};
```

---

### 💡 Langkah Implementasi

1. Gunakan `vector<Skor>`
    
2. Isi datanya dari input
    
3. Panggil `sort(v.begin(), v.end());` — tanpa perlu comparator tambahan!
    
4. Cetak `min(N, v.size())` entri
    

---

### Siap Pakai Contoh Template

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Skor {
    int nilai;
    string nama;

    bool operator<(const Skor& other) const {
        if (nilai != other.nilai) return nilai > other.nilai;
        return nama < other.nama;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    vector<Skor> data;

    while (m--) {
        int skor;
        string nama;
        cin >> skor >> nama;
        data.push_back({skor, nama});
    }

    int n; cin >> n;
    sort(data.begin(), data.end());

    for (int i = 0; i < min((int)data.size(), n); i++) {
        cout << data[i].nilai << " " << data[i].nama << "\n";
    }

    return 0;
}
```

---

Silakan kamu modifikasi/kerjakan ulang sendiri dulu kalau mau, atau langsung submit dan kita review bareng ✨