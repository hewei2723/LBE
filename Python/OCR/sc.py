from PIL import ImageGrab
# grab()如果不加参数,是全屏。四个参数分别是要截取范围的左上角x、y和右下角的x、y坐标。
im = ImageGrab.grab(bbox=(0, 0, 100, 100))
im.save(r'img.png')