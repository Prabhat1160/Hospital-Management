#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;
class hospital
{ 
    private:
    string Name,Address,Bgroup;
    public:
    // hospital():name(""),address(""),bgroup("")
    // {

    // }
    void setName(string name)
    {
        Name=name;
    }
   void setAddress(string address)
    {
       Address=address;
    }
    void setBgroup(string group)
    {
        Bgroup=group;
    }
    
string getName()
{
    return Name;
}

string getAddress()
{
    return Address;
}
string getBgroup()
{
    return Bgroup;
}
};

admit(hospital patient)
{
    system("cls");
    string name,address,group;
    cout<<"\tEnter name of Patient"<<endl;
    cin>>name;
    patient.setName(name);
    cout<<"\tEnter address of Patient"<<endl;
    cin>>address;
    patient.setAddress(address);
    cout<<"\tEnter Blood Group of Patient"<<endl;
    cin>>group;
    patient.setBgroup(group);
    ofstream outfile("hos.txt",ios::app);
    if(!outfile)
    {
        cout<<"\tError:File can't Open"<<endl;

    }
    else
    {   outfile<<"\t"<<"Name"<<" : "<<"Address"<<":"<<"Blood Group"<<endl;
        outfile<<"\t"<<patient.getName()<<" : "<<patient.getAddress()<<":"<<patient.getBgroup()<<endl;
        cout<<"\tPatient Admitted!"<<endl;
    }

    outfile.close();
    Sleep(5000);
}

discharge()
{  system("cls");
    string name;
    cout<<"\tEnter name of Patient"<<endl;
    cin>>name;
    ifstream infile("hos.txt");
    ofstream outfile("temp.txt");
    if(!infile || !outfile)
    {
        cout<<"\tError: File can't open"<<endl;

    }
    else
    {
        string line;
        bool found=false;
        while(getline(infile,line)) 
    {   
        stringstream ss;
        ss<<line;
        string patientname;
        ss>>patientname;
        if(name==patientname)
        {
            found=true;
            cout<<"\tPatient Discharged!"<<endl;
        }
        else
        {
            outfile<<line<<endl;
        }

    }
    if(!found)
    {
        cout<<"\tIncorrect Name!"<<endl;
    }
    
    
    }
    outfile.close();
    infile.close();
    remove("hos.txt");
    rename("temp.txt","hos.txt");
    Sleep(3000);
}


int main()
{
    hospital patient;
    bool exit=false;
    while(!exit)
    {
        system("cls");
        int val;
        cout<<"\tHOSPITAL MANAGEMENT SYSTEM"<<endl;
        cout<<"\t**************************"<<endl;
        cout<<"\t1.Admit Patient."<<endl;
        cout<<"\t2.Discharge Patient."<<endl;
        cout<<"\t3.Exit"<<endl;
        cout<<"\tEnter Choice"<<endl;
        cin>>val;
        if(val==1)
        {
            admit(patient);
        }
        else if(val==2)
        {
            discharge();
        }
        Sleep(5000);
    }
}