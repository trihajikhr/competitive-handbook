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
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        static const auto fastio = []() {
            ios_base::sync_with_stdio(false);
            cin.tie(nullptr);
            return 0;
        }();

        int n = nums.size();
        vector<bool> chosen(n, false);
        vector<int> current;
        vector<vector<int>> result; 
        search(nums, chosen, n, current, result);
        return result; 
    }

    void search(vector<int>& nums, vector<bool>& chosen, int n, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == n) {
            result.push_back(current); 
        } else {
            for (int i = 0; i < n; i++) {
                if (chosen[i]) continue; 
                chosen[i] = true;
                current.push_back(nums[i]); 
                search(nums, chosen, n, current, result); 
                chosen[i] = false; 
                current.pop_back(); 
            }
        }
    }
};
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