#include <iostream>
#include <exception>
#include <string>
class DatabaseError:public std::exception {std::string details;public:explicit DatabaseError(std::string s):details(std::move(s)){}const char* what()const noexcept override{return details.c_str();}};
class TimeoutError:public DatabaseError {public:int timeoutMs;TimeoutError(std::string s,int ms):DatabaseError(std::move(s)),timeoutMs(ms){}};
void executeQuery(){throw TimeoutError("Query timed out connecting to shard 3",5000);}
void intermediateAuditor(){try{executeQuery();}catch(const DatabaseError& e){std::cout<<"[AUDIT LOG]: Intercepted DB error.\n";throw;}}
int main(){try{intermediateAuditor();}catch(const TimeoutError& e){std::cout<<"Client caught TimeoutError! Duration: "<<e.timeoutMs<<" ms\n";}catch(const DatabaseError& e){std::cout<<"Client caught generic DatabaseError: "<<e.what()<<'\n';}}