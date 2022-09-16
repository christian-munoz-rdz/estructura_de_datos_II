#include <iostream>
#include<string>

using namespace std;

// Clase estudiante tiene 4 atributos: nombre, codigo, carrera y promedio
class Student{
private:
    string Name;
    string Code;
    string Career;
    string Grade;

public:
    // Constructor
    Student(string,string,string,string);

    // Metodos de la clase
    string toString_show();
    string toString_save();

    string get_Name();
    string get_Code();
    string get_Career();
    string get_Grade();

};

// Constructor de la clase recibe 4 parametros de tipo string
Student::Student(string _Name,string _Code,string _Career,string _Grade){
    Name=_Name;
    Code=_Code;
    Career=_Career;
    Grade=_Grade;
}

// Metodo que retorna un string con los datos del estudiante para mostrar en la consola
string Student::toString_show(){  
    string data;
    data += "Nombre: " + Name + "\n";
    data += "Codigo: " + Code + "\n";
    data += "Carrera: " + Career + "\n";
    data += "Promedio: " + Grade + "\n";
    return data;
}

// Metodo que retorna un string con los datos del estudiante para guardar en el archivo
string Student::toString_save(){
    string data;
    data+=Name+"|"+Code+"|"+Career+"|"+Grade+"|"+"*";
    return data;
}

// Metodos get

// get_Name retorna el nombre del estudiante
string Student::get_Name(){
    return Name;
}

// get_Code retorna el codigo del estudiante
string Student::get_Code(){
    return Code;
}

// get_Career retorna la carrera del estudiante
string Student::get_Career(){
    return Career;
}

// get_Grade retorna el promedio del estudiante
string Student::get_Grade(){
    return Grade;
}