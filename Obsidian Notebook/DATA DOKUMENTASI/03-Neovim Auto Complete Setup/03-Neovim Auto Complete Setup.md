---
obsidianUIMode: preview
note_type: Dokumentasi
judul_dokumentasi: Neovim Auto Complete Setup
date_add: 2025-07-28T16:04:00
status_dokumentasi: ✅Finish
tags:
  - neovim
  - vim
  - lazyvim
---
---
# 1 | Neovim Auto Complete Setup
Ketika kita membuat program atau menulis kode program dengan menggunakan kode editor atau IDE, sering kali kita mendapati tampilan seperti ini:

![[03-Neovim Auto Complete Setup-1.png]]

Saat saya mengetik kata `cla` pada Vscode yang sudah dipasangi LSP C++, terdapat auto complete box yang muncul, yang memberikan tebakan terhadap kode yang ingin kita ketik. Nah, fitur ini disebut dengan *Auto Complete*.

Sebelum saya memberikan penjelasan lebih panjang tentang apa itu fitur auto complete, mungkin penting bagi kita untuk tahu terlebih dahulu, apa itu LSP.

**LSP (Language Server Protocol)** adalah protokol standar yang memungkinkan editor teks (seperti Neovim, VSCode) berkomunikasi dengan _language server_ untuk menyediakan fitur pintar seperti:

- Auto complete
- Go to definition
- Hover info
- Rename symbol
- Error diagnostics

Dengan LSP, editor bisa mendukung banyak bahasa tanpa menulis ulang logika parsing/analisis untuk tiap bahasa.

Nah, didalam setiap LSP, biasanya ada fitur Auto complete yang disetel untuk bahasa dari LSP tersebut 😂. Jadi, apa itu auto complete?

Fitur **auto complete** adalah mekanisme yang secara otomatis menyarankan atau melengkapi teks saat pengguna sedang mengetik. Dalam konteks pemrograman, fitur ini membantu:

- Menyelesaikan nama fungsi, variabel, atau keyword.
- Mengurangi kesalahan penulisan (typo).
- Meningkatkan kecepatan coding.
- Memberikan dokumentasi singkat dari fungsi atau API.

Fitur ini biasanya muncul sebagai dropdown atau popup saat mengetik. Seperti gambar diatas.

Nah, supaya neovim kita lebih powerfull, dan ngoding di neovim terasa sat-set, terlebih lagi kebanyakan orang memang menggunakana neovim karena kecepatan dan ke-powerful-anya ketika digunakan, maka haram hukumnya jika tidak mengkonfigurasi fitur yang satu ini 😂.

Jadi, ikuti panduan dokumentasi pemasangan dan pengaktifan fitur auto complete pada neovim berikut.

---
<br/>

# 2 | Konfigurasi Plugins

Plugins yang memberikan fitur auto complete pada neovim sendiri ada banyak, berikut daftar plugin _autocomplete_ populer untuk Neovim:

1. **nvim-cmp**: Plugin utama autocomplete berbasis Lua, sangat modular dan fleksibel.
2. **cmp-nvim-lsp**: Sumber autocomplete dari LSP, digunakan bersama `nvim-cmp`.
3. **cmp-buffer**: Autocomplete dari isi buffer aktif.
4. **cmp-path**: Autocomplete untuk path/file.
5. **cmp-cmdline**: Autocomplete untuk command-line Neovim (`:` dan `/`).
6. **cmp-vsnip**, **cmp-luasnip**: Integrasi snippet engine seperti `vsnip` atau `LuaSnip`.
7. **LuaSnip**: Bukan autocomplete langsung, tapi menyediakan snippet yang bisa digunakan oleh `nvim-cmp`.
8. **lspkind.nvim**: Menambahkan ikon di samping suggestion untuk memperjelas jenisnya (function, variable, dll).
9. **blink.cmp**: Plugins autocomplete yang bisa diintegrasikan dengan banyak lsp, dan menjadi plugins bawaan LazyVim.
10. dll.

Masih ada banyak plugins auto complete diluaran sana, namun list diatas adalah plugins auto complete yang cukup terkenal, dan banyak digunakan, sehingga kita akan menggunakan beberapa plugins yang disebutkan diatas.

---
<br/>

## 2.1 | Persiapan Awal
Sebelum melakukan konfigurasi auto complete pertama, izinkan saya menceritakan momen menyebalkan ketika mengkonfigurasi auto complete di neovim, sekaligus bisa menjadi pelajaran untuk kedepanya.

Jadi, ketika saya pertama kali memasang plugins nvim-cmp, saya mendapati bug yang cukup merepotkan, yang butuh 2 harian untuk bisa dipecahkan, yaitu bug seperti ini;

![[Untitled video - Made with Clipchamp.mp4]]

Cuplikan diatas menampilkan bug, dimana terdapat 2 auto complete box yang saling bertumpuk, membuat saya kesulitan untuk menulis kode program, karena terdapat 2 suggestion yang berbeda dari tiap auto complete. Hal ini jelas menjadikan aktivitas menulis kode program saya terganggu dan tidak menyenangkan. Alih-alih mendapatkan kecepatan dan kemulusan neovim, malah jadi dibuat bingung tujuh keliling liat auto complete saling berebut seperti ini 😭.

Nah, setelah membaca banyak dokumentasi, instal ulang neovim beberapa kali, membaca reddit, stackoverflow, dan juga [dokumentasi resmi dari LazyVim](https://www.lazyvim.org/), akhirnya solusi dari masalah ini pun ditemukan.

> Apa?? Pakai AI? Satu abad ngga selesai-selesai nyari ini bug 🥲. AI tidak secanggih itu. Yang ada dibuat muter-muter dengan sikap sok tahunya yang bikin tambah kesel. 
> 
> Pelajari saja teknik-teknik menyelesaikan bug. Biasakan baca dokumentasi, dan pahami bagaimana suatu program bekerja!

Masalah ini berasal dari adanya 2 autocomplete yang berjalan dilatar belakang, yang tidak berasal dari satu konfigurasi yang sama. Yaitu auto complete yang saya konfigurasikan sendiri, dengan auto complete bawaan LazyVim.

Ingat lagi, bahwa ketika kita menginstall plugins manager LazyVim, akan ada beberapa plugins bawaan yang ikut terbawa dan terinstall disana. Untuk mengetahui plugins apa saja yang merupakan bawaan LazyVim, caranya cukup mudah, yaitu:

- Membuka command `:Lazy` ketika baru memasang LazyVim, untuk melihat plugins bawaan.

<br/>

- Membuka file `lazy-lock.json` ketika baru pertama kali dipasang.

<br/>

Namun, jika sudah terlanjur pasang banyak plugins, sehingga bercampur antara plugins bawaan dengan plugins kita sendiri, maka:

- Masuk ke path berikut pada windows `C:\Users\ASUS\AppData\Local\nvim-data\lazy\LazyVim\lua\lazyvim\plugins`, tepatnya di `C:\Users\ASUS\AppData\Local\nvim-data\lazy\LazyVim\lua\lazyvim\plugins\extras`.

<br/>

- Masuk ke path berikut untuk path relatif `~/.local/share/nvim/lazy/LazyVim/lua/lazyvim/plugins/`

<br/>

- Atau dengan mengunjungi alamat repository asli dari LazyVim, tepatnya pada link berikut, [LazyVim built-in plugins](https://github.com/LazyVim/LazyVim/tree/main/lua/lazyvim/plugins):
  
  ![[03-Neovim Auto Complete Setup-2.png]]

Kenapa penting untuk mengetahui plugins bawaan dari LazyVim?

Karena membuat kita bisa memanage plugins yang kita aktifkan, sehingga tidak ada plugins dengan fungsi yang sama yang aktif. Ingat sekali lagi, ada banyak sekali plugins yang disediakan untuk kita pasang di neovim, cukup ambil plugins-plugins yang menurut kita penting. Pilih saja plugins terbaik di masing-masing kategorinya. Ini penting supaya tidak ada plugins dengan fungsi yang sama yang bertumpuk, sehingga menyebabkan bug yang tidak karuan.

Untuk mengaktifkan dan menonaktifkan plugins, baik itu plugins bawaan atau plugins yang kita pasang, caranya mudah. Semisal, tambahkan satu file sebagai tempat utama mekanisme on-off plugins, misal didalam folder `lua/plugins`, dan buat file baru bernama misal `plugins-toogle.lua`.

Jika ingin mengaktifkan plugins, maka tulis:

```lua
return {
    {
        "Saghen/blink.cmp",
        enabled = true,
    }
}
```

Dan jika ingin menonaktifkanya, maka tulis:

```lua
return {
    {
        "Saghen/blink.cmp",
        enabled = false,
    }
}
```

Nah, penonaktifan plugins `Saghen/blink.cmp`, yang ternyata adalah plugins auto-complete bawaan LazyVim, langsung menyelesaikan masalah bug auto complete bertumpuk sebelumnya 😂. Hanya dengan sedikit penambahan baris kode, bug yang cukup sulit dipecahkan tersebut, akhirnya berhasil diatasi.

> Plugins `Saghen/blink.cmp` adalah plugins auto-complete yang lumayan bagus jika ingin menggunakan fitur auto-complete tanpa ribet, dan tanpa banyak konfigurasi, karena merupakan salah satu plugins built-in LazyVim. Hal ini karena plugins yang satu ini sudah menyediakan banyak pilihan auto complete, dari level dasar, hingga kode-kode yang lebih kompleks. Jika kamu tidak masalah dengan auto complete yang ala kadarnya, tapi cukup menunjang kebutuhan auto completemu, maka gunakan saja plugins ini. 
> 
> Salah satu kelemahan dari plugins ini, adalah tidak bisa menyisipkan custom snippets. Yang mana cukup penting bagi beberapa programmer, terutama untuk koding cepat, apalagi competitive-programmer.
> 
> Penjelasan lebih lengkapnya, baca di [[Saghen-blink-cmp - Plugins Auto Complete Built In terbaik]]

Jika semisal kamu juga ingin mengikuti panduan ini, ada kemungkinkan kamu akan mendapati bug yang serupa. Jadi, siap-siap gunakan panduan ini. 

---
<br/>

## 2.2 | Pemilihan Plugins Auto Complete Terbaik

Jika kita mencari tutorial memasang auto complete neovim di youtube, forum, komunitas, dan semacamnya, banyak yang merekomendasikan plugins auto complete dari `hrsh7th/nvim-cmp`. Untuk repository asli ada di link berikut, [hrsh7th/nvim-cmp](https://github.com/hrsh7th/nvim-cmp).

![[03-Neovim Auto Complete Setup-3.png]]

Dan..., ya, memang sangat direkomendasikan 😁✅! Berikut penjelasan lengkapnya:

### 📌 Apa Itu `hrsh7th/nvim-cmp`?

`nvim-cmp` (singkatan dari _completion_) adalah plugin **autocomplete** modern untuk Neovim, ditulis dalam bahasa **Lua**. Plugin ini dibuat dan dikelola oleh **hrsh7th**, salah satu kontributor terkenal di komunitas Neovim.


### 🧩 Plugin Apa Saja yang Terkait?

`nvim-cmp` adalah **core engine**, tapi sering digunakan bersama plugin sumber (_source plugins_), antara lain:

|Plugin|Fungsi|
|---|---|
|`cmp-nvim-lsp`|Autocomplete dari Language Server Protocol (LSP)|
|`cmp-buffer`|Autocomplete dari teks yang sedang dibuka (buffer)|
|`cmp-path`|Autocomplete untuk path/direktori file|
|`cmp-cmdline`|Autocomplete untuk baris perintah (`:` dan `/`)|
|`cmp-nvim-lua`|Autocomplete untuk API Lua Neovim|
|`cmp-emoji`|Menyediakan emoji completion|
|`cmp-calc`|Menyediakan hasil kalkulasi inline|
|`cmp-git`|Autocomplete berdasarkan konteks Git|
|`cmp-dictionary`|Menggunakan kamus sebagai sumber autocomplete|
|`cmp-luasnip`|Integrasi dengan snippet engine seperti `LuaSnip`|
|`LuaSnip`|Engine snippet yang fleksibel dan powerful|

### 📝 Kenapa `nvim-cmp` Banyak Direkomendasikan?

1. **Modular & Fleksibel**  
    `nvim-cmp` memungkinkan kamu memilih dan mengatur sendiri sumber autocomplete-nya. Ini memberi kebebasan dalam mengkustomisasi sesuai kebutuhan proyek.

<br/>

2. **Cepat & Ringan**  
    Dibuat dengan Lua yang dioptimalkan untuk performa tinggi di Neovim. Responsif bahkan saat digunakan dengan LSP dan banyak sumber.

<br/>

3. **Komunitas Besar & Dokumentasi Lengkap**  
    Karena populer, banyak pengguna dan tutorial tersedia di GitHub, forum, YouTube, dan Discord. Cocok untuk pemula maupun pengguna tingkat lanjut.

<br/>

4. **Integrasi dengan Ekosistem Neovim**  
    Kompatibel dengan plugin seperti `LuaSnip`, `lspkind.nvim`, `friendly-snippets`, dan lainnya—memungkinkan pengalaman menulis kode yang sangat produktif.

<br/>

5. **Aktif Dikembangkan**  
    Plugin ini terus diperbarui, memiliki issue tracker yang aktif, dan sangat jarang mengalami bug fatal yang tidak diperbaiki.

<br/>

6. **Dukungan LSP Kuat**  
    Dengan `cmp-nvim-lsp`, autocomplete bisa menampilkan signature, dokumentasi fungsi, dan parameter berdasarkan bahasa pemrograman yang sedang digunakan.

<br/>

7. **UI Ramah & Bisa Dikustomisasi**  
    Mendukung penyesuaian seperti ikon (`lspkind.nvim`), border, scroll, highlight, dan urutan prioritas sumber completion.
    

---
<br/>

## 2.3 | Pemasangan Plugins

Untuk bisa memasang plugins ini, pastikan kamu sudah mengikuti panduan [[01-Setup Neovim untuk C++ Competitive Programmer]]. Karena fitur seperti LSP sudah harus terpasang terlebih dahulu.

Untuk bisa mendapatkan kode konfigurasinya, kita harus masuk ke repository Github [nvim-cmp](https://github.com/hrsh7th/nvim-cmp), dan baca dokumentasi singkat alias file README yang diberikan. Kode konfigurasi dasarnya akan ditemukan dibagian **Setup**, **Recommended Configuration**:

![[03-Neovim Auto Complete Setup-4.png]]


Kodenya adalah seperti ini:

> ⚠️ Kunjungi repository asli jika ingin melakukan konfigurasi! Kode ini bisa saja berbeda dengan konfigurasi **Recommended Configuration**, karena update atau karena adanya perubahan terbaru yang dikeluarkan!

```lua
call plug#begin(s:plug_dir)
Plug 'neovim/nvim-lspconfig'
Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'hrsh7th/cmp-buffer'
Plug 'hrsh7th/cmp-path'
Plug 'hrsh7th/cmp-cmdline'
Plug 'hrsh7th/nvim-cmp'

" For vsnip users.
Plug 'hrsh7th/cmp-vsnip'
Plug 'hrsh7th/vim-vsnip'

" For luasnip users.
" Plug 'L3MON4D3/LuaSnip'
" Plug 'saadparwaiz1/cmp_luasnip'

" For mini.snippets users.
" Plug 'echasnovski/mini.snippets'
" Plug 'abeldekat/cmp-mini-snippets'

" For ultisnips users.
" Plug 'SirVer/ultisnips'
" Plug 'quangnguyen30192/cmp-nvim-ultisnips'

" For snippy users.
" Plug 'dcampos/nvim-snippy'
" Plug 'dcampos/cmp-snippy'

call plug#end()

lua <<EOF
  -- Set up nvim-cmp.
  local cmp = require'cmp'

  cmp.setup({
    snippet = {
      -- REQUIRED - you must specify a snippet engine
      expand = function(args)
        vim.fn["vsnip#anonymous"](args.body) -- For `vsnip` users.
        -- require('luasnip').lsp_expand(args.body) -- For `luasnip` users.
        -- require('snippy').expand_snippet(args.body) -- For `snippy` users.
        -- vim.fn["UltiSnips#Anon"](args.body) -- For `ultisnips` users.
        -- vim.snippet.expand(args.body) -- For native neovim snippets (Neovim v0.10+)

        -- For `mini.snippets` users:
        -- local insert = MiniSnippets.config.expand.insert or MiniSnippets.default_insert
        -- insert({ body = args.body }) -- Insert at cursor
        -- cmp.resubscribe({ "TextChangedI", "TextChangedP" })
        -- require("cmp.config").set_onetime({ sources = {} })
      end,
    },
    window = {
      -- completion = cmp.config.window.bordered(),
      -- documentation = cmp.config.window.bordered(),
    },
    mapping = cmp.mapping.preset.insert({
      ['<C-b>'] = cmp.mapping.scroll_docs(-4),
      ['<C-f>'] = cmp.mapping.scroll_docs(4),
      ['<C-Space>'] = cmp.mapping.complete(),
      ['<C-e>'] = cmp.mapping.abort(),
      ['<CR>'] = cmp.mapping.confirm({ select = true }), -- Accept currently selected item. Set `select` to `false` to only confirm explicitly selected items.
    }),
    sources = cmp.config.sources({
      { name = 'nvim_lsp' },
      { name = 'vsnip' }, -- For vsnip users.
      -- { name = 'luasnip' }, -- For luasnip users.
      -- { name = 'ultisnips' }, -- For ultisnips users.
      -- { name = 'snippy' }, -- For snippy users.
    }, {
      { name = 'buffer' },
    })
  })

  -- To use git you need to install the plugin petertriho/cmp-git and uncomment lines below
  -- Set configuration for specific filetype.
  --[[ cmp.setup.filetype('gitcommit', {
    sources = cmp.config.sources({
      { name = 'git' },
    }, {
      { name = 'buffer' },
    })
 })
 require("cmp_git").setup() ]]-- 

  -- Use buffer source for `/` and `?` (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline({ '/', '?' }, {
    mapping = cmp.mapping.preset.cmdline(),
    sources = {
      { name = 'buffer' }
    }
  })

  -- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline(':', {
    mapping = cmp.mapping.preset.cmdline(),
    sources = cmp.config.sources({
      { name = 'path' }
    }, {
      { name = 'cmdline' }
    }),
    matching = { disallow_symbol_nonprefix_matching = false }
  })

  -- Set up lspconfig.
  local capabilities = require('cmp_nvim_lsp').default_capabilities()
  -- Replace <YOUR_LSP_SERVER> with each lsp server you've enabled.
  require('lspconfig')['<YOUR_LSP_SERVER>'].setup {
    capabilities = capabilities
  }
EOF
```


Nah, ini adalah konfigurasi yang disarankan. Tapi kita tidak bisa langsung menggunakanya, karena ada perbedaan plugin manager dan plugin snipper yang digunakan. Pada bagian README, dijelaskan hal seperti ini dibagian **Recommended Configuration** (lihat lagi gambar diatas):

*This example configuration uses `vim-plug` as the plugin manager and `vim-vsnip` as a snippet plugin.*

Yang artinya, konfigurasi diatas ditujukan untuk pengguna neovim yang menggunakan `vim-plug` sebagai plugin manager, dan `vim-snip` sebagai plugin snipper.

Karena kita menggunakan LazyVim sebagai plugin manager, dan kedepannya kita akan menggunakan plugins bernama LuaSnip sebagai plugin snipper, maka kita perlu melakukan beberapa penyesuaian 😀.

---

Berikut adalah penyesuaian yang pas untuk pengguna LazyVim, neovim kita:

> Kode ini ditunjukan dengan tujuan dokumentasi, sehingga komentar disisipkan seminimal mungkin, karena penjelasan lebih lengkap ditaruh diluar. Sedangkan pada kode asli kita di neovim nantinya, akan jauh lebih baik jika komentar bawaan dari **Recommended Configuration** tetap dipertahankan, dan juga ditambah dengan komentar kita sendiri!

```lua
return {
  "hrsh7th/nvim-cmp",
  lazy = false,
  enabled = true,
  dependencies = {
    "neovim/nvim-lspconfig",
    "hrsh7th/cmp-nvim-lsp",
    "hrsh7th/cmp-buffer",
    "hrsh7th/cmp-path",
    "hrsh7th/cmp-cmdline",
    "L3MON4D3/LuaSnip",
    "saadparwaiz1/cmp_luasnip",
    "rafamadriz/friendly-snippets",
    "petertriho/cmp-git",
  },

  config = function()
    vim.notify("✅ nvim-cmp berhasil terpasang", vim.log.levels.INFO)
    local cmp = require("cmp")
    local luasnip = require("luasnip")

    cmp.setup({

      snippet = {
        -- REQUIRED - you must specify a snippet engine

        expand = function(args)
          -- vim.fn["vsnip#anonymous"](args.body) -- For `vsnip` users.

          require("luasnip").lsp_expand(args.body) -- For `luasnip` users.

          -- require("luasnip.loaders.from_vscode").lazy_load() -- user friendlysnippet

          -- require('snippy').expand_snippet(args.body) -- For `snippy` users.
          -- vim.fn["UltiSnips#Anon"](args.body) -- For `ultisnips` users.
          -- vim.snippet.expand(args.body) -- For native neovim snippets (Neovim v0.10+)

          -- For `mini.snippets` users:
          -- local insert = MiniSnippets.config.expand.insert or MiniSnippets.default_insert

          -- insert({ body = args.body }) -- Insert at cursor
          -- cmp.resubscribe({ "TextChangedI", "TextChangedP" })
          -- require("cmp.config").set_onetime({ sources = {} })
        end,
      },

      window = {
        completion = cmp.config.window.bordered(),
        documentation = cmp.config.window.bordered(),
      },

      mapping = cmp.mapping.preset.insert({
        ["<C-b>"] = cmp.mapping.scroll_docs(-4),
        ["<C-f>"] = cmp.mapping.scroll_docs(4),
        ["<C-Space>"] = cmp.mapping.complete(),
        ["<C-e>"] = cmp.mapping.abort(),

        -- tab akan memprioritaskan jump jika masih ada slot jump didepan
        -- pemilihan snipeet akan dilakukan manual dengan arrow keys
        ["<Tab>"] = cmp.mapping(function(fallback)
          if luasnip.expand_or_jumpable() then
            luasnip.expand_or_jump()
          else
            fallback()
          end
        end, { "i", "s" }),

        -- sama seperti diatas, tapi jump ke belakang
        ["<S-Tab>"] = cmp.mapping(function(fallback)
          if luasnip.jumpable(-1) then
            luasnip.jump(-1)
          else
            fallback()
          end
        end, { "i", "s" }),

        -- tombol enter akan memilih snippet teratas jika jendela auto complete muncul
        -- namun jika tidak, enter akan berfungsi normal, yaitu pindah baris (newline)
        ["<CR>"] = cmp.mapping(function(fallback)
          if cmp.visible() then
            cmp.confirm({ select = true })
          else
            fallback()
          end
        end, { "i", "s" }),
      }),

      -- sumber auto complete taruh disini!
      sources = cmp.config.sources({
        { name = "luasnip" }, -- For luasnip users.
        { name = "nvim_lsp" },
        { name = "path" },
        -- { name = 'vsnip' }, -- For vsnip users.
        -- { name = 'ultisnips' }, -- For ultisnips users.
        -- { name = 'snippy' }, -- For snippy users.
      }, {
        { name = "buffer" },
      }),
    })

    -- To use git you need to install the plugin petertriho/cmp-git and uncomment lines below
    -- Set configuration for specific filetype.
    -- membantu auto complete ketika menulis pesan commit
    cmp.setup.filetype("gitcommit", {
      sources = cmp.config.sources({
        { name = "git" },
      }, {
        { name = "buffer" },
      }),
    })
    require("cmp_git").setup()

    -- Use buffer source for `/` and `?` (if you enabled `native_menu`, this won't work anymore).
    -- autocomplete untuk pencarian buffer (window aktif)
    cmp.setup.cmdline({ "/", "?" }, {
      mapping = cmp.mapping.preset.cmdline(),
      sources = {
        { name = "buffer" },
      },
    })

    -- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
    -- Ini mengaktifkan autocomplete di command-line Neovim (:), seperti saat kamu mengetik :edit, :w, dll.
    cmp.setup.cmdline(":", {
      mapping = cmp.mapping.preset.cmdline(),
      sources = cmp.config.sources({
        { name = "path" },
      }, {
        { name = "cmdline" },
      }),
      matching = { disallow_symbol_nonprefix_matching = false },
    })

    -- Set up lspconfig.
    -- Ini memberi tahu LSP clangd (C/C++) bahwa Neovim mendukung fitur-fitur tambahan dari nvim-cmp
    local capabilities = require("cmp_nvim_lsp").default_capabilities()
    -- Replace <YOUR_LSP_SERVER> with each lsp server you've enabled.
    require("lspconfig")["clangd"].setup({
      capabilities = capabilities,
    })
  end,
}
```

Untuk penjelasan yang lebih detail, diberikan dua penjelasan, yang digenerate dari 2 AI. Aku terlalu lelah menulis ini semua 😪.

---
<br/>

# 3 | Dokumentasi Chat GPT

## Deskripsi Umum

Konfigurasi ini mengatur plugin `nvim-cmp` sebagai engine autocompletion di Neovim. Plugin ini digabungkan dengan berbagai sumber (LSP, buffer, path, cmdline) dan snippet engine `LuaSnip`.

## Blok 1: Deklarasi Plugin dan Dependencies

```lua
return {
  "hrsh7th/nvim-cmp",
  lazy = false,
  enabled = true,
  dependencies = {
    "neovim/nvim-lspconfig",
    "hrsh7th/cmp-nvim-lsp",
    "hrsh7th/cmp-buffer",
    "hrsh7th/cmp-path",
    "hrsh7th/cmp-cmdline",
    "L3MON4D3/LuaSnip",
    "saadparwaiz1/cmp_luasnip",
    "rafamadriz/friendly-snippets",
    "petertriho/cmp-git",
  },
```

**Penjelasan**:

- Menentukan plugin utama `nvim-cmp`.
    
- Menyertakan semua dependensi terkait auto-completion dari buffer, path, cmdline, LSP, Git, serta snippet engine LuaSnip.

## Blok 2: Konfigurasi Utama Plugin

```lua
config = function()
  vim.notify("✅ nvim-cmp berhasil terpasang", vim.log.levels.INFO)
  local cmp = require("cmp")
  local luasnip = require("luasnip")

  cmp.setup({
    snippet = {
      expand = function(args)
        require("luasnip").lsp_expand(args.body)
      end,
    },
```

**Penjelasan**:

- Menampilkan notifikasi saat plugin berhasil dimuat.
    
- Fungsi `expand` mengatur engine snippet menggunakan `LuaSnip`.


## Blok 3: Tampilan Window

```lua
    window = {
      completion = cmp.config.window.bordered(),
      documentation = cmp.config.window.bordered(),
    },
```

**Penjelasan**:

- Memberi border pada jendela autocompletion dan dokumentasi agar lebih mudah dibaca.
    
## Blok 4: Mapping Tombol

```lua
    mapping = cmp.mapping.preset.insert({
      ["<C-b>"] = cmp.mapping.scroll_docs(-4),
      ["<C-f>"] = cmp.mapping.scroll_docs(4),
      ["<C-Space>"] = cmp.mapping.complete(),
      ["<C-e>"] = cmp.mapping.abort(),

      ["<Tab>"] = cmp.mapping(function(fallback)
        if luasnip.expand_or_jumpable() then
          luasnip.expand_or_jump()
        else
          fallback()
        end
      end, { "i", "s" }),

      ["<S-Tab>"] = cmp.mapping(function(fallback)
        if luasnip.jumpable(-1) then
          luasnip.jump(-1)
        else
          fallback()
        end
      end, { "i", "s" }),

      ["<CR>"] = cmp.mapping(function(fallback)
        if cmp.visible() then
          cmp.confirm({ select = true })
        else
          fallback()
        end
      end, { "i", "s" }),
    }),
```

**Penjelasan**:

- Navigasi dokumen (`<C-b>/<C-f>`), memicu menu (`<C-Space>`), membatalkan (`<C-e>`).
    
- `<Tab>` dan `<S-Tab>` diprioritaskan untuk navigasi `LuaSnip`.
    
- `<CR>` hanya mengkonfirmasi suggestion jika popup terlihat.

## Blok 5: Sumber Completion

```lua
    sources = cmp.config.sources({
      { name = "luasnip" },
      { name = "nvim_lsp" },
      { name = "path" },
    }, {
      { name = "buffer" },
    }),
  })
```

**Penjelasan**:

- `luasnip`, `nvim_lsp`, dan `path` menjadi sumber utama.
    
- `buffer` sebagai fallback tambahan.

## Blok 6: Filetype Spesifik (Git)

```lua
  cmp.setup.filetype("gitcommit", {
    sources = cmp.config.sources({
      { name = "git" },
    }, {
      { name = "buffer" },
    }),
  })
  require("cmp_git").setup()
```

**Penjelasan**:

- Mengaktifkan sumber `git` saat menulis commit message.
    
- `cmp_git` perlu diinisialisasi manual.

## Blok 7: Completion untuk `/`, `?`, dan `:`

```lua
  cmp.setup.cmdline({ "/", "?" }, {
    mapping = cmp.mapping.preset.cmdline(),
    sources = {
      { name = "buffer" },
    },
  })

  cmp.setup.cmdline(":", {
    mapping = cmp.mapping.preset.cmdline(),
    sources = cmp.config.sources({
      { name = "path" },
    }, {
      { name = "cmdline" },
    }),
    matching = { disallow_symbol_nonprefix_matching = false },
  })
```

**Penjelasan**:

- Menyediakan auto-completion saat menggunakan `/` dan `?` (pencarian) menggunakan `buffer`.
    
- Saat mengetik perintah dengan `:`, menyarankan path dan perintah yang valid.

## Blok 8: Integrasi dengan LSP

```lua
  local capabilities = require("cmp_nvim_lsp").default_capabilities()
  require("lspconfig")["clangd"].setup({
    capabilities = capabilities,
  })
```

**Penjelasan**:

- Menambahkan kemampuan extra ke LSP agar mendukung `nvim-cmp`.
    
- Disiapkan untuk `clangd` (C/C++); bisa diganti dengan LSP lain.
    
## Catatan Tambahan

- Jika ingin menambahkan LSP lain, gunakan `require("lspconfig")["<nama-lsp>"].setup({ capabilities = capabilities })`
    
- Snippet tambahan dapat ditambahkan ke `friendly-snippets` atau didefinisikan secara manual.
    
- Mapping `<Tab>` diprioritaskan untuk `luasnip`, bukan pemilihan menu.
    
- Autocompletion tidak langsung memilih; navigasi pakai panah (`Up`/`Down`).

---
<br/>

# 4 | Dokumentasi Konfigurasi Auto-Completion (nvim-cmp) Neovim

Dokumen ini menjelaskan konfigurasi plugin `nvim-cmp` untuk auto-completion di Neovim, yang mencakup berbagai sumber penyelesaian (completion sources), pemetaan tombol (keybindings), dan integrasi dengan Language Server Protocol (LSP) serta snippet.

## 4.1 | Ikhtisar

Konfigurasi ini bertujuan untuk menyediakan pengalaman auto-completion yang kaya dan intuitif di Neovim. `nvim-cmp` adalah plugin fleksibel yang memungkinkan Anda menggabungkan berbagai sumber completion dan menyesuaikannya sesuai kebutuhan alur kerja Anda.
## 4.2 | Struktur Konfigurasi

Konfigurasi ini disajikan dalam format tabel spesifik Neovim, biasanya ditemukan di `init.lua` atau file konfigurasi plugin terpisah.


```lua
return {
  "hrsh7th/nvim-cmp",
  lazy = false,
  enabled = true,
  dependencies = {
    -- Daftar plugin yang dibutuhkan oleh nvim-cmp
    "neovim/nvim-lspconfig",
    "hrsh7th/cmp-nvim-lsp",
    "hrsh7th/cmp-buffer",
    "hrsh7th/cmp-path",
    "hrsh7th/cmp-cmdline",
    "L3MON4D3/LuaSnip",
    "saadparwaiz1/cmp_luasnip",
    "rafamadriz/friendly-snippets",
    "petertriho/cmp-git",
  },
  config = function()
    -- Log notifikasi saat nvim-cmp berhasil terpasang
    vim.notify("✅ nvim-cmp berhasil terpasang", vim.log.levels.INFO)
    -- Memuat modul cmp dan luasnip
    local cmp = require("cmp")
    local luasnip = require("luasnip")

    -- Pengaturan utama nvim-cmp
    cmp.setup({
      -- Konfigurasi snippet
      snippet = {
        expand = function(args)
          -- Menggunakan luasnip sebagai mesin snippet
          require("luasnip").lsp_expand(args.body)
        end,
      },
      -- Konfigurasi jendela pop-up completion
      window = {
        completion = cmp.config.window.bordered(),
        documentation = cmp.config.window.bordered(),
      },
      -- Pemetaan tombol
      mapping = cmp.mapping.preset.insert({
        ["<C-b>"] = cmp.mapping.scroll_docs(-4), -- Menggulir dokumentasi ke atas
        ["<C-f>"] = cmp.mapping.scroll_docs(4),  -- Menggulir dokumentasi ke bawah
        ["<C-Space>"] = cmp.mapping.complete(),  -- Memicu completion manual
        ["<C-e>"] = cmp.mapping.abort(),         -- Membatalkan completion

        -- Navigasi snippet dengan Tab
        ["<Tab>"] = cmp.mapping(function(fallback)
          if luasnip.expand_or_jumpable() then
            luasnip.expand_or_jump()
          else
            fallback()
          end
        end, { "i", "s" }),

        -- Navigasi snippet mundur dengan Shift-Tab
        ["<S-Tab>"] = cmp.mapping(function(fallback)
          if luasnip.jumpable(-1) then
            luasnip.jump(-1)
          else
            fallback()
          end
        end, { "i", "s" }),

        -- Konfirmasi completion atau pindah baris dengan Enter
        ["<CR>"] = cmp.mapping(function(fallback)
          if cmp.visible() then
            cmp.confirm({ select = true })
          else
            fallback()
          end
        end, { "i", "s" }),
      }),

      -- Sumber-sumber completion
      sources = cmp.config.sources({
        { name = "luasnip" },    -- Snippet dari LuaSnip
        { name = "nvim_lsp" },   -- Completion dari Language Server Protocol (LSP)
        { name = "path" },       -- Completion jalur file/direktori
      }, {
        { name = "buffer" },     -- Completion dari isi buffer saat ini
      }),
    })

    -- Konfigurasi khusus untuk filetype gitcommit
    cmp.setup.filetype("gitcommit", {
      sources = cmp.config.sources({
        { name = "git" },    -- Completion untuk perintah Git
      }, {
        { name = "buffer" }, -- Completion dari buffer
      }),
    })
    require("cmp_git").setup() -- Inisialisasi plugin cmp-git

    -- Konfigurasi completion untuk command-line (/) dan (?)
    cmp.setup.cmdline({ "/", "?" }, {
      mapping = cmp.mapping.preset.cmdline(),
      sources = {
        { name = "buffer" }, -- Completion dari buffer aktif
      },
    })

    -- Konfigurasi completion untuk command-line (:)
    cmp.setup.cmdline(":", {
      mapping = cmp.mapping.preset.cmdline(),
      sources = cmp.config.sources({
        { name = "path" },    -- Completion jalur file/direktori
      }, {
        { name = "cmdline" }, -- Completion dari riwayat command-line
      }),
      matching = { disallow_symbol_nonprefix_matching = false },
    })

    -- Pengaturan LSP (contoh untuk clangd)
    local capabilities = require("cmp_nvim_lsp").default_capabilities()
    require("lspconfig")["clangd"].setup({
      capabilities = capabilities,
    })
  end,
}
```

---

## 4.3 | Penjelasan Detail

### `lazy`, `enabled`, dan `dependencies`

- **`lazy = false`**: Menandakan bahwa plugin ini akan dimuat segera saat Neovim dimulai, tidak secara "lazy" (saat dibutuhkan). Ini penting untuk fungsi auto-completion yang harus selalu tersedia.
    
- **`enabled = true`**: Memastikan plugin `nvim-cmp` diaktifkan.
    
- **`dependencies`**: Daftar plugin yang dibutuhkan `nvim-cmp` untuk berfungsi dengan baik. Ini termasuk:
    
    - `neovim/nvim-lspconfig`: Konfigurasi dasar untuk Language Server Protocol (LSP) di Neovim.
        
    - `hrsh7th/cmp-nvim-lsp`: Sumber completion untuk LSP.
        
    - `hrsh7th/cmp-buffer`: Sumber completion dari kata-kata yang ada di buffer aktif.
        
    - `hrsh7th/cmp-path`: Sumber completion untuk jalur file dan direktori.
        
    - `hrsh7th/cmp-cmdline`: Sumber completion untuk baris perintah Neovim (misalnya `:e`, `:w`).
        
    - `L3MON4D3/LuaSnip`: Mesin snippet utama yang digunakan.
        
    - `saadparwaiz1/cmp_luasnip`: Integrasi `nvim-cmp` dengan `LuaSnip`.
        
    - `rafamadriz/friendly-snippets`: Kumpulan snippet siap pakai yang luas untuk `LuaSnip`.
        
    - `petertriho/cmp-git`: Sumber completion untuk Git (khususnya untuk pesan commit).
        

---

### `config = function()`

Bagian ini berisi semua logika konfigurasi `nvim-cmp` yang akan dieksekusi saat plugin dimuat.

#### Notifikasi

```lua
vim.notify("✅ nvim-cmp berhasil terpasang", vim.log.levels.INFO)
```

Ini akan menampilkan notifikasi di Neovim saat plugin `nvim-cmp` berhasil diinisialisasi, mempermudah debugging dan memastikan bahwa plugin aktif.

#### Inisialisasi Modul


```lua
local cmp = require("cmp")
local luasnip = require("luasnip")
```

Kode ini memuat modul `cmp` dan `luasnip`, sehingga fungsi-fungsi dari kedua plugin tersebut bisa digunakan dalam konfigurasi.

---

### `cmp.setup({})`

Ini adalah tabel konfigurasi utama untuk `nvim-cmp`.

#### `snippet`


```lua
snippet = {
  expand = function(args)
    require("luasnip").lsp_expand(args.body)
  end,
},
```

Bagian ini mengkonfigurasi bagaimana `nvim-cmp` menangani snippet. Fungsi `expand` diatur untuk menggunakan `luasnip.lsp_expand`, yang berarti saat `nvim-cmp` mendeteksi sebuah snippet, ia akan meminta `LuaSnip` untuk mengembangkannya.

#### `window`


```lua
window = {
  completion = cmp.config.window.bordered(),
  documentation = cmp.config.window.bordered(),
},
```

Ini mengatur tampilan jendela pop-up completion dan dokumentasi. `cmp.config.window.bordered()` menambahkan bingkai/border di sekitar jendela, membuatnya lebih rapi dan mudah dibaca.

#### `mapping` (Pemetaan Tombol)

Bagian ini mendefinisikan keybindings (pemetaan tombol) untuk berinteraksi dengan `nvim-cmp`.

- `["<C-b>"] = cmp.mapping.scroll_docs(-4)`: Menggulir jendela dokumentasi ke atas sebanyak 4 baris.
    
- `["<C-f>"] = cmp.mapping.scroll_docs(4)`: Menggulir jendela dokumentasi ke bawah sebanyak 4 baris.
    
- `["<C-Space>"] = cmp.mapping.complete()`: Secara manual memicu pop-up completion. Berguna jika auto-completion tidak muncul secara otomatis atau Anda ingin melihat semua opsi.
    
- `["<C-e>"] = cmp.mapping.abort()`: Membatalkan atau menutup jendela completion.
    
- **`<Tab>` untuk Navigasi Snippet dan Normal Fallback:**
    
    
    ```lua
    ["<Tab>"] = cmp.mapping(function(fallback)
      if luasnip.expand_or_jumpable() then
        luasnip.expand_or_jump()
      else
        fallback()
      end
    end, { "i", "s" }),
    ```
    
    Ketika Anda menekan `<Tab>`:
    
    - Jika kursor berada pada posisi di mana snippet bisa dikembangkan atau ada "slot" (placeholder) snippet yang bisa di-jump ke depan, `LuaSnip` akan melakukannya.
        
    - Jika tidak ada snippet yang bisa dikembangkan atau di-jump, `<Tab>` akan berfungsi seperti biasa (misalnya, menambahkan indentasi).
        
- **`<S-Tab>` (Shift+Tab) untuk Navigasi Snippet Mundur:**
    
    
    ```lua
    ["<S-Tab>"] = cmp.mapping(function(fallback)
      if luasnip.jumpable(-1) then
        luasnip.jump(-1)
      else
        fallback()
      end
    end, { "i", "s" }),
    ```
    
    Ketika Anda menekan `<S-Tab>`:
    
    - Jika ada "slot" snippet yang bisa di-jump ke belakang (sebelumnya), `LuaSnip` akan melompat ke sana.
        
    - Jika tidak, `<S-Tab>` akan berfungsi seperti biasa.
        
- **`<CR>` (Enter) untuk Konfirmasi Completion atau Newline:**
    
    
    ```lua
    ["<CR>"] = cmp.mapping(function(fallback)
      if cmp.visible() then
        cmp.confirm({ select = true })
      else
        fallback()
      end
    end, { "i", "s" }),
    ```
    
    Ketika Anda menekan `<CR>` (Enter):
    
    - Jika jendela completion `nvim-cmp` terlihat, Enter akan mengonfirmasi pilihan teratas (atau yang sedang disorot) dan menyisipkan completion tersebut. `select = true` memastikan item yang dipilih akan langsung disisipkan.
        
    - Jika jendela completion tidak terlihat, Enter akan berfungsi normal, yaitu membuat baris baru (newline).
        

#### `sources` (Sumber Completion)


```lua
sources = cmp.config.sources({
  { name = "luasnip" },    -- Snippet dari LuaSnip
  { name = "nvim_lsp" },   -- Completion dari Language Server Protocol (LSP)
  { name = "path" },       -- Completion jalur file/direktori
}, {
  { name = "buffer" },     -- Completion dari isi buffer saat ini
}),
```

Ini mendefinisikan sumber-sumber yang akan digunakan `nvim-cmp` untuk memberikan saran completion.

- **Grup Pertama (prioritas lebih tinggi):**
    
    - `luasnip`: Menyediakan snippet yang dikelola oleh `LuaSnip`.
        
    - `nvim_lsp`: Menyediakan saran completion dari Language Server (misalnya, nama variabel, fungsi, definisi tipe).
        
    - `path`: Menyediakan completion untuk jalur file dan direktori.
        
- **Grup Kedua (prioritas lebih rendah, dalam kasus ini, untuk buffer):**
    
    - `buffer`: Menyediakan completion dari kata-kata yang sudah ada di buffer (file) yang sedang Anda edit.
        

---

### Konfigurasi Spesifik `filetype` dan `cmdline`

#### `cmp.setup.filetype("gitcommit", ...)`


```lua
cmp.setup.filetype("gitcommit", {
  sources = cmp.config.sources({
    { name = "git" },
  }, {
    { name = "buffer" },
  }),
})
require("cmp_git").setup()
```

Ini adalah konfigurasi khusus yang hanya berlaku saat Anda mengedit file dengan `filetype` `gitcommit` (biasanya saat menulis pesan commit Git).

- Sumber `git` akan diaktifkan untuk memberikan saran yang relevan dengan Git (misalnya, branch, tag, dll.).
    
- Sumber `buffer` juga tetap aktif untuk completion dari isi commit sebelumnya.
    
- `require("cmp_git").setup()` menginisialisasi plugin `cmp-git`.
    

#### `cmp.setup.cmdline({ "/", "?" }, ...)`

```lua
cmp.setup.cmdline({ "/", "?" }, {
  mapping = cmp.mapping.preset.cmdline(),
  sources = {
    { name = "buffer" },
  },
})
```

Ini mengaktifkan auto-completion saat Anda mengetik di command-line setelah menekan `/` (untuk mencari ke depan) atau `?` (untuk mencari ke belakang). Saran completion akan berasal dari kata-kata yang ada di buffer aktif Anda.

#### `cmp.setup.cmdline(":", ...)`


```lua
cmp.setup.cmdline(":", {
  mapping = cmp.mapping.preset.cmdline(),
  sources = cmp.config.sources({
    { name = "path" },
  }, {
    { name = "cmdline" },
  }),
  matching = { disallow_symbol_nonprefix_matching = false },
})
```

Ini mengaktifkan auto-completion saat Anda mengetik perintah Neovim di command-line (setelah menekan `:`)

- Saran completion akan berasal dari:
    
    - `path`: Untuk jalur file (misalnya, saat mengetik `:e /path/to/file`).
        
    - `cmdline`: Untuk riwayat perintah Neovim yang pernah Anda ketik.
        
- `matching = { disallow_symbol_nonprefix_matching = false }`: Mengizinkan pencarian yang tidak harus dimulai dari awalan, memungkinkan pencarian yang lebih fleksibel.
    

---

### Pengaturan LSP (Language Server Protocol)


```lua
local capabilities = require("cmp_nvim_lsp").default_capabilities()
require("lspconfig")["clangd"].setup({
  capabilities = capabilities,
})
```

Bagian ini adalah integrasi `nvim-cmp` dengan Language Server Protocol (LSP).

- `local capabilities = require("cmp_nvim_lsp").default_capabilities()`: Mengambil kapabilitas default yang dibutuhkan oleh LSP untuk bekerja dengan `nvim-cmp`. Ini memberi tahu LSP bahwa Neovim mendukung fitur-fitur seperti completion, hover, dan tanda tangan (signature help) yang akan disediakan oleh `nvim-cmp`.

<br/>

- `require("lspconfig")["clangd"].setup({ capabilities = capabilities, })`: Ini adalah contoh konfigurasi untuk LSP `clangd` (untuk bahasa C/C++). Anda perlu mengganti `clangd` dengan server LSP yang Anda gunakan (misalnya `tsserver` untuk TypeScript, `pyright` untuk Python, dll.). Dengan menyertakan `capabilities = capabilities`, LSP akan sepenuhnya memanfaatkan fitur-fitur `nvim-cmp` untuk memberikan saran completion yang lebih cerdas dan kontekstual.
    

---

## 4.4 | Kesimpulan

Konfigurasi ini menyediakan sistem auto-completion yang komprehensif dan responsif di Neovim Anda, memanfaatkan kekuatan `nvim-cmp` untuk mengintegrasikan berbagai sumber completion seperti LSP, snippet, buffer, path, dan Git. Dengan pemetaan tombol yang intuitif, alur kerja Anda akan menjadi lebih efisien dan menyenangkan.

Semoga dokumentasi ini mudah dipahami dan membantu Anda dalam menggunakan Neovim!

---
<br/>

# 5 | Demo Hasil

Berikut adalah contoh ketika konfigurasi kita berhasil 😁:

![[20250728-1410-05.9037299.mp4]]