#include "Wire.h"
#include "I2Cdev.h" 
#include "MPU6050.h" 
const int red = 9;
const int green = 10;
const int blue = 11;

 
MPU6050 mpu; 
int16_t ax, ay, az; 
int16_t gx, gy, gz; 




void setup() 
{ 
Wire.begin(); 
Serial.begin(38400); 
Serial.println("Initialize MPU"); 
mpu.initialize(); 
Serial.println(mpu.testConnection() ? "Connected" : "Connection failed"); 
   pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

} 

void loop() 
{ 
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); 
  Serial.print("\t");
  Serial.print("ax=  ");
  Serial.println(ax);
 
  Serial.print("\t");
  Serial.print("ay=  ");
  Serial.print(ay);

  
 Serial.print("\t");
  Serial.print("az=  ");
 Serial.print(az);


   Serial.print("\t");
  Serial.print("gx=  ");
  Serial.print(gx);
//
//
   Serial.print("\t");
  Serial.print("gy=  ");
  Serial.print(gy);
//
//  
  Serial.print("\t");
  Serial.print("gz=  ");
  Serial.print(gz);


colorled();


delay(60);

}

void colorled(){
   analogWrite(red, (255 - map(ax, -17000, 17000, 0, 255 ) ));
  analogWrite(blue,(255 - map( ay, -17000, 17000, 0, 255 )));
  analogWrite(green,(255 - map( ay, -17000, 17000, 0, 255 )) );

}



