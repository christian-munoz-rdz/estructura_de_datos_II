#include <iostream>
#include<string>

using namespace std;

class Persona{
private:
    string nombre; 
    string usuario;

public:
    Persona(string,string);
    Persona();

    void setNombre(string);
    void setUsuario(string);

    string getNombre();
    string getUsuario();
};

Persona::Persona(string nombre, string usuario){
    this->nombre = nombre;
    this->usuario = usuario;
}

Persona::Persona(){
    this->nombre = "";
    this->usuario = "";
}

void Persona::setNombre(string nombre){
    this->nombre = nombre;
}

void Persona::setUsuario(string usuario){
    this->usuario = usuario;
}


string Persona::getNombre(){
    return this->nombre;
}

string Persona::getUsuario(){
    return this->usuario;
}
