#include "Btree.h"

int main(){
  Btree* tree = new Btree();
  tree->Load();
  int opcion;	
  do{
    system("cls");  
    cout<<"OPCIONES"<<endl
    <<"1)Insertar datos"<<endl
    <<"2)Buscar nodo"<<endl   
    <<"3)Mostrar calificación más baja"<<endl
    <<"4)Mostrar calificaciób más alta"<<endl
    <<"5)Eliminar nodo"<<endl
    <<"6)Mostrar datos en Orden"<<endl
    <<"7)Mostrar datos en preorden"<<endl
    <<"8)Mostrar datos en postorden"<<endl
    <<"9)Guardar datos"<<endl
    <<"0)Salir"<<endl;
    cout<<"Ingrese opcion >> ";
    cin >> opcion;
    cin.ignore();

    string name;
    string code;
    string career;
    Node* aux;
    float grade;
    bool retry,retry2;
		
    switch(opcion){
      case 1:
        system("cls");
        cout << "\n\n INSERTAR DATO \n\n";
        cout << "Ingrese el nombre del estudiante: "; getline(cin,name);
        cout << "Ingrese el codigo del estudiante: "; getline(cin,code);
        cout << "Ingrese la carrera del estudiante: "; getline(cin,career);
        cout << "Ingrese la calificación del estudiante: "; cin >> grade;
        tree->insert(name,code,career,grade,tree->getRoot());
        system("pause");
        break;
      case 2:
        system("cls");
        aux = NULL;
        cout << "\n\n BUSCAR NODO \n\n";
        cout << "Ingrese el codigo del estudiante: "; getline(cin,code);
        tree->search(tree->getRoot(),code,aux);
        if(aux){
          aux->show();
        }
        else{
          cout << "No se encontro el estudiante" << endl;
        }
        system("pause");
				break;
			case 3:{
          system("cls");
          cout << "\n\n MOSTRAR CALIFICACION MAS BAJA \n\n";

          Node* min = tree->min();

          if(min)
            min->show();
          else
            cout<<"Arbol Vacio"<<endl;
          
          system("pause");
				  break;
      }
			case 4:{
          system("cls");
          cout << "\n\n MOSTRAR CALIFICACION MAS ALTA \n\n";

          Node* max = tree->max();
          if (max)
            max->show();
          else
            cout<<"Arbol Vacio"<<endl;

          system("pause");
				  break;
        }
			  case 5:
            system("cls");
            aux = NULL;
            cout << "\n\n ELIMINAR NODO \n\n";
            cout << "Ingrese el codigo del estudiante a eliminar: "; getline(cin,code);
            tree->search(tree->getRoot(),code,aux);
            if(aux){
              tree->setRoot(tree->deleteNode(tree->getRoot(),aux->get_Student()->get_Grade()));
            }
            else{
              cout << "No se encontro el estudiante" << endl;
            }
            system("pause");
				    break;
			  case 6:
          system("cls");
          cout << "\n\n ORDEN \n\n";
          tree->inOrderPrint(tree->getRoot());
          system("pause");
				  break;
			  case 7:
          system("cls");
          cout << "\n\n PREORDEN \n\n";
          tree->preOrderPrint(tree->getRoot());
          system("pause");
          break;
			  case 8:
          system("cls");
          cout << "\n\n POSTORDEN \n\n";
          tree->postOrderPrint(tree->getRoot());
          system("pause");
          break;
        case 9:
          system("cls");
          cout << "\n\n GUARDAR DATOS \n\n";
          tree->Save();
          cout << "Datos guardaros con exito" << endl;
          system("pause");
          break;
        case 0:
          cout<<"Saliendo..."<<endl;
          break;
			  default:
				  cout<<"Ingrese opcion valida"<<endl;
          system("pause");
		}
	}while(opcion!=0);

  return 0;
}
