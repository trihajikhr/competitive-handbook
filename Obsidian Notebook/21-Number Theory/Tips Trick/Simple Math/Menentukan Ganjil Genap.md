---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Menentukan Ganjil Genap
sumber:
  - myself
  - chatgpt.com
tags:
  - tips-trick
  - number-theory
---
---
# Menentukan Ganjil Genap

Menentukan ganjil genap itu sangat mudah, kita cukup menggunakan operasi modulo, dimana jika angka dimodulo kan dengan angka 2, jika sisanya 0 maka angka tersebut adalah genap, dan jika sisanya adalah 1, maka angka tersebut adalah ganjil.

Well, mencari ganjil genap memang semudah itu, tapi mari kita berfokus pada setiap peningkatan, jika memang bisa ditingkatakan.

## 1 | Cara Modulo
Dengan cara modulo, kita bisa menentukan apakah suatu angka adalah ganjil atau genap dengan menggunakan operasi modulo, dan ekuivalensi, sebagai berikut:

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n; cin >> n;

    if (n%2==0) cout << "genap";
    else cout << "ganjil";
```

atau

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n; cin >> n;

    if (n%2==0) cout << "genap";
    else if (n%2==1) cout << "ganjil";
}
```

Well, ini adalah cara yang paling mudah, paling klasik, paling mudah dipelajari, karena terlihat dengan jelas.

## 2 | Cara True False / Boolean
Tanpa menambahkan tanda equivalensi, kita bisa memanfaatkan kondisi true false pada percabangan, sebagai berikut:

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n; cin >> n;

    if (n%2) cout << "ganjil";
    else cout << "genap";
}
```

atau

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n; cin >> n;

    if (n%2) cout << "ganjil";
    else if (!(n%2)) cout << "genap";
}
```

Percabangan `if` atau `else if` akan aktif jika kondisional didalamnya bernilai true. Didalam bahasa C++, true bisa diisi dengan angka apapun selain 0, sedangkan false ditandai dengan angka 0.

Jadi, ketika `n % 2`, maka jika $n$ adalah ganjil, maka blok percabangan tersebut akan dieksekusi, karena hasil sisa dari ganjil adalah 1. Sedangkan untuk angka $n$ genap, hasil dari operasi `n % 2` adalah 0, atau false. Itu bisa kita aktifkan dengan bantuan operator negasi (`!`).

## 3 | Cara Bitwise

Yang cukup jarang dipakai, tapi lumayan cepat, yaitu cara bitwise. Karena genap/ganjil ditentukan oleh bit paling rendah (LSB), maka:

- Jika LSB = $0$ -> genap
- Jika LSB = $1$ -> ganjil

Jadi, bisa kita gunakan saja langsung cara ini dengan cara:

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n; cin >> n;

    if (n & 1) cout << "ganjil";
    else cout << "genap";
}
```

atau

```cpp
#include <iostream>
using namespace std;

auto main() -> int {
    int n; cin >> n;

    if (n & 1) cout << "ganjil";
    else if (!(n & 1)) cout << "genap";
}
```


Ekspresi `n & 1` berarti operasi AND biner antara `n` dan 1.

- Bilangan `1` dalam biner direpresentasikan sebagai `...0001`.
- Operasi `n & 1` akan menghasilkan nilai bit terakhir (_least significant bit_, LSB) dari `n`.
    - Jika LSB = 0 → `n` adalah bilangan **genap**.
    - Jika LSB = 1 → `n` adalah bilangan **ganjil**.

Contoh:

```
n = 7   -> biner 0111 -> (0111 & 0001) = 0001 -> hasil 1 (ganjil)  
n = 8   -> biner 1000 -> (1000 & 0001) = 0000 -> hasil 0 (genap)
```
