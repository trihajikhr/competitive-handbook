---
obsidianUIMode: preview
note_type: latihan
latihan: Operasi Back
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T17:27:00
---
---
# 1 | Operasi Back

Buatlah program dengan ketentuan berikut:

1. Program membaca sebuah bilangan bulat $N$ dari input.
2. Program membaca $N$ bilangan bulat berikutnya ($a_i, a_{i+1}, \dots , a_{n}$) lalu masukkan semuanya ke dalam sebuah queue.
3. Cetak elemen pertama dan elemen terakhir dari queue.

### Contoh

**Input**:

```
5
10 20 30 40 50
```

**Output**:

```
10 50
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku:

```cpp
#include <iostream>
#include <queue>
using namespace std;

auto main() -> int {
    int n = 0;
    cin >> n;

    queue<int> myQueue;
    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        myQueue.push(x);
    }

    cout << myQueue.front() << " " << myQueue.back();
    return 0;
}
```

<br/>

---
# 3 | Editorial

Disini kita hanya belajar tentang memasukan data ke dalam queue sebanyak $n$ kali berdasarkan inputan user. Lalu hanya menampilkan elemen pertama dan elemen terakhir, yang bisa dilakukan dengan menggunakan fungsi `front()` dan juga `back()`:

```cpp
cout << myQueue.front() << " " << myQueue.back();
```