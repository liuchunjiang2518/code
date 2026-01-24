#include "workerManager.h"

WorkerManager::WorkerManager() {
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);
    
    if (!ifs.is_open()) {
        this->workerSize = 0;
        this->workerArray = nullptr;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->workerSize = 0;
        this->workerArray = nullptr;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    this->workerSize = this->getWorkerNumber();
    this->workerArray = new Worker*[this->workerSize];
    this->init_WorkerArray();

    ifs.close();
}

void WorkerManager::cls() {
    system("pause");
    system("cls");
}

void WorkerManager::Show_Menu() {
    std::cout << "Welcome Worker Management" << std::endl;
    std::cout << "      0.exit" << std::endl;
    std::cout << "      1.insert" << std::endl;
    std::cout << "      2.show" << std::endl;
    std::cout << "      3.delete" << std::endl;
    std::cout << "      4.update" << std::endl;
    std::cout << "      5.search" << std::endl;
    std::cout << "      6.sort" << std::endl;
    std::cout << "      7.clear" << std::endl;
}

void WorkerManager::Exit_System() {
    std::cout << "欢迎下次使用" << std::endl;
    system("pause");
    exit(0);
}

void WorkerManager::Insert_Worker() {
    std::cout << "输入添加员工数" << std::endl;
    int num;
    std::cin >> num;

    if (num > 0) {
        int newSize = this->workerSize + num;
        Worker** newSpace = new Worker*[newSize];
        if (this->workerArray != nullptr) {
            for (int i = 0; i < this->workerSize; i++) {
                newSpace[i] = workerArray[i];
            }
        }

        for (int i = 0; i < num; i++) {
            int id;
            std::string name;
            int deptID;

            std::cout << "请输入第" << i + 1 << "个新员工编号" << std::endl;
            std::cin >> id;
            std::cout << "请输入第" << i + 1 << "个新员工姓名" << std::endl;
            std::cin >> name;
            std::cout << "请输入第" << i + 1 << "个新员工岗位" << std::endl;
            std::cout << "1.employee" << std::endl;
            std::cout << "2.manager" << std::endl;
            std::cout << "3.boss" << std::endl;
            std::cin >>deptID;

            Worker* worker = nullptr;
            switch(deptID) {
                case 1:
                    worker = new Employee(id, name, deptID);
                    break;
                case 2:
                    worker = new Manager(id, name, deptID);
                    break;
                case 3:
                    worker = new Boss(id, name, deptID);
                    break;
                default:
                    break;
            }

            newSpace[this->workerSize + i] = worker;
        }

        delete[] this->workerArray;
        this->workerArray = newSpace;
        this->workerSize = newSize;

        this->save();
        std::cout << "成功添加" << num << "个新员工" << std::endl;
    } else {
        std::cout << "输入数据有误" << std::endl;
    }

    this->cls();
}

void WorkerManager::Show_Workers() {
    if (this->isFileEmpty) {
        std::cout << "没有员工信息" << std::endl;
        return;
    }

    for (int i = 0; i < this->workerSize; i++) {
        this->workerArray[i]->showInfo();
    }

    this->cls();
}

void WorkerManager::Delete_Worker() {
    std::cout << "输入删除员工ID" << std::endl;
    int id;
    std::cin >> id;
    int idx = this->isWorkerExist(id);
    if (idx != -1) {
        for (int i = idx; i < this->workerSize; i++) {
            this->workerArray[i] = this->workerArray[i + 1];
        }

        this->workerSize--;
        this->save();
        std::cout << "成功删除" << id << "号员工" << std::endl;
    } else {
        std::cout << "员工不存在" << std::endl;
    }

    this->cls();
}

void WorkerManager::Update_Worker() {
    std::cout << "输入更新员工ID" << std::endl;
    int id;
    std::cin >> id;
    int idx = this->isWorkerExist(id);
    if (idx != -1) {
        std::string name;
        int deptID;

        std::cout << "输入更新姓名" << std::endl;
        std::cin >> name;
        std::cout << "输入更新岗位" << std::endl;
        std::cout << "1.employee" << std::endl;
        std::cout << "2.manager" << std::endl;
        std::cout << "3.boss" << std::endl;
        std::cin >> deptID;

        Worker* worker = nullptr;
        switch(deptID) {
            case 1:
                worker = new Employee(id, name, deptID);
                break;
            case 2:
                worker = new Manager(id, name, deptID);
                break;
            case 3:
                worker = new Boss(id, name, deptID);
                break;
            default:
                break;
        }
        
        this->workerArray[idx] = worker;
        this->save();
        std::cout << "成功删除" << id << "号员工" << std::endl;
    } else {
        std::cout << "员工不存在" << std::endl;
    }

    this->cls();
}

void WorkerManager::Search_Worker() {
    if (this->isFileEmpty) {
        std::cout << "存储文件为空" << std::endl;
    } else {
        std::cout << "请输入查找方式" << std::endl;
        std::cout << "1.ID" << std::endl;
        std::cout << "2.Name" << std::endl;
        int choose;
        std::cin >> choose;

        if (choose == 1) {
            std::cout << "输入员工编号" << std::endl;
            int id;
            std::cin >> id;
            int idx = this->isWorkerExist(id);
            if (idx != -1) {
                this->workerArray[idx]->showInfo();
            } else {
                std::cout << "不存在" << id << "号员工" << std::endl;
            }
        } else if (choose == 2) {
            std::cout << "输入员工姓名" << std::endl;
            std::string name;
            std::cin >> name;
            int idx = this->isWorkerExist(name);
            if (idx != -1) {
                this->workerArray[idx]->showInfo();
            } else {
                std::cout << "不存在姓名为" << name << "的员工" << std::endl;
            }
        } else {
            std::cout << "请输入正确查找方式" << std::endl;
        }
    }

    this->cls();
}

void WorkerManager::Sort_Workers() {
    if (this->isFileEmpty) {
        std::cout << "存储文件为空" << std::endl;
    } else {
        std::cout << "请输入排序方式" << std::endl;
        std::cout << "1.ASC" << std::endl;
        std::cout << "2.DESC" << std::endl;
        int choose;
        std::cin >> choose;

        if (choose == 1 || choose == 2) {
            for (int i = 0; i < this->workerSize; i++) {
                int idx = i;
                for (int j = 0; j < this->workerSize; j++) {
                    if (choose == 1) {
                        if (this->workerArray[j] < this->workerArray[idx]) {
                            idx = j;
                        }
                    } else {
                        if (this->workerArray[j] > this->workerArray[idx]) {
                            idx = j;
                        }
                    } 
                }
                if (i != idx) {
                    Worker* temp = this->workerArray[i];
                    this->workerArray[i] = this->workerArray[idx];
                    this->workerArray[idx] = temp;
                }
            }           
        } else {
            std::cout << "请输入正确的排序方式" << std::endl;
        }
    }

    this->cls();
}

void WorkerManager::Clear_Worker() {
    std::cout << "确认清空" << std::endl;
    std::cout << "1.确认" << std::endl;
    std::cout << "2.返回" << std::endl;
    int choose;
    std::cin >> choose;

    if (choose == 1) {
        std::ofstream ofs(FILENAME, std::ios::trunc);
        ofs.close();

        if (this->workerArray != nullptr) {
            for (int i = 0; i < this->workerSize; i++) {
                if (this->workerArray[i] != nullptr) {
                    delete this->workerArray[i];
                }
            }
            this->workerSize = 0;
            delete[] this->workerArray;
            this->workerArray = nullptr;
            this->isFileEmpty = true;
        }

        std::cout << "清空成功" << std::endl;
    }

    this->cls();
}

void WorkerManager::save() {
    std::ofstream ofs;
    ofs.open(FILENAME, std::ios::out);
    for (int i = 0; i < this->workerSize; i++) {
        ofs << this->workerArray[i]->getID() << " "
            << this->workerArray[i]->getName() << " "
            << this->workerArray[i]->getDeptName() << std::endl;
    }
    ofs.close();
}

int WorkerManager::getWorkerNumber() {
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);

    int id;
    std::string name;
    int deptID;

    int num = 0;

    while (ifs >> id  && ifs >> name && ifs >> deptID) {
        num++;
    }

    ifs.close();

    return num;
}

void WorkerManager::init_WorkerArray() {
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);
    
    int id;
    std::string name;
    int deptID;

    int idx = 0;
    while (ifs >> id && ifs >> name && ifs >> deptID) {
        Worker* worker = nullptr;
        if (deptID == 1) {
            worker = new Employee(id, name, deptID);
        } else if (deptID == 2) {
            worker = new Manager(id, name, deptID);
        } else {
            worker = new Boss(id, name, deptID);
        }
        this->workerArray[idx++] = worker;
    }

    ifs.close();
}

int WorkerManager::isWorkerExist(int id) {
    int idx = -1;

    for (int i = 0; i < this->workerSize; i++) {
        if (this->workerArray[i]->getID() == id) {
            idx = i;
            break;
        }
    }

    return idx;
}

int WorkerManager::isWorkerExist(std::string name) {
    int idx = -1;

    for (int i = 0; i < this->workerSize; i++) {
        if (this->workerArray[i]->getName() == name) {
            idx = i;
            break;
        }
    }

    return idx;
}

WorkerManager::~WorkerManager() {
    if (this->workerArray != nullptr) {
        for (int i = 0; i < this->workerSize; i++) {
            if (this->workerArray[i] != nullptr) {
                delete this->workerArray[i];
            }
        }
        this->workerSize = 0;
        delete[] this->workerArray;
        this->workerArray = nullptr;
        this->isFileEmpty = true;
    }
}