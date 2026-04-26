import pandas as pd

# Q1-Q4: Load and inspect
df = pd.read_csv('student_data.csv')
print("Q1:\n", df.head())
print("Q2 (Rows, Cols):", df.shape)
print("Q3 Schema:\n", df.dtypes)
print("Q4 Missing:\n", df.isnull().sum())

# Q5-Q7: Handle missing values & duplicates
df['Marks'] = df['Marks'].fillna(df['Marks'].mean())
df['Attendance'] = df['Attendance'].fillna(0)
df = df.drop_duplicates()

# Q8, Q9, Q16: Sorting and Filtering
print("\nQ8 Sorted:\n", df.sort_values(by='Marks', ascending=False))
print("\nQ9 Marks > 80:\n", df[df['Marks'] > 80])
print("\nQ16 Age 20-22:\n", df[(df['Age'] >= 20) & (df['Age'] <= 22)])

# Q10-Q12, Q15, Q18: Creating new columns/DataFrames
new_df = df[['Name', 'Marks']]
df['Total_Score'] = df['Marks'] + df['Attendance']
df['Result'] = df['Marks'].apply(lambda x: 'Pass' if x >= 40 else 'Fail')
df['Rank'] = df['Marks'].rank(ascending=False)
df['Performance'] = df['Marks'].apply(lambda x: 'High' if x>=85 else ('Medium' if x>=70 else 'Low'))

# Q13, Q14, Q19: Calculations and Stats
print("\nQ13 Averages:\n", df[['Marks', 'Attendance']].mean())
print("\nQ14 Age Counts:\n", df['Age'].value_counts())
print("\nQ19 Correlation:", df['Marks'].corr(df['Attendance']))

# Q17 & Q20: Normalize and Save (Done last so it doesn't mess up Q18)
df['Marks'] = (df['Marks'] - df['Marks'].min()) / (df['Marks'].max() - df['Marks'].min())
df.to_csv('cleaned_student_data.csv', index=False)
print("\nQ20: File saved as 'cleaned_student_data.csv'")