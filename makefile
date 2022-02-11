EXEC	= a.out
FLAGS	= -Wall -lstdc++ -g
OBJDIR	= obj
SRCDIR	= src
INCDIR	= lib

SOURCES	:= ${shell find $(SRCDIR) -name '*.cpp'}
OBJECTS	:= ${patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SOURCES:.cpp=.o)}
DEPEND	:= ${patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SOURCES:.cpp=.d)}

$(EXEC) : $(OBJECTS) $(DEPEND)
	gcc -I $(INCDIR) $(FLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	gcc -c $^ -I $(INCDIR) $(FLAGS) -o $@

$(OBJDIR)/%.d: $(SRCDIR)/%.cpp
	@set -e
	rm -f $@
	$(CXX) -MM -I $(INCDIR) $(FLAGS) $< > $@.tmp
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@
	rm -f $@.tmp

include $(DEPEND)

clean:
	rm -f $(OBJDIR)/*
	rm -f $(EXEC)