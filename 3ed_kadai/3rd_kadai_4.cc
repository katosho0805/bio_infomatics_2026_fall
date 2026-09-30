#include <iostream>
#include <iomanip>
#include <cmath>       
using namespace std;

double f1(double x) {
    return exp(x) + x - 5;        
}
double f2(double x) {
    return cbrt(x);      
}
double f3(double x) {
    return exp(x)+1;        // f1の導関数
}
double f4(double x) {
    return ((double)1/3)/cbrt(x*x);      // f2の導関数  
}

int main(void){
    double x_1=0.0,x_2=-0.1;
    int count_1=0,count_2=0;
    while(count_1<1000){
        double x_next;
        x_next=x_1-f1(x_1)/f3(x_1);
        if(abs(x_next-x_1)<1e-12){
            break;
        }
        count_1++;
        x_1=x_next;
    }

    while(count_2<1000){
        double x_next;
        x_next=x_2-f2(x_2)/f4(x_2);
        if(abs(x_next-x_2)<1e-12){
            break;
        }
        count_2++;
        x_2=x_next;
    }
    cout << setprecision(15);
    cout << "x1=" << x_1 << ",count_1=" << count_1 << endl;
    cout << "x2=" << x_2 << ",count_2=" << count_2 << endl;
    return 0;

}

