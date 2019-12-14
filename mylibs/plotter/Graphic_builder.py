import matplotlib.pyplot as plt
import sys


def my_key(a):
    return a[0]


if len(sys.argv) == 1:
    print("Specify path!!!")
    in_file_path = input()
else:
    in_file_path = sys.argv[1]
data = open(in_file_path, "r").read().strip()

sorting = False
if len(sys.argv) == 3:
    if int(sys.argv[2]):
        sorting = True


if data.find(";") == -1:
    xs = []
    ys = []

    data = data.split("\n")
    for i in range(len(data)):
        x, y = data[i].split()
        xs.append(float(x))
        ys.append(float(y))

    plt.plot(xs, ys)
    plt.show()
else:
    datas = data.split(";")
    for func in datas:
        xs = []
        ys = []
        vals = func.split("\n")
        for i in range(len(vals)):
            if vals[i] == " " or vals[i] == "\n" or vals[i] == "":
                continue
            x, y = vals[i].split(" ")
            xs.append(float(x))
            ys.append(float(y))
        if sorting:
            all_ms = []
            for i in range(len(xs)):
                all_ms.append((xs[i], ys[i]))
            
            all_ms.sort(key=my_key)
            xs = []
            ys = []
            for i in all_ms:
                xs.append(i[0])
                ys.append(i[1])
        plt.plot(xs, ys)
    plt.show()