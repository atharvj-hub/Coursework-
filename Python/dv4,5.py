import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

print("--- Q10: Pairplot Visualization ---")
file10 = input("Enter Q10 CSV filename (e.g. data.csv): ").strip()
try:
    df10 = pd.read_csv(file10)
    sns.pairplot(df10)
    plt.suptitle('Multi-Feature Pairplot (Q10)', y=1.02)
    plt.show() # This generates Image 4. Close the window to see the next plot.
except FileNotFoundError:
    print(f"Error: {file10} not found.")

print("--- Q14: CSV Dataset Visualization ---")
file14 = input("Enter Q14 dataset filename (e.g. students.csv): ").strip()
try:
    df14 = pd.read_csv(file14)
    fig, axes = plt.subplots(1, 3, figsize=(15, 5))

    sns.histplot(df14['Marks'], bins=10, color='cyan', ax=axes[0])
    axes[0].set_title('Histogram of Marks')

    sns.boxplot(y=df14['Attendance'], color='magenta', ax=axes[1])
    axes[1].set_title('Boxplot of Attendance')

    sns.scatterplot(x='StudyHours', y='Marks', data=df14, color='red', ax=axes[2])
    axes[2].set_title('Study Hours vs Marks')

    plt.tight_layout()
    plt.show() # This generates Image 5.
except FileNotFoundError:
    print(f"Error: {file14} not found.")