#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <errno.h>
#include "define.h"
#include "ReadWrite_MCP3208.h"

int main (void) {
  int MCP3208_value = 0;

  if (wiringPiSetup () == -1) {
    fprintf (stdout, "Unable to start wiringPi: %s\n", strerror(errno));
    return 1;
  }

  if (wiringPiSPISetup (SPI_CHANNEL, SPI_SPEED) == -1) {
    fprintf (stdout, "wiringPiSPISetup is failed: %s\n", strerror(errno));
    return 1;
  }

  pinMode (MCP3208_CS, OUTPUT);

  MCP3208_value = ReadWrite_MCP3208 (TARGET_channel);

  printf ("MCP3208 Value: %04u\n", MCP3208_value);
  printf ("MCP3208 Voltage: %.3f\n", (MCP3208_value *  Vref) / scale_number);

  return 0;
}

// :Note - Degital output code = 4096 * Vin / Vref
