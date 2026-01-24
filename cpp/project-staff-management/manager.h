#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Manager: public Worker {
public:
    Manager(int s_ID, std::string s_Name, int s_DeptID);

    void showInfo() override;

    std::string getDeptName() override;
};