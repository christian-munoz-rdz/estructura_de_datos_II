#include "Btree.h"

int main(){

  Btree* tree = new Btree();
  string opcion_menu;	

  do{
    system("cls");  
    cout<<"OPCIONES"<<endl
    <<"1)Insertar Datos"<<endl
    <<"2)Buscar Nodo"<<endl   
    <<"3)Mostrar Minimo"<<endl
    <<"4)Mostrar Maximo"<<endl
    <<"5)Editar Nodo"<<endl
    <<"6)Eliminar Nodo"<<endl
    <<"7)Mostrar Datos en Orden"<<endl
    <<"8)Mostrar Datos en preorden"<<endl
    <<"9)Mostrar Datos en postorden"<<endl
    <<"10)Salir"<<endl;
    cout<<"Ingrese opcion >> ";
		cin >> opcion_menu;

		if((!i_input(opcion_menu))){
			cout<<"Ingrese opcion valida"<<endl;
			Sleep(1000);
		}
		else{
      string modoBusqueda;
			string id;
      string nombre;
      bool retry,retry2;
			switch(stoi(opcion_menu)){

        case 1:
          
          do{
            system("cls");
            cout << "\n\n INSERTAR DATO \n\n";
            cout<<"\nIndique el id >> ";
            cin>>id;

          
            if((!i_input(id))){
              cout<<"Ingrese opcion valida"<<endl;
              retry=true;
              Sleep(1000);
            }
            else{
                tree->insertRoot(stoi(id));
                retry=false;
            }
          } while (retry);
          system("pause");
          break;

			  case 2:

          do{
              system("cls");
              cout << "\n\n BUSCAR NODO \n\n";
              cout<< "1)Por ID"<<endl;
              cout<< "2)Por Nombre"<<endl;
              cout<<"Ingrese Opcion >> ";
              cin>>modoBusqueda;
              
              if ((!i_input(modoBusqueda))){
                cout<<"Ingrese opcion valida"<<endl;
                retry=true;
                Sleep(1000);
              }

              else{

                switch (stoi(modoBusqueda)){

                  case 1:
                    
                    retry2 = false;
                    do{
                      system("cls");
                      cout<<"\nIndique el id >> ";
                      cin>>id;

                      if((!i_input(id))){
                        cout<<"Ingrese opcion valida"<<endl;
                        retry2=true;
                        Sleep(1000);
                      }
                      else{
                        Node* finded = tree->searchRoot(stoi(id));
                        if (finded){
                          finded->show();
                          Node* pre = NULL, *suc = NULL;
                          tree->findPredSuc(tree->root,pre,suc,finded->id);
                          if (pre != NULL)
                            cout << "El predecesor es " << pre->id << endl;
                          else
                            cout << "No hay predecessor"<<endl; 
                          if (suc != NULL)
                            cout << "El succesor es " << suc->id<<endl;
                          else
                            cout << "No hay succesor"<<endl;
                        }
                        else
                          cout<<"Nodo no encontrado"<<endl;
                      
                        retry2=false;
                      }
                    } while (retry2);
                    retry=false;
                    break;
                  
                  case 2:
                    
                    cout<<"\nIndique nombre >> ";
                    cin>>nombre;
                    tree->searchNameRoot(nombre);
                    retry=false;
                    break;

                  default:
                    cout<<"Ingrese opcion valida"<<endl;
                    Sleep(1000);
                    retry=true;
                    break;
                }
              }    
          } while (retry);
          system("pause");
				  break;

			  case 3:
        {
          system("cls");
          cout << "\n\n MOSTRAR MINIMO \n\n";

          Node* min = tree->min();

          if(min)
            min->show();
          else
            cout<<"Arbol Vacio"<<endl;
          
          system("pause");
				  break;
        }
			  case 4:
        {
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
        {
          do{
            system("cls");
            cout << "\n\n EDITAR NODO \n\n";
            cout<<"\nIndique el id >> ";
            cin>>id;

            if((!i_input(id))){
              cout<<"Ingrese opcion valida"<<endl;
              Sleep(1000);
              retry=true;
            }
            else{
              Node* finded = tree->searchRoot(stoi(id));
              if (finded){
                cout<<"Antes de editar: "<<endl;
                finded->show(); 
                tree->edit(finded);
                cout<<"Despues de editar: "<<endl;
                finded->show();
              }
              else
                cout<<"El nodo no existe"<<endl;
              
              retry=false;
            }
          }while (retry);
          system("pause");
          break;
        }
			  case 6:

          do{
            system("cls");
            cout << "\n\n ELIMINAR NODO \n\n";
            cout<<"\nIndique el id >> ";
            cin>>id;

            if((!i_input(id))){
              cout<<"Ingrese opcion valida"<<endl;
              Sleep(1000);
              retry=true;
            }
            else{
              tree->root = tree->deleteNode(tree->root,stoi(id));
              system("pause");

              retry=false;
            } 
            
          } while (retry);

				  break;

			  case 7:

          system("cls");
          cout << "\n\n ORDEN \n\n";
          tree->inOrderPrintRoot();
          system("pause");
				  break;

			  case 8:

          system("cls");
          cout << "\n\n PREORDEN \n\n";
          tree->preOrderPrintRoot();
          system("pause");
          break;

			  case 9:

          system("cls");
          cout << "\n\n POSTORDEN \n\n";
          tree->postOrderPrintRoot();
          system("pause");
          break;
      
        case 10:

          cout<<"Saliendo..."<<endl;
          Sleep(1000);
          break;

			  default:
				  cout<<"Ingrese opcion valida"<<endl;
          Sleep(1000);
			}
		}
	} while (opcion_menu != "10");

  return 0;
}
