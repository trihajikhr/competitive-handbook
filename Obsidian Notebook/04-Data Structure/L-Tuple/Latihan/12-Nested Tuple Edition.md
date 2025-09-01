---
obsidianUIMode: preview
note_type: latihan
latihan: Nested Tuple Edition
sumber:
  - chatgpt.com
tags:
  - data-structure
  - tuple
date_learned: 2025-08-29T14:15:00
---
---
# 1 | Nested Tuple Edition

Sebuah **perpustakaan digital** menyimpan daftar buku dalam format berikut:

* ID Buku (bilangan bulat unik)
* Judul Buku (string tanpa spasi)
* Penulis (disimpan sebagai tuple `(NamaDepan, NamaBelakang)`)
* Jumlah Halaman (bilangan bulat)

Semua data buku disimpan dalam 

```cpp
vector<tuple<int, string, tuple<string, string>, int>>
```

### Tugasmu:

1. Baca `N` (jumlah buku).
2. Baca setiap data buku dengan format:

   ```
   ID Judul NamaDepan NamaBelakang JumlahHalaman
   ```

   lalu simpan dalam vector of tuple.
3. Urutkan semua buku berdasarkan **JumlahHalaman (descending)**.

   * Jika jumlah halaman sama, urutkan berdasarkan **NamaBelakang penulis (ascending)**.
   * Jika masih sama, urutkan berdasarkan **ID (ascending)**.
4. Cetak daftar buku dalam format:

   ```
   ID Judul NamaDepan NamaBelakang JumlahHalaman
   ```
5. Tambahan tantangan:
   Buat fungsi `string formatBook(const tuple<int, string, tuple<string,string>, int>& b)`
   yang mengubah tuple buku menjadi string ringkasan seperti:

   ```
   Book#101 "CPMastery" by John Doe - 350 pages
   ```

   Lalu cetak ringkasan ini untuk semua buku setelah sorting.

### Contoh Input

```
4
101 CPMastery John Doe 350
102 AlgoBook Alice Smith 420
103 MathGuide Bob Brown 350
104 Coding101 Alice Brown 420
```

### Contoh Output

```
Sorted Books:
102 AlgoBook Alice Smith 420
104 Coding101 Alice Brown 420
103 MathGuide Bob Brown 350
101 CPMastery John Doe 350

Summary:
Book#102 "AlgoBook" by Alice Smith - 420 pages
Book#104 "Coding101" by Alice Brown - 420 pages
Book#103 "MathGuide" by Bob Brown - 350 pages
Book#101 "CPMastery" by John Doe - 350 pages
```


💡 Soal ini bakal bikin kamu:

* Pakai **nested tuple** (`tuple<string,string>` di dalam `tuple`).
* Belajar **multi-level sorting** dengan `get<>()` di dalam nested tuple.
* Buat fungsi yang menerima tuple kompleks.

<br/>

---
# 2 | Jawaban

## 2.1 | Custom Sorting Pertama

Disini aku menggunakan custom sorting pertama, tanpa menggunakan `tie()`. Algoritma ini sudah berjalan dengan baik dan benar, namun ada versi kedua yang bisa menyiingkat kode ini:

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

namespace {
void printTuple(const tuple<int, string, tuple<string, string>, int>& book) {
    cout << "Book#" << get<0>(book) << " \"" << get<1>(book) << "\" "
         << "by " << get<0>(get<2>(book)) << " " << get<1>(get<2>(book))
         << " " << get<3>(book)
         << '\n';
}
}  // namespace

auto main() -> int {
    int n = 0;
    cin >> n;

    vector<tuple<int, string, tuple<string, string>, int>> book(n);

    for (auto& [id, jd, nm, hal] : book) {
        cin >> id >> jd >> get<0>(nm) >> get<1>(nm) >> hal;
    }

    ranges::sort(book, [](const auto& a, const auto& b) {
        if (get<3>(a) == get<3>(b)) {
            if (get<1>(get<2>(a)) == get<1>(get<2>(b))) {
                if (get<0>(a) < get<0>(b)) {
                    return true;
                }
            } else if (get<1>(get<2>(a)) < get<1>(get<2>(b))) {
                return true;
            }
        } else if (get<3>(a) > get<3>(b)) {
            return true;
        }

        return false;
    });

    cout << "\nSorted Book:\n";
    for (const auto& [id, jd, nm, hal] : book) {
        cout << id << " " << jd << " " << get<0>(nm) << " " 
        << get<1>(nm) << " " << hal << '\n';
    }

    cout << "\nSummary:\n";
    for (int i = 0; i < (int)book.size(); i++) {
        printTuple(book[i]);
    }

    return 0;
}
```

## 2.2 | Custom Sorting Kedua

Berikut adalah cara yang ternyata bisa lebih ringkas:

```cpp
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

namespace {
void printTuple(const tuple<int, string, tuple<string, string>, int>& book) {
    cout << "Book#" << get<0>(book) << " \"" << get<1>(book) << "\" "
         << "by " << get<0>(get<2>(book)) << " " << get<1>(get<2>(book))
         << " " << get<3>(book)
         << '\n';
}
}  // namespace

auto main() -> int {
    int n = 0;
    cin >> n;

    vector<tuple<int, string, tuple<string, string>, int>> book(n);

    for (auto& [id, jd, nm, hal] : book) {
        cin >> id >> jd >> get<0>(nm) >> get<1>(nm) >> hal;
    }

    ranges::sort(book, [](const auto& a, const auto& b) {
        return tie(get<3>(b), get<1>(get<2>(a)), get<0>(a)) <
               tie(get<3>(a), get<1>(get<2>(b)), get<0>(b));
    });

    cout << "\nSorted Book:\n";
    for (const auto& [id, jd, nm, hal] : book) {
        cout << id << " " << jd << " " << get<0>(nm) << " " 
        << get<1>(nm) << " " << hal << '\n';
    }

    cout << "\nSummary:\n";
    for (const auto & i : book) {
        printTuple(i);
    }

    return 0;
}

```

## 3.3 | Menggunakan Struct

Ini adalah implementasi jika menggunakan struct, lebih mudah untuk kasus data yang banyak, bahkan mungkin lebih readable daripada `tuple`:

```cpp
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Book {
    int id{};
    string nama;
    struct Penulis {
        string depan;
        string belakang;
    };
    Penulis penulis;
    int hal{};
};

namespace {
void printData(const Book& book) {
    auto [id, nm, pn, hal] = book;
    cout << "Book#" << id << " " << " \"" << nm << "\""
         << " by " << pn.depan << " " << pn.belakang << " - " 
         << hal << " pages\n";
}
}  // namespace

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;

    vector<Book> book(n);
    for (auto& [id, nm, pn, hal] : book) {
        cin >> id >> nm >> pn.depan >> pn.belakang >> hal;
    }

    ranges::sort(book, [](const auto& a, const auto& b) {
        if (a.hal == b.hal) {
            if (a.penulis.belakang == b.penulis.belakang) {
                if (a.id < b.id) {
                    return true;
                }
            } else if (a.penulis.belakang < b.penulis.belakang) {
                return true;
            }
        } else if (a.hal > b.hal) {
            return true;
        }

        return false;
    });

    cout << "\nSorted Books:\n";
    for (const auto& [id, nm, pn, hal] : book) {
        cout << id << " " << nm << " " << pn.depan << " " 
        << pn.belakang << " " << hal << '\n';
    }

    cout << "\nSummary:\n";
    for (const auto& x : book) {
        printData(x);
    }

    return 0;
}
```

<br/>

---
# 3 | Editorial

## 3.1 | Editorial Jawaban Pertama

Pada jawaban pertama, algoritma atauu mekanis sulit hanya ada pada bagian ini:

```cpp
vector<tuple<int, string, tuple<string, string>, int>> book(n);
for (auto& [id, jd, nm, hal] : book) {
	cin >> id >> jd >> get<0>(nm) >> get<1>(nm) >> hal;
}
ranges::sort(book, [](const auto& a, const auto& b) {
	if (get<3>(a) == get<3>(b)) {
		if (get<1>(get<2>(a)) == get<1>(get<2>(b))) {
			if (get<0>(a) < get<0>(b)) {
				return true;
			}
		} else if (get<1>(get<2>(a)) < get<1>(get<2>(b))) {
			return true;
		}
	} else if (get<3>(a) > get<3>(b)) {
		return true;
	}
	return false;
});
```

Baiklah, diversi jawaban ini, kita menerima semua inputan sebagai vector, dengan didalamnya terdapat `tuple` didalam `tuple`, atau nested tuple.

Proses sorting dengan syarat memiliki alur yang cukup panjang. Ketahui, bahwa ketika menggunakan custom sort dengan `lambda`, ketika suatu nilai yang dibandingkan mengembalikan nilai `true`, maka akan diswap nilainya. Tapi jika tidak, maka akan dibiarkan. Nah karena ada 3 syarat yang perlu dipenuhi selama proses sorting, maka alur pengurutan harus sebagai berikut:

1. Jika jumlah halaman sama, maka cek nama belakang penulis;
2. Jika nama belakang penulis sama, maka cek no id penulis
3. Jika no id $a < b$, maka kembalikan nilai `true`, ini artinya kita melakukan swap elemen disini.
4. Nah jika no id bukan $a < b$, maka tidak dilakukan perulangan.
5. Jika semisal jumlah halaman sama, dan nama belakang penulis $a < b$, maka kembalikan `true`, artinya dilakukan swap disini. Tapi jika tidak, maka biarkan saja.
6. Jika jumlah halaman sudah berbeda dari awal, maka akan langsung masuk kondisi kedua, yaitu kondisi ketika $a.hal > b.hal$, sehingga kembalikan nilai true.
7. Tapi jika tidak ada kondisi diatas yang memnuhi maka kembalikan saja nilai `false`, yang artinya tidak terjadi pertukaran apapun.

Alur logika diatas juga berlaku untuk 2 versi jawaban lain!

## 3.2 | Editorial Jawaban Kedua

Perbedaan versi jawaban pertama denga kedua terletak pada bagian ini:

```cpp
ranges::sort(book, [](const auto& a, const auto& b) {
	return tie(get<3>(b), get<1>(get<2>(a)), get<0>(a)) <
		   tie(get<3>(a), get<1>(get<2>(b)), get<0>(b));
});
```

Supaya bisa dilakukan perbandingan yang langsung dan cepat, maka kita bisa langsung saja gunakan fungsi `tie()`.

Sekarang lihat kode berikut:

```cpp
tie(get<3>(b), get<1>(get<2>(a)), get<0>(a))
```

Terdapat 3 objek. Objek yang berada di posisi paling kiri, artinya objek yang paling berpengaruh. Objek tersebut adalah objek `halaman`. Karena jika semisal halamanya lebih besar, maka kita tidak perlu mengecek nama belakang, dan id, kita swap berdasarkan banyaknya halaman. Jika 2 objek di sebelah kananya menggunakan variabel $a$, objek paling kiri justru menggunakan variabel $b$. Ini karena kita ingin mengurutkan dia dengan urutan descending, sedangkan 2 objek disebelah kananya adalah ascending.

Jika semisal objek pertama sama, maka baru periksa objek kedua, dan jika objek kedua sama, maka baru cek objek ketiga. Ini sesuai dengan proses pemeriksaan pengurutan yang harus dilakukan.

## 3.3 | Editorial Jawaban Ketiga

Ada 2 hal yang akan dibahas disini, pertama:

```cpp
struct Book {
    int id{};
    string nama;
    struct Penulis {
        string depan;
        string belakang;
    };
    Penulis penulis;
    int hal{};
};
```

.. dan ini yang kedua:

```cpp
ranges::sort(book, [](const auto& a, const auto& b) {
	if (a.hal == b.hal) {
		if (a.judul.belakang == b.judul.belakang) {
			if (a.id < b.id) {
				return true;
			}
		} else if (a.judul.belakang < b.judul.belakang) {
			return true;
		}
	} else if (a.hal > b.hal) {
		return true;
	}

	return false;
});
```

Ketika membuat struct `Book`, kita perlu tahu bahwa kita mungkin perlu membuat struct lagi, yaitu struct `Penulis`. Nah, jangan lupa untuk deklarasikan nested struct tersebut, supaya member variable nya tepat ada 4. 


Sebelumnya aku mengalami kesulitan dalam membuat nested struct, dan melakukan perulangan dengan menggunakan for-each loop. Ternyata setelah diselidiki, hal itu disebabkan karena aku lupa membuat deklarasi structnya, ini adalah contoh yang salah:

```cpp
struct Book {
    int id{};
    string nama;
    struct Penulis {
        string depan;
        string belakang;
    };
    int hal{}; // ❌ tidak membuat objek!
};
```


Dan ini adalah contoh yang benar:


```cpp
struct Book {
    int id{};
    string nama;
    struct Penulis {
        string depan;
        string belakang;
    };
    Penulis penulis; // ✅ membuat objek!
    int hal{};
};
```



