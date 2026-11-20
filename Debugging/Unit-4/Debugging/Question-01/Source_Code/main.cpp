#include <iostream>
struct Person {int id;explicit Person(int n):id(n){std::cout<<"Person initialized: "<<id<<'\n';}};
struct Student:virtual Person {explicit Student(int n):Person(n){}};
struct Employee:virtual Person {explicit Employee(int n):Person(n){}};
struct TeachingAssistant:Student,Employee {TeachingAssistant(int n):Person(n),Student(n),Employee(n){}};
int main(){TeachingAssistant ta(101);std::cout<<"TA ID: "<<ta.id<<'\n';}