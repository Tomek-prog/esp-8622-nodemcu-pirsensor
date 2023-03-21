

#include <ESP8266WiFi.h>

const char* ssid     = "YOUR_SSID";      
const char* password = "YOUR_PASSWORD";  
String result;

String motion ;

void setup() 
{
  pinMode(D8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(2000);
  Serial.begin(115200);
  WiFi.hostname("ESP");
  WiFi.begin(ssid, password);
}

void ifttt() 
{
  const char host[ ] = "maker.ifttt.com";         
  const char trigger[ ] = "YOUR_EVENT_NAME";          //ifttt event name    
  const char APIKey[ ] = "YOUR_KEY";  //ifttt key    
 
  WiFiClient client;
  if (!client.connect(host, 80)) {
    
    return;
    }


  String url = String("/trigger/") + trigger + String("/with/key/") + APIKey;
  


  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n"); 
  
   delay(20);
}

  
void loop()  {
 if(digitalRead(D8)== HIGH)  
  {
   motion = digitalRead(D8);
   digitalWrite(LED_BUILTIN, LOW);   
  ifttt();
  delay(1000);                      
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(2000);                     
  
  } 
  
}


  
