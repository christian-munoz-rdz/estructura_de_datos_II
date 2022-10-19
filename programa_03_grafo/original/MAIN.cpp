#include <iostream>
#include "grafo.h"

using namespace std;

int main()
{
    Grafo g1;
    g1.Inicializa();
    int opc;
    do{
    cout << "1.Insertar vertice" << endl;
    cout << "2.Insertar arista" << endl;
    cout << "3.Mostrar lista de adyacencia" << endl;
    cout << "4.Mostrar distancia" << endl;
    cout << "5.Eliminar vertice" << endl;
    cout << "6.Eliminar arista" << endl;
    cout << "0.Salir" << endl;


    cout<<"Que opcion eliges?"<<endl;
    cin>>opc;
    switch(opc){
    case 1:{ string c1,c2,c3,c4;Vertice v1;
        //cout<<"Ingresa el nombre de la ciudad:"<<endl;
        //cin.ignore();
        //getline(cin,nom);
        c1="Guadalajara";
        c2="Los Cabos";
        c3="Culiacan";
        c4="Nayarit";
        g1.InsertaVertice(c1);
        g1.InsertaVertice(c2);
        g1.InsertaVertice(c3);
        g1.InsertaVertice(c4);
        system("pause");break;
    }
    case 2:{string o1,o2,o3,o4,o5, d1,d2,d3,d4,d5;string p1,p2,p3,p4,p5; Vertice *O1,*O2,*O3,*O4,*O5, *D1,*D2,*D3,*D4,*D5;
        /*cout<<"Ingresa el origen:"<<endl;cin.ignore();
        getline(cin,origen);
        cout<<"Ingresa el destino"<<endl;
        getline(cin,destino);
        cout<<"Ingresa el tiempo:"<<endl;
        cin>>peso;*/
        o1="Guadalajara";
        d1="Nayarit";
        p1="2:30";
        O1=g1.GetVertice(o1);
        D1=g1.GetVertice(d1);
        g1.InsertarArista(O1,D1,p1);

        o2="Guadalajara";
        d2="Culiacan";
        p2="6";
        O2=g1.GetVertice(o1);
        D2=g1.GetVertice(d2);
        g1.InsertarArista(O2,D2,p2);

        o3="Nayarit";
        d3="Culiacan";
        p3="4:30";
        O3=g1.GetVertice(o3);
        D3=g1.GetVertice(d3);
        g1.InsertarArista(O3,D3,p3);

        o4="Culiacan";
        d4="Los Cabos";
        p4="9:30";
        O4=g1.GetVertice(o4);
        D4=g1.GetVertice(d4);
        g1.InsertarArista(O4,D4,p4);

        o5="Los Cabos";
        d5="Guadalajara";
        p5="12:30";
        O5=g1.GetVertice(o5);
        D5=g1.GetVertice(d5);
        g1.InsertarArista(O5,D5,p5);

        system("pause");break;
    }
    case 3: g1.ListaAdyacencia();system("pause");break;
    case 4:{string origen, destino; Vertice *v1, *v2;
    cout<<"Ciudad de origen:"<<endl;cin.ignore();
    getline(cin,origen);
    cout<<"Ciudad de destino:"<<endl;
    getline(cin,destino);
    v1=g1.GetVertice(origen);
    v2=g1.GetVertice(destino);
    cout<<endl<<"El tiempo es: "<<g1.MostrarPeso(v1,v2)<<" horas"<<endl;system("pause");break;
    }
    case 5:{string nom; Vertice *v1;
    cout<<"Cual es la ciudad"<<endl;cin.ignore();
    getline(cin,nom);
    v1=g1.GetVertice(nom);
    g1.EliminarVertice(v1);system("pause");break;
    }
    case 6:{string origen, destino; Vertice *v1, *v2;
    cout<<"Ciudad de origen: "<<endl;cin.ignore();
    getline(cin,origen);
    cout<<"Ciudad de destino: "<<endl;
    getline(cin,destino);
    v1=g1.GetVertice(origen);
    v2=g1.GetVertice(destino);
    g1.EliminarArista(v1,v2);system("pause");break;
        }

    }
    system("cls");

    }
    while(opc!=0);
    return 0;
}
