// Example program
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class accountOperations
{
    public:
    void login (); //Connecter a un compte dans la banque
    void showAccount(); //Show detail about the account last transaction (within the last 2 weeks)
    void transfertMoney(); //Transfert from one account to another in the same banks and update both accounts
    void Deposite(); //Put the money in the account
    void withdrawal(); //Make a payement at the store
    void logOut();
    accountOperations(); //Constructor
    ~accountOperations(); //Destructor
};



int main()
{
    cout <<"Hello"<<endl;
   string pass ="";
   char ch;
   cout << "Enter pass\n";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout <<"Hello"<<endl;
    return 0;
}
