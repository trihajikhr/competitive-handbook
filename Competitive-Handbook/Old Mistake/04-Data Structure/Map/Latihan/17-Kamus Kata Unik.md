---
obsidianUIMode: preview
note_type: latihan
latihan: Kamus Kata Unik
sumber: Gemini AI
tags:
  - data-structure
  - map
date_learned: 2025-06-22T18:03:00
---
---
# Tantangan 2: Kamus Kata Unik

Kamu ingin membuat kamus sederhana dari beberapa kalimat. Kamus ini hanya akan menyimpan **kata-kata unik** yang muncul, dan untuk setiap kata, kamu ingin mencatat **jumlah kemunculannya**. Huruf besar dan kecil dianggap sama (misalnya, "Apel" dan "apel" adalah kata yang sama). Selain itu, kamu harus mengabaikan tanda baca seperti titik (.), koma (,), tanda seru (!), dan tanda tanya (?).

Buatlah program C++ yang menerima satu baris input kalimat, kemudian:

1. Ubah semua huruf menjadi huruf kecil.
2. Hapus tanda baca (hanya `.,!?`).
3. Hitung frekuensi setiap **kata unik**.
4. Tampilkan setiap kata unik beserta jumlah kemunculannya.

Contoh Input:

```
Ini adalah contoh kalimat, ini adalah contoh!
```

**Contoh Output yang Diharapkan:**

```
adalah: 2
contoh: 2
ini: 2
kalimat: 1
```

_(Urutan kata bisa berbeda karena `std: :map` akan mengurutkannya secara alfabetis.)_

---

Bagaimana, menarik bukan? Silakan dicoba!

## Jawabanku
Berikut adalah jawabanku untuk tantangan kali ini:

```cpp
#include<iostream>
#include<map>
#include<cctype>
#include<sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> dasmap;
    string s;
    getline(cin >> ws, s);

    string in;
    stringstream ss(s);
    while(ss >> in){
        for(size_t i=0; i< in.size();){
            in[i]=tolower(in[i]);

            if(ispunct(in[i])){
                in.erase(i,1);
            } else {
                i++;
            }
        }

        dasmap[in]++;
    }

    for(const auto& [key, val]: dasmap){
        cout << key << ": " << val << endl;
    }

    return 0;
}
```

# Editorial
Luar biasa! Solusimu untuk Tantangan 2 juga sangat tepat dan menunjukkan pemahaman yang mendalam tentang manipulasi string dan penggunaan `std::map` untuk kasus yang lebih kompleks.

Mari kita bedah beberapa hal keren dari kodemu:

- **`stringstream`:** Ini adalah pilihan yang sangat cerdas dan efisien untuk memecah string menjadi kata-kata (tokenisasi). Penggunaan `while(ss >> in)` adalah cara yang ringkas untuk mengekstrak setiap kata.
<br/>

- **Normalisasi Kata:**
    - **`tolower(in[i])`:** Kamu berhasil mengubah semua karakter menjadi huruf kecil, yang penting untuk memastikan "Apel" dan "apel" dianggap sama.
      <br/>
    - **`ispunct(in[i])` dan `in.erase(i,1)`:** Penanganan tanda baca dilakukan dengan sangat baik. Penting untuk diperhatikan bahwa kamu menggunakan `in.erase(i,1)` dan hanya meng-increment `i` jika karakter _bukan_ tanda baca. Ini benar karena saat karakter dihapus, karakter berikutnya bergeser ke posisi `i` yang sama. Jika `i` selalu di-increment, kamu bisa saja melewatkan tanda baca berurutan. Ini adalah detail yang sering terlewatkan dan kamu menanganinya dengan sempurna!
      <br/>
- **`dasmap[in]++`:** Seperti sebelumnya, ini adalah cara yang ringkas dan idiomatis untuk menghitung frekuensi kata. Jika kata belum ada di `map`, ia akan ditambahkan dengan nilai default 0, lalu di-increment menjadi 1
<br/>

Secara keseluruhan, kamu berhasil menangani semua persyaratan tantangan ini dengan sangat baik. Ini adalah implementasi yang kuat dan efisien.

