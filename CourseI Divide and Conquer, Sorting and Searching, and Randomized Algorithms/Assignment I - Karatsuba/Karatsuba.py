
# Babak Poursartip

def karatsuba(num1, num2):
    print("{:} {:d} {:d}".format(" the numbers are:",num1, num2))
    num1Str = str(num1)
    num2Str = str(num2)
    if (num1 < 10) or (num2 < 10):
        return num1*num2

    maxLength = max(len(num1Str), len(num2Str))
    splitPosition = maxLength / 2
    high1, low1= int(num1Str[:-splitPosition]), int(num1Str[-splitPosition:])
    high2, low2= int(num2Str[:-splitPosition]), int(num2Str[-splitPosition:])

    print("{:} {:d}  {:d}".format("num 1:",high1, low1))
    print("{:} {:d}  {:d}".format("num 2:",high2, low2))

    z0 = karatsuba(low1, low2)
    print("{:} {:d}".format("call 0: z0=", z0))
    z1 = karatsuba((low1 + high1), (low2 + high2))
    print("{:} {:d}".format("call 1: z1=", z1))
    z2 = karatsuba(high1, high2)
    print("{:} {:d}".format("call 2: z2=", z2))
    print("{:} {:d}".format(" final result is ", (z2*10**(2*splitPosition)) + ((z1-z2-z0)*10**(splitPosition))+z0))
    print("")

    return (z2*10**(2*splitPosition)) + ((z1-z2-z0)*10**(splitPosition))+z0


def main(arg):
  num1 = 123456
  num2 = 7891591

  print(" {:} {:d} {:d}".format("The two numbers are:", num1, num2))
  print("{:}".format(" Doing the calculations ..."))
  print("{:d} {:} {:d} {:} {:d}".format(num1, "*", num2,"=", karatsuba(num1,num2) ))
  print("done")


if __name__ == '__main__':
    import sys    
    main(sys.argv)
