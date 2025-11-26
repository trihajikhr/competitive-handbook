---
obsidianUIMode: preview
note_type: latihan
latihan: Sistem Manajemen Antrean Prioritas
sumber: Gemini AI
tags:
  - list
  - data-structure
date_learned: 2025-07-10T22:21:00
---
---
# Sistem Manajemen Antrean Prioritas

Kamu ditugaskan untuk mengembangkan sistem manajemen antrean sederhana untuk sebuah klinik, di mana pasien diprioritaskan berdasarkan tingkat urgensi kondisi mereka. Sistem ini harus efisien dalam menambahkan pasien baru ke antrean sesuai prioritasnya, memanggil pasien terdepan, dan membatalkan pendaftaran pasien jika diperlukan.

Kamu harus menggunakan `std::list` di C++ untuk mengimplementasikan antrean ini, memanfaatkan fitur-fiturnya untuk penyisipan dan penghapusan elemen yang efisien.

---

### Detail Implementasi

Kamu perlu membuat sebuah kelas atau serangkaian fungsi yang mengelola `std::list` dari objek `Pasien`.

**Struktur Data Pasien:**

```cpp
struct Pasien {
    std::string nama;
    int tingkatPrioritas; 
    // Angka lebih tinggi = prioritas lebih tinggi 
    // (misal: 5 = darurat, 1 = tidak darurat)

    // Konstruktor untuk kemudahan inisialisasi
    Pasien(std::string n, int p) : nama(std::move(n)), tingkatPrioritas(p) {}

    // Operator == untuk membandingkan pasien 
    // (berguna saat mencari untuk pembatalan)
    bool operator==(const Pasien& other) const {
        return nama == other.nama && tingkatPrioritas == other.tingkatPrioritas;
    }
};
```

---

### Fungsi yang Harus Diimplementasikan:

1. **`void tambahPasien(list<Pasien>& antrean, const string& nama, int prioritas)`**
    
    - Menambahkan pasien baru ke dalam `antrean`.
        
    - Pasien harus disisipkan di posisi yang benar:
        
        - Pasien dengan `tingkatPrioritas` lebih **tinggi** harus berada **lebih depan** dalam antrean.
            
        - Jika `tingkatPrioritas` sama, pasien baru harus disisipkan **setelah** pasien yang sudah ada dengan prioritas yang sama.
            
2. **`Pasien panggilPasien(list<Pasien>& antrean)`**
    
    - Mengambil dan menghapus pasien dengan prioritas tertinggi (yang berada di paling depan `antrean`).
        
    - Asumsikan `antrean` tidak akan kosong saat fungsi ini dipanggil.
        
3. **`void lihatAntrean(const slist<Pasien>& antrean)`**
    
    - Mencetak semua pasien yang saat ini berada di `antrean` dalam urutan dari depan ke belakang.
        
    - Format output untuk setiap pasien: `Nama: [nama_pasien], Prioritas: [prioritas_pasien]`
        
    - Jika antrean kosong, cetak `Antrean kosong.`
        
4. **`bool batalkanPasien(list<Pasien>& antrean, const string& nama)`**
    
    - Mencari pasien berdasarkan `nama` dan menghapusnya dari `antrean`.
        
    - Jika ada lebih dari satu pasien dengan nama yang sama, hapus **pasien pertama yang ditemukan** (dari depan antrean).
        
    - Mengembalikan `true` jika pasien berhasil ditemukan dan dihapus, `false` jika pasien tidak ditemukan.
        

---

### Contoh Penggunaan (Input/Output):

**Input:**

```
TAMBAH Alice 3
TAMBAH Bob 5
LIHAT
TAMBAH Charlie 3
PANGGIL
LIHAT
BATALKAN Alice
LIHAT
BATALKAN David
```

**Output yang Diharapkan:**

```
Nama: Bob, Prioritas: 5
Nama: Alice, Prioritas: 3
Pasien terpanggil: Bob
Nama: Alice, Prioritas: 3
Nama: Charlie, Prioritas: 3
Nama: Charlie, Prioritas: 3
Pasien David tidak ditemukan.
```

---

### Catatan Penting:

- Perhatikan penggunaan **iterator** saat menyisipkan atau menghapus elemen di tengah `std::list`. Ini adalah kunci untuk efisiensi `std::list`.
    
- Gunakan `std::move` untuk `std::string` di konstruktor `Pasien` untuk performa yang lebih baik.
    

---

Selamat mengerjakan! Ini akan menjadi latihan yang bagus untuk pemahamanmu tentang `std::list`.

# Jawabanku
Aku masih tidak terlalu ahli menggunakan class, dan struct. Aku masih harus belajar lagi. Jawaban ini masih membutuhkan banyak bantuan dari luar, namun sudah merupakan jawaban yang tepat:

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;

class Pasien {
public:
    string nama;
    int prioritas;

    Pasien(string n, int p) {
        nama = move(n);
        prioritas = p;
    }

    bool operator==(const Pasien& other) const {
        return nama == other.nama && prioritas == other.prioritas;
    }

    // Semua fungsi ini harus terima referensi ke list<Pasien>
    static void tambahPasien(list<Pasien>& antrean, const string& nama, int prior);
    static void panggilPasien(list<Pasien>& antrean);
    static void lihatAntrean(const list<Pasien>& antrean);
    static void batalkanPasien(list<Pasien>& antrean, const string& nama);
};

// Fungsi TAMBAH
void Pasien::tambahPasien(list<Pasien>& antrean, const string& nama, int prior) {
    auto it = antrean.begin();
    while (it != antrean.end() && it->prioritas >= prior) {
        ++it;
    }
    antrean.insert(it, Pasien(nama, prior));
}

// Fungsi PANGGIL
void Pasien::panggilPasien(list<Pasien>& antrean) {
    if (!antrean.empty()) {
        cout << "\nPasien terpanggil: " << antrean.front().nama << endl;
        antrean.pop_front();
    } else {
        cout << "Antrean kosong\n";
    }
}

// Fungsi LIHAT
void Pasien::lihatAntrean(const list<Pasien>& antrean) {
    if (antrean.empty()) {
        cout << "Antrean kosong\n";
    } else {
        for (const auto& p : antrean) {
            cout << "Nama: " << p.nama << ", Prioritas: " 
            << p.prioritas << "\n";
        }
    }
}

// Fungsi BATALKAN
void Pasien::batalkanPasien(list<Pasien>& antrean, const string& nama) {
    auto it = find_if(antrean.begin(), antrean.end(), [&](const Pasien& p) {
        return p.nama == nama;
    });
    if (it != antrean.end()) {
        antrean.erase(it);
        cout << nama << " dibatalkan\n";
    } else {
        cout << nama << " tidak ditemukan\n";
    }
}

int main() {
    list<Pasien> psn;

    string s;
    while (getline(cin >> ws, s)) {
        stringstream ss(s);
        string cmd, name;
        int prior;

        ss >> cmd;

        if (cmd == "TAMBAH") {
            ss >> name >> prior;
            Pasien::tambahPasien(psn, name, prior);
        } else if (cmd == "PANGGIL") {
            Pasien::panggilPasien(psn);
        } else if (cmd == "LIHAT") {
            Pasien::lihatAntrean(psn);
        } else if (cmd == "BATALKAN") {
            ss >> name;
            Pasien::batalkanPasien(psn, name);
        }
    }

    return 0;
}

```

# Editorial
Berikut adalah **editorial per blok kode** untuk program antrean pasien berdasarkan prioritas:

---

### 🔷 1. Header dan Namespace

```cpp
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
#include<sstream>
using namespace std;
```

📌 **Penjelasan:**

- `iostream` → untuk input/output.
    
- `list` → untuk menggunakan `std::list` sebagai struktur antrean.
    
- `algorithm` → untuk `find_if` di fungsi pembatalan.
    
- `iterator` → tidak langsung digunakan di sini, tapi berguna untuk manipulasi iterator.
    
- `sstream` → untuk parsing input dari `getline`.
    

---

### 🔷 2. Kelas `Pasien` dan Atribut

```cpp
class Pasien {
public:
    string nama;
    int prioritas;
```

📌 **Penjelasan:**

- Membuat kelas `Pasien` yang memiliki dua atribut:
    
    - `nama`: nama pasien.
        
    - `prioritas`: angka prioritas (semakin besar → lebih cepat dilayani).
        

---

### 🔷 3. Konstruktor

```cpp
    Pasien(string n, int p) {
        nama = move(n);
        prioritas = p;
    }
```

📌 **Penjelasan:**

- Konstruktor untuk menginisialisasi objek `Pasien`.
    
- `move(n)` digunakan untuk menghindari salinan string jika memungkinkan (optimasi kecil).
    

---

### 🔷 4. Operator Pembanding ==

```cpp
    bool operator==(const Pasien& other) const {
        return nama == other.nama && prioritas == other.prioritas;
    }
```

📌 **Penjelasan:**

- Membandingkan dua pasien berdasarkan **nama dan prioritas**.
    
- Berguna untuk pencarian atau penghapusan spesifik.
    

---

### 🔷 5. Deklarasi Fungsi-Fungsi Statik

```cpp
static void tambahPasien(list<Pasien>& antrean, const string& nama, int prior);
static void panggilPasien(list<Pasien>& antrean);
static void lihatAntrean(const list<Pasien>& antrean);
static void batalkanPasien(list<Pasien>& antrean, const string& nama);
```

📌 **Penjelasan:**

- Fungsi `static` karena tidak bergantung pada _state_ objek `Pasien` itu sendiri.
    
- Semua fungsi ini beroperasi pada **list antrean**.
    

---

### 🔷 6. Fungsi `tambahPasien`

```cpp
void Pasien::tambahPasien(list<Pasien>& antrean, const string& nama, int prior) {
    auto it = antrean.begin();
    while (it != antrean.end() && it->prioritas >= prior) {
        ++it;
    }
    antrean.insert(it, Pasien(nama, prior));
}
```

📌 **Penjelasan:**

- Menyisipkan pasien ke antrean pada posisi yang sesuai berdasarkan prioritas:
    
    - Jika `prioritas` lebih kecil, pasien akan ditaruh **lebih belakang**.
        
    - Jika sama, pasien ditaruh **setelah** yang sudah ada (preserve order).
        

---

### 🔷 7. Fungsi `panggilPasien`

```cpp
void Pasien::panggilPasien(list<Pasien>& antrean) {
    if (!antrean.empty()) {
        cout << "\nPasien terpanggil: " << antrean.front().nama << endl;
        antrean.pop_front();
    } else {
        cout << "Antrean kosong\n";
    }
}
```

📌 **Penjelasan:**

- Memanggil dan menghapus pasien pertama dalam antrean (prioritas tertinggi).
    
- Menangani juga kasus jika antrean kosong.
    

---

### 🔷 8. Fungsi `lihatAntrean`

```cpp
void Pasien::lihatAntrean(const list<Pasien>& antrean) {
    if (antrean.empty()) {
        cout << "Antrean kosong\n";
    } else {
        for (const auto& p : antrean) {
            cout << "Nama: " << p.nama << ", Prioritas: " 
            << p.prioritas << "\n";
        }
    }
}
```

📌 **Penjelasan:**

- Menampilkan semua isi antrean secara berurutan.
    
- Format: `Nama: <nama>, Prioritas: <prioritas>`.
    

---

### 🔷 9. Fungsi `batalkanPasien`

```cpp
void Pasien::batalkanPasien(list<Pasien>& antrean, const string& nama) {
    auto it = find_if(antrean.begin(), antrean.end(), [&](const Pasien& p) {
        return p.nama == nama;
    });
    if (it != antrean.end()) {
        antrean.erase(it);
        cout << nama << " dibatalkan\n";
    } else {
        cout << nama << " tidak ditemukan\n";
    }
}
```

📌 **Penjelasan:**

- Mencari pasien berdasarkan nama dan menghapusnya dari antrean.
    
- Jika tidak ditemukan, tampilkan pesan bahwa nama tidak ditemukan.
    

---

### 🔷 10. Fungsi `main`

```cpp
int main() {
    list<Pasien> psn;
```

📌 **Penjelasan:**

- Membuat list `psn` untuk menyimpan antrean pasien.
    

---

```cpp
string s;
while (getline(cin >> ws, s)) {
	stringstream ss(s);
	string cmd, name;
	int prior;

	ss >> cmd;
```

📌 **Penjelasan:**

- Membaca input satu baris penuh, lalu parsing perintah dengan `stringstream`.
    
- `ws` memastikan spasi terabaikan di depan baris.
    

---

```cpp
	if (cmd == "TAMBAH") {
		ss >> name >> prior;
		Pasien::tambahPasien(psn, name, prior);
	} else if (cmd == "PANGGIL") {
		Pasien::panggilPasien(psn);
	} else if (cmd == "LIHAT") {
		Pasien::lihatAntrean(psn);
	} else if (cmd == "BATALKAN") {
		ss >> name;
		Pasien::batalkanPasien(psn, name);
	}
}
```

📌 **Penjelasan:**

- Menangani 4 perintah:
    
    - `"TAMBAH"` → nama dan prioritas → ditambahkan ke antrean.
        
    - `"PANGGIL"` → panggil pasien pertama.
        
    - `"LIHAT"` → tampilkan isi antrean.
        
    - `"BATALKAN"` → cari dan hapus berdasarkan nama.
        

---

### 🔷 11. Return akhir

```cpp
    return 0;
}
```

📌 **Penjelasan:**

- Mengakhiri program.
    

---

## ✨ Kesimpulan:

Program ini adalah simulasi antrean pasien berdasarkan **prioritas**:

- Gunakan `list` untuk penyisipan efisien dan iterasi cepat.
    
- Logika penyisipan mempertahankan **urutan stabil**.
    
- Fungsi-fungsi static memudahkan akses tanpa butuh instance `Pasien`.
    

Kalau kamu ingin, kita bisa lanjut ke:

- Menambahkan fitur seperti edit prioritas.
    
- Menyimpan log antrean.
    
- Menangani input batch/file.
    

Tapi saat ini, implementasimu **sudah sangat solid dan siap pakai**!