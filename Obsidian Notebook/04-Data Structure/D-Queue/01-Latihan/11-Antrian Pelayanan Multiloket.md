---
obsidianUIMode: preview
note_type: latihan
latihan: Antrian Pelayanan Multiloket
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T23:14:00
---
---
# 1 | Antrian Pelayanan Multiloket


Ada $K$ loket dan $N$ orang. Semua orang datang bersamaan ($t=0$) dengan waktu layanan masing-masing `t1..tN`.

Setiap loket hanya bisa melayani 1 orang sekaligus. Begitu sebuah loket kosong, dia langsung mengambil orang berikutnya dari antrian (urutan input). Jika beberapa loket kosong di saat yang sama, yang lebih kecil ID-nya duluan yang mengambil orang berikutnya.

### Output

Cetak ID loket (1-based) yang melayani masing-masing orang dalam urutan input ($N$ angka dalam satu baris).

### Catatan penting

* Polanya **bukan** sekadar 1,2,…,K berulang.
* Orang dengan waktu layanan panjang bikin loketnya sibuk lebih lama, sehingga orang berikutnya bisa “lompat” ke loket lain yang kebetulan sudah kosong.

### TC1 — Pola berubah karena durasi

```
N=5 K=2
3 2 1 5 4
```

**Output yang diharapkan:**

```
1 2 2 1 2
```

**Kenapa?**
t=0 → P1→L1 (selesai t=3), P2→L2 (t=2)
t=2 → L2 bebas → P3→L2 (t=3)
t=3 → L1 & L2 bebas barengan → L1 ambil P4 (t=8), L2 ambil P5 (t=7)

### TC2 — Job pertama sangat lama

```
N=6 K=3
7 1 1 1 1 1
```

**Output:**

```
1 2 3 2 3 2
```

### TC3 — Tie di waktu selesai (cek aturan “ID lebih kecil dulu”)

```
N=4 K=2
2 2 2 2
```

**Output:**

```
1 2 1 2
```

t=0 → P1→L1 (t=2), P2→L2 (t=2)
t=2 → L1 & L2 sama-sama kosong → L1 ambil P3 (t=4), lalu L2 ambil P4 (t=4)

### TC4 — Lebih bervariasi

```
N=6 K=3
2 4 3 2 5 2
```

**Output:**

```
1 2 3 1 3 1
```

### TC5 — Besar dan “berombak”

```
N=12 K=3
8 1 2 3 4 5 6 1 2 3 4 5
```

**Output:**

```
1 2 3 2 3 2 3 1 1 2 1 2
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah benar, walaupun mungkin dari segi kompleksitas waktu masih bisa ditingkatkan lagi:

```cpp
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int k = 0;
    cin >> n >> k;

    vector<int> loket(k);
    vector<int> userLoket(n);
    queue<pair<int, int>> antre;

    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;

        antre.emplace(i, x);
    }

    while (!antre.empty()) {
        for (int i = 0; i < k; i++) {
            if (loket[i] == 0) {
                if (!antre.empty()) {
                    userLoket[antre.front().first] = i + 1;
                    loket[i] = antre.front().second;
                    antre.pop();
                }
            }
        }

        int mins = INT_MAX;
        for (const auto& x : loket) {
            if (x > 0) {
                mins = min(mins, x);
            }
        }

        if (mins == INT_MAX) {
            break;
        }

        for (int i = 0; i < k; i++) {
            if (loket[i] > 0) {
                loket[i] -= mins;
            }
        }
    }

    for (const auto& x : userLoket) {
        cout << x << " ";
    }

    return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Deskripsi Masalah

Diberikan:

* `n` orang yang datang berurutan ke sebuah antrian.
* Setiap orang punya waktu layanan tertentu.
* Ada `k` loket yang melayani secara paralel.

Aturan:

1. Orang di depan antrean selalu masuk ke loket kosong dengan indeks terkecil.
2. Jika semua loket sibuk, waktu akan maju sesuai sisa waktu terkecil di antara loket, lalu loket yang selesai akan kembali kosong.
3. Tujuan: tentukan orang ke-i dilayani di loket mana.

## 3.2 Struktur Data yang Digunakan

1. **`vector<int> loket(k)`**
   Menyimpan **sisa waktu layanan** di setiap loket.

   * Jika `loket[i] == 0`, maka loket ke-`i` sedang kosong.

2. **`queue<pair<int,int>> antre`**
   Menyimpan antrean orang dalam bentuk `(indeks, waktu_layanan)`.

   * `indeks`: posisi orang dalam antrean (0-based).
   * `waktu_layanan`: berapa lama butuh dilayani.

3. **`vector<int> userLoket(n)`**
   Menyimpan hasil: orang ke-`i` dilayani di loket nomor berapa.

## 3.3 | Alur Algoritma

1. **Input**
   * Baca jumlah orang `n` dan jumlah loket `k`.
   * Baca waktu layanan masing-masing orang, lalu masukkan ke dalam `antre`.

2. **Simulasi**
   Selama antre masih ada orang:

   * **Step 1: Isi loket kosong**
     Cek semua loket satu per satu. Jika kosong (`loket[i] == 0`), ambil orang terdepan dari antre, masukkan ke loket, dan catat hasil ke `userLoket`.

   * **Step 2: Cari waktu minimum**
     Dari semua loket yang sibuk (`loket[i] > 0`), ambil nilai minimum (`mins`). Ini menunjukkan **berapa lama sampai ada loket yang selesai**.

   * **Step 3: Maju waktu**
     Kurangi semua loket sibuk dengan `mins`.
     → Artinya kita memajukan waktu hingga ada setidaknya satu loket yang bebas.

   * **Step 4: Ulangi**
     Balik lagi ke step 1 sampai antre kosong.

3. **Output**
   Cetak array `userLoket` yang menunjukkan orang ke-`i` dilayani di loket nomor berapa.


## 3.4 | Contoh Eksekusi

Input:

```
5 2
3 2 1 5 4
```

### Proses:

* **Awal**
  antre = \[(0,3),(1,2),(2,1),(3,5),(4,4)]
  loket = \[0,0]

* **Step 1: Isi loket kosong**
  Orang 0 (3) → loket 1
  Orang 1 (2) → loket 2
  loket = \[3,2]
  userLoket = \[1,2,*,*,\_]

* **Step 2: Cari mins = 2**
  Kurangi semua: loket = \[1,0]

* **Step 3: Isi lagi**
  Orang 2 (1) → loket 2
  loket = \[1,1]
  userLoket = \[1,2,2,*,*]

* **Step 4: Cari mins = 1**
  Kurangi semua: loket = \[0,0]

* **Step 5: Isi lagi**
  Orang 3 (5) → loket 1
  Orang 4 (4) → loket 2
  loket = \[5,4]
  userLoket = \[1,2,2,1,2]

* Antre kosong → selesai.

### Output:

```
1 2 2 1 2
```

## 3.5 | Analisis Kompleksitas

* Pengisian loket: $O(n)$ karena setiap orang hanya sekali dimasukkan.
* Pencarian waktu minimum: $O(k)$ per iterasi.
* Total kompleksitas:

  $$
  O(n \cdot k)
  $$

  → Efisien untuk ukuran kompetisi (misalnya $n,k ≤ 10^5$).


## 3.6 | Intuisi

Alih-alih mensimulasikan setiap detik (yang tidak efisien), algoritma ini hanya maju sampai ada event penting: loket selesai melayani. Dengan begitu, simulasi berjalan cepat meskipun waktu layanan sangat besar.


✨ Jadi, programmu ini bisa dilihat sebagai **event-driven simulation**: kita melompati waktu dari satu event (loket selesai) ke event berikutnya, tanpa membuang waktu di sela-sela.

