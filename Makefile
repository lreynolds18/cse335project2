EXE = Project2-335
SOURCES = main.cpp barista.cpp drink.cpp
OBJECTS := $(SOURCES:%.cpp=%.o)
CXXFLAGS = -std=c++11 -Wall

$(EXE): $(OBJECTS)
	$(CXX) $^ -o $@
	
clean:
	$(RM) $(EXE) $(OBJECTS)
