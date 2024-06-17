import serial
import time
# Adjust the serial port name as necessary
serial_port = 'COM10'  # Replace with the correct port (e.g., 'COMx' on Windows)
baud_rate = 115200

# Open the serial port
ser = serial.Serial(serial_port, baud_rate, timeout=0.1)

while True:
    # Send data to Pico
    send_data = input("Enter data to send to Pico: ")
    ser.write(f"{send_data}\n".encode())

    # Read response from Pico
    received_data = ser.readline().decode().strip()
    print(received_data)
    time.sleep(0.05)
