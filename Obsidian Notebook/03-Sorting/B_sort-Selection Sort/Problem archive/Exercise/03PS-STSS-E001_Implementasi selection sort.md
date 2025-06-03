---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STSS-E001
judul_problem: Implementasi selection sort
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ❌ → Unstable
status: 🏆 solved
date_solved: 2025-03-06T14:23:00
pendekatan: selection sort algorithm
tags:
  - array
  - sorting
  - selection-sort
---
Link problem: 

#sorting  #array  #selection-sort 

---
# Implementasi Dasar Selection Sort
Time limit: -
Memory limit: -

Buatlah sebuah program C++ yang mengimplementasikan Selection Sort untuk mengurutkan array dalam urutan menurun (descending order).

### Input
Sebuah array dengan **n** elemen bilangan bulat.
#### Input constraints
\-
### Output
Array yang sudah diurutkan dalam **urutan menurun**.
### Examples
Input:
```
5
5 7 4 2 9
```

Output:
```bash
9 7 5 4 2
```

### Note
\-
# Jawaban
Jika dilihat dengan seksama, selection sort cukup sederhana, sehingga bisa diperpendek cukup dengan syntax seperti ini:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int> & arr){
    int n=arr.size();

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j] > arr[min]) min=j;
        }
        swap(arr[min], arr[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);

    for(auto&x:arr) cin >> x;
    selectionSort(arr);
    for(auto&x:arr) cout << x << " ";

    cout << "\n";
    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 
Perhatikan baris ke-12. Kita menggunakan tanda lebih dari `>` untuk membuat angka yang terurut dari besar ke kecil atau descending order. 

Jika melihat ke tutorial selection sort, maka kode latihan yang panjang di tutorial sebenarnya bisa diringkas agar lebih pendek, sehingga cukup ditulis seperti ini.
# Informasi tambahan