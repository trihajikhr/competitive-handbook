---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1504B
judul_DEATH: Flip the Bits
teori_DEATH:
sumber:
  - codeforces.com
rating: 1200
ada_tips: false
date_learned: 2025-10-25T14:40:00
tags:
  - constructive-algorithms
  - greedy
  - implementation
  - math
---
Sumber: [Problem - 1504B - Codeforces](https://codeforces.com/problemset/problem/1504/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1504B-Flip the Bits

Diberikan dua buah string biner $a$ dan $b$ dengan panjang $n$. Tugasmu adalah membuat string biner $a$ menjadi sama dengan $b$. Dalam satu operasi, kamu bisa memilih prefiq dari $a$ yang memiliki jumlah karakter $0$ dan $1$ yang sama. Lalu, untuk setiap karakter tersebut inverted, sehingga $0$ menjadi $1$, dan $1$ menjadi $0$.

Sebagai contoh, $a = 0111010000$

- Pada operasi pertama, kita bisa memilih prefix yaitu $8$, karena jumlah karakter $0$ dan $1$ adalah sama: $[01110100]00 \rightarrow [10001011]00$
- Pada operasi kedua, kita bisa memilih prefiq $2$, karena jumlah karakter $0$ dan $1$ adalah sama yaitu $1$: $[10]00101100 \rightarrow [01]00101100$
- DIlarang untuk memilih prefiq yang didalamnya, jumlah karakter $0$ dan $1$ tidak sama.


Tentukan, dengan beberapa operasi, apakah mungkin untuk membuat string $a$ menjadi string $b$?
<br/>

---
# 2 | Sesi Death Ground ⚔️

Karena pemilihan prefix hanya bisa dilakukan jika jumlah kemunculan $0$ dan $1$ didalamnya adalah sama, maka kita hanya bisa menentukan apakah suatu string $a$ bisa menjadi $b$ dengan cara melakukan pemeriksaan kesamaan jumlah karakter $0$ dan $1$.

Pertama, hitung berapa banyak kemunculan angka $0$ dan $1$ pada string $a$. Misal dibuat variabel yang menampung jumlah karakter keduanya dengan $cnt0$ dan $cnt1$. Lalu lakukan traversal pada string $a$ dari belakang. Selama proses traversal ini, kita mengurangi jumlah kemunculan karakter $0$ dan $1$ (*yang disimpan divariabel*), sesuai dengan karakter $a_i$. Tapi proses ini harus dilakukan secara berbeda ketika invers dilakukan (*penjelasan tentang ini akan dijelaskan dibawah*).

Dalam keadaan normal, ketika terdapat karakter $a_i$ yang tidak sama dengan karakter $b_i$, maka kita lakukan pengecekan, apakah nilai $cnt0$ dan $cnt1$ adalah sama. Jika sama, maka lakukan invers, dan kurangi nilai $cnt0$ atau $cnt1$, sesuai dengan karakter yang sudah disesuaikan. Sedangkan jika tidak, maka langsung hentikan traversal dan outputkan `NO`. Ini karena, karakter yang jumlahnya berbeda, menghalangi pemilihan prefiq, sehingga kedua string tidak mungkin disamakan.

Sedangkan dalam keadaan invers, pemeriksaan hanya akan dilakukan jika karakter $a_1$ dan $b_1$ adalah sama, ini karena $a_i$ dalam keadaan ter invers, sehingga kesamaan karakter $a_i$ dan $b_i$, dianggap berbeda untuk karakter aslinya.

Dalam keadaan normal, kemunculan karakter $0$ (*ketika traversal*) akan mengurangi nilai dari variabel $cnt0$. Tetapi ketika invers, kemunculan karakter $0$ akan mengurangi nilai dari $cnt1$. Begitupun sebaliknya.

Untuk mekanisme invers, sangat tidak efisien jika kita melakukan perubahan pada string $a$ setiap kali invers dilakukan, sehingga aku menggunakan percabangan untuk menyiasati ini, memastikan kompleksitas tetap $O(n)$.

Berikut adalah implementasiku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int zer = 0, one = 0;
    for (char c: a) {
        if (c=='0') zer++;
        else one++;
    }

    bool sw = false;
    for (int i=n-1; i>=0; i--) {
        if (sw) {
            if (a[i] == b[i]) {
                if (zer != one) {
                    cout << "NO\n";
                    return;
                }

                if (a[i]=='0') zer--;
                else one--;
                sw = false;

            } else {
                if (a[i]=='0') one--;
                else zer--;
            }
        } else {
            if (a[i] != b[i]) {
                if (zer != one) {
                    cout << "NO\n";
                    return;
                }

                if (a[i]=='0') one--;
                else zer--;
                sw = true;

            } else {
                if (a[i]=='0') zer--;
                else one--;
            }
        }
    }
    cout << "YES\n";
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Mari kita sebut suatu prefiks (*prefix*) sebagai legal (*legal*) jika ia mengandung jumlah simbol $0$ dan $1$ yang sama.

Pengamatan kuncinya adalah bahwa penerapan operasi **tidak pernah mengubah** prefiks mana yang bersifat legal. Faktanya, misalkan kita menerapkan operasi pada prefiks dengan panjang $i$, dan kita mempertimbangkan prefiks dengan panjang $j$. Kita ingin menunjukkan bahwa:
1.  Jika $j$ legal sebelumnya, ia tetap legal.
2.  Jika $j$ tidak legal, ia tidak akan menjadi legal.

### Kasus 1: $j < i$

Jika $j < i$, maka semua bit dalam prefiks sepanjang $j$ **diinversi** (*inverted*). Jumlah $0$ dan $1$ akan bertukar posisi, sehingga ini tidak dapat mengubah apakah jumlah keduanya sama atau tidak, dan oleh karena itu, tidak dapat mengubah apakah $j$ itu legal.

### Kasus 2: $j \ge i$

Jika $j \ge i$, maka $\frac{i}{2}$ dari simbol $0$ menjadi $1$ dan $\frac{i}{2}$ dari simbol $1$ menjadi $0$. Jadi, jumlah kedua simbol tersebut tidak berubah, sehingga ini tidak dapat mengubah apakah $j$ itu legal.


Dengan menggunakan **jumlah prefiks** (*prefix sums*), kita dapat menentukan untuk setiap prefiks apakah prefiks tersebut legal.

Pertimbangkan suatu indeks $i$.
* Jika $i=n$ dan $a_n \ne b_n$, maka kita harus membalik (*flip*) prefiks sepanjang $n$ pada suatu titik.
* Jika $i < n$ dan ($a_i = b_i$ dan $a_{i+1} \ne b_{i+1}$), ATAU ($a_i \ne b_i$ dan $a_{i+1} = b_{i+1}$), maka kita harus membalik prefiks sepanjang $i$ pada suatu titik.

Jika kita membalik secara tepat prefiks-prefiks ini dalam urutan apa pun, operasi tersebut akan mengubah deretan $a$ menjadi $b$. Oleh karena itu, kita hanya perlu memeriksa bahwa **setiap prefiks yang harus dibalik adalah legal**.

Kompleksitas waktu (*Time complexity*) adalah $O(n)$.

Berikut adalah implementasi editorial:

```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    a.push_back('0');
    b.push_back('0');
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (a[i] == '1') - (a[i] == '0');
        if((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}
```

## 3.2 | Analisis Pribadi

Melihat dari petunjuk editorial, aku lebih tertarik untuk membedeah kode implementasi editorial:

```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    a.push_back('0');
    b.push_back('0');
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (a[i] == '1') - (a[i] == '0');
        if((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}
```

Kode ini melakukan pemeriksaan dari depan, dan karena tiap pemeriksaan melakukan pengecekan juga terhadap elemen didepanya, maka disiasati dengan memberikan jarak aman dengan menambahkan karakter yang sama untuk kedua string:

```cpp
a.push_back('0');
b.push_back('0');
```

Mekanisme yang lebih sulit ada pada bagian ini:

```cpp
int cnt = 0;
for(int i = 0; i < n; i++) {
	cnt += (a[i] == '1') - (a[i] == '0');
	if((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt != 0) {
		cout << "NO\n";
		return;
	}
}
cout << "YES\n";
```

Nilai dari $cnt$ akan bertambah ketika karakter $a[i]=1$ , dan berkurang ketika $a[i]=0$. Lalu, masuk ke bagian sulitnya, yaitu bagian kondisional. Bagian kondisional ini akan dijalankan, ketika:

1. $a[i] \equiv b[i]$ tetapi $a[i+1] \neq b[i+1]$, dan $cnt \neq 0$
2. $a[i] \neq b[i]$ tetapi $a[i+1] \equiv b[i+1]$, dan $cnt \neq 0$

Pengkondisian ini mendeteksi titik dimana invers harus dilakukan, dan apakah selisih jumlah karakter yang disimpan di $cnt$ valid atau tidak untuk melakukan operasi prefiq. 

Implementasi ini bahkan tidak memerlukan penerapan invers, dia hanya menggunakan kondisional untuk melakukan pengecekan secara sederhana. Yaitu mentrigger kondisional, ketika karakter posisi sekarang adalah sama tetapi karakter bagian depanya berbeda atau sebaliknya, tepat ketika  $cnt \neq 0$. Ketika kondisi ini terjadi, berarti operasi prefiq tidak bisa dilakukan, karena jumlah karakter yang berbeda tidak sama, menghasilakn output `NO`.

Jika kondisional ini tidak tertrigger, maka berarti $a$ bisa dirubah menjadi $b$, sehingga outputkan `YES`. 

Berikut perbaikan ku:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, dif = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    a.push_back('0');
    b.push_back('0');
    for (int i=0; i<n; i++) {
        dif += a[i] == '1' ? 1 : -1;
        if ((a[i] == b[i]) != (a[i+1] == b[i+1]) && dif != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout <<"YES\n";
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Solusi dari editorial sudah efisien dan simple, dan aku rasa pendekatan ini sudah yang paling cocok. Jawaban dari pengguna lain tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>
using namespace std;

int t, n, sum, ch;
char a[300005], b[300005];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> b;
        sum = 0, ch = 0;
        for (int i = 0; i < n; ++i) {
            sum += (a[i] == '1') - (a[i] == '0');
            if ((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && sum != 0) {
                ch = 1;
                break;
            }
        }
        cout << (ch ? "NO" : "YES") << endl;
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int n, cnt = 0;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    s1.push_back('0');
    s2.push_back('0');
    for (int i = 0; i < n; i++) {
        cnt += (s1[i] == '0') - (s1[i] == '1');
        if ((s1[i] == s2[i]) != (s1[i + 1] == s2[i + 1]) && cnt != 0) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    a.push_back('0');
    b.push_back('0');
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (a[i] == '1') - (a[i] == '0');
        if((a[i] == b[i]) != (a[i + 1] == b[i + 1]) && cnt != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}
```