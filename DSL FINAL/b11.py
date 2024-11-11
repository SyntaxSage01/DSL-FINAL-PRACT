
'''
Name : Kashvi Goyal
Roll No : 15
PRN No : F23112017
Class : SE-II(P-Batch)
'''

#Problem Statement B11

'''
a) Write a Python program to store roll numbers of student in array who attended 
training program in random order. Write function for searching whether particular 
student attended training program or not, using Linear search and Sentinel search. 
b) Write a Python program to store roll numbers of student array who attended training 
program in sorted order. Write function for searching whether particular student 
attended training program or not, using Binary search and Fibonacci search
'''

# Binary Search
def binarySearch(roll, target):
    low, high = 0, len(roll) - 1
    while low <= high:
        mid = (low + high) // 2
        if roll[mid] == target:
            print(f"Element found at index {mid}")
            return
        elif roll[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    print("Element not found")


# Fibonacci Search
def fibonacciSearch(roll, target):
    fib2 = 0
    fib1 = 1
    fib = fib1 + fib2
    n = len(roll)

    while fib < n:
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2
    offset = -1

    while fib > 1:
        i = min(offset + fib2, n - 1)
        if roll[i] < target:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif roll[i] > target:
            fib = fib2
            fib1 -= fib2
            fib2 = fib - fib1
        else:
            print(f"Element found at index {i}")
            return

    if fib1 and roll[offset + 1] == target:
        print(f"Element found at index {offset + 1}")
    else:
        print("Element not found")


# Linear Search
def linearSearch(roll, target):
    for i in range(len(roll)):
        if roll[i] == target:
            print(f"Element found at index {i}")
            return
    print("Element not found")


# Sentinel Search
def sentinelSearch(roll, target):
    n = len(roll)
    last = roll[n-1]
    roll[n-1] = target
    i = 0
    while roll[i] != target:
        i += 1
    roll[n-1] = last

    if i < n-1 or roll[n-1] == target:
        print(f"Element found at index {i}")
    else:
        print("Element not found")


def main():
    while True:
        print("\nMain Menu:")
        print("1. Sorted Array Search")
        print("2. Unsorted Array Search")
        print("3. Exit")

        choice = input("Enter your choice (1, 2, or 3): ")

        if choice == '1':
            n = int(input("Enter number of students who attended the training program: "))
            rollNumbers = []
            print("Enter roll number of each student: ")
            for i in range(n):
                roll = int(input())
                rollNumbers.append(roll)
            print("List of roll numbers who attended training program in sorted order:", rollNumbers)

            while True:
                print("\nSorted Array Search Menu:")
                print("1. Binary Search")
                print("2. Fibonacci Search")
                print("3. Exit")

                sortedChoice = input("Enter your choice (1, 2, or 3): ")

                if sortedChoice == '1':
                    target = int(input("Enter the roll number of the student to search: "))
                    binarySearch(rollNumbers, target)
                    return
                elif sortedChoice == '2':
                    target = int(input("Enter the roll number of the student to search: "))
                    fibonacciSearch(rollNumbers, target)
                    return
                elif sortedChoice == '3':
                    break
                else:
                    print("Invalid choice, please select 1, 2, or 3.")

        elif choice == '2':
            n = int(input("Enter number of students who attended the training program: "))
            roll = []
            print("Enter roll number of each student: ")
            for i in range(n):
                no = int(input())
                roll.append(no)
            print("List of roll numbers who attended training program in random order:", roll)

            while True:
                print("\nUnsorted Array Search Menu:")
                print("1. Linear Search")
                print("2. Sentinel Search")
                print("3. Exit")

                unsortedChoice = input("Enter your choice (1, 2, or 3): ")

                if unsortedChoice == '1':
                    target = int(input("Enter the roll number of the student to search: "))
                    linearSearch(roll, target)
                    return
                elif unsortedChoice == '2':
                    target = int(input("Enter the roll number of the student to search: "))
                    sentinelSearch(roll, target)
                    return
                elif unsortedChoice == '3':
                    break
                else:
                    print("Invalid choice, please select 1, 2, or 3.")

        elif choice == '3':
            print("Exiting...")
            break
        else:
            print("Invalid choice, please select 1, 2, or 3.")


main()