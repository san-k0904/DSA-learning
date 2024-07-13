#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> A={4,1,8,7};
    vector<int> B={2,3,6,5};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int AbsoluteMin=0;
    for(int i=0;i<A.size();i++){
        AbsoluteMin+= abs(A[i]-B[i]);
    }

    cout<<AbsoluteMin<<endl;
    return 0;

}