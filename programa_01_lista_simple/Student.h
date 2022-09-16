#include <iostream>
#include<string>

using namespace std;

class Student{
private:
    string Name;
    string Code;
    string Career;
    string Grade;

public:
    Student(string,string,string,string);

    string toString_show();
    string toString_save();

    string get_Name();
    string get_Code();
    string get_Career();
    string get_Grade();

    Student& operator= (const Student&);
    bool operator==(const Student&);
};

Student::Student(string _Name,string _Code,string _Career,string _Grade){
    Name=_Name;
    Code=_Code;
    Career=_Career;
    Grade=_Grade;
}

string Student::toString_show(){  
    string data;
    data += Name+ "||" + Code + "||" + Career + "||" + Grade;
    return data;
}

string Student::toString_save(){
    string data;
    data+=Name+"|"+Code+"|"+Career+"|"+Grade+"|"+"*";
    return data;
}

string Student::get_Name(){
    return Name;
}

string Student::get_Code(){
    return Code;
}

string Student::get_Career(){
    return Career;
}

string Student::get_Grade(){
    return Grade;
}

Student& Student::operator=(const Student& a1){
    Name=a1.Name;
    Code=a1.Code;
    Career=a1.Career;
    Grade=a1.Grade;
    return *this;
}

bool Student::operator==(const Student& c1){
    return Code==c1.Code;
}