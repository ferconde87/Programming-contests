if __name__ == '__main__':
    n = int(input())
    student_marks = {}
    for _ in range(n):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores
    query_name = input()
    

    student_avg = {}
    for name in student_marks:
        avg = 0
        for marks in student_marks[name]:
            avg += marks
        avg /= 3
        student_avg[name] = avg
    print("{:.2f}".format(student_avg[query_name]))
