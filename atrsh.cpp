/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 24, 2012
 * Last Changed: Dec 24, 2012
 * License: GNU General Public License v2.0
 */

#include <iostream>
#include <string>

#include "Commands.hpp"
#include "FileSystemFuncs.hpp"

using namespace std;

int main(int argc, char *argv[]){
    while (true){
        FileSystemFunc fs;
        cout << fs.getCurrDir() << "#";

        Commands cmd;
        cmd.getCmdInput();
        if (cmd.ifExit()){ break; } // exit by command "exit"
    }
	return 0;
}
