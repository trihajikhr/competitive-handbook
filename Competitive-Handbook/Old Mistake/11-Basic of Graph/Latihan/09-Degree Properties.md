---
obsidianUIMode: preview
note_type: latihan
latihan: Degree Properties
sumber:
  - chatgpt.com
tags:
  - graph-algorithm
  - graph-basic
date_learned: 2025-08-17T03:22:00
---
---
# 1 | Degree Properties

Diberikan sebuah graph. Tugasmu adalah menetukan node dengan degre maksimum dan minimum, lalu mencetak rata-rata degre setiap node pada graph. Jika ada lebih dari satu node dengan degre maksimal atau minimal, cukup cetak salah satunya. 

```ad-info
Degree (derajat) dari sebuah simpul dalam graph adalah jumlah sisi (edge) yang terhubung langsung ke simpul tersebut. Dengan kata lain, degree menunjukkan seberapa banyak tetangga (neighbor) yang dimiliki sebuah simpul. 

Pada graph tak berarah, degree dihitung dengan menjumlahkan semua sisi yang masuk dan keluar karena sifatnya simetris, sedangkan pada graph berarah dibedakan menjadi **in-degree** (jumlah sisi yang masuk) dan **out-degree** (jumlah sisi yang keluar). Degree ini penting karena bisa dipakai untuk menganalisis sifat graph, seperti menentukan simpul yang paling “ramai” (degree maksimum), simpul yang paling “sepi” (degree minimum), serta rata-rata keterhubungan graph secara keseluruhan.
```


<br/>

---
# 2 | Jawaban

Berikut adalah jawaban yand sudah benar:

```cpp
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

auto main() -> int {
   int n, m;
   cin >> n >> m;
   vector<vector<int>> graph(n + 1);

   for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   int maks = INT_MIN, mins = INT_MAX, avg = 0;
   int degreMaks, degreMins;
   for (int i = 1; i <= n; i++) {
      int temp = graph[i].size();
      avg += temp;
      if (temp > maks) {
         maks = temp;
         degreMaks = i;
      }
      if (temp < mins) {
         degreMins = i;
         mins = temp;
      }
   }

   cout << "Node dengan degre terbanyak: " << degreMaks << " dengan degre: " << maks << '\n';
   cout << "Node dengan degre terkecil: " << degreMins << " dengan degre: " << mins << '\n';
   cout << "Rata-rata degre setiap simpul adalah " << static_cast<double>(avg) / n << '\n';
   return 0;
}
```

Algoritma ini bekerja untuk graph directed maupun undirected, tinggal hapus `push_back` bolak balik jika ingin merubahnya ke directed.

<br/>

---
# 3 | Editorial

Program ini bertujuan untuk menghitung **node dengan degree maksimum, node dengan degree minimum, dan rata-rata degree** pada sebuah graph tak berarah.

#### 1. Input

* Program membaca dua bilangan `n` dan `m`:

  * `n` = jumlah simpul (node)
  * `m` = jumlah sisi (edge)
* Kemudian `m` pasang bilangan `(u, v)` yang menyatakan ada sisi tak berarah antara simpul `u` dan simpul `v`.
* Struktur data yang dipakai adalah **adjacency list**, yaitu `vector<vector<int>> graph(n+1)`.

#### 2. Representasi Graph

Setiap kali membaca sisi `(u, v)`, program menambahkan:

* `v` ke dalam daftar tetangga `graph[u]`
* `u` ke dalam daftar tetangga `graph[v]`
  Sehingga jumlah elemen di `graph[i]` akan sama dengan degree dari simpul `i`.

#### 3. Perhitungan Degree

Program melakukan iterasi dari `i = 1` sampai `n` untuk menghitung degree setiap simpul:

* `temp = graph[i].size()` → degree simpul `i`.
* Nilai `temp` ditambahkan ke variabel `avg` untuk menghitung rata-rata nantinya.
* Jika `temp` lebih besar dari `maks`, maka simpul `i` disimpan sebagai simpul dengan degree maksimum.
* Jika `temp` lebih kecil dari `mins`, maka simpul `i` disimpan sebagai simpul dengan degree minimum.

#### 4. Hasil

* **Node dengan degree maksimum** ditampilkan bersama nilainya.
* **Node dengan degree minimum** ditampilkan bersama nilainya.
* **Rata-rata degree** dihitung dengan `avg / n` (dibuat `double` agar hasilnya presisi).

#### 5. Kompleksitas

* Membaca input dan membangun adjacency list: **O(m)**.
* Menghitung degree setiap simpul: **O(n)**.
* Total kompleksitas: **O(n + m)**, efisien untuk graph berukuran besar.

---

👉 Jadi alur programnya: **bangun graph → hitung degree tiap simpul → cari max, min, dan rata-rata → tampilkan hasil**.

