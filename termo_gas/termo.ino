#include <LiquidCrystal_I2C.h>      // подключаем библу
LiquidCrystal_I2C lcd(0x3F, 16, 2); // адрес, столбцов, строк
#include <microDS18B20.h>
MicroDS18B20<5> sensor_1;
MicroDS18B20<6> sensor_2;

void setup() {
  lcd.init();           // инициализация
  lcd.backlight();      // включить подсветку
}
void loop() {
  // запрашиваем температуру
  sensor_1.requestTemp();
  sensor_2.requestTemp();
  // ждём
  delay(1000);
  // получаем и записываем в переменные
  float t1 = sensor_1.getTemp();
  float t2 = sensor_2.getTemp();
  
  lcd.home();
  lcd.setCursor(0, 0); // Устанавливаем курсор
  lcd.print("Pod"); 
  lcd.setCursor(6, 0); // Устанавливаем курсор
  lcd.print("Obr"); 
  lcd.setCursor(12, 0); // Устанавливаем курсор
  lcd.print("Razn");

  lcd.setCursor(0, 1); // Устанавливаем курсор

  lcd.print(t1, 1);     // температура 1
  lcd.write(223);       // градус
  lcd.print('-');       // "минус"
  lcd.print(t2, 1);     // температура 2
  lcd.write(223);       // градус
  lcd.print('=');       // "равно"
  lcd.print(t1 - t2, 1);  // ищем разность и выводим
  lcd.write(223);       // градус
}

