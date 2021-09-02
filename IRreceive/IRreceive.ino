/*
 * IRremote: IRreceiveDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Initially coded 2009 Ken Shirriff http://www.righto.com/
 */

#include <IRremote.h>

#if defined(ESP32)
int IR_RECEIVE_PIN = 15;
#elif defined(ARDUINO_AVR_PROMICRO)
int IR_RECEIVE_PIN = 10;
#else
int IR_RECEIVE_PIN = 2;
#endif
IRrecv IrReceiver(IR_RECEIVE_PIN);
decode_results results;
// On the Zero and others we switch explicitly to SerialUSB
#if defined(ARDUINO_ARCH_SAMD)
#define Serial SerialUSB
#endif

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);
#if defined(__AVR_ATmega32U4__) || defined(SERIAL_USB) || defined(SERIAL_PORT_USBVIRTUAL)
    delay(2000); // To be able to connect Serial monitor after reset and before first printout
#endif
    // Just to know which program is running on my Arduino
   
    IrReceiver.enableIRIn();  // Start the receiver
   

  
}

void loop() {
     if (IrReceiver.decode(&results)){
        
        //Serial.println(results.value, HEX);
        dump(&results);
        IrReceiver.resume(); // Receive the next value
  
    }
    delay(20);
}

void dump(decode_results *results) {
   int count = results->rawlen;
   
   for (int i = 0; i < count; i++) {
       
       Serial.print((unsigned int)results->rawbuf[i], DEC);
       Serial.print(',');
    
   }
  Serial.print('\n');
}
