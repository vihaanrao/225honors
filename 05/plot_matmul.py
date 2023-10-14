import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file into a DataFrame
df = pd.read_csv('performance_metrics.csv')

# Get unique matrix sizes and thread counts for grouping
unique_sizes = df['MatrixSize'].unique()
unique_threads = df['ThreadCount'].unique()

# Create a single plot for all matrix sizes and thread counts
plt.figure(figsize=(12, 8))

for size in unique_sizes:
    subset = df[df['MatrixSize'] == size]

    for thread_count in unique_threads:
        thread_subset = subset[subset['ThreadCount'] == thread_count]
        plt.plot(thread_subset['ThreadCount'], thread_subset['TimeMillis'], marker='o', label=f'Size={size}, Threads={thread_count}')

plt.title('Matrix Multiplication Performance')
plt.xlabel('Number of Threads')
plt.ylabel('Time (milliseconds)')
plt.legend()
plt.grid(True)
plt.show()
