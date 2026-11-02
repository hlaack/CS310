cmake_minimum_required(VERSION 4.3)
project(Week_9)

set(CMAKE_CXX_STANDARD 26)

add_executable(Week_9 Ch10Exercise21.cpp
        BankAccount.cpp
        BankAccount.h
        CheckingAccount.cpp
        CheckingAccount.h
        SavingsAccount.cpp
        SavingsAccount.h)
