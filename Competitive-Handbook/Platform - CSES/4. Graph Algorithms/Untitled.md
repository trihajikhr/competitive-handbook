---
obsidianUIMode: preview
note_type: problem set
sumber:
tags:
  - problem-set
date_learned:
---
Link Problem: 

---
# Judul

## Problem

## Solution
## Proof of Correctness
## Code Implementation

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

using VVC = vector<vector<char>>;
using PII = pair<int, int>;

void print(const VVC& grid) {
    for (const auto& row : grid) {
        for (const auto& x : row) {
            cout << x;
        }
        cout << "\n";
    }
}

vector<int> korX = {-1, 0, 1, 0};
vector<int> korY = {0, 1, 0, -1};
vector<char> arr = {'U', 'R', 'D', 'L'};

auto bfs_search(VVC& grid, int n, int m, PII& start, PII& end) -> vector<char> {
    queue<pair<int, int>> que_grid;
    que_grid.push(start);

    bool found = false;
    while (!que_grid.empty() && !found) {
        auto [x, y] = que_grid.front();
        que_grid.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + korX[i];
            int ny = y + korY[i];

            if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m)) {
                continue;
            }

            if (grid[nx][ny] == '#') {
                continue;
            }

            if (grid[nx][ny] == 'B') {
                grid[nx][ny] = arr[i];
                found = true;
                break;
            }

            if (grid[nx][ny] != '.') {
                continue;
            }

            grid[nx][ny] = arr[i];
            que_grid.emplace(nx, ny);
        }
    }

    if (!found) {
        return {};
    }

    vector<char> path;
    int bx = end.first;
    int by = end.second;
    while (make_pair(bx, by) != start) {
        if (grid[bx][by] == 'A') {
            break;
        }

        path.push_back(grid[bx][by]);

        for (int i = 0; i < 4; i++) {
            if (arr[i] == grid[bx][by]) {
                bx -= korX[i];
                by -= korY[i];
                break;
            }
        }
    }

    return path;
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            grid[i][j] = c;

            if (c == 'A') {
                start = {i, j};
            } else if (c == 'B') {
                end = {i, j};
            }
        }
    }

    vector<char> path = bfs_search(grid, n, m, start, end);

    if (path.empty()) {
        cout << "NO";
    } else {
        cout << "YES\n" << path.size() << "\n";
        reverse(path.begin(), path.end());
        for (const auto& x : path) {
            cout << x;
        }
    }

    return 0;
}
```