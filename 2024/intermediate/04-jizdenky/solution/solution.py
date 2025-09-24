number_of_days = int(input())
daily_ticket_price = int(input())
weekly_ticket_price = int(input())

total_daily_cost = number_of_days * daily_ticket_price

number_of_weeks = number_of_days / 7
total_weekly_cost = number_of_weeks * weekly_ticket_price

if total_daily_cost < total_weekly_cost:
    print("denni")
else:
    print("tydenni")