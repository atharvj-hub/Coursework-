import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# --- Inputs ---
print("--- Q9: Scatter Plot Categories ---")
n9 = int(input("Enter number of people: "))
print("Enter Height Weight Gender per line:")
data9 = []
for _ in range(n9):
    h, w, g = input().split()
    data9.append({'Height': int(h), 'Weight': int(w), 'Gender': g})
df9 = pd.DataFrame(data9)

print("--- Q11: Distribution Comparison ---")
n11 = int(input("Enter count for dataset: "))
data11 = list(map(int, input("Enter data: ").split()))
df11 = pd.DataFrame({'Values': data11})

# --- Plotting ---
fig, axs = plt.subplots(2, 2, figsize=(12, 10))

# Q9 Scatterplot
sns.scatterplot(data=df9, x='Height', y='Weight', hue='Gender', style='Gender', s=100, ax=axs[0, 0])
axs[0, 0].set_title('Height vs Weight by Gender')

# Q11 Histogram
sns.histplot(df11['Values'], bins=5, kde=True, color='blue', ax=axs[0, 1])
axs[0, 1].set_title('Distribution - Histogram')

# Q11 Boxplot
sns.boxplot(y=df11['Values'], color='orange', ax=axs[1, 0])
axs[1, 0].set_title('Distribution - Boxplot')

# Q11 Violin Plot
sns.violinplot(y=df11['Values'], color='green', ax=axs[1, 1])
axs[1, 1].set_title('Distribution - Violin Plot')

plt.tight_layout()
plt.show()