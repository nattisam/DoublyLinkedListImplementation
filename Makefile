CC = g++
CWFLAGS = -Wall -Wextra
RM = del /Q

SRCDIR = .
OBJDIR =
BINDIR =

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,%.o,$(SRCFILES))
EXE = kvDLL.exe
OUTPUT_TXT = kvDLLoutput.txt

.PHONY: all clean

all: $(EXE)

$(EXE): kvDLLMain.o kvDLL.o
	$(CC) $(CWFLAGS) -O2 $^ -o $@

kvDLL.o: kvDLL.cpp kvDLL.h
	$(CC) $(CWFLAGS) -O2 -c -o $@ $<

kvDLLMain.o: kvDLLMain.cpp kvDLL.h
	$(CC) $(CWFLAGS) -O2 -c -o $@ $<

clean:
	$(RM) *.o $(EXE) $(OUTPUT_TXT)
