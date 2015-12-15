/*
    C++ Phone software
    the main function is included here
    Compile and run this file
*/

#include "Options.h"

void showBasicInst();
int main(){
    showBasicInst();
    cout<<"\n\n";
    system("pause");
    preRegister();
    bool check=true;
    PhoneCall::setCallRate(2);
    cout<<"\n\n";
    displayMenu();

    while(check){
        printf("\n");
        //printf("%c%c",219,219);
        string option=chooseMenu();
        check=processMenu(option);
        printf("\n\n");
        }
        system("cls");
        printf("\n\t\tThank You for using C++ Phone !!\n\n");
}
void showBasicInst(){
    cout<<"\n** Please read the instructions carefully before running the software **\n"<<endl;
    cout<<"\n\t\t\t [ Basic Instructions ] "<<endl;
    cout<<"\n\t"<<"[1] : The Main Controller is the hub of this software. You can access various features using the Controller Options. \n"<<endl;
    cout<<"\t"<<"[2] : In choosing the Controller Options the syntax as displayed must be followed. Case sensitivity matters.\n"<<endl;
    cout<<"\t"<<"[3]: When accessing various Options you must follow a logical sequence. For more on good practices see the Documentation.\n"<<endl;
}

