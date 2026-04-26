#pragma once
#include <iostream>
#include "clsPharmacy.h"
#include "clsString.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMedicalListScreen.h"

using namespace std;

class clsAdjustStock : private clsScreen
{
private:

    // ?? Print Medicine Details
    static void _PrintCard(clsPharmacy& Medical)
    {
        cout << "\n================== MEDICINE DETAILS ==================\n";

        cout << "Courier Name   : " << Medical.Courier << "\n";
        cout << "Phone          : " << Medical.PhoneCourier << "\n";
        cout << "Type           : " << Medical.TypeMedical << "\n";
        cout << "Quantity       : " << Medical.Quantity << "\n";
        cout << "For Who        : " << Medical.ForWho << "\n";
        cout << "Price          : " << Medical.Price << "\n";
        cout << "Code           : " << Medical.Code << "\n";

        cout << "======================================================\n";
    }

    // ?? Check if medicine exists
    static string _CheckMedicineExists()
    {
        string Code;

        cout << "\nEnter the medicine code to adjust: ";
        Code = clsInputValidate::ReadString();

        while (!clsPharmacy::IsMedicalExistsByCode(Code))
        {
            cout << "Code not found, please enter a valid code: ";
            Code = clsInputValidate::ReadString();
        }

        return Code;
    }

    // ?? Get manual quantity (+ / -)
    static double _GetAdjustmentQuantity()
    {
        cout << "Enter quantity (+ to add, - to subtract): ";
        return clsInputValidate::ReadDblNumber();
    }

public:

    // ?? Main Function
    static void ShowAdjustStock()
    {
        system("color 0B");

        clsMedicalListScreen::ShowMedicalListInStock();

        _DrawScreenHeader("\t Adjust Stock Management");

        string Code = _CheckMedicineExists();

        clsPharmacy Medical = clsPharmacy::Search(Code);

        _PrintCard(Medical);

        double qty = _GetAdjustmentQuantity();

        // ? ????? ?? 0
        if (qty == 0)
        {
            cout << "\nNo changes applied.\n";
            return;
        }

        // ? ????? ?? ????????
        char confirm;
        cout << "Are you sure you want to apply this change? (Y/N): ";
        cin >> confirm;

        if (toupper(confirm) != 'Y')
        {
            cout << "\nOperation cancelled.\n";
            return;
        }

        // ?? Update Stock
        if (clsPharmacy::UpdateStock(Code, qty))
        {
            cout << "\nStock updated successfully ?\n";
            clsPharmacy Medicalafterupdate = clsPharmacy::Search(Code);
            if (Medicalafterupdate.Quantity < 10) {
                cout << "\t\t\tLow stock! Quantity is below 10.\n " << endl;
            }
            _PrintCard(Medicalafterupdate);
        }

        else
        {
            cout << "\nOperation failed (Not enough stock) ?\n";
            return;
        }

    }
};