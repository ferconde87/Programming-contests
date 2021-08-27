filename = "mr_x_input.txt"
with open(filename) as file:
  t = int(file.readline())
  output = open('output.txt', 'w')
  for k in range(1,t+1):
    s = file.readline()
    x = 1
    X = 0
    ans1 = eval(s)
    x = 0
    X = 1
    ans2 = eval(s)
    if ans1 == ans2:
      output.write('Case #{0}: 0\n'.format(k))
    else:
      output.write('Case #{0}: 1\n'.format(k))
file.close()
output.close()
