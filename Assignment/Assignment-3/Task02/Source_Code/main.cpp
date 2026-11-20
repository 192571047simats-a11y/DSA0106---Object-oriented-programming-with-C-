#include <iostream>
#include <string>
class Prescription{int n;std::string* meds;
public:explicit Prescription(int count):n(count),meds(new std::string[count]){}
Prescription(const Prescription&o):n(o.n),meds(new std::string[o.n]){for(int i=0;i<n;++i)meds[i]=o.meds[i];}
Prescription& operator=(const Prescription&o){if(this!=&o){std::string* p=new std::string[o.n];for(int i=0;i<o.n;++i)p[i]=o.meds[i];delete[] meds;meds=p;n=o.n;}return *this;}
~Prescription(){delete[] meds;}void set(int i,std::string s){if(i>=0&&i<n)meds[i]=std::move(s);}std::string get(int i)const{return meds[i];}};
int main(){Prescription p(2);p.set(0,"Paracetamol");p.set(1,"ORS");Prescription q=p;q.set(1,"Cetirizine");Prescription r(1);r=p;p.set(0,"Ibuprofen");std::cout<<p.get(0)<<' '<<p.get(1)<<" | "<<q.get(0)<<' '<<q.get(1)<<" | "<<r.get(0)<<' '<<r.get(1)<<'\n';}