
ifdef(`conf_STATUSLED_TX', `dnl
pin(STATUSLED_TX, PA1, OUTPUT)
')dnl

ifdef(`conf_STATUSLED_RX', `dnl
pin(STATUSLED_RX, PA2, OUTPUT)
')dnl

ifdef(`conf_ONEWIRE', `dnl
  /* onewire support */
  pin(ONEWIRE, PA0)
')dnl

ifdef(`conf_RFM12', `dnl
/* port the rfm12 module CS is attached to */
pin(SPI_CS_RFM12, SPI_CS_HARDWARE, OUTPUT)
RFM12_USE_INT(0)
RFM12_ASK_SENSE_USE_INT(0)
pin(RFM12_TX_PIN, PD6, OUTPUT) 
//pin(RFM12_RX_PIN, PD6, OUTPUT) 
')

ifdef(`conf_HD44780', `
    pin(HD44780_RS, PC2)
    pin(HD44780_RW, PC3)
    pin(HD44780_EN1, PD7)
    pin(HD44780_D4, PC4)
    pin(HD44780_D5, PC5)
    pin(HD44780_D6, PC6)
    pin(HD44780_D7, PC7)
')

ifdef(`conf_ZBUS', `dnl
/* port config for zbus */
pin(ZBUS_RXTX_PIN, PD4)
pin(ZBUS_TX_PIN, PD5, OUTPUT) 
//pin(ZBUS_RX_PIN, PD6, OUTPUT) 
')

//pin(STATUSLED_HB_ACT, PD6, OUTPUT)

pin(SOFT_UART_TX, PA3, OUTPUT)
