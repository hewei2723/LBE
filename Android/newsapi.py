from flask import Flask, Response
import csv
import json
import os

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
