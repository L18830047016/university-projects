        #pragma once
        #include <iostream>
        using namespace std;
        
        class Person{
            private:
                int id;
                int age;
                string name;
            public:
                static string country; //静态成员变量
                static void ShowCountry();//静态成员函数
                //设值函数
                void SetId(int id);
                void SetAge(int age);
                void SetName(string name);
                //取值函数
                int GetId();
                int GetAge();
                string GetName();
        
                void ShowInfo();
        };
       