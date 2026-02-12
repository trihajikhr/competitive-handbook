---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: 
sumber: 
date_learned: 
tags:
---
Link Sumber: 

---
# Level Implementasi
Sebelumnya sudah dijelaskan cara mengimplementasikan linked list basic. Kali ini kita akan belajar bagaimana caranya mengimplementasikan linked list dengan cara yang berbeda-beda.

## 1 | Cara Basic
Menggunakan struct:

```cpp
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int _data) {
        this->data = _data;
        this->next = nullptr;
    }
};

auto main() -> int {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next =  new Node(4);

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
```

Output:

```
1 2 3
```

Kekurangan pertama adalah pembuatan chain node yang lebih lambat, karena harus ditulis secara manual. Kekurangan kedua adalah adanya memory leak, karena tidak adanya destructor. 

Berikut adalah solusi dari kedua kekurangan tadi:

```cpp
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int _data) {
        this->data = _data;
        this->next = nullptr;
    }

    ~Node() {
        delete next;
        cerr << "\ndelete node: " << data;
    }
};

auto main() -> int {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next =  new Node(4);

    Node* helper = head->next->next->next;
    helper->next = new Node(5);
    helper->next->next = new Node(6);
    helper->next->next->next = new Node(7);

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    delete head;
    return 0;
}
```

Output:

```
1 2 3 4 5 6 7
```

Mengakali kekurangan pertama dengan membuat variabel pointer `helper` untuk membantu membuat chain node yang lebih panjang, sehingga tidak perlu menuliskan `next->` terlalu banyak. Kita juga bisa membuat variabel bantu lainya, jika bagian `helper` sudah terlalu panjang, misal `helper2`. Lalu ketika `helper2` sudah terlalu panjang, kita bisa menggunakan kembali `helper1`.

Sedangkan untuk kekurangna kedua, kita mengatasinya dengan cara yang paling tepat, yaitu dengan cara membuat destructor yang akan melakukan pembersihan node secara rekursif. Namun pastikan untuk berhati-hati ketika menggunakan destructor ini, karena pada circular linked list, bisa terjadi *overflow* karena tidak menemukan ujung linked list ketika dipanggil.

Selain menggunakan struct, kita juga bisa menggunakan class, kita cukup merubah bagian struct menjadi class, dan menambahkan akses publik:

```cpp
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int _data) {
        this->data = _data;
        this->next = nullptr;
    }

    ~Node() {
        delete next;
        cerr << "\ndelete node: " << data;
    }
};

auto main() -> int {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next =  new Node(4);

    Node* first = head->next->next->next;
    first->next = new Node(5);
    first->next->next = new Node(6);
    first->next->next->next = new Node(7);

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    delete head;
    return 0;
}
```

Output:

```
1 2 3 4 5 6 7
```

<br/>

## 2 | Cara Basic + Template Class

Linked list sebelumnya tidak fleksibel, karena data yang  disimpan hanya bisa integer saja. Tetapi membuat 2 class node hanya untuk mmebedakan 2 tipe data dari field *data* juga jelas tidak efisien. Maka solusinya disini adalah menggunakan template class.

Dengan menggunakan template class, kita bisa menggunakan class node dengan tipe data apapun, lebih fleksibel, tapi dengan menambahkan keterangan tipe data apa yang ingin kita gunakan, contohnya adalah sebagai berikut:

```cpp
#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T _data) {
        this->data = _data;
        this->next = nullptr;
    }

    ~Node() {
        delete next;
        cerr << "\ndelete node: " << data;
    }
};

auto main() -> int {
    Node<int>* headOne = new Node(1);
    headOne->next = new Node(2);
    headOne->next->next = new Node(3);
    headOne->next->next->next =  new Node(4);

    Node<int>* temp = headOne;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';

    Node<string>* headTwo = new Node<string>("Sabrina");
    headTwo->next = new Node<string>("Laura");
    headTwo->next->next = new Node<string>("Jacob");
    headTwo->next->next->next = new Node<string>("Mawar");

    Node<string>*temp2 = headTwo;
    while (temp2 != nullptr) {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }

    delete headOne;
    delete headTwo;
    return 0;
}
```

Output:

```
1 2 3 4
Sabrina Laura Jacob Mawar
```

Untuk bisa menggunakan template class, tambahkan `template <typename T>` diatas class node kita, lalu kita harus menggunakan bantuan `<T>` di main, dimana $T$ artinya adalah tipe data yang akan kita gunakan pada linked list. Untuk tipe data primitif, bisa menggunakan cara `headOne`, dimana hanya menggunakan satu `<T>` untuk deklarasi.

Tapi untuk tipe data non-primitif, seperti string, kita harus menggunakan cara kedua, yaitu menyiratkan secara literal bahwa kita ingin menggunakan tipe data string. Contoh yang aku maksud bisa dilihat di kode 33 s/d 36.