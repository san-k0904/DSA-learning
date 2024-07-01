#include<iostream>
using namespace std;

class Person{
    public:
        string name;
        int age;
        Person(string name,int age){
            this->name=name;
            this->age=age;
        }
        
};
class Student:public Person{
    public:
        string studentID;
        Student(string name,int age,string studentID):Person(name,age){
            this->studentID=studentID;
        }
};
int main(){
    Student student("Alice",20,"S12345");
    cout<<"Name: "<<student.name<<"\n";
    cout<<"Age: "<<student.age<<"\n";
    cout<<"Student ID: "<<student.studentID<<"\n";
    return 0;
}