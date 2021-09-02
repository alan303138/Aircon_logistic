#include "IRremote.h"
#include <Timer.h>

// 根據不同板子 IRsend有定好腳位
IRsend irsend;// pin 7 for Arduino Due, pin 9 for Arduino Mega, pin 3 for Arduino UNO
// 傳送訊號用的陣列
unsigned int send_cmd[343] = {0};
String cmd1 = "";//12個
String cmd2 = ""; //16個
String cmd3 = ""; //14個
int cnt = 2;

void mergeFirst(String s){
  //起始訊號
  send_cmd[0] = 8900;
  send_cmd[1] = 4540;
  for(int i=0; i<12; i++){
    dic(s[i]);
  }
}

void mergeSecond(String s){
  //分隔訊號
  send_cmd[cnt++] = 540;
  send_cmd[cnt++] = 7980;
  
  for(int i=0; i<16; i++){
    dic(s[i]);
  }
}

void mergeThird(String s){
  //分隔訊號
  send_cmd[cnt++] = 540;
  send_cmd[cnt++] = 7980;
  
  for(int i=0; i<14; i++){
    dic(s[i]);
  }
  send_cmd[cnt] = 540;
  cnt = 2;
}

void dic(char c){
  switch(c){
    case '0':
//      Serial.println("0000");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '1':
//      Serial.println("1000");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '2':
//      Serial.println("0100");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '3':
//      Serial.println("1100");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '4':
//      Serial.println("0010");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '5':
//      Serial.println("1010");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '6':
//      Serial.println("0110");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '7':
//      Serial.println("1110");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      break;
    case '8':
//      Serial.println("0001");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    case '9':
//      Serial.println("1001");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    case 'a':
//      Serial.println("0101");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    case 'b':
//      Serial.println("1101");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    case 'c':
//      Serial.println("0011");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    case 'd':
//      Serial.println("1011");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    case 'e':
//      Serial.println("0111");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 580;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    case 'f':
//      Serial.println("1111");
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      send_cmd[cnt++] = 540;
      send_cmd[cnt++] = 1720;
      break;
    default:
      Serial.println("Wrong");
      break;
  }
}

unsigned long time_1 = 0;
unsigned long time_2 = 0;
#define interval1 500
#define interval2 1000
boolean flag = false;

void send_signal(){
  flag = true;
  while(flag){
    if(millis() > time_1 + interval1){
      time_1 = millis();
      mergeFirst(cmd1);
      mergeSecond(cmd2);
      mergeThird(cmd3);
//      Serial.println(time_1);
      delay(100);
    }
    if(millis() > time_2 + interval2){
      time_2 = millis();
      irsend.sendRaw(send_cmd, sizeof(send_cmd)/sizeof(send_cmd[0]), 38);
      delay(100);
      Serial.println("ON");
      delay(10);
      digitalWrite(13,!digitalRead(13));
//      Serial.println(time_2);
      flag = false;
      delay(100);
    }
  }
}

unsigned int Power; // 開關
unsigned int Air_volume; // 風量
unsigned int Features; // 功能
unsigned int temperature; // 溫度
String stringTemperature;

String tmp1_1 = "3860";
String tmp1_2 = "0000";
String tmp2 = "08000000000000";
String power_button = "00100000800090"; // 運轉鍵
String Air_volume_button = "00110000800091"; // 風量鍵
String temperature_button = "002000008000a0"; // 溫度鍵
String Function_button = "006000008000e0"; // 功能鍵

unsigned int air_tmp;
boolean power = false;
boolean power_switch = false;

void change2cmd(unsigned int airVolume, unsigned int feature, unsigned int temp, String tmp3){
  if(!power_switch) Power = 0;
  else Power = 1;
  
  if(feature == 4) temp = 8; // 送風時溫度強制改成8(24°C) 且之後只能調強、弱、微風
  
  cmd1 += tmp1_1;
  if(power) cmd1 += String(airVolume + 4);
  else cmd1 += String(airVolume);
  cmd1 += 0;
  cmd1 += String(feature);
  stringTemperature = String(temp, HEX);
  cmd1 += stringTemperature;
  cmd1 += tmp1_2;
  Serial.println(cmd1);
  
  cmd2 += tmp2;
  if(feature == 2){
    if(Air_volume == 1) air_tmp = 3;
    else if(Air_volume == 2) air_tmp = 0;
    else if(Air_volume == 3) air_tmp = 1;
    else if(Air_volume == 0) air_tmp = 2;
    else  Serial.println("cmd2 wrong");
    if(power){
      air_tmp += 4;
      power = false;
    }
  }
  if(feature == 4){
    air_tmp = Air_volume + 4;
    if(power){
      air_tmp -= 4;
      power = false;
    }
  }
  cmd2 += air_tmp;
  stringTemperature = String(temp ^ 8, HEX);
  cmd2 += String(stringTemperature);
  Serial.println(cmd2);
  
  cmd3 += tmp3;
  Serial.println(cmd3);
}

Timer timerChcekACState, timerCheckInst;

void checkInst(){
  String cmd = get_Seiral1_response();
  if(cmd != ""){
    Serial.println(cmd);
    if (cmd.substring(0,17) == "AI_Smart_AC_121::") {
      //checkInst(cmd.charAt(17));
      checkInst(cmd);
    }
  }
}

String get_Seiral1_response() {
  String response = "";
  char c;
  while (Serial1.available()) {
    c = Serial1.read();
    if(isAlphaNumeric(c) || c == '_' || c == ':' || c == '\n' || c == '.' || c == ',' ||  c == '{' ||  c == '}'){
      response.concat(c);
      delay(10);
    }
  }
  response.trim();
  return response;
}

int button = -1;
void checkInst(String cmd){
  //Serial.print("go\n");
  if(cmd.substring(0,28) == "AI_Smart_AC_121::power_onoff") //開關機
    button = 1;
    
  else if(cmd.substring(0,23) == "AI_Smart_AC_121::volume") //風量
    button = 2;
    
  else if(cmd.substring(0,31) == "AI_Smart_AC_121::temperature_up") //溫度調高
    button = 3;
  
  else if(cmd.substring(0,33) == "AI_Smart_AC_121::temperature_down") //溫度調低
    button = 4;
  
  else if(cmd.substring(0,27) == "AI_Smart_AC_121::function") //功能
    button = 5;

  else if(cmd.substring(0,24) == "AI_Smart_AC_121::reset") //重啟
    button = 0;
    
}

void setup()
{
  delay(2000);
  Serial1.begin(115200);
  timerCheckInst.every(10,checkInst);
  Serial.println("Done");
  
  Serial.begin(9600);
  Serial.setTimeout(10); // 設定為每10毫秒結束一次讀取(數字愈小愈快)
  pinMode(13,OUTPUT);
  // 自動 強風 弱風 微風：0 1 2 3
  Air_volume = 1; // 強風
  // 送風：4 ，冷氣：2
  Features = 2; // 冷氣
  // 16°C：0  30°C：14
  temperature = 9; // 25°C
//  mergeFirst(cmd1);
//  mergeSecond(cmd2);
//  mergeThird(cmd3);
  timerChcekACState.every(100,checkACState);
}

//int x = -1, y = 0;
void loop()
{ 
//  while(Serial.available()){
//    x = Serial.parseInt();
//    y = Serial.parseInt();
//  }
  timerCheckInst.update();
  
  if(button >= 0){
    cmd1 = "";
    cmd2 = "";
    cmd3 = "";
    Serial.print("button ");
    Serial.println(button);
    delay(10);
    switch(button){
      case 0: // reset
        // 預設情況_強風、冷氣、25°C
        Air_volume = 1; // 強風
        Features = 2; // 冷氣
        temperature = 9; // 25°C
        power_switch = true; // 預設打開
        change2cmd(Air_volume, Features, temperature, Air_volume_button);
        send_signal();
        break;
        
      case 1: // 運轉
        power = true;
        power_switch = !power_switch;
        change2cmd(Air_volume, Features, temperature, power_button);
        
        send_signal();
        break;
        
      case 2: // 風量
        Air_volume++;
        if(Features == 2) 
          if(Air_volume >= 4) Air_volume = 0;
        if(Features == 4) 
          if(Air_volume >= 4) Air_volume = 1;
        change2cmd(Air_volume, Features, temperature, Air_volume_button);

        send_signal();
        break;

      case 3: // 提高溫度
        if(Features == 4) break;
        if(temperature < 14) temperature++;
        change2cmd(Air_volume, Features, temperature, temperature_button);

        send_signal();
        break;

      case 4: // 降低溫度
        if(Features == 4) break;
        if(temperature > 0) temperature--;
        change2cmd(Air_volume, Features, temperature, temperature_button);

        send_signal();
        break;

      case 5: // 功能
        if(Features == 2) {
          Features = 4;
          Air_volume = 1; // 強制轉強風
        }
        else if(Features == 4) Features = 2;
        else Serial.println("Features wrong");
        change2cmd(Air_volume, Features, temperature, Function_button);

        send_signal();
        break;
        
      default:
        Serial.println("input again");
        break;
      }
      button = -1;
      Serial.println(Power);
      Serial.println(Air_volume);
      Serial.println(Features);
      Serial.println(temperature);
    }
    timerChcekACState.update();
}

int powerState = 0; // 開關
int airVolumeState = 0; // 風量
int featuresState = 0; // 功能
int temperatureState = 0; // 溫度

void checkACState(){
  boolean StateChange = false;
  
  int powerStateTemp = Power;
  if(powerStateTemp != powerState){
    powerState = powerStateTemp;
    StateChange = true;
  }

  int airVolumeStateTemp = Air_volume;
  if(airVolumeStateTemp != airVolumeState){
    airVolumeState = airVolumeStateTemp;
    StateChange = true;
  }

  int featuresStateTemp = Features;
  if(featuresStateTemp != featuresState){
    featuresState = featuresStateTemp;
    StateChange = true;
  }

  int temperatureTemp = temperature;
  if(temperatureTemp != temperatureState){
    temperatureState = temperatureTemp;
    StateChange = true;
  }

  if(StateChange == true){
    sendNodeMCU(powerState ,airVolumeState,featuresState,temperatureState);
  }
}

void sendNodeMCU(int PS,int AV,int FS,int temp) {
  //Prepare a JSON payload string
  String payload = "{";
  payload += "\"powerState\":";
  payload += PS;
  payload += ",";
  payload += "\"airVolumeState\":";
  payload += AV;
  payload += ",";
  payload += "\"featuresState\":";
  payload += FS;
  payload += ",";
  payload += "\"temperature\":";
  payload += temp+16;
  payload += "}";

  Serial.print("Send:");
  Serial.println(payload);
  payload.concat('\n');
  // Send payload
  const char* attributes = payload.c_str();
  Serial.print("attributes:");
  Serial.println(attributes);
  Serial1.write(attributes);
}
