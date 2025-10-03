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

    student(string n, string r, int p = 0, int c = 0, int m = 0)
    {
        name = n;
        rollno = r;
        phy = p;
        che = c;
        mat = m;
    }

    student()
    {
        name = "";
        rollno = "";
        phy = 0;
        che = 0;
        mat = 0;
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
                get_result(b);
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
        int p, c, m;
        cout<<"---- enter student marks ----\n";
        cout<<"maths: ";
        cin>>m;
        cout<<"physics: ";
        cin>>p;
        cout<<"chemistry: ";
        cin>>c;
    }

    void get_result(const student& b)
    {
        int total = b.phy + b.che + b.mat;
        double percent = (double) total / 300 * 100;
        
        if (b.phy >= 37 && b.che >= 37 && b.mat >= 37)
        {
            cout << "physics   : " << b.phy << "/100 PASS\n";
            cout << "chemistry : " << b.che << "/100 PASS\n";
            cout << "maths     : " << b.mat << "/100 PASS\n";
            cout << "percentage: " << fixed << setprecision(2) << percent << "%\n";
            cout << "class     : PASS\n";
        }
        
        else
        {
            cout << "physics   : " << b.phy << "/100 " << (b.phy >= 37 ? "PASS" : "FAIL") << "\n";
            cout << "chemistry : " << b.che << "/100 " << (b.che >= 37 ? "PASS" : "FAIL") << "\n";
            cout << "maths     : " << b.mat << "/100 " << (b.mat >= 37 ? "PASS" : "FAIL") << "\n";
            cout << "percentage: " << fixed << setprecision(2) << percent << "%\n";
            cout << "class     : FAIL\n";
        }

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
        int p, c, m;
        cout<<"enter first name and last name: ";
        cin.ignore();
        getline(cin, n);
        cout<<"assign a rollNumber to the student: ";
        getline(cin, r);

        cout<<"---- enter student marks ----\n";
        cout<<"maths: ";
        cin>>m;
        cout<<"physics: ";
        cin>>p;
        cout<<"chemistry: ";
        cin>>c;
        
        student b1(n, r, p, c, m);
        data.push_back(b1);
        cout<<"||-------------------------||"<<endl;
        cout<<"student registered sucessfully ";
        cout<<"student name: "<<b1.getName()<<" | roll number: "<<b1.getRoll()<<endl;

        //get_marks();
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
        data.push_back(student("Sachin Tomar", "betn1ec22001", 78, 82, 91));
        data.push_back(student("Rahul Yadav", "betn1ec22002", 65, 74, 59));
        data.push_back(student("Vaishnavi Tirpathi", "betn1ec22003", 88, 79, 84));
        data.push_back(student("Priya Patel", "betn1ec22004", 92, 85, 77));
        data.push_back(student("Amit Kumar", "betn1ec22005", 55, 61, 49));
        data.push_back(student("Neha Joshi", "betn1ec22006", 83, 72, 68));
        data.push_back(student("Javed Qurashi", "betn1ec22007", 40, 36, 58)); // FAIL in Chem
        data.push_back(student("Sneha Sharma", "betn1ec22008", 95, 89, 93));
        data.push_back(student("Vastvik Sharma", "betn1ec22009", 72, 64, 80));
        data.push_back(student("Karan Verma", "betn1ec22010", 49, 52, 47));
        data.push_back(student("Vikas Singh", "betn1ec22011", 77, 84, 69));
        data.push_back(student("Pooja Kumari", "betn1ec22012", 91, 88, 85));
        data.push_back(student("Manoj Jain", "betn1ec22013", 66, 70, 74));
        data.push_back(student("Komal Soni", "betn1ec22014", 58, 42, 61)); // FAIL in Chem
        data.push_back(student("Alok Dwivedi", "betn1ec22015", 87, 90, 83));
        data.push_back(student("Ritu Singh", "betn1ec22016", 39, 45, 55)); // FAIL in Phy
        data.push_back(student("Ankit Tiwari", "betn1ec22017", 73, 68, 70));
        data.push_back(student("Shruti Mishra", "betn1ec22018", 82, 79, 88));
        data.push_back(student("Nikhil Kumar", "betn1ec22019", 60, 54, 49));
        data.push_back(student("Kavita Rao", "betn1ec22020", 93, 95, 97));
        data.push_back(student("Deepak Mehra", "betn1ec22021", 95, 23, 88)); // FAIL in Chem
        data.push_back(student("Aarav Singh", "betn1ec22022", 28, 31, 45)); // FAIL in Phy + Chem
        data.push_back(student("Meera Nair", "betn1ec22023", 100, 100, 100)); // Topper
        data.push_back(student("Ishaan Gupta", "betn1ec22024", 20, 15, 10)); // FAIL in all 3
        data.push_back(student("Rohan Das", "betn1ec22025", 76, 82, 35)); // FAIL in Math
        data.push_back(student("Simran Kaur", "betn1ec22026", 36, 20, 50)); // FAIL in Phy + Chem
        data.push_back(student("Arjun Sharma", "betn1ec22027", 65, 38, 39)); // FAIL in Math + Chem
        data.push_back(student("Divya Agarwal", "betn1ec22028", 90, 45, 37)); // FAIL in Math
        data.push_back(student("Kabir Khan", "betn1ec22029", 25, 28, 22)); // FAIL all 3
        data.push_back(student("Ananya Pandey", "betn1ec22030", 70, 71, 69));


    }
};

int main()
{
    student s1;
    s1.get_batch();
    s1.get_menu();
    return 0;
}