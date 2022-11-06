#ifndef SERVICE_H
#define SERVICE_H
#include "string"
#include "String"
#include "windows.h"
class Service
{
private:
    //服务名字
    std::string service_name;
    //
    void (*service_function)();
public:
    Service(std::string service_name,void(*service_function)());
    ~Service();
    bool starService();
};
#endif