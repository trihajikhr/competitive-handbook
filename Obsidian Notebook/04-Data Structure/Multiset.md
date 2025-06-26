---
obsidianUIMode: preview
note_type: algorithm theory
id_algoritma: 04TH-DSSE-M001
nama_algoritma: multiset data structure
kategori_algoritma: data structure
kesulitan: 
time_complexity: 
memory_complexity: 
sumber: programiz.com & chatgpt.com
date_learned: 2025-04-23T13:46:00
tags:
  - array
  - data-structure
  - multiset
---
#array #data-structure #multiset

---
# Multiset C++  

**Multiset C++** adalah wadah STL yang menyimpan elemen dengan tipe yang sama dalam urutan terurut, di mana beberapa elemen dapat memiliki nilai yang setara. Dengan kata lain, nilai duplikat diperbolehkan.  

Seperti **set** di C++, nilai setiap elemen bertindak sebagai kunci itu sendiri.  

## Properti Multiset  
Multiset C++ memiliki properti berikut:  

- **Asosiatif**: Elemen dirujuk berdasarkan kuncinya, bukan posisi absolutnya dalam wadah.  
- **Terurut**: Elemen disimpan dalam urutan terurut.  
- **Kunci setara**: Beberapa elemen dalam wadah dapat memiliki kunci yang setara.  
- **Imutabel**: Nilai elemen tidak dapat diubah setelah disimpan dalam multiset.  

## Membuat Multiset  
Untuk mengimplementasikan multiset di C++, kita harus menyertakan header file `<set>` dalam program:  

```cpp
#include <set>
```  

Kita dapat membuat multiset dengan sintaks berikut:  

```cpp
// deklarasi multiset  
std::multiset<data_type> nama_multiset = {kunci1, kunci2, kunci3, ...};
```  

Di mana:  
- `std::multiset` – mendeklarasikan wadah STL bertipe multiset.  
- `<data_type>` – tipe data nilai yang akan disimpan dalam multiset.  
- `nama_multiset` – nama unik yang diberikan ke multiset.  
- `kunci1, kunci2, kunci3, ...` – kunci/nilai yang akan disimpan dalam multiset.  

Contoh:  

```cpp
// inisialisasi multiset dengan elemen  
std::multiset<int> my_multiset1 = {5, 3, 8, 1, 3};  

// membuat multiset kosong  
std::multiset<int> my_multiset2;  
```  

**Catatan**: Selanjutnya, kita akan menggunakan namespace `std` sehingga bisa menghilangkan `std::` dari sintaks.  

### Contoh 1: Membuat Multiset  
```cpp
#include <iostream>  
#include <set>  
using namespace std;  

int main() {  
    multiset<int> my_multiset = {5, 3, 8, 1, 3};  

    for(int val : my_multiset) {  
        cout << val << " ";  
    }  

    return 0;  
}  
```  

**Output**:  
```  
1 3 3 5 8  
```  

Di sini, kita membuat multiset bertipe `int`. Seperti yang terlihat, multiset mengembalikan nilai dalam urutan terurut dan menyertakan duplikat angka `3`.  

## Mengurutkan Multiset secara Menurun  
Untuk mendapatkan elemen multiset dalam urutan menurun, kita dapat memodifikasi sintaks menjadi:  

```cpp
multiset<int, greater<int>> my_multiset;  
```  

Contoh:  
```cpp
#include <iostream>  
#include <set>  
using namespace std;  

int main() {  
    multiset<int, greater<int>> my_multiset = {5, 3, 8, 1, 3};  

    for(int val : my_multiset) {  
        cout << val << " ";  
    }  

    return 0;  
}  
```  

**Output**:  
```  
8 5 3 3 1  
```  

Terlihat bahwa multiset sekarang mengembalikan elemen dalam urutan menurun.  

## Metode Multiset C++  
Di C++, kita memiliki berbagai metode untuk melakukan operasi dalam multiset.  

| Operasi      | Deskripsi |  
|--------------|-----------|  
| `insert()`   | Menyisipkan elemen ke dalam multiset. |  
| `erase()`    | Menghapus semua kemunculan suatu elemen. |  
| `clear()`    | Menghapus semua elemen dari multiset. |  
| `empty()`    | Memeriksa apakah multiset kosong. |  
| `size()`     | Mengembalikan ukuran multiset. |  

### Contoh 2: Menambahkan Elemen ke Multiset  
```cpp
#include <iostream>  
#include <set>  
using namespace std;  

int main() {  
    multiset<int> my_multiset;  

    // menambahkan nilai ke multiset  
    my_multiset.insert(10);  
    my_multiset.insert(30);  
    my_multiset.insert(20);  
    my_multiset.insert(50);  
    my_multiset.insert(40);  
    my_multiset.insert(50);  

    // mencetak multiset setelah penyisipan  
    for (int i : my_multiset) {  
        cout << i << "  ";  
    }  

    return 0;  
}  
```  

**Output**:  
```  
10  20  30  40  50  50  
```  

Seperti yang terlihat, `insert()` di multiset bekerja sama seperti di set.  

### Contoh 3: Menghapus Elemen dari Multiset  
```cpp
#include <iostream>  
#include <set>  
using namespace std;  

int main() {  
    multiset<int> my_multiset = {10, 30, 20, 50, 40, 50};  

    // menghapus semua kemunculan 50 dari multiset  
    my_multiset.erase(50);  

    // mencetak multiset setelah penghapusan  
    cout << "\nMultiset setelah erase: ";  
    for (int i : my_multiset) {  
        cout << i << "  ";  
    }  

    // menghapus semua nilai dari multiset  
    my_multiset.clear();  

    // mencetak multiset setelah clear  
    cout << "\nMultiset setelah clear: ";  
    for (int i : my_multiset) {  
        cout << i << "  ";  
    }  

    return 0;  
}  
```  

**Output**:  
```  
Multiset setelah erase: 10  20  30  40  
Multiset setelah clear:  
```  

Seperti yang terlihat, `clear()` berfungsi sama seperti di set, yaitu menghapus semua nilai.  

Sementara itu, metode `erase()` menghapus semua kemunculan nilai yang diberikan dari multiset.  

```cpp
my_multiset.erase(50);  // menghapus semua nilai 50  
```  

Dalam kasus ini, kedua kemunculan `50` dihapus dari `my_multiset`.  

### Contoh 4: Metode `empty()` dan `size()` di Multiset  
Kita dapat menggunakan metode kapasitas `empty()` dan `size()` untuk memeriksa apakah multiset kosong dan mendapatkan ukurannya.  

Metode `empty()` mengembalikan:  
- `1` (`true`) – jika multiset kosong.  
- `0` (`false`) – jika multiset tidak kosong.  

Contoh:  
```cpp
#include <iostream>  
#include <set>  
using namespace std;  

int main() {  
    multiset<int> my_multiset = {10, 20, 20, 20, 30, 40};  

    // mencetak multiset sebelum clear  
    cout << "Multiset sebelum clear: ";  
    for (int i : my_multiset) {  
        cout << i << "  ";  
    }  

    // memeriksa apakah multiset kosong  
    cout << "\nKosong: " << my_multiset.empty() << endl;  

    // memeriksa ukuran multiset  
    cout << "Ukuran: " << my_multiset.size() << endl;  

    // menghapus semua nilai dari multiset  
    my_multiset.clear();  

    // mencetak multiset setelah clear  
    cout << "\nMultiset setelah clear: ";  
    for (int i : my_multiset) {  
        cout << i << "  ";  
    }  

    // menggunakan metode kapasitas lagi  
    cout << "\nKosong: " << my_multiset.empty() << endl;  
    cout << "Ukuran: " << my_multiset.size() << endl;  

    return 0;  
}  
```  

**Output**:  
```  
Multiset sebelum clear: 10  20  20  20  30  40  
Kosong: 0  
Ukuran: 6  

Multiset setelah clear:  
Kosong: 1  
Ukuran: 0  
```  

Di sini, kita menggunakan `empty()` dan `size()` sebelum dan setelah membersihkan isi multiset.  

**Sebelum clear**:  
- `empty()` mengembalikan `0`, artinya multiset tidak kosong.  
- `size()` mengembalikan `6`, artinya ada 6 elemen dalam multiset.  

**Setelah clear**:  
- `empty()` mengembalikan `1`, artinya multiset kosong.  
- `size()` mengembalikan `0`, artinya tidak ada elemen dalam multiset.