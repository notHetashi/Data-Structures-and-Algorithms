#include <iostream>
using namespace std;

struct Rectangle{
    int x;
    int y;
    int w;
    int h;
};

int main(){
    Rectangle dimensions1, dimensions2;
    cout << "Enter the coordinates (x,y) and dimensions (w,h) of rectangle a: ";
    cin >> dimensions1.x >> dimensions1.y >> dimensions1.w >> dimensions1.h;
    
    cout << "Enter the coordinates (x,y) and dimensions (w,h) of rectangle b: ";
    cin >> dimensions2.x >> dimensions2.y >> dimensions2.w >> dimensions2.h;
    
    int inters_x=max(dimensions1.x, dimensions2.x);
    int inters_y=max(dimensions1.y, dimensions2.y);
    int inters_w=min(dimensions1.x + dimensions1.w, dimensions2.x + dimensions2.w) - inters_x;
    int inters_h=min(dimensions1.y + dimensions2.h, dimensions2.y + dimensions2.h) - inters_y;
    
    if (inters_w <= 0 || inters_h <=0){
        inters_w = inters_h=0;
    }
    
    cout << "Result: " << "(" << inters_x << ", " << inters_y << ", " << inters_w << ", " << inters_h <<")"<< endl;
    
    return 0;
}