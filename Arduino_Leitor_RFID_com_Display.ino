#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(6, 7, 5, 4, 3, 2); 
char st[20];
 
void setup() 
{
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init(); 
  Serial.println("Aproxime o seu cartao!");
  Serial.println();
  lcd.begin(16, 2);  
  MensagemInicial();
}
 
void loop() 
{
  if (!mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  
  if (!mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  
  Serial.print("ID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  
  if (conteudo.substring(1) == "DA DA A4 B9") //UID 1 - Chaveiro
  {
    Serial.println("Ola Alice !");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ola Alice !");
    lcd.setCursor(0,1);
    lcd.print("Acesso liberado Chaveiro!");
    delay(3000);
    MensagemInicial();
  }
  else
    if (conteudo.substring(1) == "3A B0 23 21") //UID 2 - Cartao
    {
      Serial.println("Ola Cartao Da Alice!");
      Serial.println();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Ola Cartao da Alice !");
      lcd.setCursor(0,1);
      lcd.print("Acesso liberado Chaveiro!");
      delay(3000);
      MensagemInicial();
    }
    else
      if (conteudo.substring(1) == "A0 FB 4B A8") //UID 2 - Cartao
      {
        Serial.println("Ola Gabizinha!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Ola Gabizinha !");
        lcd.setCursor(0,1);
        lcd.print("Acesso liberado Chaveiro!");
        delay(3000);
        MensagemInicial();
      }
      else
      {
        Serial.println("Cartao nao identificado!");
        Serial.println();
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("");
        lcd.setCursor(0,1);
        lcd.print("Acesso Negado !");
        delay(3000);
        MensagemInicial();
      }
} 
 
void MensagemInicial()
{
  lcd.clear();
  lcd.print(" Aproxime o seu");  
  lcd.setCursor(0,1);
  lcd.print("cartao do leitor");  
}
