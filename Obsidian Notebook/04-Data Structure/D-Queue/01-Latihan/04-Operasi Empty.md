---
obsidianUIMode: preview
note_type: latihan
latihan: Operasi Empty
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T17:33:00
---
---
# 1 | Operasi Empty

Buatlah program dengan ketentuan berikut:

1. Buat sebuah **queue kosong**.
2. Periksa apakah queue kosong atau tidak. Jika kosong, cetak `"Queue is empty"`.
3. Masukkan dua bilangan: `100` dan `200` ke dalam queue.
4. Periksa lagi apakah queue kosong atau tidak. Jika tidak kosong, cetak `"Queue is not empty"`.
### Contoh

**Input**:
(tidak ada input dari pengguna)

**Output**:

```
Queue is empty
Queue is not empty
```



<br/>

---
# 2 | Jawaban

Berikut adalah jawabanya:

```cpp
#include <iostream>
#include <queue>
using namespace std;

auto main() -> int {
    queue<int> myQueue;
    if (myQueue.empty()) {
        cout << "Queue is empty\n";
    }

    myQueue.push(100);
    myQueue.push(200);

    if (!myQueue.empty()) {
        cout << "Queue is not empty\n";
    }
    return 0;
}
```

<br/>

---
# 3 | Editorial

Disini kita belajar fungsi baru, yaitu fungsi `empty()`. Fungsi ini berguna untuk mengecek apakah queue tersebut kosong atau tidak. Jika kosong, maka akan mengembalikan nilai `true`, dan jika masih ada isinya, maka akan mengamblikan nilai `false`.

```cpp
if (myQueue.empty()) {
	cout << "Queue is empty\n";
}

if (!myQueue.empty()) {
	cout << "Queue is not empty\n";
}
```