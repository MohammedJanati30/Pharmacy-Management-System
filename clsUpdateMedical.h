#pragma once
#include<iostream>
#include"clsPharmacy.h"
#include"clsInputValidate.h"

class clsUpdateMedical
{
private:

    static void _PrintMedicalCard(clsPharmacy Medical)
    {
        cout << "\nMedical Card:";
        cout << "\n___________________";

        cout << "\nCourier Name   : " << Medical.Courier;
        cout << "\nCourier Phone  : " << Medical.PhoneCourier;
        cout << "\nMedical Name   : " << Medical.NameMedical;
        cout << "\nType           : " << Medical.TypeMedical;
        cout << "\nQuantity       : " << Medical.Quantity;
        cout << "\nFor Who        : " << Medical.ForWho;
        cout << "\nPrice (DH)     : " << Medical.Price;
        cout << "\nCode           : " << Medical.Code;

        cout << "\n___________________\n";
    }

    static void _ReadMedicalData(clsPharmacy& Medical)
    {
        cout << "\nEnter Courier Name: ";
        Medical.Courier = clsInputValidate::ReadString();

        cout << "Enter Courier Phone: ";
        Medical.PhoneCourier = clsInputValidate::ReadString();

        cout << "Enter Medical Name: ";
        Medical.NameMedical = clsInputValidate::ReadString();

        cout << "Enter Type: ";
        Medical.TypeMedical = clsInputValidate::ReadString();

        cout << "Enter Quantity: ";
        Medical.Quantity = clsInputValidate::ReadIntNumber();

        cout << "Enter For Who: ";
        Medical.ForWho = clsInputValidate::ReadString();

        cout << "Enter Price: ";
        Medical.Price = clsInputValidate::ReadDblNumber();
    }

    static void _ValidateUpdate(clsPharmacy& Medical)
    {
        system("cls");

        cout << "\nAre you sure you want to update this Medical? y/n: ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Medical Info:";
            cout << "\n____________________\n";

            Medical = clsPharmacy::GetUpdateMedical(Medical);

            _ReadMedicalData(Medical);

            clsPharmacy::enSaveResults SaveResult;

            SaveResult = Medical.Save();

            switch (SaveResult)
            {
            case clsPharmacy::enSaveResults::svSucceeded:
                cout << "\nMedical updated successfully :-)\n";
                _PrintMedicalCard(Medical);
                break;

            case clsPharmacy::enSaveResults::svFailedEmptyObject:
                cout << "\nError: Medical was not saved because it's empty\n";
                break;
            }
        }
    }

public:

    static void ShowUpdateMedical()
    {
        cout << "Please Enter Medical Code You Want To Change: ";

        string Code = clsInputValidate::ReadString();

        while (!clsPharmacy::IsMedicalExistsByCode(Code))
        {
            cout << "\nCode is not found, choose another one: ";
            Code = clsInputValidate::ReadString();
        }

        clsPharmacy Medical = clsPharmacy::Search(Code);

        _PrintMedicalCard(Medical);

        _ValidateUpdate(Medical);
    }
};