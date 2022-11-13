//
// Created by akimfeopentov on 23.10.22.
//

#ifndef UNTITLED2_LOGGER_H
#define UNTITLED2_LOGGER_H
#include "Observer.h"
#include <vector>

class Logger : public Observer {
    std::vector<LogType> m_types;
public:
    Logger(){
        m_types=std::vector<LogType>(0);
    }
    bool logTypeAvailable(const LogType &type) const;
    void addLogType(const LogType &type);
    void copyLogger(Logger *other);
    void deleteLogType(const LogType &type);
    virtual ~Logger() = default;
};


#endif //UNTITLED2_LOGGER_H
