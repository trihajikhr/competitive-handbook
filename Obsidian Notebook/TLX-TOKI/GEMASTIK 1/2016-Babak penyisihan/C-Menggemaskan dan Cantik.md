---
obsidianUIMode: preview
note_type: Reverse Engineering
kode_soal: C
judul_soal: Menggemaskan dan Cantik
teori_REVERSE:
sumber:
  - tlx-toki
date_learned: 2025-08-22T20:56:00
tags:
  - reverse-engineering
---
Sumber: [TLX](https://tlx.toki.id/problems/gemastik-2016-pemrograman-penyisihan/C)

```ad-important
*"Reverse engineering transforms observation into insight, and insight into mastery, — just break it down, understand it, build it better."*
```

---
# 1 | Problem Statement

```ad-info
Mendefinisikan permasalahan secara formal, termasuk input, output, dan batasan operasional.
```

## Menggemaskan dan Cantik

| Time limit   | 4 s    |
| ------------ | ------ |
| Memory limit | 256 MB |

### Deskripsi

Sebentar lagi, kompetisi paling bergengsi se-Indonesia akan diadakan! Apa lagi kalau bukan Kompetisi Menggemaskan dan Cantik (geMasTIK). Seperti biasa, geMasTIK tahun ini terdiri atas dua kategori kompetisi: Kompetisi Ke**geMas**an dan Kompetisi Kecan**TIK**an.

Setiap perwakilan universitas berhak mengirimkan tepat satu tim untuk masing-masing kategori. Setiap tim harus terdiri atas tepat 3 orang. Selain itu, setiap orang tidak boleh ikut lebih dari satu kategori. Tahun ini, Anda ditugaskan oleh pihak kampus untuk mengatur pembagian tim sedemikian rupa agar universitas Anda dapat memenangkan geMasTIK.

Terdapat tepat N mahasiswa yang memenuhi syarat bertanding pada geMasTIK. Mahasiswa ke-i memiliki 2 nilai keahlian, yakni G[i] dan C[i]. G[i] menandakan seberapa menggemaskan mahasiswa tersebut, sedangkan C[i] menandakan seberapa cantik mahasiswa tersebut. Kekuatan suatu tim adalah hasil perkalian dari keahlian masing-masing anggotanya.

Anda berencana untuk mengirimkan tepat 2 tim. Tim pertama akan dikirim untuk mengikuti kontes KegeMasan, sementara kelompok kedua akan dikirim untuk mengikuti kontes KecanTIKan. Anda diminta mengatur pembagian tim sedemikian rupa sehingga kekuatan KegeMasan kelompok pertama ditambah kekuatan KecanTIKan kelompok kedua, sebesar mungkin. Dengan kata lain, misalkan indeks-indeks anggota kelompok pertama adalah a, b, c, sementara kelompok kedua adalah x, y, dan z. Carilah pembagian sedemikian sehingga nilai (G[a] × G[b] × G[c]) + (C[x] × C[y] × C[z]) maksimum.

### Format Masukan

Baris pertama berisi sebuah bilangan bulat T yang menyatakan banyaknya kasus uji.

Untuk setiap kasus uji, baris pertama berisi sebuah bilangan bulat N. N baris berikutnya masing-masing berisi string S[i] (menyatakan nama mahasiswa ke-i), dan dua buah bilangan bulat G[i] dan C[i].

### Format Keluaran

Untuk setiap kasus uji:

Keluaran terdiri atas 3 baris.

Baris pertama berisi sebuah integer yang menyatakan total kekuatan kedua kelompok.

Baris kedua berisi 3 string yang dipisahkan spasi yang merupakan nama-nama anggota kelompok 1 (kategori KegeMasan)

Baris ketiga terdiri dari 3 string yang dipisahkan spasi yang merupakan nama-nama anggota kelompok 2 (kategori KecanTIKan)

Jika ada lebih dari satu cara membagi kelompok yang menghasilkan total kekuatan terbesar, **keluarkan yang mana saja**.

### Contoh Masukan

```
3
6
dana 10 9
dini 10 9
dani 10 9
dono 9 10
dona 9 10
dina 9 10
9
abdul 3 3
afaji 7 6
alham 10 6
alice 7 10
budi 5 3
jack 3 10
kwak 10 10
kwek 2 6
kwok 5 8
11
charlie 11 60
eko 70 32
fauzan 101 101
victor 99 103
halim 103 10
mona 16 100
ridho 20 64
sherly 54 85
ahmad 100 3
bambang 40 23
wawan 74 19
```

### (Salah Satu Cara) Contoh Keluaran

```
2000
dana dini dani
dono dona dina
1500
afaji alham kwak
alice jack kwok
1915800
fauzan halim ahmad
victor mona sherly
```

### Batasan

- 1 ≤ T ≤ 10
- 6 ≤ N ≤ 50.000
- S[i] terdiri atas 1 sampai dengan 8 karakter `a` - `z`
- Semua nama dijamin berbeda-beda
- 1 ≤ G[i], C[i] ≤ 100.000

---
# 2 | Petunjuk dan Editorial
## 2.1 | Editorial

```ad-info
Merangkum pendekatan solusi dan strategi algoritmik yang disajikan oleh sumber eksternal.
```

Misalkan {a, b, c} adalah 3 orang dengan nilai kegemasan tertinggi. Maka, {a, b, c} merupakan calon terkuat untuk tim KegeMasan. Namun ada kemungkinan {a, b, c} juga memiliki nilai kecantikan yang tinggi, sehingga mereka juga berkemungkinan menjadi tim KecanTIKan. Dengan demikian, maka kita masih memerlukan {d, e, f}, yakni 3 orang dengan nilai kegemasan tertinggi setelah {a, b, c} sebagai calon terkuat selanjutnya.

Berdasarkan pengamatan di atas, calon solusi adalah 6 orang terkuat berdasarkan nilai kecantikan dan 6 orang terkuat berdasarkan nilai kegemasan. Kumpulkan mereka dalah satu himpunan calon S. Ukuran S paling besar adalah 12. Setelah itu, lakukan _brute force_ untuk membentuk tim KegeMasan dan KecanTIKan dari keduabelas orang tersebut.

Kompleksitas: O(mengambil 6 orang terkuat) + O(_brute force_ pembagian) (sekitar $3^{12}$).

## 2.2 | Kode

```ad-hint
Menyajikan implementasi referensi sebagai bahan analisis dan pembelajaran.
```

Berikut adalah kode yang akan dibedah:

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Mhs {
    string name;
    long long gemas, cantik;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Mhs> v(n);
        for (auto &x : v) cin >> x.name >> x.gemas >> x.cantik;

        // ambil top 6 gemas
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.gemas > b.gemas;
        });
        vector<Mhs> topGemas(v.begin(), v.begin() + min(6, n));

        // ambil top 6 cantik
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.cantik > b.cantik;
        });
        vector<Mhs> topCantik(v.begin(), v.begin() + min(6, n));

        long long best = LLONG_MIN;
        vector<string> ans;

        // coba semua kombinasi 3 dari topGemas dan 3 dari topCantik
        for (int i = 0; i < (int)topGemas.size(); i++) {
            for (int j = i + 1; j < (int)topGemas.size(); j++) {
                for (int k = j + 1; k < (int)topGemas.size(); k++) {
                    for (int a = 0; a < (int)topCantik.size(); a++) {
                        for (int b = a + 1; b < (int)topCantik.size(); b++) {
                            for (int c = b + 1; c < (int)topCantik.size(); c++) {
                                set<string> allNames = {
                                    topGemas[i].name, topGemas[j].name, topGemas[k].name,
                                    topCantik[a].name, topCantik[b].name, topCantik[c].name
                                };
                                if ((int)allNames.size() < 6) continue; // ada dobel

                                long long score =
                                    topGemas[i].gemas * topGemas[j].gemas * topGemas[k].gemas +
                                    topCantik[a].cantik * topCantik[b].cantik * topCantik[c].cantik;

                                if (score > best) {
                                    best = score;
                                    ans = {
                                        topGemas[i].name, topGemas[j].name, topGemas[k].name,
                                        topCantik[a].name, topCantik[b].name, topCantik[c].name
                                    };
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << best << "\n";
        for (int i = 0; i < 6; i++) {
            cout << ans[i];
            if (i == 2) cout << "\n";
            else cout << " ";
        }
        cout << "\n";
    }
}
```

---

# 3 | Reverse Engineering

```ad-danger
title:Reverse Engineering 🛠️
Menganalisis struktur dan logika kode referensi untuk mengidentifikasi pola, strategi, dan teknik yang digunakan.
```

Kita menggunakan header all in:

```cpp
#include <bits/stdc++.h>
```

Mungkin jika tanpa menggunakan header ini, jika dilihat dari kode, kita cukup melakukan sedikit pemanggilan header saja, sehingga tidak terlalu berlebihan.

Untuk menmpung nama mahasiswa dan skil gemas dan cantik yang mereka miliki, dibuatlah struct:

```cpp
struct Mhs {
    string name;
    long long gemas, cantik;
};
```

Walaupun batasan input kecil, yaitu sekitar 100.000, namun sepertinya tipe data long long digunakan disini untuk mencegah overflow, mengingat terdapat operasi dimana harus membandingkan mana kombinasi dengan nilai terbesar, dengan cara mengalikan dan menambahkan. Jadi, oke, penggunaan long long sepertinya masuk akal, dan perlu dicontoh disini.

Kode ini hampir semua solusinya ditaruh di `main`, dan diawali optimasi I/O cepat. Tidak perlu bertanya yang mana, kamu pasti sudah tahu.

Program menangani inputan dan jumlah test case dengan baik, seperti pada umumnya.

Lalu, ketika memasukan banyaknya mahasiswa, yaitu `n`, nilai ini digunakan untuk membuat ukuran vector, dengan tipe data struct yang telah dibuat, sehingga akan bisa menampung nama, skill gemas dan skill cantik.

```cpp
int n;
cin >> n;
vector<Mhs> v(n);
for (auto &x : v) cin >> x.name >> x.gemas >> x.cantik;
```

Jika melihat ke editorial, kita perlu memikirkan bahwa mahasiswa dengan skill gemas yang tinggi, mungkin juga memiliki skill cantik yang tinggi, sehingga jika mahasiswa tersebut dimasukan ke tim dengan fokus pada skill gemas, maka harus ada kandidat pengganti yang skill cantiknya ada dibawahnya.

Untuk bisa melakukan hal tersebut, kita bisa menyiapkan 3 orang dengan kemampuan gemas dan cantik tertinggi, dan juga menyiapkan 3 masing-masing kandidat untuk tim dengan kegemasan dan kecantikan tertinggi sebagai penggantinya. Ini artinya kita perlu menyiapkan 6 orang dengan kegemasan dan kecantikan tertinggi.

Untuk bisa melakukanya, kita perlu sorting custom, mengurutkan dari terbesar ke terkecil mahasiswa dengan kegemasan tertinggi, lalu mengambil 6 terbesar:

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b) {
	return a.gemas > b.gemas;
});
vector<Mhs> topGemas(v.begin(), v.begin() + min(6, n));
```

Lakukan juga sorting custom untuk mengurutkan mahasiswa dengan kecantikan dari terbesar ke terkecil, lalu ambil 6 terbesar:

```cpp
sort(v.begin(), v.end(), [](auto &a, auto &b) {
	return a.cantik > b.cantik;
});
vector<Mhs> topCantik(v.begin(), v.begin() + min(6, n));
```

Buat variabel yang digunakan untuk membandingkan nilai, dan juga vector yang menampung daftar jawaban:

```cpp
long long best = LLONG_MIN;
vector<string> ans;
```

Nah, bagian krusial dan logika utama algoritma ada dibagian selanjutnya, tapi melihat betapa rumitnya penulisan, jadi akan dijelaskan secara bertahap, diikuti logika dibaliknya.

Untuk mencoba mengecek semua kombinasi dari 12 mahasiswa dengan skill gemas dan cantik tertinggi, digunakan 6 nested loops. Oke, biasanya penggunaan nested loops terlalu banyak, berkaitan dengan kompleksitas waktu yang buruk, dan beresiko terkena runtime limit. Tetapi pada kasus ini, batasan-batasan yang digunakan cukup kecil, sehingga walaupun terdapat 6 nested loops, sepertinya kode ini berhasil untuk tidak melewati runtime limit yang ditentukan, jadi masih bisa dan aman.

Dan faktanya kode ini masuk ke jajaran runtime tercepat, itulah alasan kita mebedahnya disini.

Perhatikan perulangan ini:

```cpp
for (int i = 0; i < (int)topGemas.size(); i++) {
	for (int j = i + 1; j < (int)topGemas.size(); j++) {
		for (int k = j + 1; k < (int)topGemas.size(); k++) {
			for (int a = 0; a < (int)topCantik.size(); a++) {
				for (int b = a + 1; b < (int)topCantik.size(); b++) {
					for (int c = b + 1; c < (int)topCantik.size(); c++) {}
				}
			}
		}
	}
}
```

3 perulangan pertama, berfokus pada tim gemas, dan 3 perulangan terakhir, berfokus pada tim cantik. 

Untuk bisa menemukan kombinasi yang tepat, perhatikan bahwa perulangan ini:

```cpp
for (int i = 0; i < (int)topGemas.size(); i++) {
	for (int j = i + 1; j < (int)topGemas.size(); j++) {
		for (int k = j + 1; k < (int)topGemas.size(); k++) {}
	}
}
```

... selalu dimulai dengan satu tingkat lebih besar dari inisialisasi perulangan sebelumnya. Misal perulangan pertama dimulai dari `i = 0`, maka perulangan kedua dimulai dari `j = i+1`, dan perulangna kedua dimulai dari `k = j+1`. Begitu juga 3 perulangan dibawahnya, yang berfokus pada tim cantik.

Mungkin ini adalah metode yang tepat untuk digunakan, agar bisa mencari kombinasi 6 mahasiswa yang pas untuk masing-masing tim.

Perhatikan juga bahwa batasan yang digunakan rata-rata adalah `(int)topGemas.size()` dan juga `(int)topCantik.size()`. Well, sebenarnya ini tidak perlu, karena nilai N atau banyaknya mahasiswa yang diinputkan, adalah $N \geq 6$, artinya semua batasan tadi bisa diganti dengan angka 6, sehingga lebih simple dan readeble.

Perhatikan kode ini:

```cpp
set<string> allNames = {
	topGemas[i].name, topGemas[j].name, topGemas[k].name,
	topCantik[a].name, topCantik[b].name, topCantik[c].name
};
```

Struktur data set adalah struktur data yang hanya menyimpan elemen unik, dia tidak akan memasukan suatu elemen baru jika sudah ada elemen yang sama didalamnya. Set digunakan disini karena kita perlu memastikan bahwa setiap mahasiswa yang dipilih, hanya dipilih sekali, dan hanya dimasukan di salah satu tim saja, tidak boleh di dua tim, dan setiap tim harus terdiri dari 3 mahasiswa yang berbeda, yang artinya wajib hukumnya semua 6 mahasiswa yang dipilih adalah berbeda semuanya.

Mekanisme ini membuat proses pemeriksaan mahasiswa yang berbeda jauh lebih mudah, karena kita cukup memerika, jika ukuran set kurang dari 6, maka artinya perulangan tersebut sedang mengambil kombinasi dari mahasiswa yang duplikat, sehingga perulangan bisa langsung kita `continue`:

```cpp
if ((int)allNames.size() < 6) continue; // ada dobel
```

Tapi jika mahasiswa semuanya berbeda, maka tahap selanjutnya adalah mencoba menghitung score mereka, sesuai dengan deskripsi dari soal, yang mana tim dari gemas dikalikan, lalu ditambah dari tim cantik yang dikalikan:

```cpp
long long score =
	topGemas[i].gemas * topGemas[j].gemas * topGemas[k].gemas +
	topCantik[a].cantik * topCantik[b].cantik * topCantik[c].cantik;
```

Setelah itu, kita lakukan perbandingan dengan variabel `best`, jika nilai score kombinasi sekarang lebih besar dari `best`, maka update nilai `best` ke nilai score sekarang, dan simpan 6 data mahasiswa tadi. 

Algoritma ini akan mengambil dan menyimpan setiap kombinasi yang menghasilkan kombinasi tertinggi, dan memperbarui jawabanya di vector `ans`.

Setelah itu, outputkan jawabanya dengan mengoutputkan total score tertinggi dari kombinasi yang didapat, dan juga 3 mahasiswa terbaik untuk tim gemas, dan 3 mahasiswa terbaik untuk tim cantik:

```cpp
cout << best << "\n";
for (int i = 0; i < 6; i++) {
	cout << ans[i];
	if (i == 2) cout << "\n";
	else cout << " ";
}
cout << "\n";
```

---
# 4 | Experimentation

```ad-attention
title:Experimentation ⚙️
Melakukan eksperimen terkontrol pada kode untuk memvalidasi pemahaman, mengeksplorasi variasi, dan mengamati perilaku program.
```

Berikut adalah salah satu kode eksperimen ku yang berhasil, bahkan masuk top user by time:

```cpp
/*
Author  : Riveris
Date    : 2025-08-23 02:37
Problem : TLX-Toki | C - Gemastik-2016-Menggemaskan dan Cantik
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <ranges>
#include <set>
#include <vector>
using namespace std;

#define debug(x) cout << x << '\n';
using ll = long long;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

struct Mhs {
   string name;
   ll G, C;
};

void solve() {
   int n;
   cin >> n;
   vector<Mhs> user(n);

   for (auto& x : user) {
      cin >> x.name >> x.G >> x.C;
   }

   ranges::sort(user, [](const auto& a, const auto& b) { return a.G > b.G; });
   vector<Mhs> gemas(user.begin(), user.begin() + 6);

   ranges::sort(user, [](const auto& a, const auto& b) { return a.C > b.C; });
   vector<Mhs> cantik(user.begin(), user.begin() + 6);

   ll topScore = LLONG_MIN;
   vector<string> rest;

   for (int i = 0; i < 6; i++) {
      for (int j = i + 1; j < 6; j++) {
         for (int k = j + 1; k < 6; k++) {
            for (int x = 0; x < 6; x++) {
               for (int y = x + 1; y < 6; y++) {
                  for (int z = y + 1; z < 6; z++) {
                     set<string> diff = {gemas[i].name,  gemas[j].name,  gemas[k].name,
                                         cantik[x].name, cantik[y].name, cantik[z].name};

                     if (diff.size() < 6)
                        continue;

                     ll temp = (gemas[i].G * gemas[j].G * gemas[k].G) + (cantik[x].C * cantik[y].C * cantik[z].C);

                     if (temp > topScore) {
                        topScore = temp;
                        rest = {gemas[i].name,  gemas[j].name,  gemas[k].name,
                                cantik[x].name, cantik[y].name, cantik[z].name};
                     }
                  }
               }
            }
         }
      }
   }

   cout << topScore << '\n';
   for (int i = 0; i < 6; i++) {
      if (i == 3)
         cout << '\n';
      cout << rest[i] << " ";
   }

   cout << '\n';
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

Kode ini sudah berhasil di ACC. Ada beberapa kali WA, yang ketika diperiksa, disebabkan oleh kesalahan penggunaan tipe data `int temp`, yang ternyata mengalami overflow, sehingga harus menggunakan tipe data `long long`.

Walaupun sudah masuk ke top user by time, namun jika diperhatikan lagi, masih bisa ditingkatkan!

---
# 5 | Hypothesis
## 5.1 | Pertama

```ad-attention
Merumuskan dugaan awal terkait mekanisme atau strategi yang mendasari solusi.
```

Pertama, melakukan operasi sorting itu memakan kompleksitas waktu yang lumayan berat, yaitu $O(n \log n)$, dan itu dilakukan bahkan hingga 2 kali. Karena hanya diambil 6 mahasiswa dengan skill gemas dan cantik tertinggi, dan urutan dari 6 mahassiwa tersebut juga tidak penting, mungkin lebih baik menggunakan fungsi `nth_element()` alih-alih custom `sort`.

```ad-info
🔹 Apa itu `nth_element`?

`nth_element` adalah algoritma di C++ STL yang gunanya menaruh elemen ke-$k$ pada posisi yang benar seolah-olah array sudah terurut, tapi tidak benar-benar mengurutkan semuanya.

Syaratnya:
- Semua elemen di kiri posisi ke-$k$ nilainya $≥$ elemen ke-$k$ (kalau descending).
- Semua elemen di kanan posisi ke-$k$ nilainya $≤$ elemen ke-$k$.
- Tapi urutan dalam kiri/kanan tidak dijamin terurut.

Jadi dia setengah sorting → kompleksitas $O(n)$ rata-rata, lebih cepat daripada sort yang $O(n \log n)$.
```

Kedua, melakukan pengurutan langsung pada data input yang berupa struktur (`struct Mhs`) berpotensi menimbulkan beban waktu dan memori yang lebih besar, karena setiap operasi perbandingan maupun penukaran elemen melibatkan objek yang menyimpan string dan bilangan. Hal ini membuat proses sort menjadi lebih berat akibat adanya duplikasi data, alokasi dinamis untuk string, serta overhead penyalinan struktur. 

Sebaliknya, dengan hanya melakukan pengurutan pada indeks (`vector<int>`), data asli tetap utuh dan tidak berpindah, sementara proses sort hanya bekerja dengan bilangan bulat sebagai representasi posisi data. Strategi ini secara hipotesis akan lebih efisien baik dari sisi waktu, karena operasi perbandingan menjadi lebih ringan, maupun dari sisi memori, karena tidak ada redundansi penyalinan string maupun struktur besar.

Ketiga, penggunaan set pada setiap perulangan mengakibatkan overhead tambahan, mungkin jika ingin mengoptimlkan memory, lebih baik menggunakan percabangan `if`. Namun penerapan ini harus melihat situasi dan kondisi, karena harus memilih, kode yang lebih cepat, atau penulisan kode yang lebih cepat, karena di kontes, optimasi kecil seperti ini terlalu mahal jika mengakibatikan penulisan kode yang lebih lama.

## 5.2 | Kedua

```ad-attention
Menyempurnakan hipotesis berdasarkan hasil eksperimen dan pengamatan.
```

Ternyata, jika dipikir-pikir, penggunaan vector untuk `gemas`, `cantik`, dan `rest` bisa diganti dengan array, karena ukuran mereka tetap, yaitu adalah 6 saja. Dengan mengganti vector ke array, ini mengurangi alokasi memory dinamis.

Walaupun array di C++ tidak selalu lebih hemat dibandingkan std::vector, tetapi bisa lebih hemat karena tidak memiliki overhead dinamis seperti alokasi memori tambahan atau manajemen ukuran yang tidak perlu untuk menyimpan kapasitasnya, sehingga lebih cocok untuk data yang ukurannya sudah pasti.

Namun, jika ukuran data tidak pasti, std::vector lebih fleksibel dan seringkali lebih praktis, walaupun ada sedikit overhead untuk manajemen ukuran dinamisnya.

---

# 6 | Reconstruction (My Implementation)

## 6.1 | Kode Pertama

```ad-attention
Implementasi awal yang mereplikasi strategi inti berdasarkan pemahaman sendiri.
```

Berikut adalah kode yang aku buat setelah melakukan beberapa pengamatan, eksperimen, dan hipotesis. Kode ini cukup cepat, dengan  runtime hanya 172 ms, menempati peringkat 3 di leaderboard top users by runtime, namun dari segi memory, ternyata masih kurang, yaitu masih berada di kisaran 3124 kb. Berikut kodenya:

```cpp
/*
Author  : Riveris
Date    : 2025-08-23 04:17
Problem : TLX-Toki | C - Gemastik-2016-Menggemaskan dan Cantik
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

#define debug(x) cout << x << '\n';
using ll = long long;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

struct Mhs {
   string name;
   ll G, C;
};

void solve() {
   int n;
   cin >> n;
   vector<Mhs> user(n);
   vector<int> idx(n);
   iota(idx.begin(), idx.end(), 0);

   for (auto& x : user) {
      cin >> x.name >> x.G >> x.C;
   }

   nth_element(idx.begin(), idx.begin() + 6, idx.end(),
               [&](const auto& a, const auto& b) { return user[a].G > user[b].G; });
   vector<int> gemas(idx.begin(), idx.begin() + 6);

   nth_element(idx.begin(), idx.begin() + 6, idx.end(),
               [&](const auto& a, const auto& b) { return user[a].C > user[b].C; });
   vector<int> cantik(idx.begin(), idx.begin() + 6);

   ll topScore = LLONG_MIN;
   vector<int> rest;

   for (int i = 0; i < 6; i++) {
      for (int j = i + 1; j < 6; j++) {
         for (int k = j + 1; k < 6; k++) {
            for (int x = 0; x < 6; x++) {
               for (int y = x + 1; y < 6; y++) {
                  for (int z = y + 1; z < 6; z++) {
                     if (gemas[i] == cantik[x] || gemas[i] == cantik[y] || gemas[i] == cantik[z] ||
                         gemas[j] == cantik[x] || gemas[j] == cantik[y] || gemas[j] == cantik[z] ||
                         gemas[k] == cantik[x] || gemas[k] == cantik[y] || gemas[k] == cantik[z])
                        continue;

                     ll temp = (user[gemas[i]].G * user[gemas[j]].G * user[gemas[k]].G) +
                               (user[cantik[x]].C * user[cantik[y]].C * user[cantik[z]].C);

                     if (temp > topScore) {
                        topScore = temp;
                        rest = {gemas[i], gemas[j], gemas[k], cantik[x], cantik[y], cantik[z]};
                     }
                  }
               }
            }
         }
      }
   }

   cout << topScore << '\n';
   for (int i = 0; i < 6; i++) {
      if (i == 3)
         cout << '\n';
      cout << user[rest[i]].name << " ";
   }

   cout << '\n';
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

## 6.2 | Kode Kedua

```ad-attention
Versi optimasi dan penyempurnaan, meningkatkan efisiensi, readability, atau algoritma.
```

Hipotesis kedua adalah dengan mengganti beberapa vector dengan array, untuk mengurangi penggunaan alokasi memory dinamis, sehingga didapat runtime yang sedikit lebih cepat, dan memory yang lebih kecil:

```cpp
/*
Author  : Riveris
Date    : 2025-08-23 05:30
Problem : TLX-Toki | C - Gemastik-2016-Menggemaskan dan Cantik
*/

#include <algorithm>
#include <array>
#include <climits>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

#define debug(x) cout << x << '\n';
using ll = long long;

inline void fastio() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
}

struct Mhs {
   string name;
   ll G, C;
};

void solve() {
   int n;
   cin >> n;
   vector<Mhs> user(n);
   vector<int> idx(n);
   array<int, 6> gemas, cantik;
   iota(idx.begin(), idx.end(), 0);

   for (auto& x : user) {
      cin >> x.name >> x.G >> x.C;
   }

   nth_element(idx.begin(), idx.begin() + 6, idx.end(), [&](int a, const auto& b) { return user[a].G > user[b].G; });
   copy(idx.begin(), idx.begin() + 6, gemas.begin());

   nth_element(idx.begin(), idx.begin() + 6, idx.end(), [&](int a, int b) { return user[a].C > user[b].C; });
   copy(idx.begin(), idx.begin() + 6, cantik.begin());

   ll topScore = LLONG_MIN;
   array<int, 6> rest;

   for (int i = 0; i < 6; i++) {
      for (int j = i + 1; j < 6; j++) {
         for (int k = j + 1; k < 6; k++) {
            for (int x = 0; x < 6; x++) {
               for (int y = x + 1; y < 6; y++) {
                  for (int z = y + 1; z < 6; z++) {
                     if (gemas[i] == cantik[x] || gemas[i] == cantik[y] || gemas[i] == cantik[z] ||
                         gemas[j] == cantik[x] || gemas[j] == cantik[y] || gemas[j] == cantik[z] ||
                         gemas[k] == cantik[x] || gemas[k] == cantik[y] || gemas[k] == cantik[z])
                        continue;

                     ll temp = (user[gemas[i]].G * user[gemas[j]].G * user[gemas[k]].G) +
                               (user[cantik[x]].C * user[cantik[y]].C * user[cantik[z]].C);

                     if (temp > topScore) {
                        topScore = temp;
                        rest = {gemas[i], gemas[j], gemas[k], cantik[x], cantik[y], cantik[z]};
                     }
                  }
               }
            }
         }
      }
   }

   cout << topScore << '\n';
   for (int i = 0; i < 6; i++) {
      if (i == 3)
         cout << '\n';
      cout << user[rest[i]].name << " ";
   }

   cout << '\n';
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

---

# 7 | Knowledge Extraction

```ad-example
title:Knowledge Extraction
Mengisolasi insight, pola, dan trik algoritmik yang dapat diterapkan secara umum pada permasalahan serupa.
```

- Perhatikan penggunaa tipe data, karena aku mengalami WA beberapa kali, gara-gara menggunakan tipe data `int`, yang tidak cukup kuat untuk menampung hasil perkalian, mengakibatkan overflow! Perhatikan soal, dan amati, tipe data apa yang cocok. Jika ada kemungkinan angka yang terakumulasi sangat besar, beralih saja ke `long long`!
- Pelajari fungsi `nth_element()`, karena jika hanya diambil kumpulan nilai tertinggi, dan kumpulan nilai tertinggi tersebut tidak perlu urut, maka tidak perlu full sorting! Hal ini membuat kompleksitas lebih efisien!

---
# 8 | Reflection

```ad-success
Mengevaluasi efektivitas proses pembelajaran, mengidentifikasi keberhasilan, kelemahan, dan peluang untuk aplikasi di konteks lain.
```

Soal masuk ke ranah kombinasi dan bruteforce. Menitik beratkan pada algoritma memilih kombinasi yang tepat. Pertama kalinya menggunakan perulangan nested loops sebanyak ini. Aku kira ini pendekatan yang buruk, tapi ternyata ada beberapa problem statement yang memang bisa diselesaikan secara efisien dengan cara ini. Asalkan nested loops sebanyak itu memiliki batasan yang kecil, sepertinya masih aman dari runtime limit haha.