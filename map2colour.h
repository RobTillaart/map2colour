#pragma once
//
//    FILE: map2colour.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.0
// PURPOSE: Arduino library for mapping a float to colour spectrum
//     URL: https://github.com/RobTillaart/map2colour


#include "Arduino.h"
#include "m2c_colours.h"


#define MAP2COLOUR_LIB_VERSION          (F("0.2.0"))


class map2colour
{
  public:
    map2colour(uint8_t size = 7);
    ~map2colour();

    //  values is an array of size values in ascending order
    bool     begin(float * values, uint32_t * colourMap = NULL);
    uint8_t  size();
    uint32_t map2RGB(float value);
    uint16_t map2_565(float value);

  protected:
    uint8_t _size;
    float * _values;

    uint8_t * _Red;
    uint8_t * _Green;
    uint8_t * _Blue;

    //  default colours, split up per channel for performance.
    //  uint8_t _Red[7]   = { 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF };
    //  uint8_t _Green[7] = { 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0xFF };
    //  uint8_t _Blue[7]  = { 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF };
    //  uint8_t _Alpha[7] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
};


/////////////////////////////////////////////////////////////////////////
//
//  DERIVED CLASS
//
//  FASTER + MORE RAM
//
class map2colourFast : public map2colour
{
  public:
    map2colourFast(uint8_t size = 7);
    ~map2colourFast();

    //  values is an array of size values in ascending order
    bool begin(float * values, uint32_t * colourMap = NULL);
    uint32_t map2RGB(float value);
    uint16_t map2_565(float value);

  private:
    float * divFactor;
};


//  -- END OF FILE --

