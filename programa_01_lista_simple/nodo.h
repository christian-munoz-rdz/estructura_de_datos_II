#include <iostream>
#include "alumno.h"

class Nodo{
private:
    Alumno Datos;
    Nodo *Siguiente;
    Nodo *Anterior;
    friend class Lista;
public:
    Nodo();

    void set_Datos(const Alumno&);
    void set_Siguiente(Nodo*);
    void set_Anterior(Nodo*);

    std::string get_Data()const;
    std::string get_Data2()const;
    Nodo* get_Siguiente()const;
    Nodo* get_Anterior()const;

};

Nodo::Nodo()
{
    Siguiente=NULL;
    Anterior=NULL;
}

void Nodo::set_Datos(const Alumno& a1)
{
    Datos=a1;
}

void Nodo::set_Siguiente(Nodo* s)
{
  Siguiente=s;
}

void Nodo::set_Anterior(Nodo* a)
{
    Anterior=a;
}

string Nodo::get_Data() const
{
    return Datos.toString();
}

string Nodo::get_Data2() const
{
    return Datos.toString2();
}


Nodo* Nodo::get_Siguiente() const
{
    return Siguiente;
}

Nodo* Nodo::get_Anterior() const
{
    return Anterior;
}
