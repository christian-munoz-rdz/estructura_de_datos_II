#include "Node.h"
#include<fstream>
#include<string>

//Clase Arbol ABB tiene un solo atributo: raiz
class Btree{
private:
    Node* root;
public:
    //Constructor y destructor
    Btree();
    ~Btree();

    //Metodos get
    Node* getRoot();
    void setRoot(Node*);

    //Metodo para insertar un nodo
    void insert(string,string,string,float,Node*);

    //Metodo para buscar un nodo
    void search(Node*,string,Node*&);

    //Metodo para mostrar el minimo y el maximo
    Node* min();
    Node* max();

    //Meotod para eliminar un nodo
    Node* deleteNode(Node*, float);

    //Metodo para mostrar el arbol en orden
    void inOrderPrint(Node*);

    //Metodo para mostrar el arbol en preorden
    void preOrderPrint(Node*);

    //Metodo para mostrar el arbol en postorden
    void postOrderPrint(Node*);

    //Metodos para guardar el arbol en un archivo
    void to_string(Node*,string&);
    void Save();
    void Fields(string&);
    //Metodo para cargar el arbol desde un archivo
    void Load();
};

//El constructor por defecto inicializa la raiz en NULL
Btree::Btree(){
    root = NULL;
}

// getRoot retorna la raiz del arbol
Node* Btree::getRoot(){
    return root;
}

// setRoot recibe un nodo y lo asigna a la raiz
void Btree::setRoot(Node* root){
    this->root = root;
}

// insert recibe 5 parametros: nombre, codigo, carrera, promedio (atributos de la clase Estudiante) y un nodo que es el nodo actual
void Btree::insert(string Name,string Code,string Career,float Grade, Node* leaf){

    // Si el arbol no esta vacio y el nodo actual no es NULL
    if (root){
        if(Grade < leaf->get_Student()->get_Grade()){ // Si el promedio es menor que el promedio del nodo actual
            if (leaf->get_Left()){ // Si el nodo actual tiene un hijo izquierdo
                insert(Name,Code,Career,Grade,leaf->get_Left()); // Se llama recursivamente al metodo insert con el hijo izquierdo como nodo actual
            }
            else{ // Si el nodo actual no tiene un hijo izquierdo
                Node* newNode = new Node(Name,Code,Career,Grade); // Se crea un nuevo nodo 
                leaf->set_Left(newNode); // Se asigna el nuevo nodo como hijo izquierdo del nodo actual
            }  
        }
        else if (Grade >= leaf->get_Student()->get_Grade()){ // Si el promedio es mayor o igual que el promedio del nodo actual
            if (leaf->get_Right()){ // Si el nodo actual tiene un hijo derecho
                insert(Name,Code,Career,Grade,leaf->get_Right()); // Se llama recursivamente al metodo insert con el hijo derecho como nodo actual
            }
            else{ // Si el nodo actual no tiene un hijo derecho
                Node* newNode = new Node(Name,Code,Career,Grade); // Se crea un nuevo nodo
                leaf->set_Right(newNode); // Se asigna el nuevo nodo como hijo derecho del nodo actual
            } 
        } 
    }
    else{ // Si el arbol esta vacio
        root = new Node(Name,Code,Career,Grade); // Se crea un nuevo nodo y se asigna a la raiz
    }
}

// search recibe 3 parametros: un nodo que es el nodo actual, un string que es el codigo del estudiante a buscar y un nodo que es el nodo encontrado
void Btree::search(Node* leaf,string code,Node* &aux){ // Se pasa por referencia el nodo encontrado para que se pueda modificar en el metodo
    if (leaf){ // Si el nodo actual no es NULL
        if (code == leaf->get_Student()->get_Code()){ // Si el codigo del estudiante a buscar es igual al codigo del nodo actual 
            aux = leaf; // Se asigna el nodo actual al nodo encontrado
        }
        search(leaf->get_Left(),code,aux); // Se llama recursivamente al metodo search con el hijo izquierdo como nodo actual
        search(leaf->get_Right(),code,aux); // Se llama recursivamente al metodo search con el hijo derecho como nodo actual
    }
}

// min retorna el nodo con el menor promedio
Node* Btree::min(){ // Se recorre el arbol hasta llegar al nodo con el menor promedio
    if(root){ // Si el arbol no esta vacio
        Node* min = root; // Se crea un nodo que apunta a la raiz
        while (min->get_Left()){ // Mientras el nodo actual tenga un hijo izquierdo
            min = min->get_Left(); // Se asigna el hijo izquierdo como nodo actual
        }
        return min; // Se retorna el nodo con el menor promedio
    }
    else
        return NULL; // Si el arbol esta vacio se retorna NULL

}

// max retorna el nodo con el mayor promedio
Node* Btree::max(){ // Se recorre el arbol hasta llegar al nodo con el mayor promedio
    if (root){ // Si el arbol no esta vacio
        Node* max = root; // Se crea un nodo que apunta a la raiz
        while (max->get_Right()){ // Mientras el nodo actual tenga un hijo derecho
            max = max->get_Right(); // Se asigna el hijo derecho como nodo actual
        }
        return max; // Se retorna el nodo con el mayor promedio
    }
    else
        return NULL; // Si el arbol esta vacio se retorna NULL
}

// deleteNode recibe 2 parametros: un nodo que es el nodo actual y un float que es el promedio del estudiante a eliminar para recorrer el arbol en orden
Node* Btree::deleteNode(Node* root, float grade){ 
    if (!root) // Si el nodo actual es NULL
        return root; // Se retorna el nodo actual
 
    if (grade < root->get_Student()->get_Grade()){ // Si el promedio es menor que el promedio del nodo actual
        root->set_Left(deleteNode(root->get_Left(), grade)); // Se llama recursivamente al metodo deleteNode con el hijo izquierdo como nodo actual
        return root; // Se retorna el nodo actual
    }
    else if (grade > root->get_Student()->get_Grade()){ // Si el promedio es mayor que el promedio del nodo actual
        root->set_Right(deleteNode(root->get_Right(), grade)); // Se llama recursivamente al metodo deleteNode con el hijo derecho como nodo actual
        return root; /// Se retorna el nodo actual
    }
 
    if (!root->get_Left()) { // Si el nodo actual no tiene un hijo izquierdo
        Node* tmp = root->get_Right(); // Se crea un nodo temporal que apunta al hijo derecho del nodo actual
        delete root; // Se elimina el nodo actual
        return tmp; // Se retorna el nodo temporal
    }
    else if (!root->get_Right()) { // Si el nodo actual no tiene un hijo derecho
        Node* tmp = root->get_Left(); // Se crea un nodo temporal que apunta al hijo izquierdo del nodo actual 
        delete root; // Se elimina el nodo actual
        return tmp; // Se retorna el nodo temporal
    }
    else { // Si el nodo actual tiene dos hijos

        Node* succParent = root; // Se crea un nodo que apunta al nodo actual
        Node* succ = root->get_Right(); // Se crea un nodo que apunta al hijo derecho del nodo actual

        while (succ->get_Left()) { // Mientras el nodo actual tenga un hijo izquierdo
            succParent = succ; // Se asigna el nodo sucesor como nuevo padre del nodo sucesor
            succ = succ->get_Left(); // Se asigna el hijo izquierdo como nodo sucesor
        }
 
        if (succParent != root) // Si el nodo padre del nodo actual no es el nodo actual
            succParent->set_Left(succ->get_Right()); // Se asigna el hijo derecho del nodo sucesor como hijo izquierdo del nodo padre del nodo actual
        else
            succParent->set_Right(succ->get_Right()); // Se asigna el hijo derecho del nodo actual como hijo derecho del nodo padre del nodo actual
 
        root->set_Student(succ->get_Student()); // Se asigna el estudiante del nodo sucesor como el estudiante del nodo encontrado
 
        delete succ; // Se elimina el nodo sucesor
        return root; // Se retorna el nodo actual
    }
}

// inOrderPrint recibe 1 parametro: un nodo que es el nodo actual
void Btree::inOrderPrint(Node* leaf){ 

    if(root){ // Si el arbol no esta vacio
        if (leaf){ // Si el nodo actual no es NULL
            inOrderPrint(leaf->get_Left()); // Se llama recursivamente al metodo inOrderPrint con el hijo izquierdo como nodo actual
            leaf->show(); // Se muestra el estudiante del nodo actual
            inOrderPrint(leaf->get_Right()); // Se llama recursivamente al metodo inOrderPrint con el hijo derecho como nodo actual
        }
    }
    else // Si el arbol esta vacio
        cout<<"Arbol vacio"<<endl; // Se muestra un mensaje

}

// preOrderPrint recibe 1 parametro: un nodo que es el nodo actual
void Btree::preOrderPrint(Node* leaf){

    if (root){ // Si el arbol no esta vacio
        if (leaf){ // Si el nodo actual no es NULL
            leaf->show(); // Se muestra el estudiante del nodo actual
            inOrderPrint(leaf->get_Left()); // Se llama recursivamente al metodo inOrderPrint con el hijo izquierdo como nodo actual
            inOrderPrint(leaf->get_Right()); // Se llama recursivamente al metodo inOrderPrint con el hijo derecho como nodo actual
        }        
    }
    else // Si el arbol esta vacio
        cout<<"Arbol vacio"<<endl; // Se muestra un mensaje

}

// postOrderPrint recibe 1 parametro: un nodo que es el nodo actual
void Btree::postOrderPrint(Node* leaf){ 

    if (root){ // Si el arbol no esta vacio
        if (leaf != NULL){ // Si el nodo actual no es NULL
            inOrderPrint(leaf->get_Left()); // Se llama recursivamente al metodo inOrderPrint con el hijo izquierdo como nodo actual
            inOrderPrint(leaf->get_Right()); // Se llama recursivamente al metodo inOrderPrint con el hijo derecho como nodo actual
            leaf->show(); // Se muestra el estudiante del nodo actual
        }
    }
    else // Si el arbol esta vacio
        cout<<"Arbol vacio"<<endl; // Se muestra un mensaje

}

// to_string recibe 2 parametros un nodo que es el nodo actual y un string que es el string que se va a retornar
void Btree::to_string(Node* leaf, string& text){ // Se pasa por referencia el string para que se modifique en el metodo

    if (root){ // Si el arbol no esta vacio
        if (leaf){ // Si el nodo actual no es NULL
            to_string(leaf->get_Left(),text); // Se llama recursivamente al metodo to_string con el hijo izquierdo como nodo actual
            text += leaf->save_student(); // Se concatena el string que retorna el metodo save_student del nodo actual al string que se va a retornar
            to_string(leaf->get_Right(),text); // Se llama recursivamente al metodo to_string con el hijo derecho como nodo actual
        }
    }
    else // Si el arbol esta vacio
        cout<<"Arbol vacio"<<endl; // Se muestra un mensaje
    
}

// save guarda los estudiantes del arbol en un archivo
void Btree::Save(){
    string text = ""; // Se crea un string vacio
    to_string(root,text); // Se llama al metodo to_string con el nodo raiz como nodo actual y el string vacio como string que se va a retornar

    ofstream file; // Se crea un objeto de la clase ofstream
    file.open("file01.txt",ios::out); // Se abre el archivo file01.txt en modo escritura

    if(file.fail()){ // Si el archivo no se pudo abrir
        cout<<"No se pudo abrir el archivo"<<endl; // Se muestra un mensaje
        exit(1); // Se termina el programa
    }
    file<<text; // Se escribe el string en el archivo
    file.close(); // Se cierra el archivo
}

// Fields recibe 1 parametro string que es un registro para guardar en el arbol
void Btree::Fields(string& record){ // Se pasa por referencia el string para que se modifique en el metodo
    int i=0; // Se crea una variable entera i y se le asigna el valor 0

    string name = ""; // Se crea un string vacio que guardara el nombre del estudiante

    while(record[i] != '|'){ // Mientras el caracter en la posicion i del string no sea un |
        name += record[i]; // Se concatena el caracter en la posicion i del string al string name
        i++; // Se incrementa i
    }

    i++; // Se incrementa i para que apunte al caracter siguiente al |

    string code = "";  // Se crea un string vacio que guardara el codigo del estudiante

    while(record[i] != '|'){ // Mientras el caracter en la posicion i del string no sea un |
        code += record[i]; // Se concatena el caracter en la posicion i del string al string code
        i++;
    }

    i++; // Se incrementa i para que apunte al caracter siguiente al |

    string career = ""; // Se crea un string vacio que guardara la carrera del estudiante

    while(record[i] != '|'){ // Mientras el caracter en la posicion i del string no sea un |
        career += record[i]; // Se concatena el caracter en la posicion i del string al string career
        i++;
    }

    i++; // Se incrementa i para que apunte al caracter siguiente al |

    string grade = ""; // Se crea un string vacio que guardara la nota del estudiante

    while(record[i] != '|'){ // Mientras el caracter en la posicion i del string no sea un |
        grade += record[i]; // Se concatena el caracter en la posicion i del string al string grade
        i++;
    }

    insert(name,code,career,stof(grade),root); // Se llama al metodo insert con los datos del estudiante y el nodo raiz como nodo actual
}

// load carga los estudiantes del archivo al arbol
void Btree::Load(){ 
    Node* leaf = root; // Se crea un nodo que apunta a la raiz del arbol

    ifstream file; // Se crea un objeto de la clase ifstream

    file.open("file01.txt",ios::in); // Se abre el archivo file01.txt en modo lectura

    if(file.is_open()){ // Si el archivo se pudo abrir
        file.seekg(0,file.end); // Se posiciona el cursor al final del archivo
        int size = file.tellg(); // Se obtiene la posicion del cursor
        file.seekg(0,file.beg); // Se posiciona el cursor al inicio del archivo

        char* buffer = new char[size]; // Se crea un arreglo de caracteres con el tamaño del archivo

        file.read(buffer,size); // Se lee el archivo y se guarda en el arreglo de caracteres
        int i=0; // Se crea una variable entera i y se le asigna el valor 0
        string record = ""; // Se crea un string vacio que guardara un registro

        while(i<size){ // Mientras i sea menor al tamaño del archivo
            if(buffer[i] != '*'){ // Si el caracter en la posicion i del arreglo de caracteres no es un *
                record += buffer[i]; // Se concatena el caracter en la posicion i del arreglo de caracteres al string record
            }
            else{ // Si el caracter en la posicion i del arreglo de caracteres es un *
                Fields(record); // Se llama al metodo Fields con el string record como parametro
                record = ""; // Se le asigna el valor vacio al string record para que guarde el siguiente registro
            }
            i++; // Se incrementa i
        }
        file.close(); // Se cierra el archivo
    }
    else{ // Si el archivo no se pudo abrir
        return; // Se retorna
    }
}