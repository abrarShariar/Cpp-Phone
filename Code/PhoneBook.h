/*
    This class is part of an extension to the other classes.
    Creates a PhoneBook entry for each phone
    Data members are: private
    Member functions: public
*/

#include<iostream>
using namespace std;

class PhoneBook{
    private:
        string contactName;
        string contactNumber;
        int contactIndex;
    public:
        PhoneBook();
        PhoneBook(string contactName,string contactNumber);
        //setters
        void setContactName(string contactName);
        void setContactNumber(string contactNumber);
        //getters
        string getContactName();
        string getContactNumber();
        int getContactIndex();
        //static members
        static int contactCount;
        static void getContactCount();
};

int PhoneBook::contactCount=0;
PhoneBook::PhoneBook(){
    this->contactName="";
    this->contactNumber="";
    contactCount++;
    this->contactIndex=contactCount;
}

PhoneBook::PhoneBook(string contactName,string contactNumber){
    this->contactName=contactName;
    this->contactNumber=contactNumber;
    contactCount++;
}

void PhoneBook::setContactName(string contactName){
    this->contactName=contactName;
}
void PhoneBook::setContactNumber(string contactNumber){
    this->contactNumber=contactNumber;
}

string PhoneBook::getContactName(){
    return this->contactName;
}
string PhoneBook::getContactNumber(){
    return this->contactNumber;
}
int PhoneBook::getContactIndex(){
    return this->contactIndex;
}




