#pragma once
#include <string>
#include <iostream>

class Employee;
class Manager;
class Boss;

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
    virtual void setName(std::string name) {
        this->Name = name;
    }
    virtual void setDeptID(int deptID) {
        this->DeptID = deptID;
    }
    virtual ~Worker() = default;

protected:
    int ID;
    std::string Name;
    int DeptID;
};