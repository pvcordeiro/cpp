#include <iostream>
#include <fstream>
#include <string>

typedef std::string string;

static string	readFile(const string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return (std::cout << "Error: Cannot open file " << filename << std::endl, "");
	string	text;
	string	line;
	while (std::getline(file, line))
	{
		text += line;
		if (!file.eof())
			text += "\n";
	}
	file.close();
	return (text);
}

static string	replaceString(const string &text, const string &s1, const string &s2)
{
	if (s1.empty())
		return (text);
	string	result;
	size_t	start = 0;
	size_t	found = 0;

	while ((found = text.find(s1, start)) != string::npos)
	{
		result += text.substr(start, found - start);
		result += s2;
		start = found + s1.length();
	}
	return (result += text.substr(start));
}

static bool	writeFile(const string &filename, const string &result)
{
	std::ofstream	file(filename.c_str());
	if (!file.is_open())
		return (std::cout << "Error: Cannot create output file " << filename << std::endl, false);
	file << result;
	file.close();
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Usage: ./sed <file> <look> <replace>" << std::endl, 1);
	string	filename = argv[1];
	string	s1 = argv[2];
	string	s2 = argv[3];
	string	text = readFile((filename));

	if (text.empty())
		return (1);
	string	result = replaceString(text, s1, s2);
	if (!writeFile(filename + ".replace", result))
		return (1);
	return (0);
}
