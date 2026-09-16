# 📚 IttaBook — Aplikasi Sistem Manajemen Perpustakaan (CLI)

**IttaBook** adalah aplikasi sistem manajemen dan peminjaman buku berbasis konsol (*Command Line Interface*) yang dikembangkan menggunakan bahasa pemrograman C.
Proyek ini dirancang secara terstruktur untuk mengelola data buku, data pengguna/anggota, transaksi peminjaman, serta dilengkapi dengan fitur validasi dan berkas teks pendukung (*file-handling*).

---

## 📑 Daftar Isi
1. [Fitur Utama](#-fitur-utama)
2. [Struktur Direktori](#-struktur-direktori)
3. [Daftar Komponen & Modul C](#-daftar-komponen--modul-c)
4. [Teknologi yang Digunakan](#-teknologi-yang-digunakan)
5. [Cara Menjalankan](#-cara-menjalankan)
6. [Catatan Tambahan](#-catatan-tambahan)


## 📑 Daftar Isi
- *🏠 Menu Beranda Konsol (main.c / tampilan.c)*: Memperkenalkan sistem navigasi perpustakaan, manajemen menu utama untuk admin dan anggota, serta ringkasan interaksi program.
- *📖 Manajemen Daftar Buku (daftar_buku.txt)*: Menyediakan pencatatan koleksi buku perpustakaan lengkap dengan penyimpanan data teks persisten (*file-handling*), informasi judul, dan status ketersediaan.
- *👥 Pengelolaan Data Pengguna & Akun (user.txt & data_orang.txt)*: Menampilkan manajemen data anggota, hak akses pengguna, serta registrasi profil peminjam buku.
- *🔄 Transaksi Peminjaman (data_peminjaman.txt & fungsi.c)*: Mencatat riwayat peminjaman dan pengembalian buku secara terstruktur melalui modul logika program berbasis C.
- *🛡️ Validasi & Diagram Alur (validasi.c & FLOWCHAT)*: Menggunakan sistem validasi input data yang ketat untuk mencegah kesalahan serta dokumentasi alur kerja sistem.

---

## 📂 Struktur Direktori

```plaintext
MIFTAHUL_REZKY_NITAMI/
│
├── index.html              # (Opsional/Aset web pendukung)
├── about.txt               # Informasi deskripsi proyek & pengembang
├── daftar_buku.txt         # Berkas basis data teks daftar buku perpustakaan
├── data_orang.txt          # Berkas basis data teks informasi anggota/pengguna
├── data_peminjaman.txt     # Berkas basis data teks catatan transaksi peminjaman
├── user.txt                # Berkas data akun/autentikasi pengguna sistem
├── FLOWCHAT MIFTAHUL REZKY NITAMI.drawio # Diagram alur program (Flowchart)
│
├── fungsi.c                # Logika inti dan fungsi-fungsi operasional program
├── main.c                  # Titik masuk utama eksekusi program (Main Function)
├── main.exe                # Berkas eksekusi biner hasil kompilasi program C
├── tampilan.c              # Modul antarmuka menu & tampilan visual konsol
└── validasi.c              # Modul penanganan error dan validasi input data
