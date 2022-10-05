#include "Btree.h"

int main(){
  Btree* tree = new Btree();
  int opcion = 0;	
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
    <<"9)Salir"<<endl;
    cout<<"Ingrese opcion >> ";
    cin >> opcion;
    cin.ignore();
        
    string modoBusqueda;
    string name;
    string code;
    string career;
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
        tree->insertRoot(name,code,career,grade);
        system("pause");
        break;
      case 2:
        system("cls");
        cout << "\n\n BUSCAR NODO \n\n";
        cout << "Ingrese el nombre del estudiante: "; getline(cin,name);
        tree->searchNameRoot(name);
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
          cout << "\n\n MOSTRAR MAXIMO \n\n";

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
            cout << "\n\n ELIMINAR NODO \n\n";
            cout<<"\nIndique la calificacion >> ";
            cin>>grade;
            tree->setRoot(tree->deleteNode(tree->getRoot(),grade));
				    break;
			  case 6:
          system("cls");
          cout << "\n\n ORDEN \n\n";
          tree->inOrderPrintRoot();
          system("pause");
				  break;
			  case 7:
          system("cls");
          cout << "\n\n PREORDEN \n\n";
          tree->preOrderPrintRoot();
          system("pause");
          break;
			  case 8:
          system("cls");
          cout << "\n\n POSTORDEN \n\n";
          tree->postOrderPrintRoot();
          system("pause");
          break;
        case 9:
          cout<<"Saliendo..."<<endl;
          system("pause");
          break;
			  default:
				  cout<<"Ingrese opcion valida"<<endl;
		}
	}while(opcion!= 9);

  return 0;
}
