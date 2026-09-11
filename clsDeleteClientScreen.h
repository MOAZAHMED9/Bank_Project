#pragma once
#include<iostream>
#include"clsIsvalidedate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;




class clsDeleteClientScreen : protected clsScreen
{
private:
 static void _PrintClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client. GetFirstName();
        cout << "\nLastName    : " << client.GetLastName();
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.GetEmail();
        cout << "\nPhone       : " << client.GetPhone();
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.GetPinCode();
        cout << "\nBalance     : " << client.GetAccountBalance();
        cout << "\n___________________\n";

    }


public:
    static void Deletclient()
    {
     if(!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }


    _DrawScreenHeader("delet client");
    cout<<"enter acountnum :";
    string AccountNumber=clsInputValidate::ReadString();
    
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();

    }   

     clsBankClient Client1 = clsBankClient::Find(AccountNumber);
     _PrintClient(Client1);

     
    cout << "\nAre you sure you want to delete this client y/n? ";
        
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
       if( Client1.Delete())
       {
        cout << "\nClient Deleted Successfully :-)\n";
        _PrintClient(Client1);
       }  
            
       else
        {
           cout << "\nError Client Was not Deleted\n";
        }
    }
        
    }





};






