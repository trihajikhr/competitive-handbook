---
obsidianUIMode: preview
note_type: tips trick
tips_trick: optimalisasi input output
sumber: "buku: CP handbook by Antti Laaksonen & chatgpt.com"
tags:
  - input-output
  - efisien
---
#input-output #efisien

---
# Optimalisasi Input Output pada CP

Dalam sebagian besar kontes, aliran standar (standard streams) digunakan untuk membaca input dan menulis output. Dalam C++, aliran standar untuk input adalah `cin` dan untuk output adalah `cout`. Selain itu, fungsi C `scanf` dan `printf` juga dapat digunakan.

## 2.1 Penggunaan `cin`

Input untuk program biasanya terdiri dari angka dan string yang dipisahkan dengan spasi dan baris baru. Input tersebut dapat dibaca dari aliran `cin` sebagai berikut:

```cpp
int a, b;
string x;
cin >> a >> b >> x;
```

Kode seperti ini selalu bekerja, dengan asumsi ada setidaknya satu spasi atau baris baru di antara setiap elemen input. Sebagai contoh, kode di atas dapat membaca kedua input berikut:

```bash
123 456 monkey
```

```bash
123     456
monkey
```

## 2.2 Penggunaan `cout`
Aliran `cout` digunakan untuk output sebagai berikut:

```cpp
int a = 123, b = 456;
string x = "monkey";
cout << a << " " << b << " " << x << "\n";
```

## 2.3 Efisiensi I/O atau input output
Input dan output kadang-kadang bisa menjadi hambatan dalam program. Baris berikut di awal kode membuat input dan output menjadi lebih efisien:

```cpp
ios::sync_with_stdio(0);
cin.tie(0);
```

#### 📌 Apa yang dilakukan oleh `ios::sync_with_stdio(0);`?
 - Secara default, `cin` dan `cout` **disinkronkan** dengan `stdio` (seperti `scanf` dan `printf` dari C).
- Hal ini menyebabkan `cin` dan `cout` bekerja lebih lambat karena harus **menjaga konsistensi buffer** dengan fungsi I/O C.
- Dengan `ios::sync_with_stdio(0);`, kita **mematikan sinkronisasi** ini, sehingga `cin` dan `cout` bisa lebih cepat.

#### 📌 Apa yang dilakukan oleh `cin.tie(0)`?
- Secara default, `cin` **terikat** (`tied`) dengan `cout`, artinya setiap kali kita menggunakan `cin`, **`cout` akan otomatis di-flush (dieksekusi langsung)**.
- Dengan `cin.tie(0);`, kita **melepaskan keterikatan ini**, sehingga `cin` **tidak lagi memaksa `cout` untuk dieksekusi sebelum membaca input berikutnya**.
- Hal ini membuat eksekusi kode lebih **efisien**, terutama jika ada banyak operasi input sebelum output.

#### 📌 Kapan tidak menggunakan `ios::sync_with_stdio(0);`?
- Jika menggunakan `scanf()` atau `printf()` dalam kode yang sama.
- Jika ingin output langsung muncul setelah input (misalnya dalam interaksi dengan pengguna).

Contoh:

```cpp
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);  // Bisa juga menambahkan cout.tie(0) untuk memaksimalkan performa.
```

#### 📌 Jika menggunakan `cout.tie(0);`
`cout.tie(0);` Mirip dengan `cin.tie(0)`, tetapi untuk `cout`. Biasanya tidak berdampak besar karena `cout` jarang tied ke stream lain.
### Catatan
Hari ini, pada tanggal 24 April 2025, aku menemukan bahwa ketika aku mengikutsertakan syntax ini, maka output akan langsung meminta user memasukan inputan!

Misal:

```cpp
#include<iostream>
using namespace std;

inline void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0);
}

int main(){
	int x;
	cout << "Masukan x: ";
	cin >> x;
	
	// dan baris kode kebawah ...
	return 0;
}
```

Maka outputnya akan langsung meminta kita memasukan nilai `x`, dan bukan malah `Masukan x: ` terlebih dahulu.
## 2.4 Efisiensi penggunaan `endl` dengan newline `"\n"`
Terkadang kita menggunakan `endl` pada bagian akhir output agar bisa pindah ke baris baru, seperti ini:

```cpp
cout << "makan"; 
cout << "minum";

cout << "makan" << endl;
cout << "minum";
```

Dan outputnya:

```bash
makanminum
makan
minum
```

Penggunaan `endl;` sebenarnya kurang efisien, karena kita bisa menggunakan karakter newline berikut:

```cpp
cout << "makan \n";
cout << "minum";
```

Dan outputnya:

```bash
makan 
minum
```

Perhatikan bahwa newline `"\n"` lebih cepat daripada `endl`, karena `endl` selalu menyebabkan operasi flush.

#### 📌 Perbedaan utama antara `"\n"` dan `endl`:
- **`"\n"`** → Hanya menambahkan newline (baris baru) tanpa memaksa flush buffer output.
- **`endl`** → Menambahkan newline **dan langsung mem-flush buffer output**, yang bisa memperlambat program.

#### 🚀 Kapan Menggunakan `"\n"`?

- **Competitive programming** → Lebih cepat karena tidak memaksa flush setiap kali mencetak output.

#### ⏳ Kapan Menggunakan `endl`?

- Jika perlu **langsung melihat output tanpa menunggu buffer penuh** (misalnya saat debugging atau program interaktif).

#### 📊Perbandingan Kecepatan

Untuk mencetak banyak output, `"\n"` bisa **lebih dari 10x lebih cepat** dibandingkan `endl`.

Contoh:
```cpp
for (int i = 0; i < 1e6; i++) {
    cout << i << "\n";  // Lebih cepat
    // cout << i << endl;  // Lebih lambat
}
```

## 2.5 Fungsi C `scanf` dan `printf`

Fungsi C `scanf` dan `printf` adalah alternatif dari aliran standar C++. Mereka biasanya sedikit lebih cepat, tetapi juga lebih sulit digunakan. Berikut adalah contoh kode untuk membaca dua angka bulat dari input:

```cpp
int a, b;
scanf("%d %d", &a, &b);
```

Berikut adalah contoh kode untuk mencetak dua angka bulat:

```cpp
int a = 123, b = 456;
printf("%d %d\n", a, b);
```

#### 📌 `scanf` dan `printf` vs. `cin` dan `cout`

- `scanf` dan `printf` berasal dari **C**, sementara `cin` dan `cout` adalah bagian dari **C++**.
- `scanf` dan `printf` umumnya **lebih cepat** dibandingkan `cin` dan `cout` karena mereka tidak menggunakan sinkronisasi dengan _stream_ C.
- Namun, `cin` dan `cout` lebih **fleksibel dan aman**, terutama dengan tipe data non-standar seperti `string` atau `vector<int>`.

 #### 🚀 Perbedaan Kecepatan

-  `scanf` dan `printf` lebih cepat karena tidak memproses buffer dengan `iostream`.  
-  `cin` dan `cout` bisa dioptimalkan dengan `ios::sync_with_stdio(0); cin.tie(0);`.

Jika dibandingkan:

|Metode|Kecepatan|
|---|---|
|`scanf` / `printf`|🔥 Cepat|
|`cin` / `cout` tanpa optimasi|🐢 Lambat|
|`cin` / `cout` dengan `ios::sync_with_stdio(0);`|⚡ Hampir setara `scanf`|

 ####  📌 Kesimpulan

- **Gunakan `scanf` / `printf`** jika ingin kecepatan maksimal tanpa peduli kemudahan penggunaan.
- **Gunakan `cin` / `cout`** jika ingin kode lebih bersih dan fleksibel, terutama dengan struktur data STL (`vector`, `string`, dll.).
- **Gunakan `ios::sync_with_stdio(0); cin.tie(0);`** jika ingin `cin/cout` tetap cepat tanpa beralih ke `scanf/printf`.
## 2.6 Penggunaan fungsi `getline`

`getline` adalah fungsi di C++ yang digunakan untuk membaca seluruh baris input, termasuk spasi dan karakter whitespace lainnya, hingga menemui karakter newline (`\n`). Kegunaannya adalah untuk memungkinkan input berupa kalimat atau teks yang lebih panjang, termasuk yang berisi spasi, tanpa berhenti di tengah seperti yang dilakukan oleh `cin >>`.

### Kegunaan Utama `getline`

1. **Membaca Kalimat atau Baris Penuh**  
    `getline` sangat berguna untuk menangkap seluruh baris teks yang mengandung spasi, sehingga cocok untuk input kalimat atau paragraf, bukan hanya satu kata.
    
2. **Menghindari Pemisahan Input Berdasarkan Spasi**  
    Tidak seperti `cin >>` yang hanya membaca satu kata pertama dan berhenti di spasi, `getline` menangkap semuanya hingga akhir baris atau karakter newline. Ini menjadikannya pilihan utama ketika kita menginginkan input yang utuh dalam satu variabel string.
    
3. **Membaca Input yang Dapat Mengandung Karakter Khusus**  
    `getline` dapat membaca berbagai karakter dalam satu baris, termasuk spasi, tab, dan simbol khusus. Hal ini sangat berguna saat menangani input yang berisi kalimat dengan tanda baca atau karakter non-alfabet lainnya.
    
### Kasus-Kasus Penggunaan `getline`:

1. **Input Nama Lengkap**: Ketika pengguna diminta memasukkan nama lengkap, `getline` akan menangkap seluruh nama tanpa terpotong.
    
2. **Input Alamat**: Untuk alamat atau baris teks panjang yang mengandung spasi, `getline` memastikan input yang lengkap.
    
3. **Input Deskripsi atau Paragraf**: Jika program memerlukan deskripsi panjang atau masukan dalam bentuk paragraf, `getline` adalah fungsi yang tepat.
    
### Catatan Penting

Jika `getline` digunakan setelah `cin >>`, biasanya kita perlu menggunakan `cin.ignore()` atau `cin >> ws` untuk membersihkan newline (`\n`) yang tertinggal di buffer, agar `getline` tidak langsung berhenti pada input kosong.

Contoh:

```cpp
#include<iostream>
using namespace std;

int main(){
    
    int nim;
    string nama;
    
    cout << "Masukan NIM: ";
    cin >> nim;
    cout << "Masukan nama: ";
    getline(cin,nama);
    
    cout << nim;
    cout << nama;
    return 0;
}
```

Ketika kita menggunakan kode program diatas, penggunaan `getline()` sudah tepat, karena kita menggunakan syntax tersebut untuk menampung nama yang mengandung spasi. Tapi ketika dijalankan, maka akan terjadi error, dimana user tidak akan bisa memasukan nama, dan program langsung berhenti.

Ini disebabkan, karena dalam C++, setelah menggunakan `cin >>` untuk membaca integer atau double, ada karakter newline yang tersisa di buffer input. Ketika `getline` langsung digunakan setelah itu, dia malah membaca karakter newline tersebut sebagai input.

**Apa maksudnya "tertinggal di buffer" ?**

"**Tertinggal di buffer**" mengacu pada kondisi di mana karakter (seperti `\n` atau newline) masih ada di **input buffer** (penyimpanan sementara untuk data yang dimasukkan oleh pengguna) setelah operasi input tertentu. Karakter tersebut belum diambil atau diproses oleh program, sehingga tetap ada di buffer input.
#### Contoh Penjelasan

Ketika kita menggunakan `cin >>`, misalnya, untuk membaca angka atau kata, `cin` hanya mengambil data yang diperlukan (misalnya, angka atau satu kata) dan berhenti ketika menemui karakter pemisah seperti spasi atau newline. Namun, karakter newline (`\n`) atau spasi yang muncul setelah input utama tidak diambil oleh `cin >>` dan tetap tertinggal di buffer.
#### Contoh Kode

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    int angka;
    string kalimat;

    cout << "Masukkan angka: ";
    cin >> angka;   // Membaca angka, tetapi tidak mengambil newline

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat); // Mengambil input hingga newline, tapi newline ada di buffer

    cout << "Angka: " << angka << endl;
    cout << "Kalimat: " << kalimat << endl;

    return 0;
}
```

Contoh input:

```
123
Ini adalah contoh kalimat.
```

Maka outputnya:

```
Masukkan angka: 123
Masukkan kalimat: Angka: 123
Kalimat: 
```

Di sini, `kalimat` tampak kosong karena `getline` langsung membaca newline (`\n`) yang tertinggal di buffer setelah `cin >> angka;`. Seharusnya `getline` mengambil kalimat, tapi malah menangkap newline dari buffer, sehingga input kalimatnya dilewati.
### Mengatasi Masalah Karakter Tertinggal di Buffer

Untuk mengatasi masalah ini, kita dapat menggunakan:

1. **`cin.ignore()`**: Mengabaikan karakter yang tersisa di buffer, misalnya `\n`.
2. **`cin >> ws`**: Mengabaikan semua karakter whitespace di buffer, termasuk spasi, tab, dan newline.

Contoh penggunaan solusi pertama:

```cpp
cin >> angka;

cin.igonre(); // Abaikan newline
getline(cin,kalimat);
```

Contoh penggunaan solusi kedua:

```cpp
cin >> angka;

getline(cin >> ws, kalimat);
```

## 2.7 Mengatasi inputan berulang

Jika jumlah data tidak diketahui, loop berikut berguna:

```cpp
while (cin >> x) {
    // kode
}
```

Loop ini membaca elemen-elemen dari input satu per satu, hingga tidak ada lagi data yang tersedia di input.

Atau lebih lengkapnya, Loop `while (cin >> x)` membaca input **satu per satu** hingga tidak ada lagi data yang tersedia. Ini berguna dalam kasus **jumlah data tidak diketahui sebelumnya**, misalnya saat membaca hingga _EOF_ (End of File).

Contoh penggunaan, memasukan elemen vector:

```cpp
#include <iostream>
using namespace std;

int main() {
    vector<int> arr; 
    int x;

	// Terus membaca input sampai EOF atau input invalid
    while (cin >> x) { 
        arr.push_back(x);
    }

	// Output hasil 
	cout << "Array yang dimasukkan:\n"; 
	for (int num : arr) { 
	cout << num << " "; 
	} 
	
	cout << "\n";
	
    return 0;
}
```

💡 **Cara menghentikan input:**

- **Linux/macOS:** Tekan `Ctrl+D` (End of File)
- **Windows:** Tekan `Ctrl+Z` lalu `Enter`

Selain menggunakan `while(cin >> x)`, ada beberapa cara lain untuk membaca input dengan jumlah tidak diketahui. Dan ada juga beberapa tips lain yang perlu diketahui untuk mempermudah proses ini:

### 1️⃣ Menggunakan `istream_iterator` (C++ STL)

Jika ingin membaca seluruh input sekaligus ke dalam `vector`, bisa pakai `istream_iterator`:

```cpp
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    vector<int> data((istream_iterator<int>(cin)), istream_iterator<int>());

    for (int x : data) {
        cout << x << "\n";
    }
    return 0;
}
```

**Keuntungan:** 

- ✅ Lebih pendek, langsung menyimpan semua input ke dalam `vector`.  
- ✅ Berguna jika ingin memproses seluruh data setelah membaca.  
- ❌ Tidak fleksibel jika harus memproses data satu per satu.

### 2️⃣ Menggunakan `getline` untuk membaca per baris

Jika input terdiri dari banyak baris dan ingin membacanya sebagai string:

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) { // Membaca seluruh baris
        cout << "Baris: " << line << "\n";
    }
    return 0;
}
```

**Keuntungan:** 

- ✅ Cocok jika input memiliki format teks bebas.  
- ✅ Bisa digunakan untuk parsing lebih lanjut (misalnya `stringstream`).

### 3️⃣ Menggunakan `istringstream` untuk memasukan kata ke vector

Jika setiap masukan yang dipisahkan oleh spasi ingin dimasukkan ke dalam `vector<string>`, kamu bisa menggunakan **`istringstream`** dari `<sstream>` untuk memisahkan kata-kata dalam satu baris input:

```cpp
#include <iostream>
#include <sstream>  // Untuk istringstream
#include <vector>
#include <string>
using namespace std;

int main() {
    
    string line, word;
    vector<string> words;     // Menyimpan kata-kata dari baris
   
    while (getline(cin, line)) {  // Membaca seluruh baris
        istringstream iss(line);  // Membantu memecah string berdasarkan spasi
        
        while (iss >> word) {     // Ambil setiap kata
            words.push_back(word);
        }
    }

    // Output hasilnya
    cout << "Isi vector words: ";
    for (const string &w : words) {
        cout << "[" << w << "] ";
    }
    cout << "\n";
    
    return 0;
}
```

#### 🔍 Cara Kerja Kode

- **`getline(cin, line)`** → Membaca satu baris penuh dari input.
- **`istringstream iss(line)`** → Membuat stream dari string untuk diproses kata per kata.
- **`while (iss >> word)`** → Mengambil setiap kata yang dipisahkan oleh spasi.
- **`words.push_back(word)`** → Menyimpan kata-kata ke dalam `vector<string>`.
- **Mencetak hasilnya** → Menampilkan setiap kata yang telah dipisahkan.

### 4️⃣ Alternatif: Memasukan jumlah elemen di awal
Kita juga bisa membuat inputan berulang, dengan pertama-tama meminta user meminta banyaknya elemen dalam array atau vector yang akan dibuat, dengan membaca angka semisal `n` yang diinputkan user:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> arr (n) // (n) adalah ukuran vector

	for(int& x:arr) cin >> x; // perulangan for-each
	
	return 0;
}
```

**Kelebihan:** 
- ✅ Tidak perlu `Ctrl+D`/`Ctrl+Z` untuk berhenti.  
- ✅ Lebih terstruktur, user tahu berapa banyak elemen yang harus dimasukkan.

### 5️⃣ Menggunakan perulangan `for` biasa vs `for-each`

Jika belum tahu, ini materinya: [[For-each loop]].

Jika perulangan `while` digunakan untuk mengatasi inputan yang jumlahnya tidak ditentukan, maka perulangan seperti `for` dan `for-each` lebih cocok digunakan untuk mengatasi inputan yang sudah ditentukan batasnya. 

Jika inputan dibatasi sampai $n$ kali, maka kita bisa  menggunakan dua perulangan ini. Berikut penjelasanya:

#### Perbedaan keduanya

Perulangan `for` bisa digunakan untuk mengisi elemen vector, dan menampilkan isi vector seperti kasus  berikut:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n;
    vector<int> arr;

    for(int i=0; i<n; i++){
        cin >> x;
        arr.push_back(x);
    }

    for(int i=0; i<n; i++){
	    cout << arr[i] << " ";
    }

    return 0;
}
```

Jika kita menggunakan `for-each` hal ini tidak bisa dilakukan. `for-each loop` hanya bisa digunakan **jika elemen-elemen sudah ada di dalam container** (`vector`, `array`, `set`, dll.).

Jika kita mencoba melakukan ini:

```cpp
vector<int> arr;
for (int num : arr) {  // ❌ ERROR! arr masih kosong
    cin >> num;
}
```

Maka tidak akan berhasil karena `arr` masih kosong dan `for-each` tidak bisa menentukan jumlah iterasi.

Sehingga, kita perlu mengalokasikan ukuran vector dengan `n` elemen. Dengan sedikit memodisikasi kodenya menjadi seperti ini:

```cpp
vector<int> arr(n);  // ✅ Vector langsung dialokasikan dengan ukuran n
for (int &x : arr) cin >> x;  // ✅ Menggunakan reference untuk mengisi elemen
```

Sehingga, dengan kasus yang sama, kita bisa membuat perulangan lebih ringkas dengan perulangan `for-each`:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n); // Alokasikan ukuran vector 

	for(int& x : arr) cin >> x;

	for(int& x : arr) cout << x << " "; 

    return 0;
}
```

Perulangan `for-each` juga jauh lebih ringkas jika dibandingkan perulangan biasa. Sangat cocok digunakan untuk CP. Namun tetap harus menyesuaikan kebutuhan dan kasus yang ada.

Kesimpulanya, untuk melakukan inputan, kedua perulangan ini bisa digunakan, dengan catatan bahwa ukuran vector atau array yang akan diisi elemenya sudah dialokasikan. Jika belum, maka hanya perulangan `for` yang bekerja. 

Sedangkan untuk output, jika ingin menampilkan semua elemen dalam array, maka bisa digunakan `for-each` langsung, karena perulangan ini menampilkan semuanya sekaligus. 

#### Kesimpulan

**✅ Gunakan perulangan biasa (`for i`) jika:**

- Perlu **mengakses indeks** elemen
- Perlu **mengubah elemen** tanpa harus menggunakan referensi
- Perlu iterasi dengan langkah selain `+1` (misalnya `i += 2`)
- Memerlukan fleksibilitas dalam kontrol iterasi

✅ **Gunakan perulangan `for-each` jika:**

- **Hanya membaca** elemen tanpa perlu indeks
- **Ingin kode lebih singkat & aman dari error indeks**
- **Iterasi elemen dalam `vector`, `set`, `map`**, terutama saat indeks tidak diperlukan

⚠️ **Catatan:**

- Jika ingin **mengubah elemen** dalam `for-each`, gunakan **referensi (`&`)** agar nilai aslinya bisa diubah.
- **For-each tidak bisa digunakan jika membutuhkan akses langsung ke indeks.**

## 2.8 Input/Output pada file terpisah (`freopen`)

Dalam beberapa sistem kontes, **input dan output** tidak selalu menggunakan **stdin** (`cin`) dan **stdout** (`cout`) secara langsung, tetapi melalui **file input dan output**.

Salah satu cara untuk menangani ini adalah dengan menggunakan fungsi **`freopen`**, yang mengarahkan **stdin dan stdout** ke file tertentu.

### Cara Kerja `freopen`

Jika kita menambahkan dua baris berikut di awal program:

```cpp
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

Maka:

- **`freopen("input.txt", "r", stdin);`**  
    ➝ Membuka file `"input.txt"` sebagai **sumber input**. Semua operasi `cin` akan membaca dari file ini, bukan dari keyboard.
    
- **`freopen("output.txt", "w", stdout);`**  
    ➝ Membuka file `"output.txt"` sebagai **tempat output**. Semua operasi `cout` akan menulis ke file ini, bukan ke layar.
    

### Keuntungan `freopen`

1. **Mudah untuk debugging**  
    ➝ Kita bisa membuat **file input** sendiri dan melihat hasilnya di **file output** dengan lebih rapi.
2. **Memudahkan pengujian lokal**  
    ➝ Tidak perlu mengetik ulang input berulang kali di terminal saat menguji kode.
3. **Sesuai dengan beberapa sistem kontes**  
    ➝ Beberapa sistem lomba menggunakan file input/output, jadi kode kita langsung kompatibel.

### Contoh Program

Misalkan kita memiliki file **`input.txt`** berisi:

```
5
10 20 30 40 50
```

Dan kita ingin membaca `n` angka lalu mencetak jumlahnya ke **`output.txt`**.

#### Kode dengan `freopen`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    for (int x : arr) sum += x;

    cout << "Total: " << sum << "\n";
    return 0;
}
```

#### Hasil di `output.txt`

```
Total: 150
```

Program ini membaca data dari **`input.txt`** dan menulis hasilnya ke **`output.txt`**.

### Kekurangan `freopen`

1. **Tidak bisa digunakan di sistem interaktif**  
    ➝ Jika soal membutuhkan komunikasi langsung dengan sistem, `freopen` tidak bisa digunakan.
2. **Harus memastikan file tersedia**  
    ➝ Jika file `input.txt` tidak ada, program bisa gagal membaca input.

### Kesimpulan

✅ Gunakan `freopen` jika soal menggunakan file input/output.  
✅ Bermanfaat untuk pengujian lokal sebelum submit ke sistem kontes.  
❌ Jangan gunakan jika soal bersifat interaktif atau sistem kontes tidak memerlukannya.