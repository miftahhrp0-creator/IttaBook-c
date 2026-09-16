#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define handle GetStdHandle(STD_OUTPUT_HANDLE)
#define SILVER = 3
#define MAX_BUFFER 256
#define MAX_BARIS 13
#define MAX_BARIS_USER 8
#define MAX_BUKU_PER_PAGE 10

void tampilan_diawal();
void pilih();
void admin();
void about();
void berandadmin();
void beranda_user();
void peminjaman();
void pinnjam();
void pinbook();
void pinbookus();
void daftar_pin();
void pengembalian();
void kembalikan();
void daftar_peminjam();
void daftar_peminjam1();
void daftar_peminjamus();
void persediaan();
void tambah_buku();
void hapus_buku();
void tambah_stok();
void hapus();
void tampil_profil();
void back();
int cek_terdaftar(const char *nama);
void tampilkan_buku();
void txcolor(int new_color);
void profil_user();
void lihat_buku_dipinjam_user();
void user();
void daftar_user();
void lihat_buku_tersedia_user();
void logt();
void awal_user();
void admin();
void lihat_prodrad();
void gambar_menu(int tekan);
void keluar();

char filename[100];
char bul[][10] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
char nama[100];
char usia[100];
char nomor[100];
char email[100];
char id_buku[MAX_BUFFER];
char judul[MAX_BUFFER];
char penulis[MAX_BUFFER];
char stok_str[MAX_BUFFER];
char baris[MAX_BUFFER];
char press;
int stok;
int text, background;
int waktu;
int pilihan;
int ditemukan = 0;
int id;
char userAktif[20];
int index = 0;
int cari;


void txcolor(int new_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), new_color + text * 32);
    text = new_color;
}

void hapus()
{
    system("cls");
    bingkai(0, 0, 140, 35, 14, 9);
}

void back()
{
    gotoxy(64, 33);

    char esc[] = "PRESS ESC TO CONTINUE";

    for (int e = 0; esc[e] != '\0'; e++)
    {
        printf("%c", esc[e]);
        Sleep(20);
    }
}


void tampilkan_buku()
{
    FILE *ftampil = fopen("daftar_buku.txt", "r");
    char buffer[MAX_BUFFER];
    int y = 12; 

    if (ftampil == NULL)
    {
        gotoxy(60, 28);
        printf("Gagal membuka file.\n");
        return;
    }

    while (fgets(buffer, MAX_BUFFER, ftampil) != NULL)
    {
        char id[MAX_BUFFER], judul[MAX_BUFFER], penulis[MAX_BUFFER];
        int stok;

        sscanf(buffer, "%s\t%[^\t]\t%[^\t]\t%d", id, judul, penulis, &stok);

        gotoxy(40, y);
        printf("%s", id);
        gotoxy(48, y);
        printf("%s", judul);
        gotoxy(84, y);
        printf("%s", penulis);
        gotoxy(113, y);
        printf("%d", stok);

        y++; 
    }

    fclose(ftampil);
}

void persediaan()
{
    char pilih = 0;
    int p = 0;

    bingkaimipmip(161, 42, 0, 0);
    bingkaimipmip(161, 37, 0, 5);
    bingkaimipmip(30, 37, 0, 5);
    bingkaimipmip(21, 6, 4, 7);
    bingkaimipmip(21, 6, 4, 14);
    bingkaimipmip(21, 6, 4, 21);
    bingkaimipmip(21, 6, 4, 28);
    bingkaimipmip(21, 5, 4, 35);
    bingkaimipmip(10, 33, 35, 7);
    bingkaimipmip(30, 33, 110, 7);
    bingkaimipmip(120, 29, 35, 11);
    bingkaimipmip(120, 33, 35, 7);

    gotoxy(65, 2);
    printf(" P E R S E D I A A N   B U K U ");

    gotoxy(65, 3);
    printf("        i t t a b o o k       ");

    gotoxy(39, 9);
    printf("I D");

    gotoxy(50, 9);
    printf("J U D U L   B U K U");

    gotoxy(84, 9);
    printf("P E N U L I S ");

    gotoxy(113, 9);
    printf("STOK");

    tampilkan_buku();

    gotoxy(8, 9);
    printf("1.T A M B A H ");
    gotoxy(8, 10);
    printf("   B U K U    ");

    gotoxy(8, 16);
    printf("2.H A P U S ");
    gotoxy(8, 17);
    printf("   B U K U ");

    gotoxy(8, 23);
    printf("3.T A M B A H ");
    gotoxy(8, 24);
    printf("    S T O K   ");

    gotoxy(8, 30);
    printf("4.K E L U A R ");
    gotoxy(8, 31);
    printf("     >> << ");

    gotoxy(8, 37);
    printf(" P I L I H : ");

    while (p == 0)
    {
        gotoxy(20, 37);
        printf(" "); 

        gotoxy(20, 37);
        pilih = getch();

        gotoxy(20, 37);
        printf("%c", pilih);

        if (pilih == '1')
        {
            p = 1;
        }
        else if (pilih == '2')
        {
            p = 2;
        }
        else if (pilih == '3')
        {
            p = 3;
        }
        else if (pilih == '4')
        {
            p = 4;
        }
        else
        {
            gotoxy(8, 38);
            printf(" INVALID !! ");

            Sleep(800);

            gotoxy(8, 38);
            printf("            ");

            gotoxy(20, 37);
            printf(" ");
        }
    }

    if (p == 1)
    {
        hapus();
        tambah_buku();
    }
    else if (p == 2)
    {
        hapus();
        hapus_buku();
    }
    else if (p == 3)
    {
        hapus();
        tambah_stok();
    }
    else if (p == 4)
    {
        hapus();
        berandadmin();
    }
}

void tambah_stok()
{
    gambarbuku();
    gambarbuku2();
    char buffer[MAX_BUFFER];
    char temp_id[MAX_BUFFER];
    int stok_tambah;
    int found = 0;

    bingkaimipmip(70, 12, 43, 21);
    gotoxy(47, 22);
    printf("                        T A M B A H   S T O K                    ");
    gotoxy(46, 23);
    printf("_________________________________________________________________");
    gotoxy(47, 24);
    printf("  ID buku          : ");
    gotoxy(46, 25);
    printf("_________________________________________________________________");

    press = getch();
    if (press == 27)
    {
        hapus();
        persediaan();
    }

    gotoxy(68, 24);
    val_idbuku(id_buku);

    FILE *file = fopen("daftar_buku.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL)
    {
        gotoxy(60, 28);
        printf("belum ada buku\n");
        return;
    }

    while (fgets(buffer, MAX_BUFFER, file) != NULL)
    {
        sscanf(buffer, "%s", temp_id);
        if (strcmp(temp_id, id_buku) == 0)
        {
            found = 1;
            char judul[MAX_BUFFER], penulis[MAX_BUFFER];
            int stok;
            sscanf(buffer, "%s\t%[^\t]\t%[^\t]\t%d", temp_id, judul, penulis, &stok);

            gotoxy(47, 26);
            printf("  Jumlah Stok Tambahan : ");
            gotoxy(46, 27);
            printf("_________________________________________________________________");
            gotoxy(73, 26);
            scanf("%d", &stok_tambah);

            stok += stok_tambah;
            fprintf(temp, "%-4s\t%-20s\t%-20s\t%-4d\n", temp_id, judul, penulis, stok);
        }
        else
        {
            fputs(buffer, temp);
        }
    }

    fclose(file);
    fclose(temp);

    if (found)
    {
        file = fopen("daftar_buku.txt", "w");
        temp = fopen("temp.txt", "r");

        while (fgets(buffer, MAX_BUFFER, temp) != NULL)
        {
            fputs(buffer, file);
        }

        fclose(file);
        fclose(temp);
        gotoxy(55, 30);
        printf("Stok buku dengan ID %s berhasil ditambahkan.\n", id_buku);
    }
    else
    {
        gotoxy(55, 30);
        printf("Data buku dengan ID %s tidak ditemukan.\n", id_buku);
    }

    temp = fopen("temp.txt", "w");
    fclose(temp);
    remove("temp.txt");

    hapus();
    persediaan();
}

void hapus_buku()
{
    gambarbuku();
    gambarbuku2();
    char id_buku[MAX_BUFFER];
    char buffer[MAX_BUFFER];
    char *token;
    int found = 0;

    bingkaimipmip(70, 10, 43, 21);
    gotoxy(47, 22);
    printf("                        H A P U S   B U K U                   ");
    gotoxy(46, 23);
    printf("_________________________________________________________________");
    gotoxy(47, 24);
    printf("  ID buku          : ");
    gotoxy(46, 25);
    printf("_________________________________________________________________");

    press = getch();
    if (press == 27)
    {
        hapus();
        persediaan();
    }

    gotoxy(68, 24);
    val_idbuku(id_buku);

    FILE *fdelete = fopen("daftar_buku.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fdelete == NULL || temp == NULL)
    {
        gotoxy(60, 28);
        printf("Gagal membuka file.\n");
        return;
    }

    while (fgets(buffer, MAX_BUFFER, fdelete) != NULL)
    {
        char temp_id[MAX_BUFFER];
        sscanf(buffer, "%s", temp_id);
        if (strcmp(temp_id, id_buku) != 0)
        {
            fputs(buffer, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fdelete);
    fclose(temp);

    if (found)
    {
        fdelete = fopen("daftar_buku.txt", "w");
        temp = fopen("temp.txt", "r");

        while (fgets(buffer, MAX_BUFFER, temp) != NULL)
        {
            fputs(buffer, fdelete);
        }

        fclose(fdelete);
        fclose(temp);
        gotoxy(60, 28);
        printf("Data buku dengan ID %s berhasil dihapus.\n", id_buku);
        getch(); 
        hapus();
        persediaan();
    }
    else
    {
        gotoxy(60, 28);
        printf("Data buku dengan ID %s tidak ditemukan.\n", id_buku);
        getch();
        hapus();
        hapus_buku();
    }

    temp = fopen("temp.txt", "w");
    fclose(temp);
    remove("temp.txt");

    hapus();
    persediaan();
}

void tambah_buku()
{
    gambarbuku3();
    gambarbuku2();
    char tanya;
    FILE *faddbuku = fopen("daftar_buku.txt", "a");

    bingkaimipmip(70, 13, 43, 21);
    gotoxy(47, 22);
    printf("                        T A M B A H   B U K U                   ");
    gotoxy(46, 23);
    printf("_________________________________________________________________");
    gotoxy(47, 24);
    printf("  ID buku          : ");
    gotoxy(46, 25);
    printf("_________________________________________________________________");
    gotoxy(47, 26);
    printf("  Judul buku       : ");
    gotoxy(46, 27);
    printf("_________________________________________________________________");
    gotoxy(47, 28);
    printf("  Penulis          : ");
    gotoxy(46, 29);
    printf("_________________________________________________________________");
    gotoxy(47, 30);
    printf("  Jumlah Stok     : ");
    gotoxy(46, 31);
    printf("_________________________________________________________________");

    press = getch();
    if (press == 27)
    {
        hapus();
        persediaan();
    }

    gotoxy(68, 24);
    val_idbuku(id_buku);
    gotoxy(68, 26);
    val_judul(judul);
    gotoxy(68, 28);
    val_penulis(penulis);
    gotoxy(68, 30);
    val_stok(stok_str);

    fprintf(faddbuku, "%-4s\t%-20s\t%-20s\t%-4s\n", id_buku, judul, penulis, stok_str);
    fclose(faddbuku);

    gotoxy(63, 33);
    printf("Ingin menambah buku lagi? (Y/T): ");

    while (1)
    {
        tanya = getch();
        if (tanya == 'Y' || tanya == 'y')
        {
            hapus();
            tambah_buku();
            break;
        }
        else if (tanya == 'T' || tanya == 't')
        {
            hapus();
            persediaan();
            break;
        }
        else
        {
            gotoxy(60, 33);
            printf("Input tidak valid! Masukkan Y atau T: ");
        }
    }
}

int cek_terdaftar(const char *nama)
{
    FILE *file = fopen("data_orang.txt", "r");
    char baris[MAX_BUFFER];
    char cari_str[MAX_BUFFER];
    int ditemukan = 0;   

    if (file == NULL)
    {
        return 0;
    }

    snprintf(cari_str, sizeof(cari_str), "Nama Lengkap : %s", nama);

    while (fgets(baris, sizeof(baris), file))
    {
        if (strstr(baris, cari_str) != NULL)
        {
            ditemukan = 1;
            break;
        }
    }

    fclose(file);
    return ditemukan;
}

void pinbook()
{
    tamp_pemjam();
    bingkaimipmip(70, 10, 43, 23);

    time_t sekarang = time(NULL);
    struct tm t_pinjam = *localtime(&sekarang);

    time_t tenggat_time = sekarang + (7 * 24 * 60 * 60);
    struct tm t_tenggat = *localtime(&tenggat_time);

    FILE *fbuku, *temp, *fpinjam;

    char baris[MAX_BUFFER];
    char temp_id[MAX_BUFFER];
    char judul[MAX_BUFFER];
    char penulis[MAX_BUFFER];

    int stok;
    int buku_ditemukan = 0;

    gotoxy(47, 26);
    printf("Nama Lengkap : ");
    gotoxy(67, 26);
    val_nama(nama);

    if (!cek_terdaftar(nama))
    {
        gotoxy(60, 30);
        printf("ANDA BELUM TERDAFTAR!");
        Sleep(2000);
        hapus();
        daftar_peminjam();
        return;
    }

    gotoxy(47, 28);
    printf("ID Buku      : ");
    gotoxy(67, 28);
    val_idpinbuku(id_buku);

    fbuku = fopen("daftar_buku.txt", "r");
    temp = fopen("temp.txt", "w");

    if (!fbuku || !temp)
    {
        gotoxy(60, 30);
        printf("File buku gagal dibuka!");
        return;
    }

    while (fgets(baris, sizeof(baris), fbuku))
    {
        sscanf(baris, "%s\t%[^\t]\t%[^\t]\t%d",
               temp_id, judul, penulis, &stok);

        if (strcmp(temp_id, id_buku) == 0)
        {
            buku_ditemukan = 1;

            if (stok > 0)
            {
                stok--;
            }
            else
            {
                gotoxy(60, 30);
                printf("STOK HABIS!");
                fclose(fbuku);
                fclose(temp);
                remove("temp.txt");
                Sleep(2000);
                return;
            }
        }

        fprintf(temp, "%s\t%s\t%s\t%d\n",
                temp_id, judul, penulis, stok);
    }

    fclose(fbuku);
    fclose(temp);

    if (!buku_ditemukan)
    {
        gotoxy(60, 30);
        printf("ID buku tidak ditemukan!");
        remove("temp.txt");
        Sleep(2000);
        return;
    }

    remove("daftar_buku.txt");
    rename("temp.txt", "daftar_buku.txt");

    fpinjam = fopen("data_peminjaman.txt", "a");

    if (fpinjam)
    {
        fprintf(fpinjam,
        "Nama : %s || ID : %s || Judul : %s || Pinjam : %02d/%02d/%d || Tenggat : %02d/%02d/%d\n",
        nama,
        id_buku,
        judul,
        t_pinjam.tm_mday,
        t_pinjam.tm_mon + 1,
        t_pinjam.tm_year + 1900,
        t_tenggat.tm_mday,
        t_tenggat.tm_mon + 1,
        t_tenggat.tm_year + 1900);

        fclose(fpinjam);
    }

    gotoxy(60, 34);
    printf("PEMINJAMAN BERHASIL!");

    Sleep(2000);
    hapus();
    berandadmin();
}

void pinbookus()
{
    tamp_pemjam();
    bingkaimipmip(70, 10, 43, 23);

    time_t sekarang = time(NULL);
    struct tm t_pinjam = *localtime(&sekarang);

    time_t tenggat_time = sekarang + (7 * 24 * 60 * 60);
    struct tm t_tenggat = *localtime(&tenggat_time);

    FILE *fbuku, *temp, *fpinjam;

    char baris[MAX_BUFFER];
    char temp_id[MAX_BUFFER];
    char judul[MAX_BUFFER];
    char penulis[MAX_BUFFER];

    int stok;
    int buku_ditemukan = 0;

    gotoxy(47, 26);
    printf("Nama Lengkap : ");
    gotoxy(67, 26);
    val_nama(nama);

    if (!cek_terdaftar(nama))
    {
        gotoxy(60, 30);
        printf("ANDA BELUM TERDAFTAR!");
        Sleep(2000);
        hapus();
        daftar_peminjam();
        return;
    }

    gotoxy(47, 28);
    printf("ID Buku      : ");
    gotoxy(67, 28);
    val_idpinbuku(id_buku);

    fbuku = fopen("daftar_buku.txt", "r");
    temp = fopen("temp.txt", "w");

    if (!fbuku || !temp)
    {
        gotoxy(60, 30);
        printf("File buku gagal dibuka!");
        return;
    }

    while (fgets(baris, sizeof(baris), fbuku))
    {
        sscanf(baris, "%s\t%[^\t]\t%[^\t]\t%d",
               temp_id, judul, penulis, &stok);

        if (strcmp(temp_id, id_buku) == 0)
        {
            buku_ditemukan = 1;

            if (stok > 0)
            {
                stok--;
            }
            else
            {
                gotoxy(60, 30);
                printf("STOK HABIS!");
                fclose(fbuku);
                fclose(temp);
                remove("temp.txt");
                Sleep(2000);
                return;
            }
        }

        fprintf(temp, "%s\t%s\t%s\t%d\n",
                temp_id, judul, penulis, stok);
    }

    fclose(fbuku);
    fclose(temp);

    if (!buku_ditemukan)
    {
        gotoxy(60, 30);
        printf("ID buku tidak ditemukan!");
        remove("temp.txt");
        Sleep(2000);
        return;
    }

    remove("daftar_buku.txt");
    rename("temp.txt", "daftar_buku.txt");

    fpinjam = fopen("data_peminjaman.txt", "a");

    if (fpinjam)
    {
        fprintf(fpinjam,
        "Nama : %s || ID : %s || Judul : %s || Pinjam : %02d/%02d/%d || Tenggat : %02d/%02d/%d\n",
        nama,
        id_buku,
        judul,
        t_pinjam.tm_mday,
        t_pinjam.tm_mon + 1,
        t_pinjam.tm_year + 1900,
        t_tenggat.tm_mday,
        t_tenggat.tm_mon + 1,
        t_tenggat.tm_year + 1900);

        fclose(fpinjam);
    }

    gotoxy(60, 32);
    printf("PEMINJAMAN BERHASIL!");

    Sleep(2000);
    hapus();
    beranda_user();
}

void daftar_pin()
{
    FILE *fpinjam = fopen("data_peminjaman.txt", "r");
    char baris[MAX_BUFFER];
    int current_y = 1; 

    if (fpinjam == NULL)
    {
        printf("Tidak dapat membuka file data_peminjaman.txt\n");
        hapus();
        peminjaman();
    }

    gotoxy(2, current_y);
    while (fgets(baris, sizeof(baris), fpinjam))
    {
        gotoxy(2, current_y);
        printf("%s", baris);
        current_y++;
    }

    fclose(fpinjam);

    press = getch();
    back();
    if (press == 27)
    {
        hapus();
        berandadmin();
    }
}

void pinnjam()
{
    char menu[2][30] = {"PEMINJAMAN BUKU", "DAFTAR PINJAM"};
    int pilih = 0;
    int tombol;

    tamp_peminjaman();

    while (1)
    {
        bingkaimipmip(25, 5, 50, 28);
        bingkaimipmip(25, 5, 90, 28);

        if (pilih == 0)
        {
            txcolor(11);
            gotoxy(55, 30);
            printf("%s", menu[0]);

            txcolor(7);
            gotoxy(96, 30);
            printf("%s", menu[1]);
        }
        else
        {
            txcolor(7);
            gotoxy(55, 30);
            printf("%s", menu[0]);

            txcolor(11);
            gotoxy(96, 30);
            printf("%s", menu[1]);
        }

        txcolor(7);

        tombol = getch();

        if (tombol == 0 || tombol == 224)
        {
            tombol = getch();

            if (tombol == 77 && pilih < 1) pilih++;
            if (tombol == 75 && pilih > 0) pilih--;
        }

        else if (tombol == 13)
        {
            hapus();

            if (pilih == 0)
            {
                pinbookus();
            }
            else
            {
                daftar_peminjamus();
            }

            return;
        }

        else if (tombol == 27)
        {
            hapus();
            beranda_user();
            return;
        }
    }
}

void peminjaman()
{
    char pinjam[2][100] = {"PEMINJAMAN BUKU", "DAFTAR PINJAM"};
    int pilih = 0;
    int tombol;

    tamp_peminjaman();
    bukk();
    bukk1();

    while (1)
    {
        bingkaimipmip(25, 5, 50, 28);
        bingkaimipmip(25, 5, 90, 28);

        gotoxy(52, 30);
        if (pilih == 0)
        {
            txcolor(14);
            printf(">> %s <<", pinjam[0]);
        }
        else
        {
            txcolor(9);
            printf("   %s   ", pinjam[0]);
        }

        gotoxy(93, 30);
        if (pilih == 1)
        {
            txcolor(14);
            printf(">> %s <<", pinjam[1]);
        }
        else
        {
            txcolor(9);
            printf("   %s   ", pinjam[1]);
        }

        txcolor(7); 

        tombol = getch();

        if (tombol == 0 || tombol == 224)
        {
            tombol = getch();

            if (tombol == 77)  
            {
                pilih++;
                if (pilih > 1) pilih = 0;  
            }
            else if (tombol == 75) 
            {
                pilih--;
                if (pilih < 0) pilih = 1;  
            }
        }
        else if (tombol == 13) 
        {
            hapus();

            if (pilih == 0)
                pinbook();
            else
                daftar_peminjam();

            return;
        }
    }
    back();
}


void pengembalian()
{
    FILE *fpinjam, *ftemp;
    char baris[MAX_BUFFER];
    char namaCari[MAX_BUFFER];
    char idCari[MAX_BUFFER];
    int ditemukan = 0;

    tamp_pengembalian();
    bingkaimipmip(100, 20, 20, 10);

    gotoxy(35, 13);
    printf("Masukkan Nama Peminjam : ");
    fflush(stdin);
    scanf(" %[^\n]", namaCari);

    gotoxy(35, 15);
    printf("Masukkan ID Buku       : ");
    fflush(stdin);
    scanf(" %[^\n]", idCari);

    fpinjam = fopen("data_peminjaman.txt", "r");
    ftemp = fopen("temp.txt", "w");

    if (fpinjam == NULL)
    {
        gotoxy(35, 17);
        printf("File peminjaman tidak ditemukan!");
        getch();
        return;
    }

    while (fgets(baris, sizeof(baris), fpinjam))
    {
        if (strstr(baris, namaCari) && strstr(baris, idCari))
        {
            ditemukan = 1;
            gotoxy(35, 17);
            printf("Buku berhasil dikembalikan!");
        }
        else
        {
            fputs(baris, ftemp);
        }
    }

    fclose(fpinjam);
    fclose(ftemp);

    remove("data_peminjaman.txt");
    rename("temp.txt", "data_peminjaman.txt");

    if (!ditemukan)
    {
        gotoxy(35, 17);
        printf("Data tidak ditemukan!");
    }

    back();
    getch();
    hapus();
    berandadmin();
}

void profil_user()
{
    FILE *fp;
    char baris[MAX_BUFFER];
    char nama_file[MAX_BUFFER];

    int tampil = 0;
    int y = 15;

    userAktif[strcspn(userAktif, "\r\n")] = '\0';

    hapus();
    bingkaimipmip(70, 15, 35, 10);

    gotoxy(55, 12);
    printf("P R O F I L   A N D A");

    fp = fopen("data_orang.txt", "r");

    if (fp == NULL)
    {
        gotoxy(55, 20);
        printf("Data profil tidak ditemukan!");
        getch();
        hapus();
        beranda_user();
        return;
    }

    while (fgets(baris, MAX_BUFFER, fp))
    {
        int i = 0, j = 0;

        if (baris[0]=='N' && baris[1]=='a' && baris[2]=='m')
        {
            while (baris[i] != ':' && baris[i] != '\0')
                i++;

            if (baris[i] == ':')
                i += 2;

            while (baris[i] != '\n' && baris[i] != '\0')
            {
                nama_file[j] = baris[i];
                i++;
                j++;
            }

            nama_file[j] = '\0';

            if (strcmp(nama_file, userAktif) == 0)
            {
                tampil = 1;
            }
            else
            {
                tampil = 0;
            }
        }

        if (tampil == 1)
        {
            gotoxy(45, y);
            printf("%s", baris);
            y++;

            if (baris[0]=='-' && baris[1]=='-')
                break;
        }
    }

    fclose(fp);

    if (tampil == 0)
    {
        gotoxy(55, 20);
        printf("Profil anda belum terdaftar!");
    }

    back();
    getch();

    hapus();
    beranda_user();
}

void lihat_buku_dipinjam_user()
{
    FILE *fp;
    char baris[MAX_BUFFER];
    char nama_file[MAX_BUFFER];

    char dataUser[200][MAX_BUFFER];
    int totalBaris = 0;

    int page = 0;
    int totalPage;
    int i, j;
    char key;

    hapus();
    bingkaimipmip(110, 18, 15, 10);

    gotoxy(45, 12);
    printf("B U K U   Y A N G   A N D A   P I N J A M");

    if (strlen(userAktif) == 0)
    {
        gotoxy(45, 18);
        printf("User tidak valid!");
        getch();
        beranda_user();
        return;
    }

    fp = fopen("data_peminjaman.txt", "r");

    if (fp == NULL)
    {
        gotoxy(50, 18);
        printf("Tidak ada data peminjaman!");
        getch();
        beranda_user();
        return;
    }

    while (fgets(baris, sizeof(baris), fp) != NULL)
    {
        if (strncmp(baris, "Nama : ", 7) == 0)
        {
            i = 7;
            j = 0;

            while (baris[i] != '|' &&
                   baris[i] != '\n' &&
                   baris[i] != '\0' &&
                   j < MAX_BUFFER - 1)
            {
                nama_file[j++] = baris[i++];
            }

            nama_file[j] = '\0';

            while (j > 0 && (nama_file[j-1] == ' ' || nama_file[j-1] == '\r'))
            {
                nama_file[--j] = '\0';
            }

            if (strcmp(nama_file, userAktif) == 0)
            {
                strcpy(dataUser[totalBaris++], baris);
            }
        }
    }

    fclose(fp);

    if (totalBaris == 0)
    {
        gotoxy(45, 18);
        printf("Anda belum meminjam buku apapun.");
        getch();
        hapus();
        beranda_user();
        return;
    }

    totalPage = (totalBaris + MAX_BARIS_USER - 1) / MAX_BARIS_USER;

    while (1)
    {
        int y = 15;
        int start = page * MAX_BARIS_USER;
        int end = start + MAX_BARIS_USER;

        if (end > totalBaris)
            end = totalBaris;

        for (i = 15; i <= 25; i++)
        {
            gotoxy(20, i);
            printf("%-90s", "");
        }

        for (i = start; i < end; i++)
        {
            gotoxy(20, y++);
            printf("%-90s", dataUser[i]);
        }

        gotoxy(80, 30);
        printf("Halaman %d / %d  ( <- Kiri | Kanan -> | ESC )",
               page + 1, totalPage);

        key = getch();

        if (key == 27) 
        {
            break;
        }
        else if (key == 77 && page < totalPage - 1)
        {
            page++;
        }
        else if (key == 75 && page > 0)
        {
            page--;
        }
    }

    hapus();
    beranda_user();
}



void user()
{
   rak(); 
   rak1();
   rak2();
    FILE *mipmip;
    char username[20], password[20];
    char fileUser[20], filePass[20];
    int limit = 0;

    int dex = 0;
    tamp_logus();
    bingkaimipmip(35 , 6, 60, 23);

    do
    {
        int x = 0;
        int found = 0;

        gotoxy(63, 24);
        printf("USERNAME   : ");
        
        gotoxy(76, 24);
        val_userlog(username);   

        gotoxy(63, 26);
        printf("PASSWORD   : ");
        gotoxy(76, 26);

        while ((password[x] = getch()) != 13)
        {
            if (password[x] == 8)
            {
                x--;
                if (x < 0) x = 0;
                gotoxy(76 + x, 26);
                printf(" ");
            }
            else if (isalnum(password[x]))
            {
                printf("*");
                x++;
            }

            if (x > 8) x = 8;
            gotoxy(76 + x, 26);
        }
        password[x] = '\0';

        mipmip = fopen("user.txt", "r");
        if (mipmip == NULL)
        {
            gotoxy(60, 33);
            printf("File user tidak ditemukan!");
            Sleep(1000);
            hapus();
            daftar_user();
            
        }

        while (fscanf(mipmip, "%s %s", fileUser, filePass) != EOF)
        {
            if (strcmp(username, fileUser) == 0 &&
                strcmp(password, filePass) == 0)
            {
                found = 1;
                break;
            }
        }
        fclose(mipmip);

        if (found)
        {
            strcpy(userAktif, username);  

            hapus();
            beranda_user();
        }

        else
        {
            gotoxy(63, 31);
            printf("Username / Password salah!");
            Sleep(400);
            gotoxy(63, 31);
            printf("                          ");
            Sleep(400);

            limit++;
            gotoxy(76, 24); printf("            ");
            gotoxy(76, 26); printf("            ");
        }

    } while (limit < 3);

    gotoxy(68, 34);
    printf("Kesempatan habis!");
    Sleep(600);

    for (int a = 5; a > 0; a--)
    {
        gotoxy(58, 36);
        printf("Tunggu %d detik untuk kembali mengakses", a);
        Sleep(1000);
    }

    hapus();
    daftar_user();
}



void daftar_user()
{
    bukk();
    FILE *fp;
    char username[20], password[20];
    char cekUser[20], cekPass[20];
    int limit = 0;
    int ada;

    tamp_dagus();
    bingkaimipmip(50 , 8, 50, 22);

    do
    {
        ada = 0;

        gotoxy(53, 24);
        printf("USERNAME  : ");
        gotoxy(65, 24);
        val_userlog(username);

        fp = fopen("user.txt", "r");

        if (fp != NULL)
        {
            while (fscanf(fp, "%s %s", cekUser, cekPass) != EOF)
            {
                if (strcmp(username, cekUser) == 0)
                {
                    ada = 1;
                    break;
                }
            }

            fclose(fp); 
        }

        if (ada == 1)
        {
            gotoxy(60, 31);
            printf("Username sudah terdaftar!");
            Sleep(600);

            gotoxy(60, 31);
            printf("                         ");

            gotoxy(80, 24);
            printf("            ");

            limit = limit + 1;
        }
        else
        {
            gotoxy(53, 26);
            printf("PASSWORD  : ");
            gotoxy(65, 26);
            val_paslog(password);

            fp = fopen("user.txt", "a");

            if (fp != NULL)
            {
                fprintf(fp, "%s %s\n", username, password);
                fclose(fp); 
            }

            gotoxy(65, 34);
            printf("<< DAFTAR BERHASIL >>");
            Sleep(500);

            gotoxy(65, 34);
            printf("                     ");
            Sleep(500);

            gotoxy(65, 34);
            printf("<< DAFTAR BERHASIL >>");
            Sleep(500);

            hapus();
            user();
            return;
        }

    }
    while (limit < 3);

    gotoxy(65, 34);
    printf("Pendaftaran dibatalkan!");
    Sleep(600);

    hapus();
    pilih();
}

void kembalikan()
{
    FILE *fpinjam, *ftemp;
    char baris[MAX_BUFFER];
    char namaCari[MAX_BUFFER];
    char idCari[MAX_BUFFER];
    int ditemukan = 0;

    tamp_pengembalian();
    bingkaimipmip(100, 20, 20, 10);

    gotoxy(35, 13);
    printf("Masukkan Nama Peminjam : ");
    fflush(stdin);
    scanf(" %[^\n]", namaCari);

    gotoxy(35, 15);
    printf("Masukkan ID Buku       : ");
    fflush(stdin);
    scanf(" %[^\n]", idCari);

    fpinjam = fopen("data_peminjaman.txt", "r");
    ftemp = fopen("temp.txt", "w");

    if (fpinjam == NULL)
    {
        gotoxy(35, 17);
        printf("File peminjaman tidak ditemukan!");
        getch();
        return;
    }

    while (fgets(baris, sizeof(baris), fpinjam))
    {
        if (strstr(baris, namaCari) && strstr(baris, idCari))
        {
            ditemukan = 1;
            gotoxy(35, 17);
            printf("Buku berhasil dikembalikan!");
        }
        else
        {
            fputs(baris, ftemp);
        }
    }

    fclose(fpinjam);
    fclose(ftemp);

    remove("data_peminjaman.txt");
    rename("temp.txt", "data_peminjaman.txt");

    if (!ditemukan)
    {
        gotoxy(35, 17);
        printf("Data tidak ditemukan!");
    }

    back();
    getch();
    hapus();
    beranda_user();
}

void lihat_buku_tersedia_user()
{
    FILE *fbuku;
    char baris[MAX_BUFFER];
    char data[500][MAX_BUFFER];

    int totalData = 0;
    int page = 0;
    int dataPerPage = 10;
    int totalPage;
    int key;

    fbuku = fopen("daftar_buku.txt", "r");

    if (fbuku == NULL)
    {
        gotoxy(55, 22);
        printf("Data buku tidak ditemukan!");
        getch();
        hapus();
        beranda_user();
        return;
    }

    // Simpan hanya buku yang stoknya > 0
    while (fgets(baris, sizeof(baris), fbuku))
    {
        char id[MAX_BUFFER];
        char judul[MAX_BUFFER];
        char penulis[MAX_BUFFER];
        int stok;

        if (sscanf(baris, "%s\t%[^\t]\t%[^\t]\t%d",
                   id, judul, penulis, &stok) == 4)
        {
            if (stok > 0 && totalData < 500)
            {
                strcpy(data[totalData], baris);
                totalData++;
            }
        }
    }

    fclose(fbuku);

    if (totalData == 0)
    {
        gotoxy(55, 22);
        printf("Tidak ada buku tersedia!");
        getch();
        hapus();
        beranda_user();
        return;
    }

    totalPage = (totalData + dataPerPage - 1) / dataPerPage;

    while (1)
    {
        int y = 20;
        int start = page * dataPerPage;
        int end = start + dataPerPage;

        if (end > totalData)
            end = totalData;

        hapus();
        bingkaimipmip(140, 35, 0, 0);

        bingkaimipmip(60, 6, 45, 8);
        gotoxy(55, 10);
        printf("D A F T A R   B U K U   T E R S E D I A");

        bingkaimipmip(88, 5, 30, 13);

        gotoxy(44, 15);  printf("ID");
        gotoxy(60, 15);  printf("JUDUL");
        gotoxy(80, 15);  printf("PENULIS");
        gotoxy(100, 15); printf("STOK");

        bingkaimipmip(88, 14, 30, 17);

        for (int i = start; i < end; i++)
        {
            char id[MAX_BUFFER];
            char judul[MAX_BUFFER];
            char penulis[MAX_BUFFER];
            int stok;

            sscanf(data[i], "%s\t%[^\t]\t%[^\t]\t%d",
                   id, judul, penulis, &stok);

            gotoxy(40, y);  printf("%s", id);
            gotoxy(60, y);  printf("%s", judul);
            gotoxy(80, y);  printf("%s", penulis);
            gotoxy(100, y); printf("%d", stok);
            y++;
        }

        gotoxy(65, 32);
        printf("Halaman %d dari %d", page + 1, totalPage);

        gotoxy(45, 6);
        printf("<- Sebelumnya | Berikutnya -> | ESC Keluar");

        key = getch();

        if (key == 0 || key == 224)
        {
            key = getch();

            if (key == 77 && page < totalPage - 1)  // Panah kanan
                page++;
            else if (key == 75 && page > 0)         // Panah kiri
                page--;
        }
        else if (key == 27) // ESC
        {
            break;
        }
    }

    hapus();
    beranda_user();
}

void logt()
{
    hapus();
    pilih();
}

void daftar_peminjam()
{
    back();
    FILE *orang;
    int ditemukan;

    tamp_dafjam();
    bingkaimipmip(70, 12, 43, 21);

    gotoxy(47, 22);
    printf("                            ISI DATA                             ");
    gotoxy(46, 23);
    printf("_________________________________________________________________");
    gotoxy(47, 24);
    printf("  Nama Lengkap    : ");
    gotoxy(46, 25);
    printf("_________________________________________________________________");
    gotoxy(47, 26);
    printf("  Usia            : ");
    gotoxy(46, 27);
    printf("_________________________________________________________________");
    gotoxy(47, 28);
    printf("  No Ponsel       : ");
    gotoxy(46, 29);
    printf("_________________________________________________________________");
    gotoxy(47, 30);
    printf("  Email Anda      : ");
    gotoxy(46, 31);
    printf("_________________________________________________________________");

    back();
    press = getch();

    if (press == 27)
    {
        hapus();
        peminjaman();
        return;
    }

    gotoxy(67, 24);
    val_nama(nama);

    ditemukan = cek_terdaftar(nama);

    if (ditemukan == 1)
    {
        bingkaitata(43, 20, 66, 13);

        gotoxy(64, 26);
        printf("   NAMA SUDAH TERDAFTAR    ");

        gotoxy(64, 27);
        printf("TIDAK DAPAT MENDAFTAR LAGI!");

        Sleep(4000);

        hapus();
        berandadmin();
        return;
    }

    gotoxy(67, 26);
    val_usia(usia);

    gotoxy(67, 28);
    val_nomor(nomor);

    gotoxy(67, 30);
    val_email(email);

    orang = fopen("data_orang.txt", "a");

    if (orang != NULL)
    {
        fprintf(orang, "Nama Lengkap : %s\n", nama);
        fprintf(orang, "Usia         : %s\n", usia);
        fprintf(orang, "No Ponsel    : %s\n", nomor);
        fprintf(orang, "Email Anda   : %s\n", email);
        fprintf(orang, "--------------------------------\n");

        fclose(orang);
    }
    else
    {
        gotoxy(65, 33);
        printf("Gagal menyimpan data!");
        Sleep(2000);

        hapus();
        berandadmin();
        return;
    }

    gotoxy(63, 33);
    printf("<< PENDAFTARAN BERHASIL >>");

    Sleep(500);

    gotoxy(63, 33);
    printf("                          ");

    Sleep(500);

    gotoxy(63, 33);
    printf("<< PENDAFTARAN BERHASIL >>");

    Sleep(500);

    gotoxy(63, 33);
    printf("                          ");

    hapus();
    berandadmin();
}

void daftar_peminjam1()
{
    FILE *orang;
    int ditemukan;

    tamp_dafjam();
    bingkaimipmip(70, 12, 43, 21);

    gotoxy(47, 22);
    printf("                            ISI DATA                             ");
    gotoxy(46, 23);
    printf("_________________________________________________________________");
    gotoxy(47, 24);
    printf("  Nama Lengkap    : ");
    gotoxy(46, 25);
    printf("_________________________________________________________________");
    gotoxy(47, 26);
    printf("  Usia            : ");
    gotoxy(46, 27);
    printf("_________________________________________________________________");
    gotoxy(47, 28);
    printf("  No Ponsel       : ");
    gotoxy(46, 29);
    printf("_________________________________________________________________");
    gotoxy(47, 30);
    printf("  Email Anda      : ");
    gotoxy(46, 31);
    printf("_________________________________________________________________");

    back();
    press = getch();

    if (press == 27)
    {
        hapus();
        berandadmin();
        return;
    }

    gotoxy(67, 24);
    val_nama(nama);

    ditemukan = cek_terdaftar(nama);

    if (ditemukan == 1)
    {
        bingkaitata(43, 20, 66, 13);

        gotoxy(64, 26);
        printf("   NAMA SUDAH TERDAFTAR    ");

        gotoxy(64, 27);
        printf("TIDAK DAPAT MENDAFTAR LAGI!");

        Sleep(4000);

        hapus();
        berandadmin();
        return;
    }

    gotoxy(67, 26);
    val_usia(usia);

    gotoxy(67, 28);
    val_nomor(nomor);

    gotoxy(67, 30);
    val_email(email);

    orang = fopen("data_orang.txt", "a");

    if (orang != NULL)
    {
        fprintf(orang, "Nama Lengkap : %s\n", nama);
        fprintf(orang, "Usia         : %s\n", usia);
        fprintf(orang, "No Ponsel    : %s\n", nomor);
        fprintf(orang, "Email Anda   : %s\n", email);
        fprintf(orang, "--------------------------------\n");

        fclose(orang);
    }
    else
    {
        gotoxy(65, 33);
        printf("Gagal menyimpan data!");
        Sleep(2000);

        hapus();
        berandadmin();
        return;
    }

    gotoxy(65, 33);
    printf("<< PENDAFTARAN BERHASIL >>");

    Sleep(500);

    gotoxy(65, 33);
    printf("                          ");

    Sleep(500);

    gotoxy(65, 33);
    printf("<< PENDAFTARAN BERHASIL >>");

    Sleep(500);

    gotoxy(65, 33);
    printf("                          ");

    hapus();
    berandadmin();
}



void daftar_peminjamus()
{

    tamp_dafjam();
    bingkaimipmip(70, 12, 43, 21);

    int find;

    FILE *orang;

    gotoxy(47, 22);
    printf("                            ISI DATA                             ");
    gotoxy(46, 23);
    printf("_________________________________________________________________");
    gotoxy(47, 24);
    printf("  Nama Lengkap    : ");
    gotoxy(46, 25);
    printf("_________________________________________________________________");
    gotoxy(47, 26);
    printf("  Usia            : ");
    gotoxy(46, 27);
    printf("_________________________________________________________________");
    gotoxy(47, 28);
    printf("  No Ponsel       : ");
    gotoxy(46, 29);
    printf("_________________________________________________________________");
    gotoxy(47, 30);
    printf("  Email Anda      : ");
    gotoxy(46, 31);
    printf("_________________________________________________________________");

    back();
    press = getch();
    if (press == 27)

    {
        hapus();
        pinnjam();
    }

    gotoxy(67, 24);
    val_nama(nama);

    ditemukan = cek_terdaftar(nama);
    if (ditemukan == 1)
    {
        bingkaitata(43, 20, 66, 13);
        gotoxy(64, 26);
        printf("   NAMA SUDAH TERDAFTAR    ");
        gotoxy(64, 27);
        printf("TIDAK DAPAT MENDAFTAR LAGI!");
        Sleep(4000);
        hapus();
        beranda_user();
    }
    gotoxy(67, 26);
    val_usia(usia);
    gotoxy(67, 28);
    val_nomor(nomor);
    gotoxy(67, 30);
    val_email(email);


    gotoxy(65, 33);
    printf("<< PENDAFTARAN BERHASIL >>");
    Sleep(500);
    gotoxy(65, 33);
    printf("                          ");
    Sleep(500);
    gotoxy(65, 33);
    printf("<< PENDAFTARAN BERHASIL >>");
    Sleep(500);
    gotoxy(65, 33);
    printf("                          ");

    orang = fopen("data_orang.txt", "a");
    if (orang != NULL)
    {
        fprintf(orang, "Nama Lengkap : %s\n", nama);
        fprintf(orang, "Usia         : %s\n", usia);
        fprintf(orang, "No Ponsel    : %s\n", nomor);
        fprintf(orang, "Email Anda   : %s\n", email);
        fclose(orang);
    }

    hapus();
    beranda_user();
}


void beranda_user()
{
    gambarbuku3();
    bingkaimipmip(20, 5, 4, 15);
    gotoxy(6, 17);
    printf("  1.PINJAM");

    bingkaimipmip(20, 5, 62, 15);
    gotoxy(64, 17);
    printf("  2.PENGEMBALIAN");

    bingkaimipmip(20, 5, 116, 15);
    gotoxy(119, 17);
    printf(" 3.LIHAT PROFIL");

    bingkaimipmip(20, 5, 4, 28);
    gotoxy(6, 30);
    printf(" 4.LIHAT PINJAM");

    bingkaimipmip(25, 4, 60, 22);
    gotoxy(62, 23);
    printf(" 5.LIHAT BUKU");

    bingkaimipmip(20, 5, 116, 28);
    gotoxy(119, 30);
    printf("6.LOGOUT");

    bingkaimipmip(20, 5, 62, 28);
    gotoxy(64, 30);
    printf("    PILIH : ");

    

    char tekan;
    int p = 0;
    while (1)
    {
        gotoxy(72, 34);
        
        back();

        tekan = getch();
        if (tekan == 27)
        {
            hapus();
            pilih();
        }

        if (tekan == '1')
        {
            p = 1;
            hapus();
            pinnjam();
            break;
        }
        else if (tekan == '2')
        {
            p = 2;
            hapus();
            kembalikan();
            break;
        }
        else if (tekan == '3')
        {
            p = 3;
            profil_user();
            break;
        }
        else if (tekan == '4')
        {
            p = 4;
            lihat_buku_dipinjam_user();
            break;
        }

        else if(tekan == '5'){
            p = 5;
            lihat_buku_tersedia_user();
            break;
        }
        else if (tekan == '6')
        {
            p = 6;
            logt();
            break;
        }
        
        else
        {
            gotoxy(72, 34);
            printf("            ");
            gotoxy(72, 34);
            printf("    INVALID ");
            Sleep(700);
            gotoxy(72, 34);
            printf("            ");
        }
    }
    
}
    


void awal_user()
{
    rak_buku();
    gambarbuku2();
    bingkaimipmip(20, 5, 62, 3);
    gotoxy(64, 5);
    printf("  1.LOGIN");

    bingkaimipmip(20, 5, 62, 15);
    gotoxy(64, 17);
    printf("  2.DAFTAR");

    

    bingkaimipmip(20, 5, 62, 28);
    gotoxy(64, 30);
    printf("    PILIH : ");

    

    char tekan;
    int p = 0;
    while (1)
    {
        gotoxy(72, 34);
        
        back();

        tekan = getch();
        if (tekan == 27)
        {
            hapus();
            pilih();
        }

        if (tekan == '1')
        {
            p = 1;
            hapus();
            user();
            break;
        }
        else if (tekan == '2')
        {
            p = 2;
            hapus();
            daftar_user();
            break;
        }
        
        else
        {
            gotoxy(72, 34);
            printf("            ");
            gotoxy(72, 34);
            printf("    INVALID ");
            Sleep(700);
            gotoxy(72, 34);
            printf("            ");
        }
    }
    
}
    
void berandadmin()
{
    tamp_berandamin();

    bingkaimipmip(20, 5, 4, 15);
    gotoxy(6, 17);
    printf("  1.PEMINJAMAN");

    bingkaimipmip(20, 5, 62, 15);
    gotoxy(64, 17);
    printf("  2.PENGEMBALIAN");

    bingkaimipmip(20, 5, 116, 15);
    gotoxy(119, 17);
    printf(" 3.PERSEDIAAN");

    bingkaimipmip(20, 5, 4, 28);
    gotoxy(6, 30);
    printf(" 4.DAFTAR ");
    
    bingkaimipmip(25, 4, 60, 22);
    gotoxy(62, 23);
    printf(" 5.LIHAT PROFIL USER");

    bingkaimipmip(20, 5, 116, 28);
    gotoxy(119, 30);
    printf("    6.EXIT");

    bingkaimipmip(20, 5, 62, 28);
    gotoxy(64, 30);
    printf("    PILIH : ");


    char tekan;
    int p = 0;
    while (1)
    {
        gotoxy(72, 34);
    
        back();

        tekan = getch();
        if (tekan == 27)
        {
            hapus();
            pilih();
        }

        if (tekan == '1')
        {
            p = 1;
            break;
        }
        else if (tekan == '2')
        {
            p = 2;
            break;
        }
        else if (tekan == '3')
        {
            p = 3;
            break;
        }
        else if (tekan == '4')
        {
            p = 4;
            break;
        }
        else if (tekan == '5')
        {
            p = 5;
            break;
        }
        else if (tekan == '6')
        {
            p = 6;
            break;
        }
        else
        {
            gotoxy(72, 34);
            printf("            ");
            gotoxy(72, 34);
            printf("    INVALID ");
            Sleep(700);
            gotoxy(72, 34);
            printf("            ");
        }
    }
    if (p == 1)
    {
        hapus();
        peminjaman();
    }
    else if (p == 2)
    {
        hapus();
        pengembalian();
    }
    else if (p == 3)
    {
        hapus();
        persediaan();
    }
    else if (p == 4)
    {
        hapus();
        daftar_peminjam1();
    }
    else if (p == 5)
    {
        hapus();
        lihat_prodrad();
    }
    else if (p == 6)
    {
        hapus();
        pilih();
        
        
    }
}

void admin()
{
    char passmin[20];
    int limit = 0;
    tamp_admin1();
    boneka();
    bingkaimipmip(33 , 5, 60, 24);

    gotoxy(63, 26);
    printf("KODE ADMIN : ");

    back();
    press = getch();
    if (press == 27)
    {
        hapus();
        pilih();
    }

    do
    {

        int x = 0;

        gotoxy(76, 26);
        passmin[x] = getch();

        while (passmin[x] != 13)
        {
            if (passmin[x] == 8)
            {
                x--;
                if (x < 0)
                {
                    x = 0;
                }
                gotoxy(76 + x, 26);
                printf(" ");
            }
            else if (isdigit(passmin[x]))
            {
                printf("*");
                x++;
            }
            if (x > 8)
            {
                x = 8;
                gotoxy(84, 26);
                printf(" ");
            }
            gotoxy(76 + x, 26);
            passmin[x] = getch();
        }
        passmin[x] = '\0';

        if (strlen(passmin) <= 8 && strcmp(passmin, "270927") == 0)
        {
            gotoxy(66, 34);
            printf("<< LOGIN BERHASIL >>");
            Sleep(500);
            gotoxy(66, 34);
            printf("                    ");
            Sleep(500);
            gotoxy(66, 34);
            printf("<< LOGIN BERHASIL >>");
            Sleep(500);
            gotoxy(66, 34);
            printf("                    ");
            hapus();
            berandadmin();
        }
        else
        {
            gotoxy(65, 31);
            printf("Kode yang dimasukan salah !!");
            Sleep(400);
            gotoxy(65, 31);
            printf("                            ");
            Sleep(350);
            gotoxy(65, 31);
            printf("Kode yang dimasukan salah !!");
            Sleep(600);
            gotoxy(65, 31);
            printf("                            ");
            Sleep(300);
            limit++;
            gotoxy(76, 26);
            printf("         ");
        }
    } while (limit < 3);

    gotoxy(68, 34);
    printf("Kesempatan habis!");
    Sleep(500);
    gotoxy(68, 34);
    printf("                 ");
    Sleep(350);
    gotoxy(68, 34);
    printf("Kesempatan habis!");
    Sleep(700);
    gotoxy(68, 34);
    printf("                 ");
    Sleep(350);

    for (int a = 0; a <= 10; a++)
    {
        gotoxy(58, 36);
        printf("Tunggu dalam %d untuk kembali mengakses", a);
        Sleep(500);
    }
    hapus();
    admin();
}

void about()
{
    tamp_about();

    char tamp[300];
    FILE *miftah;
    int y = 19;
    bingkaimipmip(100, 15, 19, 15);
    gotoxy(65, 18);
    Sleep(50);

    miftah = fopen("about.txt", "r");
    if(miftah == NULL)
    {
        printf("File about tidak ditemukan");
        getch();
    }

    while(fgets(tamp, sizeof(tamp), miftah))
    {   
        
        gotoxy(30, y);
        printf("%s", tamp);
        y++;
    }

    fclose(miftah);
    
    back();
    do
    {
        press = getch();
        if (press == 27)
        {
            hapus();
            pilih();
        }
    } while (press != 27);
}


void lihat_prodrad()
{
    FILE *fp;
    char data[200][300];   
    int totalBaris = 0;
    int page = 0;
    int totalPage;
    int i;
    char key;

    tamp_prous();
    bingkaimipmip(120, 18, 10, 15);

    fp = fopen("data_peminjaman.txt", "r");

    if (fp == NULL)
    {
        gotoxy(55, 22);
        printf("Data peminjaman tidak ditemukan!");
        getch();
        hapus();
        berandadmin();
        return;
    }

    while (fgets(data[totalBaris], sizeof(data[totalBaris]), fp) != NULL)
    {
        totalBaris++;
    }

    fclose(fp);

    if (totalBaris == 0)
    {
        gotoxy(55, 10);
        printf("Data peminjaman kosong!");
        getch();
        hapus();
        berandadmin();
        return;
    }

    totalPage = (totalBaris + MAX_BARIS - 1) / MAX_BARIS;

    while (1)
    {
        int y = 17;
        int start = page * MAX_BARIS;
        int end = start + MAX_BARIS;

        if (end > totalBaris)
            end = totalBaris;

        for (i = 17; i <= 28; i++)
        {
            gotoxy(23, i);
            printf("%-90s", "");
        }

        for (i = start; i < end; i++)
        {
            gotoxy(15, y++);
            printf("%s", data[i]);
        }

        gotoxy(100, 14);
        printf("Halaman %d / %d", page + 1, totalPage);

        key = getch();

        if (key == 27) 
        {
            hapus();
            berandadmin();
            return;
        }
        else if (key == 77 && page < totalPage - 1) 
        {
            page++;
        }
        else if (key == 75 && page > 0) 
        {
            page--;
        }
    }
}

void gambar_menu(int tekan)
{
    if (tekan == 1)
        setcolor(14, 1); 
    else
        setcolor(7, 8);  
        kotak(14, 18, 25, 5);
        gotoxy(20, 20);
        printf("1. A D M I N");
    if (tekan == 2)
        setcolor(14, 1);
    else
        setcolor(7, 8);
        kotak(44, 18, 25, 5);
        gotoxy(48, 20);
        printf("2. A B O U T");
    if (tekan == 3)
        setcolor(14, 1);
    else
        setcolor(7, 8);
        kotak(76, 18, 25, 5);
        gotoxy(82, 20);
        printf("3. U S E R");
    if (tekan == 4)
        setcolor(14, 1);
    else
        setcolor(7, 8);
        kotak(105, 18, 25, 5);
        gotoxy(111, 20);
        printf("4. E X I T");
}


void keluar()
{
    tamp_exit();
    exit(0);   
}


void pilih()
{
    int tekan = 1;
    char pilihan;

    tamp_menu();
    gambar_menu(tekan);

    while ((pilihan = getch()) != 13) 
    {
        if (pilihan == 77) 
        {
            tekan++;
            if (tekan > 4)
                tekan = 1;
        }
        else if (pilihan == 75) 
        {
            tekan--;
            if (tekan < 1)
                tekan = 4;
        }

        gambar_menu(tekan);
    }

    hapus();
    switch (tekan)
    {
        case 1: admin(); break;
        case 2: about(); break;
        case 3: awal_user(); break;
        case 4: keluar(); break;
    }
}


void tampilan_diawal()
{
    bingkai(0, 0, 140, 35, 14, 9);
    gambarbuku();
    gambarbuku2();
    tamp_welcome();
    to();
    itta();
    boneka();
    getch();
    hapus();
    pilih();
}