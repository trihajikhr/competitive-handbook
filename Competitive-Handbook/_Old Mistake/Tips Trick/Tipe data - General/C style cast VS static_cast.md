---
obsidianUIMode: preview
note_type: tips trick
tips_trick: C style cast VS static_cast
sumber: Google.com, AI
tags:
  - tipe-data
  - konvert-tipe-data
---
---
# C style cast VS static_cast
Di C++ (dan C), **C-style cast** adalah cara lama untuk mengubah tipe data secara eksplisit. Bentuk dasarnya adalah:

```cpp
(TipeTujuan) ekspresi
```

atau bisa juga:

```cpp
TipeTujuan(ekspresi)
```

Contohnya:

```cpp
int x = 10;
double d = (double) x;      // C-style cast: ubah int → double
char  c = char(x + 65);     // C-style cast: ubah int → char
```

### 1. Bagaimana C-Style Cast Bekerja

- Saat kamu menulis `(TipeTujuan) ekspresi`, compiler mencoba berbagai cara untuk melakukan konversi, dalam urutan kira-kira seperti ini:
    
    1. Jika `ekspresi` sudah dapat di-convert secara **`const_cast`**, maka ia akan menghapus/mengubah qualifier `const`/`volatile` jika memungkinkan.
        
    2. Jika perlu (dan diperbolehkan), ia melakukan **`static_cast`** (misalnya untuk konversi numerik atau upcast/downcast tanpa pemeriksaan runtime).
        
    3. Jika itu juga tidak cukup, ia bisa melakukan **`reinterpret_cast`** (menerjemahkan bit secara mentah, misalnya mengubah pointer `int*` → `char*`).
        
    4. Jika masih gagal, dia mencoba **`const_cast`** lagi pada hasilnya.
        
- Intinya, **C-style cast** adalah “kombinasi” dari semua operator cast (`const_cast`, `static_cast`, `reinterpret_cast`) yang dicoba compiler secara berurutan hingga salah satunya berhasil. Kalau tidak ada yang cocok, maka akan terjadi error.
    

### 2. Contoh Perbandingan dengan `static_cast`

Misalkan kita punya:

```cpp
double  d = 3.7;
int     i1 = (int) d;                // C-style cast → sama dengan static_cast<int>(d)
int     i2 = int(d);                 // juga C-style cast
int     i3 = static_cast<int>(d);    // static_cast
```

Pada kasus konversi numerik `double → int`, ketiganya akan menghasilkan `i1 = 3`, `i2 = 3`, dan `i3 = 3`.

Namun, keuntungan **`static_cast`** adalah:

- Ia hanya melakukan **satu jenis konversi** (yakni yang diperbolehkan oleh aturan `static_cast`).
    
- Lebih eksplisit: pembaca kode tahu persis kita berniat melakukan konversi seperti `static_cast`, bukan mengizinkan semua jenis konversi lain.
    
- Jika konversi tidak bisa dilakukan via `static_cast` (misalnya `int* → double*`), maka compiler akan menolak. Sedangkan C-style cast mungkin akan “menyerah” pada `reinterpret_cast` untuk melakukan konversi bit-level.
    

### 3. Contoh Kasus Pointer/Inheritance

Anggap ada kelas turunan:

```cpp
class Base { /* ... */ };
class Derived : public Base { /* ... */ };

Base* b = new Derived;
```

- **Upcast** (`Derived* → Base*`) terjadi otomatis, atau bisa juga:
    
    ```cpp
    Base* b1 = (Base*) new Derived;          // C-style cast
    Base* b2 = static_cast<Base*>(new Derived); // static_cast
    ```
    
- **Downcast** (`Base* → Derived*`):
    
    ```cpp
    Base*  bBase = new Base;
    Derived* d1 = (Derived*) bBase;                // C-style cast → compiler tidak periksa, bisa UB
    Derived* d2 = static_cast<Derived*>(bBase);    // static_cast → tetap tidak ada pemeriksaan runtime, juga bisa UB
    Derived* d3 = dynamic_cast<Derived*>(bBase);   // dynamic_cast → melakukan pengecekan runtime, aman (menghasilkan nullptr jika bukan Derived)
    ```
    
    - Dengan **C-style cast**, compiler “akan coba” melakukan downcast melalui `static_cast`. Kalau objek sebenarnya bukan `Derived`, maka saat kamu akses anggota `Derived`, hasilnya **undefined behavior** tanpa peringatan.
        
    - Dengan **`dynamic_cast`**, compiler menyertakan pemeriksaan runtime: `d3` akan menjadi `nullptr` jika `bBase` bukan objek `Derived`, sehingga kamu dapat memeriksa dan menghindari UB.
        

### 4. Mengapa Hati-hati dengan C-Style Cast?

1. **Terlalu “Luwes”**: C-style cast dapat melakukan berbagai jenis konversi, termasuk yang sangat berisiko (reinterpret_cast). Ini membuat kode kadang sulit dipahami: kita tidak tahu apakah compiler melakukan `static_cast`, `reinterpret_cast`, atau `const_cast`.
    
2. **Penghilangan `const`/`volatile`**: C-style cast bisa juga menghapus `const` secara diam-diam. Contohnya:
    
    ```cpp
    const int ci = 5;
    int* p = (int*) &ci;   // C-style cast mengizinkan hapus const—bahaya
    *p = 10;               // Undefined Behavior, karena ci awalnya const
    ```
    
    Dengan `static_cast<int*>(&ci)`, ini tidak akan diperbolehkan (compiler error)—untuk melepas `const`, seharusnya menggunakan `const_cast`.
    
3. **Lebih Sulit Dilacak**: Saat seseorang membaca kode dan melihat `(TipeTujuan) ekspresi`, tidak langsung jelas tipe konversi apa yang sebenarnya terjadi. Sedangkan `static_cast<>()`, `dynamic_cast<>()`, `const_cast<>(),` dan `reinterpret_cast<>` secara eksplisit menunjukkan jenis konversi yang diinginkan.
    

### 5. Ringkasan Perbedaan Kunci

|C-Style Cast|`static_cast<T>`|
|---|---|
|Sintaks: `(T)expr`|Sintaks: `static_cast<T>(expr)`|
|Menggabungkan beberapa jenis cast (const, static, reinterpret) yang dicoba berurutan|Hanya melakukan konversi yang diizinkan oleh aturan `static_cast` saja|
|Bisa **menghilangkan `const`**/`volatile` dan melakukan bit‐level reinterpretasi tanpa jelas|Lebih ketat—tidak boleh dipakai untuk menghilangkan `const` atau bit‐level reinterpretasi yang tidak diizinkan|
|Sulit mengetahui jenis konversi apa yang sebenarnya terjadi|Jelas menunjukkan jenis konversi yang diinginkan pada kode|

---

## Kesimpulan

- **C-Style Cast** (`(Tipe) ekspresi`) adalah cara lama yang “serba bisa” untuk melakukan konversi tipe, tetapi kurang eksplisit dan berisiko melakukan konversi yang tidak terkontrol (misalnya reinterpret_cast atau menghilangkan const).
    
- **`static_cast<T>(ekspresi)`** lebih aman dan lebih eksplisit: compiler hanya melakukan konversi “yang masuk akal” (numerik, pointer dalam inheritance, enum→int, dan sejenisnya) serta menolak jika tidak cocok.
    
- **Rekomendasi Umum**:
    
    - Jika ingin melakukan konversi tipe secara jelas dan terbatas, gunakan `static_cast`.
        
    - Kalau perlu downcast dan butuh pemeriksaan runtime, gunakan `dynamic_cast`.
        
    - Kalau ingin melepaskan `const`/`volatile`, gunakan `const_cast`.
        
    - **Hindari** memakai C-style cast jika kamu menginginkan kode yang aman, mudah dibaca, dan mudah dipelihara.