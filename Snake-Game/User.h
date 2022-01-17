#pragma once





class User {
public:
	//setters
	void set_nickname(const char* name);
	void set_score(int score);
	//getters
	char* get_nickname();
	int get_score();

	void print_nickname();
	void print_score();

	~User();
private:
	int _score = 0;
	char* _nickname = nullptr;
};