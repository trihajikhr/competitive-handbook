---
obsidianUIMode: preview
note_type: tips trick
tips_trick: size_t
sumber: Google.com, AI
tags:
  - tipe-data
  - int
---
---
# Apa maksud dari size_t? Dan apa bedanya dengan Int?
`size_t` adalah tipe data integer tanpa tanda (unsigned integer) yang secara khusus dipakai untuk merepresentasikan ukuran (size) atau jumlah elemen dalam suatu kontainer di C++. Beberapa poin pentingnya:

1. **Tujuan Utama**
    
    - `size_t` dirancang untuk cukup besar (lebar bit yang sesuai) agar bisa menampung ukuran maksimum objek atau koleksi pada platform tertentu. Misalnya, saat kamu memanggil `vec.size()`, hasilnya bertipe `size_t`—karena bisa jadi vektor tersebut sangat besar, lebih besar daripada batas maksimum `int`.
        
2. **Unsigned (Tanpa Tanda)**
    
    - Karena `size_t` bersifat unsigned, nilainya tidak pernah negatif. Ini cocok untuk ukuran (jumlah elemen) yang logikanya tidak pernah kurang dari nol. Jika kamu pakai `int`, ada kemungkinan nilai negatif—padahal ukuran atau indeks tidak seharusnya negatif.
        
    - Dengan `size_t`, compiler juga sering bisa melakukan optimasi dan meminimalkan risiko overflow pada konteks pengindeksan.
        
3. **Menghindari Peringatan dan Mismatch Tipe**
    
    - Jika kamu menulis loop seperti:
        
        ```cpp
        for (int i = 0; i < vec.size(); i++) { ... }
        ```
        
        Maka compiler akan memperingatkan “comparison between signed and unsigned integer” karena `i` bertipe `int` (signed), sementara `vec.size()` mengembalikan `size_t` (unsigned).
        
    - Menggunakan `size_t i = 0; i < vec.size(); i++` mencegah peringatan tersebut dan memastikan konsistensi tipe pada perbandingan.
        
4. **Portabilitas & Skalabilitas**
    
    - Di mesin 64-bit, `size_t` biasanya 64-bit (memungkinkan representasi hingga $2^{64}-1$), sedangkan `int` seringkali hanya 32-bit (hingga $2^{31}−1$). Kalau kamu mengolah kontainer yang sangat besar—misalnya beberapa juta atau miliaran elemen—maka `int` mungkin tidak cukup besar dan akan overflow. `size_t` di sisi lain didesain agar sesuai dengan batas maksimum memori mesin.
        

Singkatnya, `size_t` adalah tipe yang tepat untuk mengiterasi atau memeriksa ukuran kontainer karena:

- Nilainya selalu ≥ 0 (sesuai dengan konsep “ukuran”).
    
- Lebih aman dan bebas peringatan pada perbandingan dengan fungsi-fungsi seperti `.size()`.
    
- Lebih fleksibel untuk ukuran sangat besar, terutama di arsitektur modern.
    

Kamu tetap bisa pakai `int` kalau yakin kontainermu kecil, tetapi kebiasaan pakai `size_t` lebih dianjurkan agar kode lebih portabel, jelas maksudnya, dan terhindar dari peringatan tentang signed/unsigned mismatch.

## Jadi, size_t itu int atau long long? Kok bisa sampai $2^{64}-1$?
`size_t` sebenarnya bukan `int` ataupun `long long` secara langsung, melainkan sebuah alias (typedef) untuk tipe unsigned integer yang dipilih oleh implementasi C++ agar bisa menampung ukuran terbesar yang mungkin dibutuhkan oleh platform tersebut (biasanya selaras dengan “width” alamat memori/pointer).

- **Pada sistem Linux/macOS 64-bit (model LP64)**, `size_t` biasanya didefinisikan sebagai `unsigned long`. Karena di model LP64, `long` sudah 64-bit, maka `unsigned long` memiliki rentang $0$ hingga $2^{64}-1$.
    
- **Pada Windows 64-bit (model LLP64)**, `long` hanya 32-bit, jadi untuk menyesuaikan lebar pointer, `size_t` biasanya didefinisikan sebagai `unsigned long long` yang 64-bit juga. Dengan begitu tetap punya rentang $0$ hingga $2^{64}-1$.
    

Intinya, `size_t` adalah “ukuran lebar penuh” untuk menghitung jumlah byte/elemen pada memori di mesin itu—makanya pada 64-bit ia dapat mencapai $2^{64}-1$. Pada mesin 32-bit, `size_t` biasanya 32-bit (alias `unsigned int` atau `unsigned long` tergantung implementasi), sehingga rentangnya $0$ hingga $2^{32}-1$.

## Apa perbedaan ukuran ketika menggunakan size_t dengan tidak?
Perbedaan utama antara menggunakan `size_t` dan tipe integer “biasa” (misalnya `int`) terletak pada **lebar (ukuran bit), rentang nilai**, dan **signedness** (apakah bisa negatif atau tidak). Berikut poin-poin pentingnya:

1. **Lebar (Size) di Memori**
    
    - Pada **arsitektur 64-bit** modern (Linux/macOS model LP64, Windows model LLP64),
        
        - `size_t` biasanya **8 byte** (64-bit), sehingga mampu menyimpan nilai dari $0$ hingga $2^{64}-1$.
            
        - `int` biasanya **4 byte** (32-bit), dengan rentang $-2^{31}$ sampai $2^{31}-1$.
            
    - Pada **arsitektur 32-bit**,
        
        - `size_t` umumnya **4 byte** (32-bit), rentangnya $0$ sampai $2^{32}-1$.
            
        - `int` juga biasanya **4 byte** (32-bit), rentangnya $-2^{31}$ sampai $2^{31}-1$.
            
2. **Rentang Nilai (Range)**
    
    - Karena `size_t` adalah unsigned, pada 64-bit ia mampu merepresentasikan nilai hingga sekitar 18 kuadriliun (lebih tepatnya $2^{64}-1 ≈ 18,4$ miliar miliar). Artinya kamu bisa indexing atau menghitung ukuran container yang sangat besar tanpa khawatir overflow.
        
    - Sementara `int` hanya bisa sampai sekitar $±2,1$ miliar. Kalau jumlah elemen lebih besar dari $2^{31}-1$, maka `int` akan overflow (nilai melingkar ke negatif) sedangkan `size_t` masih aman—selama tidak melebihi $2^{64}-1$ (di 64-bit).
        
3. **Signed vs. Unsigned**
    
    - `size_t` **tidak pernah negatif**; tipe ini memang dirancang khusus untuk menampung “ukuran” (size) atau “jumlah item” sehingga logikanya tidak perlu nilai negatif.
        
    - `int` bersifat signed, bisa bernilai negatif maupun positif. Kadang ini memicu peringatan compiler (signed/unsigned comparison) saat dipakai bersamaan dengan `vec.size()` atau fungsi yang mengembalikan `size_t`.
        
4. **Praktisnya di Kode**
    
    - Kalau kamu menulis:
        
        ```cpp
        for (int i = 0; i < vec.size(); i++) { … }
        ```
        
        Maka compiler akan memberi peringatan bahwa kamu membandingkan `int` (signed) dengan `vec.size()` yang mengembalikan `size_t` (unsigned).
        
    - Jika kamu ganti menjadi:
        
        ```cpp
        for (size_t i = 0; i < vec.size(); i++) { … }
        ```
        
        maka perbandingannya konsisten (keduanya unsigned), dan juga memanfaatkan lebar penuh dari tipe yang sesuai arsitektur.
        
5. **Ringkasan “Perbedaan Ukuran”**
    
    - **Di mesin 64-bit**:
        
        - `size_t` = 8 byte $(0 \dots 2^{64}-1)$
            
        - `int` = 4 byte $(−2^{31} \dots 2^{31}-1)$
            
    - **Di mesin 32-bit**:
        
        - `size_t` = 4 byte $(0 \dots 2^{32}-1)$
            
        - `int` = 4 byte $(-2^{31} \dots 2^{31}-1)$
            

Karena itu, semakin besar ukuran container atau array yang mungkin kamu hadapi—terutama di aplikasi 64-bit—`size_t` jauh lebih aman untuk menghitung jumlah elemen atau mengindeks. Sementara `int` masih bisa dipakai untuk data yang pasti kecil (misalnya jumlah elemen maksimum di bawah 2 miliar), tapi rentang dan ketidakcocokan signed/unsignednya dapat menimbulkan bug jika tidak diperhatikan.