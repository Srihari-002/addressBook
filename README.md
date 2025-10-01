# 📒 Address Book Management System in C  

This project is a **command-line based Address Book application** developed in **C** that enables users to efficiently manage contact information with features like **creation, search, edit, deletion, and storage in a `.csv` file**.  

Built using **modular C programming**, it incorporates strong **input validation** and **file handling**, simulating the functionality of real-world contact management systems.  

The system allows users to **store, retrieve, and modify contacts** in a structured way, ensuring **data consistency** and preventing errors like duplicate entries. By using a **CSV file** for storage, the application provides **persistent data storage**, so users don’t lose their contacts even after closing the program.  

Key highlights include:  
- **Efficient Contact Management**: Quickly add, edit, search, and delete contacts from a command-line interface.  
- **Robust Input Validation**: Ensures that all names, emails, and phone numbers are correctly formatted and prevents invalid data from being saved.  
- **Persistent Storage**: Contacts are saved in a `.csv` file, which can also be opened in Excel or other spreadsheet software for external editing or backup.  
- **Modular Design**: The code is divided into modules for **contacts**, **file operations**, and **utilities**, making it easy to maintain and extend.  
- **User-friendly Interface**: Simple menu-driven interaction allows users to perform operations with minimal effort.  
- **Scalability**: Supports hundreds of contacts without performance issues.  

This project not only serves as a **practical tool for managing personal or professional contacts**, but also as a **learning resource** for students and beginners to understand:  
- File handling in C  
- Modular programming concepts  
- Input validation techniques  
- Basic data structures for storing information  

It is suitable for **students, hobbyists, and anyone learning C programming**, as it combines **real-world functionality** with **core programming concepts**.  


## 📌 Project Overview  

Traditional paper-based address books are outdated and inefficient. This project provides a **digital solution** that allows users to manage contacts using a **terminal-based interface**.  

It includes:  
- Real-time user interaction  
- Robust input validation  
- Persistent storage using **file I/O operations**  

Contacts are saved in **CSV format** so that the data can also be viewed or modified externally.  

---

## ⚙️ Components / Tools Used  

- **C Programming Language**  
- **GCC Compiler**  
- **Terminal / Command-line Interface**  
- **CSV file** for storage  
- **Modular File Structure**  

---

## 🧠 Working Principle  

The system uses a **menu-driven interface** to perform the following operations:  

- **Create Contact** → Adds a new contact after validating the name, email, and phone number. Prevents duplicates.  
- **Search Contact** → Lets the user search by name, email, or phone. Displays matching results.  
- **Edit Contact** → Allows editing of existing contact information after confirmation.  
- **Delete Contact** → Removes a contact with confirmation and updates the list.  
- **List Contacts** → Displays all contacts in a neatly formatted list.  
- **Save & Exit** → Writes all changes to `contacts.csv` and exits cleanly.  

---

## 🔐 Input Validation Rules  

- **Email** → Must contain a single `@` and end with `.com`  
  - Example: `hari.g@domain.com`  
- **Phone** → Exactly **10 digits**, numeric only  
  - Example: `8328240738`  
- **Name** → Alphabetic characters only (no numbers or special characters)  
  - Example: `Anju`  

❌ Invalid entries are rejected with clear error messages.  

---

## 💡 Features  

- Add, search, edit, delete, and list contacts  
- Validates email, phone, and name before saving  
- Stores data in `.csv` file for persistence  
- Prevents duplicate entries (based on email/phone)  
- Clean, modular codebase for easy maintenance  
- Supports hundreds of contacts efficiently  

---

## 🗂️ File Structure  

📁 addressbook/
├── main.c // Program entry & menu interface
├── contact.c // Core contact management logic (CRUD)
├── contact.h // Header for contact operations
├── file.c // File handling: load & save contacts
├── file.h // Header for file operations
├── contacts.csv // Saved contact data (auto-generated)

📸 Project Media Sample Terminal Output

<img width="1390" height="747" alt="Screenshot 2025-10-01 175242" src="https://github.com/user-attachments/assets/ccb85be2-fd4c-477a-81d6-0032b3f9e8e2" />
<img width="1400" height="323" alt="Screenshot 2025-10-01 180235" src="https://github.com/user-attachments/assets/e794fd30-d296-4f26-9c17-6be54b6adee8" />
<img width="1333" height="652" alt="Screenshot 2025-10-01 180801" src="https://github.com/user-attachments/assets/2ec8b7b6-b7e6-4170-b2d5-39b1de0afab3" />

Future Scope

Future Scope

Upgrade from command-line interface to GUI for better usability.

Integrate with databases (MySQL/SQLite) to handle large data efficiently.

Add advanced search and filter options for quick data retrieval.

Introduce contact grouping and tagging for better organization.

Support import/export of contacts in VCF or Excel formats.

Provide cloud synchronization and automated backup for data safety.

Implement encryption and password protection for secure access.

Extend access through mobile and web applications.

Enable integration with communication tools (call, email, messaging).

Add AI-powered features like duplicate detection and auto-fill of details.

Support voice-command based contact search for convenience.

Improve scalability to handle thousands of contacts smoothly.

👩‍💻 Developed By AMRUTHAPURI SRIHARI Graduate Engineer – Embedded Systems Enthusiast 📧 hariamruthapuri@gmail.com


