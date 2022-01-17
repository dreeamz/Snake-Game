#pragma once

#include<vector>
#include<string>

class Records {

public:
	struct PairRecord {
		std::string nickname;
		int score;
		bool operator<(const PairRecord& rec) {
			return score > rec.score;
		}
		friend std::ostream& operator<<(std::ostream& os, PairRecord& pair);
	};

	std::vector<PairRecord> _records_array;
	PairRecord _current_pair;
	const int _MAX_RECORDS_COUNT = 6;

	Records() {
		read_from_file();
	}

	int save_to_file();
	int read_from_file();


	//getters
	std::vector<PairRecord> get_records();

	//setters
	void set_records(std::vector<PairRecord> records);

	~Records()
	{
		save_to_file();
	}
	bool _is_added = false;
private:

	const char* _FILE_NAME = "records.json";
	const char* _DIR_NAME = "Records";
	const char* _FILE_PATH = "Records/records.json";

	int _records_count = 0;
};
