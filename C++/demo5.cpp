#include <iostream>
using namespace std;

typedef struct{
    int id; //4bytes  0,1,2,3
    int age; //4bytes  4,5,6,7
    double height; //8bytes  8,9,10,11,12,13,14,15
    char* name; //8bytes  16,17,18,19,20,21,22,23 
}Person; //24bytes

//值类型参数
void showPerson(Person person);
//指针类型参数
void showPerson2(Person* person);

int main(){
    Person p1 = {1, 18, 1.75, "Alice"};
    showPerson(p1);
    showPerson2(&p1);
    return 0;
}

//值类型参数 24bytes
void showPerson(Person person){
    cout << "ID: " << person.id << endl;
    cout << "Age: " << person.age << endl;
    cout << "Height: " << person.height << endl;
    cout << "Name: " << person.name << endl;
}

//指针类型参数 8bytes
void showPerson2(Person* person){
    cout << "ID: " << person->id << endl;
    cout << "Age: " << person->age << endl;
    cout << "Height: " << person->height << endl;
    cout << "Name: " << person->name << endl;
}