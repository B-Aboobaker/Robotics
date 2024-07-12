// PasswordLCDCircuit
#include <LiquidCrystal.h> 
#include <Keypad.h> 

int a = 0, b = 0, c = 0, d = 0; 
int var = 0; 
int C1 = 1, C2 = 2, C3 = 3, C4 = 4; 
char f = '*'; 
int tries = 0, incorrecto = 0; 
int limit = 3; 
const byte rows = 4; 
const byte columns = 4; 

char pad[rows][columns] = { 
  {'1','2','3','A'}, 
  {'4','5','6','B'}, 
  {'7','8','9','C'}, 
  {'*','0','#','D'} 
}; 

byte pinRows[rows] = {7, 6, 5, 4}; 
byte pinColumns[columns] = {3, 2, 1, 0}; 

Keypad keypad = Keypad(makeKeymap(pad), pinRows, pinColumns, rows, columns); 
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); 

void setup() { 
  lcd.begin(16, 2); 
  pinMode(A0, OUTPUT); // wrong 
  pinMode(A1, OUTPUT); // right 
} 

void loop() { 
  char key = keypad.getKey(); 
  if (key) { 
    lcd.setCursor(6 + var, 1); 
    lcd.print(key);
    lcd.setCursor(6 + var, 1);
    lcd.print(f); 
    key = key - 48; 
    var++; 
    switch (var) { 
      case 1: a = key; break; 
      case 2: b = key; break; 
      case 3: c = key; break; 
      case 4: d = key; 
              delay(100); 
              if (a == C1 && b == C2 && c == C3 && d == C4) { 
                lcd.clear(); 
                lcd.setCursor(2, 0); 
                lcd.print("Correct!"); 
                lcd.setCursor(2, 1); 
                lcd.print("Welcome!"); 
                delay(1000); 
                digitalWrite(A0, HIGH); 
                delay(3000); 
                lcd.clear(); 
                digitalWrite(A0, LOW); 
              } else { 
                lcd.clear(); 
                lcd.setCursor(2, 0); 
                lcd.print("Incorrect!"); 
                lcd.setCursor(2, 1); 
                lcd.print("Wrong Password!"); 
                digitalWrite(A1, HIGH); 
                delay(3000); 
                lcd.clear(); 
                digitalWrite(A1, LOW); 
              } 

              if (a == C1 && b == C2 && c == C3 && d == C4) {
                tries = 0; 
                limit = 3; 
              } else { 
                tries++; 
                limit--; 
                lcd.setCursor(2, 0); 
                lcd.print("Wrong! "); 
                lcd.setCursor(2, 1); 
                lcd.print(limit); 
                lcd.setCursor(4, 1); 
                lcd.print("tries left"); 
                delay(1000); 
                if (limit == 0) { 
                  lcd.clear(); 
                  lcd.setCursor(2, 0); 
                  lcd.print("Di ka match!"); 
                  delay(5000); 
                } 
                delay(300); 
                lcd.clear(); 
              } 
              var = 0; 
              lcd.clear(); 
              break; 
    } 
  } 

  if (!key) { 
    lcd.setCursor(0, 0);
    lcd.print("Enter Password");
  } 

  delay(2); 
}
