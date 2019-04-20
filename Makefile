CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g
EXECUTABLE=saframa6
RM=rm -rf
SOURCEDIR=src/
BUILDDIR=build/
SOURCES=Armour.cpp Creature.cpp DialogueNCP.cpp Display.cpp Equipment.cpp Event.cpp Fight.cpp Game.cpp GameMenus.cpp Hero.cpp HeroStats.cpp Choice.cpp Interact.cpp InventoryBrowser.cpp Inventory.cpp IOhandle.cpp Item.cpp main.cpp Shopping.cpp Storyline.cpp StreamDecoder.cpp Sword.cpp Trap.cpp World.cpp
OBJECTS=$(SOURCES:.cpp=.o)
SOURCE_LIST=$(addprefix $(SOURCEDIR), $(SOURCES))
BUILD_LIST=$(addprefix $(BUILDDIR), $(OBJECTS))

all: $(SOURCE_LIST)
	mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_LIST) 
	mv *.o build
	$(CXX) $(CXXFLAGS) $(BUILD_LIST) -o $(EXECUTABLE)

compile:
	$(CXX) $(CXXFLAGS) $(SOURCE_LIST) -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)
	
clean:
	$(RM) $(BUILDDIR) $(EXECUTABLE) 

doc:

