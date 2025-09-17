#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class login
{
    int id = 22554;
    string pass = "vastvik@1234";
    int bal = 10000;
    vector<string> history;

    public:

    void get_info()
    {
        cout<< "Enter Account ID : ";  //22554
        cin>>id;
        if(id != 22554)
        
        {
            cout<<"--------------------------------"<<endl;
            cout<<"Invalid ID"<<endl;
            exit(0);
        }
        
        else
        
        {
            cout<<"--------------------------------"<<endl;
            cout<<"Account Name   : Vastvik Sharma\n";
            
            int attempts = 3;
            while(attempts > 0)
            
            {
                cout<<"Enter Password : "; //     vastvik@1234
                cin>>pass;
                
                {
                    if(pass == "vastvik@1234")
                    
                    {
                        display(); 
                        break;
                    }
                    
                    else
                    
                    {
                        
                        {
                            attempts--;
                            if(attempts > 0)
                            
                            {
                                cout<<"--------------------------------"<<endl;
                                cout<<"Invalid Password"<<endl;
                                cout<<"Attempts Left : "<<attempts<<endl;
                                cout<<"--------------------------------"<<endl;
                            }
                            
                            else
                            
                            {
                                cout<<"--------------------------------"<<endl;
                                cout<<"Too many Failed Attempts"<<endl;
                                cout<<"Accounts Locked for 24 Hours"<<endl;
                                cout<<"--------------------------------"<<endl;
                                exit (0);
                            }
                        }    
                    }
                }
            }
        }

    }

    void display()
    {
        cout<<"--------------------------------"<<endl;
        cout<<"Account Name    : Vastvik Sharma"<<endl;
        cout<<"Account ID      : "<<id<<endl;
    }

    void get_menu()
    {
        int menu;
        while(true)
        {
            cout<<"--------------------------------"<<endl;
            cout<<"------- MENU -------"<<endl;
            cout<<"1. Check Balance"<<endl;
            cout<<"2. Deposit Money"<<endl;
            cout<<"3. Withdrawal Money"<<endl;
            cout<<"4. Check Transaction History"<<endl;
            cout<<"5. Close Program"<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"Enter Choice : ";
            cin>>menu;
            
            switch(menu)
            
            {
                case 1:
                cout<<"--------------------------------"<<endl; 
                cout<<"Your Account Balance : "<<bal<<" $"<<endl; break;
                
                case 2: int deposite;
                cout<<"--------------------------------"<<endl;
                cout<<"Enter Deposit Ammount : ";
                cin>>deposite;
                bal += deposite;
                history.push_back("Deposited : " + to_string(deposite) +" $");
                cout<<"--------------------------------"<<endl;
                cout<<"Balance after Deposite : "<<bal<<" $"<<endl; break;
                
                case 3: 
                int withdrawl;
                cout<<"--------------------------------"<<endl;
                cout<<"Enter withdrawal Ammount : ";
                cin>>withdrawl;
                
                if(withdrawl > bal)
                
                {
                    cout<<"--------------------------------"<<endl;
                    cout<<"Insufficent Balance"<<endl;
                }
                
                else
                
                {
                    bal -= withdrawl;
                    history.push_back("Withdrawn : " + to_string(withdrawl) + " $");
                    cout<<"--------------------------------"<<endl;
                    cout<<"Balance after Withdrawal : "<<bal<<" $"<<endl;
                }
                break;
                
                case 4: 
                cout<<"--------------------------------"<<endl;
                cout<<"------ History ------\n";
                
                if(history.empty())
                
                {
                    cout<<"No Transaction Yet"<<endl;
                }
                
                else
                
                {
                    for(string h : history)
                    cout<<h<<endl;
                }
                break;
                
                case 5: cout<<("---- Program Terminated ----"); 
                return;
                
                default: cout<<("---- Invalid Menu ----")<<endl; break;
            }
        }
    }
};

int main()
{
    login  s1;
    s1.get_info();
    s1.get_menu();
    return 0;
}