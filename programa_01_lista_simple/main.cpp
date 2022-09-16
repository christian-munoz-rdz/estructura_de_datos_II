#include <iostream>
#include "List.h"
#include<ios>  
#include<limits>

using namespace std;

int main(){
    List l1;
        
    l1.Load();
    int opc;
 
do{
    cout << "-----B I E N V E N I D O------ " << endl;
    
    cout << "1: Insertar " << endl;
    cout << "2: Mostrar lista completa" << endl;
    cout << "3: Eliminar " << endl;
    cout << "4: Mostrar dato " << endl;
    cout << "5: Vaciar lista " << endl;
    cout << "6: Mostrar primera posicion " << endl;
    cout << "7: Mostrar ultima posicion " << endl;
    cout << "8: Guardar"<<endl;
    cout << "0: Salir " << endl;
    cout << "Ingrese una opcion: "; cin>>opc;
    cin.ignore();
    

    switch (opc){
        case 1:{
                string Name,Code,Career,Grade;
                cout<< "\n---Registro de estudiante---" << endl;
                cout << "Ingresa el nombre: "; getline(cin,Name);
                cout << "Ingresa el codigo: "; getline(cin,Code);
                cout << "Ingresa la carrera: "; getline(cin,Career);
                cout << "Ingresa el promedio: "; getline(cin,Grade);
                Student s(Name,Code,Career,Grade);
                l1.Insert(l1.Last(),s);
                break;
                }   
        case 2:
                cout<<"\n---Lista completa--- "<<endl<<endl;
                cout<< l1.Show_list()<<endl<<endl;
                break;
        case 3:{
                string code;
                cout<< "\n---Eliminacion de estudiante---" << endl; 
                cout<<"Ingresa de favor el codigo del alumno: ";cin>>code;
                l1.Delete(code);
                cin.ignore();
                break;
                }
        case 4:{
                string code;
                cout<< "\n---Mostrar estudiante---" << endl; 
                cout<<"Ingresa de favor el codigo del alumno: ";cin>>code;
                cout<<endl<<l1.Show_Data(code)<<endl;
                cin.ignore();
                break;
                }
        case 5:
                cout<< "\n---Eliminacion de lista---" << endl;
                l1.Clear();
                break;
        case 6: 
                cout<< "\n---Mostrando primera posicion---" << endl;
                if(l1.Empty())
                    cout<<"La lista esta vacia"<<endl;
                else
                    cout<<"\n"<<l1.First()->get_Data_show()<<endl;
                break;
        case 7: 
                cout<< "\n---Mostrando ultima posicion---" << endl; 
                if(l1.Empty())
                    cout<<"La lista esta vacia"<<endl;
                else
                    cout<<l1.Last()->get_Data_show()<<endl;
                break;
        case 8:
                cout<< "\n---Guardando datos---" << endl;
                l1.Save();
                break;
        case 0:
                cout<<"\n---VUELVA PRONTO---"<<endl;
                break;
        default:
                cout<<"\n---OPCION NO VALIDA---"<<endl;
                break;
    } 
    cout<<"\nEnter para continuar..."<<endl;
    cin.ignore();
    system("clear");
}while (opc!=0); 
    return 0;
}




