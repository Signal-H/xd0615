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
const int numReadings = 10;                                          //����һ�����ͳ������������Ƶ��е�Ԫ�ظ��� 

int readings[numReadings];                                           // ����һ������
int readIndex = 0;                                                   // ����һ����ǰ����������������ȷ����ȡ��λ�� 
int total = 0;                                                       // ����һ�����Σ������洢��ֵ 
int average = 0;                                                     // ����һ�����Σ������洢ƽ��ֵ 
int inputPin = A0;                                                   // ����һ�����Σ������������� 

void setup() 
{
  Serial.begin(9600);                                                //��ʼ������ 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)//������������ 
  { 
    readings[thisReading] = 0;                                       //���ν������е�ÿһ������ֵΪ�� 
  }
}

void loop() 
{
  total = total - readings[readIndex];                               //�ܺ͵����ܺͼ�ȥ��һ�ε�ֵ 
  readings[readIndex] = analogRead(inputPin);                        //�Ӵ������ж�ȡ��ֵ 
  total = total + readings[readIndex];                               //���������еĻ�ȡ����ֵ���뵽��ֵ�� 
  readIndex = readIndex + 1;                                         //����������һ����λ����һλ 

  if (readIndex >= numReadings)                                      //����Ѿ���λ�����һλ 
  {
    readIndex = 0;                                                   //�����±��ٴδ��㿪ʼ 
  }

  average = total / numReadings;                                     //����ƽ��ֵ 
  Serial.println(average);                                           //��ASCLLֵ����ʽ���͵������ 
  delay(1);                                                          //�ӳ�һ����ȷ���ȶ� 
}
