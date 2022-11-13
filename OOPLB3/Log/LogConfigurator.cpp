//
// Created by akimfeopentov on 31.10.22.
//

#include "LogConfigurator.h"

LogConfigurator::LogConfigurator(Level *cont) : level(cont) {}

void LogConfigurator::configure() {
    char choice = ' ';
    std::cout << "Добавить Console, нажмите 1\n";
    std::cout << "Добавить File, нажмите 2\n";
    std::cout << "Добавить в File и в Console, нажмите 3\n";
    std::cout << "Ничего не добавлять, нажмите 0\n";
    std::cin >> choice;
    std::cin.ignore(1251, '\n');
    while (choice<'0' || choice>'3') {
        std::cout << "Ошибка ввода, повторите ввод \n";
        std::cin >> choice;
        std::cin.ignore(1251, '\n');
    }
    if (choice == '1'|| choice == '2') {
        if(choice == '1'){
            std::cout << "Логи выводятся в консоли \n";
            Logger* loggerC = new ConsoleLogger;
            configureLevels(loggerC);
            level->subscribe(loggerC);
            LoggerPool::getInstance().addLogger(loggerC);
        }
        else{
            std::cout << "Логи записываются в файл log.txt \n";
            Logger* loggerF = new FileLogger("log.txt");
            configureLevels(loggerF);
            level->subscribe(loggerF);
            LoggerPool::getInstance().addLogger(loggerF);
        }
    } else if (choice == '3') {
        std::cout << "Логи выводятся в консоль и в файл \n";
        Logger* loggerC = new ConsoleLogger;
        configureLevels(loggerC);
        level->subscribe(loggerC);
        Logger* loggerF = new FileLogger("log.txt");
        loggerF->copyLogger(loggerC);
        level->subscribe(loggerF);
        LoggerPool::getInstance().addLogger(loggerC);
        LoggerPool::getInstance().addLogger(loggerF);
    }

}

void LogConfigurator::configureLevels(Logger *logger) {
    char cur = ' ';
    while (cur != '0') {
        if (!logger->logTypeAvailable(LogType::ObjectState))
            std::cout << "Хотите подписать ObjectState нажмите 1\n";
        if (!logger->logTypeAvailable(LogType::GameState))
            std::cout << "Хотите подписать GameState нажмите 2\n";
        if (!logger->logTypeAvailable(LogType::CriticalState))
            std::cout << "Хотите подписать CriticalState нажмите 3\n";
        std::cout << "Оставить так и выйти из подписи уровней, нажмите 0\n";
        std::cin >> cur;
        std::cin.ignore(1251, '\n');
        switch (cur) {
            case '0':
                break;
            case '1':
                logger->addLogType(LogType::ObjectState);
                std::cout << "Подписаны логи уровня ObjectState\n";
                break;
            case '2':
                logger->addLogType(LogType::GameState);
                std::cout << "Подписаны логи уровня GameState\n";
                break;
            case '3':
                logger->addLogType(LogType::CriticalState);
                std::cout << "Подписаны логи уровня CriticalState\n";
                break;
            default:
                std::cout << "Ошибка ввода\n";
        }
    }

}
