import matplotlib.pyplot as plt
import seaborn as sns

# --- Inputs ---
print("--- Q5: Semester Performance ---")
n5 = int(input("Enter number of semesters: "))
semesters = list(map(int, input("Enter semesters: ").split()))
student1 = list(map(int, input("Enter Student 1 marks: ").split()))
student2 = list(map(int, input("Enter Student 2 marks: ").split()))

print("--- Q6: Subject Boxplot ---")
math_input = input("Enter Math scores (Format -> Math: 78 85...): ")
physics_input = input("Enter Physics scores (Format -> Physics: 70 75...): ")
math_scores = list(map(int, math_input.split(':')[1].split()))
physics_scores = list(map(int, physics_input.split(':')[1].split()))

print("--- Q7: Grade Countplot ---")
grades_input = input("Enter grades string (e.g. ABACBABCA): ").strip()
grades_list = list(grades_input)

print("--- Q8: Customized Histogram ---")
n8 = int(input("Enter count: "))
data_hist2 = list(map(int, input("Enter data: ").split()))

# --- Plotting ---
fig, axs = plt.subplots(2, 2, figsize=(12, 10))

# Q5 Line Plots
axs[0, 0].plot(semesters, student1, marker='o', label='Student 1')
axs[0, 0].plot(semesters, student2, marker='s', label='Student 2')
axs[0, 0].set_title('Semester Performance Comparison')
axs[0, 0].set_xlabel('Semester')
axs[0, 0].set_ylabel('Marks')
axs[0, 0].legend()

# Q6 Boxplot
axs[0, 1].boxplot([math_scores, physics_scores], labels=['Math', 'Physics'])
axs[0, 1].set_title('Subject Score Comparison')
axs[0, 1].set_ylabel('Scores')

# Q7 Countplot
sns.countplot(x=grades_list, order=['A', 'B', 'C'], palette='Set2', ax=axs[1, 0])
axs[1, 0].set_title('Grade Frequency Countplot')
axs[1, 0].set_xlabel('Grades')
axs[1, 0].set_ylabel('Count')

# Q8 Custom Histogram
axs[1, 1].hist(data_hist2, bins=[10, 15, 20, 25, 30, 35], edgecolor='black', color='coral')
axs[1, 1].set_title('Customized Histogram')
axs[1, 1].set_xlabel('Values')
axs[1, 1].set_ylabel('Frequency')
axs[1, 1].grid(True, linestyle='--', alpha=0.7)

plt.tight_layout()
plt.show()