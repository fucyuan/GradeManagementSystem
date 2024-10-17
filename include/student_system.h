#ifndef STUDENT_SYSTEM_H
#define STUDENT_SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include <algorithm>  // 包含 std::sort
#include <set>
#include <limits>  // 用于 cin.ignore()
#include <fstream>
// 函数声明
Student* findStudentById(int id);  // 根据学号查找学生
void addStudent();                 // 添加学生
void addScore();                   // 添加成绩
void displayAllScores();           // 显示所有学生成绩
void showMenu();                   // 显示菜单
bool isIdDuplicate(int id);
bool isValidSubject(const string& subject);
void loadScoresFromFile(const string& filename);
void saveScoresToFile(const string& filename);
void displaySubjectScores(const string& subject);  // 按科目展示所有学生的成绩

#endif
