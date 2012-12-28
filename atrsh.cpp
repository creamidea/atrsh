/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 24, 2012
 * Last Changed: Dec 28, 2012
 * License: GNU General Public License v2.0
 */

#include <iostream>
#include <string>

#include "Commands.hpp"
#include "Execute.hpp"
#include "FileSystemFuncs.hpp"

using namespace std;

int main(int argc, char *argv[]){
    while (true){
        FileSystemFunc fs;
        cout << fs.getCurrDir() << "#";

        Commands cmd;
        cmd.getCmdInput();
        if (cmd.ifExit()){ break; } // exit by command "exit"

        string *cmd_arry = cmd.getCmdArry();
        Execute exe;
        string cmd_path;
        cout << "debug: cmd_path: " << cmd_path << endl; // debug line
        if (exe.ifCmdExist(cmd_arry[0], fs, cmd_path)){ // KNOWN BUG: core dumped here
            cout << "debug: cmd_path: " << cmd_path <<
            exe.executeCmd(cmd_path, cmd_arry) << endl;
            cout << endl;
        } else {
            cout << "Command not Found." << endl;
        }
    }
	return 0;
}
