import serial
import wave
import time

ser = serial.Serial('/dev/tty.usbmodem101', 9600) # change to the serial port of your Arduino
audio_file = wave.open('audiomass-output.wav', 'rb')
sample_rate = audio_file.getframerate()

while True:
    audio_data = audio_file.readframes(1)
    if not audio_data:
        break
    for sample in audio_data:
        ser.write(bytes([sample]))
        ser.flush()
    delay = int(1000000 / sample_rate)
    time.sleep(delay / 1000000)








