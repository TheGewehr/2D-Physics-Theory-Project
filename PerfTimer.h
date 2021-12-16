#ifndef __PERFTIMER_H__
#define __PERFTIMER_H__


class PerfTimer
{
public:

	// Constructor
	PerfTimer();

	void Start();
	double ReadMs() const;
	int ReadTicks() const;

private:
	int startTime;
	int static frequency;
};

#endif //__PERFTIMER_H__