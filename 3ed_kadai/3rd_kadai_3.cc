#include <iostream>
#include <cmath>       // exp と cbrt に必要
using namespace std;

double f1(double x) {
    return exp(x) + x - 5;        // eˣ + x − 5。eˣ は exp(x) で書く
}
double f2(double x) {
    return cbrt(x);        // xの三乗根。cbrt(x) を使う
}

int main(void) {
    double a_1= 0.0,b_1=2.0;
    double a_2= -0.1,b_2=0.2;
    int count_1=0,count_2=0;
    double x1,x2;
    
    while (count_1<1000) {
        x1=(a_1+b_1)/2;
        if(b_1-a_1<1e-12){
            break;
        }else if(f1(x1)*f1(a_1)<0){
            b_1=x1;
        }else{
            a_1=x1;
        }
        count_1++;
    }
    while (count_2<1000) {
        x2=(a_2+b_2)/2;
        if(b_2-a_2<1e-12){
            break;
        }else if(f2(x2)*f2(a_2)<0){
            b_2=x2;
        }else{
            a_2=x2;
        }
        count_2++;
    }
    cout << "x1=" << x1 << ",count_1=" << count_1 << endl;
    cout << "x2=" << x2 << ",count_2=" << count_2 << endl;

    return 0;
}
//x1=1.30656,count_1=41
//x2=-9.09495e-14,count_2=39