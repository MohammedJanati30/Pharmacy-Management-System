💊 Pharmacy Management System built from scratch in C++  
🖥️ Console-based application using OOP principles  
🧱 Clean structure | 🔄 Scalable | 🛠️ Easy to maintain

 WorkFlow: 
 
Pharmacy-Management-System/
│
├── main.cpp
├── core/
│   ├── clsPharmacy
│   ├── clsMedicinesManagement
│   ├── clsStockManagement
│
├── models/
│   ├── clsMedical
│
├── screens/
│   ├── clsScreen
│   ├── clsShowMainMenuPharmacy
│   ├── clsMedicalListScreen
│   ├── AddNewStockScreen
│   ├── SearchPharmacyMedical
│
├── operations/
│   ├── clsSellMedicine
│   ├── clsDeleteMedical
│   ├── clsUpdateMedical
│   ├── clsAdjustStock
│   ├── clsIncreaseQuantity
│
├── utils/
│   ├── clsString
│   ├── clsDate
│   ├── clsInputValidate
│
├── data/
│   └── PharmacyFile.txt
│
└── .gitignore

                                    🧠 Classes Summary
                                    
🔹 Core
clsPharmacy → main controller (starts system)
clsMedicinesManagement → manage medicines (add/update/delete)
clsStockManagement → manage stock logic
🔹 Models
clsMedical → represents a medicine (name, price, quantity)
🔹 Screens (UI)
clsScreen → base screen class
clsShowMainMenuPharmacy → main menu
clsMedicalListScreen → display medicines
AddNewStockScreen → add new medicine
SearchPharmacyMedical → search functionality
🔹 Operations
clsSellMedicine → selling process
clsDeleteMedical → delete medicine
clsUpdateMedical → update info
clsAdjustStock / clsIncreaseQuantity → stock changes
🔹 Utilities
clsString → string helpers
clsDate → date handling
clsInputValidate → validate user input
⚙️ OOP Concepts Used
🧩 1. Reusability
Utility classes (clsString, clsInputValidate) reused everywhere
Avoid rewriting logic → clean code
🧬 2. Inheritance
clsScreen = base class
other screens inherit from it

👉 reuse UI behavior

🔀 3. Polymorphism
same function (e.g. ShowScreen())
different behavior depending on class

👉 flexible UI system

🧱 4. Encapsulation
each class manages its own data
hide internal logic
🔗 5. Modularity
project divided into:
core
UI
utils
operations

👉 easy to maintain

🎯 Conclusion

This project is a modular C++ console application that demonstrates:

strong OOP design
separation of concerns
reusable components
