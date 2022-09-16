#include <iostream>
#include "Student.h"

// Clase nodo tiene 3 atributos: un estudiante guardado como Record, un puntero al nodo anterior y un puntero al nodo siguiente
class Node{
private:
    //Reservamos memoria para el estudiante
    Student Record = Student("","","","");
    Node *Next;
    Node *Previous;
    friend class List;
public:
    // Constructor y destructor de la clase
    Node();
    ~Node();

    // Metodos set de la clase
    void set_Data(Student);
    void set_Next(Node*);
    void set_Prev(Node*);

    // Metodos get de la clase
    string get_Data_show();
    string get_Data_save();
    Node* get_Next();
    Node* get_Prev();

};


// Constructor de la clase nodo
Node::Node(){ // Inicializamos los punteros a NULL
    Next=NULL;
    Previous=NULL; 
}

// Destructor de la clase nodo
Node::~Node(){
    cout<<"Alumno eliminado..."<<endl; //Mensaje de confirmacion
}

// ser_Data recibe un estudiante y lo guarda en el atributo Record
void Node::set_Data(Student _Record){
    Record=_Record;
}

// set_Next recibe un puntero a nodo y lo guarda en el atributo Next
void Node::set_Next(Node* _Next){
    Next=_Next;
}

// set_Prev recibe un puntero a nodo y lo guarda en el atributo Previous
void Node::set_Prev(Node* _Previous){
    Previous=_Previous;
}

// get_Data_show retorna un string con los datos del estudiante para mostrar en la consola
string Node::get_Data_show(){
    return Record.toString_show();
}

// get_Data_save retorna un string con los datos del estudiante para guardar en el archivo
string Node::get_Data_save(){
    return Record.toString_save();
}

// get_Next retorna el puntero al nodo siguiente
Node* Node::get_Next(){
    return Next;
}

// get_Prev retorna el puntero al nodo anterior
Node* Node::get_Prev(){
    return Previous;
}

