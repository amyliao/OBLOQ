# OBLOQ常见问题

**注意事项：**

1.  OBLOQ模块正负极不要接反。
2.  OBLOQ模块Rx,Tx引脚连接方式：OBLOQ模块的Rx连接Arduino UNO的Tx，OBLOQ模块的Tx连接Arduino UNO的Rx。
3.  OBLOQ模块通电后，如果能够正常和物联网通信，那么等待一段时间，板子上的信号灯将显示绿色常亮，表示正常工作。
4.  程序中的wifi账号、密码和物联网账号、密码要书写正确。
5.  程序中的发送和接收的设备名称需要和物联网网站中的保持一致。
6.  物联网网站发送消息给主控板的时候，消息类型选择command(表示主控板接收来自OBLOQ网站的消息)。




**常见问题和解决办法：**



**Q：** **OBLOQ模块通电后，板子的信号灯不亮**

**A：**电源正负极接线有问题，请尝试重新连接正负极。



**Q：OBLOQ模块信号灯一直保持红色常亮**  

**A：**这个问题可能由以下原因导致，请逐一排查：

1. OBLOQ模块Rx,Tx引脚和UNO连线错误。请检查OBLOQ模块的Rx应当连接UNO的Tx，OBLOQ模块的Tx应当连接UNO的Rx。
2. 程序中wifi账号和密码书写错误。请修正wifi账号(SSID)或密码。
3. 网络不稳定。需要重启UNO主控板。
4. wifi断开。请检查wifi网络，并重新打开。



**Q：烧完固件后，OBLOQ模块信号灯保持红色常亮**

**A：**这个问题可能由以下原因导致，请逐一排查：

1. 程序没有正常运行。请重启UNO主控板。
2. 网络不稳定。请检查wifi是否正常。




**Q：OBLOQ模块信号灯一直保持白色常亮**

**A：**wifi能成功连接，可能是网络不稳定，需要重启UNO主控板。



**Q：OBLOQ模块信号灯一直保持黄色常亮**

**A：**这个问题可能由以下原因导致，请逐一排查：

1. 网络不稳定。需要重启UNO主控板。
2. 如果多次重启UNO主控板后依然出现这个情况，表明OBLOQ连接服务器失败。请联系客服人员反馈问题。




**Q：OBLOQ模块指示灯绿色常亮，但物联网网站没有就收到设备发送过来的消息**

**A：**请检查程序中的设备名称和物联网网站的设备名称是否保持一致。如果设备名称不一致，修改程序的设备名称或者物联网网站重新新建一个设备。




**Q：OBLOQ模块指示灯绿色常亮，物联网成功发送了消息，但是接收设备没有反应**

**A：**这个问题可能由以下原因导致，请逐一排查：

1. 发送消息的设备名和接收程序中的设备名称不一致。重新选择需要发送消息的设备或者新建一个设备，设备名和接收程序中的设备名称保持一致。
2. 消息发送类型有问题。将消息发送类型修改成**command**类型(表示物联网发送的消息开发板能够接收到)。

**附：消息类型command和event的区别：**

- command：消息会被转发订阅该主题的设备。
- event: 从设备发出的消息，物联网网站做接收或者转发。




**Q：OBLOQ模块指示灯绿色常亮，所有账号，密码和设备名都正确，但是程序不能按照预期工作**

**A：**请查找并解决客户自己的程序的逻辑漏洞。



