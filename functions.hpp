/* This file is part of atrsh, A shell written in C++
 * By: Allen Zhong (AstroProfundis) <allen@mail.atr.me>
 * File Created: Dec 24, 2012
 * Last Changed: Dec 24, 2012
 * License: GNU General Public License v2.0
 */

#include <direct>
#include <iostream>
#include <string>

using namespace std;

class FileSystemFunc {
public:
	FileSystemFunc(){}

	string getCurrDir();
	string getLastDir();
	void changeDir(string curr_dir, string dest_dir);
private:
	string curr_dir_;
	string last_dir_;
	static string global_PATH;
};
