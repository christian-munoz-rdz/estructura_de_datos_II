#include "Vertice_Arista.h"
#include <string>
#include <fstream>
#include <queue>
#include <list>
#include <stack>

class Grafo{
    Vertice* h;
public:
    Grafo();
    bool Vacio();
    int Tamano();

    Vertice* GetVertice(string);

    void InsertarArista(Vertice*, Vertice*);
    void InsertaVertice(Persona*);
    
    void EliminarArista(Vertice*, Vertice*);
    void EliminarVertice(Vertice*);
    void Anular();

    void Mostrar();

    string to_string();
    void Save();
    
    void Fields_vert(string);
    void Fields_ar(string,string);
    void Load();
};

Grafo::Grafo(){
    h=NULL;
}

bool Grafo::Vacio(){
    return h==NULL;
}

int Grafo::Tamano(){
    Vertice* aux;
    int tamano=0;
    aux=h;
    while(aux!=NULL){
        tamano++;
        aux=aux->sig;
    }
    return tamano;
}

Vertice* Grafo::GetVertice(string usuario){
    Vertice* aux;
    aux=h;
    while(aux != NULL){
        if(usuario==aux->amigo->getUsuario()){
            return aux;
        }
        aux=aux->sig;
    }
    return NULL;
}

void Grafo::InsertarArista(Vertice* origen, Vertice* destino){
    Arista* nueva = new Arista();

    Arista* aux;

    aux=origen->ady;
    if(aux==NULL){
        origen->ady=nueva;
        nueva->ady=destino;
    }
    else{
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nueva;
        nueva->ady=destino;
    }

}

void Grafo::InsertaVertice(Persona* amigo){
    Vertice* nuevo= new Vertice(amigo);

    if(Vacio())
        h=nuevo;
    else{
        Vertice* aux=h;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }

}

void Grafo::Mostrar(){
    Vertice* VertAux;
    Arista* ArisAux;
    
    VertAux=h;
    while (VertAux!=NULL){
        cout<<VertAux->amigo->getNombre() << " Sigue a: ";
        ArisAux= VertAux->ady;
        while(ArisAux!=NULL){
            cout<< ArisAux->ady->amigo->getUsuario() <<", ";
            ArisAux=ArisAux->sig;
        }
        VertAux=VertAux->sig;
        cout<<endl;
    }
}

void Grafo::EliminarArista(Vertice* origen, Vertice* destino)
{
    bool encontrado = false;
    Arista* actual;
    Arista* anterior;

    actual=origen->ady;

    if(origen == NULL){
        cout<<"El vertice origen no tiene aristas"<<endl;
    }
    else{
        if(actual->ady == destino){
            origen->ady=actual->sig;
            delete actual;
        }
        else{
            while(actual!=NULL){
                if(actual->ady==destino){
                    encontrado=true;
                    anterior->sig=actual->sig;
                    delete actual;
                    break;
                }
                anterior=actual;
                actual=actual->sig;
            }
            if(!encontrado){
                cout<<"Relacion no encontrada"<<endl;
            }
        }
    }

}

void Grafo::Anular(){
    Vertice *aux;
    while(h!=NULL){
        aux=h;
        h=h->sig;
        delete aux;
    }
}

void Grafo::EliminarVertice(Vertice* vert)
{
    Vertice* actual;
    Vertice* anterior;
    Arista *aux;
    actual=h;
    while(actual!=NULL){
        aux=actual->ady;
        while(aux!=NULL){
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


string Grafo::to_string(){
    string data;
    Vertice* VertAux;
    Arista* ArisAux;

    VertAux=h;
    while(VertAux!=NULL){
        data += VertAux->save_persona();
        VertAux=VertAux->sig;
    }

    data+='\n';

    VertAux=h;
    while(VertAux!=NULL){
        ArisAux= VertAux->ady;
        while(ArisAux!=NULL){
            data += ArisAux->ady->save_persona();
            ArisAux=ArisAux->sig;
        }
        VertAux=VertAux->sig;
        data+='\n';
    }
    return data;
}

void Grafo::Save(){
    string text = to_string(); 

    ofstream file; 
    file.open("file01.txt",ios::out); 

    if(file.fail()){ 
        cout<<"No se pudo abrir el archivo"<<endl; 
        exit(1); 
    }
    file<<text; 
    file.close(); 
}

void Grafo::Fields_vert(string record){ 
    int i=0; 

    string nombre = ""; 

    while(record[i] != '|'){
        nombre += record[i]; 
        i++;
    } 
    
    i++;
    string usuario = "";  
    
    while(record[i] != '|'){
        usuario += record[i]; 
        i++;
    }
    InsertaVertice(new Persona(nombre,usuario));
}

void Grafo::Fields_ar(string record1, string origen){ 
    int i=0; 

    string nombre = ""; 

    while(record1[i] != '|'){
        nombre += record1[i]; 
        i++;
    } 
    
    i++;
    string usuario = "";  
    
    while(record1[i] != '|'){
        usuario += record1[i]; 
        i++;
    }
    Vertice* origen_ = GetVertice(origen);
    Vertice* destino = GetVertice(usuario);

    InsertarArista(origen_,destino);
}


void Grafo::Load(){

    ifstream file;

    file.open("file01.txt",ios::in);

    if(file.is_open()){
        string line;
        int index = 0;
        int length;
        int i;
        string record;
        Vertice* aux;
        while (getline(file, line)){
            length = line.length();
            i = 0;
            record = "";
            if(index < 1){
                while(i<length){ 
                    if(line[i]!='*'&&line[i]!='\n'){
                        record+=line[i];
                    }
                    else{ 
                        Fields_vert(record);
                        record="";
                    }
                    i++;
                }
                aux = h;
            }
            else{
                string origen = aux->amigo->getUsuario();
                while(i<length){ 
                    if(line[i]!='*'&&line[i]!='\n'){
                        record+=line[i];
                    }
                    else{ 
                        Fields_ar(record,origen);
                        record="";
                    }
                    i++;
                }
                aux = aux->sig;
            }
            index++;
        }

        file.close();
    }
    else{
        return;
    }
}