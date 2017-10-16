#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
    int x=0,y=0;
void spatii (int x)
{
    for (int i=0;i<x;i++)
        cout<<" ";
}
void enter (int x)
{
    for (int i=0 ; i<x; i++)
        cout<<"\n";
}

void cuv ()
{
    cout<<"afara ploua cu pesti";
}

void cuvant2()
{
    cout<< "         :LOL:ROFL:ROFL" << endl;spatii(x);
cout << "       ____^____" << endl;spatii(x);
cout << " L   _/      [] \\ " << endl;spatii(x);
cout << " O ==_           \\ " << endl;spatii(x);
cout << " L    \___________] " << endl;spatii(x);
cout << "         I     I " << endl;spatii(x);
cout << "       ----------/" << endl;spatii(x);
}

void cuvant ()
{

    cout<<  "ROFL:ROFL:LOL: " << endl;spatii(x);
    cout << "       ____^____" << endl;spatii(x);
    cout << "     _/      [] \\ " << endl;spatii(x);
    cout << "LOL==_           \\ " << endl;spatii(x);
    cout << "      \___________] " << endl;spatii(x);
    cout << "         I     I " << endl;spatii(x);
    cout << "       ----------/" << endl;spatii(x);





}


int main()
{


    int keypress;
    int k=0;
    while (true)
    {
        keypress=getch();

        if (keypress==119)
            y--;
        if (keypress==115)
            y++;
        if (keypress== 97)
            x--;
        if (keypress== 100)
            x++;
        system("cls");

        enter(y);
        spatii(x);




        if (k%2!=0)
        {
            cuvant();
            k++;
        }
        else{
            cuvant2();
            k++;
        }

    }


}
