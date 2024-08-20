///
/// \file RADIO_RDA5807M.h
/// \brief Library header file for library to control the RDA5807M radio chip with arduino.

#ifndef RADIO_RDA5807M_H
#define RADIO_RDA5807M_H

#include <Arduino.h>
#include <Wire.h>

class RDA5807M{
  public:
  bool   Radioinit();
  void   ResetChip();
  

  void   SetVolume(byte VolumeSet);
  void   SetBassBoost(bool OnOff);
  void   SetMono(bool OnOff);
  void   SetMute(bool OnOff);
  void   SetSoftMute(bool OnOff);    // Set the soft mute is mute on low signals
  void   SetFrequency(unsigned int FreqSet,byte VolumeSet); // set Frequency and play
  void 	 SetBand(byte BankSet);
  unsigned int GetFrequency(void);
  byte GetRSSI_FMInfo(void);
  unsigned int MaxFreq;
  unsigned int MinFreq;
  void    SeekUp();   // start seek mode upwards
  void    SeekDown(); // start seek mode downwards
  unsigned int CHIPRegister[16];  // var to storage operation registers of RDA5807M 00 to 0F. write from 02 to 05. read from 0A and 0B
  private:

  
  void     ReadRegisters(); // read all operation registers of RDA5807M
  void     SaveRegisters();// save all operation registers of RDA5807M
  
  void     I2Cwrite16(unsigned int DataOut);        
  unsigned int I2Cread16(void);
};

#endif
