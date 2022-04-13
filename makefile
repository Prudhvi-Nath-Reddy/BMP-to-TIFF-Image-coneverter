CC = gcc	#Variable that stores gcc
all_objs = main.o readbmp.o deftiff.o writetiff.o #Variable that stores all object files
DEPS = main.h	#Header file

#Objects
obj1 = readbmp.c
obj2 = deftiff.c
obj3 = writetiff.c
obj4 = main.c

#Final executable file
my_project: $(all_objs)
	$(CC) $(all_objs) -o my_project

#Object file that is a combination of all other object files
source_file.o: $(all_objs)
	$(CC) $(all_objs) -o source_file.o

#readbmp object file
readbmp.o: $(obj1) $(DEPS)
	$(CC) -c $(obj1)

#deftiff object file
deftiff.o: $(obj2) $(DEPS)
	$(CC) -c $(obj2)

#writetiff object file
writetiff.o: $(obj3) $(DEPS)
	$(CC) -c $(obj3)

#main object file
main.o: $(obj4) $(DEPS)
	$(CC) -c $(obj4)

#Deletes all object files and final executable file on command
clean:
	rm -rf *o my_project
