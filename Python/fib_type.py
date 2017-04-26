fibonacci_numbers = [0, 1]

x=int(input(""))
y=int(input(""))


for i in range(2,700):
    fibonacci_numbers.append(x*fibonacci_numbers[i-1]+y*fibonacci_numbers[i-2])
    

print (fibonacci_numbers[10])
