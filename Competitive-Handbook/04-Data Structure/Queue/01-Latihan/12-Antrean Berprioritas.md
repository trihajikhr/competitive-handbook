---
obsidianUIMode: preview
note_type: latihan
latihan: Antrean Berprioritas
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-28T04:23:00
---
---
# 1 | Antrean Berprioritas

Ada $n$ orang mengantri untuk dilayani di $k$ loket. Setiap orang memiliki:

* `t` = waktu pelayanan
* `p` = tingkat prioritas (angka lebih kecil berarti **lebih prioritas**).

Aturan pelayanan:

1. Jika ada loket kosong, orang antrean terdepan dengan prioritas tertinggi masuk lebih dulu.
2. Jika ada beberapa orang dengan prioritas sama, yang lebih dulu datang lebih didahulukan.
3. Jika semua loket sibuk, waktu maju sampai ada loket yang selesai, lalu ulangi aturan di atas.

Tugasmu: tentukan **loket mana yang melayani tiap orang**.
### Format Input

```
n k
t1 p1
t2 p2
...
tn pn
```

* `n` = jumlah orang
* `k` = jumlah loket
* `ti` = waktu layanan orang ke-i
* `pi` = prioritas orang ke-i

### Format Output

Cetak $n$ bilangan, di mana elemen ke-$i$ menunjukkan orang ke-$i$ dilayani di loket berapa.

### Contoh Input

```
6 2
5 2
3 1
4 1
6 3
2 2
1 1
```

### Proses Singkat

* Orang 1 (t=3, p=2) → loket 1
* Orang 2 (t=2, p=1) → loket 2 (lebih prioritas daripada antrean lain)
* Setelah 2 waktu, orang 2 selesai → loket 2 kosong. Orang 4 (t=5, p=1) masuk loket 2.
* dst.

### Output

```
1 1 2 2 2 1
```

### Catatan

Di sini, bedanya sama soal sebelumnya adalah **aturan antrean**:

* Bukan hanya FIFO, tapi **priority queue** berdasarkan `(p, urutan_datang)`.


<br/>

---
# 2 | Jawaban

## 2.1 | Jawaban Pertama
Berikut adalah jawabanku:

```cpp
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int k = 0;
    cin >> n >> k;

    vector<pair<pair<int, int>, int>> user(n);

    for (int i = 0, x = 0, y = 0; i < n; i++) {
        cin >> x >> y;
        user[i] = {{x, y}, i};
    }

    ranges::sort(user, [](const auto& a, const auto& b) {
        if (a.first.second == b.first.second) {
            return a.second < b.second;
        }
        return a.first.second < b.first.second;
    });

    vector<int> loket(k, 0);
    vector<int> finalQue(n);
    int idx = 0;

    while (idx < n) {
        for (int i = 0; i < k; i++) {
            if (idx < n && loket[i] == 0) {
                loket[i] = user[idx].first.first;
                finalQue[user[idx].second] = i + 1;
                idx++;
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

        for (auto& x : loket) {
            if (x > 0) {
                x -= mins;
            }
        }
    }

    for (const auto& x : finalQue) {
        cout << x << " ";
    }

    return 0;
}

```

## 2.2 | Untuk Tantangan Lebih

Jika semisal diminta untuk menggunakan array C-style sepenuhnya, mungkin implemetasinya adalah sebagai berikut:

```cpp
#include <iostream>
using namespace std;

struct Queue {
    int time;
    int prior;
    int index;
};

constexpr int SZ = 10005;

// NOLINTBEGIN

class Solution {
   public:
    static void swaping(Queue* a, Queue* b) {
        Queue temp = *a;
        *a = *b;
        *b = temp;
    }

    static void customSort(Queue user[], int n) {
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (user[j].prior > user[j + 1].prior) {
                    swaping(&user[j], &user[j + 1]);
                    swapped = true;
                } else if (user[j].prior == user[j + 1].prior) {
                    if (user[j].index > user[j + 1].index) {
                        swaping(&user[j], &user[j + 1]);
                        swapped = true;
                    }
                }
            }

            if (!swapped) {
                break;
            }
        }
    }
};

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int k = 0;
    cin >> n >> k;

    Queue user[SZ];

    for (int i = 0; i < n; i++) {
        cin >> user[i].time >> user[i].prior;
        user[i].index = i;
    }

    Solution::customSort(user, n);

    int idx = 0;
    int finalQue[SZ];
    int loket[SZ];

    for (int i = 0; i < k; i++) {
        loket[i] = 0;
    }

    while (idx < n) {
        for (int i = 0; i < k; i++) {
            if (idx < n && loket[i] == 0) {
                loket[i] = user[idx].time;
                finalQue[user[idx].index] = i + 1;
                idx++;
            }
        }

        int mins = 1e9;
        for (int i = 0; i < k; i++) {
            if (loket[i] > 0 && loket[i] < mins) {
                mins = loket[i];
            }
        }

        if (mins == 1e9) {
            break;
        }

        for (int i = 0; i < k; i++) {
            if (loket[i] > 0) {
                loket[i] -= mins;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << finalQue[i];
        if (i != n - 1) {
            cout << " ";
        }
    }

    // NOLINTEND
    return 0;
}
```

## 2.3 | Dengan Penerapan Class

Karena aku ingin belajar tentang class, maka aku buat sekalian dengan class, dengan menerapkan 4 pilar OOP:

```cpp
#include <iostream>
using namespace std;

constexpr int SIZE = 10005;

// NOLINTBEGIN

class Queue {
   private:
    struct Daque {
        int time;
        int prior;
        int index;
    };

    Daque user[SIZE];
    int rest[SIZE];
    int loket[SIZE];
    int n = 0;
    int k = 0;

    void merge(Daque user[], int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        Daque L[SIZE], R[SIZE];

        for (int i = 0; i < n1; i++) {
            L[i] = user[l + i];
        }

        for (int i = 0; i < n2; i++) {
            R[i] = user[mid + 1 + i];
        }

        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2) {
            if (L[i].prior < R[j].prior) {
                user[k++] = L[i++];
            } else if (L[i].prior > R[j].prior) {
                user[k++] = R[j++];
            } else {
                if (L[i].index < R[j].index) {
                    user[k++] = L[i++];
                } else {
                    user[k++] = R[j++];
                }
            }
        }

        while (i < n1) {
            user[k++] = L[i++];
        }

        while (j < n2) {
            user[k++] = R[j++];
        }
    }

    void divide(Daque user[], int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            divide(user, l, mid);
            divide(user, mid + 1, r);
            merge(user, l, mid, r);
        }
    }

    void operation() {
        int idx = 0;

        for (int i = 0; i < k; i++) {
            loket[i] = 0;
        }

        while (idx < n) {
            for (int i = 0; i < k; i++) {
                if (idx < n && loket[i] == 0) {
                    loket[i] = user[idx].time;
                    rest[user[idx].index] = i + 1;
                    idx++;
                }
            }

            int mins = 1e9;
            for (int i = 0; i < k; i++) {
                if (loket[i] > 0 && mins > loket[i]) {
                    mins = loket[i];
                }
            }

            if (mins == 1e9) {
                break;
            }

            for (int i = 0; i < k; i++) {
                if (loket[i] > 0) {
                    loket[i] -= mins;
                }
            }
        }
    }

   public:
    Queue() {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> user[i].time >> user[i].prior;
            user[i].index = i;
        }
    }

    virtual void getResult() {
        divide(user, 0, n - 1);
        operation();

        for (int i = 0; i < n; i++) {
            cout << rest[i];
            if (i != n - 1) {
                cout << " ";
            }
        }
    }
};

class Report : public Queue {
   public:
    void getResult() override {
        cout << "Hasil antrian:\n";
        Queue::getResult();
        cout << "\n================\n";
    }
};

// NOLINTEND

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Report rept;
    rept.getResult();
    return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Soal Singkat

* Ada `n` orang yang mengantri untuk dilayani di `k` loket.
* Setiap orang punya:

  * `t` → waktu pelayanan
  * `p` → tingkat prioritas (lebih kecil → lebih prioritas)
* Aturan:

  1. Jika ada loket kosong, antrean terdepan dengan prioritas tertinggi masuk dulu.
  2. Jika beberapa orang punya prioritas sama, yang datang lebih dulu didahulukan.
  3. Jika semua loket sibuk, waktu berjalan sampai ada loket selesai → ulangi aturan di atas.

Tugas: tentukan loket mana yang melayani tiap orang.

## 3.2 | Alur Logika Kode

1. **Input Data**

   * Baca jumlah orang `n` dan jumlah loket `k`.
   * Simpan setiap orang sebagai:

     ```cpp
     pair<pair<int,int>,int> → {{t, p}, index}
     ```

     * `t` = waktu pelayanan
     * `p` = prioritas
     * `index` = posisi asli orang dalam antrean

<br/>

2. **Sort Antrean Berdasarkan Prioritas**

   ```cpp
   ranges::sort(user, [](const auto& a, const auto& b){
       if (a.first.second == b.first.second) return a.second < b.second;
       return a.first.second < b.first.second;
   });
   ```

   * Urutkan berdasarkan prioritas (`p`), lebih kecil lebih didahulukan.
   * Tie-breaker: jika prioritas sama, orang datang lebih dulu (`index` lebih kecil) masuk lebih dulu.

<br/>

3. **Inisialisasi Loket dan Output**

   * `loket[k]` → menyimpan sisa waktu pelayanan di tiap loket.
   * `finalQue[n]` → menyimpan nomor loket tiap orang.
   * `idx` → pointer ke orang berikutnya di antrean.

<br/>

4. **Simulasi Layanan**

   * Loop sampai semua orang selesai (`idx < n`):

     1. **Isi Loket Kosong**

        ```cpp
        for i in 0..k-1:
            if loket[i] == 0:
                loket[i] = user[idx].first.first
                finalQue[user[idx].second] = i + 1
                idx++
        ```

        * Loket kosong diisi dari kiri ke kanan.
        * Orang antrean dengan prioritas tertinggi masuk dulu.
        * Catat nomor loket di `finalQue`.
     2. **Tentukan Waktu Minimum**

        ```cpp
        mins = min(loket[i] > 0)
        ```

        * Menentukan waktu tersingkat agar ada loket selesai.
     3. **Kurangi Waktu Loket**

        ```cpp
        for i in 0..k-1:
            if loket[i] > 0:
                loket[i] -= mins
        ```

        * Semua loket berjalan bersamaan selama `mins` unit waktu.
     4. **Ulangi** sampai semua orang dilayani.

5. **Output**

   * Cetak `finalQue[i]` → nomor loket yang melayani orang ke-i.

## 3.3 | Contoh Ilustrasi

#### Input:

```
6 2
5 2
3 1
4 1
6 3
2 2
1 1
```

#### Langkah Simulasi:

| Waktu | Loket 1  | Loket 2  | Antrean | Catatan                                |
| ----- | -------- | -------- | ------- | -------------------------------------- |
| 0     | 3 (idx1) | 4 (idx2) | 0,3,4,5 | Prioritas tertinggi masuk              |
| +3    | 0        | 1        | 0,3,4   | Kurangi waktu min(3), isi loket kosong |
| +1    | 5        | 0        | 3,4     | Kurangi waktu min(1), isi loket kosong |
| +2    | 3        | 6        | 4       | Kurangi waktu min(2), isi loket kosong |
| ...   | ...      | ...      | ...     | Lanjut sampai antrean habis            |

**Output Loket:**

```
1 1 2 2 2 1
```


## 3.4 |  Highlight Trik

1. **Stable Sort atau Tie-Breaker** → menjaga urutan orang saat prioritas sama.
2. **Min Waktu Loket** → menggerakkan “waktu global” secara efisien tanpa simulasi per unit waktu.
3. **Vector Loket & Queue Logika** → sederhana tapi cukup untuk skenario real-time.
4. **Index Tracking** → menyimpan urutan asli orang agar output sesuai indeks input.
