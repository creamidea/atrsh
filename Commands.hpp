/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 27, 2012
 * Last Changed: Dec 27, 2012
 * License: GNU General Public License v2.0
 */

#ifndef _COMMANDS_HPP_
#define _COMMANDS_HPP_

#include <string>

using namespace std;

class Commands{
public:
    Commands(){ cmd_arg[0] = ""; }
    //Commands(string cmd_argv_input);

    string *getCmdArry(){ return cmd_arg; }
    bool ifExit();
    void getCmdInput();
private:
    string cmd_arg[32]; // every argument in a line, 32 in max
    string cmd_line;    // the full cmd in one string
    string formatCmd2Line();
};

#endif // _COMMANDS_HPP_
