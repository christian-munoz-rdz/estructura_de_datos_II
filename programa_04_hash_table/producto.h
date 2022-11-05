#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>

using namespace std;

class Producto{
    float precio;
    string pais;
    string nombre;
    public:
    Producto();
    Producto(bool flag);
    string getPais() const;
    void setPais(string pais);
    string getNombre() const;
    void setNombre(string nombre);
    float getPrecio() const;
    void setPrecio(float precio);
    friend ostream& operator<<(ostream &os, const Producto &producto);
};

Producto::Producto(){
    precio = 0.0;
    pais = "";
    nombre = "";
}

Producto::Producto(bool flag){
    cout<<"Ingrese el precio del producto: ";
    cin>>precio;
    cout<<"Ingrese el pais del producto: ";
    cin.ignore();
    getline(cin, pais);
    cout<<"Ingrese el nombre del producto: ";
    getline(cin, nombre);
}

string Producto::getPais()const{
    return pais;
}

void Producto::setPais(string pais){
    this->pais = pais;
}

string Producto::getNombre()const{
    return nombre;
}

void Producto::setNombre(string nombre){
    this->nombre = nombre;
}

float Producto::getPrecio()const{
    return precio;
}

void Producto::setPrecio(float precio){
    this->precio = precio;
}

ostream &operator<<(ostream &os, const Producto &producto){
    cout<<"Precio: "<<producto.precio<<", nombre: "<<producto.nombre<<", pais: "<<producto.pais;
    return os;
}