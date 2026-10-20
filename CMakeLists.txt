cmake_minimum_required(VERSION 3.21)
project(BankingAppSmall VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 6.4 REQUIRED COMPONENTS Quick QuickControls2 Test)
qt_standard_project_setup(REQUIRES 6.4)

qt_add_executable(BankingApp
    src/main.cpp
    src/BankingController.h
    src/BankingController.cpp
)
qt_add_qml_module(BankingApp
    URI BankingApp
    VERSION 1.0
    QML_FILES
        ui/Main.qml
        ui/LoginPage.qml
        ui/DashboardPage.qml
)
target_include_directories(BankingApp PRIVATE src)
target_link_libraries(BankingApp PRIVATE Qt6::Quick Qt6::QuickControls2)

enable_testing()
qt_add_executable(tst_banking
    tests/tst_banking.cpp
    src/BankingController.h
    src/BankingController.cpp
)
target_include_directories(tst_banking PRIVATE src)
target_link_libraries(tst_banking PRIVATE Qt6::Quick Qt6::Test)
add_test(NAME banking_tests COMMAND tst_banking)
