#include "mbed.h"
// Объявляем пин светодиода как выход
DigitalOut oled1(LED1);
// Объявляем пин кнопки 1 как вход прерывания
InterruptIn ibutton1(BUTTON1);
static auto sleep_time = 100ms;
static int c=0;
Ticker toggle_led_ticker;
void led_ticker()
{
oled1 = !oled1;
}
void pressed()
{
// Управление скоростью мерцания светодиода
toggle_led_ticker.detach(); // открепляет таймер
if (c>=3){
sleep_time = 1000ms;
}
if (c>=6 ){
sleep_time = 100ms;
c=0;
}
toggle_led_ticker.attach(&led_ticker, sleep_time);
}
int main()
{
toggle_led_ticker.attach(&led_ticker, sleep_time);
// прикрепляем адрес функции на кнопку
ibutton1.rise(&pressed);
while (true) {
}
}
