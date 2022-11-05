#include "producto.h"
class TablaHash{
    static const size_t tamanioTabla = 10;
    list<pair<size_t, Producto>> tabla[tamanioTabla];
    public:
    bool isEmpty() const;
    size_t funcionHash(size_t key);
    void insertar(size_t key, Producto valor);
    void eliminar(size_t key);
    void buscar(size_t key);
    void imprimir();
    void cargar();
    void guardar();
};

bool TablaHash::isEmpty()const{
    size_t elementos = 0;
    for(size_t i = 0; i< tamanioTabla; i++){
        elementos += tabla[i].size();
    }
    if(elementos){
        return false;
    }else{
        return true;
    }
}

size_t TablaHash::funcionHash(size_t key){
    return key % tamanioTabla;
}

void TablaHash::insertar(size_t key, Producto valor){
    size_t llaveHasheada = funcionHash(key);
    auto &celda = tabla[llaveHasheada];
    bool existeLlave = false;
    for(auto iterador = begin(celda); iterador != end(celda); iterador++){
        if(iterador->first == key){
            existeLlave = true;
            iterador->second = valor;
            cout<<"Ya existe esa llave. Se reemplazo el producto"<<endl;
            break;
        }
    }
    if(!existeLlave){
        celda.emplace_back(key, valor);
    }
}

void TablaHash::eliminar(size_t key){
    if(isEmpty()){
        cout<<"Tabla vacia"<<endl;
    }
    size_t llaveHasheada = funcionHash(key);
    auto &celda = tabla[llaveHasheada];
    bool existeLlave = false;
    for(auto iterador = begin(celda); iterador != end(celda); iterador++){
        if(iterador->first == key){
            existeLlave = true;
            iterador = celda.erase(iterador);
            cout<<"Se elimino con exito el producto"<<endl;
            break;
        }
    }
    if(!existeLlave){
        cout<<"No existe esa llave"<<endl;
    }
}

void TablaHash::buscar(size_t key){
    if(isEmpty()){
        cout<<"Tabla vacia"<<endl;
    }
    size_t llaveHasheada = funcionHash(key);
    auto &celda = tabla[llaveHasheada];
    bool existeLlave = false;
    for(auto iterador = begin(celda); iterador != end(celda); iterador++){
        if(iterador->first == key){
            existeLlave = true;
            cout<<"Se encontro el producto."<<endl;
            cout<<iterador->second<<endl;
            break;
        }
    }
    if(!existeLlave){
        cout<<"No existe esa llave"<<endl;
    }
}

void TablaHash::imprimir(){
    if(isEmpty()){
        cout<<"Tabla vacia"<<endl;
    }
    for(size_t i=0;i<tamanioTabla;i++){
        if(tabla[i].size()==0){
            continue;
        }
        for(auto iterador = tabla[i].begin(); iterador != tabla[i].end();iterador++){
            cout<<"Llave: "<< iterador->first<<", valor: "<<iterador->second<<endl;
        }
    }
}

void TablaHash::guardar(){
    Producto productoAux;
    float precioAux;
    size_t llaveAux, tamPais, tamNombre;
    string paisAux, nombreAux;
    fstream archivo("file01.txt",ios::binary | ios::out | ios::trunc);
    if(!archivo.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
    }else{
        if(isEmpty()){
            return;
        }else{
            for(size_t i=0;i<tamanioTabla;i++){
                if(tabla[i].size()==0){
                    continue;
                }
                for(auto iterador = tabla[i].begin(); iterador != tabla[i].end();iterador++){
                    llaveAux = iterador->first;
                    productoAux = iterador->second;
                    precioAux = productoAux.getPrecio();
                    paisAux = productoAux.getPais();
                    nombreAux = productoAux.getNombre();
                    tamPais = paisAux.size();
                    tamNombre = nombreAux.size();

                    archivo.write((char *)&llaveAux, sizeof(size_t));
                    archivo.write((char *)&precioAux, sizeof(float));
                    archivo.write((char *)&tamPais, sizeof(size_t));
                    archivo.write(paisAux.c_str(), tamPais);
                    archivo.write((char *)&tamNombre, sizeof(size_t));
                    archivo.write(nombreAux.c_str(), tamNombre);
                }
            }
        }
    }
    archivo.close();
}

void TablaHash::cargar(){
    Producto productoAux;
    float precioAux;
    size_t llaveAux, tamPais, tamNombre;
    string paisAux, nombreAux;
    fstream archivo("file01.txt",ios::binary | ios::in);
    if(archivo.is_open()){
        while(true){
            archivo.read((char *)&llaveAux, sizeof(size_t));
            if(archivo.eof()){
                break;
            }
            archivo.read((char *)&precioAux, sizeof(float));
            productoAux.setPrecio(precioAux);
            archivo.read((char *)&tamPais, sizeof(size_t));
            paisAux.resize(tamPais);
            archivo.read((char *)paisAux.c_str(), tamPais);
            productoAux.setPais(paisAux);
            archivo.read((char *)&tamNombre, sizeof(size_t));
            nombreAux.resize(tamNombre);
            archivo.read((char *)nombreAux.c_str(), tamNombre);
            productoAux.setNombre(nombreAux);
            insertar(llaveAux, productoAux);
        }
    }
    archivo.close();
}