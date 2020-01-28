/** Timer class that uses the clock() routine to give us
 *  millisecond timing.
**/
class Timer {
  private:
	double startTime;
	double endTime;
  public:
	
	/// Set the start time to current time on init
	Timer();

	/// Doesn't do anything
	~Timer();

	/// Reset the start time to current time
	void Start(void);

	/// Set the end time to current time
	void Stop(void);

	/// Get the difference between the end and start time in milliseconds
	double GetTime(void);

	/// Get the difference between the end time and the start time in 
	/// milliseconds, sets the end time
	double GetElapsed(void);

};
