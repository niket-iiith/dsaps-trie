# TRIE-HARDER

## Problem Statement:
Design an efficient spell checker using the Trie data structure which supports the functionalities mentioned below.
1. Spell Check: Check if the input string is present in the dictionary.
2. Autocomplete: Find all the words in the dictionary which begin with the given input. 3. Autocorrect: Find all the words in the dictionary which are at an edit distance(Levenshtein distance) of at most 3 from the given input.

## Input Format:
- First line will contain two space separated integers n, q which represents the number of words in the dictionary and the number of queries to be processed respectively.
- Next n lines will contain a single string s which represents a word in the dictionary.
- Next q lines will contain two space separated values, First one will be an integer ai and second will be a string ti.
- ai = 1 means Spell Check operation needs to be done on ti. - ai = 2 means Autcomplete operation needs to be done on ti. - ai = 3 means Autocorrect operation needs to be done on ti.
- Both strings s and t consist of lowercase English letters.

## Output Format:
For each query print the result in a new line.
- Spell check: Print ‘1’ if string is present in the dictionary, otherwise ‘0’.
- Autocomplete & Autocorrect: Print the number of words in the first line. The following lines will be the set of words in lexicographical order

### Constraints:
1 <= n <= 1000
1 <= q <= 1000
1 <= len(s) <= 100 1 <= len(ti) <= 110

### Sample Input:
10 4 
consider filters filers entitled tilers litter dames filling grasses fitter
1 litter 
1 dame 
2 con 
3 filter

### Sample Output:
1 
0 
1 consider 
5 filers filters fitter litter tilers

#### Note:
1. Only trie should be used for storing the words in the dictionary.
2. You are allowed to use vector for this problem
