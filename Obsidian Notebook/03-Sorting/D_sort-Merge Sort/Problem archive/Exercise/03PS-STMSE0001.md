---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STMSE0001
judul_problem: Implementasi dasar
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥈 medium
time_complexity: 🟤 O(n log n)
memory_complexity: 🟠 O(n)  ✅ → Stable
status: 🏆 solved
date_solved: 2025-04-09T19:13:00
pendekatan: merge sort algorithm
tags:
  - array
  - sorting
  - merge-sort
---
Link problem: 

#array #sorting #merge-sort 

---
# Implementasi dasar
Time limit: -
Memory limit: -

Buat fungsi `mergeSort(arr)` yang mengurutkan array dari kecil ke besar menggunakan **Merge Sort**.
### Input
- Baris pertama berupa $n$, yaitu ukuran array.
- Baris kedua adalah nilai atau value dari array
#### Input constraints
\-
### Output
Array yang sudah diurutkan dari kecil ke terbesar.
### Examples
Input:
```
Input:  [5, 2, 8, 4, 1, 9]
```

Output:
```bash
Output: [1, 2, 4, 5, 8, 9]
```

### Note
\-
# Jawaban
Implementasi merge sort sederhana:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int p, int q, int r) {
    int n1=q-p+1;
    int n2=r-q;

    vector<int>L(n1);
    vector<int>M(n2);

    for(int i=0; i<n1; i++){
        L[i]=arr[p+i];
    }

    for(int j=0; j<n2; j++){
        M[j]=arr[q+1+j];
    }

    int i=0,j=0,k=p;

    while(i < n1 && j < n2){
        if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
        } else{
            arr[k]=M[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k]=M[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>&arr, int l, int r) {
    if(l < r){
        int m= l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    mergeSort(arr, 0, n-1);
    for (int &x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}
```

Time complexity: $O(n \; log \; n)$
Memory complexity: $O(n)$
## Jawaban efektif
#### 1. Jawaban ketika aku sudah cukup mahir:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int p, int q, int r){
    int n1= q-p+1;
    int n2=r-q;

    vector<int>L(arr.begin()+p, arr.begin()+q+1);
    vector<int>M(arr.begin()+q+1, arr.begin()+r+1);

    int i{}, j{}, k{p};

    while(i < n1 && j < n2){
        if(L[i] <= M[j]){
            arr[k++]=L[i++];
        } else {
            arr[k++]=M[j++];
        }
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = M[j++];
}

void mergeSort(vector<int>&arr, int l, int r){
    if(l < r){
        int m= l+(r-l)/2;

        mergeSort(arr,l,m);
        mergeSort(arr, m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int>arr(n);
    for(int&x:arr)cin >> x;
    mergeSort(arr,0,n-1);
    for(int&x:arr)cout << x << " "; cout << "\n";

    return 0;
}
```

Time complexity: $O(n\;log\;n)$
Memory complexity: $O()$

---
##### Lalu apa kegunaan kode ini:
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

##### ✨ Penjelasan

Fungsi ini akan:

1. **Membuat `leftArr`** berisi elemen dari `arr[left]` sampai `arr[mid]` (inklusif).
    
2. **Membuat `rightArr`** berisi elemen dari `arr[mid + 1]` sampai `arr[right]` (inklusif).
    

Karena dalam `std::vector(begin, end)`:

- `begin` adalah iterator awal.
    
- `end` adalah iterator satu posisi **setelah** elemen terakhir yang ingin disalin (**eksklusif**).
    

#### 2. Berikut adalah jawaban setelah belajar lebih lama lagi, menjadi lebih singkat, dan efisien:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;

    vector<int>L(arr.begin()+p, arr.begin()+q+1);
    vector<int>M(arr.begin()+q+1, arr.begin()+r+1);

    int i{}, j{}, k{p};

    while(i < n1 && j < n2){
        arr[k++] = (L[i] <= M[j]) ? L[i++] : M[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = M[j++];
}

void mergeSort(vector<int>&arr, int l, int r){
    if(l < r){
        int m=l+(r-l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l,m,r);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int>arr (n);
    for(int&x:arr) cin >> x;
    mergeSort(arr,0,n-1);
    for(int&x:arr) cout << x << " "; cout << "\n";
    return 0;
}
```

#### 3. Ternyata ada versi yang lebih efisien!
Jika kita menggunakan membuat dua vector didalam funtion `merge()`, memory allocation nya menjadi $O(n\;log\;n)$, yang mana ini masih bisa dioptimalkan lagi, jika kita membuat hanya 2 vector di function `main`, dan bukan di function `merge`. 

Hal ini akan membuat memory allocationya menjadi lebih kecil, yaitu $O(n)$.

```cpp
#include<iostream>
#include<vector>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

using vi = vector<int>;

void merge(vi &arr, vi &helper, int p, int q, int r){
    int i=p;
    int j=q+1;
    int k=p;

    for(int x=p; x<=r; x++){
        helper[x]=arr[x];
    }

    while(i <= q && j <= r){
        if(helper[i]<=helper[j]){
            arr[k++]=helper[i++];
        } else {
            arr[k++]=helper[j++];
        }
    }

    while(i <= q){
        arr[k++]=helper[i++];
    }
}

void mergeSort(vi &arr, vi &helper, int l, int r){
    if(l < r){
        int m = l+(r-l)/2;

        mergeSort(arr, helper, l, m);
        mergeSort(arr, helper, m+1, r);
        merge(arr, helper, l,m,r);
    }
}

int main(){
    fastio();

    int n; cin >> n;
    vi arr(n), helper(n);
    for(int&x:arr) cin >> x;
    
    mergeSort(arr, helper, 0, n-1);
    for(int&x:arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```

Versi ini juga memiliki varian lain, seperti ini:

```cpp
#include<iostream>
#include<vector>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

using vi = vector<int>;

void merge(vi &arr, vi &helper, int p, int q, int r){
    int i{p}, j{q+1}, k{p};

    // Hanya salin bagian p hingga r
    copy(arr.begin() + p, arr.begin() + r + 1, helper.begin() + p);

    while(i <= q && j <= r){
        arr[k++]=(helper[i]<=helper[j]) ? helper[i++]:helper[j++];
    }

    while(i <= q) arr[k++] = helper[i++];
}

void mergeSort(vi &arr, vi &helper, int l, int r){
    if(l < r){
        int m = l+(r-l)/2;

        mergeSort(arr, helper, l, m);
        mergeSort(arr, helper, m+1, r);
        merge(arr, helper, l,m,r);
    }
}

int main(){
    fastio();

    int n; cin >> n;
    vi arr(n), helper(n);
    for(int&x:arr) cin >> x;
    mergeSort(arr,helper, 0, n-1);
    for(int&x:arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```
# Editorial 
Problem ini tidak berbeda dari implementasi merge sort pada umumnya. 

## 🧠 Konsep Utama Merge Sort

Merge Sort bekerja dengan prinsip **Divide and Conquer**:

1. **Divide** (Bagi): Pecah array menjadi dua bagian sampai ukurannya 1.
2. **Conquer** (Tundukkan): Gabungkan dua bagian kecil menjadi satu array yang terurut.

## 🔁 Step-by-step Merge Sort

Misal array awal:

```
[8, 4, 5, 2, 9, 1]
```

### 🔹 STEP 1: Divide (Pecah)

Pecah terus array jadi dua bagian hingga tersisa 1 elemen di setiap bagian:

```
[8, 4, 5, 2, 9, 1]
↓
[8, 4, 5]       [2, 9, 1]
↓
[8] [4, 5]      [2] [9, 1]
↓
[8] [4] [5]     [2] [9] [1]
```

### 🔹 STEP 2: Conquer (Gabung Sambil Urut)

Sekarang kita mulai **gabungkan sambil diurutkan** dari bawah:

#### ⮕ Gabungkan [4] dan [5]

→ Hasil: `[4, 5]`

#### ⮕ Gabungkan [8] dan [4, 5]

→ Bandingkan elemen satu per satu dan urutkan: → Hasil: `[4, 5, 8]`

#### ⮕ Gabungkan [9] dan [1]

→ Hasil: `[1, 9]`

#### ⮕ Gabungkan [2] dan [1, 9]

→ Hasil: `[1, 2, 9]`

### 🔹 STEP 3: Final Merge

Gabungkan dua bagian besar yang sudah terurut:

```
[4, 5, 8] dan [1, 2, 9]
↓
Gabungkan satu per satu:
→ Bandingkan 4 dan 1 → 1
→ Bandingkan 4 dan 2 → 2
→ Bandingkan 4 dan 9 → 4
→ Bandingkan 5 dan 9 → 5
→ Bandingkan 8 dan 9 → 8
→ Sisa: 9

→ Hasil akhir: [1, 2, 4, 5, 8, 9]
```


## 🧮 Ilustrasi Ringkas

```
[8, 4, 5, 2, 9, 1]
↓
[8, 4, 5]       [2, 9, 1]
↓
[4, 5, 8]       [1, 2, 9]
↓
[1, 2, 4, 5, 8, 9]
```

## ⏱️ Kompleksitas Waktu

- **Worst-case, Best-case, Average-case**: `O(n log n)`
- Karena selalu membagi dua dan menggabungkan kembali semua elemen.

## 📌 Catatan Tambahan

- Merge Sort cocok untuk **array besar** dan **data yang tidak bisa diurutkan in-place**.
- Kekurangannya: Butuh **O(n)** ekstra memori untuk array sementara.

# Informasi tambahan
Aku sudah belajar merge sort lagi, dan ini adalah versi merge sort tarbaru yang aku gunakan sekarang:

```cpp
#include<iostream>
#include<vector>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

using vi = vector<int>;

void merge(vi &arr, vi &helper, int p, int q, int r){
    int i{p}, j{q+1}, k{p};

    // Hanya salin bagian p hingga r
    copy(arr.begin() + p, arr.begin() + r + 1, helper.begin() + p);

    while(i <= q && j <= r){
        arr[k++]=(helper[i]<=helper[j]) ? helper[i++]:helper[j++];
    }

    while(i <= q) arr[k++] = helper[i++];
}

void mergeSort(vi &arr, vi &helper, int l, int r){
    if(l < r){
        int m = l+(r-l)/2;

        mergeSort(arr, helper, l, m);
        mergeSort(arr, helper, m+1, r);
        merge(arr, helper, l,m,r);
    }
}

int main(){
    fastio();

    int n; cin >> n;
    vi arr(n), helper(n);
    for(int&x:arr) cin >> x;
    mergeSort(arr,helper, 0, n-1);
    for(int&x:arr) cout << x << " ";
    cout << "\n";

    return 0;
}
```

