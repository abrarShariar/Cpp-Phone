/*
    This class contains members and member functions of PhoneCall objects
    All the data members are private and member functions are public
    Static members are public
    The following link contributed valuable info for the functions used from those header fies:
    <ctime>     http://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
*/
#include<iostream>
#include<ctime>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

class PhoneCall{
    protected:
        string callNumber;
        string startTime;
        string startDate;
        double callDuration;
        double callCost;
    public:
        PhoneCall(string callNumber);
        void setStartTime();
        void setStartDate();
        void setCallDuration();
        void setCallCost();

        string getCallNumber();
        string getStartTime();
        string getStartDate();
        double getCallDuration();
        double getCallCost();

        static int callCount;
        static double callRate;
        static int getCallCount();
        static double getCallRate();
        static void setCallRate(double rate);
};

int PhoneCall::callCount=0;
double PhoneCall::callRate=0.0;

PhoneCall::PhoneCall(string callNumber){
    this->callNumber=callNumber;
    this->setStartTime();
    this->setStartDate();
    this->setCallDuration();
    this->setCallCost();
    callCount++;
}

void PhoneCall::setStartTime(){
        time_t now=time(0);
        tm *ptm=localtime(&now);
        int hour=(ptm->tm_hour);
        int mint=(ptm->tm_min);
        int sec=(ptm->tm_sec);

        stringstream c_hour,c_mint,c_sec;
        c_hour<<hour;
        string h=c_hour.str();
        c_mint<<mint;
        string m=c_mint.str();
        c_sec<<sec;
        string s=c_sec.str();

        this->startTime=h+":"+m+":"+s;
}
void PhoneCall::setStartDate(){
        time_t now=time(0);
        tm *ptm=localtime(&now);
        int day=(ptm->tm_mday);
        int month=(ptm->tm_mon)+1;
        int year=1900+((ptm->tm_year));

        stringstream c_day,c_month,c_year;
        c_day<<day;
        string d=c_day.str();
        c_month<<month;
        string m=c_month.str();
        c_year<<year;
        string y=c_year.str();

        this->startDate=m+"/"+d+"/"+y;
}
void PhoneCall::setCallDuration(){
        this->callDuration=rand()%(30*60);
}
void PhoneCall::setCallCost(){
    double cost=this->getCallDuration()*getCallRate();
    cost=cost/100;
    this->callCost=cost;
}

//getters
string PhoneCall::getCallNumber(){
        return this->callNumber;
}
string PhoneCall::getStartTime(){
        return this->startTime;
}
string PhoneCall::getStartDate(){
        return this->startDate;
}
double PhoneCall::getCallDuration(){
        return this->callDuration;
}
double PhoneCall::getCallCost(){
        return this->callCost;
}

int PhoneCall::getCallCount(){
    return callCount;
}
void PhoneCall::setCallRate(double rate){
    callRate=rate;
}
double PhoneCall::getCallRate(){
    return callRate;
}

