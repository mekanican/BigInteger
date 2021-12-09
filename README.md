# "Fun" side project for Progamming Technique course.

1. What is this?
- This is a program to calculate big & simple expression, also provide a library for big integer by converting them to string.
- Our first project so it not so well implemented with mixing C and C++ style, make its own sluggish in most case :(
2. Installation
Simply compile every `cpp` file you see in this repository
```
g++ *.cpp -o main
```
3. Usage:
Provide program with 2 arguments:
- Path to a text file for input (can be relative or absolute)
- Path to a text file for output (contain result of calculation)
4. Text file for input structure: 3 types per line
- `[Base_1] [Base_2]` : Convert from `[Base_1]` to `[Base_2]`, they can only be pair of (10, 2) or (2, 10)
- `[Base] ~ [Number]` : Calculate `NEG` operation on `[Number]`, output the same base.
- `[Base] [Number_1] [operand] [Number_2]`: Calculate with arithmetic or bitwise operation between `[Number_1]` to `[Number_2]`
5. Example
Input***.txt provided in this repos.
# Thanks 💜
Special thank to [my teammate](https://github.com/vanloc1808)
