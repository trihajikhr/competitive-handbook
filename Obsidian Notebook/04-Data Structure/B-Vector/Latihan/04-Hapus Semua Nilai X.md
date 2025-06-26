---
obsidianUIMode: preview
note_type: latihan
latihan: Hapus Semua Nilai X
sumber: Google.com, AI
tags:
  - data-structure
  - vector
date_learned: 2025-06-14T21:44:00
---
---
# Hapus Semua Nilai X

## Soal 4: Hapus Semua Nilai X

Buat program C++ yang:

1. Baca dua bilangan bulat `N` (1 ≤ N ≤ 1 000 000) dan `X`.
    
2. Baca `N` bilangan bulat, simpan ke dalam `vector<int> arr`.
    
3. Hapus semua elemen bernilai `X` dari `arr`, **tanpa menggunakan method STL `erase` secara langsung dalam loop** (gunakan algoritma linear).
    
4. Cetak ukuran `vector` hasil, lalu semua elemennya dipisah spasi.
    

### Contoh

```
Input:
7 3
1 3 2 3 4 3 5

Output:
4
1 2 4 5
```

**Petunjuk:**

- Gunakan dua indeks: satu untuk baca (`i`), satu untuk tulis ke posisi baru (`j`).
    
- Jika `arr[i] != X`, tulis `arr[j++] = arr[i]`.
    
- Setelah loop, `arr.resize(j)` untuk menyesuaikan ukuran.
    
- Ini juga ilustrasi “remove-erase idiom” secara manual.
    

Coba implementasikan, lalu kirim kode kamu untuk dicek! 😊

## Jawabanku

Kode jawabanku untuk menyelesaikan kasus ini:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for(auto&x:arr) cin >> x;

    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i] != x) arr[idx++] = arr[i];
    }

    arr.resize(idx);
    cout << idx << "\n";
    for(const auto&x: arr){
        cout << x << " ";
    } 
    return 0;
}
```

## Editorial
Kode-mu untuk Soal 4 sudah bekerja dengan benar—ia:

- Membaca `n` dan `x` lalu mengisi `vector arr`.
    
- Menggunakan dua pointer (`i` baca dan `idx` tulis) untuk menyalin elemen bukan `x` ke depan.
    
- Memanggil `arr.resize(idx)` untuk memotong sisanya.
    

Hasilnya sesuai spesifikasi: mencetak jumlah elemen baru (`idx`) dan kemudian daftar elemen tanpa nilai `x`.

### Catatan kecil

1. **Penamaan variabel loop**  
    Kamu menamai loop input dengan `auto& x`, yang ber-shadowing variabel `x` untuk nilai hapus. Meskipun di kompilasi C++ ini diizinkan (skop berbeda), akan lebih jelas jika menggunakan nama lain, misalnya:
    
    ```cpp
    for (auto &val : arr) cin >> val;
    ```
    
2. **Akhiran newline**  
    Tambahkan `\n` setelah mencetak deretan elemen untuk konsistensi format output:
    
    ```cpp
    for (const auto &val : arr) {
        cout << val << " ";
    }
    cout << "\n";
    ```
    

