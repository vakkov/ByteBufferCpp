# Makefile for ByteBuffer and accompanying test programs
# (C) Ramsey Kant 2011-2013

CC = g++ -std=c++20 -I/usr/local/include/ -DGTEST_HAS_PTHREAD=1
# Debug Flags
DEBUGFLAGS = -g -O0 -fpermissive -Wall
# Production Flags
PRODFLAGS = -Wall -O3

TEST_H   = src/ByteBuffer.hpp
TEST_SRC = src/ByteBuffer.cpp src/test.cpp
TEST2_SRC = src/ByteBuffer.cpp test_bytebuffer.cpp

PACKETS_H   = src/ByteBuffer.hpp
PACKETS_SRC = src/ByteBuffer.cpp src/examples/packets/packets.cpp

HTTP_H   = src/ByteBuffer.hpp src/examples/http/HTTPMessage.h src/examples/http/HTTPRequest.h src/examples/http/HTTPResponse.h
HTTP_SRC = src/ByteBuffer.cpp src/examples/http/http.cpp src/examples/http/HTTPMessage.cpp src/examples/http/HTTPRequest.cpp src/examples/http/HTTPResponse.cpp

test: $(TEST_SRC) $(TEST_H)
	$(CC) $(DBGFLAGS) -o bin/$@ $(TEST_SRC)

test2: $(TEST2_SRC) $(TEST_H)
	$(CC) $(DBGFLAGS) -o bin/$@ $(TEST2_SRC) -L/usr/local/lib -lgtest -lgtest_main -pthread

packets: $(PACKETS_SRC) $(PACKETS_H)
	$(CC) $(DBGFLAGS) -o bin/$@ $(PACKETS_SRC)

http: $(HTTP_SRC) $(HTTP_H)
	$(CC) $(DBGFLAGS) -o bin/$@ $(HTTP_SRC)

.PHONY: clean
clean:
	rm -f bin/test
	rm -f bin/packets
	rm -f bin/http
	rm -Rf *.dSYM

