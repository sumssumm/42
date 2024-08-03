#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>

class BitcoinExchange {
 public:
  BitcoinExchange(std::string const &dbFile);
  ~BitcoinExchange();

  void processInput(std::string const &inputFile) const;

 private:
  std::map<std::string, double> mExchangeRates;

  void loadDB(std::string const &dbFile);
  double getExchangeRate(std::string const &data) const;
  bool isValidDate(std::string const &data) const;

  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &other);
  BitcoinExchange &operator=(BitcoinExchange const &other);
};

#endif