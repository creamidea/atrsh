/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 27, 2012
 * Last Changed: Dec 27, 2012
 * License: GNU General Public License v2.0
 */

#include <iostream>
#include <string>
#include <vector>

#include "Commands.hpp"

using namespace std;
/*
bool Commands::Commands(string cmd_argv_input){
    for (int i = 0; cmd_argv_input[i] != NULL; ++i){
        cmd_arg[i] = cmd_argv_input[i];
    }
    cmd_line = cmd_arg[0];
    for (int i = 1; cmd_arg[i] != NULL; ++i){
        cmd_line += " ";        // a space
        cmd_line += cmd_arg[i];
    }
}
*/
void Commands::getCmdInput(){
    // POSSIBLE BUG: cmd_split_pattern is not initialed with a space
    string cmd_input(""), cmd_split_pattern(" "); // cmd arguements are splited by spaces
    string::size_type cmd_space_pos;          // postion of spaces
    vector<string> cmd_result;

    cin >> cmd_input;
    cmd_input += cmd_split_pattern;
    int cmd_size = cmd_input.size();

    for (int i = 0; i < cmd_size; ++i){
        cmd_space_pos = cmd_input.find(cmd_split_pattern, i);
        if (cmd_space_pos < cmd_size){
            string str = cmd_input.substr(i, cmd_space_pos - i);
            cmd_result.push_back(str);
            i = cmd_space_pos + cmd_split_pattern.size() - 1;
        }
    }

    for (int i = 0; i < cmd_result.size(); ++i){
        cmd_arg[i] = cmd_result[i];
    }
    formatCmd2Line();
}

bool Commands::ifExit(){
    return (cmd_arg[0] == "exit");
}

string Commands::formatCmd2Line(){
    cmd_line = cmd_arg[0];
    for (int i = 1; !cmd_arg[i].empty(); ++i){
        cmd_line += cmd_arg[i];
    }
}
