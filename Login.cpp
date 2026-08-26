#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class temp{
    string user_name,email,password;
    string search_name,search_password,search_email;
    fstream file;
    public:
    void login();
    void signup();
    void forgot_password();
}obj;
void temp ::login()
{   bool login=false;
    
    cout<<"--------Login--------"<<endl;
    cout<<"Enter Your User Name:";
    getline(cin,search_name);
    cout<<"Enter Your Password:";
    getline(cin,search_password);
    file.open("login_Data.txt",ios ::in);
    getline(file,user_name,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while (!file.eof())
    {
        if (user_name==search_name && password == search_password)
        {
            cout<<"--------Account Login Successful--------"<<endl;
            cout<<"Username:"<<user_name<<endl;
            cout<<"Email:"<<email<<endl;
            login=true;
        }
        getline(file,user_name,'*');
        getline(file,email,'*');
        getline(file,password,'\n');
    }
    file.close();
    if (login==false)
    {
        cout<<"--------Login Unsuccessful--------"<<endl;
        cout<<"Username and Password are incorrect"<<endl;
    }
}
void temp ::signup()
{
    cout<<"--------Signup--------"<<endl;
    cout<<"Enter Your User Name:";
    getline(cin,user_name);
    cout<<"Enter Your Email:";
    getline(cin,email);
    cout<<"Enter Your Password:";
    getline(cin,password);
    file.open("login_Data.txt",ios ::out | ios ::app);
    file<<user_name<<"*"<<email<<"*"<<password<<endl;
    file.close(); 
}
void temp ::forgot_password()
{   bool acc=false;
    cout<<"--------Forgot_Password--------"<<endl;
    cout<<"Enter Your User Name:";
    getline(cin,search_name);
    cout<<"Enter Your Email:";
    getline(cin,search_email);
    file.open("login_Data.txt",ios ::in);
    getline(file,user_name,'*');
    getline(file,email,'*');
    getline(file,password,'\n');
    while (!file.eof())
    {   
        if (user_name==search_name && email == search_email)
        {
            cout<<"--------Account_Found_Successful--------"<<endl;
            cout<<"Username:"<<user_name<<endl;
            cout<<"Email:"<<email<<endl;
            cout<<"Your Password:"<<password;
            acc=true;
        }
        getline(file,user_name,'*');
        getline(file,email,'*');
        getline(file,password,'\n');
    }
    file.close();
    if (acc==false)
    {
        cout<<"--------Account Not Found--------"<<endl; 
    }
}
int main()
{
    char choice;
    cout<<"\n 1-Login";
    cout<<"\n 2-Signup";
    cout<<"\n 3-Forgot Password";
    cout<<"\n 4-Exit";
    cout<<"\n Enter Your Choice::";
    cin>>choice;
    cin.get();
    switch (choice)
    {
    case '1':
        obj.login();
        break;
    case '2':
        obj.signup();
        break;
    case '3':
        obj.forgot_password();
        break;
    case '4':
        cout<<"Thanks For Using"<<endl;
        break;
    default:
        cout<<"Invalid Choice"<<endl;
        break;
    }

}