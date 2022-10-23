#include "Persona.h"
class Vertice;

class Arista{
public:
    Arista* sig;
    Vertice* ady;
    Arista(){
        sig = NULL;
        ady = NULL;
    }
    friend class Grafo;
};

class Vertice{
public:
    Persona* amigo;
    Vertice* sig;
    Arista* ady;
    friend class Grafo;

    Vertice(Persona* amigo){
        this->amigo = amigo;
        this->sig = NULL;
        this->ady = NULL;
    }
    ~Vertice();

    void show();
    string save_persona();
};

Vertice::~Vertice(){
    cout<<"Amigo eliminado"<<endl;
}

string Vertice::save_persona(){
    string data = "";
    data += this->amigo->getNombre() + "|";
    data += this->amigo->getUsuario() + "|*";
    return data;
}

