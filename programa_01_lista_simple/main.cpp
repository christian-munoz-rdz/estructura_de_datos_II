#include <iostream>
#include "List.h"
#include<ios>  
#include<limits>

using namespace std;

int main(){
// Creamos un objeto de la clase lista
    List l1;

// Cargamos los datos de los estudiantes desde el archivo si es que existe
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
        case 1:{ // Pedimos los datos del estudiante y lo insertamos en la lista
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
        case 2: // Mostramos la lista completa
                cout<<"\n---Lista completa--- "<<endl<<endl;
                cout<< l1.Show_list()<<endl<<endl;
                break;
        case 3:{ // Pedimos el codigo del estudiante y lo eliminamos de la lista
                string code;
                cout<< "\n---Eliminacion de estudiante---" << endl; 
                cout<<"Ingresa de favor el codigo del alumno: ";cin>>code;
                l1.Delete(code);
                cin.ignore();
                break;
                }
        case 4:{ // Pedimos el codigo del estudiante y mostramos sus datos
                string code;
                cout<< "\n---Mostrar estudiante---" << endl; 
                cout<<"Ingresa de favor el codigo del alumno: ";cin>>code;
                cout<<endl<<l1.Show_Data(code)<<endl;
                cin.ignore();
                break;
                }
        case 5: // Vaciamos la lista
                cout<< "\n---Eliminacion de lista---" << endl;
                l1.Clear();
                break;
        case 6: // Mostramos el primer estudiante de la lista
                cout<< "\n---Mostrando primera posicion---" << endl;
                if(l1.Empty())
                    cout<<"La lista esta vacia"<<endl; // Si la lista esta vacia mostramos un mensaje
                else
                    cout<<"\n"<<l1.First()->get_Data_show()<<endl;
                break;
        case 7: // Mostramos el ultimo estudiante de la lista
                cout<< "\n---Mostrando ultima posicion---" << endl; 
                if(l1.Empty())
                    cout<<"La lista esta vacia"<<endl; // Si la lista esta vacia mostramos un mensaje
                else
                    cout<<l1.Last()->get_Data_show()<<endl;
                break;
        case 8:// Guardamos los datos de la lista en el archivo
                cout<< "\n---Guardando datos---" << endl;
                l1.Save();
                break;
        case 0:// Salimos del programa
                cout<<"\n---VUELVA PRONTO---"<<endl;
                break;
        default:// Si el usuario ingresa una opcion no valida mostramos un mensaje
                cout<<"\n---OPCION NO VALIDA---"<<endl;
                break;
    } 
    cout<<"\nEnter para continuar..."<<endl;
    cin.ignore();
    system("clear"); // Limpiamos la pantalla
}while (opc!=0); 
    return 0;
}




