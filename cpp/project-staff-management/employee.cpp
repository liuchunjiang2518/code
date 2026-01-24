#include "employee.h"

Employee::Employee(int s_ID, std::string s_Name, int s_DeptID) {
    ID = s_ID;
    Name = s_Name;
    DeptID = s_DeptID;
}

void Employee::showInfo() {
    std::cout << "职工编号：" << this->getID()
              << "职工姓名：" << this->getName()
              << "岗位名称：" << this->getDeptName()
              << "岗位任务：完成经理安排任务" << std::endl; 
}

std::string Employee::getDeptName() {
    return std::string("员工");
}