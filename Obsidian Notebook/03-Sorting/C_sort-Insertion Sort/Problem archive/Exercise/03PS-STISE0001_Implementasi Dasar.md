---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STISE0001
judul_problem: Implementasi dasar
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-06T20:47:00
pendekatan: insertion sort algorithm
tags:
  - array
  - sorting
  - insertion-sort
---
Link problem: 

#array #sorting #insertion-sort 

---
# Judul
Time limit: -
Memory limit: -

Buatlah program **Insertion Sort** untuk mengurutkan array dalam **urutan naik**.
### Input
- **Baris pertama** berisi satu bilangan bulat **N** (jumlah elemen dalam array).
- **Baris kedua** berisi **N** bilangan bulat yang perlu diurutkan.
#### Input constraints
\-
### Output
\-
### Examples
Input:
```
5  
9 5 1 4 3  
```

Output:
```bash
1 3 4 5 9
```

### Note
\-
# Jawaban
Kode yang masih belum terlalu banyak dimodifikasi:

```cpp
#include<iostream>
using namespace std;

void printArray(int array[], int size){
    for(int i=0;i<size;i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int array[], int size){
    for(int step=1; step<size; step++){
        int key = array[step];
        int j=step - 1;

        while(j>=0 && key < array[j]){
            array[j+1] =array[j];
            --j;
        }
        array[j+1] = key;
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int & x: arr) cin >> x;
    insertionSort(arr,n);

    printArray(arr,n);

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
Kode jawaban yang lebih disesuaikan, seperti menggunakan vector, dan perulangan yang ringkas:

```cpp
#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int> & arr, int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j=i-1;

        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1]=key;
    }
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int & x: arr) cin >> x;
    insertionSort(arr,n);
    for(int &x:arr)cout << x << " ";

    cout << "\n";
    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
# Editorial 
Latihan problem ini masih tergolong mudah, dan tidak terlalu jauh dengan materi dasar dari insertion sort. Jadi, rujuk kembali materi jika ingin melihat materi tentang metode sorting ini.
# Informasi tambahan