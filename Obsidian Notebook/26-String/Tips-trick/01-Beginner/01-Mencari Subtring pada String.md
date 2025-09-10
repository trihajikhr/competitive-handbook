---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Mencari Subtring pada String
sumber:
  - chatgpt.com
  - google.com
  - codeforces.com
date_learned: 2025-09-09T20:37:00
tags:
  - string
  - tips-trick
---
Link Sumber: 

---
# 1 | Penggunaan `string::npos` dan `find`

Jika ada soal yang meminta kita menentukan, apakah pada string $a$ terdapat substring $b$, lalu mengoutputkan `YES` jika ada dan `NO` jika tidak, maka kita bisa menggunakan fungsi string `find()` dengan `string::npos`.

Amati soal Codeforces berikut: [96A - Football](https://codeforces.com/problemset/problem/96/A)

Inti dari soal ini adalah menentukan, apakah ada karakter 0 atau 1 yang memiliki kemunculan berurutan sebanyak lebih atau sama dengan 7. Jika ada maka outputkan `YES`, jika tidak maka `NO`.

Solusinya mudah, kita cukup menerima inputan sebagai string, bukan sebagai bilangan bulat. Lalu jika semisal kita tidak menggunakan `find()` dan `string::npos`, mungkin kita akan melakukan perhitungan manual dengan cara seperti berikut (cara pertamaku haha...):

```cpp
#include <iostream>
#include <string>
using namespace std;

auto main() -> int {
    string s;
    cin >> s;
    int one = 0;
    int zer = 0;
    for (char c : s) {
        if (c == '0') {
            zer++;
            one = 0;
        } else if (c == '1') {
            one++;
            zer = 0;
        }

        if (one == 7 || zer == 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
```

Solusi diatas cukup sederhana, mudah dilihat bagaimana alurnya bekerja. Baca string, lalu deklarasikan 2 variabel counter kemunculan angka 1 dan 0. Lakukan traversal, dan jika ada salah satu angka yang telah muncul 7 kali, outputkan `YES` dan hentikan program dengan `return 0;`. Jika hingga akhir tidak ada, maka outputkan `NO`.

Tetapi, ada solusi yang lebih mudah, yaitu menggunakan fungsi `find()` dan `string::npos`.

## 1.1 | Penjelasan

```ad-faq
Apa itu `string::find`
```

Fungsi `find()` adakah fungsi bawaan C++ didalam `std::string` yang digunakan untuk mencari substring didalam string. 

Sintaks paling sederhana:

```cpp
size_t pos = s.find("abc");
```

Katakanlah kita memiliki variabel string `s`, kita mencari apakah ada substring `abc` didalamnya dengan menggunakan fungsi `find()`. 

- Jika substring ditemukan, maka fungsi `find()` akan mengembalikan indeks (posisi) kemunculan pertama dari substring tersebut. Dan kita menampungnya didalam `size_t` (akan dijelaskan dibawah kenapa `size_t` dipilih disini).
<br/>

- Tapi jika tidak, maka `find()` akan mengembalikan nilai khusus yang disebut `string::npos`.

```ad-faq
Apa itu `string::npos`?
```


`npos` adalah konstanta bawaan dari `std::string`. Nilainya biasanya `size_t(-1)` (angka terbesar yang bisa ditampung `size_t`). Dipakai sebagai penanda **“tidak ditemukan”**.

Karena `find` harus selalu mengembalikan nilai bertipe `size_t`, maka tidak bisa mengembalikan `-1` langsung. Jadi disediakanlah `string::npos` sebagai standar.

```ad-faq
Kenapa perlu dibandingkan dengan `string::npos`?
```

Karena:

- Jika `find` menemukan substring, hasilnya adalah indeks (misal `0`, `3`, `15`, dst).
- Jika **tidak ditemukan**, hasilnya adalah `string::npos`.


Jadi cara aman untuk cek apakah substring ada atau tidak:

```cpp
if (s.find("abc") != string::npos) {
    cout << "Substring ditemukan\n";
} else {
    cout << "Tidak ada\n";
}
```

```ad-faq
Oke, jelaskan kenapa harus menggunakan `size_t`
```


`std::string::find` digunakan untuk mencari substring dalam sebuah string.

- Jika substring ditemukan, fungsi ini mengembalikan indeks kemunculan pertama (tipe data `size_t`).
- Jika substring tidak ditemukan, fungsi mengembalikan **`string::npos`**.

Alasan kenapa harus menggunakan `size_t` adalah:

- `size_t` adalah tipe bilangan bulat **unsigned** yang digunakan untuk menyimpan ukuran atau indeks (tidak bisa negatif).
- Indeks string tidak mungkin bernilai negatif, sehingga `size_t` lebih tepat dibanding `int`.
- Biasanya didefinisikan sebagai `unsigned long` atau `unsigned long long` tergantung platform.
- Dipakai untuk menyimpan ukuran dan indeks pada container (array, string, vector, dll).
- `size_t` mampu menampung ukuran string yang sangat besar (hingga miliaran karakter), sedangkan `int` terbatas.
    

Catatan kecil: Jika suatu bilangan bulat didefinisikan sebagai `unsigned`, maka ia tidak dapat menyimpan nilai negatif. Seluruh rentang bit digunakan untuk bilangan non-negatif, sehingga jangkauan nilai positif yang dapat ditampung menjadi dua kali lebih besar dibanding tipe `signed` dengan ukuran bit yang sama.

## 1.2 | Contoh

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string text = "aku suka competitive programming";

    // cari kata "suka"
    size_t pos1 = text.find("suka");
    cout << pos1 << "\n"; // output: 4 (karena 's' ada di index ke-4)

    // cari kata "tidak"
    size_t pos2 = text.find("tidak");
    if (pos2 == string::npos) {
        cout << "tidak ditemukan\n";
    }
}
```

## 1.3 | Ringkasan:

- `string::find` → mencari substring.
- `string::npos` → konstanta khusus, artinya **“tidak ditemukan”**.
- Gunanya untuk bisa cek keberadaan substring dengan `if (s.find(...) != string::npos)`.
- `size_t` -> Cocok digunakan untuk menyimpan data indeks, karena indeks tidak mungkin negatif.

<br/>

---

# 2 | Kode User Lain

## 2.1 | Pertama

Jika melihat ke user lain, mereka memiliki beberapa trik, berikut diantaranya:

```cpp
#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	if(s.find("1111111")+1||s.find("0000000")+1){
		cout<<"YES";}
	else cout<<"NO";
}
```

Ingat kembali bahwa ketika substring tidak ditemukan, maka akan mengembalikan `-1`. Semisal kedua substring di kondisional diatas tidak ditemukan, otomatis keduanya akan mengembalikan `-1`, yang ketika keduanya ditambahkan dengan 1, maka keduanya akan menjadi 0, atau menjadi false.

Ketika false, maka outputkan `NO`, karena artinya tidak ditemukan.

## 2.2 | Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	if(s.find("0000000")==-1 && s.find("1111111")==-1 ){
		cout<<"NO";
	}
	else cout<<"YES";
}
```

User ini justru menggunakan perbandingan AND, mendahulukan kondisi ketika tidak ada substring yang ditemukan dan keduanya mengembalikan `-1`, maka langsung masuk ke blok `NO`. Jika salah satu ditemukan, perbandingan AND akan menjadi false, dan menjalakan blok else, atau menampilkan `YES`.

## 2.3 | Ketiga

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool dangerous = false;
    int count = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
            if (count >= 7) {
                dangerous = true;
                break;
            }
        } else { 
            count = 1;
        }
    }

    if (dangerous) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
```

Kode ini hampir mirip seperti kode pertamaku, tapi disini digunakan hanya satu variabel counter, alih-alih 2. Cara yang digunakan disini adalah mengecek apakah karakter $s[i]==s[i-1]$. Jika iya, maka ada sepasang angka yang sama yang berjejeran. Dan jika ditemukan ada 6 pasang angka berturut-turut dengan digit yang sama, maka outputkan `YES`, karena artinya substring 1111111 atau 0000000 ada pada string.


<br/>

---
# 3 | Kode Alternatif

```ad-warning
Beberapa fungsi yang diperkenalkan disini hanya untuk menambah insight. Pelajari di catatan terpisah!
```
## 3.1 | Fungsi `contains()`

```cpp
#include<iostream>
#include<string>
using namespace std;

auto main() -> int {
	string s;
	getline(cin, s);
	if(s.contains("000000") || s.contains("1111111")){
		cout << "YES"; 
	} else {
		cout << "NO";
	}
	
	return 0;
}
```

Untuk pengguna C++23, atau versi terbaru, bisa menggunakan fungsi yang mengembalikan `true` atau `false`, bukan index, yaitu fungsi `contains`. Tapi penggunaan fungsi ini masih jarang dipakai, karena hanya tersedia C++23, dan banyak user yang masih lebih memilih menggunakan fungsi `find()`.
## 3.2 | Regex (regular expression)

```cpp
#include <iostream>
#include <regex>
using namespace std;

int main() {
    string s; 
    cin >> s;
    if (regex_search(s, regex("0000000|1111111"))) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
```

- ✅ Kelebihan: powerful (bisa ekspresi pola kompleks).
    
- ❌ Kekurangan: lambat, tidak efisien untuk CP.

## 3.3 | Manual loop + counter

Tanpa library, langsung scanning (jawaban pertamaku):

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; 
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (char c : s) {
        if (c == '0') {
            cnt0++;
            cnt1 = 0;
        } else {
            cnt1++;
            cnt0 = 0;
        }
        if (cnt0 >= 7 || cnt1 >= 7) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
```

- ✅ Kelebihan: cepat, O(n), aman untuk kontes.
- ❌ Kekurangan: lebih panjang daripada `find`/`contains`.
## 3.4 | Fungsi C klasik (`strstr`)

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char s[105]; 
    cin >> s;
    if (strstr(s, "0000000") || strstr(s, "1111111")) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
```

- ✅ Singkat.
- ❌ Gaya C, kurang idiomatik C++.

## 3.5 | Algoritma STL (`search`)

```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s; 
    cin >> s;
    string seven0(7, '0');
    string seven1(7, '1');
    if (search(s.begin(), s.end(), seven0.begin(), seven0.end()) != s.end() ||
        search(s.begin(), s.end(), seven1.begin(), seven1.end()) != s.end()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
```

- ✅ STL murni, lebih “algorithmic”.
- ❌ Agak verbose.

## 3.6 | Jadi, pilihan terbaik buat CP:

- Paling singkat → `find` / `contains`.
- Paling cepat & fleksibel → manual loop.
- Paling formal STL → `search`.
- Paling jarang dipakai → regex (overkill), strstr (C-style).
