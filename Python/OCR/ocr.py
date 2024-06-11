import pygetwindow as gw
from PIL import ImageGrab
import pytesseract
import pyperclip
import sys
import os

# 设置控制台编码
os.system('chcp 65001')  # UTF-8 编码
# 设置 Tesseract OCR 可执行文件路径
pytesseract.pytesseract.tesseract_cmd = r'"C:\\Program Files (x86)\\Tesseract-OCR\\tesseract.exe"'  # 根据你的安装路径设置

# 设置截图保存目录为用户文档目录
screenshot_dir = os.path.expanduser("~\\Documents")

def get_screenshot():
    # 获取活动窗口
    active_window = gw.getActiveWindow()
    # 获取活动窗口的位置信息
    x, y, width, height = active_window.left, active_window.top, active_window.width, active_window.height
    # 使用 ImageGrab 获取屏幕截图
    screenshot = ImageGrab.grab(bbox=(x, y, x+width, y+height))

    # 将截图保存到指定目录
    desktop_path = os.path.join(os.path.expanduser("~"), "Desktop")
    screenshot_path = os.path.join(desktop_path, "screenshot.png")

    return screenshot

def perform_ocr_and_copy_to_clipboard():
    # 等待用户手动画框
    input("按 Enter 键开始截图并进行OCR...")

    # 截取活动窗口的截图
    screenshot = get_screenshot()

    # 进行OCR识别
    ocr_result = pytesseract.image_to_string(screenshot)

    # 复制OCR识别结果到剪贴板
    pyperclip.copy(ocr_result)
    print("OCR识别结果已复制到剪贴板:", ocr_result)

if __name__ == "__main__":
    try:
        while True:
            perform_ocr_and_copy_to_clipboard()
    except KeyboardInterrupt:
        print("退出程序")
