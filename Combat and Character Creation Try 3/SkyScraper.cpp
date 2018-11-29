#include "skyScraper.h"

Skyscraper::Skyscraper(const std::string &name, double height) :
	m_name(name), m_height(height)
{
	if (m_height < 0)
		throw std::invalid_argument(
			"Height must be non-negative.");
}

void Skyscraper::print() const
{
	std::cout << this->m_name << " "
		<< this->m_height << '\n';
}

bool operator<(Skyscraper &s1, Skyscraper &s2)
{
	return s1.getHeight() < s2.getHeight();
}