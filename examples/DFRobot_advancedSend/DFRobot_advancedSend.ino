/*
  DFRobot_advancedSend

 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 *function:
 The IOT device sends a message when the key is pressed
 We can convert the integer number to a string and send it out through the IOT device

 created 2017/3/6
 by Jason
 */
 
#include <SoftwareSerial.h>
#include "Iot.h"

void * eventCb(uint8_t type, const char *data, uint16_t len);
Iot iot(eventCb);                          //当物联网既需要接收数据有需要发送数据的时候，需要传入回调函数

SoftwareSerial mySerial(10, 11);         // RX, TX

#define WIFI_SSID       "DFSoftware"       //wifi名称
#define WIFI_PASSWD     "dfrobotsoftware"  //wifi密码
#define IOT_USERNAME    "test"             //物联网账号
#define IOT_PASSWD      "test"             //物联网账号密码

char *tempString =      "string";
int normalVoltage = 0;                     //按键防抖动的相关参数
bool isPress = false;
bool isClick = false;;
bool hasPress = false;
int  buttonPin = 2;
bool currentState = false;
unsigned long currentTime = 0;
bool sendFlag  = true;

//连接状态回调函数
void * eventCb(uint8_t eventType, const char *data, uint16_t len)
{
}

void setup(void)
{
  mySerial.begin(38400);                   //打开软串口，波特率必须是38400
  pinMode(buttonPin,INPUT);
  iot.setup(mySerial, WIFI_SSID, WIFI_PASSWD, IOT_USERNAME, IOT_PASSWD);
  iot.start();
}
 
void loop(void)
{
  keyScan();
  if(isClick)
  {
    if(sendFlag){
      itoa(1,tempString,10);                //将整型转换成字符串，然后再发送
      iot.publish("key1", tempString);
      sendFlag = false;
    }
    else{
      iot.publish("key1", "0");             //直接发送字符串0也可以
      sendFlag = true;
    }    
  }
 iot.loop();
}

//按键扫描
void keyScan()
{
   if((digitalRead(buttonPin)!=normalVoltage)&&!isPress)
    {
        isPress = true;
        currentTime = millis();
    }
    else if (isPress)
    {
        if (millis()-currentTime>=10)
        {
            if(digitalRead(buttonPin)!=normalVoltage)
            {
                currentState = true;
            }
            else
            {
                currentState = false;
                isPress = false;
            }
        }
    }
    isClick = false;
    if (currentState) {
        hasPress = true;
    }
    else if(hasPress) {
        isClick = true;
        hasPress = false;
    }
}

