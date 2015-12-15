/*
    this file contains the SMS class which inherits PhoneCall
*/

#include "PhoneCall.h"
using namespace std;

class SMS:public PhoneCall{
    private:
        string text;
        double textCost;
        static double textRate;
        static int textLimit;

    public:
        SMS(string textNumber,string textContent):PhoneCall(textNumber){
            this->setText(textContent);
        }
        void setText(string text);
        static void setTextRate(double rate);
        static void setTextLimit(int textLimit);

        string getText();
        double getTextCost();
        int getTextLength();
        static double getTextRate();
        static int getTextLimit();
};

int SMS::textLimit=0;
double SMS::textRate=0;

void SMS::setText(string text){
    this->text=text;

}
void SMS::setTextRate(double rate){
    textRate=rate;
}
void SMS::setTextLimit(int limit){
    textLimit=limit;
}

string SMS::getText(){
    return this->text;
}
double SMS::getTextCost(){
    int charCount=this->text.length();
    return charCount*this->textRate;
}
double SMS::getTextRate(){
    return textRate;
}
int SMS::getTextLimit(){
    return textLimit;
}

int SMS::getTextLength(){
    string s1=this->getText();
    return s1.length();
}

/*
int main(){

    SMS::setTextLimit(200);
    SMS::setTextRate(.2);

    string text,textNum;
    cout<<"Enter recepient: ";
    getline(cin,textNum);
    cout<<"Enter Text: \t ";
    getline(cin,text);
    SMS s1(textNum,text);

    cout<<endl;
    cout<<s1.getStartDate()<<endl;
    cout<<s1.getStartTime()<<endl;
    cout<<s1.getText()<<endl;
    cout<<s1.getTextCost()<<endl;
    cout<<s1.getCallNumber()<<endl;
}
*/


