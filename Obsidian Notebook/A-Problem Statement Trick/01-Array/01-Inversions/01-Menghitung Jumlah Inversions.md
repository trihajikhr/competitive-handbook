---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Menghitung Jumlah Inversions
sumber:
date_learned: 2025-09-11T00:33:00
tags:
  - problem-statement
  - tips-trick
---
Link Sumber: 

---
# 1 | Menghitung Jumlah Inversions

Hal pertama yang perlu dikuasai tentang inversi, mungkin adalah menghitung banyaknya inversi dari inputan yang diberikan. 

Misalkan inputan berupa $n$, dan diikuti di baris keduanya adalah sebanyak $n$ elemen acak, maka tentukan banyaknya inversi didalamnya.

```
10
1 6 4 5 3 9 8 7 10 2
```

Maka akan ada beberapa cara yang bisa digunakan untuk mendapatkan banyaknya inversi. Disini kita akan memulai dari pendekatan yang mungkin kurang efisien, ke yang paling efisien dengan beberapa cara pendekatan. Tujuanya adalah bisa belajar banyak variasi solusi, sebelum menuju solusi yang paling optimal dan efisien.

## 1.1 | Variasi Bubble Sort

Algoritma sorting berbasis perbandingan pada umumnya bisa digunakan untuk menghitung banyaknya inversi, salah satunya bubble sort. Pendekatan ini mudah dilakukan, karena cukup menyisipkan variabel counter pada operasi bubble sort:

```cpp
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

auto bubbleSort(vector<int>& davec) -> int {
    size_t n = davec.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (davec[j] > davec[j + 1]) {
                ans++;
                swap(davec[j], davec[j + 1]);
                flag = true;
            }
        }

        if (!flag) {
            break;
        }
    }

    return ans;
}

auto main() -> int {
    int n = 0;
    cin >> n;
    vector<int> davec(n);
    for (auto& x : davec) {
        cin >> x;
    }

    int invers = bubbleSort(davec);
    cout << invers;

    return 0;
}
```

Fungsi `bubbleSort()` akan melakukan proses sorting, namun kita sisipkan variabel counter `ans` untuk mengetahui banyaknya inversi. Pada akhir proses sorting, nilai dari `ans` dikembalikan, dan ditangkap oleh variabel `invers`.

Walaupun cara ini cukup mudah, kompleksitas $O(n^2)$ pada bubble sort jelas membuatnya tidak efisien. Bahkan untuk algoritma sorting sendiri, bubble sort memang tergolong algoritma yang tidak efisien, jadi penerapan ini hanya berlaku untuk inputan kecil, atau sebagai bahan latihan saja.

## 1.2 | Variasi $O(n^2)$

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto countInvers(vector<int>& davec) -> int {
    int ans = 0;
    size_t n = davec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (davec[i] > davec[j]) {
                ans++;
            }
        }
    }

    return ans;
}

auto main() -> int {
    int n = 0;
    cin >> n;
    vector<int> davec(n);
    for (auto& x : davec) {
        cin >> x;
    }

    int invers = countInvers(davec);
    cout << invers;
    return 0;
}
```

Versi ini memiliki kompleksitas yang sama seperti sebelumnya, yang membuatnya kurang efisien. Tapi, implementasi ini lebih ringkas, dan langsung terlihat jelas bahwa implementasi ini bertujuan untuk mencari banyaknya inversions pada array, melalui fungsi `CountInvers()`.

