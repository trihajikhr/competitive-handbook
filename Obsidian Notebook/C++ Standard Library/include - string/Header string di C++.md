---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Header string di C++
sumber:
  - cppreference.com
  - gemini.google.com
date_learned: 2025-09-23T23:23:00
tags:
  - "#STL"
---
Link Sumber: [Standard library header \<string\> - cppreference.com](https://en.cppreference.com/w/cpp/header/string.html)

---
# 1 | Header string di C++

## 1.1 | Apa itu Header `<string>`

Header `<string>` adalah pustaka standar C++ yang mendefinisikan kelas **`std::string`** untuk mengelola urutan karakter. Secara sederhana, ini adalah cara yang lebih modern dan aman untuk bekerja dengan teks daripada menggunakan array karakter bergaya C (`char[]`). `std::string` mengabstraksi detail alokasi memori, memungkinkan kamu untuk fokus pada manipulasi teks tanpa khawatir tentang _buffer overflow_ atau manajemen memori manual.

## 1.2 | Kegunaan Header `<string>`

Kegunaan utama dari `<string>` adalah untuk mempermudah dan mengamankan operasi teks dalam program C++. Beberapa kegunaannya yang paling menonjol:

- **Manajemen Memori Otomatis:** Berbeda dengan array karakter C yang memerlukan alokasi memori manual, `std::string` secara otomatis menangani memori yang dibutuhkan. Ukurannya dapat berubah secara dinamis, sehingga kamu bisa menambahkan atau menghapus karakter tanpa harus mengalokasi ulang memori secara manual.
<br/>

- **Keamanan Tipe:** `std::string` adalah objek, bukan sekadar pointer. Hal ini mengurangi risiko kesalahan umum seperti _buffer overflow_ karena operasi seperti penambahan atau penyalinan string ditangani dengan aman.
<br/>

- **Fungsi Bawaan yang Kaya:** Pustaka ini menyediakan berbagai fungsi yang sudah ada untuk operasi umum seperti pencarian, penggantian, pemotongan, dan perbandingan string. Ini menghemat waktu dan mengurangi kode yang harus kamu tulis sendiri.

<br/>

---
# 2 | Fungsi-fungsi Berguna pada `std::string`

Berikut adalah beberapa fungsi paling berguna yang sering digunakan dengan `std::string`, beserta contoh penggunaannya.

## 2.1 | `+` dan `+=` (Operator Penambahan)

Operator `+` digunakan untuk menggabungkan (menambah) dua string atau string dengan literal C-style. Operator `+=` digunakan untuk menambahkan string ke akhir string yang sudah ada.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Halo";
    string s2 = " Dunia!";
    
    // Menggunakan operator +
    string s3 = s1 + s2; 
    cout << "Hasil gabungan: " << s3 << endl; // Output: Halo Dunia!
    
    // Menggunakan operator +=
    s1 += " C++";
    cout << "Setelah ditambah: " << s1 << endl; // Output: Halo C++
    
    return 0;
}

```


## 2.2 | `.length()` dan `.size()`

Kedua fungsi ini mengembalikan jumlah karakter dalam string. Mereka memiliki kegunaan yang sama.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string teks = "Pemrograman C++";
    
    cout << "Panjang string: " << teks.length() << endl; // Output: 15
    cout << "Ukuran string: " << teks.size() << endl;   // Output: 15
    
    return 0;
}
```

## 2.3 | `.substr()`

Fungsi ini digunakan untuk mengekstrak substring (bagian dari string) dari string yang lebih besar. Argumennya adalah posisi awal dan panjang substring.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat = "Ini adalah contoh kalimat.";
    
    // Mengambil substring dari indeks 8 dengan panjang 6 karakter
    string sub = kalimat.substr(8, 6); 
    cout << "Substring yang diambil: " << sub << endl; // Output: contoh
    
    return 0;
}
```


## 2.4 | `.find()` dan `.rfind()`

Fungsi `find()` ini digunakan untuk mencari kemunculan pertama dari substring atau karakter dalam string. Jika ditemukan, ia mengembalikan indeks posisi; jika tidak, ia mengembalikan `std::string::npos`.

Sedangkan fungsi `rfind()` digunakan untuk mencari kemunculan pertama dari substring atau karakter dalam string, namun dari belakang. Jika ditemukan, maka mengembalikan indeks, jika tidak, maka mengembalikan `std::string::npos`.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string teks = "Belajar C++ itu menyenangkan.";
    
    // Mencari kata "menyenangkan"
    size_t posisi = teks.find("menyenangkan");
    
    if (posisi != string::npos) {
        cout << "Kata 'menyenangkan' ditemukan pada indeks: " 
        << posisi << endl; // Output: 16
    } else {
        cout << "Kata tidak ditemukan." << endl;
    }
    
    return 0;
}
```

Untuk versi `rfind()`:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat = "Ini adalah contoh kalimat, ini.";

    // Mencari kemunculan pertama dari "ini"
    size_t posisi_pertama = kalimat.find("ini");
    if (posisi_pertama != string::npos) {
        cout << "Kata 'ini' pertama ditemukan pada indeks: " 
        << posisi_pertama << endl; // Output: 0
    }

    // Mencari kemunculan terakhir dari "ini"
    size_t posisi_terakhir = kalimat.rfind("ini");
    if (posisi_terakhir != string::npos) {
        cout << "Kata 'ini' terakhir ditemukan pada indeks: " 
        << posisi_terakhir << endl; // Output: 27
    }

    return 0;
}
```

## 2.5 | `.replace()`

Fungsi ini mengganti bagian dari string dengan string lain. Argumennya adalah posisi awal, jumlah karakter yang akan diganti, dan string pengganti.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat = "Harga kopi adalah 10000.";
    
    // Ganti "10000" dengan "25000"
    kalimat.replace(20, 5, "25000"); 
    cout << "Kalimat setelah diganti: " << kalimat << endl; 
    // Output: Harga kopi adalah 25000.
    
    return 0;
}
```

## 2.6 | `.erase()`

Fungsi ini digunakan untuk menghapus sebagian karakter dari string. Argumennya adalah posisi awal dan jumlah karakter yang akan dihapus.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat = "Ini kalimat yang tidak penting.";
    
    // Hapus kata "yang tidak penting" dari indeks 13 dengan panjang 19
    kalimat.erase(13, 19);
    cout << "Kalimat setelah dihapus: " << kalimat << endl; 
    // Output: Ini kalimat .
    
    return 0;
}
```

## 2.7 | `std::getline()`

Fungsi `std::getline()` digunakan untuk membaca satu baris teks dari _input stream_ (seperti `cin` atau dari file) hingga ditemukan karakter baris baru (`\n`). Ini sangat berguna untuk membaca input yang mengandung spasi, di mana `std::cin >>` saja akan berhenti pada spasi pertama.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string namaLengkap;
    cout << "Masukkan nama lengkap Anda: ";
    
    // Membaca satu baris penuh dari input
    getline(cin, namaLengkap);
    
    cout << "Halo, " << namaLengkap << "!" << endl;
    
    return 0;
}
```

## 2.8 | `.compare()`

Fungsi `.compare()` membandingkan dua string. Fungsi ini mengembalikan:

- `0` jika kedua string sama persis.
    
- Nilai `< 0` jika string yang dipanggil lebih kecil secara leksikografis (berdasarkan urutan alfabet) dari string argumen.
    
- Nilai `> 0` jika string yang dipanggil lebih besar secara leksikografis dari string argumen.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "apel";
    string s2 = "apel";
    string s3 = "pisang";
    
    // Perbandingan s1 dan s2
    if (s1.compare(s2) == 0) {
        cout << "s1 dan s2 sama." << endl; // Output: s1 dan s2 sama.
    }
    
    // Perbandingan s1 dan s3
    if (s1.compare(s3) < 0) {
        cout << "s1 lebih kecil dari s3." << endl; // Output: s1 lebih kecil dari s3.
    }
    
    return 0;
}
```

## 2.9 | `.c_str()`

Fungsi `.c_str()` digunakan untuk mendapatkan representasi C-style dari string, yaitu sebuah _pointer_ ke array karakter (`const char*`). Ini sering diperlukan saat kamu perlu berinteraksi dengan pustaka C atau fungsi-fungsi C++ yang hanya menerima `const char*` sebagai argumen.


```cpp
#include <iostream>
#include <string>
#include <cstring> // Untuk fungsi C-style, seperti strlen()
using namespace std;

int main() {
    string teks = "Contoh penggunaan c_str()";
    
    // Mengubah string menjadi const char*
    const char* c_teks = teks.c_str();
    
    // Menggunakan fungsi C-style dengan string tersebut
    cout << "Panjang string C-style: " << strlen(c_teks) << endl;
    cout << "Isi string C-style: " << c_teks << endl;
    
    return 0;
}
```

<br/>

## 2.10 | `.insert()`

Fungsi ini memiliki beberapa versi (_overloads_), tetapi kegunaan utamanya adalah untuk menambahkan data ke dalam string yang sudah ada.

Cara kerjanya adalah kamu menentukan di mana data baru akan disisipkan (`pos`) dan data apa yang akan disisipkan. Data yang ada setelah posisi penyisipan akan digeser ke kanan untuk menampung data baru.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat = "Saya belajar C++.";
    string kata_baru = "dan " ;

    // Menyisipkan string "dan " pada indeks 5
    // Indeks 5 adalah spasi di antara "Saya" dan "belajar"
    kalimat.insert(5, kata_baru);
    
    cout << "Kalimat setelah insert: " << kalimat << endl; 
    // Output: Saya dan belajar C++.
    
    return 0;
}
```

Dalam contoh di atas, kita menyisipkan string `"dan "` pada posisi kelima (`kalimat[5]`) dari string `"Saya belajar C++."`.


## 2.11 | `.empty()` dan `.clear()`

- **`.empty()`**: Memeriksa apakah string kosong (tidak ada karakter). Ini lebih efisien daripada memeriksa `s.size() == 0`.
	
- **`.clear()`**: Menghapus semua karakter dari string, membuat ukurannya menjadi nol.
	

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "Hello";
	if (!s.empty()) {
		cout << "String tidak kosong." << endl;
	}
	s.clear();
	if (s.empty()) {
		cout << "String sudah dikosongkan." << endl;
	}
	return 0;
}
```

## 2.12 | `.at()`

- Mengakses karakter pada posisi tertentu. Jika indeks di luar batas, fungsi ini akan melempar `std::out_of_range` _exception_, yang membuatnya lebih aman daripada `[]` (operator _subscript_).


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s = "Hello";
	try {
		cout << "Karakter pada indeks 1: " << s.at(1) << endl; // Output: e
		cout << s.at(10) << endl; // Ini akan melempar exception
	} catch (const out_of_range& e) {
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}
```

## 2.13 |`.append()`

- Mirip dengan `+=`, tetapi lebih fleksibel. Fungsi ini bisa menambahkan string, sebagian dari string, atau sejumlah karakter.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1 = "Hello";
	string s2 = " World";
	s1.append(s2);
	cout << s1 << endl; // Output: Hello World

	string s3 = "!!!";
	s1.append(s3, 0, 2); // Menambahkan hanya 2 karakter dari s3
	cout << s1 << endl; // Output: Hello World!!
	return 0;
}
```


## 2.14 | `string::operator[]`

Fungsi ini digunakan untuk mengakses karakter pada posisi tertentu dalam string. Berbeda dengan `.at()`, `operator[]` tidak melakukan pengecekan batas (_bounds checking_). Ini berarti, jika Anda mengakses indeks yang tidak valid, program Anda bisa mengalami _undefined behavior_, seperti _crash_. Kelebihannya, `operator[]` umumnya lebih cepat.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat = "C++ sangat seru!";

    // Mengakses karakter pada indeks ke-3 (karakter 's')
    char karakter = kalimat[3];
    cout << "Karakter pada indeks 3: " << karakter << endl; // Output: s

    // Mengubah karakter pada indeks ke-0
    kalimat[0] = 'J';
    cout << "Kalimat setelah diubah: " << kalimat << endl; // Output: J++ sangat seru!

    return 0;
}
```


## 2.15 | `string::assign()`

Fungsi ini digunakan untuk mengganti isi string dengan string atau karakter baru. Mirip dengan operator $=$, tetapi `assign()` memiliki beberapa versi yang lebih fleksibel.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Ini kalimat pertama.";
    string s2 = "Ini kalimat kedua.";

    // Mengganti seluruh isi s1 dengan s2
    s1.assign(s2);
    cout << "Setelah assign: " << s1 << endl; // Output: Ini kalimat kedua.

    // Mengganti isi dengan sebagian dari string lain
    s1.assign(s2, 4, 7); // Mengambil 7 karakter dari s2, mulai dari indeks 4
    cout << "Setelah assign sebagian: " << s1 << endl; // Output: kalimat

    return 0;
}
```

## 2.16 | `string::push_back()` dan `string::pop_back()`

Fungsi `push_back()` ini digunakan untuk menambahkan satu karakter ke akhir string. Ini adalah cara yang sangat efisien untuk membangun string karakter per karakter, misalnya dalam sebuah perulangan.

Sedangkan fungsi `pop_back()` enghapus karakter terakhir dari string. Ini adalah kebalikan dari `push_back()`.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string pesan = "Halo";
    
    // Menambahkan karakter '!' ke akhir string
    pesan.push_back('!');
    cout << "Setelah push_back: " << pesan << endl; // Output: Halo!
    
    pesan.push_back('!');
    cout << "Setelah push_back: " << pesan << endl; // Output: Halo!!
    
    pesan.pop_back();
    cout << "Setelah pop_back: " << pesan << endl; // hapus '!'

    return 0;
}
```

## 2.17 | `.resize()`


Fungsi `resize()` digunakan untuk mengubah jumlah karakter dalam sebuah string. Ada dua skenario utama saat menggunakan fungsi ini:

1. **Mengurangi Ukuran String**: Jika Anda mengubah ukuran string menjadi lebih kecil dari ukuran aslinya, karakter di akhir string akan dipotong.
<br/>

2. **Menambah Ukuran String**: Jika Anda mengubah ukuran string menjadi lebih besar, karakter baru akan ditambahkan ke akhir string. Secara _default_, karakter yang ditambahkan adalah karakter kosong (`\0`), tetapi Anda juga bisa menentukan karakter lain sebagai pengisi.
    

Berikut adalah kode yang mendemonstrasikan kedua skenario tersebut.

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Skenario 1: Mengurangi ukuran string
    cout << "--- Mengurangi Ukuran ---" << endl;
    string s1 = "Pemrograman C++";
    cout << "String awal: \"" << s1 << "\"" << endl;
    cout << "Ukuran awal: " << s1.size() << endl;

    s1.resize(5); // Ubah ukuran menjadi 5 karakter
    cout << "String setelah di-resize: \"" << s1 << "\"" << endl;
    cout << "Ukuran baru: " << s1.size() << endl;

    cout << endl;

    // Skenario 2: Menambah ukuran string
    cout << "--- Menambah Ukuran ---" << endl;
    string s2 = "Hello";
    cout << "String awal: \"" << s2 << "\"" << endl;
    cout << "Ukuran awal: " << s2.size() << endl;

    // Menambah ukuran string menjadi 10, dengan karakter pengisi 'x'
    s2.resize(10, 'x'); 
    cout << "String setelah di-resize: \"" << s2 << "\"" << endl;
    cout << "Ukuran baru: " << s2.size() << endl;

    cout << endl;

    // Menambah ukuran tanpa karakter pengisi (default '\0')
    string s3 = "C++";
    cout << "String awal: \"" << s3 << "\"" << endl;
    cout << "Ukuran awal: " << s3.size() << endl;

    s3.resize(8); 
    cout << "String setelah di-resize: \"";
    // Loop untuk mencetak string karakter per karakter
    for (char c : s3) {
        if (c == '\0') {
            cout << "\\0"; // Cetak '\0' jika karakter null ditemukan
        } else {
            cout << c;
        }
    }
    cout << "\"" << endl;
    cout << "Ukuran baru: " << s3.size() << endl;

    return 0;
}
```

## 2.18 | `capacity()` dan `shrink_to_fit()`

Kedua fungsi ini berkaitan dengan manajemen memori internal string.

- **`capacity()`**: Fungsi ini mengembalikan **ukuran memori** (dalam byte) yang dialokasikan string. Ukuran ini biasanya lebih besar atau sama dengan jumlah karakter yang ada. Hal ini memungkinkan `std::string` untuk menambahkan karakter baru tanpa harus terus-menerus mengalokasikan ulang memori, yang merupakan proses yang mahal.
    
- **`shrink_to_fit()`**: Fungsi ini meminta `std::string` untuk **mengurangi kapasitas memorinya** hingga sesuai dengan ukuran string saat ini. Jika Anda memiliki string yang sangat besar lalu menguranginya, `capacity()`-nya mungkin tetap besar. Dengan `shrink_to_fit()`, Anda bisa membebaskan memori yang tidak terpakai itu.
    

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "ini adalah string yang panjang";
    cout << "Ukuran string: " << s.size() << endl;
    cout << "Kapasitas awal: " << s.capacity() << endl;

    s.resize(10);
    cout << "\nUkuran setelah resize: " << s.size() << endl;
    cout << "Kapasitas setelah resize (masih sama): " << s.capacity() << endl;

    s.shrink_to_fit();
    cout << "\nUkuran setelah shrink_to_fit(): " << s.size() << endl;
    cout << "Kapasitas setelah shrink_to_fit(): " << s.capacity() << endl;

    return 0;
}
```

Seperti yang Anda lihat dari contoh, meskipun `resize()` mengurangi jumlah karakter, `capacity()`-nya tidak langsung berubah. Hanya setelah `shrink_to_fit()` dipanggil, memori yang tidak terpakai dibebaskan.
## 2.19 | `front()` dan `back()`

Fungsi ini adalah cara yang sangat ringkas untuk mengakses karakter **pertama** dan **terakhir** dari sebuah string.

- **`front()`**: Mengembalikan referensi ke karakter pertama string.
    
- **`back()`**: Mengembalikan referensi ke karakter terakhir string.
    

Kedua fungsi ini tidak melakukan pengecekan batas, jadi string tidak boleh kosong saat menggunakannya.

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string kata = "Hello";

    cout << "Karakter pertama: " << kata.front() << endl; // Output: H
    cout << "Karakter terakhir: " << kata.back() << endl;  // Output: o

    return 0;
}
```


---
# 3 | Fungsi-fungsi Dari cppreference
## 3.1 | Functions dan Comparison

### 3.1.1 | Operator `+`

**`operator+`** digunakan untuk menggabungkan (menggabungkan) string. Ini dapat menggabungkan dua `std::string`, `std::string` dengan literal C-style, atau `std::string` dengan sebuah karakter. Operasi ini membuat string baru dan tidak memodifikasi string aslinya.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Halo";
    string s2 = " Dunia";
    
    // Menggabungkan dua string
    string s3 = s1 + s2; 
    cout << "Hasil gabungan: " << s3 << endl; // Output: Halo Dunia
    
    // Menggabungkan dengan literal C-style
    string s4 = s1 + " C++";
    cout << "Hasil gabungan: " << s4 << endl; // Output: Halo C++
    
    return 0;
}
```

### 3.1.2 | Perbandingan Leksikografis (Comparison)

Operator perbandingan \==, `!=`, `<`, `>`, `<=`, `>=` digunakan untuk membandingkan dua string secara leksikografis, artinya berdasarkan urutan alfabet (seperti yang ada di kamus). Perbandingan ini peka terhadap huruf besar dan kecil.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "apel";
    string str2 = "apel";
    string str3 = "Apel";
    string str4 = "pisang";
    
    // Operator kesamaan (==)
    if (str1 == str2) {
        cout << "str1 dan str2 sama." << endl; // Output: str1 dan str2 sama.
    }
    
    // Operator ketidaksamaan (!=) - peka huruf besar/kecil
    if (str1 != str3) {
        cout << "str1 dan str3 tidak sama (karena peka huruf besar/kecil)." << endl; // Output: str1 dan str3 tidak sama (karena peka huruf besar/kecil).
    }
    
    // Operator kurang dari (<) - berdasarkan urutan alfabet
    if (str1 < str4) {
        cout << "str1 ('apel') lebih kecil dari str4 ('pisang')." << endl; // Output: str1 ('apel') lebih kecil dari str4 ('pisang').
    }
    
    return 0;
}
```

### 3.1.3 | `std::swap`

`std::swap(basic_string)` adalah fungsi khusus yang menukar isi dua objek `std::string` dengan sangat efisien. Alih-alih menyalin data karakter, fungsi ini hanya menukar _pointer_ internal dan data ukuran, yang jauh lebih cepat, terutama untuk string yang besar.

```cpp
#include <iostream>
#include <string>
#include <utility> // Header untuk swap
using namespace std;

int main() {
    string a = "satu";
    string b = "dua";
    
    cout << "Sebelum swap:" << endl;
    cout << "a: " << a << endl; // Output: a: satu
    cout << "b: " << b << endl; // Output: b: dua
    
    swap(a, b);
    
    cout << "Setelah swap:" << endl;
    cout << "a: " << a << endl; // Output: a: dua
    cout << "b: " << b << endl; // Output: b: satu
    
    return 0;
}
```

### 3.1.4 | `erase` dan `erase_if`

- **`erase`** menghapus karakter dari string pada posisi dan jumlah karakter tertentu.
    
- **`erase_if`** (tersedia sejak C++20) adalah cara yang lebih modern dan ringkas untuk menghapus semua karakter dari string yang memenuhi kriteria tertentu (yang ditentukan oleh fungsi _lambda_ atau fungsi lainnya).


```cpp
#include <iostream>
#include <string>
#include <cctype> // Untuk fungsi isspace()
using namespace std;

int main() {
    // Penggunaan erase
    string kalimat = "Ini contoh kalimat.";
    // Menghapus 7 karakter dari indeks 4 (" contoh")
    kalimat.erase(3, 7); 
    cout << "Setelah erase: " << kalimat << endl; // Output: Ini kalimat.

    // Penggunaan erase_if (C++20)
    string angka_dan_spasi = "1 2  3   4";
    // Menghapus semua spasi
    erase_if(angka_dan_spasi, [](char c) {
        return isspace(static_cast<unsigned char>(c));
    });
    cout << "Setelah erase_if: " << angka_dan_spasi << endl; // Output: 1234
    
    return 0;
}
```

## 3.2 | Input Output

### 3.2.1 | `operator<<` dan `operator>>`

  * **`operator<<`** digunakan untuk mengirimkan data, seperti string, ke *output stream*, seperti `std::cout` atau file. Ini adalah cara standar untuk mencetak string ke konsol.
  * **`operator>>`** digunakan untuk mengambil data dari *input stream*, seperti `std::cin`. **Penting untuk diingat**, operator ini berhenti membaca saat bertemu spasi, tab, atau karakter baris baru. Ini artinya hanya membaca satu "kata" saja.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama_pertama;
    string nama_lengkap;

    // Menggunakan operator>>
    cout << "Masukkan nama pertama Anda (misal: Budi): ";
    cin >> nama_pertama; 
    cout << "Nama pertama Anda adalah: " << nama_pertama << endl;

    // Menggunakan operator<<
    string pesan = "Selamat datang!";
    cout << pesan << endl; 
    
    return 0;
}
```


### 3.2.2 | `std::getline()`

**`std::getline()`** adalah fungsi yang digunakan untuk membaca seluruh baris dari *input stream* (seperti `cin` atau dari file) hingga ditemukan karakter baris baru (`\n`). Ini adalah solusi yang tepat untuk membaca kalimat yang mengandung spasi, karena `operator>>` akan berhenti di spasi.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string kalimat_lengkap;
    
    cout << "Masukkan sebuah kalimat (misal: Saya sedang belajar C++): ";
    // Menggunakan getline() untuk membaca seluruh baris, termasuk spasi
    getline(cin, kalimat_lengkap); 
    
    cout << "Kalimat yang Anda masukkan adalah: " << kalimat_lengkap;
    
    return 0;
}
```

## 3.3 | Conversion

Tentu, mari kita lanjutkan dengan penjelasan dan contoh untuk fungsi-fungsi konversi numerik yang sangat berguna dari `<string>`. Fungsi-fungsi ini mempermudah proses mengubah string menjadi angka dan sebaliknya, yang merupakan tugas umum dalam pemrograman.

### 3.3.1 | Konversi String ke Angka (String to Number)

Fungsi-fungsi ini memungkinkan kamu untuk mengonversi string yang berisi representasi numerik menjadi tipe data angka yang sesuai. Semua fungsi ini diperkenalkan di C++11, sehingga membutuhkan kompiler yang mendukung standar tersebut.

#### 3.3.1.1 | `stoi`, `stol`, `stoll`

Fungsi ini mengonversi string menjadi **bilangan bulat bertanda** (`signed integer`).

- **`stoi`** (string to int)
    
- **`stol`** (string to long)
    
- **`stoll`** (string to long long)
    

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str_int = "12345";
    string str_long = "9876543210";

    int num_int = stoi(str_int);
    long num_long = stol(str_long);

    cout << "Nilai int: " << num_int << endl;
    cout << "Nilai long: " << num_long << endl;
    
    return 0;
}
```

#### 3.3.1.2 | `stoul`, `stoull`

Fungsi ini mengonversi string menjadi **bilangan bulat tak bertanda** (`unsigned integer`).

- **`stoul`** (string to unsigned long)
    
- **`stoull`** (string to unsigned long long)
    

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str_uint = "123456789";
    
    unsigned long num_uint = stoul(str_uint);
    
    cout << "Nilai unsigned long: " << num_uint << endl;
    
    return 0;
}
```

#### 3.3.1.3 | `stof`, `stod`, `stold`

Fungsi ini mengonversi string menjadi **bilangan _floating-point_**.

- **`stof`** (string to float)
    
- **`stod`** (string to double)
    
- **`stold`** (string to long double)


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str_double = "3.14159";
    
    double num_double = stod(str_double);
    
    cout << "Nilai double: " << num_double << endl;
    
    return 0;
}
```


### 3.3.2 | Konversi Angka ke String (Number to String)

Fungsi-fungsi ini adalah kebalikan dari yang di atas, mengubah nilai numerik menjadi representasi string.

#### 3.3.2.1 |  `to_string`

Fungsi ini mengonversi nilai numerik apa pun (int, long, double, dll.) menjadi **`std::string`**. Ini sangat berguna untuk mencetak nilai numerik bersama dengan teks lainnya tanpa harus mengonversi secara manual.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int umur = 30;
    double pi = 3.14159;

    string pesan_umur = "Umur saya adalah " + to_string(umur) + " tahun.";
    string pesan_pi = "Nilai Pi: " + to_string(pi);

    cout << pesan_umur << endl;
    cout << pesan_pi << endl;
    
    return 0;
}
```

#### 3.3.2.2 | `to_wstring`

Fungsi ini berfungsi sama seperti `to_string`, tetapi mengonversi nilai numerik menjadi **`std::wstring`**. `wstring` digunakan untuk menangani set karakter yang lebih luas, seperti Unicode, yang memerlukan lebih dari satu _byte_ per karakter.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    int tahun = 2025;
    
    // Perhatikan penggunaan wchar_t dan wcout
    wstring pesan_tahun = L"Tahun saat ini: " + to_wstring(tahun);
    
    wcout << pesan_tahun << endl; 

    return 0;
}
```

## 3.4 | Range Acces

Tentu, mari kita lanjutkan dengan penjelasan dan contoh untuk fungsi-fungsi akses rentang (_range access_) yang disediakan oleh `<string>`. Fungsi-fungsi ini penting untuk mengelola string dan memanfaatkannya dalam algoritma atau perulangan.
### 3.4.1 | Akses Rentang (`Range Access`)

Fungsi-fungsi ini menyediakan cara untuk mendapatkan _iterator_ dan informasi dasar tentang string, memfasilitasi perulangan dan interaksi dengan algoritma pustaka standar.

#### 3.4.1.1 | `begin` dan `end`

- **`begin()`**: Mengembalikan _iterator_ ke karakter **pertama** dari string.
    
- **`end()`**: Mengembalikan _iterator_ ke posisi **setelah** karakter terakhir. Ini bukan karakter yang valid, tetapi berfungsi sebagai penanda akhir perulangan.
    
- **`cbegin()`** dan **`cend()`** (diperkenalkan di C++11/C++14) adalah versi konstan dari `begin()` dan `end()`. Mereka mengembalikan _iterator_ yang tidak dapat memodifikasi karakter, memastikan string tetap tidak berubah.

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    // Menggunakan iterator untuk perulangan
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << " "; // Output: H e l l o
    }
    cout << endl;
    
    // Perulangan modern (range-based for loop) menggunakan begin() dan end() di belakang layar
    for (char c : s) {
        cout << c << " "; // Output: H e l l o
    }
    cout << endl;

    return 0;
}
```


### 3.4.2 | Akses Rentang Terbalik (`Reverse Range Access`)

#### 3.4.2.1 | `rbegin` dan `rend`

- **`rbegin()`**: Mengembalikan _reverse iterator_ ke karakter **terakhir** dari string. Ini adalah "awal" dari perulangan terbalik.
    
- **`rend()`**: Mengembalikan _reverse iterator_ ke posisi **sebelum** karakter pertama. Ini adalah "akhir" dari perulangan terbalik.
    
- **`crbegin()`** dan **`crend()`** (C++14) adalah versi konstan.
    

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "Hello";

    // Menggunakan reverse iterator untuk perulangan terbalik
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        cout << *it; // Output: olleH
    }
    cout << endl;

    return 0;
}
```

### 3.4.3 | Informasi Ukuran dan Status

#### 3.4.3.1 | `size`, `ssize`, `empty`

- **`size()`**: Mengembalikan jumlah karakter dalam string sebagai tipe data `std::size_t` (tak bertanda).
    
- **`ssize()`** (C++20): Mengembalikan jumlah karakter sebagai tipe data `std::ptrdiff_t` (bertanda). Berguna untuk menghindari peringatan kompiler saat membandingkan dengan tipe data bertanda lainnya.
    
- **`empty()`**: Mengembalikan `true` jika string tidak memiliki karakter (`.size() == 0`), dan `false` jika tidak. Ini adalah cara yang lebih jelas dan efisien daripada memeriksa ukuran string secara manual.


```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Contoh";
    string s2 = "";

    cout << "Ukuran s1: " << s1.size() << endl; // Output: 6
    cout << "Ukuran s2: " << s2.size() << endl; // Output: 0

    if (s1.empty()) {
        cout << "s1 kosong." << endl;
    } else {
        cout << "s1 tidak kosong." << endl; // Output: s1 tidak kosong.
    }

    if (s2.empty()) {
        cout << "s2 kosong." << endl; // Output: s2 kosong.
    }
    
    return 0;
}
```

### 3.4.4 | Akses ke Data Internal

#### 3.4.4.1 | `data`

- **`data()`** (C++17): Mengembalikan _pointer_ (`char*`) ke array karakter yang mendasari string. Ini memungkinkan modifikasi langsung pada string jika tidak digunakan versi konstan. Ini berbeda dengan `c_str()` yang mengembalikan `const char*` dan tidak bisa dimodifikasi.
    


```cpp
#include <iostream>
#include <string>
#include <cstring> // Untuk strlen
using namespace std;

int main() {
    string s = "Hello";
    
    // Mendapatkan pointer ke array internal
    char* ptr = s.data(); 

    cout << "Isi string melalui pointer: " << ptr << endl; // Output: Hello
    
    // Perubahan langsung pada array internal
    ptr[0] = 'J';
    cout << "Setelah perubahan: " << s << endl; // Output: Jello
    
    return 0;
}
```

## 3.5 | Literals

Ini bagian terakhir, yaitu tentang _string literals_. Fungsinya menyediakan cara yang lebih ringkas dan modern untuk membuat objek `std::string`.

### 3.5.1 | `operator""s` (Sufiks `s`)

**`operator""s`** adalah sufiks yang bisa kamu tambahkan di akhir literal string (seperti `"hello"`). Ketika sufiks ini digunakan, kompiler secara otomatis mengubah literal C-style (`const char*`) menjadi objek **`std::string`** yang lengkap. Ini diperkenalkan di C++14 dan sangat berguna untuk menghindari pengetikan `std::string()` atau `std::string("")`.

Untuk menggunakannya, kamu perlu menyertakan `<string>` dan menggunakan _inline namespace_ `std::literals::string_literals` atau `using namespace std::string_literals`.

```cpp
#include <iostream>
#include <string>

// Masukkan namespace untuk menggunakan sufiks "s"
using namespace std::string_literals;

int main() {
    // Tanpa sufiks, ini adalah literal C-style (const char*)
    const char* c_style = "Halo Dunia";
    
    // Dengan sufiks 's', ini langsung menjadi objek std::string
    std::string cpp_style = "Halo Dunia"s; 
    
    // Contoh lain, menggabungkan string literal dengan string lain
    std::string pesan = "Selamat datang"s + " di C++.";
    
    std::cout << "Tipe C-style: " << c_style << std::endl;
    std::cout << "Tipe C++-style: " << cpp_style << std::endl;
    std::cout << "Pesan lengkap: " << pesan << std::endl;
    
    return 0;
}
```

**Kenapa ini berguna?**

Sufiks `s` sangat berguna untuk:

- **Meningkatkan Keamanan:** Secara eksplisit menyatakan bahwa kamu ingin menggunakan `std::string`, yang memiliki fitur keamanan dan manajemen memori otomatis, bukan array karakter C yang lebih rentan.
<br/>

- **Menyederhanakan Kode:** Mengurangi kode yang diperlukan untuk membuat string.
<br/>

- **Konsistensi Tipe:** Memastikan bahwa operasi seperti penambahan (`+`) menghasilkan `std::string`, bukan _pointer_ C-style. Ini mencegah kesalahan yang mungkin muncul saat mencoba menggabungkan tipe data yang tidak cocok.