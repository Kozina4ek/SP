#include "mbed.h"
#include "BME280.h"
BME280 sensor(I2C_SDA, I2C_SCL);
DigitalOut oled1(LED1);
DigitalOut oled(D9);
InterruptIn ibutton1(BUTTON1);
static auto sleep_time = 1000ms;
static auto sleep_time1 = 100ms;
Ticker toggle_led_ticker;
Thread thread;
#define ALARM_FLAG 2
void mythread()
{
while (!ThisThread::flags_wait_all_for(ALARM_FLAG, sleep_time1))
{
oled = !oled;
}
}
void led_ticker()
{
oled1 = !oled1;
}
void pressed()
{
// Управление скоростью мерцания светодиода
toggle_led_ticker.detach(); // открепляет таймер
sleep_time1 = 1000ms;
sleep_time = 100ms;
toggle_led_ticker.attach(&led_ticker, sleep_time);
}
char buf[2];
int main()
{
thread.start(mythread);
toggle_led_ticker.attach(&led_ticker, sleep_time);
//ibutton1.rise(&pressed);
while (true) {
printf("%d degC, %d hPa, %d $$\n", (int)sensor.getTemperature(), (int)sensor.getPressure(), (int)sensor.getHumidity());
if (sensor.getTemperature()>=25)
{
pressed();
}
else
{
toggle_led_ticker.detach();
sleep_time = 1000ms;
sleep_time1 = 100ms;
toggle_led_ticker.attach(&led_ticker, sleep_time);
}
ThisThread::sleep_for(1000ms);
}
}
