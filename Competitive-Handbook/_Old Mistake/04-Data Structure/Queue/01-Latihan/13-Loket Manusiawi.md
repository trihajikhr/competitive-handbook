---
obsidianUIMode: preview
note_type: latihan
latihan: Loket Manusiawi
sumber:
  - myself
tags:
  - data-structure
  - queue
date_learned: 2025-08-28T19:53:00
---
---
# 1 | Loket Manusiawi

Disebuah vila pantai, terdapat bar yang sangat ramai. Hari ini adalah malam tahun baru, banyak orang dari luar negri dan daerah luar memadati tempat tersebut. Vila tersebut cukup besar dan memiliki sekitar $K$ loket. 

Terdapat sekitar $N$ pelanggan yang berada di bar yang ingin memesan minuman, sehingga mereka harus antri di setiap loket yang tersedia. Setiap pelanggan diperbolehkan untuk memesan beberapa minuman, tapi karena pelanggan terlalu banyak, maka minuman hanya diberikan satu-persatu, dan jika ingin memesan lagi, harus mengantri kebelakang. 

Petugas yang bekerja di vila tersebut tidak bisa bekerja sepnuhnya, setiap waktu ke $Q$ pekerja yang bekerja pada loket ke $Q_i$ akan mulai beristirahat selama $t$ menit, sehingga loketnya menjadi kosong. 

Setiap pelanggan bisa dilayani dalam 1 menit.

Total waktu yang diberikan adalah $T$, dimana setiap $Q_i \leq T$.

Tentukan loket mana yang melayani pelanggan untuk kali terakhir pemesanan.

### Input

Baris pertama berisi empat bilangan bulat:

```
N K Q
```

- $N$ — jumlah pelanggan
- $K$ — jumlah loket
- $Q$ — jumlah kejadian istirahat

Selanjutnya terdapat $Q$ baris, masing-masing berisi tiga bilangan bulat:

```
Q_i L_i t_i
```

- $Q_i$ — waktu mulai istirahat
    
- $L_i$ — nomor loket yang beristirahat ($1 \leq L_i \leq K$)
    
- $t_i$ — durasi istirahat

Lalu baris terakhir berisi $N$ angka, dengan setiap $N_i$ menunjukan banyaknya minuman yang dipesan:

```
N1 N2 N3 N4 N4 ... Nn
```

### Batasan:

- $0 \leq N \leq 10000$
- $1 \leq K \leq 50$
- $1 \leq Q \leq 50$
- $1 \leq N_i \leq 10000$
- $1 \leq L_i \leq K$

Dijamin bahwa akan ada satu loket yang bekerja.

### Contoh:

```
10 4 5
1 1 3
2 2 4
1 5 1
5 3 2
3 4 2
5 5 3 6 3 4 5 6 8 3
```

<br/>

---
# 2 | Jawaban

## 2.1 | Jawaban Pertama

Berikut adalah jawabanku yang sudah termasuknya benar (menurutku):

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Data {
    int startTime;
    int noLoket;
    int duration;
};

namespace {
inline void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
}  // namespace

auto main() -> int {
    fastio();
    int n = 0;
    int k = 0;
    int q = 0;
    cin >> n >> k >> q;

    vector<int> finalQue(n);
    vector<Data> resting(q);
    vector<pair<bool, int>> loket(k, {true, 0});
    queue<pair<int, int>> pelanggan;

    for (int i = 0; i < q; i++) {
        cin >> resting[i].startTime >> resting[i].noLoket 
        >> resting[i].duration;
    }

    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        pelanggan.emplace(x, i);
    }

    ranges::sort(resting, [](const auto& a, const auto& b) { 
	    return a.startTime < b.startTime; 
    });

    int idx = 0;
    int counterTime = 1;
    while (!pelanggan.empty()) {
        for (int i = 0; i < k; i++) {
            if (loket[i].second > 0 && !loket[i].first) {
                loket[i].second--;
                if (loket[i].second == 0) {
                    loket[i].first = true;
                }
            }
        }

        while (idx < q && resting[idx].startTime == counterTime) {
            loket[resting[idx].noLoket - 1].second += 
	            resting[idx].duration;
            loket[resting[idx].noLoket - 1].first = false;
            idx++;
        }

        for (int i = 0; i < k; i++) {
            if (loket[i].first) {
                pelanggan.front().first--;
                if (pelanggan.front().first == 0) {
                    finalQue[pelanggan.front().second] = i + 1;
                    pelanggan.pop();
                } else {
                    pelanggan.push(pelanggan.front());
                    pelanggan.pop();
                }
            }
        }

        counterTime++;
    }

    for (int i = 0; i < n; i++) {
        cout << finalQue[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    return 0;
}

```

<br/>

---
# 3 | Editorial

Oke, aku jelaskan saja dengan menggunakan alur logika dan juga alur algoritmanya saja, tidak perlu terlalu teknis.

Pertama, ketahui dulu bagaimana hasil akhir bisa tercapai, yaitu meliputi:

- Setiap pelanggan mampu dilacak index antrean awalnya, dan menulis loket mana yang melayani pelanggan tersebut. Karena loket hanya melayani satu minuman, dan jika pelanggan tersebut masih memiliki minuman lagi maka pelanggan akan mengantri kebelakang, otomatis pelacakan index menjadi wajib. Maka dibuat inputan yang menerima pelanggan dengan menyimpan `banyaknya minuman` yang dipesan, dan juga `index` dari pelanggan tersebut.
<br/>

- Beberapa loket akan berhenti beroperasi karena beristirahat di waktu-waktu tertentu, dan juga ada `nomer loket` yang menunjukan loket mana yang beristirahat, dan juga berapa lama `durasi` dari loket tersebut beristirahat. Terdapat 3 data yang harus saling berdampingan, sehingga dibuatlah tipe data custom, yaitu struct `Data`.
<br/>

- Inputan informasi loket mana yang akan beristirahat, belum terurut. Sehingga perlu diurutkan, dengan cara mengatur kapan loket tersebut akan mulai beristirahat, atau `startTime`, dengan mengurutkanya secara ascending, atau dari kecil ke besar, karena waktu juga berjalan dari nilai kecil ke besar. Satuan waktu disini adalah sama.
<br/>

- Hasil akhir didapat ketika minuman pelanggan tertentu habis dilayani pada loket ke-$i$, dan lalu gunakan index yang tersimpan pada pelanggan untuk dijadikan index ke vector `finalQue`, lalu simpan nomor loketnya dengan cara `i+1`, karena kita menggunakan array 1-based array.

Berikut adalah algoritma utamanya:

```cpp
int idx = 0;
int counterTime = 1;
while (!pelanggan.empty()) {
	for (int i = 0; i < k; i++) {
		if (loket[i].second > 0 && !loket[i].first) {
			loket[i].second--;
			if (loket[i].second == 0) {
				loket[i].first = true;
			}
		}
	}

	while (idx < q && resting[idx].startTime == counterTime) {
		loket[resting[idx].noLoket - 1].second += 
			resting[idx].duration;
		loket[resting[idx].noLoket - 1].first = false;
		idx++;
	}

	for (int i = 0; i < k; i++) {
		if (loket[i].first) {
			pelanggan.front().first--;
			if (pelanggan.front().first == 0) {
				finalQue[pelanggan.front().second] = i + 1;
				pelanggan.pop();
			} else {
				pelanggan.push(pelanggan.front());
				pelanggan.pop();
			}
		}
	}

	counterTime++;
}
```

Perulangan `for` pertama bertujuan untuk mengurangi durasi istirahat setiap loket yang sedang masuk fase istirahat sebanyak 1 satuan waktu, ketika terdeteksi loket tersebut sedang `false`, atau memang sedang tidak aktif. Ketika pengurangan sebanyak 1 tidak menjadikan durasi istirahat dari loket tersebut menjadi 0, maka artinya loket tersebut masih akan beristirahat lebih lama. Tapi jika habis menjadi 0, maka loket tersebut siap bekerja kembali.

Perulangan `while` kedua bertujuan untuk membuat beberapa loket tidak aktif, jika semisal `counterTime` berada di waktu yang sama dengan awal waktu loket ke-$i$ mulai beristirahat. Ini akan menonaktifkan loket, dan juga menambahkan durasi waktu istirahat pada loket tersebut. Kenapa menggunakan while? Karena ada kemungkinan beberapa loket beristirahat di waktu yang sama, sehingga perlu dinonaktifkan bersamaan.

Lalu perulangan terakhir adalah mekanisme antrian. Jika ada loket ke-$i$ yang beroperasi, maka loket tersebut akan mengambil satu pelanggan. Lalu jumlah pesanan minuman dari pelanggan tersebut akan dikurangi dengan 1. Jika jumlah pesanan minuman pelanggan tersebut habis, atau menjadi nol, maka pelanggan tersebut selesai dilayani, sehingga dikeluarkan dari antrian, dan juga simpan indeks dari loket yang melayani. Tapi jika pelanggan sebelumnya masih ada pesanan yang belum terlayani, maka pelanggan akan kembali ke belakang, untuk mengantri lagi, hingga minumanya habis.

Perulangan while akan berhenti ketika antrian kosong, dengan kata lain, semua pelanggan sudah terlayani.