// Example program
#include <iostream>
#include <string>
#include <conio.h>
#include <map>
using namespace std;

class accountOperations
{
private:
    map<string, string> userList;
public:
    void signUp(); //
    void logIn(); //Connecter a un compte dans la banque
    void hidePassword(string&);//
    void showAccount(); //Show detail about the account last transaction (within the last 2 weeks)
    void transfertMoney(); //Transfert from one account to another in the same banks and update both accounts
    void Deposite(); //Put the money in the account
    void withdrawal(); //Make a payement at the store
    void logOut();
    accountOperations(); //Constructor
    ~accountOperations(); //Destructor
};

accountOperations::accountOperations()
{

} //Constructor
accountOperations::~accountOperations()
{

} //Destructor
void accountOperations::signUp()
{
    string userName;
    string passWord;
    string confirmPw;
    map<string,string>::iterator it = userList.begin();
   cout<<"Entre votre nom d'utilisateur et mot de passe"<<endl;
   cout<<"Username: ";
   cin>>userName;
   cout<<"Password: ";
   hidePassword(passWord);
   cout<<"confirm Password: ";
   hidePassword(confirmPw);
   while(passWord != confirmPw)
   {
    cout<<"Password don't match"<<endl;
    cout<<"Password: "<<endl;
    hidePassword(passWord);
    cout<<"confirm Password: "<<endl;
    hidePassword(confirmPw);
   }
   userList.insert(it, pair<string,string>(userName,passWord));
   cout<<"Welcome "<<userName<<endl;
}


void accountOperations::logIn()
{
    string userName;
    string passWord;
    int count = 0;
   cout<<"Entre votre nom d'utilisateur et mot de passe"<<endl;
   cout<<"Username: ";
   cin>>userName;
   cout<<"Password: ";
   hidePassword(passWord);
   map<string, string>::iterator it;

   while (count < 3)
   {
    it = userList.find(userName);
       hidePassword(passWord);
    if (it != userList.end())
    {
        if(userList.find(userName)->second == passWord)
              cout<<"Welcome "<<userName<<endl;
        else
          {
            cout<<"error try again "<<endl;
            passWord = "";
          }
    }
    else
    {
      cout<<"error try again "<<endl;
      passWord = "";
    }
    count++;
   }
    cout<<"Sorry about we can't identify you please call customer service"<<endl;
	return;
}

void accountOperations::hidePassword(string &pass)
{
  char ch;
  ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
}

int main()
{
  string userName;
  string passWord;
  accountOperations user;

   int choice;
   int count = 0;
   cout <<"Hello Thank you for choosing our bank"<<endl;
 
   cout <<"Please choose an option"<<endl;
   cout <<"1- Login"<<endl;
   cout <<"2- Signup"<<endl;
   cin >> choice;
   while(choice != 2 && choice != 1)
    {
       cout <<"Please select a good option"<<endl;
       cin >> choice;
    }

   switch(choice)
   {
    case 1: {
        cout << "Enter pass\n";
        user.logIn();
        break;
    }
    case 2: {
        user.signUp();
        break;
    }
    default:{
        cout<<""<<endl;
        break;
    }
   }

   cout <<"Please choose an option"<<endl;
   cout <<"1- Deposite"<<endl;
   cout <<"2- Transfert money"<<endl;
   cout <<"3- Buy a bill"<<endl;
   cout <<"4- Signup"<<endl;
   cout <<"Hello"<<endl;
   cin>>choice;
   switch(choice)
   {
    case 1: {
        cout << "Enter pass\n";
        user.logIn();
        break;
    }
    case 2: {
        user.signUp();
        break;
    }
    default:{
        cout<<""<<endl;
        break;
    }
   }
    return 0;
}
