#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"



using namespace std;

class clsScreen
{
protected :
    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        
        cout << "\t\t\t\t\t User:"<< CurrentUser.GetUserName()<<endl;
        // clsDate date;
        // cout << "\t\t\t\t\t Date:";
        // date.Print();
        cout<< "\t\t\t\t\t Date:"<< clsDate::DateToString(clsDate())<<endl;
      

    }

    
    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
     
            if (!CurrentUser.CheckAccessPermission(Permission))
            {
                cout << "\t\t\t\t\t______________________________________";
                cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";   
                cout << "\n\t\t\t\t\t______________________________________\n\n";
                return false;
            }
            else
            {
                return true;
            }

    }

};




















