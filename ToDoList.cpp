#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;
struct TODO
{
    string task;
    bool complete;
};
void save_task(vector<TODO>&todos)
{   
    fstream file("tasks.todo",ios::out);
    if (!file)
    {
        cout<<"Error Opening file for saving!!"<<endl;
        return;
    }
    for (int i = 0; i < todos.size(); i++)
    {
        file<<todos[i].complete<<"|"<<todos[i].task<<endl;
    }
    file.close();
}
void load_task(vector<TODO>&todos)
{
    fstream file("tasks.todo",ios::in);
    
    if (!file)
    {
        return;
    }
    string linee;
    while (getline(file,linee))
    {
        size_t sep=linee.find('|');
        if (sep==string::npos)
        {
            continue;
        }
        bool complete=stoi(linee.substr(0,sep));
        string task=linee.substr(sep+1);
        todos.push_back({task,complete});
    }
    file.close();

}
void view_task(vector<TODO>&todos)
{
    if (todos.empty())
    {
        cout<<endl<<"--------No Task Available--------"<<endl;
        return;
    }
    cout<<endl<<"--------TODO LIST--------"<<endl;
    
    for (int i = 0; i < todos.size(); i++)
    {   cout<<"Task "<<i+1<<":";
        if (todos[i].complete==true)
        {
            cout<<"[DONE]:";
        }
        else
        {
            cout<<"[    ]:";            
        }
        
        cout<<todos[i].task<<endl;
    }
}
void add_task(vector<TODO>&todos)
{   
    string task;
    cout<<"Enter Task::";
    getline(cin,task);
    todos.push_back({task,false});
    save_task(todos);
    cout<<endl<<"--------TASK ADDED--------"<<endl;
}
void task_complete(vector<TODO>&todos)
{
    if (todos.empty())
    {
        return;
    }
    view_task(todos);
    int num;
    cout<<endl<<"Enter Task Number to Complete:";
    cin>>num;
    if (num>=1 &&num<=todos.size())
    {
        todos[num-1].complete=true;
        save_task(todos);
        cout<<"----Task Completed----"<<endl;
    }
    else
    {
        cout<<"Invalid Task Number"<<endl;
    }
}
void task_delete(vector<TODO>&todos)
{
     if (todos.empty())
    {
        return;
    }
    view_task(todos);
    int num;
    cout<<endl<<"Enter Task Number to Delete:";
    cin>>num;
    if (num>=1 &&num<=todos.size())
    {
        todos.erase(todos.begin()+num-1);
        save_task(todos);
        cout<<"----Task Deleted----"<<endl;
    }
    else
    {
        cout<<"Invalid Task Number"<<endl;
    }
}



int main()
{
    vector<TODO> todolist;
    load_task(todolist);
    char a;
    while (true)
    {
        cout<<"========TODO APP========"<<endl;
        cout<<"1-View Task"<<endl;
        cout<<"2-Add Task"<<endl;
        cout<<"3-Complete Task"<<endl;
        cout<<"4-Delete Task"<<endl;
        cout<<"5-Exit"<<endl;
        cout<<"Enter Your Choice::";
        cin>>a;
        cin.get();
        switch (a)
        {
        case '1':
            view_task(todolist);
            break;
        case '2':
            add_task(todolist);
            break;
        case '3':
            task_complete(todolist);
            break;
        case '4':
            task_delete(todolist);
            break;
        case '5':
            cout<<"GoodBye"<<endl;
            return 0;
        default:
            cout<<"Invalid Choice"<<endl;
            break;
        }
    }
    
    return 0;
}