---
obsidianUIMode: preview
note_type: latihan
latihan: Hapus Duplikat Berurutan
sumber: Google.com, AI
tags:
  - data-structure
  - vector
date_learned: 2025-06-14T21:44:00
---
---
# Hapus Duplikat Berurutan

## Soal 2: Hapus Duplikat Berurutan

Buat program C++ yang:

1. Baca sebuah bilangan bulat `N` (1 ≤ N ≤ 1000), jumlah elemen.
    
2. Baca `N` bilangan bulat dan simpan ke `vector<int>`.
    
3. Hapus semua elemen yang muncul berurutan sama, sehingga hanya menyisakan satu contoh tiap run.
    
4. Cetak elemen hasil penghapusan, dipisahkan spasi.
    

### Contoh

```
Input:
8
1 1 2 2 2 3 3 2

Output:
1 2 3 2
```

**Petunjuk:**

- Buat `vector<int> result;`
    
- Traversal `arr` dan tiap kali `arr[i] != arr[i-1]`, lakukan `result.push_back(arr[i]);`.
    

Coba kerjakan, lalu kirim kode kamu untuk dicek. 😊

## Jawabanku

Berikut kode program untuk jawabanku:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;

    vector<int> rest;
    for(int i=0; i<n; i++){
        if(i==0) rest.push_back(arr[i]);
        else if(arr[i] != arr[i-1]) rest.push_back(arr[i]);
    }

    for(const auto & x :rest){
        cout << x << " ";
    } cout << "\n";
    return 0;
}
```

## Editorial
Kodenya sudah tepat—ia:

- Memasukkan elemen pertama tanpa syarat (`i == 0`),
    
- Lalu hanya menambahkan `arr[i]` ketika berbeda dari `arr[i-1]`.
    

Kompleksitasnya O(N) dan memenuhi contoh:

```plaintext
Input:
8
1 1 2 2 2 3 3 2

Output:
1 2 3 2
```

### Beberapa catatan kecil

1. **Cetakan spasi di akhir**  
    Meskipun umumnya diterima di banyak judge, jika benar-benar ingin menghindari spasi ekstra, kamu bisa:
    
    ```cpp
    for (size_t i = 0; i < rest.size(); ++i) {
        if (i) cout << ' ';
        cout << rest[i];
    }
    cout << '\n';
    ```
    
2. **STL alternative**  
    Kalau mau “one-liner” mutasi vector:
    
    ```cpp
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    ```
    
    atau untuk output langsung:
    
    ```cpp
    unique_copy(arr.begin(), arr.end(),
                ostream_iterator<int>(cout, " "));
    ```
    

Tapi implementasimu sudah sangat baik!

