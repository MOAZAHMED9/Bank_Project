#pragma once
#include<iostream>
#include"clsIsvalidedate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;



class clsUpdateClientSCreen:protected clsScreen
{   
private:

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.SetFirstName( clsInputValidate::ReadString());

        cout << "\nEnter LastName: ";
        Client.SetLastName(clsInputValidate::ReadString()) ;

        cout << "\nEnter Email: ";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        Client.SetPhone(clsInputValidate::ReadString()) ;

        cout << "\nEnter PinCode: ";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        Client.SetAccountBalance( clsInputValidate::ReadTNumber<float>());
    }


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

    static void showupdateclint()
    {
         if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("update client");
        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        
        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";
        ReadClientInfo(Client1);

    
        clsBankClient::enSaveResults SaveResult;
        
        SaveResult = Client1.Save();
        
        switch (SaveResult)
        {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
            cout << "\nError account was not saved because it's Empty";
            break;
                    
            }
                    
        }

    }

};





