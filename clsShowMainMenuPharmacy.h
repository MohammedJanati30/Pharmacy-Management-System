#pragma once
#include <iostream>
#include <iomanip>

#include "clsDate.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "SearchPharmacyMedical.h"
#include "clsAlertSystem.h"
#include "clsMedicinesManagement.h"
#include "clsStockManagement.h"

using namespace std;

class clsShowMainMenuPharmacy : protected clsScreen
{
private:

    enum enPharmacyMenuOptions
    {
        enMedicinesManagement = 1,
        enStockManagement = 2,
        enSearchMedicine = 3,
        enAlertSystem = 4,
        enLogout = 5
    };

    static short _ReadMainMenuOption(short From, short To)
    {
        cout << setw(37) << left << ""
            << "Please enter a number from [ " << From << " ] to [ " << To << " ] : ";

        short Choice = clsInputValidate::ReadShortNumberBetween(
            From, To, "Enter a valid number");

        return Choice;
    }

    static void _PerformMainMenuOption(enPharmacyMenuOptions Option)
    {
        switch (Option)
        {
        case enMedicinesManagement:
            system("cls");
            clsMedicinesManagement::ShowMedicinesManagement();
            _GoBackToMenu();
            break;

        case enStockManagement:
            system("cls");

            clsStockManagement::ShowStockManagement();
            _GoBackToMenu();
            break;

        case enSearchMedicine:
            system("cls");

            SearchPharmacyMedical::ShowPharmacyMedical();
            _GoBackToMenu();
            break;

        case enAlertSystem:
            system("cls");

            clsAlertSystem::ShowAlertQuantity();
            _GoBackToMenu();
            break;

        case enLogout:
            _ShowLogout();
            break;
        }
    }

    static void _GoBackToMenu()
    {
        cout << "\nPress any key to return to menu...";
        system("pause");
        ShowMainMenuPharmacy();
    }

    static void _ShowMedicineList()
    {
        clsMedicalListScreen::ShowMedicalListInStock();
    }

    static void _StockManagement()
    {
        clsStockManagement::ShowStockManagement();
    }

    static void _ShowLogout()
    {
        cout << "Logout of the system\n";
    }

public:

    static void ShowMainMenuPharmacy()
    {
        system("cls");
        system("color 0A");

        _DrawScreenHeader("\t\tPharmacy System");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  MAIN MENU\n";
        cout << setw(37) << left << "" << "===========================================\n";

        cout << setw(37) << left << "" << "\t[1] Medicines Management.\n";
        cout << setw(37) << left << "" << "\t[2] Stock Management.\n";
        cout << setw(37) << left << "" << "\t[3] Search Medicine.\n";
        cout << setw(37) << left << "" << "\t[4] Stock Alert System.\n";
        cout << setw(37) << left << "" << "\t[5] Logout.\n";

        cout << setw(37) << left << "" << "===========================================\n";
        _PerformMainMenuOption(
            (enPharmacyMenuOptions)_ReadMainMenuOption(1, 5)
        );
    }
};