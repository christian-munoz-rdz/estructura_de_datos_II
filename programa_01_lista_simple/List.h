#include "Node.h"
#include<fstream>
#include<string>

class List{
private:
    Node* Head;

public:
    List();

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

List::List(){ 
	Head = NULL;
}

bool List::Empty(){
    return Head==NULL;
}

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

void List::Delete(string code){
    Node* n= Search(code);
    
    if(n==NULL){
        cout << "No se encontro el estudiante..." << endl;
    }
    else{
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

string List::Show_list(){ 
    Node* n = Head;
    string text = "";
    
    if(Empty()){ 
        return "La lista esta vacia...";
    }
    
    while(n!=NULL){ 
        text += n->get_Data_show()+"\n"; 
        n=n->get_Next(); 
    }
    return text;
}

string List::Show_Data(string code){ 
   Node* n = Search(code);

    if(n==NULL){ 
       return "No existe el estudiante";
   }
    return n->get_Data_show(); 
}

Node* List::Search(string code){ 
    Node* aux=Head;

    while(aux!=NULL){ 
        if(aux->Record.get_Code()==code){
            return aux; 
        }
        aux= aux->get_Next();
    }
    return NULL; 
}

void List::Clear(){
    Node* aux;
    
    int count = 0;
    while(Head!=NULL){
        aux=Head;
        Head=Head->get_Next();
        delete aux;
        count++; 
    }
    cout<<"Lista completamente vacia..."<<endl;
    cout<<"Se eliminaron "<<count<<" elementos..."<<endl; 
}

Node* List::Last(){

    if(Head==NULL){
        return Head;
    }
    
    Node* aux=Head;

    while(aux->get_Next()!=NULL){
        aux=aux->get_Next(); 
    }
    return aux; 
}

Node* List::First(){
    return Head;
}

void List::Save(){

    if(Empty())
        cout<<"La lista esta vacia"<<endl;                               
    
    Node* n=Head;

    string text;

    while(n!=NULL){
        text += n->get_Data_save();
        n=n->get_Next();
    }

    ofstream file;

    file.open("data.txt",ios::out);
    
    if(file.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    file<<text;
    file.close(); 
}

void List::Fields(string& record){
    int i=0;
    
    string Name="";
    
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

    Student s(Name,Code,Career,Grade);

    Insert(Last(),s);
}

void List::Load(){
    Node* aux=Head;

    ifstream file;

    file.open("data.txt",ios::in);

    if(file.is_open()){
        
        file.seekg(0,file.end); 
        int length=file.tellg(); 
        file.seekg(0,file.beg); 

        char *buffer = new char[length]; 

        file.read(buffer,length); 
        
        int i=0; 
        string record=""; 
    
        while(i<length){ 
            if(buffer[i]!='*'){ 
                record+=buffer[i]; 
            }
            else{ 
                Fields(record); 
                record=""; 
            }
            i++; 
        }
        file.close(); 
    }
    else{
        return; 
    }
}

