#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const char *ssid = "HTR";
const char *password = "87654321";
ESP8266WebServer server(80);
#define pin D7;
#define pin D6;
#define pin D1;
#define pin D2;
#define pin D5;

void LEFT()
{
  digitalWrite(D5,1);
  server.send(200, "text/plain", "LEFT" );
  }

void RIGHT()
{
  digitalWrite(D5,1);
  server.send(200, "text/plain", "RIGHT" );
  }

void FORWARD()
{
  digitalWrite(D1,1);
  digitalWrite(D2,0);
  server.send(200, "text/plain", "FORWARD" );
}

void BACKWARD()
{
  digitalWrite(D1,0);
  digitalWrite(D2,1);
  server.send(200, "text/plain", "BACKWARD" );
}

void STOP()
{
  digitalWrite(D5,0);
  digitalWrite(D1,0);
  digitalWrite(D2,0);
  server.send(200, "text/plain", "STOP" );
  }
  
void GON()
{
  digitalWrite(D6,1);
  server.send(200, "text/plain", "GOOGLE I" );
}

void GOFF()
{
  digitalWrite(D6,0);
  server.send(200, "text/plain", "GOOGLE R" );
}

void BLASTON()
{
  digitalWrite(D7,1);
  server.send(200, "text/plain", "BLAST ON" );
}

void BLASTOFF()
{
  digitalWrite(D7,0);
  server.send(200, "text/plain", "BLAST OFF" );
}

void CONNECT()
{
  server.send(200, "text/plain", " AT YOUR SERVICE BOSS!" );
  
}

void handleNotFound()
{
   server.send(200, "text/plain","I DIDN'T GET YOU BOSS" );
}
void setup() {
  // put your setup code here, to run once:
WiFi.softAP(ssid,password);
IPAddress myIP = WiFi.softAPIP();
pinMode(D7, OUTPUT);
pinMode(D6, OUTPUT);
pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D5, OUTPUT);
server.on("/LEFT", LEFT);
server.on("/RIGHT", RIGHT);
server.on("/FORWARD", FORWARD);
server.on("/BACKWARD", BACKWARD);
server.on("/GON", GON);
server.on("/GOFF", GOFF);
server.on("/BLASTON", BLASTON);
server.on("/BLASTOFF", BLASTOFF);
server.on("/STOP", STOP);
server.on("/CONNECT", CONNECT);
server.onNotFound(handleNotFound);
server.begin();
}

void loop() 
{
  server.handleClient();
  delay(5);
  // put your main code here, to run repeatedly:
}
