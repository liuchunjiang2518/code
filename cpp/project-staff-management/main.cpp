#include <iostream>
#include "workerManager.h"

int main() {
    system("chcp 65001 >nul");
    WorkerManager wm;
    
    int choose = 0;
    while (true) {
        wm.Show_Menu();
        std::cin >> choose;
        switch (choose) {
            case 0:
                wm.Exit_System();
                break;
            case 1:
                wm.Insert_Worker();
                break;
            case 2:
                wm.Show_Workers();
                break;
            case 3:
                wm.Delete_Worker();
                break;
            case 4:
                wm.Update_Worker();
                break;
            case 5:
                wm.Search_Worker();
                break;
            case 6:
                wm.Sort_Workers();
                break;
            case 7:
                wm.Clear_Worker();
                break;
            default:
                system("cls");
        }
    }

    return 0;
}