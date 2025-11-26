---
obsidianUIMode: preview
note_type: latihan
latihan: Operasi Dasar Push
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T17:08:00
---
---
# 1 | Operasi Dasar Push

Buatlah program dengan ketentuan berikut:

1. Buat sebuah **queue** kosong.
2. Masukkan tiga bilangan bulat ke dalam queue secara berurutan: `10`, `20`, `30`.
3. Cetak elemen **pertama** di dalam queue (tanpa menghapusnya).

### Contoh

**Input**:
(tidak ada input dari pengguna, semua angka sudah ditentukan di dalam program)

**Output**:

```
10
```

<br/>

---
# 2 | Jawaban

Ezz guys

```cpp
#include <iostream>
#include <queue>
using namespace std;

auto main() -> int {
    queue<int> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    cout << myQueue.front();
    return 0;
}
```

<br/>

---
# 3 | Editorial

Panggil library dari queue:

```cpp
#include <queue>
```

Deklarasikan dan isi dengan menggunakan fungsi `push()`:

```cpp
queue<int> myQueue;
myQueue.push(10);
myQueue.push(20);
myQueue.push(30);
```

Lalu outputkan bagian depan dari queue, dengan menggunakan fungsi `front()`:

```cpp
cout << myQueue.front();
```