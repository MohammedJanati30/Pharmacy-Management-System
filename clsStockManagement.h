#pragma once
#include<iostream>
#include"clsPharmacy.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsSellMedicine.h"
#include"AddNewStockScreen.h"
#include"clsAdjustStock.h"
#include"clsMedicalListScreen.h"

class clsStockManagement : protected clsScreen
{
private:

    enum enStockOperation
    {
        DecreaseStock = 1,
        Restock = 2,
        AdjustStock = 3,
        ViewStockList = 4,
        Back = 5,
    };

    static void _GoBackToSubMenu()
    {
        cout << "\nPress any key to return to Stock Management menu...\n";
        system("pause");
        system("cls");

        ShowStockManagement();
    }
    static void _ViewStockList(){
        clsMedicalListScreen::ShowMedicalListInStock();
         }
    static void _SellMedicine()
    {
        clsSellMedicine::ShowSellMedicine();
    }

    static void _RestockMedicine()
    {
        AddNewStockScreen::ShowAddNewMedical();
    }

    static void _AdjustStock()
    {
        clsAdjustStock::ShowAdjustStock();
    }
    static void _GoBackToStockMenu()
    {
        cout << "\nPress any key to return to menu...";
        system("pause");
    }
    static void _Perform(enStockOperation choice)
    {
        switch (choice)
        {
        case DecreaseStock:
            system("cls");
            _SellMedicine();
            _GoBackToSubMenu();       
            break;

        case Restock:
            system("cls");
            _RestockMedicine();
            _GoBackToSubMenu();     
            break;

        case AdjustStock:
            system("cls");
            _AdjustStock();
            _GoBackToSubMenu();      
            break;
        case ViewStockList:
            system("cls");
            _ViewStockList();
            _GoBackToSubMenu();
            break;

        case Back:
            _GoBackToStockMenu();
            break;
        }
    }                                                

public:
    static void ShowStockManagement()
    {
        short choice;

        do
        {
            system("cls");
            system("color 0B");

            _DrawScreenHeader("Stock Management Menu");

            cout << "===========================================\n";
            cout << "\t STOCK MANAGEMENT\n";
            cout << "===========================================\n";

            cout << "[1] Sell Medicine\n";
            cout << "[2] Restock Medicine\n";
            cout << "[3] Adjust Stock\n";
            cout << "[4] View Stock List\n";
            cout << "[5] Back\n";
            cout << "===========================================\n";

            choice = clsInputValidate::ReadShortNumberBetween(1, 5);

            _Perform((enStockOperation)choice);

        } while (choice != Back);
    }
};