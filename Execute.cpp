/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 28, 2012
 * Last Changed: Dec 29, 2012
 * License: GNU General Public License v2.0
 */

#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
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

void Execute::executeCmd(string cmd_path, string cmd_argv[]){
    char *c_cmd_argv[32], *c_cmd_path;
    cmd_path += "/" + cmd_argv[0];
    c_cmd_path = new char[cmd_path.size() + 1];
    strcpy(c_cmd_path, cmd_path.c_str());
    int i;

    c_cmd_argv[0] = new char[sizeof(c_cmd_path) + 1];
    strcpy(c_cmd_argv[0], c_cmd_path);
    for (i = 1; !cmd_argv[i].empty(); ++i){
        c_cmd_argv[i] = new char[cmd_argv[i].size() + 1];
        strcpy(c_cmd_argv[i - 1], cmd_argv[i].c_str());
    }

    cout << "Now Executing: " << c_cmd_path << endl;

    pid_t pid = fork();
    if (pid < 0){ // KNOWN BUG: threads messed up
        cout << "error" << endl;
        return;
    } else if (pid == 0) {
        execvp(c_cmd_argv[0], c_cmd_argv);
        cout << "#"; // KNOWN BUG: this line is not executed
        kill(pid, SIGTERM);
    } else {
        ;
    }
    //execvp(c_cmd_argv[0], c_cmd_argv);
}
