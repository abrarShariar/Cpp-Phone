/*
    this file contains all the necessary error handling functions used throughout the program
*/

#include<iostream>
using namespace std;

bool errorPhoneCount(string phoneCount){
    bool error=false;
    for(int i=0;i<phoneCount.length();i++){
        if(phoneCount[0]==48){
            error=true;
            break;
        }
        if(phoneCount[i]<48 || phoneCount[i]>57){
            error=true;
            break;
        }
    }
    if(error){
        cout<<"\nCaution : Invalid Input "<<endl;
    }
    return error;
}
