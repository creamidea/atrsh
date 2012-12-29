/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 28, 2012
 * Last Changed: Dec 28, 2012
 * License: GNU General Public License v2.0
 */

#ifndef _EXECUTE_HPP_
#define _EXECUTE_HPP_

#include <iostream>
#include <string>

#include "FileSystemFuncs.hpp"

using namespace std;

class Execute {
public:
    Execute(){}

    bool ifCmdExist(string cmd, FileSystemFunc &fs, string &cmd_path);
    void executeCmd(string cmd_path, string cmd_argv[]);
private:

};


#endif // _EXECUTE_HPP_
