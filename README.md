# RFID Access Control System

This project demonstrates how to create a basic access control system using an Arduino, an MFRC522 RFID reader, and an LCD display. The system is designed to read RFID tags, compare their IDs to a predefined list, and display a corresponding message on the LCD screen. If the tag is recognized, a welcome message is shown; otherwise, access is denied.

## How It Works

1. **RFID Reader Initialization**: The MFRC522 RFID reader is initialized and set up to read RFID tags.
2. **LCD Initialization**: The LCD display is initialized to show messages.
3. **Reading RFID Tags**: When a new RFID tag is detected, the system reads its unique ID.
4. **ID Comparison**: The read ID is compared to a list of predefined IDs.
5. **Displaying Messages**: Depending on whether the ID is recognized or not, the system displays a welcome message or an access denied message on the LCD screen.

### Key Features

- **RFID Tag Reading**: Uses the MFRC522 RFID reader to detect and read RFID tags.
- **LCD Display**: Shows messages on a 16x2 LCD display.
- **Predefined IDs**: Compares the read RFID tag ID against a list of predefined IDs to determine if access is granted.
- **Serial Output**: Outputs messages to the serial monitor for debugging purposes.

## Hardware Required

- Arduino board (e.g., Arduino Uno)
- MFRC522 RFID reader
- RFID tags/cards
- 16x2 LCD display
- Connecting wires

## How to Use

### Wiring Diagram

1. **Connect the MFRC522 RFID Reader to Arduino:**
   - `SDA` to `Pin 10`
   - `SCK` to `Pin 13`
   - `MOSI` to `Pin 11`
   - `MISO` to `Pin 12`
   - `IRQ` to `Not Connected`
   - `GND` to `GND`
   - `RST` to `Pin 9`
   - `3.3V` to `3.3V`

2. **Connect the 16x2 LCD Display to Arduino:**
   - `VSS` to `GND`
   - `VDD` to `5V`
   - `V0` to `GND` (or through a potentiometer for contrast adjustment)
   - `RS` to `Pin 6`
   - `RW` to `GND`
   - `E` to `Pin 7`
   - `D4` to `Pin 5`
   - `D5` to `Pin 4`
   - `D6` to `Pin 3`
   - `D7` to `Pin 2`
   - `A` to `5V`
   - `K` to `GND`

### Running the Code

1. **Clone the Repository:**
   ```sh
   git clone https://github.com/your-username/rfid-access-control.git
   cd rfid-access-control
   ```

2. **Upload the Code to Arduino:**
   - Open the `.ino` file in the Arduino IDE.
   - Select the correct board and port from the `Tools` menu.
   - Click the `Upload` button to upload the code to your Arduino.

3. **Power the System:**
   - Connect your Arduino to a power source (USB or external power supply).
   - Ensure all connections are secure.

4. **Use the System:**
   - Open the Serial Monitor from the Arduino IDE (ensure the baud rate is set to `9600`).
   - Approach an RFID tag to the RFID reader.
   - Observe the message displayed on the LCD and the Serial Monitor.

### Example Messages

- **Recognized Tag**: 
  ```
  ID da tag : 3A B0 23 21
  Mensagem: 
  Ola Cartao Da Alice!
  ```
  - LCD: "Ola Cartao da Alice!" and "Acesso liberado!"

- **Unrecognized Tag**:
  ```
  ID da tag : A1 B2 C3 D4
  Mensagem: 
  Cartao nao identificado!
  ```
  - LCD: "Acesso Negado!"

