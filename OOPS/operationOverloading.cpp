#include<iostream>
using namespace std;
class Complex{
    public:
        int real;
        int img;
        Complex(int real,int img){
            this->real=real;
            this->img=img;
        }
        Complex operator - (Complex& c2){
            int resReal= this->real - c2.real;
            int resImg= this->img - c2.img;
            Complex c3(resReal,resImg);
            return c3;
        }
};
int main(){
    Complex c1(5,6);
    Complex c2(2,3);
    Complex res= c1 - c2;
    cout<<"Result is: "<<res.real<<" + "<<res.img<<"i\n";
    return 0;

}