#pragma once



using uint = unsigned int;

struct Flag {
	uint hours;
	uint minutes;
	uint seconds;

	Flag() :hours(0), minutes(0), seconds(0) {}
	Flag(uint h, uint m, uint s) :hours(h), minutes(m), seconds(s) {}

	struct Flag operator-(const Flag& other) const {
		uint h, m, s;
		if (hours >= other.hours) {
			h = hours - other.hours;
			m = minutes - other.minutes;
			s = seconds - other.seconds;
		}
		else {
			h = other.hours - hours;
			m = other.minutes - minutes;
			s = other.seconds - seconds;
		}

		if (s < 0) {
			m--;
			s += 60;
		}

		if (m < 0) {
			h--;
			m += 60;
		}

		return Flag{ h, m, s };
	}
};