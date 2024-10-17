#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    // 构造函数
    Student(string n, int i);
    
    // 添加科目和成绩
    void addScore(string subject, double score);

    // 获取总成绩
    double getTotalScore();

    // 获取平均成绩
    double getAverageScore();

    // 打印成绩信息
    void printScores();

    // 学生姓名和学号
    string name;
    int id;
   // 获取成绩信息，返回一个 const reference
    const vector<pair<string, double>>& getScores() const;
    

private:
    // 科目和成绩对
    vector<pair<string, double>> scores;
};

#endif
