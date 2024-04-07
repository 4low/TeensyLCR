#ifndef borad_h
#define board_h


#include <Keypad.h>
#include <ILI9341_t3n.h>
#include <XPT2046_Touchscreen.h>
#include <Temperature_LM75_Derived.h>
#include <Encoder.h>
#include <Bounce.h>

// define digital pins
#define STATUS_LED_PIN  22
#define RANGE_SEL_A_PIN 26
#define RANGE_SEL_B_PIN 27
#define PGA_V_A_PIN     28
#define PGA_V_B_PIN     29
#define PGA_I_A_PIN     30
#define PGA_I_B_PIN     31

// encoder
#define ENCODER_PINA  	15
#define ENCODER_PINB    16
#define ENCODER_PINSW   17

// keypad
#define KEYPAD_PIN1     40
#define KEYPAD_PIN2     39
#define KEYPAD_PIN3     38
#define KEYPAD_PIN4     37
#define KEYPAD_PIN5     36
#define KEYPAD_PIN6     35
#define KEYPAD_PIN7     34
#define KEYPAD_PIN8     33

// display
#define DISP_BACKLIGHT_PIN  6
#define TFT_RST_PIN     5
#define TFT_CS_PIN      10
#define TFT_DC_PIN      9
// touch screen
#define TS_CS_PIN       4
#define TS_IRQ_PIN      3

// define LCR range and PGA values
#define LCR_RANGE_100   0
#define LCR_RANGE_1K    1
#define LCR_RANGE_10K   2
#define LCR_RANGE_100K  3
#define LCR_RANGE_NUM   4

#define PGA_GAIN_1      0
#define PGA_GAIN_5      2
#define PGA_GAIN_25     3
#define PGA_GAIN_100    1
#define PGA_GAIN_NUM    4

// define I2C adresses
#define I2C_ADDR_TEMPSENSOR 0x48
#define I2C_ADDR_EEPROM     0x50
#define I2C_ADDR_CODEC      0x10


extern Encoder encoder;
extern Generic_LM75 temperature;
extern ILI9341_t3n tft;
extern XPT2046_Touchscreen ts;
//extern DMAMEM uint16_t tft_frame_buffer[];
extern Keypad keypad;
extern Bounce encButton;

extern elapsedMillis blink;

void boardInit();
bool boardSelftest();
void boardSetLCRRange();
void boardSetLCRRange(uint rangePreset);
void boardSetPGAGainV();
void boardSetPGAGainV(uint gainPreset);
void boardSetPGAGainI();
void boardSetPGAGainI(uint gainPreset);
void btn_feedback();
void boardBlinkStatusLed();


#endif