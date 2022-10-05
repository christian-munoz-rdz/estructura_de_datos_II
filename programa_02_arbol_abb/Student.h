#include <iostream>
#include<string>

using namespace std;

// Clase estudiante tiene 4 atributos: nombre, codigo, carrera y promedio
class Student{
private:
    string Name;
    string Code;
    string Career;
    float Grade;

public:
    // Constructor
    Student(string,string,string,float);
    Student();

    // Metodos set
    void setName(string);
    void setCode(string);
    void setCareer(string);
    void setGrade(float);

    // Metodos get
    string get_Name();
    string get_Code();
    string get_Career();
    float get_Grade();
};

// Constructor de la clase recibe 4 parametros de tipo string
Student::Student(string Name,string Code,string Career,float Grade){
    this->Name= Name;
    this->Code= Code;
    this->Career= Career;
    this->Grade= Grade;
}

// Constructor por defecto
Student::Student(){
    this->Name= "";
    this->Code= "";
    this->Career= "";
    this->Grade= 0;
}

// Metodos set

// Metodo set para el nombre
void Student::setName(string Name){
    this->Name= Name;
}

// Metodo set para el codigo
void Student::setCode(string Code){
    this->Code= Code;
}

// Metodo set para la carrera
void Student::setCareer(string Career){
    this->Career= Career;
}

// Metodo set para el promedio
void Student::setGrade(float Grade){
    this->Grade= Grade;
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
float Student::get_Grade(){
    return Grade;
}
