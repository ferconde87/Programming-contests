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
        student_avg[name] = sum(map(float,student_marks[name]))/3
    print("{:.2f}".format(student_avg[query_name]))
