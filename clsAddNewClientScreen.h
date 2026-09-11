#pragma once
#include<iostream>
#include"clsIsvalidedate.h"
#include"clsBankClient.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
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
    static void AddNewClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            system("poase");
            // return ;// this will exit the function and it will not continue
        }


        _DrawScreenHeader("add new client");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }

};





























