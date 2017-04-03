CFLAGS=-Wall -ggdb

global_history: globalHistory.o stats.o smithCounter.o branchHistoryRegister.o
	g++ -o global_history $(CFLAGS) globalHistory.o stats.o smithCounter.o branchHistoryRegister.o

branchHistoryRegister.o: branchHistoryRegister.cpp branchHistoryRegister.h
	g++ $(CFLAGS) -c branchHistoryRegister.cpp -o branchHistoryRegister.o

smithCounter.o: smithCounter.cpp smithCounter.h
	g++ $(CFLAGS) -c smithCounter.cpp -o smithCounter.o

stats.o: stats.cpp stats.h
	g++ $(CFLAGS) -c stats.cpp -o stats.o

globalHistory.o: globalHistory.cpp branchHistoryRegister.h stats.h smithCounter.h
	g++ $(CFLAGS) -c globalHistory.cpp -o globalHistory.o

clean:
	rm -f global_history *.o
