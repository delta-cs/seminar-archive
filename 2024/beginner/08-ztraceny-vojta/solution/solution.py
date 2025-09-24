
actual_position_x = int(input())
actual_position_y = int(input())

z = int(input())

for i in range(z):
    ran_distance_x = int(input())
    ran_distance_y = int(input())
    actual_position_x += ran_distance_x
    actual_position_y += ran_distance_y

print(actual_position_x)
print(actual_position_y)