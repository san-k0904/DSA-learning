#include<iostream>
using namespace std;
void TOH(char src,char aux,char dest,int n){
    if(n==1){
        cout<<"Move disk"<<n<<" from "<<src<<" to "<<dest<<"\n";
        return;
    }
    TOH(src,dest,aux,n-1);
    cout<<"Move disk"<<n<<" from "<<src<<" to "<<dest<<"\n";
    TOH(aux,src,dest,n-1);
}
int main(){
    TOH('A','B','C',3);
    return 0;
}