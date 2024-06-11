def flash_led(self):
        g_led = Pin(1, Pin.OUT)
        while True:
            g_led.on()
            utime.sleep_ms(100)
            g_led.off()