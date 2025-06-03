---
obsidianUIMode: preview
note_type: tips trick
tips_trick: pengenalah heder string
sumber: Google.com, AI
tags:
  - string
---
#string 

---
# Pengenalan Header String

Header `<string>` adalah salah satu pustaka standar di C++ yang menyediakan tipe data `std::string` beserta fungsi-fungsi dan operator yang memudahkan kita dalam mengelola teks atau kumpulan karakter. Dengan menggunakan header ini, kita bisa membuat, memodifikasi, dan memanipulasi string secara lebih mudah dibandingkan harus menggunakan array karakter manual ala C.

Kegunaan utama dari header `<string>` adalah untuk memudahkan pengelolaan teks. Tipe `std::string` memungkinkan kita untuk menyimpan teks dalam variabel, mengakses karakter per karakter, menggabungkan string, mengambil potongan string (substring), mencari substring, dan berbagai operasi lain yang sering dibutuhkan saat mengolah data berupa teks.

Selain itu, `std::string` secara otomatis mengelola memori untuk kita, sehingga kita tidak perlu pusing mengalokasikan dan membebaskan memori secara manual seperti ketika memakai array karakter tradisional. Ini sangat membantu dalam mengurangi kesalahan seperti buffer overflow.

Singkatnya, header `<string>` adalah alat yang sangat penting dalam pemrograman modern dengan C++ untuk mengolah teks secara efisien, mudah, dan aman. Sebagian besar program yang berhubungan dengan input-output teks, parsing, atau manipulasi kata akan memanfaatkan tipe dan fungsi dari header ini.

<br/><br/>

# Iterator
### 🔹 Apa Itu Iterator pada `std::string`?

Iterator adalah objek yang memungkinkan kita untuk mengakses elemen-elemen dalam sebuah container (seperti `std::string`) secara berurutan. Dalam konteks `std::string`, iterator memungkinkan kita untuk menelusuri setiap karakter dalam string, baik dari awal ke akhir maupun sebaliknya.

---
### 🔹 Jenis-Jenis Iterator pada `std::string`

 ## 1 | Iterator `begin()` dan `end()`

- `begin()` mengembalikan iterator yang menunjuk ke karakter pertama dalam string.
	
- `end()` mengembalikan iterator yang menunjuk ke posisi setelah karakter terakhir dalam string (bukan karakter terakhir itu sendiri).
	

Contoh penggunaan:

```cpp
#include <iostream>
#include <string>

int main() {
	std::string str = "Hello, World!";
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		std::cout << *it << ' ';
	}
	return 0;
}
```

Output:

```
H e l l o ,   W o r l d !
```

Dalam contoh di atas, kita menggunakan iterator untuk mencetak setiap karakter dalam string `str`.

## 2 | Iterator `rbegin()` dan `rend()`

- `rbegin()` mengembalikan reverse iterator yang menunjuk ke karakter terakhir dalam string.
	
- `rend()` mengembalikan reverse iterator yang menunjuk ke posisi sebelum karakter pertama dalam string.
	

Contoh penggunaan:

```cpp
#include <iostream>
#include <string>

int main() {
	std::string str = "Hello, World!";
	for (std::string::reverse_iterator rit = str.rbegin(); rit != str.rend(); ++rit) {
		std::cout << *rit << ' ';
	}
	return 0;
}
```

Output:

```
! d l r o W   , o l l e H
```

Di sini, kita mencetak karakter dalam string `str` secara terbalik menggunakan reverse iterator.

## 3 | Iterator `cbegin()` dan `cend()`

- `cbegin()` mengembalikan const_iterator yang menunjuk ke karakter pertama dalam string.
	
- `cend()` mengembalikan const_iterator yang menunjuk ke posisi setelah karakter terakhir dalam string.
	

Const_iterator digunakan ketika kita ingin membaca elemen-elemen dalam string tanpa mengubahnya.

Contoh penggunaan:

```cpp
#include <iostream>
#include <string>

int main() {
	const std::string str = "Hello, World!";
	for (std::string::const_iterator it = str.cbegin(); it != str.cend(); ++it) {
		std::cout << *it << ' ';
	}
	return 0;
}
```

Output:

```
H e l l o ,   W o r l d !
```

Karena `str` dideklarasikan sebagai `const`, kita menggunakan `const_iterator` untuk menelusuri string tanpa mengubah isinya.
    
## 4 | Iterator `crbegin()` dan `crend()`

- `crbegin()` mengembalikan const_reverse_iterator yang menunjuk ke karakter terakhir dalam string.
	
- `crend()` mengembalikan const_reverse_iterator yang menunjuk ke posisi sebelum karakter pertama dalam string.
	

Const_reverse_iterator digunakan untuk membaca elemen-elemen dalam string secara terbalik tanpa mengubahnya.

Contoh penggunaan:

```cpp
#include <iostream>
#include <string>

int main() {
	const std::string str = "Hello, World!";
	for (std::string::const_reverse_iterator rit = str.crbegin(); rit != str.crend(); ++rit) {
		std::cout << *rit << ' ';
	}
	return 0;
}
```

Output:

```
! d l r o W   , o l l e H
```

Di sini, kita menggunakan `const_reverse_iterator` untuk mencetak karakter dalam string `str` secara terbalik tanpa mengubah isinya.

---

### 🔹 Kapan Menggunakan Iterator?

Iterator sangat berguna ketika kita perlu menelusuri string, terutama dalam konteks algoritma STL yang membutuhkan iterator sebagai parameter. Misalnya, kita bisa menggunakan iterator untuk mencari elemen tertentu, menghapus elemen, atau melakukan operasi lainnya yang melibatkan traversal string.

---

### 🔹 Catatan Penting

- Iterator pada `std::string` adalah **random access iterator**, yang berarti kita bisa melakukan operasi seperti penambahan atau pengurangan iterator untuk melompat ke posisi tertentu dalam string.
    
- Jika string dimodifikasi (misalnya dengan menambahkan atau menghapus karakter), iterator yang sebelumnya dibuat mungkin menjadi tidak valid. Oleh karena itu, setelah modifikasi, sebaiknya hindari menggunakan iterator lama dan buat iterator baru jika diperlukan.
    
---
<br/><br/>
# Capacity
Bagian yang membahas **capacity** dalam konteks `std::string` di C++ adalah bagian yang menjelaskan **bagaimana string menyimpan dan mengelola memori internalnya** untuk menampung karakter-karakter di dalamnya.

### 📦 Apa Itu "Capacity" pada `std::string`?

**Capacity** adalah **jumlah karakter maksimum** yang dapat ditampung oleh string **tanpa harus mengalokasikan ulang memori**.

> Ini berbeda dengan **size** atau **length**, yang hanya menunjukkan jumlah karakter yang _saat ini_ ada di string.

---

### 📚 Tujuan dan Fungsi Bagian "Capacity"

Bagian ini sangat berguna untuk:

- **Mengoptimalkan performa**: dengan memesan kapasitas lebih dulu, kita bisa menghindari alokasi ulang berulang saat string bertambah panjang.
    
- **Manajemen memori**: mengecilkan kapasitas yang terlalu besar agar hemat ruang.
    
- **Validasi dan pengecekan**: memeriksa apakah string kosong atau penuh.
    

---

### Fungsi-Fungsi yang Masuk dalam Kategori Capacity

1. **`size()` / `length()`** → Ukuran saat ini (jumlah karakter aktual).
    
2. **`max_size()`** → Ukuran maksimum yang _bisa_ ditampung (batas teoritis).
    
3. **`capacity()`** → Ukuran kapasitas saat ini (jumlah karakter yang bisa ditampung tanpa realokasi).
    
4. **`resize(n)`** → Ubah ukuran string menjadi `n`.
    
5. **`reserve(n)`** → Minta kapasitas minimal `n`, untuk persiapan sebelum menambahkan banyak karakter.
    
6. **`clear()`** → Kosongkan string, tapi tidak selalu mengecilkan kapasitas.
    
7. **`empty()`** → Cek apakah string kosong (`size() == 0`).
    
8. **`shrink_to_fit()`** → Minta agar kapasitas disesuaikan dengan ukuran aktual string.
    

---

### Analogi Sederhana

Bayangkan `std::string` seperti **wadah air**:

- `size()` = seberapa banyak air yang sedang ada di dalamnya.
    
- `capacity()` = seberapa besar wadahnya.
    
- `reserve(n)` = ganti ke wadah lebih besar agar tidak tumpah saat menambah air.
    
- `shrink_to_fit()` = ganti ke wadah lebih kecil jika airnya sedikit saja.
    
- `clear()` = buang semua air, tapi wadahnya tetap besar.
    
- `empty()` = cek apakah wadahnya kosong.
    

---

Bagian capacity sangat penting untuk program yang sering memanipulasi string panjang (misalnya pada competitive programming atau pengolahan teks), agar program berjalan **lebih cepat dan efisien**.

Berikut adalah pembahasan lengkap tentang macam-macam fungsi yang berkaitan dengan capacity string:


Fungsi-fungsi berikut digunakan untuk mengelola **kapasitas dan ukuran memori** dari objek `std::string`. Ini berguna untuk pengoptimalan kinerja dan manajemen isi string.
## 1 | Fungsi `size()` dan `length()`

Kedua fungsi ini **identik**, dan mengembalikan jumlah karakter (panjang) dari string. Semisal kita memiliki string yang menampung kalimat `Hello World`, maka dengan fungsi ini, kita akan mendapatkan panjang dari string tersebut, atau jumlah dari semua karakter didalam `Hello World`, yaitu adalah 11.

**Penjelasan**:

- `str.size()` atau `str.length()` akan mengembalikan panjang dari string dalam bentuk `size_t`.
    
- Biasanya digunakan untuk menghitung jumlah karakter dalam string.
    

**Contoh**:

```cpp
string str = "Halo!";
cout << str.size();   // Output: 5
cout << str.length(); // Output: 5 (sama)
```

---

## 2 | Fungsi `max_size()`

Fungsi ini mengembalikan jumlah maksimal karakter yang bisa ditampung oleh string (tergantung implementasi compiler dan sistem).

**Contoh**:

```cpp
string str = "C++";
cout << str.max_size(); // Nilai sangat besar, tergantung platform
```

**Catatan**: Ini adalah batas teoritis, bukan jumlah yang biasanya bisa kamu capai dalam praktik.

Contoh lagi, aku memiliki kode berikut, yang memanggil fungsi `max_size()`, maka berikut outputnya:

```cpp
#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "Hello World";
    cout << str.max_size() << "\n";
    return 0;
}
```

Output:

```
9223372036854775806
```

Compiler yang digunakan adalah C++23 msyslib.

---

## 3 | Fungsi `resize(n)`

Fungsi `resize()` digunakan untuk mengubah ukuran string menjadi `n`.

- Jika ukuran diperbesar, karakter tambahan akan berupa `'\0'` (null).
    
- Jika diperkecil, karakter di akhir akan dipotong.
    

**Contoh**:

```cpp
string str = "Halo";
str.resize(2);   // str jadi "Ha"
str.resize(6);   // str jadi "Ha\0\0\0\0"
```

Untuk conoth yang lebih lengkapya, perhatikan kode berikut:

```cpp
#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "Hello World";
    str.resize(2);
    cout << str << "\n";
    str.resize(10);
    cout << str << "\n";

    for (char c : str) {
        if (c == '\0') cout << "\\0";
        else cout << c;
    }
    cout << "\n";
    return 0;
}
```

Output dari kode diatas adalah:
```
He
He
He\0\0\0\0\0\0\0\0
```

Ketika kita resize ukuran string menjadi `n`, maka string akan dipotong hingga hanya menyisakan `n` karakter. Sama seperti diatas, kita meresize variabel string `str` menjadi 2. Sekarang, ketika kita outputkan, maka hasilnya hanya menampilkan dua karakter yang tersisa, atau karakter yang tidak teresize, yaitu: `He`.

Lalu ketika kita resize kembali ke ukuran 10, kenapa hasilnya masih sama? Kemana `\0` yang katanya bakal muncul?

- Setelah `resize(2)`, string menjadi `"He"`
- Setelah `resize(10)`, string menjadi `"He\0\0\0\0\0\0\0\0"`

Namun:

- **`std::string` menyimpan karakter null (`\0`) secara internal, tapi `cout << str` berhenti mencetak saat bertemu `\0`** jika `str` tidak memiliki karakter tampak setelahnya.


Itulah kenapa kamu **tidak melihat `\0` di output**—karena `\0` adalah **null character**, dan itu **bukan karakter cetak**, alias tidak punya representasi visual yang bisa ditampilkan di terminal.

---
### 🔧 Bagaimana Cara Melihat Karakter `\0`?

Untuk melihat karakter null (`\0`), kamu harus mencetak karakter per karakter, misalnya:

```cpp
for (char c : str) {
    if (c == '\0') cout << "\\0";
    else cout << c;
}
cout << "\n";
```

Contoh Output (jika `str` = `"He\0\0\0\0\0\0\0\0"`):

```
He\0\0\0\0\0\0\0\0
```

---

### 📌 Kesimpulan

- `resize()` menambahkan karakter null (`\0`) saat memperbesar string, tapi `cout << str` tidak menampilkannya.
    
- Untuk melihat karakter `\0`, kamu harus mencetak isi string secara manual per karakter dan beri perlakuan khusus pada `\0`.
    

---

## 4 | Fungsi `capacity()`

Mengembalikan kapasitas internal string saat ini (jumlah karakter yang bisa ditampung sebelum alokasi ulang).

**Contoh**:

```cpp
string str = "Hello";
cout << str.capacity(); // Bisa lebih besar dari 5
```


Fungsi `capacity()` digunakan untuk mengetahui berapa banyak karakter yang bisa ditampung string _tanpa perlu alokasi ulang memori_.

Dengan kata lain:

> 🧠 `capacity()` menunjukkan jumlah karakter maksimum yang dapat disimpan saat ini, sebelum `std::string` harus mengalokasikan ulang blok memori yang lebih besar.

### 🧪 Contoh Kasus: `"Hello World"`

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello World";
    cout << "Size: " << str.size() << "\n";
    cout << "Capacity: " << str.capacity() << "\n";
    return 0;
}
```

**Output kemungkinan besar:**

```
Size: 11
Capacity: 15
```

Kenapa **Capacity = 15**, bukan 11?


### ⚙️ Penjelasan Teknis

`std::string` biasanya **mengalokasikan memori berlebih** untuk menghindari alokasi ulang yang sering saat kamu menambahkan karakter baru.

Misalnya:

- Kamu buat `"Hello World"` → panjang 11
    
- Tetapi `std::string` akan secara internal mengalokasikan, katakanlah, 15 karakter langsung, agar performa lebih baik saat `push_back`, `append`, dll.
    

📦 Jadi kapasitas = 15 itu artinya **memori internal string siap menampung hingga 15 karakter** tanpa perlu memperluas buffer lagi.


### 📌 Ringkasan

|Properti|Penjelasan|
|---|---|
|`size()`|Jumlah karakter nyata dalam string (11)|
|`capacity()`|Jumlah karakter yang bisa ditampung saat ini tanpa realokasi (15 bisa saja tergantung implementasi)|
|`max_size()`|Batas maksimal total karakter yang bisa ditampung (biasanya sangat besar)|

---

## 5 | Fungsi `reserve(n)`

Meminta agar string memiliki kapasitas **minimal `n` karakter**.

- Tidak mengubah isi string.
    
- Hanya menyetel alokasi memori agar lebih optimal saat string akan bertambah panjang.
    

**Contoh**:

```cpp
string str;
str.reserve(100);       // Memesan kapasitas untuk 100 karakter
cout << str.capacity(); // >= 100
```

### 🧠 Apa Itu `reserve()`?

Fungsi **`reserve(n)`** digunakan untuk **meminta agar kapasitas internal dari string disiapkan minimal sebesar `n` karakter.**

> Artinya, kamu bilang ke `std::string`: "Tolong alokasikan memori untuk minimal `n` karakter, ya!"  
> Tujuannya? **Menghindari alokasi ulang berkali-kali saat string bertambah panjang.**


### 🔧 Format Penggunaan

```cpp
str.reserve(n);
```

- `n` = jumlah karakter yang kamu **prediksi atau rencanakan** akan disimpan.
    
- Jika `n` lebih kecil dari `current capacity`, maka **tidak terjadi apa-apa** (kapasitas tetap).
    
- Jika `n` lebih besar, maka kapasitas akan ditingkatkan.
    

### 📌 Contoh

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "halo";
    cout << "Awal: capacity = " << str.capacity() << "\n";

    str.reserve(100);
    cout << "Setelah reserve(100): capacity = " << str.capacity() << "\n";

    str.reserve(10);  // Tidak akan menurunkan kapasitas!
    cout << "Setelah reserve(10): capacity = " << str.capacity() << "\n";

    return 0;
}
```

### Output yang mungkin:

```
Awal: capacity = 15
Setelah reserve(100): capacity = 100
Setelah reserve(10): capacity = 100
```

Kenapa saat `reserve(10)` kapasitas tidak turun?  
👉 Karena **`reserve()` hanya bisa menaikkan kapasitas, tidak bisa menurunkan**.

Kalau kamu ingin menurunkan kapasitas agar sesuai ukuran string saat ini, maka kamu pakai:

```cpp
str.shrink_to_fit();
```

### 🧰 Kegunaan `reserve()`

- **Optimasi performa**: Jika kamu tahu string akan bertambah panjang secara besar (misalnya saat membaca file, atau append dalam loop), kamu bisa hindari banyak realokasi.
    
- **Stabilitas alokasi memori**: Membantu program besar tetap stabil dan cepat saat bekerja dengan banyak string panjang.
    


---

## 6 | Fungsi `clear()`

Fungsi **`clear()`** digunakan untuk **menghapus semua isi string** sehingga menjadi string kosong (`""`).

> Dengan kata lain, `clear()` akan membuat `size()` menjadi 0, tapi **capacity-nya tetap** (tidak di-reset).

### 🔧 Format Penggunaan

```cpp
str.clear();
```

- Tidak memiliki parameter.
    
- Tidak mengembalikan nilai (`void`).
    
- Setelah dipanggil, `str.empty()` akan bernilai `true`.
    

### 📌 Contoh

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Competitive Programming";
    cout << "Isi: " << str << "\n";
    cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << "\n";

    str.clear();

    cout << "Setelah clear()\n";
    cout << "Isi: \"" << str << "\"\n";
    cout << "Size: " << str.size() << ", Capacity: " << str.capacity() << "\n";
    cout << "Apakah kosong? " << boolalpha << str.empty() << "\n";

    return 0;
}
```

#### Output yang mungkin:

```
Isi: Competitive Programming
Size: 24, Capacity: 24
Setelah clear()
Isi: ""
Size: 0, Capacity: 24
Apakah kosong? true
```

### ⚠️ Catatan Penting

- `clear()` hanya menghapus konten, **tidak mengosongkan kapasitas**.  
    Jadi kalau kamu ingin membebaskan memori juga, gunakan:
    
    ```cpp
    str.clear();
    str.shrink_to_fit();  // Untuk mengecilkan capacity
    ```
    

### ✅ Kegunaan `clear()`

- Menghapus isi string sebelum digunakan kembali.
    
- Reset nilai dalam loop atau proses.
    
- Membersihkan string untuk menghemat memori (jika digabung dengan `shrink_to_fit()`).
    


---

## 7 | Fungsi `empty()`

Mengembalikan `true` jika string kosong (`size() == 0`), dan `false` jika ada isinya.

**Contoh**:

```cpp
string str = "";
if(str.empty()) cout << "Kosong!";
```

---

## 8 | Fungsi `shrink_to_fit()`

Meminta agar kapasitas string dikurangi seminimal mungkin agar sesuai dengan ukuran string saat ini.

- Tidak menjamin kapasitas benar-benar dikurangi (optional behavior).
    
- Cocok digunakan setelah banyak operasi yang memperbesar string, lalu kamu ingin mengecilkannya.
    

**Contoh**:

```cpp
string str = "banyak isi";
str.resize(3);         // Ukuran jadi lebih kecil
str.shrink_to_fit();   // Minta agar kapasitas disesuaikan
```

