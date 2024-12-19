from flask import Flask, Response
import random
import json
import os
import csv

app = Flask(__name__)

# 创建CSV文件并写入数据，但只有在文件不存在时才创建
def create_csv():
    if not os.path.exists('data.csv'):
        data = [
            {"title": "今日热榜", "link": "https://tophub.today/"},
            {"title": "人民日报热榜", "link": "https://tophub.today/n/x9oz03bdXb"},
            {"title": "博客榜", "link": "https://www.lttac.cn/"},
            {"title": "标题4", "link": "https://example.com/4"},
            {"title": "标题5", "link": "https://example.com/5"},
            {"title": "标题6", "link": "https://example.com/6"},
            {"title": "标题7", "link": "https://example.com/7"}
        ]
        
        # 创建CSV文件并写入数据
        with open('data.csv', mode='w', newline='', encoding='utf-8') as csvfile:
            fieldnames = ['title', 'link']
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(data)

# 随机返回一句话
@app.route('/yiyan', methods=['GET'])
def get_quote():
    quotes = [
    "人生就像一场旅行，不必在乎目的地。",
    "成功的秘诀在于坚持自己的目标。",
    "生命短暂，时间宝贵，不要浪费在不重要的事情上。",
    "每天都是一个新的开始，保持乐观，迎接挑战。",
    "生活不是等待风暴过去，而是学会在雨中跳舞。",
    "与其担心未来，不如把握现在。",
    "不论你有多么努力，总会有自己的时机。",
    "一个人能走多远，取决于他有多么坚定的信念。",
    "不要害怕失败，害怕的是从未尝试。",
    "只要你勇敢迈出第一步，未来的一切都会更好。"
]

    return random.choice(quotes)  # 返回随机的一句话

@app.route('/get_data', methods=['GET'])
def get_data():
    data = []
    # 读取CSV文件
    try:
        with open('data.csv', newline='', encoding='utf-8') as csvfile:
            csvreader = csv.DictReader(csvfile)
            # 获取最多5条数据
            for i, row in enumerate(csvreader):
                if i >= 5:
                    break
                data.append(row)
    except FileNotFoundError:
        return Response('CSV file not found', status=404)
    response_data = json.dumps(data, ensure_ascii=False, indent=4)
    return Response(response_data, mimetype='application/json')

if __name__ == '__main__':
    create_csv()  # 只有在文件不存在时才创建CSV文件
    app.run(debug=True, host='0.0.0.0', port=5677)
