#include "systemc.h"

SC_MODULE(nand) {
	sc_in<bool> input_1, input_2;
	sc_out<bool> output;

	void execute_nand() {
		output.write( !(input_1.read() && input_2.read()) );
	}

	SC_CTOR(nand) {
		SC_METHOD(execute_nand);
		sensitive << input_1 << input_2;
	}
};