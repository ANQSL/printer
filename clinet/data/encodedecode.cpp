#include "encodedecode.h"
#include "malloc.h"
#include "stdio.h"
EncodeDecode::EncodeDecode(/* args */)
{
     frames=(Data *)malloc(sizeof(Data)*MAX_FRAME);
}
EncodeDecode::~EncodeDecode()
{
    
}
void EncodeDecode::strcpy(char *dest,char *src,int len)
{
    for(int i=0;i<len;i++)
    {
        dest[i]=src[i];
    }
}
void EncodeDecode::deleteFrames()
{
    for(int i=0;i<MAX_FRAME;i++)
    {
        if(this->frames[i].getData()!=NULL)
        {
            this->frames[i].deleteData();
        }
    }
}
Data EncodeDecode::encoder(Data data,int type)
{
    int data_len=data.getLen();
    int buffer_len=data_len+5;
    Data buffer;
    char buffer_point[buffer_len+1];//分配帧空间
    //帧头
    buffer_point[0]=char(0xBE);
    //数据类型
    buffer_point[1]=char(type);
    //数据长度
    buffer_point[2]=char(buffer_len>>8);
    buffer_point[3]=char(buffer_len);
    //将数据复制到帧中
    this->strcpy(&buffer_point[4],data.getData(),data_len);
    //帧尾
    buffer_point[buffer_len-1]=char(0xEB);

    buffer.setData(buffer_point,buffer_len);
    return buffer;
}
Data EncodeDecode::decoder(Data buffer,int &type)
{
    //获取帧长
    int buffer_len=buffer.getData()[3]+char(buffer.getData()[2]<<8);
    //获取数据类型
    type=uint8_t(buffer.getData()[1]);
    //获取数据长度
    int data_len=buffer_len-5;
    //分配数据空间
    Data  data;
    char data_point[data_len+1];
    //数据复制
    this->strcpy(data_point,&buffer.getData()[4],data_len);

    
    data.setData(data_point,data_len);
    return data;
}
void EncodeDecode::appendData(char *data,int len)
{
    char *temp_data=this->data.getData();
    char data_point[this->data.getLen()+len+1];
    if(temp_data!=NULL)
    {
        this->strcpy(data_point,temp_data,this->data.getLen());
        this->strcpy(&data_point[this->data.getLen()],data,len);
        this->data.updataData(data_point,this->data.getLen()+len);
    }
    else
    {
        this->strcpy(&data_point[this->data.getLen()],data,len);
        this->data.setData(data_point,this->data.getLen()+len);
    }
}
int  EncodeDecode::getFrameNum()
{
    deleteFrames();
    //初始化帧的数目
    int frame_num=0;
    //获取数据的长度
    int data_len=data.getLen();
    //初始化剩余数据的下标
    int index=0;
    for(int i=0;i<data_len;i++)
    {
        char *data=this->data.getData();
        if(data[i]==char(0xBE))
        {
            int buffer_len=(data[i+2]<<8)+data[i+3];
            if(data[buffer_len-1]==char(0xEB)&&(data_len-i)>=buffer_len)
            {
                //获取一帧数据
                char data_point[buffer_len+1];
                this->strcpy(data_point,&data[i],buffer_len);
                //帧数目+1
                frames[frame_num].setData(data_point,buffer_len);
                frame_num++;
                //数据下标移动到下一帧开始
                i=i+buffer_len-1;
                
            }
            else if((data_len-i)<buffer_len)
            {
                //设置剩余数据的下标
                index=i;
                //数据空间更新
                char *temp_data=this->data.getData();
                char data_point[data_len-i+1];
                this->strcpy(data_point,&temp_data[i],data_len-i);
                this->data.updataData(data_point,data_len-i);
                break;
            }
        }
    }
    return frame_num;
}
Data *EncodeDecode::getFrames()
{
    return this->frames;
}