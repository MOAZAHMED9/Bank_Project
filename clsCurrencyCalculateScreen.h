#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsCurrency.h"
#include "clsIsvalidedate.h"
#include <iomanip>




class clsCurrencyCalculateScreen : protected clsScreen
{

static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }


public:

static void showCalcoulate()
{
         char mm='y';
         while(mm=='y'||mm=='Y')
        {
            system("cls");
            _DrawScreenHeader("calcoulate");
            string CurrencyCode , c2;
            cout << "\nPlease Enter CurrencyCode from: ";
            CurrencyCode = clsInputValidate::ReadString();
                
            while (!clsCurrency::IsCurrencyExist(CurrencyCode))
            {
                cout<<" currency is not found enter again \n";               
                CurrencyCode = clsInputValidate::ReadString();    

            }
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);    
        
            
            cout << "\nPlease Enter CurrencyCode to: ";
            c2 = clsInputValidate::ReadString();
                
            while (!clsCurrency::IsCurrencyExist(c2))
            {
                cout<<" currency is not found enter again \n";               
                c2 = clsInputValidate::ReadString();    

            }
                
            clsCurrency Currency2 = clsCurrency::FindByCode(c2);    

            int num=0;
            cout<<"enter amount\n";
            cin>>num;
            _PrintCurrency(Currency);
            
        
            float Defarance=Currency.defancebetweentwocurrency(Currency2,num);

            cout<<num<<" "<<Currency.CurrencyCode()<<" = "<<Defarance<<" "<<Currency2.CurrencyCode();
           
            cout<<"\n\nDo you Want Calculate Again : ";
            cin>>mm;

        };

}


};















