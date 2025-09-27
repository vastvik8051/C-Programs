#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class student
{
    int phy,che,mat;
    double percent = 0;
    string name;
    string rollno;
    vector<student>data;
    string rollSearch; // for searching

    string getName(){return name;}
    string getRoll(){return rollno;}


    public:

    student(string n, string r)
    {
        name = n;
        rollno = r;
    }

    student()
    {
        name = "";
        rollno = "";
    }

    void get_info()
    {
        cout<<"enter student roll number: ";
        cin.ignore();
        getline(cin, rollSearch);

        bool found = false;
        for(const student &b : data)
        {
            if(b.rollno == rollSearch)
            {
                get_result(); 
                found = true;
                break;
            }
        }
        if(!found)
        {
            cout<<"sudent not registered"<<endl;
        }
    }

    void get_marks()
    {
        cout<<"---- enter student marks ----\n";
        cout<<"maths: ";
        cin>>mat;
        cout<<"physics: ";
        cin>>phy;
        cout<<"chemistry: ";
        cin>>che;
    }

    void get_result()
    {
        calc();

        if(phy > 37 && che > 37 && mat > 37) //pass
        {
            cout<<"physics   : "<<phy<<"/100 PASS\n";
            cout<<"chemistry : "<<che<<"/100 PASS\n";
            cout<<"maths     : "<<mat<<"/100 PASS\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"class     : PASS\n";
        }

        else if(phy < 37 && che > 37 && mat > 37) //phy
        {
            cout<<"supplymentry\n";
            cout<<"physics   : "<<phy<<"/100 FAIL\n";
            cout<<"chemistry : "<<che<<"/100 PASS\n";
            cout<<"maths     : "<<mat<<"/100 PASS\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"clear backlog to pass\n";
        }

        else if(phy > 37 && che < 37 && mat > 37) //che
        {
            cout<<"physics   : "<<phy<<"/100 PASS\n";
            cout<<"chemistry : "<<che<<"/100 FAIL\n";
            cout<<"maths     : "<<mat<<"/100 PASS\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"clear backlog to pass\n";
        }
        
        else if(phy > 37 && che > 37 && mat < 37) // math
        {
            cout<<"physics   : "<<phy<<"/100 PASS\n";
            cout<<"chemistry : "<<che<<"/100 PASS\n";
            cout<<"maths     : "<<mat<<"/100 FAIL\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"clear backlog to pass\n";
        }

        else if(phy > 37 && che < 37 && mat < 37) //che math
        {
            cout<<"physics   : "<<phy<<"/100 PASS\n";
            cout<<"chemistry : "<<che<<"/100 FAIL\n";
            cout<<"maths     : "<<mat<<"/100 FAIL\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"FAIL\n";
        }

        else if(phy < 37 && che > 37 && mat < 37) // phy math
        {
            cout<<"physics   : "<<phy<<"/100 FAIL\n";
            cout<<"chemistry : "<<che<<"/100 PASS\n";
            cout<<"maths     : "<<mat<<"/100 FAIL\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"FAIL\n";
        }

        else if(phy < 37 && che < 37 && mat > 37) // phy che
        {
            cout<<"physics   : "<<phy<<"/100 FAIL\n";
            cout<<"chemistry : "<<che<<"/100 FAIL\n";
            cout<<"maths     : "<<mat<<"/100 PASS\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"FAIL\n";
        }

        else // all fail
        {
            cout<<"physics   : "<<phy<<"/100 FAIL\n";
            cout<<"chemistry : "<<che<<"/100 FAIL\n";
            cout<<"maths     : "<<mat<<"/100 FAIL\n";
            cout<<"percentage: "<<fixed<<setprecision(2)<<percent<<"%\n";
            cout<<"FAIL\n";
        }
    }

    void calc()
    {
        int total = phy + che + mat;
        percent = (double)total / 300 * 100;
    }

    void display()
    {
        cout<<"||-------------------------||"<<endl;
        cout<<"----- MENU -----\n";
        cout<<"1. view student result\n";
        cout<<"2. add new student\n";
        cout<<"3. search a student\n";
        cout<<"4. view all students\n";
        cout<<"5. exit\n";
    }

    void get_menu()
    {
        int num;
        while(true)
        {
            display();
            cout<<"||-------------------------||"<<endl;
            cout<<"enter your choice: ";
            cin>>num;
            
            switch(num)
            {
                case 1: case_one(); break; // done
                
                case 2: case_two(); break; // done
                
                case 3: case_three(); break; // done

                case 4: case_four(); break;  // 

                case 5: return; 
                
                default: cout<<"----- INVALID CHOICE -----\n"; break;
            }
        }
    }

    void case_one() // student result
    {
        get_info();
    }

    void case_two() // add student
    {
        string n, r;
        cout<<"enter first name and last name: ";
        cin.ignore();
        getline(cin, n);
        cout<<"assign a rollNumber to the student: ";
        getline(cin, r);
        student b1(n, r);
        data.push_back(b1);
        cout<<"||-------------------------||"<<endl;
        cout<<"student registered sucessfully ";
        cout<<"student name: "<<b1.getName()<<" | roll number: "<<b1.getRoll()<<endl;

        get_marks();
    }

    void case_three() // search a student
    {
        cout<<"enter student roll number: ";
        cin.ignore();
        getline(cin, rollSearch);
        
        bool found = false;
        for(const student& b : data)
        {
            if(b.rollno == rollSearch)
            {
                cout<<"||-------------------------||"<<endl;
                cout<<"student name: "<<b.name<<endl;
                cout<<"roll number : "<<rollSearch<<endl;
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout<<"student does not exist\n";
            cout<<"roll number: "<<rollSearch<<endl;
        }
    }

    void case_four() // view all student
    {
        int i = 1;
        for(const student& b : data)
        {
            cout<<i++
            <<".  Student name: "<<b.name
            <<" | Rollno: "<<b.rollno<<endl;
        }
    }

    void get_batch()
    {
        data.push_back(student("Sachin Tomar", "betn1ec22001"));
        data.push_back(student("Rahul Yadav", "betn1ec22002"));
        data.push_back(student("Vaishnavi Tirpathi", "betn1ec22003"));
        data.push_back(student("Priya Patel", "betn1ec22004"));
        data.push_back(student("Amit Kumar", "betn1ec22005"));
        data.push_back(student("Neha Joshi", "betn1ec22006"));
        data.push_back(student("Javed Qurashi", "betn1ec22007"));
        data.push_back(student("Sneha Sharma", "betn1ec22008"));
        data.push_back(student("Vastvik Sharma", "betn1ec22009"));
        data.push_back(student("Karan Verma", "betn1ec22010"));
        data.push_back(student("Vikas Singh", "betn1ec22011"));
        data.push_back(student("Pooja Kumari", "betn1ec22012"));
        data.push_back(student("Manoj Jain", "betn1ec22013"));
        data.push_back(student("Komal Soni", "betn1ec22014"));
        data.push_back(student("Alok Dwivedi", "betn1ec22015"));
        data.push_back(student("Ritu Singh", "betn1ec22016"));
        data.push_back(student("Ankit Tiwari", "betn1ec22017"));
        data.push_back(student("Shruti Mishra", "betn1ec22018"));
        data.push_back(student("Nikhil Kumar", "betn1ec22019"));
        data.push_back(student("Kavita Rao", "betn1ec22020"));
    }
};

int main()
{
    student s1;
    s1.get_batch();
    s1.get_menu();
    return 0;
}