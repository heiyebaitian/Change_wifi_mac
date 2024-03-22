#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <esp_wifi.h>



IPAddress local_IP(192,168,1,1);  //  主机地址
IPAddress gateway(192,168,1,1);   //  网关地址
IPAddress subnet(255,255,255,0);  //  子网掩码

const char *ssid = "yourAP";  //  WIFI名称
const char *password = "yourPassword";  //  WIFI密码
const int  channel = 1; //  WIFI信道（1~13）
const int  ssid_hidden = 0;  //  是否隐藏WIFI(0为不隐藏，1为隐藏)
const int  max_connection = 4; //  最大连接数（1~4）

uint8_t newMACAddress[] = {0x32, 0xAE, 0xA4, 0x07, 0x0D, 0x66}; //您需要设置的MAC地址




void setup() {

  Serial.begin(115200); //  初始化串口
  Serial.println();
  Serial.println("程序运行");
  esp_base_mac_addr_set(&newMACAddress[0]); //  在启动AP前将自定义地址装载，此方法需要在调用esp_read_mac()前使用，否则无效！ 
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(local_IP, gateway, subnet); //设置AP地址
  if (!WiFi.softAP(ssid, password,channel,ssid_hidden,max_connection)) {
    log_e("AP创建失败！");
    while(1);
  }
  Serial.print("[OLD] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
  



  

  
  Serial.print("[NEW] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());

}

void loop() {
  // put your main code here, to run repeatedly:

}
