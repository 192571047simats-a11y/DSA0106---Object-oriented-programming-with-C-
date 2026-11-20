#include <iostream>
int getMaximumScaled(int a, int b, int scaleFactor) {
    return ((a > b) ? a : b) * scaleFactor;
}
int& getArrayElement(int arr[], int index) { return arr[index]; }
int main() {
    int x=10, y=20;
    int scaled = getMaximumScaled(x,y,2);
    int data[3]={100,200,300};
    getArrayElement(data,1)=999;
    std::cout << "Scaled Max: " << scaled << '\n';
    std::cout << "Updated Array[1]: " << data[1] << '\n';
    std::cout << "Scaled Max Value: " << scaled << '\n';
}