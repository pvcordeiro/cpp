#include "Serializer.hpp"

int main(void)
{
	std::cout << "=== Testing Serializer ===" << std::endl;
    
    Data* originalData = new Data();
    originalData->value = 42;
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << originalData << std::endl;
    std::cout << "  Value: " << originalData->value << std::endl;
    
    uintptr_t serialized = Serializer::serialize(originalData);
    std::cout << "\nSerialized address: " << serialized << std::endl;
    std::cout << "Serialized address (hex): 0x" << std::hex << serialized << std::dec << std::endl;
    Data* deserializedData = Serializer::deserialize(serialized);
    
    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << "  Address: " << deserializedData << std::endl;
    std::cout << "  Value: " << deserializedData->value << std::endl;

    std::cout << "\n=== Verification ===" << std::endl;
    if (originalData == deserializedData)
    {
        std::cout << "✅ SUCCESS: Original and deserialized pointers are equal!" << std::endl;
        std::cout << "✅ Data integrity maintained through serialization/deserialization" << std::endl;
    }
    else
        std::cout << "❌ ERROR: Pointers are not equal!" << std::endl;
    delete originalData;
	return (0);
}
