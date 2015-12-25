/*
    This file contains necessary functions used as extensions in the main program
    the following links contributed to this code:
    file i/o	http://www.cplusplus.com/doc/tutorial/files/
    <fstream>	http://www.cplusplus.com/reference/fstream/fstream/
    http://www.cplusplus.com/reference/ostream/ostream/operator%3C%3C/
    <limits>    http://stackoverflow.com/questions/5918451/why-getline-skips-first-line
*/
#include "Person.h"
#include "RegisterPerson.h"
#include<fstream>
#include<limits>
#include<cstdio>
#include<ctime>
#include "SFML.cpp"

using namespace std;

//SFML function declaration
void showPhoneScreen();
void playMusic(string name);

/*
    Write/Read entire PhoneBook entry passed by vector<PhoneBook> into
    the specified fileName
*/
 /*
    code to fix first line skip of getline()
    the following code is found at:
    http://stackoverflow.com/questions/5918451/why-getline-skips-first-line
    */
void flushLine(){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
vector<string> readFromFile(string fileName){
    vector<string> readFile;
    ifstream read;
    read.open(fileName);
    string output;
    while(getline(read,output)){
        readFile.push_back(output);
    }
    read.close();
    return readFile;
}

void displayFile(string fileName){
    ifstream display;
    string line;
    display.open(fileName);
    while(getline(display,line)){
        cout<<line<<endl;
    }
    display.close();
}

void writeToFile(vector<PhoneBook> myPhoneBook,string fileName){
    ofstream write;
    fileName="PhoneBook/"+fileName;
    write.open(fileName);
    for(int i=0;i<myPhoneBook.size();i++){
        PhoneBook phoneBook=myPhoneBook[i];
        string name=phoneBook.getContactName();
        string number=phoneBook.getContactNumber();
        write<<name<<" : "<<number<<endl;
    }
    write.close();
}

//function to validate if a number is a valid phone number
bool validPhoneNumber(string number){
    bool chk;
    if(number.length()==11){
            for(int i=0;i<number.length();i++){
                if(number[i]>=48 && number[i]<=57){
                    chk=true;
                }else{
                    chk=false;
                    break;
                }
            }
    }else{
        chk=false;
    }
    return chk;
}
/*
Function to display Call History/details
*/
void viewCallHistory(Phone phone){
    for(int i=0;i<phone.getCallHistorySize();i++){
         PhoneCall call=phone.getCallHistory(i);
        cout<<"Call Details["<<i+1<<"]"<<endl;
        cout<<"Call Number: "<<call.getCallNumber()<<"\t";
        cout<<"Rate: "<<call.getCallRate()<<"p/s"<<endl;
        cout<<"Duration: "<<call.getCallDuration()/60<<"min\t";
        cout<<"Cost: "<<call.getCallCost()<<"tk"<<endl;
        cout<<"Start Date: "<<call.getStartDate()<<"\t"<<"Start Time: "<<call.getStartTime()<<endl;
        cout<<endl;
    }
}

void viewSmsHistory(Phone phone){
    for(int i=0;i<phone.getSmsHistorySize();i++){
        cout<<"\n";
        SMS sms=phone.getSmsHistory(i);
        cout<<"Message Details["<<i+1<<"]"<<endl;
        cout<<"Text: \t"<<sms.getText()<<endl;
        cout<<"Recipient: "<<sms.getCallNumber()<<"\t";
        cout<<"Rate: "<<sms.getTextRate()<<"p/s"<<endl;

        cout<<"Text Length: "<<sms.getTextLength()<<"\t\t";
        cout<<"Cost: "<<sms.getTextCost()<<"tk"<<endl;
        cout<<"Start Date: "<<sms.getStartDate()<<"\t"<<"Start Time: "<<sms.getStartTime()<<endl;
        cout<<"\n";
    }

}

/*
    Function to be used on PhoneBook objects
    return true duplicate entry is found and false otherwise
*/
bool checkDuplicate(vector<string>phoneBook){
    for(int i=0;i<phoneBook.size();i++){
        int chk=0;
        string check=phoneBook[i];
        for(int j=0;j<phoneBook.size();j++){
            if(phoneBook.at(j)==check){
                chk++;
            }
        }
        if(chk>1){
            return true;
            break;
        }
    }
    return false;
}
/*
    Function to add a vector<PhoneBook> to the given fileName
*/
vector<PhoneBook> addPhoneBookEntry(string fileName){
    string temp1,temp2;
    int ct;
    stringstream ss;
    vector<PhoneBook>tempPhoneBook;
    PhoneBook preEntry("Abrar Shariar","01715002999");
    tempPhoneBook.push_back(preEntry);
    preEntry.setContactName("Rakib Hasan");
    preEntry.setContactNumber("01715002067");
    tempPhoneBook.push_back(preEntry);
    preEntry.setContactName("Fahim Khan");
    preEntry.setContactNumber("01719999999");
    tempPhoneBook.push_back(preEntry);
    preEntry.setContactName("Steve Jobs");
    preEntry.setContactNumber("01710000000");
    tempPhoneBook.push_back(preEntry);

    printf("Number of Phone Book Entry: ");
    scanf("%d",&ct);

    for(int i=0;i<ct;i++){
        PhoneBook myEntry;
        printf("Contact Number: ");
        cin>>temp1;
        flushLine();
        myEntry.setContactNumber(temp1);
        printf("Contact Name: ");
        getline(cin,temp2);
        myEntry.setContactName(temp2);
        tempPhoneBook.push_back(myEntry);
        cout<<endl;
    };

    //to write myPhoneBook to a file
    writeToFile(tempPhoneBook,fileName);
    return tempPhoneBook;
}
/*
    Function to choose new Person
    returns a person object
*/
Person choosePerson(vector<Person>personList,string index){
    for(int i=0;i<personList.size();i++){
       Person per=personList[i];
        if(index==per.getPersonName()){
            return per;
            break;
        }
    }
}

void loading(){
    int show=219;
    for(int i=0;i<50;i++){
        for(int j=0;j<7000000;j++){
        }
        printf("%c",show);
    }
}

/*
string showDate(){
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

        string startDate=m+"/"+d+"/"+y;
        return startDate;
}

string showTime(){
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

       string startTime=h+":"+m+":"+s;
        return startTime;
}
*/


// SEE RegisterPerson.h
void preRegister(){
    map<int,string> preMap;
    RegisterPerson::setRegisterPerson("Abrar Shariar");
    RegisterPerson::setRegisterPerson("Steve Jobs");
    RegisterPerson::setRegisterPerson("Mike");
    RegisterPerson::setRegisterPerson("Harry Potter");
    RegisterPerson::setRegisterPerson("Batman");
    RegisterPerson::setRegisterPerson("Mark Tyson");
    RegisterPerson::setRegisterPerson("Henry Ford");
    RegisterPerson::setRegisterPerson("Rakib Hasan");
    RegisterPerson::setRegisterPerson("Fahim Khan");
    RegisterPerson::setRegisterPerson("Gilfoyle");
    RegisterPerson::setRegisterPerson("Richard Hendricks");
    RegisterPerson::setRegisterPerson("Bruce Wayne");
    RegisterPerson::setRegisterPerson("Jon Snow");

    RegisterPerson::writeRegisterPerson();
}

//Functions to handle MENU activities
string arrOption[]={"[+S]","[+R]","[+P]","[+D]","[X]","[#]"};
void displayMenu(){
    string arrText[]={"Select Person","Register Person","Use C++ Phone","View Details","EXIT","View Main Controller/ Refresh"};
    char icon=219;
    //HEAD
     for(int i=0;i<30;i++){
        cout<<icon;
    }
    cout<<" MAIN Controller \n"<<endl;

    //Body
    // fist 2 icon
    for(int i=0;i<2;i++){
       cout<<arrOption[i]<<"\t\t\t";
    }
    cout<<endl;
    // first 2 text
    for(int i=0;i<2;i++){
        cout<<arrText[i]<<"\t\t";
    }
    cout<<"\n\n";
    //second 2 icon
    for(int i=2;i<4;i++){
        cout<<arrOption[i]<<"\t\t\t";
    }
    cout<<endl;
    //second 2 text
    for(int i=2;i<4;i++){
        cout<<arrText[i]<<"\t\t";
    }
    cout<<"\n\n";
    //last two icon
    for(int i=4;i<6;i++){
        cout<<arrOption[i]<<"\t\t\t";
    }
    cout<<endl;
    //last two text
    for(int i=4;i<6;i++){
        cout<<arrText[i]<<"\t\t\t";
    }

    cout<<"\n";
    for(int i=0;i<30;i++){
        cout<<icon;
    }
    cout<<endl;
}

string chooseMenu(){
    bool valid=false;
    string option;
    cout<<" Choose Controller Option: ";
    cin>>option;
    option="["+option+"]";
    for(int i=0;i<6;i++){
        if(option==arrOption[i]){
            valid=true;
            break;
        }
        else if(option=="[x]"){
            valid=true;
            break;
        }
    }
    if(valid==false){
        return "INVALID INPUT !!";
    }else{
        return option;
    }
}

void wait(){
    for(int i=0;i<40;i++){
        for(int j=0;j<7000000;j++){
        }
    }
}

void showCalculator(){
 //first row
    cout<<"\t\t"<<"[+]"<<"\t\t"<<"[-]"<<"\t\t"<<"[*]"<<"\t\t"<<"[/]"<<endl;
    cout<<"\t\t"<<"Add"<<"\t\t"<<"Subtract"<<"\t"<<"Multiply"<<"\t"<<"Divide"<<endl;
    cout<<endl;
    //second row
    cout<<"\t\t"<<"[sq]"<<"\t\t"<<"[sin]"<<"\t\t"<<"[cos]"<<"\t\t"<<"[tan]"<<endl;
    cout<<"\t\t"<<"square root"<<"\t"<<"sine"<<"\t\t"<<"cosine"<<"\t\t"<<"tangent"<<endl;
    cout<<endl;
    //third row
    cout<<"\t\t"<<"[cb]"<<"\t\t"<<"[pow]"<<"\t\t"<<"[ln]"<<"\t\t"<<"[e]"<<endl;
    cout<<"\t\t"<<"cubic root"<<"\t"<<"power"<<"\t\t"<<"ln"<<"\t\t"<<"exp"<<endl;
    cout<<endl;
}


//call to showPhoneScreen() in SFML.h


