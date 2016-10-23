#ifndef GLOBAL_H
#define GLOBAL_H
class Globals
{
	int size;
public:
	Globals(unsigned psize);
	~Globals();

	void operator[](unsigned index);
};

#endif // GLOBAL_H

