/*
    This Class contains members and member functions for a Phone object
    Phone objects access PhoneCall members so, PhoneCall.h is included
    <vector> is introduced here, the following references contributed to this code:

    http://stackoverflow.com/questions/8221702/accessing-elements-of-a-vector-in-c
    http://www.cplusplus.com/reference/vector/vector/operator[]/
*/

//#include "PhoneCall.h"
#include "SMS.h"
#include "PhoneBook.h"
#include<vector>
using namespace std;

class Phone{
    private:
        string phoneNumber;
        double phoneCredit;
        vector<PhoneCall>callHistory;
        vector<SMS>smsHistory;
    public:
        Phone();
        Phone(int id);

        vector<PhoneBook>myPhoneBook;
        void setPhoneNumber(int personId);
        void setPhoneCredit(double phoneCredit);

        string getPhoneNumber();
        double getPhoneCredit();

        static string basePhoneNumber;
        static int phoneCount;
        static int getPhoneCount();

        void newPhoneCall(string num);
        PhoneCall getCallHistory(int index);
        int getCallHistorySize();
        void newSMS(string num,string text);
        SMS getSmsHistory(int index);
        int getSmsHistorySize();
        string getYear();
};
Phone::Phone(){
    this->phoneNumber="";
    this->phoneCredit=0;
}

Phone::Phone(int id){
        phoneCount++;
        this->setPhoneNumber(id);
        this->phoneCredit=0;
}

void Phone::setPhoneNumber(int personId){
    stringstream ss1,ss2,ss3,ss4,ss5;
    string temp;
    long int i_number;

    string number=basePhoneNumber+getYear();
    number=number+"000";
    ss1<<number;
    ss1>>i_number;

    i_number=i_number+personId;
    ss2<<i_number;
    ss2>>number;

    number=number+"00";
    ss3<<number;
    ss3>>i_number;

    i_number=i_number+phoneCount;
    ss4<<i_number;
    ss4>>number;

    int lnum=rand()%10;
    ss5<<lnum;
    ss5>>temp;
    number="0"+number+temp;

    this->phoneNumber=number;
}
void Phone::setPhoneCredit(double phoneCredit){
        this->phoneCredit=phoneCredit;
}

//Call
void Phone::newPhoneCall(string num){
        PhoneCall call(num);
        double credit=this->getPhoneCredit()-call.getCallCost();
        this->setPhoneCredit(credit);
        this->callHistory.push_back(call);
}
//SMS
void Phone::newSMS(string num,string text){
    SMS sms(num,text);
    double credit=this->getPhoneCredit()-sms.getTextCost();
    this->setPhoneCredit(credit);
    this->smsHistory.push_back(sms);
}



string Phone::getPhoneNumber(){
        return this->phoneNumber;
}
double Phone::getPhoneCredit(){
        return this->phoneCredit;
}

//static members
string Phone::basePhoneNumber="017";
int Phone::phoneCount=0;
int Phone::getPhoneCount(){
        return phoneCount;
}

//Call
PhoneCall Phone::getCallHistory(int index){
    return this->callHistory[index];
}
int Phone::getCallHistorySize(){
    return this->callHistory.size();              //returns the size of the callHistory vector
}

//SMS
SMS Phone::getSmsHistory(int index){
    return this->smsHistory[index];
}
int Phone::getSmsHistorySize(){
    return this->smsHistory.size();
}

string Phone::getYear(){
        time_t clock=time(0);
        tm *now=localtime(&clock);
        int year=1900+(now->tm_year);

        string newYear="";
        for(int i=0;i<2;i++){
            stringstream ss;
            string stDigit;
            int digit=year%10;
            year=year/10;
            ss<<digit;
            ss>>stDigit;
            newYear=stDigit+newYear;
        }
        return newYear;
}





