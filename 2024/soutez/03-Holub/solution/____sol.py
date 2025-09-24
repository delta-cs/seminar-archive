D = int(input())  # Distance in meters
C = int(input())  # Pigeon capacity in GB
V = int(input())  # Pigeon velocity in m/s
P = float(input())  # Landline speed in MB/s
N = int(input())  # Number of files
S = int(input())  # Size of each file in GB

# Convert landline speed to GB/s
P = P / 1024

# Calculate flight time
flight_time = D / V

# Determine how many files the pigeon can carry
pigeon_files = min(N, C // S)  # Max files the pigeon can carry
remaining_files = N - pigeon_files  # Files left for landline transfer

# Calculate time for remaining files over landline
landline_time = remaining_files * S / P

# Total time is the longer of flight or landline transfer time
total_time = max(flight_time, landline_time)

# Output the result as an integer
print(int(total_time))
