#include <windows.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

char *val_nama(char *nama);
char *val_usia(char *usia);
char *val_nomor(char *nomor);
char *val_email(char *email);
char *val_judul(char *judul);
char *val_idbuku(char *id_buku);
char *val_idpinbuku(char *id_buku);
char *val_penulis(char *penulis);
char *val_stok(char *stok_str);
char *val_username();
char *val_password();
char * val_userlog(char *username);
char *val_paslog(char *pasword);

#define handle GetStdHandle(STD_OUTPUT_HANDLE)

void gotoxy(int x, int y)
{
    COORD koordinat;
    koordinat.X = x;
    koordinat.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), koordinat);
}

char *val_nama(char *nama)
{
    char ch;
    int index = 0;
    int huruf_kata = 0; 

    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            if (index >= 3 && nama[index - 1] != ' ')
                break;
        }

        else if (isupper(ch))
        {
            if ((index == 0 || nama[index - 1] == ' ') && index < 24)
            {
                printf("%c", ch);
                nama[index++] = ch;
                huruf_kata = 1;
            }
        }

        else if (islower(ch))
        {
            if (index > 0 && nama[index - 1] != ' ' && index < 24)
            {
                printf("%c", ch);
                nama[index++] = ch;
                huruf_kata++;
            }
        }

        else if (ch == ' ')
        {
            if (huruf_kata >= 3 && nama[index - 1] != ' ' && index < 24)
            {
                printf(" ");
                nama[index++] = ' ';
                huruf_kata = 0; 
            }
        }

        else if (ch == 8 && index > 0)
        {
            printf("\b \b");
            index--;
            huruf_kata = 0;

            for (int i = index - 1; i >= 0; i--)
            {
                if (nama[i] == ' ')
                    break;
                huruf_kata++;
            }
        }
    }

    nama[index] = '\0';
    return nama;
}

char *val_usia(char *usia)
{
    char inp_usia;
    int index = 0;
    int age;

    while (1)
    {
        gotoxy(67 + index, 26);
        inp_usia = getch();

        if (inp_usia == 13 && index == 2)
        { 
            usia[index] = '\0';
            age = atoi(usia);
            if (age >= 17 && age <= 60)
            {
                gotoxy(67, 26);
                printf("%d Tahun", age);
                break;
            }
            else
            {
                index = 0;
                gotoxy(67, 26);
                printf("  ");
            }
        }
        else if (inp_usia == 8 && index > 0)
        { 
            printf("\b \b");
            index--;
        }
        else if (index < 2 && inp_usia >= '0' && inp_usia <= '9')
        { 
            usia[index] = inp_usia;
            printf("%c", usia[index]);
            index++;
        }
    }
    return usia;
}

char *val_nomor(char *nomor)
{
    char ch;
    int idx = 0;
    int panjang_awal = 0;   
    int max_total = 0;      

    while (1)
    {
        ch = getch();

        if (ch == 13)
        {
            if ((panjang_awal == 2 && idx >= 3) || (panjang_awal == 3 && idx >= 4))    
            {
                break;
            }
        }

        else if (ch == 27)
        {
            nomor[0] = '\0';
            return nomor;
        }

        else if (ch == 8 && idx > 0)
        {
            printf("\b \b");
            idx--;

            if (idx < panjang_awal)
                panjang_awal = idx;

            continue;
        }

        if (idx == 0 && ch == '0')
        {
            printf("%c", ch);
            nomor[idx++] = ch;
        }
        else if (idx == 1 && nomor[0] == '0' && ch == '8')
        {
            printf("%c", ch);
            nomor[idx++] = ch;
            panjang_awal = 2;
            max_total = 12; 
        }
        else if (idx == 0 && ch == '+')
        {
            printf("%c", ch);
            nomor[idx++] = ch;
        }
        else if (idx == 1 && nomor[0] == '+' && ch == '6')
        {
            printf("%c", ch);
            nomor[idx++] = ch;
        }
        else if (idx == 2 && nomor[0] == '+' && nomor[1] == '6' && ch == '2')
        {
            printf("%c", ch);
            nomor[idx++] = ch;
            panjang_awal = 3;
            max_total = 13; 
        }

        else if (panjang_awal > 0 &&
                 idx < max_total &&
                 ch >= '0' && ch <= '9')
        {
            if (idx == panjang_awal)
            {
                if (ch == '2' || ch == '1' || ch == '5' ||
                    ch == '9' || ch == '8')
                {
                    printf("%c", ch);
                    nomor[idx++] = ch;
                }
            }
            else
            {
                printf("%c", ch);
                nomor[idx++] = ch;
            }
        }
    }

    nomor[idx] = '\0';
    return nomor;
}

char *val_email(char *email)
{
    char ch;
    char *p = email;
    int len = 0;
    int mode = 0; 

    while (1)
    {
        ch = getch();

        if (ch == 13)
        {
            if (mode == 2 && len >= 12)
                break;
        }

        else if (ch == 8 && len > 0)
        {
            printf("\b \b");
            p--;
            len--;
            *p = '\0';

            if (strchr(email, '@') == NULL)
                mode = 0;
            else
                mode = 1;
        }

        else if (mode == 0)
        {
            if (((ch >= 'a' && ch <= 'z') ||
                 (ch >= 'A' && ch <= 'Z') ||
                 (ch >= '0' && ch <= '9')) && len < 24)
            {
                *p = ch;
                p++;
                len++;
                printf("%c", ch);
            }
            else if (ch == '@' && len >= 5)
            {
                *p = ch;
                p++;
                len++;
                printf("@");
                mode = 1;
            }
        }

        else if (mode == 1)
        {
            if (ch == 'g')
            {
                printf("gmail.com");
                strcpy(p, "gmail.com");
                p += 9;
                len += 9;
                mode = 2;
            }
            else if (ch == 'e')
            {
                printf("email.com");
                strcpy(p, "email.com");
                p += 9;
                len += 9;
                mode = 2;
            }
            else if (ch == 'y')
            {
                printf("yahoo.com");
                strcpy(p, "yahoo.com");
                p += 9;
                len += 9;
                mode = 2;
            }
        }
    }

    *p = '\0';
    return email;
}

char *val_judul(char *judul)
{
    char input_judul;
    int index = 0;

    while (1)
    {
        input_judul = getch();

        if (input_judul == 13 && index >= 4)
        {
            break;
        }

        if (islower(input_judul))
        {
            if (index > 0 && judul[index - 1] != ' ' && (input_judul != judul[index - 1] || input_judul != judul[index - 2]))
            {
                printf("%c", input_judul);
                judul[index++] = input_judul;
            }
        }
        else if (isupper(input_judul))
        {
            if (index == 0 || judul[index - 1] == ' ')
            {
                printf("%c", input_judul);
                judul[index++] = input_judul;
            }
        }
        else if (input_judul == ' ')
        {
            if (index > 0 && index < 25 && judul[index - 1] != ' ')
            {
                printf("%c", input_judul);
                judul[index++] = input_judul;
            }
        }
        else if (input_judul == 8 && index > 0)
        {
            printf("\b \b");
            index--;
        }
    }

    judul[index] = '\0'; 
    return judul;
}

char *val_idbuku(char *id_buku)
{
    char inp_id;
    int index = 0;
    int id;

    while (1)
    {
        gotoxy(68 + index, 24);
        inp_id = getch();

        if (inp_id == 13 && index < 3)
        {
            id_buku[index] = '\0';
            id = atoi(id_buku);
            if (id <= 99)
            {
                gotoxy(68, 24);
                printf("%d", id);
                break;
            }
            else
            {
                index = 0;
                gotoxy(68, 24);
                printf("  ");
            }
        }
        else if (inp_id == 8 && index > 0)
        { 
            printf("\b \b");
            index--;
        }
        else if (index < 2 && inp_id >= '0' && inp_id <= '9')
        { 
            id_buku[index] = inp_id;
            printf("%c", id_buku[index]);
            index++;
        }
    }
    return id_buku;
}

char *val_idpinbuku(char *id_buku)
{
    char inp_id;
    int index = 0;
    int id;

    while (1)
    {
        gotoxy(67 + index, 28);
        inp_id = getch();

        if (inp_id == 13 && index < 3) 
        {
            id_buku[index] = '\0';
            id = atoi(id_buku);
            if (id <= 99)
            {
                gotoxy(67, 28);
                printf("%d", id);
                break;
            }
            else
            {
                index = 0;
                gotoxy(67, 28);
                printf("  ");
            }
        }
        else if (inp_id == 8 && index > 0)
        { 
            printf("\b \b");
            index--;
        }
        else if (index < 2 && inp_id >= '0' && inp_id <= '9')
        { 
            id_buku[index] = inp_id;
            printf("%c", id_buku[index]);
            index++;
        }
    }
    return id_buku;
}

char *val_penulis(char *penulis)
{
    char input_penulis;
    int index = 0;

    while (1)
    {
        input_penulis = getch();

        if (input_penulis == 13 && index >= 3)
        {
            break;
        }

        if (islower(input_penulis))
        {
            if (index > 0 && penulis[index - 1] != ' ' && (input_penulis != penulis[index - 1] || input_penulis != penulis[index - 2]))
            {
                printf("%c", input_penulis);
                penulis[index++] = input_penulis;
            }
        }
        else if (isupper(input_penulis))
        {
            if (index == 0 || penulis[index - 1] == ' ')
            {
                printf("%c", input_penulis);
                penulis[index++] = input_penulis;
            }
        }
        else if (input_penulis == ' ')
        {
            if (index > 0 && index < 25 && penulis[index - 1] != ' ')
            {
                printf("%c", input_penulis);
                penulis[index++] = input_penulis;
            }
        }
        else if (input_penulis == 8 && index > 0)
        {
            printf("\b \b");
            index--;
        }
    }

    penulis[index] = '\0'; 
    return penulis;
}

char *val_stok(char *stok_str)
{
    char inp_stok;
    int index = 0;
    int stok;

    while (1)
    {
        gotoxy(68 + index, 30);
        inp_stok = getch();

        if (inp_stok == 13 && index > 0)
        { 
            stok_str[index] = '\0';
            stok = atoi(stok_str);
            if (stok < 30)
            {
                gotoxy(68, 30);
                printf("%d", stok);
                break;
            }
            else
            {
                index = 0;
                gotoxy(68, 30);
                printf("   ");
            }
        }
        else if (inp_stok == 8 && index > 0)
        { 
            printf("\b \b");
            index--;
        }
        else if (index < 2 && inp_stok >= '0' && inp_stok <= '9')
        { 
            stok_str[index] = inp_stok;
            printf("%c", stok_str[index]);
            index++;
        }
    }
    return stok_str;
}

char *val_username()
{
    char x, tamp[20];
    int q = 0;

    printf("username:");
    while ((x = getch()) != 13 || q < 10)
    {
        if ((x >= 'A' && x <= 'Z' ||
             x >= 'a' && x <= 'z' ||
             x >= '0' && x <= '9' ||
             x == '.' || x == '_' || x == '@') &&
            q < 19)
        {
            tamp[q] = x;
            q++;
            printf("%c", x);
        }
        else if (x == 8)
        {
            q--;
            tamp[q] = '\0';
            printf("\b\b");
        }
        tamp[q] = '\0';
    }
    printf("\n username anda : %s\n", tamp);
}

char *val_password()
{
    char s,tamp[30];
    int a = 0;
    printf("password = ");
    while((s=getch())!= 13 || a < 10)
    {
        if((s >= 'A' && s <= 'Z' ||
           s >= 'a' && s <= 'z'  ||
           s >= '0' && s <= '9'  ||
           s == '_' || s == '@') && a < 29)
           {
            tamp[a]=s;
            a++;
            printf("%c",s); 
        }else if(s==8){
            a--;
            tamp[a]='\0';
            printf("\b \b");
        }
    }
    tamp[a]='\0'; 
    printf("\n password anda = %s\n",tamp);
}

char * val_userlog(char *username)
{
    char idx;
    char tam[100]={};
    int i =0;
    while((idx=getch())!=13||i<3){
                    if(i==0 && (idx >='A' && idx<='Z'))
                    {
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 13  && ( idx >='a' && idx<='z' && idx != tam[i-1] || tam[i-2] != idx &&(idx == 'n' || idx=='g' || idx=='m')  || idx >='0' && idx<='9'  ))
                    {
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if( i != 0 && idx== 32 && tam[i-1]!=32 && tam[i-2]!=32 && tam[i-3]!=32 )
                    {
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 )
                    {
                              i--;
                              printf("\b \b");
                              tam[i]='\0';

                    }
          }
        tam[i]='\0';

        strcpy(username,tam);
}

char *val_paslog(char *pasword)
{
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<4){
         if( i <= 9 && ( idx >='a' && idx<='z' || idx >='0' && idx<='9' )){
                              printf("*");
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]='\0';

                    }
          }
          tam[i]='\0';

          strcpy(pasword,tam);
}

