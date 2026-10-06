---
obsidianUIMode: preview
sumber: duniailkom
level: pemula
bahasa: C++
tanggal_study: 2024-10-01T09:41:00
total_study: 4
tags:
  - Cpp
id: DIC4
---
# Tutorial Belajar C++ Part 8: Pengertian Konstanta dalam Bahasa C++

20 Oct 20 

Pada tutorial belajar C++ sebelumnya telah dibahas tentang [Pengertian Variabel dalam Bahasa C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-variabel-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 7: Pengertian Variabel dalam Bahasa C++"). Kali ini akan kita lengkapi dengan konsep yang mirip tapi tidak sama, yakni **Konstanta**.

---

### Pengertian Konstanta

**Konstanta** adalah sebuah tempat atau container dari suatu nilai. Sesuai dengan namanya, nilai dari konstanta bersifat tetap (konstan) dan tidak bisa diubah sepanjang program berjalan. Inilah yang menjadi pembeda antara konstanta dengan variabel.

---

### Cara Membuat Konstanta C++ dengan Perintah "#define"

Untuk membuat konstanta dalam bahasa C++ terdapat 2 cara: menggunakan keyword **\#define** atau menggunakan keyword **const**. Kita akan bahas dengan perintah **\#define** terlebih dahulu

Jika ingin membuat konstanta dengan keyword **\#define**, konstanta ini ditulis sebelum **main()**. Berikut contoh cara pembuatan konstanta menggunakan **\#define**:

```Cpp
#include <iostream>
 
using namespace std;
 
#define PANJANG 8
#define LEBAR 5
 
int main()
{
  cout << "Panjang = " << PANJANG;
  cout << "\n";
 
  cout << "Lebar = " << LEBAR;
  cout << "\n";
 
  cout << "Luas (panjang*lebar) = " << PANJANG*LEBAR;
  cout << "\n";
 
  return 0;
}
```

[![Contoh kode program C++ membuat konstanta](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-kode-program-C-membuat-konstanta.png)](https://www.duniailkom.com/wp-content/uploads/2020/10/Contoh-kode-program-C-membuat-konstanta.png)

Disini saya membuat 2 buah konstanta: **PANJANG** dan **LEBAR**. Masing-masing berisi nilai **8** dan **5**. Perintah ini harus ditulis sebelum **int main()**.

Format pembuatan konstanta menggunakan perintah **\#define** adalah:

```
#define nama_konstanta nilai_konstanta
```

Dalam kode program diatas, perintah **\#define PANJANG 8** artinya saya membuat konstanta bernama **PANJANG** yang di isi nilai **8**. Sedangkan perintah **\#define LEBAR 5** artinya saya membuat konstanta bernama **LEBAR** yang di isi nilai **5**.

Di bagian program utama, yakni di dalam **int main()**, nilai dari masing-masing konstanta ditampilkan dengan perintah **cout**.

Penjelasan lebih rinci tentang cara penggunaan perintah **cout** akan kita pelajari dalam tutorial setelah ini. Untuk sementara silahkan fokus ke cara pembuatan konstanta **PANJANG** dan **LEBAR** di baris 5 dan 6.

Sebagai tambahan, perintah **cout << "\n"** dipakai untuk membuat karakter _new line_ (baris baru). Tujuannya agar teks berikutnya tampil di baris baru. Tanpa perintah ini, teks akan disambung terus ke kanan.

---

### Aturan Penamaan Konstanta

Aturan penamaan konstanta sama seperti _identifier_ lain yang sudah kita bahas dalam tutorial [Aturan Dasar Penulisan Kode Program C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-aturan-dasar-penulisan-kode-program-c-plus-plus/ "Tutorial Belajar C++ Part 6: Aturan Dasar Penulisan Kode Program C++").

Namun menjadi kebiasaan mayoritas programmer untuk membuat nama konstanta dalam **HURUF BESAR**. Tujuannya agar mudah dibedakan dengan variabel yang menggunakan huruf kecil. Meskipun begitu, kita juga bisa membuat konstanta dengan huruf kecil.

Berikut contoh lain pembuatan konstanta dalam bahasa pemrograman C++:

```Cpp
#include <iostream>
 
using namespace std;
 
#define website "www.duniailkom.com"
#define ipk 3.99
 
int main()
{
  cout << "Sedang belajar bahasa C++ di " << website;
  cout << "\n";
 
  cout << "Semoga dapat IPK " << ipk;
  cout << "\n";
 
  return 0;
}
```

Hasil kode program:

```
Sedang belajar bahasa C++ di www.duniailkom.com
Semoga dapat IPK 3.99
```

Kali ini saya menggunakan huruf kecil untuk konstanta **website** dan **ipk**. Karena nilai konstanta **website** berupa teks, harus ditulis dalam tanda kutip dua.

---

### Cara Membuat Konstanta C++ dengan Perintah "const"

Selain dari perintah **\#define**, konstanta juga bisa dibuat menggunakan perintah **const**. Bedanya, pembuatan konstanta sekarang berada di dalam **main()** function dan juga harus ditulis tipe data dari konstanta tersebut.

Berikut contoh kode program bahasa C++ untuk membuat konstanta menggunakan keyword **const**:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  const string WEBSITE = "www.duniailkom.com";
  const double IPK = 3.99;
 
  cout << "Sedang belajar bahasa C++ di " << WEBSITE;
  cout << "\n";
 
  cout << "Semoga dapat IPK " << IPK;
  cout << "\n";
 
  return 0;
}
```

Hasil kode program:

```
Sedang belajar bahasa C++ di www.duniailkom.com
Semoga dapat IPK 3.99
```

Format pembuatan konstanta menggunakan perintah **const** adalah:

```Cpp
const tipe_data nama_konstanta = nilai_konstanta;
```

Dalam kode program diatas, perintah `const string WEBSITE = "www.duniailkom.com"` artinya saya membuat konstanta bernama **WEBSITE** dengan tipe data **string** yang di isi teks `"www.duniailkom.com"`.

Sedangkan perintah **const double IPK = 3.99** artinya saya membuat konstanta bernama **IPK** dengan tipe data **double** yang di isi nilai 3.99.

Lebih jauh tentang jenis-jenis tipe data dalam bahasa C++ akan kita pelajari dalam tutorial tersendiri.

Sebagai bahasan terakhir, mari coba tukar nilai sebuah konstanta setelah di definisikan:

```Cpp
#include <iostream>
 
using namespace std;
 
int main()
{
  const double IPK = 3.99;
 
  cout << "Semoga dapat IPK " << IPK;
  cout << "\n";
 
  IPK = 2.99;
 
  return 0;
}
```

Hasil kode program:

```
error: assignment of read-only variable 'IPK'
```

Setelah membuat dan mengisi konstanta **IPK** dengan nilai **3.99**, saya mencoba mengisinya dengan angka **2.99** menggunakan perintah **IPK = 2.99**. Hasilnya tampil _error: assignment of read-only variable 'IPK'_ yang berarti nilai IPK bersifat **read-only** dan tidak bisa diubah.

---

Sepanjang tutorial belajar pemrograman bahasa C++ kali ini kita telah membahas pengertian dan cara pembuatan konstanta. Berikutnya akan disambung dengan [Fungsi Perintah cout di C++](https://www.duniailkom.com/tutorial-belajar-c-plus-plus-fungsi-perintah-cout-dalam-bahasa-c-plus-plus/ "Tutorial Belajar C++ Part 9: Fungsi Perintah cout dalam Bahasa C++").