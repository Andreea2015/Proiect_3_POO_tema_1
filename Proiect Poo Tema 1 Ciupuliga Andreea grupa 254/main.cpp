#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include <string.h>
using namespace std;

class Plata
{
protected:
    int data;
    int suma;

public:
    Plata(int d=0,int s=0)
    {
        try
        {
            data=d;
            suma=s;

            if(d<0 ||s<0)
                throw -1;
        }
        catch(int x)
        {
            cout<<"NUMAR NEGATIV"<<endl;
        }
    }
    Plata(const Plata &ob)
    {
        data=ob.data;
        suma=ob.suma;
    }
    ~Plata()
    {
        cout<<"destructor"<<endl;
    }
    void set_suma(int s)
    {
        suma=s;
    }
    void set_data(int d)
    {
        data=d;
    }
    int get_suma()
    {
        return suma;
    }
    int get_data()
    {
        return data;
    }
    virtual void citire_plata();
    virtual void afisare_plata();
    Plata& operator=(const Plata& ob);

    friend istream& operator>>(istream &in,Plata &p)
    {
        p.citire_plata();
        return in;
    }

    friend ostream& operator<<(ostream &out,Plata &p)
    {
        p.afisare_plata();
        return out;
    }
};

void Plata::citire_plata()
{
    cout<<"Introdu data"<<endl;
    cin>>data;
    cout<<"Introdu suma"<<endl;
    cin>>suma;
}
void Plata::afisare_plata()
{
    cout<<"Data este "<<data<<endl;
    cout<<"Suma este "<<suma<<endl;

}
Plata& Plata::operator=(const Plata &ob)
{
    if(this != &ob)
    {
        data=ob.data;
        suma=ob.suma;
    }
    return *this;
}



class Numerar:public Plata
{
public:
    Numerar()
    {
        cout<<"constructor"<<endl;
    }
    ~Numerar()
    {
        cout<<"destructor"<<endl;
    }

    void citire_plata()
    {
        cout<<"PLATA NUMERAR"<<endl;
        cout<<"Introdu data "<<endl;
        cin>>data;
        cout<<"Introdu suma "<<endl;
        cin>>suma;
    }
    void afisare_plata()
    {
        cout<<"AFISARE PLATA NUMERAR"<<endl;
        cout<<"Data este "<<data<<endl;
        cout<<"Suma este "<<suma<<endl;

    }

};



class Cec:public Plata
{
public:

    void citire_plata()
    {
        cout<<"PLATA CEC"<<endl;
        cout<<"Introdu data "<<endl;
        cin>>data;
        cout<<"Introdu suma "<<endl;
        cin>>suma;
    }
    void afisare_plata()
    {
        cout<<"AFISARE PLATA CEC"<<endl;
        cout<<"Data este "<<data<<endl;
        cout<<"Suma este "<<suma<<endl;
    }

};



class Card_de_credit:public Plata
{
private:
    int nr_card_de_credit;

public:
    Card_de_credit(int data=0,int suma=0,int nrc=0):Plata(data,suma)
    {
        nr_card_de_credit=nrc;
    }
    Card_de_credit(const Card_de_credit &ob):Plata(ob)
    {
        nr_card_de_credit=ob.nr_card_de_credit;
    }
    ~Card_de_credit()
    {
        cout<<"destructor"<<endl;
    }


    void citire_plata()
    {
        cout<<"PLATA CARD DE CREDIT"<<endl;
        cout<<"Introduceti numarul cardului de credit "<<endl;
        cin>>nr_card_de_credit;
        cout<<"Introdu data "<<endl;
        cin>>data;
        cout<<"Introdu suma "<<endl;
        cin>>suma;
    }
    void afisare_plata()
    {
        cout<<"AFISARE PLATA CARD DE CREDIT"<<endl;
        cout<<"Data este "<<data<<endl;
        cout<<"Suma este "<<suma<<endl;
        cout<<"Numarul cardului de credit este "<<nr_card_de_credit<<endl;
    }

    Card_de_credit& operator=(const Card_de_credit &ob);
};

Card_de_credit& Card_de_credit::operator=(const Card_de_credit &ob)
{
    if(this!=&ob)
        this->Plata::operator=(ob);
    return *this;
}



template <class T>
class Gestiune
{
    int nr_total_de_plati;
    int nr_total_de_plati_numerar;
    int nr_total_de_plati_cec;
    int nr_total_de_plati_cu_cardul;
    T *N;

    unordered_map<int,T>m;


public:

    Gestiune(int numerar=0,int cec=0,int card=0,int plati=0)
    {
        nr_total_de_plati_numerar=numerar;
        nr_total_de_plati_cec=cec;
        nr_total_de_plati_cu_cardul=card;
        nr_total_de_plati=plati;
    }
    Gestiune(const Gestiune &ob)
    {
        nr_total_de_plati_numerar=ob.nr_total_de_plati_numerar;
        nr_total_de_plati_cec=ob.nr_total_de_plati_cec;
        nr_total_de_plati_cu_cardul=ob.nr_total_de_plati_cu_cardul;
        nr_total_de_plati=ob.nr_total_de_plati;
    }
    ~Gestiune()
    {
        cout<<"Destructor"<<endl;
    }

    void set_nr_plati(int nr)
    {
        nr_total_de_plati=nr;
    }
    void set_nr_plati_numerar(int nr)
    {
        nr_total_de_plati_numerar=nr;
    }
    void set_nr_plati_cec(int nr)
    {
        nr_total_de_plati_cec=nr;
    }
    void set_nr_plati_card(int nr)
    {
        nr_total_de_plati_cu_cardul=nr;
    }


    void Afisare_Gestiune();
    void Citire_Gestiune();

    Gestiune operator +=(Gestiune op)
    {
        nr_total_de_plati_numerar=op.nr_total_de_plati_numerar+nr_total_de_plati_numerar;
        nr_total_de_plati_cec=op.nr_total_de_plati_cec+nr_total_de_plati_cec;
        nr_total_de_plati_cu_cardul=op.nr_total_de_plati_cu_cardul+nr_total_de_plati_cu_cardul;
        nr_total_de_plati=op.nr_total_de_plati+nr_total_de_plati;
        return *this;
    }

    void Adunare_numerar(int nr_plati)
    {
        nr_total_de_plati_numerar+=nr_plati;
        cout<<"Numar total de plati numerar: "<<nr_total_de_plati_numerar<<endl;
    }
    void Adunare_cec(int nr_plati)
    {
        nr_total_de_plati_cec+=nr_plati;
        cout<<"Numar total de plati cec: "<<nr_total_de_plati_cec<<endl;
    }
    void Adunare_card(int nr_plati)
    {
        nr_total_de_plati_cu_cardul+=nr_plati;
        cout<<"Numar total de plati cu cardul: "<<nr_total_de_plati_cu_cardul<<endl;
    }
};

template <class T>
void Gestiune<T>::Citire_Gestiune()
{

    N=new T[nr_total_de_plati];


    for(int i=0; i<nr_total_de_plati; i++)
    {
        N[i].citire_plata();
        m.insert(pair<int,T>(i,N[i]));


    }

}
template <class T>
void Gestiune<T>::Afisare_Gestiune()
{

    typename unordered_map<int,T>::iterator p;
    for(p=m.begin(); p!=m.end(); p++)
        cout<<p->first<<" "<<p->second<<endl;
}




template<>
class Gestiune<Card_de_credit>
{
    int nr_clienti;
    char nume_client[20];
    int nr_total_de_plati;
    int nr_total_de_plati_cu_cardul;
    Card_de_credit *N;


    unordered_map<int,Card_de_credit>m;


public:

    Gestiune(int card=0,int plati=0,int nrcl=0)
    {

        nr_total_de_plati_cu_cardul=card;
        nr_total_de_plati=plati;
        nr_clienti=nrcl;
        strcpy(nume_client,"");

    }
    Gestiune(const Gestiune &ob)
    {

        nr_total_de_plati_cu_cardul=ob.nr_total_de_plati_cu_cardul;
        nr_total_de_plati=ob.nr_total_de_plati;
        nr_clienti=ob.nr_clienti;
        strcpy(nume_client,ob.nume_client);
    }
    ~Gestiune()
    {
        cout<<"Destructor"<<endl;
    }

    void set_nr_plati(int nr)
    {
        nr_total_de_plati=nr;
    }


    void set_nr_plati_card(int nr)
    {
        nr_total_de_plati_cu_cardul=nr;
    }


    Gestiune operator +=(Gestiune op)
    {

        nr_total_de_plati_cu_cardul=op.nr_total_de_plati_cu_cardul+nr_total_de_plati_cu_cardul;
        nr_total_de_plati=op.nr_total_de_plati+nr_total_de_plati;
        return *this;
    }



    void Adunare_card(int nr_plati)
    {
        nr_total_de_plati_cu_cardul+=nr_plati;
        cout<<"Numar total de plati cu cardul /client: "<<nr_total_de_plati_cu_cardul<<endl;
    }


    void Citire_Gestiune()
    {

        N=new Card_de_credit[nr_total_de_plati];

        cout<<"Introduceti numarul de clienti "<<endl;
        cin>>nr_clienti;

        for(int j=0; j<nr_clienti; j++)
        {
            cout<<"Introduceti numele clientului "<<endl;
            cin>>nume_client;

            for(int i=0; i<nr_total_de_plati; i++)
            {
                N[i].citire_plata();
                m.insert(pair<int,Card_de_credit>(i,N[i]));


            }
        }

    }

    void Afisare_Gestiune()
    {
        cout<<"Numar clienti: "<<nr_clienti<<endl;
        cout<<"Nume client: "<<nume_client<<endl;

        typename unordered_map<int,Card_de_credit>::iterator p;


        for(p=m.begin(); p!=m.end(); p++)
            cout<<p->first<<" "<<p->second<<endl;
    }
};



int main()
{

    int nr,nr_plati_numerar=0,nr_plati_cec=0,nr_plati_card=0;


    do
    {
        cout<<"CUM VRETI SA PLATITI?"<<endl;
        cout<<endl;
        cout<<"optiunea 1: NUMERAR"<<endl;
        cout<<"optiunea 2: CEC"<<endl;
        cout<<"optiunea 3: CARD DE CREDIT"<<endl;
        cout<<"optiunea 4: IESIRE"<<endl;
        cout<<endl;

        cin>>nr;

        switch(nr)
        {
        case 1:
        {
            cout<<"NUMERAR"<<endl;

            Gestiune<Numerar>N;
            N.set_nr_plati_numerar(nr_plati_numerar);

            cout<<"INTRODUCETI NUMARUL DE PLATI"<<endl;
            cin>>nr_plati_numerar;

            N.set_nr_plati(nr_plati_numerar);
            N.Citire_Gestiune();
            N.Adunare_numerar(nr_plati_numerar);
            N.Afisare_Gestiune();

            cout<<"Tipul acestui obiect este: "<<typeid(N).name()<<endl;



        }
        break;
        case 2:
        {
            cout<<"CEC"<<endl;

            Gestiune<Cec>C;
            C.set_nr_plati_cec(nr_plati_cec);

            cout<<"INTRODUCETI NUMARUL DE PLATI"<<endl;
            cin>>nr_plati_cec;

            C.set_nr_plati(nr_plati_cec);
            C.Citire_Gestiune();
            C.Adunare_cec(nr_plati_cec);
            C.Afisare_Gestiune();

            cout<<"Tipul acestui obiect este: "<<typeid(C).name()<<endl;
        }
        break;
        case 3:
        {
            cout<<"CARD DE CREDIT"<<endl;

            Gestiune<Card_de_credit>CC;
            CC.set_nr_plati_card(nr_plati_card);

            cout<<"INTRODUCETI NUMARUL DE PLATI /CLIENT "<<endl;
            cin>>nr_plati_card;

            CC.set_nr_plati(nr_plati_card);
            CC.Citire_Gestiune();
            CC.Adunare_card(nr_plati_card);
            CC.Afisare_Gestiune();

            cout<<"Tipul acestui obiect este: "<<typeid(CC).name()<<endl;


        }
        break;
        case 4:
        {
            cout<<"IESIRE"<<endl;
        }
        break;
        default:
            cout<<"NUMAR GRESIT"<<endl;
        }
    }
    while(nr!=4);



    return 0;
}


