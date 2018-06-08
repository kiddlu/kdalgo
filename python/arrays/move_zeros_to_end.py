"""
Write an algorithm that takes an array and moves all of the zeros to the end,
preserving the order of the other elements.
    move_zeros([false, 1, 0, 1, 2, 0, 1, 3, "a"])
    returns => [false, 1, 1, 2, 1, 3, "a", 0, 0]
The time complexity of the below algorithm is O(n).
"""

def move_zeros(array):
    result = []
    zeros = 0

    for i in array:
        if i is 0:  # not using `not i` to avoid `False`, `[]`, etc.
            zeros += 1
        else:
            result.append(i)
    
    result.extend([0] * zeros)
    return result

#arr = ['a', 0, 7, 1, False, 3, 8, 12, 0, 55]
#print(move_zeros(arr))