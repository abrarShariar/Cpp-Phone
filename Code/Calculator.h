#include<cmath>
using namespace std;

const double PI=3.14159;
double add(){
    double n1,n2;
    cout<<"\t\tInput[1] : ";
    cin>>n1;
    cout<<"\t\tInput[2] : ";
    cin>>n2;
    return n1+n2;
}
double sub(){
    double n1,n2;
    cout<<"\t\tInput[1] : ";
    cin>>n1;
    cout<<"\t\tInput[2] : ";
    cin>>n2;
    return n1-n2;
}
double mul(){
    double n1,n2;
    cout<<"\t\tInput[1] : ";
    cin>>n1;
    cout<<"\t\tInput[2] : ";
    cin>>n2;
    return n1*n2;
}
double div(){
    double n1,n2;
    cout<<"\t\tInput[1] : ";
    cin>>n1;
    cout<<"\t\tInput[2] : ";
    cin>>n2;
    if(n2==0){
        throw "Caution: Divided by zero is undefined ";
    }
    return n1/n2;
}


