/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 24, 2012
 * Last Changed: Dec 28, 2012
 * License: GNU General Public License v2.0
 */

#ifndef _FILESYSTEMFUNCS_HPP_
#define _FILESYSTEMFUNCS_HPP_

#include <iostream>
#include <string>

using namespace std;

class FileSystemFunc {
public:
	FileSystemFunc(){
        curr_dir_ = getCurrWorkingDir();
        last_dir_ = "";
        setGlobalPATHArry();
	}

	string getCurrDir(){ return curr_dir_; }
	string getLastDir(){ return last_dir_; }
	void changeDir(string source_dir, string dest_dir);
	string getPATHByIndex(int index){ return global_PATH[index]; }
	int getPATHCount(){ return path_count_; }
private:
	string curr_dir_;
	string last_dir_;
	string global_PATH[64]; // every single path in a line, 64 different path max
	int path_count_;
	void setGlobalPATHArry();
	string getCurrWorkingDir();
};

#endif // _FILESYSTEMFUNCS_HPP_
