//
// Created by Abigail Animah Owusu on 27/11/2022.
//

#ifndef C___PROJECT_HELPER_FUNCTIONS_H
#define C___PROJECT_HELPER_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include<vector>
#include<regex>

using namespace std;

vector<string> split(string s, regex re);
vector<vector<std::string> > file_reader(string file_path);
#endif //C___PROJECT_HELPER_FUNCTIONS_H
