#pragma once
#include"clsPharmacy.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMedicalListScreen.h"

class clsDeleteMedical : private clsScreen
{

    static void _PrintMedicalCard(clsPharmacy& Medical)
    {
        cout << "\n================== MEDICAL CARD ==================\n";

        cout << "Courier Name        : " << Medical.Courier << "\n";
        cout << "Courier Phone       : " << Medical.PhoneCourier << "\n";
        cout << "Medical Type        : " << Medical.TypeMedical << "\n";
        cout << "Price (DH)          : " << Medical.Price << "\n";
        cout << "Quantity            : " << Medical.Quantity << "\n";
        cout << "For Who             : " << Medical.ForWho << "\n";
        cout << "Code                : " << Medical.Code << "\n";

        cout << "==================================================\n";
    }

public:

    static void ShowDeleteMedical()
    {
        clsMedicalListScreen::ShowMedicalListInStock();


        _DrawScreenHeader("\t Delete Medical From Stock ");

        cout << "\t\t\t\tPlease Enter Code Of Medical You Want To Delete: ";

        string Code = clsInputValidate::ReadString();

        while (!clsPharmacy::IsMedicalExistsByCode(Code))
        {
            cout << "\t\t\t\tThis Code Was Not Found, Enter Correct Code: ";
            Code = clsInputValidate::ReadString();
        }

        clsPharmacy medicalCurrent = clsPharmacy::Search(Code);

        _PrintMedicalCard(medicalCurrent);

        char Answer = 'Y';

        cout << "\nDo you want to delete this medical from stock? [Y/N]: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (medicalCurrent.Delete())
            {
                cout << "Medical deleted successfully\n";
                _PrintMedicalCard(medicalCurrent);
            }
            else
            {
                cout << "\nError: Medical was not deleted\n";
            }
        }
    }
};