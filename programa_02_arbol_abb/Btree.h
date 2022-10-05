#include "Node.h"
#include<fstream>
#include<string>

class Btree{
private:
    Node* root;
public:

    Btree();
    ~Btree();

    Node* getRoot();
    void setRoot(Node*);

    void insert(string,string,string,float,Node*);

    void search(Node*,string,Node*&);

    Node* min();
    Node* max();

    Node* deleteNode(Node*, float);

    void inOrderPrint(Node*);

    void preOrderPrint(Node*);

    void postOrderPrint(Node*);

    void to_string(Node*,string&);
    void Save();
    void Fields(string&);
    void Load();
};

Btree::Btree(){
    root = NULL;
}

Node* Btree::getRoot(){
    return root;
}

void Btree::setRoot(Node* root){
    this->root = root;
}

void Btree::insert(string Name,string Code,string Career,float Grade, Node* leaf){

    if (root){
        if(Grade < leaf->get_Student()->get_Grade()){
            if (leaf->get_Left()){
                insert(Name,Code,Career,Grade,leaf->get_Left());
            }
            else{
                Node* newNode = new Node(Name,Code,Career,Grade);
                leaf->set_Left(newNode);
            }  
        }
        else if (Grade >= leaf->get_Student()->get_Grade()){
            if (leaf->get_Right()){
                insert(Name,Code,Career,Grade,leaf->get_Right());
            }
            else{
                Node* newNode = new Node(Name,Code,Career,Grade);
                leaf->set_Right(newNode);
            } 
        } 
    }
    else{
        root = new Node(Name,Code,Career,Grade);
    }
}

void Btree::search(Node* leaf,string code,Node* &aux){
    if (leaf){
        if (code == leaf->get_Student()->get_Code()){
            aux = leaf;
        }
        search(leaf->get_Left(),code,aux);
        search(leaf->get_Right(),code,aux);
    }
}

Node* Btree::min(){
    if(root){
        Node* min = root;
        while (min->get_Left()){
            min = min->get_Left();
        }
        return min;
    }
    else
        return NULL;

}

Node* Btree::max(){
    if (root){
        Node* max = root;
        while (max->get_Right()){
            max = max->get_Right();
        }
        return max;
    }
    else
        return NULL;
}

Node* Btree::deleteNode(Node* root, float grade){
    if (!root)
        return root;
 
    if (grade < root->get_Student()->get_Grade()){
        root->set_Left(deleteNode(root->get_Left(), grade));
        return root;
    }
    else if (grade > root->get_Student()->get_Grade()){
        root->set_Right(deleteNode(root->get_Right(), grade));
        return root;
    }
 
    if (!root->get_Left()) {
        Node* tmp = root->get_Right();
        delete root;
        return tmp;
    }
    else if (!root->get_Right()) {
        Node* tmp = root->get_Left();
        delete root;
        return tmp;
    }
 
    else {

        Node* succParent = root;
        Node* succ = root->get_Right();

        while (succ->get_Left()) {
            succParent = succ;
            succ = succ->get_Left();
        }
 
        if (succParent != root)
            succParent->set_Left(succ->get_Right());
        else
            succParent->set_Right(succ->get_Right());
 
        root->set_Student(succ->get_Student());
 
        delete succ;
        return root;
    }
}

void Btree::inOrderPrint(Node* leaf){

    if(root){
        if (leaf){
            inOrderPrint(leaf->get_Left());
            leaf->show();
            inOrderPrint(leaf->get_Right());
        }
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::preOrderPrint(Node* leaf){

    if (root){
        if (leaf){
            leaf->show();
            inOrderPrint(leaf->get_Left());
            inOrderPrint(leaf->get_Right());
        }        
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::postOrderPrint(Node* leaf){

    if (root){
        if (leaf != NULL){
            inOrderPrint(leaf->get_Left());
            inOrderPrint(leaf->get_Right());
            leaf->show();
        }
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::to_string(Node* leaf, string& text){

    if (root){
        if (leaf){
            to_string(leaf->get_Left(),text);
            text += leaf->save_student();
            to_string(leaf->get_Right(),text);
        }
    }
    else
        cout<<"Arbol vacio"<<endl;
    
}

void Btree::Save(){
    string text = "";
    to_string(root,text);

    ofstream file;
    file.open("file01.txt",ios::out);

    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    file<<text;
    file.close();
}

void Btree::Fields(string& record){
    int i=0;

    string name = "";

    while(record[i] != '|'){
        name += record[i];
        i++;
    }

    i++;

    string code = "";

    while(record[i] != '|'){
        code += record[i];
        i++;
    }

    i++;

    string career = "";

    while(record[i] != '|'){
        career += record[i];
        i++;
    }

    i++;

    string grade = "";

    while(record[i] != '|'){
        grade += record[i];
        i++;
    }

    insert(name,code,career,stof(grade),root);
}

void Btree::Load(){
    Node* leaf = root;

    ifstream file;

    file.open("file01.txt",ios::in);

    if(file.is_open()){
        file.seekg(0,file.end);
        int size = file.tellg();
        file.seekg(0,file.beg);

        char* buffer = new char[size];

        file.read(buffer,size);
        int i=0;
        string record = "";

        while(i<size){
            if(buffer[i] != '*'){
                record += buffer[i];
            }
            else{
                Fields(record);
                record = "";
            }
            i++;
        }
        file.close();
    }
    else{
        return;
    }
}