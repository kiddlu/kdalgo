
#### Search algorithms
```
In computer science, a search algorithm is an algorithm that retrieves information stored within some data structure, or calculated in the search space of a problem domain. Data structures can include linked lists, arrays, search trees, hash tables, or various other storage methods. The appropriate search algorithm often depends on the data structure being searched.
```

* [Sequential Search](https://github.com/kiddlu/oh-my-algorithm/blob/master/c/algorithm/search/sequential_search.c) [(wiki)](https://en.wikipedia.org/wiki/Linear_search)
* [Binary Search](https://github.com/kiddlu/oh-my-algorithm/blob/master/c/algorithm/search/binary_search.c) [(wiki)](https://en.wikipedia.org/wiki/Binary_search_algorithm)
* [Jump Search](https://github.com/kiddlu/oh-my-algorithm/blob/master/c/algorithm/search/jump_search.c) [(wiki)](https://en.wikipedia.org/wiki/Jump_search)





|   method   |   avg   | best | worst  | space |     data struct      | ordered |
| :--------: | :-----: | :--: | :----: | :---: | :------------------: | :-----: |
| sequential |  O(n)   | O(1) |  O(n)  | O(1)  | array or linked list |    n    |
|   binary   | O(logn) | O(1) |  O(n)  | O(1)  |    ordered array     |    y    |
|    jump    | O(logn) | O(1) |  O(n)  | O(1)  |    ordered array     |    y    |
|    bst     | O(logn) | O(1) | O(*n*) | O(n)  | ordered search trees |    y    |
|    hash    |  O(1)   |      |        |       |     hash tables      |    y    |

