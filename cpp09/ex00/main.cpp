#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Error: could not open file." << std::endl;
    return 1;
  }

  const std::string dbFile = "./data.csv";
  const std::string inputFile = argv[1];

  try {
    BitcoinExchange btc(dbFile);
    btc.processInput(inputFile);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}