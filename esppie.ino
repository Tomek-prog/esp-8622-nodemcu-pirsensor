

#include <ESP8266WiFi.h>

const char* ssid     = "arduino";      
const char* password = "kulo6770";  
String result;

String motion ;

void setup() 
{
  pinMode(D8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(2000);
  Serial.begin(115200);
  WiFi.hostname("ESPDrzwi");
  WiFi.begin(ssid, password);
}

void ifttt() 
{
  const char host[ ] = "maker.ifttt.com";         
  const char trigger[ ] = "lot_Motion_Sensor";                 
  const char APIKey[ ] = "kT9aCIo2VjjYNioqabtneAoQl5kRK2sZIUVv4wfjOC5";     
 
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


  
