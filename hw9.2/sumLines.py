"""
sumLines.py - Compute sum, count, and average of numbers in a file

This script reads a text file where each line contains space-separated integers. It computes the sum of these integers,
the number of integers, and the average of these integers.

Command Line Arguments:
1. Text file name (e.g., dataInput.txt)

Example Invocation:
python3 sumLines.py dataInput.txt
"""

import sys

def main():
    # Check that the user has provided a filename
    if len(sys.argv) != 2:
        print("Usage: python3 sumLines.py <filename>")
        return
    
    filename = sys.argv[1]
    
    try:
        with open(filename, 'r') as file:
            total = 0
            count = 0
            
            for line in file:
                # Split the line into numbers and convert them to integers
                numbers = list(map(int, line.split()))
                
                # Add the numbers to the total and increment the count
                total += sum(numbers)
                count += len(numbers)
            
            # Calculate the average
            average = total / count if count != 0 else 0

            # Print the results
            print(total, count, average)
    except FileNotFoundError:
        print(f"File {filename} not found.")

if __name__ == "__main__":
    main()
