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

# CC = gcc # Flag for implicit rules
# CFLAGS = -g # Flag for implicit rules. Turn on debug info
#
# # Implicit rule #1: blah is built via the C linker implicit rule
# # Implicit rule #2: blah.o is built via the C compilation implicit rule, because blah.c exists
# blah: blah.o
#
# blah.c:
# 	echo "int main() { return 0; }" > blah.c
#
# clean:
# 	rm -f blah*

# objects = foo.o bar.o all.o
# all: $(objects)
# 	$(CC) $^ -o all
#
# foo.o: foo.c
# 	$(CC) -c foo.c -o foo.o
#
# bar.o: bar.c
# 	$(CC) -c bar.c -o bar.o
#
# all.o: all.c
# 	$(CC) -c all.c -o all.o
#
# all.c:
# 	echo "int main() { return 0; }" > all.c
#
# # Note: all.c does not use this rule because Make prioritizes more specific matches when there is more than one match.
# %.c:
# 	touch $@
#
# clean:
# 	rm -f *.c *.o all

# objects = foo.o bar.o all.o
# all: $(objects)
# 	$(CC) $^ -o all
#
# # Syntax - targets ...: target-pattern: prereq-patterns ...
# # In the case of the first target, foo.o, the target-pattern matches foo.o and sets the "stem" to be "foo".
# # It then replaces the '%' in prereq-patterns with that stem
# $(objects): %.o: %.c
# 	$(CC) -c $^ -o $@
#
# all.c:
# 	echo "int main() { return 0; }" > all.c
#
# # Note: all.c does not use this rule because Make prioritizes more specific matches when there is more than one match.
# %.c:
# 	touch $@
#
# clean:
# 	rm -f *.c *.o all

# obj_files = foo.result bar.o lose.o
# src_files = foo.raw bar.c lose.c
#
# all: $(obj_files)
# # Note: PHONY is important here. Without it, implicit rules will try to build the executable "all", since the prereqs are ".o" files.
# .PHONY: all 
#
# # Ex 1: .o files depend on .c files. Though we don't actually make the .o file.
# $(filter %.o,$(obj_files)): %.o: %.c
# 	echo "target: $@ prereq: $<"
#
# # Ex 2: .result files depend on .raw files. Though we don't actually make the .result file.
# $(filter %.result,$(obj_files)): %.result: %.raw
# 	echo "target: $@ prereq: $<" 
#
# %.c %.raw:
# 	touch $@
#
# clean:
# 	rm -f $(src_files)

# # Define a pattern rule that compiles every .c file into a .o file
# %.o: %.c
# 	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

# # Define a pattern rule that has no pattern in the prerequisites.
# # This just creates empty .c files when needed.
# %.c:
# 	touch $@

# all: blah
#
# blah::
# 	echo "hello"
#
# blah::
# 	echo "hello again"

# all: 
# 	@echo "This make line will not be printed"
# 	echo "But this will"

# all: 
# 	cd ..
# 	# The cd above does not affect this line, because each command is effectively run in a new shell
# 	echo `pwd`
#
# 	# This cd command affects the next because they are on the same line
# 	cd ..;echo `pwd`
#
# 	# Same as above
# 	cd ..; \
# 	echo `pwd`

# SHELL=/bin/bash
#
# cool:
# 	echo "Hello from bash"

# make_var = I am a make variable
# all:
# 	# Same as running "sh_var='I am a shell variable'; echo $sh_var" in the shell
# 	sh_var='I am a shell variable'; echo $$sh_var
#
# 	# Same as running "echo I am a make variable" in the shell
# 	echo $(make_var)

# one:
# 	# This error will be printed but ignored, and make will continue to run
# 	-false
# 	touch one

# new_contents = "hello:\n\ttouch inside_file"
# all:
# 	mkdir -p subdir
# 	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
# 	cd subdir && $(MAKE)
#
# clean:
# 	rm -rf subdir

# # Run this with "export shell_env_var='I am an environment variable'; make"
# all:
# 	# Print out the Shell variable
# 	echo $$shell_env_var
#
# 	# Print out the Make variable
# 	echo $(shell_env_var)

# shell_env_var=Shell env var, created inside of Make
# export shell_env_var
# all:
# 	echo $(shell_env_var)
# 	echo $$shell_env_var

# new_contents = "hello:\n\techo \$$(cooly)"
#
# all:
# 	mkdir -p subdir
# 	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
# 	@echo "---MAKEFILE CONTENTS---"
# 	@cd subdir && cat makefile
# 	@echo "---END MAKEFILE CONTENTS---"
# 	cd subdir && $(MAKE)
#
# # Note that variables and exports. They are set/affected globally.
# cooly = "The subdirectory can see me!"
# export cooly
# # This would nullify the line above: unexport cooly
#
# clean:
# 	rm -rf subdir

# one=this will only work locally
# export two=we can run subcommands with this
#
# all: 
# 	@echo $(one)
# 	@echo $$one
# 	@echo $(two)
# 	@echo $$two

# .EXPORT_ALL_VARIABLES:
# new_contents = "hello:\n\techo \$$(cooly)"
#
# cooly = "The subdirectory can see me!"
# # This would nullify the line above: unexport cooly
#
# all:
# 	mkdir -p subdir
# 	printf $(new_contents) | sed -e 's/^ //' > subdir/makefile
# 	@echo "---MAKEFILE CONTENTS---"
# 	@cd subdir && cat makefile
# 	@echo "---END MAKEFILE CONTENTS---"
# 	cd subdir && $(MAKE)
#
# clean:
# 	rm -rf subdir

# # Recursive variable. This will print "later" below
# one = one ${later_variable}
# # Simply expanded variable. This will not print "later" below
# two := two ${later_variable}
#
# later_variable = later
#
# all: 
# 	echo $(one)
# 	echo $(two)


# one = hello
# # one gets defined as a simply expanded variable (:=) and thus can handle appending
# one := ${one} there
#
# all: 
# 	echo $(one)

# one = hello
# one ?= will not be set
# two ?= will be set
#
# all: 
# 	echo $(one)
# 	echo $(two)

# with_spaces = hello   # with_spaces has many spaces after "hello"
# after = $(with_spaces)there
#
# nullstring =
# space = $(nullstring) # Make a variable with a single space.
#
# all: 
# 	echo "$(after)"
# 	echo start"$(space)"end

# all: 
# 	# Undefined variables are just empty strings!
# 	echo $(nowhere)

# foo := start
# foo += more
#
# all: 
# 	echo $(foo)

# # Overrides command line arguments
# override option_one = did_override
# # Does not override command line arguments
# option_two = not_override
# all: 
# 	echo $(option_one)
# 	echo $(option_two)

# one = export blah="I was set!"; echo $$blah
#
# define two
# export blah="I was set!"
# echo $$blah
# endef
#
# all: 
# 	@echo "This prints 'I was set'"
# 	@$(one)
# 	@echo "This does not print 'I was set' because each command runs in a separate shell"
# 	@$(two)

# all: one = cool
#
# all: 
# 	echo one is defined: $(one)
#
# other:
# 	echo one is nothing: $(one)

# %.c: one = cool
#
# blah.c: 
# 	echo one is defined: $(one)
#
# other:
# 	echo one is nothing: $(one)

# foo = ok
#
# all:
# ifeq ($(foo), ok)
# 	echo "foo equals ok"
# else
# 	echo "nope"
# endif


# nullstring =
# foo = $(nullstring) # end of line; there is a space here
#
# all:
# ifeq ($(strip $(foo)),)
# 	echo "foo is empty after being stripped"
# endif
# ifeq ($(nullstring),)
# 	echo "nullstring doesn't even have spaces"
# endif

# bar =
# foo = $(bar)
#
# all:
# ifdef foo
# 	echo "foo is defined"
# endif
# ifndef bar
# 	echo "but bar is not"
# endif

# all:
# # Search for the "-i" flag. MAKEFLAGS is just a list of single characters, one per flag. So look for "i" in this case.
# ifneq (,$(findstring i, $(MAKEFLAGS)))
# 	echo "i was passed to MAKEFLAGS"
# endif

# bar := ${subst not,"totally", "I am not superman"}
# all: 
# 	@echo $(bar)

# comma := ,
# empty:=
# space := $(empty) $(empty)
# foo := a b c
# bar := $(subst $(space),$(comma),$(foo))
#
# all: 
# 	@echo $(bar)

# comma := ,
# empty:=
# space := $(empty) $(empty)
# foo := a b c
# bar := $(subst $(space), $(comma) , $(foo)) # Watch out!
#
# all: 
# 	# Output is ", a , b , c". Notice the spaces introduced
# 	@echo $(bar)

# foo := a.o b.o l.a c.o
# one := $(patsubst %.o,%.c,$(foo))
# # This is a shorthand for the above
# two := $(foo:%.o=%.c)
# # This is the suffix-only shorthand, and is also equivalent to the above.
# three := $(foo:.o=.c)
#
# all:
# 	echo $(one)
# 	echo $(two)
# 	echo $(three)

# foo := who are you
# # For each "word" in foo, output that same word with an exclamation after
# bar := $(foreach wrd,$(foo),$(wrd)!)
#
# all:
# 	# Output is "who! are! you!"
# 	@echo $(bar)

# foo := $(if this-is-not-empty,then!,else!)
# empty :=
# bar := $(if $(empty),then!,else!)
#
# all:
# 	@echo $(foo)
# 	@echo $(bar)

# sweet_new_fn = Variable Name: $(0) First: $(1) Second: $(2) Empty Variable: $(3)
#
# all:
# 	# Outputs "Variable Name: sweet_new_fn First: go Second: tigers Empty Variable:"
# 	@echo $(call sweet_new_fn, go, tigers)

# all: 
# 	@echo $(shell ls -la) # Very ugly because the newlines are gone!


# obj_files = foo.result bar.o lose.o
# filtered_files = $(filter %.o,$(obj_files))
#
# all:
# 	@echo $(filtered_files)

# some_file:
# 	touch some_file
# 	touch clean
#
# .PHONY: clean
# clean:
# 	rm -f some_file
# 	rm -f clean

# .DELETE_ON_ERROR:
# all: one two
#
# one:
# 	touch one
# 	false
#
# two:
# 	touch two
# 	false

# Thanks to Job Vranish (https://spin.atomicobject.com/2016/08/26/makefile-c-projects/)
TARGET_EXEC := final_program

BUILD_DIR := ./build
SRC_DIRS := ./src

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')

# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./build/./your_dir/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.cpp.o turns into ./build/hello.cpp.d
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
