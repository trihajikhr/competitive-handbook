---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1543A
judul_DEATH: Exciting Bets
teori_DEATH: aturan GCD
sumber:
  - codeforces.com
ada_tips?: true
date_learned: 2025-10-06T11:01:00
tags:
  - math
---
Sumber: [Problem - 1543A - Codeforces](https://codeforces.com/problemset/problem/1543/A)

```ad-tip
title:⚔️ Teori Death Ground
- $GCD(a,b)=GCD(a-b,b)$, jika $a>b$
```

<br/>

---
# 1 | 1543A-Exciting Betska

Kamu diberikan angka $a$ dan angka $b$. Tugas kita adalah menentukan, dengan dua operasi yang boleh kita lakukan:

1. Menambahkan 1 ke angka $a$ dan $b$
2. Mengurangkan 1 ke angka $a$ dan $b$

Yang akan menghasilkan nilai $gcd(a,b)$ terbesar yang mungkin. Untuk $gcd(x,0)=0, \; \text \; {jika} \; x\geq 0$.

Di trial of ten, aku masih bingung dengan bagaimana mendekati solusi dari problem ini.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Mencari nilai $gcd(a,b)$ terbesar itu mudah, cukup dengan menghitung selisih dari $|a-b|$. Tapi menghitung jumlah operasi yang diperlukan masih tidak ketemu.

Untuk kasus ketika $a==b$, maka jawabanya adalah $0$, karena kita bisa menggunakan operasi 1 dan 2 tanpa batas.

<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

**Hint 1**: $GCD(a,b)=GCD(a-b,b)$, jika $a>b$

**Hint 2**:  $a-b$ tidak berubah dengan menerapkan operasi apa pun. Namun, $b$ dapat diubah secara sewenang-wenang.

Jika $a=b$, para penggemar dapat memperoleh kegembiraan dalam jumlah tak terbatas, dan kita dapat mencapai ini dengan menerapkan operasi pertama berkali-kali tanpa batas.

Jika tidak, kegembiraan maksimum yang bisa didapatkan para penggemar adalah $g=|a-b|$ dan jumlah langkah minimum yang diperlukan untuk mencapainya adalah $min(a \bmod g, g - a \bmod g)$.

```ad-hint
Tanpa mengurangi keumuman, asumsikan $a>b$, jika tidak, kita dapat menukar $a$ dan $b$. Kita tahu bahwa $GCD(a,b)=GCD(a-b,b)$. Perhatikan bahwa tidak peduli berapa kali kita menerapkan operasi apa pun, nilai dari $a-b$ tidak berubah. Kita dapat secara sewenang-wenang mengubah nilai $b$ menjadi kelipatan dari $a-b$ dengan menerapkan operasi tersebut. Dengan cara ini, kita dapat mencapai $GCD$ yang sama dengan $a-b$. Sekarang, karena $GCD(x,y) \le \min(x,y)$ untuk setiap bilangan positif $x$ dan $y$, $GCD(a-b,b)$ tidak akan pernah melebihi $a-b$. Jadi, kita tidak dapat mencapai $GCD$ yang lebih tinggi dengan cara apa pun.

Untuk mencapai $GCD$ yang diperlukan, kita perlu menjadikan $b$ kelipatan dari $g=a-b$ menggunakan operasi sesedikit mungkin. Ada dua cara untuk melakukannya $- $ mengurangi $b$ menjadi kelipatan terbesar dari $g$ yang kurang dari atau sama dengan $b$ atau meningkatkan $b$ menjadi kelipatan terkecil dari $g$ yang lebih besar dari $b$. Jumlah operasi yang diperlukan untuk melakukannya masing-masing adalah $b \bmod g$ dan $g - b \bmod g$. Kita jelas akan memilih yang minimum dari keduanya. Perhatikan juga bahwa $a \bmod g = b \bmod g$ karena $a=b+g$. Jadi, tidak masalah apakah kita menggunakan $a$ atau $b$ untuk menentukan jumlah minimum operasi.
```

**Kompleksitas Waktu**: $O(1)$ per kasus uji.

Berikut implementasinya:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long a,b;
        cin >> a >> b;
        if(a==b)
            cout << 0 << " " << 0 << '\n';
        else
        {
            long long g = abs(a-b);
            long long m = min(a%g,g-a%g);
            cout << g << " " << m << '\n';
        }
    }
}
```

## 3.2 | Analisis Pribadi

Selama proses mencari solusi, aku memang menemukan solusi, bahwa nilai terbesar untuk $gcd(a,b)$ bisa didapatkan dengan mengurangi angka $a$ dan $b$ dengan nilai terkecil dari keduanya. Ketika salah satu menyentuk angka $0$, maka angka sisanya akan memberikan nilai $gcd(a,b)$ terbesar, dan itu bisa dicapai cukup dengan melakukan operasi $g=|a-b|$.

Namun menghitung jumlah operasi yang diperlukan itulah yang membuatku buntu. 

Mengikut saran dari editorial, berikut adalah implementasiku:

```cpp
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

void solve() {
    long long a,b,g;
    cin >> a >> b;
    if (a==b) cout << "0 0";
    else {
        g = abs(a-b);
        cout << g << " " << min(a%g, g-(a % g));
    }
    cout << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);; cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```
## 3.3 | Analisis Jawaban User Lain

Solusi dari editorial sudah merupakan solusi yang paling tepat, sehingga jawaban dari user lainn tidak jauh berbeda:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a = 0, b, r;
        cin >> a >> b;
        r = abs(a - b);
        if (r != 0) a = max(a, b) % r;
        cout << r << ' ' << min(a, (r == 0 ? 0 : r - a)) << "\n";
    }
}
```
### 2 | Jawaban Kedua

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int t;
	cin>>t;
	while (t--)
	{
		ll a,b;
		cin>>a>>b;
		ll t=abs(a-b);
		if (t==0) cout<<"0 0\n";
		else cout<<t<<' '<<min(a%t,t-a%t)<<endl;
	}
}
```
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        long long a,b;
        cin >> a >> b;
        if(a==b)
            cout << 0 << " " << 0 << '\n';
        else
        {
            long long g = abs(a-b);
            long long m = min(a%g,g-a%g);
            cout << g << " " << m << '\n';
        }
    }
}
```