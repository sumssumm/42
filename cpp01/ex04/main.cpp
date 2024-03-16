# include <iostream>
# include <string>
# include <fstream>

void	replace(std::string &buf, std::string s1, std::string s2)
{
	size_t	find_pos = 0;
	size_t	s1_len = s1.length();
	size_t	s2_len = s2.length();

	find_pos = buf.find(s1, find_pos);
	while (find_pos != std::string::npos)
	{
		buf.erase(find_pos, s1_len);
		buf.insert(find_pos, s2);
		find_pos = buf.find(s1, find_pos + s2_len);
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace [filename] [string1] [string2]" << std::endl;
		return 1;
	}
	std::string			infile = argv[1];
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string			outfile;
	std::string			buffer;

	if (infile.empty() || s1.empty())
	{
		std::cout << "input is empty" << std::endl;
		return 1;
	}
	ifs.open(infile.c_str());
	if (ifs.fail()) //!ifs.is_open()
	{
		std::cout << "Cannot open file" << std::endl;
		return 1;
	}
	if (ifs.peek() == std::ifstream::traits_type::eof())
	{
		std::cout << "file is empty" << std::endl;
		ifs.close();
		return 1;
	}
	outfile = infile.append(".replace");
	ofs.open(outfile.c_str());
	if (ofs.fail())
	{
		std::cout << "Cannot open file" << std::endl;
		ifs.close();
		return 1;
	}
	while (1)
	{
		std::getline(ifs, buffer);
		replace(buffer, s1, s2);
		ofs << buffer;
		if (ifs.eof())
			break ;
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return 0;
}