#include <stdint.h>
#include <string>
#include "CryptoNoteCore/CryptoNoteFormatUtils.h"
#include "Common/Base58.h"

using namespace CryptoNote;

extern "C" uint32_t convert_blob(const char *blob, size_t len, char *out) {
    std::string input = std::string(blob, len);
    std::string output = "";

    Block b = Block();
    if (!CryptoNote::parseAndValidateBlockFromBinaryArray(input, b)) { // Adjust based on available functions
        return 0;
    }

    BinaryArray blobArray;
    get_block_hashing_blob(b, blobArray);
    output = std::string(blobArray.begin(), blobArray.end());
    output.copy(out, output.length(), 0);
    return output.length();
}

extern "C" bool validate_address(const char *addr, size_t len) {
    std::string input = std::string(addr, len);
    std::string output = "";
    uint64_t prefix;
    return CryptoNote::tools::base58::decode_addr(input, prefix, output);
}
