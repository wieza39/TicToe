#include <iostream>
#include <unistd.h>
#include <ctime>

using namespace std;

int losowanie ()
{
    int los;
    srand(time(0));
    los = (std::rand()%2)+1;
    return los;
}

void czysta_plansza(int tab[])
{
    for (int i=0; i<9; i++)
        {
            tab[i] = 0;
        }
}

void plansza(int tab[])
{
    for (int i=0; i<9; i++)
        {
            if (i%3)
            {
                cout << " | ";
            }else
                cout << "\n";
                    if (tab[i]==0) cout << " ";
                    if (tab[i]==1) cout << "X";
                    if (tab[i]==2) cout << "O";
        }
        std::cout << "\n";
}

int sprawdz(int tab[])
{

if (tab[0] == tab[1] && tab[1] == tab[2])
    {
        if (tab[0]==1 || tab[0]==2)
            return 1;
    }
if (tab[3] == tab[4] && tab[4] == tab[5])
    {
        if (tab[3]==1 || tab[3]==2)
            return 1;
    }
if (tab[6] == tab[7] && tab[7] == tab[8])
    {
        if (tab[6]==1 || tab[6]==2)
            return 1;
    }
if (tab[0] == tab[3] && tab[3] == tab[6])
    {
        if (tab[0]==1 || tab[0]==2)
            return 1;
    }
if (tab[1] == tab[4] && tab[4] == tab[7])
    {
        if (tab[1]==1 || tab[1]==2)
            return 1;
    }
if (tab[2] == tab[5] && tab[5] == tab[8])
    {
        if (tab[2]==1 || tab[2]==2)
            return 1;
    }
if (tab[0] == tab[4] && tab[4] == tab[8])
    {
        if (tab[0]==1 || tab[0]==2)
            return 1;
    }
if (tab[6] == tab[4] && tab[4] == tab[2])
    {
        if (tab[6]==1 || tab[6]==2)
            return 1;
    }
if (tab[0]!=0 && tab[1]!=0 && tab[2]!=0 && tab[3]!=0 && tab[4]!=0 && tab[5]!=0 && tab[6]!=0 && tab[7]!=0 && tab[8]!=0)
    {
    return 2;
    }
else return 0;
}

int strategia_CPU(int tab[], int los)
{

//jesli CPU zaczyna
if(los==1)
{
// uzupelnienie
if(tab[0]==1 && tab[2]==1 && tab[1]==0) return tab[1]=1;
if(tab[0]==1 && tab[6]==1 && tab[3]==0) return tab[3]=1;
if(tab[0]==1 && tab[8]==1 && tab[4]==0) return tab[4]=1;
if(tab[2]==1 && tab[6]==1 && tab[4]==0) return tab[4]=1;
if(tab[2]==1 && tab[8]==1 && tab[5]==0) return tab[5]=1;
if(tab[6]==1 && tab[8]==1 && tab[7]==0) return tab[7]=1;
if(tab[3]==1 && tab[5]==1 && tab[4]==0) return tab[4]=1;
if(tab[1]==1 && tab[7]==1 && tab[4]==0) return tab[4]=1;

//kontry na koncu gry
if(tab[0]==1 && tab[8]==1 && tab[6]==1 && tab[3]==2 && tab[7]==0)              return tab[7]=1;
if(tab[0]==1 && tab[8]==1 && tab[6]==1 && tab[7]==2 && tab[3]==0)              return tab[3]=1;
if(tab[0]==1 && tab[8]==1 && tab[2]==1 && tab[1]==2 && tab[5]==0)              return tab[5]=1;
if(tab[0]==1 && tab[8]==1 && tab[2]==1 && tab[5]==2 && tab[1]==0)              return tab[1]=1;

//kontra rogi
if(tab[0]==2 && tab[2]==2 && tab[1]==0)              return tab[1]=1;
if(tab[0]==2 && tab[6]==2 && tab[3]==0)              return tab[3]=1;
if(tab[8]==2 && tab[2]==2 && tab[5]==0)              return tab[5]=1;
if(tab[8]==2 && tab[6]==2 && tab[7]==0)              return tab[7]=1;

//kontra ze srodkiem
if(tab[4]==2 && tab[1]==2 && tab[7]==0)              return tab[7]=1;
if(tab[4]==2 && tab[2]==2 && tab[6]==0)              return tab[6]=1;
if(tab[4]==2 && tab[3]==2 && tab[5]==0)              return tab[5]=1;
if(tab[4]==2 && tab[5]==2 && tab[3]==0)              return tab[3]=1;
if(tab[4]==2 && tab[6]==2 && tab[2]==0)              return tab[2]=1;
if(tab[4]==2 && tab[7]==2 && tab[1]==0)              return tab[1]=1;

//poczatek rozgrywki
if(tab[0]==0)                                        return tab[0]=1;
if(tab[8]==0 || tab[4]==2)                           return tab[8]=1;
if(tab[0]==1 && tab[8]==1 && tab[2]==0)              return tab[2]=1;
if(tab[0]==1 && tab[8]==1 && tab[6]==0)              return tab[6]=1;

//wariant z zajetym rogiem
if(tab[0]==1 && tab[8]==2 && tab[6]==2 && tab[5]==2)  return tab[3]=1;
if(tab[0]==1 && tab[8]==2 && tab[6]==2 && tab[3]==2)  return tab[5]=1;
if(tab[0]==1 && tab[8]==2 && tab[2]==0)              return tab[2]=1;
if(tab[0]==1 && tab[8]==2 && tab[2]==2)              return tab[6]=1;
if(tab[0]==1 && tab[8]==2)                           return tab[4]=1;
}

// jesli gracz zaczyna
if(los==2)
{
    //uzupelnienie

    if(tab[0]==2 && tab[2]==2 && tab[1]==0) return tab[1]=2;
    if(tab[0]==2 && tab[6]==2 && tab[3]==0) return tab[3]=2;
    if(tab[0]==2 && tab[8]==2 && tab[4]==0) return tab[4]=2;
    if(tab[2]==2 && tab[6]==2 && tab[4]==0) return tab[4]=2;
    if(tab[2]==2 && tab[8]==2 && tab[5]==0) return tab[5]=2;
    if(tab[6]==2 && tab[8]==2 && tab[7]==0) return tab[7]=2;
    if(tab[3]==2 && tab[5]==2 && tab[4]==0) return tab[4]=2;
    if(tab[1]==2 && tab[7]==2 && tab[4]==0) return tab[4]=2;
    if(tab[4]==2 && tab[0]==2 && tab[8]==0) return tab[8]=2;
    if(tab[4]==2 && tab[8]==2 && tab[0]==0) return tab[0]=2;
    if(tab[4]==2 && tab[2]==2 && tab[6]==0) return tab[6]=2;
    if(tab[4]==2 && tab[6]==2 && tab[2]==0) return tab[2]=2;

    //kontra srodek
    if(tab[4]==1 && tab[1]==1 && tab[7]==0)              return tab[7]=2;
    if(tab[4]==1 && tab[5]==1 && tab[3]==0)              return tab[3]=2;
    if(tab[4]==1 && tab[7]==1 && tab[1]==0)              return tab[1]=2;
    if(tab[4]==1 && tab[3]==1 && tab[5]==0)              return tab[5]=2;
    if(tab[4]==1 && tab[2]==1 && tab[6]==0)              return tab[6]=2;
    if(tab[4]==1 && tab[6]==1 && tab[2]==0)              return tab[2]=2;

    if(tab[0]==2 && tab[8]==2 && tab[2]==0)              return tab[2]=2;
    if(tab[0]==2 && tab[8]==2 && tab[6]==0)              return tab[6]=2;

    //kontra boki
    if(tab[2]==1 && tab[5]==1 && tab[8]==0)              return tab[8]=2;
    if(tab[0]==1 && tab[2]==1 && tab[1]==0)              return tab[1]=2;
    if(tab[0]==1 && tab[6]==1 && tab[3]==0)              return tab[3]=2;
    if(tab[2]==1 && tab[8]==1 && tab[5]==0)              return tab[5]=2;
    if(tab[6]==1 && tab[8]==1 && tab[7]==0)              return tab[7]=2;
    if(tab[3]==1 && tab[5]==1 && tab[4]==0)              return tab[4]=2;
    if(tab[1]==1 && tab[7]==1 && tab[4]==0)              return tab[4]=2;
    if(tab[8]==1 && tab[5]==1 && tab[2]==0)              return tab[2]=2;

    //odpowiedz na bledne ruchy gracza
    if(tab[1]==1 && tab[6]==1 && tab[4]==0)              return tab[4]=2;
    if(tab[5]==1 && tab[6]==1 && tab[4]==0)              return tab[4]=2;
    if(tab[7]==1 && tab[2]==1 && tab[4]==0)              return tab[4]=2;
    if(tab[3]==1 && tab[9]==1 && tab[4]==0)              return tab[4]=2;

    //srodek lub boki start
    if(tab[4]==1 && tab[0]==2)                           return tab[8]=2;
    if(tab[4]==1 || tab[1]==1 || tab[3]==1 || tab[5]==1 || tab[7]==1) return tab[0]=2;

    //start rog
    if(tab[0]==1 && tab[8]==1 && tab[2]==0)              return tab[2]=2;
    if(tab[2]==1 && tab[6]==1 && tab[0]==0)              return tab[0]=2;
    if(tab[0]==1 || tab[2]==1 || tab[6]==1 || tab[8]==1)              return tab[4]=2;
    }
}


void ruch(int tab[], int gracz, int los, int wybor)
{
int pole,p;

// dla graczy
if (gracz == 1 && wybor == 1 || wybor == 2 && los == 2)
 {
   p = 1;
 }else if (gracz == 2 && wybor == 1 || wybor == 2 && los == 1)
   {
   p = 2;
   }

if (wybor == 1 || wybor == 2 && gracz == 1)
  {
    std::cout << "\nGracz " << gracz << ". Wybierz pole: ";
    std::cin >> pole;
    if(tab[pole-1]==1 || tab[pole-1]==2)
    {
        do
        {
            std::cout << "To pole jest juz zajete. Wybierz puste: ";
            std::cin >> pole;
        }
        while(tab[pole-1]==1 || tab[pole-1]==2);
        tab[pole-1]=p;
    }
    else
    tab[pole-1]=p;
    }else if (wybor == 2 && gracz == 2)
    {
    strategia_CPU(tab,los);
    cout << "CPU wybral pole.\n";
    plansza(tab);
    }
}

void rozgrywka(int tab[], int wybor, int los)
{
int pole;
int wynik_1 = 0;
int wynik_2 = 0;
int gracz;

if (los == 1)
{
gracz = 2;
}else if (los == 2)
{
gracz = 1;
}

while(wynik_1 != 3 || wynik_2 != 3) {

 std::cout << "###########################################\n";
 std::cout << "\nAktualny wynik (Gracz1:Gracz2): " << wynik_1 << " : " << wynik_2 << "\n";

    if (wynik_1 == 3 || wynik_2 == 3)
      break;
    else
         czysta_plansza(tab);
         plansza(tab);
        do{
            ruch(tab,gracz,los,wybor);
            sprawdz(tab);
                if (sprawdz(tab)==1)
                    {
                    std::cout << "\nBrawo! Gracz " << gracz << " wygrywa!\n\n";
                        if (gracz == 1)
                           {
                            wynik_1++;
                            }else if (gracz == 2)
                            {
                            wynik_2++;
                            }
                break;
            }else if (sprawdz(tab)==2)
            {
             std::cout << "Remis.\n";
             break;
            }
            if (gracz == 1)
            {
                gracz = 2;
            }else if (gracz == 2)
                gracz = 1;
            }while(tab[pole-1]!=0);
    }
    if (wynik_1 == 3) std::cout << "\n\n**** KONIEC GRY! WYGRAL GRACZ 1! ****\n";
    else if (wynik_2 == 3) std::cout << "\n\n**** KONIEC GRY! WYGRAL GRACZ 2! ****\n";
}


int main()
{
    int wybor;
    int los = losowanie();
    int tab[9] = {};
    std::cout << "###########################################\n";
    std::cout << "                   Witaj!\n\n";
    std::cout << "Przed Toba klasyczna gra w kolko i krzyzyk.\n\n";
    std::cout << "###########################################\n";
    std::cout << "Ponizej legenda pola gry. \nWskazujac miejsce postawienia kolka lub krzyzyka,\nwybierz odpowiedni numer pola:\n\n";
    std::cout << "#############\n";
    std::cout << "# " << "1" << " | " << "2" << " | " << "3" << " #\n";
    std::cout << "# --------- #\n";
    std::cout << "# " << "4" << " | " << "5" << " | " << "6" << " #\n";
    std::cout << "# --------- #\n";
    std::cout << "# " << "7" << " | " << "8" << " | " << "9" << " #\n";
    std::cout << "#############\n\n";
    std::cout << "Jak gramy? Mozesz zagrac z kolezanka/kolega lub ze mna. \nKtora wybierasz? Podaj 1 albo 2, aby wybrac. \n";
    std::cout << "   1. Gram z kolezanka lub kolega.\n";
    std::cout << "   2. Gram z Toba.\n";
    std::cout << "Wybieram opcje nr: ";
do
{
    std::cin >> wybor;
    switch(wybor)
    {
        case 1: std::cout << "\nWolisz grac ze znajomym.. ok. Powodzenia!\n\n";
            break;
        case 2: std::cout << "\nGrasz ze mna. Swietnie! Nie tracmy czasu\n\n";
            break;
        default:
            std::cout << "Nie ma takiej opcji do wyboru... Wybierz poprawna: ";
    }

    if (wybor == 2 && los == 1)
     {
        std::cout << "###########################################\n\n";
        cout << "Pozwolilem sobie odrazu wylosowac kolejke..\n Oczywiscie ja zaczynam!\n\n";
     }else if (wybor == 2 && los == 2)
        {
        std::cout << "###########################################\n\n";
        cout << "Zaczynaj pierwsza/-y..\n\n";
        }
}while(wybor != 1 && wybor != 2);

    rozgrywka(tab, wybor, los);

    return 0;
}
