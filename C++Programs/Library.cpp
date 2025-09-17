#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


class library
{
    string name; // user name                                 books to be added - 50
    int id; // unique id                                10 jave, 10 js, 10 py, 10 C, 10 C++
    string title; // library book                                 note for self
    string bookname;  //submit
    string bookauthor;  //submit
    string author; // library book author
    bool available = true;
    bool borrowed = false;
    vector<library> books;

    public:

    void get_info()
    {
        cout<<"Enter your full name : ";
        cin>>name;
    }

    void get_menu()
    {
        int menu;
        while(true)
        
        {
            cout<<"----- MENU -----"<<endl;
            cout<<"1. Add book to the Library"<<endl;
            cout<<"2. Search book by Title"<<endl;
            cout<<"3. Search book by Author"<<endl;
            cout<<"4. Search book by name"<<endl;
            cout<<"5. Search book by Category"<<endl;
            cout<<"6. Exit Library"<<endl;

            cout<<"Choose Menu : ";
            cin>>menu;
            switch(menu)
            
            {
                case 1: 
                cout<<"Enter the name of the Book : ";
                cin>>bookname;
                cout<<"Enter the name of the Author : ";
                cin>>bookauthor;
                cout<<"Thankyou for Registring a book in the Library"<<endl;
                break;
                
                case 2: break;
                
                case 3: break;
                
                case 4: break;
                
                case 5: break;
                
                case 6: cout<<"------ PROGRAM TERMINATED ------"<<endl;
                return;
                
                default: cout<<"----- INVALID MENU-----"<<endl; break;
            }
        }
        
    }
};

int main()
{
    library s1;
    s1.get_info();
    s1.get_menu();
    return 0;
}