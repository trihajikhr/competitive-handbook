---
obsidianUIMode: preview
note_type: latihan
latihan: Membangun Menara
sumber:
  - tlx-toki
tags:
  - gemastik
date_learned: 2025-07-19T18:48:00
---

Link problem: [Gemastik2016-Membangun Menara](https://tlx.toki.id/problems/gemastik-2016-pemrograman-penyisihan/A)

---
# Membangun Menara

| Time limit   | 1 s   |
| ------------ | ----- |
| Memory limit | 64 MB |

### Deskripsi
Untuk mempersiapkan geMasTIK, William selaku kepala divisi dekorasi berniat untuk membangun sebuah menara yang akan digunakan sebagai hiasan gapura. Menara ini dibangun menggunakan balok-balok dengan berbagai ukuran. William memiliki $N$ buah balok. Balok ke-$i$ memiliki dimensi $A[i] × B[i] × C[i]$. Balok-balok tersebut akan ditumpuk-tumpuk hingga membentuk menara.

William ingin tahu, berapa tinggi menara paling tinggi yang mungkin dibentuk, serta tinggi menara paling rendah yang mungkin dibentuk jika semua balok dipakai dalam penyusunan menara. Dalam penyusunannya, balok-balok tersebut boleh diputar sesuai keinginan. William memberikan tugas kepada Anda (sebagai wakil kepala divisi) untuk mencari tahu hal tersebut.

### Format Masukan
Baris pertama berisi sebuah bilangan bulat $T$ yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat $N$. $N$ baris berikutnya masing-masing berisi tiga buah bilangan bulat $A[i]$, $B[i]$, dan $C[i]$.
### Format Keluaran
Untuk setiap kasus uji, keluarkan sebuah baris berisi dua buah bilangan bulat $L$ dan $H$. $L$ menyatakan tinggi menara minimum, dan $H$ menyatakan tinggi menara maksimum.
### Contoh Masukan
```
3
3
1 2 3
5 4 6
9 8 7
1
6 6 6
2
1 1 1
10 20 30
```

### Contoh Keluaran
```
12 18
6 6
11 31
```

### Batasan

- $1 ≤ T ≤ 20$
- $1 ≤ N ≤ 100$
- $1 ≤ A[i], \; B[i], \; C[i] ≤ 1000$

# Solusiku
Baiklah, aku memiliki solusi yang cukup sederahana, karena soal ini memang lumayan mudah. Suatu balok, akan mendapatkan tinggi maksimalnya, jika kita menjadikan sisi terpanjang sebagai tinggi. Dan suatu balok akan mendapatkan tinggi terendahnya, jika kita menjadikan sisi terpendeknya menjadi tinggi balok. Kita juga perlu tahu bahwa balok ini bisa diputar sesuai dengan keinginan kita, sehingga solusinya cukup sederhana menurutku.

Untuk mendapatkan tinggi minimal balok, kita deklarasikan `mins=0`, dan tambhakan `mins` dengan nilai terkecil dari $A$, $B$, dan $C$. Dan untuk mendapatkan tinggi tertinggi balok, kita deklarasikan `maks=0`, dan tambahkan dengan nilai tertinggi dari $A$, $B$, dan $C$.

### Implementasi
Dengan C++ 20:

```cpp
#include<iostream>
using namespace std;

void solve(){
    int n; cin >> n;
    int mins=0, maks=0;
    int a,b,c;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
        if(a<=b && a<=c) mins+=a;
        else if(b<=a && b<= c) mins+=b;
        else if(c<=a && c<=b) mins+=c;

        if(a>=b && a>=c) maks+=a;
        else if(b>=a && b>=c) maks+=b;
        else if(c>=a && c>=b) maks+=c;
    }
    cout << mins << " " << maks << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
```

Dengan C++ 23:

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

void solve(){
    int n; cin >> n;
    int mins=0, maks=0;
    int a,b,c;
    for(int i=0; i<n; i++){
        cin >> a >> b >> c;
		mins += min({a,b,c});
		maks += max({a,b,c});
    }
    cout << mins << " " << maks << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
```

> [!NOTE] Verdict
> Jawaban ini benar! 

# Editorial Resmi
Ini adalah soal paling mudah pada penyisihan GEMASTIK 9.

Untuk setiap balok yang ada, kita boleh memutar orientasi balok tersebut sesuka hati. Artinya, untuk membentuk menara tertinggi/terendah, kita cukup memutar setiap balok sehingga sisi terpanjang/terpendek balok menjadi tinggi balok tersebut. Dengan kata lain, untuk setiap balok, cari panjang sisi maksimum dan minimumnya.

Kompleksitas: O(N).

### Jawaban Efisien
Jawabanku sudah efisien berdasarkan pengguna yang lain.