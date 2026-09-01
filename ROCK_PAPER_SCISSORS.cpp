#include<iostream>
#include <ctime>
#include<cstdlib>
using namespace std;
void display_choice(int val)
{
    switch (val)
    {
    case 1:
        cout<<"ROCK"<<endl;
        break;
    case 2:
        cout<<"PAPER"<<endl;
        break;
    case 3:
        cout<<"Scissors"<<endl;
        break;
    case 4:
        cout<<"GoodBye"<<endl;
        break;
    default:
        cout<<"Invalid Choice"<<endl;
    }
    return ;
}
int getuserchoice()
{   
    int user_choice;    
    cout<<"1.ROCK"<<endl;
    cout<<"2.Paper"<<endl;
    cout<<"3.Scissors"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter Your Choice:";
    cin>>user_choice;
    cout<<"YOUR CHOICE:";
    display_choice(user_choice);
    return user_choice;
    
}
int getcomputerchoice()
{   
    int computer_choice;
    computer_choice=rand()%3+1;
    cout<<"Computer Choice:";
    display_choice(computer_choice);
    return computer_choice;
}
void result(int user_choice,int computer_choice,int &User_Score,int &Computer_Score,int &Draw)
{
    if (user_choice==computer_choice)
        {
            cout<<"\n****Its a DRAW!!****\n";
            Draw++;
        }
        else if ((user_choice==1 && computer_choice==3) || (user_choice==2 && computer_choice==1) || (user_choice==3 && computer_choice==2))
        {
            cout<<"\n****You Win!!****\n";
            User_Score++;
        }
        else
        {
            cout<<"\n****Computer Win!!****\n";
            Computer_Score++;
        }
}
int main()
{   int user_choice,computer_choice;
    int User_Score=0,Computer_Score=0,Draw=0;
    srand(time(0));
    while (true)
    {
        cout<<"\n==================ROCK PAPER SCISSOR=================="<<endl;
        cout<<"USER SCORE:"<<User_Score<<"          Computer Score:"<<Computer_Score<<"         Draw:"<<Draw<<endl;
        user_choice=getuserchoice();
        if (user_choice==4)
        {
            return 0;
        }
        if (user_choice<1 ||user_choice>3)
        {
            continue;
        }
        computer_choice=getcomputerchoice();
        result(user_choice,computer_choice,User_Score,Computer_Score,Draw);
        
    }
    return 0;
}