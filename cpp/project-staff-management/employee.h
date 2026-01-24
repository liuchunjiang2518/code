#pragma once
#include <string>
#include <iostream>
#include "worker.h"

class Employee: public Worker {
public:
    Employee(int s_ID, std::string s_Name, int s_DeptID);

    void showInfo() override;

    std::string getDeptName() override;
};