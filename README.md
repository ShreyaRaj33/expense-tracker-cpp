# 💰 Expense Tracker (C++)

A console-based Expense Tracker application built using C++ that helps users manage income and expenses efficiently with persistent storage.


## 🔥 Features
- ➕ Add income and expense transactions  
- 📜 View all transactions  
- ❌ Delete transactions  
- 📊 Real-time balance calculation  
- 💾 Data saved using file handling  
- 🔄 Automatic data loading on restart  

## 🛠️ Tech Stack & Concepts Used

### 🔹 C++
- Structures (`struct`) for data modeling  
- Vectors (`vector`) for dynamic storage  
- Functions for modular programming  
- Menu-driven program design  

### 🔹 File Handling
- `ifstream` for reading data  
- `ofstream` for writing data  
- Persistent storage using `data.txt`  

### 🔹 Programming Concepts
- Loops (`for`, `do-while`)  
- Conditional statements (`if-else`, `switch`)  
- Basic input/output handling  


## 📊 How It Works
- User selects options from a menu  
- Adds transactions with description and amount  
- Positive amount → Income  
- Negative amount → Expense  
- Data is saved to a file and loaded automatically  


## 🚀 How to Run

1. Compile the program:
```bash
g++ -o main main.cpp
