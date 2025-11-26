---
obsidianUIMode: preview
note_type: latihan
latihan: Moving Average dari Stream
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-28T20:59:00
---
---
# 1 | Moving Average dari Stream

Sebuah sensor suhu menghasilkan data secara terus-menerus. Karena datanya terlalu banyak, sistem hanya ingin menyimpan **K bacaan terakhir** untuk menghitung **rata-rata bergerak (moving average)**.

Aturan:

1. Setiap kali ada data baru masuk, masukkan ke dalam queue.
2. Jika ukuran queue lebih besar dari `K`, keluarkan data yang paling lama.
3. Hitung rata-rata dari data dalam queue saat ini, lalu tampilkan.

**Input:**

* Baris pertama berisi dua bilangan bulat `N` dan `K`
  (`N` = jumlah data, `K` = ukuran jendela moving average).
* Baris kedua berisi `N` bilangan bulat, data sensor.

**Output:**

* Cetak rata-rata bergerak untuk setiap data masuk, dibulatkan ke bawah (floor).


**Contoh Input:**

```
8 3
4 7 9 3 5 8 6 2
```

**Proses:**

* Data masuk 4 → rata-rata = 4
* Data masuk 7 → rata-rata = (4+7)/2 = 5
* Data masuk 9 → rata-rata = (4+7+9)/3 = 6
* Data masuk 3 → rata-rata = (7+9+3)/3 = 6
* Data masuk 5 → rata-rata = (9+3+5)/3 = 5
* Data masuk 8 → rata-rata = (3+5+8)/3 = 5
* Data masuk 6 → rata-rata = (5+8+6)/3 = 6
* Data masuk 2 → rata-rata = (8+6+2)/3 = 5

**Output:**

```
4 5 6 6 5 5 6 5
```


👉 Soal ini melatih konsep **queue sebagai sliding window** — beda dengan simulasi antrian atau eliminasi.

<br/>

---
# 2 | Jawaban

Hoamm, ngatuk:

```cpp
#include <iostream>
#include <queue>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int k = 0;
    cin >> n >> k;

    int sum = 0;
    queue<int> suhu;

    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        if (suhu.size() < k) {
            suhu.push(x);
            sum += x;
            cout << sum / suhu.size() << " ";
        } else {
            sum -= suhu.front();
            suhu.pop();
            suhu.push(x);
            sum += x;
            cout << sum / suhu.size() << " ";
        }
    }
    return 0;
}
```

<br/>

---
# 3 | Editorial

Ini hanya soal pendinginan, untuk bersenang-senang saja. Latihan sesi pertama untuk struktur data queue akhirnya selesai.

Bagian ini aku rasa tidak perlu membuat editorial, karena masih tergolong mudah.