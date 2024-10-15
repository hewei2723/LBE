import pyautogui
import time
import sys

# 设置自动化过程中的延迟（以秒为单位）
ACTION_DELAY = 0.5

# 定义屏幕坐标
INPUT_BOX_POS = (883, 510)          # 密码输入框
CONFIRM_BUTTON_POS = (895, 541)     # 确定按钮
ERROR_CONFIRM_BUTTON_POS = (956, 587)  # 错误提示框中的确定按钮

# 生成所有6位数密码（从000000到999999）
password_list = [f"{i:06d}" for i in range(1000000)]

def enter_password(password):
    """
    执行以下操作：
    1. 点击密码输入框
    2. 输入密码
    3. 点击确定按钮
    """
    # 点击密码输入框
    pyautogui.moveTo(INPUT_BOX_POS[0], INPUT_BOX_POS[1], duration=0.2)
    pyautogui.click()
    time.sleep(ACTION_DELAY)

    # 输入密码
    pyautogui.typewrite(password)
    time.sleep(ACTION_DELAY)

    # 点击确定按钮
    pyautogui.moveTo(CONFIRM_BUTTON_POS[0], CONFIRM_BUTTON_POS[1], duration=0.2)
    pyautogui.click()
    time.sleep(ACTION_DELAY)

def click_error_confirm():
    """
    尝试点击错误提示框中的确定按钮。
    如果提示框不存在，这一步可能会点击到其他地方。
    """
    pyautogui.moveTo(ERROR_CONFIRM_BUTTON_POS[0], ERROR_CONFIRM_BUTTON_POS[1], duration=0.2)
    pyautogui.click()
    time.sleep(ACTION_DELAY)

def main():
    """
    主函数，遍历所有密码并尝试输入。
    """
    for idx, password in enumerate(password_list):
        print(f"尝试密码 {idx + 1}/{len(password_list)}: {password}")
        enter_password(password)

        # 等待一段时间，让错误提示框弹出
        time.sleep(1.5)  # 根据实际情况调整等待时间

        # 尝试点击错误提示框的确定按钮
        # 如果错误提示框不存在，这一步将点击到错误位置，可能导致意外行为
        # 无法直接检测密码是否正确
        click_error_confirm()

        # 假设如果没有错误提示框，密码正确，退出脚本
        # 但无法实际检测到这一点，需手动验证
        # 因此，这种方法不推荐使用

    print("所有密码尝试完毕，未找到正确密码。")

if __name__ == "__main__":
    main()
