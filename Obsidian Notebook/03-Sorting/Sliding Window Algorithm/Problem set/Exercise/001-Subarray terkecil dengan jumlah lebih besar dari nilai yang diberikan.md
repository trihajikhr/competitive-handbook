---
obsidianUIMode: preview
note_type: problem statement
id_problem: 03PS-STSWE0001
judul_problem: "\rSubarray terkecil dengan jumlah lebih besar dari nilai yang diberikan"
sumber: geeksforgeeks.org
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟠 O(n)
memory_complexity: 🟢 O(1)
status: 🏆 solved
date_solved: 2025-03-02T17:22:00
pendekatan: algoritma sliding window
tags:
  - array
  - sliding-window
  - two-pointer
---
Link problem: [Smallest subarray with sum greater than a given value - GeeksforGeeks](https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/)

#array #sliding-window #two-pointer 

---
# Subarray terkecil dengan jumlah lebih besar dari nilai yang diberikan
Time limit: -
Memory limit: -

Diberikan sebuah array $arr[\,]$ berisi bilangan bulat dan int $x$. Tugasnya adalah menemukan subarray terkecil dengan jumlah yang lebih besar dari $x$. 
### Input
\-
### Output
\-
### Examples

```bash
Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: Minimum length subarray is [4, 45, 6]
```


```bash
Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray exist
```
### Note
\-
# Jawaban

```cpp
#include <bits/stdc++.h>
using namespace std;

int smallestSubWithSum(int x, vector<int>& arr) {

    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;
    
    while (j < arr.size()) {
        
        while (j < arr.size() && sum <= x) {
            sum += arr[j++];
        }
        
        if (j == arr.size() && sum <= x) break;
        
        while (i < j && sum - arr[i] > x) {
            sum -= arr[i++];
        }
        
        ans = min(ans, j-i);
        
        sum -= arr[i];
        i++;
    }
    
    if (ans == INT_MAX) return 0;
    return ans;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int & x : arr) cin >> x;
    int x; cin >> x;

    cout<<smallestSubWithSum(x, arr) << "\n";

    return 0;
}

```
## Jawaban efektif
\-
# Editorial 

Kita akan menggunakan **Sliding Window Technique** untuk menyelesaikan masalah ini dengan efisien.

## Ide Utama

1. Gunakan dua pointer, **i** (awal jendela) dan **j** (akhir jendela), untuk merepresentasikan jendela subarray.
2. Gunakan **j** untuk memperluas jendela sampai jumlah elemen subarray lebih besar dari **x**.
3. Setelah kondisi tersebut terpenuhi, geser **i** ke kanan untuk mencoba mengecilkan subarray dan tetap memenuhi syarat.
4. Simpan panjang minimum subarray yang ditemukan.
5. Jika tidak ada subarray yang memenuhi syarat, kembalikan **0**.

---

## Implementasi Kode

```cpp
#include <bits/stdc++.h>
using namespace std;

int smallestSubWithSum(int x, vector<int>& arr) {
    int i = 0, j = 0;
    int sum = 0;
    int ans = INT_MAX;
    
    while (j < arr.size()) {
        // Memperbesar jendela hingga jumlah lebih besar dari x
        while (j < arr.size() && sum <= x) {
            sum += arr[j++];
        }
        
        // Jika seluruh elemen sudah ditambahkan dan masih kurang dari x, keluar
        if (j == arr.size() && sum <= x) break;
        
        // Memperkecil jendela dari kiri sambil tetap menjaga jumlah > x
        while (i < j && sum - arr[i] > x) {
            sum -= arr[i++];
        }
        
        // Perbarui panjang minimum subarray
        ans = min(ans, j - i);
        
        // Geser i ke kanan dan kurangi elemen pertama dari subarray
        sum -= arr[i];
        i++;
    }
    
    return (ans == INT_MAX) ? 0 : ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    int x;
    cin >> x;

    cout << smallestSubWithSum(x, arr) << "\n";
    return 0;
}
```

---

## Analisis Kompleksitas

- **Kompleksitas Waktu**: O(n)
    - Pointer **j** hanya bergerak maju sekali, begitu juga **i**, sehingga setiap elemen hanya diproses paling banyak dua kali.
- **Kompleksitas Ruang**: O(1)
    - Hanya menggunakan variabel tambahan tetap.

---

## Contoh Kasus

### Input 1:

```
6
1 4 45 6 0 19
51
```

### Output 1:

```
3
```

**Penjelasan:** Subarray terkecil yang memiliki jumlah lebih besar dari 51 adalah `[4, 45, 6]` dengan panjang **3**.

### Input 2:

```
3
1 2 3
7
```

### Output 2:

```
0
```

**Penjelasan:** Tidak ada subarray yang memiliki jumlah lebih besar dari **7**, sehingga hasilnya **0**.

---

## Kesimpulan

- **Sliding Window** memungkinkan kita menemukan solusi secara **efisien** dibandingkan brute force O(n²).
- Pendekatan ini berguna untuk masalah yang memerlukan **subarray dengan batasan jumlah tertentu**.

# Informasi tambahan

`INT_MAX` adalah konstanta yang merepresentasikan nilai maksimum yang dapat disimpan dalam tipe data `int`. Dalam C++, `INT_MAX` didefinisikan di dalam header `<limits.h>` atau `<climits>` dan biasanya bernilai **2,147,483,647** (2³¹ - 1) pada sistem 32-bit.

### Mengapa Menggunakan `INT_MAX` di Kode?

Dalam kode yang kamu berikan, `INT_MAX` digunakan sebagai nilai awal untuk variabel `ans` karena kita ingin mencari **panjang minimum** dari subarray.

#### Alasan penggunaan `INT_MAX`:

1. **Sebagai nilai awal yang besar** → Agar nilai pertama yang ditemukan lebih kecil dari `INT_MAX`, sehingga bisa diperbarui.
2. **Menentukan apakah solusi ditemukan** → Jika setelah pencarian tetap `INT_MAX`, berarti tidak ada subarray yang memenuhi syarat, sehingga kita bisa mengembalikan `0`.

### Ilustrasi Singkat

Misalkan kita mencari nilai minimum dalam array `[5, 3, 9, 2]`. Jika kita mulai dengan `ans = INT_MAX`, prosesnya seperti ini:

1. `ans = INT_MAX = 2147483647`
2. Periksa angka pertama `5` → `ans = min(2147483647, 5) = 5`
3. Periksa angka kedua `3` → `ans = min(5, 3) = 3`
4. Periksa angka ketiga `9` → `ans = min(3, 9) = 3`
5. Periksa angka keempat `2` → `ans = min(3, 2) = 2`

Jadi, `ans` akan mendapatkan nilai minimum **dengan pasti**.

🚀 **Kesimpulan:** `INT_MAX` digunakan untuk menginisialisasi nilai maksimum agar bisa diperbarui ke nilai yang lebih kecil selama pencarian solusi.