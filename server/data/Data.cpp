#include "Data.h"
#include "malloc.h"
#include "string.h"
Data::Data()
{
    this->data=NULL;
    this->len=0;
}
Data::Data(char *data,int len)
{
    this->data=NULL;
    this->len=0;
    this->setData(data,len);
}
Data::~Data()
{
    
}
int Data::getLen()
{
    return this->len;
}
char *Data::getData()
{
    return this->data;
}
void Data::setData(char *data,int len)
{
    this->data=(char*)malloc(len+1);
    for(int i=0;i<len;i++)
    {
        this->data[i]=data[i];
    }
    this->len=len;
    printf("str长度:%d\n",strlen(this->data));
}
void Data::updataData(char *data,int len)
{
    deleteData();
    setData(data,len);
}
void Data::deleteData()
{
    delete this->data;
    this->data=NULL;
}