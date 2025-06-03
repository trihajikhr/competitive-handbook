---
obsidianUIMode: preview
note_type: tips trick
tips_trick: pengenalan h
sumber: Google.com, AI
tags:
  - string
  - convert
---
#string #convert 

---
# Header cctype
File header `<cctype>` memiliki banyak fungsi untuk membantu kita mengenali jenis suatu karakter. Seperti menandai bahwa karakter tersebut adalah karakter angka, huruf, tanda baca, angka-huruf, huruf besar atau huruf kecil, dan sebagainya. Jadi, karena alasan tersebut, mungkin perlu bagi kita mempelajari fungsi-fungsi yang ada di file header ini.

## 1 | Fungsi `isalpha()`

Fungsi `isalpha()` digunakan untuk mengecek apakah sebuah karakter adalah huruf alfabet, baik huruf besar (A–Z) maupun huruf kecil (a–z). Fungsi ini termasuk dalam pustaka `<cctype>`.
### Penjelasan:

Katakanlah kita memiliki sebuah karakter `c`, maka:

- `isalpha(c)` akan mengembalikan **nilai true (benar)** jika `c` adalah huruf (besar atau kecil).
    
- `isalpha(c)` akan mengembalikan **false (salah)** jika `c` adalah angka, spasi, atau simbol.
### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'A';
    char b = 'g';
    char c = '1';
    char d = '#';

    cout << isalpha(a) << "\n"; // 1 (benar, huruf)
    cout << isalpha(b) << "\n"; // 1 (benar, huruf)
    cout << isalpha(c) << "\n"; // 0 (salah, angka)
    cout << isalpha(d) << "\n"; // 0 (salah, simbol)

    return 0;
}
```

---

### Kegunaan:

- **Memfilter huruf dari string campuran** (misalnya mengabaikan angka dan simbol).
    
- **Validasi input** agar hanya menerima huruf.
    
- **Pembersihan data teks**, misalnya saat membuat program pemrosesan kata.

---

## 2 | Fungsi `isdigit()`

Fungsi `isdigit()` digunakan untuk mengecek apakah sebuah karakter adalah **angka digit desimal**, yaitu 0 sampai 9. Fungsi ini juga termasuk dalam pustaka `<cctype>`.

### Penjelasan:

Jika kita punya sebuah karakter `c`, maka:

- `isdigit(c)` akan mengembalikan **true (benar)** jika `c` adalah karakter angka `'0'` hingga `'9'`.
    
- `isdigit(c)` akan mengembalikan **false (salah)** jika `c` adalah huruf, simbol, atau spasi.
    

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = '5';
    char b = '9';
    char c = 'a';
    char d = '#';

    cout << isdigit(a) << "\n"; // 1 (benar, angka)
    cout << isdigit(b) << "\n"; // 1 (benar, angka)
    cout << isdigit(c) << "\n"; // 0 (salah, huruf)
    cout << isdigit(d) << "\n"; // 0 (salah, simbol)

    return 0;
}
```

---

### Kegunaan:

- **Validasi input numerik**, seperti hanya menerima angka di form isian.
    
- **Mengekstrak angka dari string** yang bercampur huruf dan simbol.
    
- **Menghitung jumlah digit dalam sebuah teks**.

---

## 3 | Fungsi `isalnum()`

Fungsi `isalnum()` digunakan untuk mengecek apakah sebuah karakter adalah **huruf** (A–Z, a–z) atau **angka digit** (0–9). Dengan kata lain, `isalnum()` menggabungkan fungsi `isalpha()` dan `isdigit()` sekaligus.


### Penjelasan:

Jika kita memiliki karakter `c`, maka:

- `isalnum(c)` akan mengembalikan **true (benar)** jika `c` adalah huruf atau angka.
    
- `isalnum(c)` akan mengembalikan **false (salah)** jika `c` adalah simbol atau spasi.
    


### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'A';
    char b = '8';
    char c = '%';
    char d = 'z';

    cout << isalnum(a) << "\n"; // 1 (benar, huruf)
    cout << isalnum(b) << "\n"; // 1 (benar, angka)
    cout << isalnum(c) << "\n"; // 0 (salah, simbol)
    cout << isalnum(d) << "\n"; // 1 (benar, huruf)

    return 0;
}
```

---

### Kegunaan:

- **Validasi input** agar hanya mengandung huruf atau angka (alphanumeric).
    
- **Filter karakter** dari string campuran untuk membuang simbol.
    
- **Mengecek karakter pada password**, apakah hanya huruf dan angka.

---

## 4 | Fungsi `islower()`

Fungsi `islower()` digunakan untuk mengecek apakah sebuah karakter adalah **huruf kecil** (a–z). Fungsi ini sangat berguna saat kita ingin membedakan huruf kecil dari huruf besar.
### Penjelasan:

Jika kita punya karakter `c`, maka:

- `islower(c)` akan mengembalikan **true (benar)** jika `c` adalah huruf kecil.
    
- `islower(c)` akan mengembalikan **false (salah)** jika `c` adalah huruf besar, angka, simbol, atau spasi.
    

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'a';
    char b = 'Z';
    char c = '3';
    char d = 'm';

    cout << islower(a) << "\n"; // 1 (benar, huruf kecil)
    cout << islower(b) << "\n"; // 0 (salah, huruf besar)
    cout << islower(c) << "\n"; // 0 (salah, angka)
    cout << islower(d) << "\n"; // 1 (benar, huruf kecil)

    return 0;
}
```

---

### Kegunaan:

- **Mengelompokkan huruf kecil dan besar** dalam proses analisis teks.
    
- **Konversi huruf kecil ke huruf besar** dengan fungsi `toupper()`, hanya jika `islower()` bernilai true.
    
- **Pembersihan atau validasi karakter huruf kecil** pada input.
    

---
## 5 | Fungsi `isupper()`

Fungsi `isupper()` digunakan untuk mengecek apakah sebuah karakter adalah **huruf besar** (A–Z). Fungsi ini sangat berguna untuk membedakan huruf besar dari huruf kecil dalam sebuah string.


### Penjelasan:

Jika kita punya karakter `c`, maka:

- `isupper(c)` akan mengembalikan **true (benar)** jika `c` adalah huruf besar.
    
- `isupper(c)` akan mengembalikan **false (salah)** jika `c` adalah huruf kecil, angka, simbol, atau spasi.
    

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'A';
    char b = 'z';
    char c = '7';
    char d = 'M';

    cout << isupper(a) << "\n"; // 1 (benar, huruf besar)
    cout << isupper(b) << "\n"; // 0 (salah, huruf kecil)
    cout << isupper(c) << "\n"; // 0 (salah, angka)
    cout << isupper(d) << "\n"; // 1 (benar, huruf besar)

    return 0;
}
```

---

### Kegunaan:

- **Membedakan huruf besar dan kecil** dalam pengolahan teks.
    
- **Konversi huruf besar ke huruf kecil** dengan `tolower()`, hanya jika `isupper()` bernilai true.
    
- **Validasi input huruf kapital** pada kata atau kode tertentu.
    

---

## 6 | Fungsi `isspace()`

Fungsi `isspace()` digunakan untuk mengecek apakah sebuah karakter adalah karakter spasi putih (whitespace), termasuk spasi biasa, tab, newline, dan karakter whitespace lain.

### Penjelasan:

Jika kita punya karakter `c`, maka:

- `isspace(c)` akan mengembalikan **true** jika `c` adalah spasi `' '`, tab `'\t'`, newline `'\n'`, carriage return `'\r'`, form feed `'\f'`, atau vertical tab `'\v'`.
    
- `isspace(c)` akan mengembalikan **false** jika `c` bukan karakter whitespace.
    
### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = ' ';
    char b = '\n';
    char c = 'A';
    char d = '\t';

    cout << isspace(a) << "\n"; // 1 (true, spasi)
    cout << isspace(b) << "\n"; // 1 (true, newline)
    cout << isspace(c) << "\n"; // 0 (false, huruf)
    cout << isspace(d) << "\n"; // 1 (true, tab)

    return 0;
}
```

---

### Kegunaan:

- **Memisahkan kata** berdasarkan spasi dan karakter whitespace.
    
- **Membersihkan input** agar tidak ada whitespace yang tidak diinginkan.
    
- **Parsing teks** yang menggunakan whitespace sebagai pemisah.
    

---
## 7 | Fungsi `ispunct()`

Fungsi `ispunct()` digunakan untuk mengecek apakah sebuah karakter adalah **tanda baca atau simbol** yang bukan huruf, angka, atau spasi.

### Penjelasan:

Jika kita punya karakter `c`, maka:

- `ispunct(c)` akan mengembalikan **true** jika `c` termasuk karakter tanda baca seperti `!`, `?`, `,`, `.`, `;`, `:`, `@`, `#`, `$`, `%`, `&`, dan lain-lain.
    
- `ispunct(c)` akan mengembalikan **false** jika `c` adalah huruf, angka, atau whitespace.
    

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = '!';
    char b = '#';
    char c = 'A';
    char d = '5';
    char e = ' ';

    cout << ispunct(a) << "\n"; // 1 (true, tanda baca)
    cout << ispunct(b) << "\n"; // 1 (true, tanda baca)
    cout << ispunct(c) << "\n"; // 0 (false, huruf)
    cout << ispunct(d) << "\n"; // 0 (false, angka)
    cout << ispunct(e) << "\n"; // 0 (false, spasi)

    return 0;
}
```

---

### Kegunaan:

- **Memfilter tanda baca** saat memproses teks.
    
- **Menghapus simbol** agar hanya tersisa huruf dan angka.
    
- **Mengecek validitas karakter input** dalam aplikasi tertentu.
    

---

## 8 | Fungsi `tolower()` dan `toupper()`

Kedua fungsi ini digunakan untuk **mengubah karakter huruf besar menjadi kecil** (`tolower()`), dan **mengubah karakter huruf kecil menjadi besar** (`toupper()`).

### Penjelasan singkat:

- `tolower(c)` mengembalikan karakter huruf kecil dari `c` jika `c` adalah huruf besar; selain itu mengembalikan `c` apa adanya.
    
- `toupper(c)` mengembalikan karakter huruf besar dari `c` jika `c` adalah huruf kecil; selain itu mengembalikan `c` apa adanya.
    
### Contoh singkat:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'A';
    char b = 'z';
    char c = '1';

    cout << (char)tolower(a) << "\n"; // a
    cout << (char)toupper(b) << "\n"; // Z
    cout << (char)tolower(c) << "\n"; // 1 (tidak berubah)

    return 0;
}
```

---

### Kegunaan:

- **Konversi huruf agar seragam** (semua kecil atau semua besar).
    
- **Membantu proses pencarian dan perbandingan string tanpa case-sensitive**.
    

---
## 9 | Fungsi `isxdigit()`

Fungsi `isxdigit()` mengecek apakah karakter merupakan **digit heksadesimal** valid, yaitu karakter `'0'`–`'9'`, `'a'`–`'f'`, atau `'A'`–`'F'`.
### Penjelasan:

Jika karakter `c` berada dalam rentang tersebut, maka `isxdigit(c)` mengembalikan true, jika tidak false.
### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = '9';
    char b = 'B';
    char c = 'g';
    char d = 'F';
    char e = 'z';

    cout << isxdigit(a) << "\n"; // 1
    cout << isxdigit(b) << "\n"; // 1
    cout << isxdigit(c) << "\n"; // 0
    cout << isxdigit(d) << "\n"; // 1
    cout << isxdigit(e) << "\n"; // 0

    return 0;
}
```

---

## 10 | Fungsi `iscntrl()`

Fungsi `iscntrl()` mengecek apakah karakter adalah karakter kontrol non-printable seperti newline `\n`, carriage return `\r`, tab `\t`, dll.
### Penjelasan:

Jika `c` adalah karakter kontrol, fungsi ini mengembalikan true, jika tidak false.

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = '\n';
    char b = '\t';
    char c = 'A';

    cout << iscntrl(a) << "\n"; // 1
    cout << iscntrl(b) << "\n"; // 1
    cout << iscntrl(c) << "\n"; // 0

    return 0;
}
```

---

## 11 | Fungsi `isgraph()`

Fungsi `isgraph()` mengecek apakah karakter adalah **printable** dan **bukan spasi**.

### Penjelasan:

Karakter seperti huruf, angka, simbol adalah true; spasi dan karakter non-printable adalah false.

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'A';
    char b = ' ';
    char c = '#';
    char d = '\n';

    cout << isgraph(a) << "\n"; // 1
    cout << isgraph(b) << "\n"; // 0
    cout << isgraph(c) << "\n"; // 1
    cout << isgraph(d) << "\n"; // 0

    return 0;
}
```

---

## 12 | Fungsi `isprint()`

Fungsi `isprint()` mengecek apakah karakter adalah **printable**, termasuk spasi.

### Penjelasan:

Semua karakter yang bisa ditampilkan di layar (huruf, angka, simbol, spasi) akan mengembalikan true.

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = 'A';
    char b = ' ';
    char c = '\n';

    cout << isprint(a) << "\n"; // 1
    cout << isprint(b) << "\n"; // 1
    cout << isprint(c) << "\n"; // 0

    return 0;
}
```

---

## 13 | Fungsi `isblank()`

Fungsi `isblank()` mengecek apakah karakter adalah **spasi biasa (' ')** atau **tab ('\t')**.

### Penjelasan:

Lebih spesifik dari `isspace()` yang mencakup spasi, tab, newline, dll. `isblank()` hanya cek spasi dan tab.

### Contoh Implementasi:

```cpp
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char a = ' ';
    char b = '\t';
    char c = '\n';

    cout << isblank(a) << "\n"; // 1
    cout << isblank(b) << "\n"; // 1
    cout << isblank(c) << "\n"; // 0

    return 0;
}
```
