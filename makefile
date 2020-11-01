GY = "./"

.DEFAULT_GOAL := TARGET
RUN : driver.c read.c token.c parseTree.c
	gcc -o exeRUN driver.c read.c token.c parseTree.c
TARGET : RUN
	$(GY)exeRUN
