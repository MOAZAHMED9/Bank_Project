#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsIsvalidedate.h"
#include <iomanip>



class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }


public:
static void DeleteUser()
{
    _DrawScreenHeader("delet User");

    string UserName=clsInputValidate::ReadString();
    
    while (!clsUser::IsUserExist(UserName))
    {
        cout << "\nUser  is not found, choose another one: ";
        UserName = clsInputValidate::ReadString();

    }   

     clsUser User = clsUser ::Find(UserName);
     _PrintUser(User);

     
    cout << "\nAre you sure you want to delete this user y/n? ";
        
    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
       if( User.Delete())
       {
        cout << "\nuser Deleted Successfully :-)\n";
        _PrintUser(User);
       }  
            
       else
        {
           cout << "\nError user Was not Deleted\n";
        }
    }
}      
};





