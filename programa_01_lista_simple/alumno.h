#include <iostream>
#include<string>

using namespace std;

class Alumno{
private:
    string Nombre;
    string Codigo;
    string Carrera;
    string Promedio;

public:
    Alumno();

    void set_Nombre(const string&);
    void set_Codigo(const string&);
    void set_Carrera(const string&);
    void set_Promedio(const string&);

    string toString() const;
    string toString2() const;

    string get_Nombre()const;
    string get_Codigo()const;
    string get_Carrera()const;
    string get_Promedio()const;

    Alumno& operator= (const Alumno&);
    bool operator==(const Alumno&);
};

Alumno::Alumno(){}

void Alumno::set_Nombre(const string& n)
{
    Nombre=n;
}

void Alumno::set_Codigo(const string& c)
{
    Codigo=c;
}

void Alumno::set_Carrera(const string& c)
{
    Carrera=c;
}

void Alumno::set_Promedio(const string& p)
{
    Promedio=p;
}

string Alumno::toString() const
{  string resultado;
    resultado+=Nombre+"||"+Codigo+"||"+Carrera+"||"+Promedio;
    return resultado;
}
string Alumno::toString2() const
{
    string resultado;
    resultado+=Nombre+"|"+Codigo+"|"+Carrera+"|"+Promedio+"|"+"*";
    return resultado;
}


string Alumno::get_Nombre() const
{
    return Nombre;
}

string Alumno::get_Codigo() const
{
    return Codigo;
}

string Alumno::get_Carrera() const
{
    return Carrera;
}

string Alumno::get_Promedio() const
{
    return Promedio;
}

Alumno& Alumno::operator=(const Alumno& a1)
{
    Nombre=a1.Nombre;
    Codigo=a1.Codigo;
    Carrera=a1.Carrera;
    Promedio=a1.Promedio;
    return *this;
}

bool Alumno::operator==(const Alumno& c1)
{
    return Codigo==c1.Codigo;
}