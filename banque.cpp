// Example program
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;

class accountOperations
{
    public:
    void signUp(string); //
    void login(); //Connecter a un compte dans la banque
    void hidePassword(string&);//
    void showAccount(); //Show detail about the account last transaction (within the last 2 weeks)
    void transfertMoney(); //Transfert from one account to another in the same banks and update both accounts
    void Deposite(); //Put the money in the account
    void withdrawal(); //Make a payement at the store
    void logOut();
    accountOperations(); //Constructor
    ~accountOperations(); //Destructor
};

void hidePassword(string &pass)
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
  //vector<string> userList = {""};
  string testpw = "gun";
  int count = 0;
   cout <<"Hello Merci d'avoir choisi la notre banque"<<endl;
   cout<<"Entre votre nom d'utilisateur et mot de passe"<<endl;
   cout<<"Username: ";
   cin>>userName;
   cout<<"Password: ";
   hidePassword(passWord);

   while (count < 3)
   {
	   hidePassword(passWord);
    if (passWord == testpw)
    {
      cout<<"Welcome "<<userName<<endl;
	  passWord = "";
    }
    else
    {
      cout<<"error try again "<<endl;
	  passWord = "";
    }
	count++;
   }
   cout << "Enter pass\n";
   
   cout <<"Hello"<<endl;
    return 0;
}
