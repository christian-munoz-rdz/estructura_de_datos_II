
#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class Vertice;

class Arista{
    Arista *sig;
    Vertice *ady;
    string peso;
    friend class Grafo;

};
class Vertice{
    Vertice *sig;
    Arista *ady;
    string nombre;
    friend class Grafo;

};

class Grafo{
    Vertice *h;
public:
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

#endif // GRAFO_H_INCLUDED
