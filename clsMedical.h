#pragma once
#include <sstream>
#include <iomanip>
#include<iostream>
#include<string>
using namespace std;

class clsMedical
{
private:
    string _NameMedical = "";
    string _TypeMedical = "";
    int _Quantity = 0;
    string _ForWho = "";
    double _Price = 0;
    string _Code = "";

public:

    // Constructor
    clsMedical() {}

    clsMedical(string name, string type, int quantity, string forWho, double price, string code)
    {
        _NameMedical = name;
        _TypeMedical = type;
        _Quantity = quantity;
        _ForWho = forWho;
        _Price = price;
        _Code = code;
    }

    // ======================
    // GETTERS
    // ======================

    string GetNameMedical() { return _NameMedical; }
    string GetTypeMedical() { return _TypeMedical; }
    int GetQuantity() { return _Quantity; }
    string GetForWho() { return _ForWho; }
    double GetPrice() { return _Price; }
    string GetCode() { return _Code; }

    // ======================
    // SETTERS
    // ======================

    void SetNameMedical(string name) { _NameMedical = name; }
    void SetTypeMedical(string type) { _TypeMedical = type; }
    void SetQuantity(int quantity) { _Quantity = quantity; }
    void SetForWho(string forWho) { _ForWho = forWho; }
    void SetPrice(double price) { _Price = price; }
    void SetCode(string code) { _Code = code; }

    // ======================
    // PROPERTIES STYLE (MSVC only)
    // ======================

    __declspec(property(get = GetNameMedical, put = SetNameMedical)) string NameMedical;
    __declspec(property(get = GetTypeMedical, put = SetTypeMedical)) string TypeMedical;
    __declspec(property(get = GetQuantity, put = SetQuantity)) int Quantity;
    __declspec(property(get = GetForWho, put = SetForWho)) string ForWho;
    __declspec(property(get = GetPrice, put = SetPrice)) double Price;
    __declspec(property(get = GetCode, put = SetCode)) string Code;

    string GetPriceAsString() {

        ostringstream oss;
        oss << fixed << setprecision(2) << GetPrice() << " DH";

        return oss.str();
    }
}; 