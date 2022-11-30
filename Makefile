CXX      = g++

.DEFAULT_GOAL := test_graphe

SOURCES =
SOURCES += Graphe.cpp

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAGS  += -g -Wall -std=c++11 -pedantic
LDFLAGS +=

$(OBJECTS) : %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS =

########## test_AVL ##########

TEST_SOURCES = graphe_tests.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

test_graphe : $(TEST_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(TEST_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)

$(TEST_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : test_graphe
TARGETS += test_graphe
CLEAN_OBJECTS += $(TEST_OBJECTS)

########## nettoyage ##########

DEPS = $(CLEAN_OBJECTS:.o=.d)

clean:
	@rm -f $(DEPS) $(TARGETS) $(CLEAN_OBJECTS)

-include $(DEPS)
