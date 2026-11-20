#include <iostream>
double cuboidVolume(double l,double w,double h){return l*w*h;}
double cubeVolume(double side){return side*side*side;}
double cylinderVolume(double radius,double height){return 3.14159*radius*radius*height;}
int main(){std::cout<<"Cube: "<<cubeVolume(5.0)<<'\n';std::cout<<"Cylinder: "<<cylinderVolume(3.0,7.0)<<'\n';std::cout<<"Cuboid: "<<cuboidVolume(5.0,2.0,3.0)<<'\n';}