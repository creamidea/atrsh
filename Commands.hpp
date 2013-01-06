/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 27, 2012
 * Last Changed: Jan 06, 2013
 * License: GNU General Public License v2.0
 */

#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include <string>

using namespace std;

class Commands{
public:
    Commands(){ for (int i = 0; i < 32; ++i){ cmd_arg[i] = ""; } }

    string *getCmdArry(){ return cmd_arg; }
    bool ifExit();
    void getCmdInput();
private:
    string cmd_arg[32]; // every argument in a line, 32 arguments in max
};

#endif // _COMMANDS_HPP_
