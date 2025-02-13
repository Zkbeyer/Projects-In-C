# CMP_SC 3050 FS2024
****SUBMIT THIS AS lab01****
# Assignment 1: Implement Insertion Sort

## Description

You are to implement Insertion Sort as a function similar to the
Standard C Library's qsort function. If you are unfamiliar with qsort,
you can of course google it, but a better alternative might be to login
to tc.rnet.missouri.edu and use the "man" command to get documentation
specific to tc.rnet.missouri.edu (i.e., "man qsort").

You are given a main() program, a Makefile, a library, and some starter
code for your sorting function. All you need to do is complete the
actual code for the function insertionsort() in the provided sort.c
file.

## How to Get Started

The starter code is publicly available on GitHub. You can clone it using
git via the following command:

> git clone <https://github.com/angrynarwhal/cs3050fs2024a1>

I recommend you clone this code somewhere under your home directory on
tc.rnet.missouri.edu. You are welcome to clone this and work on your
code on any platform you like. However, you should be aware that
submissions will **[[only]{.underline}]{.mark}** be evaluated by the TAs
on tc.rnet.missouri.edu. If, for example, something works on your
machine but doesn't compile on tc.rnet.missouri.edu, you will get a
zero.

Once you have cloned things down, you should cd to the newly cloned
directory and type "make". This will build the code and leave you with
an executable file called "mysort". The mysort program should work for
bubble sort and quick sort. However, it would be best if you implemented
insertion sort (out of the box, this sort will do nothing).

## Notes

-   You should not need to change files except sort.c. After completing
    the assignment, submit only sort.c on Canvas. The TAs will clone
    fresh starter code down and copy in your sort.c to evaluate it.

-   Notice that the function you are writing is already prototyped in
    sort.h and an empty stub is available in sort.c.

-   If you want to swap the positions of two items in your data
    structure, you **[[must]{.underline}]{.mark}** use the provided
    Swap() function to do this. Take a look at the provided bubblesort()
    function to understand how Swap() can be used.

-   If you want to assign one item to another (not swap them), you
    **[[must]{.underline}]{.mark}** use the Copy() function from
    cs3050.h. This will work whether your item is an int, a float, a
    struct, or whatever.

-   Notice that the tests try each function with a two int arrays and an
    array of structures (Customers). The Customer array is to be sorted
    first by lastname, firstname and then it is sorted again by age.

-   You don't need to worry about writing a Compare() function, as an
    appropriate one will be passed to you during testing. If you find it
    hard to think about how Compare() works, you might look at the
    Standard C Library function strcmp(). That function compares two
    strings and is an example of a Compare() function. A specific
    Compare() function must be used to allow the sort functions to
    compare elements of specific types (i.e., strcmp() knows how to
    compare strings, but you would need something else to compare ints,
    floats, structs, etc.).

-   You can certainly add your own functions to sort.c to break the
    problem down more. There should not be a need to add prototypes to
    sort.h.

## Sample Output
```bash
jimr@JimRBeastCanyon:\~/CS3050\$ ./mysort

Bubble Sort:

\-\-\-\-\-\-\-\-\-\-\-\-\--

\*\*\*\*\* Integers:

-\> 9 items: 23 -1 15 700 10 1 2 3 -99

-\> 9 items: -99 -1 1 2 3 10 15 23 700

\*\* Comparisons = 72, Swaps = 25, Copies = 0 \*\*

\*\*\*\*\* More Integers:

-\> 46 items: 9999 8888 -9999 -8888 7777 6666 1111 2222 3333 -7777 4444
1 2 3 7 6 5 4 3 2 1 1 0 -1 -2 -3 -4 10000 19 18 8 8 8 9 9 9 10 9 11 12
13 14 15 18 18 -7777

-\> 46 items: -9999 -8888 -7777 -7777 -4 -3 -2 -1 0 1 1 1 2 2 3 3 4 5 6
7 8 8 8 9 9 9 9 10 11 12 13 14 15 18 18 18 19 1111 2222 3333 4444 6666
7777 8888 9999 10000

\*\* Comparisons = 2070, Swaps = 483, Copies = 0 \*\*

\*\*\*\*\* Customers by Lastname, Firstname:

-\> 10 items: Jim Ries (56), Larry Ries (54), Robert Bisby (56), Cisco
Ries (13), Albert Pujols (42), Adam Wainwright (40), Yadier Molina (39),
David Polly (56), Bill Moser (54), Neil Blanck (53),

-\> 10 items: Robert Bisby (56), Neil Blanck (53), Yadier Molina (39),
Bill Moser (54), David Polly (56), Albert Pujols (42), Cisco Ries (13),
Jim Ries (56), Larry Ries (54), Adam Wainwright (40),

\*\* Comparisons = 90, Swaps = 31, Copies = 0 \*\*

\*\*\*\*\* Customers by Age:

-\> 10 items: Cisco Ries (13), Yadier Molina (39), Adam Wainwright (40),
Albert Pujols (42), Neil Blanck (53), Bill Moser (54), Larry Ries (54),
Robert Bisby (56), David Polly (56), Jim Ries (56),

\*\* Comparisons = 90, Swaps = 24, Copies = 0 \*\*

Insertion Sort:

\-\-\-\-\-\-\-\-\-\-\-\-\--

\*\*\*\*\* Integers:

-\> 9 items: 23 -1 15 700 10 1 2 3 -99

-\> 9 items: -99 -1 1 2 3 10 15 23 700

\*\* Comparisons = 31, Swaps = 0, Copies = 41 \*\*

\*\*\*\*\* More Integers:

-\> 46 items: 9999 8888 -9999 -8888 7777 6666 1111 2222 3333 -7777 4444
1 2 3 7 6 5 4 3 2 1 1 0 -1 -2 -3 -4 10000 19 18 8 8 8 9 9 9 10 9 11 12
13 14 15 18 18 -7777

-\> 46 items: -9999 -8888 -7777 -7777 -4 -3 -2 -1 0 1 1 1 2 2 3 3 4 5 6
7 8 8 8 9 9 9 9 10 11 12 13 14 15 18 18 18 19 1111 2222 3333 4444 6666
7777 8888 9999 10000

\*\* Comparisons = 526, Swaps = 0, Copies = 573 \*\*

\*\*\*\*\* Customers by Lastname, Firstname:

-\> 10 items: Jim Ries (56), Larry Ries (54), Robert Bisby (56), Cisco
Ries (13), Albert Pujols (42), Adam Wainwright (40), Yadier Molina (39),
David Polly (56), Bill Moser (54), Neil Blanck (53),

-\> 10 items: Robert Bisby (56), Neil Blanck (53), Yadier Molina (39),
Bill Moser (54), David Polly (56), Albert Pujols (42), Cisco Ries (13),
Jim Ries (56), Larry Ries (54), Adam Wainwright (40),

\*\* Comparisons = 39, Swaps = 0, Copies = 49 \*\*

\*\*\*\*\* Customers by Age:

-\> 10 items: Cisco Ries (13), Yadier Molina (39), Adam Wainwright (40),
Albert Pujols (42), Neil Blanck (53), Bill Moser (54), Larry Ries (54),
Robert Bisby (56), David Polly (56), Jim Ries (56),

\*\* Comparisons = 30, Swaps = 0, Copies = 42 \*\*

Quick Sort:

\-\-\-\-\-\-\-\-\-\-\-\-\--

\*\*\*\*\* Integers:

-\> 9 items: 23 -1 15 700 10 1 2 3 -99

-\> 9 items: -99 -1 1 2 3 10 15 23 700

\*\* Comparisons = 19, Swaps = 0, Copies = 0 \*\*

\*\*\*\*\* More Integers:

-\> 46 items: 9999 8888 -9999 -8888 7777 6666 1111 2222 3333 -7777 4444
1 2 3 7 6 5 4 3 2 1 1 0 -1 -2 -3 -4 10000 19 18 8 8 8 9 9 9 10 9 11 12
13 14 15 18 18 -7777

-\> 46 items: -9999 -8888 -7777 -7777 -4 -3 -2 -1 0 1 1 1 2 2 3 3 4 5 6
7 8 8 8 9 9 9 9 10 11 12 13 14 15 18 18 18 19 1111 2222 3333 4444 6666
7777 8888 9999 10000

\*\* Comparisons = 183, Swaps = 0, Copies = 0 \*\*

\*\*\*\*\* Customers by Lastname, Firstname:

-\> 10 items: Jim Ries (56), Larry Ries (54), Robert Bisby (56), Cisco
Ries (13), Albert Pujols (42), Adam Wainwright (40), Yadier Molina (39),
David Polly (56), Bill Moser (54), Neil Blanck (53),

-\> 10 items: Robert Bisby (56), Neil Blanck (53), Yadier Molina (39),
Bill Moser (54), David Polly (56), Albert Pujols (42), Cisco Ries (13),
Jim Ries (56), Larry Ries (54), Adam Wainwright (40),

\*\* Comparisons = 23, Swaps = 0, Copies = 0 \*\*

\*\*\*\*\* Customers by Age:

-\> 10 items: Cisco Ries (13), Yadier Molina (39), Adam Wainwright (40),
Albert Pujols (42), Neil Blanck (53), Bill Moser (54), Larry Ries (54),
Robert Bisby (56), David Polly (56), Jim Ries (56),

\*\* Comparisons = 23, Swaps = 0, Copies = 0 \*\*
```
