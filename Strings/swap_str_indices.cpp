#include<iostream>
using namespace std;

bool Check_strings(string original,string checkString){
    int size=original.length();
    if(original!=checkString){
        for(int i=0;i<size;i++){
            if(original[i]!=checkString[i]){
                for(int j=i+1;j<size;j++){
                    swap(checkString[i],checkString[j]);
                    if(original==checkString){
                        return true;
                    }
                    swap(checkString[i],checkString[j]);
                }
                return false;
            }
        }
    }
    else
        return true;
}
int main(){
    string original,checkString;
    cout<<"Enter your String: ";
    getline(cin,original);//can give delimiter...optional
    cout<<"Enter another String: ";
    getline(cin,checkString);
    if(original.length()!=checkString.length())
        cout<<(boolalpha)<<false<<"\n";
    else
        cout<<(boolalpha)<<Check_strings(original,checkString)<<"\n";
    return 0;
}