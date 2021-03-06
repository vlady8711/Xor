#include "systemc.h"

SC_MODULE(monitor) {
	sc_in<bool> input_1, input_2, output;
	sc_in_clk clock;
	
	void Monitor() {
		while(1) {
			wait();

			double time_stamp = sc_time_stamp().to_default_time_units();

			if (time_stamp != 0)
			{
				cout << sc_time_stamp() << "\t   " << input_1.read()
					<< "       " << input_2.read() << "       " << output.read() << endl;
			}
		}
	}
	
	SC_CTOR(monitor) {
		SC_THREAD(Monitor);
		sensitive << clock.pos();
		cout << "Time\tinput_1 input_2 output" << endl;
	}
};