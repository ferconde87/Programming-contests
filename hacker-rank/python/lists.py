if __name__ == '__main__':
    N = int(input())
    a = []
    for _ in range(N):
        command = input().split()
        if command[0] == "insert":
            index = int(command[1])
            value = int(command[2])
            a.insert(index,value)
        elif command[0] == "append":
            value = int(command[1])
            a.append(value)
        elif command[0] == "remove":
            value = int(command[1])
            a.remove(value)
        elif command[0] == "print":
            print(a)
        elif command[0] == "pop":
            a.pop()
        elif command[0] == "reverse":
            a.reverse()
        elif command[0] == "sort":
            a.sort()
        else:
            print("Unknown command")
    

