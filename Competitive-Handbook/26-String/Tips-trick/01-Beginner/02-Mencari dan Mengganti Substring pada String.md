---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Mencari dan Mengganti Substring pada String
sumber:
  - codeforces.com
  - google.com
  - chatgpt.com
date_learned: 2025-09-10T13:39:00
tags:
  - string
  - tips-trick
---
Link Sumber: 

---
# 1 | Mencari dan Mengganti Substring pada String

Diberikan sebuah string `s`, tugasmu adalah mencari semua substring `a` pada string `s`, dan menghapusnya. 

Ada beberapa problem dengan tantangan seperti ini, contohnya adalah problem Codeforces berikut: [Problem - 208A - Codeforces](https://codeforces.com/problemset/problem/208/A)

Inti dari soal ini adalah diberikan sebuah string `s`, dan tugas kita adalah mengembalikan string tersebut dengan terlebih dahulu menghapus semua kemunculan substring `WUB` didalamnya. Misal jika inputan seperti ini:

```
WUBWEWUBAREWUBWUBTHEWUBCHAMPIONSWUBMYWUBFRIENDWUB
```

maka setelah semua substring `WUB` dihapus, hasilnya menjadi seperti ini:

```
WE ARE THE CHAMPIONS MY FRIEND 
```

<br/>

---
# 2 | Jawaban dan Solusi

Berikut akan disajikan solusi yang aku temukan, dan solusi dari orang lain:

## 2.1 | Manual Search

```cpp
#include <iostream>
#include <string>
using namespace std;

auto main() -> int {
    string s;
    getline(cin, s);
    bool first = false;
    for (int i = 0; i < s.length();) {
        if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            for (int j = 0; j < 3; j++) {
                s.erase(i, 1);
            }
            if (first) {
                first = false;
                s.insert(i, " ", 1);
                i++;
            }
        } else {
            first = true;
            i++;
        }
    }

    cout << s;
    return 0;
}
```

Melakukan traversal pada string `s`, dan mencari apakah ada substring `WUB` yang muncul berurutan dengan menggunakan pencarian manual seperti ini:

```cpp
if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {}
```

JIka ada, maka lakukan perulangan sebanyak 3 kali, untuk menghapusnya pada indeks `i`. Karena penggunan fungsi `erase()` akan membuat string dibelakangnya maju kedepan untuk mengisi karakter yang dihapus, maka penggunaan `s.erase(i, 1);` akan aman.

Tapi bisa diperjelas lagi, dengan menggunakan penghapusan langsung 3 karakter ke depan, dengan menggatinya menjadi `s.erase(i, 3);`, sehingga perulangan dirasa tidak perlu.

Karena aku berpikir bahwa setiap kata selain `WUB` harus dirapikan, aku juga memberikan jarak spasi masing-masing satu, tepat ketika ada kata selain `WUB` yang terdeteksi, sehingga jumlah spasinya tetap konsisten.

Mungkin ini peningkatan yang jauh lebih baik setelah aku menganalisisnya sendiri:

```cpp
#include <iostream>
#include <string>
using namespace std;

auto main() -> int {
    string s;
    getline(cin, s);
    bool first = false;
    for (int i = 0; i < s.length();) {
        if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            s.erase(i, 3);
            if (first) {
                first = false;
                s.insert(i, " ", 1);
                i++;
            }
        } else {
            first = true;
            i++;
        }
    }

    cout << s;
    return 0;
}
```

Jawaban-jawaban dengan runtime tercepat untuk permasalahan [Problem - 208A - Codeforces](https://codeforces.com/problemset/problem/208/A), justru kebanyakan menggunakan cara manual. Ini contohnya:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int flag = 1;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
            i += 2;
            if(!flag){
                cout << " ";
            }
        }
        else{
            flag = 0;
            cout << s[i];
        }
    }
}
```

Kode ini mendeteksi lokasi substring `WUB` secara manual, dan menskip bagian tersebut. Kode ini tidak memanipulasi string asli, melainkan hanya menseleksi `WUB` untuk tidak ditampilkan, sedangkan sisanya di outputkan.

Jelas kode ini lebih cepat secara runtime. Hal ini karena penggantian string dengan cara manual, biasanya memiliki overhead yang lebih kecil, mengakibatkan runtime yang lebih cepat. 

Namun untuk kasus yang kompleks, mungkin cara manual seperti ini akan terlalu memakan banyak waktu penulisan, sehingga harus bijak memilih, dan menyesuaikan dengan kondisi.

## 2.2 | Fungsi `regex()`

```cpp
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    cout<<regex_replace(s,regex("WUB")," ");
}
```

Formatter:

```cpp
#include <iostream>
#include <regex>
#include <string>
using namespace std;

auto main() -> int {
    string s;
    getline(cin, s);
    cout << regex_replace(s, regex("WUB"), " ");
    return 0;
}
```

Jauh lebih singkat, dan cepat. 

Untuk bisa menggunakan fungsi-fungsi seperti diatas, harus dipanggil header `regex`. Header `<regex>` di C++ memungkinkan programer untuk menggunakan ekspresi reguler (regex) untuk mencari, mencocokkan, dan memanipulasi pola dalam string teks secara efisien. Pustaka ini memberikan kemampuan yang ampuh untuk memproses teks dengan cara yang kompleks, menggantikan banyak baris kode dengan satu baris pola regex yang kuat. Kegunaan utamanya meliputi validasi input, pencarian teks yang kompleks, dan pemrosesan berkas teks, yang sangat berguna untuk berbagai tugas seperti pengembangan web dan pemrosesan data.

Fungsi `regex_replace()` berguna untuk membuat salinan dari sebuah string di mana semua kecocokan dari sebuah pattern ekspresi reguler (regex) telah diganti dengan string pengganti yang ditentukan. Ini memungkinkan Anda untuk melakukan operasi pencarian dan penggantian yang kompleks pada teks secara efisien, seperti membersihkan data yang tidak teratur, memformat ulang konten, atau memanipulasi string berdasarkan pola tertentu.

Sedangkan fungsi `regex()`, adalah untuk menandai pola yang dicari.

Polanya mungkin seperti ini:

```cpp
std::regex_replace(s, regex_pattern, replacement)
```

- `s` : Variabel string yang akan direplace.
- `regex_pattern` : Fungsi `std::regex_replace` hanya menerima argument bertipe `std::regex` untuk parameter pola. Dia tidak bisa menerima string biasa ("WUB") secara langsung. Pada C++ memang harus explicit dan strict
- `replacement` : String pengganti.

Tapi penggantian substring `WUB` menjadi spasi, akan membuat banyak spasi, yang mungkin akan membuat jarak antar kata terlalu jauh, jadi sesuaikan dengan syarat dari problem statement. Karena jarak antar kata tidak menjadi masalah disini, maka hal itu tidak menjadi masalah. Seperti ini maksudku:

Input:

```
WUBJKDWUBWUBWBIRAQKFWUBWUBYEWUBWUBWUBWVWUBWUB
```

Output:

```
 JKD  WBIRAQKF  YE   WV  
```

Penggunaan `regex()` juga bisa dipakai seperti ini, layaknya variabel, dengan tipe data regex:

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    regex p("WUB");
    cout<<regex_replace(s,p," ");
}
```

## 2.3 | Fungsi `find()` dan `replace()`

```cpp
#include <iostream>
#include <string>
using namespace std;

auto main() -> int {
    string s;
    cin >> s;
    while (s.find("WUB") != -1) {
        s.replace(s.find("WUB"), 3, " ");
    }

    while (s[0] == ' ') {
        s.erase(0, 1);
    }

    cout << s;
    return 0;
}
```

User pemilik kode diatas, memilih menggunakan fungsi `find()` dan `replace()`.

Fungsi `s.find("WUB")` akan mengembalikan indeks pertama kemunculan substring `WUB` dari string `s`. Ketika ditemukan, maka while loop akan bekerja, dan jika tidak ditemukan lagi, mengembalikan `-1`.

Selanjutnya menjalankan:

```cpp
s.replace(s.find("WUB"), 3, " ");
```

Fungsi `replace()` memiliki 3 parameter:

- Parameter pertama adalah indeks dari string, ingin mulai dari indeks ke berapa replace diberlakukan. Disini digunakan fungsi `s.find("WUB")` lagi, yang sebenarnya jadi terlalu boros.
- Parameter kedua, di isi dengan `3`, artinya adalah berapa banyak karakter mulai dari indeks parameter pertama, yang akan digantikan. Karena substring `WUB` hanya punya 3 karakter, maka kita tulis 3.
- Parameter ketiga, adalah string yang akan digunakan untuk menggantikanya. Kita ganti dengan spasi kosong.

Lalu, ada perulangan while seperti ini:

```cpp
while (s[0] == ' ') {
	s.erase(0, 1);
}
```

Berguna untuk menghapus semua spasi kosong diawal kalimat.

Setelah mengamati kode ini, aku memiliki versi ku sendiri untuk menyelesaikan tantangan ini dengan pendekatanku sendiri, yaitu sebagia berikut:

```cpp
#include <iostream>
#include <string>
using namespace std;

auto main() -> int {
    string s;
    cin >> s;
    while (true) {
        auto idx = s.find("WUB");
        if (idx != -1) {
            s.replace(idx, 3, " ");
        } else {
            break;
        }
    }

    while (true) {
        auto idx = s.find("  ");
        if (idx != -1) {
            s.replace(idx, 2, " ");
        } else {
            break;
        }
    }
    
    if (s[0] == ' ') {
        s.erase(0, 1);
    }

    cout << s;
    return 0;
}
```

Alih alih memanggil fungsi `find()` dua kali, lebih baik gunakan pendekatan seperti diatas, break perulangan ketika fungsi `find()` mengembalikan `-1`.

Tapi disini, kita buat lebih rapi lagi, dimana kode diatas akan membersihkan semua spasi berlebih, dan hanya boleh menyisakan satu spasi antar kata yang terpisah. Khusus untuk awal kalimat, digunakan kondisional untuk mengatasi spasi tunggal yang tertinggal:

```cpp
if (s[0] == ' ') {
	s.erase(0, 1);
}
```

Catatan: 
```cpp
s.find("WUB") != -1
```

... itu sama dengan:

```cpp
s.find("WUB") != string::npos
```

## 2.4 | `regex()` dengan `stringstream()`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s, word;
    cin >> s;
    
    s = regex_replace(s,regex("WUB")," ");
    stringstream ss(s); 
    
    while (ss>>word){
        cout<<word<<" ";
    } 
    
    return 0;
}
```

Versi yang lebih readable:

```cpp
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
using namespace std;

auto main() -> int {
    string s;
    string word;
    getline(cin, s);
    s = regex_replace(s, regex("WUB"), " ");

    stringstream ss(s);
    while (ss >> word) {
        cout << word << " ";
    }

    return 0;
}
```

Pencarian dan penggantian masih menggunakan `regex_replace()` dan `regex()`. Tapi penanganan spasi berlebih ditangani oleh `sstream`, dimana setiap kata pada string `s` dipecah atau di parsing dengan menggunakan bantuan while loop, dan ditambah spasi tunggal secara manual, cukup kreatif. Jika paham bagaimana `stringstream`, cara ini cukup bagus untuk digunakan.



<br/>

---
# 3 | Solusi User yang Unik-unik

## 3.1 | Track dan output dengan seleksi

```cpp
#include <iostream>
#include <string>
using namespace std;

auto main() -> int {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        string s = str.substr(i, 3);
        if (s == "WUB") {
            str[i] = str[i + 1] = str[i + 2] = '*';
        }
    }

    bool ok = false;
    for (int i = 0; i < str.size(); i++) {
        if (ok) {
            cout << ' ';
            ok = false;
        }

        if (str[i] != '*') {
            cout << str[i];
        }

        if (str[i] == '*' && str[i - 1] != '*' && i - 1 >= 0) {
            ok = true;
        }
    }
    return 0;
}
```

Substring `WUB` diubah menjadi karakter `*`, lalu di traversal kedua, digunakan untuk menandai bahwa bagian tersebut tidak boleh ditampilkan, diganti dengan satu spasi. Namun masih terlalu verbose, dan kompleksitas kurang efisien

## 3.2 | String Eater

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string a; cin >> a;
    vector<char> arr;

    int i = 0;
    while(size(a) != 0) {
        // cout << a.substr(i, i + 3) << endl;
        if (a.substr(i, i + 3) == "WUB") {
            a = a.substr(i + 3);
            if (!arr.empty() && arr.back() != ' ') {
                arr.push_back(' ');
            } 
        } else {    
            arr.push_back(a[i]);
            a = a.substr(i + 1);
        }
    }

    for(char c: arr) {
        cout << c;
    }
    cout << endl;

    return 0;
}
```

Input string dikonsumsi habis (mirip tokenizing), dengan:

```cpp
a = a.substr(i + 3);
```

Namun terlalu rumit, dan keberadaan vector sebenarnya tidak diperlukan.

## 3.3 | Gabut style

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') || 
        (s[i-1] == 'W' && s[i] == 'U' && s[i+1] == 'B') || 
        (s[i-2] == 'W' && s[i-1] == 'U' && s[i] == 'B')) continue;
        
        cout << s[i];
        
        if (s[i+1] == 'W' && s[i+2] == 'U' && s[i+3] == 'B' 
        && i != s.size()-3) cout << ' ';
    }
    return 0;
}
```

Semua kondisi diperiksa, apakah bisa menemukan keberadaan `WUB`. Kondisi yang dicek bahkan dibuat 3 kali, dengan tujuan sepertinya untuk bisa menskip 3 karakter `WUB` secara berturut-turut dengan `continue`. Tapi ini benar-benar tidak perlu, tujuan dari kode ini, sebenarnya cukup menggunakan kondisional pertama, lalu `i+=2`, bukan `continue`.

Tapi yah..., ini benar-benar tidak perlu, kenapa harus melakukan kondisional hingga 3 kali di percabangan pertama? Kompleksitas masih cepat, O(n), namun overcomplicated, resiko out of bound, dan redundant check di percabangan pertama.

## 3.4 | String bantu

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans;
    for (int i = 0; i < s.size();) {
        if (i+2 < s.size() && s[i]=='W' && s[i+1]=='U' && s[i+2]=='B') {
            if (!ans.empty() && ans.back()!=' ') ans.push_back(' ');
            i += 3;
        } else {
            ans.push_back(s[i]);
            i++;
        }
    }
    cout << ans;
}
```

Apa yang unik disini adalah pada bagian ini:

```cpp
if (!ans.empty() && ans.back()!=' ') ans.push_back(' ');
```

Jadi, ketika ditemukan ada substring `WUB`, maka jika string `ans` sudah memiliki isi didalmnya, dan bagian belakangnya bukan spasi, maka dia akan menambahkan spasi. Tapi jika sudah ada, maka hanya akan melakukan skip. Karakter selain `WUB`, akan langsung ditambahkan ke `ans` dengan menggunakan `push_back()`.

Ini adalah salah satu cara yang cukup menarik untuk merapikan spasi dengan cara yang kreatif