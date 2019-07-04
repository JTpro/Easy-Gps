//EZgps program -Jonathan
//Basically a frame for use in creating code with ublox GPS stuff
//Not really optimized for anything except usability at the moment
//ping
#include <TinyGPS.h>
#include <SoftwareSerial.h>

//Use Hardware Serial-
#define gpsserial Serial1
//or Software Serial-
//SoftwareSerial gpsserial = SoftwareSerial(5,6);

//Structure containing different parameters parsed by the GPS
struct GPSdata{
  float GPSLat=-1;
  float GPSLon=-1;
  unsigned long GPSTime=-1;
  unsigned long GPSSpeed=-1;
  long GPSAlt=-1;
  int GPSSats=-1;
  long GPSCourse = -1;
};
TinyGPS gps; //The library object
unsigned long cur = 0;
GPSdata gpsInfo; //Current obj
GPSdata preserve;//Last obj (for getting deltas)

void setup() {
  GPSINIT(115200); //Only 9600 or 115200 for now, but simpler than before
  Serial.begin(115200);
  Serial.println("Init:-");
}

void loop() {
 //Parse GPS
 //Serial.println((String)millis());
 gpsRun(); //Leave this in loop
 
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
