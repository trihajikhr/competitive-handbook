---
obsidianUIMode: 
note_type: Book Theory
judul_materi: Input & Output
sumber:
  - USACO guide
date_learned: 2025-07-18T23:22:00
tags:
  - general-usaco
  - input-output
---
Link Sumber: 


```cardlink
url: https://usaco.guide/general/input-output?lang=cpp#standard-io
title: "Input & Output"
description: "How to read input and print output for USACO contests."
host: usaco.guide
favicon: https://usaco.guide/favicon-32x32.png?v=486b7e9b938c7be5463018a5e8da37f8
image: https://usaco.guide/static/2863837723a7041cb58da9f7856ce0fb/0ff54/social-media-image.jpg
```


---
# Input & Output


> [!NOTE] Resource
> - [ ] [2.1 - Input and Output](https://darrenyao.com/usacobook/cpp.pdf#page=10) -> modul di pembahasan ini
> - [ ] [1.2 - Input and Output](https://usaco.guide/CPH.pdf#page=14) -> cin, getline, files
> - [ ] [2.4 - Input and Output](https://usaco.guide/PAPS.pdf#page=41) -> cin, getline


---
## Standard I/O

Pada sebagian besar situs (seperti Codeforces dan CSES), serta pada soal-soal USACO setelah Desember 2020, input dan output menggunakan standar input/output.

### Method 1 - [`<iostream>`](https://www.cplusplus.com/reference/iostream/)

Lebih mudah digunakan. Pemanggilan operator ekstraksi `operator>>` pada `cin` akan membaca data yang dipisahkan oleh spasi dari _standard input_. Begitu juga, pemanggilan operator penyisipan `operator<<` pada `cout` akan menulis ke _standard output_. Urutan pelolosan `\n` merepresentasikan baris baru.

```cpp
#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	int c;
	cin >> a >> b >> c;
	// "\n" can be replaced with endl as well
	cout << "The sum of these three numbers is " << a + b + c << "\n";
}
```

> `endl` dan `\n` tidaklah sama, walaupun sama-sama mencetak baris baru. Hal ini akan dibahas di pembahasan Fast I/O

### Method 2 - [`<cstdio>`](https://www.cplusplus.com/reference/cstdio/)
Library ini mencakup fungsi `scanf` dan `printf`, yang sedikit lebih rumit untuk digunakan.

```cpp
#include <cstdio>
using namespace std;

int main() {
	int a;
	int b;
	int c;
	/*
	 * %d menunjukkan bahwa nilai bertipe int sedang diinput.
	 * Untuk menginput bilangan 64-bit (long long),
	 * gunakan %lld sebagai gantinya (beberapa Online Judge mungkin perlu %I64).
	 * Banyak spesifier lain juga tersedia; lihat tautan untuk detail lebih lanjut.
	 *
	 * Pastikan menambahkan karakter & (operator address-of) saat
	 * menggunakan scanf, KECUALI saat menginput string dengan %s.
	 *
	 * Kita bisa menginput beberapa nilai sekaligus seperti di bawah ini.
	 */
	scanf("%d %d %d", &a, &b, &c);

	/*
	 * Spesifier untuk printf sebagian besar sama seperti
	 * yang digunakan oleh scanf, kecuali untuk angka desimal.
	 * Gunakan karakter backslash diikuti huruf kecil n
	 * untuk mencetak baris baru (\n).
	 * Operator address-of (&) tidak digunakan di sini.
	 */
	printf("Jumlah dari ketiga angka tersebut adalah %d\n", a + b + c);
}
```

> [!NOTE] Kecepatan Input  
Metode kedua (_`scanf`/`printf`_) secara signifikan lebih cepat (biasanya hanya menjadi masalah saat ukuran input sangat besar). Namun, metode pertama (_`cin`/`cout`_) juga bisa dipercepat sehingga perbedaan kecepatannya tidak terlalu signifikan; lihat bagian _Fast I/O_ untuk detailnya.

## Example Problem - Weird Algorithm

Coba kerjakan problem [Weird Algorithm](https://cses.fi/problemset/task/1068)
 
 > [!NOTE] Resource
 > [1.3 - CSES Problem Set](https://link.springer.com/book/10.1007/978-3-319-72547-5) -> Contoh solusi C++ untuk masalah ini. 

## Solution - Weird Algorithm
Berikut adalah solusinya:

```cpp
#include <iostream>
using namespace std;

int main() {
	long long x;
	cin >> x;
	while (x != 1) {
		cout << x << " ";
		if (x % 2 == 0) {
			x /= 2;
		} else {
			x = 3 * x + 1;
		}
	}
	cout << x << endl;
}
```

⚠️ Warning!
Seperti yang disebutkan dalam sumber di atas, soal ini memerlukan penggunaan bilangan integer 64-bit. Solusi berikut, yang menggunakan `int` alih-alih `long long`, tidak berhasil lolos semua test case.

```cpp
#include <iostream>
using namespace std;

int main() {
	int x;
	cin >> x;
	while (x != 1) {
		cout << x << " ";
		if (x % 2 == 0) {
			x /= 2;
		} else {
			x = 3 * x + 1;
		}
	}
	cout << x << endl;
}
```

Hal ini terjadi karena angka-angka dalam urutan tersebut bisa melebihi batas maksimum tipe data `int` ($2^{31} - 1$, seperti yang telah dijelaskan di modul prasyarat).
### How to Submit Your Solution

> [!NOTE] Pemilihan IDE
> Dalam bagian ini diasumsikan bahwa kamu menggunakan [IDE online](https://usaco.guide/general/running-code-online), seperti [USACO Guide IDE](https://ide.usaco.guide/). Petunjuk untuk menggunakan [IDE lokal](https://usaco.guide/general/running-code-locally) kurang lebih sama, kecuali kamu tidak perlu melakukan langkah unduh.

Berikut langkah-langkah untuk melakukan submit di CSES. Proses submit di platform lain (seperti USACO) serupa:

1. Jalankan kode solusi-mu dengan input sampel, dan pastikan hasil output-nya sesuai dengan output sampel.
2. Unduh kode solusi ke dalam sebuah file. Ekstensi file harus berupa `.cpp`, `.java`, `.py`, atau sejenisnya tergantung bahasa pemrograman yang kamu gunakan.
3. Buka halaman soal. Login jika kamu belum login.
4. Tekan tab Submit (untuk USACO, scroll ke bagian bawah halaman).
5. Unggah file solusi-mu.
    
    - Di CSES, jika ekstensi file sudah benar, bahasa pemrograman akan terdeteksi otomatis.
        
    - Di USACO, kamu harus memilih bahasanya secara manual.
        
    - Beberapa platform lain (seperti Codeforces) juga memungkinkan kamu untuk langsung paste kode ke dalam text box, alih-alih mengunggah file.
        
6. Submit solusi-mu.
    
    - Di CSES, kamu akan langsung diarahkan ke halaman hasil.
        
    - Di USACO, hasil akan muncul di bagian atas halaman.
        
    - Jika semua test case lolos, berarti kamu sudah selesai! Jika belum, perbaiki kode-mu dan ulangi dari langkah 1.
        

> [!NOTE] Submit ke Soal USACO Sebelumnya
Jika kamu menggunakan [USACO Guide IDE](https://ide.usaco.guide/), kamu bisa submit ke soal-soal USACO lama melalui sana:  Settings → Judge.Fitur ini tidak bisa digunakan untuk melakukan submit saat kontes live.
## File I/O

Soal-soal USACO dari Desember 2020 dan seterusnya menggunakan input/output standar. Namun, kamu tetap perlu menggunakan file I/O untuk mengumpulkan (submit) jawaban ke soal-soal yang lebih lama.

Pada soal-soal USACO yang lebih lama, nama file input dan output sudah ditentukan dan mengikuti format `namasoal.in`. Setelah program dijalankan, output harus dituliskan ke dalam file bernama `namasoal.out`.

Ulas problem berikut: [Fence Painting](http://www.usaco.org/index.php?page=viewproblem2&cpid=567)

Kamu **harus menggunakan nama file yang benar** saat membuka file `.in` dan `.out`, sesuai dengan soal. Nama file tersebut akan dicantumkan di soal-soal USACO yang membutuhkan file I/O. Sebagai contoh, untuk soal _paint_, kamu harus membuka file **`paint.in`** untuk input dan menuliskan hasil ke **`paint.out`**.

### Method 1 - [`freopen`](https://www.cplusplus.com/reference/cstdio/freopen/)
Kamu akan membutuhkan pustaka `<cstdio>`. Pernyataan `freopen` digunakan untuk mengalihkan I/O standar menjadi I/O file. Setelah itu, kamu bisa tetap menggunakan `cin` dan `cout` (atau `scanf` dan `printf`) seperti biasa untuk membaca dan menulis data.

```cpp
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	// Membuka file input bernama "problemname.in" untuk dibaca
	freopen("problemname.in", "r", stdin);
	// Baris berikut membuat/mengganti file output
	freopen("problemname.out", "w", stdout);

	// cin sekarang membaca dari file input, bukan dari input standar (keyboard)
	int a;
	int b;
	int c;
	cin >> a >> b >> c;

	// cout sekarang menulis ke file output, bukan ke output standar (layar)
	cout << "Jumlah dari ketiga bilangan ini adalah " << a + b + c << "\n";
}
```

Keterangan tambahan:

- `"r"` artinya mode baca (read),
    
- `"w"` artinya mode tulis (write), dan akan menimpa file jika sudah ada.

Untuk menguji solusi kamu secara lokal **tanpa menggunakan file I/O**, cukup beri komentar (`//`) pada baris-baris yang menggunakan `freopen`.

Agar lebih praktis, kita bisa mendefinisikan fungsi untuk mengatur ulang `stdin` dan `stdout` berdasarkan nama soal, seperti ini:

```cpp
void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);   // Buka file input
    freopen((name + ".out").c_str(), "w", stdout); // Buka file output
}
```

Contoh penggunaannya di dalam `main()`:

```cpp
int main() {
    setIO("problemname"); // Ganti "problemname" dengan nama file sesuai soal
    // Lanjutkan program...
}
```

Dengan pendekatan ini, kamu cukup ganti `"problemname"` dengan nama file input/output sesuai soal USACO tanpa menulis ulang `freopen` berkali-kali. Contoh lengkap:

```cpp
#include <cstdio>
#include <iostream>
using namespace std;

// the argument is the input filename without the extension
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
	setIO("problemname");
	int a;
	int b;
	int c;
	cin >> a >> b >> c;
	cout << "The sum of these three numbers is " << a + b + c << "\n";
}
```

### Method 2 - [`<fstream>`](https://www.cplusplus.com/reference/fstream/)

Kamu tidak bisa menggunakan I/O gaya C (`scanf`, `printf`) dengan metode ini.

```cpp
#include <fstream>
using namespace std;

int main() {
	ifstream fin("problemname.in");
	ofstream fout("problemname.out");

	int a;
	int b;
	int c;
	fin >> a >> b >> c;
	fout << "The sum of these three numbers is " << a + b + c << "\n";
}
```

## Example Solution - Fence Painting

Coba kerjakan problem berikut: [Technical Specifications for Contests](http://www.usaco.org/index.php?page=instructions)

### Method 1 - `freopen`

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Use standard input to read from "paint.in"
	freopen("paint.in", "r", stdin);
	// Use standard output to write to "paint.out"
	freopen("paint.out", "w", stdout);

	vector<bool> cover(100);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = a; i < b; i++) { cover[i] = true; }
	for (int i = c; i < d; i++) { cover[i] = true; }

	int ans = 0;
	for (int i = 0; i < cover.size(); i++) { ans += cover[i]; }
	cout << ans << endl;
}
```

### Method 2 - `<fstream>`

```cpp
#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream fin("paint.in");
	ofstream fout("paint.out");

	vector<bool> cover(100);
	int a, b, c, d;
	fin >> a >> b >> c >> d;
	for (int i = a; i < b; i++) { cover[i] = true; }
	for (int i = c; i < d; i++) { cover[i] = true; }

	int ans = 0;
	for (int i = 0; i < cover.size(); i++) { ans += cover[i]; }
	fout << ans << endl;
}
```

## USACO Note - Extra Whitespace
Penting: USACO secara otomatis akan menambahkan newline (baris baru) di akhir file output kamu jika belum ada di sana.

 > [!NOTE] ⚠️ Peringatan!
 > Kadang-kadang, pada awal jendela kontes, model output yang diberikan tidak diakhiri dengan newline, yang membuat soal menjadi tidak dapat diselesaikan.

Hati-hati juga! Jangan mencetak spasi di akhir baris output, karena hal itu akan menyebabkan error seperti berikut:  

_(misalnya: “Wrong answer due to trailing whitespace”)_

![[Input & Output-1.png]]

Berikut beberapa contoh tentang apa yang diizinkan dan apa yang tidak diizinkan ketika output yang dimaksud adalah sebuah bilangan bulat tunggal `ans`:


```cpp
cout << ans;            // OK, no newline
cout << ans << endl;    // OK, newline
cout << ans << "\n";    // OK, newline
cout << ans << " ";     // NOT OK, extra space
cout << ans << "\n\n";  // NOT OK, extra newline
```
