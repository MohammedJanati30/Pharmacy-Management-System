#pragma once
#include<iostream>
#include"clsPharmacy.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class AddNewStockScreen : protected clsScreen
{
private:

    // ===== Quantity Functions =====
    static double _OtherQuantity() {
        cout << "\tEnter Custom Quantity: ";
        return clsInputValidate::ReadDblNumber();
    }

    static double _Q20() { return 20; }
    static double _Q40() { return 40; }
    static double _Q50() { return 50; }
    static double _Q100() { return 100; }
    static double _Q150() { return 150; }
    static double _Q200() { return 200; }

    static double _PerformIncrease(short Choice)
    {
        switch (Choice)
        {
        case 1: return _Q20();
        case 2: return _Q40();
        case 3: return _Q50();
        case 4: return _Q100();
        case 5: return _Q150();
        case 6: return _Q200();
        case 7: return _OtherQuantity();
        }
        return 0;
    }

    static double _GetIncreaseValue()
    {
        cout << "\n===========================================\n";
        cout << "\t\t INCREASE STOCK MENU\n";
        cout << "===========================================\n";

        cout << "\t[1] +20\n";
        cout << "\t[2] +40\n";
        cout << "\t[3] +50\n";
        cout << "\t[4] +100\n";
        cout << "\t[5] +150\n";
        cout << "\t[6] +200\n";
        cout << "\t[7] Custom Quantity\n";

        cout << "===========================================\n";

        short Choice = clsInputValidate::ReadShortNumberBetween(1, 7, "Choose Option: ");

        return _PerformIncrease(Choice);
    }

    // ===== For Who Functions =====
    static string _Adult() { return "Adult"; }
    static string _Child() { return "Child"; }
    static string _Baby() { return "Baby"; }
    static string _Elderly() { return "Elderly"; }
    static string _All() { return "All"; }

    static string _PerformForWho(short Choice)
    {
        switch (Choice)
        {
        case 1: return _Adult();
        case 2: return _Child();
        case 3: return _Baby();
        case 4: return _Elderly();
        case 5: return _All();
        }
        return "Unknown"; // 🔥 fix مهم
    }

    static string _GetForWho()
    {
        cout << "\n===========================================\n";
        cout << "\t\t FOR WHO MENU\n";
        cout << "===========================================\n";

        cout << "\t[1] Adult\n";
        cout << "\t[2] Child\n";
        cout << "\t[3] Baby\n";
        cout << "\t[4] Elderly\n";
        cout << "\t[5] All\n";

        cout << "===========================================\n";

        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Choose Option: ");

        return _PerformForWho(Choice);
    }

    // ===== Main Fill =====
    static void _AddNewMedicalToStock(clsPharmacy& Medical)
    {
        cout << "\n--- Add New Stock ---\n";

        cout << "Courier Name     : ";
        Medical.Courier = clsInputValidate::ReadString();

        cout << "Courier Phone    : ";
        Medical.PhoneCourier = clsInputValidate::ReadString();

        cout << "Medical Name     : ";
        Medical.NameMedical = clsInputValidate::ReadString();

        cout << "Medical Type     : ";
        Medical.TypeMedical = clsInputValidate::ReadString();
     
        Medical.Quantity = _GetIncreaseValue();

        Medical.ForWho = _GetForWho();

        cout << "Price (DH)       : ";
        Medical.Price = clsInputValidate::ReadDblNumber();

      
    }

    static void _PrintCard(clsPharmacy& Medical)
    {
        cout << "\n================== MEDICAL CARD ==================\n";

        cout << "Courier Name   : " << Medical.Courier << "\n";
        cout << "Phone          : " << Medical.PhoneCourier << "\n";
        cout << "Type           : " << Medical.TypeMedical << "\n";
        cout << "Quantity       : " << Medical.Quantity << "\n";
        cout << "For Who        : " << Medical.ForWho << "\n";
        cout << "Price          : " << Medical.Price << "\n";
        cout << "Code           : " << Medical.Code << "\n";

        cout << "==================================================\n";
    }

public:




    static void ShowAddNewMedical()
    {
        _DrawScreenHeader("\tAdd New Medical To Stock");

        string Code;
        cout << "\nEnter Code Medical Name: ";
        Code = clsInputValidate::ReadString();
      
        if (clsPharmacy::IsMedicalExistsByCode(Code))
        {
            cout << "Medical Already Exists\n";

            if (clsPharmacy::AskToAddToStock(Code))
            {
                // ✔ FIX 
                double Quantity = _GetIncreaseValue();

                clsPharmacy::UpdateStock(Code, Quantity);

                clsPharmacy Medical = clsPharmacy::Search(Code);

                _PrintCard(Medical);
            }

            return;
        }
       

            clsPharmacy Medical = clsPharmacy::GetAddNewMedical(Code);

            _AddNewMedicalToStock(Medical);

            clsPharmacy::enSaveResults Result = Medical.Save();

            if (Result == clsPharmacy::enSaveResults::svSucceeded)
            {
                _PrintCard(Medical);
            }
            else
            {
                cout << "\nError: Save Failed\n";
            }
        }
    };
    