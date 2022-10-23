#include "Grafo.h"

int main()
{
    Grafo* g = new Grafo();
    g->Load();
    int opc;
    do{
        cout << "1.Insertar vertice" << endl;
        cout << "2.Insertar arista" << endl;
        cout << "3.Mostrar Grafo" << endl;
        cout << "4.Eliminar vertice" << endl;
        cout << "5.Eliminar arista" << endl;
        cout << "6.Guardar grafo" << endl;
        cout << "0.Salir" << endl;
        cout<<"Opcion: ";cin>>opc;
        switch(opc){
            case 1:{ 
                string nombre, usuario;
                cout<<"Nombre de la persona: ";
                cin.ignore();
                getline(cin,nombre);
                cout<<"Usuario de la persona: ";
                getline(cin,usuario);
                g->InsertaVertice(new Persona(nombre,usuario));
                system("pause");
                break;
            }
            case 2:{
                string origen, destino;
                cout<<"Ingresa el usuario origen:";cin.ignore();
                getline(cin,origen);
                if(g->GetVertice(origen)==NULL){
                    cout<<"No existe el usuario"<<endl;
                    system("pause");
                    break;
                }

                cout<<"Ingresa el usuario destino: ";
                getline(cin,destino);
                if(g->GetVertice(destino)==NULL){
                    cout<<"No existe el usuario"<<endl;
                    system("pause");
                    break;
                }

                g->InsertarArista(g->GetVertice(origen),g->GetVertice(destino));
                system("pause");
                break;
            }
            case 3: 
                g-> Mostrar();
                system("pause");
                break;
            case 4:{
                string usuario; 
                Vertice* v;
                cout<<"Cual es el nombre de usario?: ";cin.ignore();
                getline(cin,usuario);
                v = g->GetVertice(usuario);
                if (v != NULL)
                    g->EliminarVertice(v);
                else
                    cout<<"No existe el usuario"<<endl;
                system("pause");
                break;
            }
            case 5:{
                string origen, destino;
                
                cout<<"Usuario de origen: ";cin.ignore();
                getline(cin,origen);
                if(g->GetVertice(origen)==NULL){
                    cout<<"No existe el usuario"<<endl;
                    system("pause");
                    break;
                }
                
                cout<<"Usuario de destino: ";
                getline(cin,destino);
                if(g->GetVertice(destino)==NULL){
                    cout<<"No existe el usuario"<<endl;
                    system("pause");
                    break;
                }
                
                g->EliminarArista(g->GetVertice(origen),g->GetVertice(destino));
                system("pause");
                break;
            }
            case 6:{
                g->Save();
                system("pause");
                break;
            }
        }
        system("cls");
    }while(opc!=0);
    return 0;
}