/*

  Smoothing

  Reads repeatedly from an analog input, calculating a running average
  and printing it to the computer.  Keeps ten readings in an array and
  continually averages them.

  The circuit:
    * Analog sensor (potentiometer will do) attached to analog input 0

  Created 22 April 2007
  By David A. Mellis  <dam@mellis.org>
  modified 9 Apr 2012
  by Tom Igoe
  http://www.arduino.cc/en/Tutorial/Smoothing

  This example code is in the public domain.


*/


// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 10;                                          //定义一个整型常量，用来限制当中的元素个数 

int readings[numReadings];                                           // 定义一个数组
int readIndex = 0;                                                   // 定义一个当前读数的索引，用来确定读取的位置 
int total = 0;                                                       // 定义一个整形，用来存储和值 
int average = 0;                                                     // 定义一个整形，用来存储平均值 
int inputPin = A0;                                                   // 定义一个整形，用来输入引脚 

void setup() 
{
  Serial.begin(9600);                                                //初始化串口 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)//将这个数组遍历 
  { 
    readings[thisReading] = 0;                                       //依次将数组中的每一个数赋值为零 
  }
}

void loop() 
{
  total = total - readings[readIndex];                               //总和等于总和减去上一次的值 
  readings[readIndex] = analogRead(inputPin);                        //从传感器中读取数值 
  total = total + readings[readIndex];                               //将传感器中的获取的新值加入到总值中 
  readIndex = readIndex + 1;                                         //数组索引加一，移位到下一位 

  if (readIndex >= numReadings)                                      //如果已经移位至最后一位 
  {
    readIndex = 0;                                                   //数组下标再次从零开始 
  }

  average = total / numReadings;                                     //计算平均值 
  Serial.println(average);                                           //以ASCLL值的形式发送到计算机 
  delay(1);                                                          //延迟一秒来确保稳定 
}
