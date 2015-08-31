#include "systemc.h"

SC_MODULE(monitor) {
	sc_in<bool> A, B, F;
	sc_in_clk Clk;
	
	void Monitor() {
		while(1) {
			wait();
			cout << sc_time_stamp() << "\t" << A.read()
			<< " " << B.read() << " " << F.read() << endl;
		}
	}
	
	SC_CTOR(monitor) {
		SC_THREAD(Monitor);
		sensitive << Clk.pos();
		cout << "Time\tA B F" << endl;
	}
};