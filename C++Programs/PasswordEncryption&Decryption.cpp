#include <iostream>
#include <string>
#include <vector>
using namespace std;

class password
{
    string userID;
    string pass;
    string encPass;
    string encData[55] = {"1","!","2","@","3","#","4","$","5","%","6","^","7","&","8","*","9","(",")","0","-","_","=","+","~","<",">","?","/","|","t","u","i","d","f","g","q","d","v","h","j","t","x","d","f","g","l","q","z","x","c","n","+","G","H"};
    string decData[55] = {"q","w","e","r","t","y","u","i","o","p","a","s","d","f","g","h","j","k","l","z","x","c","v","b","n","m","Q","W","E","R","T","Y","U","I","O","P","A","S","D","F","G","H","J","K","L","Z","X","C","V","B","N","M","@","-","_"};
    vector<password>store;
    const int MAX_size = sizeof(encData) / sizeof(encData[0]); // sizeSafeGuard

    public:

    void get_input()
    {
        cout<<("enter userID: ");
        getline(cin, userID);
        cout<<("input password: ");
        getline(cin, pass);
    }

    void process()
    {
        cout<<"-----------------------------------------------------------\n";
        cout<<"orignal pass: "<<pass<<endl;
        cout<<"encrypted pass: "<<encPass<<endl;
    }

    void encryption()
    {
        encPass.clear(); // remove garbage

        for(char ch : pass) // for searching 
        {
            bool found = false;
            for(int i = 0; i < MAX_size; i++)
            {
                if(decData[i][0] == ch)
                {
                    encPass += encData[i]; // switchLetters
                    found = true;
                    break;
                }
            }

            if(!found)
            {
                encPass += ch; // keep og
            }
        }
    }

    void run()
    {
        get_input();
        encryption();
        process();
    }
};

int main()
{
    password s1;
    s1.run();
    return 0;
}