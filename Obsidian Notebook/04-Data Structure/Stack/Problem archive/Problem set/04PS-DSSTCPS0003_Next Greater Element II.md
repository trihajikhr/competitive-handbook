---
obsidianUIMode: preview
note_type: problem set
id_problem: 04PS-DSSTCPS0003
judul_problem: Next Greater Element II
sumber: leetcode.com
kategori_problem: 📊 problem_statement
kesulitan: 🥈 medium
time_complexity: 🟠 O(n)
memory_complexity: 🟠 O(n) ✅ → Stable
status: 🏆 solved
date_solved: 2025-03-07T04:01:00
pendekatan: stack data structure
tags:
  - data-structure
  - array
  - stack
---
Link problem: [Next Greater Element II - LeetCode](https://leetcode.com/problems/next-greater-element-ii/description/)

#data-structure #stack #array 

---
# Next Greater Element II
Time limit: -
Memory limit: -

Diberikan sebuah array bilangan bulat _circular_ `nums` (yaitu, elemen setelah `nums[nums.length - 1]` adalah `nums[0]`), kembalikan bilangan yang lebih besar berikutnya untuk setiap elemen dalam `nums`.

Bilangan yang lebih besar berikutnya dari sebuah bilangan `x` adalah bilangan pertama yang lebih besar darinya dalam urutan penelusuran array, yang berarti kamu dapat mencari secara _circular_ untuk menemukan bilangan yang lebih besar berikutnya. Jika tidak ada, kembalikan `-1` untuk bilangan tersebut.

### Input
Sebuah array.
#### Input constraints
- $1 \leq num.length \leq 10^4$
- $-10^{9} \leq nums[i] \leq 10^{9}$
### Output
\-
### Examples
Input 1:
```
1 2 1
```

Output 1:
```bash
2 -1 2
```

- Bilangan **1 pertama** memiliki bilangan lebih besar berikutnya, yaitu **2**.
- Bilangan **2** tidak memiliki bilangan lebih besar berikutnya, jadi hasilnya **-1**.
- Bilangan **1 kedua** harus mencari secara _circular_ dan menemukan bilangan **2**.

Input 2:
```
1 2 3 4 3
```

Output 2:
```bash
2 3 4 -1 4
```

- Bilangan **1** memiliki bilangan lebih besar berikutnya, yaitu **2**.
- Bilangan **2** memiliki bilangan lebih besar berikutnya, yaitu **3**.
- Bilangan **3 pertama** memiliki bilangan lebih besar berikutnya, yaitu **4**.
- Bilangan **4** tidak memiliki bilangan lebih besar berikutnya, jadi hasilnya **-1**.
- Bilangan **3 kedua** harus mencari secara _circular_ dan menemukan bilangan **4**.
### Note
\-
# Jawaban
Karena di leetcode hanya memasukan solusi di dalam class langsung, maka fungsinnya mungkin cukup seperti ini:

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1); // Inisialisasi hasil dengan -1
        stack<int> s;

        // Loop dua kali untuk menangani circular array
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i % n]) {
                    s.pop();
            }

            if (i < n && !s.empty()) {
                    nge[i] = s.top();
            }

            s.push(nums[i % n]);
        }
    return nge;
    }
};
```

Time complexity: $O(n)$
Memory complexity: $O(n)$
## Jawaban efektif
Jika program bisa memeriksa inputan dari user, mungkin akan seperti ini:

```cpp
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0);

vector<int> nextGreaterElements(vector<int> & arr){
    int n=arr.size();
    vector<int> nge (n, -1);
    stack<int> s;

    for(int i=2*n-1;i>=0;i--){
        while(!s.empty() && s.top() <= arr[i%n]){
            s.pop();
        }

        if(i<n && !s.empty()){
            nge[i]=s.top();
        }
        s.push(arr[i%n]);
    }
    return nge;
}

int main(){
    fastio();
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int & x: arr) cin >> x;

    vector<int> rest=nextGreaterElements(arr);
    for(int & x: rest) cout << x << " ";

    cout << "\n";

    return 0;

}
```

Time complexity: $O(n)$
Memory complexity: $O(n)$
# Editorial 
Sebelum kamu mengerjakan soal ini, pasti kamu akan mencoba pendekatan Next Greater Element, seperti soal sebelumnya. Dan pasti terdapat kesalahan.

Kenapa?

Kode yang kamu tulis **seharusnya sudah benar** untuk mencari _Next Greater Element_ dalam array **biasa** (bukan _circular array_). Tapi ada beberapa kemungkinan yang bisa membuatnya **tidak bekerja dengan benar** tergantung bagaimana kamu menggunakannya:

## Kemungkinan Kesalahan

Jika soal meminta _Next Greater Element_ dalam **circular array**, kode ini tidak cukup karena hanya memeriksa array **sekali**. Untuk _circular array_, kita perlu **menjalankan loop dua kali** agar elemen di awal bisa melihat ke elemen di akhir.

## Solusi Jika Soal Circular Array

Jika soal yang kamu kerjakan adalah _Next Greater Element II_ (dalam _circular array_), gunakan **dua kali iterasi** untuk menangani elemen yang "melihat ke belakang" dalam array.

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, -1); // Inisialisasi hasil dengan -1
    stack<int> s;

    // Loop dua kali untuk menangani circular array
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums[i % n]) {
            s.pop();
        }

        if (i < n && !s.empty()) {
            nge[i] = s.top();
        }

        s.push(nums[i % n]);
    }

    return nge;
}

int main() {
    vector<int> arr = {1, 2, 1};
    vector<int> result = nextGreaterElements(arr);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

#### Penjelasan

- `i % n` digunakan agar array bisa "berputar".
- Looping dilakukan **dua kali** (`2 * n - 1`) untuk menangani elemen yang perlu melihat ke belakang.

**Input:**

```
1 2 1
```

**Output:**

```
2 -1 2
```

---

## Kesimpulan

- Jika soalnya _Next Greater Element_ biasa → Kode awalmu sudah benar ✅
- Jika soalnya _Circular Next Greater Element_ → Gunakan **dua kali iterasi** seperti di atas

# Informasi tambahan
Circular Array itu maksudnya apa oy?

**Circular Array** (Array Melingkar) adalah array di mana **elemen terakhir dianggap terhubung kembali ke elemen pertama**, sehingga bisa diakses secara _looping_ seolah-olah array itu melingkar.

## Contoh Circular Array

Misalkan ada array:

```
[1, 2, 3, 4, 5]
```

Jika ini adalah **array biasa**, maka setelah elemen `5`, array akan berhenti.

Namun, jika ini adalah **circular array**, setelah `5`, kita bisa kembali ke `1` seolah-olah array tidak memiliki ujung.

## Next Greater Element pada Circular Array

Misalkan kita punya **input array**:

```
[1, 2, 1]
```

Dan kita ingin mencari _Next Greater Element_ untuk setiap elemen dalam bentuk **circular**.

- **Elemen pertama (`1`)** → _Next Greater_ adalah `2` (di sebelah kanan).
- **Elemen kedua (`2`)** → Tidak ada yang lebih besar setelahnya, jadi _Next Greater_ adalah `-1`.
- **Elemen ketiga (`1`)** → Karena array _melingkar_, maka bisa kembali ke awal. Jadi _Next Greater_ untuk `1` ini adalah `2` (yang ada di indeks pertama).

#### Output yang benar:

```
[2, -1, 2]
```

Jika kita **tidak** menggunakan pendekatan _circular array_, maka output akan menjadi:

```
[2, -1, -1]
```

yang **salah** untuk soal _circular array_ karena elemen terakhir harus bisa melihat ke elemen pertama.


## Bagaimana Menanganinya?

Untuk menangani _circular array_, kita bisa menggunakan **modulus (`%`)** untuk membuat indeks tetap dalam batas array saat kita melihat ke depan.

Seperti dalam kode sebelumnya:

```cpp
nums[i % n] // Mengakses elemen seolah-olah array berputar
```

Karena `i % n` memastikan kita kembali ke awal jika indeks melebihi panjang array.

---

## Kesimpulan

- **Array biasa:** Setiap elemen hanya melihat ke kanan, berhenti di akhir.
- **Circular Array:** Elemen di akhir dapat melihat ke awal, seolah-olah array berputar.

