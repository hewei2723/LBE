from flask import Flask, render_template, request, redirect, url_for, session

app = Flask(__name__)
app.secret_key = 'your_secret_key'  # 设置一个密钥用于session管理

# 模拟的用户数据
users = {
    'admin': 'password123',
    'user': 'user123'
}

@app.route('/')
def home():
    return redirect(url_for('login'))

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        if username in users and users[username] == password:
            session['username'] = username
            return redirect(url_for('dashboard'))
        else:
            return render_template('login.html', error='用户名或密码错误')

    return render_template('login.html')

@app.route('/dashboard')
def dashboard():
    if 'username' in session:
        return f'欢迎, {session["username"]}!'
    return redirect(url_for('login'))

@app.route('/logout')
def logout():
    session.pop('username', None)
    return redirect(url_for('login'))

if __name__ == '__main__':
    app.run(debug=True) 