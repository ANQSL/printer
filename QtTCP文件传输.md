## QtTCP传输文件

### 第一步

1.传输文件名

2.传输文件大小

### 第二步

1.传输文件数据

2.边传输边保存

#### 协议

文件信息帧

| 帧头    | 文件名 | 帧尾    |
| ----- | --- | ----- |
| BE EB |     | EB BE |

数据帧：文件数据

文件传输结束信号：0xBE 0xEB 0xEB 0xBE

服务端：

文件开始发送信号：0xEB  0xBE 

打印功能：

通过window的shellexcuteEx的api来实现

#### 工作流程：

![](C:\Users\20291\AppData\Roaming\marktext\images\2022-10-14-12-35-35-image.png)

客户端：在连接服务器后，等待服务器发送传输文件的信号，并且将文件传输完毕后自动断开。

服务端：当socke队列不为空时，将socket入队，否则直接设scoket为当前客户端。当检测客户断开连接后，直接socket出队。
