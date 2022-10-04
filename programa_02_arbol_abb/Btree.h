#include "Node.h"

class Btree{
public:
    Node* root;

    Btree();
    ~Btree();

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
};

Btree::Btree(){
    root = NULL;
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
            while (tmp->get_Right()){
                tmp = tmp->get_Right();
            pre = tmp ;
        }

        if (begin->get_Right()){
            Node* tmp = begin->get_Right();
            while (tmp->get_Left()){
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
 
    if (root->id > id) {
        root->left = deleteNode(root->left, id);
        return root;
    }
    else if (root->id < id) {
        root->right = deleteNode(root->right, id);
        return root;
    }
 
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    else {
 
        Node* succParent = root;
 
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        root->id = succ->id;
        root->name = succ->name;
        root->direction = succ->direction;
        root->email = succ->email;
 
        delete succ;
        return root;
    }
}

void Btree::inOrderPrintRoot(){
    
    if (root){
        inOrderPrint(root);
        cout << "\n";
    }
    else
        cout<<"Arbol vacio"<<endl;
    

}

void Btree::inOrderPrint(Node* leaf){
    if (leaf!=NULL){
        inOrderPrint(leaf->left);
        leaf->show();
        inOrderPrint(leaf->right);
    }
}

void Btree::preOrderPrintRoot(){
    if (root){
        preOrderPrint(root);
        cout<<"\n";        
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::preOrderPrint(Node* leaf){
    if (leaf!=NULL){
        leaf->show();
        inOrderPrint(leaf->left);
        inOrderPrint(leaf->right);
    }
    
}

void Btree::postOrderPrintRoot(){

    if (root){
        postOrderPrint(root);
        cout<<"\n";
    }
    else
        cout<<"Arbol vacio"<<endl;

}

void Btree::postOrderPrint(Node* leaf){
    
    if (leaf != NULL){
        inOrderPrint(leaf->left);
        inOrderPrint(leaf->right);
        leaf->show();
    }
}