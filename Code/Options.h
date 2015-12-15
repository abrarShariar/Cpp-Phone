/*
    This file contains all the functionalities which are accessible by the Main Controller
    See main function
*/
#include "SFML.h"
#include "error.h"
#include "Calculator.h"

Phone activePhone;
Person alphaPerson;

Person selectPerson();
void selectPhone(Person activePerson);
bool processMenu(string option);
void chooseApp();
void usePhoneApp();
void useTextApp();
void viewPersonDetails();
void registerPerson();
void useContactsApp();
void useCalculatorApp();
//select from pre-registered person
Person selectPerson(){
    vector<Person>personList;

    map<int,string> selectMap;
    selectMap=RegisterPerson::readRegisterPerson();

    //display all registered person
    printf("\n\n\tAll Registered Person :\n\n");
    for(auto it=selectMap.begin();it!=selectMap.end();it++){
        cout<<"\t["<<it->first<<"] : "<<it->second<<endl;
        Person person(it->second);
        personList.push_back(person);
    }

    cout<<endl;

    //activated person
    int index;
    printf("Choose Person [index]: ");
    cin>>index;
    if(index>=personList.size()){
        throw "Caution: Please Enter Valid Index";
    }

    Person activePerson=personList[index];
    printf("\n\t\t%c%c ",219,219);
    cout<<activePerson.getPersonName()<<" is Activated !!"<<"\n\n";

    return activePerson;
}

//select phone for a person
void selectPhone(Person activePerson){
        stringstream ss;
        vector<Phone>phoneList;
        //Register Phone to Person
        cout<<"Register Phone for "<<activePerson.getPersonName()<<endl;
        string phoneCount;
        int pCount;
        do{
            cout<<"\nNumber of Phones: ";
            cin>>phoneCount;
        }while(errorPhoneCount(phoneCount));
        ss<<phoneCount;
        ss>>pCount;


        printf("\n");
        for(int i=0;i<pCount;i++){
            Phone phn(activePerson.getPersonId());
            cout<<"\tPhone["<<i<<"] : "<<phn.getPhoneNumber()<<endl;
            phoneList.push_back(phn);
        }
        cout<<endl;

        //Select Phone
        int phnIndex;
        cout<<"Select Phone: ";
        cin>>phnIndex;
        if(phnIndex<0 || phnIndex>=pCount){
                cout<<"\nCaution : Invalid Input\n"<<endl;
                return;
        }


        activePhone=phoneList[phnIndex];
        //Phone activities
        double credit;
        cout<<"\nUsing Phone["<<phnIndex<<"]: "<<activePhone.getPhoneNumber()<<"\t";
        cout<<"Load Credit:(tk) ";
        cin>>credit;
        activePhone.setPhoneCredit(credit);
}

//Process Controller/Main menu options
bool processMenu(string option){
        bool flag=true;
        int opt=666;
        for(int i=0;i<6;i++){
            if(arrOption[i]==option){
                opt=i;
                break;
            }
            else if(option=="[x]" || option=="[X]"){
                opt=4;
                break;
            }
        }
        switch(opt){
        case 0:
        {
            try{
                alphaPerson=selectPerson();
                selectPhone(alphaPerson);
            }catch(const char* exp){
                cerr<<"\n"<<exp<<endl;
            }
            break;
        }
        case 1:
            //RegisterPerson code here
            registerPerson();
            break;
        case 2:
            try{
            showPhoneScreen();
            }catch(exception exp){
                cout<<"\nUnable to display Phone Screen\n"<<endl;
            }

            chooseApp();
            break;
        case 3:
            viewPersonDetails();
            //ViewDetails code here
            break;
        case 4:
            //EXIT code here
            flag=false;
            break;
        case 5:
            system("cls");
            printf("%c%c",219,219);
            displayMenu();
            string option=chooseMenu();
            processMenu(option);
            break;
        }
        return flag;
}

//Choose Phone App (see SFML)
void chooseApp(){
    string appName;
    printf("\n\n\tChoose App [Full Name] : ");
    cin>>appName;
    printf("\n");
    if(appName=="Phone" || appName=="phone"){
            usePhoneApp();
    }
    else if(appName=="Contacts" || appName=="contacts"){
            useContactsApp();
    }
    else if(appName=="Text" || appName=="text"){
            useTextApp();
    }
    else if(appName=="Calculator" || appName=="calculator" || appName=="cal"){
        useCalculatorApp();
    }
}

void useCalculatorApp(){
    double ans=0;
    string opr;
    showCalculator();
    cout<<"\n\n";
    cout<<"\t\tOperator: ";
    cin>>opr;
    if(opr=="+"){
        ans=add();
    }else if(opr=="-"){
        ans=sub();
    }else if(opr=="*"){
        ans=mul();
    }else if(opr=="/"){
        try{
            ans=div();
        }catch(const char* exp){
            cout<<"\n"<<exp<<endl;
        }
    }else if(opr=="sq"){
        double num;
        cout<<"\t\t"<<"Input: ";
        cin>>num;
        ans=sqrt(num);
    }else if(opr=="sin"){
        double num;
        cout<<"\t\t"<<"Input: ";
        cin>>num;
        ans=sin(num*PI/180);
    }else if(opr=="cos"){
        double num;
        cout<<"\t\t"<<"Input: ";
        cin>>num;
        ans=cos(num*PI/180);
    }else if(opr=="tan"){
        double num;
        cout<<"\t\t"<<"Input: ";
        cin>>num;
        ans=tan(num*PI/180);
    }else if(opr=="cb"){
        double num;
        cout<<"\t\t"<<"Input: ";
        cin>>num;
        ans=cbrt(num);
    }else if(opr=="pow"){
        double base,power;
        cout<<"\t\t"<<"Input [base]: ";
        cin>>base;
        cout<<"\t\t"<<"Input [power]: ";
        cin>>power;
        ans=pow(base,power);
    }else if(opr=="ln"){
        double num;
        cout<<"\t\t"<<"Input: ";
        cin>>num;
        ans=log(num);
    }else if(opr=="e"){
        double num;
        cout<<"\t\t"<<"Input: ";
        cin>>num;
        ans=exp(num);
    }

    cout<<"\n\t\tANSWER: "<<ans<<endl;




}

void useContactsApp(){
    //vector<PhoneBook>tempBook;
    char chk;
    cout<<"\n\t\t[PhoneBook]\n"<<endl;
    string fileName=activePhone.getPhoneNumber()+".txt";
    activePhone.myPhoneBook=addPhoneBookEntry(fileName);
    cout<<"\nView Contact List (y/n): ";
    cin>>chk;
    cout<<"\n\t\t\t[Contact List]\n"<<endl;
    if(chk=='y'){
        int len=activePhone.myPhoneBook.size();

        for(int i=0;i<len;i++){
             PhoneBook entry=activePhone.myPhoneBook[i];
            cout<<"\t\t"<<entry.getContactName()<<" : "<<entry.getContactNumber()<<endl;
        }
    }else{

    }
    cout<<endl;
}

//access the features of SMS
void useTextApp(){
    SMS::setTextLimit(200);
    SMS::setTextRate(0.2);
    bool exit=false;
    string opt;
    do{
        cout<<"Press + to send New Message & X to EXIT: ";
        cin>>opt;
        flushLine();

        if(opt=="+"){
            string num;
            cout<<"\tEnter recipient : ";
            getline(cin,num);
            if(validPhoneNumber(num)){
                string text;
                cout<<"\tEnter Text:\t";
                getline(cin,text);
                if(text.length()>SMS::getTextLimit()){
                    cout<<"\nCaution: Word Limit Exceeded\n\n";
                    continue;
                }

                activePhone.newSMS(num,text);
                cout<<"Sending ";
                loading();
                cout<<"\a Message Successfully Sent !! \n"<<endl;
            }else{
                 cout<<"INVALID PHONE NUMBER\n"<<endl;
                    continue;
            }
        }else if(opt=="x" || opt=="X"){
            break;
        }else{
            cout<<"\nPlease Enter A Valid Option \n"<<endl;
        }
    }while(!exit);

     char chk;
        cout<<"\nView Message History (y/n) : ";
        cin>>chk;
        cout<<endl;
        if(chk=='y'){
            viewSmsHistory(activePhone);
            }
        alphaPerson.phoneBox.push_back(activePhone);
}


//access all features of Phone
void usePhoneApp(){
    string opt;
    cout<<"\n\t\t[Phone]\n"<<endl;
    do{
        cout<<"\tPress + to Call & X to EXIT : ";
        cin>>opt;
        if(opt=="+"){
                string num;
                cout<<"\n\tCall Number: ";
                cin>>num;
                if(validPhoneNumber(num)){
                    //PhoneCall myCall(num);
                    activePhone.newPhoneCall(num);
                    cout<<"Calling ";
                        loading();
                    cout<<" \a\aCall received \n"<<endl;
                }else{
                    cout<<"\tINVALID PHONE NUMBER\n"<<endl;
                    continue;
                    }
        }else if(opt=="x" || opt=="X"){
            break;
        }else{
            cout<<"\nPlease Enter A Valid Option \n"<<endl;
        }
    }while(true);

        char chk;
        cout<<"\n\t\tView Call History (y/n) : ";
        cin>>chk;
        cout<<endl;
        if(chk=='y'){
            viewCallHistory(activePhone);
            }
        alphaPerson.phoneBox.push_back(activePhone);
}

//access all the features of Contacts/ PhoneBook

//view details of a Person
void viewPersonDetails(){
 char chk;
    cout<<"View Phone Details of (y/n) "<<alphaPerson.getPersonName()<<" : ";
    cin>>chk;
    printf("\n\n");
    if(chk=='y'){
        cout<<"Total Credit Available :"<<alphaPerson.getTotalCredit()<<" tk"<<endl;
        cout<<"Average Call Length: "<<alphaPerson.getAvgCallLength()/60<<endl;
        cout<<"Max Call Number: "<<alphaPerson.getMaxCallNumber()<<endl;
    }
}

void registerPerson(){
    int regPerson;
    printf("\nHow many Person you want to register : ");
    cin>>regPerson;
    flushLine();
    printf("\n\n");

    for(int i=0;i<regPerson;i++){
        string name;
        cout<<"\t\t["<<i+1<<"]Person Name: ";
        getline(cin,name);
        RegisterPerson::setRegisterPerson(name);
    }
    RegisterPerson::writeRegisterPerson();
}




