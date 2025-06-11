---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Memahami Pointer di C++
sumber: petanikode.com
date_learned: 2025-06-11T12:44:00
tags:
  - basic
  - pointer
---
Link Sumber: [Memahami Pointer di C++](https://www.petanikode.com/cpp-pointer/)

---
# Memahami Pointer di C++

![[14 Memahami Pointer di C++-1.png]]

Bagi sebagian pemula.. pointer memang sulit dipahami. Ini juga pernah saya alami dulu saat baru belajar C.

Tapi tenang saja..

Saya akan coba menjelaskannya dengan bahasa yang mudah dipahami.

Baiklah..

Mari kita mulai.

## Apa itu Pointer?

Setiap variabel yang kita buat pada program akan memiliki alamat memori. Alamat memori berfungsi untuk menentukan lokasi penyimpanan data pada memori (RAM).

Kadang alamat memori ini disebut _reference_ atau referensi. Coba perhatikan gambar ini:

![[14 Memahami Pointer di C++-2.png]]

Pada gambar ini, kita membuat dua variabel.. yakni `score` dan `hp`. Kedua variabel ini punya alamat memori masing-masing.

Variabel `score` alamat memorinya adalah `01abc`, sedangkan `hp` alamat memorinya `02ffd`.

Selama sebuah alamat masih kosong.. maka alamat itu yang akan dipilih.

Oya, pemilihan alamat memori ini, dilakukan secara acak. Inilah mengapa memori ini di sebut RAM _(Random Access Memory)_.

Intinya, setiap kita membuat variabel pasti akan punya alamat memori.

Kalau tidak percaya, kamu bisa buktikan sendiri dengan menggunakan simbol `&` _(ampersand)_.

Contoh:

```cpp
#include <iostream>
using namespace std;

int main () {

    int  a;
    char b[10];

    cout << "Alamat memori variabel a: " << &a << endl;
    cout << "Alamat memory variabel b: " << &b << endl;
    return 0;
}
```

Pada program ini, kita menggunakan simbol `&` untuk mengambil alamat memori dari variabel `a` dan `b`.

Hasilnya:

![[14 Memahami Pointer di C++-3.png]]

Lalu apa hubungannya alamat memori dengan pointer?

Mari kita bahas…

Pointer adalah sebuah **variabel khusus yang berisi alamat memori**. Pointer nantinya akan bisa mengakses data yang ada di suatu alamat memori.

Kata kunci yang perlu kamu ingat:

**“Pointer berisi alamat memori”**
## Cara Membuat Pointer

Pointer dibuat dengan menambahkan simbol `*` _(asterik)_ di depan namanya, kemudian diisi dengan alamat memori yang akan digunakan sebagai referensi.

Contoh:

```cpp
int *pointer1 = 00001;
```

Maka `*pointer1` akan bisa mengakses data yang ada pada alamat memori `00001`. Dengan kata lain, si `*pointer1` akan menggunakan alamat `00001` sebagai referensinya.

Kita juga bisa membuat pointer tanpa harus mengisinya langsung dengan alamat memori.

Contoh:

```cpp
int *pointer_ku;

// atau bisa juga

int *pointer_ku = NULL;
```

Maka `*pointer_ku` akan menggunakan alamat memori `00000`, alamat memori ini khusus untuk menyimpan data `null` atau data kosong.

Sekarang masalahnya:

Karena kita tidak bisa lihat daftar alamat memori secara langsung, kita akan kesulitan memberikan referensi alamat memori untuk pointer.

Belum lagi.. beda komputer beda juga alamat memorinya. Ada yang 8 bit, ada juga yang 16, 32, dan sebagainya.

Solusinya:

Kita harus mengambil alamat memori dari variabel yang lain.

Masih ingat caranya? Ya, dengan menggunakan simbol `&`.

Coba perhatikan gambar ini:

![[14 Memahami Pointer di C++-4.png]]

Pada gambar ini, kita membuat pointer dengan nama `*ptr_hp*` dengan isi alamat memori dari variabel `hp`.

Dengan begini..

Pointer `*ptr_hp` akan bisa mengakses nilai pada alamat memori `02ffd` yang mana ini adalah alamat memori dari variabel `hp`.

Jika kita ingin mengubah nilai pada alamat memori tersebut, maka kita bisa gunakan pointer `*ptr_hp` seperti ini:

```cpp
*ptr_hp = 95;
```

Maka, sekarang alamat memori `02ffd` akan berisi `95` begitu juga dengan variabel `hp`.

![[14 Memahami Pointer di C++-5.png]]

Biar lebih jelas, mari kita coba latihan dalam program.
## Latihan: Mengakses data dengan Pointer

Buatlah program baru dengan nama `contoh_pointer.cpp`, kemudian isi dengan kode berikut:

```cpp
#include <stdio.h>

int main(){
    int score = 50;
    int hp = 100;

    // membuat pointer dengan isi alamat memori dari hp
    int *ptr_hp = &hp;

    // print isi variabel dan alama memori
    printf("Nama Variabel \t Alamat \t Konten\n");
    printf("score \t\t %x \t %d \n", &score, score);
    printf("hp \t\t %x \t %d \n", &hp, hp);
    printf("ptr_hp \t\t %x \t %x \n", &ptr_hp, ptr_hp);
    printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);

    // mengubah data pada alamat memori dengan pointer
    *ptr_hp = 95;

    printf("hp \t\t %x \t %d \n", &hp, hp);
    printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);

    return 0;
}
```

Setelah itu, coba _compile_ dan jalankan.

Maka hasil:

![[14 Memahami Pointer di C++-6.png]]

Pointer `*ptr_hp` berhasil mengubah nilai pada alamat `d57ba6c` menjadi `95`.

Saat menggunakan pointer, kita menggunakan tanda `*` di depan nama pointer untuk mengakses nilai pada alamat memori. Jika tidak menggunakan tanda ini, maka kita akan mendapatkan alamat memori yang di-pointing.

```cpp
*ptr // ini akan berisi 95 (nilai dari alamat)
ptr // ini akan berisi d57ba6c (alamat memori dari variabel hp)
```

Oh iya, pointer juga punya alamat memorinya sendiri.

Pada contoh di atas, alamat memori dari pointer `*ptr_hp` adalah `d57ba70`. Mungkin di komputermu akan berbeda, silakan di cek sendiri.

Jika kamu perhatikan gambar ini:

![[14 Memahami Pointer di C++-7.png]]

Alamat memori yang dipakai `*ptr_hp` adalah `012ef` dengan isi alamat memori `02ffd`.

Sapai di sini sudah paham?

Sekarang pertanyaannya:

Kalau kita menggunakan pointer, bukankah ini akan boros memori? Karena kita harus mengalokasikan alamat memori untuk si pointernya juga.

Jika kita bisa menggunakan variabel biasa, ngapain pakai pointer?

Penggunaan pointer sebenarnya opsional, kamu boleh pakai.. boleh juga tidak.

Namun..

Pada kondisi tertentu, penggunaan pointer lebih optimal.

Nanti kita akan bahas ini lagi.

## Kapan Saya Harus Pakai Pointer?

Seperti yang saya katakan tadi, kita **tidak harus selalu** menggunakan pointer dalam program.

Namun, ada beberapa kasus tertentu yang menyarankan menggunakan pointer daripada cara biasa.

Biar jelas..

Kita bahas dulu, **mengapa pointer diciptakan**?

Jadi zaman dulu, memori komputer itu sangat terbatas. Tidak seperti sekarang yang kapasitasnya sampai giga-gigaan.

Saat kita melakukan operasi iterasi pada tipe data seperti array, string, tree, linked list, graph, dan sebagainya.. sering kali memakan banyak memori dan membuat programnya lambat.

Penggunaan Pointer pada operasi semacam akan meningkatkan performa secara signifikan dibandingkan tanpa menggunakan pointer.

## Latihan: Pointer untuk Pass by Reference pada Fungsi

Pertama kita akan coba menggunakan pointer untuk melakukan _passing_ argumen berdasarkan referensinya _(pass by reference)_.

Contoh:

```cpp
#include <stdio.h>

void add_score(int score){
    score = score + 5;
}

int main(){
    int score = 0;

    printf("score sebelum diubah: %d\n", score);
    add_score(score);
    printf("score setelah diubah: %d\n", score);
    return 0;
}
```

Pada program ini, kita membuat fungsi dengan nama `add_score()` untuk menambahkan nilai score sebanyak `5`.

Tapi ketika dijalankan:

![[14 Memahami Pointer di C++-8.png]]

Nilai variabel score tidak berubah, ia tetap bernilai `0`.

Mengapa?

Ini karena kita melakukan _pass by value_, bukan _pass by reference_.

Variabel `score` kan dibuat di dalam fungsi `main()`, lalu ketika fungsi `add_score()` mencoba mengubah nilainya..

…maka perubahan hanya terjadi secara lokal di dalam fungsi `add_score()` saja.

Nggak percaya?

Coba buktikan dengan mengubah fungsi `add_score()` menjadi seperti ini:

```cpp
#include <stdio.h>

void add_score(int score){
    score = score + 5;
    printf("Score diubah ke %d\n", score);
}

int main(){
    int score = 0;

    printf("score sebelum diubah: %d\n", score);
    add_score(score);
    printf("score setelah diubah: %d\n", score);
    return 0;
}
```

Hasilnya:

![[14 Memahami Pointer di C++-9.png]]

Benar kan yang saya katakan..

Nilai `score` pada fungsi `add_score()` sudah berubah menjadi `5`, namun variabel `score` pada fungsi `main()` akan tetap bernilai `0`.

Nah..

Di sinilah kita harus menggunakan pointer untuk melakukan _pass-by-reference_.

Sekarang, coba ubah kode programnya menjadi seperti ini:

```cpp
#include <stdio.h>

void add_score(int *score){
    *score = *score + 5;
    printf("score diubah ke: %d\n", *score);
}

int main(){
    int score = 0;

    printf("score sebelum diubah: %d\n", score);
    add_score(&score);
    printf("score setelah diubah: %d\n", score);
    return 0;
}
```

Karena argumen fungsi `add_score()` kita ubah menjadi pointer, maka kita harus memberikan alamat memori saat memanggilnya.

Maka hasilnya:

![[14 Memahami Pointer di C++-10.png]]

Setiap fungsi `add_score()` dipanggil atau dieksekusi, maka nilai variabel `score` akan bertambah `5`.

Coba kita ubah menjadi seperti ini:

```cpp
#include <stdio.h>

void add_score(int *score){
    *score = *score + 5;
    printf("score diubah ke: %d\n", *score);
}

int main(){
    int score = 0;

    printf("score sebelum diubah: %d\n", score);
    add_score(&score);
    add_score(&score);
    add_score(&score);
    add_score(&score);
    add_score(&score);
    add_score(&score);
    printf("score setelah diubah: %d\n", score);
    return 0;
}
```

Hasilnya:

![[14 Memahami Pointer di C++-11.png]]

## Latihan: Pointer untuk Mengakses Data pada Array

Pointer juga sering digunakan untuk mengakses data pada array.

Contoh: `pointer_array.cpp`

```cpp
#include <stdio.h>

int main(){
    printf("## Program Antrian CS ##\n");

    char no_antrian[5] = {'A', 'B', 'C', 'D', 'E'};

    // menggunakan pointer
    char *ptr_current = no_antrian;

    for(int i = 0; i < 5; i++){
        printf("📢 Pelanggan dengan no antrian %c silakan ke loket!\n", *ptr_current);
        printf("Saat ini CS sedang melayani: %c\n", *ptr_current);
        printf("-------- Tekan Enter untuk Next --------");
        getchar();
        ptr_current++;
    }

    printf("✅ Selesai");
    return 0;
}
```

Pada program ini, kita menggunakan `ptr_current` untuk mengakses elemen array. Saat pertama kali dibuat, pointer `ptr_current` akan mereferensi pada elemen pertama array.

Lalu pada perulangan dilakukan increment `ptr_current++`, maka pointer ini akan mereferensi ke elemen array selanjutnya.

Hasilnya:

![[pointer-array.webm]]

## Latihan: Pointer untuk Mengakses Data pada Struct

Menggunakan pointer pada struct akan membantu kita membuat kode menjadi lebih mudah dan gampang dibaca dibandingkan tanpa pointer.

Sebagai contoh..

Misalnya kita punya struct seperti ini:

```cpp
struct Player {
  char *name;
  int score;
  int hp;
	struct Weapon *weapon;
};

struct Weapon {
	char *name;
  int attack;
  int guard;
};
```

Struct `Player` di dalamnya ada struct lagi, yakni struct `Weapon`. Nah di sini kita menggunakan pointer untuk struct `Weapon`.

```cpp
struct Weapon *weapon;
```

Pertanyaannya:

Gimana cara mengakses data di struct weapon?

Ada dua cara, kita bisa pakai operator `.` (dot/titik) dan `->` (operator pointer).

Pertama kita coba dulu pakai titik.

Silakan buat program baru dengan nama `pointer_struct.cpp`, kemudian isi dengan kode berikut:

```cpp
#include <iostream>

using namespace std;

int main(){
    struct Weapon {
        string name;
        int attack;
        int guard;
    };

    struct Player {
        string name;
        int score;
        int hp;
        Weapon *weapon;
    };

    Player player1;
    player1.name    = "Petani Kode";
    player1.score   = 0;
    player1.hp      = 100;
    player1.weapon = new Weapon;

    (*player1.weapon).name = "Katana";
    (*player1.weapon).attack = 16;
    (*player1.weapon).guard = 10;

    // cetak status player
    cout << "PLAYER STATUS" << endl;
    cout << "Name: " << player1.name << endl;
    cout << "Score: " << player1.score << endl;
    cout << "HP: " << player1.hp << endl;
    cout << "Weapon" << endl;
    cout << "  name: " << (*player1.weapon).name << endl;
    cout << "  attack: " << (*player1.weapon).attack << endl;
    cout << "  guard: " << (*player1.weapon).guard << endl;

    return 0;
}
```

Setelah itu, compile dan jalankan.

Maka hasilnya:

![[14 Memahami Pointer di C++-12.png]]

Perhatikan kodenya!

Saat kita mengakses data member pada struct yang bentuknya pointer dengan operator dot atau titik, maka kita harus menggunakan tanda kurung dan `*` untuk menyatakan itu adalah pointer.

```cpp
(*player1.weapon).name = "Katana";
(*player1.weapon).attack = 16;
(*player1.weapon).guard = 10;
```

Jika hanya satu member yang berbentuk pointer struct, ini oke-oke aja.

Tapi..

Kalau misalnya ada member struct pointer dan di dalamnya lagi ada struct pointer dan di dalamnya ada struct pointer, pasti kita akan bingung.

Bisa saja kodenya seperti ini:

```cpp
(*(*(*player.weapon).katana).type).name = "Wakizashi";
```

Duh! saya aja bingung bacanya.

Nah, biar gak seperti ini.. kita bisa pakai arrow operator (`->`) untuk mengakses member dari struct yang menggunakan pointer.

Contoh:

```cpp
player->weapon->katana->type->name = "Wakizashi";
```

Ini lebih mudah dibaca dibandingkan yang tadi.

Jadi, jika ada member pointer di dalam Struct, maka sebaiknya pakai operator `->` untuk mengakses membernya.

Mari kita ubah kode yang tadi (`pointer_struct.cpp`) menjadi seperti ini:

```cpp
#include <iostream>

using namespace std;

int main(){
    struct Weapon {
        string name;
        int attack;
        int guard;
    };

    struct Player {
        string name;
        int score;
        int hp;
        Weapon *weapon;
    };

    Player player1;

    // membuat pointer untuk player1
    Player *p1 = &player1;

    p1->name    = "Petani Kode";
    p1->score   = 0;
    p1->hp      = 100;
    p1->weapon = new Weapon;

    p1->weapon->name = "Katana";
    p1->weapon->attack = 16;
    p1->weapon->guard = 10;

    // cetak status player
    cout << "PLAYER STATUS" << endl;
    cout << "Name: " << p1->name << endl;
    cout << "Score: " << p1->score << endl;
    cout << "HP: " << p1->hp << endl;
    cout << "Weapon" << endl;
    cout << "  name: " << p1->weapon->name << endl;
    cout << "  attack: " << p1->weapon->attack << endl;
    cout << "  guard: " << p1->weapon->guard << endl;

    return 0;
}
```

Hasilnya:

![[14 Memahami Pointer di C++-13.png]]

Pada program ini kita membuat dua variabel untuk struct Player, yakni `player1` dan `p1`. Variabel `p1` akan menjadi pointer untuk mengakses data pada `player1`.

```cpp
// membuat struct player
Player player1;
// membuat pointer untuk player
Player *p1 = &player1;
```

Karena `p1` adalah pointer yang mereferensi ke struct `player1` maka member pada `player1` dapat kita akses dengan arrow operator (`->`).

## Apa Selanjutnya?

Kita sudah membahas konsep dasar pointer pada C++. Konsep ini harus kamu pahami, agar nanti saat ketemu pointer tidak bingung.

Kita tidak harus selalu menggunakan Pointer, tapi ada kasus tertentu seperti akses data pada Struct.. menggunakan pointer sangat disarankan agar kodenya lebih mudah dibaca.

Jika kamu masih bingung, silakan tanyakan di komentar.

Selanjutnya silakan pelajari tentang alokasi memori dengan fungsi `malloc()`, `calloc()`, `realloc()`, dan `free()`.

Selamat belajar. 🙌