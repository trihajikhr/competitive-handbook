---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 1837B
judul_DEATH: Comparison String
teori_DEATH:
sumber:
  - codeforces.com
ada_tips?:
date_learned: 2025-10-05T00:26:00
tags:
---
Sumber: [Problem - 1837B - Codeforces](https://codeforces.com/problemset/problem/1837/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 1837B-Comparison String

Kita diberikan sebuah string yang hanya terdiri dari karakter `<` dan `>`. Karakter ini merepresentasikan, untuk setiap tanda $>$, maka $a_i > a_{i+1}$. Dan untuk setiap tanda $<$, maka $a_i < a_{i+1}$.

Jika kita diperbolehkan menggunakan angka-angka yang sama (asal tetap memenuhi pertidaksamaan yang diberikan oleh string), maka berapa jumlah angka minimal yang bisa kita gunakan?

Pertama aku merasa solusi dari ini sulit, tapi ternyata cukup mudah. Simak saja penjelasanya!

<br/>

---
# 2 | Sesi Death Ground ⚔️

Solusinya mudah, kita cukup menggunakan sedikit intuisi disini. Di contoh input output yang diberikan, yaitu yang tertulis seperti ini:

```
4
4
<<>>
4
>><<
5
>>>>>
7
<><><><
```

Output:

```
3
3
6
2
```

Kita bisa melihat di test case ke-3, bahwa ketika string tersusun oleh tanda `>>>>>`, maka jawabanya adalah 6. 

Dan jika di test case ke-4, ketika string tersusun oleh tanda `<><><><`, maka jawabanya adalah 2.

Disini, aku mengambil kesimpulan, bahwa kita tidak bisa menghitung banyaknya kemunculan karakter `>` dan `<` tanpa mengabaikan urutanya. Karena urutanya ternyata sangat penting. 

Karena urutan sangat penting, dan pola pada test case ke-3 dan ke-4 lumayan jelas, aku berkesimpulan bahwa satu-satunya hal yang paling menentukan banyaknya angka yang berbeda yang mungkin, itu ditentukan oleh substring terpanjang dari karakter yang sama, lalu tambahkan 1.

Jadi, pada test case ke-3, karena substring terpanjang adalah `>>>>>`, maka kita bisa outputkan $5+1$, yaitu $6$.

Dan untuk test case ke-4, karena panjang substring maksimal hanyalah 1 (semua karakter saling berlawanan), maka kita outputkan $1+1$, menjadi $2$.

Dan kesimpulan ini benar, setelah implementasi berikut mendapatkan status *Accepted*:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int maks = 0, cnt=1;
    char a = s[0];
    for (int i=1; i<s.length(); i++) {
        if (s[i]==a) cnt++;
        else {
            maks = max(maks, cnt);
            cnt=1;
        }
        a = s[i];
    }

    cout << max(maks,cnt)+1 << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official


Misalkan ada segmen dengan panjang $k$ yang terdiri dari karakter yang sama di $s$. Segmen ini menyiratkan bahwa setidaknya ada $k+1$ nilai berbeda dalam jawaban: sebagai contoh, jika segmen tersebut terdiri dari tanda $<$ (kurang dari), elemen pertama harus kurang dari elemen kedua, elemen kedua harus kurang dari elemen ketiga, dan seterusnya, sehingga segmen yang bersesuaian dari larik $a$ mengandung setidaknya $k+1$ elemen berbeda.

Jadi, jawabannya setidaknya $m+1$, di mana $m$ adalah panjang segmen terpanjang dari string yang terdiri dari karakter yang sama. Bisakah kita menyusun larik $a$ yang akan berisi tepat $m+1$ nilai berbeda? Ternyata kita bisa melakukannya dengan algoritma serakah (greedy) berikut: 

mari kita gunakan bilangan bulat dari $0$ hingga $m$ untuk larik $a$ kita, dan mari kita susun dari kiri ke kanan; setiap kali kita menempatkan elemen, kita memilih salah satu bilangan bulat terbesar yang mungkin kita gunakan (jika karakter berikutnya adalah $>$ (lebih dari)) atau bilangan bulat terkecil yang mungkin kita gunakan (jika karakter berikutnya adalah $<$ (kurang dari)). Misalnya, untuk string $<><<<>$, $6$ elemen pertama dari larik akan menjadi $[0,3,0,1,2,3]$ (dan kita dapat menggunakan bilangan bulat apa pun dari $0$ hingga $2$ di posisi terakhir). Dengan cara itu, setiap kali segmen karakter yang sama dimulai, nilai saat ini dalam larik akan menjadi $m$ atau $0$, dan kita akan dapat mengurangi atau menambahkannya $m$ kali, sehingga kita tidak akan sampai pada situasi di mana, misalnya, nilai saat ini adalah $0$ dan kita harus menemukan bilangan bulat yang lebih kecil.

Jadi, masalahnya pada dasarnya direduksi menjadi **menemukan subsegmen yang berdekatan (contiguous subsegment) terpanjang dari karakter yang sama di $s$**.

Berikut implementasinya:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 1, cur = 1;
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i - 1]) cur = 1;
            else cur++;
            ans = max(ans, cur);
        }
        cout << ans + 1 << endl;
    }    
}
```

## 3.2 | Analisis Pribadi

Alih-alih menerima semua inputanya sebagai string, kita bisa menampungnya dalam char untuk menjadikan penggunaan memory lebih efisien dan minimal. 

Dengan konsep yang sama, namun lebih efisien secara memory:

```cpp
#include<iostream>
using namespace std;

void solve() {
    int n, ans=1, temp=1; cin >> n;
    char c, a; cin >> a;
    for (int i=0; i<n-1; i++) {
        cin >> c;
        if (c==a) temp++;
        else temp=1;
        a=c;
        ans = max(ans, temp);
    }
    cout << ans+1 << '\n';
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
```

```ad-warning
Nilai awal `ans` harus 1! Ini berguna untuk mengatasi edge case, dimana nilai $n$ atau panjang string hanyalah 1. Ketika edge case ini muncul, kita bisa mengoutputkan nilai 2 sebagai jawaban!
```
## 3.3 | Analisis Jawaban User Lain

Karena solusi dari soal ini hanyalah mencari substring atau segmen karakter sama terpanjang, maka jawaban dari user lain tidak terlalu berbeda poinya:

### 1 | Jawaban Pertama

```cpp
#include<bits/stdc++.h>

using namespace std;
int main() {
    int a, b, c, n;

    string s;
    cin >> n;
    while (cin >> n >> s) {
        a = b = c = 1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) c++;
            else c = 1;
            a = max(c, a);
        }

        cout << a + 1 << endl;
    }
}
```

### 2 | Jawaban Kedua

```cpp
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<set>

using namespace std;
using ll = long long;
using db = double;
void solution() {
    int n, s = 1, mx = 1;
    string a;
    cin >> n >> a;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) s = 1;
        else s++;
        mx = max(s, mx);
    }
    cout << mx + 1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solution();
}
```

### 3 | Jawaban Ketiga

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 1;
        string s = "";
        cin >> s;
        int len = 1;
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c == s[i - 1]) len++;
            else len = 1;
            ans = max(ans, len);
        }
        cout << ans + 1 << endl;
    }
}
```