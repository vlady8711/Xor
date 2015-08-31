#include "systemc.h"

SC_MODULE(stimulus) {
	sc_out<bool> A, B;
	sc_in<bool> Clk;
	
	void StimGen() {
		wait();
		A.write(false);
		B.write(false);
		wait();
		// wait for the next clock tick
		A.write(false);
		B.write(true);
		wait();

		A.write(true);
		B.write(false);
		wait();

		A.write(true);
		B.write(true);
		wait();
		// wait for the next clock tick
		
		sc_stop();
		// notify kernel to stop simulation
	}
	
	SC_CTOR(stimulus) {
		SC_THREAD(StimGen);
		sensitive << Clk.pos();
	}
};