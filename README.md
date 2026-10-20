# BankingApp Small — Qt Quick/QML + C++

## Included
- Demo login screen
- Dashboard with account balance
- Deposit and withdrawal actions
- Basic validation and insufficient-funds protection
- C++ controller exposed to QML
- Qt Test tests for login and money operations

## Safety
This is a learning/portfolio demo only. It is not connected to a bank and does not move real money. The demo credentials are hard-coded for simplicity. Do not use real passwords or financial data.

## Build with Qt Creator
1. Extract this ZIP.
2. Open `CMakeLists.txt` in Qt Creator.
3. Select a Qt 6 kit.
4. Configure, build, and run `BankingApp`.

## Build from PowerShell
Adjust `CMAKE_PREFIX_PATH` to match your installed Qt version and kit:
```powershell
cmake -S . -B build -DCMAKE_PREFIX_PATH="C:/Qt/6.8.0/msvc2022_64"
cmake --build build --config Debug
```

## Run tests
```powershell
ctest --test-dir build --output-on-failure
```

## Demo login
- Username: `demo`
- Password: `demo123`

## Folder structure
```text
BankingApp_Small/
├── CMakeLists.txt
├── README.md
├── docs/architecture.md
├── src/
│   ├── main.cpp
│   ├── BankingController.h
│   └── BankingController.cpp
├── ui/
│   ├── Main.qml
│   ├── LoginPage.qml
│   └── DashboardPage.qml
└── tests/tst_banking.cpp
```
