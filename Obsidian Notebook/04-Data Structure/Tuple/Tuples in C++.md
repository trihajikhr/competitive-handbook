---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSTP-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber:
  - geeksforgeeks.org
  - chatgpt.com
date_learned: 2025-08-02T20:38:00
tags:
  - data-structure
  - tuple
---
Link sumber: [Tuples in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/tuples-in-c/)

---
# Tuples in C++

**Tuple** adalah objek yang dapat menyimpan sejumlah elemen. Elemen-elemennya bisa memiliki tipe data yang berbeda. Elemen dalam tuple diinisialisasi sebagai argumen sesuai urutan yang akan diakses. Tuple adalah struktur data serbaguna untuk mengelompokkan nilai. Untuk memahami cara menggunakan tuple dalam C++ dan aplikasinya, [_C++ Course_](https://www.geeksforgeeks.org/courses/cpp-programming-basic-to-advanced?utm_campaign=221_tuples_in_cpp&utm_medium=gfgcontent_icp&utm_source=geeksforgeeks) menyediakan tutorial dan contoh yang lengkap.

## Operasi pada Tuple

### 1 | **`get()`**
Digunakan untuk mengakses dan memodifikasi nilai dalam tuple. Fungsi ini menerima indeks dan nama tuple sebagai argumen untuk mengakses elemen tertentu.

---
### 2 | **`make_tuple()`** 
Digunakan untuk menetapkan nilai pada tuple. Nilai-nilai yang diberikan harus sesuai dengan urutan deklarasi dalam tuple.
    

```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main() {
	// Deklarasi tuple
	tuple<char, int, float> geek;

	// Menetapkan nilai ke tuple menggunakan make_tuple()
	geek = make_tuple('a', 10, 15.5);

	// Mencetak nilai awal dari tuple menggunakan get()
	cout << "Nilai awal dari tuple adalah: ";
	cout << get<0>(geek) << " " << get<1>(geek);
	cout << " " << get<2>(geek) << endl;

	// Menggunakan get() untuk mengubah nilai tuple
	get<0>(geek) = 'b';
	get<2>(geek) = 20.5;

	// Mencetak nilai tuple setelah dimodifikasi
	cout << "Nilai tuple setelah dimodifikasi adalah: ";
	cout << get<0>(geek) << " " << get<1>(geek);
	cout << " " << get<2>(geek) << endl;

	return 0;
}
```

**Keluaran:**

```
Nilai awal dari tuple adalah: a 10 15.5  
Nilai tuple setelah dimodifikasi adalah: b 10 20.5
```

**Penjelasan:**  
Dalam kode di atas, fungsi `get()` digunakan untuk mengubah nilai pertama dan ketiga dari tuple.

---
### 3 | **`tuple_size`**

Mengembalikan jumlah elemen dalam tuple.


```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main() {
	// Inisialisasi tuple
	tuple<char, int, float> geek(20, 'g', 17.5);

	// Menggunakan tuple_size untuk mencari jumlah elemen
	cout << "Jumlah elemen dalam tuple adalah: ";
	cout << tuple_size<decltype(geek)>::value;

	return 0;
}
```

**Keluaran:**

```
Jumlah elemen dalam tuple adalah: 3
```

---
### 4 | **`swap()`**

Menukar elemen antara dua tuple yang berbeda.


```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main() {
	// Inisialisasi tuple pertama
	tuple<int, char, float> tup1(20, 'g', 17.5);

	// Inisialisasi tuple kedua
	tuple<int, char, float> tup2(10, 'f', 15.5);

	// Cetak sebelum swap
	cout << "Tuple pertama sebelum ditukar: ";
	cout << get<0>(tup1) << " " << get<1>(tup1) << " " << get<2>(tup1) << endl;
	cout << "Tuple kedua sebelum ditukar: ";
	cout << get<0>(tup2) << " " << get<1>(tup2) << " " << get<2>(tup2) << endl;

	// Tukar isinya
	tup1.swap(tup2);

	// Cetak setelah swap
	cout << "Tuple pertama setelah ditukar: ";
	cout << get<0>(tup1) << " " << get<1>(tup1) << " " << get<2>(tup1) << endl;
	cout << "Tuple kedua setelah ditukar: ";
	cout << get<0>(tup2) << " " << get<1>(tup2) << " " << get<2>(tup2) << endl;

	return 0;
}
```

**Keluaran:**

```
Tuple pertama sebelum ditukar: 20 g 17.5  
Tuple kedua sebelum ditukar: 10 f 15.5  
Tuple pertama setelah ditukar: 10 f 15.5  
Tuple kedua setelah ditukar: 20 g 17.5
```

---
### 5 | **`tie()`** 

Digunakan untuk membongkar (unpack) nilai-nilai tuple ke dalam variabel-variabel terpisah. Versi dengan `ignore` digunakan untuk melewati elemen tertentu agar tidak dibongkar.


```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main() {
    // Variabel untuk hasil unpack
    int i_val;
    char ch_val;
    float f_val;

    // Inisialisasi tuple
    tuple<int, char, float> tup1(20, 'g', 17.5);

    // Menggunakan tie() tanpa ignore
    tie(i_val, ch_val, f_val) = tup1;
    cout << "Nilai tuple setelah unpack (tanpa ignore): ";
    cout << i_val << " " << ch_val << " " << f_val << endl;

    // Menggunakan tie() dengan ignore (abaikan char)
    tie(i_val, ignore, f_val) = tup1;
    cout << "Nilai tuple setelah unpack (dengan ignore): ";
    cout << i_val << " " << f_val << endl;

    return 0;
}
```

**Keluaran:**

```
Nilai tuple setelah unpack (tanpa ignore): 20 g 17.5  
Nilai tuple setelah unpack (dengan ignore): 20 17.5
```

---

### 6 | **`tuple_cat()`** 

Fungsi ini digunakan untuk menggabungkan dua tuple dan mengembalikan tuple baru.

```cpp
#include <iostream>
#include <tuple> // untuk tuple_cat() dan tuple
using namespace std;

int main() {
    // Inisialisasi tuple pertama
    tuple<int, char, float> tup1(20, 'g', 17.5);

    // Inisialisasi tuple kedua
    tuple<int, char, float> tup2(30, 'f', 10.5);
    
    // Menggabungkan dua tuple menjadi tuple baru
    auto tup3 = tuple_cat(tup1, tup2);
    
    // Menampilkan elemen-elemen dari tuple baru
    cout << "Elemen-elemen tuple baru secara berurutan adalah: ";
    cout << get<0>(tup3) << " " << get<1>(tup3) << " " 
         << get<2>(tup3) << " " << get<3>(tup3) << " " 
         << get<4>(tup3) << " " << get<5>(tup3) << endl;

    return 0;
}
```

**Keluaran:**

```
Elemen-elemen tuple baru secara berurutan adalah: 20 g 17.5 30 f 10.5
```


---

## Materi Pelengkap!

Berikut tiga fitur lanjutan tuple C++ yang melengkapi pemahamanmu:

### 1. Structured Bindings (C++17)

Cara modern untuk _unpack_ tuple tanpa `tie()`:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main() {
    tuple<int, char, float> tup(42, 'x', 3.14);

    // Structured bindings
    auto [i, c, f] = tup;

    cout << "Nilai: " << i << " " << c << " " << f << endl;
    return 0;
}
```

**Keluaran:**

```
Nilai: 42 x 3.14
```

---

### 2. std::apply (C++17)

Menjalankan fungsi dengan elemen tuple sebagai argumen:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

int sum(int a, int b, int c) {
    return a + b + c;
}

int main() {
    tuple<int, int, int> tup(1, 2, 3);

    int result = apply(sum, tup);

    cout << "Hasil apply: " << result << endl;
    return 0;
}
```

**Keluaran:**

```
Hasil apply: 6
```

---

### 3. std::tuple_element

Untuk mengetahui tipe data dari elemen tertentu:

```cpp
#include <iostream>
#include <tuple>
using namespace std;

int main() {
    tuple<int, char, float> tup;

    // Mendapatkan tipe elemen ke-1 (indeks 0)
    tuple_element<0, decltype(tup)>::type a = 10;

    cout << "Tipe elemen pertama adalah int, nilainya: " << a << endl;
    return 0;
}
```

Maka outputnya adalah:

```bash
Tipe elemen pertama adalah int, nilainya: 10
```

<br/>

> [!NOTE] FAQ
> kok int nya kita nulis manual? katanya buat mengetahui tipe data?

Pertanyaan bagus!

`std::tuple_element` **bukan** untuk menampilkan tipe secara langsung di terminal (C++ tidak punya refleksi tipe bawaan), tapi digunakan **oleh compiler** untuk _menentukan tipe_ saat compile time.

Contoh yang lebih terasa manfaatnya:

```cpp
#include <tuple>
using namespace std;

tuple<int, double, char> t;

tuple_element<1, decltype(t)>::type b = 3.14;  // b bertipe double
```

Kita **tidak tulis `double` secara manual**, tapi biarkan `tuple_element` yang menyediakannya. Jadi fungsinya:

- Mengambil **tipe elemen ke-N** dari tuple
    
- **Digunakan saat template atau generic programming**, bukan untuk mencetak tipe di runtime
    

Kalau kamu ingin melihat nama tipe secara eksplisit saat runtime, itu butuh fitur tambahan seperti `typeid(b).name()` atau bantuan dari library seperti Boost atau fmt.