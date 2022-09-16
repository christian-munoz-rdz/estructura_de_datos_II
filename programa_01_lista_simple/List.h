#include "Node.h"
// incluimos la librerias necesarias fstream para leer y escribir archivos
#include<fstream>
#include<string>

// Clase lista solo tiene 1 atributo: un puntero al primer nodo
class List{
private:
    Node* Head;

public:
    // Constructor de la clase lista
    List();

    // Metodos de la clase lista
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
List::List(){ // Inicializa el puntero Head a NULL
	Head = NULL;
}

// Metodo que retorna true si la lista esta vacia
bool List::Empty(){
    return Head==NULL;
}

// Metodo que inserta un nodo en la lista, recibe un puntero y un estudiante
void List::Insert(Node* n, Student& s){
    Node* aux= new Node();
    aux->set_Data(s);
    
    if(n==NULL){
        aux->set_Next(Head);
        if(Head!=NULL){
            Head->set_Prev(aux);
        }
        Head=aux;
    }
    else{
        aux->set_Prev(n);
        aux->set_Next(n->get_Next());
        if(n->get_Next()!=NULL){
            n->get_Next()->set_Prev(aux);
        }
        n->set_Next(aux);
    }

}

// Metodo que elimina un nodo de la lista, recibe un string con el codigo del estudiante
void List::Delete(string code){
    // Buscamos el nodo a eliminar con el metodo Search
    Node* n= Search(code);
    
    //Si search nos retorno NULL significa que no encontro el nodo
    if(n==NULL){
        cout << "No se encontro el estudiante..." << endl;
    }
    else{ // Si search nos retorno un nodo procedemos a eliminarlo
        Node* aux=n;
    
        if(n->get_Prev()!=NULL){
            n->get_Prev()->set_Next(n->get_Next()); 
        }
    
        if(n->get_Next()!=NULL){
            n->get_Next()->set_Prev(n->get_Prev());
        }
        if(n==Head){
            Head=n->get_Next();
        }

        delete aux;
    }

}

// Metodo que retorna un string con los datos de todos los nodos de la lista
string List::Show_list(){ 
    Node* n = Head;
    string text = "";
    
    if(Empty()){ // Si la lista esta vacia retornamos un string vacio
        return "La lista esta vacia...";
    }
    
    while(n!=NULL){ // Mientras n no sea NULL recorremos la lista
        text += n->get_Data_show()+"\n"; // Concatenamos los datos del nodo a un string
        n=n->get_Next(); 
    }
    return text;
}

// Metodo que retorna un string con los datos de un nodo de la lista, recibe un string con el codigo del estudiante
string List::Show_Data(string code){ 
   Node* n = Search(code);

    if(n==NULL){ // Si search nos retorno NULL significa que no encontro el nodo
       return "No existe el estudiante";
   }
    return n->get_Data_show(); // Si search nos retorno un nodo retornamos los datos del nodo
}

// Metodo que busca un nodo en la lista, recibe un string con el codigo del estudiante
Node* List::Search(string code){ 
    Node* aux=Head;

    while(aux!=NULL){ // Mientras aux no sea NULL recorremos la lista
        if(aux->Record.get_Code()==code){
            return aux; // Si encontramos el nodo retornamos el nodo
        }
        aux= aux->get_Next();
    }
    return NULL; // Si no encontramos el nodo retornamos NULL
}

// Metodo que elimina todos los nodos de la lista
void List::Clear(){
    Node* aux;
    
    int count = 0;
    while(Head!=NULL){
        aux=Head;
        Head=Head->get_Next();
        delete aux;
        count++; // Contamos la cantidad de nodos eliminados
    }
    cout<<"Lista completamente vacia..."<<endl;
    cout<<"Se eliminaron "<<count<<" elementos..."<<endl; // Mostramos la cantidad de nodos eliminados
}

// Metodo que retorna el ultimo nodo de la lista
Node* List::Last(){

    Node* aux=Head;

    while(aux->get_Next()!=NULL){
        aux=aux->get_Next(); 
    }
    return aux; 
}

// Metodo que retorna el primer nodo de la lista
Node* List::First(){
    return Head;
}

// Metodo que guarda los datos de la lista en un archivo de texto
void List::Save(){

    if(Empty())
        cout<<"La lista esta vacia"<<endl;  // Si la lista esta vacia mostramos un mensaje
                                            //Evitamos que se cree un archivo vacio
    
    Node* n=Head;

    //Creamos un string para guardar los datos de la lista
    string text;

    //Recorremos la lista y concatenamos los datos de cada nodo al string
    while(n!=NULL){
        text += n->get_Data_save();
        n=n->get_Next();
    }

    //Creamos un objeto de la clase ofstream para escribir en el archivo
    ofstream file;

    //Abrimos el archivo en modo escritura
    file.open("data.txt",ios::out);
    
    //Si el archivo no se pudo abrir mostramos un mensaje
    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    //Escribimos los datos en el archivo
    file<<text;
    file.close(); //Cerramos el archivo
}

// Metodo que carga los campos de un archivo de texto a la lista recibe un string que representa un registro
void List::Fields(string& record){
    //Inicializamos un iterador para recorrer el string
    int i=0;
    
    //Creamos un string para guardar los datos de cada campo
    string Name="";
    
    //Recorremos el string hasta encontrar un caracter de separacion
    while(record[i]!='|'){
        Name += record[i];
        i++;
    }

    i++;

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

    //Creamos un objeto de la clase Student con los campos leidos
    Student s(Name,Code,Career,Grade);

    //Insertamos el objeto en la lista
    Insert(Last(),s);
}

// Metodo que carga todos los datos de un archivo de texto a la lista
void List::Load(){
    Node* aux=Head;

    //Creamos un objeto de la clase ifstream para leer el archivo
    ifstream file;

    //Abrimos el archivo en modo lectura
    file.open("data.txt",ios::in);

    //Si pudimos abrir el archivo recorremos el archivo y cargamos los datos a la lista
    if(file.is_open()){
        
        file.seekg(0,file.end); //Nos posicionamos al final del archivo
        int length=file.tellg(); //Obtenemos la longitud del archivo
        file.seekg(0,file.beg); //Nos posicionamos al inicio del archivo

        char *buffer = new char[length]; //Creamos un buffer para guardar los datos del archivo

        file.read(buffer,length); //Leemos los datos del archivo y los guardamos en el buffer
        
        int i=0; //Inicializamos un iterador para recorrer el buffer
        string record=""; //Creamos un string para guardar los datos de cada registro
    
        while(i<length){ //Recorremos el buffer hasta encontrar un caracter de separacion
            if(buffer[i]!='*'){ //Si el caracter no es un separador lo concatenamos al string
                record+=buffer[i]; 
            }
            else{ 
                Fields(record); //Si el caracter es un separador llamamos al metodo Fields
                record=""; //Reiniciamos el string
            }
            i++; //Incrementamos el iterador
        }
        file.close(); //Cerramos el archivo
    }
    else{
        return; //Si no pudimos abrir el archivo retornamos
    }
}

