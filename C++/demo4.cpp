#include <iostream>
#include <cstring>
using namespace std;

typedef struct{
  int id;  
  int age;  
  double height;
  char name[50];
} Person;

void printArr(int *arr, int size);
void printArr1(int arr[]);
void show_person(Person person);

int main(void){
  int nums[]={12,67,88,99,46};
  printArr(nums,5);
  printArr1(nums);
  Person p;
  p.id=100;
  p.age=18;
  p.height=185.5;
  strcpy(p.name, "tom");
  show_person(p);
  return 0;
}
void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printArr1(int arr[]){
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// 值类型参数
void show_person(Person person){
  cout<<"id:"<<person.id;
  cout<<"age:"<<person.age;
  cout<<"name:"<<person.name;
  cout<<"height:"<<person.height;
}
