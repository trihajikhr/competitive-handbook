---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T22:18:00
total_study: 3
tags:
  - Cpp
id: DID2
---
# Tutorial Belajar C++ Part 12: Tipe Data Char Bahasa C++

22 Oct 20 

Tutorial bahasa pemrograman C++ di Duniailkom kali ini akan membahas tentang tipe data **char**, mulai dari pengertian, jenis dan contoh kode program tipe data char di C++.

---

### Pengertian Tipe Data char Bahasa C++

Tipe data char dalam bahasa C++ digunakan untuk menampung 1 digit karakter, entah itu berupa huruf maupun angka. Variabel yang didefinisikan untuk menampung tipe data char butuh 1 byte memory. Secara teknis, char ini dikodekan dari charset **ASCII**.

---

### Contoh Kode Program Tipe Data char Bahasa C++

Contoh penggunaan tipe data **char** sudah pernah kita coba beberapa kali dari tutorial-tutorial sebelumnya. Berikut contoh lain dari tipe data char dalam bahasa C++:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  char huruf;
  huruf = 'D';
  cout << "Huruf yang tersimpan adalah: " << huruf << endl;
 
  return 0;
}
```

[![Contoh Kode Program Tipe Data Char bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Char-bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Char-bahasa-C.png)

Dalam kode ini saya mendefinisikan variabel **huruf** dengan tipe **char**. Variabel huruf kemudian diisi dengan karakter 'D' dan ditampilkan dengan perintah **cout**.

Untuk contoh kedua, saya akan buat konstanta dengan tipe data **char**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  const char huruf = 'a';
  cout << "Huruf yang tersimpan adalah: " << huruf << endl;
 
  return 0;
}
```

Hasil kode program:

```Cpp
Huruf yang tersimpan adalah: a
```

Kali ini **huruf** berupa sebuah konstanta bertipe **char**, bukan lagi variabel seperti sebelumnya. Mengenai perbedaan antara variabel dengan konstanta, sudah pernah kita bahas dalam beberapa tutorial sebelum ini: [Pengertian Variabel Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-variabel-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 7: Pengertian Variabel dalam Bahasa C++"), dan [Pengertian Konstanta Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-konstanta-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 8: Pengertian Konstanta dalam Bahasa C++").

Sebagai contoh terakhir, saya akan kombinasikan dengan perintah **cin** agar kode program kita menjadi lebih dinamis:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  char karakter1, karakter2, karakter3;
 
  cout << "Input 3 karakter sembarang" << endl;
  cout << "==========================" << endl;
  cout << endl;
 
 
  cout << "Karakter pertama: ";
  cin  >> karakter1;
 
  cout << "Karakter kedua: ";
  cin  >> karakter2;
 
  cout << "Karakter ketiga: ";
  cin  >> karakter3;
 
  cout << endl;
 
  cout << "Karakter yang diinput adalah: ";
  cout << karakter1 << ", " << karakter2 << ", dan "<< karakter3;
  cout << endl;
 
  return 0;
}
```

[![Contoh Kode Program Tipe Data Char bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Char-bahasa-C-2.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Tipe-Data-Char-bahasa-C-2.png)

Di awal kode program saya menyiapkan 3 buah variabel bertipe data **char**. Ketiga variabel ini bernama **karakter1**, **karakter2** dan **karakter3**. Isi program akan meminta inputan dari user untuk ketiga karakter tersebut, kemudian menampilkannya kembali.

Yang juga patut diingat, karakter disini bisa terdiri dari huruf, angka, serta karakter khusus seperti ?, *, %, #. Jadi tidak masalah jika kita menginput angka ke dalam tipe data char. Selama angka tersebut harus 1 digit.

Bagaimana dengan karakter yang lebih dari 1 digit seperti kata atau kalimat? Di dalam bahasa C++ itu menjadi tipe data tersendiri, yakni **string**. Lebih lanjut tentang tipe data string akan di bahas pada tutorial terpisah.

---

Sampai disini kita sudah membahas tentang pengertian tipe data char serta contoh penggunaannya Materi tentang tipe data akan dilanjutkan dengan [Tipe Data Integer pada Bahasa Pemrograman C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-tipe-data-integer-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 13: Tipe Data Integer Bahasa C++").