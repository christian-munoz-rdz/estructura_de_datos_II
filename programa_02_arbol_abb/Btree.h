#include "Node.h"
#include<fstream>
#include<string>

class Btree{
private:
    Node* root;
public:

    Btree();
    ~Btree();

    bool Empty();

    Node* getRoot();
    void setRoot(Node*);

    void insertRoot(string,string,string,float);
    void insert(string,string,string,float,Node*);

    Node* searchRoot(float);
    Node* search(float, Node*);

    void searchNameRoot(string);
    void searchName(Node*,string);

    Node* min();
    Node* max();

    void findPredSuc(Node*,Node*&, Node*&, float);

    Node* deleteNode(Node*, float);

    void inOrderPrintRoot();
    void inOrderPrint(Node*);

    void preOrderPrintRoot();
    void preOrderPrint(Node*);

    void postOrderPrintRoot();
    void postOrderPrint(Node*);

    void to_stringRoot(string&);
    void to_string(Node*,string&);
    void Save();
    void Fields(string&);
    void Load();
};

Btree::Btree(){
    root = NULL;
}

bool Btree::Empty(){
    return root == NULL;
}

Node* Btree::getRoot(){
    return root;
}

void Btree::setRoot(Node* root){
    this->root = root;
}


void Btree::insertRoot(string Name,string Code,string Career,float Grade){
    if (root){
        insert(Name,Code,Career,Grade,root);
    }
    else{
        root = new Node(Name,Code,Career,Grade);
    }  
}

void Btree::insert(string Name,string Code,string Career,float Grade, Node* leaf){
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

Node* Btree::searchRoot(float Grade){
    return search(Grade,root);
}

Node* Btree::search(float grade, Node* leaf){
    if (leaf){
        if (grade == leaf->get_Student()->get_Grade()){
            return leaf;
        }
        else if (grade < leaf->get_Student()->get_Grade()){
            return search(grade,leaf->get_Left());
        }
        else{
            return search(grade,leaf->get_Right());
        }
    }
    else{
        return NULL;
    }
}

void Btree::searchNameRoot(string name){
    searchName(root,name);
}

void Btree::searchName(Node* leaf,string name){
    if (leaf){
        if (name == leaf->get_Student()->get_Name()){
            leaf->show();
            Node* pre = NULL, *suc = NULL;
            findPredSuc(root,pre,suc,leaf->get_Student()->get_Grade());
            if (pre)
                cout << "El predecesor es " << pre->get_Student()->get_Name() << endl;
            else
                cout << "No hay predecesor"<<endl; 
            if (suc)
                cout << "El succesor es " << pre->get_Student()->get_Name() <<endl;
            else
                cout << "No hay succesor"<<endl;
            return;
        }
        searchName(leaf->get_Left(),name);
        searchName(leaf->get_Right(),name);
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

void Btree::findPredSuc(Node* begin, Node*& pre, Node*& suc, float grade){
    if (!begin)  
        return ;
 
    if(begin->get_Student()->get_Grade() == grade){
        if (begin->get_Left()){
            Node* tmp = begin->get_Left();
            while (tmp->get_Right())
                tmp = tmp->get_Right();
            pre = tmp ;
        }

        if (begin->get_Right()){
            Node* tmp = begin->get_Right();
            while (tmp->get_Left())
                tmp = tmp->get_Left();
            suc = tmp ;
        }
        return;
    }
 
    if(begin->get_Student()->get_Grade() > grade){
        suc = begin ;
        findPredSuc(begin->get_Left(), pre, suc, grade);
    }
    else{
        pre = begin ;
        findPredSuc(begin->get_Right(), pre, suc, grade) ;
    }
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

void Btree::inOrderPrintRoot(){
    
    if(root){
        inOrderPrint(root);
    }
    else
        cout<<"Arbol vacio"<<endl;
    

}

void Btree::inOrderPrint(Node* leaf){
    if (leaf){
        inOrderPrint(leaf->get_Left());
        leaf->show();
        inOrderPrint(leaf->get_Right());
    }
}

void Btree::preOrderPrintRoot(){
    if (root){
        preOrderPrint(root);        
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::preOrderPrint(Node* leaf){
    if (leaf){
        leaf->show();
        inOrderPrint(leaf->get_Left());
        inOrderPrint(leaf->get_Right());
    }
    
}

void Btree::postOrderPrintRoot(){

    if (root){
        postOrderPrint(root);
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::postOrderPrint(Node* leaf){
    
    if (leaf != NULL){
        inOrderPrint(leaf->get_Left());
        inOrderPrint(leaf->get_Right());
        leaf->show();
    }
}

void Btree::to_stringRoot(string& text){
    if (root){
        to_string(root,text);
    }
    else
        cout<<"Arbol vacio"<<endl;
}

void Btree::to_string(Node* leaf, string& text){
    if (leaf){
        to_string(leaf->get_Left(),text);
        text += leaf->save_student();
        to_string(leaf->get_Right(),text);
    }
}

void Btree::Save(){
    string text = "";
    to_stringRoot(text);

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

    insertRoot(name,code,career,stof(grade));
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