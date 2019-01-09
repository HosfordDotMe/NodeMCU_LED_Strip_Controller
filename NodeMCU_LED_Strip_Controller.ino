#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

#include "index.h"

ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);

const int redLED = 4;
const int greenLED = 14;
const int blueLED = 5;

void handleRoot();
void handleLED();
void handleNotFound();

void setup(void){
  Serial.begin(115200);
  delay(10);
  Serial.println('\n');

  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  wifiMulti.addAP("******", "*****"); //SSID, Key

  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) {
    delay(250);
    Serial.print('.');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID())
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  server.on("/", HTTP_GET, handleRoot);
  server.on("/LED", HTTP_POST, handleLED);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}

void handleRoot() {
  server.send(200, "text/html", indexPage);
}

void handleLED() {
  analogWrite(redLED, server.arg("red").toInt()); //0-1025, not 255
  analogWrite(greenLED, server.arg("green").toInt());
  analogWrite(blueLED, server.arg("blue").toInt());

  delay(1000); 
  
  String pathToSend = "/?red=" + String(server.arg("red")) + "&green=" + String(server.arg("green")) + "&blue=" + String(server.arg("blue")); //not being used yet
  server.sendHeader("Location", pathToSend);n
  server.send(303);
}
void handleNotFound(){
  server.send(404, "text/plain", "404: Not found");
}
