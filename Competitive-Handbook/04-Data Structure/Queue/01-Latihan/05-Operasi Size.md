---
obsidianUIMode: preview
note_type: latihan
latihan: Operasi Size
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T17:39:00
---
---
# 1 | Operasi Size

Buatlah program dengan ketentuan berikut:

1. Buat sebuah **queue kosong**.
2. Masukkan tiga bilangan bulat ke dalam queue: `7`, `14`, `21`.
3. Cetak jumlah elemen dalam queue saat ini.
4. Hapus satu elemen dari queue.
5. Cetak lagi jumlah elemen dalam queue setelah penghapusan.

### Contoh

**Input**:
(tidak ada input dari pengguna)

**Output**:

```
3
2
```

<br/>

---
# 2 | Jawaban

Berikut adalah jawaban dariku:

```cpp
#include <iostream>
#include <queue>
using namespace std;

auto main() -> int {
    queue<int> myQueue;
    myQueue.push(14);
    myQueue.push(12);
    myQueue.push(21);

    cout << myQueue.size() << '\n';

    myQueue.pop();

    cout << myQueue.size() << '\n';

    return 0;
}
```

<br/>

---
# 3 | Editorial

Pada latihan kali ini, kita belajar menggunakan fungsi untuk memeriksa ukuran dari queue, yaitu dengan menggunakan fungsi `size()`, yang akan mengembalikan nilai berupa banyaknya elemen yang ada di dalam queue ketika fungsi ini dipanggil:

```cpp
cout << myQueue.size() << '\n';
```