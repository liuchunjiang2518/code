#include "manager.h"

Manager::Manager(int s_ID, std::string s_Name, int s_DeptID) {
    ID = s_ID;
    Name = s_Name;
    DeptID = s_DeptID;
}

void Manager::showInfo() {
    std::cout << "职工编号：" << this->getID()
              << "职工姓名：" << this->getName()
              << "岗位名称：" << this->getDeptName()
              << "岗位任务：完成老板任务，下发员工" << std::endl; 
}

std::string Manager::getDeptName() {
    return std::string("经理");
}