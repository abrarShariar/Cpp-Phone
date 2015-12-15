#include<iostream>
#include<vector>
#include<stdlib.h>
#include<sstream>


class PhoneCall{
        string callNumber;
        double callDuration;
    public:
        void setCallNumber(string num){
            callNumber=num;
        }
        string getCallNumber(){
            return callNumber;
        }
        double getCallDuration(){
            return rand()%20+1;
        }
};
