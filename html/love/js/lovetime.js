function lovetime() {
    setInterval(function () {
        var t1 = new Date(2024, 0, 1, 0, 0, 0); // 将月份调整为0表示1月
        var today = new Date();
        var diff = today - t1;
        var diffYears = Math.floor(diff / (365.25 * 24 * 60 * 60 * 1000));
        var remainingMillis = diff % (365.25 * 24 * 60 * 60 * 1000);
        var diffDays = Math.floor(remainingMillis / (24 * 60 * 60 * 1000));
        remainingMillis %= 24 * 60 * 60 * 1000;
        var diffHours = Math.floor(remainingMillis / (60 * 60 * 1000));
        remainingMillis %= 60 * 60 * 1000;
        var diffMinutes = Math.floor(remainingMillis / (60 * 1000));
        remainingMillis %= 60 * 1000;
        var diffSeconds = Math.floor(remainingMillis / 1000);
        document.getElementById("lovetime").innerHTML = "我们已经在一起 " + diffYears + "年" + diffDays + "天" +
            diffHours + "小时" + diffMinutes + "分钟" + diffSeconds + "秒啦";
    }, 1000);
}
lovetime();
