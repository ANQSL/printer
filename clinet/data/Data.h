#ifndef DATA_H
#define DATA_H
#include "stdio.h"
typedef signed char             int8_t;
typedef short int               int16_t;
typedef int                     int32_t;

typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
typedef unsigned int            uint32_t;
class Data
{
private:
    int len;
    char *data;
public:
    Data(char *data,int len);
    Data();
    // Data(const Data &data);
    ~Data();
    int getLen();
    char *getData();
    void setData(char *data,int len);
    void deleteData();
    void updataData(char *data,int len);
};
#endif