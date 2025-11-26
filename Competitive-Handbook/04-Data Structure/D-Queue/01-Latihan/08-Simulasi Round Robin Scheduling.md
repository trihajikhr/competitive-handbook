---
obsidianUIMode: preview
note_type: latihan
latihan: Simulasi Round Robin Scheduling
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T19:16:00
---
---
# 1 | Simulasi Round Robin Scheduling

Bayangkan kamu punya sekumpulan proses yang akan dieksekusi oleh CPU dengan algoritma Round Robin (pakai queue).

Aturannya:

1. Baca sebuah bilangan bulat $N$ (jumlah proses).
2. Baca $N$ bilangan bulat → masing-masing menyatakan lama eksekusi dari setiap proses `P1, P2, ..., PN`.
3. Baca sebuah bilangan bulat $TQ$ = *time quantum*.
4. Simulasikan algoritma Round Robin:

   * Setiap proses berjalan maksimal $TQ$ satuan waktu.
   * Jika proses selesai (waktu eksekusinya ≤ $TQ$), proses keluar dari antrian dan dicatat waktu total kapan selesai.
   * Jika belum selesai, kurangi waktunya sebanyak $TQ$, lalu masukkan kembali ke belakang queue.
1. Cetak waktu selesai masing-masing proses dalam urutan $P1 … PN$.

### Contoh

**Input**:

```
3
5 8 6
4
```

**Proses simulasi**:

* P1 jalan 4 → sisa 1 → balik ke belakang.
* P2 jalan 4 → sisa 4 → balik ke belakang.
* P3 jalan 4 → sisa 2 → balik ke belakang.
* P1 jalan 1 → selesai pada waktu 13.
* P2 jalan 4 → selesai pada waktu 17.
* P3 jalan 2 → selesai pada waktu 19.

**Output**:

```
13 17 19
```


⚠️ Di sini kamu harus bener-bener mikir gimana cara nyimpen **index proses** + **sisa waktu eksekusi** di queue, bukan cuma angkanya doang.

<br/>

---
# 2 | Jawaban

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    queue<pair<int, int>> daque;
    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        daque.emplace(i, x);
    }

    int tq = 0;
    cin >> tq;

    vector<int> rest(n, 0);
    int ans = 0;

    while (!daque.empty()) {
        if (daque.front().second <= tq) {
            ans += daque.front().second;
            rest[daque.front().first] = ans;
            daque.pop();
        } else {
            ans += tq;
            daque.front().second -= tq;
            pair<int, int> temp = daque.front();
            daque.pop();
            daque.push(temp);
        }
    }

    for (const auto& x : rest) {
        cout << x << " ";
    }

    return 0;
}
```

<br/>

---
# 3 | Editorial

Tantangan dalam problem ini terletak dimana kita harus mampu mendapatkan indeks yang sesuai, dari data yang terus berputar-putar pada struktur data queue. Ketika antrian memiliki nilai yang terlalu besar, maka antrian tersebut nilainya dikurangi, dan mengulang ke belakang. Dan jika nilai antrian kurang dari batas yang diberikan, yaitu `tq`, maka antrian tersebut akan dikeluarkan dari antrian, dan dicatat waktu yang dibutuhkan untuk antrian tersebut keluar dari queue.

Karena data didalam queue tersebut terus diputar-putar, berkali-kali, akan sulit untuk mentrace atau mengikuti indeksnya, karena problem meminta kita mengoutputkan jumlah waktu yang dibutuhkan dengan rapi, seperti susunan ketika input dimasukan.

Solusinya cukup mudah, kita bisa menggunakan bantuan `pair`, yang mana salah satu nilainya kita gunakan untuk disisipi nilai indeks ketika inputan, dan satunya adalah nilai dari antrian itu sendiri.

Dengan cara tersebut, setiap antrian terdepan tidak hanya membawa data berupa nilainya sendiri, melainkan juga nilai indeks ketika ia pertama kali diinputkan, sehingga mempermudah proses pelacakan indeks, dan juga saat mencatat waktu yang dibutuhkanya pada indeks vector yang sesuai.