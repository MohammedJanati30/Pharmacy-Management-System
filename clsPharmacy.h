#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsMedical.h"
#include"clsInputValidate.h"
#include"clsString.h"

using namespace std;

class clsPharmacy : public clsMedical
{

private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _Courier = "";
    string _PhoneCourier = "";
    bool _MarkedForDelete = false;

    static clsPharmacy _ConvertLineToMedicalObject(string Line, string Separator = "#//#")
    {
        vector<string> vPharmacyData;
        vPharmacyData = clsString::Split(Line, Separator);

        return clsPharmacy(enMode::UpdateMode, vPharmacyData[0], vPharmacyData[1], vPharmacyData[2],
            vPharmacyData[3], stoi(vPharmacyData[4]), vPharmacyData[5], stod(vPharmacyData[6]), vPharmacyData[7]);
    }

    static vector<clsPharmacy> _LoadLineDataFromFile() {
        vector<clsPharmacy> vPharmacyData;
        fstream MyFile;
        MyFile.open("PharmacyFile.txt", ios::in);

        if (MyFile.is_open()) {
            string Line = "";
            while (getline(MyFile, Line)) {
                clsPharmacy Medical = _ConvertLineToMedicalObject(Line);
                vPharmacyData.push_back(Medical);
            }
            MyFile.close();
        }
        return vPharmacyData;
    }

    static string _ConvertMedicalObjectRecordToLine(clsPharmacy& MedicalData, string Separator = "#//#") {
        string RecordToLine = " ";
        RecordToLine += MedicalData.Courier + Separator;
        RecordToLine += MedicalData.PhoneCourier + Separator;
        RecordToLine += MedicalData.NameMedical + Separator;
        RecordToLine += MedicalData.TypeMedical + Separator;
        RecordToLine += to_string(MedicalData.Quantity) + Separator;
        RecordToLine += MedicalData.ForWho + Separator;
        RecordToLine += to_string(MedicalData.Price) + Separator;
        RecordToLine += MedicalData.Code;

        return RecordToLine;
    }

    void _AddNew() {
        _AddDataLineToFile(_ConvertMedicalObjectRecordToLine(*this));
    }

    void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("PharmacyFile.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }

    static clsPharmacy _EmptyMedicalObject() {
        return clsPharmacy(EmptyMode, "", "", "", "", 0, "", 0, "");
    }

    static void _SaveClientsDataToFile(vector<clsPharmacy> vMedical)
    {
        fstream MyFile;
        MyFile.open("PharmacyFile.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsPharmacy C : vMedical)
            {
                if (C.MarkedForDeleted() == false)
                {
                    DataLine = _ConvertMedicalObjectRecordToLine(C);
                    MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }
    }

    void _Update() {
        vector<clsPharmacy> VMedicalData = _LoadLineDataFromFile();

        for (clsPharmacy& M : VMedicalData) {
            if (M.Code == Code) {
                M = *this;
                break;
            }
        }

        _SaveClientsDataToFile(VMedicalData);
    }

public:

    clsPharmacy(enMode Mode, string Courier, string PhoneCourier,
        string NameMedical, string TypeMedical,
        int Quantity, string ForWho,
        double Price, string Code)
        : clsMedical(NameMedical, TypeMedical, Quantity, ForWho, Price, Code)
    {
        _Mode = Mode;
        _Courier = Courier;
        _PhoneCourier = PhoneCourier;
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    static clsPharmacy GetAddNewMedical(string Code) {
        return clsPharmacy(AddNewMode, "", "", "", "", 0, "", 0, Code);
    }

    static clsPharmacy GetUpdateMedical(clsPharmacy Medical) {
        return clsPharmacy(AddNewMode, "", "", "", "", 0, "", 0, Medical.Code);
    }

    enMode GetMode() { return _Mode; }
    string GetCourier() { return _Courier; }
    string GetPhoneCourier() { return _PhoneCourier; }

    void SetMode(enMode mode) { _Mode = mode; }
    void SetCourier(string courier) { _Courier = courier; }
    void SetPhoneCourier(string phone) { _PhoneCourier = phone; }

    __declspec(property(get = GetMode, put = SetMode)) enMode Mode;
    __declspec(property(get = GetCourier, put = SetCourier)) string Courier;
    __declspec(property(get = GetPhoneCourier, put = SetPhoneCourier)) string PhoneCourier;

    bool IsEmpty() {
        return (_Mode == enMode::EmptyMode);
    }

    static vector<clsPharmacy> GetPharmacyMedicalList() {
        return _LoadLineDataFromFile();
    }

    static clsPharmacy Search(string Code) {

        vector<clsPharmacy> vPharmacyMedical = GetPharmacyMedicalList();

        for (clsPharmacy& Medical : vPharmacyMedical) {
            if (Medical.Code == Code) {
                return Medical;
            }
        }
        return _EmptyMedicalObject();
    }

    static clsPharmacy SearchMedical(string NameMedical) {

        vector<clsPharmacy> vPharmacyMedical = GetPharmacyMedicalList();

        for (clsPharmacy& Medical : vPharmacyMedical) {
            if (Medical.NameMedical == NameMedical) {
                return Medical;
            }
        }
        return _EmptyMedicalObject();
    }

    static bool IsMedicalExistsByCode(string Code) {

        clsPharmacy Medical = clsPharmacy::Search(Code);
        return (!Medical.IsEmpty());
    }

    static bool CheckQuantity(clsPharmacy Medical) {
        return Medical.Quantity < 10;
    }

    static vector<clsPharmacy> AlertSystem() {

        vector<clsPharmacy> AlertQuantity;
        vector<clsPharmacy> vAllMedicals = GetPharmacyMedicalList();

        for (clsPharmacy M : vAllMedicals) {
            if (CheckQuantity(M)) {
                AlertQuantity.push_back(M);
            }
        }
        return AlertQuantity;
    }

    static bool UpdateStock(string& Code, double Quantity)
    {
        vector<clsPharmacy> vAllMedicals = GetPharmacyMedicalList();

        for (clsPharmacy& M : vAllMedicals)
        {
            if (M.Code == Code)
            {
                // check ??? ????
                if (M.Quantity + Quantity < 0)
                {
                    
                    return false;
                }

                M.Quantity += Quantity;

                _SaveClientsDataToFile(vAllMedicals);
                return true; // ??? ??????
            }
        }

       
        return false;
    }

    static bool AskToAddToStock(string Code)
    {
        clsPharmacy MedicalCode = clsPharmacy::Search(Code);

        cout << setw(37) << left << "" << "==============================================================\n";
        cout << setw(37) << left << "" << "\t\t Quantity Aleardy Existe   " << MedicalCode.NameMedical  << " :  " << MedicalCode.GetQuantity() << "\n";
        cout << setw(37) << left << "" << "==============================================================\n";

        cout << setw(37) << left << "" << "Do You Want To Add This To Stock [1]: YES   [2]: NO ? ";

        short choice = clsInputValidate::ReadIntNumberBetween(1, 2);

        return choice == 1;
    }

    bool Delete() {
        vector<clsPharmacy> VMedicals = GetPharmacyMedicalList();

        for (clsPharmacy& Medical : VMedicals) {
            if (Medical.GetCode() == Code) {
                Medical._MarkedForDelete = true;
                break;
            }
        }

        _SaveClientsDataToFile(VMedicals);

        *this = _EmptyMedicalObject();
        return true;
    }

    enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            if (IsEmpty())
                return enSaveResults::svFailedEmptyObject;
            break;

        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;

        case enMode::AddNewMode:
            _AddNew();
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;
        }

        return enSaveResults::svFailedEmptyObject;
    }
};