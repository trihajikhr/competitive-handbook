---
obsidianUIMode: preview
note_type: latihan
latihan: Printer Queue dengan Prioritas
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T20:34:00
---
---
# 1 | Printer Queue dengan Prioritas

Bayangkan sebuah printer yang melayani antrian cetak dokumen.
Setiap dokumen punya:

* Nomor dokumen (P1, P2, …, Pn).
* Prioritas (semakin besar angkanya, semakin tinggi prioritas).

Aturannya:

1. Program membaca $N$ (jumlah dokumen) dan $idx$ (index dokumen yang ingin kita ketahui kapan dicetak).
2. Program membaca $N$ bilangan bulat = prioritas masing-masing dokumen.
3. Printer bekerja dengan aturan:

   * Selalu ambil dokumen terdepan dari antrian.
   * Jika ada dokumen lain dengan prioritas lebih tinggi daripada dokumen ini, maka dokumen ini dipindahkan ke belakang antrian.
   * Jika tidak ada yang lebih tinggi, dokumen ini langsung dicetak (selesai).

Tentukan urutan ke berapa dokumen ke-`idx` dicetak.

### Contoh

**Input**:

```
6 0
1 1 9 1 1 1
```

**Simulasi**:

* Dokumen ke-0 prioritas 1.
* Ada dokumen dengan prioritas lebih tinggi (dokumen ke-2, prioritas 9), jadi ke-0 dipindah ke belakang.
* Cetak urutan:

  * Cetak dokumen ke-2 (prioritas 9).
  * Lanjut, dokumen ke-0 akhirnya akan dicetak di urutan ke-5.

**Output**:

```
5
```

⚠️ Tantangan:
Kamu harus menjaga urutan antrian sambil bisa cek apakah ada yang lebih prioritas di belakang.


<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku yang sudah benar:

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int t = 0;
    cin >> n >> t;

    if (t >= n) {
        cout << "Target diluar rentang!\n";
        return 0;
    }

    queue<pair<int, int>> daque;
    unordered_map<int, int> dasmap;
    vector<pair<int, int>> dataDocs;

    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        dasmap[x]++;
        daque.emplace(i, x);
    }

    dataDocs.reserve(dasmap.size());
    for (const auto& [key, val] : dasmap) {
        dataDocs.emplace_back(key, val);
    }

    ranges::sort(dataDocs, [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    int ans = 0;
    int idx = 0;
    while (true) {
        int curr = -1;
        if (dataDocs[idx].second > 0) {
            curr = dataDocs[idx].first;
        } else {
            idx++;
            continue;
        }

        if (daque.front().second < curr) {
            daque.push(daque.front());
            daque.pop();
        } else if (daque.front().second == curr) {
            if (daque.front().first == t) {
                ans++;
                break;
            }

            ans++;
            dataDocs[idx].second--;
            daque.pop();
        }
    }

    cout << ans << '\n';
    return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Intuisi Masalah

Kita diberi antrian dokumen, masing-masing punya nilai prioritas.
Proses pencetakan mengikuti aturan:

* Jika ada dokumen dengan prioritas lebih tinggi di antrian, dokumen di depan dipindahkan ke belakang.
* Jika dokumen di depan memiliki prioritas tertinggi, maka ia akan dicetak.

Tugasnya adalah menentukan **urutan ke berapa dokumen target (indeks `t`) dicetak**.

## 3.2 | Representasi Data

Program menyimpan dua struktur data utama:

1. **Queue `daque`**
   Menyimpan pasangan `(index, priority)`, sehingga kita tahu dokumen mana yang sedang diproses.

2. **Vector `dataDocs`**
   Menyimpan **jumlah dokumen** berdasarkan prioritas, lalu diurutkan descending (prioritas terbesar → terkecil). Tujuannya supaya kita selalu tahu *prioritas tertinggi yang masih tersisa*.

Contoh:
Input prioritas `[1, 1, 9, 1, 1, 1]` → `dataDocs = [(9, 1), (1, 5)]`.

## 3.3 | Alur Algoritma

1. **Baca input.**
   Masukkan semua dokumen ke queue `(index, priority)`.
   Catat frekuensi setiap prioritas ke dalam `dasmap`.

2. **Susun daftar prioritas tertinggi.**
   `dataDocs` diisi dari `dasmap`, lalu di-sort descending berdasarkan prioritas.

3. **Simulasi proses printer.**

   * Lihat prioritas tertinggi yang masih tersedia: `curr = dataDocs[idx].first`.
   * Bandingkan dengan elemen paling depan dari queue:

     * Jika **prioritas depan < curr**, berarti masih ada dokumen lebih penting → pindahkan dokumen depan ke belakang.
     * Jika **prioritas depan == curr**, dokumen ini boleh dicetak:

       * Tambah counter cetak `ans`.
       * Jika dokumen ini adalah target (indeks = `t`), selesai → output `ans`.
       * Jika bukan, kurangi jumlah dokumen dengan prioritas itu (`dataDocs[idx].second--`), lalu keluarkan dokumen dari queue.

4. **Ulangi sampai target tercetak.**


## 3.4 | Kompleksitas

* Queue operasi `push`/`pop`: $O(1)$ per langkah.
* `dataDocs` diurutkan sekali: $O(k \log k)$, dengan `k` = jumlah prioritas unik (≤ `n`).
* Total simulasi maksimal $O(n)$, karena setiap dokumen pasti keluar dari antrian sekali.

Sehingga kompleksitas total: $O(n \log n)$ (karena sorting).



## 3.5 | Contoh Eksekusi

Input:

```
6 0
1 1 9 1 1 1
```

* Target = indeks 0 (prioritas 1).
* Urutan cetak: `9` → lima dokumen `1` → akhirnya target.
* Hasil: `6`.

## 3.6 | Ringkasan

Algoritma ini menyimulasikan antrian dengan:

* Queue untuk urutan dokumen.
* Array frekuensi prioritas (terurut) untuk tahu siapa yang harus dicetak dulu.

Dengan pendekatan ini, kita bisa langsung menghitung **kapan target dicetak** tanpa harus memindai queue berulang kali.
