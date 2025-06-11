---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Mengenal Tipe Data Union
sumber: petanikode.com
date_learned: 2025-06-11T12:56:00
tags:
  - basic
  - union
---
Link Sumber: [Mengenal Tipe Data Union](https://www.petanikode.com/cpp-union/)

---
# Mengenal Tipe Data Union

![[13 Mengenal Tipe Data Union-1.png]]

Setelah belajar tentang [Struct](https://www.petanikode.com/cpp-struct/), berikutnya kita akan berkenalan dengan tipe data Union.

Apa itu union?

Mengapa kita butuh union?

Apa bedanya dengan struct?

..dan gimana cara pakai union?

Mari kita pelajari!

## Apa itu Union?

Union adalah tipe data yang berisi **sekumpulan variabel** yang dibungkus jadi satu dan **memiliki alamat memori yang sama**.

Union sebenarnya mirip seperti struct dan class. Namun berbeda dalam cara memberikan alamat memori.

Mengapa kita membutuhkan union?

Untuk menjawab ini, kita akan pakai studi kasus..

Misalnya kita akan membuat game, lalu ingin menyimpan data senjata yang dimiliki pemain.

Anggap saja pemain punya dua senjata, yakni: pistol dan pisau.

Maka kita bisa membuat struct seperti ini:

```cpp
struct Senjata {
	string nama;
	int jumlah_peluru;
	int ketajaman;
};
```

Perhatikan variabel `jumlah_peluru` dan `ketajaman`. Variabel ini dibutuhkan masing-masing jenis senjata.

Pistol membutuhkan `jumlah_peluru` dan pisau membutuhkan `ketajaman`.

Jika pemain cuma punya pistol, berarti variabel `ketajaman` akan sia-sia. Begitu sebaliknya.

Nah biar tidak sia-sia, kita harus menyimpan variabel `jumlah_peluru` dan `ketajaman` dalam satu alamat memori.

Ini bisa kita lakukan dengan union seperti ini:

```cpp
struct Senjata {
	string nama;
	union {
		int jumlah_peluru;
		int ketajaman;
	}
};
```

Dengan begini, variabel `jumlah_peluru` dan `ketajaman` akan menggunakan satu alamat memori yang sama. Ini tentunya akan lebih efisien.

Jadi mengapa kita membutuhkan union?

Union kita butuhkan saat kita ingin menggunakan satu alamat memori untuk dua atau lebih variabel.

## Cara Membuat Union

Union bisa kita buat dengan kata kunci `union` kemudian diikuti dengan nama union-nya.

Setelah itu kita menggunakan kurung kurawal untuk mendefinisikan member dan tipe datanya.

![[13 Mengenal Tipe Data Union-2.png]]

Beberapa ketentuan membuat Union di C++:

- member Union bisa berisi fungsi
- member Union nggak bisa pakai type data non-static atau reference, contohnya seperti object.
- kalau mau pakai non-static member, maka harus dibuatkan constructor dan destructor-nya.
- Union mirip seperti struct, akses membernya bersifat publik.

Contoh:

```cpp
union Product {
  char* name;
  unsigned int price;
  unsigned int stock;
  float weight;
};
```

> Catatan: `char*` adalah sama dengan `string`.

Lalu cara menggunakannya:

```cpp
// membuat variabel untuk union
Product p;

// mengisi data ke member union
p.name = "Pupuk NPK 1kg";
p.price = 200000;
p.stok = 999;
```

Variabel `p` adalah variabel yang berisi union dan di dalamnya terdapat member yang akan menggunakan satu alamat memori yang sama.

Union juga bisa kita buat tanpa nama seperti ini:

```cpp
union {
  float x;
  float y;
};
```

..dan Union yang tanpa nama ini, bisa juga kita simpan di dalam Struct:

Contoh:

```cpp
struct Buku {
  char *title ;
  bool is_digital;
  union {
  	char *format;
    float weight;
  };
};
```

Di dalam struct `Buku` terdapat `union` tanpa nama yang berisi variabel `format` dan `weight`. Kedua variabel ini, akan menggunakan satu alamat memori yang sama dan bisa langsung diakses dari struct `Buku`.

Contoh:

```cpp
// membuat variabel struct
Buku belajar_cpp;

// mengakses union di dalam struct
belajar_cpp.format = "PDF";
```

Biar lebih paham, mari kita coba latihan.

## Latihan: Menggunakan Union

Setelah tau cara mendefinisikan atau membuat union, kita saatnya kita coba menggunakannya.

Buatlah program baru dengan nama `contoh_union.c`, kemudian isi kodenya seperti ini:

```cpp
#include <iostream>
using namespace std;

// membuat struct yang berisi union
struct Notification
{
    enum { EMAIL, SMS } type;
    string title;
    string message;
    union
    {
        char* phone_number;
        char* email_address;
    };
};

int main()
{
    Notification sms =
    {
        .type = Notification::SMS,
        .title = "Greeting",
        .message = "Halo Selamat datang",
        .phone_number = "081234567890"
    };

    Notification email =
    {
        .type = Notification::EMAIL,
        .title = "Welcome",
        .message = "Selamat datang di aplikasi",
        .email_address = "mail@petanikode.com"
    };

    // show notification
    cout << "## 🔔 NOTIFICATION SMS ##\n";
    cout << "to: " << sms.phone_number << endl;
    cout << "message: " << sms.message << endl;

    cout << endl;

    cout << "## ✉ NOTIFICATION EMAIL ##\n";
    cout << "subject: " << email.title << endl;
    cout << "to: " << email.email_address << endl;
    cout << "message: " << email.message << endl;

    return 0;
}
```

Setelah itu, coba compile dan jalankan.

Maka hasilnya:

![[13 Mengenal Tipe Data Union-3.png]]

Pada program ini, kita membuat sistem notifikasi dengan dua jenis notifikasi yang berbeda. Ada notifikasi berbentuk email dan sms.

Berkat union kita bisa menentukan tujuan pengiriman notifikasi dengan jenis yang berbeda, yakni bisa `phone_number` dan `email_address`.

## Perbedaan Union dengan Struct

Union sebenarnya sama seperti tipe data Struct. Namun, berbeda dalam metode alokasi memorinya.

Struct mengalokasikan memori untuk setiap membernya pada alamat memori yang berbeda-beda.

Sedangkan Union mengalokasikan memori di satu alamat memori dengan ukuran diambil dari ukuran member yang paling besar.

Contoh:

```cpp
struct Player 
{
  char *name; // address: 00000011
  unsigned int level; // address: 00000012
}

union Enemy 
{
  char *name; // 00000022
  unsigned int hp; // 00000022
}
```

Setiap member pada struct `Player` akan menggunakan alamat memori yang berbeda. Sedangkan union `Enemy` hanya menggunakan satu alamat memori saja.

Biar lebih jelas, mari kita coba latihan.

## Latihan: Struct vs Union

Buatlah program baru dengan nama `union_vs_struct.cpp`, kemudian isi dengan kode berikut:

```cpp
#include <iostream>
#include <stdio.h>
using namespace std;

struct Player
{
    string name;
    unsigned int level;
};

union Enemy
{
    char *name;
    unsigned int hp;
};

int main()
{
    Player player1 =
    {
        .name = "Petani Kode",
        .level = 1
    };

    printf("Player  : %d  (address = %x)\n", sizeof(player1), &player1);
    printf(" - name : %d  (address = %x)\n", sizeof(player1.name), &player1.name);
    printf(" - level: %d  (address = %x)\n", sizeof(player1.level), &player1.level);


    union Enemy zombie;
    zombie.name = "Zombie 1";
    zombie.hp = 100;

    printf("Enemy   : %d  (address = %x)\n", sizeof(zombie), &zombie);
    printf(" - name : %d  (address = %x)\n", sizeof(zombie.name), &zombie.name);
    printf(" - Hp   : %d  (address = %x)\n", sizeof(zombie.hp), &zombie.hp);

    return 0;
}
```

Setelah itu, coba compile dan jalankan.

Maka hasilnya:

![[13 Mengenal Tipe Data Union-4.png]]

Ukuran memori union `Enemy` adalah `8` karena mengambil dari ukuran member yang paling besar, yakni ukuran dari `name`.

Alamat memori yang digunakan tiap member pada `union` adalah sama. Tidak seperti struct `Player` yang alamatnya berbeda-beda.

## Apa Selanjutnya?

Kita sudah belajar dan memahami tipe ata union pada C. Kita memang tidak harus selalu menggunakan union.

Tapi..

Pada kasus tertentu seperti yang dicontohkan di atas, kita disarankan menggunakan union.

Berikutnya silakan pelajari tentang pointer di C++.

- [[14 Memahami Pointer di C++]]

Jika ada yang belum dipahami, silakan tanyakan di komentar.

Selamat belajar. 🙌