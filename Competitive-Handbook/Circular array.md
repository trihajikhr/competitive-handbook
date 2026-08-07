
0-based:
```cpp
int pos = (x % n + n) % n;
```


---

1-based:
```cpp
int pos = (x - 1 + n) % n + 1;
```

atau:

```cpp
int pos = ((x - 1) % n + n) % n + 1;
```