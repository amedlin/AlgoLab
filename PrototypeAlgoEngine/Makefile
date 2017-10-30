SRC := $(wildcard *.cpp)
SRC := $(filter-out file_to_exclude.cpp, $(SRC))
OBJS := $(SRC:.cpp=.o)
CC := g++
LIBDIR := -L/usr/lib
CFLAGS := -std=c++11 $(INCLUDE) -Wall 
LFLAGS := $(LIBDIR) -lstdc++
TARGET := main

all: release

debug: CFLAGS += -g
debug: TARGET := main_debug
debug: OUTDIR := dbg
debug: main

release: CFLAGS += -O2
release: LFLAGS += -O2
release: OUTDIR := rel
release: main

# Target executable
main: $(OBJS)
	$(CC) $(LFLAGS) $(addprefix $(OUTDIR)/, $(OBJS)) -o $(TARGET)

# Object files
%.o: %.cpp Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $(OUTDIR)/$@ $<

# Clean binaries
clean:
	\rm -f $(addprefix dbg/, $(OBJS)) $(addprefix rel/, $(OBJS)) *~ main main_debug

# Update dependencies
depend:
	makedepend -- $(CFLAGS) -- $(SRC)
# DO NOT DELETE

AlgoA.o: stdafx.h targetver.h AlgoA.h AlgoModule.h serializable.h
AlgoA.o: AlgoSettingsFactory.h SignalFactory.h AlgoSettings.h Versioned.h
AlgoA.o: AlgoASettings.h AlgoAResults.h Signal.h SignalBase.h cast.h
AlgoAResults.o: stdafx.h targetver.h AlgoAResults.h Signal.h SignalBase.h
AlgoAResults.o: serializable.h Versioned.h
AlgoASettings.o: stdafx.h targetver.h AlgoASettings.h AlgoSettings.h
AlgoASettings.o: serializable.h Versioned.h
AlgoB.o: stdafx.h targetver.h AlgoB.h AlgoModule.h serializable.h
AlgoB.o: AlgoSettingsFactory.h SignalFactory.h AlgoSettings.h Versioned.h
AlgoB.o: AlgoBSettings.h AlgoBResults.h Signal.h SignalBase.h cast.h
AlgoBResults.o: stdafx.h targetver.h AlgoBResults.h Signal.h SignalBase.h
AlgoBResults.o: serializable.h Versioned.h
AlgoBSettings.o: stdafx.h targetver.h AlgoBSettings.h AlgoSettings.h
AlgoBSettings.o: serializable.h Versioned.h
AlgoC.o: stdafx.h targetver.h AlgoC.h AlgoModule.h serializable.h
AlgoC.o: AlgoSettingsFactory.h SignalFactory.h AlgoSettings.h Versioned.h
AlgoC.o: AlgoCSettings.h AlgoCResults.h Signal.h SignalBase.h cast.h
AlgoCResults.o: stdafx.h targetver.h AlgoCResults.h Signal.h SignalBase.h
AlgoCResults.o: serializable.h Versioned.h
AlgoCSettings.o: stdafx.h targetver.h AlgoCSettings.h AlgoSettings.h
AlgoCSettings.o: serializable.h Versioned.h
AlgoFramework.o: stdafx.h targetver.h AlgoFramework.h serializable.h
AlgoFramework.o: Versioned.h SettingsManager.h AlgoSequencer.h AlgoModule.h
AlgoFramework.o: AlgoSettingsFactory.h SignalFactory.h AlgoSettings.h
AlgoFramework.o: ResultCollector.h
AlgoModule.o: stdafx.h targetver.h AlgoModule.h serializable.h
AlgoModule.o: AlgoSettingsFactory.h SignalFactory.h AlgoSettings.h
AlgoModule.o: Versioned.h
AlgoSequencer.o: stdafx.h targetver.h AlgoSequencer.h serializable.h
AlgoSequencer.o: AlgoModule.h AlgoSettingsFactory.h SignalFactory.h
AlgoSequencer.o: AlgoSettings.h Versioned.h SignalBase.h
AlgoSettings.o: stdafx.h targetver.h AlgoSettings.h serializable.h
AlgoSettings.o: Versioned.h
PrototypeAlgoEngine.o: stdafx.h targetver.h AlgoFramework.h serializable.h
PrototypeAlgoEngine.o: Versioned.h SettingsManager.h AlgoSequencer.h
PrototypeAlgoEngine.o: AlgoModule.h AlgoSettingsFactory.h SignalFactory.h
PrototypeAlgoEngine.o: AlgoSettings.h ResultCollector.h AlgoA.h
PrototypeAlgoEngine.o: AlgoASettings.h AlgoB.h AlgoBSettings.h AlgoC.h
PrototypeAlgoEngine.o: AlgoCSettings.h
ResultCollector.o: stdafx.h targetver.h ResultCollector.h serializable.h
SettingsManager.o: stdafx.h targetver.h SettingsManager.h serializable.h
Signal.o: stdafx.h targetver.h Signal.h SignalBase.h serializable.h
Signal.o: Versioned.h
stdafx.o: stdafx.h targetver.h
