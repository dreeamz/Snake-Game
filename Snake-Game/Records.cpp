#include "Records.h"
#include<iostream>
//check folder exists
#include<sys/stat.h>
//for work with files
#include<fstream>

//for _mkdir() creates folder
#include<direct.h>


//this is an external library wich was downloaded from
//https://github.com/nlohmann/json and unpaked in our project's dependency folder
//and then included to work with json format
#include<nlohmann/json.hpp>
using json = nlohmann::json;

//Serialization
void to_json(json& JSON, const Records::PairRecord& n) {
	JSON = { {"nickname", n.nickname}, {"score", n.score} };
}
//Derialization
void from_json(const json& j, Records::PairRecord& n) {
	n.nickname = (j.at("nickname").get<std::string>());
	n.score = (j.at("score").get<int>());
}
//To get "std::cout" to accept a PairRecord object
std::ostream& operator<<(std::ostream& os, Records::PairRecord& pair) {
	return os << pair.nickname << " - " << pair.score;
}



int Records::save_to_file()
{
	//If nobody was added in a records then we don't need to overwrite new file
	if (_is_added) {
		std::ofstream records_file(_FILE_PATH);
		if (records_file.is_open()) {
			json records_json = _records_array;
			records_file << records_json;
			records_file.close();
		}
		else {
			std::cerr << "Error in opening the file";
			return 1;
		}
	}
}
int Records::read_from_file()
{
	struct stat buffer;
	if (stat(_DIR_NAME, &buffer) == 0) {
		std::ifstream records_file(_FILE_PATH);
		if (records_file.is_open()) {
			json j;
			records_file >> j;
			_records_array = j;
			_records_count = _records_array.size();

			records_file.close();
		}
		else
		{
			std::cerr << "Error in opening the file";
			return 1;
		}
	}
	else
		_mkdir(_DIR_NAME);
	return 0;
}







std::vector<Records::PairRecord> Records::get_records()
{
	return _records_array;
}
void Records::set_records(std::vector<Records::PairRecord> records) {
	_records_array = records;
}






