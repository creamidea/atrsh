/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 28, 2012
 * Last Changed: Dec 28, 2012
 * License: GNU General Public License v2.0
 */

#include <string.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#include "Execute.hpp"

using namespace std;

bool Execute::ifCmdExist(string cmd, FileSystemFunc &fs, string &cmd_path){
    string curr_dir = fs.getCurrDir();

    fstream cmd_file;
    for (int i = 0; i < fs.getPATHCount(); ++i){ // search the system PATH
        string cmd_fpath_sys = fs.getPATHByIndex(i) + "/" + cmd;
        cmd_file.open(cmd_fpath_sys.c_str(), ios::in);
        if (cmd_file != NULL){
            cmd_path = fs.getPATHByIndex(i);
            cmd_file.close();
            return true;
        } else {
            cmd_file.close();
            continue;
        }
    }
    string cmd_fpath_curr = curr_dir + "/" + cmd;
    cmd_file.open(cmd_fpath_curr.c_str(), ios::in);
    if (cmd_file != NULL){ // search current working directory
        cmd_path = curr_dir;
        cmd_file.close();
        return true;
    }
    cmd_file.close();
    return false;
}

int Execute::executeCmd(string cmd_path, string cmd_argv[]){
    char *c_cmd_argv[33];
    int i;

    for (i = 0; !cmd_argv[i].empty(); ++i){
        //c_cmd_argv[i] = cmd_argv[i].c_str();
        strcpy(c_cmd_argv[i], cmd_argv[i].c_str());

    }
    c_cmd_argv[i] = NULL;

    return execv(cmd_path.c_str(), c_cmd_argv);
}
