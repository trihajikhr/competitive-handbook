---
obsidianUIMode: preview
note_type: data structure theory
id_algoritma: 04TH-DSST-0005
nama_algoritma: 
kategori_algoritma: data structure
kesulitan: 🥉 easy
time_complexity: 
memory_complexity: 
sumber: programiz.com & gemini AI
date_learned: 2025-06-14T22:43:00
tags:
  - stack
  - data-structure
---
---
# Analisis Mendalam Struktur Data Stack dalam C++: Konsep, Implementasi, Kegunaan, dan Fungsi

## 1. Pendahuluan

Struktur data merupakan fondasi dalam ilmu komputer, menyediakan cara yang terorganisir untuk menyimpan dan mengelola data agar dapat diakses dan dimodifikasi secara efisien. Di antara berbagai struktur data yang ada, _stack_ menonjol sebagai salah satu yang paling fundamental dan banyak digunakan. Struktur data linear ini beroperasi berdasarkan prinsip yang unik, yang menjadikannya pilihan ideal untuk berbagai aplikasi dalam pengembangan perangkat lunak dan sistem komputasi. Laporan ini akan mengulas secara komprehensif struktur data _stack_ dalam konteks pemrograman C++, mencakup definisi, karakteristik, operasi inti, metode implementasi, serta beragam kegunaan dan aplikasinya di dunia nyata.

## 2. Definisi Struktur Data Stack

_Stack_ adalah struktur data linear yang mengikuti prinsip **LIFO (Last In, First Out)**, yang berarti elemen terakhir yang ditambahkan ke dalam _stack_ adalah elemen pertama yang akan dihapus. Konsep ini dapat dianalogikan dengan tumpukan piring di kafetaria atau tumpukan tab browser: piring atau tab terbaru selalu ditempatkan di paling atas, dan saat ingin mengambil atau menutup, piring atau tab terataslah yang pertama kali diakses.

Dalam _stack_, semua operasi penyisipan (penambahan) dan penghapusan elemen hanya terjadi di satu ujung, yang dikenal sebagai **"top"** (puncak) dari _stack_. Hal ini membedakan _stack_ dari struktur data lain seperti antrean (queue) yang mengikuti prinsip FIFO (First In, First Out), atau daftar tertaut (linked list) yang memungkinkan penyisipan dan penghapusan di posisi mana pun.

## 3. Karakteristik Utama Stack

Memahami karakteristik _stack_ sangat penting untuk mengidentifikasi kapan dan mengapa struktur data ini menjadi pilihan yang tepat dalam desain algoritma dan sistem:

### 3.1. Prinsip LIFO (Last In, First Out)

Karakteristik paling mendasar dari _stack_ adalah prinsip LIFO. Ini berarti bahwa elemen yang paling baru ditambahkan ke _stack_ akan menjadi elemen pertama yang dapat diakses atau dihapus.1Urutan ini secara inheren memastikan bahwa setiap operasi selalu berfokus pada elemen "puncak" dari _stack_.
### 3.2. Operasi Terbatas pada Satu Ujung

Semua interaksi dengan _stack_ dibatasi pada satu titik akses, yaitu bagian "top". Elemen tidak dapat ditambahkan atau dihapus dari tengah atau bawah _stack_ secara langsung. Pembatasan ini menyederhanakan logika implementasi dan memastikan konsistensi perilaku LIFO.

### 3.3. Adaptor Kontainer `std::stack` dalam C++

Di C++, _stack_ sering diimplementasikan menggunakan kelas `std::stack` dari Standard Template Library (STL). `std::stack` bukanlah struktur data independen, melainkan sebuah **adaptor kontainer**. Ini berarti `std::stack` membungkus (mengadaptasi) kontainer STL lain yang sudah ada, seperti `std::deque`, `std::list`, atau `std::vector`, dan menyediakan antarmuka yang hanya mengekspos operasi _stack_ (LIFO).

Secara _default_, jika tidak ada kontainer dasar yang ditentukan saat mendeklarasikan `std::stack`, `std::deque` akan digunakan sebagai kontainer dasar. Pemilihan `std::deque` sebagai _default_ adalah keputusan desain yang disengaja karena `std::deque` menawarkan efisiensi tinggi untuk operasi penambahan dan penghapusan elemen di kedua ujungnya, termasuk `push_back()` dan `pop_back()` dengan kompleksitas waktu $O(1)$ dalam kasus terburuk. Ini sangat menguntungkan untuk operasi `push` dan `pop` pada _stack_, karena `std::deque` dapat tumbuh dan menyusut secara efisien tanpa realokasi memori yang mahal dan penyalinan elemen yang mungkin terjadi pada `std::vector` ketika kapasitasnya terlampaui.

Meskipun `std::deque` adalah _default_, pengembang dapat secara eksplisit memilih `std::vector` atau `std::list` sebagai kontainer dasar. Namun, `std::vector` umumnya tidak direkomendasikan untuk `std::stack` jika operasi `push` dan `pop` sangat sering dilakukan dan ukuran _stack_ sering berubah secara signifikan, karena potensi realokasi dan penyalinan elemen dapat menurunkan kinerja.

Sementara itu, `std::list` dapat menghindari biaya realokasi, tetapi mungkin memiliki _overhead_ memori tambahan karena setiap node memerlukan memori untuk _pointer_.

## 4. Fungsi-fungsi Dasar (Operasi) Stack

`std::stack` menyediakan serangkaian fungsi anggota publik yang memungkinkan interaksi dengan _stack_ sesuai prinsip LIFO. Fungsi-fungsi ini adalah inti dari fungsionalitas _stack_:

### 4.1. Fungsi `push()`

Fungsi `push()` digunakan untuk menambahkan elemen baru ke bagian atas (puncak) _stack_. Ketika sebuah elemen didorong ke _stack_, ukuran _stack_ bertambah satu, dan elemen baru tersebut menjadi elemen teratas yang baru. Dalam implementasi berbasis array, ini melibatkan penambahan indeks `top` dan menempatkan elemen pada posisi baru tersebut. Jika _stack_ sudah penuh (dalam implementasi array dengan ukuran tetap), kondisi _stack overflow_ dapat terjadi.

**Contoh Penggunaan `std::stack::push()`:**

```cpp
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> languages;

    // Menambahkan elemen ke stack
    languages.push("C++");
    languages.push("Java");
    languages.push("Python");

    std::cout << "Elemen teratas setelah push: " << languages.top() << std::endl; // Output: Python
    return 0;
}
```

Pada contoh di atas, "Python" adalah elemen terakhir yang didorong, sehingga menjadi elemen teratas.

### 4.2. Fungsi `pop()`

Fungsi `pop()` digunakan untuk menghapus elemen teratas dari _stack_. Fungsi ini hanya menghapus elemen dan tidak mengembalikan nilainya secara langsung. Setelah operasi `pop()`, elemen yang sebelumnya berada di bawah elemen yang dihapus akan menjadi elemen teratas yang baru. Jika _stack_ sudah kosong saat `pop()` dipanggil, kondisi _stack underflow_ dapat terjadi.

**Contoh Penggunaan `std::stack::pop()`:**

```cpp
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> colors;
    colors.push("Red");
    colors.push("Orange");
    colors.push("Blue");

    std::cout << "Stack awal (dari atas ke bawah): Blue, Orange, Red" << std::endl;
    colors.pop(); // Menghapus "Blue"

    std::cout << "Elemen teratas setelah pop: " << colors.top() << std::endl; // Output: Orange
    return 0;
}
```

Dalam contoh ini, "Blue" dihapus karena merupakan elemen teratas, dan "Orange" kemudian menjadi elemen teratas.

### 4.3. Fungsi `top()`

Fungsi `top()` digunakan untuk mengakses (melihat) elemen yang berada di bagian paling atas _stack_ tanpa menghapusnya. Fungsi ini mengembalikan referensi ke elemen teratas. 

Penting untuk memastikan _stack_ tidak kosong sebelum memanggil `top()`, karena mengakses elemen dari _stack_ kosong akan menghasilkan perilaku tak terdefinisi.

**Contoh Penggunaan `std::stack::top()`:**

```cpp
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> colors;
    colors.push("Red");
    colors.push("Orange");
    colors.push("Blue");

    std::string topElement = colors.top();
    std::cout << "Elemen teratas: " << topElement << std::endl; // Output: Blue
    return 0;
}
```

Elemen "Blue" adalah yang terakhir dimasukkan, sehingga `top()` mengembalikannya.

### 4.4. Fungsi `empty()`

Fungsi `empty()` digunakan untuk memeriksa apakah _stack_ kosong atau tidak. Fungsi ini mengembalikan nilai boolean:

`true` jika _stack_ tidak mengandung elemen apa pun, dan `false` jika _stack_ memiliki setidaknya satu elemen. Ini adalah fungsi penting untuk mencegah kondisi _underflow_ saat melakukan operasi `pop()` atau `top()`.

**Contoh Penggunaan `std::stack::empty()`:**

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> st;

    if (st.empty()) {
        std::cout << "Stack kosong." << std::endl; // Output: Stack kosong.
    } else {
        std::cout << "Stack tidak kosong." << std::endl;
    }

    st.push(11);

    if (st.empty()) {
        std::cout << "Stack kosong." << std::endl;
    } else {
        std::cout << "Stack tidak kosong." << std::endl; // Output: Stack tidak kosong.
    }
    return 0;
}
```

Contoh ini menunjukkan bagaimana `empty()` berubah status setelah elemen ditambahkan.

### 4.5. Fungsi `size()`

Fungsi `size()` mengembalikan jumlah elemen yang saat ini ada di dalam _stack_. Ini memberikan informasi tentang ukuran _stack_ saat ini, yang dapat berguna untuk berbagai tujuan, seperti alokasi memori atau debugging.

**Contoh Penggunaan `std::stack::size()`:**

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> prime_nums;
    prime_nums.push(2);
    prime_nums.push(3);
    prime_nums.push(5);

    int size = prime_nums.size();
    std::cout << "Ukuran stack: " << size << std::endl; // Output: 3
    return 0;
}
```

Fungsi `size()` dengan cepat mengembalikan jumlah elemen yang ada.

## 5. Implementasi Stack di C++

Implementasi _stack_ di C++ dapat dilakukan dengan beberapa cara, baik secara manual maupun memanfaatkan pustaka standar.

### 5.1. Menggunakan `std::stack` (Standard Template Library)

Cara paling umum dan direkomendasikan untuk menggunakan _stack_ di C++ adalah melalui `std::stack` dari STL. Seperti yang telah dijelaskan, `std::stack` adalah adaptor kontainer yang menyederhanakan penggunaan _stack_ dengan mengabstraksi detail implementasi kontainer dasarnya.

---

#### Deklarasi dan Inisialisasi `std::stack`:

Untuk mendeklarasikan `std::stack`, header `<stack>` harus disertakan. Pengguna dapat memilih tipe data elemen yang akan disimpan, dan secara opsional, kontainer dasar yang akan digunakan.

- **Dengan Kontainer Dasar _Default_ (`std: :deque`):**
    

    ```cpp
    #include <stack>
    
    std::stack<int> myStack; // Menggunakan std::deque<int> secara implisit
    ```
    
    `myStack` akan menyimpan integer dan menggunakan `std::deque` sebagai wadah internalnya.
    
- **Menggunakan `std::vector` sebagai Kontainer Dasar:**
    
    ```cpp
    #include <stack>
    #include <vector>
    
    std::stack<int, std::vector<int>> myVectorStack; // Menggunakan std::vector<int>
    ```
    
    `myVectorStack` akan menyimpan integer yang dikelola oleh `std::vector`.
    
- **Menggunakan `std::list` sebagai Kontainer Dasar:**
    
    ```cpp
    #include <stack>
    #include <list>
    
    std::stack<int, std::list<int>> myListStack; // Menggunakan std::list<int>
    ```
    
    `myListStack` akan menyimpan integer yang dikelola oleh `std::list`.

---

#### Contoh Implementasi `std::stack` Lengkap:

Berikut adalah contoh program yang menunjukkan penggunaan fungsi-fungsi dasar `std::stack`:

```cpp
#include <iostream>
#include <stack> // Diperlukan untuk std::stack
#include <string>

// Fungsi utilitas untuk mencetak isi stack (dengan membuat salinan karena stack tidak bisa di-traverse langsung)
void printStack(std::stack<std::string> st) {
    std::cout << "Isi stack (dari atas ke bawah): ";
    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

int main() {
    // Deklarasi stack dengan kontainer default (std::deque)
    std::stack<std::string> tasks;

    // 1. Operasi push()
    std::cout << "--- Operasi PUSH ---" << std::endl;
    tasks.push("Mengerjakan Laporan");
    tasks.push("Membalas Email");
    tasks.push("Menghadiri Rapat");
    std::cout << "Ukuran stack setelah push: " << tasks.size() << std::endl; // Output: 3
    printStack(tasks); // Output: Menghadiri Rapat Membalas Email Mengerjakan Laporan

    std::cout << "\n--- Operasi TOP ---" << std::endl;
    // 2. Operasi top()
    if (!tasks.empty()) {
        std::cout << "Elemen teratas: " << tasks.top() << std::endl; // Output: Menghadiri Rapat
    }

    std::cout << "\n--- Operasi POP ---" << std::endl;
    // 3. Operasi pop()
    tasks.pop(); // Menghapus "Menghadiri Rapat"
    std::cout << "Ukuran stack setelah 1x pop: " << tasks.size() << std::endl; // Output: 2
    if (!tasks.empty()) {
        std::cout << "Elemen teratas baru: " << tasks.top() << std::endl; // Output: Membalas Email
    }
    printStack(tasks); // Output: Membalas Email Mengerjakan Laporan

    std::cout << "\n--- Operasi EMPTY ---" << std::endl;
    // 4. Operasi empty() dan membersihkan stack
    while (!tasks.empty()) {
        std::cout << "Pop: " << tasks.top() << std::endl;
        tasks.pop();
    }
    std::cout << "Ukuran stack setelah semua pop: " << tasks.size() << std::endl; // Output: 0
    if (tasks.empty()) {
        std::cout << "Stack sekarang kosong." << std::endl; // Output: Stack sekarang kosong.
    }

    return 0;
}
```

### 5.2. Implementasi Stack Berbasis Array (Konseptual)

Meskipun `std::stack` adalah pilihan utama, memahami implementasi manual memberikan pemahaman yang lebih dalam. Stack dapat diimplementasikan menggunakan array. Dalam pendekatan ini, array digunakan untuk menyimpan elemen, dan sebuah variabel integer (misalnya, `top`) digunakan untuk melacak indeks elemen teratas.

- **`push`**: Untuk menambahkan elemen, indeks `top` akan ditambah, lalu elemen baru ditempatkan pada `array[top]`. Batasan utama adalah ukuran array yang tetap; jika array penuh, operasi `push` akan menyebabkan _stack overflow_.
<br/>

- **`pop`**: Untuk menghapus elemen, nilai dari `array[top]` akan diambil (atau diabaikan), lalu indeks `top` akan dikurangi. Jika `top` sudah berada di bawah batas (misalnya -1), operasi `pop` akan menyebabkan _stack underflow_.
<br/>
- **`top`**: Mengakses elemen cukup dengan mengembalikan `array[top]`.

Implementasi array sederhana dan cepat untuk akses elemen karena lokasi memori yang berdekatan. Namun, kurangnya fleksibilitas dalam ukuran tetap menjadi kelemahan signifikan.

### 5.3. Implementasi Stack Berbasis Linked List (Konseptual)

Alternatif lain adalah mengimplementasikan _stack_ menggunakan _linked list_. Dalam kasus ini, setiap elemen _stack_ adalah sebuah _node_ dalam _linked list_, dan _node_ teratas (head) dari _linked list_ berfungsi sebagai "top" dari _stack_.

- **`push`**: Menambahkan elemen baru berarti membuat _node_ baru dan menjadikannya _head_ baru dari _linked list_, sambil menunjuk _node_ lama sebagai _node_ berikutnya.
<br/>

- **`pop`**: Menghapus elemen berarti menghapus _node_ _head_ dan menjadikan _node_ berikutnya sebagai _head_ baru.
<br/>

- **`top`**: Mengakses elemen teratas cukup dengan melihat data pada _node_ _head_.
    

Keuntungan utama dari implementasi _linked list_ adalah **ukuran yang dinamis**; _stack_ dapat tumbuh atau menyusut sesuai kebutuhan tanpa khawatir akan _overflow_ (kecuali memori sistem habis). Namun, ada _overhead_ memori karena setiap _node_ memerlukan _pointer_ tambahan, dan operasi mungkin sedikit lebih lambat dibandingkan array karena manipulasi _pointer_.
## 6. Kegunaan dan Aplikasi Nyata Stack

_Stack_ adalah struktur data yang sangat serbaguna dengan berbagai aplikasi penting dalam ilmu komputer dan pengembangan perangkat lunak:

### 6.1. Manajemen Panggilan Fungsi (Call Stack)

Salah satu aplikasi paling krusial dari _stack_ adalah pengelolaan panggilan fungsi dalam program, terutama untuk fungsi rekursif. Ketika sebuah fungsi dipanggil, detail eksekusinya (seperti variabel lokal dan alamat pengembalian) didorong ke dalam _call stack_. Ketika fungsi selesai, detailnya dihapus (_pop_) dari _stack_, dan eksekusi kembali ke alamat pengembalian yang disimpan.

Ini memungkinkan rekursi bekerja dengan benar, seperti yang terlihat pada algoritma penetapan harga yang kompleks di platform seperti Airbnb yang menggunakan panggilan rekursif untuk menganalisis data historis.

### 6.2. Evaluasi Ekspresi

_Stack_ digunakan secara luas dalam mengevaluasi ekspresi matematika, terutama untuk mengonversi ekspresi dari notasi _infix_ (misalnya, `A + B * C`) ke notasi _postfix_ (misalnya, `ABC*+`) atau _prefix_. Misalnya, di Microsoft Word, mekanisme berbasis _stack_ mengelola tindakan pengguna, memungkinkan pembalikan operasi yang efisien. Setiap tindakan didorong ke _stack_, dan memanggil 'undo' akan menghapus tindakan terbaru, mengembalikan dokumen ke keadaan sebelumnya.

### 6.3. Operasi Undo/Redo

Sebagian besar aplikasi perangkat lunak modern, seperti editor teks atau editor gambar, mengimplementasikan fungsionalitas "Undo" dan "Redo" menggunakan _stack_. Setiap perubahan yang dilakukan pengguna didorong ke _stack_ "Undo". Ketika pengguna memilih "Undo", perubahan terakhir dihapus dari _stack_ "Undo" dan opsional didorong ke _stack_ "Redo". Sebaliknya, "Redo" akan memindahkan perubahan dari _stack_ "Redo" kembali ke _stack_ "Undo".

### 6.4. Validasi Sintaks

Dalam kompilator dan editor kode, _stack_ digunakan untuk memvalidasi sintaks, seperti memeriksa kecocokan tanda kurung `()`, kurung siku `[]`, dan kurung kurawal `{}`. Setiap kali tanda kurung pembuka ditemukan, itu didorong ke _stack_. Ketika tanda kurung penutup ditemukan, elemen teratas dari _stack_ dihapus dan diperiksa untuk kecocokan. Jika tidak cocok atau _stack_ kosong, ada kesalahan sintaks. Editor seperti yang digunakan GitHub memanfaatkan _stack_ untuk validasi sintaks waktu nyata, membantu pengembang menemukan kesalahan saat mereka mengetik.

### 6.5. Navigasi Riwayat Browser

Fungsi tombol "Kembali" dan "Maju" di peramban web diimplementasikan menggunakan _stack_. Setiap halaman web yang dikunjungi didorong ke _stack_ riwayat. Ketika tombol "Kembali" diklik, halaman terakhir yang dikunjungi dihapus dari _stack_ dan ditampilkan. Halaman yang dihapus ini dapat didorong ke _stack_ "Maju" untuk memungkinkan navigasi ke depan.
### 6.6. Algoritma Backtracking

_Stack_ merupakan komponen penting dalam algoritma _backtracking_, yang digunakan dalam penyelesaian masalah seperti mencari jalan keluar dari labirin atau melakukan _Depth-First Search (DFS)_ dalam graf. Ketika algoritma menjelajahi jalur, setiap langkah atau keputusan didorong ke _stack_. Jika jalur tersebut menemui jalan buntu, algoritma akan "mundur" (_backtrack_) dengan menghapus elemen dari _stack_ hingga mencapai titik keputusan sebelumnya, lalu mencoba jalur alternatif.

### 6.7. Penjadwalan CPU

Dalam sistem operasi, _stack_ juga dapat digunakan dalam penjadwalan CPU. Misalnya, proses yang siap dijalankan dapat ditempatkan dalam array "aktif" yang diindeks berdasarkan prioritas. Ketika _time slice_ suatu pekerjaan berakhir, pekerjaan tersebut dipindahkan ke array "kadaluarsa". Dua array ini dapat bertukar peran ketika array "aktif" menjadi kosong, dengan struktur _runqueue_ yang menyimpan array-array ini.
## 7. Keuntungan Menggunakan Stack

Penggunaan _stack_ menawarkan beberapa keuntungan signifikan, terutama dalam skenario di mana prinsip LIFO sangat relevan:

### 7.1. Kesederhanaan dan Kemudahan Implementasi

Konsep LIFO yang sederhana membuat _stack_ mudah dipahami dan diimplementasikan. Operasi terbatas pada satu ujung (top) menyederhanakan logika pemrograman, mengurangi potensi kesalahan.

### 7.2. Efisiensi Waktu untuk Operasi Dasar

Operasi inti `push` dan `pop` pada _stack_ memiliki kompleksitas waktu konstan ($O(1)$). Ini berarti bahwa waktu yang dibutuhkan untuk menambahkan atau menghapus elemen tidak bergantung pada jumlah elemen yang sudah ada di dalam _stack_, menjadikannya sangat cepat untuk operasi-operasi ini.

### 7.3. Manajemen Memori Otomatis - dengan `std::stack`

Ketika menggunakan `std::stack` dari STL, manajemen memori (alokasi dan dealokasi) ditangani secara otomatis oleh kontainer dasar yang dipilih — misalnya, `std::deque` atau `std::vector`. Hal ini mengurangi beban pengembang dalam mengelola memori secara manual, yang sering menjadi sumber bug seperti kebocoran memori pada array C-style.

### 7.4. Organisasi Data yang Jelas

Struktur LIFO secara inheren memberikan cara yang terorganisir untuk mengelola data di mana urutan akses sangat penting. Ini membantu dalam desain perangkat lunak yang bersih dan terstruktur, terutama dalam masalah yang secara alami cocok dengan pola LIFO.

## 8. Kekurangan Stack

Meskipun memiliki banyak keuntungan, _stack_ juga memiliki beberapa keterbatasan yang perlu dipertimbangkan:

### 8.1. Ukuran Tetap (untuk Implementasi Array)

Jika _stack_ diimplementasikan menggunakan array tradisional (C-style array), ukurannya harus ditentukan pada waktu kompilasi dan tidak dapat diubah selama _runtime_. Keterbatasan ini dapat menyebabkan pemborosan memori jika ukuran yang dialokasikan terlalu besar atau

_stack overflow_ jika ukuran yang dialokasikan terlalu kecil untuk menampung semua elemen yang diperlukan.

### 8.2. Akses Elemen Terbatas

Karakteristik LIFO membatasi akses hanya pada elemen teratas _stack_. Tidak ada cara langsung untuk mengakses elemen di tengah atau di bawah _stack_ tanpa terlebih dahulu menghapus elemen-elemen di atasnya. Untuk "melintasi" seluruh _stack_ dan melihat semua elemen, seseorang harus menghapus elemen satu per satu, yang akan mengubah status _stack_ asli.

### 8.3. Overhead Memori (untuk Implementasi Linked List)

Implementasi _stack_ berbasis _linked list_ mengatasi masalah ukuran tetap, tetapi memperkenalkan _overhead_ memori. Setiap _node_ dalam _linked list_ memerlukan memori tambahan untuk menyimpan _pointer_ ke _node_ berikutnya, yang dapat menjadi signifikan untuk _stack_ yang menyimpan banyak elemen kecil.

### 8.4. Potensi Re-alokasi — untuk `std::vector` sebagai Kontainer Dasar

Jika `std::vector` digunakan sebagai kontainer dasar untuk `std::stack`, meskipun menyediakan ukuran dinamis, operasi `push_back` dapat memicu realokasi memori yang mahal jika kapasitas `std::vector` terlampaui. Proses ini melibatkan alokasi blok memori baru yang lebih besar, penyalinan semua elemen yang ada ke lokasi baru, dan dealokasi blok memori lama, yang dapat mempengaruhi kinerja secara signifikan, terutama untuk objek yang kompleks atau _stack_ yang sering tumbuh.

## 9. Kesimpulan

Struktur data _stack_ adalah konsep fundamental dalam ilmu komputer yang beroperasi berdasarkan prinsip LIFO (Last In, First Out), dengan semua operasi terbatas pada satu ujung, yaitu "top". Di C++, `std::stack` dari Standard Template Library (STL) menyediakan implementasi yang kuat dan fleksibel sebagai adaptor kontainer. Secara _default_, `std::deque` dipilih sebagai kontainer dasar untuk `std::stack` karena efisiensi $O(1)$ yang konsisten untuk operasi `push` dan `pop`, yang secara efektif menghindari biaya realokasi yang mungkin terjadi pada `std::vector`.

_Stack_ memiliki kegunaan yang luas dalam berbagai aplikasi dunia nyata, mulai dari manajemen panggilan fungsi (termasuk rekursi), evaluasi ekspresi matematika, fungsionalitas undo/redo di aplikasi, validasi sintaks dalam kompilator, navigasi riwayat peramban web, hingga algoritma _backtracking_. Keunggulannya terletak pada kesederhanaan, efisiensi waktu untuk operasi dasar, dan kemampuan manajemen memori otomatis saat menggunakan `std::stack` dari STL.

Meskipun demikian, penting untuk menyadari keterbatasannya, seperti ukuran tetap pada implementasi berbasis array, akses elemen yang terbatas hanya pada bagian teratas, dan potensi _overhead_ memori pada implementasi _linked list_ atau biaya realokasi pada `std::vector` jika tidak dikelola dengan baik. Memahami karakteristik ini memungkinkan pengembang untuk membuat pilihan yang tepat dalam desain sistem, memastikan bahwa _stack_ digunakan secara optimal untuk masalah yang paling sesuai dengan sifat LIFO-nya.