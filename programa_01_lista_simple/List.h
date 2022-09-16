#include "Node.h"
#include<fstream>
#include<string>

// Clase lista solo tiene un atributo: un puntero al primer nodo de la lista
class List{
private:
    Node* Head;

public:
    // Constructor de la clase
    List();

    // Metodos de la clase
    bool Empty();
    void Insert(Node*, Student&);
    void Delete(string);
    string Show_list();
    string Show_Data(string);
    Node* Search(string);
    void Clear();
    Node* Last();
    Node* First();

    void Save();

    void Fields(string&);
    void Load();

};

// Constructor de la clase lista no recibe parametros
List::List(){ 
	Head = NULL; // Inicializamos el puntero a NULL
}

// Metodo que retorna true si la lista esta vacia y false si no lo esta
bool List::Empty(){
    return Head==NULL;
}

// Metodo que recibe un puntero a nodo y un estudiante y lo inserta en la lista
void List::Insert(Node* n, Student& s){
    Node* aux= new Node(); // Reservamos memoria para el nodo auxiliar
    aux->set_Data(s); // Guardamos el estudiante en el nodo auxiliar
    
    if(n==NULL){ // Si el puntero recibido es NULL
        aux->set_Next(Head); // El puntero Next del nodo auxiliar apunta al primer nodo de la lista
        if(Head!=NULL){
            Head->set_Prev(aux); // El puntero Previous del primer nodo de la lista apunta al nodo auxiliar
        }
        Head=aux; // El puntero Head apunta al nodo auxiliar
    }
    else{ // Si el puntero recibido no es NULL
        aux->set_Prev(n); // El puntero Previous del nodo auxiliar apunta al nodo recibido
        aux->set_Next(n->get_Next()); // El puntero Next del nodo auxiliar apunta al nodo siguiente al nodo recibido
        if(n->get_Next()!=NULL){ // Si el nodo siguiente al nodo recibido no es NULL
            n->get_Next()->set_Prev(aux); // El puntero Previous del nodo siguiente al nodo recibido apunta al nodo auxiliar
        }
        n->set_Next(aux); // El puntero Next del nodo recibido apunta al nodo auxiliar
    }

}

// Metodo que recibe un string y lo busca en la lista, si lo encuentra lo elimina
void List::Delete(string code){
    Node* n= Search(code); // Buscamos el nodo con el codigo recibido
    
    if(n==NULL){
        cout << "No se encontro el estudiante..." << endl; // Mensaje de error si no se encuentra el estudiante
    }
    else{
        Node* aux=n;
    
        if(n->get_Prev()!=NULL){ // Si el nodo anterior no es NULL
            n->get_Prev()->set_Next(n->get_Next()); // Asignamos el siguiente nodo del nodo anterior al siguiente nodo del nodo a eliminar
        }
    
        if(n->get_Next()!=NULL){ // Si el nodo siguiente no es NULL
            n->get_Next()->set_Prev(n->get_Prev()); // Asignamos el nodo anterior del nodo siguiente al nodo anterior del nodo a eliminar
        }
        if(n==Head){
            Head=n->get_Next(); // Si el nodo a eliminar es el primero de la lista, asignamos el siguiente nodo como el primero
        }

        delete aux; // Eliminamos el nodo
    }

}

// Metodo que retorna un string con los datos de todos los estudiantes de la lista
string List::Show_list(){ 
    Node* n = Head;
    string text = ""; // Variable que almacenara el string a retornar
    
    if(Empty()){ 
        return "La lista esta vacia..."; // Mensaje de error si la lista esta vacia
    }
    
    // Recorremos la lista y concatenamos los datos de cada estudiante
    while(n!=NULL){ 
        text += n->get_Data_show()+"\n"; 
        n=n->get_Next(); 
    }
    return text;
}

// Metodo que recibe un string y lo busca en la lista, si lo encuentra retorna un string con los datos del estudiante
string List::Show_Data(string code){ 
   Node* n = Search(code); // Buscamos el nodo con el codigo recibido

    if(n==NULL){ // Mensaje de error si no se encuentra el estudiante
       return "No existe el estudiante";
   }
    return n->get_Data_show(); // Retorna los datos del estudiante
}

// Metodo que recibe un string y lo busca en la lista, si lo encuentra retorna un puntero al nodo donde se encuentra
Node* List::Search(string code){ 
    Node* aux=Head;

    while(aux!=NULL){ 
        if(aux->Record.get_Code()==code){ //si el codigo del estudiante es igual al codigo que se busca
            return aux; // Retorna el puntero al nodo donde se encuentra el estudiante
        }
        aux= aux->get_Next();
    }
    return NULL; // Retorna NULL si no se encuentra el estudiante
}

// Metodo que elimina todos los nodos de la lista
void List::Clear(){
    Node* aux;
    
    int count = 0; // Contador de nodos eliminados
    while(Head!=NULL){
        aux=Head;
        Head=Head->get_Next(); // Reasignamos la cabeza de la lista
        delete aux; // Eliminamos el nodo auxiliar
        count++; 
    }
    cout<<"Lista completamente vacia..."<<endl;
    cout<<"Se eliminaron "<<count<<" elementos..."<<endl; // mostramos el numero de nodos eliminados 
}

// Metodo que retorna un puntero al ultimo nodo de la lista
Node* List::Last(){

    // Si la lista esta vacia retornamos NULL
    if(Head==NULL){
        return Head;
    }
    
    // Creamos una variable auxiliar que apunte al primer nodo de la lista
    Node* aux=Head;

    // Recorremos la lista hasta llegar al ultimo nodo
    while(aux->get_Next()!=NULL){
        aux=aux->get_Next(); 
    }
    return aux; 
}

// Metodo que retorna un puntero al primer nodo de la lista
Node* List::First(){
    return Head;
}

// Metodo que guarda los datos de la lista en un archivo
void List::Save(){

    if(Empty())
        cout<<"La lista esta vacia"<<endl;//                 
    
    Node* n=Head;

    // Creamos un string para guardar los datos de los estudiantes
    string text;

    // Recorrer la lista y guardar los datos de los estudiantes en el string
    while(n!=NULL){
        text += n->get_Data_save();
        n=n->get_Next();
    }

    // Creamos un objeto de la clase ofstream para escribir en el archivo
    ofstream file;

    // Abrimos el archivo en modo escritura
    file.open("data.txt",ios::out);
    
    // Si el archivo no se pudo abrir mostramos un mensaje de error
    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    // Escribimos los datos en el archivo
    file<<text;
    // Cerramos el archivo
    file.close(); 
}

// Metodo que recibe un string y lo divide en campos para crear un estudiante
void List::Fields(string& record){
    int i=0; // Inicializamos un iterador para recorrer el string
    
    // Guardamos cada campo en un string
    string Name="";
    
    // Recorremos el string hasta encontrar un caracter de separacion
    while(record[i]!='|'){
        Name += record[i];
        i++;
    }

    // Incrementamos el iterador para saltar el caracter de separacion
    i++;

    //Repetimos el proceso para los demas campos
    string Code="";

    while(record[i]!='|'){
        Code+=record[i];
        i++;
    }

    i++;

    string Career="";

    while(record[i]!='|'){
        Career+=record[i];
        i++;
    }

    i++;

    string Grade="";

    while(record[i]!='|'){
        Grade+=record[i];
        i++;
    }

    // Creamos un estudiante con los datos obtenidos
    Student s(Name,Code,Career,Grade);

    // Insertamos el estudiante en la lista
    Insert(Last(),s);
}

// Metodo que carga los datos de la lista desde un archivo
void List::Load(){

    Node* aux=Head;

    // Creamos un objeto de la clase ifstream para leer el archivo
    ifstream file;

    // Abrimos el archivo en modo lectura
    file.open("data.txt",ios::in);

    // Si podemos abrir el archivo leemos los datos
    if(file.is_open()){
        
        file.seekg(0,file.end); // Nos posicionamos al final del archivo 
        int length=file.tellg(); // Obtenemos la longitud del archivo
        file.seekg(0,file.beg); // Nos posicionamos al inicio del archivo

        char *buffer = new char[length]; // Creamos un buffer para guardar los datos del archivo

        file.read(buffer,length);  // Leemos los datos del archivo y los guardamos en el buffer
        
        int i=0; // Inicializamos un iterador para recorrer el buffer
        string record=""; // Creamos un string para guardar los datos de cada estudiante

        // Recorremos el buffer hasta encontrar un caracter de separacion
        while(i<length){ 
            if(buffer[i]!='*'){ 
                record+=buffer[i]; // Guardamos los datos en el strig de estudiante
            }
            else{ 
                Fields(record); // Creamos un estudiante con los datos del string si encontramos un caracter de separacion
                record=""; // Reiniciamos el string de estudiante
            }
            i++; // Incrementamos el iterador
        }
        file.close(); // Cerramos el archivo
    }
    else{
        return; // Si no se pudo abrir el archivo retornamos
    }
}

