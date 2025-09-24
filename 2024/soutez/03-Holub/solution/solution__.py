

gb2mb = lambda x: 1024*x
mb2gb = lambda x: x/1024



if __name__ == '__main__':
    distance, capacity, velocity, landline_transfer_speed, file_n, file_size = [float(input()) for _ in range(6)]
    capacity = gb2mb(capacity)
    

    # maximum files we can fit on the homing pigeon
    hp_max_files = capacity//file_size

    # maximum gb capacity of pigeon
    hp_usable_capacity = hp_max_files*file_size # (Gb)

    # flight time of pigeon
    hp_flight_time = velocity/distance # (sec)
    
    
    # we need to find which option will take the longest
    # (pigeon travels parallely with landline data, one doesn't wait for the other to finish)
    max_t = 0 # (sec)


    # if homing pigeon has better transfer speed
    if gb2mb(hp_usable_capacity)/hp_flight_time <= landline_transfer_speed:
        # send maximum files over pigeon
        file_n -= hp_max_files
        # time for pigeon to reach endpoint
        max_t = hp_flight_time
        

    # time to send the rest of files over landline
    landline_time = gb2mb(file_n * file_size) / landline_transfer_speed # (sec)

    max_t = max(max_t, landline_time)

    print(int(max_t))