#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsIsvalidedate.h"
#include"clsBankClient.h"



using namespace  std;


class  clsWithdrowScreen : protected clsScreen
{
private:

    static void _PrintClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.GetFirstName();
        cout << "\nLastName    : " << client.GetLastName();
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.GetEmail();
        cout << "\nPhone       : " << client.GetPhone();
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.GetPinCode();
        cout << "\nBalance     : " << client.GetAccountBalance();
        cout << "\n___________________\n";

    }


    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


    
public:
 
    static void showWithdrowScreen()
    {
        system("cls");
        _DrawScreenHeader("Withdrow ");
        string AccountNumber= _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient Client =clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease enter Withdrow amount? ";
        Amount = clsInputValidate::ReadTNumber<double>();

        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
           if( Client.Withdrow(Amount))
           { 
            cout << "\nAmount Withdrew Successfully.\n";
            cout << "\nNew Balance Is: " << Client.GetAccountBalance();
           }
           else
           {
               cout << "\nCannot withdraw, Insuffecient Balance!\n";
               cout << "\nAmout to withdraw is: " << Amount;
               cout << "\nYour Balance is: " << Client.GetAccountBalance();
               
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
            
    }


};
