//
// Created by akimfeopentov on 04.11.22.
//

#ifndef UNTITLED2_COMMANDFILE_H
#define UNTITLED2_COMMANDFILE_H
#include "CommandMap.h"
#include <vector>
#include <fstream>

class CommandFile: public CommandMap{
    std::ifstream file;
    std::map<std::string,CommandType> strType;
    std::map<std::string,CommandType> mapLocal;
public:
    CommandFile(const std::string &nameFile);
    bool get_map(std::map<std::string ,CommandType> &map);
    void checkString(std::string str);
    void delete_space(std::string &str);
    ~CommandFile();
};


#endif //UNTITLED2_COMMANDFILE_H
