# Fred Wittman
# Robin Hill
# COSC 2030
# 06 May 2019

# This function calculates the total grocery bill based on the subtotals and then calculates the cost per person.
# The function showcases exception handling for ValueError and ZeroDivisionError.

def groceryBill():
    print("This function calculates the amount each person must pay towards the grocery bill.")
    try:
        i = int(input("How much was spent on produce?"))
        j = int(input("How much was spent on dairy?"))
        e = int(input("How much was spent on baked goods?"))
    except ValueError:
        print("Subtotal must be a number.  Exiting")
        return
    
    try: 
        r = int(input("How many people are splitting the cost?"))
        print("The cost per person for the grocery bill is " + str((i + j + e)/r) + " dollars.")
    except ValueError:
        print("The input for the number of people splitting the cost must be a number.")
        return
    
    except ZeroDivisionError:
        print("The number of people sharing the cost of the grocery bill cannot be zero.")
        return

groceryBill()
