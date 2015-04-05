1) What is this all about?

The task is to make a GUI enabled Sudoku solver.
The GUI has already been made for you. Your task is to implement the backtracking algorithm
which will solve the board.

Before implementing the backtracking algorithm, understand what the rest of the code is doing.
For the GUI part of the code, only a surface level understanding is enough. You should understand
the flow of the program.

The function that you need to implement is called "solveBoard". This function receives a variable
called "board" which points to a 9x9 integer array. Initially, each cell contains a number between
0-9. A 0 in an entry indicates that the cell is unsolved. Your task is to use backtracking to fill
the correct numbers in the board.
Note that you should not change the non-zero numbers in the cells given during the input. Your task
is to fill only the cells with the 0 entries.

You can assume that a valid board is passed to the "solveBoard" function. A valid board has entries
only from 0-9 for each cell. As said earlier, 0 indicates an unsolved cell. Any other number from 1-9
in a cell indicates that you need to retain these numbers in the solved board as they are the input
numbers. Finally, your board should have a number from 1-9 for each cell.

2) How do I compile and run?

Compilation:
gcc -Wall -g sudoku.c -o sudoku `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`

Or

Use the make file.

Run:
./sudoku


3) Implemented the code. What next?

Now you can test your code by either filling the GUI with your own numbers or by loading a file
by using the menu bar. Note that you have been given some sample test boards in the folder "testBoards".
For checking whether your program works fine, you can start solving by loading these files.
If a cell is empty or has a 0 or has any random character other than a number between 1 and 9, it is
treated as a 0.

If your code is correct, on clicking the "Solve" button in the GUI for a given input board, the 
board should show the final solved sudoku and the terminal will display "The Solved Board is valid."

If the solved sudoku is incorrect, the displayed GUI board will not change and the terminal will
display "The solved board is invalid." along with the reason why it is invalid.
If the board still has unsolved cells, the message displayed will be "The board has not been solved yet."

Your code will be tested with private test cases at the time of evaluation.

4) What if the GUI doesn't work?

If the GUI doesn't work, then a working code with terminal displayed Sudoku needs to be shown. For this,
you'll need to code Sudoku on your own without using the given code. Your code should also have a board
verification code which checks whether the final solved board is a valid Sudoku solution or not.

5) Points break up?

Sudoku, fully working with the provided code (GUI etc.) fetches 40 points out of 100. Whereas, a terminal displayed
verified Sudoku solution fetches 30 out of 100.
