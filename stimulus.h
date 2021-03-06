#include "systemc.h"

SC_MODULE(stimulus) {
	sc_out<bool> input_1, input_2;
	sc_in<bool> clock;
	
	void StimGen() {
		wait();

		input_1.write(false);
		input_2.write(false);
		wait();
		
		input_1.write(false);
		input_2.write(true);
		wait();

		input_1.write(true);
		input_2.write(false);
		wait();

		input_1.write(true);
		input_2.write(true);
		wait();
		
		sc_stop();
	}
	
	SC_CTOR(stimulus) {
		SC_THREAD(StimGen);
		sensitive << clock.pos();
	}
};