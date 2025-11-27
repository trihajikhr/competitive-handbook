---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 208A
judul_DEATH: Dubstep
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips:
date_learned: 2025-11-27T20:53:00
tags:
  - strings
---
Sumber: [Problem - 208A - Codeforces](https://codeforces.com/problemset/problem/208/A)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 208A-Dubstep

Diberikan sebuah string $s$. String ini diberikan dengan terdapat string asli yang tercampur dengan substring `WUB`. Hapus substring `WUB` ini dan outputkan string asli $s$.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Mudah, kita hanya perlu mendeteksi keberadaan substring `WUB`, lalu lakukan penghapusan pada substring tersebut, atau secara simple melompati bagian substring tersebut, sehingga hanya mengoutputkan string asli yang diberikan.

Cara yang bisa digunakan ada banyak, mulai dari melakukan penghapusan secara langsung, melompati, atau dengan menggunakan cara yang lebih advance.

Berikut adalah beberapa cara yang aku gunakan, dan berhasil. Misal menggunakan penghapusan dengan `erase()`, atau `replace()`.

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

Dengan menggunakan fungsi `regex_replace()`:

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

Atau melompati secara langsung:

```cpp
#include<iostream>
#include<string>
using namespace std;
 
auto main() -> int {
    string s;
    cin >> s;
    while (true) {
        int idx = s.find("WUB");
        if (idx != -1) {
            for (int i=idx; i<idx+3; i++) {
                s[i] = ' ';
            }
        } else break;
    }
    cout << s;
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Masalah ini bersifat teknis. Pertama, Anda harus menghapus semua kemunculan kata WUB di awal dan di akhir _string_. Dan kemudian, uraikan (_parse_) _string_ yang tersisa dengan memisahkan token berdasarkan kata WUB. Token kosong juga harus dihapus. _String_ yang diberikan relatif kecil, Anda dapat mengimplementasikan algoritma dengan cara apa pun.
## 3.2 | Analisis Pribadi

Soal ini memperbolehkan banyak implementasi algoritma, jadi tidak perlu dipusingkan, dan pastinya beberapa jawabanku diatas sudah benar.
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

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

Menggunakan fungsi `regex_replace()`, kuat namun sedikit lambat. Gunakan dengan bijak.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string s;
	cin>>s;
	string ans ;
	ans = regex_replace(s,regex("WUB")," ");
	cout<<ans<<endl;

}
```
### 3 | Jawaban Ketiga

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
        else {
            flag = 0;
            cout << s[i];
        }
    }
}
```

Cara manual, namun lebih cepat secara eksekusi, karena tidak perlu memanggil dan mengeksekusi fungsi dari header `regex` yang berat.