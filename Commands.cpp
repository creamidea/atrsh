/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 27, 2012
 * Last Changed: Jan 06, 2013
 * License: GNU General Public License v2.0
 */

#include <iostream>
#include <string>
#include <vector>

#include "Commands.hpp"

using namespace std;

void Commands::getCmdInput(){
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
}

bool Commands::ifExit(){
    return (cmd_arg[0] == "exit");
}
