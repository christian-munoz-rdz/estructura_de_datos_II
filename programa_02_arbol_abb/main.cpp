#include "Btree.h"

int main(){
  Btree* tree = new Btree();
  tree->Load(); // Carga los datos del archivo si es que existe
  int opcion;	
  do{ // Menu ciclico de opciones 
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
		
    switch(opcion){
      case 1: // Insertar datos
        system("cls");
        cout << "\n\n INSERTAR DATO \n\n";
        cout << "Ingrese el nombre del estudiante: "; getline(cin,name);
        cout << "Ingrese el codigo del estudiante: "; getline(cin,code);
        cout << "Ingrese la carrera del estudiante: "; getline(cin,career);
        cout << "Ingrese la calificación del estudiante: "; cin >> grade;
        tree->insert(name,code,career,grade,tree->getRoot()); // Inserta el dato en el arbol usando la raiz como parametro y los datos ingresados 
                                                              //por el usuario
        system("pause");
        break;
      case 2: // Buscar nodo
        system("cls");
        aux = NULL; // Inicializa el nodo auxiliar en NULL
        cout << "\n\n BUSCAR NODO \n\n";
        cout << "Ingrese el codigo del estudiante: "; getline(cin,code);
        tree->search(tree->getRoot(),code,aux); // Busca el nodo con el codigo ingresado por el usuario
        if(aux){ // Si el nodo auxiliar no es NULL
          aux->show(); // Muestra los datos del nodo
        }
        else{ // Si el nodo auxiliar es NULL
          cout << "No se encontro el estudiante" << endl; // Muestra mensaje de error
        }
        system("pause");
				break;
			case 3:{ // Mostrar calificación más baja
          system("cls");
          cout << "\n\n MOSTRAR CALIFICACION MAS BAJA \n\n";

          Node* min = tree->min(); // Obtiene el nodo con la calificación más baja

          if(min) // Si el nodo no es NULL
            min->show(); // Muestra los datos del nodo
          else // Si el nodo es NULL
            cout<<"Arbol Vacio"<<endl; // Muestra mensaje de error
          
          system("pause");
				  break;
      }
			case 4:{ // Mostrar calificación más alta
          system("cls");
          cout << "\n\n MOSTRAR CALIFICACION MAS ALTA \n\n";

          Node* max = tree->max(); // Obtiene el nodo con la calificación más alta
          if (max) // Si el nodo no es NULL
            max->show(); // Muestra los datos del nodo
          else // Si el nodo es NULL
            cout<<"Arbol Vacio"<<endl; // Muestra mensaje de error

          system("pause");
				  break;
        }
			  case 5: // Eliminar nodo
            system("cls");
            aux = NULL; // Inicializa el nodo auxiliar en NULL
            cout << "\n\n ELIMINAR NODO \n\n";
            cout << "Ingrese el codigo del estudiante a eliminar: "; getline(cin,code);
            tree->search(tree->getRoot(),code,aux); // Busca el nodo a eliminar con el codigo ingresado por el usuario
            if(aux){ // Si el nodo auxiliar no es NULL
              tree->setRoot(tree->deleteNode(tree->getRoot(),aux->get_Student()->get_Grade())); // Elimina el nodo y actualiza la raiz
                                                                                                // utilizando la calificación del nodo
            }
            else{ // Si el nodo auxiliar es NULL
              cout << "No se encontro el estudiante" << endl; // Muestra mensaje de error
            }
            system("pause");
				    break;
			  case 6: // Muesra los datos en orden
          system("cls");
          cout << "\n\n ORDEN \n\n";
          tree->inOrderPrint(tree->getRoot()); 
          system("pause");
				  break;
			  case 7: // Muestra los datos en preorden
          system("cls");
          cout << "\n\n PREORDEN \n\n";
          tree->preOrderPrint(tree->getRoot());
          system("pause");
          break;
			  case 8: // Muestra los datos en postorden
          system("cls");
          cout << "\n\n POSTORDEN \n\n";
          tree->postOrderPrint(tree->getRoot());
          system("pause");
          break;
        case 9: // Guarda los datos en el archivo
          system("cls");
          cout << "\n\n GUARDAR DATOS \n\n";
          tree->Save();
          cout << "Datos guardaros con exito" << endl; // Muestra mensaje de exito
          system("pause");
          break;
        case 0: // Salir
          cout<<"Saliendo..."<<endl; // Muestra mensaje de salida
          break;
			  default: // Opcion invalida
				  cout<<"Ingrese opcion valida"<<endl; // Muestra mensaje de error
          system("pause");
		}
	}while(opcion!=0); // Repite el menu mientras la opcion sea diferente de 0

  return 0;
}
