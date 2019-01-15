# define the C++ compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g

INCLUDES = -Iinclude

# define the C++ source files
SDIR = source
_SRCS = compose_generator.cpp power_generator.cpp uniform_generator.cpp \
	alpha_stack_sort.cpp main.cpp alpha_merge_sort.cpp tail_sort.cpp timsort.cpp \
	shivers_sort.cpp augmented_shivers_sort.cpp adaptive_shivers_sort.cpp \
	power_sort.cpp

SRCS = $(patsubst %,$(SDIR)/%,$(_SRCS))

# define the C object files
ODIR = objects
_OBJS = $(_SRCS:.cpp=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

# define the executable file
MAIN = simulate

# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'

.PHONY: clean

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	mkdir -p objects
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)
