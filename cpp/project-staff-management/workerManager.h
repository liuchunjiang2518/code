#pragma once
#include <iostream>
#include <fstream>
#define FILENAME "workerFile.txt"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

class WorkerManager {
public:
    WorkerManager();

    void Show_Menu();

    void Exit_System();

    void Insert_Worker();

    void Show_Workers();

    void Delete_Worker();

    void Update_Worker();

    void Search_Worker();

    void Sort_Workers();

    void Clear_Worker();

    ~WorkerManager();

private:
    int workerSize;
    Worker** workerArray;
    bool isFileEmpty;

    void cls();

    void save();

    int getWorkerSize();

    void init_WorkerArray();

    int isWorkerExist(int id);

    int isWorkerExist(std::string name);

    void updateFileEmptyStatus();
};