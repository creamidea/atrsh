/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 24, 2012
 * Last Changed: Dec 29, 2012
 * License: GNU General Public License v2.0
 */

#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include "Commands.hpp"
#include "Execute.hpp"
#include "FileSystemFuncs.hpp"

using namespace std;

int main(int argc, char *argv[]){
    cout << "#";
    while (true){
        FileSystemFunc fs;
        //cout << fs.getCurrDir() << "#";

        Commands cmd;
        cmd.getCmdInput();
        if (cmd.ifExit()){ break; } // exit by command "exit"

        string *cmd_arry = cmd.getCmdArry();
        Execute exe;
        string cmd_path;
        if (exe.ifCmdExist(cmd_arry[0], fs, cmd_path)){
                cout << endl;
                exe.executeCmd(cmd_path, cmd_arry);
                cout << endl;
        } else {
            cout << "Command not Found." << endl;
        }
    }
	return 0;
}
