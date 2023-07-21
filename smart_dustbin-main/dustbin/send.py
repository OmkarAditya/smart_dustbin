import serial
from twilio.rest import Client

# Twilio account details
account_sid = "your_account_sid"
auth_token = "your_auth_token"
twilio_number = "your_twilio_phone_number"
recipient_number = "recipient_phone_number"

# Serial port details
serial_port = "COM6"  # Replace with your serial port

# Create Twilio client
client = Client(account_sid, auth_token)

# Open serial connection
ser = serial.Serial(serial_port, 9600)  # Adjust baud rate if necessary

# Read data from serial port
while True:
    data = ser.readline().decode().strip()

    if data == "Dustbin 1 is full" or data == "Dustbin 2 is full":
        message = f"Attention: {data}"
        try:
            # Send SMS using Twilio
            client.messages.create(
                body=message,
                from_=twilio_number,
                to=recipient_number
            )
            print("SMS sent successfully.")
        except Exception as e:
            print(f"Failed to send SMS: {str(e)}")
