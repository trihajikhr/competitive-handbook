---
obsidianUIMode: preview
note_type: latihan
latihan: Rotasi Kanan
sumber: Google.com, AI
tags:
  - data-structure
  - vector
date_learned: 2025-06-14T21:44:00
---
---
# Rotasi Kanan

## Soal 3: Rotasi Kanan

Buat program C++ yang:

1. Baca `N` (1 ≤ N ≤ 1 000 000) dan `K` (0 ≤ K < N).
    
2. Baca `N` bilangan bulat dan simpan di `vector<int> arr`.
    
3. Lakukan **rotasi ke kanan** sebanyak `K` langkah: tiap langkah terakhir menjadi elemen pertama, sisanya bergeser ke kanan satu.
    
4. Cetak hasil rotasi, elemen dipisah spasi.
    

### Contoh

```
Input:
5 2
1 2 3 4 5

Output:
4 5 1 2 3
```

**Petunjuk:**

- Rotasi brute-force O(N·K) akan TLE jika N besar.
    
- Gunakan `K %= N` untuk kembalikan ke range.
    
- Dua strategi efisien O(N):
    
    1. Buat vector baru `res` lalu:
        
        ```cpp
        for (int i = 0; i < N; i++)
            res[(i + K) % N] = arr[i];
        ```
        
    2. In-place dengan tiga kali `reverse`:
        
        ```cpp
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+K);
        reverse(arr.begin()+K, arr.end());
        ```
        

Coba implementasikan, lalu kirim kodenya agar aku cek! 😊

## Jawabanku
Berikut adalah jawabanku yang menggunakan array tambahan:

```cpp
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int>arr(n);
    for(auto&x:arr) cin >> x;

    vector<int> rest(n);
    for(int i=0; i<n; i++){
        rest[(i+k) % n] = arr[i];
    }

    for(const auto& x: rest) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
```

## Editorial

Kodenya sudah tepat—`rest[(i + k) % n] = arr[i];` akan memetakan elemen ke posisi rotasi yang benar dalam O(N). Beberapa catatan kecil:

1. **Reduksi `k` ke dalam batas 0…N–1**  
    Meskipun soal menjamin 0 ≤ K < N, biasanya kita tambahkan baris
    
    ```cpp
    k %= n;
    ```
    
    supaya jika diubah nanti menjadi bebas range, tetap aman.
    
2. **Kasus `k == 0`**  
    Saat `k == 0`, rotasi sebetulnya tidak perlu—kamu bisa langsung cetak `arr`. Tapi loop-mu tetap meng-handle-nya dengan benar, jadi ini cuma optimasi mikro.
    
3. **Pendekatan in-place**  
    Kalau ingin tanpa buffer tambahan (menghemat memori), bisa pakai trik tiga kali `reverse`:
    
    ```cpp
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    ```
    
    Tapi solusi dengan buffer (`rest`) sudah sempurna untuk latihan ini.
    

