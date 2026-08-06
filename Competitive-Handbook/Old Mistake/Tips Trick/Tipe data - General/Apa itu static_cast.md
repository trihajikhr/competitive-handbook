---
obsidianUIMode: preview
note_type: tips trick
tips_trick: Apa itu static_cast
sumber: Google.com, AI
tags:
  - tipe-data
  - konvert-tipe-data
---
---
# Apa itu static_cast
**`static_cast`** adalah salah satu operator casting di C++ yang digunakan untuk melakukan konversi tipe (type conversion) secara eksplisit dengan pemeriksaan pada waktu kompilasi. Berbeda dengan C-style cast (`(T)value`), `static_cast<T>(value)` menawarkan:

1. **Compile-time Checking**: Compiler memastikan bahwa konversi tersebut “masuk akal” antara tipe sumber dan tipe tujuan (misalnya, antara tipe numerik, atau antara pointer ke kelas yang saling berhubungan).
    
2. **Keamanan lebih baik** daripada C-style cast, karena tidak melakukan konversi “se asalnya” (misalnya, tidak mengizinkan sembarang reinterpretasi bit, kecuali dalam kasus pointer‐to‐void atau pointer turun‐naik (up/down) pada hierarki kelas yang diketahui).
    
3. **Tanpa Overhead Runtime**: Semua pemeriksaan dilakukan pada saat kompilasi; di runtime, biasanya sama efisiennya dengan konversi bawaan.
    

---

## Kapan Harus Menggunakan `static_cast`

1. **Konversi Numerik (Built-in Types)**
    
    - Misalnya konversi antara integer dan floating-point (`int ↔ double`, `float ↔ long`, dsb.).
        
    - Saat kamu ingin menegaskan bahwa memang sengaja membuang pecahan saat mengubah `double` menjadi `int`, atau sebaliknya.
        
2. **Pointer/Referensi pada Tipe yang Berhubungan (Inheritance)**
    
    - **Upcast** (dari kelas turunan → kelas induk) selalu aman dan bisa dilakukan dengan `static_cast` tanpa pemeriksaan runtime.
        
    - **Downcast** (dari kelas induk → kelas turunan) hanya aman apabila kamu yakin objek sebenarnya memang tipe turunan tersebut. Tidak ada pemeriksaan runtime—jika ternyata objek bukan instance turunan, perilaku menjadi **undefined**.
        
3. **Konversi ke/dari `void*`**
    
    - Ketika kamu menyimpan sebuah pointer dalam `void*` (misalnya dalam struktur data generik), lalu ingin mengembalikannya ke tipe aslinya. Conver­sion dari `T*` ke `void*` dan sebaliknya boleh dilakukan dengan `static_cast`.
        
4. **Menghilangkan `const`/`volatile`?**
    
    - **Tidak bisa**! Untuk melepaskan `const` atau `volatile` dari sebuah objek, Anda harus memakai `const_cast`, bukan `static_cast`.
        
5. **Mengonversi Enum ke Tipe Integral**
    
    - Misalnya mengubah `enum Color { RED, GREEN, BLUE };` → `int` atau sebaliknya, asalkan Anda yakin nilainya sesuai. Namun hati-hati: jika nilai enum tidak dalam rentang integral target, perilaku bisa undefined.
        
6. **Membuat Kode Lebih Jelas (Self-Documenting)**
    
    - Dengan `static_cast`, niat “saya tahu saya mengonversi ini dari T₁ ke T₂ secara eksplisit” menjadi jelas pada pembaca kode.
        
    - Hindari C-style cast karena kurang terkontrol: C-style cast dapat berperilaku seperti `static_cast`, `reinterpret_cast`, atau bahkan `const_cast`, tergantung konteks—menyebabkan potensi bug terselubung.
        

---

## Contoh-Contoh Penggunaan `static_cast`

### 1. Konversi Numerik

```cpp
#include <iostream>
using namespace std;

int main() {
    double x = 3.14159;
    // Konversi eksplisit dari double ke int: buang bagian desimal
    int i = static_cast<int>(x);
    cout << "Nilai x (double): " << x << "\n";
    cout << "Setelah static_cast<int>(x): " << i << "\n\n";

    int a = 10, b = 3;
    // Konversi salah satu operand ke double agar pembagian floating-point
    double hasil = static_cast<double>(a) / b;  
    cout << a << " / " << b << " = " << hasil << "\n";  // 3.33333...
    return 0;
}
```

- `static_cast<int>(x)` secara eksplisit “memaksa” nilai `x` (3.14159) dipotong menjadi integer 3.
    
- Jika kita hanya menulis `a / b` tanpa cast, hasilnya `3` (integer division). Dengan `static_cast<double>(a)`, maka `a` jadi `double` → operasi menjadi floating-point division.
    

---

### 2. Upcast dan Downcast pada Inheritance

Misalkan terdapat hierarki kelas:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void info() const { cout << "Ini Base\n"; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void info() const override { cout << "Ini Derived\n"; }
    void hanyaDiDerived() const { cout << "Method khusus Derived\n"; }
};

int main() {
    Derived d;
    Base* ptrBase = &d;                     // Implicit upcast: Derived* → Base*
    ptrBase->info();                        // Output: "Ini Derived" (polimorfisme)

    // Downcast: Base* → Derived*
    Derived* ptrDer = static_cast<Derived*>(ptrBase);
    ptrDer->hanyaDiDerived();               // Aman, karena ptrBase sebenarnya menunjuk ke Derived

    // Jika kita lakukan downcast yang tidak sah:
    Base b;
    Base* ptrBase2 = &b;                    // ptrBase2 memang menunjuk objek Base asli
    Derived* ptrDer2 = static_cast<Derived*>(ptrBase2);
    // ptrBase2 bukan objek Derived → memanggil fungsi di ptrDer2 menjadi undefined behavior!
    // ptrDer2->hanyaDiDerived();  <-- Jangan lakukan ini, UB.

    return 0;
}
```

- **Upcast (tanda panah ke atas)**: `Derived*` → `Base*`. Implicit (otomatis) aman, tapi bisa juga ditulis `static_cast<Base*>(&d)`.
    
- **Downcast (tanda panah ke bawah)**: `Base*` → `Derived*`. Hanya aman jika objek yang direferensikan memang bertipe `Derived`.
    
    - `static_cast` tidak melakukan pemeriksaan runtime, jadi jangan lakukan jika ragu.
        
    - Jika perlu pemeriksaan di runtime (menghindari UB), gunakan `dynamic_cast<Derived*>(ptrBase)`—hanya bekerja jika kelas punya setidaknya satu `virtual` method (sehingga memiliki _polymorphic type_).
        

---

### 3. Konversi ke/dari `void*`

```cpp
#include <iostream>
using namespace std;

void fungsiGenerik(void* data, bool isInt) {
    if (isInt) {
        int* ptrInt = static_cast<int*>(data);
        cout << "Nilai int: " << *ptrInt << "\n";
    } else {
        double* ptrDouble = static_cast<double*>(data);
        cout << "Nilai double: " << *ptrDouble << "\n";
    }
}

int main() {
    int   x = 42;
    double y = 2.718;

    // Simpan pointer ke void*
    void* v1 = static_cast<void*>(&x);
    void* v2 = static_cast<void*>(&y);

    fungsiGenerik(v1, true);    // Output: Nilai int: 42
    fungsiGenerik(v2, false);   // Output: Nilai double: 2.718

    return 0;
}
```

- Saat kita me-_cast_ `&x` (tipe `int*`) menjadi `void*`, kemudian di dalam fungsi kita mengembalikannya ke `int*` dengan `static_cast<int*>(data)`.
    
- Ingat: konversi ini aman hanya jika kita yakin bahwa `data` memang awalnya berasal dari `int*` (atau `double*`).
    

---

### 4. Konversi Antar Tipe Integral/Lebih Umum di Template

Kadang di template, kita ingin mengizinkan konversi antar tipe selama kompatibilitas pada kompilasi:

```cpp
#include <iostream>
using namespace std;

// Fungsi template yang menerima tipe sumber S, menghasilkan tipe tujuan T
template <typename T, typename S>
T convertValue(const S& sumber) {
    return static_cast<T>(sumber);
}

int main() {
    float f = 3.14f;
    int   i = convertValue<int>(f);       // static_cast<int>(3.14f) → 3
    cout << "float f = " << f << "; setelah convert ke int: " << i << "\n\n";

    long long ll = 1234567890123LL;
    double d     = convertValue<double>(ll);
    cout << "long long ll = " << ll << "; setelah convert ke double: " << d << "\n";

    return 0;
}
```

- `convertValue<int>(f)` memanggil `static_cast<int>(f)`.
    
- Dengan template, konversi nilai antar tipe bisa di-abstraksi ke satu fungsi.
    

---

## Perbandingan dengan Operator Cast Lain
Berikut perbandingan `static_cast` dengan operator casting lainnya (tanpa tabel) dalam bentuk penjelasan naratif:

### 1. `static_cast` vs. C-Style Cast (`(T)value`)

- **C-Style Cast**
    
    - Sintaksnya sederhana, misalnya `(int)x` atau `(Derived*)ptrBase`.
        
    - Namun di baliknya, compiler akan mencoba beberapa jenis cast (seperti `static_cast`, `reinterpret_cast`, atau bahkan `const_cast`) tergantung konteks. Akibatnya, kita tidak selalu tahu pasti apa yang terjadi—apakah bit reinterpretasi, konversi numerik, atau pelepasan `const`.
        
    - Karena tidak eksplisit, C-style cast dapat menimbulkan bug terselubung: misalnya secara tidak sengaja me‐remove qualifier `const`, atau memaksa reinterpretasi pointer yang berbahaya.
        
- **`static_cast`**
    
    - Jelas memberitahukan compiler dan pembaca bahwa kita hanya ingin melakukan konversi yang “masuk akal” di waktu kompilasi: seperti konversi numerik (misalnya `double`→`int`), upcast/downcast antar kelas yang masih berada dalam hierarki (tanpa pemeriksaan runtime), atau pointer ↔ `void*`.
        
    - Karena sifatnya terkontrol, kita bisa melihat pada kode bahwa kita sengaja membatasi konversi hanya pada jenis yang diizinkan oleh `static_cast`. Ini meminimalkan ambiguitas dan potensi kesalahan dibandingkan C-style cast, meski tidak mencegah semua kesalahan (terutama pada downcast yang tidak aman).
        

---

### 2. `static_cast` vs. `dynamic_cast`

- **`dynamic_cast`**
    
    - Hanya berlaku ketika ada setidaknya satu metode virtual dalam hierarki kelas (menjadikan kelas tersebut “polymorphic”).
        
    - Saat dipakai untuk downcast (misalnya `Base*`→`Derived*`), `dynamic_cast` akan memeriksa di runtime apakah objek yang dirujuk benar‐benar instance `Derived`. Jika tidak, ia mengembalikan `nullptr` (atau melempar `bad_cast` jika digunakan pada referensi).
        
    - Lebih aman untuk downcast karena mencegah behavior tak terdefinisi (undefined behavior) saat tipe objek tidak sesuai, tetapi ada overhead RTTI (runtime type information).
        
- **`static_cast`**
    
    - Tidak melakukan pengecekan di runtime. Jika kita melakukan downcast `static_cast<Derived*>(ptrBase)` pada objek yang sebenarnya bukan `Derived`, maka hasilnya **undefined behavior** tanpa peringatan.
        
    - Dibandingkan `dynamic_cast`, `static_cast` lebih cepat (karena tidak ada pemeriksaan runtime), tetapi hanya boleh digunakan jika kita 100% yakin bahwa konversi itu valid—misalnya kita memang tahu objek tersebut benar‐benar berasal dari tipe turunan.
        

---

### 3. `static_cast` vs. `reinterpret_cast`

- **`reinterpret_cast`**
    
    - Melakukan reinterpretasi bit secara bebas: misalnya mengubah `int*` menjadi `double*`, atau mengubah pointer fungsi menjadi tipe integer tertentu.
        
    - Tidak ada jaminan keamanan, tidak ada pemeriksaan sama sekali; hasilnya bergantung sepenuhnya pada bagaimana bit dibaca ulang. Sangat cocok untuk operasi low-level, misalnya memetakan alamat memori, membuat union aman, atau berinteraksi dengan API C yang memerlukan layout memori tertentu.
        
    - Karena sifatnya ekstrem bebas, sangat mudah memicu bug dan undefined behavior jika bukan dilakukan oleh programmer yang benar-benar memahami implikasi bit‐level.
        
- **`static_cast`**
    
    - Tidak mengizinkan reinterpretasi bit antar tipe yang sama sekali tidak berhubungan. Kita hanya boleh menggunakannya jika memang ada konversi yang masuk akal (misalnya numerik, upcast/downcast di dalam satu hierarki, atau `void*`).
        
    - Karena batasannya lebih ketat, `static_cast` lebih aman daripada `reinterpret_cast` untuk sebagian besar kasus umum. Jika kita membutuhkan konversi low-level yang “memaksa” reinterpretasi data di memori, barulah kita beralih ke `reinterpret_cast`.
        

---

### 4. `static_cast` vs. `const_cast`

- **`const_cast`**
    
    - Satu-satunya operator cast yang mengizinkan kita menambah atau menghilangkan qualifier `const` atau `volatile`.
        
    - Contoh: `const int* p = …; int* q = const_cast<int*>(p);` Menghilangkan sifat `const` dari pointer.
        
    - Hanya boleh dipakai jika kita yakin objek aslinya sebenarnya tidak dideklarasikan sebagai `const`; kalau tidak, memodifikasi nilai melalui pointer hasil `const_cast` bisa menimbulkan undefined behavior.
        
- **`static_cast`**
    
    - **Tidak** bisa digunakan untuk menghilangkan atau menambahkan qualifier `const`/`volatile`. Jika mencoba, compiler akan menolak.
        
    - Karena `static_cast` tidak bisa mengubah “constness”, kita dipaksa untuk memilih `const_cast` jika memang sengaja ingin drop qualifier, sehingga niat kita menjadi eksplisit dan pembaca kode tahu bahwa kita benar‐benar berniat memodifikasi objek yang mungkin diberi qualifier.
        

---

### 5. Kapan Waktu yang Tepat Menggunakan `static_cast`?

1. **Konversi Numerik**
    
    - Saat kamu punya `double d = 3.99;` dan ingin membuang bagian desimal, kamu tuliskan `int i = static_cast<int>(d);`.
        
    - Atau jika kamu melakukan perhitungan di template: `static_cast<double>(a) / b` agar pembagian dilakukan dalam floating-point.
        
2. **Upcast/Downcast di Hierarki Kelas (Tanpa Pemeriksaan Runtime)**
    
    - **Upcast**: Dari turunan ke induk (misalnya `Derived*`→`Base*`) sebenarnya bisa implicit, tapi kamu bisa menulis `static_cast<Base*>(derivedPtr)` agar lebih eksplisit.
        
    - **Downcast**: Dari induk ke turunan (misalnya `Base*`→`Derived*`) saat kamu yakin objek yang diacu memang instance `Derived`. Gunakan `static_cast` jika kamu tidak ingin overhead RTTI, tetapi pahami risikonya (jika tebakanmu salah, program akan undefined behavior).
        
3. **Konversi Pointer ke/dari `void*`**
    
    - Misalnya menyimpan pointer ke berbagai tipe dalam wadah generik lalu mengambilnya kembali:
        
        ```cpp
        void* vp = static_cast<void*>(someIntPtr);
        // ...
        int* intp = static_cast<int*>(vp);
        ```
        
    - `static_cast` di sini memastikan compiler mengizinkan konversi pointer tanpa ubahan bit, karena pointer ke tipe apa saja bisa di‐cast ke/dari `void*`.
        
4. **Penggunaan di Template untuk Memastikan Tipe**
    
    - Di fungsi atau kelas templat, kadang kita perlu mengubah satu tipe menjadi tipe lain yang kompatibel. Misalnya:
        
        ```cpp
        template <typename T>
        void printValue(const T& val) {
            double x = static_cast<double>(val); // misalnya agar diperlakukan sebagai double
            cout << x << "\n";
        }
        ```
        
    - Dengan `static_cast`, hasil kompilasi akan gagal jika `T` tidak convertible ke `double`.
        

---

### 6. Contoh Lengkap Kode Menyorot Perbedaan

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void info() const { cout << "Ini Base\n"; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void info() const override { cout << "Ini Derived\n"; }
    void onlyDerived() const { cout << "Method khusus Derived\n"; }
};

int main() {
    // 1. Konversi numerik menggunakan static_cast
    double d = 5.99;
    int    i = static_cast<int>(d);   // i = 5
    cout << "static_cast<int>(5.99) = " << i << "\n";

    // 2. C-Style cast yang “kaya pake bumbu”: 
    // bisa jadi static, reinterpret, atau const cast tergantung konteks
    int j = (int) d;                   // sama hasilnya, tapi kurang eksplisit
    cout << "(int)5.99 = " << j << "\n";

    // 3. Upcast/Downcast pada kelas
    Derived derivedObj;
    Base*   ptrB = &derivedObj;    
    ptrB->info();                     // Memanggil “Ini Derived” (polimorfisme)

    // Downcast menggunakan static_cast
    Derived* ptrD1 = static_cast<Derived*>(ptrB);
    ptrD1->onlyDerived();             // Aman, karena ptrB memang menunjuk ke Derived

    // Downcast yang salah → undefined behavior jika dipanggil methodnya
    Base baseObj;
    Base* ptrB2 = &baseObj;
    // Tanpa runtime check, static_cast langsung menerima
    Derived* ptrD2 = static_cast<Derived*>(ptrB2);
    // Kalau kita panggil ptrD2->onlyDerived(), hasilnya undefined behavior

    // 4. Downcast menggunakan dynamic_cast (aman tapi perlu RTTI)
    Derived* ptrD3 = dynamic_cast<Derived*>(ptrB2);
    if (ptrD3) {
        ptrD3->onlyDerived();
    } else {
        cout << "dynamic_cast gagal: ptrB2 bukan Derived\n";
    }

    // 5. reinterpret_cast : memaksa ubah interpretasi bit
    int  x = 65;
    char* cptr = reinterpret_cast<char*>(&x);
    // Sekarang cptr menunjuk ke byte pertama dalam memori x (low-endian), 
    // jika dibaca *cptr mungkin 'A' (ASCII 65), 
    // tapi ini tergantung arsitektur dan endian—sangat low-level.

    cout << "reinterpret_cast<char*>(&x) → '" << *cptr << "'\n";

    // 6. const_cast (menghilangkan const)
    const int ci = 10;
    const int* pci = &ci;
    // static_cast<int*>(pci);   // Salah! static_cast tidak bisa hapus const.
    int* pi = const_cast<int*>(pci);  
    *pi = 20;                     // Jika ci awalnya memang const, ini UB (undefined behaviour).
    cout << "Setelah const_cast, *pi = " << *pi << "\n"; 

    return 0;
}
```

Pada contoh:

- **`static_cast<int>(double)`** hanya menghapus bagian desimal, aman di compile-time.
    
- **`(int)double`** (C-style cast) bekerja mirip, tapi lebih ambigu di konteks lain.
    
- **`static_cast<Derived*>(ptrB)`** melakukan downcast tanpa cek runtime (bahaya jika pointer tidak valid).
    
- **`dynamic_cast<Derived*>(ptrB)`** memeriksa runtime dan menolak jika tipe tidak cocok.
    
- **`reinterpret_cast<char*>(&x)`** memaksa membaca ulang memori `int` sebagai `char`, hasilnya tergantung endian/arsitektur.
    
- **`const_cast<int*>(pci)`** menghapus qualifier `const`, sehingga kita bisa menulis ke lokasi yang seharusnya `const`—potensi undefined behavior jika fakta aslinya memang memori konstan.
    

---

### 7. Kesimpulan Singkat

- **`static_cast`** digunakan untuk konversi yang masuk akal pada compile-time (numerik, up/downcast yang sudah pasti valid, pointer ↔ `void*`).
    
- **Hindari** downcast `static_cast` jika tidak yakin tipe objeknya; gunakan `dynamic_cast` jika butuh keamanan runtime.
    
- **Jangan** pakai `static_cast` untuk menghapus `const` (`const_cast` yang tepat).
    
- **Kalau butuh reinterpretasi bit secara brutal**, gunakan `reinterpret_cast`—tetapi hanya jika kamu paham implikasi low-level-nya.
    
- **C-Style cast** sebaiknya dihindari karena terlalu permisif dan kurang eksplisit; gunakan cast C++ (static, dynamic, const, reinterpret) agar niat konversi jelas di kode.
    

Dengan pemahaman ini, kamu dapat memilih jenis casting yang paling tepat sesuai kasus: keamanan vs. kinerja, tingkat pemeriksaan di runtime vs. toleransi ambigu, dan kebutuhan untuk mengubah qualifier `const`.

---

## Tips dan Praktik Baik (Best Practices)

1. **Selalu Utamakan `static_cast` Daripada C-Style Cast**
    
    - Kode menjadi lebih eksplisit dan lebih aman. Pembaca kode tahu ini adalah konversi yang “masuk akal” antara tipe tertentu.
        
2. **Hindari Downcast dengan `static_cast` Jika Tidak Yakin**
    
    - Jika ragu apakah objek sebenarnya bertipe turunan, gunakan `dynamic_cast<T*>`.
        
    - Contoh:
        
        ```cpp
        Base* b = getSomeBasePointer();
        if (Derived* d = dynamic_cast<Derived*>(b)) {
            // Aman: hanya masuk ke sini jika b memang menunjuk ke Derived
            d->hanyaDiDerived();
        } else {
            // b bukan objek Derived
        }
        ```
        
3. **Gunakan untuk Konversi Numerik yang Eksplisit**
    
    - Daripada membiarkan compiler melakukan implicit conversion (yang mungkin menimbulkan peringatan atau kehilangan presisi), lebih baik tulis `static_cast<T>(value)` agar niatmu jelas.
        
4. **Jangan Gunakan `static_cast` untuk Menghilangkan `const`**
    
    - Buat tujuan sempit: `static_cast` tidak dibuat untuk mengubah `const` ke non-`const`. Untuk itu, pakai `const_cast`.
        
5. **Ketahui Batasannya**
    
    - `static_cast` tidak melakukan safe check pada runtime. Kesalahan downcast dapat menyebabkan undefined behavior tanpa peringatan.
        
    - Untuk pointer yang tidak berhubungan sama sekali (misalnya `int*` → `double*`), gunakan `reinterpret_cast` jika memang diperlukan (meski jarang disarankan).
        

---

## Ringkasan

1. **Apa itu `static_cast`?**
    
    - Operator casting bawaan C++ untuk konversi tipe yang “masuk akal” pada waktu kompilasi: numerik, pointer dalam hubungan inheritance, `void*`, enum → integral, dsb.
        
2. **Kapan Menggunakannya?**
    
    - Ketika kamu perlu konversi tipe secara eksplisit dan yakin aman pada compile time.
        
    - Saat ingin menjelaskan niat konversi (lebih baik daripada C-style cast).
        
    - Saat melakukan upcast/downcast sederhana di hierarki kelas (dengan risiko UB pada downcast).
        
    - Saat meng-konversi antara pointer ke tipe konkret ↔ pointer ke `void*`.
        
3. **Contoh Paling Umum**
    
    ```cpp
    // Konversi numerik:
    double d = 9.87;
    int    i = static_cast<int>(d);  // i == 9
    
    // Upcast implicit:
    Derived derivedObj;
    Base* ptrBase = &derivedObj;  
    
    // Downcast (hati-hati: UB jika salah tipe):
    Derived* ptrDer = static_cast<Derived*>(ptrBase);
    
    // Konversi ke/dari void*:
    void* v = static_cast<void*>(&derivedObj);
    Derived* pd = static_cast<Derived*>(v);
    ```
    

Dengan memahami `static_cast`—tujuan, batasan, dan contoh penggunaannya—maka kamu dapat menulis kode C++ yang lebih eksplisit, aman, dan mudah dipahami daripada mengandalkan C-style cast yang terlalu permisif. Semoga membantu!

---
