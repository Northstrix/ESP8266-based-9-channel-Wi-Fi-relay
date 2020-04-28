# ESP8266-based-9-channel-Wi-Fi-relay

You can find the code and a circuit of this device here:  https://github.com/Northstrix/ESP8266-based-9-channel-Wi-Fi-relay

To build this device you need:
1) One ESP8266
2) Two ULN2003
3) Twelve relays
4) Power source(s) that can provide 12 volts and enough current for relays as well as supply ESP8266 (3.3V or 5V)

Note: If you're using 5 volts power supply then you have to put "+" of your power supply to pin Vin.
If you're using 3.3 volts power supply then you have to put "+" of your power supply to pin 3V3.
In both cases you have to put "-" of your power supply to pin GND.<br>
<br>
The state of each channel is individually controlled and completely independent from one another.<br>
<br>
It's not a dimmer. Each channel has only two states "ON" and "OFF".<br>
<br>
You can expand the number of channels up to 11, but I wouldn't recommend you to do so.
