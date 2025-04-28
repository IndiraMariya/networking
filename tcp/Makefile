CC = clang
CFLAGS = -Wall
TARGET = TCPEchoClient
OBJS = TCPEchoClient.o DieWithError.o

# build the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# build .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# delete object files and executable
clean:
	rm -f $(TARGET) $(OBJS)