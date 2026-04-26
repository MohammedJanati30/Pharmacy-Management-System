#pragma once
#include<iostream>
#include"clsPharmacy.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class SearchPharmacyMedical : protected clsScreen
{
private:

    static void _PrintPharmacyMedicalCard(clsPharmacy& Medical)
    {
        cout << "\n Pharmacy Medical Card:";
        cout << "\n___________________";

        cout << "\nName Of Courier  : " << Medical.Courier;
        cout << "\nPhone Of Courier : " << Medical.PhoneCourier;
        cout << "\nMedical Name     : " << Medical.NameMedical;
        cout << "\nMedical Type     : " << Medical.TypeMedical;
        cout << "\nQuantity         : " << Medical.Quantity;
        cout << "\nFor Who          : " << Medical.ForWho;
        cout << "\nPrice (DH)       : " << Medical.Price;
        cout << "\nCode             : " << Medical.Code;

        cout << "\n___________________\n";
    }

public:

    static void ShowPharmacyMedical()
    {
        string Title = "Searching On Medical";

        _DrawScreenHeader(Title);

        string Code = "";

        cout << "\t\t\t Please Enter Code : ";
        Code = clsInputValidate::ReadString();

        while (!clsPharmacy::IsMedicalExistsByCode(Code))
        {
            cout << "\t\t\t This Code Was Not Found, Try to choose another one\n";
            Code = clsInputValidate::ReadString();
        }

        clsPharmacy pharmacyMedical = clsPharmacy::Search(Code);

        _PrintPharmacyMedicalCard(pharmacyMedical);
    }
};