******************************
Author : Utkarsh Kumar
******************************
1. Please refer to Language_Description.pdf for details of 
  Language implemented.
2. Run makefile to generated required executable.
3. The program takes the source code in simple .txt format.
4. The program takes argument file at run time.
5. Please refer to Grammar.txt for syntax of the source code.
6. Further coding details are provided below.
7. This Project was completed for partial completion of 
   Principle of Programing Languages course at BITS Pilani.
***************************************************************************************************************
CODING DETAILS:

1.	IDs  and Names : 2017B2A71008P UTKARSH KUMAR
2.	Mention the names of the Submitted files :
	1.) def.h                                    
	2.) driver.c                                  
	3.) group_28_grammer.txt                       
	4.) makefile                                 
	5.) nonterminals.txt                     
	6.) parseTree.c                
	7.) read.c
	8.) t1.txt
	9.) t2.txt
	10.) t3.txt
	11.) t4.txt
	12.) t5.txt
	13.) t6.txt
	14.) terminals.txt
	15.) token.c

3.	Total number of submitted files: 15
4.	Have you mentioned your names and IDs at the top of each file (and commented well)? (Yes/ no) yes
5.	Have you compressed the folder as specified in the submission guidelines? (yes/no) yes
6.	Have you ensured that the folder does not have any *.o file or any executable file? (yes/no) yes

7.	Grammar and token stream
	Total number of production rules: 41 
	Total number of nonterminal: 15
	Total number of terminals: 34
	Grammar.txt file created [yes/no]: yes
	Nonterminal symbols enumerated [yes/no]: no
	Terminal symbols enumerated [yes/no]: yes
	Grammar data structure populated successfully [yes/no]: yes
	Token stream created [yes/no]: yes

8.	Which functions have you implemented?
[A].	readGrammar ( ) [yes/no] yes
[B].	tokeniseSourcecode  ( ) [yes/no] yes
[C].	createParseTree ( ) [yes/no] yes
[D].	traverseParseTree ( ) [yes/no] no 
[E].	printParseTree ( ) [yes/no] yes
[F].	printTypeExpressionTable ( ) [yes/no] no

9.	Parse tree 
[A].	Constructed (yes/no): yes
[B].	Printing as per the given format (yes/no): yes
[C].	Describe the order you have adopted for printing the parse tree nodes (in maximum two lines)
	preorder traversal in format : Symbol , line, terminal, keyword, grammar rule

10.	Type Expression Table
[A].	Constructed (yes/no): no
[B].	Implemented as (lookup table/ hash table): NA
[C].      Printing as per the given format (yes/no): NA
[C].	Describe the structure of the type expression accommodating all types (in maximum two lines)

11.	Compilation Details:
[A].	Implemented in multiple files / single file: Multiple files
[B].	Makefile works (yes/no): yes
[C].	Code Compiles (yes/ no): yes
[D].	Mention the .c files that do not compile: none
[E].	Any specific function that does not compile: none
[F].	Ensured the compatibility of your code with the specified gcc version(yes/no): yes
[G].	Give below the exact commands to compile your code: make

12.	Driver Details: Does it take care of the options specified earlier(yes/no): yes
13.	Execution 
[A].	Status (describe in maximum 2 lines): executes successfully and compiles
[B].	Gives segmentation fault with any of the test cases (1-6) uploaded on the course page. If yes, specify 
	the testcase file name: none
[C].	Command line arguments used for input file (yes/no): no (argument to be given by user when code runs)

14.	Specify the language features your code is not able to handle (in maximum one line) : reads, 
	tokenizes and creates parse Tree for all features except for type checking.
15.	Are you availing the lifeline (Yes/No): Yes

16.	Declaration: We, Utkarsh Kumar declare that we have 
	put our genuine efforts in creating the code and have submitted the code developed only by our group. We 
	have not copied any piece of code from any source. If our code is found plagiarized in any form or degree, we 
	understand that a disciplinary action as per the institute rules will be taken against us and we will accept 
	the penalty as decided by the department of Computer Science and Information Systems, BITS, Pilani.
	        
	ID 2017B2A71008P   Name: Utkarsh Kumar 		         	          
Date: 30th October 2020
