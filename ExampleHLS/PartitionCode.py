
#
# Check if the integer x encodes a solution to the partition problem
#
def check(x,n,values):
    mask = 1
    sum0s = 0
    sum1s = 0
    for i in range(n):
        if mask & x != 0:
            sum1s = sum1s + values[i]
        else:
            sum0s = sum0s + values[i]
        mask = mask*2

    if sum0s == sum1s:
        return True
    else:
        return False 


# main
# read n
#n = int(input("How large is the instance of the partition problem (positive integer\n)"))
n = int(input(""))

values = []
for i in range(n):
# value = int(input("Enter a value: "))
    value = int(input(""))
    values.append(value)


twoToN = pow(2,(n-1)) 
#print(twoToN)
found = False
for x in range(twoToN):
    result = check(x,n,values)
    if result:
        print('Solution found!\nDecimal code: ')
        print(x)
        found = True
        break

    if not found:
        print('Solution not found.')

