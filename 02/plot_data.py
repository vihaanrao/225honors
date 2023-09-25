import pandas as pd
import matplotlib.pyplot as plt

# load the CSV data into a pandas DataFrame
data = pd.read_csv('performance_data.csv')

# filter data for each data structure
list_data = data[data['Data Structure'] == 'List']
vector_data = data[data['Data Structure'] == 'Vector']

# plot insertion times
plt.figure(figsize=(10, 6))
plt.plot(list_data['Input Size'], list_data['Insertion Time (ms)'], label='List (Insertion)', marker='o')
plt.plot(vector_data['Input Size'], vector_data['Insertion Time (ms)'], label='Vector (Insertion)', marker='o')

# plot deletion times
plt.plot(list_data['Input Size'], list_data['Deletion Time (ms)'], label='List (Deletion)', linestyle='--', marker='x')
plt.plot(vector_data['Input Size'], vector_data['Deletion Time (ms)'], label='Vector (Deletion)', linestyle='--', marker='x')

plt.xscale('log')
plt.yscale('log')
plt.title('Performance Comparison: List vs. Vector')
plt.xlabel('Input Size')
plt.ylabel('Time (ms)')
plt.legend()
plt.grid(True, which="both", ls="--", c='0.7')
plt.tight_layout()
plt.show()
