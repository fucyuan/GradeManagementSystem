#include "student_system.h"
#include "Student.h"
using namespace std;

// 全局变量
 vector<Student> students;

// 根据学号查找学生
Student* findStudentById(int id) {
    for (auto& student : students) {
        if (student.id == id) {
            return &student;
        }
    }
    return nullptr;
}



// 检查学号是否重复
bool isIdDuplicate(int id) {
    for (const auto& student : students) {
        if (student.id == id) {
            return true;
        }
    }
    return false;
}

// 添加学生，包含输入错误检查
void addStudent() {
    string name;
    int id;

    // 输入并检查姓名是否合法
    while (true) {
        cout << "请输入学生姓名: ";
        cin >> name;
        
        if (name.empty()) {
            cout << "姓名不能为空，请重新输入。" << endl;
        } else {
            break;
        }
    }

    // 输入并检查学号是否合法
    while (true) {
        cout << "请输入学生学号: ";
        cin >> id;

        // 检查输入是否为整数，以及学号是否重复
        if (cin.fail()) {
            cin.clear();  // 清除错误状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃无效输入
            cout << "无效输入，请输入正确的整数学号。" << endl;
        } else if (isIdDuplicate(id)) {
            cout << "学号已存在，请输入一个不同的学号。" << endl;
        } else {
            break;
        }
    }

    // 添加学生
    students.push_back(Student(name, id));
    cout << "学生 " << name << " 已成功添加。" << endl;
}


// 预定义小学科目
const set<string> validSubjects = {"语文", "数学", "英语", "科学", "体育", "音乐", "美术"};

// 检查输入的科目是否合法
bool isValidSubject(const string& subject) {
    return validSubjects.find(subject) != validSubjects.end();
}

// 添加成绩，包含输入错误检查
void addScore() {
    int id;
    // 输入学号并检查合法性
    while (true) {
        cout << "请输入学生学号: ";
        cin >> id;

        // 检查输入是否为有效的整数
        if (cin.fail()) {
            cin.clear();  // 清除输入错误
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃错误输入
            cout << "无效输入，请输入数字学号。" << endl;
        } else if (id < 0) {
            cout << "学号不能为负数，请重新输入。" << endl;
        } else {
            break;  // 学号合法，退出循环
        }
    }

    Student* student = findStudentById(id);
    if (student) {
        string subject;
        double score;

        // 检查科目是否合法
        while (true) {
            cout << "请输入科目: ";
            cin >> subject;

            if (isValidSubject(subject)) {
                break;
            } else {
                cout << "无效的科目。有效科目包括：语文, 数学, 英语, 科学, 体育, 音乐, 美术" << endl;
            }
        }

        // 检查成绩是否在 0 到 100 之间
        while (true) {
            cout << "请输入该科目的成绩: ";
            cin >> score;

            if (cin.fail()) {
                cin.clear();  // 清除输入错误
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢弃错误输入
                cout << "无效的输入，请输入一个数字。" << endl;
            } else if (score < 0 || score > 100) {
                cout << "成绩必须在 0 到 100 之间，请重新输入。" << endl;
            } else {
                break;  // 成绩合法，退出循环
            }
        }

        // 添加成绩
        student->addScore(subject, score);
        cout << "成绩已成功添加。" << endl;
    } else {
        cout << "未找到该学号的学生。" << endl;
    }
}


// 显示所有学生的成绩，并按总成绩从高到低排序
void displayAllScores() {
    // 使用 lambda 表达式对 students 向量按总成绩排序
    std::sort(students.begin(), students.end(), []( Student& a,  Student& b) {
        return a.getAverageScore() > b.getAverageScore();  // 从高到低排序
    });

    // 输出排序后的成绩
    for (auto& student : students) {
        student.printScores();
        cout << "------------------" << endl;
    }
}


void showMenu() {
    cout << "成绩管理系统菜单" << endl;
    cout << "1. 添加学生" << endl;
    cout << "2. 添加成绩" << endl;
    cout << "3. 显示所有学生成绩" << endl;
    cout << "4. 按科目展示所有学生成绩" << endl;
    cout << "5. 保存并退出系统" << endl;
}



// 从文件导入成绩
void loadScoresFromFile(const string& filename) {
    ifstream inFile(filename);
    
    if (!inFile) {
        cout << "无法打开文件: " << filename << endl;
        return;
    }

    string name, subject;
    int id;
    double score;
    
    while (inFile >> name >> id) {
        Student student(name, id);

        int numSubjects;
        inFile >> numSubjects;  // 读取该学生有多少科目

        for (int i = 0; i < numSubjects; ++i) {
            inFile >> subject >> score;
            student.addScore(subject, score);
        }

        students.push_back(student);
    }

    inFile.close();
    cout << "成绩已成功导入。" << endl;
}

// 将成绩导出到文件
void saveScoresToFile(const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "无法打开文件: " << filename << endl;
        return;
    }

    for (const auto& student : students) {
        outFile << student.name << " " << student.id << endl;
        const auto& scores = student.getScores();  // 获取成绩信息
        outFile << scores.size() << endl;  // 输出科目数量
        for (const auto& score : scores) {
            outFile << score.first << " " << score.second << endl;  // 输出科目名称和分数
        }
    }

    outFile.close();
    cout << "成绩已成功保存。" << endl;
}

// 按科目展示所有学生的成绩
void displaySubjectScores(const string& subject) {
    cout << "展示所有学生在科目 " << subject << " 上的成绩：" << endl;

    bool found = false;  // 用于检查是否有学生有该科目的成绩
    for (const auto& student : students) {
        const auto& scores = student.getScores();
        for (const auto& score : scores) {
            if (score.first == subject) {
                cout << "学生: " << student.name << ", 学号: " << student.id << ", 成绩: " << score.second << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "没有找到任何学生的 " << subject << " 成绩。" << endl;
    }
}