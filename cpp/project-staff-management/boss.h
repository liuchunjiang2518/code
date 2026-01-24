#pragma once
#include <iostream>
#include <string>
#include "worker.h"

class Boss: public Worker {
public:
    Boss(int s_ID, std::string s_Name, int s_DeptID);

    void showInfo() override;

    std::string getDeptName() override;
};
