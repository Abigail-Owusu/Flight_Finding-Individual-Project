//
// Created by Styve Lekane and Abigail Owusu on 27/11/2022.
//
#pragma once
#include "helper_functions.h"

/**
 *
 */
vector<string> split(string s, regex re)
{
    vector<string> line;

    sregex_token_iterator iter(s.begin(), s.end(), re, -1);
    sregex_token_iterator end;

    while (iter != end)
    {
        line.push_back(*iter);
        ++iter;
    }

    return line;
}
/** this function takes in the name of the file and stores each line as a vectors, which are stored in one vector
 * @param file_path is the name of the file or the path
 *@return a vector of vector of strings
 */
vector<vector<std::string> > file_reader(string file_path) {
    vector<vector<string> > allLines;

    ifstream inputStream;

    inputStream.open(file_path);

    string line;
    const string REGEX = ",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)";

    int i = 0;
    getline(inputStream,line);
    while (getline(inputStream,line)){
        vector<string> each_line = split(line,regex(REGEX));
        allLines.push_back(each_line);
    }
    inputStream.close();
    return allLines;
}

