#ifndef audio_design_h
#define audio_design_h

//#include "audio_ext.h"
#include <Audio.h>


typedef struct ad_readings_struct {
  float v_rms;
  float i_rms;
  float v_mean;
  float i_mean;
  float phase;
  float phase_raw;
  float v_peak;
  float i_peak;
  uint32_t time;
  float mean1;
  float mean2;
  float mean3;
  float mean4;
  float a1;
  float a2;
} ad_readings_t;

extern bool adDataAvailable;
extern ad_readings_t adReadings;

void adInit();
void adSetOutputFrequency(float frequency);
void adSetOutputAmplitude(float amplitude);
void adSetOutputOffset(float offset);
void adResetSquarewavePhase();
float adHeadroom(float peaklevel);
void adResetReadings();
void adAverageReadings();
float adGetFrequency();
uint adGetAveraging();
void adSetAveraging(uint avg);


#endif
