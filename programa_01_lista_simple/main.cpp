//Hernandez Michel Oscar Uriel
#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    Lista l1;
    int opc;
    do{
    cout << "------B I E N V E N I D O------ " << endl;
    cout << "\n1: Insertar " << endl;
    cout << "\n2: Mostrar lista completa" << endl;
    cout << "\n3: Eliminar " << endl;
    cout << "\n4: Mostrar dato " << endl;
    cout << "\n5: Borrar todo " << endl;
    cout << "\n6: Primera posicion " << endl;
    cout << "\n7: Ultima posicion " << endl;
    cout << "\n8: Guardar"<<endl;
    cout << "\n9: Cargar"<<endl;
    cout << "\n0: Salir " << endl;

   cin>>opc;
string aux;

   if (opc>=0 && opc<=10 ){
   switch (opc){
    case 1: {
        Alumno c1;
        string Nom2,Cod2,Car,Prom;
        cout << "Ingresa el nombre: " << endl;
        cin.ignore();
        getline(cin,Nom2);
        cout << "Ingresa el codigo: " << endl;
        getline(cin,Cod2);
        cout << "Ingresa la carrera: " << endl;
        getline(cin,Car);
        cout << "Ingresa el promedio: " << endl;
        getline(cin,Prom);
        c1.set_Nombre(Nom2);
        c1.set_Codigo(Cod2);
        c1.set_Carrera(Car);
        c1.set_Promedio(Prom);

        l1.Insertar(l1.UltimaPos(),c1);break;}
    case 2:cout<<l1.Mostrar_Lista();break;
    case 3:{
        Alumno c1;
        string aux;
        cout<<"Ingresa de favor el codigo del alumno"<<endl;cin>>aux;
        c1.set_Codigo(aux);
    l1.Eliminar(c1);break;}
    case 4:{
        Alumno c1;
        string aux;
        cout<<"Ingresa de favor el codigo del alumno"<<endl;cin>>aux;
        c1.set_Codigo(aux);
    cout<<endl<<l1.Mostrar_Dato(c1)<<endl;break;}
     case 5:l1.Vaciar();break;
     case 6:cout<<"\n"<<l1.PrimeraPos()->get_Data()<<endl;break;
    case 7:cout<<"\n"<<l1.UltimaPos()->get_Data()<<endl;break;
    case 8:l1.Guardar();break;
    case 9:l1.Cargar();break;
    case 0:cout<<"\nVUELVA PRONTO"<<endl;break;
} }
else {
    cout<<"Esta opcion no es valida"<<endl;
}
if (opc!=0){
    cout<<endl<<"Enter para continuar...";
    cin.get();
    cin.get();
    system("cls");
}
    }
    while (opc!=0);
    return 0;
}

