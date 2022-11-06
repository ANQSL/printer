#ifndef ENCODEDECODE_H
#define ENCODEDECODE_H
//帧的最大数目
#define MAX_FRAME 10
#include "Data.h"
class EncodeDecode
{
private:
    Data data;//数据
    void strcpy(char *dest,char *src,int len);
    void deleteFrames();
public:
    EncodeDecode(/* args */);
    ~EncodeDecode();
    //编码器
    Data encoder(Data data,int type);
    //解码器
    Data decoder(Data buffer,int &type);
    // //数据的插入
    void appendData(char *data,int len);
    // //获取data中有多少帧
    int  getFrameNum();
    //计算数据长度
    Data *frames;
    Data *getFrames();
};
#endif