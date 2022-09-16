#include <iostream>
#include "Student.h"

class Node{
private:
    Student Record = Student("","","","");
    Node *Next;
    Node *Previous;
    friend class List;
public:
    Node();
    ~Node();

    void set_Data(Student);
    void set_Next(Node*);
    void set_Prev(Node*);

    string get_Data_show();
    string get_Data_save();
    Node* get_Next();
    Node* get_Prev();

};


Node::Node(){
    Next=NULL; 
    Previous=NULL; 
}

Node::~Node(){
    cout<<"Alumno eliminado..."<<endl;
}

void Node::set_Data(Student _Record){
    Record=_Record;
}

void Node::set_Next(Node* _Next){
    Next=_Next;
}

void Node::set_Prev(Node* _Previous){
    Previous=_Previous;
}

string Node::get_Data_show(){
    return Record.toString_show();
}

string Node::get_Data_save(){
    return Record.toString_save();
}

Node* Node::get_Next(){
    return Next;
}

Node* Node::get_Prev(){
    return Previous;
}

