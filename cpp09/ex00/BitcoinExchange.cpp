#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string const &dbFile) { loadDB(dbFile); }

void BitcoinExchange::loadDB(std::string const &dbFile) {
  std::ifstream file(dbFile.c_str());
  if (!file.is_open())
    throw std::runtime_error("Error: could not open file.");

  std::string line;
  if (!std::getline(file, line))
    throw std::runtime_error("Error: empty data file.");

  if (line != "date,exchange_rate")
    throw std::runtime_error("Error: invalid database file format.");

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string date, rateStr;

    if (std::getline(iss, date, ',') && std::getline(iss, rateStr)) {
      if (date[10] != '\0' || !isdigit(rateStr[0]))
        throw std::runtime_error("Error: Invalid data format.");
      if (!isValidDate(date))
        throw std::runtime_error("Error: Invalid data date format.");

      char *end;
      double rate = std::strtod(rateStr.c_str(), &end);
      if (*end != '\0' || rate < 0)
        throw std::runtime_error("Error: Invalid data exchange_rate format.");

      mExchangeRates[date] = rate;
    } else {
      throw std::runtime_error("Error: Invalid data file format.");
    }
  }
  file.close();
}

bool BitcoinExchange::isValidDate(std::string const &date) const {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 1000 || year > 9999 || month < 1 || month > 12)
    return false;

  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    days[1] = 29;

  return day > 0 && day <= days[month - 1];
}

double BitcoinExchange::getExchangeRate(std::string const &date) const {
  std::map<std::string, double>::const_iterator it =
      mExchangeRates.lower_bound(date);
  if (it == mExchangeRates.end() || it->first != date) {
    if (it == mExchangeRates.begin())
      return -1;
    --it;
  }
  return it->second;
}

void BitcoinExchange::processInput(std::string const &inputFile) const {
  std::ifstream file(inputFile.c_str());
  if (!file.is_open())
    throw std::runtime_error("Error: could not open file.");

  std::string line;
  if (!std::getline(file, line))
    throw std::runtime_error("Error: empty input file.");

  if (line != "date | value")
    throw std::runtime_error("Error: Invalid input file format.");

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string date, valueStr;

    if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
      if (date[10] != ' ' || date[11] != '\0') {
        std::cerr << "Error: bad input => " + line << std::endl;
        continue;
      }

      if (valueStr[0] != ' ' || (!isdigit(valueStr[1]) && valueStr[1] != '-')) {
        std::cerr << "Error: bad input => " + line << std::endl;
        continue;
      }

      date = date.substr(0, date.find_last_not_of(" \t\n\r") + 1);
      valueStr = valueStr.substr(valueStr.find_first_not_of(" \t\n\r"));
      if (!isValidDate(date)) {
        std::cerr << "Error: bad input => " + date << std::endl;
        continue;
      }

      char *end;
      double value = std::strtod(valueStr.c_str(), &end);
      if (*end != '\0') {
        std::cerr << "Error: bad inputs => " + valueStr << std::endl;
        continue;
      } else if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        continue;
      } else if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        continue;
      }

      double rate = getExchangeRate(date);
      if (rate == -1) {
        std::cerr << "Error: this date does not exist => " + date << std::endl;
        continue;
      }

      double result = rate * value;
      std::cout << date << " => " << value << " = " << result << std::endl;
    } else {
      std::cerr << "Error: bad input => " + line << std::endl;
    }
  }
  file.close();
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
  *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
  if (this != &other) {
    mExchangeRates = other.mExchangeRates;
  }
  return *this;
}
BitcoinExchange::~BitcoinExchange() {}
