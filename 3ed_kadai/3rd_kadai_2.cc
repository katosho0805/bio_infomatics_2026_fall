#include <stdio.h>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
    float a=1.0,b=10000.0,c=1.0;
    float x1,x2=0.0;
    
    x1=(-b+sqrt(b*b-4*a*c))/(2*a);
    x2=-(b+sqrt(b*b-4*a*c))/(2*a);//配慮してないもの

    cout << setprecision(10) << x1 << "," << x2 <<endl;

    float x3=(c/a)/x2;
    cout << setprecision(10) << x3 << endl;
    
    return 0;
}
//0,-10000
//-9.999999747e-05