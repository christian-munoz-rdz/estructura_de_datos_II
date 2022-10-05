#include "Student.h"

using namespace std;

class Node{
private:
    Student* student;
    Node* left;
    Node* right;
public:
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

    void show();
    string save_student();
};

Node::Node(string Name,string Code,string Career,float Grade){
    student= new Student(Name,Code,Career,Grade);
    left = NULL;
    right = NULL;
}

Node::~Node(){
    cout<<"Alumno eliminado"<<endl;
}

//Metodos Get
Student* Node::get_Student(){
    return student;
}

Node* Node::get_Left(){
    return left;
}

Node* Node::get_Right(){
    return right;
}

//Metodos Set
void Node::set_Student(Student* student){
    this->student = student;
}

void Node::set_Left(Node* left){
    this->left = left;
}

void Node::set_Right(Node* right){
    this->right = right;
}

void Node::show(){
    cout << "Nombre: " << student->get_Name() << endl;
    cout << "Codigo: " << student->get_Code() << endl;
    cout << "Carrera: " << student->get_Career() << endl;
    cout << "Promedio: " << student->get_Grade() << endl;
    cout << endl;
}

string Node::save_student(){
    return student->toString_save();
}