#include "src/ByteBuffer.hpp"

// int main() {
//     bb::ByteBuffer buffer;

//     // Set the byte order to little endian
//     buffer.order(bb::ByteOrder::big);

//     printf("Endian: %d\n", buffer.order());

//     // Put an integer value
//     //buffer.putInt(0x12345678);
// 	buffer.putInt(10);
// 	buffer.putInt(20);
// 	buffer.putInt(30);

//     // Reset read position
//     buffer.setReadPos(0);

//     // Read the integer value
//     //uint32_t value = buffer.getInt();

//     // Output the value
//     //std::cout << std::hex << value << std::endl; // Should output 0x12345678

// 	for (int i = 0; i < 3; i++) {
// 		uint32_t value = buffer.getInt();
// 		std::cout << value << std::endl;
// 		//std::cout << std::hex << value << std::endl;
// 	}

//     // Change byte order to big endian
//     bb::ByteBuffer buffer2 = buffer.order(bb::ByteOrder::little);
//     printf("Endian1: %d\n", buffer.order());
//     printf("Endian2: %d\n", buffer2.order());

//     // Reset read position
//     buffer2.setReadPos(0);

// 	for (int i = 0; i < 3; i++) {
// 		uint32_t value = buffer2.getInt();
// 		std::cout << value << std::endl;
// 		//std::cout << std::hex << value << std::endl;
// 	}

//     // Read the integer value with new byte order
//     //value = buffer2.getInt();

//     // Output the value
//     //std::cout << std::hex << value << std::endl; // Output will differ due to byte order change
// 	//std::cout << value << std::endl; // Output will differ due to byte order change

//     return 0;
// }


// // ByteBufferTest.cpp
#include <gtest/gtest.h>
#include "src/ByteBuffer.hpp"

TEST(ByteBufferTest, DefaultEndian) {
	bb::ByteBuffer buffer;
	EXPECT_EQ(buffer.order(), bb::ByteOrder::big);
}

TEST(ByteBufferTest, SetLittleEndian) {
	bb::ByteBuffer buffer;
	buffer.order(bb::ByteOrder::little);
	EXPECT_EQ(buffer.order(), bb::ByteOrder::little);
}

TEST(ByteBufferTest, SetBigEndian) {
	bb::ByteBuffer buffer;
	buffer.order(bb::ByteOrder::big);
	EXPECT_EQ(buffer.order(), bb::ByteOrder::big);
}

TEST(ByteBufferTest, PutGetIntLittleEndian) {
	bb::ByteBuffer buffer;
	buffer.order(bb::ByteOrder::little);
	buffer.putInt(0x12345678);
	buffer.setReadPos(0);
	uint32_t value = buffer.getInt();
	EXPECT_EQ(value, 0x12345678);
}

TEST(ByteBufferTest, PutGetIntBigEndian) {
	bb::ByteBuffer buffer;
	buffer.order(bb::ByteOrder::big);
	buffer.putInt(0x12345678);
	buffer.order(bb::ByteOrder::little);
	buffer.setReadPos(0);
	uint32_t value = buffer.getInt();
	EXPECT_EQ(value, 0x78563412);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}