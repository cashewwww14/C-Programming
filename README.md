# Simple e-KTP Database in C++

This is a simple console-based application written in C++ that simulates a basic **e-KTP (Electronic Identity Card)** database system. It allows users to **add**, **display**, **delete**, and **update** citizen data stored in a binary file (`data.dat`).

## Features

* Add new citizen data (NIK, name, etc.)
* Display all stored data
* Delete specific data based on record number
* Update existing data based on NIK
* Data is persistently stored in a binary file (`data.dat`)

## 📁 File Structure

```
.
├── main.cpp          # Main menu logic
├── typa.cpp            # Type definitions (e.g., struct for citizen data)
└── datas.cpp         # Implementation of inputData, displayData, etc.
```

## ▶ How to Run

1. **Compile the project**
   Use a C++ compiler like `g++`:

   ```bash
   g++ main.cpp datas.cpp file.c -o ektp
   ```

2. **Run the executable**

   ```bash
   ./ektp
   ```

3. **Follow the menu in the terminal:**

   ```
   1. Input data
   2. Tampilkan data
   3. Hapus data
   4. Ubah data
   0. Keluar
   ```

## Notes

* Make sure to define the **`initializeFile()`**, **`inputData()`**, **`displayData()`**, **`deleteData()`**, and **`updateData()`** functions properly in `datas.cpp` or `file.c`.
* This project uses **binary file I/O** for simplicity and data persistence.
* Ensure that `data.dat` exists or is created using `initializeFile()` before performing other operations.

## Author

Ahmad Zaky Ash Shidqi — Informatics Engineering

Institut Teknologi Sepuluh Nopember (ITS)

---
