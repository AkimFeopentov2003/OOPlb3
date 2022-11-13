//
// Created by akimfeopentov on 23.10.22.
//

#include "Logger.h"

void Logger::addLogType(const LogType &type) {
    if (!logTypeAvailable(type))
        m_types.push_back(type);
}

void Logger::deleteLogType(const LogType &type) {
    for (int i = 0; i < m_types.size(); i++)
        if (m_types[i] == type) {
            m_types.erase(m_types.begin() + i);
            return;
        }
}

bool Logger::logTypeAvailable(const LogType &type) const {
    for (const auto &t: m_types)
        if (type == t) return true;
    return false;
}

void Logger::copyLogger(Logger *other) {
    for(LogType log_t : other->m_types)
        m_types.push_back(log_t);
}