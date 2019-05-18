#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include<limits>
using namespace std;

struct furnizori
{
    string numeFurnizor;
    int codFiscal;
    int nrProd;
    struct produselele
    {
        string produse;
    } P[50];
    string strada;
    int nr;
    string numeContact;
    string prenumeContact;
    string nrTel;

} R[50];
int main()
{
    int it=0,x,i,j,k,auxiliar;
    string furnizori1[50];
    bool done = false;
    string argument,fruct;
    ifstream file1("furnizori.txt");
    while(!file1.eof())
    {
        file1>>R[it].numeFurnizor;
        file1>>R[it].codFiscal;
        file1>>R[it].nrProd;
        auxiliar=R[it].nrProd;
        for(i=0; i<auxiliar; i++)
        {
            file1>>R[it].P[i].produse;

        }
        file1>>R[it].strada;
        file1>>R[it].nr;
        file1>>R[it].numeContact;
        file1>>R[it].prenumeContact;
        file1>>R[it].nrTel;
        it++;
    }
    do
    {
        cout<<"1.Pentru a afisa lista furnizorilor apasati tasta 1 \n";
        cout<<"2.Pentru a adauga un nou furnizor apasati tasta 2 \n";
        cout<<"3.Pentru a sterge un furnizor dupa denumire apasati tasta 3 \n";
        cout<<"4.Pentru a cauta un furnizor dupa cod fiscal apasati tasta 4  \n";
        cout<<"5.Pentru a adauga produse unui anumit furnizor apasati tasta 5 \n";
        cout<<"6.Pentru a sterge un produs de la un anumit furnizor apasati tasta 6 \n";
        cout<<"7.Pentru a afisa furnizorii sortati dupa nume apasati tasta 7 \n";
        cout<<"0.Pentru a iesi apasati tasta 0 \n";
        cin>>x;

        //IN CAZ DE EROARE
        if(cin.fail())   // NU S-A INTRODUS O CIFRA
        {
            cin.clear(); // SE GOLESC PARAMETRII LOCALI
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // IGNORA BUFFER-UL
        }

        switch(x)
        {
        case 1:
            cout<<"Lista furnizorilor este urmatoare: \n";
            for(i=0; i<it; i++)
            {
                cout<<R[i].numeFurnizor<<" Cod Fiscal:"<<R[i].codFiscal<<"\n\tProdusele oferite: ";
                for(int j=0; j<R[i].nrProd; j++)
                    cout<<R[i].P[j].produse<<" ";
                cout<<"\n\tLocatie: Str."<<R[i].strada<<" Nr."<<R[i].nr<<"\n\tPersoana Contact: "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel<<endl;
            }

            break;

        case 2:
        {
            cout<<"Introduceti numele firmei, codul fiscal, numarul de produse, produsele cu un spatiu intre ele, strada(cu liniuta in caz ca strada are mai multe nume), numarul, prenume si nume contact si numar de telefon: ";
            ofstream file2;
            file2.open("furnizori.txt", std::ios_base::trunc);
            cin>>R[it].numeFurnizor>>R[it].codFiscal>>R[it].nrProd;
            auxiliar=R[it].nrProd;
            for(i=0; i<auxiliar; i++)
            {
                cin>>R[it].P[i].produse;

            }
            cin>>R[it].strada>>R[it].nr>>R[it].numeContact>>R[it].prenumeContact>>R[it].nrTel;
            it++;
            for(i=0; i<it-1; i++)
            {
                file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
                for(j=0; j<R[i].nrProd; j++)
                    file2<<R[i].P[j].produse<<" ";
                file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel<<endl;
            }
            file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
            for(j=0; j<R[i].nrProd; j++)
                file2<<R[i].P[j].produse<<" ";
            file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel;

            file2.close();
            break;
        }

        case 3:
        {
            cout<<"Introduceti numele furnizorului(conteaza sa fie exact cu litere mari/mici): ";
            cin>>argument;
            for(i=0; i<it; i++)
            {
                std::size_t found=R[i].numeFurnizor.find(argument);
                if(found!=std::string::npos)
                {
                    for(j=i; j<it-1; j++)
                    {
                        R[j].numeFurnizor=R[j+1].numeFurnizor;
                        R[j].codFiscal=R[j+1].codFiscal;
                        R[j].nrProd=R[j+1].nrProd;
                        auxiliar=R[j].nrProd;
                        for(k=0; k<auxiliar; k++)
                        {
                            R[j].P[k].produse=R[j+1].P[k].produse;

                        }
                        R[j].strada=R[j+1].strada;
                        R[j].nr=R[j+1].nr;
                        R[j].numeContact=R[j+1].numeContact;
                        R[j].prenumeContact=R[j+1].prenumeContact;
                        R[j].nrTel=R[j+1].nrTel;
                    }
                    it--;
                }
            }
            ofstream file2;
            file2.open("furnizori.txt", std::ios_base::trunc);
            for(i=0; i<it-1; i++)
            {
                file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
                for(j=0; j<R[i].nrProd; j++)
                    file2<<R[i].P[j].produse<<" ";
                file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel<<endl;
            }
            file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
            for(j=0; j<R[i].nrProd; j++)
                file2<<R[i].P[j].produse<<" ";
            file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel;
            file2.close();
            break;
        }


        case 4:
        {
            cout<<"Introduceti codul furnizorului: ";
            cin>>auxiliar;
            for(i=0; i<it; i++)
            {
                if(R[i].codFiscal == auxiliar)
                {
                    cout<<R[i].numeFurnizor<<" Cod Fiscal:"<<R[i].codFiscal<<"\n\tProdusele oferite: ";
                    for(int j=0; j<R[i].nrProd; j++)
                        cout<<R[i].P[j].produse<<" ";
                    cout<<"\n\tLocatie: Str."<<R[i].strada<<" Nr."<<R[i].nr<<"\n\tPersoana Contact: "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel<<endl;
                }
            }
            break;
        }


        case 5:
        {
            int nrProdAux;
            string ProduseAux[30];
            cout<<"Introduceti codul furnizorului: ";
            cin>>auxiliar;
            cout<<"\nIntroduceti numarul de produse pe care doriti sa le adaugati: ";
            cin>>nrProdAux;
            cout<<"\nIntroduceti produsele pe care doriti sa le adaugati cu cate un spatiu intre ele: ";
            for(i=0; i<nrProdAux; i++)
                cin>>ProduseAux[i];
            for(i=0; i<it; i++)
            {
                if(R[i].codFiscal == auxiliar)
                {
                    k=0;
                    R[i].nrProd+=nrProdAux;
                    for(j=(R[i].nrProd-nrProdAux); j<R[i].nrProd; j++)
                    {
                        R[i].P[j].produse=ProduseAux[k];
                        k++;
                    }

                }
            }
            ofstream file2;
            file2.open("furnizori.txt", std::ios_base::trunc);
            for(i=0; i<it-1; i++)
            {
                file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
                for(j=0; j<R[i].nrProd; j++)
                    file2<<R[i].P[j].produse<<" ";
                file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel<<endl;
            }
            file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
            for(j=0; j<R[i].nrProd; j++)
                file2<<R[i].P[j].produse<<" ";
            file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel;
            file2.close();
            break;
        }

        case 6:
        {
            int nrProdAux,l;
            string ProduseAux[30];
            cout<<"Introduceti codul furnizorului: ";
            cin>>auxiliar;
            cout<<"\nIntroduceti numarul de produse pe care doriti sa le stergeti: ";
            cin>>nrProdAux;
            cout<<"\nIntroduceti produsele pe care doriti sa le stergeti cu cate un spatiu intre ele: ";
            for(i=0; i<nrProdAux; i++)
                cin>>ProduseAux[i];
            for(i=0; i<it; i++)
            {
                if(R[i].codFiscal == auxiliar)
                {
                    for(j=0; j<R[i].nrProd; j++)
                    {
                        for(k=0; k<nrProdAux; k++)
                        {
                            if(R[i].P[j].produse==ProduseAux[k])
                            {
                                for(l=j; l<R[i].nrProd; l++)
                                    R[i].P[l].produse=R[i].P[l+1].produse;
                                j--;
                            }
                        }
                    }
                    R[i].nrProd-=nrProdAux;
                }
            }

            ofstream file2;
            file2.open("furnizori.txt", std::ios_base::trunc);
            for(i=0; i<it-1; i++)
            {
                file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
                for(j=0; j<R[i].nrProd; j++)
                    file2<<R[i].P[j].produse<<" ";
                file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel<<endl;
            }
            file2<<R[i].numeFurnizor<<" "<<R[i].codFiscal<<" "<<R[i].nrProd<<" ";
            for(j=0; j<R[i].nrProd; j++)
                file2<<R[i].P[j].produse<<" ";
            file2<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].numeContact<<" "<<R[i].prenumeContact<<" "<<R[i].nrTel;
            file2.close();

        }

        case 7:
        {
            cout<<"Lista furnizorilor sortati dupa nume:"<<endl;
            for(i=0; i<it; i++)
                furnizori1[i]=R[i].numeFurnizor;
            for(i=0; i<it; i++)
            {
                for(j=i+1; j<it; j++)
                {
                    if(furnizori1[j]<furnizori1[i])
                    {
                        string aux;
                        aux=furnizori1[i];
                        furnizori1[i]=furnizori1[j];
                        furnizori1[j]=aux;
                    }
                }
            }
            for(i=0; i<it; i++)
            {
                for(j=0; j<it; j++)
                    if(furnizori1[i]==R[j].numeFurnizor)
                    {
                        cout<<R[j].numeFurnizor<<" Cod Fiscal:"<<R[j].codFiscal<<"\n\tProdusele oferite: ";
                        for(int k=0; k<R[i].nrProd; k++)
                            cout<<R[j].P[k].produse<<" ";
                        cout<<"\n\tLocatie: Str."<<R[j].strada<<" Nr."<<R[j].nr<<"\n\tPersoana Contact: "<<R[j].numeContact<<" "<<R[j].prenumeContact<<" "<<R[j].nrTel<<endl;
                    }
            }
            break;
        }
        case 0:
            cout<<"La revedere!";
            done=true;
            break;

        }
        cout<<"\n";
    }
    while(!done);

    return 0;
}
