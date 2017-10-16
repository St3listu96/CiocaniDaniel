#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

char tabla[3][3]={0};

char log[10][13]={0};

int spatii=3,enter=3;
int turn=1; // numarul de runde

void afisarelog()
{
    cout<<"LOG:"<<endl;
    int i;
    for (i=0;i<10;i++)
        {
            cout<<log[i];
            cout<<endl;
        }

}

int verificadacaestesimbol(char x)  // daca este simbol returneaza 0 adica sa nu il adauge si daca nu 1, se poate adauga...
{
    int i,j;
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
        {
            if (tabla[i][j]==x)  // daca este numarul introdus
            {
                return 1;
            }
        }
    return 0;
}

void adaugaintabla(char x,int player)  // adauga x sau 0 in tabla
{
    int i,j;
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
    {
        if (tabla[i][j]==x)  // daca este numarul introdus
        {
            if (player==1)
                tabla[i][j]='X';
            else
                tabla[i][j]='O';
        }
    }
}

void afisarespatii() // functie care afiseaza tabla
{
    int i;
    for (i=0;i<spatii;i++)
        if (i==1)
            cout<<"|";
        else
            cout<<" ";
}

void afisareenter()  // functie afiseaza tabla
{
    int i;
    for (i=0;i<enter;i++)
        {
            cout<<endl;
            if (i==0)
                cout<<" _____________";
        }
}

void init () // initializare tabla
{
    int i,j;
    char k='1';
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
    {
        tabla[i][j]=k;
        k++;
    }

    for (i=0;i<10;i++)
        strcpy(log[i],"");
    tabla[1][0]='4';
}

void afisare ()  // afisare tabla
{
    int i,j;
    for (i=0;i<3;i++)
        {
            afisareenter();  // afiseaza niste "enteruri" initial
            afisarespatii(); // niste spatii ca sa indenteza tabla
            for (j=0;j<3;j++)
            {
                cout<<tabla[i][j];
                afisarespatii(); // spatiile dintre simboluri
            }
        }
    afisareenter(); // niste "enteruri" la final

}

bool win ()
{
    int i;
    for (i=0;i<3;i++)
    {
        if (tabla[i][0]==tabla[i][1] && tabla[i][1]==tabla[i][2])
        {
            if (tabla[i][1]=='X')
                {
                    system("cls");


                    turn=1;
                    afisare();
                    afisarelog();
                    cout<<"Player 1 castiga ";
                    cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                    getch();
                    init();

                }
                else
                    if (tabla[i][1]=='O')
                    {
                        system("cls");


                        turn=1;
                        afisare();
                        afisarelog();
                        cout<<"Player 2 castiga ";
                        cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                        getch();
                        init();

                    }

        }

        if (tabla[0][i]==tabla[1][i] && tabla[1][i]==tabla[2][i])
        {
            if (tabla[0][i]=='X')
                {
                    system("cls");


                    turn=1;
                    afisare();
                    afisarelog();
                    cout<<"Player 1 castiga ";
                    cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                        getch();
                    init();

                }
                else
                    if (tabla[0][i]=='O')
                    {
                        system("cls");

                        turn=1;
                        afisare();
                        afisarelog();
                        cout<<"Player 2 castiga ";
                        cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                        getch();
                        init();

                    }
        }
    }

    if (tabla[0][0]==tabla[1][1] && tabla[1][1]==tabla[2][2])
    {
        if (tabla[1][1]=='X')
                {
                    system("cls");
                    cout<<"Player 1 castiga ";

                    turn=1;
                    afisare();
                    afisarelog();
                    cout<<"Player 1 castiga ";
                    cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                        getch();
                    init();

                }
                else
                    if (tabla[1][1]=='O')
                    {
                        system("cls");
                        cout<<"Player 2 castiga ";

                        turn=1;
                        afisare();
                        afisarelog();
                        cout<<"Player 2 castiga ";
                        cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                        getch();
                        init();

                    }
    }

    if (tabla[0][2]==tabla[1][1] && tabla[1][1]==tabla[2][0])
    {
        if (tabla[1][1]=='X')
                {
                    system("cls");


                    turn=1;
                    afisare();
                    afisarelog();
                    cout<<"Player 1 castiga ";
                    cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                        getch();
                    init();

                }
                else
                    if (tabla[1][1]=='O')
                    {
                        system("cls");


                        turn=1;
                        afisare();
                        afisarelog();
                        cout<<"Player 2 castiga ";
                        cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                        getch();

                        init();

                    }
    }

}

int main()
{
    init (); // pune tabla la starea initiala (inceput de joc)
    afisare(); // afiseaza tabla in starea curenta

    int player;
    while (win())
    {
        system("cls");
        afisare();

        char input[150];  // ce numar baga utilizatorul
        bool x=true;
        if (turn %2!=0)  // aceasta conditie trece prin randul jucatorilor din 1 in 1
        {
            do{
                cout<<"Player 1 mutare : ";
                cin>>input;
                if (input[0]>='1' && input[0]<='9')  // daca au bagat numar
                {
                    if (verificadacaestesimbol(input[0]) == 0) // daca este simbol (x sau 0)
                        x=true;  // mai cere un numar
                    else
                    {
                        x=false; // trece mai departe
                        player=1;

                        strcpy(log[turn],"Player 1 :  ");
                        log[turn][11]=input[0];

                        adaugaintabla(input[0],player); // bagam in tabla X al playerului 1
                        turn++;
                    }
                }

            }while (x);
        }
        else{
            do{
                cout<<"Player 2 mutare : ";
                cin>>input;
                if (input[0]>='1' || input[0]<='9')
                {
                    if (verificadacaestesimbol(input[0]) == 0)
                        x=true;
                    else
                    {
                        x=false;
                        player=2;

                        strcpy(log[turn],"Player 2 :  ");
                        log[turn][11]=input[0];

                        adaugaintabla(input[0],player); // bagam in tabla X al playerului 1
                        turn++;
                    }
                }

            }while (x);
        }

        if (turn==10)
            {
                system("cls");
                turn=1;
                afisare();
                afisarelog();
                init ();
                cout<<endl;
                cout<<"REMIZA"<<endl;
                cout<<endl<<"Pentru a incepe o noua runda apasati orice";
                getch();
                init();
            }
    }

    return 0;
}
