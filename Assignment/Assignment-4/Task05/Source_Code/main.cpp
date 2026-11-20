#include <iostream>
class Student{int mark;public:explicit Student(int m):mark(m){}Student& setMark(int m){this->mark=m;return *this;}void show()const{std::cout<<this->mark<<'\n';}};
int main(){Student s(70);s.setMark(90).show();Student* p=&s;p->show();}