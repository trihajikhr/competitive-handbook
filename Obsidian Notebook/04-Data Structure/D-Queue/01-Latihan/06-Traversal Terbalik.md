---
obsidianUIMode: preview
note_type: latihan
latihan: Traversal Terbalik
sumber:
  - chatgpt.com
tags:
  - data-structure
  - queue
date_learned: 2025-08-27T17:46:00
---
---
# 1 | Traversal Terbalik

Buatlah program dengan ketentuan berikut:

1. Baca sebuah bilangan bulat **N**.
2. Baca **N bilangan bulat** berikutnya, masukkan semuanya ke dalam sebuah **queue**.
3. Cetak semua bilangan dari queue dalam **urutan terbalik** (dari belakang ke depan).

   > **Hint:** Karena queue hanya mendukung akses dari depan, kamu perlu memakai **struktur data tambahan** (misalnya stack atau vector).

### Contoh

**Input**:

```
5
1 2 3 4 5
```

**Output**:

```
5 4 3 2 1
```

<br/>

---
# 2 | Jawaban

```cpp
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

auto main() -> int {
    int n = 0;
    cin >> n;

    queue<int> daque;
    stack<int> dastack;

    for (int i = 0, x = 0; i < n; i++) {
        cin >> x;
        daque.push(x);
    }

    // traversal terbalik
    while (!daque.empty()) {
        dastack.push(daque.front());
        daque.pop();
    }

    while (!dastack.empty()) {
        cout << dastack.top() << " ";
        dastack.pop();
    }
    return 0;
}
```

<br/>

---
# 3 | Editorial

Tantangan dari soal ini adalah ketika harus mencetak data yang ada didalam queue secara terbalik. Padahal, struktur data queue hanya memperbolehkan kita melakukan traversal dari depan ke belakang, bukan sebaliknya. 

Solusi dari tantangan ini adalah dengan menggunakan struktur data bantu, semisal vector atau stack. Tapi disini aku memilih stack saja.

```cpp
// traversal terbalik
while (!daque.empty()) {
	dastack.push(daque.front());
	daque.pop();
}

while (!dastack.empty()) {
	cout << dastack.top() << " ";
	dastack.pop();
}
```

Semua elemen yang ada didalam queue, diambil dan di push ke dalam stack dengan operasi `push()`, hingga habis. Mekanisme ini ada di perulangan while pertama.

Karena stack menggunakan prinsip LIFO (*Last in, First out*), otomatis kita hanya bisa mengakses data yang paling terakhir ditambahkan, ini membuat kita seakan-akan membalik urutan data dari elemen yang ada di queue sebelumnya.

Sehingga, kita cukup mengambil data pada posisi paling atas dari stack, dengan menggunakan fungsi `top()`, lalu menghapusnya. Demikian seterusnya hingga stack menjadi kosong, dan perulangan while kedua berhenti secara otomatis.