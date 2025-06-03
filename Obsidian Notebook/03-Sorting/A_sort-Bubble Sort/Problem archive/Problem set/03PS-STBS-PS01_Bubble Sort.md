---
obsidianUIMode: preview
note_type: problem set
id_problem: 03PS-STBS-PS01
judul_problem: Bubble Sort
sumber: hackerearth.com
kategori_problem: 📊 problem_statement
kesulitan: 🥉 easy
time_complexity: 🟣 O(n²)
memory_complexity: 🟢 O(1) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-03T13:30:00
pendekatan: bubble sort algorithm
tags:
  - array
  - bubble-sort
  - sorting
---
Link problem: [Bubble Sort \| Practice Problems](https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/bubble-sort-15-8064c987/?purpose=login&source=problem-page&update=google)

#array #bubble-sort #sorting 

---
# Bubble Sort
Time limit: 1 s
Memory limit: 256 megabyte

Diberikan sebuah array $a_{1},a_{2},...,a_{n}$. Yang menggunakan fungsi semisal $BubbleSort(A)$, yang bernilai banyaknya iterasi.

### Input
- Baris pertama berisi sebuah bilangan bulat $n(1\leq n \leq 10^{5})$ yang menyatakan jumlah elemen dalam array.
- Baris kedua berisi $n$ bilangan bulat positif $(1 \leq a_i \leq 10^9)$ yang merupakan elemen-elemen array.
- **Catatan**: Dijamin bahwa semua elemen dalam array **berbeda**.
### Output
Cetak satu bilangan bulat yang merupakan jawaban dari pertanyaan.
### Examples
Input:
```
5  
1 3 2 5 4  
```

Output:
```bash
2
```

### Note
Problem statement ini kurang jelas, karena meminta user untuk membuka gambar yang sayangnya tidak bisa dibuka. Namun diketahui bahwa output yang diminta adalah banyaknya iterasi yang dilakukan di perulangan pertama. Jika kamu mengetahui algoritma bubble sort, maka ini adalah soal yang mudah.
# Jawaban
Jawaban yang biasa:

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bubbleSort(int n, vector<int> &arr){
	
	int count=0;

	for(int i=0; i<n-1; i++){
		count++;
		bool swapped = false;

		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
	return count;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();

	int n; cin >> n;
	vector<int> arr(n);
	for(int&x : arr) cin >> x;

	cout << bubbleSort(n, arr) << "\n";
	return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
## Jawaban efektif
Setelah beberapa percobaan, jawaban berikut membutuhkan waktu dan memory terkecil:

```cpp
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int bs(int n, vector<int> & arr){
 
	int count = 0;
 
	for(int i=0; i<n-1;i++){
		bool swapped = false;
		count++;
		for(int j=0;j<n-i-1;j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
	return count;
}
 
int main(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int &x : arr) cin >> x;
 
	cout << bs(n,arr) << "\n";
	return 0;
}
```

Time complexity: $O(n^2)$
Memory complexity: $O(1)$
# Editorial 
Menuliskan algoritma bubble sort biasa. Namun karena yang dicari adalah banyaknya iterasi (passes) yang dilakukan dalam bubble sort untuk mengurutkan array yang diberikan, maka kita berfokus pada variabel `count`.

Problem statemen ini cukup mudah, terutama jika kita mengetahui algoritma bubble sort. Kita hanya perlu menambahkan iterasi `count` pada perulangan pertama. Dan lalu mengembalikan variabel `count` tersebut.
# Informasi tambahan