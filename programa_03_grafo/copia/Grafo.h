#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Vertice;

//Clase Grafo solo tiene un atributo que es una lista de vertices
class Grafo{
    Vertice *h;
public:
    //Meodos de un grafo
    void Inicializa();
    bool Vacio();
    int Tamanio();
    Vertice *GetVertice(string nombre);
    void InsertarArista(Vertice *origen, Vertice *destino, string peso);
    void InsertaVertice(string nombre);
    void ListaAdyacencia();
    void EliminarArista(Vertice *origen, Vertice *destino);
    void Anular();
    void EliminarVertice(Vertice *vert);

    string MostrarPeso(Vertice *origen, Vertice *destino);

};

class Vertice{
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;

};

class Arista{
    Arista *sig;
    Vertice *ady;
    string peso;
    friend class Grafo;

};

//Metodo para inicializar el grafo
void Grafo::Inicializa(){
    h=nullptr;
}

//Metodo para saber si el grafo esta vacio
bool Grafo::Vacio()
{
    if(h==nullptr){
        return true;
    }
    else{
        return false;
    }
}

//Metodo para saber el tamaño del grafo
int Grafo::Tamanio()
{
    Vertice *aux;
    int tamanio=0;
    aux=h;
    while(aux!=nullptr){
        tamanio++;
        aux=aux->sig;
    }
    return tamanio;
}

//Retorna un vertica del grafo
Vertice* Grafo::GetVertice(string nombre)
{
    Vertice *aux;
    aux=h;
    while(aux != nullptr){
        if(nombre==aux->nombre){
            return aux;
        }
        aux=aux->sig;
    }
    return nullptr;
}

//Metodo para insertar una arista en el grafo
void Grafo::InsertarArista(Vertice* origen, Vertice* destino, string peso)
{
    Arista *nueva= new Arista;
    nueva->peso=peso;
    nueva->sig=nullptr;
    nueva->ady=nullptr;

    Arista *aux;

    aux=origen->ady;
    if(aux==nullptr){
        origen->ady=nueva;
        nueva->ady=destino;
    }
    else{
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        aux->sig=nueva;
        nueva->ady=destino;
    }

}

//Metodo para insertar un vertice en el grafo
void Grafo::InsertaVertice(string nombre)
{
    Vertice *nuevo= new Vertice;
    nuevo->nombre=nombre;
    nuevo->sig=nullptr;
    nuevo->ady=nullptr;

    if(Vacio()){
        h=nuevo;
    }
    else{
        Vertice *aux=h;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }

}

//Metodo para recorrer el grafo y mostrar la lista de adyacencia
void Grafo::ListaAdyacencia()
{
    Vertice *VertAux;
    Arista *ArisAux;

    VertAux=h;
    while (VertAux!=nullptr){
        cout<<VertAux->nombre<<"->";
        ArisAux=VertAux->ady;
        while(ArisAux!=nullptr){
            cout<<ArisAux->ady->nombre<<"->";
            ArisAux=ArisAux->sig;
        }
        VertAux=VertAux->sig;
        cout<<endl;
    }
}

//Metodo para eliminar una arista del grafo
void Grafo::EliminarArista(Vertice* origen, Vertice* destino)
{
    int band=0;
    Arista *actual, *anterior;

    actual=origen->ady;

    if(origen == nullptr){
        cout<<"El vertice origen no tiene aristas"<<endl;
    }
    else{
        if(actual->ady == destino){
            origen->ady=actual->sig;
            delete actual;
        }
        else{
            while(actual!=nullptr){
                if(actual->ady==destino){
                    band=1;
                     anterior->sig=actual->sig;
                    delete actual;
                    break;
                }
                anterior=actual;
                actual=actual->sig;
            }
            if(band==0){
                cout<<"Esos dos vertices no estan conectados"<<endl;
            }
        }
    }

}

//Metodo para anular el grafo
void Grafo::Anular()
{
    Vertice *aux;
    while(h!=nullptr){
        aux=h;
        h=h->sig;
        delete aux;
    }

}

//Metodo para eliminar un vertice del grafo
void Grafo::EliminarVertice(Vertice* vert)
{
    Vertice *actual, *anterior;
    Arista *aux;
    actual=h;
    while(actual!=nullptr){
        aux=actual->ady;
        while(aux!=nullptr){
            if(aux->ady==vert){
                EliminarArista(actual,aux->ady);
                break;
            }
            aux=aux->sig;
        }
        actual=actual->sig;
    }
    actual=h;
    if(h==vert){
        h=h->sig;
        delete actual;
    }
    else{
    while(actual!=vert){
        anterior=actual;
        actual=actual->sig;
        }
        anterior->sig=actual->sig;
        delete actual;
    }

}

//Metodo para mostrar el peso de una arista
string Grafo::MostrarPeso(Vertice* origen, Vertice* destino){
    Vertice *aux=h;
    Arista *aris;
    while(aux!=nullptr){
        if(aux==origen){
            aris=aux->ady;
            while(aris->ady!=nullptr){
                    if(aris->ady==destino){
                        return aris->peso;
                    }
                aris=aris->sig;
            }
        }
        aux=aux->sig;
    }


    return 0;
}

