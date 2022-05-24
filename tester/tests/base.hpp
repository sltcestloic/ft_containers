#if !defined(USING_STD)
# define TESTED_NAMESPACE ft
#else
# define TESTED_NAMESPACE std
#endif

#include <iostream>
#include <fstream>

#include "../../vector.hpp"

#include <unistd.h>
#include <sys/stat.h>

class base
{
	private:
		std::string		 _output_name;
	public:
		std::ofstream	_ofstream;

		base(char **av){
			char *dir = (char *)malloc(200);
			getcwd(dir, 200);
			std::string _output_name(dir);
			_output_name.append(&av[0][1]);
			size_t index = _output_name.find("/tests/");
			_output_name.replace(index, 7, "/output/");
			#if !defined(USING_STD)
				_output_name.append(".ft_out");
			#else
				_output_name.append(".std_out");
			#endif
			
			std::cout << _output_name << std::endl;
			_ofstream.open(_output_name, std::ofstream::trunc);
		}

		void print(std::string str) {
			_ofstream << str;
		}

		~base() {
			_ofstream.close();
		}
};

