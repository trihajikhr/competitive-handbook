---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSVC-0001
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-04-21T14:31:00
tags:
  - data-structure
  - vector
---
---
# C++ Vectors
Dalam C++, **vektor** digunakan untuk menyimpan elemen dengan tipe data yang serupa. Namun, tidak seperti **array**, ukuran vektor dapat bertambah secara dinamis. Artinya, kita dapat mengubah ukuran vektor selama eksekusi program sesuai kebutuhan kita. Vektor adalah bagian dari pustaka template standar C++ /  [C++ Standard Template Library](https://www.programiz.com/cpp-programming/standard-template-library). Untuk menggunakan vektor, kita perlu menyertakan file header vektor dalam program kita.

```cpp
#include <vector>
```

# Mendeklarasikan Vector di C++
Setelah kita menyertakan file header, berikut ini adalah cara kita mendeklarasikan sebuah vektor dalam C++:

```cpp
std::vector<T> vector_name;
```

Parameter tipe `<T>` menentukan jenis vektor. Ini dapat berupa tipe data primitif seperti int, char, float, dll. Sebagai contoh: 

```cpp
vector<int> num;
```

Di sini, **num** adalah nama vektor.

Perhatikan bahwa kita belum menentukan ukuran vektor selama deklarasi. Hal ini karena ukuran vektor dapat bertambah secara dinamis, sehingga tidak perlu didefinisikan.
# Menginisialisasikan Vector di C++
Ada beberapa cara untuk menginisialisasi vektor dalam C++.
## Cara pertama:

```cpp
// Initializer list
vector<int> vector1 = {1, 2, 3, 4, 5};
```

```cpp
// Uniform initialization
vector<int> vector2 {1, 2, 3, 4, 5};
```

Di sini, kita menginisialisasi vektor dengan memberikan nilai secara langsung ke vektor. Sekarang, baik **vektor1** maupun **vektor2** diinisialisasi dengan nilai 1, 2, 3, 4, 5.
## Cara kedua:

```cpp
vector<int> vector3(5, 12);
```

Di sini, 5 adalah ukuran vektor dan 12 adalah nilainya.

Kode ini membuat vektor int dengan ukuran 5 dan menginisialisasi vektor tersebut dengan nilai 12. Jadi, vektor tersebut setara dengan:

```cpp
vector<int> vector3 = {12, 12, 12, 12, 12};
```

## Contoh: Menginisialisasikan Vector C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {

  // initializer list
  vector<int> vector1 = {1, 2, 3, 4, 5};

  // uniform initialization
  vector<int> vector2{6, 7, 8, 9, 10};

  // method 3
  vector<int> vector3(5, 12);

  cout << "vector1 = ";

  // ranged loop
  for (const int& i : vector1) {
    cout << i << "  ";
  }

  cout << "\nvector2 = ";

  // ranged loop
  for (const int& i : vector2) {
    cout << i << "  ";
  }

  cout << "\nvector3 = ";

  // ranged loop
  for (int i : vector3) {
    cout << i << "  ";
  }

  return 0;
}
```

Maka outputnya adalah: 

```
vector1 = 1  2  3  4  5  
vector2 = 6  7  8  9  10  
vector3 = 12  12  12  12  12
```

Di sini, kita telah mendeklarasikan dan menginisialisasi tiga vektor yang berbeda menggunakan tiga metode inisialisasi yang berbeda dan menampilkan isinya.
# Cara Menampilkan Isi Vector
Dari kode sebelumnya, kamu mungkin belajar bahwa untuk menampilkan isi vector, adalah dengan mengunakan perulangan berikut:

## Cara perulangan 

```cpp
for (const int& i : vector1) {
    cout << i << "  ";
}
```

Berikut adalah penjelasanya:

- **`for (const int& i : vector1)`**: Ini adalah **range-based for loop**, yang digunakan untuk mengiterasi setiap elemen dalam `vector1`.
    
    - `const int& i` berarti kita membuat sebuah referensi konstanta (`const int&`) untuk elemen-elemen dalam `vector1`. Ini membuat kita tidak mengubah nilai elemen dan menghindari salinan data.
    - `vector1` adalah `vector` yang akan diiterasi. Setiap elemen dalam `vector1` akan disalin ke dalam `i` satu per satu selama iterasi.
- **`cout << i << " ";`**: Baris ini mencetak nilai dari `i` (elemen yang sedang diproses) diikuti dengan dua spasi (`" "`).
### Penjelasan Tambahan:

- **`const`** di sini memastikan bahwa kamu tidak bisa mengubah nilai elemen dalam `vector1` selama iterasi.
- **`&` (referensi)** memungkinkan kamu untuk mengakses elemen tanpa menyalin data, yang lebih efisien terutama untuk tipe data besar atau objek.

Dengan kode ini, isi dari `vector1` akan ditampilkan dalam satu baris, dengan setiap elemen dipisahkan oleh dua spasi.

## Menampilkan vector dengan cara lain
**Apakah ada cara menampilkan isi vector, selain dengan cara ini? Dan apakah menampilkan vector dengan cara ini merupakan cara terbaik?**

Ya, ada beberapa cara lain untuk menampilkan isi dari sebuah `vector` di C++. Cara mana yang terbaik tergantung pada konteksnya, tetapi menggunakan **range-based for loop** seperti yang kamu gunakan adalah salah satu cara yang paling ringkas dan mudah dibaca. Namun, mari kita lihat beberapa alternatif lain, termasuk kelebihan dan kekurangannya.
### 1. Loop dengan Indeks Biasa (`for` Loop Standar)

```cpp
for (size_t i = 0; i < vector1.size(); i++) {
    cout << vector1[i] << "  ";
}
```

- **Kelebihan**: Ini memberi kontrol lebih besar atas indeks. Kamu bisa menambahkan logika tambahan seperti melompati elemen atau mengakses elemen lain dengan indeks tertentu.
- **Kekurangan**: Sedikit lebih verbose dibandingkan range-based for loop dan mungkin terlihat sedikit lebih kompleks.

### 2. Menggunakan Iterator

```cpp
for (auto it = vector1.begin(); it != vector1.end(); ++it) {
    cout << *it << "  ";
}
```

- **Kelebihan**: Menggunakan iterator lebih umum dalam C++ saat kamu bekerja dengan berbagai jenis kontainer STL (seperti `list`, `map`, dll.). Ini juga berguna jika kamu ingin melakukan operasi yang lebih kompleks, misalnya, menghapus elemen selama iterasi.
- **Kekurangan**: Kode ini mungkin terlihat lebih sulit dipahami, terutama jika kamu baru belajar C++.

### 3. Menggunakan `for_each` dengan Lambda (C++11 dan Lebih Baru)

```cpp
#include <algorithm>

for_each(vector1.begin(), vector1.end(), [](int i) {
    cout << i << "  ";
});
```

- **Kelebihan**: Berguna jika kamu ingin menyematkan logika tambahan ke dalam lambda atau menggunakan fungsi tertentu untuk setiap elemen dalam `vector`.
- **Kekurangan**: Kode ini mungkin terlihat lebih kompleks, dan `for_each` sering dianggap berlebihan untuk iterasi sederhana.

### 4. Menggunakan `copy` dan `ostream_iterator`

```cpp
#include <iterator>

copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, "  "));
```

- **Kelebihan**: Ini adalah cara yang sangat ringkas untuk menampilkan elemen-elemen `vector` tanpa harus membuat loop secara manual. Berguna dalam kasus sederhana.
- **Kekurangan**: Mungkin kurang intuitif untuk dipahami bagi pemula.

### Cara Terbaik?

- **Range-based for loop** (seperti pada kode yang kamu berikan) adalah salah satu cara terbaik dan direkomendasikan untuk menampilkan semua elemen dalam `vector`. Selain ringkas, cara ini juga mudah dipahami dan ideal jika kamu hanya perlu menampilkan atau mengakses nilai elemen tanpa mengubahnya.
- Namun, jika kamu memerlukan kontrol lebih besar atau logika kompleks, `for` loop standar atau iterator manual mungkin lebih sesuai.
# Operasi Vektor Dasar
Kelas vektor menyediakan berbagai metode untuk melakukan berbagai operasi pada vektor. Kita akan melihat beberapa operasi vektor yang umum digunakan dalam tutorial ini: 
- Menambahkan elemen 
- Mengakses elemen 
- Mengubah elemen 
- Menghapus elemen

## 1. Menambahkan Elemen ke Vektor
Untuk menambahkan satu elemen ke dalam sebuah vektor, kita menggunakan fungsi **push_back()**. Fungsi ini menyisipkan sebuah elemen ke dalam akhir vektor. Sebagai contoh:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Initial Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }
  
  // add the integers 6 and 7 to the vector
  num.push_back(6);
  num.push_back(7);

  cout << "\nUpdated Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }

  return 0;
}
```

Outputnya:

```
Initial Vector: 1  2  3  4  5  
Updated Vector: 1  2  3  4  5  6  7
```

Di sini, kita telah menginisialisasi vektor int num dengan elemen {1, 2, 3, 4, 5}. Perhatikan pernyataan-pernyataannya:

```cpp
num.push_back(6);
num.push_back(7);
```

Di sini, fungsi **push_back()** menambahkan elemen **6** dan **7** ke dalam vektor.

> **Catatan:** Kita juga dapat menggunakan fungsi **insert()** dan **emplace()** untuk menambahkan elemen pada vektor.

## 2. Mengakses Elemen-elemen Vektor
Dalam C++, kita menggunakan nomor indeks untuk mengakses elemen-elemen vektor. Di sini, kita menggunakan fungsi **at()** untuk mengakses elemen dari indeks yang ditentukan. Sebagai contoh:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Element at Index 0: " << num.at(0) << endl;
  cout << "Element at Index 2: " << num.at(2) << endl;
  cout << "Element at Index 4: " << num.at(4);

  return 0;
}
```

Maka outputnya:

```
Element at Index 0: 1
Element at Index 2: 3
Element at Index 4: 5
```

Ini penjelasanya:

- **Element at Index 0: 1**  - mengakses elemen 0 pada index 
- **Element at Index 2: 3**  - mengakses elemen 2 pada index 
- **Element at Index 4: 5**  - mengakses elemen 4 pada index 

**Catatan:** Seperti halnya array, kita juga dapat menggunakan tanda kurung siku \[] untuk mengakses elemen vektor. Sebagai contoh:

```cpp
vector<int> num {1, 2, 3};
cout << num[1];  // Output: 2
```

Namun, fungsi **at()** lebih disukai daripada \[] karena **at()** melemparkan pengecualian setiap kali vektor berada di luar batas, sementara \[] memberikan nilai sampah.

```Cpp
vector<int> num {1, 2, 3};

// gives garbage value
cout << num[4];

// throws an exception
cout << num.at(4);
```

## 3. Mengubah Elemen Vektor
Kita dapat mengubah sebuah elemen vektor dengan menggunakan fungsi **at()** yang sama. Sebagai contoh,

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Initial Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }

  // change elements at indexes 1 and 4
  num.at(1) = 9;
  num.at(4) = 7;

  cout << "\nUpdated Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }

  return 0;
}
```

Maka outputnya:

```
Initial Vector: 1  2  3  4  5  
Updated Vector: 1  9  3  4  7
```

Pada contoh di atas, perhatikan pernyataan-pernyataannya:

```cpp
num.at(1) = 9;
num.at(4) = 7;
```

Di sini, kami telah menetapkan nilai baru untuk indeks **1** dan **4**. Jadi, nilai pada **indeks 1** diubah menjadi **9** dan nilai pada **indeks 4** diubah menjadi **7**.
## 4. Menghapus Elemen dari Vektor C++
Untuk menghapus satu elemen dari sebuah vektor, kita menggunakan fungsi **pop_back()**. Sebagai contoh,

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> prime_numbers{2, 3, 5, 7};
  
  // initial vector
  cout << "Initial Vector: ";
  for (int i : prime_numbers) {
    cout << i << " ";
  }

  // remove the last element
  prime_numbers.pop_back();

  // final vector
  cout << "\nUpdated Vector: ";
  for (int i : prime_numbers) {
    cout << i << " ";
  }
  
  return 0;
}
```

Maka outputnya:

```
Initial Vector: 2 3 5 7 
Updated Vector: 2 3 5 
```

Pada contoh di atas, perhatikan pernyataannya,

```cpp
prime_numbers.pop_back();
```

Di sini, kita telah menghapus elemen terakhir (**7**) dari vektor.

### 4.1) Menghapus elemen vector berdasarkan value 
Kita juga bisa menghapus value vector yang kita tentukan. Sebagai contoh kasus berikut:

Terdapat vector arr, dengan isi berupa:

```cpp
vector<int>arr = [1,2,3,4,5];
```

Dan kita ingin menhapus value `4`, sehingga hasil akhirnya adalah `[1,2,3,5]`. Kita bisa menggunakan fungsi `erase()` dan fungsi `find()`, sebagai berikut:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int>arr={1,2,3,4,5};

	// value yang ingin dihapus:
	int x; cin >> x;
	arr.erase(find(arr.begin(), arr.end(), x));
	
	for(int&x:arr) cout << x << " "; 
	cout << "\n";
	return 0;
}
```

Katakanlah inputan kita adalah `5`, maka outputnya adalah sebagai berikut:

```bash
1 2 3 4
```

Disini kita berhasil untuk menghapus nilai `5` dari array.

> Apa jadinya jika nilai yang kita hapus tidak ada didalam array yang dituju?

Pertanyaan bagus, dan **iya**, _jika nilai yang dicari tidak ditemukan dalam array_, maka:

```cpp
find(arr.begin(), arr.end(), x)
```

akan **mengembalikan `arr.end()`**, yaitu iterator **satu langkah setelah elemen terakhir** dari array.

Nah, ketika kamu melakukan:

```cpp
arr.erase(find(arr.begin(), arr.end(), x));
```

dan nilai `x` **tidak ada** di array, maka kamu akan menulis:

```cpp
arr.erase(arr.end());
```

Ini **undefined behavior**. Secara teknis **tidak sah**, dan bisa:

- Tidak menghapus apa pun,
    
- Crash program,
    
- Atau seperti yang kamu alami, **menghapus elemen terakhir**—tapi ini **bukan jaminan perilaku resmi**, hanya kebetulan hasil dari _implementation-defined behavior_.
    

---

### ✔️ Solusi Aman

Tambahkan pengecekan sebelum `erase`:

```cpp
auto it = find(arr.begin(), arr.end(), x);
if (it != arr.end()) {
    arr.erase(it);
}
```

Dengan ini, kamu hanya menghapus jika `x` **benar-benar ditemukan** di array.

### 4.2) Menghapus elemen array berdasarkan index
Nah, kalau kamu mau menghapus elemen dari `vector` berdasarkan **index**, tinggal langsung pakai `erase` dengan iterator ke posisi tersebut:

```cpp
arr.erase(arr.begin() + index);
```

### ✅ Contoh:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    int index; cin >> index;

    if (index >= 0 && index < arr.size()) {
        arr.erase(arr.begin() + index);
    } else {
        cout << "Index di luar jangkauan!\n";
    }

    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```

### ⚠️ Penting:

Kamu **harus cek** apakah `index` valid, karena jika `index` negatif atau lebih besar dari `arr.size() - 1`, akan menyebabkan **crash atau undefined behavior**.

# C++ Vector Functions
Dalam C++, file header vektor menyediakan berbagai fungsi yang dapat digunakan untuk melakukan berbagai operasi pada vektor.

| Function     | Description                                       |
| ------------ | ------------------------------------------------- |
| `size()`     | mengembalikan jumlah elemen yang ada dalam vektor |
| `clear()`    | menghapus semua elemen vektor                     |
| `front()`    | mengembalikan elemen pertama dari vektor          |
| `back()`     | mengembalikan elemen terakhir dari vektor         |
| `empty()`    | mengembalikan **1** (true) jika vektor kosong     |
| `capacity()` | memeriksa ukuran keseluruhan dari sebuah vektor   |
| `erase()`    | menghapus elemen vector yang ditentukan           |
# Iterator Vektor C++
Iterator vektor digunakan untuk menunjuk ke alamat memori dari sebuah elemen vektor. Dalam beberapa hal, iterator vektor berfungsi seperti pointer dalam C++. Kita dapat membuat iterator vektor dengan sintaks

```cpp
vector<T>::iterator iteratorName;
```

Sebagai contoh, jika kita memiliki **2** vektor bertipe int dan double, maka kita akan membutuhkan **2** iterator yang berbeda sesuai dengan tipenya:

```cpp
// iterator for int vector
vector<int>::iterator iter1;

// iterator for double vector
vector<double>::iterator iter2;
```

## 1. Inisialisasi Iterator Vektor
Kita dapat menginisialisasi iterator vektor menggunakan fungsi **begin()** dan **end()**.
### 1. begin() function
Fungsi **begin()** mengembalikan sebuah iterator yang menunjuk ke elemen pertama dari vektor. Sebagai contoh,

```cpp
vector<int> num = {1, 2, 3};
vector<int>::iterator iter;

// iter points to num[0]
iter = num.begin();
```

### 2. end() function
Fungsi **end()** menunjuk pada **elemen teoritis** yang muncul **setelah** elemen akhir vektor. Sebagai contoh,

```cpp
// iter points to the last element of num
iter = num.end() - 1;
```

Di sini, karena sifat dari fungsi **end()**, kita telah menggunakan kode **num.end() - 1** untuk menunjuk ke elemen terakhir dari vektor num, yaitu num\[2].

## Contoh: Iterator Vector C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  // declare iterator
  vector<int>::iterator iter;

  // initialize the iterator with the first element
  iter = num.begin();

  // print the vector element
  cout << "num[0] = " << *iter << endl;

  // iterator points to the 3rd element
  iter = num.begin() + 2;
  cout << "num[2] = " << *iter;

  // iterator points to the last element
  iter = num.end() - 1;
  cout << "num[4] = " << *iter;

  return 0;
}
```

Maka outputnya:

```cpp
num[0] = 1
num[2] = 3
num[4] = 5
```

Pada program ini, kita telah mendeklarasikan sebuah iterator vektor **int** untuk **iter** untuk digunakan dengan vektor **num**.

```cpp
// declare iterator
vector<int>::iterator iter;
```

Kemudian, kita menginisialisasi iterator ke elemen pertama dari vektor menggunakan fungsi **begin()**.

```cpp
// initialize the iterator with the first element
iter = num.begin();
```

Kemudian, kami mencetak elemen vektor dengan melakukan **dereferensi** pada iterator:

```cpp
// print the vector element
cout << "num[0] = " << *iter << endl;
```

Kemudian, kita mencetak elemen ke-3 dari vektor dengan mengubah nilai **iter** menjadi **num.begin() + 2**. 

Terakhir, kita mencetak elemen terakhir dari vektor dengan menggunakan fungsi **end()**.

## Contoh: Lakukan Perulangan Melalui Vektor Menggunakan Iterator
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  // declare iterator
  vector<int>::iterator iter;

  // use iterator with for loop
  for (iter = num.begin(); iter != num.end(); ++iter) {
    cout << *iter << "  ";
  }

  return 0;
}
```

Maka outputnya:

```
1  2  3  4  5 
```

Di sini, kita telah menggunakan perulangan for untuk menginisialisasi dan mengulang perulangan iterator dari **iter** dari awal vektor ke akhir vektor menggunakan fungsi **begin()** dan **end()**.

```cpp
// use iterator with for loop
for (iter = num.begin(); iter != num.end(); ++iter) {
  cout << *iter << "  ";
}
```