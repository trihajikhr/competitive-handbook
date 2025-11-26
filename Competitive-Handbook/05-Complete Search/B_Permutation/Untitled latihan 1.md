---
obsidianUIMode: preview
note_type: problem set
id_problem: 
judul_problem: 
sumber: 
kategori_problem: 🎯 exercise 📊 problem_statement 🥇 contest
kesulitan: 🥉 easy 🥈 medium 🥇 hard
time_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula)
memory_complexity: 🟢 O(1) 🔵 O(log n) 🟡 O(√n) 🟠 O(n) 🟤 O(n log n) 🟣 O(n²) 🟧 O(n³) 🔴 O(2ⁿ) ⚫ O(n!) ⚪O(formula) ✅ → Stable ❌ → Unstable
status: ❌ unsolved ⏳ progress 🏆 solved
date_solved: 
pendekatan: 
tags:
  - tag
---
Link problem: 

#tag #tag #tag

---
# Judul
Time limit: -
Memory limit: -

// problem nya

### Input
\-
#### Input constraints
\-
### Output
\-
### Examples
Input:
```

```

Output:
```bash

```

### Note
\-
# Jawaban
// penjelasan singkat

```cpp
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>permutation;
vector<bool> chosen;

void search(){
    if((int)permutation.size()==n){
        for(int x : permutation){
            cout << x << " ";
        }
        cout << "\n";  
    } else {
        for(int i=0; i<n ;i++){
            if(chosen[i]) continue;
            chosen[i]=true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }      
}

int main(){
    cout << "Masukan nilai n: "; cin >> n;

    chosen.assign(n, false);
    search();

    return 0;
}
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
# Informasi tambahan