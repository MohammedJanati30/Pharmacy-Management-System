#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMedicalListScreen.h"
#include "AddNewStockScreen.h"
#include "clsUpdateMedical.h"
#include "clsDeleteMedical.h"
                                          
using namespace std;

class clsMedicinesManagement : protected clsScreen
{
private:

    enum enMedicinesMenu
    {
        ShowList = 1,
        AddNew = 2,
        UpdateInfo = 3, 
        DeleteMed = 4,
        Back = 5
    };
    static short _ReadMainMenuOption(short From, short To)
    {
        cout << setw(37) << left << ""
            << "Please enter a number from [ " << From << " ] to [ " << To << " ] : ";

        short Choice = clsInputValidate::ReadShortNumberBetween(
            From, To, "Enter a valid number");

        return Choice;
    }

    static void _GoBackToMenu()
    {
        cout << "\nPress any key to return to menu...";
        system("pause");
        ShowMedicinesManagement();

    }


    static short _ReadChoice()
    {
        cout << "\nEnter your choice [1 - 5]: ";
        return clsInputValidate::ReadShortNumberBetween(1, 5);
    }

    static void _ShowList()
    {
        clsMedicalListScreen::ShowMedicalListInStock();
    }

    static void _AddNew()
    {
        AddNewStockScreen::ShowAddNewMedical();
    }

    static void _UpdateInfo()
    {
        clsUpdateMedical::ShowUpdateMedical();
    }

    static void _Delete()
    {
        clsDeleteMedical::ShowDeleteMedical();
    }
    static void _GoBackToMainMenue()
    {
        cout << "\nPress any key to return to menu...";
        system("pause");
    }

    static void _Perform(enMedicinesMenu Choice)
    {
        switch (Choice)
        {
        case ShowList:
            system("cls");
            _ShowList();
            _GoBackToMenu();
            break;

        case AddNew:
            system("cls");
            _AddNew();
            _GoBackToMenu();
            break;

        case UpdateInfo:
            system("cls");
            _UpdateInfo();
            _GoBackToMenu();
            break;

        case DeleteMed:
            system("cls");
            _Delete();
            _GoBackToMenu();
            break;

        case Back:
            _GoBackToMainMenue();
            break;
        }
    }

public:

    static void ShowMedicinesManagement()
    {
       
            system("cls");
            system("color 0A");

            _DrawScreenHeader("\t Medicines Management");

            cout << setw(37) << left << "" << "----------- MEDICINES MANAGEMENT -----------\n\n";

            cout << setw(37) << left << "" << "[1] Show Medicines List\n";
            cout << setw(37) << left << "" << "[2] Add New Medicine\n";
            cout << setw(37) << left << "" << "[3] Update Medicine Info\n";
            cout << setw(37) << left << "" << "[4] Delete Medicine\n";
            cout << setw(37) << left << "" << "[5] Back \n";

            cout << setw(37) << left << "" << "------------------------------------------\n";

            _Perform((enMedicinesMenu)_ReadMainMenuOption(1, 5));
    }
};