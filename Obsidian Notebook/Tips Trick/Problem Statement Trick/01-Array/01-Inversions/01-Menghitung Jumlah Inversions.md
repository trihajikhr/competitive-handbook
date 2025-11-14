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

## 1.1 | Brute Force ($O(n^2)$)

Ini merupakan pendekatan yang paling standar untuk menghitung banyaknya inversi pada array. Dilakukan 2 perulangan, untuk menghitung banyaknya elemen $a[j]$ yang lebih besar dari pada elemen $a[i]$. 

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

Versi ini memiliki kompleksitas $O(n^2)$, yang membuatnya kurang efisien. Hanya cocok digunakan untuk ukuran input yang kecil, misal dibawah misal $n \leq 2000$. 

Tapi, implementasi ini lebih ringkas, simple, dan langsung terlihat jelas bahwa implementasi ini bertujuan untuk mencari banyaknya inversions pada array, melalui fungsi `CountInvers()`.

## 1.2 | Merge Sort Modified ($O(n \log n)$)

Menghitung inversion menggunakan algoritma sorting berupa merge sort, merupakan salah satu cara yang paling populer untuk menyelesaikan masalah ini. Merge sort memiliki kompleksitas yang cukup efisien, yaitu $O(n \log n)$, sehingga pencarian inversion pada array jauh lebih baik, daripada versi brute force.

```cpp
#include <iostream>
#include <vector>
using namespace std;

auto merge(vector<int>& davec, int l, int m, int r) -> int {
    int n1 = m - l + 1;
    int n2 = r - m;
    int inversions = 0;

    vector<int> vecA(n1);
    vector<int> vecB(n2);

    for (int i = 0; i < n1; i++) {
        vecA[i] = davec[l + i];
    }

    for (int i = 0; i < n2; i++) {
        vecB[i] = davec[m + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (vecA[i] <= vecB[j]) {
            davec[k++] = vecA[i++];
        } else {
            davec[k++] = vecB[j++];
            inversions += (n1 - i);
            // semua elemen tersisa di vecA[i..end] lebih besar dari vecB[j]
        }
    }

    while (i < n1) {
        davec[k++] = vecA[i++];
    }

    while (j < n2) {
        davec[k++] = vecB[j++];
    }
    return inversions;
}

auto mergeSort(vector<int>& davec, int l, int r) -> int {
    int ans = 0;
    if (l < r) {
        int m = l + ((r - l) / 2);
        ans += mergeSort(davec, l, m);
        ans += mergeSort(davec, m + 1, r);
        ans += merge(davec, l, m, r);
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

    int invers = mergeSort(davec, 0, n - 1);
    cout << invers;

    return 0;
}

```

