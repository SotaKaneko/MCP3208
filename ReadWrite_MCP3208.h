int ReadWrite_MCP3208 (unsigned char MCP3208_Channel) {
  unsigned char buffer[3];
  int MCP3208Value = 0;

  buffer[0] = ((MCP3208_Channel & 0x07) >> 2) | 0x06;
  buffer[1] = ((MCP3208_Channel & 0x07) << 6);
  buffer[2] = 0x00;
 
  digitalWrite (MCP3208_CS, 0);

  wiringPiSPIDataRW (SPI_CHANNEL, buffer, 3);
 
  buffer[1] = 0x0f & buffer[1];
  MCP3208Value = (buffer[1] << 8) | buffer[2];

  digitalWrite (MCP3208_CS, 1);

  return MCP3208Value;
}
