---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Switch Case Bertumpuk (Fall-through)
sumber:
  - myself
  - chatgpt.com
tags:
  - tips-trick
---
---
# Switch Case Bertumpuk (Fall-through)

Didalam bahasa program C++, kita tahu bahwa terdapat bebrapa jenis percabangan yang bisa digunakan, dan salah satunya adalah switch case.

Percabangan `switch-case` adalah struktur kontrol dalam pemrograman yang mengarahkan alur program untuk menjalankan blok kode tertentu berdasarkan nilai dari sebuah variabel. Struktur ini membandingkan nilai variabel dengan beberapa "kasus" (case) yang telah ditentukan; jika ditemukan kecocokan, kode di dalam kasus tersebut akan dieksekusi. `Switch-case` cocok untuk kondisi dengan banyak pilihan dan digunakan untuk tipe data seperti bilangan bulat atau karakter, berbeda dengan `if-else` yang lebih fleksibel untuk perbandingan kompleks.

Nah, contoh penggunaan dari switch case adalah sebagai berikut:

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;

    switch (n) {
        case 0: {
            cout << "OKE";
            break;
        }
        case 5: {
            cout << "OKE";
            break;
        }
        case 10: {
            cout << "OKE";
            break;
        }
        default: {
            cout << "Null";
            break;
        }
    }
    return 0;
}
```

Tujuan dari program ini adalah untuk mengeluarkan output berupa `OKE` ketika inputan $n$ bernilai $0,5,10$. Jika inputan adalah selain dari ketiga angka tersebut, maka output yang dicetak adalah `Null`. 

Nah, tetapi ada hal yang janggal disini. Dari kode diatas, terlihat bahwa kita membuat case untuk masing-masing angka $0,5,10$, dengan blok eksekusi yang sama, yaitu sama-sama mengeksekusi perintah output `OKE`. 

Cara ini sebenarnya kurang efisien, karena tampaknya bisa disederhakan, dan kenyataanya memang bisa. 

Cara menyederhanakan switch case ini, adalah dengan menggunakan *grouped case (fall-through)*. Implementasi dari cara ini adalah dengan langsung membuat beberapa case, dan cukup satu blok eksekusi. Contohnya adalah sebagai berikut:

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n;
    cin >> n;

    switch (n) {
        case 0:
        case 5:
        case 10: {
            cout << "OKE";
            break;
        }
        default: {
            cout << "Null";
        }
    }
    return 0;
}
```

Seperti yang terlihat diatas, beberapa nilai `case` bisa langsung menuju blok aksi yang sama. Lebih cepat, readeable, dan clean.

