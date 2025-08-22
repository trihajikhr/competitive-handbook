---
obsidianUIMode: preview
test_case: BFS dan DFS
---
# Test Case {algoritma}
**Test Case** lebih luas cakupannya karena mencakup berbagai skenario, seperti:

- **Normal case** → Input standar
- **Edge case** → Kasus ekstrem (misal, input terbesar/kecil)
- **Corner case** → Kasus yang sering terlewat (misal, semua elemen sama)
- **Stress test** → Kasus besar untuk menguji efisiensi

# Test Case

Input:
```
7 8  
0 1  
0 2  
1 2  
1 3  
2 4  
3 4  
1 6  
1 5
```

Output DFS:
```bash
0 1 2 4 3 5 6
```

Output BFS:
```bash
0 1 2 3 5 6 4
```

---

Input:
```
8 8  
0 1  
0 2  
1 7  
2 4  
1 2  
3 5  
5 6  
7 4
```

Output DFS:
```bash
0 1 2 4 7 3 5 6
```

Output BFS:
```bash
0 1 2 7 4 3 5 6
```