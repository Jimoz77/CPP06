#ifndef DATA_HPP
#define DATA_HPP
#include <string>

class Data
{
	private:
		int _id;
		std::string _name;

	public:
		Data(int id, const std::string& name);
		Data(const Data &other);
		int getid() const;
		const std::string& getname() const;

		Data &operator=(const Data &other);

		~Data();
};
#endif
