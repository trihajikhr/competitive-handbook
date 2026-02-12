---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Compare String
sumber:
  - myself
  - chatgpt.com
date_learned: 2026-01-13T19:26:00
tags:
  - tips-trick
  - strings
---
---
# Compare String

Terkadang terdapat kasus pada sebuah problem di mana kita diminta untuk membandingkan dua buah string. Misalnya, menentukan apakah kedua string tersebut sama, mana yang lebih besar secara leksikografis, atau apakah kedua string tetap dianggap sama jika perbedaan huruf besar dan kecil diabaikan.

Ada beberapa cara yang dapat digunakan untuk melakukan perbandingan string.

> [!CAUTION]
> Di dalam C++, terdapat dua jenis string, yaitu `std::string` (string C++) dan C-style string (`char[]` / `char*`).  
> 
> Materi ini hanya membahas perbandingan string menggunakan `std::string`, karena perlakuan yang sama pada kedua jenis string tersebut dapat menghasilkan perilaku dan hasil yang berbeda.

## 1. Compare Langsung

Semisal kita diminta untuk menentukan apakah dua buah string $a$ dan $b$ adalah sama atau tidak, maka bisa menggunakan perbandingan langsung dengan operator logika == berikut:

```cpp
if(a == b){
	cout << "Sama!";
} else {
	cout << "Berbeda!";
}
```

Untuk mengetahu perbandingan leksikografis, juga bisa menggunakan operator logika `>` dan `<`, misal:

```cpp
if (a < b) {
	cout << "a lebih kecil dari b!";
} else if(a > b) {
	cout << "a lebih besar dari b!";
} else {
	cout << "a sama dengan b!";
}
```

Sedangkan jika diminta untuk mmebandingkan dengan mengabaikan besar kecil huruf, maka kita perlu melakukan standarisasi. Misal mengecilkan atau membesarkan semua karakter yang ada. Berikut adalah contoh membandingkan 2 buah string dengan mengabaikan besar kecilnya huruf, dengan standarisasi yang digunakan adalah menyecilkan semua karakter yang ada:

```cpp
string a, b;
cin >> a >> b;

// standarisasi: ubah semua karakter menjadi huruf kecil
for (char &c : a) {
    c = tolower(c);
}
for (char &c : b) {
    c = tolower(c);
}

if (a == b) {
    cout << "Sama!";
} else {
    cout << "Berbeda!";
}
```

Atau dengan mengandalkan fungsi buatan sendiri:

```cpp
string toLower(string s) {
    for (char &c : s) {
        c = tolower(c);
    }
    return s;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (toLower(a) == toLower(b)) {
        cout << "Sama!";
    } else {
        cout << "Berbeda!";
    }
}
```

> [!CAUTION]
> Perlu diperhatikan bahwa fungsi `tolower` bekerja berdasarkan karakter ASCII, sehingga pendekatan ini aman untuk alfabet Latin, namun tidak untuk Unicode atau locale tertentu.

Dengan melakukan standarisasi terlebih dahulu, perbandingan string dapat dilakukan menggunakan operator == seperti biasa, karena perbedaan huruf besar dan kecil sudah dihilangkan.

## 2. Fungsi `compare()`

Fungsi `compare` pada `std::string` merupakan fungsi bawaan C++ yang digunakan untuk membandingkan dua buah string secara leksikografis. Perbandingan dilakukan karakter demi karakter berdasarkan urutan nilai karakter (ASCII), dimulai dari indeks pertama hingga ditemukan perbedaan atau hingga salah satu string berakhir. Fungsi ini bersifat _case-sensitive_, sehingga perbedaan huruf besar dan kecil akan memengaruhi hasil perbandingan.

Pemanggilan paling sederhana dari fungsi ini adalah `a.compare(b)`, dengan `a` dan `b` bertipe `std::string`. Fungsi ini mengembalikan sebuah bilangan bulat. Jika nilai yang dikembalikan adalah nol, maka kedua string memiliki isi yang sama. Jika nilainya kurang dari nol, maka string pemanggil dianggap lebih kecil secara leksikografis dibandingkan string pembanding. Sebaliknya, jika nilainya lebih besar dari nol, maka string pemanggil lebih besar secara leksikografis.

Sebagai contoh penggunaan sederhana untuk mengecek kesamaan dua string:

```cpp
string a = "hello";
string b = "hello";

if (a.compare(b) == 0) {
    cout << "Kedua string sama";
} else {
    cout << "Kedua string berbeda";
}
```

Fungsi `compare` juga dapat digunakan untuk menentukan urutan leksikografis dua string, misalnya untuk mengetahui string mana yang lebih kecil atau lebih besar:

```cpp
string a = "apple";
string b = "banana";

if (a.compare(b) < 0) {
    cout << "a lebih kecil dari b secara leksikografis";
} else if (a.compare(b) > 0) {
    cout << "a lebih besar dari b secara leksikografis";
} else {
    cout << "a sama dengan b";
}
```

Selain membandingkan string secara keseluruhan, fungsi `compare` menyediakan bentuk pemanggilan lain yang memungkinkan perbandingan sebagian string atau substring tertentu. Hal ini berguna ketika hanya bagian tertentu dari string yang perlu dibandingkan, tanpa harus membuat substring baru secara eksplisit. Contohnya:

```cpp
string s = "competitive";
string t = "pet";

if (s.compare(3, 3, t) == 0) {
    cout << "Substring sama";
} else {
    cout << "Substring berbeda";
}
```

Pada contoh tersebut, fungsi `compare` digunakan untuk membandingkan substring dari `s` yang dimulai pada indeks ke-3 dengan panjang 3 karakter terhadap string `t`.

Perlu diperhatikan bahwa fungsi `compare` tidak mengabaikan perbedaan huruf besar dan kecil. Apabila perbandingan string diminta untuk mengabaikan perbedaan tersebut, maka diperlukan proses standarisasi terlebih dahulu, seperti mengubah seluruh karakter pada kedua string menjadi huruf kecil atau huruf besar sebelum fungsi `compare` digunakan.

Dengan demikian, fungsi `compare` dapat dianggap sebagai alternatif berbasis fungsi dari operator perbandingan pada `std::string`, yang berguna ketika dibutuhkan hasil perbandingan dalam bentuk numerik atau ketika melakukan perbandingan pada bagian tertentu dari sebuah string.