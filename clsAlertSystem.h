#pragma once

#include "clsScreen.h"
#include "clsPharmacy.h"
#include <iomanip>
#include <string>
using namespace std;

class clsAlertSystem : protected clsScreen
{
private:

    static void _PrintAlertQuantityInSystem(clsPharmacy& Medical) {

        cout << "\t\t" << setw(10) << left << "" << "| " << setw(15) << left << Medical.NameMedical;
        cout << "\t\t" << "| " << setw(10) << left << Medical.TypeMedical;
        cout << "\t\t" << "| " << setw(7) << left << Medical.Quantity;
        cout << "\t\t" << "| " << setw(10) << left << Medical.Code;
    }

public:

    static void ShowAlertQuantity() {

        vector<clsPharmacy> VAlertQty = clsPharmacy::AlertSystem();

        string Title = "\t Low Stock Items In System ";
        string SubTitle = "Low Stock Alert Count: ( " + to_string(VAlertQty.size()) + " ) ";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\t\t\t" << setw(10) << left << "" << "\n\t___________________________________________________________________________________________________________________\n";
        cout << "\t\t" << setw(10) << "" << left << "| " << setw(15) << left << "Medical Name";
        cout << "\t\t" << "| " << setw(10) << left << "Medical Type";
        cout << "\t\t" << "| " << setw(7) << left << "Quantity";
        cout << "\t\t" << "| " << setw(10) << left << "Code / Low";
        cout << "\t\t\t" << setw(10) << left << "" << "\n\t___________________________________________________________________________________________________________________\n\n";

        if (VAlertQty.size() > 10) {
            cout << "\t\t" << setw(10) << left << "No medicines with low quantity.\n";
        }
        else {

            for (clsPharmacy& Medicine : VAlertQty) {
                system("color 0C");
                _PrintAlertQuantityInSystem(Medicine);
                cout << endl;
            }
        }

        cout << "\t\t\t" << setw(10) << left << "" << "\n\t___________________________________________________________________________________________________________________\n";
    }
};