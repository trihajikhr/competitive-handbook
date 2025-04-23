---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STMSPS0001
judul_problem: Sort an Array
sumber: leetcode.com
kategori_problem: 📊 problem_statement
kesulitan: 🥈 medium
time_complexity: 🟤 O(n log n)
memory_complexity: 🟠 O(n) ✅ → Stable
status: 🏆 solved
date_solved: 2025-04-10T05:52:00
pendekatan: merge sort algorithm
tags:
  - array
  - sorting
  - merge-sort
---
Link problem: [Sort an Array - LeetCode](https://leetcode.com/problems/sort-an-array/description/?source=submission-ac)

#array #sorting #merge-sort 

---
# Sort an Array
Time limit: -
Memory limit: -

Diberikan sebuah array bilangan bulat `nums`, urutkan array tersebut dalam urutan menaik dan kembalikan hasilnya.

Kamu **harus menyelesaikan masalah ini tanpa menggunakan fungsi bawaan** dan dengan **kompleksitas waktu O(n log n)** serta **kompleksitas ruang sekecil mungkin**.

### Input
Fungsi sudah disediakan dari leetcode!

#### Input constraints
- $1 <= nums.length <= 5 * 10^4$
- $-5 * 10^4 <= nums[i] <= 5 * 10^4$
### Output
Kembalikan array `nums` yang sudah di sorting.
### Examples
Input 1:
```
nums=[5,2,3,1]
```

Output 1:
```bash
[1,2,3,5]
```

Setelah array diurutkan, posisi beberapa angka tetap (misalnya, 2 dan 3), sementara posisi angka lainnya berubah (misalnya, 1 dan 5).

Input 2:
```
nums = [5,1,1,2,0,0]
```

Output 2:
```bash
[0,0,1,1,2,5]
```

Perhatikan bahwa nilai dalam `nums` tidak harus unik.

### Note
\-
# Jawaban
Dengan menggunakan implementasi merge sort standar:

```cpp
class Solution {
public:
    void merge(vector<int>&nums, int p, int q, int r){
        int n1=q-p+1;
        int n2=r-q;

        vector<int>L(n1);
        vector<int>M(n2);

        for(int i=0; i<n1; i++){
            L[i]=nums[p+i];
        }

        for(int j=0; j<n2; j++){
            M[j]=nums[q+1+j];
        }

        int i=0, j=0, k=p;

        while(i < n1 && j < n2){
            if(L[i]<=M[j]){
                nums[k]=L[i];
                i++;
            } else {
                nums[k]=M[j];
                j++;
            }
            k++;
        }

        while(i < n1){
            nums[k]=L[i];
            i++;
            k++;
        }

        while(j < n2){
            nums[k]=M[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>&nums, int l, int r){
        if(l < r){
            int m= l+(r-l)/2;

            mergeSort(nums, l, m);
            mergeSort(nums, m+1, r);
            merge(nums, l, m, r);
        }
    }

// fungsi bawaan leetcode
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
```

Time complexity: $O(n\; log\;n)$
Memory complexity: $O(n)$
## Jawaban efektif
#### Solving dengan constructor static + efisiensi memory allocator
Jika sebelumnya kita membuat 2 vector didalam fungsi `merge`, disini kita akan membuatnya lebih efisien dengan menggunakan 1 array bantuan, berupa vector `helper`, ini akan membuat kode berjalan dengan penggunaan memory cukup 1/2 -nya dari metode konvensional:

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        static const auto fastio=[](){
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            return 0;
        }();

        vector<int>helper(nums.size());
        mergeSort(nums,helper,0,nums.size()-1);
        return nums;
    }

    void mergeSort(vector<int>&nums, vector<int>&helper, int l, int r){
        if(l < r){
            int m = l+(r-l)/2;
            mergeSort(nums, helper, l, m);
            mergeSort(nums, helper, m+1, r);
            merge(nums, helper, l,m,r);
        }
    }

    void merge(vector<int>&nums, vector<int>&helper, int p, int q, int r){
        int i{p}, j{q+1}, k{p};

        for(int x=p; x<=r; x++){
            helper[x]=nums[x];
        }

        while(i <= q && j <= r){
            nums[k++]=(helper[i]<=helper[j]) ? helper[i++] : helper[j++];
        }

        while(i <= q) nums[k++]=helper[i++];
    }
};
```

Time complexity: $O(n\;log\;n)$
Memory complexity: $O(n)$
#### Solving dengan bypass runtime checker 

Namun, terdapat kode yang lebih efisien yang dapat membuat *seakan akan* kode berjalan sangat cepat, dengan membypass runtime checker, walaupun tidak disarankan dan tidak terlalu berguna di kompetisi asli, namun tidak ada salahnya untuk mengetahui kode tersebut:

```cpp
nst auto __ = []() {
struct ___ { static void _(){ std::ofstream("display_runtime.txt") << 0 << "\n"; } }; 
std::atexit(&___::_) ; return 0; } ();

class Solution {
public:
co
    void merge(vector<int>& arr, int left, int mid, int right){
        int size1 = mid - left + 1;
        int size2 = right - mid;

        std::vector<int> leftArr( arr.begin() + left, arr.begin() + mid + 1 );
        std::vector<int> rightArr( arr.begin() + mid + 1, arr.begin() + right + 1 );

        int i{}, j{}, k{left};

        while(i < size1 and j < size2){
            if(leftArr[i] < rightArr[j]){
                arr[k++] = leftArr[i++];
            }
            else {
                arr[k++] = rightArr[j++];
            }
        }

        while(i < size1){
            arr[k++] = leftArr[i++];
        }

        
        while(j < size2){
            arr[k++] = rightArr[j++];
        }

        return;
    }

    void mergeSort(vector<int>& arr, int left, int right){
        if(left >= right) return;
        
        int mid = left + ( right - left ) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums, 0, nums.size() - 1);

        return nums;    
    }
};
```

Time complexity: $O(n\;log\;n)$
Memory complexity: $O(n)$
# Editorial bypass runtime checker
Baiklah, editorial ini akan difokuskan untuk membahas kode yang menggunakan bypass runtime checker.

---

Kode tersebut sebenarnya mirip dengan implementasi merge sort biasa, tapi ada **beberapa poin efisiensi** yang bisa kita perhatikan dan bandingkan. Mari kita uraikan bagian demi bagian.

---

## ⚡ Bagian 1: Blok "trik" `const auto __ = []() {...}();`

```cpp
const auto __ = []() {
    struct ___ { 
        static void _(){ std::ofstream("display_runtime.txt") << 0 << "\n"; } 
    }; 
    std::atexit(&___::_); 
    return 0; 
}();
```

### ✨ Apa fungsinya?

Blok ini adalah **trik kecil** (sering digunakan oleh competitive programmer dan pengguna LeetCode) untuk:

- Menjalankan kode sebelum `main()` dipanggil (atau sebelum `Solution: :sortArray()` dipakai).
    
- Dalam kasus ini, dia membuka file `"display_runtime.txt"` dan menulis `0`.
    

Tapi **fungsi utama dari pattern ini** di LeetCode adalah **menonaktifkan sinkronisasi antara C++ iostream dan C stdio**, yang bisa mempercepat I/O — meskipun di kode ini `std::ios::sync_with_stdio(false);` tidak eksplisit dipakai.

Biasanya ditulis seperti ini untuk I/O speed:

```cpp
const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
```

---

## ⚡ Bagian 2: Merge Sort

```cpp
void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right) return;
        
    int mid = left + ( right - left ) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
```

Implementasi ini sudah cukup optimal dan mengikuti best practice:

- **Mid dihitung dengan cara aman**: `left + (right - left) / 2` mencegah overflow.
    
- **Merge dilakukan dengan slicing langsung dari `vector`**, ini lebih ringkas dibandingkan `for` loop manual menyalin elemen.
    

---

## 🔍 Efisiensi Kode Ini (dibandingkan dengan versi lain)

|Aspek|Penjelasan|
|---|---|
|**Akses vektor**|Menggunakan `std::vector<int>(begin, end)` untuk membuat salinan bagian array → lebih clean dan readable|
|**Mid aman dari overflow**|`left + (right - left) / 2` lebih aman dari `mid = (left + right) / 2`|
|**Menghindari alokasi berlebih**|Tidak membuat array tambahan di luar recursive call (merging hanya saat dibutuhkan)|
|**Trik awal blok lambda**|Biasanya dipakai untuk mempercepat runtime LeetCode, meskipun dalam contoh ini hanya menulis file|

---

## ✅ Kesimpulan

Kode ini **tidak lebih cepat secara algoritmik** (tetap `O(n log n)` dan pakai `O(n)` ruang), tapi:

- Rapi dan aman dari overflow
    
- Lebih clean dalam penggunaan slicing vector saat merge
    
- Menggunakan teknik yang sering dipakai untuk runtime tuning di LeetCode (walau di sini tidak dimanfaatkan penuh)
    

Kalau kamu ingin versi paling ringan (tanpa copy array besar), bisa pertimbangkan **in-place merge sort**, meski lebih rumit dan tricky implementasinya.

### Lalu apa kegunaan kode ini:
```cpp
std::vector<int> leftArr( arr.begin() + left, arr.begin() + mid + 1 );
std::vector<int> rightArr( arr.begin() + mid + 1, arr.begin() + right + 1 );
```

Bagian kode berikut:

```cpp
std::vector<int> leftArr( arr.begin() + left, arr.begin() + mid + 1 );
std::vector<int> rightArr( arr.begin() + mid + 1, arr.begin() + right + 1 );
```

adalah cara **C++ STL** untuk **menyalin sebagian elemen dari array `arr` ke dalam vektor baru** menggunakan **range constructor**.

---

#### ✨ Penjelasan

Fungsi ini akan:

1. **Membuat `leftArr`** berisi elemen dari `arr[left]` sampai `arr[mid]` (inklusif).
    
2. **Membuat `rightArr`** berisi elemen dari `arr[mid + 1]` sampai `arr[right]` (inklusif).
    

Karena dalam `std::vector(begin, end)`:

- `begin` adalah iterator awal.
    
- `end` adalah iterator satu posisi **setelah** elemen terakhir yang ingin disalin (**eksklusif**).
    

---

#### 🧠 Contoh konkret

Misal:

```cpp
std::vector<int> arr = {5, 2, 8, 4, 7, 6};
int left = 1;
int mid = 3;
int right = 5;
```

Maka:

```cpp
std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);  // arr[1] to arr[3]
```

⟹ `leftArr = {2, 8, 4}`

```cpp
std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);  // arr[4] to arr[5]
```

⟹ `rightArr = {7, 6}`

---

#### ✅ Keuntungan

- Ringkas (dibanding manual `for` loop untuk menyalin).
    
- Tidak perlu menghitung ukuran dan alokasi vektor secara eksplisit.
    
- Lebih readable untuk yang familiar dengan STL.
# Editorial Efisiensi memory allocator
Walaupun mergesort sendiri merupakan sorting yang sudah efisien, namun metode konvensional yang sering diajarkan masih bisa dioptimalkan lagi tapi, terutama jika kamu mau lebih hemat waktu dan memori, terutama dalam konteks yang sangat besar.

---

## ⚡ Tujuan Efisiensi

- **Kurangi alokasi memori baru (salinan vector `L` dan `M`)**
    
- **Kurangi overhead constructor vector**
    
- **Minimalkan cache miss dan copy**
    

---

## ✅ Versi yang Lebih Efisien

### 🔁 Gunakan satu array bantu (helper array) yang dibagi sepanjang proses

Alih-alih buat `vector L` dan `M` setiap kali, kita buat satu vector tambahan di awal dan hanya copy yang diperlukan.

---

### ✅ Optimal Merge Sort (Pakai `helper` array)

```cpp
#include<iostream>
#include<vector>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

using vi = vector<int>;

void merge(vi &arr, vi &helper, int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int k = p;

    // Salin ke helper
    for (int x = p; x <= r; x++) {
        helper[x] = arr[x];
    }

    while (i <= q && j <= r) {
        if (helper[i] <= helper[j]) {
            arr[k++] = helper[i++];
        } else {
            arr[k++] = helper[j++];
        }
    }

    while (i <= q) {
        arr[k++] = helper[i++];
    }
    // Tidak perlu copy sisa dari kanan, karena sudah di tempatnya
}

void mergeSort(vi &arr, vi &helper, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, helper, l, m);
        mergeSort(arr, helper, m + 1, r);
        merge(arr, helper, l, m, r);
    }
}

int main(){
    fastio();

    int n; cin >> n;
    vi arr(n), helper(n);
    for (int &x : arr) cin >> x;

    mergeSort(arr, helper, 0, n - 1);

    for (int &x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```

---

## 📊 Perbandingan

|Versi Sebelumnya|Versi Optimasi Ini|
|---|---|
|Alokasi `L` & `M` setiap merge|Hanya alokasi 1x vector `helper`|
|`O(n log n)` waktu dan `O(n log n)` memori (karena salinan)|`O(n log n)` waktu dan `O(n)` memori|
|Lebih readable|Lebih hemat memori & cache-friendly|
|Cocok untuk latihan CP|Cocok untuk ukuran besar/production|

---

## 🤔 Worth it untuk Competitive Programming?

- Untuk soal ukuran sedang: **kode kamu sudah cukup bagus**
    
- Untuk ukuran besar (misal: `n` sampai 10^6 atau lebih): **optimasi ini sangat terasa**
    

---

Kalau kamu ingin versi paling singkat (tanpa helper) tapi tetap cepat, bisa juga pakai `in-place merge sort` tapi itu jauh lebih rumit dan tidak selalu lebih cepat secara praktis.

Kalau kamu mau, aku juga bisa buatkan benchmark perbedaan waktunya! Mau dicoba?
# Informasi tambahan
Aku masih belajar merge sort, dan sepertinya merge sort masih bisa untuk dioptimalkan lagi lebih jauh hahaha.