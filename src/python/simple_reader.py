import re

filename = "D:\\Projects\\Experiments\\Pendulum_signal_processing\\res\\input\\Less_than_30\\First\\1.txt"
fout = "D:\\Projects\\Experiments\\Pendulum_signal_processing\\src\\python\\read_test.txt"

file = open(filename, "r")
ms = []
file_out = open(fout, "w")


while True:
    s = file.readline()
    if s == "":
        break
    s = s.replace("\t", " ")
    file_out.write(s)
    file_out.write("\n")
    ms.append(s)

print(ms)
