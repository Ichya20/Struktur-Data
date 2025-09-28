#include <iostream>
using namespace std;

int main(){
    float a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    if(b!=0) cout<<a/b<<endl;
    else cout<<"Error"<<endl;
    return 0;
}
