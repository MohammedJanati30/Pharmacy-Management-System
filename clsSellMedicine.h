#pragma once
#include<iostream>
#include"clsPharmacy.h"
#include"clsString.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMedicalListScreen.h"

class clsSellMedicine  : private clsScreen
{



private :

	static void _PrintCard(clsPharmacy& Medical)
	{
		cout << "\n================== MEDICAL CARD ==================\n";


		cout << "Type           : " << Medical.TypeMedical << "\n";
		cout << "Quantity       : " << Medical.Quantity << "\n";
		cout << "For Who        : " << Medical.ForWho << "\n";
		cout << "Price          : " << Medical.Price << "\n";

		cout << "==================================================\n";
	}
    static double _Q1() { return 1; }
    static double _Q2() { return 2; }
    static double _Q3() { return 3; }
    static double _Q4() { return 4; }
   
    static double _PerformIncrease(short Choice)
    {
        switch (Choice)
        {
        case 1: return _Q1();
        case 2: return _Q2();
        case 3: return _Q3();
        case 4: return _Q4();



        default:
        {
            cout << "\t\t\tYou Cant Sell > 4 Medicales From the Same Type \n";
        }
        return 0;
        }
    }
    static short _GetDeccreaseValue()
    {
        cout << "\n===========================================\n";
        cout << "\t\t SELL MEDICINE MENU\n";
        cout << "===========================================\n";

        cout << "\t[1] -1\n";
        cout << "\t[2] -2\n";
        cout << "\t[3] -3\n";
        cout << "\t[4] -4\n";
        

        cout << "===========================================\n";

        short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Choose Option: ");

        return _PerformIncrease(Choice);
    }
    static string    CheckMedicineExists() {
        string Code;
        cout << "\nPlease enter the medicine code  : ";
        Code = clsInputValidate::ReadString();

        while (!clsPharmacy::IsMedicalExistsByCode(Code))
        {
            cout << "\t\t\t\tThis Code Was Not Found, Enter Correct Code: ";
            Code = clsInputValidate::ReadString();
        }
        return Code;
    }
public:
    static void ShowSellMedicine()

    {
        clsMedicalListScreen::ShowMedicalListInStock();
        _DrawScreenHeader("\tDecrease Quantity From Stock");

        string Code = CheckMedicineExists();
      
        
        
            clsPharmacy Medical = clsPharmacy::Search(Code);

            _PrintCard(Medical);

                
                double Quantity = _GetDeccreaseValue();

                if (clsPharmacy::UpdateStock(Code, -Quantity)) {
                    cout << "\t\tDecrease Quantity Successfully \n";
                    clsPharmacy MedicalAfterUpdate = clsPharmacy::Search(Code);


                    _PrintCard(MedicalAfterUpdate);

               }
                else {
                    cout << "Not enough stock!  " << endl;
                    return;
                }

             



       
    }
};

