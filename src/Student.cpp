#include "Student.h"

// 构造函数
Student::Student(string n, int i) : name(n), id(i) {}

// 添加科目和成绩
void Student::addScore(string subject, double score) {
    scores.push_back({subject, score});
}

// 获取总成绩
double Student::getTotalScore() {
    double total = 0;
    for (const auto& s : scores) {
        total += s.second;
    }
    return total;
}

// 获取平均成绩
double Student::getAverageScore() {
    if (scores.empty()) return 0;
    return getTotalScore() / scores.size();
}

// 打印学生成绩信息
void Student::printScores()  {
    cout << "学生姓名: " << name << ", 学号: " << id << endl;
    for (const auto& s : scores) {
        cout << "科目: " << s.first << ", 成绩: " << s.second << endl;
    }
    cout << "总成绩: " << getTotalScore() << ", 平均成绩: " << getAverageScore() << endl;
}
// 获取成绩信息，返回 const reference
const vector<pair<string, double>>& Student::getScores() const {
    return scores;
}