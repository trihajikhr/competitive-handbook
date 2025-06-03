---
obsidianUIMode: preview
note_type: tips trick
tips_trick: penggunaan template di c++
sumber: chatgpt.com
tags:
  - efisien
  - template-code
---
---
# 🔹 Apa Itu Template?

Template di C++ adalah fitur yang memungkinkan kita menulis **kode yang fleksibel dan dapat digunakan untuk berbagai tipe data**.

Bayangkan kamu punya resep kue yang ingin kamu gunakan untuk membuat berbagai macam rasa—misalnya kue cokelat, kue vanila, atau kue stroberi. Daripada menulis resep baru untuk setiap rasa, kamu cukup punya “reseptemplate” dengan instruksi umum, lalu ganti bahannya sesuai kebutuhan. Di C++, **template** bekerja persis seperti “reseptemplate” itu: kamu menulis satu kode generik yang bisa dipakai untuk berbagai tipe data tanpa harus menyalin-tempel kode berulang-ulang.

---

## Penjelasan Sederhana

- **Template = Cetak Biru (Blueprint) Kode**  
    Saat kamu menuliskan fungsi atau kelas dengan template, sebenarnya kamu sedang membuat “kerangka” (blueprint) yang **belum mengikat tipe** tertentu. Baru saat kamu menggunakan atau memanggil template itu dengan tipe sebenarnya (misalnya `int`, `double`, atau `string`), compiler akan **menggandakan** (instansiasi) kode tersebut—seperti mencetak ulang resep sesuai rasa yang diinginkan.
    
- **Keuntungan Utama:**
    
    1. **Reusable**: Cukup satu definisi, bisa untuk banyak tipe.
        
    2. **Type-safe**: Compiler memeriksa tipe saat kompilasi.
        
    3. **Effisien**: Karena di-compile khusus untuk setiap tipe, sering kali performanya sama bagusnya dengan kalau kamu menulis kode “khusus” untuk masing-masing tipe.
        

---

## Contoh Fungsi Template: `tambah` (add)

Misalnya kamu ingin membuat fungsi penjumlahan untuk `int` dan `double`. Tanpa template, kamu perlu menulis dua versi:

```cpp
int tambahInt(int a, int b) {
    return a + b;
}

double tambahDouble(double a, double b) {
    return a + b;
}
```

Dengan template, cukup satu:

```cpp
#include <iostream>
using namespace std;

// Fungsi template: T sebagai “placeholder” tipe yang bisa apa saja
template <typename T>
T tambah(T a, T b) {
    return a + b;
}

int main() {
    int x = 5, y = 7;
    double p = 3.5, q = 2.1;

    // Compiler otomatis membuat instansiasi tambah<int> dan tambah<double>
    cout << "tambah<int>: " << tambah(x, y) << "\n";       // Output: 12
    cout << "tambah<double>: " << tambah(p, q) << "\n";    // Output: 5.6

    return 0;
}
```

- `template <typename T>`: Menandakan bahwa `T` adalah placeholder untuk suatu tipe yang akan ditentukan nanti.
    
- Saat kamu memanggil `tambah(x, y)`, compiler melihat bahwa `x` dan `y` bertipe `int`, jadi dia membuatlah “salinan” fungsi `tambah<int>(int, int)`. Begitu juga untuk `double`.
    

---

## Contoh Kelas Template: `Kotak` (Box)

Bayangkan kamu ingin membuat wadah (box) yang bisa menyimpan `int`, `string`, atau apa saja. Daripada membuat `BoxInt`, `BoxString`, dll., kamu bisa buat:

```cpp
#include <iostream>
#include <string>
using namespace std;

// Kelas template: T sebagai placeholder tipe data yang disimpan
template <typename T>
class Kotak {
private:
    T isi;

public:
    Kotak(T val) : isi(val) {}

    void printIsi() const {
        cout << isi << "\n";
    }
};

int main() {
    Kotak<int> kotakAngka(100);
    Kotak<string> kotakTeks("Halo, Template!");

    kotakAngka.printIsi();  // Output: 100
    kotakTeks.printIsi();   // Output: Halo, Template!

    return 0;
}
```

- Saat kamu menulis `Kotak<int>`, compiler bikin class khusus yang menyimpan `int`.
    
- Kalau `Kotak<string>`, compiler bikin class khusus yang menyimpan `string`.
    
- Kamu tidak perlu menulis ulang logika “menyimpan” dan “menampilkan” untuk tiap tipe; cukup satu definisi generik.
    

---

## Kapan Harus Menggunakan Template?

1. **Algoritma atau Struktur Data yang Sama untuk Banyak Tipe**  
    Contoh: sorting, pencarian, stack, queue, linked list, dan sebagainya. Daripada menulis lagi untuk setiap tipe (`int`, `double`, custom class), pakai template sekali saja.
    
2. **Menghindari Duplikasi Kode**  
    Template membantu mencegah kamu menyalin-tempel blok kode yang hanya berbeda pada tipe data. Satu definisi bisa melayani banyak kasus.
    
3. **Ingin Kode yang Aman dan “Future-Proof”**  
    Jika di kemudian hari kamu perlu menggunakan tipe data baru (misalnya tipe `Fraction` atau `BigInteger`), cukup memanggil template dengan tipe baru itu; tidak perlu menulis ulang fungsi/kode.
    

---

## Ringkasan “Enak”:

- **Template ≈ Cetak biru**: bikin kode sekali, bisa untuk banyak tipe.
    
- **Syntax sederhana**: tulis `template <typename T>` (atau `template <class T>`) di atas definisi fungsi/kelas.
    
- **Instansiasi**: saat kamu panggil (misalnya `tambah(2, 3.5)`), compiler akan menyesuaikan `T` jadi `int` atau `double` sesuai kebutuhan.
    
- **Hemat waktu & tenaga**: tinggal tambahkan placeholder `T`, dan kamu sudah punya kode “multi-tipe”!
    

Dengan pemahaman ini, kamu bisa mulai memanfaatkan template untuk membuat kode yang lebih ringkas, fleksibel, dan mudah dipelihara. Selamat mencoba!

---
### 🔥 Sintaks

```cpp
template <typename T>
```

- `template` → Kata kunci untuk mendefinisikan template.
- `<typename T>` → `T` adalah **parameter tipe**, yang bisa diganti dengan tipe data apa saja saat digunakan.
- `typename` dan `class` bisa dipakai bergantian (artinya sama).

## 🔹 Contoh **Function Template**

Misalnya kita mau bikin fungsi **max** yang bisa bekerja untuk `int`, `double`, atau tipe lain tanpa harus menulis ulang:

```cpp
#include <iostream>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(3, 7) << "\n";      // int
    cout << myMax(3.5, 2.1) << "\n";  // double
    cout << myMax('a', 'z') << "\n";  // char
}
```

📌 **Penjelasan:**

- `T` akan otomatis digantikan oleh tipe data yang diberikan saat pemanggilan.
- Jadi, kita **nggak perlu bikin banyak fungsi untuk tipe data berbeda**.

## 🔹 Contoh **Class Template**

Kita bisa bikin class template untuk struktur data seperti **Stack** yang bisa menyimpan berbagai tipe data:

```cpp
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T data[100];
    int top;
public:
    Stack() { top = -1; }

    void push(T val) { data[++top] = val; }
    T pop() { return data[top--]; }
};

int main() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    cout << s1.pop() << "\n";  // 20

    Stack<double> s2;
    s2.push(3.14);
    cout << s2.pop() << "\n";  // 3.14
}
```

📌 **Penjelasan:**

- `Stack<int>` → Stack khusus untuk `int`.
- `Stack<double>` → Stack khusus untuk `double`.
- Dengan **template**, kita **cuma perlu bikin satu class** yang bisa dipakai untuk berbagai tipe data.

---

## 🔹 Kesimpulan

- `template <typename T>` membuat **kode lebih fleksibel** dan **dapat digunakan ulang**.
- Bisa dipakai untuk **fungsi** maupun **class**.
- **Hemat waktu**, karena nggak perlu bikin banyak versi untuk tipe data berbeda.

🔥 **Template sering dipakai di STL (Standard Template Library)**, misalnya di `vector<T>`, `map<K, V>`, dll. 🚀