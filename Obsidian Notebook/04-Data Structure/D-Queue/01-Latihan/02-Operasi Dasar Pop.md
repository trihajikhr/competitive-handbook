---
obsidianUIMode: preview
note_type: latihan
latihan: Operasi Dasar Pop
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T17:18:00
---
---
# 1 | Operasi Dasar Pop

Buatlah program dengan ketentuan berikut:

1. Buat sebuah queue kosong.
2. Masukkan empat bilangan bulat ke dalam queue: `5`, `15`, `25`, `35`.
3. Hapus satu elemen terdepan dari queue.
4. Cetak seluruh isi queue yang tersisa, dari depan ke belakang.

### Contoh

**Input**:
(tidak ada input dari pengguna, semua angka sudah ditentukan di dalam program)

**Output**:

```
15 25 35
```


<br/>

---
# 2 | Jawaban

Berikut adalah jawabanku, tanganganya masih cukup mudah:

```cpp
#include <iostream>
#include <queue>
using namespace std;

auto main() -> int {
    queue<int> myQueue;
    myQueue.push(5);
    myQueue.push(15);
    myQueue.push(25);
    myQueue.push(35);

    myQueue.pop();

    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    return 0;
}
```

<br/>

---
# 3 | Editorial

Untuk melakukan operasi penghapusan, kita menggunakan fungsi `pop()`. Fungsi ini akan menghapus data yang paling awal dimasukan, ini sesuai dengan prinsip FIFO (*First in First out*). 

```cpp
myQueue.pop();
```

Setelah itu, untuk menampilkan semua data dari `myQueue`, bisa menggunakan perulangan while, yang akan terus bekerja ketika queue masih memiliki data, seperti berikut:

```cpp
while (!myQueue.empty()) {
	cout << myQueue.front() << " ";
	myQueue.pop();
}
```