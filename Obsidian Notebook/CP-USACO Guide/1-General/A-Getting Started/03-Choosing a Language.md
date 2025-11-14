---
obsidianUIMode: preview
note_type: Book Theory
judul_materi: Choosing a Language
sumber:
  - USACO guide
date_learned: 2025-07-18T22:25:00
tags:
  - general-usaco
  - programming-language
---
Link Sumber: 


```cardlink
url: https://usaco.guide/general/choosing-lang?lang=cpp#what-languages-does-the-usaco-support
title: "Choosing a Language"
description: "What languages you can use for programming contests."
host: usaco.guide
favicon: https://usaco.guide/favicon-32x32.png?v=486b7e9b938c7be5463018a5e8da37f8
image: https://usaco.guide/static/2863837723a7041cb58da9f7856ce0fb/0ff54/social-media-image.jpg
```


---
# Choosing a Language
## What Languages Does The USACO Support?

Bahasa pemrograman yang paling populer dan didukung oleh USACO adalah C++17, Java, dan Python 3. C juga didukung, namun pada dasarnya merupakan versi yang lebih terbatas dibandingkan C++, karena tidak memiliki struktur data bawaan (_built-in data structures_) yang sering digunakan dalam kompetisi.

## What Are The Differences Between C++11 and C++17?

Jika kamu baru mulai belajar, kemungkinan besar kamu belum akan menggunakan fitur khusus C++17, jadi mengumpulkan solusi dengan C++11 atau C++17 sudah cukup.

Untuk informasi tentang fitur-fitur yang diperkenalkan di C++11, C++14, dan C++17, silakan lihat tautan-tautan berikut:

- [C++11 for Programming Contests](https://usaco.guide/CPH.pdf#page=130)
    
- [C++ Tricks (C++11 onwards)](https://codeforces.com/blog/entry/74684)
    
- [C++14](https://en.cppreference.com/w/cpp/14)
    
- [C++17](https://en.cppreference.com/w/cpp/17)
    
## What Are The Differences Between Python 2 and Python 3?

Seperti yang disebutkan dalam tautan di bawah ini, terdapat banyak perbedaan antara Python 2 dan Python 3. Python 3 adalah versi yang lebih baru, dan sebagian besar peserta USACO menggunakan Python 3 dibandingkan Python 2.

- [Python 2 vs Python 3](https://wiki.python.org/moin/Python2orPython3)

## What Language Should I Start Out With?

Secara umum, kami merekomendasikan hal-hal berikut:

- Jika kamu sudah menguasai satu atau lebih dari bahasa-bahasa ini, cukup gunakan bahasa yang paling kamu kuasai.
<br/>
- Jika kamu belum mengenal satupun dari bahasa-bahasa ini, sebaiknya mulai dengan C++, karena pengguna C++ umumnya tidak perlu terlalu khawatir soal solusi yang terlalu lambat karena faktor konstanta. Selain itu, sebagian besar modul saat ini belum mendukung Java dan Python.
<br/>
- Jangan terlalu banyak berpikir dalam memilih bahasa — kamu selalu bisa mengganti bahasa nanti!

## Can I Pass Every Problem in Every Language?
C++ biasanya lebih cepat dibandingkan Java, dan Java biasanya lebih cepat dibandingkan Python. Meskipun Python dan Java diberi batas waktu dua kali lipat dibandingkan C++ di USACO, hal ini tidak berlaku di sebagian besar situs lainnya (misalnya Codeforces, CSES). Bahkan dengan batas waktu yang diperpanjang, Python dan Java kadang tetap kesulitan untuk lolos.

- Mulai musim USACO 2022–2023, panitia sering memastikan bahwa peserta bisa mendapatkan skor penuh pada soal-soal Bronze dan Silver, baik menggunakan C++, Python, maupun Java. Namun, hal ini tidak dijamin. Contohnya, ada soal Bronze terbaru yang tidak diharapkan bisa diselesaikan dengan Python karena terlalu lambat.
<br/>
- Python terlalu lambat untuk sebagian besar soal di divisi Gold dan Platinum. 
<br/>
- Saat ini belum ada contoh soal USACO yang benar-benar tidak bisa diselesaikan dengan Java, namun ada kasus di mana kode resmi versi C++ tidak cukup cepat jika diterjemahkan ke Java dan karena itu tidak bisa mendapatkan skor penuh.

## Example - [Wormhole Sort](http://www.usaco.org/index.php?page=viewproblem2&cpid=992) (USACO Silver Jan 2020)
Solusi Java yang disajikan dalam analisis membutuhkan lebih dari 3 detik untuk dijalankan (dari batas waktu 4 detik yang tersedia).

```java
import java.io.*;
import java.util.*;
public class wormsort {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("wormsort.in"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		loc = new int[n];
		component = new int[n];
		edges = new LinkedList[n];
		for (int i = 0; i < n; i++) edges[i] = new LinkedList<>();
		lhs = new int[m];
		rhs = new int[m];
		weight = new int[m];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) loc[i] = Integer.parseInt(st.nextToken()) - 1;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			lhs[i] = Integer.parseInt(st.nextToken()) - 1;
			rhs[i] = Integer.parseInt(st.nextToken()) - 1;
			weight[i] = Integer.parseInt(st.nextToken());
		}
		br.close();
		int minW = 0;
		int maxW = 1000000001;
		while (minW != maxW) {
			int mid = (minW + maxW + 1) / 2;
			if (valid(mid)) minW = mid;
			else maxW = mid - 1;
		}
		if (minW > 1e9) minW = -1;
		PrintWriter pw =
		    new PrintWriter(new BufferedWriter(new FileWriter("wormsort.out")));
		pw.println(minW);
		pw.close();
	}
	static int[] loc, lhs, rhs, weight;
	static LinkedList<Integer>[] edges;
	static int[] component;
	private static void dfs(int curr, int label) {
		if (component[curr] == label) return;
		component[curr] = label;
		for (int child : edges[curr]) dfs(child, label);
	}
	private static boolean valid(int minW) {
		Arrays.fill(component, -1);
		for (int i = 0; i < edges.length; i++) edges[i].clear();
		for (int i = 0; i < lhs.length; i++) {
			if (weight[i] >= minW) {
				edges[lhs[i]].add(rhs[i]);
				edges[rhs[i]].add(lhs[i]);
			}
		}
		int numcomps = 0;
		for (int i = 0; i < component.length; i++) {
			if (component[i] < 0) { dfs(i, numcomps++); }
		}
		for (int i = 0; i < loc.length; i++) {
			if (component[i] != component[loc[i]]) return false;
		}
		return true;
	}
}
```

Solusi C++ yang setara berjalan dalam waktu kurang dari 800 milidetik.

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> loc, lhs, rhs, weight;
vector<vector<int>> edges;
vector<int> component;

void dfs(int curr, int label) {
	if (component[curr] == label) return;
	component[curr] = label;
	for (int child : edges[curr]) dfs(child, label);
}

bool valid(int minW) {
	component.assign(n, -1);
	for (int i = 0; i < edges.size(); i++) edges[i].clear();
	for (int i = 0; i < lhs.size(); i++) {
		if (weight[i] >= minW) {
			edges[lhs[i]].push_back(rhs[i]);
			edges[rhs[i]].push_back(lhs[i]);
		}
	}
	int numcomps = 0;
	for (int i = 0; i < component.size(); i++) {
		if (component[i] < 0) { dfs(i, numcomps++); }
	}
	for (int i = 0; i < loc.size(); i++) {
		if (component[i] != component[loc[i]]) return false;
	}
	return true;
}

int main() {
	freopen("wormsort.in", "r", stdin);
	cin >> n >> m;
	loc = vector<int>(n);
	component = vector<int>(n);
	edges = vector<vector<int>>(n);
	lhs = vector<int>(m);
	rhs = vector<int>(m);
	weight = vector<int>(m);
	for (int i = 0; i < n; i++) {
		cin >> loc[i];
		--loc[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> lhs[i] >> rhs[i] >> weight[i];
		--lhs[i], --rhs[i];
	}
	int minW = 0;
	int maxW = 1000000001;
	while (minW != maxW) {
		int mid = (minW + maxW + 1) / 2;
		if (valid(mid)) minW = mid;
		else maxW = mid - 1;
	}
	if (minW > 1e9) minW = -1;
	freopen("wormsort.out", "w", stdout);
	cout << minW << "\n";
}
```

Solusi Python yang setara hanya berhasil melewati lima test case pertama.

```py
import sys

sys.setrecursionlimit(1000000)

sys.stdin = open("wormsort.in", "r")
sys.stdout = open("wormsort.out", "w")

n, m = map(int, input().split())
loc = [0] * n
component = [0] * n
edges = [[] for i in range(n)]

lhs = [0] * m
rhs = [0] * m
weight = [0] * m


def dfs(curr, label):
	if component[curr] == label:
		return
	component[curr] = label
	for child in edges[curr]:
		dfs(child, label)


def valid(minW):
	global component
	component = [-1] * n
	for i in range(n):
		edges[i].clear()
	for i in range(m):
		if weight[i] >= minW:
			edges[lhs[i]].append(rhs[i])
			edges[rhs[i]].append(lhs[i])
	numcomps = 0
	for i in range(n):
		if component[i] < 0:
			dfs(i, numcomps)
			numcomps += 1
	for i in range(n):
		if component[i] != component[loc[i]]:
			return False
	return True


loc = list(map(lambda x: int(x) - 1, input().split()))
for i in range(m):
	lhs[i], rhs[i], weight[i] = map(int, input().split())
	lhs[i] -= 1
	rhs[i] -= 1

minW = 0
maxW = 1000000001
while minW != maxW:
	mid = (minW + maxW + 1) // 2
	if valid(mid):
		minW = mid
	else:
		maxW = mid - 1

if minW > 1e9:
	minW = -1
print(minW)
```

Pendekatan ini masih bisa dioptimalkan agar dapat melewati semua test case.
Waktu eksekusinya sekitar 3,8 detik.

```py
def main():
	f = open("wormsort.in", "rb")
	n, m = map(int, f.readline().split())
	loc = [*map(int, f.readline().split())]
	edges = [[] for _ in range(n)]
	weights = []

	def valid(loc, minW):
		component = [-1] * n
		numcomps = 0
		for i in range(n):
			if component[i] != component[loc[i] - 1]:
				return False
			elif component[i] == -1:
				todo = [i]
				component[i] = numcomps
				for node in todo:
					for child, weight in edges[node]:
						if component[child] == -1 and weight >= minW:
							component[child] = numcomps
							todo.append(child)
				numcomps += 1
		return True

	for line in f:
		a, b, w = map(int, line.split())
		edges[a - 1].append((b - 1, w))
		edges[b - 1].append((a - 1, w))
		weights.append(w)

	weights.sort()
	weights.append(10**9 + 1)

	lo, hi = 0, m + 1
	while lo != hi:
		mid = (lo + hi) // 2
		if valid(loc, weights[mid]):
			lo = mid + 1
		else:
			hi = mid

	open("wormsort.out", "w").write(f"{-1 if lo == m + 1 else weights[lo-1]}\n")


main()
```

Terakhir, pendekatan di bawah ini menggunakan DSU (Disjoint Set Union) — sebuah topik tingkat Gold — yang berjalan dalam waktu sekitar 1 detik.

```py
# Author: Nicolas Hsu

file = open("wormsort.in")
N, M = map(int, file.readline().split())
P = tuple(map(int, ("0 " + file.readline()).split()))
W = [tuple(map(int, file.readline().split())) for i in range(M)]
W.sort(key=lambda w: -w[2])

par = list(range(N + 1))


def find(u):
	if par[u] == u:
		return u
	else:
		par[u] = find(par[u])
		return par[u]


w = -1
for n in range(1, N + 1):
	while find(n) != find(P[n]):
		w += 1
		par[find(W[w][1])] = find(W[w][0])

out = open("wormsort.out", "w")
out.write("-1" if w == -1 else str(W[w][2]))
out.close()
```

## What Am I Expected to Know?
Kamu sebaiknya sudah bisa ngoding dalam setidaknya satu dari bahasa pemrograman yang disebutkan sebelumnya sebelum melanjutkan ke bagian Bronze dari panduan ini.

Untuk daftar yang lebih rinci tentang apa saja yang sebaiknya kamu kuasai, bacalah modul **["Expected Knowledge"](https://usaco.guide/general/expected?lang=cpp)**.