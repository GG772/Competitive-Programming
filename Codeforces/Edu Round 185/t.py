f = lambda t : (player, (gis, 1))

a = [("lebron", 2.0), ("lebron", 3.0), ("lebron", 4.0)]

result = map(lambda t : (t[0], (t[1], 1)), a)
result = list(result)
print(result)