#include <cstring>
#include <iostream>
class DynamicString {
    char* buffer;
public:
    explicit DynamicString(const char* s):buffer(new char[std::strlen(s)+1]){std::strcpy(buffer,s);}
    DynamicString(const DynamicString& other):buffer(new char[std::strlen(other.buffer)+1]){std::strcpy(buffer,other.buffer);}
    DynamicString& operator=(const DynamicString& other){if(this!=&other){char* p=new char[std::strlen(other.buffer)+1];std::strcpy(p,other.buffer);delete[] buffer;buffer=p;}return *this;}
    ~DynamicString(){delete[] buffer;}
    void print()const{std::cout<<buffer<<'\n';}
};
int main(){DynamicString s1("Antigravity C++");DynamicString s2=s1;s2.print();}