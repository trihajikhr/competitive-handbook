---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSQU-E001
nama_algoritma: queue data structure
kategori_algoritma: data structure
kesulitan: 
time_complexity: 
memory_complexity: 
sumber: programiz.com
date_learned: 2025-04-22T22:25:00
tags:
  - array
  - data-structure
  - queue
---
#data-structure #data-structure #queue

---
# Queue Data Structure

Dalam C++, **STL queue** menyediakan fungsionalitas dari struktur data **queue**.

Struktur data queue mengikuti prinsip **FIFO (First In First Out)**, di mana elemen yang dimasukkan pertama akan dikeluarkan pertama.

Dalam queue, elemen dimasukkan dari **belakang (rear)** dan dikeluarkan dari **depan (front)**.

![[Queue Data Structure-1.png]]

---

### Membuat Queue STL di C++

Untuk membuat queue di C++, pertama kita harus menyertakan header file `queue`:

```cpp
#include <queue>
```

Setelah mengimpor file tersebut, kita bisa membuat queue dengan sintaks berikut:

```cpp
queue<tipe> q;
```

Di sini, `tipe` menunjukkan tipe data yang ingin kita simpan di dalam queue. Contohnya:

```cpp
// membuat queue bertipe integer
queue<int> integer_queue;

// membuat queue bertipe string
queue<string> string_queue;
```

---

### Metode-Metode Queue di C++

Queue dalam C++ adalah sebuah kelas yang menyediakan berbagai metode untuk melakukan operasi terhadap queue.

|Metode|Deskripsi|
|---|---|
|`push()`|Menambahkan elemen di belakang queue|
|`pop()`|Menghapus elemen dari depan queue|
|`front()`|Mengembalikan elemen pertama di queue|
|`back()`|Mengembalikan elemen terakhir di queue|
|`size()`|Mengembalikan jumlah elemen dalam queue|
|`empty()`|Mengembalikan `true` jika queue kosong|

---

## Menambahkan Elemen ke Queue

Kita menggunakan metode `push()` untuk menambahkan elemen ke belakang queue. Contoh:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<string> animals;

  animals.push("Cat");
  animals.push("Dog");

  cout << "Queue: ";
  while(!animals.empty()) {
    cout << animals.front() << ", ";
    animals.pop();
  }

  cout << endl;
  return 0;
}
```

**Output:**

```
Queue: Cat, Dog,
```

Pada contoh di atas, kita membuat queue string bernama `animals`, dan menambahkan elemen dengan `push()`.

Karena kita tidak bisa mengakses elemen queue secara langsung seperti pada `vector`, kita gunakan loop untuk mencetak isi queue satu per satu dengan `front()` dan `pop()`.

---

## Menghapus Elemen dari Queue

Kita bisa menggunakan `pop()` untuk menghapus elemen dari depan queue:

```cpp
#include <iostream>
#include <queue>
using namespace std;

// prototype
void display_queue(queue<string> q);

int main() {
  queue<string> animals;

  animals.push("Cat");
  animals.push("Dog");
  animals.push("Fox");

  cout << "Initial Queue: ";
  display_queue(animals);

  animals.pop();

  cout << "Final Queue: ";
  display_queue(animals);

  return 0;
}

void display_queue(queue<string> q) {
  while(!q.empty()) {
    cout << q.front() << ", ";
    q.pop();
  }
  cout << endl;
}
```

**Output:**

```
Initial Queue: Cat, Dog, Fox,
Final Queue: Dog, Fox,
```

`animals.pop()` akan menghapus elemen pertama ("Cat"), sehingga yang tersisa adalah "Dog" dan "Fox".

---

## Mengakses Elemen dalam Queue

Kita bisa mengakses elemen menggunakan metode:

- `front()` – mengakses elemen di depan
    
- `back()` – mengakses elemen di belakang
    

Contoh:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> nums;

  nums.push(1);
  nums.push(2);
  nums.push(3);

  int front = nums.front();
  cout << "First element: " << front << endl;

  int back = nums.back();
  cout << "Last element: " << back << endl;

  return 0;
}
```

**Output:**

```
First element: 1
Last element: 3
```

---

## Mengetahui Ukuran Queue

Gunakan metode `size()` untuk mendapatkan jumlah elemen:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<string> languages;

  languages.push("Python");
  languages.push("C++");
  languages.push("Java");

  int size = languages.size();
  cout << "Size of the queue: " << size;

  return 0;
}
```

**Output:**

```
Size of the queue: 3
```

---

## Mengecek Apakah Queue Kosong

Gunakan metode `empty()`:

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<string> languages;

  cout << "Is the queue empty? ";
  if (languages.empty()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  cout << "Pushing elements..." << endl;

  languages.push("Python");
  languages.push("C++");

  cout << "Is the queue empty? ";
  if (languages.empty()) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}
```

**Output:**

```
Is the queue empty? Yes
Pushing elements...
Is the queue empty? No
```
