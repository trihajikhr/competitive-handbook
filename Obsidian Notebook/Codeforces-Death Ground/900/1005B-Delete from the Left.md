---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1005B
judul_DEATH: Delete from the Left
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-15T11:45:00
tags:
---
Sumber: [Problem - 1005B - Codeforces](https://codeforces.com/problemset/problem/1005/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1005B-Delete from the Left

Diberikan sebuah string $s$ dan $t$. Kita diharuskan membuat string $s$ dan $t$ sama, dengan cara menghapus seminimal mungkin karakter dari kiri ke kanan. Outputkan total karakter yang kita hapus ketika melakukan operasi ini.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Karena penghapusan dari kiri, maka string $s$ dan $t$ hanya mungkin untuk sama (*equal*), jika karakter-karakter paling kanannya juga sama, karena kita hanya bisa menghapus karakter dari kiri, bukan mengurutkan kembali.

Yang perlu kita lakukan adalah membandingkan berapa banyak rentetan karater yang sama diakhir string $s$ dan $t$, misal kita tampung di variabel $ans$, dan hentikan perulangan ketika ada satu karakter saja yang tidak sesuai.

Setelah itu, dapatkan total karakter yang dihapus, dengan cara $s.lenght() + t.length() - (ans*2)$

Berikut implementasiku:

```cpp
#include<iostream>
using namespace std;

auto main() -> int {
    string s, t;
    cin >>s >> t;
    int ans = 0;
    for (int i=0; i<min(s.length(), t.length()); i++) {
        if (s[s.length()-i-1] == t[t.length()-i-1]) ans+=2;
        else break;
    }
    cout << (s.length()+t.length()) - ans;
    return 0;
}
```
```cpp
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita cari nilai $w$ — panjang **suffix persekutuan terpanjang** (*longest common suffix*) dari $s$ dan $t$.

Anda dapat dengan mudah menemukannya dalam satu perulangan (*loop*) linear: cukup bandingkan huruf terakhir dari $s$ dan $t$. Jika keduanya sama, maka bandingkan huruf sebelum huruf terakhir dari $s$ dan $t$. Begitu seterusnya.

$w$ huruf terakhir dari $s$ dan $t$ adalah dua *string* yang sama, yang akan menjadi hasil setelah pergerakan optimal.

Maka, jawabannya adalah $|s|+|t|-2 \cdot w$.

Kode implementasi:

```cpp
#include<iostream>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int w = 0;
	while (true) {
	    int i = s.length() - w - 1;
	    int j = t.length() - w - 1;
	    if (i >= 0 && j >= 0 && s[i] == t[j])
	        w++;
	    else
	        break;
	}
	cout << s.length() + t.length() - 2 * w << endl;
	return 0;
}
```

## 3.2 | Analisis Pribadi

Jika menggunakan fungsi `length()` dirasa terlalu panjang, bisa diakali dengan membuat alias `define` sebagai berikut:
```cpp
#include<iostream>
using namespace std;

#define le length()

auto main() -> int {
    string s, t;
    cin >>s >> t;
    int ans = 0;
    for (int i=0; i<min(s.le, t.le); i++) {
        if (s[s.le-i-1] == t[t.le-i-1]) ans+=2;
        else break;
    }
    cout << (s.le+t.le) - ans;
    return 0;
}

```
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

string s, t;
int i, j, a, b;
main() {
    cin >> s >> t;
    i = s.size();
    j = t.size();
    for (a = i - 1, b = j - 1; i >= 0, j >= 0 && s[i] == t[j]; i--, j--);
    cout << i + j + 2;
}
```

Well, logikanya sama, hanya saja dimuat didalam perulangan langsung. Simple, tapi tidak readable, sulit untuk didebug. Tapi bagus sebagai bahan evaluasi dan eksplorasi.
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
	int nom=0;
	string a,b;
	cin >> a >> b;
	for(int i=1;i<=min(a.size(),b.size());i++){
		if(a[a.size()-i]==b[b.size()-i]) nom++;
		else break;
	}
	cout << a.size()+b.size()-2*nom;
}
```

Solusi yang hampir sama dengan solusiku!
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    //cin >> test;

    while(test--){
        string s,t; cin >> s >> t;
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());

        int answer = s.size()+t.size();
        for(int i=0; i<min(s.size(),t.size()); i++){
            if(s.at(i) == t.at(i)) answer -= 2;
            else break;
        }
        cout << answer << endl;
    }
}  
```

Kedua string di reverse menggunakan `reverse()`. Lalu menggunakan $answer$ sebagai variabel penampung jawaban, dengan pertama-tama mengisinya dengan total panjang dari string $s$ dan $t$. Lalu, dari depan, untuk setiap karakter yang sama, kurangi $answer$ dengan $2$, dan cetak hasilnya.