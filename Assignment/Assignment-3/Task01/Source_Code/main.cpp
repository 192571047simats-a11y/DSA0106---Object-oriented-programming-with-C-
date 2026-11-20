#include <iostream>
#include <stdexcept>
#include <string>
class Book{std::string title;int copies;
public:Book():Book("Untitled",0){}explicit Book(std::string t):Book(std::move(t),1){}
Book(std::string t,int c):title(std::move(t)),copies(c){if(c<0)throw std::invalid_argument("negative copies");}
void print()const{std::cout<<title<<" copies="<<copies<<'\n';}};
int main(){Book a;Book b("C++");Book c("OOP",5);a.print();b.print();c.print();}