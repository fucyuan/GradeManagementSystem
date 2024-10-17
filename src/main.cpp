#include "student_system.h"

int main() {
    const string filename = "scores.txt";  // 定义成绩文件名

    // 启动时加载已有成绩
    loadScoresFromFile(filename);

    int choice;

    while (true) 
    {
        showMenu();
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                addScore();
                break;
            case 3:
                displayAllScores();
                break;
            case 4: 
            {
                string subject;
                bool flag=true;
                cout << "请输入要查询的科目: ";
                while (flag) {
            cout << "请输入要查询的科目: ";
            cin >> subject;

            if (isValidSubject(subject)) {
            displaySubjectScores(subject);
                flag=false;
            } 
            else {
                cout << "无效的科目。有效科目包括：语文, 数学, 英语, 科学, 体育, 音乐, 美术" << endl;
            }       
            }
            break;  
            }
            case 5:
                saveScoresToFile(filename);
                cout << "退出系统。" << endl;
                return 0;
            default:
                cout << "无效的选择，请重试。" << endl;
        }
    }

    return 0;
}
