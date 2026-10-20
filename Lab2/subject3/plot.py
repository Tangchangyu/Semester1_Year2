import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# 1. 读取 C++ 导出的 CSV 数据文件
csv_path = (
    "/Users/shanfe/Documents/code/Semester1_year2/Lab2/subject3/algorithm_performance.csv"
)
df = pd.read_csv(csv_path)

# 将溢出标记（-1）替换为 np.nan，这样 matplotlib 能自动识别并跳过
df.replace(-1, np.nan, inplace=True)

# 2. 创建画布并设置大小
plt.figure(figsize=(10, 6))

# 3. 绘制四条算法性能对比曲线
plt.plot(
    df["n"],
    df["F1a_Iterative"],
    marker='o',
    linewidth=2,
    label="F1a (Direct Iterative)",
)
plt.plot(
    df["n"],
    df["F1b_Recursive"],
    marker='s',
    linewidth=2,
    linestyle='--',
    label="F1b (Direct Recursive)",
)
plt.plot(
    df["n"],
    df["F2a_Iterative"],
    marker='^',
    linewidth=2,
    label="F2a (Horner Iterative)",
)
plt.plot(
    df["n"],
    df["F2b_Recursive"],
    marker='d',
    linewidth=2,
    linestyle='--',
    label="F2b (Horner Recursive)",
)

# 4. 图表细节与样式美化
plt.title(
    "Algorithm Execution Time Comparison for Polynomial Calculation",
    fontsize=14,
    fontweight="bold",
)
plt.xlabel("Polynomial Degree (n)", fontsize=12)
plt.ylabel("Execution Time (seconds)", fontsize=12)
plt.grid(True, linestyle="--", alpha=0.6)
plt.legend(fontsize=11, loc="upper left")

# 5. 自动调整布局，保存高分辨率图片并显示
plt.tight_layout()
plt.savefig("algorithm_comparison.png", dpi=300)
print("折线图已成功保存为 'algorithm_comparison.png'！")
plt.show()