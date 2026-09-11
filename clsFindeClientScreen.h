#pragma once
#include<iostream>
#include"clsIsvalidedate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;
 
class clsFindClientScreen : protected clsScreen
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

static void ShowFindClient()
{
    
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("find acount");
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        if(!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
            _PrintClient(Client1);
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

    }


};