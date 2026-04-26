import matplotlib.pyplot as plt

# --- Inputs ---
print("--- Q1: Line Plot ---")
n1 = int(input("Enter number of months (e.g. 6): "))
temps = list(map(int, input("Enter temperatures: ").split()))
months = list(range(1, n1 + 1))

print("--- Q2: Bar Chart ---")
n2 = int(input("Enter number of departments (e.g. 4): "))
departments = input("Enter department names: ").split()
students = list(map(int, input("Enter student counts: ").split()))

print("--- Q3: Histogram ---")
n3 = int(input("Enter number of students (e.g. 10): "))
marks_hist = list(map(int, input("Enter marks: ").split()))

print("--- Q4: Scatter Plot ---")
n4 = int(input("Enter number of records (e.g. 5): "))
study_hours = list(map(int, input("Enter study hours: ").split()))
marks_scatter = list(map(int, input("Enter marks: ").split()))

# --- Plotting ---
fig, axs = plt.subplots(2, 2, figsize=(12, 10))

# Q1 Line Plot
axs[0, 0].plot(months, temps, marker='o', linestyle='-')
axs[0, 0].set_title('Monthly Temperature Trend')
axs[0, 0].set_xlabel('Month')
axs[0, 0].set_ylabel('Temperature')

# Q2 Bar Chart
axs[0, 1].bar(departments, students, color='skyblue')
axs[0, 1].set_title('Department vs Students')
axs[0, 1].set_xlabel('Department')
axs[0, 1].set_ylabel('Number of Students')

# Q3 Histogram
axs[1, 0].hist(marks_hist, bins=[40, 50, 60, 70, 80, 90, 100], edgecolor='black', color='lightgreen')
axs[1, 0].set_title('Marks Distribution')
axs[1, 0].set_xlabel('Marks')
axs[1, 0].set_ylabel('Frequency')

# Q4 Scatter Plot
axs[1, 1].scatter(study_hours, marks_scatter, color='purple', marker='x')
axs[1, 1].set_title('Study Hours vs Marks')
axs[1, 1].set_xlabel('Study Hours')
axs[1, 1].set_ylabel('Marks')

plt.tight_layout()
plt.show()