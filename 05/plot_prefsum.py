import pandas as pd
import matplotlib.pyplot as plt

# Read the new CSV file into a DataFrame
df = pd.read_csv('prefix_sum_performance.csv')

# Unique array sizes and thread counts for grouping
unique_sizes = df['ArraySize'].unique()
unique_threads = df['ThreadCount'].unique()

# Create a single plot
plt.figure(figsize=(12, 8))

for size in unique_sizes:
    subset = df[df['ArraySize'] == size]
    
    for thread_count in unique_threads:
        thread_subset = subset[subset['ThreadCount'] == thread_count]
        plt.plot(thread_subset['ThreadCount'], thread_subset['TimeMillis'], marker='o', label=f'Size={size}, Threads={thread_count}')

plt.title('Parallel Prefix Sum Performance')
plt.xlabel('Number of Threads')
plt.ylabel('Time (milliseconds)')
plt.legend()
plt.grid(True)
plt.show()
