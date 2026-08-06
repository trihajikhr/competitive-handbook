---
obsidianUIMode: preview
note_type: Death Ground ☠️
kode_soal: 746B
judul_DEATH: Decoding
teori_DEATH:
sumber:
  - codeforces.com
rating: 900
ada_tips?:
date_learned: 2025-10-18T13:44:00
tags:
---
Sumber: [Problem - 746B - Codeforces](https://codeforces.com/problemset/problem/746/B)

```ad-tip
title:⚔️ Teori Death Ground
```

<br/>

---
# 1 | 746B-Decoding

Diberikan sebuah string $s$ dengan panjang $n$. Median dari string, adalah titik karakter tengah dari string. Dimana median dari string $s$, jika panjang atau nilai dari $n$ adalah ganjil, maka medianya tepat di tengah. Sedangkan jika $n$ genap, maka medianya adalah bagian kiri dari 2 karakter yang ada ditengah.

String $s$ yang diberikan, adalah string yang diencoding dengan cara mengambil median dari string asli, menghapusnya, lalu mengambil mediannya lagi, hingga string asli tidak menyisakan karakter.

Tugasmu adalah melakukan decoding terhadap string $s$, untuk menemukan dan menyusun kembali string asli.

<br/>

---
# 2 | Sesi Death Ground ⚔️

Untuk $s = logva$, maka outputnya adalah $volga$. Intuisiku mengatakan bahwa kita bisa menyusun kembali string asli, dengan meletakan setiap karakter mulai dari kiri string $s$, ke bagian kiri dan kanan string asal.

Jika $n$ ganjil, maka peletakan pertama adalah menambahkanya di kanan, lalu menambahkanya di bagian depan atau kiri. Alurnya berarti adalah kanan-kiri-kanan.

Sedangkan ketika $n$ genap, maka alurnya berbeda, itu bisa diamati dari $s=abba$ dengan output $baba$. Alurnya adalah kebalikan dari sebelumnya, yaitu kiri-kanan-kiri.

Berikut adalah implementasiku:

```cpp
#include<iostream>
#include<string>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s, rest = "";
    cin >> s;

    bool even = n%2==0;
    for (int i=0; i<n; i++) {
        if (even) {
            rest.insert(rest.begin(), s[i]);
            even = false;
        } else {
            rest += s[i];
            even = true;
        }
    }
    cout << rest << '\n';
    return 0;
}
```


<br/>

---


# 3 | Jawaban dan Editorial

## 3.1 | Analisis Official

Untuk menemukan jawabannya, kita bisa mengulangi (melakukan iterasi) string yang diberikan dari kiri ke kanan dan menambahkan setiap huruf ke string hasil. Caranya, satu huruf ke awal string hasil, huruf berikutnya ke akhir, huruf berikutnya lagi ke awal, dan seterusnya.

Aturan Penempatan Huruf:

1.  Jika $n$ (panjang string) genap:
    * Huruf pertama harus ditambahkan **ke awal** string hasil.
    * Huruf kedua ke **akhir**.



2.  Jika $n$ (panjang string) ganjil:
    * Huruf pertama harus ditambahkan **ke akhir** string hasil.
    * Huruf kedua ke **awal**.

Kita perlu melakukannya hingga semua huruf dari string yang diberikan telah ditambahkan ke string hasil.
## 3.2 | Analisis Pribadi

Solusi dari pendekatanku sama persis dengan editorial. Jawabanku sudah benar, dan analisis awal sudah optimal!
## 3.3 | Analisis Jawaban User Lain

### 1 | Jawaban Pertama

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, d;
    int n;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if ((n - i) % 2) d = d + s[i];
        else d = s[i] + d;
    }
    cout << d << endl;

    return 0;
}
```

Kode ini melakukan penambahan dibagian depan tanpa fungsi insert, tapi menggunakan cara yang lebih cerdik, $d = s[i] + d$.
### 2 | Jawaban Kedua

```cpp
#include<bits/stdc++.h>
using namespace std;

long long a, b, c, d, n, i;

string s;
int main() {
    cin >> n >> s;
    for (i = s.size() - 2; i >= 0; i = i - 2)
        cout << s[i];
    for (i = (s.size() % 2 + 1) % 2; i <= n; i = i + 2)
        cout << s[i];
    return 0;
}
```

Tanpa membuat string bantu, namun langsung membanung string asli dengan hardcoded. Terlihat efisien, namun lebih sulit dipahami.
### 3 | Jawaban Ketiga

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, sz = 0;
    cin >> n;
    string s;
    cin >> s;
    deque < char > res;
    while (n > 0) {
        res.insert(res.begin() + sz / 2, s[n - 1]);
        s.pop_back();
        n--;
        sz++;
    }
    while (!res.empty()) {
        cout << res.front();
        res.pop_front();
    }
}
```

Menggunakan struktur data deque untuk membangun string asli. 