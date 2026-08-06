---
obsidianUIMode: preview
note_type: latihan
latihan: Multi-Level Feedback Queue
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T19:43:00
---
---
# 1 | Multi-Level Feedback Queue (MLFQ) Simplified
Kali ini kita coba simulasi sistem antrian dengan beberapa level. Bayangkan ada 2 level queue:

1. Queue Level 1 (prioritas tinggi) dengan *time quantum* = `TQ1`.
2. Queue Level 2 (prioritas rendah) dengan *time quantum* = `TQ2`.

Aturannya:

* Semua proses masuk **Queue Level 1** terlebih dahulu. 
* Saat dieksekusi:
  * Jika proses selesai dalam `TQ1` → selesai, catat waktu selesai.
  * Jika proses butuh lebih lama → kurangi waktunya, lalu turunkan ke **Queue Level 2**.
* Di **Queue Level 2**, proses dijalankan dengan *time quantum* = `TQ2` menggunakan aturan Round Robin.
* Eksekusi berjalan terus sampai semua proses selesai.

Cetak waktu selesai masing-masing proses dalam urutan `P1 … PN`.

### Input Format

```
N
t1 t2 ... tN
TQ1 TQ2
```

* `N` = jumlah proses.
* `t1 … tN` = waktu eksekusi masing-masing proses.
* `TQ1` = time quantum queue level 1.
* `TQ2` = time quantum queue level 2.

### Contoh

**Input**:

```
3
5 12 7
4 6
```

**Simulasi**:

* Semua proses masuk Q1.
* P1: butuh 5, TQ1=4 → sisa 1 → turun ke Q2. waktu=4
* P2: butuh 12, TQ1=4 → sisa 8 → turun ke Q2. waktu=8
* P3: butuh 7, TQ1=4 → sisa 3 → turun ke Q2. waktu=12
* Sekarang semua ada di Q2, TQ2=6.
* P1: butuh 1 → selesai di waktu 13.
* P2: butuh 8, dapat 6 → sisa 2 → balik ke belakang. waktu=19
* P3: butuh 3 → selesai di waktu 22.
* P2: sisa 2 → selesai di waktu 24.

**Output**:

```
13 24 22
```



⚠️ Di sini kamu harus handle **dua queue berbeda** dan memindahkan proses antar-queue.
Udah mulai mirip sistem operasi beneran 😏🔥


<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku:

```cpp
#include <iostream>
#include <iterator>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    queue<tuple<int, int, bool>> daque;
    vector<int> finishTime(n);
    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        daque.emplace(i, x, true);
    }

    int q1 = 0;
    int q2 = 0;
    cin >> q1 >> q2;
    int ans = 0;

    while (!daque.empty()) {
        auto [idx, val, lvlOne] = daque.front();

        if (lvlOne) {
            if (val <= q1) {
                ans += val;
                finishTime[idx] = ans;
                daque.pop();
            } else {
                ans += q1;
                lvlOne = false;
                val -= q1;
                daque.pop();
                daque.emplace(idx, val, lvlOne);
            }
        } else {
            if (val <= q2) {
                ans += val;
                finishTime[idx] = ans;
                daque.pop();
            } else {
                ans += q2;
                val -= q2;
                daque.pop();
                daque.emplace(idx, val, lvlOne);
            }
        }
    }

    for (int i = 0; i < ssize(finishTime); i++) {
        cout << finishTime[i];
        if (i != finishTime.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}
```

<br/>

---
# 3 | Editorial

## Alur Logika

1. **Dua level antrian**:

   * Semua proses masuk dulu ke **Level 1** (prioritas tinggi).
   * Jika tidak selesai di Level 1, proses diturunkan ke **Level 2**.

2. **Eksekusi Level 1 (Time Quantum = Q1)**:

   * Proses paling depan dijalankan maksimal `Q1` waktu.
   * Kalau selesai (sisa waktu ≤ Q1) → catat waktu selesai, buang dari antrian.
   * Kalau belum selesai → sisa waktu dikurangi `Q1`, lalu proses diturunkan ke Level 2.

3. **Eksekusi Level 2 (Time Quantum = Q2)**:

   * Semua proses di Level 2 berjalan dengan aturan Round Robin menggunakan `Q2`.
   * Sama: kalau selesai (sisa waktu ≤ Q2) → catat waktu selesai.
   * Kalau belum → sisa waktu dikurangi `Q2`, proses balik lagi ke belakang antrian (tetap di Level 2).

4. **Jam global (ans)**:

   * Setiap kali CPU bekerja (baik di Level 1 atau Level 2), total waktu `ans` bertambah sesuai berapa lama proses berjalan.
   * Saat proses selesai, `ans` dicatat sebagai waktu selesai proses tersebut.

5. **Berhenti**:

   * Simulasi selesai kalau antrian kosong (semua proses sudah beres).
   * Cetak hasil waktu selesai masing-masing proses dalam urutan P1..Pn.

## Alur Algoritma

1. **Inisialisasi**:

   * Masukkan semua proses `(index, execution_time, level=1)` ke dalam queue.
   * Siapkan array `finishTime` untuk menyimpan hasil.

2. **Loop utama** selama queue tidak kosong:

   * Ambil proses paling depan.
   * Kalau level = 1:

     * Eksekusi `min(val, Q1)`.
     * Jika selesai → catat `finishTime`.
     * Jika belum → turunkan ke Level 2 dengan sisa waktu.
   * Kalau level = 2:

     * Eksekusi `min(val, Q2)`.
     * Jika selesai → catat `finishTime`.
     * Jika belum → masukkan lagi ke belakang Level 2 dengan sisa waktu.

1. **Output**: cetak `finishTime` sesuai urutan index proses.
## Intuisi

* Level 1 memberi **kesempatan cepat** untuk proses singkat → mereka selesai lebih awal.
* Proses berat yang tidak selesai di Level 1 **turun ke Level 2** dan diproses secara adil dengan Round Robin.
* Dengan cara ini, sistem seolah-olah memberi prioritas lebih ke proses kecil/singkat tanpa mengabaikan proses besar.

---

👉 Jadi, intinya MLFQ bekerja dengan cara “uji dulu cepat di Level 1, kalau tidak beres, masuk Round Robin di Level 2”.
