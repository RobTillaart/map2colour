//
//    FILE: map2colour.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Arduino library for mapping a float to colour spectrum
//     URL: https://github.com/RobTillaart/map2colour
//
//  HISTORY:
//  0.1.0  2021-12-04  initial version


#include "map2colour.h"


map2colour::map2colour()
{
}


bool map2colour::begin(float * values)
{
  _values = values;
  return true;
}


uint32_t map2colour::map2RGB(float value)
{
  int index = 1;
  while ((index < 7) && (_values[index] < value)) index++;
  float factor = 1 - (_values[index] - value) / (_values[index] - _values[index-1]);

  uint8_t R = _R[index - 1] + factor * (_R[index] - _R[index - 1]);
  uint8_t G = _G[index - 1] + factor * (_G[index] - _G[index - 1]);
  uint8_t B = _B[index - 1] + factor * (_B[index] - _B[index - 1]);
  uint32_t col = R;
  col <<= 8;
  col |= G;
  col <<= 8;
  col |= B;
  return col;
}

/*
// linear mapping  0 .. 1 => RGB colour

void map2colour::HSL(float H, float S, float L, float& Rval, float& Gval, float& Bval)
{
  float var_1;
  float var_2;

  if ( S == 0 )
  {
    Rval = L;
    Gval = L;
    Bval = L;
  }
  else
  {
    if ( L < 0.5 )
    {
      var_2 = L * ( 1 + S );
    }
    else
    {
      var_2 = ( L + S ) - ( S * L );
    }
    var_1 = 2 * L - var_2;
    Rval = Hue_2_RGB( var_1, var_2, H + 1.0 / 3.0 );
    Gval = Hue_2_RGB( var_1, var_2, H );
    Bval = Hue_2_RGB( var_1, var_2, H - 1.0 / 3.0 );
  }
  // tackle negative math
  if (Rval < 0) Rval = 0;
  if (Gval < 0) Gval = 0;
  if (Bval < 0) Bval = 0;
}

*/


/*

float map2colour::Hue_2_RGB( float v1, float v2, float vH )
{
  if ( vH < 0 )
    vH += 1;
  if ( vH > 1 )
    vH -= 1;
  if ( ( 6 * vH ) < 1 )
    return ( v1 + ( v2 - v1 ) * 6 * vH );
  if ( ( 2 * vH ) < 1 )
    return ( v2 );
  if ( ( 3 * vH ) < 2 )
    return ( v1 + ( v2 - v1 ) * ((2.0 / 3) - vH) * 6 );
  return ( v1 );
}

*/


// -- END OF FILE --

