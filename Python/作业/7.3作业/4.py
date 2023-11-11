data = []
while True:
    try:
        line = input()
        if line:
            data.append(line.split())
        else:
            break
    except EOFError:
        break

max_score = float('-inf')
min_score = float('inf')
max_course = ""
min_course = ""
total_score = 0
count = 0

for course, score in data:
    score = int(score)
    total_score += score
    count += 1
    if score > max_score:
        max_score = score
        max_course = course
    if score < min_score:
        min_score = score
        min_course = course

average_score = total_score / count
print(f"最高分课程是{max_course} {max_score},最低分课程是{min_course} {min_score},平均分是{average_score:.2f}")