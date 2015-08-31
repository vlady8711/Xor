#include "nand.h"

SC_MODULE(xor_) {
	sc_in<bool> input_1, input_2;
	sc_out<bool> output;
	nand nand_1, nand_2, nand_3, nand_4;
	sc_signal<bool> signal_1, signal_2, signal_3;
	
	SC_CTOR(xor_) : nand_1("nand_1"), nand_2("nand_2"), nand_3("nand_3"), nand_4("nand_4") {
		nand_1.input_1(input_1);
		nand_1.input_2(input_2);
		nand_1.output(signal_1);
		
		nand_2.input_1(input_1);
		nand_2.input_2(signal_1);
		nand_2.output(signal_2);

		nand_3.input_1(signal_1);
		nand_3.input_2(input_2);
		nand_3.output(signal_3);

		nand_4.input_1(signal_2);
		nand_4.input_2(signal_3);
		nand_4.output(output);
	}
};