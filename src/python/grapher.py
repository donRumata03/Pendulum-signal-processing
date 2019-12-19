from matplotlib import pyplot as plt

def key(a):
    return a[0]

points = [(0.705318, -0.425423), (0.49851, -0.490319), (0.547212, -0.477662), \
    (0.36458, -0.526366), (0.421959, -0.514321), (0.352146, -0.530876), (0.428119, -0.52203), \
         (0.476693, -0.499432), (0.560445, -0.470761), (0.450706, -0.511672), (0.0802851, -0.655047), \
              (0.169079, -0.559079)]

sorted_points = sorted(points, key=key)
print(sorted_points)

xs = []
ys = []

for i in range(len(points)):
    xs.append(sorted_points[i][0])
    ys.append(points[i][1])

plt.plot(xs, ys)
plt.show()