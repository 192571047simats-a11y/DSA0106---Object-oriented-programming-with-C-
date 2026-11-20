#include <iostream>
#include <string>
class Student {
    int roll; std::string name;
public:
    Student():roll(0),name("Not assigned"){}
    Student(int r,std::string n):roll(r),name(std::move(n)){}
    void display()const{std::cout<<"Roll: "<<roll<<", Name: "<<name<<'\n';}
};
int main(){Student batch[3];batch[0]=Student(101,"Aarav");batch[1]=Student(102,"Bhavna");batch[2]=Student(103,"Chirag");for(const auto&s:batch)s.display();}