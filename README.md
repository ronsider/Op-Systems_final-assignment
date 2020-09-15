# Final-assignment
Final assignment in "Opearting Systems" course.\
This assignment consists of all the relevant material that's been taught in the course.

* Memory layout of a program
* Processes and signals
* CPU scheduling
* Files in Linux


## Table of Contents  
[Prerequisite](#Prerequisite)  
[Question 1 Memory Layout](#Question-1-Memory-Layout)  
[Question 2 Signals](#Question-2-Signals)  
[Question 3 Cpu Scheduling](#Question-3-cpu-scheduling)  
[Question 4 Files in Linux](#Question-4-Files-Linux)

   

## Prerequisite 
###### The assignment was made on ubuntu distribution, thus install commands for various tools, may differ on different distributions.

* Linux based distribution.
* Ide for compiling the C program(Text Editor and compiler are enough)
* Debugger to assure answers are valid(GDB is preferable)  
Before you go for installation, check if you already have gdb installed on your Unix system by issuing the following command(linux terminal):  
<code> $gdb -help </code>

If GDB is installed, then it will display all the available options within your GDB. If GDB is not installed, then proceed for a fresh installation.
Use the following command to install gdb on linux machine:  
<code> $ sudo apt-get install libc6-dbg gdb valgrind </code>

Check the newly installed gdb by running $gdb- help


## Question 1 Memory Layout
In this question we will inspect the memory layout of a program written in C(text, heap, stack, etc..).
Given the file "process_layout_q.c", re-write the comment to relevant section in the memory(text, heap, etc..).
For this part you need to use the tools:objdump,nm,size.


## Question 2 Signals
#### Part A
Our task is to check whether or not a process with a certain pid exists.
Write a program named "check_pid.c" that takes one parameter,which is the pid of a process and gives the following output:  
<code>If EPERM, Process <pid> ​exists but we have no permission.</code>  
<code>If ESRCH, Process <pid> does not exist.</code>  
<code>If kill is successful, Process <pid> exists.</code>
  
<code>*Running example*:check_pid 2003</code>  
<code>Process 2003 exists.</code>

#### Part B
In this part you will come to see that the number of signals received may be less than number of signals sent(you will come to the conclusion that it's better to use a real time signal like sigaction() or sigqueue() instead of signal() although it might a bit more fiddly than the latter...).



## Question 3 CPU scheduling
In this part the user will experience with tools such as:chrt,renice,taskset in Linux.

Write a program named "set_policy.c" which defines process policy and process scheduling.
set_policy(an object file) will receive 2 parameters:A number which represents the policy no. and a number which represents the priority no. .



## Question 4 Files in Linux
In this part you will experience with files and their respective metadata.

For this exersice you will need to use the nftw() tool, which enables us to scan a path directory recursively(incase of a softlink-->ignore).
You need to write a program named "dir_traversal.c" which recuresively iterates path directory.
For each file or directory the program prints:type, inode number and name.
incase of softlink ignore.


<code>$ mkdir dir</code>  
<code>$ touch dir/a dir/b</code>  
<code>$ ln -s a dir/sl ←- ​later​ ​ignored from the output</code>  
<code>$ mkdir dir/sub</code>  
<code>$ touch dir/sub/x</code>

*output:*  
<code>$ ./dir_traversal dir</code>  
<code>D 2327983 dir</code>  
<code>F 2327984 a</code>  
<code>F 2327985 b</code>  
<code>D 2327988 sub</code>  
<code>F 2327989 x</code>  

*Note: order of printing doesn't matter*


**General Note:The task was originally published in hebrew, but for the sake of non hebrew speakers I translated it to English(I've added a file ref. in Hebrew)**


**Good Luck and may the force be with you**








  
  











