//EZgps program -Jonathan
//Basically a frame for use in creating code with ublox GPS stuff
//Not really optimized for anything except usability at the moment
//ping
#include <TinyGPS.h>
#include <SoftwareSerial.h>

//#define gpsserial Serial1; //Hardware Serial option
//HardwareSerial & gpsserial = Serial3;
#define gpsserial Serial1
//SoftwareSerial gpsserial = SoftwareSerial(5,6);

struct GPSdata{
  float GPSLat=0;
  float GPSLon=0;
  unsigned long GPSTime=0;
  long GPSAlt=0;
  int GPSSats=-1;
};
TinyGPS gps;
unsigned long cur=0;
GPSdata gpsInfo;
GPSdata preserve;

void setup() {
  GPSINIT(115200); //Only 9600 or 115200 for now, but simpler than before
  Serial.begin(9600);
  Serial.println("Init:-");
}

void loop() {
 //Parse GPS
 preserve = gpsInfo;
  while (gpsserial.available()){
   if (gps.encode(gpsserial.read())){
	 gpsInfo = getGPS();
     break;
   }
 }
 //---
 //Print to screen
  if(millis()>=(cur+1000)){
    cur=millis();
	output();
	//change
  }
  //---
  
  //DO OTHER STUFF
  delay(10);//Not needed
}
