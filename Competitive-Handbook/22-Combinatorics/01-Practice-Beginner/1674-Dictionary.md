---
obsidianUIMode: preview
note_type: STRIKE
kode_soal: "1674"
judul_STRIKE: Dictionary
teori_STRIKE: Trik lexicographical index
sumber:
  - codeforces
ada_tips?: true
date_learned: 2025-08-14T01:31:00
tags:
  - STRIKE
  - combinatorics
---
Sumber: [Problem - 1674B - Codeforces](https://codeforces.com/problemset/problem/1674/B)


```ad-tip
title:⚔️ Teori STRIKE
1. **Lexicographical index bisa dihitung langsung**  
    → Gunakan _offset blok_ × ukuran blok + _offset dalam blok_, tanpa harus generate semua kemungkinan.
    <br/>
    
2. **Saat menghitung offset dalam blok, perhatikan elemen yang dilarang**  
    → Kalau elemen kedua ≥ elemen pertama, geser 1 ke atas (karena kombinasi huruf sama tidak ada).
    
```

<br/>

---
# 1 | Dictionary


Bahasa Berland terdiri dari kata-kata yang memiliki **tepat dua huruf**. Selain itu, huruf pertama dari sebuah kata **berbeda** dengan huruf keduanya. Kombinasi apa pun dari dua huruf Berland yang berbeda (yang, omong-omong, sama dengan huruf Latin kecil) adalah kata yang benar dalam bahasa Berland.

Kamus Berland memuat **semua kata** dari bahasa ini. Kata-kata diurutkan sebagaimana biasanya dalam kamus. Secara formal, kata $a$ muncul lebih awal daripada kata $b$ di kamus jika salah satu kondisi berikut terpenuhi:

* Huruf pertama $a$ **lebih kecil** daripada huruf pertama $b$;
* Huruf pertama $a$ sama dengan huruf pertama $b$, dan huruf kedua $a$ **lebih kecil** daripada huruf kedua $b$.

Jadi, kamusnya akan terlihat seperti ini:

* Kata 1: `ab`
* Kata 2: `ac`
* ...
* Kata 25: `az`
* Kata 26: `ba`
* Kata 27: `bc`
* ...
* Kata 649: `zx`
* Kata 650: `zy`

Kamu diberikan sebuah kata $s$ dari bahasa Berland. Tugasmu adalah menemukan **indeks** kata tersebut di dalam kamus.

#### Masukan:
Baris pertama berisi satu bilangan bulat $t$ $(1 \le t \le 650)$ — jumlah kasus uji.

Setiap kasus uji terdiri dari satu baris berisi $s$ — sebuah string yang terdiri dari tepat dua huruf Latin kecil yang berbeda (artinya kata yang benar dari bahasa Berland).

#### Keluaran:
Untuk setiap kasus uji, cetak satu bilangan bulat — **indeks** kata $s$ di dalam kamus.

<br/>

---
# 2 | Sesi STRIKE ⚔️

1. **Lexicographical index bisa dihitung langsung**  
    → Gunakan _offset blok_ × ukuran blok + _offset dalam blok_, tanpa harus generate semua kemungkinan.
    
2. **Saat menghitung offset dalam blok, perhatikan elemen yang dilarang**  
    → Kalau elemen kedua ≥ elemen pertama, geser 1 ke atas (karena kombinasi huruf sama tidak ada).

 #tips-trick Lexicographical index bisa dihitung langsung, jadi tidak semua kasus harus generate dulu semua kemungkinan!

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Ada banyak cara berbeda untuk menyelesaikan masalah ini:

* Membuat semua kata Berland dengan dua loop for dan menyimpannya dalam sebuah array, lalu untuk setiap test case, telusuri array kata tersebut untuk menemukan kata yang dibutuhkan.
<br/>

* Membuat semua kata Berland dengan dua loop for dan menyimpannya dalam struktur data seperti kamus (map di C++, dict di Python, dll), menggunakan kata sebagai key dan nomornya sebagai value. Cara ini memungkinkan pencarian indeks kata yang diberikan dilakukan dengan cepat.
<br/>

* Untuk setiap test case, jalankan dua loop for untuk menelusuri kata-kata, hitung berapa banyak kata yang dilewati, dan berhenti di kata dari test case.
<br/>

* Mencoba menemukan beberapa rumus yang memungkinkan kita menghitung jumlah kata sebelum kata yang diberikan.

Berikut contoh implementasinya:

```cpp
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string w = "aa";
    map<string, int> idx;
    int i = 1;
    for(w[0] = 'a'; w[0] <= 'z'; w[0]++)
        for(w[1] = 'a'; w[1] <= 'z'; w[1]++)
            if(w[0] != w[1])
                idx[w] = i++;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string s;
        cin >> s;
        cout << idx[s] << endl;
    }   
}
```

## 3.2 | Analisis Pribadi

Dari beberapa metode yang dibeerikan, untungnya aku menemukan sebuah solusi yang lebih baik, dimana solusiku ini tidak perlu melakukan precompute, atau membutuhkan memory tambahan, bahkan bisa dilakukan dalam waktu $O(1)$, alias konstan.

Berikut adalah implementasiku:

```cpp
/*
Author  : Riveris
Date    : 2025-08-12 18:09
Problem : Codeforces - 1674B | Dictionary
*/

#include <iostream>
using namespace std;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

void solve() {
   char a, b;
   cin >> a >> b;

   int x = (a - 'a');
   int y = (b - 'a');

   int rest = 25 * x;
   rest += (x > y ? (y + 1) : y);
   cout << rest << '\n';
}

auto main() -> int {
   fastio();
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
   return 0;
}
```

Sebenarnya ini adalah cara yang lebih readeble dari beberapa pengguna lain yang sepertinya menemukan cara yang sama efisienya, kebanyakan dari mereka menggunakan cara seperti ini:

```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int NR=1010;

signed main(){
	int T;cin>>T;
	while(T--){
		char a,b;cin>>a>>b;
		cout<<(a-'a')*25+(b-'a')+(a>b?1:0)<<endl;
	}
	return 0;
}
```

Logikanya mudah, pertama kita perlu tahu bahwa setiap 2 karakter pasti tidaklah sama, sehingga kamus pertama pasti adalah `ab` dan kamus terakhir pastilah `zy`.

Nah, setiap satu lembar karakter pertama, misal `a..`, itu terdiri dari 25 halaman, yang terdiri dari karakter berupa `..b` hingga `..z`. 

Sehingga kita cukup kalikan 25 dengan nilai dari karakter pertama. Karakter pertama dimulai dari `a..` yaitu 0.

Rumusnya berarti `25 * (s[0]-'a')`.

Nah, sekarang kita urus karakter kedua. Jika karakter pertama lebih besar leksikografinya dari karakter pertama, maka nilai sebelumnya ditambahkan `(y+1)`, jika tidak, cukup tambahkan `y`.

Lalu outputkan hasilnya.