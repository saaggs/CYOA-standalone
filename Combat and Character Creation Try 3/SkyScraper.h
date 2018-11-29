#pragma once

#ifndef SKYSCRAPER_H
#define SKYSCRAPER_H
#include <string>
#include <iostream>
#include <stdexcept>

class Skyscraper
{
public:
	Skyscraper(const std::string& name, double height);
	double getHeight() { return m_height; }
	std::string getName() const { return m_name; }
	void print() const;

private:
	std::string m_name;
	double m_height;
};

bool operator<(Skyscraper &s1, Skyscraper &s2);

#endif // SKYSCRAPER_H