#include "tablaHash.h"

int main(){
    TablaHash tabla;
    size_t aux;
    int opc = -1;
    tabla.cargar();
    do{
        cout<<"       ******MENU******"<<endl;
        cout<<"1.- Agregar Articulo/Producto"<<endl;
        cout<<"2.- Buscar Articulo/Producto"<<endl;
        cout<<"3.- Eliminar Articulo/Producto"<<endl;
        cout<<"4.- Mostrar Tabla con Articulo/Producto"<<endl;
        cout<<"0.- Salir"<<endl;
        cout<<"\nIngrese la opcion que corresponde a \nla actividad que desea que se ejecute: "<<endl;
        cin>>opc;
        switch(opc){
            case 1:{
                cout<<"Ingrese la clave del Articulo/Producto"<<endl;
                cin>>aux;
                Producto producto = Producto(1);
                tabla.insertar(aux, producto);
                tabla.guardar();
                break;
            }
            case 2:{
                cout<<"Ingrese la clave del Articulo/Producto a buscar"<<endl;
                cin>>aux;
                tabla.buscar(aux);
                break;
            }
            case 3:{
                cout<<"Ingrese la clave del Articulo/Producto a eliminar"<<endl;
                cin>>aux;
                tabla.eliminar(aux);
                tabla.guardar();
                break;
            }
            case 4:
                tabla.imprimir();
            break;
        }
    }while(opc != 0);
    return 0;
}
