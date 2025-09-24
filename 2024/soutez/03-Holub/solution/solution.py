if __name__ == "__main__":
    import math

    # Input
    D = int(input())  # Distance in meters
    C = int(input())  # Capacity of pigeon in GB
    V = int(input())  # Velocity of pigeon in m/s
    P = float(input())  # Speed of fixed line in MB/s
    N = int(input())  # Number of files
    S = int(input())  # Size of each file in GB

    # Convert capacities to MB
    C_mb = C * 1024
    S_mb = S * 1024

    # Compute pigeon flight time
    flight_time = D / V  # Time in seconds

    # Max files the pigeon can carry
    pigeon_capacity_files = C_mb // S_mb

    # Files left to transfer over the fixed line
    remaining_files = N - pigeon_capacity_files

    # Total data size for remaining files in MB
    remaining_data_size = remaining_files * S_mb if remaining_files > 0 else 0

    # Fixed line transfer time
    fixed_line_time = remaining_data_size / P

    # Result is the maximum time of the two
    total_time = max(flight_time, fixed_line_time)
    print(int(total_time))
