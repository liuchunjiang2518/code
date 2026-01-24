#pragma once
#include <string>
#include <iostream>
#include "employee.h"
#include "manager.h"
#include "boss.h"

class Worker {
public:
    virtual void showInfo() = 0;
    virtual std::string getDeptName() = 0;
    
    virtual std::string getName() const {
        return Name;
    }
    virtual int getID() const {
        return ID;
    }
    virtual int getDeptID() const {
        return DeptID;
    }
    virtual void updateName(std::string name) {
        this->Name = name;
    }
    virtual void updateDeptID(int deptID) {
        this->DeptID = deptID;
    }

protected:
    int ID;
    std::string Name;
    int DeptID;
};