#include <stdio.h>
#include <stdint.h>
#include <stdint.h>
#include <time.h>

#define PORTD_MODER   (*((volatile uint32_t*) 0x40020C00))
#define PORTD_ODR     (*((volatile uint32_t*) 0x40020C14))

void sleep(uint32_t ms); // use systick to busy-wait

int main(void)
{

  volatile uint16_t a;
  uint16_t volatile b;

  volatile uint16_t *c;
  uint16_t volatile *d;

  uint32_t moder = PORTD_MODER;
  moder |= (1 << 16);
  moder &= ~(1 << 17);
  PORTD_MODER = moder;

  while(1) {
    PORTD_ODR |= (1 << 8);   // led-on
    sleep(500);
    PORTD_ODR &= ~(1 << 8);  // led-off
    sleep(500);
  }
}
void sleep(uint32_t ms) // use systick to busy-wait
{
  long pause;
  clock_t now,then;

  pause = ms*(CLOCKS_PER_SEC/1000);
  now = then = clock();
  while( (now-then) < pause )
      now = clock();
}
