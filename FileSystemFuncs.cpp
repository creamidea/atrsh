/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 27, 2012
 * Last Changed: Dec 27, 2012
 * License: GNU General Public License v2.0
 */

#include <unistd.h>

#include <stdlib.h>
#include <string>
#include <vector>

#include "FileSystemFuncs.hpp"

using namespace std;

void FileSystemFunc::setGlobalPATHArry(){
    string str_PATH;
    string::size_type pos;  // position of ':'s
    vector<string> result;  // splited PATH
    string pattern = ":";   // PATH is splited by ':'

    str_PATH = getenv("PATH");
    str_PATH += pattern;
    int size = str_PATH.size();

    int i = 0;
    for (i = 0; i < size; ++i){
        pos = str_PATH.find(pattern, i);
        if (pos < size){
            string str = str_PATH.substr(i, pos - i);
            result.push_back(str);
            i = pos + pattern.size() - 1;
        }
    }

    for (i = 0; i < result.size(); ++i){
        global_PATH[i] = result[i];
        //cout << result[i] << endl;
    }
    path_count_ = i - 1;
}

string FileSystemFunc::getCurrWorkingDir(){
    char c_buffer[128];
    getcwd(c_buffer, sizeof(c_buffer));
    string result(c_buffer);
    return result;
}

void FileSystemFunc::changeDir(string source_dir, string dest_dir){
    last_dir_ = source_dir;
    curr_dir_ = dest_dir;
}
