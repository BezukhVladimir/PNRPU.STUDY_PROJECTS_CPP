#include <iostream>

class Time
{
public:
	Time() { min_ = 0; sec_ = 0; }
	Time(const int& min, const int& sec) { min_ = min, sec_ = sec; }
	Time(const Time& copy) { min_ = copy.min_; sec_ = copy.sec_; }
	~Time() {}

	int get_min() const { return min_; }
	int get_sec() const { return sec_; }

	void set_min(const int& min) { min_ = min; }
	void set_sec(const int& sec) { sec_ = sec; }

	Time& operator=(const Time&);

	Time& operator++();
	Time operator++(const int);

	Time operator+(const Time&) const;
	Time operator-(const Time&) const;
	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;

	friend std::istream& operator>>(std::istream& in, Time& t);
	friend std::ostream& operator<<(std::ostream& out, const Time& t);

private:
	int min_;
	int sec_;
};