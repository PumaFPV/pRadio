#include <Arduino.h>

HardwareSerial vhf (1);
uint8_t vhfTx = 0;
uint8_t vhfRx = 0;

uint8_t vhfHandshake();
uint8_t vhfSetGroupParameters(uint8_t bandwidth, uint8_t txFrequency, uint8_t rxFrequency, uint8_t txSubAudio, uint8_t squelch, uint8_t rxSubAudio);
uint8_t vhfScanFrequency(uint8_t scanFrequency);
uint8_t vhfVolumeConfiguration(uint8_t volume);
uint8_t vhfAudiofilterConfiguration(uint8_t preEmph, uint8_t highpass, uint8_t lowpass);
uint8_t vhfSetTailTone(uint8_t taileTone);
uint8_t vhfReadRssi();
uint8_t vhfGetModuleVersion();

void setup() 
{
  vhf.begin(9600, SERIAL_8N1, vhfTx, vhfRx);
}

void loop() 
{

}



uint8_t vhfHandshake()
{
  vhf.write("AT+DMOCONNECT\r\n");
  return vhf.read();
}



uint8_t vhfSetGroupParameters(uint8_t bandwidth /*0: 12.5k, 1: 25k*/, 
                              uint8_t txFrequency, 
                              uint8_t rxFrequency, 
                              int8_t txSubAudio, 
                              uint8_t squelch, 
                              uint8_t rxSubAudio)
{
  String command = "AT+DMOSETGROUP=";
  command += bandwidth; command += ",";
  command += txFrequency; command += ",";
  command += rxFrequency; command += ",";
  command += txSubAudio; command += ",";
  command += squelch; command += ",";
  command += rxSubAudio;
  command += "\r\n";

  vhf.print(command); 
}

uint8_t vhfScanFrequency()
{
  
}

uint8_t vhfScanFrequency(uint8_t scanFrequency);
uint8_t vhfVolumeConfiguration(uint8_t volume);
uint8_t vhfAudiofilterConfiguration(uint8_t preEmph, uint8_t highpass, uint8_t lowpass);
uint8_t vhfSetTailTone(uint8_t taileTone);
uint8_t vhfReadRssi();
uint8_t vhfGetModuleVersion();

