💊 Pharmacy Management System built from scratch in C++  
🖥️ Console-based application using OOP principles  
🧱 Clean structure | 🔄 Scalable | 🛠️ Easy to maintain

 WorkFlow: 
 
 1️⃣ main.cpp → Entry point (starts the program)

2️⃣ core/
   → Controls the system logic
   - clsPharmacy → main controller
   - clsMedicinesManagement → CRUD operations
   - clsStockManagement → stock handling

3️⃣ models/
   → Data representation
   - clsMedical → medicine object (name, price, quantity)

4️⃣ screens/
   → User Interface (console)
   - clsScreen → base screen
   - clsShowMainMenuPharmacy → main menu
   - clsMedicalListScreen → display medicines
   - AddNewStockScreen → add new medicine
   - SearchPharmacyMedical → search feature

5️⃣ operations/
   → Business actions
   - clsSellMedicine → selling process
   - clsDeleteMedical → delete medicine
   - clsUpdateMedical → update info
   - clsAdjustStock → adjust stock
   - clsIncreaseQuantity → increase quantity

6️⃣ utils/
   → Helper tools (reusable)
   - clsString → string functions
   - clsDate → date handling
   - clsInputValidate → input validation

7️⃣ data/
   → Data storage
   - PharmacyFile.txt → save/load data

8️⃣ .gitignore
   → Ignore unnecessary files (.vs, bin, obj)

   
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

👉 easyy to maintain

🎯 Conclusion

This project is a modular C++ console application that demonstrate:

strong OOP desiign
separation of concerns
reusable components
