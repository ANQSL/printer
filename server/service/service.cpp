#include "service.h"
Service::Service(std::string service_name,void(*service_function)())
{
    this->service_name=service_name;
    this->service_function=service_function;
}
Service::~Service()
{

}
bool Service::starService()
{

}