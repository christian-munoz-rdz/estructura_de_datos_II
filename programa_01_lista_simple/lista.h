#include "nodo.h"
#include<fstream>
#include<string>

class Lista{
private:
    Alumno a1;
    Nodo* Ancla;
public:
    Lista();

    bool Vacia();
    void Insertar(Nodo*, Alumno&);
    void Eliminar(Alumno&);
    std::string Mostrar_Lista();
    std::string Mostrar_Dato(Alumno&);
    Nodo* Buscar(Alumno&);
    void Vaciar();
    Nodo* UltimaPos();
    Nodo* PrimeraPos();

    void Guardar();

    void Campos(std::string&);
    void Cargar();

};

Lista::Lista(){
	Ancla = NULL;
}

bool Lista::Vacia()
{
    return Ancla;
}

void Lista::Insertar(Nodo* p, Alumno& a1)
{
    Nodo* aux= new Nodo;
    aux->set_Datos(a1);
    if(p==NULL){
        aux->set_Siguiente(Ancla);
        if(Ancla!=NULL){
            Ancla->set_Anterior(aux);
        }
        Ancla=aux;
        }
        else{
            aux->set_Anterior(p);
            aux->set_Siguiente(p->get_Siguiente());
            if(p->Siguiente!=NULL){
            p->get_Siguiente()->set_Anterior(aux);
            }
            p->set_Siguiente(aux);
        }

}

void Lista::Eliminar(Alumno& a1)
{
   Nodo* p= Buscar(a1);
    if(Vacia()){
        cout<<"No existe ningun elemento"<<endl;
    }
    Nodo* aux=p;
    if(p->get_Anterior()!=NULL){
        p->get_Anterior()->set_Siguiente(p->get_Siguiente());
    }
    if(p->get_Siguiente()!=NULL){
        p->get_Siguiente()->set_Anterior(p->get_Anterior());
    }
    if(p==Ancla){
        Ancla=Ancla->get_Siguiente();
    }

    delete aux;
}

string Lista::Mostrar_Lista()
{ Nodo* x=Ancla;
string resultado;
if(Vacia()){
    cout<<"La lista esta vacia"<<endl;
}
while(x!=NULL){
    resultado+=x->get_Data()+"\n";
    x=x->get_Siguiente();
}
return resultado;
}

string Lista::Mostrar_Dato(Alumno& a1)
{
   return Buscar(a1)->get_Data();
}

Nodo* Lista::Buscar(Alumno& a1)
{
    Nodo* aux=Ancla;
    while(aux!=NULL){
        if(aux->Datos.get_Codigo()==a1.get_Codigo()){
            return aux;
        }
        aux=aux->get_Siguiente();
    }
    return NULL;
}

void Lista::Vaciar()
{
    Nodo* aux;
    while(Ancla!=NULL){
        aux=Ancla;
        Ancla=Ancla->get_Siguiente();
        delete aux;
    }
}

Nodo* Lista::UltimaPos()
{
    if(Ancla==NULL){
        return Ancla;
    }
    Nodo* aux=Ancla;
    while(aux->get_Siguiente()!=NULL){
        aux=aux->get_Siguiente();
    }
    return aux;
}

Nodo* Lista::PrimeraPos()
{
    return Ancla;
}
void Lista::Guardar()
{   Nodo* x=Ancla;
string resultado;
while(x!=NULL){
    resultado+=x->get_Data2();
    x=x->get_Siguiente();
}
    ofstream archivo;
    archivo.open("file01.txt",ios::out);
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    archivo<<resultado;
    archivo.close();
}

void Lista::Campos(std::string& registro)
{
    int i=0;
    cout<<registro<<endl;
    string Nombre="";
    while(registro[i]!='|'){
        Nombre+=registro[i];
        i++;
    }
    cout<<Nombre<<endl;
    i++;

    string Codigo="";
    while(registro[i]!='|'){
        Codigo+=registro[i];
        i++;
    }
    cout<<Codigo<<endl;
    i++;

    string Carrera="";
    while(registro[i]!='|'){
        Carrera+=registro[i];
        i++;
    }
    cout<<Carrera<<endl;
    i++;

    string Promedio="";
    while(registro[i]!='|'){
        Promedio+=registro[i];
        i++;
    }
   cout<<Promedio<<endl;
    Alumno a1;
    a1.set_Nombre(Nombre);
    a1.set_Codigo(Codigo);
    a1.set_Carrera(Carrera);
    a1.set_Promedio(Promedio);
    Insertar(UltimaPos(),a1);

}

void Lista::Cargar()
{
Nodo*aux=Ancla;
ifstream archivo;
archivo.open("file01.txt");
if(archivo.is_open()){
    archivo.seekg(0,archivo.end);
    int length=archivo.tellg();
    archivo.seekg(0,archivo.beg);

    char *buffer = new char[length];

    archivo.read(buffer,length);
    int i=0;
    string registro="";
    cout<<length<<endl;

    while(i<length){
        if(buffer[i]!='*'){
            registro+=buffer[i];

        }
        else{
            Campos(registro);
            registro="";
        }
        i++;
    }

    archivo.close();
}
else{
    cout<<"No se pudo abrir el achivo"<<endl;
    }
}