#include <stdio.h>
#include <stdint.h>
#include <stdint.h>
#include <time.h>

volatile uint32_t* const portd_moder   = (uint32_t*) 0x40020C00;
volatile uint32_t* const portd_odr     = (uint32_t*) 0x40020C14;

void sleep(uint32_t ms); // use systick to busy-wait

int main(void)
{

  uint32_t moder = *portd_moder;
  moder |= (1 << 16);
  moder &= ~(1 << 17);
  *portd_moder = moder;

  while(1) {
    *portd_odr |= (1 << 8);   // led-on
    sleep(500);
    *portd_odr &= ~(1 << 8);  // led-off
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
