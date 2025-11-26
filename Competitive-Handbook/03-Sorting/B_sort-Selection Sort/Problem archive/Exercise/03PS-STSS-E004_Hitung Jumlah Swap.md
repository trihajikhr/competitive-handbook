---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STSS-E004
judul_problem: Hitung jumlah swap
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ❌ → Unstable
status: 🏆 solved
date_solved: 2025-03-06T16:18:00
pendekatan: selection sort algorithm
tags:
  - array
  - sorting
  - selection-sort
---
Link problem: 

#array #sorting #selection-sort 

---
# Hitung Jumlah Swap dalam Selection Sort
Time limit: -
Memory limit: -

Diberikan sebuah array **n** bilangan bulat. Gunakan **Selection Sort** untuk mengurutkan array dalam **ascending order**, lalu hitung berapa kali terjadi **swap** selama proses sorting.

### Input
- **n** (jumlah elemen dalam array).
- **n** bilangan bulat dalam satu baris.
#### Input constraints
\-
### Output
- Array yang terurut secara ascending.
- **Jumlah swap** yang terjadi selama Selection Sort.
### Examples
Input 1:
```
5  
3 1 4 1 5  
```

Output 1:
```bash
1 1 3 4 5
3
```

Input 2:
```
5
5 4 3 2 1
```

Output 2:
```bash
1 2 3 4 5 
2
```

### Note
\-
# Jawaban
Jawaban sederhana:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int selectionSort(vector<int> & arr){
    int n= arr.size();
    int count=0;

    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]< arr[min]) min = j;
        }
        if(min != i){
            swap(arr[min], arr[i]);
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr (n);
    for(int & x: arr) cin >> x;

    int rest=selectionSort(arr);
    for(int & x : arr) cout << x << " ";
    cout << "\n" << rest << "\n";

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
Mode kompetitve guys:

```cpp
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(a) for(auto&x:a)
using vi = vector<int>;

int selectionSort(vi & arr, int n){
    int count=0;
    rep(i,0,n-1){
        int min=i;
        rep(j,i+1,n){
            if(arr[j]<arr[min]) min = j;
        }
        if(i != min){
            swap(arr[min], arr[i]);
            count++;
        }
    }
    return count;
}

int main(){
    fastio();
    int n; cin >> n;
    vi arr (n);
    fore(arr) cin >> x;

    int rest=selectionSort(arr,n);
    fore(arr) cout << x << " ";
    cout << "\n" << rest << "\n";

    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
# Editorial 
Setiap perulangan yang mengharuskan dilakukanya `swap`, hanya akan terjadi ketika `i != min`, jadi, kita buat kondisional dimana `count` hanya akan bertambah ketika mendapatkan kondisi tersebut. Syntax ini ada dibaris ke-15.
# Informasi tambahan