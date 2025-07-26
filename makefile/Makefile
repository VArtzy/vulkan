# hello:
# 	echo "Hello, World"
# 	echo "This line will print if the file hello does not exist."

# blah: blah.c
# 	cc blah.c -o blah

# blah: blah.o
# 	cc blah.o -o blah # Runs third
#
# blah.o: blah.c
# 	cc -c blah.c -o blah.o # Runs second
#
# # Typically blah.c would already exist, but I want to limit any additional required files
# blah.c:
# 	echo "int main() { return 0; }" > blah.c # Runs first

# some_file: other_file
# 	echo "This will always run, and runs second"
# 	touch some_file
#
# other_file:
# 	echo "This will always run, and runs first"

# some_file: 
# 	touch some_file
#
# clean:
# 	rm -f some_file

# files := file1 file2
# some_file: $(files)
# 	echo "Look at this variable: " $(files)
# 	touch some_file
#
# file1:
# 	touch file1
# file2:
# 	touch file2
#
# clean:
# 	rm -f file1 file2 some_file

# a := one two# a is set to the string "one two"
# b := 'one two' # Not recommended. b is set to the string "'one two'"
# all:
# 	printf '$a\n'
# 	printf $b

# x := dude
#
# all:
# 	echo $(x)
# 	echo ${x}
#
# 	# Bad practice, but works
# 	echo $x 

# all: one two three
#
# one:
# 	touch one
# two:
# 	touch two
# three:
# 	touch three
#
# clean:
# 	rm -f one two three

# all: f1.o f2.o
#
# f1.o f2.o:
# 	echo $@
# # Equivalent to:
# # f1.o:
# #	 echo f1.o
# # f2.o:
# #	 echo f2.o

# # Print out file information about every .c file
# print: $(wildcard *.c)
# 	ls -la  $?

# thing_wrong := *.o # Don't do this! '*' will not get expanded
# thing_right := $(wildcard *.o)
#
# all: one two three four
#
# # Fails, because $(thing_wrong) is the string "*.o"
# one: $(thing_wrong)
#
# # Stays as *.o if there are no files that match this pattern :(
# two: *.o 
#
# # Works as you would expect! In this case, it does nothing.
# three: $(thing_right)
#
# # Same as rule three
# four: $(wildcard *.o)

# hey: one two
# 	# Outputs "hey", since this is the target name
# 	echo $@
#
# 	# Outputs all prerequisites newer than the target
# 	echo $?
#
# 	# Outputs all prerequisites
# 	echo $^
#
# 	# Outputs the first prerequisite
# 	echo $<
#
# 	touch hey
#
# one:
# 	touch one
#
# two:
# 	touch two
#
# clean:
# 	rm -f hey one two

CC = gcc # Flag for implicit rules
CFLAGS = -g # Flag for implicit rules. Turn on debug info

# Implicit rule #1: blah is built via the C linker implicit rule
# Implicit rule #2: blah.o is built via the C compilation implicit rule, because blah.c exists
blah: blah.o

blah.c:
	echo "int main() { return 0; }" > blah.c

clean:
	rm -f blah*
