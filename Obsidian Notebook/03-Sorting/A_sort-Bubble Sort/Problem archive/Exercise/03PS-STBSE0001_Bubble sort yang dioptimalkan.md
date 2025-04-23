---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBSE0001
judul_problem: Bubble sort yang dioptimalkan
sumber: programiz.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-03T01:42:00
pendekatan: bubble sort algorithm
tags:
  - sorting
  - array
  - bubble-sort
---
Link problem: [Bubble Sort (With Code in Python/C++/Java/C)](https://www.programiz.com/dsa/bubble-sort)

#sorting #array #bubble-sort 

---
# Bubble sort yang dioptimalkan
Time limit: -
Memory limit: -

Urutkan sebuah array `arr[]` yang diinputkan oleh user, dengan urutan dari elemen terkecil ke terbesar atau ascending, menggunakan algoritma bubble sort yang dioptimalkan.
### Input
Input berupa `n` untuk menentukanya banyaknya elemen array, dan  `arr[]` untuk mengisi elemen array.
### Output
Menampilkan elemen array yang sudah diurutkan.
### Examples
Input 1:
```
5
3 2 1 5 4
```

Output 1:
```bash
1 2 3 4 5
```

Input 2:
```
10
10 9 8 7 6 4 3 2 5 1
```

Output 2:
```bash
1 2 3 4 5 6 7 8 9 10
```

Baris pertama adalah ukuran array, artinya array berukuran $n$ elemen, dan baris kedua adalah elemen array yang dimasukan.
### Note
\-
# Jawaban

```cpp
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {1, 3, 8, 2, 9, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n - 1; i++){ // 
        bool swapped = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) break; 
    }

    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
```

Time complexity: $O(n)$
Memory complexity: $O(2)$
## Jawaban efektif
Kode diatas adalah jawaban pertama, jawaban setelah belajar memperdalam CP beberapa hari kemudian berubah menjadi seperti  ini:

```cpp
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(a) for(auto&x:a)
using vi = vector<int>;

void bs(vi & arr){
    int n= arr.size();

    rep(i,0,n-1){
        bool swapped = false;
        rep(j,0,n-i-1){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

int main(){
    fastio();
    int n; cin >>n;
    vi arr(n);

    fore(arr) cin >> x;
    bs(arr);
    fore(arr) cout << x << " ";

    return 0;
}
```

Versi sederhana, untuk belajar lagi:

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void BubbleSort(vector<int>&arr){
    int n = arr.size();
    
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0; j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto& x:arr) cin >> x;
    BubbleSort(arr);
    for(auto&x : arr) cout << x << " ";
    
    cout << "\n";
    
    return 0;
}
```

Time complexity: $O(n)$
Memory complexity: $O(n^2)$
# Editorial 

Loop luar berjalan hingga n-1, karena pada iterasi terakhir array sudah pasti terurut, sehingga iterasi tambahan tidak diperlukan.

Loop dalam hanya membandingkan elemen yang belum terurut, karena setelah setiap iterasi, elemen terbesar sudah berada di posisi yang benar. Oleh karena itu, batas loop dalam dikurangi sesuai dengan jumlah iterasi yang telah dilakukan.

Menambahkan flag `swapped` untuk mendeteksi apakah ada pertukaran dalam iterasi tertentu. Jika tidak ada pertukaran, berarti array sudah terurut, sehingga loop dapat dihentikan lebih awal untuk menghemat waktu eksekusi.

# Informasi tambahan