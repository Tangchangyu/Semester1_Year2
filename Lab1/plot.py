import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("binary_search_result.csv")
plt.plot(df["n"], df["avg_time_ns"], "o-")
plt.xlabel("n")
plt.ylabel("Average Time (ns)")
plt.title("BinarySearch Average Running Time")
plt.grid(True)
plt.savefig("binary_search.png", dpi=150)
plt.show()
