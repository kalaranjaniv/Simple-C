# This is a Makefile to compile two source files, of which fu.c
# contains the main program. main() calls a function stored in
# root.c. main() also depends on init.h as it contains definitions.

# comment next line if you want to see, in what order the commands are executed.
#.SILENT:

# Define variables. 
PROG   = stage2
OBJS   = stage2.o output.o 
SRCS   = stage2.c output.c
CC     = /usr/local/bin/gcc

# this Makefile should be invoked by 'make' or 'make fu'.

# Following statements are in the form - target:  dependence
# i.e., fu depends on OBJS files; It also states commands
# that should be executed for that target

stage2: $(OBJS)
	$(CC) $(OBJS) -o stage2 -lc 
	@echo executable file is $(PROG)

# fu.o depends on init.h and fu.c
# If either fu.c or init.h chnages, run cc to prepare new fu.o
stage2.o: my_header.h stage2.c
	$(CC) -c stage2.c

output.o: output.c
	$(CC) -c output.c
	
# to install the program, invoke 'make install'. Installs in
# 'bin' directory of your HOME.

install: $(PROG)
	if [ -f $(HOME)/bin/$(PROG) ]  \
		then  \
		  echo moving $(HOME)/bin/$(PROG) to $(HOME)/bin/$(PROG).old; \
		  mv $(HOME)/bin/$(PROG) $(HOME)/bin/$(PROG).old;  \
		  echo copying $(PROG) $(HOME)/bin; \
		  cp $(PROG) $(HOME)/bin; \
		else \
		  echo copying $(PROG) $(HOME)/bin; \
		  cp $(PROG) $(HOME)/bin; \
	fi

clean:
		rm -f $(OBJS)
