# All the targets
all: queue

# Dependencies and rule to make queue
queue: main.o
	g++ -o lab1 main.o

clean:
	rm queue main.o
