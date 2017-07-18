


#define LED_ON (PORTD |= (3<<PD2))
#define LED_OFF (PORTD &= ~(3<<PD2))
#define LED_init (DDRD |= (3<<PD2))
