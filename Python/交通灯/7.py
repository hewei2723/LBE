def countdown(seconds):
    while seconds > 0:
        seconds -= 1
        tens = seconds // 10
        ones = seconds % 10
        return tens, ones