---
obsidianUIMode: preview
note_type: latihan
latihan: Simulasi Antrian
sumber:
  - chatp
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T18:06:00
---
---
# 1 | Simulasi Antrian

Buatlah program untuk **mensimulasikan antrian** dengan aturan:

1. Program membaca sebuah bilangan bulat **Q** = jumlah operasi.
2. Setiap operasi bisa berupa:

   * `"ADD x"` → tambahkan orang bernomor `x` ke belakang antrian.
   * `"POP"` → keluarkan orang terdepan dari antrian (jika tidak kosong).
   * `"FRONT"` → cetak nomor orang yang ada di depan antrian. Jika kosong, cetak `"EMPTY"`.
3. Setelah semua operasi selesai, cetak isi antrian yang tersisa dari depan ke belakang. Jika kosong, cetak `"EMPTY"`.

### Contoh

**Input**:

```
6
ADD 10
ADD 20
FRONT
POP
FRONT
POP
```

**Output**:

```
10
20
EMPTY
```


<br/>

---
# 2 | Jawaban

```cpp
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

auto main() -> int {
    int q = 0;
    cin >> q;

    queue<int> daque;

    while ((q--) != 0) {
        string s;
        getline(cin >> ws, s);

        stringstream ss(s);
        int num = 0;
        string cmd;
        ss >> cmd >> num;

        if (cmd == "ADD") {
            daque.push(num);
        } else if (cmd == "POP" && !daque.empty()) {
            daque.pop();
        } else if (cmd == "FRONT") {
            if (!daque.empty()) {
                cout << daque.front() << '\n';
            } else {
                cout << "EMPTY\n";
            }
        }
    }

    if (daque.empty()) {
        cout << "EMPTY";
    } else {
        while (!daque.empty()) {
            cout << daque.front() << " ";
            daque.pop();
        }
    }
    return 0;
}
```

<br/>

---
# 3 | Editorial

Solusinya sederhana, kita cukup menggunakan `stringstream` dimana fitur ini berguna untuk memecah string berdasarkan spasi. Karena ada 2 inputan, yaitu perintah dan angka, maka kita deklarasikan string `cmd` dan int `num` untuk menangkap inputanya.

Setelah itu, buat percabangan yang menyaring setiap kemungkinan nilai dari `cmd`, lalu lakukan perintah yang sesuai dengan permintaan dari problem statement.

Disini tidak ada fungsi baru dari queue yang diperkenalkan, jadi masih cukup mudah.