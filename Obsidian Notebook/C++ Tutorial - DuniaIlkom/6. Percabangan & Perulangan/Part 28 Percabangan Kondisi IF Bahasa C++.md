---
obsidianUIMode: preview
sumber: duniailkom
level: medium
bahasa: C++
tanggal_study: 2024-09-27T10:29:00
total_study: 1
tags:
  - Cpp
id: DIF1
---
# Tutorial Belajar C++ Part 28: Percabangan Kondisi IF Bahasa C++

30 Oct 20 

Setelah membahas tentang operator bahasa C++, dalam beberapa tutorial ke depan kita akan mempelajari struktur percabangan kode program dalam bahasa C++. Segmen materi ini dibuka dengan membahas bentuk percabangan yang paling sederhana, yakni kondisi IF.

---

### Pengertian Kondisi IF bahasa C++

Dalam pembuatan program, ada saatnya kita butuh suatu percabangan, yakni jika sebuah kondisi terpenuhi, jalankan kode program ini, jika tidak jalankan kode program yang lain. Menggunakan bahasa C++, konsep tersebut dibuat menggunakan **struktur IF** dengan aturan penulisan sebagai berikut:

```Cpp
if (condition)
{
  //Kode program yang akan dijalankan jika condition berisi nilai True
}
```

Bagian **condition** berperan sebagai penentu dari struktur percabangan. Jika _condition_ terpenuhi (menghasilkan nilai boolean **true**), blok kode program akan dijalankan. Jika _condition_ tidak terpenuhi (menghasilkan nilai boolean **false**), blok kode program tidak akan dijalankan.

Blok kode program yang di maksud adalah semua kode yang berada di antara tanda kurung kurawal "{" dan "}". _Condition_ biasanya terdiri dari operasi perbandingan, seperti apakah variabel **a** berisi angka 18, atau apakah variabel password berisi string 'qwerty'.

Mari kita bahas dengan contoh kode program.

---

### Contoh Kode Program Percabangan IF Bahasa C++

Sebagai praktek pertama, berikut contoh kode program untuk melihat apakah sebuah angka lebih besar dari angka lain, lalu tampilkan hasilnya jika kondisi terpenuhi:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 12;
  int b = 10;
 
  if (a > b) {
    cout << "Nilai variabel a lebih besar dari variabel b" << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
Nilai variabel a lebih besar dari variabel b
```

Di awal kode program saya mengisi variabel **a** dengan angka **12** serta variabel **b** dengan angka **10**. Kemudian di baris 7 terdapat kondisi **if (a > b)**, yakni apakah variabel a berisi angka yang lebih besar dari b? Apakah 12 lebih besar dari 10? betul (**true**), maka blok kode program akan dijalankan.

Kita juga bisa membuat struktur if beberapa kali tergantung kebutuhan seperti contoh berikut:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a = 5;
  int b = 10;
 
  if (a > b) {
    cout << "Nilai variabel a lebih besar dari variabel b" << endl;
  }
 
  if (a < b) {
    cout << "Nilai variabel a lebih kecil dari variabel b" << endl;
  }
 
  if (a == b) {
    cout << "Nilai variabel a sama dengan variabel b" << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
Nilai variabel a lebih kecil dari variabel b
```

Kode program ini merupakan hasil modifikasi dari kode sebelumnya. Kali ini terdapat 3 buah kondisi, yakni **if (a > b)**, **if (a < b)**, serta **if (a == b)**. Setiap kondisi if akan diperiksa dan jika operasi perbandingan menghasilkan nilai **true**, maka blok tersebut akan diproses. Silahkan coba ubah isi variabel a dan b untuk melihat blok kode program mana yang akan dijalankan.

Supaya lebih interaktif, saya akan modifikasi kode sebelumnya untuk meminta user menginput angka ke dalam variabel **a** dan **b**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a, b;
 
  cout << "Input nilai variabel a: ";
  cin >> a;
 
  cout << "Input nilai variabel b: ";
  cin >> b;
 
  if (a > b) {
    cout << "Nilai variabel a lebih besar dari variabel b" << endl;
  }
 
  if (a < b) {
    cout << "Nilai variabel a lebih kecil dari variabel b" << endl;
  }
 
  if (a == b) {
    cout << "Nilai variabel a sama dengan variabel b" << endl;
  }
 
  return 0;
}
```

[![Contoh Kode Program Percabangan IF Bahasa C++](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Percabangan-IF-Bahasa-C.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-Kode-Program-Percabangan-IF-Bahasa-C.png)

Selain tambahan perintah **cin >> a** dan **cin >> b** agar user bisa menginput angka, kode program kita masih sama seperti sebelumnya, yakni mencari variabel yang berisi angka lebih besar.

Contoh terakhir, mari buat kode program untuk menebak apakah sebuah angka merupakan bilangan genap atau bilangan ganjil:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  int a;
 
  cout << "Input sembarang angka bulat: ";
  cin >> a;
 
  if (a % 2 == 0) {
    cout << a << " adalah angka genap" << endl;
  }
  if (a % 2 == 1) {
    cout << a << " adalah angka ganjil" << endl;
  }
 
  return 0;
}
```

Hasil kode program:

```
Input sembarang angka: 20
20 adalah angka genap
  
Input sembarang angka: 999
999 adalah angka ganjil
 
Input sembarang angka: 0
0 adalah angka genap
```

Sekarang kondisi yang diperiksa adalah **if (a % 2 == 0)** dan **if (a % 2 == 1)**. Di dalam bahasa C++, tanda persen ( **%** ) adalah operator **modulus** yang dipakai untuk mencari sisa hasil bagi. Lebih lanjut tentang operator ini pernah kita bahas di [Operator Aritmatika Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-jenis-jenis-operator-aritmatika-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 22: Jenis-jenis Operator Aritmatika Bahasa C++").

Kondisi pertama, yakni **if (a % 2 == 0)** akan bernilai **true** jika variabel a habis dibagi 2. Ini artinya variabel a berisi angka genap.

Sedangkan kondisi kedua, yakni **if (a % 2 == 1)** akan bernilai **true** jika variabel a bersisa 1 pada saat dibagi 2. Ini artinya variabel a berisi angka ganjil.

---

Percabangan IF seperti ini sangat sering dipakai untuk memecahkan sebuah masalah. Berikutnya, akan di bahas tentang [percabangan IF ELSE dalam bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-percabangan-kondisi-if-else-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 29: Percabangan Kondisi IF ELSE Bahasa C++").