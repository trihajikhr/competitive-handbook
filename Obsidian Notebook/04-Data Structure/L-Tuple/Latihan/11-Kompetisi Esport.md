---
obsidianUIMode: preview
note_type: latihan
latihan: Kompetisi Esport
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-29T13:07:00
---
---
# 1 | Kompetisi Esport

Di sebuah kompetisi e-sport, ada $N$ pemain yang mengikuti turnamen. Setiap pemain punya data:

* **ID pemain** (bilangan bulat unik).
* **Username** (string, tanpa spasi).
* **Skor** (bilangan bulat).

Data pemain disimpan sebagai **tuple**.

### Tugasmu:

1. Baca `N`.
2. Baca data tiap pemain dalam bentuk `(ID, Username, Skor)` dan simpan ke dalam sebuah `vector<tuple<int, string, int>>`.
3. Setelah semua data terbaca:
   * Urutkan semua pemain berdasarkan **Skor (descending)**.
   * Jika ada skor sama, urutkan berdasarkan **ID (ascending)**.
4. Cetak **3 pemain terbaik** (atau kurang kalau total pemain < 3), dalam format:

	```
	ID Username Skor
	```
5. Tambahan tantangan:

   * Buat fungsi yang menerima sebuah `tuple` lalu mengembalikan **string ringkasan**, misalnya:

     ```
     (101, "Rivaldo", 2500) → "Player#101 [Rivaldo] has score 2500"
     ```
   * Cetak ringkasan ini untuk setiap pemain setelah sorting.

### Contoh Input

```
5
101 Rivaldo 2500
103 Andi 2700
107 Budi 2700
111 Sinta 1900
115 Dodi 2500
```

### Contoh Output

```
Top 3 Players:
103 Andi 2700
107 Budi 2700
101 Rivaldo 2500

Summary:
Player#103 [Andi] has score 2700
Player#107 [Budi] has score 2700
Player#101 [Rivaldo] has score 2500
Player#115 [Dodi] has score 2500
Player#111 [Sinta] has score 1900
```

💡 Soal ini bakal melatih:

* Penyimpanan data pakai `tuple`.
* Akses elemen tuple (`get<>()`).
* Custom sorting dengan `tuple`.
* Fungsi yang menerima dan mengembalikan hasil dari `tuple`.
<br/>

---
# 2 | Jawaban

## 2.1  | Jawaban Pertama

Berikut adalah jawabanku:

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

void tuplePrint(int id, const string& name, int skor) {
    cout << "Player#" << id << " [" << name << "]" << " has score " << skor << '\n';
}

auto main() -> int {
    int n = 0;
    cin >> n;

    vector<tuple<int, string, int>> player(n);

    for (int i = 0; i < n; i++) {
        cin >> get<0>(player[i]) >> get<1>(player[i]) >> get<2>(player[i]);
    }

    ranges::sort(player, [](const auto& a, const auto& b) {
        if (get<2>(a) == get<2>(b)) {
            return get<0>(a) < get<0>(b);
        }

        return get<2>(a) > get<2>(b);
    });

    cout << "\nTop 3 Players:\n";
    for (int i = 0; i < min(3, n); i++) {
        cout << get<0>(player[i]) << " " << get<1>(player[i]) << " " 
        << get<2>(player[i]) << '\n';
    }

    cout << "\nSummary:\n";
    for (int i = 0; i < n; i++) {
        tuplePrint(get<0>(player[i]), get<1>(player[i]), get<2>(player[i]));
    }
    return 0;
}
```

## 2.2 | Jawaban Kedua

Jika ingin cara yang lebih efisien dan singkat, kita bisa memanfaatkan fitur dari C++ 17, yaitu *structured binding* yang bisa digunakan untuk memecah tuple dengan cara yang lebih readable:

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

auto main() -> int {
    int n = 0;
    cin >> n;

    vector<tuple<int, string, int>> player(n);

    for (auto& [id, nm, sk] : player) {
        cin >> id >> nm >> sk;
    }

    ranges::sort(player, [&](const auto& a, const auto& b) {
        if (get<2>(a) == get<2>(b)) {
            return get<0>(a) < get<0>(b);
        }

        return get<2>(a) < get<2>(b);
    });

    cout << "\nTop 3 Players:\n";
    for (int i = 0; i < min(3, n); i++) {
        auto [id, nm, sk] = player[i];
        cout << id << " " << nm << " " << sk << '\n';
    }

    cout << "\nSummary:\n";
    for (int i = 0; i < n; i++) {
        auto [id, nm, sk] = player[i];
        cout << "Player#" << id << " [" << nm << "] has score " 
        << sk << '\n';
    }
    return 0;
}
```



<br/>

---
# 3 | Editorial

Wuihh 🔥 ini udah keren banget kodenya, kamu udah pakai **structured binding** langsung di `for` dan `auto [id, nm, sk]`, mantap. Aku coba kasih beberapa catatan biar makin rapi dan lebih “CP-style”:
## 3.1 | Hal yang sudah bagus:

1. **Tuple** benar-benar dipakai buat nyimpan data (sesuai tujuan latihan).
2. **Custom sort** pakai `ranges::sort` + lambda, clean banget.
3. **Structured binding** bikin kode mudah dibaca.
4. Output sudah sesuai spesifikasi soal cerita.

## 3.2 | Saran Perbaikan / Enhancement:

1. Gunakan `const auto&` untuk loop summary
   Supaya tidak membuat salinan tuple di setiap iterasi.

   ```cpp
   for (const auto& [id, nm, sk] : player) {
       cout << "Player#" << id << " [" << nm << "] has score " << sk << '\n';
   }
   ```

   Jadi lebih efisien.

2. Pisahkan fungsi untuk ringkasan
   Karena di soal diminta bikin fungsi, coba bikin misalnya:

   ```cpp
   string summary(const tuple<int, string, int>& p) {
       auto [id, nm, sk] = p;
       return "Player#" + to_string(id) + " [" + nm + "] has score " + to_string(sk);
   }
   ```

   Lalu di main:

   ```cpp
   for (const auto& p : player) {
       cout << summary(p) << '\n';
   }
   ```

3. Pakai `std::tie` kalau mau bandingin tuple secara langsung
   Daripada `if (get<2>(a) == get<2>(b)) ...`, kamu bisa ganti comparator jadi:

   ```cpp
   ranges::sort(player, [](const auto& a, const auto& b) {
       return tie(-get<2>(a), get<0>(a)) < tie(-get<2>(b), get<0>(b));
   });
   ```

   Trik ini sering dipakai di CP buat multi-key sorting. Lebih ringkas.

Jadi, kodenya **sudah benar banget**, tinggal ditambah fungsi `summary` supaya sesuai instruksi awal.

## 3.3 | Pemahaman Mendalam Lambda Function

```ad-faq
Apa itu `[ ]` di lambda?
```

`[ ]` adalah **daftar capture** → yaitu cara sebuah lambda **mengambil variabel dari scope luar** supaya bisa dipakai di dalam body-nya.

Format dasarnya:

```cpp
[capture] (parameter) -> return_type {
    // body
}
```

### 3.1 | Jenis Capture

Ada beberapa cara isi `[ ]`:

1. **Kosong `[ ]`**
   Artinya lambda **tidak mengambil variabel apapun dari luar**.

   ```cpp
   int x = 10;
   auto f = []() { return 5; }; // tidak bisa akses x
   ```

<br/>

2. **Capture by value `[=]`**
   Semua variabel luar **disalin** ke dalam lambda.

   ```cpp
   int x = 10;
   auto f = [=]() { return x + 5; }; // x disalin → nilai awalnya 10
   ```

<br/>

3. **Capture by reference `[&]`**
   Semua variabel luar diambil **referensinya**, jadi kalau diubah dalam lambda → nilai aslinya ikut berubah.

   ```cpp
   int x = 10;
   auto f = [&]() { x += 5; }; 
   f(); 
   cout << x; // hasilnya 15
   ```

<br/>

4. **Capture spesifik**

   * By value: `[x]` → hanya `x` yang dicopy.
   * By reference: `[&x]` → hanya `x` yang direferensikan.

   ```cpp
   int a = 3, b = 4;
   auto f = [a, &b]() { 
       // a by value, b by reference
       return a + (++b); 
   };
   ```

<br/>

5. **Campur**
   Bisa digabung:

   ```cpp
   auto f = [=, &x]() { ... }; // default by value, tapi x by ref
   auto g = [&, y]() { ... }; // default by ref, tapi y by value
   ```

### 3.2 | Contoh di Kode Sortingmu

Di comparator sorting tadi:

```cpp
ranges::sort(player, [&](const auto& a, const auto& b) {
    // ...
});
```

* `[&]` artinya **semua variabel luar boleh diakses lewat reference**.
* Tapi, sebenarnya di situ kamu **tidak butuh capture apapun** karena semua informasi datang dari parameter `a` dan `b`.
* Jadi bisa ditulis aja:

  ```cpp
  ranges::sort(player, [](const auto& a, const auto& b) {
      // ...
  });
  ```

### 3.3 | Singkatnya

* `[ ]` → lambda capture list.
* `[=]` → copy semua variabel luar.
* `[&]` → reference semua variabel luar.
* Bisa spesifik `[x]`, `[&y]`, atau campur `[=, &x]`.
* Kalau nggak butuh variabel luar → cukup kosong `[]`.

