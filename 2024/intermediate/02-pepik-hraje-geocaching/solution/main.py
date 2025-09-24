s = input()
chars_lower = "abcdefghijklmnopqrstuvwxyz"
chars_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
trans_lower = chars_lower[13:] + chars_lower[:13]
trans_upper = chars_upper[13:] + chars_upper[:13]

rot_char = lambda c: trans_lower[chars_lower.find(c)] if c in chars_lower else trans_upper[chars_upper.find(c)] if c in chars_upper else c

print(''.join(rot_char(c) for c in s))