This readme file contains instructions to run the source code
of project: Applying Machine Learing To Process Scheduling. 

In /Program folder there are source code files of the programs we used in our project.

All of the programs are written using C programming language.

Each program has exactly one macro named 'INPUTSIZE' define inside it that defines the input size of that programs.
This macro can be editted using any text editor to change the input size of the programs.

Steps to compile the source code
1. Open the directory /Programs.
2. Open the programs with any text editor and edit the input size of programs.
3. Open the Linux terminal window and navigate to the /Programs folder.
4. Using the GCC compiler, compile the programs to generate the executable.
5. Commands to compile the source code
   $ gcc MatrixMultiplicationLong.c -o mat1500
   $ gcc Fibonacci.c -o fib46
   $ gcc bubble.c -o bub79903

6. Above instruction will geberate the executable named 'mat1500', 'fib46', 'bub79903'.
   
   Note: Throughout our project we followed this nomenclature for naming the executables.
   The first characters indicate the program name and last digits indicate the input size.
   For Example: 'mat1500' is an executable file of Matrix Multipmication program that multiplies
   two matrices of 1500 * 1500 dimension.

We have deliberately chosen high input size of the programs such that they take longer duration to finish 
their execution.
This helps us to accurately measure the change in turnaround time of any process.

The above generated programs must be run in parallel in order to get the most accurate results

Steps to run the programs in parallel.
1. Open the Linux terminal and navigate to the folder /Programs
2. Run the above executables in parallel by using the setsid command. 
3. Syntax is
   $ setsid ./fib46 && setsid ./mat1500 && setsid ./bub79903

Steps to compute the total turnaround time of each process.
1. Note which program was executed first.
2. Note the starting time of the program that was executed first.
3. Wait until all programs finish their execution.
4. Compute the total turnaround time of a process by subtracting the start time of first process from its finish time. 
5. Repeat the above step for all the  processes for calculating their respective turnaround time. 

