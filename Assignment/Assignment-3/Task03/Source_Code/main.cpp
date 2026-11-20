#include <iostream>
#include <vector>
class Event{std::vector<std::vector<bool>> seats;
public:Event(int r,int c):seats(r,std::vector<bool>(c,false)){}
bool book(int r,int c){if(r<0||c<0||r>=static_cast<int>(seats.size())||c>=static_cast<int>(seats[r].size())||seats[r][c])return false;seats[r][c]=true;return true;}
~Event(){std::cout<<"Event closed; rows="<<seats.size()<<'\n';}};
int main(){Event e(2,3);std::cout<<e.book(0,1)<<' '<<e.book(0,1)<<'\n';}