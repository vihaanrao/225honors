import matplotlib.pyplot as plt
import pandas as pd

# Load the CSV data into a DataFrame
data = pd.read_csv('sorting_times.csv')

# Separate the data
sizes = data['Size']
std_sort_times = data['std::sort Time']
counting_sort_times = data['Counting Sort Time']

# Plotting
plt.figure(figsize=(10, 6))

plt.plot(sizes, std_sort_times, marker='o', label='std::sort')
plt.plot(sizes, counting_sort_times, marker='o', label='Counting Sort')

plt.xscale('log')
plt.yscale('log')

plt.title('Performance Comparison: std::sort vs Counting Sort')
plt.xlabel('Input Size (log scale)')
plt.ylabel('Time (s) (log scale)')

plt.legend()
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.tight_layout()

# Save the plot as a .png file
plt.savefig('sort_comparison_plot.png')

# Display the plot
plt.show()
