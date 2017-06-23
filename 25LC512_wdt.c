// 25LC512 = 512k bits / 8 = 64k bytes = 16 bit address

#define EEPROM_ADDRESS int16
#define EEPROM_SIZE    65536     

void init_ext_eeprom() 
{ 
   setup_spi(SPI_MASTER | SPI_MODE_0_0 | SPI_CLK_DIV_16 );
   
   output_high(EEP_CS);
   output_high(EEP_WP);
} 

//-------------------------------- 
int8 ext_eeprom_ready(void) 
{ 
   int8 data; 
   
   output_low(EEP_CS); 
   spi_write(0x05); 
   data = spi_read(0); 
   output_high(EEP_CS); 
   
   return(!bit_test(data, 0)); 
} 

//-------------------------------- 
void write_ext_eeprom(EEPROM_ADDRESS address, BYTE data) 
{ 
   heartbeat(FALSE);
      while(!ext_eeprom_ready());
   
      output_low(EEP_CS); 
      spi_write(0x06); 
      output_high(EEP_CS); 
      
      output_low(EEP_CS); 
      spi_write(0x02); 
      spi_write(address >> 8); 
      spi_write(address); 
      spi_write(data); 
      output_high(EEP_CS); 
      
   heartbeat(TRUE);  
} 
//-------------------------------- 

BYTE read_ext_eeprom(EEPROM_ADDRESS address) 
{ 
   int8 data; 
   
   heartbeat(FALSE);
   
      while(!ext_eeprom_ready());
      
      output_low(EEP_CS); 
      spi_write(0x03); 
      spi_write(address >> 8); 
      spi_write(address); 
      
      data = spi_read(0); 
      output_high(EEP_CS); 
      
   heartbeat(TRUE);  
   
   return(data); 
}


