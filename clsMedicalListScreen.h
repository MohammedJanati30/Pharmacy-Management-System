#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "clsScreen.h"
#include "clsPharmacy.h"
#include <iomanip>

class clsMedicalListScreen : protected clsScreen
{
private:

    static void _ShowPrintMedicalRecord(clsPharmacy& Medical) {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Medical.Courier;
        cout << "| " << setw(15) << left << Medical.PhoneCourier;
        cout << "| " << setw(30) << left << Medical.NameMedical;
        cout << "| " << setw(15) << left << Medical.TypeMedical;
        cout << "| " << setw(10) << left << Medical.Quantity;
        cout << "| " << setw(13) << left << Medical.ForWho;
        cout << "| " << setw(13) << left << Medical.GetPriceAsString();
        cout << "| " << setw(13) << left << Medical.Code;
    }

public:

    static void ShowMedicalListInStock() {

        vector<clsPharmacy> vMedicalPharmacy = clsPharmacy::GetPharmacyMedicalList();

        string Title = "\tPharmacy Medical List ";
        string SubTitle = "\t ( " + to_string(vMedicalPharmacy.size()) + " ) Medicals";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________";
        cout << "_________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Courier";
        cout << "| " << left << setw(15) << "Phone Courier";
        cout << "| " << left << setw(30) << "Medical Name";
        cout << "| " << left << setw(15) << "Medical Type";
        cout << "| " << left << setw(10) << "Quantity";
        cout << "| " << left << setw(13) << "For Who";
        cout << "| " << left << setw(13) << "Price (DH)";
        cout << "| " << left << setw(13) << "Code";

        cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________";
        cout << "_________________________________________________\n" << endl;

        if (vMedicalPharmacy.empty()) {
            cout << setw(8) << left << "" << "No Medical For the moment\n";
        }
        
            for (clsPharmacy& Medical : vMedicalPharmacy) {
                _ShowPrintMedicalRecord(Medical);
                cout << endl;
            }
       

        cout << setw(8) << left << "" << "\n\t__________________________________________________________________________________";
        cout << "_________________________________________________\n" << endl;
    }
};