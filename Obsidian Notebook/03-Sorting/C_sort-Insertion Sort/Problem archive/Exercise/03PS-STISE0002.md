---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STISE0002
judul_problem: Menyusun Angka Sederhana
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-04-08T19:27:00
pendekatan: insertion sort algorithm
tags:
  - insertion-sort
  - array
  - sorting
---
Link problem: 

#insertion-sort #array #sorting 

---
# Menyusun Angka Sederhana
Time limit: -
Memory limit: -

Diberikan sebuah array berisi `n` bilangan bulat. Urutkan array tersebut menggunakan algoritma **insertion sort** dalam urutan menaik. Cetak array setelah setiap langkah penyisipan (insertion).

### Input
- Baris pertama berisi satu bilangan bulat `n` (1 ≤ n ≤ 1000)
- Baris kedua berisi `n` bilangan bulat yang dipisahkan spasi
#### Input constraints
\-
### Output
Cetak array setelah setiap langkah penyisipan, masing-masing dalam satu baris
### Examples
Input:
```
5
5 2 4 6 1
```

Output:
```bash
2 5 4 6 1
2 4 5 6 1
2 4 5 6 1
1 2 4 5 6
```

### Note
\-
# Jawaban
Karena output harus mencetak kembali setiap penyisipan dilakukan, maka mudah saja. Kita hanya perlu melakukan operasi output tepat setelah penyisipan dilakukan, yang terdapat pada baris ke 17-18: 

```cpp
#include<iostream>
#include<vector>
using namespace std;

void is(vector<int> & arr){
    int n = arr.size();
    
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        
        while(j >= 0 && key < arr[j]){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
        for(auto&x :arr) cout << x << " ";
        cout << "\n";
    }    
}

int main(){
    int n; cin >> n;
    vector<int>arr(n);
    
    for(int&x:arr) cin >> x;
    is(arr);
    
    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
Jika semisal menggunakan metode yang ditingkatkan, mungkin seperti ini, walaupun mungkin suatu saat ada revisi lagi. Yaaaa, walaupun cuma menambahkan efisiensi pada proses input saja haha:

```cpp
#include<iostream>
#include<vector>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0)

void is(vector<int> & arr){
    int n=arr.size();
    
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        
        while(j >= 0 && key<arr[j]){
            arr[j+1]= arr[j];
            --j;
        }
        arr[j+1] = key;
        for(int&x:arr) cout << x << " "; cout << "\n";
    }
}

int main(){
    fastio();
    
    int n; cin >> n;
    vector<int> arr(n);
    for(int&x:arr) cin >> x;
    is(arr);
    
    return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
# Editorial 
- Iterasi mulai dari indeks ke-1
- Simpan nilai `arr[i]` ke variabel `key`
- Bandingkan dan geser elemen sebelumnya yang lebih besar dari `key` ke kanan
- Sisipkan `key` ke posisi yang tepat
- Cetak isi array setelah setiap langkah
# Informasi tambahan