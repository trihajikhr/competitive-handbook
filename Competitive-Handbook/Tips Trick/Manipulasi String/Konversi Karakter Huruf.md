---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Konversi karakter huruf
sumber: Google.com, AI
tags:
  - string
  - convert
---
#string  #convert 

---
# Konversi Karakter Huruf

Katakanlah kita diberikan soal, dimana kita harus menangani dua inputan string, yaitu string `a` dan string `b`.

Lalu tugas kita adalah membuat string `a` menjadi semuanya karakter huruf besar, atau uppercase, dan string `b` menjadi semuanya karakter huruf kecil, atau lowercase. 

Maka yang perlu kita lakukan disini, adalah melakukan konversi string.

Ada beberapa cara untuk mengkonversi suatu string, menjadi semua uppercase, atau lowercase. Berikut diantaranya:

## 1 | Metode Manual
Cara ini menggunakan pengenalan kode ASII untuk mengkonversi huruf. Tetaapi kita harus melakukan pengecekan, apakah karakter yang diakses berada direntang yang sesuai, karena angka, karakter spesial dan unik, bahkan spasi pun memiliki kode ASCII nya masing masing.

Cuku tahu bahwa karakter huruf besar berada direntang ASII $65 \leq upper \geq 90$. Sedangkan karakter huruf kecil berada di rentang $97 \leq lower \geq 122$.

- Huruf besar : `65` sd `90`
- Huruf kecil : `97` sd `122`

Nah, jika suatu karakter teridentifikasi memiliki ASCII diantara $65 \leq c \geq 90$, maka karakter tersebut pastilah karakter huruf besar. Dan jika suatu karakter memiliki ASCII diantara $97 \leq lower \geq 122$, maka pastilah karakter huruf kecil.

Jika telah teridentifikasi bahwa karakter tersebut masuk golongan karakter huruf, kita bisa mengkonversi karakter tersebut. 

Jika karakter tersebut huruf besar, kita bisa menjadinya karakter huruf kecil dengan menambahkan kode ASCII karakter tersebut dengan `32`. Dan jika karakter tersebut huruf kecil, kita bisa menjadikanya karakter huruf besar dengan mengurangi kode ASCII karakter tersebut dengan `32`.

Kenapa `32`? Karena selisih kode ASCII antara semua karakter huruf besar dan karakter huruf kecil adalah 32. Seperti karakter `a` yang memiliki kode ASCII berupa `97`, dan karakter `A` yang memiliki kode ASCII `65`, selisihnya adalah 32, begitupula dengan semua karakter.

Maka, kita bisa melakukan konversi dengan cara manual berikut:

```cpp
#include<iostream>
using namespace std;

int main() {
    string a,b;
    getline(cin >> ws, a);
    getline(cin >> ws, b);

    for(char & c:a){
        if(c>=97 && c<=122){
            c-=32;
        }
    }

    for(char & c:b){
        if(c>=65 && c<=90){
            c+=32;
        }
    }

    cout << a << "\n";
    cout << b << "\n";
    return 0;
}
```

Ketika kita mengakses karakter, kita juga bisa mengakses kode ASCII nya. Oleh karena itu, cara berikut juga bisa digunakan. Walaupun caranya hampir sama, yaitu memanfaatkan kode ASCII, tetapi dengan cara yang lebih readeble:

```cpp
#include<iostream>
using namespace std;

int main() {
    string a,b;
    getline(cin >> ws, a);
    getline(cin >> ws, b);

    for(char & c:a){
        if (c>='a' && c<='z') {
            c-=('a'-'A');
        }
    }

    for(char & c:b){
        if (c>='A' && c<='Z'){
            c+=('a'-'A');
        }
    }

    cout << a << "\n";
    cout << b << "\n";
    return 0;
}
```

## 2 | Metode Fungsi Sepasang
Jika sebelumnya kita mengecek apakah suatu karakter adalah huruf besar atau huruf kecil dengan melihat kode ASCII, kita bisa langsung saja menggunakan fungsi bawaan untuk tugas ini. 

Fungsi itu adalah `islower()` dan `isupper()`. Cara kerja fungsi ini sederhana, katakanlah kita memiliki suatu karakter huruf dengan variabel `c`, maka:
- `islower()` akan mengembalikan nilai *true* ketika karakter `c` adalah huruf kecil, dan mengembalikan nilai *false* jika `c` adalah karakter huruf besar.
- `isupper()` akan mengembalikan nilai *true* ketika karakter `c` adalah huruf besar, dan mengembalikan nilai *false* jika `c` adalah karakter huruf kecil.

Ini seperti mengecek, apakah suatu karakter berada di rentang ASCII yang sesuai atau tidak.

Selain itu, kita juga bisa menggunakan fungsi konversi bawaan, yaitu `tolower()` dan `toupper()`. Fungsi dari `tolower()` adalah mengkonversi karakter huruf ke huruf kecil, dan fungsi dari `toupper()` adalah mengkonversi karakter huruf ke huruf besar.

Berikut adalah implementasinya:

```cpp
#include<iostream>
#include<cctype>
using namespace std;

int main() {
    string a,b;
    getline(cin >> ws, a);
    getline(cin >> ws, b);

    for(char & c:a){
        if(islower(c))  c=toupper(c);
    }

    for(char & c:b){
        if(isupper(c)) c=tolower(c);
    }

    cout << a << "\n";
    cout << b << "\n";
    return 0;
}
```

## 3 | Metode Cepat dengan `transform()`
Jika sebelumnya kita melakukan perulangan manual untuk mengkonversi setiap karakter tadi, kita bisa menggunakan fungsi `transform()` untuk merubah semua karakter dari suatu string menjadi besar atau kecil sekaligus.

Kita cukup memanggil tambahan header `<algorithm>` untuk fungsi `transfrom`, dan tetap memanggil `<cctype>` untuk menggunakan `tolower()` dan `toupper()`. 

Berikut adalah implementasinya:

```cpp
#include <iostream>
#include <string>
#include <algorithm> // untuk transform
#include <cctype>    // untuk tolower dan toupper
using namespace std;

int main() {
    string a; getline(cin >> ws, a);
    string b; getline(cin >> ws, b);

    transform(a.begin(), a.end(), a.begin(), ::toupper);
    transform(b.begin(), b.end(), b.begin(), ::tolower);

    cout << a << "\n";
    cout << b << "\n";

    return 0;
}
```

## 4 | Konversi karakter `locale`

`std::locale` adalah bagian dari C++ STL (`<locale>`) yang menyediakan cara untuk mengatur format lokal (misal: bahasa, negara, karakter huruf, angka, dll).

Misalnya: `'İ'` di Turkish atau `'ß'` di Jerman mungkin punya aturan konversi yang berbeda dari ASCII biasa.
### 🔧 Struktur Dasar

```cpp
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
    string s = "HeLLo WörLD";
    locale loc;

    for (char &c : s) {
        c = use_facet<ctype<char>>(loc).tolower(c);
    }

    cout << s << "\n"; // Output: hello wörld (tergantung locale)
    return 0;
}
```
### 🧠 Penjelasan

- `locale loc;`: Membuat objek `locale` default (biasanya `"C"` atau sesuai OS).
    
- `use_facet<ctype<char>>(loc)`: Mengakses **facet** `ctype` dari `locale`, yaitu bagian yang mengatur jenis karakter.
    
- `.tolower(c)`: Memanggil fungsi `tolower` dari facet itu, **bukan** `::tolower()` dari `<cctype>`.
    

### 🔄 Ubah ke huruf besar, dan huruf kecil

```cpp
c = use_facet<ctype<char>>(loc).toupper(c);
```

```cpp
c = use_facet<ctype<char>>(loc).tolower(c);
```

---

### 📍 Catatan Penting

1. Fungsi ini hanya bekerja untuk `char` (bukan `wchar_t` atau Unicode penuh), kecuali kamu eksplisit pakai template `ctype<wchar_t>`, dst.
    
2. Untuk penggunaan **non-ASCII**, kamu bisa set locale secara eksplisit:
    

```cpp
locale loc("en_US.UTF-8"); // atau "de_DE.UTF-8", "id_ID.UTF-8" jika tersedia
```

Tapi ini tergantung pada **locale yang tersedia di sistem**.

---

### 📌 Contoh Lengkap

```cpp
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main() {
    string a, b;
    getline(cin >> ws, a);
    getline(cin >> ws, b);

    locale loc;

    for (char &c : a) {
        c = use_facet<ctype<char>>(loc).tolower(c);
    }

    for (char &c : b) {
        c = use_facet<ctype<char>>(loc).toupper(c);
    }

    cout << a << "\n";
    cout << b << "\n";

    return 0;
}
```

### 💬 Kapan Sebaiknya Digunakan?

| Situasi                                                     | Gunakan `std::locale`? |
| ----------------------------------------------------------- | ---------------------- |
| Program biasa, ASCII saja                                   | ❌ Tidak perlu          |
| Program internasional (support multi bahasa)                | ✅ Ya                   |
| Butuh akurasi tinggi untuk karakter non-ASCII               | ✅ Ya                   |
| Aplikasi sistem besar (format angka, waktu, karakter lokal) | ✅ Ya                   |
## 5 | Metode Bitwise super simple

Jika sebelumnya kita mengandalkan fungsi bawaan seperti `islower()` / `toupper()`, atau memakai `transform()`, ternyata ada cara yang **sangat cepat dan sederhana** untuk mengkonversi huruf besar dan kecil, yaitu dengan **operasi bitwise**.

Cara ini memanfaatkan fakta bahwa:

- Huruf besar dan kecil dalam ASCII hanya berbeda di **bit ke-6** (yaitu bernilai 32 desimal atau `0010 0000` dalam biner).
    
- Maka, kita bisa menggunakan **operator bitwise** seperti `^`, `|`, dan `&` untuk mengubah huruf besar ke kecil, kecil ke besar, atau bahkan menukar keduanya.
    
### Operasi Dasar Bitwise

| Operasi_bitwise | Tujuan                  | Konversi            | Penjelasan Singkat                                                     |
| --------------- | ----------------------- | ------------------- | ---------------------------------------------------------------------- |
| `c ^= ' '`      | Toggle case             | huruf besar ⇄ kecil | XOR dengan 32 akan membalik status besar/kecil                         |
| c \|= ' '       | konversi ke huruf kecil | besar → kecil       | (spasi `' '` = 32) akan menyalakan bit ke-6 → menghasilkan huruf kecil |
| `c &= '_'`      | Konversi ke huruf besar | kecil → besar       | akan menghapus bit ke-6 jika hidup → menghasilkan huruf besar.         |


---

### Implementasinya:

```cpp
#include <iostream>
using namespace std;

int main() {
    string text;
    getline(cin, text);

    string upper = text;
    string lower = text;
    string toggle = text;

    for (char &c : upper) {
        if (c >= 'a' && c <= 'z') c &= '_'; // kecil -> besar
    }

    for (char &c : lower) {
        if (c >= 'A' && c <= 'Z') c |= ' '; // besar -> kecil
    }

    for (char &c : toggle) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) 
            c ^= ' '; // toggle
    }

    cout << "Asli    : " << text << "\n";
    cout << "Besar   : " << upper << "\n";
    cout << "Kecil   : " << lower << "\n";
    cout << "Toggle  : " << toggle << "\n";
    return 0;
}
```

---

### Penjelasan:

- **`c &= '_'`** (underscore `'_'` = 95) akan menghapus bit ke-6 jika hidup → menghasilkan huruf besar.
    
- **`c |= ' '`** (spasi `' '` = 32) akan menyalakan bit ke-6 → menghasilkan huruf kecil.
    
- **`c ^= ' '`** akan membalik bit ke-6 → menukar status besar/kecil.
    
- Dicek dengan `if (c >= 'a' && c <= 'z')` atau `if (isalpha(c))` agar tidak mengubah angka/simbol.
    

---

### Kelebihan:

- Sangat cepat dan efisien karena langsung bekerja di level bit.
    
- Tidak butuh header tambahan (`<cctype>`, `<algorithm>`, dll).
    
- Berguna dalam aplikasi embedded atau kompetisi yang butuh performa tinggi.
    

### Kekurangan:

- Tidak bisa digunakan untuk karakter Unicode atau non-ASCII.
    
- Kurang jelas bagi pembaca awam jika belum paham operasi bitwise.
    

## 6 | Metode Mapping (lookup table)

### 💡 Apa itu tabel mapping?

Sebuah **array berisi hasil konversi** untuk semua kemungkinan karakter. Misalnya:

- `to_lower_table['A']` = `'a'`
    
- `to_upper_table['b']` = `'B'`
    
- Karakter non-huruf (seperti angka, spasi, dll) tetap sama
    

Kita hanya perlu **mengisi tabel sekali**, lalu pakai secepat akses array biasa (`O(1)` waktu).

---

### 🛠️ Contoh: Tabel Konversi Huruf Besar ke Kecil

```cpp
#include <iostream>
#include <string>
using namespace std;

char to_lower_table[256]; // semua kemungkinan karakter ASCII

void init_to_lower() {
    for (int i = 0; i < 256; ++i) {
        if (i >= 'A' && i <= 'Z')
            to_lower_table[i] = i + 32; // ubah ke huruf kecil
        else
            to_lower_table[i] = i; // karakter lain tetap
    }
}

int main() {
    init_to_lower(); // inisialisasi tabel

    string s;
    getline(cin >> ws, s);

    for (char &c : s) {
        c = to_lower_table[(unsigned char)c]; // pakai tabel
    }

    cout << s << "\n";
    return 0;
}
```

---

### 🔁 Variasi: Tabel Konversi Huruf Kecil ke Besar

```cpp
char to_upper_table[256];

void init_to_upper() {
    for (int i = 0; i < 256; ++i) {
        if (i >= 'a' && i <= 'z')
            to_upper_table[i] = i - 32;
        else
            to_upper_table[i] = i;
    }
}
```

---

### 🔀 Variasi: Tabel **toggle case** (huruf besar jadi kecil, kecil jadi besar)

```cpp
char toggle_case_table[256];

void init_toggle_case() {
    for (int i = 0; i < 256; ++i) {
        if (i >= 'a' && i <= 'z')
            toggle_case_table[i] = i - 32; // kecil jadi besar
        else if (i >= 'A' && i <= 'Z')
            toggle_case_table[i] = i + 32; // besar jadi kecil
        else
            toggle_case_table[i] = i;
    }
}
```

---

### ⚠️ Catatan Teknis

- Pastikan karakter dikonversi ke `unsigned char` saat digunakan sebagai indeks array:
    
    ```cpp
    c = to_lower_table[(unsigned char)c];
    ```
    
    Karena `char` bisa bernilai negatif, khususnya di karakter non-ASCII.
    

---

### 🧠 Kapan perlu pakai ini?

- Saat kamu butuh performa **super cepat** (misal: konversi jutaan karakter)
    
- Saat kamu ingin **menghindari fungsi pustaka** seperti `tolower()` (misal: pada embedded system)
    
- Saat ingin **modifikasi aturan konversi sendiri**
    

---

Contoh program lengkap yang mengubah kalimat campuran jadi huruf kecil dan besar dengan toggle case menggunakan `toggle_case_table[]`:

```cpp
#include <iostream>
#include <string>
using namespace std;

char toggle_case_table[256]; // tabel untuk konversi

// Inisialisasi tabel toggle case
void init_toggle_case() {
    for (int i = 0; i < 256; ++i) {
        if (i >= 'a' && i <= 'z')
            toggle_case_table[i] = i - 32; // huruf kecil → besar
        else if (i >= 'A' && i <= 'Z')
            toggle_case_table[i] = i + 32; // huruf besar → kecil
        else
            toggle_case_table[i] = i; // karakter lain tetap
    }
}

int main() {
    init_toggle_case(); // siapkan tabel

    string s;
    getline(cin >> ws, s); // input string

    for (char &c : s) {
        c = toggle_case_table[(unsigned char)c]; // ubah pakai tabel
    }

    cout << s << "\n"; // output hasil toggle case
    return 0;
}

```