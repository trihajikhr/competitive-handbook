---
obsidianUIMode: preview
note_type: latihan
latihan: Cetak Ulang Terbalik
sumber: Google.com, AI
tags:
  - data-structure
  - vector
date_learned: 2025-06-14T21:44:00
---
---
# Cetak Ulang Terbalik
Berikut soal latihan pertama untuk memperkuat pemahamanmu tentang **`vector`** di C++:

---

## Soal 1: Cetak Ulang Terbalik

Tulislah program C++ yang melakukan hal berikut:

1. Baca sebuah bilangan bulat `N` (1 ≤ N ≤ 100), menyatakan banyaknya elemen.
    
2. Baca `N` bilangan bulat berikutnya, dan simpan ke dalam sebuah `vector<int>`.
    
3. Cetak kembali semua elemen dalam `vector` tersebut tetapi dalam urutan terbalik, dipisahkan oleh satu spasi.
    

### Contoh

```
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
```

**Petunjuk:**

- Gunakan `push_back` untuk memasukkan elemen.
    
- Kamu bisa membalik urutan dengan mengiterasi dari `vector.size() - 1` ke `0`.
    

Coba implementasikan sendiri. Setelah selesai dan yakin programmu berjalan, beri tahu aku kalau sudah siap untuk soal selanjutnya! 😊

## Jawabanku
Versi yang lebih efisien, tanpa menggunakan bantuan array tambahan:

```cpp
#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main() {
    cout << "Input: \n";
    int n; cin >> n;

    vector<int> arr(n);
    for(auto&x:arr) cin >> x;

    for(int i=0; i<n/2; i++){
        swap(arr[i], arr[n-i-1]);
    }

    cout << "\nOutput: \n";
    for(const auto& x:arr){
        cout << x << " ";
    }cout << "\n";

    return 0;
}
```

## Editorial
Kodenya sudah benar dan akan membalik urutan elemen dengan baik. Beberapa catatan kecil:

1. **Flag “Input:” dan “Output:”**  
    Untuk soal di kompetisi atau pengujian otomatis, biasanya kita tidak perlu mencetak string pembantu, cukup baca dan tulis data sesuai format yang diinginkan. Jika memang ingin dipakai interaktif di lokal, tidak apa-apa.
    
2. **Header `<utility>`**  
    Kamu sudah include `<utility>` tapi sebenarnya `swap` sudah tersedia di `<algorithm>` atau bahkan `<utility>` dipull-in oleh `<vector>`/`<iostream>`. Tidak salah, tapi bisa dihapus jika ingin minimal.
    
3. **Iterasi pembalikan**  
    Loop dari `i = 0` sampai `i < n/2` sudah sempurna. ✅
    
4. **Alternatif tanpa manual swap**  
    C++ STL punya fungsi siap pakai:
    
    ```cpp
    reverse(arr.begin(), arr.end());
    ```
    
    Tapi menulis manual seperti kamu justru melatih pemahaman.
    

Overall, code-mu clean dan efisien untuk N ≤ 100.
