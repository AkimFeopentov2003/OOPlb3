//
// Created by akimfeopentov on 04.11.22.
//
#include <algorithm>
#include "CommandFile.h"

CommandFile::CommandFile(const std::string &nameFile) {
    file.open(nameFile);
    strType.emplace("down",CommandType::DOWN);
    strType.emplace("up",CommandType::UP);
    strType.emplace("left",CommandType::LEFT);
    strType.emplace("right",CommandType::RIGHT);
    strType.emplace("esc",CommandType::ESC);
}

bool CommandFile::get_map(std::map<std::string , CommandType> &map) {
    if (!file.fail()) {
        while (!file.eof()) {
            std::string str;
            std::getline(file, str);
            std::transform(str.begin(), str.end(), str.begin(), tolower);
            delete_space(str);
            checkString(str);
        }
    }
    if (mapLocal.size() == strType.size()) {
        map = mapLocal;
        return true;
    } else {
        map["s"] = CommandType::DOWN;
        map["w"] = CommandType::UP;
        map["a"] = CommandType::LEFT;
        map["d"] = CommandType::RIGHT;
        map["l"] = CommandType::ESC;
        return false;
    }

}

void CommandFile::delete_space(std::string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str.erase(i, 1);
            i--;
        }
    }
}

void CommandFile::checkString(std::string str) {
    auto it = str.find(':');
    if(it && (strType.find(str.substr(0,it))!=strType.end()))
        mapLocal.emplace(str.substr(it+1),strType[str.substr(0,it)]);
    //    std::string sType;
//    sType.reserve(20);
//    int i = 0;
//    for (it ; it != end(str); it++)
//    {
//        if(*it == ':')
//            break;
//        sType+=*it;
//    }
//    if(it!=end(str)){
//        if(strType.find(sType) != strType.end()){
//            std::string sCommand;
//            sCommand.reserve(20);
//            it++;
//            for(it;it!=end(str);it++){
//                sCommand+=*it;
//            }
//            mapLocal.emplace(sCommand,strType[sType]);
//        }
//    }
//    for (i; i < str.size(); i++) {
//        if (str[i] == ':')
//            break;
//        s = s + str[i];
//    }
//    if (i != str.size() - 1) {
//        i++;
//
//        for (int j = 0; j < strType.size(); j++) {
//            if (strType[j] == s && str.size() == strType[j].size() + 2) {
//                if (mapLocal.find(str[i]) == mapLocal.end()) {
//                    switch (j) {
//                        case 0:
//                            mapLocal.insert_or_assign(str[i], CommandType::DOWN);
//                            break;
//                        case 1:
//                            mapLocal.insert_or_assign(str[i], CommandType::UP);
//                            break;
//                        case 2:
//                            mapLocal.insert_or_assign(str[i], CommandType::LEFT);
//                            break;
//                        case 3:
//                            mapLocal.insert_or_assign(str[i], CommandType::RIGHT);
//                            break;
//                        case 4:
//                            mapLocal.insert_or_assign(str[i], CommandType::ESC);
//                            break;
//                    }
//                }
//
//            }
//        }
//    }
}

CommandFile::~CommandFile() {
    file.close();
    mapLocal.clear();
    strType.clear();
}