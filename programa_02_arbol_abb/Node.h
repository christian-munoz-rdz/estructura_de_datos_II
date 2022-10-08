#include "Student.h"

using namespace std;

// Clase Nodo tiene 3 atributos: estudiante, hijo izquierdo y hijo derecho
class Node{
private:
    Student* student;
    Node* left;
    Node* right;
public:
    // Constructor y destructor
    Node(string,string,string,float);
    ~Node();

    //Metodos Get
    Student* get_Student();
    Node* get_Left();
    Node* get_Right();

    //Metodos Set
    void set_Student(Student*);
    void set_Left(Node*);
    void set_Right(Node*);

    //Otros metodos
    void show();
    string save_student();
};

// Constructor de la clase recibe 4 parametros
Node::Node(string Name,string Code,string Career,float Grade){
    student= new Student(Name,Code,Career,Grade);
    left = NULL;
    right = NULL;
}

// Destructor de la clase
Node::~Node(){
    cout<<"Alumno eliminado"<<endl;
}

//Metodos Get

// Metodo get para el estudiante
Student* Node::get_Student(){
    return student;
}

// Metodo get para el hijo izquierdo
Node* Node::get_Left(){
    return left;
}

// Metodo get para el hijo derecho
Node* Node::get_Right(){
    return right;
}

//Metodos Set

// Metodo set para el estudiante
void Node::set_Student(Student* student){
    this->student = student;
}

// Metodo set para el hijo izquierdo
void Node::set_Left(Node* left){
    this->left = left;
}

// Metodo set para el hijo derecho
void Node::set_Right(Node* right){
    this->right = right;
}

//Metodo para mostrar los datos del estudiante
void Node::show(){
    cout << "Nombre: " << student->get_Name() << endl;
    cout << "Codigo: " << student->get_Code() << endl;
    cout << "Carrera: " << student->get_Career() << endl;
    cout << "Promedio: " << student->get_Grade() << endl;
    cout << endl;
}

//Metodo para guardar los datos del estudiante en un registro
string Node::save_student(){
    string data;
    data = student->get_Name() + "|" + student->get_Code() + "|" + student->get_Career() + "|" + to_string(student->get_Grade()) + "*";
    return data;
}