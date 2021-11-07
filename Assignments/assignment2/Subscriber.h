#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <string>

class Subscriber {

	public:
		//constructor
    Subscriber(const std::string& name, const std::string& creditcard);


		//other
    bool matches(const std::string& name) const;

		void print() const;

	private:
		//variables
		std::string name;
		std::string creditcard;

};
#endif
