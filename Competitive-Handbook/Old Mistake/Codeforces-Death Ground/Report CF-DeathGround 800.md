---
obsidianUIMode: preview
---
# DataviewJS Codeforces
## 1 | Rating 800

```dataviewjs
let pages = dv.pages('"Codeforces-Death Ground/800"')
    .where(p => p.date_learned)          
    .sort(p => p.date_learned, 'asc');   

dv.table(
  ["No", "Problem", "Tags", "Tanggal Solved"],
  pages.map((p, i) => [
    i + 1,                      
    p.judul ? p.judul : p.file.link,             
    p.tags ? (Array.isArray(p.tags) ? p.tags.join(", ") : p.tags) : "-", 
    dv.date(p.date_learned)?.toFormat("HH:mm - dd MMM yyyy") ?? "-"
  ])
);
```


<br/>

---
## 2 | Rating 900

```dataviewjs
let pages = dv.pages('"Codeforces-Death Ground/900"')
    .where(p => p.date_learned)          
    .sort(p => p.date_learned, 'asc');   

dv.table(
  ["No", "Problem", "Tags", "Tanggal Solved"],
  pages.map((p, i) => [
    i + 1,                      
    p.judul ? p.judul : p.file.link,             
    p.tags ? (Array.isArray(p.tags) ? p.tags.join(", ") : p.tags) : "-", 
    dv.date(p.date_learned)?.toFormat("HH:mm - dd MMM yyyy") ?? "-"
  ])
);
```

## 3 | Rating 1200

```dataviewjs
let pages = dv.pages('"Codeforces-Death Ground/1200"')
    .where(p => p.date_learned)          
    .sort(p => p.date_learned, 'asc');   

dv.table(
  ["No", "Problem", "Tags", "Tanggal Solved"],
  pages.map((p, i) => [
    i + 1,                      
    p.judul ? p.judul : p.file.link,             
    p.tags ? (Array.isArray(p.tags) ? p.tags.join(", ") : p.tags) : "-", 
    dv.date(p.date_learned)?.toFormat("HH:mm - dd MMM yyyy") ?? "-"
  ])
);
```