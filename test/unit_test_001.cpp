//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-12-04
// PURPOSE: unit tests for the map2colour library
//          https://github.com/RobTillaart/map2colour
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)


#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "map2colour.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_constructor_I)
{
  fprintf(stderr, "MAP2COLOUR_LIB_VERSION: %s\n", (char *) MAP2COLOUR_LIB_VERSION);

  map2colour mc;

  float values[7] = { 1, 2, 3, 4, 5, 6, 7 };
  assertTrue(mc.begin(values));

  assertEqual(0x00000000, mc.map2RGB(1));
  assertEqual(0x00FF0000, mc.map2RGB(2));
  assertEqual(0x00FFFF00, mc.map2RGB(3));
  assertEqual(0x0000FF00, mc.map2RGB(4));
  assertEqual(0x0000FFFF, mc.map2RGB(5));
  assertEqual(0x000000FF, mc.map2RGB(6));
  assertEqual(0x00FFFFFF, mc.map2RGB(7));
}

unittest(test_constructor_II)
{
  fprintf(stderr, "MAP2COLOUR_LIB_VERSION: %s\n", (char *) MAP2COLOUR_LIB_VERSION);

  map2colour mc;

  float values[7] = { 1, 2, 3, 4, 5, 6, 7 };
  uint32_t colours[7] = 
  {
    M2C_WHITE, M2C_BLACK, M2C_FUCHSIA, M2C_OLIVE, M2C_NAVY, M2C_GREEN, M2C_YELLOW
  };
  assertTrue(mc.begin(values));

  assertEqual(M2C_WHITE,   mc.map2RGB(1));
  assertEqual(M2C_BLACK,   mc.map2RGB(2));
  assertEqual(M2C_FUCHSIA, mc.map2RGB(3));
  assertEqual(M2C_OLIVE,   mc.map2RGB(4));
  assertEqual(M2C_NAVY,    mc.map2RGB(5));
  assertEqual(M2C_GREEN,   mc.map2RGB(6));
  assertEqual(M2C_YELLOW,  mc.map2RGB(7));
}



unittest_main()


// -- END OF FILE --
