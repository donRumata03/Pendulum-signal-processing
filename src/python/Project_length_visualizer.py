import matplotlib
import json

data_path = "D:\\Projects\\Video_anal\\Machine_Learning\\support\\project_stat.json"

data = list(map(float, open(data_path, "r").read().strip().split("\n")))

index = 1
plot_or_not = {"Total number of symbols in project": True, "Total number of lines in project": True,
                "Average line length": False, 3: "", 4: "", 5:""}



while index < len(data):
    this_time = data[index]
    this_val = data[index + 1]
    index += 2