/*
    This class contains members and member functions of Person objects
    Person objects access Phone object's members so, Phone.h is included
    Data members are private
    Containers are public
    Members functions are public

    The following link contributed to this code:
    find_first_of()	http://www.cplusplus.com/reference/string/string/find_first_of/
    substr() 	http://www.cplusplus.com/reference/string/string/substr/

*/

#include "Phone.h"
using namespace std;

//class to create new Persons objects
class Person{
    private:
        string personName;
        int personId;

    public:
        vector<string>allCallNumber;
        vector<Phone>phoneBox;
        //Person(){ };
        Person();
        Person(string name);
                                                        //NOTE: here setters are not used since person name and id is set by constructor
        string getPersonName();
        int getPersonId();
        double getTotalCredit();
        double getAvgCallLength();
        double getCostLastMonth(int index);
        string getMaxCallNumber();
        int getPhoneBoxSize();

    //static members
        static int personCount;
        static int getPersonCount();
};

Person::Person(){
    this->personName="";
    this->personId=0;
}

Person::Person(string name){
        this->personName=name;
        personCount++;
        this->personId=personCount;
}

int Person::getPhoneBoxSize(){
        return this->phoneBox.size();
}

//getters
string Person::getPersonName(){
        return this->personName;
}
int Person::getPersonId(){
        return this->personId;
}
double Person::getTotalCredit(){
        double sumCredit=0;
        for(int i=0;i<this->phoneBox.size();i++){
            double credit=phoneBox[i].getPhoneCredit();
            sumCredit=sumCredit+credit;
        }
        return sumCredit;
}

double Person::getAvgCallLength(){
    double totalCallLength=0,callCount=0;
     for(int i=0;i<this->phoneBox.size();i++){
        Phone myPhn=this->phoneBox[i];
        for(int j=0;j<myPhn.getCallHistorySize();j++){
            PhoneCall myCall=myPhn.getCallHistory(j);
            totalCallLength=totalCallLength+myCall.getCallDuration();
            callCount++;
        }
     }
     return totalCallLength/callCount;
}

double Person::getCostLastMonth(int index){
        Phone phn=this->phoneBox[index];

        time_t now=time(0);
        tm *ptm=localtime(&now);
        int currentMonth=ptm->tm_mon+1;
        int previousMonth=currentMonth-1;
        if(previousMonth==0){
            previousMonth=12;
        }

        double totalCost=0;
        for(int i=0;i<phn.getCallHistorySize();i++){
            PhoneCall call=phn.getCallHistory(i);
            string date=call.getStartDate();

            int digit;
            size_t pos=date.find_first_of("/",0);
            date=date.substr(0,pos);
            stringstream ss;
            ss<<date;
            ss>>digit;

            if(digit==previousMonth){
                totalCost=totalCost+call.getCallCost();
            }
        }
        return totalCost;
}

string Person::getMaxCallNumber(){
        int sz=this->getPhoneBoxSize();
    //store all call numbers from all Phone in phoneBox into the vector allCallNumber
        for(int i=0;i<sz;i++){
            Phone phn=this->phoneBox[i];
            for(int j=0;j<phn.getCallHistorySize();j++){
                PhoneCall call=phn.getCallHistory(j);
                string num=call.getCallNumber();
                this->allCallNumber.push_back(num);
            }
        }
    //calculate the maximum callNumber stored in vector allCallNumber
        int mxCount=0,inCount;
        string mxCall;
        for(int i=0;i<allCallNumber.size();i++){
            string check=allCallNumber[i];
            inCount=0;
            for(int j=0;j<allCallNumber.size();j++){
                if(i==j){
                    continue;
                }
                else if(check==allCallNumber[j]){
                    inCount++;
                }
            }
            if(inCount>mxCount){
                mxCount=inCount;
                mxCall=check;
            }
        }
        if(mxCall!=""){
            return mxCall;
        }
        else{
            return "NULL";
        }
}

//static members
int Person::personCount=0;
int Person::getPersonCount(){
        return personCount;
}






