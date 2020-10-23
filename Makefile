D=gcc #First make variable of gcc
all: pre_processed 
#Making pre-processed file
pre_processed:
	$(D) main.c -o main.out && $(D) ls.c -o ls && $(D) cat.c -o cat && $(D) date.c -o date && $(D) mkdir.c -o mkdir && $(D) rm.c -o rm 

exe:
	./main.out
