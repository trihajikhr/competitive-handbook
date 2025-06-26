---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Menerima Inputan dengan Spasi
sumber: deepseek.com
tags:
  - input-output
---
---
# Perbandingan `getline(cin, s)` vs `getline(cin >> ws, s)`  

Kedua cara ini digunakan untuk membaca input string, tetapi memiliki perbedaan penting dalam menangani **whitespace** (spasi, newline, dll). Berikut penjelasannya:

---

## 1 | Metode  `getline(cin, s)`  
#### Cara Kerja:  
- Membaca seluruh baris input (termasuk spasi) hingga **newline** (`\n`).  
- **Tidak menghiraukan** whitespace di awal input.  

#### Contoh:  
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Masukkan teks: ";
    getline(cin, s);  // Input: "   Hello World"
    cout << "Output: " << s;  // Output: "   Hello World"
    return 0;
}
```

#### Kapan Digunakan?  
- Saat ingin membaca **seluruh baris input** termasuk spasi di awal/tengah.  
- Contoh: Input alamat, deskripsi, atau kalimat lengkap.  

---

## 2 | Metode  `getline(cin >> ws, s)`  
#### Cara Kerja:  
- `cin >> ws` (**whitespace eater**) menghapus semua whitespace (spasi, tab, newline) **sebelum** membaca input.  
- Baru kemudian `getline` membaca sisanya hingga newline.  

#### Contoh:  
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Masukkan teks: ";
    getline(cin >> ws, s);  // Input: "   Hello World"
    cout << "Output: " << s;  // Output: "Hello World" (spasi awal dihapus)
    return 0;
}
```

#### Kapan Digunakan?  
- Saat ingin **mengabaikan spasi/newline** yang tersisa dari input sebelumnya.  
- Contoh: Setelah menggunakan `cin >>` sebelum `getline`.  

---

### Perbedaan Utama  
| Fitur                | `getline(cin, s)` | `getline(cin >> ws, s)`            |
| -------------------- | ----------------- | ---------------------------------- |
| Whitespace awal  | Dibaca            | Dihapus                            |
| Newline (`\n`)   | Berhenti membaca  | Juga berhenti membaca              |
| Input sebelumnya | Tidak terpengaruh | Membersihkan whitespace sebelumnya |

---

## Kasus Kritis: Input Campuran (`cin >>` + `getline`)  
#### Masalah:  
```cpp
int age;
string name;

cout << "Umur: ";
cin >> age;          // Input: 25\n
cout << "Nama: ";
getline(cin, name);  // Tidak menunggu input, langsung membaca newline (\n)!
```
- **Akibat:** `name` akan kosong karena `getline` membaca newline tersisa dari `cin >> age`.  

#### Solusi:  
Gunakan `cin >> ws` untuk membersihkan newline:  
```cpp
cout << "Umur: ";
cin >> age;
cout << "Nama: ";
getline(cin >> ws, name);  // Membersihkan newline sebelum membaca
```

---

## Kesimpulan & Rekomendasi  
- **Gunakan `getline(cin, s)`** jika:  
  - Ingin membaca input lengkap (termasuk spasi di awal).  
  - Tidak ada operasi `cin >>` sebelumnya.  

- **Gunakan `getline(cin >> ws, s)`** jika:  
  - Ada `cin >>` sebelum `getline`.  
  - Ingin menghapus spasi/newline yang tidak diinginkan.  

#### Best Practice:  
```cpp
int main() {
    int id;
    string title;

    cout << "ID: ";
    cin >> id;
    cout << "Judul: ";
    getline(cin >> ws, title);  // Hindari bug newline

    return 0;
}
```

Semoga membantu! 🚀