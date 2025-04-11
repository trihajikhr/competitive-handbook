---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBNSE0001
judul_problem: Cari Angka di Array
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🔵 O(log n)
memory_complexity: 🟢 O(1)
status: 🏆 solved
date_solved: 2025-04-11T09:02:00
pendekatan: binary search
tags:
  - array
  - binary-search
  - search
---
Link problem: 

#array #binary-search #search 

---
# Cari Angka di Array
Time limit: -
Memory limit: -

Diberikan sebuah array, sebanyak `n`, dalam keadaan yang acak atau tergantung inputan. Tentukan index dari array yang memiliki nilai yang sama dengan `target`.

### Input
- Baris pertama berupa ukuran array dalam `n`;
- Baris kedua berupa isi dari array;
- Baris ketiga berupa nilai array yang dicari.
#### Input constraints
\-
### Output
- Jika nilai ditemukan, keluarkan nilai indexnya, jika tidak kembalikan `-1`;
### Examples
Input:
```
5
5 3 2 4 1
3
```

Output:
```bash
2
```

Penjelasan: Value `3` akan berada di index ke `2` setelah array diurutkan.
### Note

# Jawaban
Dengan masih menggunakan struktur data array biasa:

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int arr[], int target, int n){

    int low=0; int high=n-1;

    while(low <= high){
        int mid = low+(high-low)/2;

        if(target == arr[mid]){
            return mid;
        }

        if(target < arr[mid]){
            high=mid-1;
        }

        if(target>arr[mid]){
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int&x:arr) cin >> x;
    sort(arr, arr+n);
    int x; cin >> x;
    
    int rest=binarySearch(arr, x,n);
    cout << rest << "\n";

    return 0;
    
}
```

Time complexity: $O(log\;n)$
Memory complexity: $O(1)$
## Jawaban efektif
Jawaban versi singkat dan cepat ku:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline void fastio(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int binarySearch(vector<int>&arr, int target, int n){
    int low=0; 
    int high=n-1;

    while(low <= high){
        int mid=low+(high-low)/2;

        if(target==arr[mid]) return mid;
        (target<arr[mid])? high=mid-1:low=mid+1;
    }

    return -1;
}

int main(){
    fastio();
    int n; cin >> n;
    vector<int>arr(n);
    for(int&x:arr) cin >> x;
    sort(arr.begin(), arr.end());

    int x; cin >> x;
    int rest=binarySearch(arr,x,n);
    cout << rest << "\n";

    return 0;
}
```

Time complexity: $O(log\;n)$
Memory complexity: $O(1)$

# Editorial 

# Informasi tambahan
Jawaban lain dengan pembacaan ukuran array di dalam fungsi, bukan di main function:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

template <size_t N>
int binarySearch(int (&arr)[N], int target) {
    sort(arr, arr + N);
    int low = 0, high = N - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        (target < arr[mid]) ? high = mid - 1 : low = mid + 1;
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 1, 9};
    int x; cin >> x;

    int res = binarySearch(arr, x);
    cout << res << "\n";
    return 0;
}
```