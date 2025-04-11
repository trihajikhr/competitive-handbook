---
obsidianUIMode: preview
note_type: problem set
id_problem: 04PS-DSSTCE0002
judul_problem: Next Greater Element
sumber: chatgpt.com
kategori_problem: 🎯 exercise
kesulitan: 🥉 easy
time_complexity: 🟠 O(n)
memory_complexity: 🟠 O(n) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-07T03:03:00
pendekatan: stack data structure
tags:
  - array
  - stack
  - data-structure
---
Link problem: 

#stack #array #data-structure 

---
# Next Greater Element
Time limit: -
Memory limit: -

Diberikan sebuah array `arr` dengan panjang `N`, untuk setiap elemen `arr[i]`, cari elemen pertama di sebelah kanan yang lebih besar darinya. Jika tidak ada, kembalikan `-1`.

### Input
- Baris pertama berupa `n`, yaitu panjang array `arr`.
- Baris kedua berupa elemen array.
#### Input constraints
\-
### Output
\-
### Examples
Input:
```
5
4, 5, 2, 10, 8
```

Output:
```bash
5, 10, 10, -1, -1
```

### Note
\-
# Jawaban
Jawaban tanpa keterangan lanjutan:

```cpp
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> & arr){
    int n=arr.size();
    vector<int> nge (n, -1);
    stack<int> s;

    for(int i=n-1; i>=0;i--){
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }

        if(!s.empty()){
            nge[i]=s.top();
        }

        s.push(arr[i]);
    }
    return nge;
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);

    for(int &x:arr) cin >> x;

    vector<int> result=nextGreaterElement(arr);
    for(int&x:result){
        cout << x << " ";
    }
    cout << "\n";
    return 0;

}
```

Time complexity: $O(n)$
Memory complexity: $O(n)$
## Jawaban efektif
Jika ada keterangan untuk memudahkan:

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1); // Inisialisasi hasil dengan -1
    stack<int> s; // Stack untuk menyimpan kandidat next greater

    for (int i = n - 1; i >= 0; i--) { 
        // Hapus elemen di stack yang lebih kecil atau sama dengan arr[i]
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // Jika stack tidak kosong, elemen teratas adalah next greater
        if (!s.empty()) {
            nge[i] = s.top();
        }

        // Masukkan elemen saat ini ke dalam stack
        s.push(arr[i]);
    }
    
    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(arr);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

Time complexity: $O(n)$
Memory complexity: $O(n)$
# Editorial 

Soal **Next Greater Element** bisa diselesaikan dengan pendekatan menggunakan **stack** dalam waktu $O(N)$. Berikut adalah langkah-langkahnya:

- Kita memproses elemen dari **kanan ke kiri** dalam array.
- Gunakan stack untuk menyimpan elemen yang mungkin menjadi _next greater_ untuk elemen sebelumnya.
- Saat memproses elemen baru:
    - Pop elemen dari stack jika mereka lebih kecil atau sama dengan elemen saat ini (karena tidak mungkin jadi _next greater_).
    - Jika stack tidak kosong setelah pop, elemen teratas stack adalah _next greater_.
    - Jika stack kosong, berarti tidak ada _next greater_, simpan `-1`.
    - Setelah itu, masukkan elemen saat ini ke dalam stack.

---

## Penjelasan Contoh

**Input:**

```cpp
arr = {4, 5, 2, 10, 8}
```

Kita akan memproses array dari kanan ke kiri:

|i|arr[i]|Stack (s)|Next Greater|
|---|---|---|---|
|4|8|8|-1|
|3|10|10|-1|
|2|2|10 → 2|10|
|1|5|10 → 5|10|
|0|4|10 → 5 → 4|5|

 **Output:**

```
[5, 10, 10, -1, -1]
```

## Kompleksitas Waktu

- $O(N)$ karena setiap elemen hanya masuk dan keluar dari stack **sekali**.

Kalau ada pertanyaan atau ingin penjelasan lebih lanjut, tanyakan aja! 🚀
# Informasi tambahan