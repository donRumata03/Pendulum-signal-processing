import matplotlib.pyplot as plt
import sys

#  in_file_path = "D:\\Projects\\Experiments\\Pendulum_signal_processing\\src\\python\\data_to_plot.txt"

in_file_path = sys.argv[1]
data = open(in_file_path, "r").read().strip()

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
        plt.plot(xs, ys)
    plt.show()