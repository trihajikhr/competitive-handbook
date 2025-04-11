---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBSPS0003
judul_problem: Easy Going (Very Easy)
sumber: hackerearth.com
kategori_problem: 📊 problem_statement
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: ⏳ progress 🏆 solved
date_solved: 
pendekatan: bubble sort algorithm
tags:
  - array
  - bubble-sort
  - sorting
---
Link problem: [Easy Going.(Very Easy) \| Practice Problems](https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/min-max-difference/)

#array #bubble-sort #sorting 

---
# Judul
Time limit: 1 s
Memory limit: 256 megabyte

Hai para _coders_! Berikut adalah tugas sederhana untuk kalian. Diberikan sebuah array berukuran **N** dan sebuah bilangan bulat **M**, tugas kalian adalah menghitung selisih antara jumlah maksimum dan jumlah minimum dari **N - M** elemen dalam array yang diberikan.

### Input
- Baris pertama berisi sebuah bilangan bulat **T** yang menyatakan jumlah kasus uji.
- Setiap kasus uji terdiri dari dua bilangan bulat **N** dan **M** pada baris pertama.
- Baris berikutnya berisi **N** bilangan bulat yang dipisahkan oleh spasi, menunjukkan elemen-elemen dalam array.
#### Input constraints
- $1≤t≤10$ _(jumlah kasus uji)_
- $1≤n≤1000$  _(jumlah elemen dalam array)_
- $1≤a[i]≤1000$ _(nilai elemen dalam array)_
### Output
Untuk setiap kasus uji, cetak hasil perhitungan dalam baris baru.
### Examples
Input:
```
1
5 1
1 2 3 4 5
```

Output:
```bash
4
```

- **M** adalah **1**, dan **N** adalah **5**, sehingga kita harus menghitung jumlah maksimum dan jumlah minimum dengan menggunakan **4 elemen** dari array.
  <br/>
- **Jumlah maksimum** menggunakan **4 elemen terbesar**:  
    $2+3+4+5=14$
    <br/>
- **Jumlah minimum** menggunakan **4 elemen terkecil**:  
    $1+2+3+4=10$
    <br/>
- **Selisihnya**:  
    $14−10=4$
### Note
\-
# Jawaban
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
## Jawaban efektif
// penjelasan singkat

```cpp

```

Time complexity: $O()$
Memory complexity: $O()$
# Editorial 
Sebelumnya aku membuat kode jawaban yang salah seperti ini:

```cpp
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int>&arr){  // >> kesalahan 1
    int n = arr.size();

    for(int i=0; i<n-1; i++){
        bool swapped = false;
        for(int j=0;j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
    return arr;
}

int selisih(int m, vector<int> &arr){
    bubbleSort(arr);
    int n=arr.size();
    int sum1=0,sum2=0;

    for(int i=n-m; i<n;i++) sum1+=arr[i];
    for(int i=0;i<m;i++) sum2+=arr[i];

    sum1=abs(sum1-sum2);
    return sum1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    int t,n,m,x;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> arr;
        while(cin >> x){
            arr.push_back(x);
        }
        int n=abs(n-m);
        cout << selisih(n,arr) << "\n";
    }
    return 0;
}
```


Terdapat beberapa kesalahan yang menyebabkan hasil yang tidak sesuai atau bahkan menyebabkan error saat dijalankan. Berikut adalah beberapa poin kesalahannya:
### Kesalahan dalam kode:

1. Kesalahan pada `bubbleSort`
    
    - Fungsi `bubbleSort` mengembalikan **vector**, tetapi di dalam `selisih()`, kamu tidak menangkap nilai kembalian tersebut.
    - Sebaiknya, ubah `bubbleSort` agar bekerja langsung pada `arr` tanpa mengembalikan nilai.
  <br/>
2. Kesalahan dalam membaca input array
    
    - Dalam loop `while(cin >> x)`, program akan terus membaca sampai **EOF** (akhir dari input), bukan sampai `n` elemen saja. Ini menyebabkan **jumlah elemen yang dibaca lebih dari yang seharusnya**.
    - Sebaiknya, gunakan **loop terbatas berdasarkan `n`** untuk memastikan hanya `n` elemen yang dibaca.
3. **Variabel `n` yang ditimpa dalam loop `while(t--)`**
    
    - Kamu mendeklarasikan ulang `int n=abs(n-m);`, tetapi `n` sudah ada sebagai parameter dalam `selisih()`.
    - Variabel ini seharusnya langsung dikirimkan sebagai `m` dalam `selisih()`.
4. **Kesalahan dalam iterasi `selisih()`**
    
    - Loop `for(int i=0;i<m;i++) sum2+=arr[i];` salah karena `m` seharusnya digunakan untuk menghitung selisih dari **N-M elemen terbesar dan N-M elemen terkecil**, bukan `m` itu sendiri.
5. **Kesalahan dalam `cin.tie();`**
    
    - `cin.tie();` seharusnya `cin.tie(0);` untuk bekerja dengan benar.

---

