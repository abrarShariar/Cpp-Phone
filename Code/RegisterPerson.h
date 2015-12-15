/*
    This File contains The class RegisterPerson
    Read and write names of registered person into a .txt file using <map>
*/
#include<map>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class RegisterPerson{
    public:
        static void setRegisterNumber();
        static map<int,string> personMap;
        static int totalRegistered;
        static void setRegisterPerson(string name);
        static void writeRegisterPerson();
        static map<int,string> readRegisterPerson();
};


int RegisterPerson::totalRegistered=0;
map<int,string> RegisterPerson::personMap;

void RegisterPerson::setRegisterPerson(string name){
    personMap[totalRegistered]=name;
    totalRegistered++;
}
void RegisterPerson::writeRegisterPerson(){
        ofstream write;
        write.open("Person/Registered_Person.txt");
        for(auto it=personMap.begin();it!=personMap.end();it++){
            write<<it->first<<" : "<<it->second<<endl;
        }
        write.close();
    }

map<int,string> RegisterPerson::readRegisterPerson(){
        map<int,string> readMap;
        ifstream read;
        stringstream ss;
        int index;
        string name,num;
        string temp;

        read.open("Person/Registered_Person.txt");
        while(getline(read,temp))
        {
            int found=temp.find_first_of(":");
            num=temp.substr(0,found);
            name=temp.substr(found+2,temp.length()-1);
            ss<<num;
            ss>>index;
            readMap[index]=name;
        }
        read.close();
        return readMap;
}

//-------------------------------------------------

