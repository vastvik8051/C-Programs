#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


class library
{
    string username;
    int menu; // for switch
    string title;  // for books
    string author; // for books
    bool available;
    vector<library>book;
    string getTitle(){return title;}                  // for fetching
    string getAuthor(){return author;}               // defining as i go on
    string searchTitle; // for searching books
    string searchAuthor; // for searching author

    public:

    library(string t, string a)   // constructor
    {
        title = t;
        author = a;
        available = true;
    }

    library()        // default constructor
    {
        title = "";
        author = "";
        available = true;
    }
    
    void get_info()
    {
        cout<<"Enter your full name : ";
        getline(cin, username);
    }

    void display()
    {
        cout<<"----- MENU -----"<<endl;
        cout<<"1. Add book to the Library"<<endl;  //done
        cout<<"2. Search book by Title"<<endl;   // done
        cout<<"3. Search book by Author"<<endl; // done
        cout<<"4. Borrow Book"<<endl;
        cout<<"5. Return Book"<<endl;
        cout<<"6. See All listed Book"<<endl;  // done
        cout<<"7. Exit Library"<<endl;  // done
    }

    void get_menu()
    {
        while(true)
        {
            display();
            cout<<"Enter Choice : ";
            cin>>menu;
            
            switch(menu)
            {
                case 1: case_one(); break;
                case 2: case_two(); break;
                case 3: case_three(); break;
                case 4: case_four(); break;
                case 5: case_five(); break;
                case 6: case_six(); break;
                case 7: return;
                default: cout<<"----- INVALID MENU -----"<<endl;
            }
        }
    }

    void case_one() // add books
    {
        string t, a;
        cout<<"Enter the Book Title : ";
        cin.ignore();
        getline(cin, t);
        cout<<"Enter the Author name : ";
        getline(cin, a);
        library b1(t, a);
        book.push_back(b1);
        cout<<"New book added to the Library"<<endl;
        cout<<"Title  : "<<b1.getTitle()<<endl;
        cout<<"Author : "<<b1.getAuthor()<<endl;
        cout<<"Thankyou "<<username <<" for your contribution to the Library"<<endl;
    }

    void case_two()  // search by title
    {
        cout<<"Enter Book Title : ";
        cin.ignore();
        getline(cin, searchTitle);

        bool found;

        for(const library& b : book)
        {
            if(b.title == searchTitle)
            {
                cout<<"book found"<<endl;
                cout<<"Title : "<<searchTitle
                    <<" | Author : "<<b.author
                    <<" | Available : "<<(b.available ? "Yes" : "No")<<endl;
                found = true;
                break;
            }
            
            else
            {
                cout<<"Book not found"<<endl;
                cout<<"Title : "<<searchTitle<<endl;
                found = false;
                break;
            }
        }
    }

    void case_three() // search by author
    {
        cout<<"Enter Authors Name : ";
        cin.ignore();
        getline(cin, searchAuthor);
        
        bool found;
        
        for(const library& b : book)
        {
            if(b.author == searchAuthor)
            {
                cout<<"book found"<<endl;
                cout<<"Title : "<<b.title
                    <<" | Author : "<<searchAuthor
                    <<" | Available : "<<(b.available ? "Yes" : "No")<<endl;
                found = true;
                break;
            }
            
            else
            {
                cout<<"Book not found"<<endl;
                cout<<"Author : "<<searchAuthor<<endl;
                found = false;
                break;
            }
        }
    }

    void case_four() //borrow 
    {
        cout<<"Enter book name : ";
        cin.ignore();
        getline(cin, searchTitle);
        
        for(library& b : book)
        {
            if(b.title == searchTitle)
            {
                if(b.available)
                {
                    int num;
                    
                    cout<<"To borrow Enter : 1"<<endl;
                    cout<<"GoTo MENU - Enter : 2"<<endl;
                    cin>>num;
                    
                    switch(num)
                    {
                        case 1: cout<<"The book: "<<b.title
                                    <<" | Author: "<<b.author<<endl;
                                    cout<<"Borrowed by: "<<username<<endl;
                                    b.available = false;
                                    break;
                        
                        case 2: exit(0);

                        default: cout<<"---- INVALID Entry ----"<<endl; break;
                    }
                }

                else
                {
                    cout<<"Book has already been borrowed"<<endl;
                    break;
                }
            }

            else
            {
                cout<<"Book not available in the Library"<<endl; break;
            }
        }

    }

    void case_five() // return 
    {
        cout<<"Enter book name : ";
        cin.ignore();
        getline(cin, searchTitle);
        
        for(library& b : book)
        {
            if(b.title == searchTitle)
            {
                if(!b.available)
                {
                    cout<<"The book: "<<b.title<<" | Author: "<<b.author<<endl;
                    cout<<"Returned by: "<<username<<endl;
                    b.available = true;
                    break;
                }
            }
        }
    }

    void case_six()  // all books
    {
        int i = 1;
        for(const library& b : book)
        {
            cout<<i++
            <<". Title : "<<b.title
            <<" | Author : "<<b.author
            <<" | Available : "<<(b.available ? "Yes" : "No")<<endl;
        }
    }

    void get_books() 
    {
        // C++
        book.push_back(library("C++ Primer", "Stanley Lippman"));
        book.push_back(library("Effective C++", "Scott Meyers"));
        book.push_back(library("The C++ Programming Language", "Bjarne Stroustrup"));
        book.push_back(library("Accelerated C++", "Andrew Koenig"));
        book.push_back(library("More Effective C++", "Scott Meyers"));
        book.push_back(library("C++ Concurrency in Action", "Anthony Williams"));
        book.push_back(library("Modern C++ Design", "Andrei Alexandrescu"));
        book.push_back(library("Programming Principles in C++", "Bjarne Stroustrup"));
        book.push_back(library("Effective Modern C++", "Scott Meyers"));
        book.push_back(library("C++ Templates", "David Vandevoorde"));
        
        // Java
        book.push_back(library("Effective Java", "Joshua Bloch"));
        book.push_back(library("Java: The Complete Reference", "Herbert Schildt"));
        book.push_back(library("Head First Java", "Kathy Sierra"));
        book.push_back(library("Core Java Volume I", "Cay Horstmann"));
        book.push_back(library("Java Performance", "Scott Oaks"));
        book.push_back(library("Java Concurrency in Practice", "Brian Goetz"));
        book.push_back(library("Spring in Action", "Craig Walls"));
        book.push_back(library("Beginning Programming with Java", "Barry Burd"));
        book.push_back(library("Think Java", "Allen Downey"));
        book.push_back(library("Java Puzzlers", "Joshua Bloch"));
        
        // Python
        book.push_back(library("Learning Python", "Mark Lutz"));
        book.push_back(library("Python Crash Course", "Eric Matthes"));
        book.push_back(library("Fluent Python", "Luciano Ramalho"));
        book.push_back(library("Automate the Boring Stuff with Python", "Al Sweigart"));
        book.push_back(library("Effective Python", "Brett Slatkin"));
        book.push_back(library("Python Cookbook", "David Beazley"));
        book.push_back(library("Head First Python", "Paul Barry"));
        book.push_back(library("Think Python", "Allen Downey"));
        book.push_back(library("Python Tricks", "Dan Bader"));
        book.push_back(library("Programming Python", "Mark Lutz"));
        
        // jS
        book.push_back(library("Eloquent JavaScript", "Marijn Haverbeke"));
        book.push_back(library("You Don’t Know JS", "Kyle Simpson"));
        book.push_back(library("JavaScript: The Good Parts", "Douglas Crockford"));
        book.push_back(library("Head First JavaScript Programming", "Eric Freeman"));
        book.push_back(library("JavaScript: The Definitive Guide", "David Flanagan"));
        book.push_back(library("Learning JavaScript Design Patterns", "Addy Osmani"));
        book.push_back(library("Speaking JavaScript", "Axel Rauschmayer"));
        book.push_back(library("Secrets of the JavaScript Ninja", "John Resig"));
        book.push_back(library("Functional-Light JavaScript", "Kyle Simpson"));
        book.push_back(library("Professional JavaScript for Web Developers", "Nicholas Zakas"));
        
        // C
        book.push_back(library("The C Programming Language", "Kernighan & Ritchie"));
        book.push_back(library("C Programming Absolute Beginner’s Guide", "Greg Perry"));
        book.push_back(library("Expert C Programming", "Peter van der Linden"));
        book.push_back(library("Head First C", "David Griffiths"));
        book.push_back(library("C in Depth", "Deepali Srivastava"));
        book.push_back(library("Modern C", "Jens Gustedt"));
        book.push_back(library("C Programming: A Modern Approach", "K. N. King"));
        book.push_back(library("Let Us C", "Yashavant Kanetkar"));
        book.push_back(library("Practical C Programming", "Steve Oualline"));
        book.push_back(library("Advanced C Programming", "Peter van der Linden"));
    }
};


int main()
{
    library s1;
    s1.get_info();
    s1.get_books();
    s1.get_menu();
    return 0;
}