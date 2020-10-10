#include<stdio.h>
#include<string.h>

typedef struct ksiazki
    {
        char tytul[21];
        char kraj[16];
        char dzial[16];
        char numer[6];
    } Ksiazki;
    Ksiazki tab[50];

void pobierzTytul ( int t )
{
    int n;
    char tmp='0';
    n=0;
    printf ("Tytul: ");
    do
    {
        tmp=getc(stdin);
        if (tmp=='\n')
        {
            tab[t].tytul[n]='\0';
            break;
        }
        tab[t].tytul[n]=tmp;
        n++;
    }
    while (1);
    if (n>=21)
        {
            printf ("Wprowadzono za duzo znakow. \n");
            pobierzTytul (t);
        }
    if ( tab[t].tytul[0]==' ' && strlen(tab[t].tytul)==1 )
        {
            printf ("\n");
            return;
        }
    if ( tab[t].tytul[0]<65 || tab[t].tytul[0]>90  )
        {
            printf ("Podano zly format danych. \n");
            pobierzTytul (t);
        }
    return;
}

void pobierzKraj ( int t )
{
    int n=0,k;
    char tmp='0';
    printf ("Kraj pierwszego wydania: ");
    do
    {
        tmp=getc(stdin);
        if (tmp=='\n')
        {
            tab[t].kraj[n]='\0';
            break;
        }
        tab[t].kraj[n]=tmp;
        n++;
    }
    while (1);
    if (n>=16)
        {
            printf ("Wprowadzono za duzo znakow. \n");
            pobierzKraj (t);
        }
    if ( tab[t].kraj[0]<65 || tab[t].kraj[0]>90  )
        {
            printf ("Podano zly format danych. \n");
            pobierzKraj (t);
        }
    for (k=1; k<n; ++k)
    if ( ( tab[t].kraj[k]<65 || tab[t].kraj[k]>90 ) && ( tab[t].kraj[k]<97 || tab[t].kraj[k]>122 ) && tab[t].kraj[k]!=32   )
    {
        printf ("Podano zly format danych. \n");
        pobierzKraj (t);
    }
    return;
}

void pobierzDzial ( int t )
{
    int n=0,k;
    char tmp='0';
    printf ("Dzial: ");
    do
    {
        tmp=getc(stdin);
        if (tmp=='\n')
        {
            tab[t].dzial[n]='\0';
            break;
        }
        tab[t].dzial[n]=tmp;
        n++;
    }
    while (1);
    if (n>=16)
        {
            printf ("Wprowadzono za duzo znakow. \n");
            pobierzDzial (t);
        }
    if ( tab[t].dzial[0]<65 || tab[t].dzial[0]>90  )
        {
            printf ("Podano zly format danych. \n");
            pobierzDzial (t);
        }
    for (k=1; k<n; ++k)
    if ( ( tab[t].dzial[k]<65 || tab[t].dzial[k]>90 ) && ( tab[t].dzial[k]<97 || tab[t].dzial[k]>122 ) && tab[t].dzial[k]!=32   )
    {
        printf ("Podano zly format danych. \n");
        pobierzDzial (t);
    }
    return;
}

void pobierzNumer (int t)
{
    int n=0,k;
    char tmp='0';
    printf ("Numer: ");
    do
    {
        tmp=getc(stdin);
        if (tmp=='\n')
        {
            tab[t].numer[n]='\0';
            break;
        }
        tab[t].numer[n]=tmp;
        n++;
    }
    while (1);
    if (n!=5)
    {
        printf ("Podano zly format danych. \n");
        pobierzNumer (t);
    }
    for (k=0; k<5; ++k)
    if ( ( tab[t].numer[k]<48 || tab[t].numer[k]>57 )  )
    {
        printf ("Podano zly format danych. \n");
        pobierzNumer (t);
    }
    for (k=0; k<t; ++k)
    {
        if ( strcmp( tab[t].numer, tab[k].numer )==0 )
        {
            printf ("Podany kod juz zostal wpisany. \n");
            pobierzNumer (t);
        }
    }
    return;
}

void sort1 (int w)
{
    int a,b,z;
    char temp[21];
    for(b=0; b<w-1; ++b)
        for(a=0; a<w-1; ++a)
            if ( (strcmp (tab[a].dzial, tab[a+1].dzial) > 0) )
                {
                    for (z=0; z<21; ++z)
                    {
                        temp[z]=tab[a].tytul[z];
                        tab[a].tytul[z]=tab[a+1].tytul[z];
                        tab[a+1].tytul[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].kraj[z];
                        tab[a].kraj[z]=tab[a+1].kraj[z];
                        tab[a+1].kraj[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].dzial[z];
                        tab[a].dzial[z]=tab[a+1].dzial[z];
                        tab[a+1].dzial[z]=temp[z];
                    }
                    for (z=0; z<6; ++z)
                    {
                        temp[z]=tab[a].numer[z];
                        tab[a].numer[z]=tab[a+1].numer[z];
                        tab[a+1].numer[z]=temp[z];
                    }
                }
    for(b=0; b<w-1; ++b)
        for(a=0; a<w-1; ++a)
            if ( (strcmp (tab[a].dzial, tab[a+1].dzial) == 0) && (strcmp (tab[a].numer, tab[a+1].numer) < 0) )
                {
                    for (z=0; z<21; ++z)
                    {
                        temp[z]=tab[a].tytul[z];
                        tab[a].tytul[z]=tab[a+1].tytul[z];
                        tab[a+1].tytul[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].kraj[z];
                        tab[a].kraj[z]=tab[a+1].kraj[z];
                        tab[a+1].kraj[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].dzial[z];
                        tab[a].dzial[z]=tab[a+1].dzial[z];
                        tab[a+1].dzial[z]=temp[z];
                    }
                    for (z=0; z<6; ++z)
                    {
                        temp[z]=tab[a].numer[z];
                        tab[a].numer[z]=tab[a+1].numer[z];
                        tab[a+1].numer[z]=temp[z];
                    }
                }
}


void sort2 (int w)
{
    int a,b,z;
    char temp[21];
    for(b=0; b<w-1; ++b)
        for(a=0; a<w-1; ++a)
            if ( (strcmp (tab[a].dzial, tab[a+1].dzial) > 0) )
                {
                    for (z=0; z<21; ++z)
                    {
                        temp[z]=tab[a].tytul[z];
                        tab[a].tytul[z]=tab[a+1].tytul[z];
                        tab[a+1].tytul[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].kraj[z];
                        tab[a].kraj[z]=tab[a+1].kraj[z];
                        tab[a+1].kraj[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].dzial[z];
                        tab[a].dzial[z]=tab[a+1].dzial[z];
                        tab[a+1].dzial[z]=temp[z];
                    }
                    for (z=0; z<6; ++z)
                    {
                        temp[z]=tab[a].numer[z];
                        tab[a].numer[z]=tab[a+1].numer[z];
                        tab[a+1].numer[z]=temp[z];
                    }
                }
    for(b=0; b<w-1; ++b)
        for(a=0; a<w-1; ++a)
            if ( (strcmp (tab[a].dzial, tab[a+1].dzial) == 0) && (strcmp (tab[a].tytul, tab[a+1].tytul) > 0) )
                {
                    for (z=0; z<21; ++z)
                    {
                        temp[z]=tab[a].tytul[z];
                        tab[a].tytul[z]=tab[a+1].tytul[z];
                        tab[a+1].tytul[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].kraj[z];
                        tab[a].kraj[z]=tab[a+1].kraj[z];
                        tab[a+1].kraj[z]=temp[z];
                    }
                    for (z=0; z<16; ++z)
                    {
                        temp[z]=tab[a].dzial[z];
                        tab[a].dzial[z]=tab[a+1].dzial[z];
                        tab[a+1].dzial[z]=temp[z];
                    }
                    for (z=0; z<6; ++z)
                    {
                        temp[z]=tab[a].numer[z];
                        tab[a].numer[z]=tab[a+1].numer[z];
                        tab[a+1].numer[z]=temp[z];
                    }
                }
}

void obslugaMenu ( int y )
{
    int f, g, k;
    char c;
    char w[2], x[2], p[2], r[2];
    printf ("****************************************************************\n\nMENU \n\nWpisz cyfre odpowiadajaca zadanej przez Ciebie czynnosci: \n1- Powrot do wprowadzania danych \n2- Poprawienie wprowadzonego elementu listy \n3- Wyswietlenie listy w/g alfabetycznej kolejnosci dzialow i malejacych numerow \n4- Wyswietlenie w/g alfabetycznej kolejnosci dzialow i listy alfabetycznej tytulow ksiazek \n5- Wyjscie z programu \n");
    do
    {
        printf (" Wybierz opcje: ");
        scanf ("%s", w);
        if ( ( w[0]!='1' && w[0]!='2' && w[0]!='3' && w[0]!='4' && w[0]!='5'  ) || strlen(w)!=1 )
            printf ("Nie ma takiej instrukcji. \n");
    }
    while ( ( w[0]!='1' && w[0]!='2' && w[0]!='3' && w[0]!='4' && w[0]!='5'  ) || strlen(w)!=1 );
    c=w[0];
    printf ("\n");
    switch (c)
    {
        case '1': do
                {
                    fflush(stdin);
                    pobierzTytul(y);
                    if ( tab[y].tytul[0]==' ' && strlen(tab[y].tytul)==1 )
                    {
                        printf ("\n");
                        break;
                    }
                    pobierzKraj(y);
                    pobierzDzial(y);
                    pobierzNumer(y);
                    printf ("\n");
                    ++y;
                }
                while (1);
                obslugaMenu (y);
                break;
        case '2': do
                {
                    printf ("Podaj nr ksiazki, ktora chcesz poprawic: ");
                    scanf ("%s", x);
                    g=x[0]-48-1;
                    if ( g+1>y || g<0 || strlen(x)!=1 )
                    {
                        printf ("Nie ma takiej ksiazki. \n");
                    }
                }
                while ( g+1>y || g<0 || strlen(x)!=1 );
                printf ("Popraw: \nTytul- 1 \nKraj pierwszego wydania- 2 \nDzial- 3 \nNumer- 4 \n ");
                do
                {
                    printf ("Wpisz numer wybranego elementu: ");
                    scanf ("%s", p);
                    if ( ( p[0]!='1' && p[0]!='2' && p[0]!='3' && p[0]!='4' ) || strlen(p)!=1 )
                    {
                        printf ("Nie ma takiej pozycji. \n");
                    }
                }
                while ( ( p[0]!='1' && p[0]!='2' && p[0]!='3' && p[0]!='4' ) || strlen(p)!=1 );
                f=p[0]-48;
                if (f==1)
                    {
                        fflush(stdin);
                        pobierzTytul(g);
                        obslugaMenu (y);
                    }
                else if (f==2)
                    {
                        fflush(stdin);
                        pobierzKraj(g);
                        obslugaMenu (y);
                    }
                else if (f==3)
                    {
                        fflush(stdin);
                        pobierzDzial(g);
                        obslugaMenu (y);
                    }
                else if (f==4)
                    {
                        fflush(stdin);
                        pobierzNumer(g);
                        obslugaMenu (y);
                    }
                else printf ("Nie ma takiego elementu.");
                break;
        case '3': sort1 (y);
                printf ("Dzial \t\t Tytul \t\t Numer \t\t Kraj \n\n");
                for (k=0; k<y; ++k)
                {
                    printf ("%s \t\t %s \t\t %s \t\t %s \n", tab[k].dzial, tab[k].tytul, tab[k].numer, tab[k].kraj);
                }
                printf ("\n");
                obslugaMenu(y);
                break;
        case '4': sort2 (y);
                printf ("Dzial \t\t Tytul \t\t Numer \t\t Kraj \n\n");
                for (k=0; k<y; ++k)
                {
                    printf ("%s \t\t %s \t\t %s \t\t %s \n", tab[k].dzial, tab[k].tytul, tab[k].numer, tab[k].kraj);
                }
                printf ("\n");
                obslugaMenu(y);
                break;
        case '5': do
                {
                    printf ("Czy na pewno chcesz zamknac program? Jesli tak- wpisz 1, jesli nie- 2: ");
                    scanf ("%s", r);
                    if ( ( r[0]!='1' && r[0]!='2' ) || strlen(r)!=1 )
                    {
                        printf ("Nie ma takiej instrukcji. \n");
                    }
                }
                while ( ( r[0]!='1' && r[0]!='2' ) || strlen(r)!=1 );
                if ( r[0]=='1')
                    return;
                if ( r[0]=='2' )
                    obslugaMenu (y);
                break;
        default: printf ("Nie ma takiej instrukcji. \n\n");
                 fflush(stdin);
                 obslugaMenu(y);
    }
}


int main ()
{
    printf ("Podaj informacje o kazdej ksiazce: \n1) tytul ksiazki (bez polskich znakow, zacznij z wielkiej litery) \n2) kraj pierwszego wydania (bez polskich znakow, zacznij z wielkiej litery) \n3) nazwe dzialu (bez polskich znakow, zacznij z wielkiej litery) \n4) unikatowy 5- cyfrowy numer. \n\n");
    int i=0;
    do
    {
        pobierzTytul(i);
        if ( tab[i].tytul[0]==' ' && strlen(tab[i].tytul)==1 )
        {
            printf ("\n");
            break;
        }
        pobierzKraj(i);
        pobierzDzial(i);
        pobierzNumer(i);
        printf ("\n");
        ++i;
    }
    while (1);
    obslugaMenu (i);
    return 0;
}
