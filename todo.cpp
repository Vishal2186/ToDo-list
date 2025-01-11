#include<iostream>
#include<string>
#include<list>
#include<ctime>
using namespace std;

class ToDoItem
{
private:
    int id;
    string description;
    bool completed;

public:
    ToDoItem(): id(0), description(""),completed(false) {}
    ~ToDoItem() = default;

    bool create(string new_description)
    {
        id = rand() % 100 +1;
        description = new_description;
        return true;
    }

    int getId(){ return id;}
    string getDescription(){ return description;}
    bool isCompleted(){ return completed;}

    void setCompleted(bool val){ completed = val;}
};


int main(){
    char inpute_option;
    int inpute_id;
    string input_description;
    string version = "v0.20";
    list <ToDoItem> todoItem;
    list <ToDoItem> ::iterator it;

    srand(time(NULL));

    todoItem.clear();

    // ToDoItem test;
    // test.create("this is a test");
    // todoItem.push_back(test);

    while (1)
    {
        system("clear");
        cout<<"\t\tToDo List Maker -- "<<version<<endl;
        cout<<endl;cout<<endl;

        for(it = todoItem.begin(); it != todoItem.end(); it++)
        {
            string completed = it->isCompleted() ? "done" : "not done";
            cout<< it->getId() << "  |  " << it->getDescription() << "  |  " << completed << endl;
        }
        if(todoItem.empty()){cout<<"Add your first ToDo!"<<endl;}
        cout<<endl;
        cout<<"[a]dd a new ToDo"<<endl;
        cout<<"[c]omplete a ToDo"<<endl;
        cout<<"[q]uite"<<endl;
        cout<<"choice: ";
        cin>>inpute_option;
        if(inpute_option == 'q'){cout<<"Have a great day";break;}
        else if(inpute_option == 'a')
        {
            cout<<"Add a new description: ";
            cin.clear();
            cin.ignore();
            getline(cin, input_description);
            ToDoItem newItem;
            newItem.create(input_description);
            todoItem.push_back(newItem);
        }
        else if(inpute_option == 'c')
        {
            cout<<"Enter id to mark completed"<<endl;
            cin>>inpute_id;

            for(it = todoItem.begin(); it != todoItem.end(); it++)
            {
                if(inpute_id == it->getId()){it->setCompleted(true);break;}
            }
        }
        
    }
    
    return 0;
}